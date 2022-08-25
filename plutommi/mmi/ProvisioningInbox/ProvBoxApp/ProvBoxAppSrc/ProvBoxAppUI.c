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
 * ProvBoxUIMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox UI main procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "kal_public_api.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "mmi_inet_app_trc.h"
#include "gui_typedef.h"

#include "menucuigprot.h"
#include "AlertScreen.h"

#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"

#include "wgui_categories.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_text_viewer.h"

#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
#include "mmi_frm_gestures_gprot.h"
#endif
#endif

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
#include "gui_effect_oem.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#endif

#ifndef __MMI_PROV_IN_UM__
#include "wgui_categories_email.h"
#endif

#include "custom_events_notify.h"

#include "UMGProt.h"

#include "mmi_rp_app_cca_def.h"
#include "CentralConfigAgentGProt.h" //EVT_ID_CCA_GROUP_ENTER_NOTIFY

#include "mmi_rp_app_provbox_def.h"
#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
static const mmi_event_notify_enum g_provbox_notify_event[] =
{
#if (MMI_MAX_SIM_NUM == 1)
    MMI_EVENT_SMS,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_EVENT_SIM1_SMS,
    MMI_EVENT_SIM2_SMS,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_EVENT_SIM3_SMS,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_EVENT_SIM4_SMS
#endif
};

static const U16 g_provbox_sim_msg_title[] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    STR_ID_PROVBOX_SIM_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    STR_ID_PROVBOX_SIM1_NAME,
    STR_ID_PROVBOX_SIM2_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    STR_ID_PROVBOX_SIM3_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    STR_ID_PROVBOX_SIM4_NAME
#endif
};

static const U16 g_provbox_sim_icon[] =
{
#if (MMI_MAX_SIM_NUM >= 1)
    IMG_GLOBAL_SIM1,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    IMG_GLOBAL_SIM2,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    IMG_GLOBAL_SIM3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    IMG_GLOBAL_SIM4
#endif
};

/*****************************************************************************
 * Local function
 *****************************************************************************/
#define LOCAL_FUNCTION_DECLARE

static U16 mmi_provbox_get_scrn_title_icon(void);

/***************************************************************************
 * Screen group handle
 **************************************************************************/


/***************************************************************************
 * List screen handle
 **************************************************************************/
static mmi_ret mmi_provbox_list_scrn_proc(mmi_event_struct *evt);

static void mmi_provbox_list_scrn_active_hdlr(mmi_frm_scrn_active_evt_struct *evt);

static void mmi_provbox_list_scrn_deinit(void);

static void mmi_provbox_hilit_idx_increase(void);

static U16 mmi_provbox_hilit_idx_get_cur_idx(void);


/***************************************************************************
 * Option handle
 **************************************************************************/
static void mmi_provbox_options_set_menu_id(MMI_ID menu_id);

static MMI_ID mmi_provbox_options_get_menu_id(void);

static mmi_ret mmi_provbox_options_sel_hdlr(
                   cui_menu_event_struct *evt, 
                   mmi_um_opt_para_struct* um_para);

static MMI_RET mmi_provbox_options_entry_hdlr(cui_menu_event_struct *evt);


/***************************************************************************
 * Progress screen handle
 **************************************************************************/
static mmi_ret mmi_provbox_progress_scrn_proc(mmi_event_struct *evt);

static void mmi_provbox_progress_scrn_active_hdlr(mmi_frm_scrn_active_evt_struct *evt);

/***************************************************************************
 * Properties screen handle
 **************************************************************************/
static void mmi_provbox_properties_scrn_init(void);

static void mmi_provbox_properties_scrn_active(mmi_frm_scrn_active_evt_struct *evt);

static void mmi_provbox_properties_scrn_close(void);

static MMI_BOOL mmi_provbox_properties_scrn_key(mmi_frm_key_evt_struct *key_evt);

static mmi_ret mmi_provbox_properties_scrn_proc(mmi_event_struct *evt);

static void mmi_provbox_properties_scrn_iter_bar(void);

/***************************************************************************
 * FTE handle
 **************************************************************************/
static void mmi_provbox_fte_set_toolbar(void);

static void mmi_provbox_fte_set_intuitive_cmd(void);

#define FUNCTION_DEFINITION

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_scrn_title_icon
 *
 * DESCRIPTION
 *  this function is to provide the title icon of properties screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  U16
 *  return id of title icon
 *****************************************************************************/
static U16 mmi_provbox_get_scrn_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IMG_ID_CCA_MAIN_ICON;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_notify_event
 *
 * DESCRIPTION
 *  this function is to provide the notify event by sim index
 *
 * PARAMETERS
 *  U32       [IN]
 *  sim_idx: indicate which sim notify event is
 *
 * RETURNS
 *  mmi_event_notify_enum
 *****************************************************************************/
