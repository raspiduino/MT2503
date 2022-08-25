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
 *  PhoneBookCore.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phonebook main function.
 *  Including initialize procedure, main menu, common utilities, etc.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#include "CommonScreens.h"

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookCore.h"
#include "PhbSrvGprot.h"
#include "PhoneBookTypes.h"
#include "PhoneBookExtraNumber.h"

#include "custom_events_notify.h"

#include "IdleAppGprot.h"
#include "IdleGprot.h"
#include "SettingDefs.h"
#include "mmi_rp_srv_prof_def.h"
#if 0
#ifdef __MMI_IMPS__
/* under construction !*/
#endif
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLResDef.h"
#include "SyncMLGprot.h"
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
#endif
#endif

#if defined(__MMI_VCARD__)
#include "vObjects.h"
#include "mmi_rp_srv_vcard_def.h"
#include "vcard.h"
#endif /* defined(__MMI_VCARD__) */ 
#if 0
#ifdef __MMI_VRSD_DIAL__
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __USB_IN_NORMAL_MODE__ 
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __MMI_UDX_VCARD_SUPPORT__
#include "UDXGprot.h"
#endif

#include "UCMGprot.h"
#include "simctrlsrvgprot.h"
#include "USBSrvGprot.h"

#if defined(__MMI_BT_PBAP_CLIENT__)

#include "PhoneBookpbapc.h"
#include "PhoneBookBtDailerGprot.h"

#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "string.h"
#include "GlobalResDef.h"
#include "ps_public_enum.h"
#include "CustDataRes.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "mmi_rp_app_phonebook_def.h"
#include "mmi_rp_srv_syncml_def.h"
#include "custom_phb_config.h"
#include "sim_common_enums.h"
#include "gui.h"
#include "Unicodexdcl.h"
#include "customer_email_num.h"
#include "FileMgrSrvGProt.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "PhbSrvGprot.h"
/* auto add by kw_check end */

/*----------------------------------------------------------------*/
/* Static Variables                                               */
/*----------------------------------------------------------------*/
static const U16 g_mmi_phb_grp_id[MMI_PHB_SG_TOTAL][2] =
{
    {GRP_ID_PHB_MAIN, 1},
    {GRP_ID_PHB_RES, 1},    
    {GRP_ID_PHB_MARK_SEVERAL, 1},
    {GRP_ID_PHB_GROUP, 1},
    {GRP_ID_PHB_SETTING, 1},
    
    {GRP_ID_PHB_CUI_SAVE, CUI_PHB_SAVE_CONTACT_COUNT},
    {GRP_ID_PHB_CUI_VIEW, CUI_PHB_VIEW_CONTACT_COUNT},
    {GRP_ID_PHB_CUI_LIST, CUI_PHB_SELECT_CONTACT_COUNT},
    {GRP_ID_PHB_CUI_LIST_MULTI, CUI_PHB_MULTI_SELECT_CONTACT_COUNT},
    {GRP_ID_PHB_CUI_LIST_GROUP_TAB, CUI_PHB_MULTI_SELECT_CONTACT_COUNT}
};

/*----------------------------------------------------------------*/
/* Global Variables                                               */
/*----------------------------------------------------------------*/
mmi_phb_cntx_mgr_struct g_phb_cntx_mgr;


/*----------------------------------------------------------------*/
/* Static function                                                */
/*----------------------------------------------------------------*/
static MMI_BOOL mmi_phb_cntx_mgr_check_sg_handle(U32 handle);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntxmgr_init
 * DESCRIPTION
 *  initilize phonebook context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_CNTX_MGR_INIT);

    /**
     * initilize cntx mgr
     */
    /**
     * The state maybe set to MMI_PHB_STATE_SAT, then we have to init it at here
     */
    g_phb_cntx_mgr.state = MMI_PHB_STATE_IDLE;
    g_phb_cntx_mgr.processing = MMI_FALSE;
    g_phb_cntx_mgr.ready = MMI_TRUE;

    /* initial setting state */
	#ifndef __MMI_PHB_SLIM_NEW__
    mmi_phb_setting_init();
	#else
	srv_phb_set_storage_mask((U16)PHB_STORAGE_MAX);
	#endif
}


