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
 *  SmsUmBtMapProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Um Application For BT Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MAP_CLIENT__

#include "SmsUmBtMapGProt.h"
#include "SmsUmBtMapProt.h"
#include  "GlobalResDef.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#include "SmsBtAppProt.h"
mmi_sms_um_bt_ui_cntx_struct g_sms_um_ui_cntx;
mmi_sms_um_bt_ui_cntx_struct *g_sms_um_ui_p = &g_sms_um_ui_cntx;

mmi_sms_bt_cntx_struct g_sms_bt_ui_cntx[MMI_UM_UI_MAX_DEV_LIST_NUM];
mmi_sms_bt_cntx_struct *g_sms_bt_ui_p = &g_sms_bt_ui_cntx[0];
srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */
MMI_BOOL g_sms_bt_disable_del_event = MMI_FALSE;
U8 g_sms_bt_opt_cancel_flag = 0;
U8 g_sms_bt_send_cancel_flag = 0;

mmi_sms_bt_entry_folder_userdata g_ef_usdata;

srv_um_bt_msg_info_struct *g_sms_um_ui_msg_info_buf_p[MMI_UM_UI_MAX_MSG_INFO_NUM];
MMI_ID g_sms_bt_gid = GRP_ID_INVALID;
typedef enum
{
    MMI_SMS_UM_EF_FSM_DUMMY,
    MMI_SMS_UM_EF_FSM_INIT_INIT,
    MMI_SMS_UM_EF_FSM_INIT_DEL,
    MMI_SMS_UM_EF_FSM_INIT_KEP,
    
    MMI_SMS_UM_EF_FSM_CR_DELETE,
    MMI_SMS_UM_EF_FSM_CR_CHECK,
    MMI_SMS_UM_EF_FSM_CR_READY,

    MMI_SMS_UM_EF_FSM_CD_REF,
    MMI_SMS_UM_EF_FSM_CD_CHECK,
    MMI_SMS_UM_EF_FSM_CD_UNREADY,
    MMI_SMS_UM_EF_FSM_CD_UP_LIST,
    MMI_SMS_UM_EF_FSM_CD_REL_LIST,
    MMI_SMS_UM_EF_FSM_CD_DELETE,
    
    MMI_SMS_UM_EF_FSM_UD_REF,
    MMI_SMS_UM_EF_FSM_UD_DELETE,
    MMI_SMS_UM_EF_FSM_UD_CHECK,
    MMI_SMS_UM_EF_FSM_UD_UNREADY,
    MMI_SMS_UM_EF_FSM_UD_UP_LIST,
    MMI_SMS_UM_EF_FSM_UD_REL_LIST
    
} mmi_sms_um_ef_fsm_event_handler_enum;
const mmi_sms_um_bt_ui_fsm_event_hdlr_node sms_um_bt_fsm_ef_tb[] = 
{
    mmi_sms_um_bt_ui_fsm_eh_dummy,
        
    mmi_sms_um_bt_ui_fsm_ef_eh_init_init, 
    mmi_sms_um_bt_ui_fsm_ef_eh_init_delete,
    mmi_sms_um_bt_ui_fsm_ef_eh_init_kp_list, 
        
    mmi_sms_um_bt_ui_fsm_ef_eh_cr_delete,
    mmi_sms_um_bt_ui_fsm_ef_eh_cr_check,
    mmi_sms_um_bt_ui_fsm_ef_eh_cr_ready,
    
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_refresh, 
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_check, 
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_unready, 
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_up_list,
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_rel_list,
    mmi_sms_um_bt_ui_fsm_ef_eh_cd_delete,
        
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_refresh, 
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_delete, 
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_check, 
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_unready, 
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_up_list, 
    mmi_sms_um_bt_ui_fsm_ef_eh_ud_rel_list
    
};
const U8 g_sms_um_bt_ui_fsm_ef_event_table[MMI_UM_UI_FSM_EVENT_TOTAL][MMI_UM_UI_FSM_EF_TOTAL] =
{
    {MMI_SMS_UM_EF_FSM_INIT_INIT,       MMI_SMS_UM_EF_FSM_INIT_INIT,     MMI_SMS_UM_EF_FSM_INIT_INIT,       MMI_SMS_UM_EF_FSM_INIT_INIT,    MMI_SMS_UM_EF_FSM_INIT_INIT}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_CD_REF,      MMI_SMS_UM_EF_FSM_UD_REF,                      MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_DUMMY,       MMI_SMS_UM_EF_FSM_DUMMY,    MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_INIT_DEL,        MMI_SMS_UM_EF_FSM_CR_DELETE, MMI_SMS_UM_EF_FSM_CD_DELETE,   MMI_SMS_UM_EF_FSM_UD_DELETE,                     MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_CR_CHECK,  MMI_SMS_UM_EF_FSM_CD_CHECK,    MMI_SMS_UM_EF_FSM_UD_CHECK,                      MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_CR_READY,  MMI_SMS_UM_EF_FSM_DUMMY,       MMI_SMS_UM_EF_FSM_DUMMY,    MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_CD_UNREADY,  MMI_SMS_UM_EF_FSM_UD_UNREADY,                     MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_CD_REL_LIST, MMI_SMS_UM_EF_FSM_UD_REL_LIST,    MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_CD_UP_LIST,  MMI_SMS_UM_EF_FSM_UD_UP_LIST,    MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_INIT_KEP,        MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_DUMMY,       MMI_SMS_UM_EF_FSM_DUMMY,    MMI_SMS_UM_EF_FSM_DUMMY}, 
    {MMI_SMS_UM_EF_FSM_DUMMY,           MMI_SMS_UM_EF_FSM_DUMMY,     MMI_SMS_UM_EF_FSM_DUMMY,       MMI_SMS_UM_EF_FSM_DUMMY,    MMI_SMS_UM_EF_FSM_DUMMY}
};
const U16 g_sms_um_bt_ui_show_hide_menu[] =
{
    0
};
typedef MMI_BOOL (*if_event_hdlr)(U16 screen_id, U16 event, void *arg);
void mmi_sms_bt_get_inbox_list_cb(srv_sms_callback_struct* data);
void mmi_sms_bt_get_outbox_list_cb(srv_sms_callback_struct* data);
void mmi_sms_bt_get_unsent_list_cb(srv_sms_callback_struct* data);
void mmi_sms_bt_get_drafts_list_cb(srv_sms_callback_struct* data);


