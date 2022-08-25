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
 * vCard.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vcard object.
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 ****************************************************************************/
#include "MMI_features.h"
#ifndef _MMI_VCARD_C
#define _MMI_VCARD_C

#if defined(__MMI_VCARD__)

#include "CommonScreens.h"
#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhbSrvGprot.h"
#include "vObjects.h"
#include "vCard.h"
#include "vcard_lib.h"
#include "app_usedetails.h"
#include "mmi_rp_srv_vcard_def.h"
#include "mmi_rp_srv_vobject_def.h"
#include "Conversions.h"

#if defined(__MMI_FILE_MANAGER__)
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrCuiGProt.h"
#endif /* defined(__MMI_FILE_MANAGER__) */

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#include "SmsCuiGprot.h"
#endif

#if defined(__MMI_MMS__)
#include "mmsadp.h"
#if defined (OBIGO_SUPPORT)
#include "WapResDef.h"
#endif
#endif /* defined(__MMI_MMS__) */

#ifdef __MMI_OPP_SUPPORT__
#include "BTSendCUIGprot.h"
#endif

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#include "ConnectivityResDef.h"
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#include "MenuCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "CallLogSrvGProt.h"
#include "UcmSrvGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "ps_public_enum.h"
#include "mmi_rp_app_phonebook_def.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "fs_func.h"
#include "fs_type.h"
#include "kal_public_api.h"
#include "custom_phb_config.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "string.h"
#include "mms_api.h"
#include "customer_email_num.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "CommonScreensResDef.h"
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "stdio.h"
#include "PhbSrvIprot.h"
#include "ModeSwitchSrvGprot.h"

#include "MMI_common_app_trc.h"

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetsetAppGprot.h"
#endif

#define VCARD_FILE_EXT_WCHAR        L"vcf"


typedef enum
{
    MMI_VCARD_FIELD_NAME_FIRST,             /* vcard name field - family name */
    MMI_VCARD_FIELD_NAME_SECOND,            /* vcard name field - given name */
    MMI_VCARD_FIELD_NAME_THIRD,             /* vcard name field - additional name */
    MMI_VCARD_FIELD_NAME_FORTH,             /* vcard name field - name prefix */
    MMI_VCARD_FIELD_NAME_FIFTH,             /* vcard name field - name suffix */
    MMI_VCARD_FIELD_NUM_CELL,
    MMI_VCARD_FIELD_NUM_HOME,
    MMI_VCARD_FIELD_COMPANY,
    MMI_VCARD_FIELD_EMAIL,
    MMI_VCARD_FIELD_EMAIL2,
    MMI_VCARD_FIELD_NUM_OFFICE,
    MMI_VCARD_FIELD_NUM_FAX,
    MMI_VCARD_FIELD_BDAY,
    MMI_VCARD_FIELD_TITLE,
    MMI_VCARD_FIELD_URL,
    MMI_VCARD_FIELD_ADDRESS_POBOX,
    MMI_VCARD_FIELD_ADDRESS_EXTENSION,
    MMI_VCARD_FIELD_ADDRESS_STREET,
    MMI_VCARD_FIELD_ADDRESS_CITY,
    MMI_VCARD_FIELD_ADDRESS_STATE,
    MMI_VCARD_FIELD_ADDRESS_POSTALCODE,
    MMI_VCARD_FIELD_ADDRESS_COUNTRY,
    MMI_VCARD_FIELD_NOTE,
    MMI_VCARD_FIELD_CALLER_IMAGE,
    MMI_VCARD_FIELD_ENUM_TOTAL              /* enum total */
} mmi_vcard_field_enum;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    U16 src_path[SRV_FMGR_PATH_MAX_LEN + 1];                /* vcard file path */
    mmi_vcard_parse_vcard_enum type;
    U8 storage_loc;                                         /* phonebook storage to save vcard */
    mmi_vcard_field_data_struct vcard_data;                 /* vcard data */
    U16 title[MMI_VCARD_FIELD_ENUM_TOTAL];
    U16 save_path[SRV_FMGR_PATH_MAX_LEN + 1];               /* save path */
    U16 file_name[SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1]; /* save file name */
    cui_vcard_result_struct event;
} mmi_vcard_parse_vcard_cntx_sturct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_vcard_field_data_struct vcard_data;                 /* vcard data */
    mmi_vcard_version_enum version;
    U8 build_empty;
    MMI_BOOL append;
    mmi_vcard_build_vcard_enum type;
    U16 save_path[SRV_FMGR_PATH_MAX_LEN + 1];               /* save path */
    U16 file_name[SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1]; /* save file name */
    cui_vcard_result_struct event;
} mmi_vcard_build_vcard_cntx_sturct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_vcard_field_data_struct vcard_data;                 /* vcard data */
    srv_phb_contact_info_struct info;
    U16* contact_list;
    U16 contact_count;
    U16 active_index;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_vcard_version_enum version;
    cui_vcard_result_struct event;
} mmi_vcard_multi_send_cntx_sturct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    VB_HANDLE handle;
    vcard_object_struct vcard_object;                       /* vcard object */
    srv_phb_contact_info_struct *contact_info;
    MMI_BOOL is_append;
    U16* contact_list;
    U16 contact_count;
    U16 active_index;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    cui_vcard_result_struct event;
} mmi_vcard_export_vcard_cntx_sturct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    VP_HANDLE handle;
    vcard_object_struct vcard_object;                       /* vcard object */
    srv_phb_contact_info_struct *contact_info;
    U16 percentage;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    cui_vcard_result_struct event;
} mmi_vcard_import_vcard_cntx_sturct;


#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
static U16 g_mmi_vcard_bday[11];
#endif

static void mmi_vcard_util_delete_quote_file(void);


mmi_id        group_id;
mmi_sim_enum  sim_rm_id;


void mmi_vcard_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_group_close(group_id);
	
	mmi_frm_group_close(GRP_ID_VCARD_RECEVE);

}

mmi_ret mmi_vcard_sim_profile_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct * sim_evt =
        (srv_sim_ctrl_availability_changed_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
        || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_RECOVERY)
    {
    
    	if(sim_evt->sim == sim_rm_id) 
    	{
			mmi_vcard_group_close();
			sim_rm_id = MMI_SIM_NONE;
    	}
		
    }
    return MMI_RET_OK;
}

static void mmi_vcard_send_cancel_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_vcard_parse_vcard_cntx_sturct* cntx;
    mmi_vcard_field_data_struct* vcard_data;
#endif /* __MMI_PHB_CALLER_RES__ */
    cui_vcard_result_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
    vcard_data = &cntx->vcard_data;
    if (vcard_data->image_path && vcard_data->image_path[0])
    {
        FS_Delete(vcard_data->image_path);
    }
#endif /* __MMI_PHB_CALLER_RES__ */
    evt.evt_id = EVT_ID_VCARD_CANCEL;
    mmi_frm_group_send_to_parent(mmi_frm_group_get_active_id(), (mmi_group_event_struct*)&evt);
}


static void mmi_vcard_clear_all_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


static MMI_BOOL mmi_vcard_is_phb_full(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        switch (storage)
        {
            case PHB_STORAGE_NVRAM:
                str_id = STR_PHONE_FULL_MSG;
                break;
        #if (MMI_MAX_SIM_NUM >= 2)
            case PHB_STORAGE_SIM:
                str_id = STRING_MTPNP_SIM1_STORAGE_FULL;
                break;
            case PHB_STORAGE_SIM2:
                str_id = STRING_MTPNP_SIM2_STORAGE_FULL;
                break;
        #if (MMI_MAX_SIM_NUM >= 3)
            case PHB_STORAGE_SIM3:
                str_id = STR_ID_PHB_SIM3_STORAGE_FULL;
                break;
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            case PHB_STORAGE_SIM4:
                str_id = STR_ID_PHB_SIM4_STORAGE_FULL;
                break;
        #endif
        #else /* MMI_MAX_SIM_NUM */
            case PHB_STORAGE_SIM:
                str_id = STR_SIM_FULL_MSG;
                break;
        #endif /* MMI_MAX_SIM_NUM */
            case PHB_STORAGE_MAX:
            default:
                str_id = STR_PBOOK_FULL_MSG;
                break;
        }
        mmi_popup_display((UI_string_type)GetString(str_id), MMI_EVENT_FAILURE, NULL);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


static void mmi_vcard_util_delete_temp_file(U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 path_len = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete(path);
    for (i = 0; path[i]; i++)
    {
        if (path[i] == L'\\')
        {
            path_len = i + 1;
        }
    }
    path[path_len] = 0;
    FS_RemoveDir(path);
}


static void mmi_vcard_util_get_default_file(U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path,"%c:\\%s\\%s", VOBJ_DRV, VOBJ_FILE_PATH, VOBJ_VCARD_DEFAULT_FILE_NAME);
}


static S32 mmi_vcard_util_create_quote_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((kal_uint16*) VOBJ_VCARD_DRIVE_PATH, FS_READ_ONLY | FS_OPEN_DIR);

	if (fh >= FS_NO_ERROR)
	{
		FS_Close(fh);
	}
	else	/* Error handling */
	{
		fh = FS_CreateDir(VOBJ_VCARD_DRIVE_PATH);	  
	}
	
	return (S32)fh;
}

static void mmi_vcard_util_get_quote_file(U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_vcard_util_create_quote_folder();
    kal_wsprintf(path,"%w\\%s", VOBJ_VCARD_DRIVE_PATH, VOBJ_VCARD_DEFAULT_FILE_NAME);
}



static S32 mmi_vcard_util_get_default_file_by_name(U16* path, U16* f_name, U16* s_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_name[MMI_PHB_NAME_LENGTH+ 1];
    U16* temp_ptr;
    FS_HANDLE fh;
    U16 max_len = SRV_FMGR_PATH_MAX_LEN - SRV_FMGR_PATH_MAX_FILE_EXT_LEN - mmi_wcslen(path);
    S32 id = rand();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	fh = mmi_vcard_util_create_quote_folder();
   	if (fh  < 0)
   	{
   		return (S32)fh;
   	}
	
	kal_wsprintf(path,"%w\\tmp%d\\", VOBJ_VCARD_DRIVE_PATH, id);
    fh = FS_CreateDir(path);
    if (fh < 0)
	{
		return (S32)fh;
	} 

   
    srv_phb_convert_to_name(temp_name, s_name, f_name, MMI_PHB_NAME_LENGTH);

    temp_ptr = (U16*)srv_fmgr_path_skip_leading_space(temp_name);
    if (mmi_wcslen(temp_ptr) >= max_len)
    {
        temp_ptr[max_len - 1] = 0;
    }
    kal_wsprintf(path, "%w%w%s", path, temp_ptr, VOBJ_VCARD_FILE_EXT);

    fh = FS_Open(path, FS_CREATE | FS_READ_WRITE);
    FS_Close(fh);
    if (fh == FS_INVALID_FILENAME)
    {
        kal_wsprintf(path, "%c:\\%s\\~tmp%d\\~vcard%s", VOBJ_DRV, VOBJ_FILE_PATH, id, VOBJ_VCARD_FILE_EXT);
    }
    return FS_NO_ERROR;
}


static void mmi_vcard_util_delete_default_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
    mmi_vcard_util_get_default_file(path);
    FS_Delete(path);
    OslMfree(path);
}

static void mmi_vcard_util_delete_quote_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
    mmi_vcard_util_get_quote_file(path);
    FS_Delete(path);
    OslMfree(path);
}



static void mmi_vcard_util_get_tcard_file(U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path,"%c:\\%s", SRV_FMGR_CARD_DRV, VOBJ_VCARD_DEFAULT_FILE_NAME);
}


MMI_BOOL mmi_vcard_check_tcard_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
    mmi_vcard_util_get_tcard_file(path);
    fh = FS_Open(path, FS_READ_ONLY);
    if (fh < 0)
    {
        OslMfree(path);
        return MMI_FALSE;
    }

    FS_Close(fh);
    OslMfree(path);
    return MMI_TRUE;
}


#if defined(__MMI_FILE_MANAGER__)

static mmi_ret mmi_vcard_recv_from_file_mgr_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_SMS_SEND:
            {
                if (!((cui_evt_sms_send_struct*)evt)->is_send_finish)
                {
                    break;
                }
            }
        case EVT_ID_VCARD_CANCEL:
        case EVT_ID_VCARD_DONE:
            mmi_frm_group_close(GRP_ID_VCARD_RECEVE);
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_vcard_recv_from_file_mgr(CHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        return;
    }
    if (!mmi_frm_group_is_present(GRP_ID_VCARD_RECEVE))
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VCARD_RECEVE, mmi_vcard_recv_from_file_mgr_proc, NULL);
        mmi_frm_group_enter(GRP_ID_VCARD_RECEVE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        sg_id = cui_vcard_parse_vcard_creat(GRP_ID_VCARD_RECEVE);
        cui_vcard_parse_vcard_set_path(sg_id, (U16*)path);
        cui_vcard_parse_vcard_run(sg_id);
    }
    else
    {
        mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
    }
}