mmi_event_notify_enum mmi_provbox_get_notify_event(U32 sim_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_NOTIFY_EVENT, sim_idx);

    return g_provbox_notify_event[sim_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_sim_msg_title
 *
 * DESCRIPTION
 *  this function is to provide the sim message title by sim index
 *
 * PARAMETERS
 *  U32       [IN]
 *  sim_idx: indicate which sim message title is
 *
 * RETURNS
 *  U16       [OUT]
 *  return string id of sim message title
 *****************************************************************************/
U16 mmi_provbox_get_sim_msg_title(U32 sim_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_SIM_MSG_TITLE, sim_idx);

    return g_provbox_sim_msg_title[sim_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_sim_icon
 *
 * DESCRIPTION
 *  this function is to provide the sim icon by sim index
 *
 * PARAMETERS
 *  U32       [IN]
 *  sim_idx: indicate which sim icon is
 *
 * RETURNS
 *  U16       [OUT]
 *  return sim icon id
 *****************************************************************************/
U16 mmi_provbox_get_sim_icon(U32 sim_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_SIM_ICON, sim_idx);

    return g_provbox_sim_icon[sim_idx];
}

/***************************************************************************
 * Screen group handle
 **************************************************************************/
#define MMI_PROVBOX_SCRN_GROUP


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_scrn_group_get_id
 *
 * DESCRIPTION
 *  this function is to get screen group id of provisioning message screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_ID       [OUT]
 *  return screen group id
 *****************************************************************************/
MMI_ID mmi_provbox_scrn_group_get_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return cntx->group_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_scrn_group_create
 *
 * DESCRIPTION
 *  this function is to create the screen group of provisioning message
 *
 * PARAMETERS
 *  MMI_ID       [IN]
 *
 * RETURNS
 *  MMI_ID       [OUT]
 *  return screen group id
 *****************************************************************************/
MMI_ID mmi_provbox_scrn_group_create(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_SCRN_GROUP_CREATE, parent_gid, cntx->group_id);

    if (GRP_ID_INVALID != cntx->group_id)
    {
        return cntx->group_id;
    }
    
    if (GRP_ID_INVALID == parent_gid)
    {
        return GRP_ID_INVALID;
    }
    
    cntx->group_id = mmi_frm_group_create_ex(parent_gid, 
                        GRP_ID_AUTO_GEN, 
                        mmi_provbox_scrn_group_proc, NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return cntx->group_id;
}

void mmi_provbox_scrn_group_close(void)
{
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    if (GRP_ID_INVALID == cntx->group_id)
        return;
    
    mmi_frm_group_close(cntx->group_id);
    cntx->group_id = GRP_ID_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_scrn_group_proc
 *
 * DESCRIPTION
 *  this function is to process the event of screen group
 *
 * PARAMETERS
 *  mmi_event_struct *  [IN]
 *
 * RETURNS
 *  mmi_ret             [OUT]
 *****************************************************************************/
mmi_ret mmi_provbox_scrn_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_provbox_scrn_group_evt_hdlr(evt, NULL);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_scrn_group_evt_hdlr
 *
 * DESCRIPTION
 *  this function is to process the event of screen group
 *
 * PARAMETERS
 *  mmi_event_struct *                  [IN]
 *  mmi_um_opt_para_struct* um_para     [IN]
 *
 * RETURNS
 *  mmi_ret             [OUT]
 *****************************************************************************/
mmi_ret mmi_provbox_scrn_group_evt_hdlr(mmi_event_struct *evt, mmi_um_opt_para_struct* um_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!evt)
        return MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_provbox_options_sel_hdlr((cui_menu_event_struct *)evt, um_para);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_provbox_options_entry_hdlr((cui_menu_event_struct *)evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        #ifndef __MMI_PROV_IN_UM__
            cui_menu_close(mmi_provbox_options_get_menu_id());
        #endif
            break; 
    
        case EVT_ID_GROUP_DEINIT:
        #ifndef __MMI_PROV_IN_UM__
            mmi_provbox_list_scrn_deinit();
        #else
            mmi_provbox_um_scrn_deinit();
        #endif
            break;

        case EVT_ID_CCA_GROUP_ENTER_NOTIFY:
            mmi_provbox_progress_scrn_close();
            break;
    
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/***************************************************************************
 * List handle
 **************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_hilit_idx_increase
 *
 * DESCRIPTION
 *  this function is to update highlight index of list screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_hilit_idx_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (mmi_frm_scrn_is_present(mmi_provbox_scrn_group_get_id(), 
            SCR_ID_PROVBOX_LIST_MENU, MMI_FRM_NODE_ALL_FLAG))
    {
        cntx->cur_hilit_idx++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_hilit_idx_get_cur_idx
 *
 * DESCRIPTION
 *  this function is to get current index of list screen
 *
 * PARAMETERS
 *  void    [IN]
 *
 * RETURNS
 *  U16     [OUT]
 *****************************************************************************/
static U16 mmi_provbox_hilit_idx_get_cur_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* no-um case, there is only inbox list */
    if (srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX) <= cntx->cur_hilit_idx)
    {
        cntx->cur_hilit_idx--;
    }
    
    return cntx->cur_hilit_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_hilit_idx_set_cur_id
 *
 * DESCRIPTION
 *  this function is to set current id of highlight provisioning message
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  srv_provbox_result_enum          
 *****************************************************************************/
srv_provbox_result_enum mmi_provbox_hilit_idx_set_cur_id(U32 hilit_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cntx->cur_hilit_idx = hilit_idx;

    result = srv_provbox_get_msg_id_by_idx(hilit_idx, SRV_PROVBOX_BOX_TYPE_INBOX, &cntx->cur_msg_id);
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_HILIT_IDX_SET_CUR_ID, hilit_idx, cntx->cur_msg_id);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_hilit_idx_update
 *
 * DESCRIPTION
 *  this function is to update highlight index of list menu
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void          
 *****************************************************************************/
void mmi_provbox_hilit_idx_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* no-um case, there is only inbox list */
    if (cntx->cur_hilit_idx >= srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX))
    {
        cntx->cur_hilit_idx = srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX) - 1;
        srv_provbox_get_msg_id_by_idx(cntx->cur_hilit_idx, SRV_PROVBOX_BOX_TYPE_INBOX, &cntx->cur_msg_id);
        
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_HILIT_IDX_SET_CUR_ID, cntx->cur_hilit_idx, cntx->cur_msg_id);
    }
}



