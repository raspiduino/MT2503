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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) 
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "mmi_inet_app_trc.h"

#include "wgui_touch_screen.h"
#include "wgui_categories_util.h"

#include "mmi_rp_app_provbox_def.h"

#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Local function
 *****************************************************************************/
static void mmi_provbox_entry_list(void);

static void mmi_provbox_set_list_menu_item(
                gui_iconlist_menu_item *item, 
                srv_provbox_list_info_struct *cntx, 
                U32 *start_idx, U32 msg_num);
                
static void mmi_provbox_set_list_item_text(gui_iconlist_menu_item *menu_item, WCHAR *msg_info);

static void mmi_provbox_set_list_item_icon(gui_iconlist_menu_item *menu_item, srv_provbox_msg_cmn_info_struct *msg_info);

static void mmi_provbox_set_list_item_address(
                gui_iconlist_menu_item *menu_item,
                srv_provbox_msg_cmn_info_struct *msg_info);

static void mmi_provbox_set_list_item_time(
                gui_iconlist_menu_item *menu_item,
                srv_provbox_msg_cmn_info_struct *msg_info);
                

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_enter_init
 *
 * DESCRIPTION
 *  This function is to initial all parameter of list screen. Only No-Um case
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *
 *****************************************************************************/
void mmi_provbox_app_enter_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_ENTER_INIT,
        cntx->group_id,
        cntx->cur_hilit_idx,
        cntx->cur_msg_id,
        cntx->cur_box_type);

#if defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)

	if(cntx->group_id !=  GRP_ID_INVALID)
	{
		mmi_provbox_scrn_group_close();
	}

#else
    if (cntx->group_id != GRP_ID_INVALID)
    {
        MMI_ASSERT(0);
    }
#endif
    
    cntx->group_id = GRP_ID_INVALID;
    cntx->cur_hilit_idx = 0;
    cntx->cur_msg_id = 0;
    cntx->cur_box_type = SRV_PROVBOX_BOX_TYPE_INBOX;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_app_deinit
 *
 * DESCRIPTION
 *  This function is to deinit all parameter of list screen. Only No-Um case
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *
 *****************************************************************************/
void mmi_provbox_app_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_DEINIT,
        cntx->group_id,
        cntx->cur_hilit_idx,
        cntx->cur_msg_id,
        cntx->um_grp_id);

    if (cntx->group_id == GRP_ID_INVALID)
    {
        MMI_ASSERT(0);
    }
    
    cntx->group_id      = GRP_ID_INVALID;
    cntx->cur_hilit_idx = 0;
    cntx->cur_msg_id    = 0;
    cntx->um_grp_id     = 0;
}

/*****************************************************************************
 * FUNCTION
 *  cui_provboxui_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 * MMI_ID 
 * RETURNS
 * MMI_ID
 *****************************************************************************/