void mmi_vcard_fmgr_sms_forward(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    if (!mmi_frm_group_is_present(GRP_ID_VCARD_RECEVE))
    {
        mmi_id grp_id;
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VCARD_RECEVE, mmi_vcard_recv_from_file_mgr_proc, NULL);
        mmi_frm_group_enter(GRP_ID_VCARD_RECEVE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        grp_id = cui_sms_send_create(GRP_ID_VCARD_RECEVE);
        if (grp_id != GRP_ID_INVALID)
        {
            cui_sms_set_send_data_port(grp_id, VOBJ_SRC_PORT, VOBJ_VCARD_PORT);
            cui_sms_set_send_content_data_file(grp_id, (U16*)path);
            cui_sms_send_run(grp_id);
        }
        else
        {
            mmi_frm_group_close(GRP_ID_VCARD_RECEVE);
        }
    }
    else
    {
        mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
    }
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 


static void mmi_vcard_build_vcard(mmi_vcard_field_data_struct* vcard_data, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_fmgr_filetype_enum type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(vcard_object, 0, sizeof(vcard_object_struct));
    vcard_object->n.given = vcard_data->second_name;
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    vcard_object->n.family = vcard_data->first_name;
#endif
#if defined(__MMI_PHB_USIM_SUPPORT__)
    vcard_object->nickname.name = vcard_data->nick_name;
#endif
    vcard_object->tel[0].tel = vcard_data->number;
    vcard_object->tel[0].type = VCARD_TEL_TYPE_CELL;
    vcard_object->tel[0].is_preferred =
        (kal_bool)(vcard_data->default_number == SRV_PHB_ENTRY_FIELD_NUMBER);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (vcard_data->opt_num[0])
    {
        vcard_object->tel[1].tel = vcard_data->opt_num[0]->number;
        vcard_object->tel[1].type = (vcard_tel_type_enum)vcard_data->opt_num[0]->type;
        vcard_object->tel[1].is_preferred =
            (kal_bool)(vcard_data->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_1);
    }
    if (vcard_data->opt_num[1])
    {
        vcard_object->tel[2].tel = vcard_data->opt_num[1]->number;
        vcard_object->tel[2].type = (vcard_tel_type_enum)vcard_data->opt_num[1]->type;
        vcard_object->tel[2].is_preferred =
            (kal_bool)(vcard_data->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_2);
    }
    if (vcard_data->opt_num[2])
    {
        vcard_object->tel[3].tel = vcard_data->opt_num[2]->number;
        vcard_object->tel[3].type = (vcard_tel_type_enum)vcard_data->opt_num[2]->type;
        vcard_object->tel[3].is_preferred =
            (kal_bool)(vcard_data->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_3);
    }
    vcard_object->email[0].email = vcard_data->email;
    vcard_object->email[0].is_preferred = MMI_TRUE;
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    vcard_object->email[1].email = vcard_data->email2;
    vcard_object->email[1].is_preferred = MMI_FALSE;
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    vcard_object->org.name = vcard_data->company;
#endif /* (defined(__MMI_PHB_OPTIONAL_FIELD__)) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    vcard_object->bday.year = vcard_data->b_year;
    vcard_object->bday.month = vcard_data->b_month;
    vcard_object->bday.day = vcard_data->b_day;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    vcard_object->title.title = vcard_data->title;
    vcard_object->url[0].url = vcard_data->url;
    vcard_object->adr[0].post_office = vcard_data->pobox;
    vcard_object->adr[0].extended = vcard_data->extension;
    vcard_object->adr[0].street = vcard_data->street;
    vcard_object->adr[0].locality = vcard_data->city;
    vcard_object->adr[0].region = vcard_data->state;
    vcard_object->adr[0].postal_code = vcard_data->postalcode;
    vcard_object->adr[0].country = vcard_data->country;
    vcard_object->note.note = vcard_data->note;
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

#ifdef __MMI_PHB_CALLER_RES__
    if (vcard_data->image_path)
    {
        type = srv_fmgr_types_find_type_by_filename_str(vcard_data->image_path);
        switch (type)
        {
            case FMGR_TYPE_BMP:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_BMP;
                break;

        #if defined(__GDI_MEMORY_PROFILE_2__)
            case FMGR_TYPE_JPG:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_JPG;
                break;

            case FMGR_TYPE_JPEG:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_JPEG;
                break;
        #endif /* defined(__GDI_MEMORY_PROFILE_2__) */

            case FMGR_TYPE_GIF:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_GIF;
                break;

        #if defined(GDI_USING_PNG)
            case FMGR_TYPE_PNG:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_PNG;
                break;
        #endif /* defined(GDI_USING_PNG) */

            case FMGR_TYPE_WBMP:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_WBMP;
                break;

            case FMGR_TYPE_WBM:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_WBM;
                break;

        #if defined(GDI_USING_M3D)
            case FMGR_TYPE_M3D:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_M3D;
                break;
        #endif /* defined(GDI_USING_M3D) */

        #ifdef SVG12_SUPPORT
            case FMGR_TYPE_SVG:
                vcard_object->photo.type = VCARD_PHOTO_TYPE_SVG;
                break;
        #endif /* SVG12_SUPPORT */

            default:
                vcard_object->photo.file_name[0] = 0;
                return;
        }
        mmi_wcsncpy(vcard_object->photo.file_name, vcard_data->image_path, SRV_FMGR_PATH_MAX_LEN);
    }
#endif /* __MMI_PHB_CALLER_RES__ */
}


S32 mmi_vcard_writer_v21_to_file(U16* path, mmi_vcard_field_data_struct* field_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VB_HANDLE vb;
    vcard_object_struct object;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vb = vcard_open_builder(path, VCARD_OPEN_MODE_DEFAULT, &result);
    if (!vb)
    {
        return result;
    }

    mmi_vcard_build_vcard(field_content, &object);

    result = vcard_build(vb, &object);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_build_error(vb);
        vcard_close_builder(vb);
        return result;
    }

    vcard_close_builder(vb);
    return VOBJ_ERR_NO_ERROR;
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)

static void mmi_vcard_forward_sms(mmi_vcard_build_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;
    S32 result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_SMS, result);
	
    cntx->event.result = CUI_VARD_TO_SMS_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_DONE;

    if (result == FS_NO_ERROR)
    {
        path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        mmi_vcard_util_get_quote_file(path);
		
        result = mmi_vcard_writer_v21_to_file(path, &cntx->vcard_data);
		MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_BUILD_RESULT, result);	
		
        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete(path);
            mmi_popup_display_simple(
                (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
                MMI_EVENT_FAILURE,
                cntx->group_id,
                NULL);
        }
        else
        {
            cntx->child_id = cui_sms_send_create(cntx->group_id);
            if (cntx->child_id != GRP_ID_INVALID)
            {
                cui_sms_set_send_data_port(cntx->child_id, VOBJ_SRC_PORT, VOBJ_VCARD_PORT);
                cui_sms_set_send_content_data_file(cntx->child_id, path);
                cui_sms_send_run(cntx->child_id);
            }
            else
            {
                FS_Delete(path);
                mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            }
        }
        OslMfree(path);
    }
    else
    {
        /* Error Handling here. */


		if (( FS_MEDIA_CHANGED==result) && (FS_NO_ERROR!=FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM)))
	    {
	    mmi_popup_display_simple(
				(WCHAR*) get_string(STR_GLOBAL_INSERT_MEMORY_CARD),
				MMI_EVENT_FAILURE,
				cntx->group_id,
				NULL);
	    }

	    else
	    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
            MMI_EVENT_FAILURE,
            cntx->group_id,
            NULL);
		}
        
    }
}
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */


#if defined(__MMI_MMS__)

static void mmi_vcard_forward_mms_call_back(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_MMS_CALLBACK);
	
    mmi_vcard_util_delete_temp_file((U16*) param);
    OslMfree(param);
}


static void mmi_vcard_forward_mms(mmi_vcard_build_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;
    S32 result = mmi_vobj_fs_check_folder();
    mms_content_entry_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_MMS, result);
	
    cntx->event.result = CUI_VARD_TO_MMS_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_DONE;

    if (result == FS_NO_ERROR)
    {
        path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        result = mmi_vcard_util_get_default_file_by_name(path, cntx->vcard_data.first_name, cntx->vcard_data.second_name);

		MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_BUILD_RESULT, result);
        if (result == FS_NO_ERROR)
        {
            result = mmi_vcard_writer_v21_to_file(path, &cntx->vcard_data);
            if (result != VOBJ_ERR_NO_ERROR)
            {
                mmi_vcard_util_delete_temp_file(path);
                mmi_popup_display_simple(
                    (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
                    MMI_EVENT_FAILURE,
                    cntx->group_id,
                    NULL);

                OslMfree(path);
            }
            else
            {
                memset(&data, 0x00, sizeof(mms_content_entry_struct));
                data.mode = MMS_NEW_FILE;
                data.file_path = (CHAR*)path;
                data.callback = mmi_vcard_forward_mms_call_back;
                data.callback_param = path;
                mms_content_insert_hdlr_with_callback(&data);
                cntx->event.result = CUI_VARD_TO_MMS_DONE;
                mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            }
            return;
        }
    }

	if (( FS_MEDIA_CHANGED==result) && (FS_NO_ERROR!=FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM)))
	{
	mmi_popup_display_simple(
				(WCHAR*) get_string(STR_GLOBAL_INSERT_MEMORY_CARD),
				MMI_EVENT_FAILURE,
				cntx->group_id,
				NULL);
	}

	else
	{
    mmi_popup_display_simple(
        (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
        MMI_EVENT_FAILURE,
        cntx->group_id,
        NULL);
	}
    
}
#endif /* defined(__MMI_MMS__) */


#if defined(__MMI_OPP_SUPPORT__)

static void mmi_vcard_forward_bt(mmi_vcard_build_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;
    S32 result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_BT, result);
	
    cntx->event.result = CUI_VARD_TO_BT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_DONE;

    if (result == FS_NO_ERROR)
    {
        path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        mmi_vcard_util_get_quote_file(path);

        if (path[0])
        {
            result = mmi_vcard_writer_v21_to_file(path, &cntx->vcard_data);

			MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_BUILD_RESULT, result);	
            if (result != VOBJ_ERR_NO_ERROR)
            {
                FS_Delete((U16*) path);
                mmi_popup_display_simple(
                    (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
                    MMI_EVENT_FAILURE,
                    cntx->group_id,
                    NULL);
            }
            else
            {
                cui_bt_sending_para_struct para;
                cui_bt_sending_obj_struct obj;

                memset(&para, 0, sizeof(para));
                memset(&obj, 0, sizeof(obj));

                para.total = 1;
                para.option = CUI_BT_SENDIND_OPT_NORMAL;
                para.obj = &obj;

                obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
                obj.data.u.file.path = path;
                
                cui_bt_sending_launch(cntx->group_id, &para);
                cntx->event.result = CUI_VARD_TO_BT_DONE;
            }
        }
        else
        {
            mmi_popup_display_simple(
                (UI_string_type)GetString(STR_GLOBAL_ERROR),
                MMI_EVENT_FAILURE,
                cntx->group_id,
                NULL);
        }

        OslMfree(path);
    }
    else
    {

	    if (( FS_MEDIA_CHANGED==result) && (FS_NO_ERROR!=FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM)))
	    {
	    mmi_popup_display_simple(
				(WCHAR*) get_string(STR_GLOBAL_INSERT_MEMORY_CARD),
				MMI_EVENT_FAILURE,
				cntx->group_id,
				NULL);
	    }
	    else
	    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
            MMI_EVENT_FAILURE,
            cntx->group_id,
            NULL);
	    }
        
    }
}
#endif /* defined(__MMI_OPP_SUPPORT__) */ 


#if defined(__MMI_EMAIL__)

void mmi_vcard_forward_email_call_back(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_EMAIL_CALLBACK);
	
    mmi_vcard_util_delete_temp_file((U16*)param);
    OslMfree(param);
}


void mmi_vcard_forward_email(mmi_vcard_build_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* path;
    S32 result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_SEND_BY_EMAIL, result);
	
    cntx->event.result = CUI_VARD_TO_EMAIL_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_DONE;

    if (result == FS_NO_ERROR)
    {
        path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        result = mmi_vcard_util_get_default_file_by_name(path, cntx->vcard_data.first_name, cntx->vcard_data.second_name);
        if (result == FS_NO_ERROR)
        {
            result = mmi_vcard_writer_v21_to_file(path, &cntx->vcard_data);

			MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_VCARD_BUILD_RESULT, result);	
            if (result != VOBJ_ERR_NO_ERROR)
            {
                mmi_vcard_util_delete_temp_file(path);
                mmi_popup_display_simple(
                    (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
                    MMI_EVENT_FAILURE,
                    cntx->group_id,
                    NULL);
                OslMfree(path);
            }
            else
            {
                mmi_email_app_send_attch_from_vobj((CHAR*)path, mmi_vcard_forward_email_call_back);
                cntx->event.result = CUI_VARD_TO_EMAIL_DONE;
                mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            }
            return;
        }
    }
    mmi_popup_display_simple(
        (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
        MMI_EVENT_FAILURE,
        cntx->group_id,
        NULL);
}
#endif /* defined(__MMI_EMAIL__) */


S32 mmi_vcard_get_version(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VP_HANDLE vp;
    S32 result, fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vp = vcard_open_parser((U16*) path, VCARD_PROPERTY_NONE, &fs_error);
    if (!vp)
    {
        return fs_error;
    }

    result = vcard_parse(vp, NULL);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_parse_error(vp);
        vcard_close_parser(vp);
        return result;
    }

    result = vcard_get_parse_version(vp);
    if (result == VCARD_VERSION_3_0)
    {
        result = MMI_VCARD_PARSE_VERSION_30;
    }
    else
    {
        result = MMI_VCARD_PARSE_VERSION_21;
    }

    vcard_close_parser(vp);
    return result;
}