#define MMI_PHB_CNTX_MGR_SG
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_create_handle
 * DESCRIPTION
 *  creat new screen groups, if the screen group support multi instance, user should call this api
 * PARAMETERS
 *  sg_type                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_phb_cntx_mgr_create_handle(U16 sg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sg_data_struct *sg_data;
    U32 sg_count;
    U32 sg_begain;
    U32 sg_handle = 0;
    U16 temp_age = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sg_type < MMI_PHB_SG_TOTAL);

    sg_begain = g_mmi_phb_grp_id[sg_type][0];
    sg_count = g_mmi_phb_grp_id[sg_type][1];

    /**
     * If the SG is multi instance, then find the first unused SG, or the oldest SG
     */
    for (i = 0; i < sg_count; i++)
    {
        sg_data = g_phb_cntx_mgr.sg_stack[sg_begain - GRP_ID_PHB_BEGIN + i];
        
        if (sg_data == NULL)
        {
            if (temp_age < 0xFFFF)
            {
                temp_age = 0xFFFF;
                sg_handle = sg_begain - GRP_ID_PHB_BEGIN + i;
                break;
            }
        }
        else
        {
            if (temp_age < sg_data->age)
            {
                temp_age = sg_data->age;
                sg_handle = sg_begain - GRP_ID_PHB_BEGIN + i;
            }
            sg_data->age++;
        }
    }

    /**
     * SG ID is in using, then delete the SG from history
     */
    if (g_phb_cntx_mgr.sg_stack[sg_handle] != NULL)
    {
        /* check */
        mmi_frm_group_close((mmi_id)(sg_handle + GRP_ID_PHB_BEGIN));
    }

    /**
     * malloc buffer, and set age to 1
     */
    g_phb_cntx_mgr.sg_stack[sg_handle] = (mmi_phb_sg_data_struct*)mmi_phb_mem_malloc(sizeof(mmi_phb_sg_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(g_phb_cntx_mgr.sg_stack[sg_handle], 0, sizeof(mmi_phb_sg_data_struct));

    (g_phb_cntx_mgr.sg_stack[sg_handle])->age = 1;
    (g_phb_cntx_mgr.sg_stack[sg_handle])->sg_type = sg_type;

    MMI_PHB_LOG2(TRC_MMI_PHB_CREATE_HANDLE, sg_type, sg_handle);
    
    return sg_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_release_handle
 * DESCRIPTION
 *  Free SG data buffer, before call this function, user must be sure, user private data has been freed
 *  Must be call at receiving FW evt GO BACK, or Delete Req
 * PARAMETERS
 *  U32                      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_release_handle(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_phb_sg_data_struct *instance;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_RELEASE_HANDLE, handle);
    
    MMI_ASSERT((GRP_ID_PHB_BEGIN + handle) < GRP_ID_PHB_END);

    instance = g_phb_cntx_mgr.sg_stack[handle];
    
    if (instance != NULL)
    {
        if (instance->delay_event)
        {
            mmi_phb_mem_free(instance->delay_event);
            instance->delay_event = NULL;
        }
        
        mmi_phb_mem_free(g_phb_cntx_mgr.sg_stack[handle]);
    }
    
    g_phb_cntx_mgr.sg_stack[handle] = NULL;
}


static MMI_BOOL mmi_phb_cntx_mgr_sg_is_valid(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (sg_id >= GRP_ID_PHB_BEGIN && sg_id < GRP_ID_PHB_END)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_sg_id
 * DESCRIPTION
 *  Get sg_id by sg_handle, the sg_id must be in history
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id mmi_phb_cntx_mgr_get_sg_id(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (mmi_id)(handle + GRP_ID_PHB_BEGIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_handle_by_sg_id
 * DESCRIPTION
 *  Get sg_handle by sg_id, the sg_id must be in history
 * PARAMETERS
 *  sg_id                      [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 sg_handle = sg_id - GRP_ID_PHB_BEGIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_GET_HANDLE_BY_SG_ID, sg_id);

    if (sg_id >= GRP_ID_PHB_BEGIN && sg_id < GRP_ID_PHB_END && g_phb_cntx_mgr.sg_stack[sg_handle] != NULL)
    {
        return sg_handle;
    }

    return MMI_PHB_SG_INVALID_HANDLE;
}


mmi_phb_sg_data_struct * mmi_phb_cntx_mgr_get_instance(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_phb_sg_data_struct *instance = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_sg_is_valid(sg_id))
    {
        instance = g_phb_cntx_mgr.sg_stack[mmi_phb_cntx_mgr_get_handle_by_sg_id(sg_id)];
    }

    return instance;
}

void mmi_phb_cntx_mgr_post_evt(mmi_id sg_id, MMI_BOOL evt_wait, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_phb_sg_data_struct *instance = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance = mmi_phb_cntx_mgr_get_instance(sg_id);

    if (instance == NULL)
    {
        return;
    }

    if (evt_wait)
    {
        MMI_ASSERT(instance->delay_event == NULL);

        instance->delay_event = mmi_phb_mem_malloc(evt->size, SRV_PHB_MEMORY_TYPE_ADM);
        memcpy(instance->delay_event, evt, evt->size);
    }
    else
    {
        if (evt)
        {
            mmi_frm_group_send_to_parent(sg_id, (mmi_group_event_struct *) evt);
            //srv_phb_mem_free(evt);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_handle
 * DESCRIPTION
 *  Get current running phonebook sg handle
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_phb_cntx_mgr_get_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sg_id = mmi_phb_cntx_mgr_get_current_sg_id();

    MMI_PHB_LOG1(TRC_MMI_PHB_GET_HANDLE_BY_SG_ID, sg_id);
    MMI_ASSERT(sg_id >= GRP_ID_PHB_BEGIN && sg_id < GRP_ID_PHB_END);

    return (sg_id - GRP_ID_PHB_BEGIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_set_data
 * DESCRIPTION
 *  Set SG private data
 * PARAMETERS
 *  handle                      [IN]
 *  data                         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_set_data(U32 handle, void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SET_DATA, handle);

    (g_phb_cntx_mgr.sg_stack[handle])->private_data = data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_data
 * DESCRIPTION
 *  Get SG private data
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  void*
 *****************************************************************************/
void* mmi_phb_cntx_mgr_get_data(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_GET_DATA, handle);

    return (g_phb_cntx_mgr.sg_stack[handle])->private_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_set_parent_id
 * DESCRIPTION
 *  Set SG parent gropu id
 * PARAMETERS
 *  handle                      [IN]
 *  parent_id                  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_set_parent_id(U32 handle, mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_SET_PARENT_ID, handle, parent_id);

    (g_phb_cntx_mgr.sg_stack[handle])->parent_id = parent_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_parent_id
 * DESCRIPTION
 *  Get SG parent group id
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id mmi_phb_cntx_mgr_get_parent_id(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_GET_PARETN_ID, handle);

    return (g_phb_cntx_mgr.sg_stack[handle])->parent_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_sg_tpye
 * DESCRIPTION
 *  Get SG type
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_cntx_mgr_get_sg_tpye(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_GET_SG_TYPE, handle);
    
    return (g_phb_cntx_mgr.sg_stack[handle])->sg_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_refresh_data
 * DESCRIPTION
 *  Get refresh data from cntx mgr
 * PARAMETERS
 *  handle                      [IN]
 *  refresh_data             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_refresh_struct* mmi_phb_cntx_mgr_get_refresh_data(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_check_sg_handle(handle))
    {
        return &((g_phb_cntx_mgr.sg_stack[handle])->refresh_data);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_check_sg_handle
 * DESCRIPTION
 *  Check if the handle is valid
 * PARAMETERS
 *  handle                     [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phb_cntx_mgr_check_sg_handle(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_CHECK_SG_HANDLE, handle);
    MMI_ASSERT(handle < (GRP_ID_PHB_END - GRP_ID_PHB_BEGIN));

    if (g_phb_cntx_mgr.sg_stack[handle] == NULL)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_current_sg_id
 * DESCRIPTION
 *  Cntx mgr get current running sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id mmi_phb_cntx_mgr_get_current_sg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
	mmi_group_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**
     * Now use framework api to get current running sg id. In furture, cntx mgr maybe need to maintain it by itself
     */
    scr_id = mmi_frm_group_get_active_id();
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	
	mmi_frm_group_get_info (scr_id, &node_info);
    if (mmi_phb_cntx_mgr_sg_is_valid(scr_id))
    {
        return scr_id;
    }
else if (node_info.parent >= GRP_ID_PHB_BEGIN && node_info.parent < GRP_ID_PHB_END)
    {
         return node_info.parent;
    }
#else	
	
    if (mmi_phb_cntx_mgr_sg_is_valid(scr_id))
    {
        return scr_id;
    }
#endif
    return GRP_ID_INVALID;
}

#if 0
#if defined(__MMI_IMPS__)
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
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_clear_history
 * DESCRIPTION
 *  Cntx mgr clear all phonebook screen in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_clear_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_CLEAR_HISTORY);

    /**
     * Since not all applications support SG, so should handle some special case here
     */
    // TODO: filemgr/UDX/IMPS/VRSI/VRSD/VCARD
    
#ifdef __MMI_UDX_VCARD_SUPPORT__
    if (mmi_frm_scrn_is_present(GRP_ID_PHB_MARK_SEVERAL, SCR_ID_PHB_MULTI_OP_PHB_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_udx_delete_fmgr_service_screen();
    }
#endif

#if defined(__MMI_VCARD__)
    mmi_frm_group_close(GRP_ID_VCARD_RECEVE);
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif

//    mmi_phb_delete_enter_pin2_screen();
    
    //vcard : support group, not need to handle
    
    //vrsi/vrsd : should handle
#if 0    
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif
#endif

    //filemgr : support group, not need to handle
    
    //editor : support group, not need to handle

    //imps : should handle
    
    for (i = 0; i < GRP_ID_PHB_END - GRP_ID_PHB_BEGIN; i++)
    {
        mmi_frm_group_close((mmi_id)(i + GRP_ID_PHB_BEGIN));
    }
}


#define MMI_PHB_CNTX_MGR_STATE_CONTROLLER
void mmi_phb_cntx_mgr_refresh(mmi_phb_op_cntx_struct *op_cntx, U16 *contact_array, U16 contact_count, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (handle = 0; handle < GRP_ID_PHB_END - GRP_ID_PHB_BEGIN; handle++)
    {
        if (mmi_phb_cntx_mgr_check_sg_handle(handle))
        {
            mmi_phb_refresh_struct *refresh_data = &((g_phb_cntx_mgr.sg_stack[handle])->refresh_data);
 
            refresh_data->refresh_type = op_cntx->action;
            refresh_data->old_store_index = op_cntx->store_index;
            refresh_data->new_store_index = store_index;

            refresh_data->sg_id = mmi_frm_group_get_top_parent_group_id(op_cntx->sg_id);
        }
    }
}

#ifdef __DM_LAWMO_SUPPORT__

void mmi_phb_cntx_mgr_qstate_in(U16 state)
{
    g_phb_cntx_mgr.qstate[0] = state;
}


U16 mmi_phb_cntx_mgr_qstate_out(void)
{
    U16 state = g_phb_cntx_mgr.qstate[0];

    g_phb_cntx_mgr.qstate[0] = 0;
    
    return state;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 *  set                       [IN]             MMI_TRUE: set to state; MMI_FALSE: reset
 *  data                      [IN]             for callers pass data to handle
 * RETURNS
 *  MMI_BOOL                                Verify the operation on the state is success or not
 *****************************************************************************/
MMI_BOOL mmi_phb_cntx_mgr_controller(U16 state, MMI_BOOL set, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_CONTROLLER, state, set);

    if (set)
    {
        switch (state)
        {
            case MMI_PHB_STATE_IDLE:
            #ifdef __DM_LAWMO_SUPPORT__
                if (mmi_phb_cntx_mgr_qstate_out() == MMI_PHB_STATE_DM)
                {
                    result = MMI_FALSE;
                    mmi_phb_cntx_mgr_clear_history();
                    mmi_phb_cntx_mgr_set_state(MMI_PHB_STATE_DM);                    
                    mmi_phb_dm_delete_all_pre_req();
                }
            #endif
                break;
                
          /**
           * Always allow to read operation, if phonebook is ready
           */       
            case MMI_PHB_STATE_UPDATE:
            case MMI_PHB_STATE_COPY_MULTI:
            case MMI_PHB_STATE_DELETE_MULTI:
                if (g_phb_cntx_mgr.state == MMI_PHB_STATE_IDLE)
                {
                    mmi_phb_cntx_mgr_set_state(state);
                }
                else
                {
                    result = MMI_FALSE;
                }
                break;
            #ifndef __MMI_PHB_SLIM_NO_SAT__    
            case MMI_PHB_STATE_SAT:                
                mmi_phb_cntx_mgr_set_state(state);
            #ifdef __DM_LAWMO_SUPPORT__
                if (mmi_phb_cntx_mgr_state_is_set(MMI_PHB_STATE_DM))
                {
                    mmi_phb_cntx_mgr_qstate_in(MMI_PHB_STATE_DM);
                }
            #endif
                if (g_phb_cntx_mgr.state != MMI_PHB_STATE_SAT)
                {
                    if (mmi_phb_cntx_mgr_state_is_set(MMI_PHB_STATE_COPY_MULTI | MMI_PHB_STATE_DELETE_MULTI | MMI_PHB_STATE_DM))
                    {
                    #if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
                        mmi_phb_multi_op_cancel();
                    #endif
                    }
                }
                break;
			#endif
                
        #ifdef __DM_LAWMO_SUPPORT__
            case MMI_PHB_STATE_DM:
                if (!srv_phb_startup_is_phb_ready())
                {
                    *((U32*)data) = 1;
                    mmi_phb_cntx_mgr_qstate_in(MMI_PHB_STATE_DM);
                }
                else
                {
                    mmi_phb_cntx_mgr_set_state(state);
                    if (g_phb_cntx_mgr.state != MMI_PHB_STATE_DM)
                    {
                        if (mmi_phb_cntx_mgr_state_is_set(MMI_PHB_STATE_COPY_MULTI | MMI_PHB_STATE_DELETE_MULTI))
                        {
                            *((U32*)data) = 1;
                        #if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
                            mmi_phb_multi_op_cancel();
                        #endif
                        }
                    }
                }
                break;
        #endif
        
            default:
                break;
        }
    }
    else
    {
        switch (state)
        {
          /**
           * Always allow to read operation, if phonebook is ready
           */    
            case MMI_PHB_STATE_UPDATE:
            case MMI_PHB_STATE_COPY_MULTI:
            case MMI_PHB_STATE_DELETE_MULTI:
                if (g_phb_cntx_mgr.state != state)
                {
                    result = MMI_FALSE;
                }
                
                mmi_phb_cntx_mgr_reset_state(state);
            #ifdef __DM_LAWMO_SUPPORT__
                if (mmi_phb_cntx_mgr_state_is_set(MMI_PHB_STATE_DM))
                {
                    mmi_phb_dm_delete_all_pre_req();
                }
            #endif
                break;

          /**
           * Will not happen this case
           */
            #ifndef __MMI_PHB_SLIM_NO_SAT__
            case MMI_PHB_STATE_SAT:                
                MMI_ASSERT(0);
                break;
			#endif
            
        #ifdef __DM_LAWMO_SUPPORT__
            case MMI_PHB_STATE_DM:
                if (g_phb_cntx_mgr.state != state)
                {
                    result = MMI_FALSE;
                }
                
                mmi_phb_cntx_mgr_reset_state(state);
                break;
        #endif
        
            default:
                break;
        }
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_state
 * DESCRIPTION
 *  Get cntx mgr state
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_cntx_mgr_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phb_cntx_mgr.state;
}


MMI_BOOL mmi_phb_cntx_mgr_state_is_set(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx_mgr.state & state)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_set_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.state |= state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_reset_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.state &= ~state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_sim_refresh
 * DESCRIPTION
 *  Cntx mgr receive sim refresh command
 * PARAMETERS
 *  storage                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHB_SLIM_NO_SAT__ 
void mmi_phb_cntx_mgr_sim_refresh(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim_refresh[20];
    U32 sim = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_cntx_mgr_controller(MMI_PHB_STATE_SAT, MMI_TRUE, NULL);

    /* Context and screen handle */

    sim = storage - PHB_STORAGE_SIM + 1;

    MMI_ASSERT(storage >= PHB_STORAGE_SIM);
    MMI_ASSERT(storage <= PHB_STORAGE_SIM4);

    kal_wsprintf((WCHAR *) sim_refresh, "%w%d %w", GetString(STR_GLOBAL_SIM), sim, GetString(STR_GLOBAL_REFRESH));

    if (mmi_phb_cntx_mgr_sg_is_valid(mmi_frm_group_get_active_id()))
    {
        mmi_phb_popup_display(
            (UI_string_type) sim_refresh,
            MMI_EVENT_INFO);
    }
    
    mmi_phb_cntx_mgr_clear_history();
}
#endif

#ifdef __MMI_PHB_SLIM_NEW__
#ifdef __MMI_PHB_ATCMD_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_at
 * DESCRIPTION
 *  Cntx mgr receive at operation
 * PARAMETERS
 *  operation                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_cntx_mgr_at(U8 operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sg_id = mmi_frm_group_get_active_id();

    /* Phonebook main list is active, contain running other CUI cases */
    if (mmi_frm_group_is_in_active_serial(GRP_ID_PHB_MAIN))
    {
        U16 scr_id_start = mmi_frm_scrn_get_active_id();
        U16 scr_id_end = mmi_frm_scrn_get_neighbor_id(GRP_ID_PHB_MAIN, GRP_ID_INVALID, MMI_FRM_NODE_AT_BEGINNING_FLAG);
        
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_INFO);

        if (scr_id_start != scr_id_end)
        {
            scr_id_start = mmi_frm_scrn_get_neighbor_id(GRP_ID_PHB_MAIN, scr_id_end, MMI_FRM_NODE_AFTER_FLAG);
            while (scr_id_start != SCR_ID_INVALID)
            {
                mmi_frm_group_close(scr_id_start);
                mmi_frm_scrn_close(GRP_ID_PHB_MAIN, scr_id_start);

                scr_id_start = mmi_frm_scrn_get_neighbor_id(GRP_ID_PHB_MAIN, scr_id_end, MMI_FRM_NODE_AFTER_FLAG);
            }
            /*
            mmi_frm_scrn_multiple_close(
            sg_id,
                scr_id_start,
                MMI_TRUE,
                0,
                scr_id_end,
                MMI_FALSE);
            */
        }
    }
    else if (mmi_phb_cntx_mgr_sg_is_valid(sg_id))
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_INFO);

        mmi_phb_cntx_mgr_clear_history();
    }
    else
    {
        if ((0)
		#if 0	
        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
		#endif
        )
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_DONE,
                MMI_EVENT_INFO);
        }

    #ifdef __MMI_UDX_VCARD_SUPPORT__
        else if (mmi_frm_scrn_is_present(GRP_ID_PHB_MARK_SEVERAL, SCR_ID_PHB_MULTI_OP_PHB_LIST, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_DONE,
                MMI_EVENT_INFO);

            mmi_udx_delete_fmgr_service_screen();
        }
    #endif
    
        mmi_phb_cntx_mgr_clear_history();
    }
}
#endif
#endif


void mmi_phb_cntx_mgr_input_method_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id;

#if defined(__MMI_BT_PBAP_CLIENT__)
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_PBAP_CLIENT__)
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    if (phb_pbapc_cntx_p->phb_list == 2
        #if SRV_PBAPC_LINK_NUM >= 2
        || phb_pbapc_cntx_p->phb_list == 3
        || phb_pbapc_cntx_p->cui_list == 3
        #endif
        || phb_pbapc_cntx_p->cui_list == 2)
    {
        phb_pbapc_cntx_p->qsearch_input_buffer[0] = 0;
        return;
    }
    else if (phb_pbapc_cntx_p->cui_list = 1)
    {
        phb_pbapc_cntx_p->local_qsearch_input_buffer[0] = 0;
        return;
    }
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

    sg_id = mmi_phb_cntx_mgr_get_current_sg_id();

    if (sg_id == GRP_ID_PHB_MAIN || (sg_id >= GRP_ID_PHB_CUI_LIST && sg_id <= GRP_ID_PHB_MARK_SEVERAL))
    {
        list_cntx = (mmi_phb_list_cntx_struct *) mmi_frm_group_get_user_data(sg_id);
        list_cntx->qsearch_input_buffer[0] = 0;
    }
}

