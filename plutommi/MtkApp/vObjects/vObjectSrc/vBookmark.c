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
 * vBookmark.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receiving vbookmark object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifndef _MMI_VBOOKMARK_C
#define _MMI_VBOOKMARK_C


#if defined(__MMI_VBOOKMARK__)

#include "vObjects.h"
#include "mmi_rp_srv_vbookmark_def.h"
#include "vBookmark.h"
#include "Conversions.h"
#include "app_qp.h"
#include "FileMgrSrvGProt.h"


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#include "SmsCuiGprot.h"
#endif

/* RHR activity */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "string.h"
#include "stdio.h"
#include "DebugInitDef_Int.h"
/* RHR activity */

/*
 * Global Variable
 */
#include"Menucuigprot.h"

/*
 * Local Variable
 */
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
static mmi_id vbkm_fmgr_sms_forward_cui_id;
static mmi_id vbkm_fmgr_sms_forward_gid;
#endif
static vbkm_context_struct g_vbkm_cntx;
static vbkm_recv_file_info_list_struct* g_vbkm_recv_file_info_list;
static vbkm_recv_medium_type_enum g_vbkm_recv_med;
static U8 vbkm_recvd_count;
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_init
 * DESCRIPTION
 *  Initialize function of vbookmark application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_vbkm_cntx.file_path, (S8*)L"");
	g_vbkm_recv_file_info_list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_deinit
 * DESCRIPTION
 *  Deinitialize function of vbookmark application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*--------------------------------------------------BEGIN vBookmark Received operation ---------------------------------------------------*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
#if defined(__MMI_FILE_MANAGER__)

/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_fmgr
 * DESCRIPTION
 *  save vbookmark to file manager, file manager will take over screen after calling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		srv_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
			if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
			}
			else
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
			}
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
			mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
			mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_save_to_fmgr(g_vbkm_cntx.file_path, filename, file_extn);
	}
	else
	{
            mmi_popup_display_simple((WCHAR*)GetString(srv_fmgr_fs_error_get_string(fh)),MMI_EVENT_ERROR,GRP_ID_ROOT,NULL);
	}
}
#endif /* defined(__MMI_FILE_MANAGER__) */
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */



#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_view
 * DESCRIPTION
 *  function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		srv_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_view(g_vbkm_cntx.file_path, filename);
	}
	else
	{
            mmi_popup_display_simple((WCHAR*)GetString(srv_fmgr_fs_error_get_string(fh)),MMI_EVENT_ERROR,GRP_ID_ROOT,NULL);
	}
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_bookmark
 * DESCRIPTION
 *  function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		srv_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
			if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
			}
			else
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
			}
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
			mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
			mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_save_to_bookmark(g_vbkm_cntx.file_path, filename, file_extn);
	}
	else
	{
            mmi_popup_display_simple((WCHAR*)GetString(srv_fmgr_fs_error_get_string(fh)),MMI_EVENT_ERROR,GRP_ID_ROOT,NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_pre_entry_options
 * DESCRIPTION
 *  pre entry func for showing vbookmark options after receiving via SMS/BT/IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin[MMI_VOBJ_VBKM], (S8*)g_vbkm_cntx.file_path, MMI_VOBJ_VBKM);
	mmi_vbkm_recv_file_entry_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_rec_file_option_proc
 * DESCRIPTION
 *  Proc function for the received vbookmark option menu CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_vbkm_rec_file_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_VBKM_RECV_OPTION_SAVE_TO_BOOKMARK)
            {
                mmi_vbkm_recv_file_save_to_bookmark();
            }
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_VBKM_RECV_OPTION_VIEW)
            {
                mmi_vbkm_recv_file_view();
                mmi_vbkm_clean_one_file_buffer();
            }
        #endif
        #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        #if defined(__MMI_FILE_MANAGER__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_VBKM_RECV_OPTION_SAVE_TO_FMGR)
            {
                mmi_vbkm_recv_file_save_to_fmgr();
            }
        #endif        
        #endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_entry_options
 * DESCRIPTION
 *  shows the screen for vbookmark options after receiving via SMS/BT/IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;
    mmi_id cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create(GRP_ID_ROOT,
                                    GRP_ID_AUTO_GEN,
                                    mmi_vbkm_rec_file_option_proc,
                                    (void*)NULL);
    mmi_frm_group_enter(group_id , MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_id = cui_menu_create(group_id,
                             CUI_MENU_SRC_TYPE_RESOURCE,
                             CUI_MENU_TYPE_FROM_RESOURCE,
                             MENU_ID_VBKM_RECV_OPTION,
                             MMI_TRUE,
                             (void*)NULL);
    cui_menu_run(cui_id);
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_file_info
 * DESCRIPTION
 *  save vbookmark to file manager, file manager will take over screen after calling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_file_info(U8* file_path, vbkm_recv_medium_type_enum med_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//FS_HANDLE fh;
	//U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	//U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	vbkm_recv_file_info_list_struct *pNode;
    vbkm_recv_file_info_list_struct *tempnode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_vbkm_recv_file_info_list)
	{
		g_vbkm_recv_file_info_list = (vbkm_recv_file_info_list_struct*)OslMalloc(sizeof(vbkm_recv_file_info_list_struct));
        memset(g_vbkm_recv_file_info_list, 0, sizeof(vbkm_recv_file_info_list_struct));
		g_vbkm_recv_file_info_list->nextNode = NULL;
        pNode = g_vbkm_recv_file_info_list;
	}
    else
    {   
        tempnode = g_vbkm_recv_file_info_list;
	    for(pNode = g_vbkm_recv_file_info_list ; pNode != NULL;)
	    {
            tempnode = pNode;
		    pNode = (vbkm_recv_file_info_list_struct*)pNode->nextNode;
	    }
		pNode = (vbkm_recv_file_info_list_struct*)OslMalloc(sizeof(vbkm_recv_file_info_list_struct));
        memset(pNode, 0, sizeof(vbkm_recv_file_info_list_struct));
		pNode->nextNode = NULL;
        tempnode->nextNode = (vbkm_recv_file_info_list_struct*)pNode;
    }

	srv_vbkm_util_get_filename_and_extn(file_path, pNode->file_info.file_name,
		pNode->file_info.file_extn);

    vbkm_recvd_count++;
	g_vbkm_recv_med = med_type;
}
/*--------------------------------------------------END vBookmark Received operation ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark forward ---------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_fmgr_sms_forward
 * DESCRIPTION
 *  Forward vbookmark to SMS from file manager.
 *  This is a intermediate function between file manager and SMS app.
 * PARAMETERS
 *  path        [IN]	vbookmark file path     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_fmgr_sms_forward(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    vbkm_fmgr_sms_forward_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_vbkm_fmgr_sms_forward_proc, NULL);
    mmi_frm_group_enter(vbkm_fmgr_sms_forward_gid, 0);
    vbkm_fmgr_sms_forward_cui_id = cui_sms_send_create(vbkm_fmgr_sms_forward_gid);  
    if(vbkm_fmgr_sms_forward_cui_id != GRP_ID_INVALID)
    {
        cui_sms_set_send_content_data_file(vbkm_fmgr_sms_forward_cui_id, (U16*)path);
        cui_sms_set_send_data_port(vbkm_fmgr_sms_forward_cui_id, VOBJ_SRC_PORT, VOBJ_VBKM_PORT);
        cui_sms_send_run(vbkm_fmgr_sms_forward_cui_id);
    }
#endif 
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_fmgr_sms_forward_proc
 * DESCRIPTION
 *  callback function for send vBookmark via SMS from FMGR
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_vbkm_fmgr_sms_forward_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_sms_send_struct *event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_SMS_SEND:
              event = (cui_evt_sms_send_struct*)evt;
              if (event ->is_send_finish)
              {
                cui_sms_send_close(vbkm_fmgr_sms_forward_cui_id);
                mmi_frm_group_close(vbkm_fmgr_sms_forward_gid);  
                vbkm_fmgr_sms_forward_cui_id = GRP_ID_INVALID;  
              }
              break;

        case EVT_ID_GROUP_DEINIT:
              vbkm_fmgr_sms_forward_cui_id = GRP_ID_INVALID;  
              break;
			  
        default:
            break;
    }
    return MMI_RET_OK;  
}
#endif
/*--------------------------------------------------END vbookmark forward ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark utilites ---------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_clean_one_file_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_clean_one_file_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vbkm_recv_file_info_list_struct *pNextNode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(vbkm_recvd_count !=0);
	if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
	{
		if(g_vbkm_recv_file_info_list)
		{
			pNextNode = (vbkm_recv_file_info_list_struct*)g_vbkm_recv_file_info_list->nextNode;
			OslMfree(g_vbkm_recv_file_info_list);
			g_vbkm_recv_file_info_list = pNextNode;
		}
	}
    vbkm_recvd_count--;
    mmi_vobj_clear_one_file_buffer();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_display_error_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_display_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY),MMI_EVENT_ERROR,GRP_ID_ROOT,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_space_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vbkm_space_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vbkm_recvd_count == VBKM_RECVD_COUNT_MAX)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

/*--------------------------------------------------END vbookmark utilites ---------------------------------------------------*/

#endif /* defined(__MMI_VBOOKMARK__) */ /* END #if defined(__MMI_VBOOKMARK__) */
#endif /* _MMI_VBOOKMARK_C */ /* END #define _MMI_VBOOKMARK_C */