static void mmi_vcard_save_free_data_buffer(mmi_vcard_field_data_struct* vcard_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vcard_data->first_name)
    {
        OslMfree(vcard_data->first_name);
        vcard_data->first_name = NULL;
    }
    if (vcard_data->second_name)
    {
        OslMfree(vcard_data->second_name);
        vcard_data->second_name = NULL;
    }
    if (vcard_data->number)
    {
        OslMfree(vcard_data->number);
        vcard_data->number = NULL;
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        if (vcard_data->opt_num[i])
        {
            OslMfree(vcard_data->opt_num[i]);
            vcard_data->opt_num[i] = NULL;
        }
    }
    if (vcard_data->email)
    {
        OslMfree(vcard_data->email);
        vcard_data->email = NULL;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (vcard_data->email2)
    {
        OslMfree(vcard_data->email2);
        vcard_data->email2 = NULL;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (vcard_data->company)
    {
        OslMfree(vcard_data->company);
        vcard_data->company = NULL;
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#ifdef __MMI_PHB_INFO_FIELD__
    if (vcard_data->url)
    {
        OslMfree(vcard_data->url);
        vcard_data->url = NULL;
    }
    if (vcard_data->title)
    {
        OslMfree(vcard_data->title);
        vcard_data->title = NULL;
    }
    if (vcard_data->note)
    {
        OslMfree(vcard_data->note);
        vcard_data->note = NULL;
    }
    if (vcard_data->pobox)
    {
        OslMfree(vcard_data->pobox);
        vcard_data->pobox = NULL;
    }
    if (vcard_data->extension)
    {
        OslMfree(vcard_data->extension);
        vcard_data->extension = NULL;
    }
    if (vcard_data->street)
    {
        OslMfree(vcard_data->street);
        vcard_data->street = NULL;
    }
    if (vcard_data->city)
    {
        OslMfree(vcard_data->city);
        vcard_data->city = NULL;
    }
    if (vcard_data->state)
    {
        OslMfree(vcard_data->state);
        vcard_data->state = NULL;
    }
    if (vcard_data->postalcode)
    {
        OslMfree(vcard_data->postalcode);
        vcard_data->postalcode = NULL;
    }
    if (vcard_data->country)
    {
        OslMfree(vcard_data->country);
        vcard_data->country = NULL;
    }
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_PHB_CALLER_RES__
    if (vcard_data->image_path)
    {
        OslMfree(vcard_data->image_path);
        vcard_data->image_path = NULL;
    }
#endif /* __MMI_PHB_CALLER_RES__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_save_build_buffer
 * DESCRIPTION
 *  a pre- parsing vcard function. Create path and do some error handling before
 *  send file to parser.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_save_build_buffer(mmi_vcard_field_data_struct* vcard_data, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field = srv_phb_get_support_field(storage);
    U32 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field & MMI_PHB_CONTACT_FIELD_NAME)
    {
        if (storage == PHB_STORAGE_NVRAM)
        {
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            vcard_data->first_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
        #endif
        }
        vcard_data->second_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
    }
    
    if (field & MMI_PHB_CONTACT_FIELD_NICK)
    {
        vcard_data->nick_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
    }

    count = srv_phb_get_support_field_count(storage, MMI_PHB_CONTACT_FIELD_ID_NUMBER);
    vcard_data->number = OslMalloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16));
    count--;
    for (i = 0; i < count; i++)
    {
        vcard_data->opt_num[i] = OslMalloc(sizeof(mmi_phb_wcs_num_struct));
    }

    count = srv_phb_get_support_field_count(storage, MMI_PHB_CONTACT_FIELD_ID_EMAIL);
    if (count)
    {
        vcard_data->email = OslMalloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16));
        count--;
    }
    if (count)
    {
        vcard_data->email2 = OslMalloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16));
    }

    if (field & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        vcard_data->company = OslMalloc((MMI_PHB_COMPANY_LENGTH + 1) * sizeof(U16));
    }
    
    if (field & MMI_PHB_CONTACT_FIELD_URL)
    {
        vcard_data->url = OslMalloc((MMI_PHB_URL_LENGTH + 1) * sizeof(U16));
    }
    if (field & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        vcard_data->title = OslMalloc((MMI_PHB_TITLE_LENGTH + 1) * sizeof(U16));
    }
    if (field & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        vcard_data->note = OslMalloc((MMI_PHB_NOTE_LENGTH + 1) * sizeof(U16));
    }
    if (field & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        vcard_data->pobox = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->extension = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->street = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->city = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->state = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->postalcode = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        vcard_data->country = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
    }
    if (field & MMI_PHB_CONTACT_FIELD_IMAGE)
    {
        vcard_data->image_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
    }
}