srv_sms_btmapc_bt_enum  mmi_sms_bt_get_active_index()
{
    return g_sms_active_dev_index;
}


U16 mmi_sms_um_bt_ui_if_entry_general(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp, U16 type, void *extend_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct setting;
    U16 disp_scrn_id = 0;
    mmi_sms_um_bt_ui_aprc_st_enum aprc_type = MMI_SMS_UM_BT_UI_SCRN_TYPE_TOTAL;
    if_event_hdlr evt_hdlr =  NULL;
    scrn_init_func init_func = NULL;
    MMI_BOOL result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct));
    kal_prompt_trace(MOD_MMI, "[SMS],Entry mmi_sms_um_bt_ui_if_entry_general");
    
    setting.folder.msg_type = g_sms_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    switch (type)
    {
		case MMI_SMS_UM_BT_ENTRY_SCREEN_WRITE_MESSAGE:
		{
            disp_scrn_id = STR_SMS_UM_BT_WRITE_MSG_ID;
            /* Set appearance */
            aprc_type = MMI_SMS_UM_BT_UI_SCRN_TYPE_MAIN_MENU;
            evt_hdlr = mmi_sms_um_bt_ui_sh_main_msg_event_hdlr;
            init_func = mmi_sms_um_bt_ui_sh_main_msg_init;
		}
		break;
		case MMI_SMS_UM_BT_ENTRY_SCREEN_MAIN_MENU:
        {
            disp_scrn_id = SCR_ID_SMS_UM_BT_MAIN_MESSAGE;
            /* Set appearance */
            aprc_type = MMI_SMS_UM_BT_UI_SCRN_TYPE_MAIN_MENU;
            evt_hdlr = mmi_sms_um_bt_ui_sh_main_msg_event_hdlr;
            init_func = mmi_sms_um_bt_ui_sh_main_msg_init;
        }
		break;
        
		case MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER:
        {
            /* Check network status */
            if (MMI_FALSE == mmi_sms_um_bt_ui_int_is_available())
            {
                //mmi_sms_um_current_not_avaiable_popup();
                return 0;
            }

            /* Check pending action */
            //if (mmi_sms_um_bt_ui_ut_check_all_msg_pending_action())
            {
                //return 0;
            }
		
            setting.folder.msg_box_type = ((srv_sms_um_box_identity_struct *)extend_data)->msg_box_type;
            disp_scrn_id = SCR_ID_SMS_UM_BT_FOLDER;
            /* Set appearance */
            aprc_type = MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER;
            evt_hdlr = mmi_sms_um_bt_ui_sh_general_folder_event_hdlr;
            init_func = mmi_sms_um_bt_ui_sh_general_folder_init;
        }
            break;
        case MMI_SMS_UM_BT_ENTRY_SCREEN_LOADING:
        {
            /* Check loding scrn */
            for(i = 0; i < g_sms_um_ui_p->cc_cntx.num_of_scrn; i++)
            {
                if((g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id != 0) && (g_sms_um_ui_p->cc_cntx.scrn_table[i].aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING))
                {
                    mmi_sms_um_bt_ui_ut_del_relative_scrn(&(g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id));
                }
            }

            disp_scrn_id = SCR_ID_SMS_UM_BT_PROCESSING;
            /* Set appearance */
            aprc_type = MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING;
            /* Set screen handler */
            evt_hdlr = mmi_sms_um_bt_ui_sh_process_event_hdlr;
            init_func = mmi_sms_um_bt_ui_sh_process_init;
        }
            break;

        default:
            break;
    }

    setting.scrn_id = mmi_sms_um_bt_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = disp_scrn_id;
    
    /* Set appearance */
    setting.aprc_type = aprc_type;
    
    /* Set screen handler */
    setting.event_hdlr = evt_hdlr;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_sms_um_bt_ui_cc_create_scrn_cntx(&setting, init_func);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_if_entry_general mmi_sms_um_bt_ui_cc_create_scrn_cntx");

    MMI_ASSERT(result == MMI_TRUE);

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BT_UI_IF_ENTRY_MAIN_MESSAGE, setting.scrn_id);

    return setting.scrn_id;
}

