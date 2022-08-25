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
 *  RightsMgr.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include
 */
#include "MMI_include.h"
#ifdef __DRM_SUPPORT__
#include "custom_mmi_default_value.h"
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"

//#include "CommonScreens.h"
//#include "SettingProfile.h"

#include "drm_gprot.h"
//#include "drm_msg.h"
#include "drm_memory.h"
//#include "app_mine.h"
//#include "ProtocolEvents.h"
//#include "FileManagerDef.h"
//#include "FileManagerGprot.h"
#include "Filemgrsrvgprot.h"

//#include "wapadp.h"
//#include "FileManagerDef.h" /**Access denied*/
//#include "SimDetectionGprot.h"
//#include "CommonScreens.h"  /* gIndexIconsImageList */

#include "wgui_categories_list.h"
#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_rmgr_def.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "drm_def.h"
#include "fs_type.h"
#include "drm_errcode.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "MMI_features.h"
#include "wgui_touch_screen.h"
#include "CustMenuRes.h"
#include "RightsMgrResDef.h"
#include "menucuigprot.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "stack_msgs.h"
#include "mmi_frm_nvram_gprot.h"

/*
 * typedef
 */

mmi_rmgr_cntx_struct g_mmi_rmgr_cntx;    /* rights manager context */


static void mmi_rmgr_entry_main(void);
static void mmi_rmgr_set_execute_key_hdlr(FuncPtr key_hdlr);
void mmi_rmgr_highlight_main(void);
void mmi_rmgr_highlight_list_ro(void);
void mmi_rmgr_highlight_info(void);
void mmi_rmgr_highlight_db_proc(void);
static void mmi_rmgr_highlight_hdlr(S32 menu_idx);

#ifdef __DRM_V02__
static void mmi_rmgr_toggle_trans(void);
static void mmi_rmgr_show_trans_LSK_and_hint(void);
void mmi_rmgr_highlight_trans(void);
void mmi_rmgr_highlight_whitelist(void);
#endif /* __DRM_V02__ */

/*
 * Global Variable
 */
mmi_rmgr_cntx_struct *const mmi_rmgr_p = &g_mmi_rmgr_cntx;  /* rights manager pointer */

#ifdef __DRM_V02__
kal_bool g_mmi_rmgr_switch_cermgr = KAL_FALSE;
#endif /* __DRM_V02__ */

/*
 * External Variable
 */
extern U8 rmgr_dbchk_nv;

/*
 * External function
 */

/*****************************************************************************
 * Local Function
 *****************************************************************************/

