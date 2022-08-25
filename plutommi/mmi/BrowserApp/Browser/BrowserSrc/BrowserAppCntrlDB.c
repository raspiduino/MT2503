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
 * BrowserAppCntrlDB.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef MMI_BROWSERAPPCNTRLDB_C
#define MMI_BROWSERAPPCNTRLDB_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppCntrlDB.h"
#include "BrowserAppDMgr.h"
#include "BrowserAppTypes.h"
#include "BrowserAppScrHdlr.h"

#include "mmi_rp_app_browser_def.h"
#include "BrowserSrvConfig.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"


static g_brw_app_cntrl_index = 0;

mmi_brw_app_cntrlrDB_struct g_brw_app_cntrlrDB[] =
{
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
        mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func, /* Currently there is no case when data is not ready */
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_BOOKMARKS
	},
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	{   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_recent_page_list_screen_get_data_func,
		mmi_brw_app_dmgr_recent_page_list_screen_check_data_func,
        SCR_ID_BRW_RECENT_PAGES
	},
#endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
        mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
        mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_ENTER_URL
	},
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_stored_page_list_screen_get_data_func,
		mmi_brw_app_dmgr_stored_page_list_screen_check_data_func,
        SCR_ID_BRW_STORED_PAGES
	},
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_BROWSER_MAIN
	},
    {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_MEMORY_STATUS
	},
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_VIEW_BOOKMARK
	},
#endif
#ifdef WAP_SEC_SUPPORT
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_trusted_cert_list_screen_get_data_func,
		mmi_brw_app_dmgr_trusted_cert_list_screen_check_data_func,
        SCR_ID_BRW_TRUSTED_CERTIFICATES
	},
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_trusted_cert_view_screen_get_data_func,
		mmi_brw_app_dmgr_trusted_cert_view_screen_check_data_func,
        SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE
	},
#endif /* WAP_SEC_SUPPORT */
#ifndef SLIM_WAP_MMS
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_PAGE_ACTIONS
	},
#endif
#ifdef OBIGO_Q05A
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
  	    mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_OBJECT_PROPERTIES
	},
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_page_objects_type_screen_get_data_func,
		mmi_brw_app_dmgr_page_objects_type_screen_check_data_func,
        SCR_ID_BRW_PAGE_OBJECT_TYPES
	},
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_PAGE_OBJECTS
	},
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_recent_page_list_screen_get_data_func,
		mmi_brw_app_dmgr_recent_page_host_list_screen_check_data_func,
        SCR_ID_BRW_RECENT_PAGES_HOST
	},
#endif
#endif /* OBIGO_Q05A  */
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_BUSY_SCREEN
	},
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func, /* Currently there is no case when data is not ready */
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_BOOKMARK_BROWSE_PATH
	},
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_SELECT_BOOKMARK
	},
#endif
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_TEMP_BUSY_SCREEN
	},
	{
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN
	},
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_OUT_OF_MEM_CONFIRMATION_SCREEN
	},
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN
	},
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_PAGE_SIZE_CHECK
	},
#endif
#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_LOADING_TIME_CHECK
	},
#endif
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN
	},
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN
	},
#endif
#ifdef __MMI_BRW_POST_SESSION_INFO__
	 {
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_POST_SESSION_INFO
	},
#endif
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_SPLASH_SCREEN
	},
#endif
#ifdef __OP01__ 
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
		mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
		mmi_brw_app_dmgr_static_screen_get_data_func,
		mmi_brw_app_dmgr_static_screen_check_data_func,
        SCR_ID_BRW_VIEW_URL
	},
#endif /* __OP01__  */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    {   
        mmi_brw_app_cntrlr_create_func,
        mmi_brw_app_cntrlr_pre_func,
        mmi_brw_app_cntrlr_show_func,
        mmi_brw_app_cntrlr_post_func,
        mmi_brw_app_dmgr_static_screen_get_data_func, /* Currently there is no case when data is not ready */
        mmi_brw_app_dmgr_static_screen_get_data_func,
        SCR_ID_BRW_LAUNCH_PAGE
	},
#endif
    /* Please add New entry above this line */
    {NULL, NULL, NULL, NULL, NULL, NULL, 0}
};


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_ctrlr_db_index
 * DESCRIPTION
 *  This function is to set the global index which points to the controller 
 * database to the index of a particular screen
 * particular screen id
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_app_set_ctrlr_db_index(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_brw_app_cntrlrDB[index].scrn_id != 0)
    {
        if (g_brw_app_cntrlrDB[index].scrn_id == scr_id)
        {
            g_brw_app_cntrl_index = index;
            return;
        }
        index++;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_cntrlrDB
 * DESCRIPTION
 *  This function is to get the global index which points to the controller 
 * database to the currently pointed index
 * particular screen id
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_brw_app_cntrlrDB_struct* mmi_brw_app_get_cntrlrDB (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_brw_app_cntrlrDB[g_brw_app_cntrl_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_cntrlr_create_func
 * DESCRIPTION
 * 
 * particular screen id
 * PARAMETERS
 *  screen_id
 * RETURNS
 *  
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_cntrlr_create_func (U16 screen_id)
{
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_cntrlr_pre_func
 * DESCRIPTION
 * 
 * particular screen id
 * PARAMETERS
 *  screen_id
 * RETURNS
 *  
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_cntrlr_pre_func (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret_code = MMI_BRW_FALSE;
    mmi_brw_app_cntrlrDB_struct *cntrlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr = mmi_brw_app_get_cntrlrDB();
    if (cntrlr == NULL)
    {
        ASSERT (0);
    }
    ret_code = cntrlr->data_ready_check_func(screen_id);
    if (ret_code != MMI_TRUE)
    {
        ret_code = cntrlr->get_async_data_func(screen_id);
        if (ret_code == MMI_TRUE)
        {
            ret_code = MMI_BRW_ASYNC_WAIT;
        }
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_cntrlr_show_func
 * DESCRIPTION
 * 
 * particular screen id
 * PARAMETERS
 *  screen_id
 * RETURNS
 *  
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_cntrlr_show_func (U16 screen_id)
{
    return mmi_brw_app_sh_init_function(screen_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_cntrlr_post_func
 * DESCRIPTION
 * 
 * particular screen id
 * PARAMETERS
 *  screen_id
 * RETURNS
 *  
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_cntrlr_post_func (U16 screen_id)
{
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_invoke_ui_controller
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_invoke_ui_controller (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret_code = MMI_BRW_FALSE;
    mmi_brw_app_cntrlrDB_struct *cntrlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr = mmi_brw_app_get_cntrlrDB();
    if (cntrlr == NULL)
    {
        ASSERT (0);
    }
    ret_code = cntrlr->create_func(screen_id);
    if (ret_code == MMI_BRW_TRUE)
    {
        ret_code = MMI_BRW_FALSE;
        ret_code = cntrlr->pre_func(screen_id);
        if (ret_code == MMI_BRW_TRUE)
        {
            ret_code = MMI_BRW_FALSE;
            ret_code = cntrlr->show_func(screen_id);
            if (ret_code == MMI_BRW_TRUE)
            {
                ret_code = MMI_BRW_FALSE;
                ret_code = cntrlr->post_func(screen_id);
                return ret_code;
            }
            else
            {
                return ret_code;
            }
        }
        else
        {
            return ret_code;
        }
    }
    else
    {
        return ret_code;
    }
}




#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPCNTRLDB_C */