MMI_ID g_sms_um_ui_main_menu_scrn_id = 0;

void mmi_sms_um_bt_entry_main_message_menu_int()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set all zero */
    memset(g_sms_um_ui_p, 0, sizeof(mmi_sms_um_bt_ui_cntx_struct));
    
    /* setting init */
    g_sms_um_ui_p->setting.support_msg_type = SRV_UM_MSG_SMS;
    g_sms_um_ui_p->setting.scrn_id_counter = 0;

    /* set message information buffer */
    memset(g_sms_um_ui_msg_info_buf_p, 0, sizeof(g_sms_um_ui_msg_info_buf_p));
    scrn_id = mmi_sms_um_bt_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_SMS_UM_BT_ENTRY_SCREEN_MAIN_MENU, NULL);
    //g_sms_um_ui_main_menu_scrn_id = scrn_id;
    mmi_sms_um_bt_ui_ut_send_init_event(scrn_id);
	return;
}


MMI_BOOL mmi_sms_um_bt_ui_cc_create_scrn_cntx(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting, 
                    scrn_init_func init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID int_grp_id;
    MMI_ID root_grp_id;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BT_UI_CC_CREATE_SCRN_CNTX, setting->scrn_id);
    
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_free_scrn_cntx();

    if (scrn_cntx == NULL)
    {
        return MMI_FALSE;
    }

    memset(scrn_cntx, 0, sizeof(mmi_sms_um_bt_ui_cc_scrn_cntx_struct));
    int_grp_id = root_grp_id = GRP_ID_INVALID;

    if (MMI_TRUE == setting->new_grp)
    {
        srv_sms_um_pool_clean(SRV_UM_MSG_SMS,SRV_UM_MSG_BOX_ALL);
        /* create a new root group for message application */
        /*grp_cntx = mmi_sms_um_bt_ui_cc_get_free_grp_cntx();
        MMI_ASSERT(NULL != grp_cntx);
        root_grp_id = mmi_frm_group_create(
                        setting->parent_group_id, 
                        GRP_ID_AUTO_GEN, 
                        NULL, 
                        (void*) grp_cntx);
        mmi_frm_group_enter(root_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        grp_cntx->root_grp_id = root_grp_id;*/

        /* create a internal group for UM app */
        /*int_grp_id = mmi_frm_group_create(
                        root_grp_id, 
                        GRP_ID_AUTO_GEN, 
                        mmi_sms_um_bt_ui_cc_grp_proc, 
                        (void*) grp_cntx);
        mmi_frm_group_enter(int_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        grp_cntx->grp_id = int_grp_id;
        g_sms_um_ui_p->cc_cntx.num_of_grp++;*/
        //g_sms_bt_gid = grp_cntx->grp_id; /*Akhil*/
    }
    //else
    //{
        /* no need to create new group */
        int_grp_id = setting->parent_group_id;
    //}