static void mmi_vcard_parse_vcard(mmi_vcard_field_data_struct* vcard_data, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (vcard_data->first_name && vcard_object->n.family)
    {
        mmi_wcsncpy(vcard_data->first_name, vcard_object->n.family, MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (vcard_data->second_name && vcard_object->n.given)
    {
        if (!vcard_data->first_name && vcard_object->n.family)
        {
            srv_phb_convert_to_name(
                vcard_data->second_name,
                vcard_object->n.given,
                vcard_object->n.family,
                MMI_PHB_NAME_FIELD_LENGTH);
        }
        else
        {
            mmi_wcsncpy(vcard_data->second_name, vcard_object->n.given, MMI_PHB_NAME_FIELD_LENGTH);
        }
    }
#else /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    if (vcard_data->second_name)
    {
        srv_phb_convert_to_name(
            vcard_data->second_name,
            vcard_object->n.given,
            vcard_object->n.family,
            MMI_PHB_NAME_FIELD_LENGTH);
    }
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
#if defined(__MMI_PHB_USIM_SUPPORT__)
    if (vcard_data->nick_name && vcard_object->nickname.name)
    {
        mmi_wcsncpy(vcard_data->nick_name, vcard_object->nickname.name, MMI_PHB_NAME_FIELD_LENGTH);
    }
#endif

    if (vcard_data->number && vcard_object->tel[0].tel)
    {
        if (vcard_object->tel[0].tel[0] == L'+')
        {
            mmi_wcsncpy(vcard_data->number, vcard_object->tel[0].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(vcard_data->number, vcard_object->tel[0].tel, MMI_PHB_NUMBER_LENGTH);
        }
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (vcard_data->opt_num[0] && vcard_data->opt_num[0]->number && vcard_object->tel[1].tel)
    {
        if (vcard_object->tel[1].tel[0] == L'+')
        {
            mmi_wcsncpy(vcard_data->opt_num[0]->number, vcard_object->tel[1].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(vcard_data->opt_num[0]->number, vcard_object->tel[1].tel, MMI_PHB_NUMBER_LENGTH);
        }
        vcard_data->opt_num[0]->type = (mmi_phb_num_type_enum)vcard_object->tel[1].type;
    }
    if (vcard_data->opt_num[1] && vcard_data->opt_num[1]->number && vcard_object->tel[2].tel)
    {
        if (vcard_object->tel[2].tel[0] == L'+')
        {
            mmi_wcsncpy(vcard_data->opt_num[1]->number, vcard_object->tel[2].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(vcard_data->opt_num[1]->number, vcard_object->tel[2].tel, MMI_PHB_NUMBER_LENGTH);
        }
        vcard_data->opt_num[1]->type = (mmi_phb_num_type_enum)vcard_object->tel[2].type;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (vcard_data->opt_num[2] && vcard_data->opt_num[2]->number && vcard_object->tel[3].tel)
    {
        if (vcard_object->tel[3].tel[0] == L'+')
        {
            mmi_wcsncpy(vcard_data->opt_num[2]->number, vcard_object->tel[3].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(vcard_data->opt_num[2]->number, vcard_object->tel[3].tel, MMI_PHB_NUMBER_LENGTH);
        }
        vcard_data->opt_num[2]->type = (mmi_phb_num_type_enum)vcard_object->tel[3].type;
    }
#else /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
    if (vcard_data->opt_num[2] && vcard_data->opt_num[2]->number)
    {
        vcard_data->opt_num[2]->number[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
#if defined(__MMI_PHB_DEFAULT_NUMBER__)
    if (vcard_object->tel[0].is_preferred)
    {
        vcard_data->default_number = SRV_PHB_ENTRY_FIELD_NUMBER;
    }
    else if (vcard_object->tel[1].is_preferred)
    {
        vcard_data->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
    }
    else if (vcard_object->tel[2].is_preferred)
    {
        vcard_data->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
    }
    else if (vcard_object->tel[3].is_preferred)
    {
        vcard_data->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
    }
    else
    {
        vcard_data->default_number = 0xFE;
    }
#endif /* defined(__MMI_PHB_DEFAULT_NUMBER__) */
    if (vcard_data->email && vcard_object->email[0].email)
    {
        mmi_wcsncpy(vcard_data->email, vcard_object->email[0].email, MMI_PHB_EMAIL_LENGTH);
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (vcard_data->email2 && vcard_object->email[1].email)
    {
        mmi_wcsncpy(vcard_data->email2, vcard_object->email[1].email, MMI_PHB_EMAIL_LENGTH);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (vcard_data->company && vcard_object->org.name)
    {
        mmi_wcsncpy(vcard_data->company, vcard_object->org.name, MMI_PHB_COMPANY_LENGTH);
    }
#else /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (vcard_data->email2)
    {
        vcard_data->email2[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (vcard_data->company)
    {
        vcard_data->company[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
#endif /* (defined(__MMI_PHB_OPTIONAL_FIELD__)) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    vcard_data->b_year = vcard_object->bday.year;
    vcard_data->b_month = vcard_object->bday.month;
    vcard_data->b_day = vcard_object->bday.day;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (vcard_data->title && vcard_object->title.title)
    {
        mmi_wcsncpy(vcard_data->title, vcard_object->title.title, MMI_PHB_TITLE_LENGTH);
    }
    if (vcard_data->url && vcard_object->url[0].url)
    {
        mmi_wcsncpy(vcard_data->url, vcard_object->url[0].url, MMI_PHB_URL_LENGTH);
    }
    if (vcard_data->pobox && vcard_object->adr[0].post_office)
    {
        mmi_wcsncpy(vcard_data->pobox, vcard_object->adr[0].post_office, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->extension && vcard_object->adr[0].extended)
    {
        mmi_wcsncpy(vcard_data->extension, vcard_object->adr[0].extended, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->street && vcard_object->adr[0].street)
    {
        mmi_wcsncpy(vcard_data->street, vcard_object->adr[0].street, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->city && vcard_object->adr[0].locality)
    {
        mmi_wcsncpy(vcard_data->city, vcard_object->adr[0].locality, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->state && vcard_object->adr[0].region)
    {
        mmi_wcsncpy(vcard_data->state, vcard_object->adr[0].region, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->postalcode && vcard_object->adr[0].postal_code)
    {
        mmi_wcsncpy(vcard_data->postalcode, vcard_object->adr[0].postal_code, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->country && vcard_object->adr[0].country)
    {
        mmi_wcsncpy(vcard_data->country, vcard_object->adr[0].country, MMI_PHB_ADDRESS_LENGTH);
    }
    if (vcard_data->note && vcard_object->note.note)
    {
        mmi_wcsncpy(vcard_data->note, vcard_object->note.note, MMI_PHB_NOTE_LENGTH);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

#ifdef __MMI_PHB_CALLER_RES__
    if (vcard_data->image_path && vcard_object->photo.file_name)
    {
        mmi_wcsncpy(vcard_data->image_path, vcard_object->photo.file_name, SRV_FMGR_PATH_MAX_LEN);
    }
#endif /* __MMI_PHB_CALLER_RES__ */
}


S32 mmi_vcard_parse_file(U16* path, mmi_vcard_field_data_struct* vcard_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VP_HANDLE vp;
    vcard_object_struct *object_p;
    S32 result, fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vp = vcard_open_parser(path, VCARD_PROPERTY_ALL, &fs_error);
    if (!vp)
    {
        return fs_error;
    }
	
    result = vcard_parse(vp, &object_p);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_parse_error(vp);
        vcard_close_parser(vp);
        return result;
    }

    mmi_vcard_parse_vcard(vcard_data, object_p);

    vcard_close_parser(vp);
    return MMI_VCARD_PARSE_NO_ERROR;
}


static MMI_BOOL mmi_vcard_parse_file_to_phb(U16* path, mmi_vcard_field_data_struct* vcard_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = MMI_VCARD_PARSE_NO_ERROR;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_vcard_parse_file(path, vcard_data);
    if (error_code == MMI_VCARD_PARSE_NO_ERROR)
    {
        return MMI_TRUE;
    }

    do
    {
        if (error_code == MMI_VCARD_PARSE_FILE_SIZE_TOO_LARGE)
        {
            str_id = STR_ID_VCARD_FILE_TO_LARGE;
            break;
        }
        if (error_code < 0)
        {
            str_id = (U16)srv_fmgr_fs_error_get_string(error_code);
            break;
        }
        str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
    } while (0);
    
    mmi_popup_display((UI_string_type)GetString(str_id), MMI_EVENT_FAILURE, NULL);

    return MMI_FALSE;
}


static void mmi_vcard_save_to_phb_callback(S32 result, U16 store_index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx = (mmi_vcard_parse_vcard_cntx_sturct*)user_data;
    U16 string_id;
    mmi_event_notify_enum popup_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->event.result = CUI_VARD_TO_SMS_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_DONE;

    if (result >= SRV_PHB_NO_ERROR)
    {
        if (cntx->storage_loc == PHB_STORAGE_SIM)
        {
            cntx->event.result = CUI_VARD_TO_SIM_DONE;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if (cntx->storage_loc == PHB_STORAGE_SIM2)
        {
            cntx->event.result = CUI_VARD_TO_SIM2_DONE;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (cntx->storage_loc == PHB_STORAGE_SIM3)
        {
            cntx->event.result = CUI_VARD_TO_SIM3_DONE;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (cntx->storage_loc == PHB_STORAGE_SIM4)
        {
            cntx->event.result = CUI_VARD_TO_SIM4_DONE;
        }
    #endif
    #endif /* MMI_MAX_SIM_NUM */
        else
        {
            cntx->event.result = CUI_VARD_TO_PHONE_DONE;
        }
    }
    else
    {
        if (cntx->storage_loc == PHB_STORAGE_SIM)
        {
            cntx->event.result = CUI_VARD_TO_SIM_FAIL;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if (cntx->storage_loc == PHB_STORAGE_SIM2)
        {
            cntx->event.result = CUI_VARD_TO_SIM2_FAIL;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (cntx->storage_loc == PHB_STORAGE_SIM3)
        {
            cntx->event.result = CUI_VARD_TO_SIM3_FAIL;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (cntx->storage_loc == PHB_STORAGE_SIM4)
        {
            cntx->event.result = CUI_VARD_TO_SIM4_FAIL;
        }
    #endif
    #endif /* MMI_MAX_SIM_NUM */
        else
        {
            cntx->event.result = CUI_VARD_TO_PHONE_FAIL;
        }
    }
    string_id = mmi_phb_get_error_string(result, &popup_type, store_index);
    mmi_popup_display_simple(
        (UI_string_type)GetString(string_id),
        popup_type,
        cntx->group_id,
        NULL);
}


static void mmi_vcard_build_contact_info(srv_phb_contact_info_struct* contact_info, mmi_vcard_field_data_struct* vcard_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(contact_info, 0, sizeof(srv_phb_contact_info_struct));
    if (vcard_data->second_name)
    {
        contact_info->field_data.name = vcard_data->second_name;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_NAME;
    }
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (vcard_data->first_name)
    {
        contact_info->field_data.l_name = vcard_data->first_name;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_NAME;
    }
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */
#if defined(__MMI_PHB_USIM_SUPPORT__)
    if (vcard_data->nick_name)
    {
        contact_info->field_data.n_name = vcard_data->nick_name;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_NICK;
    }
#endif
    if (vcard_data->number)
    {
        contact_info->field_data.number = vcard_data->number;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_NUMBER;
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (vcard_data->opt_num[0])
    {
        contact_info->field_data.opt_num[0] = vcard_data->opt_num[0];
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
    }
    if (vcard_data->opt_num[1])
    {
        contact_info->field_data.opt_num[1] = vcard_data->opt_num[1];
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
    }
    if (vcard_data->opt_num[2])
    {
        contact_info->field_data.opt_num[2] = vcard_data->opt_num[2];
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
    }
    if (vcard_data->email)
    {
        contact_info->field_data.email_address= vcard_data->email;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL1;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (vcard_data->email2)
    {
        contact_info->field_data.email_address2 = vcard_data->email2;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL2;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (vcard_data->company)
    {
        contact_info->field_data.company_name = vcard_data->company;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_COMPANY;
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#ifdef __MMI_PHB_INFO_FIELD__
    if (vcard_data->url)
    {
        contact_info->field_data.url = vcard_data->url;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_URL;
    }
    if (vcard_data->title)
    {
        contact_info->field_data.title = vcard_data->title;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_TITLE;
    }
    if (vcard_data->note)
    {
        contact_info->field_data.note = vcard_data->note;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_NOTE;
    }
    if (vcard_data->pobox)
    {
        contact_info->field_data.pobox = vcard_data->pobox;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->extension)
    {
        contact_info->field_data.extension = vcard_data->extension;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->street)
    {
        contact_info->field_data.street = vcard_data->street;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->city)
    {
        contact_info->field_data.city = vcard_data->city;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->state)
    {
        contact_info->field_data.state = vcard_data->state;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->postalcode)
    {
        contact_info->field_data.postalcode = vcard_data->postalcode;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (vcard_data->country)
    {
        contact_info->field_data.country = vcard_data->country;
        contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_PHB_CALLER_RES__
    contact_info->field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_ID;
    if (vcard_data->image_path)
    {
        contact_info->field_data.image_path = vcard_data->image_path;
        if (vcard_data->image_path[0])
        {
            contact_info->field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_FILE;
        }
    }
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_PIC;
#endif /* __MMI_PHB_CALLER_RES__ */

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    contact_info->field_data.default_number = vcard_data->default_number;
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_DEF;
#endif /* __MMI_PHB_DEFAULT_NUMBER__ */
    contact_info->field_data.b_day = vcard_data->b_day;
    contact_info->field_data.b_month= vcard_data->b_month;
    contact_info->field_data.b_year= vcard_data->b_year;
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_BDAY;
    
}


static MMI_BOOL mmi_vcard_check_valid_number(U16* number, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_phb_check_valid_number(number))
    {
         if (mmi_wcsstr(number, L"?"))
         {
             return MMI_FALSE;
         }
         if (storage != PHB_STORAGE_NVRAM && (mmi_wcsstr(number, L"W") || mmi_wcsstr(number, L"w")))
         {
             return MMI_FALSE;
         }
         return MMI_TRUE;
    }
    return MMI_FALSE;
}


static void mmi_vcard_parse_save_to_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx;
    mmi_vcard_field_data_struct* vcard_data;
    cui_vcard_result_struct event;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());
    vcard_data = &cntx->vcard_data;

    do
    {
        if (!mmi_phb_check_ready_with_sg_cb(GRP_ID_INVALID, MMI_TRUE))
        {
            break;
        }
        if ((vcard_data->number && !mmi_vcard_check_valid_number(vcard_data->number, cntx->storage_loc))
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            || (vcard_data->opt_num[0] && !mmi_vcard_check_valid_number(vcard_data->opt_num[0]->number, cntx->storage_loc))
            || (vcard_data->opt_num[1] && !mmi_vcard_check_valid_number(vcard_data->opt_num[1]->number, cntx->storage_loc))
            || (vcard_data->opt_num[2] && !mmi_vcard_check_valid_number(vcard_data->opt_num[2]->number, cntx->storage_loc))
        #endif
            )
        {
            str_id = STR_GLOBAL_INVALID_NUMBER;
            break;
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if (vcard_data->email && !applib_is_valid_email_address_unicode(vcard_data->email))
        {
            vcard_data->email[0] = 0;
        }
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        if (vcard_data->email2 && !applib_is_valid_email_address_unicode(vcard_data->email2))
        {
            vcard_data->email2[0] = 0;
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
    #if defined(__MMI_PHB_INFO_FIELD__)
        if (vcard_data->url && !srv_phb_check_valid_url(vcard_data->url))
        {
            vcard_data->url[0] = 0;
        }
    #endif
    #ifdef __MMI_PHB_CALLER_RES__
        if (vcard_data->image_path && vcard_data->image_path[0] &&
            !mmi_phb_image_check_valid_image((CHAR*) vcard_data->image_path, MMI_TRUE))
        {
            vcard_data->image_path[0] = 0;
        }
    #endif /* __MMI_PHB_CALLER_RES__ */
        {
            srv_phb_contact_info_struct info;
            mmi_vcard_build_contact_info(&info, vcard_data);
            srv_phb_oplib_add_contact(cntx->storage_loc, SRV_PHB_INVALID_INDEX, &info, mmi_vcard_save_to_phb_callback, cntx);
            mmi_vcard_clear_all_event();
            return;
        }
    } while (0);

    if (str_id != 0)
    {
        mmi_popup_display((UI_string_type)GetString(str_id), MMI_EVENT_FAILURE, NULL);
    }

    if (cntx->storage_loc == PHB_STORAGE_SIM)
    {
        event.result = CUI_VARD_TO_SIM_FAIL;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (cntx->storage_loc == PHB_STORAGE_SIM2)
    {
        event.result = CUI_VARD_TO_SIM2_FAIL;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (cntx->storage_loc == PHB_STORAGE_SIM3)
    {
        event.result = CUI_VARD_TO_SIM3_FAIL;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (cntx->storage_loc == PHB_STORAGE_SIM4)
    {
        event.result = CUI_VARD_TO_SIM4_FAIL;
    }
#endif
#endif /* MMI_MAX_SIM_NUM */
    else
    {
        event.result = CUI_VARD_TO_PHONE_FAIL;
    }
    event.evt_id = EVT_ID_VCARD_DONE;
    mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&event);
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vcard_parse_entry_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_entry_recv_view_detail
 * DESCRIPTION
 *  This is the detail message of a vcard after parsing. Show details to users before saving.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vcard_parse_entry_view_detail(mmi_scrn_essential_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* items_list[MMI_VCARD_FIELD_ENUM_TOTAL];
    U16 image_list[MMI_VCARD_FIELD_ENUM_TOTAL];
    U8 *guiBuffer;
    U8 j = 0;
    mmi_vcard_parse_vcard_cntx_sturct* cntx;
    mmi_vcard_field_data_struct* data;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(info->group_id, SCR_ID_VCARD_RECV_VIEW_DETAIL, NULL, (FuncPtr)mmi_vcard_parse_entry_view_detail, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(info->group_id);
    data = &cntx->vcard_data;

    if (!mmi_phb_check_ready_with_sg_cb(GRP_ID_INVALID, MMI_TRUE) || 
        !mmi_vcard_parse_file_to_phb(cntx->src_path, &cntx->vcard_data))
    {
        cui_vcard_result_struct evt;
        if (cntx->storage_loc == PHB_STORAGE_SIM)
        {
            evt.result = CUI_VARD_TO_SIM_FAIL;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if (cntx->storage_loc == PHB_STORAGE_SIM2)
        {
            evt.result = CUI_VARD_TO_SIM2_FAIL;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (cntx->storage_loc == PHB_STORAGE_SIM3)
        {
            evt.result = CUI_VARD_TO_SIM3_FAIL;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (cntx->storage_loc == PHB_STORAGE_SIM4)
        {
            evt.result = CUI_VARD_TO_SIM4_FAIL;
        }
    #endif
    #endif /* MMI_MAX_SIM_NUM */
        else
        {
            evt.result = CUI_VARD_TO_PHONE_FAIL;
        }
        evt.evt_id = EVT_ID_VCARD_DONE;
        mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&evt);
        return;
    }
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (data->first_name)
    {
        srv_phb_remove_invalid_name(data->first_name);
    }
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    srv_phb_remove_invalid_name(data->second_name);
    
#if defined(__MMI_PHB_USIM_SUPPORT__)
    if (data->nick_name)
    {
        srv_phb_remove_invalid_name(data->nick_name);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    srv_phb_remove_invalid_number(data->number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        if (data->opt_num[i])
        {
            srv_phb_remove_invalid_number(data->opt_num[i]->number);
        }
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    /* Truncated to fit buffer size */
    if (cntx->storage_loc != PHB_STORAGE_NVRAM)
    {
        srv_phb_truncate_name(data->second_name, cntx->storage_loc);
    }
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    else
    {
        if (data->b_year)
        {
            kal_wsprintf(g_mmi_vcard_bday, "%04d/%02d/%02d", data->b_year, data->b_month, data->b_day);
        }
        else
        {
            g_mmi_vcard_bday[0] = 0;
        }
    }
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* begin to associate to inline editor */
    items_list[j] = data->second_name;
    cntx->title[j] = STR_ID_PHB_NAME;
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    image_list[j++] = IMG_NAME;
	#else
	image_list[j++] = 0;
	#endif
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (data->first_name)
    {
        items_list[j] = data->first_name;
        cntx->title[j] = STR_ID_PHB_NAME;
        
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
        image_list[j++] = IMG_NAME;
	    #else
	    image_list[j++] = 0;
	    #endif
    }
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */

#if defined(__MMI_PHB_USIM_SUPPORT__)
    if (data->nick_name && data->nick_name[0])
    {
        items_list[j] = data->nick_name;
        cntx->title[j] = STR_ID_PHB_NICK_NAME;
        
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
        image_list[j++] = IMG_NAME;
	    #else
	    image_list[j++] = 0;
	    #endif
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    items_list[j] = data->number;
    cntx->title[j] = STR_ID_PHB_NUMBER;
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    image_list[j++] = IMG_MOBILE_NUMBER;
	#else
	image_list[j++] = 0;
	#endif
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        if (data->opt_num[i] && data->opt_num[i]->number[0])
        {
            items_list[j] = data->opt_num[i]->number;
            if (cntx->storage_loc == PHB_STORAGE_NVRAM)
            {
                switch (data->opt_num[i]->type)
                {
                    case MMI_PHB_NUM_TYPE_HOME:
                        cntx->title[j] = STR_HOME_NUMBER;
                        image_list[j++] = IMG_HOME_NUMBER;
                        break;
                        
                    case MMI_PHB_NUM_TYPE_OFFICE:
                        cntx->title[j] = STR_OFFICE_NUMBER;
                        image_list[j++] = IMG_OFFICE_NUMBER;
                        break;

                #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
                    case MMI_PHB_NUM_TYPE_FAX:
                        cntx->title[j] = STR_FAX_NUMBER;
                        image_list[j++] = IMG_FAX_NUMBER;
                        break;
                #endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
                        
                    case MMI_PHB_NUM_TYPE_MOBILE:
                    default:
                        cntx->title[j] = STR_ID_PHB_MOBILE_NUMBER;
                        
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                        image_list[j++] = IMG_MOBILE_NUMBER;
	                    #else
	                    image_list[j++] = 0;
	                    #endif
                        break;
                }
            }
            else
            {
                cntx->title[j] = STR_ID_PHB_MOBILE_NUMBER;
                
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                image_list[j++] = IMG_MOBILE_NUMBER;
	            #else
	            image_list[j++] = 0;
	            #endif
            }
        }
    }
    if (data->company && data->company[0])
    {
        items_list[j] = data->company;
        cntx->title[j] = STR_COMPNAY_NAME;
        image_list[j++] = IMG_COMPANY_NAME;
    }
    if (data->email && data->email[0])
    {
        items_list[j] = data->email;
        cntx->title[j] = STR_EMAIL_ADRESS;
        image_list[j++] = IMG_EMAIL_ADDRESS;
    }
    
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (data->email2 && data->email2[0])
    {
        items_list[j] = data->email2;
        cntx->title[j] = STR_EMAIL_ADRESS;
		/* MTK81195 MAUI_03095240 */ 
#if 0 //lhm: remove for option slim
    #ifndef __OP01__
/* under construction !*/
    #else
/* under construction !*/
    #endif
#else
    image_list[j++] = IMG_EMAIL_ADDRESS;
#endif //if 0
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__)*/

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (cntx->storage_loc == PHB_STORAGE_NVRAM && g_mmi_vcard_bday[0])
    {
        items_list[j] = g_mmi_vcard_bday;
        cntx->title[j] = STR_ID_PHB_BIRTHDAY;
        image_list[j++] = IMG_ID_PHB_BIRTHDAY;
    }
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    if (data->title && data->title[0])
    {
        items_list[j] = data->title;
        cntx->title[j] = STR_ID_PHB_TITLE;
        image_list[j++] = IMG_ID_PHB_TITLE;
    }
    if (data->url && data->url[0])
    {       
        items_list[j] = data->url;
        cntx->title[j] = STR_ID_PHB_URL;
        image_list[j++] = IMG_ID_PHB_URL;
    }
    if (data->pobox && data->pobox[0])
    {  
        items_list[j] = data->pobox;
        cntx->title[j] = STR_ID_PHB_ADR_POBOX;
        image_list[j++] = IMG_ID_PHB_ADR_POBOX;
    }
    if (data->extension && data->extension[0])
    {  
        items_list[j] = data->extension;
        cntx->title[j] = STR_ID_PHB_ADR_EXTENSION;
        image_list[j++] = IMG_ID_PHB_ADR_EXTENSION;
    }
    if (data->street && data->street[0])
    {  
        items_list[j] = data->street;
        cntx->title[j] = STR_ID_PHB_ADR_STREET;
        image_list[j++] = IMG_ID_PHB_ADR_STREET;
    }
    if (data->city && data->city[0])
    {  
        items_list[j] = data->city;
        cntx->title[j] = STR_ID_PHB_ADR_CITY;
        image_list[j++] = IMG_ID_PHB_ADR_CITY;
    }
    if (data->state && data->state[0])
    {  
        items_list[j] = data->state;
        cntx->title[j] = STR_ID_PHB_ADR_STATE;
        image_list[j++] = IMG_ID_PHB_ADR_STATE;
    }
    if (data->postalcode && data->postalcode[0])
    {  
        items_list[j] = data->postalcode;
        cntx->title[j] = STR_ID_PHB_ADR_POSTALCODE;
        image_list[j++] = IMG_ID_PHB_ADR_POSTALCODE;
    }
    if (data->country && data->country[0])
    {  
        items_list[j] = data->country;
        cntx->title[j] = STR_ID_PHB_ADR_COUNTRY;
        image_list[j++] = IMG_ID_PHB_ADR_COUNTRY;
    }
    if (data->note && data->note[0])
    {  
        items_list[j] = data->note;
        cntx->title[j] = STR_ID_PHB_NOTE;
        image_list[j++] = IMG_ID_PHB_NOTE;
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory84Screen(
        STR_ID_VCARD_VCARD_DETAILS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        0,
        j,
        (U8**)items_list,
        image_list,
        0,
        0,
        guiBuffer);

    ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
    SetCenterSoftkeyFunction(mmi_vcard_parse_save_to_phb, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vcard_parse_save_to_phb, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif 
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_vcard_parse_entry_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(mmi_vcard_send_cancel_event, KEY_EVENT_UP);
}


static void mmi_vcard_parse_save_to_phone(mmi_vcard_parse_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vcard_is_phb_full(PHB_STORAGE_NVRAM))
    {
        return;
    }
    cntx->event.evt_id = EVT_ID_VCARD_DONE;
    cntx->storage_loc = PHB_STORAGE_NVRAM;
    mmi_vcard_save_build_buffer(&cntx->vcard_data, PHB_STORAGE_NVRAM);
    mmi_frm_scrn_first_enter(
            cntx->group_id,
            SCR_ID_VCARD_RECV_VIEW_DETAIL, 
            (FuncPtr)mmi_vcard_parse_entry_view_detail, 
            NULL);
}


static void mmi_vcard_parse_save_to_sim(mmi_vcard_parse_vcard_cntx_sturct* cntx, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vcard_is_phb_full(storage))
    {
        return;
    }
    cntx->event.evt_id = EVT_ID_VCARD_DONE;
    cntx->storage_loc = storage;
    mmi_vcard_save_build_buffer(&cntx->vcard_data, storage);
    mmi_frm_scrn_first_enter(
            cntx->group_id,
            SCR_ID_VCARD_RECV_VIEW_DETAIL, 
            (FuncPtr)mmi_vcard_parse_entry_view_detail, 
            NULL);
}


#if defined(__MMI_FILE_MANAGER__)

static void mmi_vcard_save_file_done(mmi_id group_id, S32 result, U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vcard_result_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.result = CUI_VARD_TO_FMGR_FAIL;

    switch (result)
    {
        case VOBJ_ERR_NO_ERROR:
            mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
            evt.result = CUI_VARD_TO_FMGR_DONE;
            break;
        case VOBJ_ERR_EMPTY_NAME:
            mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME), MMI_EVENT_FAILURE, NULL);
            return;
        case VOBJ_ERR_DUPLICATE_NAME:
            mmi_popup_display((UI_string_type)GetString(STR_ID_VOBJ_DUPLICATE_FILENAME), MMI_EVENT_FAILURE, NULL);
            return;
        case VOBJ_ERR_INVALID_FILENAME:
            mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_INVALID_FILENAME), MMI_EVENT_FAILURE, NULL);
            return;
        case VOBJ_ERR_SELECT_PATH_TOO_LONG:
            mmi_popup_display((UI_string_type)GetString(STR_ID_VOBJ_FILE_PATH_TOO_LONG), MMI_EVENT_FAILURE, NULL);
            return;
        case VOBJ_ERR_UNKNOWN:
            if (path)
            {
                FS_Delete(path);
            }
            mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE, NULL);
            break;
        default:
            if (path)
            {
                FS_Delete(path);
            }
            mmi_popup_display((UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)), MMI_EVENT_FAILURE, NULL);
            if (FS_PATH_OVER_LEN_ERROR == result || FS_INVALID_FILENAME == result)
            {
                return;
            }
            break;
    }
    evt.evt_id = EVT_ID_VCARD_DONE;
    mmi_frm_group_send_to_parent(group_id, (mmi_group_event_struct*)&evt);
}


mmi_ret mmi_vcard_parse_copy_file_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int attr;
    S32 result = ((srv_fmgr_async_done_event_struct*)param)->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            mmi_vcard_parse_vcard_cntx_sturct* cntx = (mmi_vcard_parse_vcard_cntx_sturct*)param->user_data;
            if (result >= 0)
            {
                attr = FS_GetAttributes(cntx->save_path);
                attr &= ~FS_ATTR_HIDDEN;
                FS_SetAttributes(cntx->save_path, (BYTE)attr);
                mmi_vcard_save_file_done(cntx->group_id, VOBJ_ERR_NO_ERROR, cntx->save_path);
            }
            else
            {
                mmi_vcard_save_file_done(cntx->group_id, result, cntx->save_path);
            }
            break;
        }
    }
    return MMI_RET_OK;
}


static void mmi_vcard_parse_filename_editor_done(mmi_vcard_parse_vcard_cntx_sturct* cntx, cui_folder_selector_result_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result > 0)
    {
        cui_filename_editor_get_fullpath(cntx->child_id, (WCHAR *)cntx->save_path, sizeof(cntx->save_path));
        
        ret = srv_fmgr_async_move(
                cntx->src_path,
                cntx->save_path,
                0, 
                mmi_vcard_parse_copy_file_proc,
                cntx);
        mmi_vcard_clear_all_event();
		if(ret < 0)
		{
             mmi_vcard_save_file_done(cntx->group_id, ret, cntx->save_path);
		}
        return;
    }
    else if (param->result < 0)
    {
        mmi_popup_display(get_string(srv_fmgr_fs_error_get_string(param->result)), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        cui_vcard_result_struct event;
        event.evt_id = EVT_ID_VCARD_DONE;
        event.result = CUI_VARD_TO_FMGR_FAIL;
        mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&event);
    }
}


static void mmi_vcard_parse_folder_selector_done(mmi_vcard_parse_vcard_cntx_sturct* cntx, cui_folder_selector_result_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result <= 0)
    {
        cui_vcard_result_struct event;
        event.evt_id = EVT_ID_VCARD_DONE;
        event.result = CUI_VARD_TO_FMGR_FAIL;
        mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&event);
    }
    else
    {
        srv_fmgr_fileinfo_struct info;
        cui_folder_selector_get_selected_filepath(
            cntx->child_id,
            &info, 
            (WCHAR*)cntx->save_path,
            (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
        mmi_frm_group_close(cntx->child_id);
        
        cntx->file_name[0] = 0;
        cntx->child_id = cui_filename_editor_create(
                                cntx->group_id,
                                (WCHAR *)cntx->file_name,
                                sizeof(cntx->file_name),
                                SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                                (WCHAR*)cntx->save_path,
                                VCARD_FILE_EXT_WCHAR);
        cui_filename_editor_set_title(cntx->child_id, STR_GLOBAL_FILENAME, IMG_SCR_PBOOK_CAPTION);
        cui_filename_editor_run(cntx->child_id);
    }
}


static void mmi_vcard_parse_to_fmgr(mmi_vcard_parse_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->event.evt_id = EVT_ID_VCARD_DONE;
    cntx->child_id = cui_folder_selector_create(cntx->group_id, (WCHAR*)L"root", CUI_FOLDER_SELECTOR_STYLE_WRITE, 0);
    cui_folder_selector_run(cntx->child_id);
}


static void mmi_vcard_build_filename_editor_done(mmi_vcard_build_vcard_cntx_sturct* cntx, cui_folder_selector_result_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result > 0)
    {
        cui_filename_editor_get_fullpath(cntx->child_id, (WCHAR*)cntx->save_path, sizeof(cntx->save_path));
        result = mmi_vcard_writer_v21_to_file(cntx->save_path, &cntx->vcard_data);
        mmi_vcard_save_file_done(cntx->group_id, result, cntx->save_path);
    }
    else if (param->result < 0)
    {
        mmi_popup_display(get_string(srv_fmgr_fs_error_get_string(param->result)), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        cui_vcard_result_struct event;
        event.evt_id = EVT_ID_VCARD_DONE;
        event.result = CUI_VARD_TO_FMGR_FAIL;
        mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&event);
    }
}


static void mmi_vcard_build_folder_selector_done(mmi_vcard_build_vcard_cntx_sturct* cntx, cui_folder_selector_result_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result <= 0)
    {
        cui_vcard_result_struct event;
        event.evt_id = EVT_ID_VCARD_DONE;
        event.result = CUI_VARD_TO_FMGR_FAIL;
        mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&event);
    }
    else
    {
        srv_fmgr_fileinfo_struct info;
        cui_folder_selector_get_selected_filepath(
            cntx->child_id,
            &info, 
            (WCHAR*)cntx->save_path,
            (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
        srv_phb_convert_to_name(
            cntx->file_name,
            cntx->vcard_data.second_name,
            cntx->vcard_data.first_name,
            SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN);
        mmi_frm_group_close(cntx->child_id);

        cntx->child_id = cui_filename_editor_create(
                                cntx->group_id,
                                (WCHAR *)cntx->file_name,
                                sizeof(cntx->file_name),
                                SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                                (WCHAR*)cntx->save_path,
                                VCARD_FILE_EXT_WCHAR);
        cui_filename_editor_set_title(cntx->child_id, STR_GLOBAL_FILENAME, IMG_SCR_PBOOK_CAPTION);
        cui_filename_editor_run(cntx->child_id);
    }
}
#endif /* __MMI_FILE_MANAGER__ */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
void cui_menu_set_dynamic_sim_name(mmi_id owner_gid)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	mmi_sim_enum sim_id;
	WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
	U16 menu_string[] = {
#if (MMI_MAX_SIM_NUM >= 2)
		MENU_ID_VCARD_RECV_OPTION_TO_SIM,
		MENU_ID_VCARD_RECV_OPTION_TO_SIM2,
#if (MMI_MAX_SIM_NUM>=3)
		MENU_ID_VCARD_RECV_OPTION_TO_SIM3,
#if (MMI_MAX_SIM_NUM>=4)
		MENU_ID_VCARD_RECV_OPTION_TO_SIM4,
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
		};

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(srv_sim_ctrl_get_num_of_inserted() <= 1)
	{
		return;
	}

	for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
	{	
		if ((srv_mode_switch_get_current_mode() && sim_id || srv_sim_ctrl_is_available(sim_id)) &&
			(mmi_netset_get_sim_name(sim_id) != NULL)
			)
		{
			kal_wsprintf(menu_str, "%w(%w)", GetString(menu_string[i]), mmi_netset_get_sim_name(sim_id));
			cui_menu_set_item_string(owner_gid, MENU_ID_VCARD_RECV_OPTION_TO_SIM + i, menu_str);
		}  
	}
}
#endif

static mmi_ret cui_vcard_parse_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
		{
            mmi_vcard_save_free_data_buffer(&cntx->vcard_data);
            OslMfree(cntx);
            break;
        }
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            mmi_vcard_parse_folder_selector_done(cntx, (cui_folder_selector_result_event_struct*)evt);
            break;
            
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT :
            mmi_vcard_parse_filename_editor_done(cntx, (cui_folder_selector_result_event_struct*)evt);
            break;

        case EVT_ID_POPUP_QUIT:
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
		{
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__	
			cui_menu_set_dynamic_sim_name(menu_evt->sender_id);
#endif
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (((cui_menu_event_struct*)evt)->highlighted_menu_id)
            {
                case MENU_ID_VCARD_RECV_OPTION_TO_PHONE:
                    mmi_vcard_parse_save_to_phone(cntx);
                    break;

                case MENU_ID_VCARD_RECV_OPTION_TO_SIM:
                    mmi_vcard_parse_save_to_sim(cntx, PHB_STORAGE_SIM);
					sim_rm_id = MMI_SIM1;				
                    break;

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_VCARD_RECV_OPTION_TO_SIM2:
                    mmi_vcard_parse_save_to_sim(cntx, PHB_STORAGE_SIM2);
					sim_rm_id = MMI_SIM2;	
                    break;
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_VCARD_RECV_OPTION_TO_SIM3:
                    mmi_vcard_parse_save_to_sim(cntx, PHB_STORAGE_SIM3);
					sim_rm_id = MMI_SIM3;				
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_VCARD_RECV_OPTION_TO_SIM4:
                    mmi_vcard_parse_save_to_sim(cntx, PHB_STORAGE_SIM4);
					sim_rm_id = MMI_SIM4;
                    break;
            #endif
            #endif /* MMI_MAX_SIM_NUM */

            #if defined(__MMI_FILE_MANAGER__)
                case MENU_ID_VCARD_RECV_OPTION_FMGR:
                    mmi_vcard_parse_to_fmgr(cntx);
                    break;
            #endif /* defined(__MMI_FILE_MANAGER__) */

                default:
                    break;
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (cntx->event.evt_id == EVT_ID_VCARD_CANCEL)
            {
                mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            }
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_id cui_vcard_parse_vcard_creat(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = OslMalloc(sizeof(mmi_vcard_parse_vcard_cntx_sturct));
    cntx->parent_id = parent_id;
    cntx->type = MMI_VCARD_PARSE_VCARD_PHB;
    cntx->event.evt_id = EVT_ID_VCARD_CANCEL;
    memset(&cntx->vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    cntx->group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, cui_vcard_parse_vcard_proc, cntx);
	group_id = cntx->group_id;
    return cntx->group_id;
}


void cui_vcard_parse_vcard_set_path(mmi_id sg_id, U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        mmi_wcsncpy(cntx->src_path, path, SRV_FMGR_PATH_MAX_LEN);
    }
}


void cui_vcard_parse_vcard_set_type(mmi_id sg_id, mmi_vcard_parse_vcard_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cntx->type = type;
    }
}


void cui_vcard_parse_vcard_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_parse_vcard_cntx_sturct* cntx =
        (mmi_vcard_parse_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    cui_menu_type_enum menu_type;
	MMI_BOOL SIM_STATUS = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
    if (cntx->type == MMI_VCARD_PARSE_VCARD_BOTH)
    {
        menu_type = CUI_MENU_TYPE_OPTION;
    }
    else
    {
        menu_type = CUI_MENU_TYPE_APPSUB;
    }
    cntx->child_id = cui_menu_create(
                        sg_id,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        menu_type,
                        MENU_ID_VCARD_RECV_OPTION,
                        MMI_FALSE,
                        0);

    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_PHONE, MMI_FALSE);
    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM, MMI_FALSE);
#if (MMI_MAX_SIM_NUM >= 2)
    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM2, MMI_FALSE);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM3, MMI_FALSE);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM4, MMI_FALSE);
#endif
#if defined(__MMI_FILE_MANAGER__)
    cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_FMGR, MMI_FALSE);
#endif /* defined(__MMI_FILE_MANAGER__) */
#ifdef __MMI_TELEPHONY_SUPPORT__
    if ((!(srv_mode_switch_get_current_mode() && MMI_SIM1)) || !srv_sim_ctrl_is_available(MMI_SIM1))
    {
    	SIM_STATUS = srv_sim_ctrl_is_available(MMI_SIM1);
    	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_PHB_VCARD_HIDE_SIM_ITEM, MMI_SIM1, SIM_STATUS);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM, MMI_TRUE);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if ((!(srv_mode_switch_get_current_mode() && MMI_SIM2)) || !srv_sim_ctrl_is_available(MMI_SIM2))
    {
    	SIM_STATUS = srv_sim_ctrl_is_available(MMI_SIM2);
    	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_PHB_VCARD_HIDE_SIM_ITEM, MMI_SIM2, SIM_STATUS);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM2, MMI_TRUE);
    }
#endif /* MMI_MAX_SIM_NUM >= 2 */
#if (MMI_MAX_SIM_NUM >= 3)
    if ((!(srv_mode_switch_get_current_mode() && MMI_SIM3)) || !srv_sim_ctrl_is_available(MMI_SIM3))
    {
    	SIM_STATUS = srv_sim_ctrl_is_available(MMI_SIM3);
    	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_PHB_VCARD_HIDE_SIM_ITEM, MMI_SIM3, SIM_STATUS);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM3, MMI_TRUE);
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    if ((!(srv_mode_switch_get_current_mode() && MMI_SIM4))|| !srv_sim_ctrl_is_available(MMI_SIM4))
    {
    	SIM_STATUS = srv_sim_ctrl_is_available(MMI_SIM4);
    	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_PHB_VCARD_HIDE_SIM_ITEM, MMI_SIM4, SIM_STATUS);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM4, MMI_TRUE);
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif
    if (cntx->type == MMI_VCARD_PARSE_VCARD_FMGR)
    {
    	MMI_TRACE(MMI_COMMON_TRC_G4_VCARD, TRC_MMI_PHB_VCARD_TYPE, cntx->type);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_PHONE, MMI_TRUE);
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM, MMI_TRUE);
    #if (MMI_MAX_SIM_NUM >= 2)
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM2, MMI_TRUE);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM3, MMI_TRUE);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_TO_SIM4, MMI_TRUE);
    #endif
    }

#if defined(__MMI_FILE_MANAGER__)
    if (cntx->type == MMI_VCARD_PARSE_VCARD_PHB)
    {
        cui_menu_set_item_hidden(cntx->child_id, MENU_ID_VCARD_RECV_OPTION_FMGR, MMI_TRUE);
    }
#endif /* defined(__MMI_FILE_MANAGER__) */ 
    if (cntx->type == MMI_VCARD_PARSE_VCARD_PHB)
    {
        cui_menu_set_default_title(
            cntx->child_id,
            (WCHAR*)GetString(STR_CHOOSE_STORAGE_CAPTION),
            (UI_image_type)GetImage(IMG_SCR_PBOOK_CAPTION));
    }

    cui_menu_run(cntx->child_id);
}


void cui_vcard_parse_vcard_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);
}


static mmi_ret cui_vcard_build_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    mmi_vcard_build_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_build_vcard_cntx_sturct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_vcard_save_free_data_buffer(&cntx->vcard_data);
            OslMfree(cntx);
            break;

        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            mmi_vcard_build_folder_selector_done(cntx, (cui_folder_selector_result_event_struct*)evt);
            break;
            
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT :
            mmi_vcard_build_filename_editor_done(cntx, (cui_folder_selector_result_event_struct*)evt);
            break;
            
        case EVT_ID_CUI_SMS_SEND:
            {
                if (!((cui_evt_sms_send_struct*)evt)->is_send_finish)
                {
                    break;
                }
                cntx->event.result = CUI_VARD_TO_SMS_DONE;
                mmi_vcard_util_delete_default_file();
                mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            }
            break;
    #if defined(__MMI_OPP_SUPPORT__)
        case EVT_ID_CUI_BT_SENDING_SUCC:
        case EVT_ID_CUI_BT_SENDING_FAIL:
            mmi_vcard_util_delete_default_file();
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;
    #endif /* defined(__MMI_OPP_SUPPORT__) */

        case EVT_ID_POPUP_QUIT:
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_id cui_vcard_build_vcard_creat(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_build_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = OslMalloc(sizeof(mmi_vcard_parse_vcard_cntx_sturct));
    cntx->parent_id = parent_id;
    cntx->build_empty = 0;
    cntx->append = MMI_FALSE;
    cntx->type = MMI_VCARD_BUILD_VCARD_FMG;
    cntx->version = MMI_VCARD_VERSION_21;
    memset(&cntx->vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    cntx->group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, cui_vcard_build_vcard_proc, cntx);
	group_id = cntx->group_id;
    return cntx->group_id;
}


static void cui_vcard_build_vcard_copy_data(mmi_vcard_field_data_struct* src_data, mmi_vcard_field_data_struct* dest_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_data->first_name && src_data->first_name[0])
    {
        dest_data->first_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->first_name, src_data->first_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (src_data->second_name && src_data->second_name[0])
    {
        dest_data->second_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->second_name, src_data->second_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (src_data->nick_name && src_data->nick_name[0])
    {
        dest_data->nick_name = OslMalloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->nick_name, src_data->nick_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (src_data->number && src_data->number[0])
    {
        dest_data->number = OslMalloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->number, src_data->number, MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        if (src_data->opt_num[i] && src_data->opt_num[i]->number[0])
        {
            dest_data->opt_num[i] = OslMalloc(sizeof(mmi_phb_wcs_num_struct));
            memcpy(dest_data->opt_num[i], src_data->opt_num[i], sizeof(mmi_phb_wcs_num_struct));
        }
    }
    if (src_data->email && src_data->email[0])
    {
        dest_data->email = OslMalloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->email, src_data->email, MMI_PHB_EMAIL_LENGTH);
    }
    if (src_data->email2 && src_data->email2[0])
    {
        dest_data->email2 = OslMalloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->email2, src_data->email2, MMI_PHB_EMAIL_LENGTH);
    }
    if (src_data->company && src_data->company[0])
    {
        dest_data->company = OslMalloc((MMI_PHB_COMPANY_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->company, src_data->company, MMI_PHB_COMPANY_LENGTH);
    }
    if (src_data->url && src_data->url[0])
    {
        dest_data->url = OslMalloc((MMI_PHB_URL_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->url, src_data->url, MMI_PHB_URL_LENGTH);
    }
    if (src_data->title && src_data->title[0])
    {
        dest_data->title = OslMalloc((MMI_PHB_TITLE_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->title, src_data->title, MMI_PHB_TITLE_LENGTH);
    }
    if (src_data->note && src_data->note[0])
    {
        dest_data->note = OslMalloc((MMI_PHB_NOTE_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->note, src_data->note, MMI_PHB_NOTE_LENGTH);
    }
    if (src_data->pobox && src_data->pobox[0])
    {
        dest_data->pobox = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->pobox, src_data->pobox, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->extension && src_data->extension[0])
    {
        dest_data->extension = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->extension, src_data->extension, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->street && src_data->street[0])
    {
        dest_data->street = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->street, src_data->street, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->city && src_data->city[0])
    {
        dest_data->city = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->city, src_data->city, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->state && src_data->state[0])
    {
        dest_data->state = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->state, src_data->state, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->postalcode && src_data->postalcode[0])
    {
        dest_data->postalcode = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->postalcode, src_data->postalcode, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->country && src_data->country[0])
    {
        dest_data->country = OslMalloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->country, src_data->country, MMI_PHB_ADDRESS_LENGTH);
    }
    if (src_data->image_path && src_data->image_path[0])
    {
        dest_data->image_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16));
        mmi_wcsncpy(dest_data->image_path, src_data->image_path, SRV_FMGR_PATH_MAX_LEN);
    }
    dest_data->default_number = src_data->default_number;
    dest_data->b_year = src_data->b_year;
    dest_data->b_month = src_data->b_month;
    dest_data->b_day = src_data->b_day;
}


void cui_vcard_build_vcard_set_data(mmi_id sg_id, mmi_vcard_field_data_struct* vcard_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_build_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_build_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cui_vcard_build_vcard_copy_data(vcard_data, &cntx->vcard_data);
    }
}


void cui_vcard_build_vcard_set_type(mmi_id sg_id, mmi_vcard_build_vcard_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_build_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_build_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cntx->type = type;
    }
}


void cui_vcard_build_vcard_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_build_vcard_cntx_sturct* cntx;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_build_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);

    if (!(cntx->vcard_data.first_name && cntx->vcard_data.first_name[0]) 
        && !(cntx->vcard_data.second_name && cntx->vcard_data.second_name[0]))
    {
        str_id = STR_ID_VCARD_NAME_EMPTY;
        cntx->event.result = CUI_VARD_NAME_EMPTY;
    }
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_vobj_get_full_path_name(0, (CHAR*)cntx->save_path, MMI_VOBJ_UNRECOGNIZED);
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)cntx->save_path))
        {
            str_id = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
            cntx->event.result = CUI_VARD_USB_MODE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    if (str_id)
    {
        cntx->event.evt_id = EVT_ID_VCARD_DONE;
        mmi_popup_display_simple(
            (UI_string_type)GetString(str_id),
            MMI_EVENT_FAILURE,
            sg_id,
            NULL);
        return;
    }

    switch (cntx->type)
    {
    #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
        case MMI_VCARD_BUILD_VCARD_SEND_SMS:
            mmi_vcard_forward_sms(cntx);
            break;
    #endif /* __MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__ */
    
    #if defined(__MMI_MMS__)
        case MMI_VCARD_BUILD_VCARD_SEND_MMS:
            mmi_vcard_forward_mms(cntx);
            break;
    #endif /* __MMI_MMS__ */

    #if defined(__MMI_OPP_SUPPORT__)
        case MMI_VCARD_BUILD_VCARD_SEND_BT:
            mmi_vcard_forward_bt(cntx);
            break;
    #endif /* __MMI_OPP_SUPPORT__ */

    #if defined(__MMI_EMAIL__)
        case MMI_VCARD_BUILD_VCARD_SEND_EMAIL:
            mmi_vcard_forward_email(cntx);
            break;
    #endif /* __MMI_EMAIL__ */
    
        case MMI_VCARD_BUILD_VCARD_FMG:
            cntx->child_id = cui_folder_selector_create(sg_id, (WCHAR*)L"root", CUI_FOLDER_SELECTOR_STYLE_WRITE, 0);
            cui_folder_selector_run(cntx->child_id);
            break;
            
        default:
            cntx->event.evt_id = EVT_ID_VCARD_CANCEL;
            mmi_frm_group_send_to_parent(sg_id, (mmi_group_event_struct*)&cntx->event);
            break;
    }
}


void cui_vcard_build_vcard_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);
}


#if defined(__MMI_OPP_SUPPORT__)

static S32 cui_vcard_multi_send_build_next_file(mmi_vcard_multi_send_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = VOBJ_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx->active_index < cntx->contact_count)
    {
        if (srv_phb_oplib_get_contact_info(cntx->contact_list[cntx->active_index++], &cntx->info) == SRV_PHB_NO_ERROR)
        {
            if ((cntx->vcard_data.first_name && cntx->vcard_data.first_name[0]) 
                || (cntx->vcard_data.second_name && cntx->vcard_data.second_name[0]))
            {
                return mmi_vcard_writer_v21_to_file(cntx->path, &cntx->vcard_data);
            }
            else
            {
                result = VOBJ_ERR_EMPTY_NAME;
            }
        }
    }
    return result;
}


static mmi_ret cui_vcard_multi_send_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    mmi_vcard_multi_send_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_multi_send_cntx_sturct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_vcard_save_free_data_buffer(&cntx->vcard_data);
            OslMfree(cntx);
            break;

        case EVT_ID_CUI_BT_SENDING_SUCC:
        case EVT_ID_CUI_BT_SENDING_FAIL:
            if (cui_vcard_multi_send_build_next_file(cntx) == VOBJ_ERR_NO_ERROR)
            {
                cui_bt_sending_obj_struct obj;
                memset(&obj, 0, sizeof(obj));
                obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
                obj.data.u.file.path = cntx->path;
                
                cui_bt_sending_continue(cntx->child_id, &obj);
            }
            else
            {
                cui_bt_sending_continue(cntx->child_id, NULL);
            }
            break;
        case EVT_ID_CUI_BT_SENDING_DONE:
            mmi_vcard_util_delete_default_file();
            cntx->event.evt_id = EVT_ID_VCARD_DONE;
            cntx->event.result = CUI_VARD_TO_BT_DONE;
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        case EVT_ID_POPUP_QUIT:
            cntx->event.sender_id = cntx->group_id;
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_id cui_vcard_multi_send_creat(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_multi_send_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = OslMalloc(sizeof(mmi_vcard_multi_send_cntx_sturct));
    cntx->parent_id = parent_id;
    cntx->contact_list = NULL;
    cntx->contact_count = 0;
    cntx->active_index = 0;
    cntx->version = MMI_VCARD_VERSION_21;
    memset(&cntx->vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    cntx->group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, cui_vcard_multi_send_proc, cntx);
    return cntx->group_id;
}


void cui_vcard_multi_send_set_contact_list(mmi_id sg_id, U16* contact_list, U16 contact_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_multi_send_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_multi_send_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cntx->contact_list = contact_list;
        cntx->contact_count = contact_count;
    }
}


void cui_vcard_multi_send_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_multi_send_cntx_sturct* cntx;
    U16 str_id = 0;
    S32 result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_multi_send_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_vobj_get_full_path_name(0, (CHAR*)cntx->path, MMI_VOBJ_UNRECOGNIZED);
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)cntx->path))
        {
            str_id = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
            cntx->event.result = CUI_VARD_USB_MODE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!str_id)
    {
        if (result == FS_NO_ERROR)
        {
            mmi_vcard_save_build_buffer(&cntx->vcard_data, PHB_STORAGE_NVRAM);
            mmi_vcard_build_contact_info(&cntx->info, &cntx->vcard_data);
            mmi_vcard_util_get_quote_file(cntx->path);
            result = cui_vcard_multi_send_build_next_file(cntx);
            if (result == VOBJ_ERR_NO_ERROR)
            {
                cui_bt_sending_para_struct para;
                cui_bt_sending_obj_struct obj;
                memset(&obj, 0, sizeof(obj));
                obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
                obj.data.u.file.path = cntx->path;
                
                memset(&para, 0, sizeof(para));
                para.total = cntx->contact_count;
                para.option = CUI_BT_SENDIND_OPT_NORMAL;
                para.obj = &obj;
                cntx->child_id = cui_bt_sending_create(sg_id);
                cui_bt_sending_run(cntx->child_id, &para);
                return;
            }
        }
        if (result == VOBJ_ERR_EMPTY_NAME)
        {
            str_id = STR_ID_VCARD_NAME_EMPTY;
            cntx->event.result = CUI_VARD_NAME_EMPTY;
        }
        else if (result == VOBJ_ERR_UNKNOWN)
        {
            str_id = STR_GLOBAL_FAILED_TO_SEND;
            cntx->event.result = CUI_VARD_TO_BT_FAIL;
        }
        else
        {
            str_id = srv_fmgr_fs_error_get_string(result);
            cntx->event.result = CUI_VARD_TO_BT_FAIL;
        }
    }
    cntx->event.evt_id = EVT_ID_VCARD_DONE;
    mmi_popup_display_simple(
        (UI_string_type)GetString(str_id),
        MMI_EVENT_FAILURE,
        sg_id,
        NULL);
}