/***************************************************************************
 * List screen handle
 **************************************************************************/
#define MMI_PROVBOX_LIST_SCRN
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_list_scrn_reset_info
 *
 * DESCRIPTION
 *  this function is to reset information of list screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void          
 *****************************************************************************/
void mmi_provbox_list_scrn_reset_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cntx->cur_hilit_idx = 0;
    cntx->cur_msg_id = MMI_PROVBOX_MSG_ID_INVAILD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_list_scrn_entry
 *
 * DESCRIPTION
 *  this function is to enter list screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void          
 *****************************************************************************/
void mmi_provbox_list_scrn_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_SCRN_ENTRY);

#ifdef __DM_LAWMO_SUPPORT__
    /* Handle DM phone lock*/
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif

    mmi_frm_scrn_create(mmi_provbox_scrn_group_get_id(),
        SCR_ID_PROVBOX_LIST_MENU,
        mmi_provbox_list_scrn_proc, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_list_scrn_proc
 *
 * DESCRIPTION
 *  this function is to process the event of list screen
 *
 * PARAMETERS
 *  mmi_event_struct *    [IN]
 *  evt: list screen event struct
 *
 * RETURNS
 *  mmi_ret          
 *****************************************************************************/
static mmi_ret mmi_provbox_list_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_provbox_list_scrn_active_hdlr((mmi_frm_scrn_active_evt_struct *)evt);
            break;
        }
        
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            
            if (SRV_PROVBOX_RESULT_NOT_FOUND == mmi_provbox_hilit_idx_set_cur_id(cat_evt->item_index))
            {
                mmi_provbox_app_error_hdlr();
            }
            return MMI_RET_CHANGED;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            mmi_provbox_options_create();
            return MMI_RET_KEY_HANDLED;
        }
        
        case EVT_ID_WGUI_CSK_CLICK:
        {
            mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    

            mmi_provbox_msg_install(cntx->cur_msg_id);
            return MMI_RET_KEY_HANDLED;
        }
        
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_provbox_list_scrn_deinit();
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_list_scrn_active_hdlr
 *
 * DESCRIPTION
 *  this function is to process the active event of list screen
 *
 * PARAMETERS
 *  mmi_frm_scrn_active_evt_struct *evt *    [IN]
 *  evt: list screen active event struct
 *
 * RETURNS
 *  void          
 *****************************************************************************/
static void mmi_provbox_list_scrn_active_hdlr(mmi_frm_scrn_active_evt_struct *evt)
{
#ifndef __MMI_PROV_IN_UM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    U16 left_key_str_id;
    U16 left_key_icon_id;
    S32 list_not_ready;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* nmgr hdlr. reset flag which indicate whether nofity screen of ild should be showed.*/
    mmi_provbox_nmgr_cancel();
    
    msg_num = srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_SCRN_ACTIVE_HDLR, msg_num);

    /* set FTE tool bar*/
    mmi_provbox_fte_set_toolbar();

#if (MMI_MAX_SIM_NUM >= 2 )
    wgui_cat_list_set_display_more_icon(MMI_TRUE);