//    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_UM_BT_UI_CC_GROUP_CNTX, root_grp_id, int_grp_id, setting->new_grp);
    /* set the group id */
    scrn_cntx->group_id = int_grp_id;

    scrn_cntx->scrn_id = setting->scrn_id;
    scrn_cntx->parent_scrn_id = setting->parent_scrn_id;
    scrn_cntx->event_hdlr = setting->event_hdlr;

    init(scrn_cntx, setting);

    g_sms_um_ui_p->cc_cntx.num_of_scrn++;

    return MMI_TRUE;
}

MMI_BOOL mmi_sms_um_bt_ui_cc_send_event(U16 scrn_id,mmi_sms_um_bt_ui_event_enum event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CC_SEND_EVENT, scrn_id, event);

    if (g_sms_um_ui_p->cc_cntx.num_of_scrn == 0)
    {
        return MMI_TRUE;
    }

    /* Broadcast the event to all existed screens */
    if (scrn_id == 0)
    {
        for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
        {
            if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id != 0)
            {
                scrn_id = g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id;
                result = g_sms_um_ui_p->cc_cntx.scrn_table[i].event_hdlr(scrn_id, (U16)event, arg);
                if (result == MMI_FALSE)
                {
                    MMI_ASSERT(0);
                    return result;
                }
            }
        }

        return MMI_TRUE;
    }

    /* find the specified screen id */
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            break;
        }
    }

    /* could not find the specified screen id */
    if (i == MMI_UM_UI_MAX_SCRN_CNTX_NUM)
    {
        return MMI_FALSE;
    }

    result = g_sms_um_ui_p->cc_cntx.scrn_table[i].event_hdlr(scrn_id, (U16)event, arg);

    if (result == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    return result;
}
U16 mmi_sms_um_bt_ui_cc_get_parent_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);

    if (NULL == scrn_cntx)
    {
        /* No finding any screen context */
        return 0;
    }

    return scrn_cntx->parent_scrn_id;
}
U16 mmi_sms_um_bt_ui_cc_get_child_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);

    if (NULL == scrn_cntx)
    {
        /* No finding any screen context */
        return 0;
    }

    return scrn_cntx->child_scrn_id;
}
MMI_BOOL mmi_sms_um_bt_ui_cc_check_scrn_alive(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_FALSE;

    /* No child screen */
    if (scrn_id == 0)
    {
        return result;
    }
    
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        /* hit */
        if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            result = MMI_TRUE;
            break;
        }
    }

    return result;
}
void mmi_sms_um_bt_ui_cc_delete_scrn_cntx(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);

    if (scrn_cntx == NULL)
    {
        return;
    }

    memset(scrn_cntx, 0, sizeof(mmi_sms_um_bt_ui_cc_scrn_cntx_struct));
    
    g_sms_um_ui_p->cc_cntx.num_of_scrn--;
}

mmi_sms_um_bt_ui_cc_scrn_cntx_struct *mmi_sms_um_bt_ui_cc_get_scrn_cntx(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = NULL;
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (scrn_id == g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id)
        {
            scrn_cntx = &(g_sms_um_ui_p->cc_cntx.scrn_table[i]);
            break;
        }
    }

    return scrn_cntx;
}

mmi_sms_um_bt_ui_cc_scrn_cntx_struct* mmi_sms_um_bt_ui_cc_get_free_scrn_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = NULL;
    for (i = 0; i < MMI_SMS_UM_BT_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id == 0)
        {
            scrn_cntx = &g_sms_um_ui_p->cc_cntx.scrn_table[i];
            return scrn_cntx;
        }
    }

    return NULL;
}
void mmi_sms_um_bt_ui_cc_delete_all_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id > 0)
        {
            result =mmi_sms_um_bt_ui_cc_send_event(g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            MMI_ASSERT(result == MMI_TRUE);
        }
    }
}
U16 mmi_sms_um_bt_ui_cc_get_grp_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_grp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.grp_table[i].grp_id != GRP_ID_INVALID)
        {
            num_of_grp++;
        }
    }

    return num_of_grp;
}
mmi_sms_um_bt_ui_cc_grp_cntx_struct *mmi_sms_um_bt_ui_cc_get_free_grp_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
   mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_cntx = NULL;

    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.grp_table[i].grp_id == 0)
        {
            grp_cntx = &g_sms_um_ui_p->cc_cntx.grp_table[i];
            break;
        }
    }

    return grp_cntx;
}