void cui_vcard_multi_send_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);
}
#endif /* defined(__MMI_OPP_SUPPORT__) */


#if defined(__MMI_MULTI_VCARD__)

#define LOCAL_FUNCTION

static MMI_BOOL g_mmi_vcard_cancel_flag;
static U16 g_mmi_vcard_success_count;
static U16 g_mmi_vcard_fail_count;
static void cui_vcard_export_vcard_build_callback(S32 error_code, void *user_data);

#define GLOBAL_FUNCTION

extern void srv_phb_convert_to_vcard_object(srv_phb_contact_info_struct *contact_p, vcard_object_struct *vcard_object);


static void mmi_vcard_cancel_exporting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vcard_cancel_flag = MMI_TRUE;
    cui_vcard_export_vcard_cancel(mmi_frm_group_get_active_id());
}


static mmi_ret mmi_vcard_cancel_exporting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            g_mmi_vcard_cancel_flag = MMI_TRUE;
            break;
            
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_vcard_cancel_exporting();
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_vcard_cancel_exporting_popup(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *title = (WCHAR*) OslMalloc(128);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_success_count <= 1)
    {
        kal_wsprintf(
            title,
            "%w\r\n%d %w",
            (WCHAR *)GetString(STR_ID_PHB_CANCELLED),
            g_mmi_vcard_success_count,
            (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE));
    }
    else
    {
        kal_wsprintf(
            title,
            "%w\r\n%d %w",
            (WCHAR *)GetString(STR_ID_PHB_CANCELLED),
            g_mmi_vcard_success_count,
            (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE2));
    }
    if (g_mmi_vcard_success_count == 0)
    {
        mmi_popup_display_simple(title, MMI_EVENT_FAILURE, sg_id, NULL);
    }
    else
    {
        mmi_popup_display_simple(title, MMI_EVENT_SUCCESS, sg_id, NULL);
    }
    OslMfree(title);
}