#endif

    /* if empty, exit list screen and go back to ready state. */
    if (msg_num == 0)
    {
        left_key_str_id = 0;
        left_key_icon_id = 0;
        wgui_cat_set_list_menu_empty_lable(get_string(STR_ID_PROVBOX_EMPTY_MSG));
        mmi_provbox_list_scrn_reset_info();
    }
    else
    {
        left_key_str_id = STR_GLOBAL_OPTIONS;
        left_key_icon_id = IMG_GLOBAL_OPTIONS;
        mmi_provbox_hilit_idx_update();
    }
    
    if (NULL != evt->gui_buffer)
    {
        change_list_menu_category_history(
            evt->gui_buffer,
            cntx->cur_hilit_idx,
            msg_num, 0);
    }

    ShowCategory263Screen(
        (U8*) get_string(STR_ID_PROVBOX_APP),
        mmi_provbox_get_scrn_title_icon(),
        left_key_str_id,
        left_key_icon_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        msg_num,
        mmi_provbox_list_get_item_info,
        NULL,
        mmi_provbox_hilit_idx_get_cur_idx(),
        IMG_ID_PROVBOX_READ /* list_icon */ ,
        evt->gui_buffer,
        &list_not_ready);

    mmi_provbox_fte_set_intuitive_cmd();

    /* No enough info to show list, get it at first */
    if (list_not_ready)
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_NOT_READY);
        return;
    }

    /* Remove idle nmgr screen */
    mmi_provbox_nmgr_cancel();
    
    if (msg_num != 0)
    {
        ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
#endif /* __MMI_PROV_IN_UM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_list_scrn_deinit
 *
 * DESCRIPTION
 *  this function is to process the deinit event of list screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_list_scrn_deinit(void)
{
#ifndef __MMI_PROV_IN_UM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_SCRN_DEINIT);

    mmi_provbox_app_deinit();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_refresh_list_scrn
 *
 * DESCRIPTION
 *  this function is to refresh list screen
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_refresh_list_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_SCRN_REFRESH);

    mmi_frm_scrn_create(mmi_provbox_scrn_group_get_id(), SCR_ID_DUMMY, NULL, NULL);

    mmi_frm_scrn_close(mmi_provbox_scrn_group_get_id(), SCR_ID_DUMMY);
}

/***************************************************************************
 * Option handle
 **************************************************************************/
#define MMI_PROVBOX_OPTION
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_options_set_menu_id
 *
 * DESCRIPTION
 *  this function is to set menu cui id of option menu
 *
 * PARAMETERS
 *  MMI_ID       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_options_set_menu_id(MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_OPTION_SET_MENU_ID, menu_id);

    MMI_ASSERT(menu_id);
    
    cntx->menu_id = menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_options_get_menu_id
 *
 * DESCRIPTION
 *  this function is to get menu cui id of option menu
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_ID      [OUT]
 *****************************************************************************/
