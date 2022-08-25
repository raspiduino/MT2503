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
 * Appicon.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for application icon
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
#include "MMIDataType.h"
#include "WPSSProtos.h"

#include "WallpaperDefs.h"
#include "SettingProt.h"
#include "PhoneSetup.h"
#include "PhnsetProt.h"
#include "IdleAppDef.h"
#include "Conversions.h"
#include "Menucuigprot.h"

#include "Inlinecuigprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

/* auto add by kw_check begin */
#include "GlobalResDef.h"
#include "mmi_rp_app_setting_appicon_def.h"
#include "ImeGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "wgui_inline_edit.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "gui_data_types.h"
#include "gui.h"
#include "PhoneSetupResList.h"
#include "mmi_theme_mgr.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "kal_trace.h"
#include "wgui_categories_list.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_phnset_dispchar.h"
#include "wgui_categories_multimedia.h"
#include "wgui_include.h"
#include "gdi_include.h"
#include "wgui_categories_clock.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"
#include "string.h"
#include "nvram_common_defs.h"
/* auto add by kw_check end */
#include "IdleGprot.h"
#include "PhoneSetupGprots.h"
#include "ViewSettingCommonProt.h"
#include "Appicon.h"
#include "CustVenusThemeRes.h"
#include "mmi_rp_app_profiles_def.h"
#include "wgui_categories_multimedia.h"
#include "app_mem.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_app_filemanager_def.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "MMI_trc_Int.h"
#include "FactoryGprot.h"
#include "IdleFactory.h"
#include "PhoneSetupSlim.h"
/*******************************************************************
*global 
********************************************************************/

S8 g_appicon_system_count;
U16 g_popup_string;

/*******************download app icon veriable**************************/
mmi_phnset_appicon_cntx_struct g_dl_appicon_cntx;
mmi_phnset_appicon_cntx_struct *g_appicon_cntx =&g_dl_appicon_cntx;

/*******************************************************************/
U16 mmi_phnset_get_appicon_id(void);
void  mmi_phnset_set_appicon_id(U16 activeIndex);
static MMI_BOOL mmi_phnset_set_appicon(U16 index);
static U32 mmi_phnset_appicon_get_count(void);
static void mmi_phnset_appicon_deactive(void);
static void mmi_phnset_appicon_restore_default(void);
static S32 mmi_phnset_appicon_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
static void mmi_phnset_appicon_display_popup(U16 str_id);
static MMI_BOOL mmi_phnset_appicon_check_active(void);
static MMI_BOOL mmi_phnset_set_appicon(U16 index);
static MMI_BOOL mmi_phnset_appicon_set_hightlight(void);
//void mmi_phnset_appicon_execute_active(void);

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
static MMI_BOOL PhnsetAppIconIsAppIconFileExit(void);
static MMI_BOOL PhnsetAppIconIsActiveInAppIconFolder(void);
static void mmi_phnset_appicon_refresh(U32 curr);
static MMI_BOOL mmi_phnset_get_appicon_path(U16 *buffer, U32 size);
#endif


/*******************************************************************
*reference
********************************************************************/
extern void ShowCategory129ScreenInternal(
			UI_string_type title,
			PU8 title_icon,
			U16 left_softkey,
			U16 right_softkey,
			U16 message_icon,
			U8 *history_buffer,
			PU8 message_icon2,
			U8 buf_without_header);