MMI_ID mmi_provbox_pre_entry_from_message(MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID provboxui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_PRE_ENTRY_FROM_MESSAGE, parent_grp_id);

    if (GRP_ID_INVALID == parent_grp_id)
        return GRP_ID_INVALID;
    
    mmi_provbox_app_enter_init();
    
    provboxui_gid =  mmi_provbox_scrn_group_create(parent_grp_id);

    mmi_provbox_entry_list();

    return provboxui_gid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_ENTRY_LIST);

    /* Check SIM status*/
    if (!mmi_provbox_is_item_shown())
    {
        mmi_provbox_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }

    mmi_provbox_list_scrn_entry();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_item_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 *  menu_data       [OUT]
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_provbox_list_get_item_info(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 get_item_totle_num = 0;
    U32 menu_data_idx = 0;
    srv_provbox_list_info_struct cntx = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_LIST_GET_ITEM_INFO, start_index, num_item);

    cntx.start_idx = start_index;
    cntx.msg_num = num_item;
    cntx.box_type = SRV_PROVBOX_BOX_TYPE_INBOX;
    
    while(cntx.msg_num > 0)
    {
        srv_provbox_get_list_info(&cntx);
        get_item_totle_num += cntx.hdlr_msg_num;
        cntx.msg_num -= cntx.hdlr_msg_num;
        mmi_provbox_set_list_menu_item(menu_data, &cntx, &menu_data_idx, cntx.hdlr_msg_num);
        cntx.start_idx = cntx.next_start_idx;
    }
    
    if (get_item_totle_num != num_item)
        return -1;

    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_set_list_menu_item
 *
 * DESCRIPTION
 *  this function is to provide the information of list menu
 *
 * PARAMETERS
 *  gui_iconlist_menu_item *       [IN]
 *  srv_provbox_list_info_struct * [OUT]
 *  U32                            [OUT]
 *  U32                            [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_set_list_menu_item(
                gui_iconlist_menu_item *item, 
                srv_provbox_list_info_struct *cntx, 
                U32 *start_idx, U32 msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    WCHAR msg_addr[MMI_PROVBOX_ADDR_MAX_LEN] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_SET_LIST_MENU_ITEM, *start_idx, msg_num);

    for (i = *start_idx, j = 0; j < msg_num; i++, j++)
    {
        /* List item */
        msg_addr[0] = '\0';

        mmi_provbox_get_msg_address(msg_addr, 
            (mmi_sim_enum)cntx->cmn_info[j].sim_id ,
            cntx->cmn_info[j].msg_type, 
            &cntx->cmn_info[j].sender_addr);

        mmi_provbox_set_list_item_text(&item[i], msg_addr);
 
        mmi_provbox_set_list_item_icon(&item[i], &cntx->cmn_info[j]);
        mmi_provbox_set_list_item_address(&item[i], &cntx->cmn_info[j]);
        mmi_provbox_set_list_item_time(&item[i], &cntx->cmn_info[j]);
    }
    
    *start_idx = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_item_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_item       [OUT]
 *  msg_info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_set_list_item_text(gui_iconlist_menu_item *menu_item, WCHAR *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy name */
    name_len = mmi_ucs2strlen((const CHAR *)msg_info);

    if (name_len < (MAX_SUBMENU_CHARACTERS - 1))
    {
        mmi_ucs2cpy((CHAR*) menu_item->item_list[0], (const CHAR *)msg_info);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*) menu_item->item_list[0], (const CHAR*)msg_info, (MAX_SUBMENU_CHARACTERS - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_item_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_item       [OUT]
 *  msg_info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_set_list_item_icon(gui_iconlist_menu_item *menu_item, srv_provbox_msg_cmn_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim_icon_id;
    U16 status_icon_id; 
    U8 sim_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* List icon */
    if (msg_info->read_status == SRV_PROVBOX_MSG_READ_STATUS_UNREAD)
    {
         status_icon_id = IMG_ID_PROVBOX_UNREAD;
    }
    else
    {
         status_icon_id = IMG_ID_PROVBOX_READ;
    }

    sim_idx = mmi_frm_sim_to_index(msg_info->sim_id);

    sim_icon_id = mmi_provbox_get_sim_icon(sim_idx);

    menu_item->image_list[0] = get_image((MMI_ID_TYPE)status_icon_id);
    menu_item->image_list[1] = get_image((MMI_ID_TYPE)sim_icon_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_item_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_item       [OUT]
 *  msg_info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_set_list_item_address(
                gui_iconlist_menu_item *menu_item,
                srv_provbox_msg_cmn_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U16 str_sim_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_PROVBOX_MSG_TYPE_SIM_MMSICP == msg_info->msg_type)
    {
        str_sim_idx = mmi_provbox_get_sim_msg_title(mmi_frm_sim_to_index(msg_info->sim_id));

        mmi_ucs2cpy((CHAR*) menu_item->item_list[1], (const CHAR*)get_string((MMI_ID_TYPE)str_sim_idx));
    }
    else
    {
        str_len = mmi_ucs2strlen((const CHAR*) msg_info->sender_addr.addr);

        if (str_len < (MAX_SUBMENU_CHARACTERS - 1))
        {
            if (str_len == 0)
            {
                mmi_ucs2cpy((CHAR*) menu_item->item_list[1], (const CHAR*)get_string(STR_ID_PROVBOX_NO_NUMBER));
            }
            else
            {
                mmi_ucs2cpy((CHAR*) menu_item->item_list[1], (const CHAR*)msg_info->sender_addr.addr);
            }
        }
        else
        {
            mmi_ucs2ncpy((CHAR*) menu_item->item_list[1], (const CHAR*)msg_info->sender_addr.addr, (MAX_SUBMENU_CHARACTERS - 1));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_set_list_item_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_item       [OUT]
 *  msg_info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_set_list_item_time(
                gui_iconlist_menu_item *menu_item,
                srv_provbox_msg_cmn_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U32 local_sec = 0;
    applib_time_struct time = {0};
    UI_character_type str[MMI_PROVBOX_LIST_TIME_MAX_LEN + 1];
    UI_character_type list_time[MMI_PROVBOX_LIST_TIME_MAX_LEN + 1] = {0x0000};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Time string */
    if (msg_info->timestamp != 0)
    {
        local_sec = applib_dt_sec_utc_to_local(msg_info->timestamp);
        applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);

        date_string((MYTIME*) & time, str, DT_IDLE_SCREEN);
        mmi_ucs2cpy((CHAR*) list_time, (const CHAR*) str);
        mmi_ucs2cat((CHAR*) list_time, (const CHAR*) MMI_PROVBOX_UCS2_SPACE);

        time_string((MYTIME*) & time, str, DT_IDLE_SCREEN);
        mmi_ucs2cat((CHAR*) list_time, (const CHAR*) str);
    }

    str_len = mmi_wcslen((const WCHAR*) list_time);

    if (str_len < (MAX_SUBMENU_CHARACTERS - 1))
    {
        mmi_ucs2cpy((CHAR*) menu_item->item_list[2], (const CHAR*) list_time);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*) menu_item->item_list[2], (const CHAR*)list_time, (MAX_SUBMENU_CHARACTERS - 1));
    }
}

/***************************************************************************
 * FTE handle
 **************************************************************************/
#define MMI_PROVBOX_FTE_HANDLE

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_fte_toolbar_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  S32  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_fte_toolbar_hdlr(S32 index)
{
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = SRV_PROVBOX_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_get_msg_id_by_idx(
        mmi_provbox_get_msg_hilit_idx(),
        SRV_PROVBOX_BOX_TYPE_INBOX,
        &msg_id);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_FTE_TOOLBAR_HDLR, msg_id);

    switch(index)
    {
        case MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL:
        {
            mmi_provbox_msg_install(msg_id);
            break;
        }

        case MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE:
        {
            mmi_provbox_confirm_display(
                STR_ID_PROVBOX_DELETE_CONFIRM, 
                MMI_EVENT_QUERY, 
                mmi_provbox_msg_delete_confirm,
                (void*)MMI_PROVBOX_OP_DELECTING);
            break;
        }
        
        default:
            return;
    }
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_list_intuitive_cmd_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
void mmi_provbox_fte_intuitive_cmd_handler(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_FTE_INTUITIVE_CMD_HDLR, tap_type, index);

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        /* set new highlight index */
        cntx->cur_hilit_idx = index;

        /* set cur msg id */
        srv_provbox_get_msg_id_by_idx(index, SRV_PROVBOX_BOX_TYPE_INBOX, &cntx->cur_msg_id);
        return;
    }    
    else if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_provbox_options_create();
        return;
    }
}
#endif

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ && __MMI_PROV_IN_UM__ */