static MMI_ID mmi_provbox_options_get_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx->menu_id);
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_OPTION_GET_MENU_ID, cntx->menu_id);

    return cntx->menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_options_get_menu_id
 *
 * DESCRIPTION
 *  this function is to craete menu cui of option menu
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_options_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_OPTION_CREATE);

    menu_id = cui_menu_create(mmi_provbox_scrn_group_get_id(), 
                  CUI_MENU_SRC_TYPE_RESOURCE, 
                  CUI_MENU_TYPE_FROM_RESOURCE, 
                  MENU_ID_PROVBOX_OPTION_MENU,
                  MMI_TRUE, NULL);

    cui_menu_set_default_title_image(menu_id, get_image(mmi_provbox_get_scrn_title_icon()));

    mmi_provbox_options_set_menu_id(menu_id);
    
    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_options_sel_hdlr
 *
 * DESCRIPTION
 *  this function is to process selete event of option menu
 *
 * PARAMETERS
 *  cui_menu_event_struct *         [IN]
 *  mmi_um_opt_para_struct* um_para [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_provbox_options_sel_hdlr(cui_menu_event_struct *evt, mmi_um_opt_para_struct* um_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* if provbox screen group is not created, 
       please create it firstly and set display 
       flag to be true */
    if (NULL != um_para && GRP_ID_INVALID == mmi_provbox_scrn_group_get_id())
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_OPTION_SEL_HDLR);

        mmi_provbox_scrn_group_create(cntx->um_grp_id);
        um_para->display_flag = MMI_TRUE;
    }

    switch (evt->highlighted_menu_id)
    {
    #if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
        case MENU_ID_PROVBOX_OPTION_VIEW:
            mmi_provbox_um_iter_viewer();
            break;
    #else
        case MENU_ID_PROVBOX_OPTION_INSTALL:
            mmi_provbox_msg_install(cntx->cur_msg_id);
            break;
    #endif

        case MENU_ID_PROVBOX_OPTION_DELETE:
        {
            mmi_provbox_confirm_display(
                STR_ID_PROVBOX_DELETE_CONFIRM, 
                MMI_EVENT_QUERY, 
                mmi_provbox_msg_delete_confirm,
                (void*)MMI_PROVBOX_OP_DELECTING);
            break;
        }

    #ifndef __MMI_PROV_IN_UM__  
        case MENU_ID_PROVBOX_OPTION_DELETE_ALL:
        {
            mmi_provbox_confirm_display(
                STR_ID_PROVBOX_DELETE_ALL_CONFIRM, 
                MMI_EVENT_QUERY, 
                mmi_provbox_msg_delete_confirm,
                (void*)MMI_PROVBOX_OP_DELECTING_ALL);
            break;
        }
    #endif

    #ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_PROVBOX_OPTION_MOVE_TO_ARCHIVE:
        {
            mmi_provbox_confirm_display(
                STR_ID_PROVBOX_MOVE_TO_ARCHIVE_CONFIRM, 
                MMI_EVENT_QUERY, 
                mmi_provbox_msg_move_to_achive_confirm,
                NULL);
            break;
        }
    #endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    #if !defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)|| !defined(__MMI_PROV_IN_UM__)
        case MENU_ID_PROVBOX_OPTION_PROERTIES:
        {
            mmi_provbox_properties_scrn_show();
            break;
        }
    #endif
        default:
            break;
    }

    return MMI_RET_OK;   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_handle_entry_evt
 *
 * DESCRIPTION
 *  this function is to process entry event of option menu
 *  
 * PARAMETERS
 *  mmi_event_struct*       [IN]
 *  mmi_um_opt_para_struct* [OUT]
 *
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_provbox_options_entry_hdlr(cui_menu_event_struct *evt)
{
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct * cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PROVBOX_BOX_TYPE_ARCHIVE == (srv_provbox_box_type_enum)cntx->cur_box_type)
    {
        cui_menu_set_item_hidden(evt->sender_id,
            MENU_ID_PROVBOX_OPTION_MOVE_TO_ARCHIVE,
            MMI_TRUE);
    }
    else 
    {
        cui_menu_set_item_hidden(evt->sender_id,
            MENU_ID_PROVBOX_OPTION_MOVE_TO_ARCHIVE,
            MMI_FALSE);
    }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    return MMI_RET_OK;
}

/***************************************************************************
 * Progress screen handle
 **************************************************************************/