static void mmi_vcard_entry_exporting(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 percentage;
    WCHAR string[6];
    mmi_vcard_export_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(scrn_data->group_id);
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_vcard_entry_exporting,
            MMI_FRM_UNKNOW_SCRN))
    {
        U8 str[6];
        percentage = (cntx->active_index * 100) / cntx->contact_count;
        sprintf((CHAR*)str, "%d%%", percentage);
        mmi_asc_to_ucs2((CHAR*) string, (CHAR*) str);
        ShowCategory402Screen(
            (U8*) GetString(STR_SCR_PBOOK_CAPTION),
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_COPY_ALL_ABORT,
            (U8*)GetString(STR_ID_VCARD_EXPORTING),
            percentage,
            (U8*)string);

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
        {
            ClearInputEventHandler(MMI_DEVICE_KEY);
        }

        SetRightSoftkeyFunction(mmi_vcard_cancel_exporting, KEY_EVENT_UP);
    }
}


static void mmi_vcard_show_exporting(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(sg_id, SCR_ID_VCARD_EXPORTING, (FuncPtr)mmi_vcard_entry_exporting, NULL);

    mmi_frm_scrn_set_leave_proc(
        sg_id,
        SCR_ID_VCARD_EXPORTING,
        mmi_vcard_cancel_exporting_proc);
}