#define __RMGR_INTERNAL_UTIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_get_root_icon
 * DESCRIPTION
 *  To get menu root icon
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_rmgr_get_root_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetRootTitleIcon(MENU_ID_RMGR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_set_execute_key_hdlr
 * DESCRIPTION
 *  Set the execution key handler
 * PARAMETERS
 *  key_hdlr        [IN]        Key handler function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_set_execute_key_hdlr(FuncPtr key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(key_hdlr, KEY_EVENT_UP);
    SetKeyHandler(key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_plmn_change_hdlr
 * DESCRIPTION
 * Register this for event EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_drm_plmn_change_hdlr(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
     /* Local Variables												  */
     /*----------------------------------------------------------------*/

      S8 imsi[SRV_MAX_IMSI_LEN + 1];
		
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    
      srv_sim_ctrl_get_imsi(MMI_SIM1, imsi, sizeof(imsi));
      mmi_drm_send_get_imsi_cnf(imsi, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_get_imsi_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  imsi        [?]         
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_send_get_imsi_cnf(U8* imsi, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MYQUEUE Message;
    drmt_get_imsi_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_get_imsi_cnf_struct*) OslConstructDataPtr(sizeof(drmt_get_imsi_cnf_struct));

    msg->result = result;
    memset(msg->imsi, 0, sizeof(msg->imsi));

    if( result == MMI_TRUE )
    {
        for( i = 0 ;i < 17; i++)
        {
            msg->imsi[i] = imsi[i];
        }
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_DRMT;
    Message.oslSapId = DRMT_MMI_SAP;
    Message.oslMsgId = MSG_ID_DRMT_GET_IMSI_CNF;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_show_trans_LSK_and_hint
 * DESCRIPTION
 *  Update and show trans LSK and hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_show_trans_LSK_and_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlight_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_idx = GetCurrHiliteID();

    if (mmi_rmgr_p->trans_state)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    Category52ChangeItemDescription(highlight_idx, hintData[highlight_idx]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_toggle_trans
 * DESCRIPTION
 *  Toggle trans state on the fly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_toggle_trans(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->trans_state = DRM_toggle_tracking(MMI_FALSE);

    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_trans
 * DESCRIPTION
 *  Hightlight handler of the trans tracking
 *  including hints
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_trans(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_toggle_trans, KEY_EVENT_UP);

    mmi_rmgr_show_trans_LSK_and_hint();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_hint_trans
 * DESCRIPTION
 *  Hint handler for trans. tracking ON/OFF
 * PARAMETERS
 *  hint_idx        [IN]        Hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_hint_trans(U16 hint_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_p->trans_state)
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_whitelist
 * DESCRIPTION
 *  Hightlight handler of the white list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_whitelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_cermgr
 * DESCRIPTION
 *  Hightlight handler of the HTTP profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_cermgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_entry_fmgr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_switch_cermgr
 * DESCRIPTION
 *  show/hide Import Certificate menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_switch_cermgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_rmgr_switch_cermgr)
        g_mmi_rmgr_switch_cermgr = KAL_FALSE;
    else
        g_mmi_rmgr_switch_cermgr = KAL_TRUE;

    mmi_frm_scrn_close_active_id();

    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
}
#endif /* __DRM_V02__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_main
 * DESCRIPTION
 *  Highlight handler of the rights manager screen in the services menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set default white list url index as 0 */
#ifdef __DRM_V02__
    mmi_rmgr_p->wl_sel_idx = 0;
#endif
    mmi_rmgr_p->rmgr_sel_idx = 0;

    SetLeftSoftkeyFunction(mmi_rmgr_entry_main, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_rmgr_entry_main, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_list_ro
 * DESCRIPTION
 *  Hightlight handler of the list RO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_list_ro(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_info
 * DESCRIPTION
 *  Hightlight handler of the general info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_gen_info_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_db_proc
 * DESCRIPTION
 *  Hightlight handler of db proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_db_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_rmgr_entry_db, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_entry_db, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the rights manager main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->rmgr_sel_idx = menu_idx;

#ifdef __DRM_V02__
    if (GetSeqItemId_Ext(MENU_ID_RMGR, (U16) menu_idx) != MENU_ID_RMGR_TRANS)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
#endif /* __DRM_V02__ */

    ExecuteCurrHiliteHandler(menu_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_more_rits_entry_main
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_more_rits_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    filetypes_group_type_enum   group;
    U16 *file_path;
    U8 perm = DRM_PERMISSION_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_get_ro_bound_path())
    {
        file_path = mmi_rmgr_get_ro_bound_path();
    }
    else
    {
        file_path = (U16*) srv_fmgr_types_query_fileinfo(&file_info);
        group = srv_fmgr_types_find_group_by_type(file_info.type);

        if (file_path == NULL)
            return;

        if (group == FMGR_GROUP_VIDEO || group == FMGR_GROUP_AUDIO)
        {
            perm = DRM_PERMISSION_PLAY;
        }
        else if (group == FMGR_GROUP_IMAGE)
        {
            perm = DRM_PERMISSION_DISPLAY;
        }
    #ifdef __J2ME__
        else if (file_info.type == FMGR_TYPE_JAD || file_info.type == FMGR_TYPE_JAR)
        {
            perm = DRM_PERMISSION_EXECUTE;
        }
    #endif /* __J2ME__ */
    }

    #ifdef __DRM_V02__
        mmi_rmgr_clear_unlock_screen();

        /* DRM 2.0 uses "activate file" */
        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, file_path, perm, MMI_TRUE, NULL, 0, 0, NULL);
#else /* __DRM_V02__ */ 
        {
            S32 size = DRM_MAX_LINE_LENGTH;
            U8* url = (U8 *)drmt_mem_alloc(size);

            FS_HANDLE handle;
    
            handle = DRM_open_file((kal_wchar*)file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
            if (handle < DRM_RESULT_OK)
            {
                size = 0;
                drmt_mem_free(url);
                url = NULL;
                mmi_popup_display((WCHAR*)(get_string(srv_fmgr_fs_error_get_string(handle))), MMI_EVENT_FAILURE, NULL);
                return;
            }
            else
            {
                if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, (kal_uint32 *)&size))
                {
                    size = 0;
                    drmt_mem_free(url);
                    url = NULL;
                    mmi_popup_display((WCHAR*)(get_string(STR_GLOBAL_INVALID_URL)), MMI_EVENT_FAILURE, NULL);
                    return;
                }
    
                DRM_close_file(handle);
            }

            mmi_rmgr_clear_unlock_screen();
            mmi_rmgr_register_unlock_session(0, file_path, perm, MMI_TRUE, url, size, 0, NULL);
        }
#endif /* __DRM_V02__ */ 

    mmi_rmgr_request_rights_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_more_rits
 * DESCRIPTION
 *  Highlight handler of getting more rights 
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_more_rits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_rmgr_more_rits_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_more_rits_entry_main, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_rmgr_more_rits_entry_main);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_option_enabler_more_rits
 * DESCRIPTION
 *  Eandler of getting more rights 
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_option_enabler_more_rits(mmi_menu_id menu_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!DRM_rights_extendable((U16*)filepath) ||
       !srv_nw_usab_is_any_network_available())
    {
        mmi_frm_hide_menu_item(menu_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_query_icon
 * DESCRIPTION
 *  To get DRM file icon (lock/unlock) 
 * PARAMETERS
 *  filepath        [?]         
 *  perm            [IN]        Permission
 *  id              [?]         
 *  handle(?)       [IN]        File hande
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_query_icon(U16 *filepath, U8 perm, U16 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RMGR_REPLACE_FILE_ICON__
    FS_HANDLE handle = DRM_open_file(filepath, FS_READ_ONLY | FS_OPEN_SHARED, perm);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(perm)
    {
    if (handle >= FS_NO_ERROR)
    {
        U8 method = DRM_get_object_method(handle, NULL);
        if (method != DRM_METHOD_NONE)
        {
            if (DRM_validate_permission(handle, NULL, perm))
            {
                *id = IMG_ID_RMGR_UNLOCK;
            }
            else
            {
                *id = IMG_ID_RMGR_LOCK;
            }
        }
    }
    }
    DRM_close_file(handle);
#endif /* __MMI_RMGR_REPLACE_FILE_ICON__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_main
 * DESCRIPTION
 *  Entry function of the rights manager main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 ItemList[MAX_SUB_MENUS];
    //U8 *hints[MAX_SUB_MENUS];
    //U16 nItems;
    mmi_id g_id;

    /* U8 *guiBuffer; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     g_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_RMGR_MAIN, mmi_rmgr_main_evt_hdlr, NULL);
     mmi_frm_group_enter(g_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_rmgr_p->menu_cui_id = cui_menu_create(
             g_id, 
             CUI_MENU_SRC_TYPE_RESOURCE, 
             CUI_MENU_TYPE_APPSUB, 
             MENU_ID_RMGR, 
             MMI_TRUE, 
             NULL);
    cui_menu_set_default_title_image(mmi_rmgr_p->menu_cui_id,(UI_image_type)GetImage(mmi_rmgr_get_root_icon()));
    cui_menu_run(mmi_rmgr_p->menu_cui_id);
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_V02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __DRM_V02__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_main_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_rmgr_main_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(mmi_rmgr_p->menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_GROUP_EXIT:
            break;

        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_GOBACK:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_RMGR_LIST_RO:
                    rmgr_list_ro_cntx.refresh = MMI_TRUE;
		      mmi_rmgr_p->current_idx = 0;
                    mmi_rmgr_list_ro_entry_main();
                    break;

                case MENU_ID_RMGR_INFO:
                    mmi_rmgr_gen_info_entry_main();
                    break;

                case MENU_ID_RMGR_DB_PROC:
                    mmi_rmgr_entry_db();
                    break;
            #ifdef __DRM_V02__
                case MENU_ID_RMGR_WHITE_LIST:
                    mmi_rmgr_whitelist_entry_main();
                    break;
                case MENU_ID_RMGR_TRANS: 
                    mmi_rmgr_toggle_trans();
                    break;
                case MENU_ID_RMGR_CERMGR:
                    mmi_rmgr_entry_fmgr();
                    break;
            #endif /* __DRM_V02__ */ 
                default:
                    MMI_ASSERT(0);
                    break;

            }
}
            break;  /* EVT_ID_CUI_MENU_ITEM_SELECT */
       case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /*if (menu_evt->app_data)
            {
                OslMfree(menu_evt->app_data);
            }*/
            cui_menu_close(menu_evt->sender_id);
            break;

    #ifdef __DRM_V02__
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            if (menu_evt->highlighted_menu_id == MENU_ID_RMGR_TRANS)
            {
                SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                mmi_rmgr_show_trans_LSK_and_hint();
            }

        }
    #endif /* __DRM_V02__ */ 
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_init
 * DESCRIPTION
 *  Init function of rights manager application, called in InitService()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DRM_V02__
    mmi_rmgr_p->trans_state = DRM_toggle_tracking(MMI_TRUE);
    mmi_rmgr_p->wl_count = 0;

    SetProtocolEventHandler(DRM_app_ro_expiry_hdlr, MSG_ID_DRMT_RO_EXPIRY_IND);
    SetProtocolEventHandler(DRM_app_activate_hdlr, MSG_ID_DRMT_ACTIVATE_CNF);
#endif /* __DRM_V02__ */

    SetProtocolEventHandler(DRM_app_parse_drm_message_hdlr, MSG_ID_DRMT_PARSE_DM_CNF);
    SetProtocolEventHandler(DRM_app_install_obj_hdlr, MSG_ID_DRMT_INSTALL_OBJECT_CNF);
    SetProtocolEventHandler(DRM_app_process_database_hdlr, MSG_ID_DRMT_PROCESS_DATABASE_CNF);
    SetProtocolEventHandler(DRM_app_get_ro_num_hdlr, MSG_ID_DRMT_GET_RO_NUM_CNF);
    SetProtocolEventHandler(DRM_app_encode_drm_message_hdlr, MSG_ID_DRMT_ENCODE_DRM_MESSAGE_CNF);
#ifdef __DRM_SUPPORT_SCAN_DISK__
    SetProtocolEventHandler(DRM_app_scan_disk_hdlr, MSG_ID_DRMT_SCAN_DISK_CNF);
#endif
#ifdef __DRM_SUPPORT_SD_CALLBACK__
        SetProtocolEventHandler(DRM_app_sd_expiry_hdlr, MSG_ID_DRMT_SD_EXPIRY_IND);
#endif

    /* special case for drm task busy */
#ifdef __DRM_V02__
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_ACTIVATE_REQ);
#endif
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_INSTALL_OBJECT_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_PARSE_DM_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_GET_RO_NUM_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_PROCESS_DATABASE_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_ENCODE_DRM_MESSAGE_REQ);
    ReadValue(NVRAM_RMGR_DB_CHECK, &rmgr_dbchk_nv, DS_BYTE, &error);

#ifdef __DRM_SEC_CLK_NITZ__
    SetProtocolEventHandler((PsFuncPtr) mmi_rmgr_stime_expiry_hdlr, MSG_ID_DRMT_NOTIFY_STIME_EXP_IND);
#endif /*__DRM_SEC_CLK_NITZ__*/

#ifdef __DRM_V02__
    mmi_drm_ui_init();
#endif

#ifdef __DRM_SUPPORT_SCAN_DISK__
    /* StartTimer(RMGR_SCAN_DISK_TIMER, 1000*60, mmi_rmgr_scan_disk); */
#endif
}

#endif /* __DRM_SUPPORT__ */