#ifndef __MMI_PHB_SLIM_NO_SAT__
mmi_ret mmi_phb_cntx_mgr_sim_profile(mmi_event_struct *evt)
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
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        mmi_phb_cntx_mgr_controller(MMI_PHB_STATE_SAT, MMI_TRUE, NULL);

        mmi_phb_cntx_mgr_clear_history();
    }

    return MMI_RET_OK;
}
#endif

#define MMI_PHB_CNTX_MGR_UTIL

void mmi_phb_ucm_app_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_ucm_get_error_info(0, &popup_type);

    mmi_phb_popup_display_ext(
        str_id,
        popup_type);
}


MMI_BOOL mmi_phb_usb_app_unavailable_popup(S32 result)
{
#ifdef __USB_IN_NORMAL_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            MMI_STR_ID str_id;
            mmi_event_notify_enum popup_type;
            str_id = mmi_usb_get_error_info(result, &popup_type);
            
            mmi_phb_popup_display_ext(
                str_id,
                popup_type);
            
            return MMI_TRUE;
        }
    }
#endif

    return MMI_FALSE;
}


MMI_BOOL mmi_phb_display_popup_cb(
            mmi_id parent_id,
            UI_string_type string,
            mmi_event_notify_enum event_id,
            mmi_proc_func proc,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_id == GRP_ID_INVALID)
    {
        mmi_phb_popup_display(
            string,
            event_id);
    }
    else
    {
        mmi_popup_property_init(&arg);
        arg.parent_id = parent_id;
        arg.callback = proc;
        arg.user_tag = user_data;
        mmi_popup_display(
                   string,
                   event_id,
                   &arg);
    }

    return MMI_TRUE;
}