/*************************function*********************************/
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
static void phnsetcheckActiveAppIcon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FileItem *itr;
    S32 i;
    S32 j;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

	if (mmi_phnset_get_appicon_id() != 0xFF)
	{
		return;
	}
	if (PhnsetAppIconIsActiveInAppIconFolder())
	{
		// Insert the active item to the fist position.
		itr = g_dl_appicon_cntx.m_fileItems;
		
		for (i = 0; i < mmi_phnset_appicon_get_count(); i++, itr++)
		{
			if (itr->handle == g_dl_appicon_cntx.m_activeFileItem.handle &&
				itr->index == g_dl_appicon_cntx.m_activeFileItem.index)
			{
				break;
			}
		}

		for (j = i; j != 0; j--)
		{
			g_dl_appicon_cntx.m_fileItems[j] = g_dl_appicon_cntx.m_fileItems[j - 1];
		}

		// place the active item at the first index
		g_dl_appicon_cntx.m_fileItems[0] = g_dl_appicon_cntx.m_activeFileItem;
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "phnsetcheckActiveAppIcon g_dl_appicon_cntx.m_fileItems[0].handle =%d",g_dl_appicon_cntx.m_fileItems[0].handle);
	}
	else
	{
		if (PhnsetAppIconIsAppIconFileExit())
		{
			for ( i = (mmi_phnset_appicon_get_count() - 1); i != 0; i--)
			{
				g_dl_appicon_cntx.m_fileItems[i] = g_dl_appicon_cntx.m_fileItems[i - 1];
			}

			g_dl_appicon_cntx.m_fileItems[0].handle = INVALID_HANDLER;
		}
	}
}
static S32 mmi_phnset_appicon_get_hdlrindex(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      	
	do
	{
		if (handle == g_dl_appicon_cntx.m_lstHandle[i])
		{
			return i;
		}
	}while (++i < FOLDER_TOTAL);

	return -1;
}
static S32 mmi_phnset_appicon_sortByName(const FileItem *item1, const FileItem *item2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 *buffer1, *buffer2;
    S32 ret =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
	buffer1 = OslMalloc(sizeof(U16) * SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
	buffer2 = OslMalloc(sizeof(U16) * SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    memset(buffer1, 0 ,sizeof(U16) * SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    memset(buffer1, 0 ,sizeof(U16) * SRV_FMGR_PATH_MAX_FILE_NAME_LEN );
    if (srv_fmgr_filelist_get_filename(item1->handle, item1->index, buffer1, SRV_FMGR_PATH_MAX_FILE_NAME_LEN) == 0)
	{
		if (srv_fmgr_filelist_get_filename(item2->handle, item2->index, buffer2, SRV_FMGR_PATH_MAX_FILE_NAME_LEN) == 0)
		{
			 ret = mmi_ucs2cmp((const CHAR *)buffer1, (const CHAR *)buffer2);
             OslMfree(buffer1);
             OslMfree(buffer2);
             return ret;
		}
	}
    OslMfree(buffer1);
    OslMfree(buffer2);
	return 0;
}
static void mmi_phnset_appicon_mergeSort(cmpFuncPtr cmp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr[FOLDER_TOTAL]={0};
    U32 i;
    U32 j;
    FileItem *itr = g_appicon_cntx->m_fileItems;
	FileItem item[FOLDER_TOTAL];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    // Only support two folders right now
    do
	{
		if (curr[FOLDER_PHONE] >= g_dl_appicon_cntx.m_lstFileCnt[FOLDER_PHONE] ||
			curr[FOLDER_CARD] >= g_dl_appicon_cntx.m_lstFileCnt[FOLDER_CARD])
		{
			break;
		}
	
		item[FOLDER_PHONE].handle = g_dl_appicon_cntx.m_lstHandle[FOLDER_PHONE];
		item[FOLDER_PHONE].index = curr[FOLDER_PHONE];

		item[FOLDER_CARD].handle = g_dl_appicon_cntx.m_lstHandle[FOLDER_CARD];
		item[FOLDER_CARD].index = curr[FOLDER_CARD];

		if ((*cmp)(&item[FOLDER_PHONE], &item[FOLDER_CARD]) <= 0)
		{
			*itr = item[FOLDER_PHONE];
			curr[FOLDER_PHONE]++;
		}
		else
		{
			*itr = item[FOLDER_CARD];
			curr[FOLDER_CARD]++;
		}

		++itr;
	}while(MMI_TRUE);

	// Copy the remaining data.
	for ( i = 0; i < FOLDER_TOTAL; i++)
	{
		for ( j = curr[i]; j < g_dl_appicon_cntx.m_lstFileCnt[i]; j++)
		{
			itr->handle = g_dl_appicon_cntx.m_lstHandle[i];
			itr->index = j;

			++itr;
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_filemanager_search_end_proc
 * DESCRIPTION
 *  search file callback, get the file list
 *  Functionality:
 * PARAMETERS
 *  mmi_event_struct              
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
static mmi_ret mmi_phnset_appicon_filemanager_search_end_proc(mmi_event_struct *param)
{
 /*----------------------------------------------------------------*/
 /* Local Variables                                                */
 /*----------------------------------------------------------------*/
 /*----------------------------------------------------------------*/
 /* Code Body                                                      */
 /*----------------------------------------------------------------*/  
   switch(param->evt_id) 
    {
	    case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
			srv_fmgr_filelist_refresh_result_event_struct *evt;
			evt = (srv_fmgr_filelist_refresh_result_event_struct *)param;
			
            if (evt->result >= 0)
            {
            	g_dl_appicon_cntx.m_lstFileCnt[mmi_phnset_appicon_get_hdlrindex(evt->handle)] = srv_fmgr_filelist_count(evt->handle);
                MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_filemanager_search_end_proc g_dl_appicon_cntx.m_lstFileCnt[%d]=%d",mmi_phnset_appicon_get_hdlrindex(evt->handle),g_dl_appicon_cntx.m_lstFileCnt[mmi_phnset_appicon_get_hdlrindex(evt->handle)]);
				// Find the location of actived theme file
				if (evt->search_index >= 0)
				{
					g_dl_appicon_cntx.m_activeFileItem.handle = evt->handle;
					g_dl_appicon_cntx.m_activeFileItem.index = evt->search_index;
                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_filemanager_search_end_proc g_dl_appicon_cntx.m_activeFileItem.handle=%d,g_dl_appicon_cntx.m_activeFileItem.index=%d",g_dl_appicon_cntx.m_activeFileItem.handle,g_dl_appicon_cntx.m_activeFileItem.index);
				}
            }
			g_dl_appicon_cntx.m_waitingJob &= ~(JOB_FLAG(mmi_phnset_appicon_get_hdlrindex(evt->handle)));

			// next folder
			mmi_phnset_appicon_refresh(mmi_phnset_appicon_get_hdlrindex(evt->handle) + 1);

			if (g_dl_appicon_cntx.m_waitingJob == 0)
			{
				if ((mmi_phnset_get_appicon_id() == 0xFF) && !PhnsetAppIconIsActiveInAppIconFolder() && PhnsetAppIconIsAppIconFileExit())
				{
					g_dl_appicon_cntx.m_adjustCnt = 1;
				}
				if(g_dl_appicon_cntx.isdlActive || mmi_frm_scrn_is_present(GRP_ID_APPICON_MAIN,SCR_ID_APPICON_MAIN,MMI_FRM_NODE_ALL_FLAG ))
	            {
				    g_appicon_cntx->m_fileItems = kal_adm_alloc(g_appicon_cntx->adm_pool_id, sizeof(FileItem) * mmi_phnset_appicon_get_count());
                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_filemanager_search_end_proc g_appicon_cntx->m_fileItems=%x",g_appicon_cntx->m_fileItems);
                    mmi_phnset_appicon_mergeSort(mmi_phnset_appicon_sortByName);
                    phnsetcheckActiveAppIcon();
                    mmi_phnset_appicon_set_hightlight();
		            wgui_cat1032_refresh_list((mmi_phnset_appicon_get_count() + g_appicon_system_count), g_dl_appicon_cntx.hightlightindex, mmi_phnset_appicon_get_async_items, NULL);
                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_filemanager_search_end_proc wgui_cat1032_refresh_list");
                }
			}			
			break;
        }
		default:
			break;
    }

	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  PhnsetAppIconIsAppIconFileExit
 * DESCRIPTION
 *   confirm the active file is exit or not
 *  Functionality:
 * PARAMETERS
 *  void               
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/

static MMI_BOOL PhnsetAppIconIsAppIconFileExit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    memset(g_appicon_cntx->m_nameBuffer,0,SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
    if (mmi_phnset_get_appicon_path(g_appicon_cntx->m_nameBuffer,NVRAM_EF_DLT_APPICON_SIZE))
	{
	    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "PhnsetAppIconIsAppIconFileExit  appicon file is exit");
		return MMI_TRUE;
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "PhnsetAppIconIsAppIconFileExit  appicon file is not exit");
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  PhnsetAppIconIsActiveInAppIconFolder
 * DESCRIPTION
 *  confirm the acive file is in appicon folder
 *  Functionality:
 * PARAMETERS
 *  void               
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
static MMI_BOOL PhnsetAppIconIsActiveInAppIconFolder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
  MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "PhnsetAppIconIsActiveInAppIconFolder g_dl_appicon_cntx.m_activeFileItem.handle =%d",g_dl_appicon_cntx.m_activeFileItem.handle );
  if(g_dl_appicon_cntx.m_activeFileItem.handle ==0)
  {
    return MMI_FALSE;
  }  
  else
  {
    return MMI_TRUE;
  }  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_freset
 * DESCRIPTION
 *  reset the download appicon cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_phnset_appicon_freset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_freset");
     g_dl_appicon_cntx.m_activeFileItem.handle = 0;
	for (i = FOLDER_TOTAL; i != 0; i--)
	{
		if (g_dl_appicon_cntx.m_waitingJob & JOB_FLAG(i - 1))
		{
			srv_fmgr_filelist_abort(g_dl_appicon_cntx.m_lstHandle[i - 1]);
		}
		
		srv_fmgr_filelist_destroy(g_dl_appicon_cntx.m_lstHandle[i - 1]);

		g_dl_appicon_cntx.m_lstHandle[i - 1] = 0;
        g_dl_appicon_cntx.m_lstFileCnt[i - 1] = 0;
	}
	if(g_appicon_cntx->m_fileItems)
     {
       kal_adm_free(g_appicon_cntx->adm_pool_id,g_appicon_cntx->m_fileItems);
       g_appicon_cntx->m_fileItems = NULL;
     }
	g_dl_appicon_cntx.m_adjustCnt = 0;
	g_dl_appicon_cntx.m_waitingJob = 0;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_refresh
 * DESCRIPTION
 *   refresh the folder 
 * PARAMETERS
 *  U32 curr     folder index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_appicon_refresh(U32 curr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0; 
    U16 *pattern = NULL;
    char *strPath;
    S32 ret;
	MMI_BOOL isMatch = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if(!srv_fmgr_drivelist_get_drv_letter((SRV_FMGR_DRV_PHONE_TYPE+1),0))
	    curr++;
	if (curr < FOLDER_TOTAL)
	{	
		if ((mmi_phnset_get_appicon_id() == 0xFF) && !PhnsetAppIconIsActiveInAppIconFolder())
		{
			if (PhnsetAppIconIsAppIconFileExit())
			{
			   strPath = OslMalloc(NVRAM_EF_DLT_APPICON_SIZE * sizeof(U16));
                for (i = 0; i < FOLDER_TOTAL; i++)
				{
				   memset(strPath,0,NVRAM_EF_DLT_APPICON_SIZE * sizeof(U16));
					sprintf(strPath,"%c%s",(char)srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)g_dl_appicon_cntx.m_drvList[i]),FOLDER_NAME);
                    if (mmi_ucs2ncmp((CHAR *)strPath,(const char *)g_appicon_cntx->m_nameBuffer,mmi_ucs2strlen((CHAR *)strPath)))
					{
							isMatch = MMI_TRUE;
                            //break;
					}
				}
                OslMfree(strPath);
				// If the activated theme file is not in the theme folder, don't pattern it in theme folder
				//	to avoid the issue that there is the same file name in the theme folder
				if (isMatch)
				{
					pattern = srv_fmgr_path_get_filename_ptr((WCHAR *)g_appicon_cntx->m_nameBuffer);
                }
			}				
		}
        ret = srv_fmgr_filelist_refresh(
						g_dl_appicon_cntx.m_lstHandle[curr], 
						pattern,
						0,
						0,	// No process event
						mmi_phnset_appicon_filemanager_search_end_proc, 
						NULL); 
		if (ret == 0)
		{
			g_dl_appicon_cntx.m_waitingJob |= JOB_FLAG(curr);
		}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_refresh pattern=%s,ret=%d",pattern,ret);    
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_create_appicon_folderlist
 * DESCRIPTION
 *   get the folder handle :
 *   D:\AppIcon   and  E:\AppIcon 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_phnset_create_appicon_folderlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp_Path[40] = {0};
    CHAR appicon_path[81] = {0};
	S32 ret;
    U32 i;
    S8 j = 0;
    FMGR_FILTER filter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_dl_appicon_cntx.m_drvList[FOLDER_PHONE] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    #if defined (__FS_CARD_SUPPORT__)
    /* Card Drive -- Card */
    g_dl_appicon_cntx.m_drvList[FOLDER_CARD]  = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    #endif
	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET(&filter, (filetypes_file_type_enum)FMGR_TYPE_APPICON);
	for (i = 0; i < FOLDER_TOTAL; i++)
	{
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_create_appicon_folderlist folder g_appicon_cntx->m_drvList[%d] =%x",i,g_appicon_cntx->m_drvList[i]);
		//sprintf((CHAR *)temp_Path,"%c%s",(CHAR *)srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)g_dl_appicon_cntx.m_drvList[i]),FOLDER_NAME);
		sprintf((CHAR *)temp_Path,"%c%s",(CHAR *)g_appicon_cntx->m_drvList[i],FOLDER_NAME);
        mmi_asc_n_to_ucs2((CHAR*)appicon_path,temp_Path,sizeof(temp_Path));
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_create_appicon_folderlist folder path: %s",appicon_path);  
        ret = srv_fmgr_folder_filelist_create(
					(const WCHAR *)appicon_path, 
					&filter, 
					FS_SORT_NAME, 
					(g_appicon_cntx->m_workingBuffer + (i * SRV_FMGR_FOLDER_FILELIST_MEM_SIZE)),
					SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
					&g_dl_appicon_cntx.m_lstHandle[i]);
      MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_create_appicon_folderlist g_dl_appicon_cntx.m_lstHandle[%d]=%f ret = %d",i,g_dl_appicon_cntx.m_lstHandle[i],ret);
		//MMI_ASSERT(ret == 0);
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_dlappicon_path
 * DESCRIPTION
 *  set appicon path and set current appicon
 *  Ancestor Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        const U16
 *  b(?)        [IN]            S32
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_dlappicon_path(CHAR *path, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 errCode;
    U16 temp_path[NVRAM_EF_DLT_APPICON_SIZE+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_ucs2ncpy((char*)temp_path,path,NVRAM_EF_DLT_APPICON_SIZE);
	WriteRecord(NVRAM_EF_DLT_APPICON_LID, 1, temp_path, NVRAM_EF_DLT_APPICON_SIZE, &errCode);
    mmi_phnset_set_appicon_id(0xFF);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_appicon_path
 * DESCRIPTION
 *  This function is get appicon path
 *  Functionality:
 * PARAMETERS
 *  buffer       [OUT]            
 *  size        [IN]                  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_phnset_get_appicon_path(U16 *buffer, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 errCode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

	MMI_ASSERT(size >= NVRAM_EF_DLT_APPICON_SIZE);
    memset(buffer, 0 , sizeof(U16)*NVRAM_EF_DLT_APPICON_SIZE);
    ReadRecord(NVRAM_EF_DLT_APPICON_LID, 1, buffer, NVRAM_EF_DLT_APPICON_SIZE, &errCode);
   if (srv_fmgr_fs_path_exist((WCHAR*)buffer) < 0)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}
static U16*  mmi_phnset_dlappicon_getText(S32 pos,U16 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *extPos; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_ASSERT(pos >= 0);
    memset(g_appicon_cntx->m_nameBuffer, 0, SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
	if (!srv_fmgr_filelist_get_filepath(
						g_dl_appicon_cntx.m_fileItems[pos].handle, 
						g_dl_appicon_cntx.m_fileItems[pos].index,
						g_appicon_cntx->m_nameBuffer,
						SRV_FMGR_PATH_BUFFER_SIZE))
	{
		buffer = srv_fmgr_path_get_filename_ptr(g_appicon_cntx->m_nameBuffer);
	}
	else
	{
		buffer = NULL;
	}
	if (buffer != NULL)
	{
		extPos = srv_fmgr_path_get_extension_ptr(buffer);
		*(extPos - 1) = 0;
	}
    extPos = NULL;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_dlappicon_getText download appicon name=%s",buffer);
    return buffer;
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_isActivedFile
* DESCRIPTION
*  check current select download appicon  is  active appicon or not
* PARAMETERS
*  path   [IN]
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL  mmi_phnset_appicon_isActivedFile(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buffer;

	MMI_BOOL bActivated = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	
	buffer = (WCHAR *)OslMalloc(sizeof(WCHAR) *SRV_FMGR_PATH_BUFFER_SIZE);
	if (mmi_phnset_get_appicon_path((WCHAR *)buffer, NVRAM_EF_DLT_APPICON_SIZE))
	{
		if (mmi_ucs2cmp((CHAR *)path, (CHAR *)buffer) == 0)
		{
			bActivated = MMI_TRUE;
		}
	}
	OslMfree(buffer);

	return bActivated;
}
static MMI_BOOL mmi_phnset_set_dlappicon(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appicon_deactive();
   if(!mmi_res_set_dlt_priority_theme(path,1,&g_dl_appicon_cntx.handle))
    {
       return MMI_TRUE;
    }
   return MMI_FALSE;
}

static MMI_BOOL mmi_phnset_appicon_activeDltCache(WCHAR *path)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  S16 ret;
#ifndef __LOW_COST_SUPPORT_COMMON__  
  CHAR *cache_path;
  CHAR *temp_cache_path;
  CHAR *temp_name;
#endif  
  S32 fsRet = srv_fmgr_fs_path_exist(path);

  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/ 

#ifndef __LOW_COST_SUPPORT_COMMON__
  cache_path = (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
  temp_cache_path=  (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
  temp_name =  (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
#endif  
	if (fsRet < 0)
	{
	    mmi_popup_display_simple_ext(srv_fmgr_fs_error_get_string(fsRet), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_activeDltCache download actived fail");
	#ifndef __LOW_COST_SUPPORT_COMMON__  	
		OslMfree(temp_name);
		OslMfree(cache_path);
        OslMfree(temp_cache_path);
    #endif    
		return MMI_FALSE;
	}
    mmi_phnset_appicon_deactive();
	//
	// Slim project do not support cache, so activate it directly.
	//
#ifndef __LOW_COST_SUPPORT_COMMON__
	// always active dlt theme from cache.
	memset(cache_path, 0 ,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
    memset(temp_name, 0 ,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
	sprintf(temp_name,"%s",APPICON_CACHE_PATH);
    mmi_asc_to_ucs2(cache_path,temp_name);
	if (mmi_ucs2cmp((CHAR *)path, (CHAR *)cache_path))
	{
	    memset(temp_cache_path, 0 ,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
        memset(temp_name, 0 ,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
	    sprintf(temp_name,"%s",APPICON_TEMP_CACHE_PATH);
        mmi_asc_to_ucs2(temp_cache_path,temp_name);
		fsRet = srv_fmgr_fs_copy(path, (WCHAR *)temp_cache_path);
		if (fsRet != FS_NO_ERROR)
		{
		    mmi_popup_display_simple_ext(srv_fmgr_fs_error_get_string(fsRet), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
            OslMfree(temp_name);
			OslMfree(cache_path);
            OslMfree(temp_cache_path);
			return MMI_FALSE;
		}

		fsRet = srv_fmgr_fs_delete((WCHAR *)cache_path);
		fsRet = srv_fmgr_fs_move((WCHAR *)temp_cache_path, (WCHAR *)cache_path);
		fsRet = srv_fmgr_fs_delete((WCHAR *)temp_cache_path);
	}
	ret = mmi_phnset_set_dlappicon((WCHAR *)cache_path);
	if (ret < 0)
	{
		fsRet = srv_fmgr_fs_delete((WCHAR *)temp_cache_path);
	}
    OslMfree(temp_name);
    OslMfree(cache_path);
    OslMfree(temp_cache_path);
#else
	ret = mmi_phnset_set_dlappicon(path);
#endif
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_activeDltCache ret=%d",ret);
	return (ret >= 0 ? MMI_TRUE : MMI_FALSE);
}

static mmi_ret mmi_phnset_appicon_dl_change_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if (!mmi_phnset_appicon_activeDltCache((WCHAR*) g_appicon_cntx->m_nameBuffer))
	  {
	     MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_dl_change_callback download appicon set failed");
         mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	  }
	 else
	  {
	     MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_dl_change_callback download appicon set success");
		 g_popup_string = STR_ID_PHNSET_APPICON_CHANGED;
		 g_appicon_cntx->isformFmgr = MMI_TRUE;
         mmi_popup_display_simple_ext(STR_ID_PHNSET_APPICON_SWITCH, MMI_EVENT_PROGRESS, GRP_ID_ROOT, NULL);
         MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHNSET_APPICON_CHANGED);
	     MMI_FRM_CB_EMIT_EVENT(&evt);
         mmi_applist_theme_change_notify();
         mmi_frm_close_to_idle_group();
      }
      return MMI_RET_OK;
}
static void mmi_phnset_appicon_download_active(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_res_theme_ret_enum ret;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/ 
   ret = mmi_res_is_dlt_theme_valid((WCHAR *) g_appicon_cntx->m_nameBuffer);
   MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_download_active ret = %d",ret);
   if(ret < 0)
    {
       mmi_popup_display_simple_ext(STR_ID_PHNSET_APPICON_INVALID, MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    }
   else if(ret>0)
    {
       g_dl_appicon_cntx.isneedcomfirm = MMI_TRUE;
       mmi_phnset_appicon_display_popup(STR_ID_PHNSET_APPICON_COMPATIBLE_ASK); 
    }
   else
    {
       mmi_event_struct evt;
       //g_dl_appicon_cntx.isCorrectSet = 1;
       MMI_FRM_INIT_EVENT(&evt, 0);
       mmi_frm_post_event(&evt, mmi_phnset_appicon_dl_change_callback, NULL);
    }
}

/********************fmgr evt hdlr*****************************/
/***************************************************************************** 
 * Helper Function
 *****************************************************************************/
#ifdef __MMI_FILE_MANAGER__
static void mmi_phnset_appicon_fmgr_check_hdlr(WCHAR* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if ((mmi_phnset_get_appicon_id() == 0xFF) &&
		mmi_phnset_appicon_isActivedFile((WCHAR *)filepath))
	{
	   MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_fmgr_check_hdlr already actived");
	   mmi_popup_display_simple_ext(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);	
	   return;
	}
	mmi_ucs2cpy((CHAR *)g_appicon_cntx->m_nameBuffer, (CHAR *)filepath);
    g_dl_appicon_cntx.isdlActive = MMI_TRUE;
    mmi_phnset_appicon_display_popup(STR_ID_PHNSET_APP_ICON_CHNAGE_ASK);
}

static mmi_ret mmi_phnset_appicon_fmgr_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_fmgr_notification_adv_action_event_struct *adv_action;
    MMI_BOOL  bret;
    WCHAR *buffer = NULL;
	adv_action = (srv_fmgr_notification_adv_action_event_struct*)evt;
	if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_QUERY &&
	   adv_action->action != SRV_FMGR_NOTIFICATION_ACTION_COPY)
	{
		if (mmi_phnset_get_appicon_id() != 0xFF)
		{
		    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_fmgr_evt_hdlr current actived is system apicon");
			return MMI_RET_OK;
		}
		buffer = (WCHAR *)OslMalloc(sizeof(WCHAR) * SRV_FMGR_PATH_BUFFER_SIZE);

        bret = mmi_phnset_get_appicon_path((U16 *)buffer, SRV_FMGR_PATH_BUFFER_SIZE);
		if (!bret)
		{
			OslMfree(buffer);			
			return MMI_RET_OK;
		}
		// rename or delete file
		if(!(adv_action->src_fileinfo.attribute & FS_ATTR_DIR))
		{
			if (mmi_ucs2cmp((CHAR *)adv_action->src_filepath, (CHAR *)buffer) == 0)
			{
			    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_fmgr_evt_hdlr is actived, file rename or delete file is not allow");
				OslMfree(buffer);
				return MMI_RET_ERR;
			}
		}
		// rename or delete the folder
		else
		{			
			if (mmi_ucs2ncmp((CHAR *)adv_action->src_filepath,
								 (CHAR *)buffer, 
								 mmi_ucs2strlen((CHAR *)adv_action->src_filepath)) == 0)
			{
			    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_fmgr_evt_hdlr is actived file, rename or delete the folder is not allow");
				OslMfree(buffer);
				return MMI_RET_ERR;
			}
		}
		OslMfree(buffer);
	}

	return MMI_RET_OK;
}
void mmi_phnset_appicon_fmgr_use_enabler(mmi_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item_id)
      {
       case MENU_ID_APPICON_FMGR_ACTIVATE:       
            if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_APPLIST)
			  {
                 mmi_frm_hide_menu_item(item_id);
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
         #ifndef __MMI_SLIM_FILE_MANAGER__
/* under construction !*/
         #endif
/* under construction !*/
/* under construction !*/
        #endif  
            break;            
       default:
          break;
      }
       
}
void mmi_phnset_appicon_fmgr_use_handler(mmi_id item_id, 
										  WCHAR* filepath, 
										  srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_phnset_appicon_fmgr_check_hdlr(filepath);
}
/**************************************usb evt*************************************/
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
#endif
mmi_ret mmi_phnset_appicon_notify_hdlr(mmi_event_struct* para)
{
  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(para != NULL);
    switch(para->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            format = (srv_fmgr_notification_format_event_struct*)para;
            //mmi_thm_drv_format_hdlr((CHAR)format->drv_letter);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            mmi_phnset_appicon_fmgr_evt_hdlr(para);
        break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
             MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_notify_hdlr memory card plug out/in");
			 mmi_phnset_appicon_freset();
             mmi_phnset_create_appicon_folderlist();
             mmi_phnset_appicon_refresh(0);
		     if((g_dl_appicon_cntx.hightlightindex >= g_appicon_system_count) && !( mmi_frm_scrn_get_active_id() == SCR_ID_APPICON_MAIN))
              {
                g_dl_appicon_cntx.resethighlightindex = MMI_TRUE;
                mmi_frm_scrn_close_active_id();
              }
             if(!mmi_phnset_appicon_check_active())
              {
                mmi_phnset_set_appicon(0);
              }
			 mmi_applist_refresh();
            break;
        }
#ifdef __MMI_USB_SUPPORT__ 
	   case EVT_ID_USB_ENTER_MS_MODE:
         {
             kal_prompt_trace(MOD_MMI,"mmi_phnset_appicon_enter_mass_storage_mode");
             mmi_phnset_appicon_freset();
             mmi_phnset_create_appicon_folderlist();
             mmi_phnset_appicon_refresh(0);
              if(mmi_phnset_get_appicon_id()== 0XFF && PhnsetAppIconIsAppIconFileExit() )
              {
                mmi_phnset_set_appicon(0);
                mmi_applist_refresh();
   
              }
              g_dl_appicon_cntx.resethighlightindex = MMI_TRUE;
              break;
         }  
       case EVT_ID_USB_EXIT_MS_MODE:
         {
		 	#if 0
/* under construction !*/
			#endif
			kal_prompt_trace(MOD_MMI,"mmi_phnset_appicon_exit_mass_storage_mode");
            mmi_phnset_appicon_freset();
            mmi_phnset_create_appicon_folderlist();
            mmi_phnset_appicon_refresh(0);
            if(!mmi_phnset_appicon_check_active()) 
              {
                mmi_phnset_set_appicon(0);

              }
	        mmi_applist_refresh();
            g_dl_appicon_cntx.resethighlightindex = MMI_TRUE;
             break;     
         }
#endif
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif
static MMI_BOOL mmi_phnset_appicon_initappicon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      MMI_BOOL ret = MMI_FALSE;
#ifndef __LOW_COST_SUPPORT_COMMON__
      CHAR *cache_path;
      CHAR *temp_path;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if (mmi_phnset_get_appicon_id() == 0xFF)
	{
	#ifndef __LOW_COST_SUPPORT_COMMON__
        cache_path = (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE * 2);
        temp_path = (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE * 2);
        memset(cache_path,0,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE * 2);
        memset(temp_path,0,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE * 2);
        sprintf(temp_path,"%s",APPICON_CACHE_PATH);
        mmi_asc_to_ucs2(cache_path, temp_path);
		if (mmi_phnset_appicon_activeDltCache((WCHAR *)cache_path))
          {  
             OslMfree(temp_path);
             OslMfree(cache_path);
             
	#else

		if (PhnsetAppIconIsAppIconFileExit() &&
			mmi_phnset_appicon_activeDltCache(g_appicon_cntx->m_nameBuffer))
           {
    #endif
			ret = MMI_TRUE;
		}
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_initappicon ret=%d",ret);
	return ret;
}

#endif

/*=================================system api==========================================*/
static void mmi_phnset_appicon_complete_popup(void)
{
  mmi_popup_display_simple_ext(g_popup_string, MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
}
void mmi_phnset_appicon_complete_active(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_event_struct evt;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      if(!result)
        {
	        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_execute_active download appicon switch file");
		    mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            return;
        }
	  else
	    {
		   g_popup_string = STR_ID_PHNSET_APPICON_CHANGED;
	    }
      if(g_appicon_cntx->hightlightindex >= g_appicon_system_count  || g_appicon_cntx->isformFmgr)
        {
            g_dl_appicon_cntx.isdlActive = MMI_FALSE;
			g_appicon_cntx->isformFmgr =MMI_FALSE;
            mmi_phnset_set_dlappicon_path((CHAR *)g_appicon_cntx->m_nameBuffer,NVRAM_EF_DLT_APPICON_SIZE);
        }
      else
        {
            mmi_phnset_set_appicon_id(g_dl_appicon_cntx.hightlightindex);
        }
	  g_appicon_cntx->hightlightindex = 0;
      gui_start_timer(300,mmi_phnset_appicon_complete_popup);
}
static void mmi_phnset_appicon_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appicon_deactive();
    mmi_phnset_set_appicon_id(0);
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
    mmi_phnset_appicon_freset();
#endif

}
static U32 mmi_phnset_appicon_get_count(void)
{
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
   if (g_dl_appicon_cntx.m_waitingJob == 0)
	{
		for (i = 0; i < FOLDER_TOTAL; i++)
		{
			count += g_dl_appicon_cntx.m_lstFileCnt[i];
		}
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_get_count download appicon count =%d",count + g_dl_appicon_cntx.m_adjustCnt );
		return (count + g_dl_appicon_cntx.m_adjustCnt);
	}
#endif   
	return 0;
}

void mmi_phnset_appicon_setting_exit_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
}
static mmi_ret mmi_phnset_appicon_sysetm_change_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if(!mmi_phnset_set_appicon((U16)g_dl_appicon_cntx.hightlightindex))
	  {
	     MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_sysetm_change_callback actived system appicon failed");
         mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	  }
	 else
	  {
	     MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_sysetm_change_callback actived system appicon success");
		 g_popup_string = STR_ID_PHNSET_APPICON_CHANGED;
         mmi_popup_display_simple_ext(STR_ID_PHNSET_APPICON_SWITCH, MMI_EVENT_PROGRESS, GRP_ID_ROOT, NULL);
         MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHNSET_APPICON_CHANGED);
	     MMI_FRM_CB_EMIT_EVENT(&evt);
         mmi_applist_theme_change_notify();
         mmi_frm_close_to_idle_group();
      }
       return MMI_RET_OK;
}

void  mmi_phnset_set_appicon_id(U16 activeIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_set_appicon_id, appicon id=%d",activeIndex);
	mmi_dispchar_set_img_id(NVRAM_RESTORE_APP_ICON_ID, &activeIndex);
}
static MMI_BOOL mmi_phnset_set_appicon(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_set_appicon"); 
    mmi_phnset_appicon_deactive();
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
   if(!mmi_res_set_priority_theme((U8)index, 1, &g_dl_appicon_cntx.handle))
    {
       return MMI_TRUE;
    }
   return MMI_FALSE; 
}
static void mmi_phnset_appicon_init_data(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
   g_dl_appicon_cntx.hightlightindex = 0;
   g_dl_appicon_cntx.m_drvList[FOLDER_PHONE] = NULL;
   #if defined (__FS_CARD_SUPPORT__)
   /* Card Drive -- Card */
   g_dl_appicon_cntx.m_drvList[FOLDER_CARD]  = NULL;
   #endif
   //g_dl_appicon_cntx.m_drvList[FOLDER_PHONE] = SRV_FMGR_DRV_PHONE_TYPE;
   //g_dl_appicon_cntx.m_drvList[FOLDER_CARD] = SRV_FMGR_DRV_CARD_TYPE;
   g_dl_appicon_cntx.m_adjustCnt = 0;
   g_dl_appicon_cntx.isdlActive = MMI_FALSE;
   g_dl_appicon_cntx.m_waitingJob = 0;
#endif   
   g_dl_appicon_cntx.handle = INVALID_HANDLE;
}
static MMI_BOOL mmi_phnset_appicon_check_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_check_active start"); 
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
	if (mmi_phnset_get_appicon_id() == 0xFF)
	{
	  #ifdef __MMI_USB_SUPPORT__
        if(srv_usb_is_in_mass_storage_mode())
          {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_check_active mass storage mode, set default appicon"); 
            ret = mmi_phnset_set_appicon(0);
          }
        else
        {
           if(mmi_phnset_appicon_initappicon())
			ret = MMI_TRUE;
		}
      #else
       if(mmi_phnset_appicon_initappicon())
        {
			ret = MMI_TRUE;
		}
      #endif
	}
   else
#endif /* __MMI_DOWNLOADABLE_APPICON_SUPPORT__  */
	{
		if(mmi_phnset_set_appicon(mmi_phnset_get_appicon_id()) >= 0)
		{
			ret = MMI_TRUE;
		}
	}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_init
 * DESCRIPTION
 *  for bootup 
 *  Ancestor Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_appicon_init(void)
{    

   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__   
#ifndef __LOW_COST_SUPPORT_COMMON__
      CHAR *cache_path;
      CHAR *temp_path;
#endif
#endif
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
    mmi_res_init_theme();
    mmi_phnset_appicon_init_data();
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
#ifndef __LOW_COST_SUPPORT_COMMON__
    // check @Settings folder   
     cache_path = (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
     temp_path = (CHAR *)OslMalloc(sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE );
     memset(cache_path,0,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
     memset(temp_path,0,sizeof(CHAR) * SRV_FMGR_PATH_BUFFER_SIZE);
     sprintf(temp_path,"%s",SETTING_PATH_NAME);
     mmi_asc_to_ucs2(cache_path, temp_path);
     srv_fmgr_fs_create_folder((WCHAR *)cache_path);
     OslMfree(cache_path);
     OslMfree(temp_path);
#endif 
#endif
     g_appicon_system_count = mmi_res_get_app_icon_count();
     if(!mmi_phnset_appicon_check_active())
      {
        mmi_phnset_appicon_restore_default();
      }
}
static void mmi_phnset_appicon_deactive(void)
{
  if(g_dl_appicon_cntx.handle != INVALID_HANDLE)
    {
     mmi_res_close_priority_theme(g_dl_appicon_cntx.handle);
     g_dl_appicon_cntx.handle =INVALID_HANDLE;
    }
}
static void mmi_phnset_appicon_system_active(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    //g_dl_appicon_cntx.isCorrectSet = 1;
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, mmi_phnset_appicon_sysetm_change_callback, NULL);
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_proc
 * DESCRIPTION
 *  mmi_phnset_appicon_set_popup  popup callback
 *  Functionality:
 * PARAMETERS
 *  param       [IN]                       
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_appicon_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
     case EVT_ID_ALERT_QUIT:
	  {
        mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)param;
        switch (confirm_evt->result)
    	{
    	case MMI_ALERT_CNFM_OK:
    	case MMI_ALERT_CNFM_YES:
          {
     #ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__        
             if(g_dl_appicon_cntx.isneedcomfirm)
               {
                  mmi_event_struct evt;
				  g_dl_appicon_cntx.isneedcomfirm = MMI_FALSE;
                 //mmi_phnset_set_dlappicon_path((CHAR *)g_appicon_cntx->m_nameBuffer,SRV_FMGR_PATH_BUFFER_SIZE);
                  //g_dl_appicon_cntx.isCorrectSet = 1;
                  MMI_FRM_INIT_EVENT(&evt, 0);
                  mmi_frm_post_event(&evt, mmi_phnset_appicon_dl_change_callback, NULL);
                  break;
               }
             if(!g_dl_appicon_cntx.isdlActive)
               {
                  mmi_phnset_appicon_system_active();
               }
             else
               {
                  mmi_phnset_appicon_download_active();
               }
      #else
              mmi_phnset_appicon_system_active();
      #endif
                break;
          }  
        case MMI_ALERT_CNFM_CANCEL:    
        case MMI_ALERT_CNFM_NO:    
			 g_dl_appicon_cntx.isneedcomfirm = MMI_FALSE;
             mmi_frm_scrn_close_active_id();
    		break;

    	default:
    		break;
    	 }
      }
   }
	  return  MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_set_popup
 * DESCRIPTION
 *  This function is display popup when select one appicon
 *  for Phonesetup -> Display Character -> Application icon -> priview ->ok
 *  Functionality:
 * PARAMETERS
 *  str_id       [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_appicon_display_popup(U16 str_id)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
   mmi_confirm_property_struct confirm_arg;

  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
   mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_OKCANCEL);
   confirm_arg.callback = mmi_phnset_appicon_proc;
   confirm_arg.parent_id = GRP_ID_ROOT;
   mmi_confirm_display_ext(
        str_id,
		MMI_EVENT_CONFIRM,
        &confirm_arg);
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_check_select
* DESCRIPTION
*  check current select is  active appicon or not
* PARAMETERS
*  index   [IN]
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_phnset_appicon_check_select(S8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 fmgrRet;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  if(index== (S32)mmi_phnset_get_appicon_id())
	 {  
		ret = MMI_TRUE;
	 } 
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__   
if(g_dl_appicon_cntx.hightlightindex >= g_appicon_system_count && mmi_phnset_get_appicon_id()== 0XFF)
{
#if 0
#ifndef __LOW_COST_SUPPORT_COMMON__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
   memset(g_appicon_cntx->m_nameBuffer,0,SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
   fmgrRet = srv_fmgr_filelist_get_filepath(
						g_dl_appicon_cntx.m_fileItems[g_dl_appicon_cntx.hightlightindex - g_appicon_system_count].handle, 
						g_dl_appicon_cntx.m_fileItems[g_dl_appicon_cntx.hightlightindex - g_appicon_system_count].index,
						(WCHAR *)g_appicon_cntx->m_nameBuffer,
						SRV_FMGR_PATH_BUFFER_SIZE);
   //MMI_ASSERT( fmgrRet == 0);
   if(fmgrRet)
       return MMI_FALSE; 
   if(mmi_phnset_appicon_isActivedFile((WCHAR *)g_appicon_cntx->m_nameBuffer))
    {
      ret = MMI_TRUE;
    }
}
#endif  
   MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_check_select ret=%d",ret);
   return ret;
}
static mmi_ret mmi_phnset_appicon_done(mmi_event_struct *param)
{
   switch (param->evt_id)
    {
       case EVT_ID_ALERT_QUIT:
	     {
            #ifdef __MMI_SUPPORT_ASMV2__
		    mmi_frm_app_close(APP_SETTING_APPICON);
            #else  //__MMI_SUPPORT_ASMV2__
		    mmi_frm_group_close(APP_SETTING_APPICON);
            #endif  //__MMI_SUPPORT_ASMV2__
		  break;
         }
	   default:
    	  break;
   }
	  return  MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_preview_hdlr
* DESCRIPTION
*  set appicon handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_appicon_preview_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if(mmi_phnset_appicon_check_select(g_dl_appicon_cntx.hightlightindex))
    {
       MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_preview_hdlr is actived appicon");
       mmi_popup_property_init(&arg);
	   arg.callback   = mmi_phnset_appicon_done;
	   arg.user_tag    = NULL;
	   mmi_popup_display_ext(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS, &arg);
       return;
    }
	mmi_phnset_appicon_display_popup(STR_ID_PHNSET_APP_ICON_CHNAGE_ASK);
}
static CHAR* PhnsetGetAppIconNameById(U16 Id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* aiName = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Id >= 0 && Id < g_appicon_system_count)
    {
        aiName = GetString((U16) (STR_ID_PHNSET_APP_ICON1 + Id));
    }
    return aiName;
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_preview
* DESCRIPTION
*  get the right image buffer and call showcategory to show the image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_appicon_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 appiconId;
    CHAR *ssName;
	MMI_BOOL ret = MMI_FALSE;
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
    U16 *extPos;
    CHAR *app_name = OslMalloc(sizeof(CHAR)*MMI_MAX_FILE_NAME_LEN+1);    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    memset(app_name, 0, sizeof(CHAR)*MMI_MAX_FILE_NAME_LEN+1);
    g_dl_appicon_cntx.isdlActive = ((g_dl_appicon_cntx.hightlightindex < g_appicon_system_count) ? MMI_FALSE : MMI_TRUE);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_preview_hdlr g_dl_appicon_cntx.isdlActive=%d",g_dl_appicon_cntx.isdlActive);
#endif    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_APPICON_MAIN, mmi_frm_scrn_get_active_id());
    g_appicon_cntx->image_buffer =NULL;
    if(g_dl_appicon_cntx.hightlightindex < g_appicon_system_count)
      {
        ssName = PhnsetGetAppIconNameById(g_dl_appicon_cntx.hightlightindex);
        g_appicon_cntx->image_buffer=mmi_res_get_pri_theme_preview(mmi_res_get_app_icon_data(g_dl_appicon_cntx.hightlightindex));
        ret = (g_appicon_cntx->image_buffer == NULL ? MMI_FALSE : MMI_TRUE);          
      }
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
    else
      {     
        g_appicon_cntx->image_buffer = kal_adm_alloc(g_appicon_cntx->adm_pool_id,MMI_APPICON_PREVIEW_CACHE_BUFFER_SIZE);
        MMI_ASSERT(g_appicon_cntx->image_buffer);
        memset(g_appicon_cntx->m_nameBuffer, 0, SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
   #ifndef __LOW_COST_SUPPORT_COMMON__       
        if(g_dl_appicon_cntx.hightlightindex == g_appicon_system_count && mmi_phnset_get_appicon_id() == 0xFF && PhnsetAppIconIsAppIconFileExit())
          {
              mmi_phnset_get_appicon_path(g_appicon_cntx->m_nameBuffer,SRV_FMGR_PATH_BUFFER_SIZE);
          }
        else
   #endif         
          {
              srv_fmgr_filelist_get_filepath(
						g_dl_appicon_cntx.m_fileItems[g_dl_appicon_cntx.hightlightindex - g_appicon_system_count].handle, 
						g_dl_appicon_cntx.m_fileItems[g_dl_appicon_cntx.hightlightindex - g_appicon_system_count].index,
						g_appicon_cntx->m_nameBuffer,
						SRV_FMGR_PATH_BUFFER_SIZE);
          }
        if(!mmi_res_get_dlt_theme_preview((WCHAR*)g_appicon_cntx->m_nameBuffer ,(S8*)g_appicon_cntx->image_buffer , MMI_APPICON_PREVIEW_CACHE_BUFFER_SIZE))
          {
             ret = MMI_TRUE;
          }
        mmi_ucs2cpy((CHAR *)app_name,(CHAR *)srv_fmgr_path_get_filename_ptr(g_appicon_cntx->m_nameBuffer));
        extPos = srv_fmgr_path_get_extension_ptr((WCHAR*)app_name);
		*(extPos - 1) = 0;  
        extPos = NULL;
        ssName = app_name;
      }
#endif    
    if(!ret)
     {
        appiconId = IMG_ID_PHNSET_APPICON_FILECORRUPTED;
     } 
      //wgui_softkey_disable_text_translucence();  
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_preview ret=%d",ret);
    if(ret)
     {
       EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        //image buffer is valid
       ShowCategory129ScreenInternal(
                (UI_string_type)ssName,
                 0,
                 STR_GLOBAL_OK,
                 STR_GLOBAL_BACK,
                 NULL,
                 guiBuffer,
				 (PU8)g_appicon_cntx->image_buffer,
				 0);
     }
    else
     {
       EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
       // the image buffer is invalid show the default image
       ShowCategory129ScreenInternal(
                (UI_string_type)ssName,
                 0,
                 STR_GLOBAL_OK,
                 STR_GLOBAL_BACK,
                 appiconId,
                 guiBuffer,
				 NULL,
				 0);
     }
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
     OslMfree(app_name);
     if(g_dl_appicon_cntx.hightlightindex >= g_appicon_system_count)
       {
          kal_adm_free(g_appicon_cntx->adm_pool_id,g_appicon_cntx->image_buffer);
       }
#endif     
     g_appicon_cntx->image_buffer = NULL;
     SetLeftSoftkeyFunction(mmi_phnset_appicon_preview_hdlr, KEY_EVENT_UP);
     SetCenterSoftkeyFunction(mmi_phnset_appicon_preview_hdlr, KEY_EVENT_UP);   
     //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
}
#ifndef __MMI_PHNSET_WP_SLIM__ 
/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysViewPre
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:   EntryPhnsetScrSvrSysView
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetAppIconViewPre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction();
    if(g_dl_appicon_cntx.hightlightindex <= 0)
      {
         g_dl_appicon_cntx.hightlightindex = g_appicon_system_count + mmi_phnset_appicon_get_count();
      }
      g_dl_appicon_cntx.hightlightindex --;
      mmi_phnset_appicon_setting_view_lsk();
}
/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysViewNext
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:   EntryPhnsetScrSvrSysView
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetAppIconViewNext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction();
    if (g_dl_appicon_cntx.hightlightindex >= (mmi_phnset_appicon_get_count() + g_appicon_system_count - 1))
           {
             g_dl_appicon_cntx.hightlightindex = -1;
           }

      g_dl_appicon_cntx.hightlightindex++;
      mmi_phnset_appicon_setting_view_lsk();
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_setting_view
* DESCRIPTION
*  appicon entry appicon prview lsk handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_appicon_setting_view_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_enter_switch_screen();     
    //g_dl_appicon_cntx.isCorrectSet = 0;
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__   
    //handler the plug in/out card must back to the appicon list screen when preview download appicon
	if(g_dl_appicon_cntx.resethighlightindex)//if (((g_dl_appicon_cntx.hightlightindex >= g_appicon_system_count) && !mmi_phnset_appicon_get_count()) || ( mmi_phnset_get_appicon_id()== 0XFF && g_dl_appicon_cntx.hightlightindex >= (S8)mmi_phnset_appicon_get_count))
     {
       mmi_frm_scrn_close_active_id();
	   return;
     }
#endif    
#ifndef __MMI_PHNSET_WP_SLIM__ 
    wgui_set_touch_title_bar_buttons(); /* enable the display of title bar buttons */
#if defined(__MMI_TOUCH_SCREEN__)
    register_touch_button_handlers(NULL, PhnsetAppIconViewPre, NULL, PhnsetAppIconViewNext);
#endif 
#endif
    mmi_phnset_appicon_preview();
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE); /* for handle long press LNK and RNK */    
#ifndef __MMI_PHNSET_WP_SLIM__     
    SetKeyHandler(PhnsetAppIconViewPre, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetAppIconViewPre, KEY_LEFT_ARROW, KEY_REPEAT);    
    SetKeyHandler(PhnsetAppIconViewPre, KEY_LEFT_ARROW, KEY_LONG_PRESS);        
    SetKeyHandler(PhnsetAppIconViewNext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
    SetKeyHandler(PhnsetAppIconViewNext, KEY_RIGHT_ARROW, KEY_REPEAT);    
    SetKeyHandler(PhnsetAppIconViewNext, KEY_RIGHT_ARROW, KEY_LONG_PRESS);   
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_get_async_items
 * DESCRIPTION
 *  This function is to get phone appicon info asynchronously
 * PARAMETERS
 *  start_indx:[IN] the first item to get 
 *  menuData:  [OUT] an array to store the appicon name info
 *  num_item:  [IN] number of items to get
 * RETURNS
 *  number of items gotten
 *****************************************************************************/
static S32 mmi_phnset_appicon_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	S32 i;
	S32 items = 0;
	U16 *app_name;
	U16 max_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_key_events();
    max_count = (S32)(mmi_phnset_appicon_get_count()+g_appicon_system_count);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_get_async_items appicon total count=%d",max_count);
	app_name = OslMalloc(MMI_MAX_FILE_NAME_LEN+1);
    for (i = start_indx; items < num_item && i < max_count; i++, items++)
	{
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__ 	
      
       if(i < g_appicon_system_count)
        {
              mmi_ucs2cpy((CHAR *)app_name ,(CHAR *)PhnsetGetAppIconNameById(i));
        }
       else
        {
            memset(g_appicon_cntx->m_nameBuffer, 0, SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
            if((i == g_appicon_system_count && mmi_phnset_get_appicon_id() == 0xFF) && mmi_phnset_get_appicon_path(g_appicon_cntx->m_nameBuffer, NVRAM_EF_DLT_APPICON_SIZE))
              {
				 U16 *extPos;  
                 mmi_ucs2cpy((CHAR *)app_name,(CHAR *)srv_fmgr_path_get_filename_ptr(g_appicon_cntx->m_nameBuffer));
                 extPos = srv_fmgr_path_get_extension_ptr(app_name);
		         *(extPos - 1) = 0;  
                 extPos = NULL;
			  }
			else
			 {
                 mmi_ucs2cpy((CHAR *)app_name ,(CHAR *)mmi_phnset_dlappicon_getText((i-g_appicon_system_count) , app_name)); 
			 }        		
	   }
#else
               mmi_ucs2cpy((CHAR *)app_name ,(CHAR *)PhnsetGetAppIconNameById(i));
#endif
		mmi_ucs2ncpy((CHAR*) menuData[items].item_list[0], (CHAR*)app_name, MAX_SUBMENU_CHARACTERS);
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[1], NULL); 
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[2], NULL); 
		if (
         #ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__    
            ((i == g_appicon_system_count) && (mmi_phnset_get_appicon_id() == 0xFF)) || 
         #endif   
            (mmi_phnset_get_appicon_id()== i && g_appicon_system_count > 0))
		{
			menuData[items].image_list[1] = get_image(IMG_ID_PROF_ACTIVATED);//TODO
		}
		else
		{
			menuData[items].image_list[1] = get_image(IMG_NONE);
		}
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__         
        if(!PhnsetAppIconIsAppIconFileExit() && (mmi_phnset_get_appicon_id() == 0xFF))
          {
             menuData[0].image_list[1] = get_image(IMG_ID_PROF_ACTIVATED);
          }
        if(i < g_appicon_system_count)
          {
            menuData[items].image_list[0] = get_image(IMG_ID_FMGR_DRIVE_PHONE);
          }
        else
          {
            menuData[items].image_list[0] = get_image(IMG_ID_FMGR_DRIVE_MEM_CARD);
          }
#else
           menuData[items].image_list[0] = get_image(IMG_ID_FMGR_DRIVE_PHONE);
#endif
	}
	OslMfree(app_name);
	return num_item;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_setting_highlight_hdlr
* DESCRIPTION
*  appicon setting highlight handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_appicon_setting_highlight_hdlr(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	g_dl_appicon_cntx.hightlightindex = item_idx;
}
U16 mmi_phnset_get_appicon_id(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U16 activeIndex;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_dispchar_get_img_id(NVRAM_RESTORE_APP_ICON_ID, &activeIndex);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_get_appicon_id appicon id=%d",activeIndex);
	return activeIndex;
}
static MMI_BOOL mmi_phnset_appicon_set_hightlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__       
    if(g_dl_appicon_cntx.resethighlightindex)
      {
         g_dl_appicon_cntx.resethighlightindex = MMI_FALSE;
         g_dl_appicon_cntx.hightlightindex = 0;
         ret = MMI_TRUE;
      }
    if(mmi_phnset_get_appicon_id()== 0xFF)   
      {
        if(g_dl_appicon_cntx.m_waitingJob == 0 && PhnsetAppIconIsAppIconFileExit())
          {
            g_dl_appicon_cntx.hightlightindex = g_appicon_system_count;
          }
        else
          {
               g_dl_appicon_cntx.hightlightindex = 0;
          }
      }
   else
#endif    
    {
          g_dl_appicon_cntx.hightlightindex= (S32)mmi_phnset_get_appicon_id();     
    } 
	return ret;
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_appicon_setting_view
* DESCRIPTION
*  appicon set setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_appicon_setting_view(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_scrn_enter(
		scrn_data->group_id,
        scrn_data->scrn_id, 
		NULL,
		(FuncPtr)mmi_phnset_appicon_setting_view, 
		MMI_FRM_UNKNOW_SCRN))
    {
		gui_buffer = mmi_frm_scrn_get_gui_buf(scrn_data->group_id, scrn_data->scrn_id);
        //search folder file list
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__ 
        if(!mmi_frm_is_in_backward_scenario()
         #ifdef __MMI_USB_SUPPORT__
           &&   !srv_usb_is_in_mass_storage_mode()
         #endif 
         )
         {
           mmi_phnset_appicon_freset();
           mmi_phnset_create_appicon_folderlist();
           mmi_phnset_appicon_refresh(0);
         }
#endif         
        g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_APPICON;
        if(mmi_phnset_appicon_set_hightlight())
          {
            gui_buffer = NULL;
          }  
         /* register highlight handler */
		RegisterHighlightHandler(mmi_phnset_appicon_setting_highlight_hdlr);
		//EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
			/* show category */
	    wgui_cat1032_show(
	        (WCHAR*) get_string(STR_ID_PHNSET_APP_ICON),
	        NULL,
	        (WCHAR*) get_string(STR_GLOBAL_VIEW),
	        NULL,              				/* left_softkey_icon */
	        (WCHAR*) get_string(STR_GLOBAL_BACK),
	        NULL,              				/* right_softkey_icon */
	        mmi_phnset_appicon_get_count()+g_appicon_system_count, 							/* number_of_items */
	        mmi_phnset_appicon_get_async_items,
	        NULL,              				/* get hint callback */
	        0,           		/* highlighted_item */
	        0,  							/* highlighted_tab */
	        IMG_ID_FMGR_DRIVE_PHONE,
	        IMG_ID_PROF_ACTIVATED,
	        gui_buffer,
		    NULL);
		wgui_restore_list_menu_slim_style();	
		SetLeftSoftkeyFunction(mmi_phnset_appicon_setting_view_lsk, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_phnset_appicon_setting_view_lsk, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_phnset_appicon_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if !defined(__MMI_SUPPORT_ASMV2__)
	switch(evt->evt_id)
	{
	    case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(APP_SETTING_APPICON);
            break;
        }
    }
    #endif  //!defined(__MMI_SUPPORT_ASMV2__)
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetAppIcon
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->Display->Application icons
 *  Following Functions:   mmi_phnset_appicon_setting_view_lsk
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetAppIcon(MMI_ID parent_gid)
{  

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if (mmi_frm_group_is_present(GRP_ID_APPICON_MAIN))
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_APPICON_MAIN,
        mmi_phnset_appicon_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_APPICON_MAIN,
        SCR_ID_APPICON_MAIN,
        (FuncPtr)mmi_phnset_appicon_setting_view,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_launch_proc
 * DESCRIPTION
 *  launch screen proc function for settings menu
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_phnset_appicon_launch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID app_id = APP_SETTING_APPICON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{		
		case EVT_ID_APP_ENTER:
        case EVT_ID_GROUP_ENTER:
         {           
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__             
             g_appicon_cntx->mem_ptr = mmi_frm_asm_alloc_r(app_id, MMI_APPICON_BASE_SIZE);
             MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_launch_proc g_appicon_cntx->mem_ptr=%x, size =%f", g_appicon_cntx->mem_ptr, MMI_APPICON_BASE_SIZE);
             if (g_appicon_cntx->mem_ptr)
	          {
                kal_mem_set(g_appicon_cntx->mem_ptr, 0x00, MMI_APPICON_BASE_SIZE);
                g_appicon_cntx->adm_pool_id = kal_adm_create(
                                           g_appicon_cntx->mem_ptr,
                                           MMI_APPICON_BASE_SIZE,
                                           NULL,
                                           KAL_TRUE);
             MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_launch_proc g_appicon_cntx->adm_pool_id=%d, size =%f", g_appicon_cntx->adm_pool_id, MMI_APPICON_BASE_SIZE);  
              }   
#endif       
            g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_APPICON;      
			 EntryPhnsetAppIcon(app_id);
			 break;
          }         
        case EVT_ID_APP_DEINIT:
        case EVT_ID_GROUP_DEINIT:
          {                
            g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP; 
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__               
		    g_dl_appicon_cntx.isdlActive = MMI_FALSE;
            mmi_phnset_appicon_freset();        
            if(g_appicon_cntx->m_fileItems)
              {
                kal_adm_free(g_appicon_cntx->adm_pool_id,g_appicon_cntx->m_fileItems);
                g_appicon_cntx->m_fileItems = NULL;
              }
           if(g_appicon_cntx->adm_pool_id)
             {
               kal_adm_delete(g_appicon_cntx->adm_pool_id);
               g_appicon_cntx->adm_pool_id = NULL;
             }
          if(g_appicon_cntx->mem_ptr)
            {
              applib_mem_ap_free(g_appicon_cntx->mem_ptr);
              g_appicon_cntx->mem_ptr = NULL;
            }
           MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "mmi_phnset_appicon_launch_proc g_appicon_cntx->mem_ptr free success");  
#endif           
          break;         
         }       
		default:
			break;
	}
	return MMI_RET_OK;
}

void mmi_phnset_appicon_launcher(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if !defined(__MMI_SUPPORT_ASMV2__)
    mmi_id this_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    this_gid = mmi_frm_group_create(
                GRP_ID_ROOT,
                APP_SETTING_APPICON,
                mmi_phnset_appicon_launch_proc,
                NULL);

    mmi_frm_group_enter(this_gid, MMI_FRM_NODE_NONE_FLAG);
    #else  //!defined(__MMI_SUPPORT_ASMV2__)
    mmi_frm_app_launch(
        	APP_SETTING_APPICON, 
			0, 
			0, 
			mmi_phnset_appicon_launch_proc, 
			NULL, 
			MMI_FRM_APP_NORMAL_LAUNCH);
    #endif  //!defined(__MMI_SUPPORT_ASMV2__)
}

mmi_ret mmi_phnset_appicon_sub_menu_handler(cui_menu_event_struct *menu_evt, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_evt->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT &&
        menu_evt->highlighted_menu_id == MENU_SETTING_APP_ICON)
    {
          mmi_phnset_appicon_launcher();
          return MMI_RET_OK;
    }
    else
    {
          return MMI_RET_DONT_CARE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_appicon_set_hint
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Display Character -> Application icon
 *  Functionality:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_appicon_set_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* p;
    U16 active_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p = OslMalloc(sizeof(CHAR)*MMI_MAX_FILE_NAME_LEN+1);
    memset(p, 0, sizeof(CHAR)*MMI_MAX_FILE_NAME_LEN+1);
    active_index = mmi_phnset_get_appicon_id();
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__ 	  
   if(active_index == 0xFF)
      {
       if(PhnsetAppIconIsAppIconFileExit())
        {
          U16 *extPos;
          memset(g_appicon_cntx->m_nameBuffer, 0, SRV_FMGR_PATH_BUFFER_SIZE * sizeof(U16));
          mmi_phnset_get_appicon_path(g_appicon_cntx->m_nameBuffer, NVRAM_EF_DLT_APPICON_SIZE);
          mmi_ucs2cpy((CHAR *)p,(CHAR *)srv_fmgr_path_get_filename_ptr(g_appicon_cntx->m_nameBuffer));
          extPos = (U16*)srv_fmgr_path_get_extension_ptr((WCHAR *)p);
		  *(extPos - 1) = 0; 
        }
       else
        {
          mmi_ucs2cpy((CHAR *)p  ,(CHAR *)PhnsetGetAppIconNameById(0));
        }
      }
      else
#endif     
      {
         mmi_ucs2cpy((CHAR *)p  ,(CHAR *)PhnsetGetAppIconNameById(active_index));
      }  
    if (p)
    {
        cui_menu_set_item_hint(
            mmi_frm_group_get_active_id(),
            MENU_SETTING_APP_ICON,
            (WCHAR*)p);
    }
	OslMfree(p);
}
#endif