#define MMI_PROVBOX_PROGRESS_SCRN
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_progress_scrn_proc
 *
 * DESCRIPTION
 *  this function is to process screen event of progress screen
 *  
 * PARAMETERS
 *  mmi_event_struct*       [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_provbox_progress_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_provbox_progress_scrn_active_hdlr((mmi_frm_scrn_active_evt_struct *)evt);
            break;
        }
              
        case EVT_ID_WGUI_CSK_CLICK:
        {
            if (MMI_PROVBOX_OP_INITING != (mmi_provbox_op_enum)evt->user_data)
            {
                return MMI_RET_KEY_HANDLED;
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
 *  mmi_provbox_progress_scrn_active_hdlr
 *
 * DESCRIPTION
 *  this function is to process active event of progress screen
 *  
 * PARAMETERS
 *  mmi_frm_scrn_active_evt_struct*       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_progress_scrn_active_hdlr(mmi_frm_scrn_active_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id = 0;
    U16 rsk_title = 0;
    mmi_provbox_op_enum op_type = (mmi_provbox_op_enum)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_type)
    {
        case MMI_PROVBOX_OP_INITING:
        case MMI_PROVBOX_OP_GETTING_LIST_INFO:
        #ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
        #endif
            title_id = STR_GLOBAL_LOADING;
            break;

        case MMI_PROVBOX_OP_INSTALLING:
        #ifdef __MMI_SCREEN_SWITCH_EFFECT__
            if (!mmi_frm_scrn_get_neighbor_id(mmi_provbox_scrn_group_get_id(), SCR_ID_PROVBOX_LIST_MENU, MMI_FRM_NODE_BEFORE_FLAG))
            {
                gui_screen_switch_effect_block(MMI_TRUE);
            }
        #endif
        case MMI_PROVBOX_OP_READING_PROPERTIES:
            title_id = STR_GLOBAL_PLEASE_WAIT;
            break;

        case MMI_PROVBOX_OP_DELECTING:
            title_id = STR_GLOBAL_DELETING;
            break;

        default:
            return;
    }

    /* RSK */
    if (op_type == MMI_PROVBOX_OP_INITING)
    {
        rsk_title = STR_GLOBAL_BACK;
    }

    /* show it */
    ShowCategory8Screen(
        0,
        0,
        0,
        0,
        rsk_title,
        IMG_GLOBAL_BACK,
        title_id,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_progress_scrn_show
 *
 * DESCRIPTION
 *  this function is to create progress screen
 *  
 * PARAMETERS
 *  mmi_provbox_op_enum  [IN]
 *  op_type: indicate which type of progress screen
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_progress_scrn_show(mmi_provbox_op_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    /* Dm phone lock handle */
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PROGRESS_SCRN_SHOW);

    mmi_frm_scrn_create(mmi_provbox_scrn_group_get_id(),
        SCR_ID_PROVBOX_PROGRESSING,
        mmi_provbox_progress_scrn_proc,
        (void*)op_type);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_progress_scrn_close
 *
 * DESCRIPTION
 *  this function is to close progress screen
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_progress_scrn_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PROGRESS_SCRN_CLOSE);
    
    mmi_frm_scrn_close(mmi_provbox_scrn_group_get_id(), SCR_ID_PROVBOX_PROGRESSING);
}


/***************************************************************************
 * Properties screen handle
 **************************************************************************/
#define MMI_PROVBOX_PROPERTIES_SCRN
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_init
 *
 * DESCRIPTION
 *  this function is to initial properties screen
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_properties_scrn_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* properties buffer */
    MMI_ASSERT(!cntx->properties);

    cntx->properties = (WCHAR *)mmi_provbox_malloc(MMI_PROVBOX_PROPERTIES_BUF_SIZE);
    
    if (!cntx->properties)
    {
        mmi_provbox_app_error_hdlr();
    }
    
#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
    if (!cntx->um_iter_viewer_mid_str)
    {
         cntx->um_iter_viewer_mid_str = mmi_provbox_malloc(MMI_PROVBOX_ITER_VIEWER_MID_STR_MAX_LEN);
         MMI_ASSERT(NULL != cntx->um_iter_viewer_mid_str);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_active
 *
 * DESCRIPTION
 *  this function is to process the active event of properties screen
 *  
 * PARAMETERS
 *  mmi_frm_scrn_active_evt_struct * [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_properties_scrn_active(mmi_frm_scrn_active_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_sk = 0;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_UM_ITERATOR_VIEWER__) || defined(__MMI_VUI_WIDGET_KEY_MESSAGE__)) && defined(__MMI_PROV_IN_UM__)
    #ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
	if (cntx->view_from_widget)
    #endif
    left_sk = STR_GLOBAL_INSTALL;
#endif

    /* set iterator middle string to show */
    mmi_provbox_properties_scrn_iter_bar();
    
    /* set properties screen context to show */
    mmi_provbox_msg_read_properties(cntx->cur_msg_id, cntx->properties);

    ShowCategory78Screen(STR_GLOBAL_DETAILS, 
        mmi_provbox_get_scrn_title_icon(),
        left_sk, 0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) cntx->properties,
        mmi_ucs2strlen((const CHAR*)cntx->properties), 
        evt->gui_buffer);    
        

#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_RIGHT , mmi_provbox_um_left_gesture_hdlr);
    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_provbox_um_right_gesture_hdlr);
#endif
    ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_close
 *
 * DESCRIPTION
 *  this function is to close the properties screen
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_properties_scrn_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif

    if (cntx->properties)
    {
        mmi_provbox_free((void *)cntx->properties);
        cntx->properties = NULL;
    }

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (cntx->um_iter_node)
    {
        mmi_provbox_free((void *)cntx->um_iter_node);
        cntx->um_iter_node = NULL;
    }
    
    if (cntx->um_iter_viewer_mid_str)
    {
        mmi_provbox_free((void *)cntx->um_iter_viewer_mid_str);
        cntx->um_iter_viewer_mid_str = NULL;
    }