mmi_ret mmi_sms_um_bt_ui_cc_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_cntx = (mmi_sms_um_bt_ui_cc_grp_cntx_struct *)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        {
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_sms_um_bt_ui_cc_deinit_grp_cntx();
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}
mmi_ret mmi_sms_um_bt_ui_cc_destroy_all_grp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.grp_table[i].grp_id != GRP_ID_INVALID)
        {
            /* call framework api to destroy, destroy the root group id */
            ret = mmi_frm_group_close(g_sms_um_ui_p->cc_cntx.grp_table[i].root_grp_id);
            if (MMI_RET_OK != ret)
            {
                return ret;
            }
        }
    }

    return ret;
}
MMI_ID mmi_sms_um_bt_ui_cc_get_root_grp_id(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_ID root_grp_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.grp_table[i].grp_id == group_id)
        {
            root_grp_id = g_sms_um_ui_p->cc_cntx.grp_table[i].root_grp_id;
            break;
        }
    }

    return root_grp_id;
}
srv_um_msg_btmapc_box_enum mmi_sms_um_bt_ui_cc_get_active_scrn_msg_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_btmapc_box_enum active_scrn_box_type = SRV_UM_MSG_BOX_NONE;
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        scrn_cntx = &(g_sms_um_ui_p->cc_cntx.scrn_table[i]);
        /* has instance & active */
        if (0 != scrn_cntx->scrn_id &&
            MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
        {
            active_scrn_box_type = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
            break;
        }
    }

    return active_scrn_box_type;
}


void mmi_sms_um_bt_ui_cc_del_grp_cntx(mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(grp_cntx, 0, sizeof(mmi_sms_um_bt_ui_cc_grp_cntx_struct));
    grp_cntx->grp_id = GRP_ID_INVALID;
    g_sms_um_ui_p->cc_cntx.num_of_grp--;
}

U16 mmi_sms_um_bt_ui_if_entry_write_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    return mmi_sms_um_bt_ui_if_entry_general(parent_scrn_id,parent_grp_id,new_grp, MMI_SMS_UM_BT_ENTRY_SCREEN_WRITE_MESSAGE, NULL);
}

U16 mmi_sms_um_bt_ui_if_entry_processing(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_if_entry_processing");
    return mmi_sms_um_bt_ui_if_entry_general(parent_scrn_id, parent_grp_id, new_grp, MMI_SMS_UM_BT_ENTRY_SCREEN_LOADING, NULL);
}

void mmi_sms_um_current_not_avaiable_popup(void)
{
    mmi_popup_display_simple(
            (WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
}

srv_um_msg_enum mmi_sms_um_bt_ui_cc_get_support_msg_type_by_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_enum support_msg_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    support_msg_type = SRV_UM_MSG_NONE;
    
    for (i = 0 ; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        if (g_sms_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            break;
        }
    }

    if (i == MMI_UM_UI_MAX_SCRN_CNTX_NUM)
    {
        return support_msg_type;
    }

    support_msg_type = g_sms_um_ui_p->cc_cntx.scrn_table[i].screen_hdlr.folder_type.msg_type;
    
    return support_msg_type;
}
MMI_ID mmi_sms_um_bt_ui_adp_cui_launch_by_menu_id(MMI_ID parent_grp_id, MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CUI_LAUNCH_MENU_ID, parent_grp_id, menu_id);

    switch (menu_id)
    {
	case MENU_ID_SMS_UM_WRITE_MSG:
		{
			cui_sms_bt_write_launch(parent_grp_id);
            break;
		}
        default:
        {
            break;
        }
    }

    return grp_id;
}


void mmi_sms_um_bt_ui_cc_deinit_grp_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_cntx=&(((*g_sms_um_ui_p).cc_cntx).grp_table[0]);
    mmi_frm_group_close(grp_cntx->grp_id);
    memset(grp_cntx, 0, sizeof(mmi_sms_um_bt_ui_cc_grp_cntx_struct));
    grp_cntx->grp_id = GRP_ID_INVALID;
    g_sms_um_ui_p->cc_cntx.num_of_grp--;

    mmi_frm_group_close(g_sms_bt_gid);
    g_sms_bt_gid = GRP_ID_INVALID;
}