static void mmi_vcard_update_exporting(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 percentage;
    WCHAR string[6];
    mmi_vcard_export_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_VCARD_EXPORTING)
    {
        U8 str[6];
        percentage = (cntx->active_index * 100) / cntx->contact_count;
        sprintf((CHAR*)str, "%d%%", percentage);
        mmi_asc_to_ucs2((CHAR*) string, (CHAR*) str);
        UpdateCategory402Value(percentage, (U8*)string);
    }

    if (cntx->active_index == cntx->contact_count)
    {
        WCHAR *title = (WCHAR*) OslMalloc(128);
        cntx->event.result = CUI_VARD_TO_EXPORT_DONE;
        cntx->event.evt_id = EVT_ID_VCARD_EXPORT_DONE;
        if (g_mmi_vcard_success_count <= 1)
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE));
        }
        else
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE2));
        }
        if (g_mmi_vcard_success_count == 0)
        {
            mmi_popup_display_simple(title, MMI_EVENT_FAILURE, cntx->group_id, NULL);
        }
        else
        {
            mmi_popup_display_simple(title, MMI_EVENT_SUCCESS, cntx->group_id, NULL);
        }
        OslMfree(title);
    }
}


static void cui_vcard_export_vcard_build_next(mmi_vcard_export_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->active_index < cntx->contact_count)
    {
        if (srv_phb_oplib_get_contact_info(cntx->contact_list[cntx->active_index++], cntx->contact_info) == SRV_PHB_NO_ERROR)
        {
            srv_phb_convert_to_vcard_object(cntx->contact_info, &cntx->vcard_object);
            vcard_multi_build(cntx->handle, &cntx->vcard_object, cui_vcard_export_vcard_build_callback, cntx);
        }
        else
        {
            g_mmi_vcard_fail_count++;
            if (cntx->active_index == cntx->contact_count)
            {
                mmi_vcard_update_exporting(cntx->group_id);
            }
        }
    }
}


static void cui_vcard_export_vcard_build_callback(S32 error_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct *cntx = (mmi_vcard_export_vcard_cntx_sturct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_cancel_flag)
    {
        if (cntx && mmi_frm_group_is_present(cntx->group_id))
        {
            cntx->event.result = CUI_VARD_TO_EXPORT_DONE;
            cntx->event.evt_id = EVT_ID_VCARD_EXPORT_CANCEL;
            if (error_code == VCARD_NO_ERROR)
            {
                g_mmi_vcard_success_count++;
            }
            mmi_vcard_cancel_exporting_popup(cntx->group_id);
        }
        return;
    }

    if (error_code == VCARD_NO_ERROR)
    {
        g_mmi_vcard_success_count++;
        mmi_vcard_update_exporting(cntx->group_id);
        cui_vcard_export_vcard_build_next(cntx);
        return;
    }

    cntx->event.result = CUI_VARD_TO_EXPORT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_EXPORT_DONE;
    if (g_mmi_vcard_success_count == 0)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(error_code)),
            MMI_EVENT_FAILURE,
            cntx->group_id,
            NULL);
    }
    else
    {
        WCHAR *title = (WCHAR*) OslMalloc(128);
        
        if (g_mmi_vcard_success_count <= 1)
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE));
        }
        else
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_EXPORT_COMPLETE2));
        }
        mmi_popup_display_simple(title, MMI_EVENT_FAILURE, cntx->group_id, NULL);
        OslMfree(title);
    }
}


static void cui_vcard_export_vcard_build_this(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct* cntx =
        (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    S32 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_get_tcard_file(cntx->path);
    cntx->contact_info = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_VCARD);
    if (cntx->is_append)
    {
        cntx->handle = vcard_open_builder(cntx->path, VCARD_OPEN_MODE_APPEND|VCARD_OPEN_MODE_HIDDEN, &error_code);
    }
    else
    {
        cntx->handle = vcard_open_builder(cntx->path, VCARD_OPEN_MODE_HIDDEN, &error_code);
    }

    if (cntx->handle)
    {
        mmi_vcard_show_exporting(sg_id);
        cui_vcard_export_vcard_build_next(cntx);
        return;
    }

    cntx->event.result = CUI_VARD_TO_EXPORT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_EXPORT_DONE;
    mmi_popup_display_simple(
        (UI_string_type)GetString(srv_fmgr_fs_error_get_string(error_code)),
        MMI_EVENT_FAILURE,
        sg_id,
        NULL);
}


static mmi_ret cui_vcard_export_vcard_build_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_result_evt_struct *result_evt = (mmi_alert_result_evt_struct*)evt;

        switch (result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                cui_vcard_export_vcard_build_this((mmi_id)result_evt->user_tag);
                break;

            case MMI_ALERT_CNFM_NO:
                cui_vcard_export_vcard_close((mmi_id)result_evt->user_tag);
                break;

            case MMI_ALERT_INTERRUPT_EXIT:
                cui_vcard_export_vcard_close((mmi_id)result_evt->user_tag);
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


static void cui_vcard_export_vcard_build_confirm(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = sg_id;
    arg.callback = cui_vcard_export_vcard_build_confirm_proc;
    arg.user_tag = (void*)sg_id;
    mmi_confirm_display((UI_string_type)GetString(STR_ID_VCARD_EXPORT_WARNING), MMI_EVENT_QUERY, &arg);
}


static mmi_ret cui_vcard_export_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct *cntx = (mmi_vcard_export_vcard_cntx_sturct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (cntx->handle)
            {
                vcard_close_builder(cntx->handle);
                cntx->handle = NULL;
            }
            if (cntx->contact_info != NULL)
            {
                srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, cntx->contact_info);
                cntx->contact_info = NULL;
            }
            OslMfree(cntx);
            break;

        case EVT_ID_POPUP_QUIT:
            cntx->event.sender_id = cntx->group_id;
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_id cui_vcard_export_vcard_creat(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct* cntx = OslMalloc(sizeof(mmi_vcard_export_vcard_cntx_sturct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->parent_id = parent_id;
    cntx->is_append = MMI_FALSE;
    cntx->contact_list = NULL;
    cntx->contact_count = 0;
    cntx->active_index = 0;
    cntx->handle = NULL;
    cntx->contact_info = NULL;
    memset(&cntx->vcard_object, 0, sizeof(vcard_object_struct));
    cntx->group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, cui_vcard_export_vcard_proc, cntx);
    return cntx->group_id;
}


void cui_vcard_export_vcard_set_append(mmi_id sg_id, MMI_BOOL is_append)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cntx->is_append = is_append;
    }
}


void cui_vcard_export_vcard_set_contact_list(mmi_id sg_id, U16* contact_list, U16 contact_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx)
    {
        cntx->contact_list = contact_list;
        cntx->contact_count = contact_count;
    }
}


static void cui_vcard_export_vcard_cancel_callback(S32 error_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct *cntx = (mmi_vcard_export_vcard_cntx_sturct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_cancel_flag)
    {
        if (cntx && mmi_frm_group_is_present(cntx->group_id))
        {
            cntx->event.result = CUI_VARD_TO_EXPORT_DONE;
            cntx->event.evt_id = EVT_ID_VCARD_EXPORT_CANCEL;
            if (error_code == VCARD_NO_ERROR)
            {
                g_mmi_vcard_success_count++;
            }
            mmi_vcard_cancel_exporting_popup(cntx->group_id);
        }
        return;
    }
}


void cui_vcard_export_vcard_cancel(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_export_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_export_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx == NULL)
    {
        return;
    }
    vcard_cancel_build(cntx->handle, cui_vcard_export_vcard_cancel_callback);
}