U16 mmi_phb_get_error_string(S32 result, mmi_event_notify_enum *popup_type, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_str = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    
    if (result == SRV_PHB_NO_ERROR)
    {
        *popup_type = MMI_EVENT_SUCCESS;
        switch (srv_phb_get_storage(store_index))
        {
            default:
                error_str = STR_GLOBAL_SAVED;
                break;
        }
    }
    else if (result == SRV_PHB_IMAGE_ERROR)
    {
        *popup_type = MMI_EVENT_SUCCESS;
        error_str = STR_ID_PHB_OP_IMAGE_FAIL;
    }
    else if (result == SRV_PHB_VIDEO_ERROR)
    {
        *popup_type = MMI_EVENT_SUCCESS;
        error_str = STR_ID_PHB_OP_VIDEO_FAIL;
    }
    else if (result == SRV_PHB_RES_ALL_ERROR)
    {
        *popup_type = MMI_EVENT_SUCCESS;
        error_str = STR_ID_PHB_OP_IMAGE_VIDEO_FAIL;
    }
    else if (result == SRV_PHB_NAME_MODIFIED)
    {
        *popup_type = MMI_EVENT_SUCCESS;
        error_str = STR_ID_PHB_NAME_MODIFIED;
    }
    else if (result == SRV_PHB_ADN_FORBID)
    {
        error_str = STR_ID_PHB_ADN_FORBID;
    }
    else if (result == SRV_PHB_NUMBER_TOO_LONG)
    {
        error_str = STR_NOT_SAVED_NUMBER_TOO_LONG;
    }
    else if (result == SRV_PHB_STORAGE_FULL && srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
    {
        error_str = STR_PHONE_FULL_MSG;
    }
    else if (result == SRV_PHB_STORAGE_FULL && srv_phb_get_storage(store_index) != PHB_STORAGE_NVRAM )
	 {
		   error_str = STR_SIM_FULL_MSG;
	 }
#ifdef __MMI_PHB_USIM_SUPPORT__
    else if (result == SRV_PHB_SIM_PARTIAL_ERROR)
    {
        error_str = STR_ID_PHB_SAVE_TO_SIM_PARTIAL_SUCCEED;
    }
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    else if (result == SRV_PHB_TCARD_NOT_AVAILABLE)
    {
        error_str = STR_ID_PHB_MEMORY_CARD_NOT_AVAILABLE;    
    }
#endif
    else
    {
        error_str = STR_GLOBAL_UNFINISHED;
    }

    return error_str;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_screen_present
 * DESCRIPTION
 *  if any phonebook screen exist in history , then reture true, others, reture false
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_screen_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_id = GRP_ID_PHB_BEGIN; group_id < GRP_ID_PHB_END; group_id++)
    {
        if (mmi_frm_group_is_present(group_id))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_storage_full_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage             [IN]
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_get_storage_full_str_id(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(storage)
    {
        case PHB_STORAGE_NVRAM:
            str_id = STR_PHONE_FULL_MSG;
            break;

    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
            str_id = STR_ID_PHB_MEMORY_CARD_FULL;
            break;
    #endif

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
    #else
        case PHB_STORAGE_SIM:
            str_id = STR_SIM_FULL_MSG;
            break;
    #endif

        case PHB_STORAGE_MAX:
        default:
            str_id = STR_PBOOK_FULL_MSG;
            break;
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (1 == srv_sim_ctrl_get_num_of_inserted() && 
        mmi_phb_check_storage(MMI_FALSE, storage) && 
        storage != PHB_STORAGE_MAX)
    {
        str_id = STR_SIM_FULL_MSG;   
    }
#endif

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_storage_status
 * DESCRIPTION
 *  test phonebook storage status
 * PARAMETERS
 *  storage             [IN]
 *  check_type          [IN]
 *  need_popup          [IN]
 * RETURNS
 *  test result
 *****************************************************************************/
MMI_BOOL mmi_phb_check_storage_status(U8 storage, mmi_phb_check_storage_enum check_type, MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_type != MMI_PHB_CHECK_STORAGE_FULL && srv_phb_get_used_contact(storage) == 0 )
    {
        if (need_popup)
        {
            if (storage == PHB_STORAGE_MAX)
            {
                str_id = STR_ID_PHB_NO_CONTACT;
            }
            else
            {
                str_id = STR_ID_PHB_NO_ENTRY_TO_SELECT; 
            }
            
            mmi_phb_popup_display_ext(
                str_id,
                MMI_EVENT_FAILURE);
        }
        return MMI_TRUE;
    }
    else if (check_type != MMI_PHB_CHECK_STORAGE_EMPTY 
            && srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        if (need_popup)
        {
            str_id = mmi_phb_get_storage_full_str_id(storage);

            mmi_phb_popup_display_ext(
                str_id,
                MMI_EVENT_FAILURE);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_storage_status
 * DESCRIPTION
 *  test phonebook storage status
 * PARAMETERS
 *  storage             [IN]
 *  check_type          [IN]
 *  need_popup          [IN]
 * RETURNS
 *  test result
 *****************************************************************************/
MMI_BOOL mmi_phb_op_all_check_storage_status(U8 storage, mmi_phb_check_storage_enum check_type, MMI_BOOL need_popup, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_type != MMI_PHB_CHECK_STORAGE_FULL && srv_phb_get_used_contact(storage) == 0 )
    {
        if (need_popup)
        {
            if (storage == PHB_STORAGE_MAX)
            {
                str_id = STR_ID_PHB_NO_CONTACT;
            }
            else
            {
                str_id = STR_ID_PHB_NO_ENTRY_TO_SELECT; 
            }

            mmi_popup_display_simple_ext(
                   str_id,
                   MMI_EVENT_FAILURE,
                   group_id,
                   0);
        }

        return MMI_TRUE;
    }
    else if (check_type != MMI_PHB_CHECK_STORAGE_EMPTY 
            && srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        if (need_popup)
        {
            str_id = mmi_phb_get_storage_full_str_id(storage);

            mmi_popup_display_simple_ext(
                   str_id,
                   MMI_EVENT_FAILURE,
                   group_id,
                   0);
        }

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_processing
 * DESCRIPTION
 *  check phonebook is processing
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_check_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phb_cntx_mgr.processing;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_ready
 * DESCRIPTION
 *  test phonebook is ready
 * PARAMETERS
 *  not_ready_popup         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_check_ready(MMI_BOOL not_ready_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_ready() || mmi_phb_check_processing())
    {
        if (not_ready_popup)
        {
            mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        }

        return MMI_FALSE;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        if (not_ready_popup)
        {
            mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        }

        return MMI_FALSE;
    }
#endif /* __SYNCML_SUPPORT__ */ 

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_ready
 * DESCRIPTION
 *  test phonebook is ready
 * PARAMETERS
 *  not_ready_popup         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_check_ready_with_sg_cb(
            mmi_id sg_id,
            MMI_BOOL not_ready_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    U16 err_str = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_ready() || mmi_phb_check_processing())
    {
        err_str = STR_PROCESSING_PHONEBOOK;        
        result = MMI_FALSE;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        err_str = STR_ID_SYNC_PLEASE_WAIT;
        result = MMI_FALSE;
    }
#endif /* __SYNCML_SUPPORT__ */ 

    if (not_ready_popup && !result)
    {
        if (sg_id == GRP_ID_INVALID)
        {
            mmi_phb_popup_display_ext(
                err_str,
                MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_phb_display_popup_cb(
                sg_id,
                (UI_string_type) GetString(err_str),
                MMI_EVENT_FAILURE,
                (mmi_proc_func)NULL,
                NULL);
        }
    }

    return result;
}

MMI_BOOL mmi_phb_check_storage_full(U8 storage, MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_string = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case PHB_STORAGE_NVRAM:
            if (srv_phb_get_total_contact(PHB_STORAGE_NVRAM) ==
                srv_phb_get_used_contact(PHB_STORAGE_NVRAM))
            {
                error_string = STR_PHONE_FULL_MSG;
            }
            break;
            
        case PHB_STORAGE_SIM:
    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
    #endif
    #if (MMI_MAX_SIM_NUM >=4)
        case PHB_STORAGE_SIM4:
    #endif
        #ifdef __MMI_TELEPHONY_SUPPORT__
            if (!srv_sim_ctrl_is_available(MMI_SIM1<<(storage - PHB_STORAGE_SIM)))
            {
                error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
            }
            else if (srv_phb_get_total_contact(storage) ==
                     srv_phb_get_used_contact(storage))
            {  
                error_string = mmi_phb_get_storage_full_str_id(storage);
            }
        #endif
            break;

        case PHB_STORAGE_MAX:
        default:
            if (srv_phb_get_total_contact(PHB_STORAGE_MAX) ==
                srv_phb_get_used_contact(PHB_STORAGE_MAX))
            {
                error_string = STR_PBOOK_FULL_MSG;
            }
            break;
    }

    if (error_string)
    {
        if (is_popup)
        {
            mmi_phb_popup_display_ext(
                error_string,
                MMI_EVENT_FAILURE);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_contact_build_field_mask
 * DESCRIPTION
 *  Phonebook build contact field mask
 * PARAMETERS
 *  contact                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_phb_contact_build_field_mask(mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(contact != NULL);

    if (contact->name[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_NAME;
    }
#ifdef __MMI_PHB_LAST_NAME_FIELD__    
    if (contact->last_name[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_NAME;
    }
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
	if (contact->nick_name[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_NICK;
    }
#endif 
    if (contact->number[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_NUMBER;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (contact->opt_num[0].number[0])
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
    }
    if (contact->opt_num[1].number[0])
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
    }
    if (contact->opt_num[2].number[0])
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
    }
    if (contact->companyName[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_COMPANY;
    }
    if (contact->emailAddress[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL1;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (contact->emailAddress2[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL2;
    }
#endif
#endif
    
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (contact->bday[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_BDAY;
    }
#endif
    
#if defined(__MMI_PHB_INFO_FIELD__)
    if (contact->title[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_TITLE;
    }
    if (contact->url[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_URL;
    }
    if (contact->pobox[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }    
    if (contact->extension[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->street[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->city[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->state[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->postalcode[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->country[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
    }
    if (contact->note[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_NOTE;
    }
#endif
    if (contact->group_id != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_GROUP;
    }
    if (contact->ring_tone_id != 0 || contact->ring_tone[0] != 0)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_RING;
    }    
    if (contact->picture[0] != 0 || (contact->picture_id != 0 && contact->picture_id != IMG_PHB_DEFAULT))
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_PIC;
    }
#if defined(__MMI_PHB_CALLER_VIDEO__)    
    if (contact->video[0] != 0 || contact->video_id & 0x8fff)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_VIDEO;
    }
#endif
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
#endif
#if 0
#if defined(__MMI_VOIP__)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    if (contact->default_number != 0xff)
    {
        field_mask |= SRV_PHB_ENTRY_FIELD_DEF;
    }
#endif

    MMI_PHB_LOG1(TRC_MMI_PHB_BUILD_FIELD_MASK, field_mask);
    return field_mask;
}


U32 mmi_phb_get_name_length(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_storage(MMI_TRUE, storage))
    {
        length = MMI_PHB_NAME_FIELD_LENGTH;
    }
    else
    {
        U32 sim_index = storage - PHB_STORAGE_SIM;

        length = (U32)srv_phb_startup_get_alpha_length(sim_index, PHB_PHONEBOOK);
    }

    return length;
}

#ifdef __MMI_VCARD__
void mmi_phb_contact_mmi_to_vcard(mmi_phb_contact_info_struct *contact, mmi_vcard_field_data_struct *vcard)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(contact != NULL && vcard != NULL);
    
    vcard->second_name = contact->name;
#ifdef __MMI_PHB_LAST_NAME_FIELD__    
    vcard->first_name = contact->last_name;
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__ 
    vcard->nick_name = contact->nick_name;
#endif

    vcard->number = contact->number;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        vcard->opt_num[i] = &(contact->opt_num[i]);
    }
    vcard->email = contact->emailAddress;
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__    
    vcard->email2 = contact->emailAddress2;
#endif
    vcard->company = contact->companyName;
#endif
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    vcard->b_year = (U16) gui_atoi(contact->b_year);
    vcard->b_month = (U8) gui_atoi(contact->b_month);
    vcard->b_day = (U8) gui_atoi(contact->b_day);
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    vcard->url = contact->url;
    vcard->title = contact->title;
    vcard->note = contact->note;
    vcard->pobox = contact->pobox;
    vcard->extension = contact->extension;
    vcard->street = contact->street;
    vcard->city = contact->city;
    vcard->state = contact->state;
    vcard->postalcode = contact->postalcode;
    vcard->country = contact->country;
#endif
    vcard->image_path = contact->picture;
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    vcard->default_number = contact->default_number;
#endif
}
#endif


static void mmi_phb_wcsncpy(WCHAR *str_dst, const WCHAR *str_src, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str_src != NULL)
    {
        mmi_wcsncpy(str_dst, str_src, count);
    }
}

void mmi_phb_contact_srv_to_mmi(srv_phb_contact_data_struct *srv_contact, mmi_phb_contact_info_struct *mmi_contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
#endif
    U16 *name;
    U16 *number;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_wcs_num_struct *opt_num;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_contact != NULL && mmi_contact != NULL);

    name = srv_contact->name;
    if (name != NULL)
    {
        srv_phb_remove_invalid_name(name);
        mmi_wcsncpy(mmi_contact->name, name, MMI_PHB_NAME_FIELD_LENGTH);
    }

#ifdef __MMI_PHB_LAST_NAME_FIELD__ 
    name = srv_contact->l_name;
    if (name != NULL)
    {
        srv_phb_remove_invalid_name(name);
        mmi_wcsncpy(mmi_contact->last_name, name, MMI_PHB_NAME_FIELD_LENGTH);
    }
#endif

#ifdef __MMI_PHB_USIM_SUPPORT__
    name = srv_contact->n_name;
	if (name!= NULL)
    {
        srv_phb_remove_invalid_name(name);
        mmi_wcsncpy(mmi_contact->nick_name, name, MMI_PHB_NAME_FIELD_LENGTH);
    }
#endif

    number = srv_contact->number;
    if (number != NULL)
    {
        srv_phb_remove_invalid_number(number);
        mmi_phb_truncate_number_field_to_max_len(mmi_contact->number, number, MMI_PHB_NUMBER_LENGTH);
    }
 
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        opt_num = srv_contact->opt_num[i];        
        if (opt_num)
        {
            srv_phb_remove_invalid_number(opt_num->number);
            memcpy(&(mmi_contact->opt_num[i]), opt_num, sizeof(mmi_phb_wcs_num_struct));
        }
    }
    mmi_phb_wcsncpy(mmi_contact->companyName, srv_contact->company_name, MMI_PHB_COMPANY_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->emailAddress, srv_contact->email_address, MMI_PHB_EMAIL_LENGTH);
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    mmi_phb_wcsncpy(mmi_contact->emailAddress2, srv_contact->email_address2, MMI_PHB_EMAIL_LENGTH);
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /*__MMI_PHB_OPTIONAL_FIELD__ */

    /* contact info fields */
#ifdef __MMI_PHB_INFO_FIELD__
    mmi_phb_wcsncpy(mmi_contact->title, srv_contact->title, MMI_PHB_TITLE_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->url, srv_contact->url, MMI_PHB_URL_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->pobox, srv_contact->pobox, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->extension, srv_contact->extension, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->street, srv_contact->street, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->city, srv_contact->city, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->state, srv_contact->state, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->postalcode, srv_contact->postalcode, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->country, srv_contact->country, MMI_PHB_ADDRESS_LENGTH);
    mmi_phb_wcsncpy(mmi_contact->note, srv_contact->note, MMI_PHB_ADDRESS_LENGTH);
#endif /* __MMI_PHB_INFO_FIELD__ */

    /* birthday info */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_phb_bday_to_string(
        mmi_contact->bday,
        mmi_contact->b_year,
        mmi_contact->b_month,
        mmi_contact->b_day,
        srv_contact->b_year,
        srv_contact->b_month,
        srv_contact->b_day);
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif

    /* Group id */
    mmi_contact->group_id = srv_contact->group_mask;

    /* Caller info*/
    mmi_contact->ring_tone_id = srv_contact->ringtone_id;

    mmi_contact->picture_id = srv_contact->image_id;
    mmi_phb_wcsncpy(mmi_contact->picture, srv_contact->image_path, SRV_FMGR_PATH_MAX_LEN);        
    
#if defined(__MMI_PHB_CALLER_VIDEO__)
    mmi_contact->video_id = srv_contact->video_id;
    mmi_phb_wcsncpy(mmi_contact->video, srv_contact->video_path, SRV_FMGR_PATH_MAX_LEN);        
#endif
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    mmi_contact->default_number = srv_contact->default_number;
#endif
}

srv_phb_contact_info_struct *mmi_phb_get_contact_build_buffer(mmi_phb_contact_info_struct* contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_phb_contact_info_struct *contact_info;
    srv_phb_contact_data_struct *field_data;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(contact != NULL);

    contact_info = (srv_phb_contact_info_struct *) mmi_phb_mem_malloc(sizeof(srv_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(contact_info, 0, sizeof(srv_phb_contact_info_struct));

    field_data = &(contact_info->field_data);

    field_data->name = contact->name;
#ifdef __MMI_PHB_LAST_NAME_FIELD__    
    field_data->l_name = contact->last_name;
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
	field_data->n_name = contact->nick_name;
#endif
    field_data->number = contact->number;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        field_data->opt_num[i] = &(contact->opt_num[i]);
    }
    field_data->opt_order = contact->opt_order;
    field_data->company_name = contact->companyName;
    field_data->email_address = contact->emailAddress;
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    field_data->email_address2 = contact->emailAddress2;
#endif
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
    field_data->title = contact->title;
    field_data->url = contact->url;
    field_data->pobox = contact->pobox;
    field_data->extension = contact->extension;
    field_data->street = contact->street;
    field_data->city = contact->city;
    field_data->state = contact->state;
    field_data->postalcode = contact->postalcode;
    field_data->country = contact->country;
    field_data->note = contact->note;
#endif
    field_data->ringtone_path = contact->ring_tone;
    field_data->image_path = contact->picture;
#if defined(__MMI_PHB_CALLER_VIDEO__)    
    field_data->video_path = contact->video;
#endif
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif    
#endif
#if 0
#if defined(__MMI_VOIP__)    
/* under construction !*/
#endif
#endif

    return contact_info;
}


void mmi_phb_get_contact_free_buffer(srv_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact != NULL)
    {
        mmi_phb_mem_free(contact);
    }
}


srv_phb_contact_info_struct* mmi_phb_contact_build(mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct *contact_info;
    srv_phb_contact_data_struct *field_data;
    U16 *res_type; 
    U16 *image_id;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    U16 *video_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(contact != NULL);
    
    contact_info = mmi_phb_get_contact_build_buffer(contact);

    field_data = &(contact_info->field_data);

    res_type = &(field_data->res_type); 
    image_id = &(field_data->image_id);
#if defined(__MMI_PHB_CALLER_VIDEO__)
    video_id = &(field_data->video_id);
#endif

    contact_info->field_mask = SRV_PHB_ENTRY_FIELD_ALL;
    
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    field_data->b_year = (U16) gui_atoi(contact->b_year);
    field_data->b_month = (U8) gui_atoi(contact->b_month);
    field_data->b_day = (U8) gui_atoi(contact->b_day);
#endif

    field_data->group_mask = contact->group_id;
    field_data->ringtone_id = contact->ring_tone_id;

    if (field_data->ringtone_path[0] != 0)
    {
        *res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
    }
    else
    {
        *res_type |= SRV_PHB_RES_TYPE_RING_ID;
    }

    *image_id = contact->picture_id;

    if (*image_id == 0x8000)
    {
        *image_id = 0;
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
    }
    else if (*image_id && (*image_id !=  IMG_PHB_DEFAULT))
    {
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)    
    *video_id = contact->video_id;

    if (*video_id & 0x4000)
    {
        *video_id &= ~(0x4000);
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
    }

    if (*video_id & 0x8000)
    {
        *video_id = 0;
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
    }
    else if (*video_id)
    {
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
    }
#endif

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    field_data->default_number = contact->default_number;
#endif
    
    return contact_info;
}


void mmi_phb_contact_get_contact_info(U16 store_index, mmi_phb_contact_info_struct* contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct *contact_info;
    srv_phb_contact_data_struct *field_data;
    U16 res_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(contact, 0, sizeof(mmi_phb_contact_info_struct));
    
    contact_info = mmi_phb_get_contact_build_buffer(contact);

    field_data = &(contact_info->field_data);

    contact_info->field_mask = SRV_PHB_ENTRY_FIELD_ALL;

    srv_phb_oplib_get_contact_info(store_index, contact_info);

    res_type = field_data->res_type; 

    /* birthday info */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_phb_bday_to_string(
        contact->bday,
        contact->b_year,
        contact->b_month,
        contact->b_day,
        field_data->b_year,
        field_data->b_month,
        field_data->b_day);
#endif

    /* Group id */
    contact->group_id = field_data->group_mask;

    /* Caller info */
    if (res_type & SRV_PHB_RES_TYPE_RING_FILE)
    {
        mmi_wcscpy(contact->ring_tone, field_data->ringtone_path);
		contact->ring_tone_id = MMI_RP_SRV_PROF_AUD_MAX;
    }
    else
    {
        contact->ring_tone_id = field_data->ringtone_id;
    }

    if (mmi_phb_check_storage(MMI_TRUE, srv_phb_get_storage(store_index)))
    {
        contact->picture_id = field_data->image_id;

        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
            contact->picture_id |= 0x8000;
            mmi_wcscpy(contact->picture, field_data->image_path);
        }
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    contact->video_id = field_data->video_id;

    if (res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        contact->video_id |= 0x8000;
    }
    if (res_type & SRV_PHB_RES_TYPE_VIDEO_SOUND_ON)
    {
        contact->video_id |= 0x4000;
    }
#endif

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    contact->default_number = field_data->default_number;
#endif

    mmi_phb_get_contact_free_buffer(contact_info);
}


mmi_phb_contact_info_struct* mmi_phb_contact_get_contact(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_info_struct *contact_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info = (mmi_phb_contact_info_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);

    mmi_phb_contact_get_contact_info(store_index, contact_info);

    return contact_info;
}

void mmi_phb_contact_free_contact(mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact != NULL)
    {
        mmi_phb_mem_free(contact);
    }
}

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_contact_get_item_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage             [IN]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_contact_get_item_image(U16 store_index, U8** image_buffer1, U8** image_buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img2_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_buffer1)
    {
        *image_buffer1 = get_image(IMG_ID_PHB_LIST_PHOTO);
    }

    if (image_buffer2)
    {
	    switch (srv_phb_get_storage(store_index))
	    {
	        case PHB_STORAGE_SIM:
    		#if (MMI_MAX_SIM_NUM >= 2)
	            img2_id = IMG_GLOBAL_SIM1;
	    	#else   
	        	img2_id = IMG_STORAGE_SIM;
	    	#endif
	            break;

		#if (MMI_MAX_SIM_NUM >= 2)
	        case PHB_STORAGE_SIM2:
	            img2_id = IMG_GLOBAL_SIM2;
	            break;
		#endif

		#if (MMI_MAX_SIM_NUM >= 3)
	        case PHB_STORAGE_SIM3:
	            img2_id = IMG_GLOBAL_SIM3;
	            break;
		#endif

		#if (MMI_MAX_SIM_NUM >= 4)
	        case PHB_STORAGE_SIM4:
	            img2_id = IMG_GLOBAL_SIM4;
	            break;
		#endif
        
        #if defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
            case PHB_STORAGE_TCARD:
                img2_id = IMG_ID_PHB_TCARD_LIST;
                break;
        #endif

	        default:
	            break;
	    }

        if (img2_id == 0)
        {
            *image_buffer2 = NULL;
        }
        else
        {
            *image_buffer2 = get_image(img2_id);
        }
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_contact_get_item_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage             [IN]
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_contact_get_item_image(U16 store_index, U8** image_buffer1, U8** image_buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img1_id = IMG_STORAGE_SIM;
#if (MMI_MAX_SIM_NUM >= 2)
    U16 img2_id = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_phb_get_storage(store_index))
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM:
            img2_id = IMG_GLOBAL_SIM1;
            break;

        case PHB_STORAGE_SIM2:
            img2_id = IMG_GLOBAL_SIM2;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            img2_id = IMG_GLOBAL_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            img2_id = IMG_GLOBAL_SIM4;
            break;
    #endif

        case PHB_STORAGE_NVRAM:
        #if defined(__MMI_VIDEO_TELEPHONY__)
            if (srv_phb_is_vt_call(store_index))
            {
                img1_id = IMG_ID_PHB_VT_CONTACT;
            }
            else
        #endif /* defined(__MMI_VIDEO_TELEPHONY__) */
            {
                img1_id = IMG_STORAGE_HANDSET;
            }
            break;

    #if defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
        case PHB_STORAGE_TCARD:
            img2_id = IMG_ID_PHB_TCARD_LIST;
            break;
    #endif

        default:
            break;
    }

    if (image_buffer1)
    {
        *image_buffer1 = get_image(img1_id);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (image_buffer2)
    {
        if (img2_id == 0)
        {
            *image_buffer2 = NULL;
        }
        else
        {
            *image_buffer2 = get_image(img2_id);
        }
    }
#endif
}
#endif


void mmi_phb_confirm_user_data_init(mmi_phb_confirm_user_data_struct * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg->sg_id = GRP_ID_INVALID;
    arg->LSK_function = NULL;
    arg->CSK_function = NULL;
    arg->RSK_function = NULL;
}


mmi_ret mmi_phb_comfirm_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
            mmi_phb_confirm_user_data_struct * confirm_data = 
                (mmi_phb_confirm_user_data_struct *)alert->user_tag;
            MenucuiPtr LSK_function = confirm_data->LSK_function;
            MenucuiPtr RSK_function = confirm_data->RSK_function;

            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                    mmi_frm_group_close(alert->alert_id);
                    break;

                case MMI_ALERT_CNFM_YES:
                    if (LSK_function != NULL)
                    {
                        LSK_function(confirm_data->sg_id);
                    }
                    break;

                case MMI_ALERT_CNFM_NO:
                    if (RSK_function != NULL)
                    {
                        RSK_function(confirm_data->sg_id);
                    }
                    break;

                default:
                    break;
            }
        }
    }

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_storage
 * DESCRIPTION
 *  check phonebook is processing
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_check_storage(MMI_BOOL is_or, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_or)
    {
        if((phb_storage_enum)storage == PHB_STORAGE_NVRAM
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            || (phb_storage_enum)storage == PHB_STORAGE_TCARD
        #endif
            )
        {
            result = MMI_TRUE;    
        }
    }
    else
    {
        if((phb_storage_enum)storage != PHB_STORAGE_NVRAM
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            && (phb_storage_enum)storage != PHB_STORAGE_TCARD
        #endif
            )
        {
            result = MMI_TRUE;    
        }    
    }

    return result;
}