mmi_ret mmi_sms_um_bt_deinit_grp_cntx_on_shift(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
	
	srv_sms_event_struct *evt_sms = (srv_sms_event_struct *)evt;
    srv_sms_event_update_struct *event_data = (srv_sms_event_update_struct *)evt_sms->event_info;
	
    srv_sms_btmapc_bt_enum bt_index = event_data->bt_index;
    SrvSmsCallbackFunc func;
    int i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_GET_SHIFT_EVT);
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();    
    for (i = 0; i < MMI_SMS_BT_BOX_END; i++)
    {
        g_sms_bt_ui_p[bt_index].need_refresh[i] = MMI_TRUE;
    }
    if (scrn_cntx == NULL)
        return;
   

    if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER &&
        g_sms_active_dev_index == bt_index && (!g_sms_bt_ui_p[bt_index].is_on_request))
    {
        srv_um_msg_btmapc_box_enum box_type;
        mmi_sms_bt_entry_folder_userdata *userdata;

        userdata = &g_ef_usdata;
        userdata->is_back_folder = MMI_FALSE;
        userdata->scrn_id = scrn_cntx->scrn_id;
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_deinit_grp_cntx_on_shift scrn_cntx->scrn_id = %d", scrn_cntx->scrn_id);     
        userdata->bt_index = event_data->bt_index;

        box_type = scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type;
        switch (box_type)
        {
            case SRV_UM_MSG_BTMAPC_BOX_INBOX:
            {
                func = mmi_sms_bt_get_inbox_list_cb;
                break;
            }
            case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
            {
                func = mmi_sms_bt_get_outbox_list_cb;
                break;
            }
            case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
            {
                func = mmi_sms_bt_get_drafts_list_cb;
                break;
            }
            case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
            {
                func = mmi_sms_bt_get_unsent_list_cb;
                break;
            }
        }
        if (!g_sms_bt_ui_p[bt_index].is_on_request)
        {
            if (box_type == SRV_UM_MSG_BTMAPC_BOX_UNSENT || box_type == SRV_UM_MSG_BTMAPC_BOX_OUTBOX)
            {
                if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_UNSENT) != 0)
                {
                #ifndef __MMI_TELEPHONY_SUPPORT__
                    srv_sms_btmapc_delete_all();
                #else
                    srv_sms_btmapc_storage_reset_data(MMI_TRUE);
                #endif
                }
            //}
            kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_um_bt_deinit_grp_cntx_on_shift Entry mmi_sms_um_bt_ui_if_entry_processing "); 				
        	scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
            g_sms_bt_ui_p[bt_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[bt_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_TRUE,
          	    scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type,
         	    func,
            	(void *)userdata);
            g_sms_bt_ui_p[bt_index].is_on_request = MMI_TRUE;
				
            mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            }
        }
    }
    return MMI_RET_OK;
}


void mmi_sms_bt_app_init()
{
    memset(g_sms_um_ui_p, 0, sizeof(mmi_sms_um_bt_ui_cntx_struct));
    
    /* setting init */
    g_sms_um_ui_p->setting.support_msg_type = SRV_UM_MSG_SMS;
    g_sms_um_ui_p->setting.scrn_id_counter = 0;

    /* set message information buffer */
    memset(g_sms_um_ui_msg_info_buf_p, 0, sizeof(g_sms_um_ui_msg_info_buf_p));
    srv_sms_um_pool_clean(SRV_UM_MSG_SMS,SRV_UM_MSG_BOX_ALL);
}


void mmi_sms_bt_app_set_cntx(void* cntx)
{
    mmi_sms_um_bt_ui_cntx_struct* bt_cntx = (mmi_sms_um_bt_ui_cntx_struct*)cntx;

    if (bt_cntx)
    {
        //memcpy(&g_sms_um_ui_p->setting, &bt_cntx->setting, sizeof(mmi_sms_um_bt_ui_setting_struct));
        //memcpy(&g_sms_um_ui_p->cc_cntx.grp_table[0], &bt_cntx->cc_cntx.grp_table[0], sizeof(mmi_sms_um_bt_ui_cc_grp_cntx_struct));
        
        memcpy(g_sms_um_ui_p, bt_cntx, sizeof(mmi_sms_um_bt_ui_cntx_struct));
    }
    g_sms_um_ui_p->setting.support_msg_type = SRV_UM_MSG_SMS;
}
#endif