void cui_vcard_export_vcard_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vcard_cancel_flag = MMI_FALSE;
    g_mmi_vcard_success_count = 0;
    g_mmi_vcard_fail_count = 0;
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
    cui_vcard_export_vcard_build_confirm(sg_id);
}


void cui_vcard_export_vcard_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);
}


#define LOCAL_FUNCTION

static void cui_vcard_import_vcard_parse_next(mmi_vcard_import_vcard_cntx_sturct* cntx);
static void cui_vcard_import_vcard_parse_callback(S32 error_code, U16 percentage, vcard_object_struct *object, void *user_data);

#define GLOBAL_FUNCTION

extern void srv_phb_convert_from_vcard_object(srv_phb_contact_info_struct *contact_p, vcard_object_struct *vcard_object);


static void mmi_vcard_cancel_importing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vcard_cancel_flag = MMI_TRUE;
    cui_vcard_import_vcard_cancel(mmi_frm_group_get_active_id());
}


static mmi_ret mmi_vcard_cancel_importing_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            g_mmi_vcard_cancel_flag = MMI_TRUE;
            break;
            
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_vcard_cancel_importing();
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_vcard_cancel_importing_popup(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *title = (WCHAR*) OslMalloc(128);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_success_count <= 1)
    {
        kal_wsprintf(
            title,
            "%w\r\n%d %w",
            (WCHAR *)GetString(STR_ID_PHB_CANCELLED),
            g_mmi_vcard_success_count,
            (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE));
    }
    else
    {
        kal_wsprintf(
            title,
            "%w\r\n%d %w",
            (WCHAR *)GetString(STR_ID_PHB_CANCELLED),
            g_mmi_vcard_success_count,
            (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE2));
    }
    if (g_mmi_vcard_success_count == 0)
    {
        mmi_popup_display_simple(title, MMI_EVENT_FAILURE, sg_id, NULL);
    }
    else
    {
        mmi_popup_display_simple(title, MMI_EVENT_SUCCESS, sg_id, NULL);
    }
    OslMfree(title);
}


static void mmi_vcard_entry_importing(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR string[6];
    mmi_vcard_import_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_import_vcard_cntx_sturct*)mmi_frm_group_get_user_data(scrn_data->group_id);
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_vcard_entry_importing,
            MMI_FRM_UNKNOW_SCRN))
    {
        U8 str[6];
        sprintf((CHAR*)str, "%d%%", cntx->percentage);
        mmi_asc_to_ucs2((CHAR*) string, (CHAR*) str);
        ShowCategory402Screen(
            (U8*) GetString(STR_SCR_PBOOK_CAPTION),
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_COPY_ALL_ABORT,
            (U8*)GetString(STR_ID_VCARD_IMPORTING),
            cntx->percentage,
            (U8*)string);

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
        {
            ClearInputEventHandler(MMI_DEVICE_KEY);
        }

        SetRightSoftkeyFunction(mmi_vcard_cancel_importing, KEY_EVENT_UP);
    }
}


static void mmi_vcard_show_importing(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(sg_id, SCR_ID_VCARD_IMPORTING, (FuncPtr)mmi_vcard_entry_importing, NULL);

    mmi_frm_scrn_set_leave_proc(
        sg_id,
        SCR_ID_VCARD_IMPORTING,
        mmi_vcard_cancel_importing_proc);
}


static void mmi_vcard_update_importing(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR string[6];
    mmi_vcard_import_vcard_cntx_sturct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_import_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_VCARD_IMPORTING)
    {
        U8 str[6];
        sprintf((CHAR*)str, "%d%%", cntx->percentage);
        mmi_asc_to_ucs2((CHAR*) string, (CHAR*) str);
        UpdateCategory402Value(cntx->percentage, (U8*)string);
    }

    if (cntx->percentage == 100)
    {
        WCHAR *title = (WCHAR*) OslMalloc(128);
        cntx->event.result = CUI_VARD_TO_IMPORT_DONE;
        cntx->event.evt_id = EVT_ID_VCARD_IMPORT_DONE;
        if (g_mmi_vcard_success_count <= 1)
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE));
        }
        else
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE2));
        }
        if (g_mmi_vcard_success_count == 0)
        {
            mmi_popup_display_simple(title, MMI_EVENT_FAILURE, cntx->group_id, NULL);
        }
        else
        {
            mmi_popup_display_simple(title, MMI_EVENT_SUCCESS, cntx->group_id, NULL);
        }
        OslMfree(title);
    }
}


static void cui_vcard_import_vcard_parse_save_to_phb_callback(S32 result, U16 store_index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct* cntx = (mmi_vcard_import_vcard_cntx_sturct*)user_data;
    U16 string_id;
    mmi_event_notify_enum popup_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_cancel_flag)
    {
        if (cntx && mmi_frm_group_is_present(cntx->group_id))
        {
            cntx->event.result = CUI_VARD_TO_IMPORT_DONE;
            cntx->event.evt_id = EVT_ID_VCARD_IMPORT_CANCEL;
            if (result >= SRV_PHB_NO_ERROR)
            {
                g_mmi_vcard_success_count++;
            }
            mmi_vcard_cancel_importing_popup(cntx->group_id);
        }
        return;
    }

    if (result >= SRV_PHB_NO_ERROR)
    {
        g_mmi_vcard_success_count++;
        mmi_vcard_update_importing(cntx->group_id);
        cui_vcard_import_vcard_parse_next(cntx);
        return;
    }

    cntx->event.result = CUI_VARD_TO_IMPORT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_IMPORT_DONE;
    string_id = mmi_phb_get_error_string(result, &popup_type, store_index);
    if (g_mmi_vcard_success_count == 0)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(string_id),
            popup_type,
            cntx->group_id,
            NULL);
    }
    else
    {
        WCHAR *title = (WCHAR*) OslMalloc(128);
        
        if (g_mmi_vcard_success_count <= 1)
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE));
        }
        else
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE2));
        }
        mmi_popup_display_simple(title, MMI_EVENT_FAILURE, cntx->group_id, NULL);
        OslMfree(title);
    }
}


static void cui_vcard_import_vcard_parse_save_to_phb(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct* cntx;
    srv_phb_contact_info_struct *contact_info;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cntx = (mmi_vcard_import_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx == NULL)
    {
        return;
    }
    contact_info = cntx->contact_info;

    if (contact_info->field_data.number && !mmi_vcard_check_valid_number(contact_info->field_data.number, PHB_STORAGE_NVRAM))
    {
        contact_info->field_data.number[0] = 0;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        if (contact_info->field_data.opt_num[i]->number &&
            !mmi_vcard_check_valid_number(contact_info->field_data.opt_num[i]->number, PHB_STORAGE_NVRAM))
        {
            contact_info->field_data.opt_num[i]->number[0] = 0;
        }
    }
    if (contact_info->field_data.email_address &&
        !applib_is_valid_email_address_unicode(contact_info->field_data.email_address))
    {
        contact_info->field_data.email_address[0] = 0;
    }
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    if (contact_info->field_data.email_address2 &&
        !applib_is_valid_email_address_unicode(contact_info->field_data.email_address2))
    {
        contact_info->field_data.email_address2[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
#if defined(__MMI_PHB_INFO_FIELD__)
    if (contact_info->field_data.url && !srv_phb_check_valid_url(contact_info->field_data.url))
    {
        contact_info->field_data.url[0] = 0;
    }
#endif

    if ((contact_info->field_data.name && contact_info->field_data.name[0]) ||
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
        (contact_info->field_data.l_name && contact_info->field_data.l_name[0]) ||
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
        (contact_info->field_data.number && contact_info->field_data.number[0]))
    {
        srv_phb_oplib_add_contact(
            PHB_STORAGE_NVRAM,
            SRV_PHB_INVALID_INDEX,
            cntx->contact_info,
            cui_vcard_import_vcard_parse_save_to_phb_callback,
            cntx);
    }
    else
    {
        g_mmi_vcard_fail_count++;
        if (cntx->percentage < 100)
		{
		    mmi_vcard_update_importing(cntx->group_id);
        	cui_vcard_import_vcard_parse_next(cntx);
		}
        else
        {
            mmi_vcard_update_importing(cntx->group_id);
        }
    }
}


static void cui_vcard_import_vcard_parse_next(mmi_vcard_import_vcard_cntx_sturct* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->percentage < 100)
    {
        vcard_multi_parse(cntx->handle, cui_vcard_import_vcard_parse_callback, cntx);
    }
}


static void cui_vcard_import_vcard_parse_callback(S32 error_code, U16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct *cntx = (mmi_vcard_import_vcard_cntx_sturct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_cancel_flag)
    {
        if (cntx && mmi_frm_group_is_present(cntx->group_id))
        {
            cntx->event.result = CUI_VARD_TO_IMPORT_DONE;
            cntx->event.evt_id = EVT_ID_VCARD_IMPORT_CANCEL;
            mmi_vcard_cancel_importing_popup(cntx->group_id);
        }
        return;
    }

    if (error_code == VCARD_NO_ERROR)
    {
        cntx->percentage = percentage;
        srv_phb_convert_from_vcard_object(cntx->contact_info, object);
        cui_vcard_import_vcard_parse_save_to_phb(cntx->group_id);
        return;
    }

    cntx->event.result = CUI_VARD_TO_IMPORT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_IMPORT_DONE;
    if (g_mmi_vcard_success_count == 0)
    {
        mmi_popup_display_simple(
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(error_code)),
            MMI_EVENT_FAILURE,
            cntx->group_id,
            NULL);
    }
    else
    {
        WCHAR *title = (WCHAR*) OslMalloc(128);
        
        if (g_mmi_vcard_success_count <= 1)
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE));
        }
        else
        {
            kal_wsprintf(title, "%d %w", g_mmi_vcard_success_count, (WCHAR *)GetString(STR_ID_VCARD_IMPORT_COMPLETE2));
        }
        mmi_popup_display_simple(title, MMI_EVENT_FAILURE, cntx->group_id, NULL);
        OslMfree(title);
    }
}


static void cui_vcard_import_vcard_parse_this(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct* cntx =
        (mmi_vcard_import_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    S32 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vcard_util_get_tcard_file(cntx->path);
    cntx->contact_info = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_VCARD);
    cntx->handle = vcard_open_parser(cntx->path, VCARD_PROPERTY_ALL, &error_code);
    if (cntx->handle)
    {
        mmi_vcard_show_importing(sg_id);
        cui_vcard_import_vcard_parse_next(cntx);
        return;
    }

    cntx->event.result = CUI_VARD_TO_IMPORT_FAIL;
    cntx->event.evt_id = EVT_ID_VCARD_IMPORT_DONE;
    mmi_popup_display_simple(
        (UI_string_type)GetString(srv_fmgr_fs_error_get_string(error_code)),
        MMI_EVENT_FAILURE,
        sg_id,
        NULL);
}


static mmi_ret cui_vcard_import_vcard_parse_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_result_evt_struct *result_evt = (mmi_alert_result_evt_struct*)evt;

        switch (result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                cui_vcard_import_vcard_parse_this((mmi_id)result_evt->user_tag);
                break;

            case MMI_ALERT_CNFM_NO:
                cui_vcard_import_vcard_close((mmi_id)result_evt->user_tag);
                break;

            case MMI_ALERT_INTERRUPT_EXIT:
                cui_vcard_import_vcard_close((mmi_id)result_evt->user_tag);
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


static void cui_vcard_import_vcard_parse_confirm(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = sg_id;
    arg.callback = cui_vcard_import_vcard_parse_confirm_proc;
    arg.user_tag = (void*)sg_id;
    mmi_confirm_display((UI_string_type)GetString(STR_ID_VCARD_IMPORT_WARNING), MMI_EVENT_QUERY, &arg);
}


static mmi_ret cui_vcard_import_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct *cntx = (mmi_vcard_import_vcard_cntx_sturct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (cntx->handle)
            {
                vcard_close_parser(cntx->handle);
                cntx->handle = NULL;
            }
            if (cntx->contact_info != NULL)
            {
                srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, cntx->contact_info);
                cntx->contact_info = NULL;
            }
            OslMfree(cntx);
            break;

        case EVT_ID_POPUP_QUIT:
            cntx->event.sender_id = cntx->group_id;
            mmi_frm_group_send_to_parent(cntx->group_id, (mmi_group_event_struct*)&cntx->event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_id cui_vcard_import_vcard_creat(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct* cntx = OslMalloc(sizeof(mmi_vcard_import_vcard_cntx_sturct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->parent_id = parent_id;
    cntx->percentage = 0;
    cntx->handle = NULL;
    cntx->contact_info = NULL;
    memset(&cntx->vcard_object, 0, sizeof(vcard_object_struct));
    cntx->group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, cui_vcard_import_vcard_proc, cntx);
    return cntx->group_id;
}


static void cui_vcard_import_vcard_cancel_callback(S32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct *cntx = (mmi_vcard_import_vcard_cntx_sturct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vcard_cancel_flag)
    {
        if (cntx && mmi_frm_group_is_present(cntx->group_id))
        {
            cntx->event.result = CUI_VARD_TO_IMPORT_DONE;
            cntx->event.evt_id = EVT_ID_VCARD_IMPORT_CANCEL;
            mmi_vcard_cancel_importing_popup(cntx->group_id);
        }
        return;
    }
}


void cui_vcard_import_vcard_cancel(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_import_vcard_cntx_sturct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_vcard_import_vcard_cntx_sturct*)mmi_frm_group_get_user_data(sg_id);
    if (cntx == NULL)
    {
        return;
    }
    vcard_cancel_parse(cntx->handle, cui_vcard_import_vcard_cancel_callback);
}


void cui_vcard_import_vcard_run(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vcard_cancel_flag = MMI_FALSE;
    g_mmi_vcard_success_count = 0;
    g_mmi_vcard_fail_count = 0;
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_NONE_FLAG);
    cui_vcard_import_vcard_parse_confirm(sg_id);
}


void cui_vcard_import_vcard_close(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(sg_id);
}
#endif /* defined(__MMI_MULTI_VCARD__) */

#endif /* defined(__MMI_VCARD__) */

#endif /* _MMI_VCARD_C */