#endif
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    cntx->view_from_widget = MMI_FALSE;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_key
 *
 * DESCRIPTION
 *  this function is to handle key event of properties screen
 *  
 * PARAMETERS
 *  mmi_frm_key_evt_struct * [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_provbox_properties_scrn_key(mmi_frm_key_evt_struct *key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL key_hdlr_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PROPERTIES_SCRN_KEY, key_evt->key_type, key_evt->key_code);
    key_hdlr_result = MMI_TRUE;

    if (key_evt->key_code == KEY_LEFT_ARROW)
    {
        if (key_evt->key_type == KEY_EVENT_UP)
        {
            mmi_provbox_um_iter_launch_prev();
        }
        else if (key_evt->key_type == KEY_EVENT_DOWN)
        {
            wgui_cat_text_viewer_show_left_slide_button_down();
        }
    } 
    else if (key_evt->key_code == KEY_RIGHT_ARROW)
    {
        if (key_evt->key_type == KEY_EVENT_UP)
        {
            mmi_provbox_um_iter_launch_next();
        }
        else if (key_evt->key_type == KEY_EVENT_DOWN)
        {
            wgui_cat_text_viewer_show_right_slide_button_down();
        }
    }
    else
    {
        key_hdlr_result = MMI_FALSE;
    }
#endif

    return key_hdlr_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_proc
 *
 * DESCRIPTION
 *  this function is to handle the event of properties screen
 *  
 * PARAMETERS
 *  mmi_event_struct * [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_provbox_properties_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INIT:
        {
            mmi_provbox_properties_scrn_init();
            break;
        }
        
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_provbox_properties_scrn_active((mmi_frm_scrn_active_evt_struct *)evt);
            break;
        }
        
        case EVT_ID_SCRN_INACTIVE:
        {
        #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
            mmi_frm_gesture_stop_listen_event();
        #endif
            break;
        }
     
        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
        {
        #if (defined(__MMI_UM_ITERATOR_VIEWER__)|| defined(__MMI_VUI_WIDGET_KEY_MESSAGE__)) && defined(__MMI_PROV_IN_UM__)
            mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
            mmi_provbox_msg_install(cntx->cur_msg_id);
            return MMI_RET_KEY_HANDLED;
        #else
            break;
        #endif
        }
        
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_provbox_properties_scrn_close();
            break;;
        }
        
        case EVT_ID_ON_KEY:
        {
            if (mmi_provbox_properties_scrn_key((mmi_frm_key_evt_struct *)evt))
            {
                return MMI_RET_KEY_HANDLED;
            }
            break;
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_show
 *
 * DESCRIPTION
 *  this function is to create properties screen
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_properties_scrn_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PROPERTIES_SCRN_SHOW);

#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif

    mmi_frm_scrn_create(mmi_provbox_scrn_group_get_id(), 
        SCR_ID_PROVBOX_PROPERTIES,
        mmi_provbox_properties_scrn_proc, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_properties_scrn_iter_bar
 *
 * DESCRIPTION
 *  this function is to register iterive bar of properties screen
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_properties_scrn_iter_bar(void)
{
#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr prev_func = NULL;
    FuncPtr next_func = NULL;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx->um_iter_node)
        return;

    if (NULL != cntx->um_iter_node->prev_launch_func_ptr)
        prev_func = mmi_provbox_um_iter_launch_prev;

    if (NULL != cntx->um_iter_node->next_launch_func_ptr)
        next_func = mmi_provbox_um_iter_launch_next;       
            
    kal_wsprintf((WCHAR *) cntx->um_iter_viewer_mid_str, 
        "%d/%d", 
        cntx->um_iter_node->index_number, 
        cntx->um_iter_node->total_number);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PROPERTIES_MSG_NUM, cntx->um_iter_node->index_number, cntx->um_iter_node->total_number);
    
    wgui_cat_text_viewer_setup_slide_buttons(NULL, NULL, NULL, prev_func,
        NULL, NULL, NULL, next_func,
        cntx->um_iter_viewer_mid_str, 0);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
}


/***************************************************************************
 * Popup screen handle
 **************************************************************************/
#define MMI_PROVBOX_POPUP

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_popup
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  text        [IN]        
 *  type        [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_popup(U16 text, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    grp_id = mmi_provbox_scrn_group_get_id();

    if (GRP_ID_INVALID == grp_id)
        grp_id = GRP_ID_ROOT;
 
    mmi_popup_display_simple_ext(text, type, grp_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_popup_by_str
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  type        [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_popup_by_str(UI_string_type text, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_provbox_scrn_group_get_id();

    if (GRP_ID_INVALID == grp_id)
        grp_id = GRP_ID_ROOT;

    mmi_popup_display_simple(text, type, grp_id, NULL);
}

/***************************************************************************
 * Confirm screen handle
 **************************************************************************/
#define MMI_PROVBOX_CONFIRM_SCRN

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_confirm_display
 * DESCRIPTION
 *  
 * PARAMETERS
 * U16                   [IN]
 * mmi_event_notify_enum [IN] 
 * mmi_proc_func         [IN]
 * RETURNS
 * void
 *****************************************************************************/
void mmi_provbox_confirm_display(U16 title_id, 
         mmi_event_notify_enum event_type,
         mmi_proc_func callback,
         void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = callback;
    arg.parent_id = mmi_provbox_scrn_group_get_id();
    arg.user_tag = user_data;

/*    if (STR_ID_PROVBOX_DELETE_CONFIRM == title_id || STR_ID_PROVBOX_DELETE_ALL_CONFIRM == title_id)
        arg.f_auto_map_empty_softkey =  MMI_FALSE;
*/

    mmi_confirm_display_ext(title_id, event_type, &arg);
}

/***************************************************************************
 * FTE handle
 **************************************************************************/
#define MMI_PROVBOX_FTE

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_fte_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_fte_set_toolbar(void)
{
#if !defined(__MMI_PROV_IN_UM__) && defined(__MMI_ICON_BAR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL fte_cmd_enable = MMI_TRUE;
    U8 *toolbar_texts[MMI_PROVBOX_FTE_TOOLBAR_NUM];
    U8 *toolbar_icons[MMI_PROVBOX_FTE_TOOLBAR_NUM];
    U8 *toolbar_icons_disabled[MMI_PROVBOX_FTE_TOOLBAR_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toolbar_texts[MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL] = (U8*)get_string(STR_GLOBAL_INSTALL);
    toolbar_texts[MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE] = (U8*)get_string(STR_GLOBAL_DELETE);

    toolbar_icons[MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL] = (U8*)GetImage(IMG_ID_PROVBOX_FTE_INSTALL);
    toolbar_icons[MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE] = (U8*)GetImage(IMG_GLOBAL_TOOLBAR_DELETE);

    toolbar_icons_disabled[MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL] = (U8*)GetImage(IMG_ID_PROVBOX_FTE_INSTALL_DISABLED);
    toolbar_icons_disabled[MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE] = (U8*)GetImage(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
    
    wgui_icon_bar_setup(MMI_PROVBOX_FTE_TOOLBAR_NUM,
        toolbar_icons,
        toolbar_icons_disabled,
        toolbar_texts,
        mmi_provbox_fte_toolbar_hdlr);

    if (mmi_provbox_is_in_call() || (0 == srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX)))
    {
        fte_cmd_enable = MMI_FALSE;
    }
    
    wgui_icon_bar_set_item_enable_state(MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL, fte_cmd_enable);
    
    fte_cmd_enable = (srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX) > 0) ? MMI_TRUE : MMI_FALSE;

    wgui_icon_bar_set_item_enable_state(MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE, fte_cmd_enable);
    
    wgui_icon_bar_update();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_intuitive_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_fte_set_intuitive_cmd(void)
{
#if !defined(__MMI_PROV_IN_UM__) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_tap_callback(mmi_provbox_fte_intuitive_cmd_handler);
#endif
}


/*===========================================================================
 * Status icon Handle
 *==========================================================================*/
#define MMI_PROVBOX_STATUS_ICON
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_update_status_icon
 * DESCRIPTION
 *  1. message full:    hide new message status icon, 
 *                      and show blink full message status icon  
 *  2. new message:     show new message status icon
 *  3. no new message:  hide new message status icon
 *  4. no full message: hide blink full message status icon
 *  5. provisiong item is not allow shown: hide new message status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_provbox_is_item_shown())
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UPDATE_HIDE_ICON);
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PROVMSG_STATE);
        #else
          wgui_status_icon_bar_hide_icon(STATUS_ICON_INCOMING_SMS);
        #endif
        return;
    }
    
    if (srv_provbox_is_full())
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UPDATE_FULL_ICON);
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_blink_icon(STATUS_ICON_PROVMSG_STATE);
        #else
          wgui_status_icon_bar_blink_icon(STATUS_ICON_INCOMING_SMS);
		#endif
        return;
    }
    else
    {
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PROVMSG_STATE);
        #else
          wgui_status_icon_bar_reset_icon_display(STATUS_ICON_INCOMING_SMS);
	   #endif
    }
    
    if (srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL))
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UPDATE_UNREAD_ICON);
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_show_icon(STATUS_ICON_PROVMSG_STATE);
        #else
          wgui_status_icon_bar_show_icon(STATUS_ICON_INCOMING_SMS);
		#endif
        return;
    }
    else
    {
    	#ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PROVMSG_STATE);
        #else
        	wgui_status_icon_bar_hide_icon(STATUS_ICON_INCOMING_SMS);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_handle_popup_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_hide_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_provbox_is_full())
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_HIDE_FULL_ICON);
   		#ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PROVMSG_STATE);
		#else
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_INCOMING_SMS);
		#endif
        return;
    }
    
    if (srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL))
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_HIDE_UNREAD_ICON);
		#ifndef __MMI_STATUS_ICON_BAR_SLIM__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_PROVMSG_STATE);
		#else
		wgui_status_icon_bar_hide_icon(STATUS_ICON_INCOMING_SMS);
		#endif
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_handle_popup_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_notify_popup(srv_provbox_notify_type_enum notify_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notify_type == SRV_PROVBOX_NOTIFY_TYPE_MEM_FULL || notify_type == SRV_PROVBOX_NOTIFY_TYPE_DISK_FULL )
    {
        mmi_provbox_popup(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_FAILURE);
    }
#ifndef __MMI_PROV_IN_UM__
    mmi_provbox_update_status_icon();
#endif
}


/*===========================================================================
 * Status icon Handle end
 *==========================================================================*/
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

