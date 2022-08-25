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
 * BTMMIAVRCP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bluetooth AVRCP MMI application
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
/***************************************************************************** 
* Included files
*****************************************************************************/

/* avrcp header files */
//#include "bt_avrcp_struct.h"
//#include "bt_avrcp.h"

//#include "BtcmSrvGprot.h"
//#include "BTMMIAVRCPGProt.h"

#ifdef __MMI_A2DP_SUPPORT__
//#include "av_bt.h"
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
#include "BTMMIAVRCPGProt.h"
#include "mmi_rp_srv_avrcp_def.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_init(void)
{
    srv_avrcp_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_set_cmd_hdlr(AVRCPCmdFuncPtr callback_func)
{
    srv_avrcp_set_cmd_hdlr((AVRCP_SRV_CMD_CALLBACK)callback_func);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_clear_cmd_hdlr(AVRCPCmdFuncPtr callback_func)
{
    srv_avrcp_clear_cmd_hdlr((AVRCP_SRV_CMD_CALLBACK)callback_func);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_frm_sync_calllback
 * DESCRIPTION
 *  for framework to callback if keypad / touch is triggered.
 * PARAMETERS
 *  BOOL    [IN] is keypad / touch blocked by target
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_bt_avrcp_frm_sync_calllback(BOOL is_blocked)
//{
//    srv_avrcp_frm_sync_calllback(is_blocked);
//}

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_get_actively_connect_tg_flag
 * DESCRIPTION
 *  get flag 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//MMI_BOOL mmi_bt_avrcp_get_actively_connect_tg_flag(void)
//{
//    return srv_avrcp_get_actively_connect_tg_flag();
//}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_set_actively_connect_tg_flag
 * DESCRIPTION
 *  for em to set this flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_bt_avrcp_set_actively_connect_tg_flag(MMI_BOOL on_off)
//{
//    srv_avrcp_set_actively_connect_tg_flag(on_off);
//}

#endif

#ifdef __MMI_AVRCP_DEBUG__

#include "ExtDeviceDefs.h"
#include "CommonScreens.h"
#include "SettingProfile.h"

#define MMI_BT_AVRCP_CMD_NUM    58

typedef struct
{
    U8 cmd_value;
    U16 str_id;
}mmi_bt_avrcp_cmd_struct;

static mmi_bt_avrcp_cmd_struct g_mmi_bt_avrcp_cmd[] =
{
BT_AVRCP_OP_UNIT_INFO           ,STR_BT_AVRCP_CMD_UNIT_COMMAND,
BT_AVRCP_OP_SUBUNIT_INFO        ,STR_BT_AVRCP_CMD_SUBUNIT_COMMAND,
MMI_AVRCP_POP_SELECT            ,STR_BT_AVRCP_CMD_SELECT,
MMI_AVRCP_POP_UP                ,STR_BT_AVRCP_CMD_UP,
MMI_AVRCP_POP_DOWN              ,STR_BT_AVRCP_CMD_DOWN,
MMI_AVRCP_POP_LEFT              ,STR_BT_AVRCP_CMD_LEFT,
MMI_AVRCP_POP_RIGHT             ,STR_BT_AVRCP_CMD_RIGHT,
MMI_AVRCP_POP_RIGHT_UP          ,STR_BT_AVRCP_CMD_RIGHT_UP,
MMI_AVRCP_POP_RIGHT_DOWN        ,STR_BT_AVRCP_CMD_RIGHT_DOWN,
MMI_AVRCP_POP_LEFT_UP           ,STR_BT_AVRCP_CMD_LEFT_UP,
MMI_AVRCP_POP_LEFT_DOWN         ,STR_BT_AVRCP_CMD_LEFT_DOWN,
MMI_AVRCP_POP_ROOT_MENU         ,STR_BT_AVRCP_CMD_ROOT_MENU,
MMI_AVRCP_POP_SETUP_MENU        ,STR_BT_AVRCP_CMD_SETUP,
MMI_AVRCP_POP_CONTENTS_MENU     ,STR_BT_AVRCP_CMD_CONTENTS,
MMI_AVRCP_POP_FAVORITE_MENU     ,STR_BT_AVRCP_CMD_FAVORITE,
MMI_AVRCP_POP_EXIT              ,STR_BT_AVRCP_CMD_EXIT,
MMI_AVRCP_POP_0                 ,STR_BT_AVRCP_CMD_0,
MMI_AVRCP_POP_1                 ,STR_BT_AVRCP_CMD_1,
MMI_AVRCP_POP_2                 ,STR_BT_AVRCP_CMD_2,
MMI_AVRCP_POP_3                 ,STR_BT_AVRCP_CMD_3,
MMI_AVRCP_POP_4                 ,STR_BT_AVRCP_CMD_4,
MMI_AVRCP_POP_5                 ,STR_BT_AVRCP_CMD_5,
MMI_AVRCP_POP_6                 ,STR_BT_AVRCP_CMD_6,
MMI_AVRCP_POP_7                 ,STR_BT_AVRCP_CMD_7,
MMI_AVRCP_POP_8                 ,STR_BT_AVRCP_CMD_8,
MMI_AVRCP_POP_9                 ,STR_BT_AVRCP_CMD_9,
MMI_AVRCP_POP_DOT               ,STR_BT_AVRCP_CMD_DOT,
MMI_AVRCP_POP_ENTER             ,STR_BT_AVRCP_CMD_ENTER,
MMI_AVRCP_POP_CLEAR             ,STR_BT_AVRCP_CMD_CLEAR,
MMI_AVRCP_POP_CHANNEL_UP        ,STR_BT_AVRCP_CMD_CHANNEL_UP,
MMI_AVRCP_POP_CHANNEL_DOWN      ,STR_BT_AVRCP_CMD_CHANNEL_DOWN,
MMI_AVRCP_POP_PREVIOUS_CHANNEL  ,STR_BT_AVRCP_CMD_PREVIOUS_CHANNEL,
MMI_AVRCP_POP_SOUND_SELECT      ,STR_BT_AVRCP_CMD_SOUND_SELECT,
MMI_AVRCP_POP_INPUT_SELECT      ,STR_BT_AVRCP_CMD_INPUT_SELECT,
MMI_AVRCP_POP_DISPLAY_INFO      ,STR_BT_AVRCP_CMD_DISPLAY_INFO,
MMI_AVRCP_POP_HELP              ,STR_BT_AVRCP_CMD_HELP,
MMI_AVRCP_POP_PAGE_UP           ,STR_BT_AVRCP_CMD_PAGE_UP,
MMI_AVRCP_POP_PAGE_DOWN         ,STR_BT_AVRCP_CMD_PAGE_DOWN,
MMI_AVRCP_POP_POWER             ,STR_BT_AVRCP_CMD_POWER,
MMI_AVRCP_POP_VOLUME_UP         ,STR_BT_AVRCP_CMD_VOLUME_UP,
MMI_AVRCP_POP_VOLUME_DOWN       ,STR_BT_AVRCP_CMD_VOLUME_DOWN,
MMI_AVRCP_POP_MUTE              ,STR_BT_AVRCP_CMD_MUTE,
MMI_AVRCP_POP_PLAY              ,STR_BT_AVRCP_CMD_PLAY,
MMI_AVRCP_POP_STOP              ,STR_BT_AVRCP_CMD_STOP,
MMI_AVRCP_POP_PAUSE             ,STR_BT_AVRCP_CMD_PAUSE,
MMI_AVRCP_POP_RECORD            ,STR_BT_AVRCP_CMD_RECORD,
MMI_AVRCP_POP_REWIND            ,STR_BT_AVRCP_CMD_REWIND,
MMI_AVRCP_POP_FAST_FORWARD      ,STR_BT_AVRCP_CMD_FAST_FORWARD,
MMI_AVRCP_POP_EJECT             ,STR_BT_AVRCP_CMD_EJECT,
MMI_AVRCP_POP_FORWARD           ,STR_BT_AVRCP_CMD_FORWARD,
MMI_AVRCP_POP_BACKWARD          ,STR_BT_AVRCP_CMD_BACKWARD,
MMI_AVRCP_POP_ANGLE             ,STR_BT_AVRCP_CMD_ANGLE,
MMI_AVRCP_POP_SUBPICTURE        ,STR_BT_AVRCP_CMD_SUBPICTURE,
MMI_AVRCP_POP_F1                ,STR_BT_AVRCP_CMD_F1,
MMI_AVRCP_POP_F2                ,STR_BT_AVRCP_CMD_F2,
MMI_AVRCP_POP_F3                ,STR_BT_AVRCP_CMD_F3,
MMI_AVRCP_POP_F4                ,STR_BT_AVRCP_CMD_F4,
MMI_AVRCP_POP_F5                ,STR_BT_AVRCP_CMD_F5
};

#ifdef __MMI_AVRCP_CT_SUPPORT__

static U16 g_mmi_bt_avrcp_ct_curr_cmd;

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_cmd_confirm
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_cmd_confirm(U16 op_code, U8 command_type, BOOL key_press)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR display_buffer[80];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op_code)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            mmi_ucs2cpy(display_buffer, (CHAR*) GetString(STR_BT_AVRCP_CMD_UNIT_COMMAND));
            break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            mmi_ucs2cpy(display_buffer, (CHAR*) GetString(STR_BT_AVRCP_CMD_SUBUNIT_COMMAND));
            break;

        case BT_AVRCP_OP_PASS_THROUGH:
            mmi_ucs2cpy(display_buffer, (CHAR*) GetString(mmi_bt_avrcp_util_get_cmd_string(command_type)));
            break;

        default:
            mmi_ucs2cpy(display_buffer, (CHAR*) GetString(STR_GLOBAL_ERROR));        
            break;
    }

    mmi_ucs2cat(display_buffer, (CHAR*)L"\n Response\0");

    mmi_popup_display_simple((WCHAR*) display_buffer, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_send_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_send_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_bt_avrcp_ct_curr_cmd == 0)
    {
        srv_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_UNIT_INFO, 0, 0);
    }
    else if(g_mmi_bt_avrcp_ct_curr_cmd == 1)
    {
        srv_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_SUBUNIT_INFO, 0, 0);    
    }
    else
    {
        srv_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_PASS_THROUGH, g_mmi_bt_avrcp_cmd[g_mmi_bt_avrcp_ct_curr_cmd].cmd_value, 1); /*just send key down*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main_list_highlight_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_main_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_avrcp_ct_curr_cmd = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main_list_item
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_bt_avrcp_ct_main_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) str_buff, (CHAR*) GetString(g_mmi_bt_avrcp_cmd[item_index].str_id));
    img_buff_p = NULL;

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BT_AVCRP_CT_MAIN, NULL, mmi_bt_avrcp_ct_main, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BT_AVCRP_CT_MAIN);

    if (gui_buffer == NULL)
    {
        g_mmi_bt_avrcp_ct_curr_cmd = 0;
        srv_avrcp_set_cmd_frame_cnf_hdlr((AVRCP_SRV_CMD_CNF_CALLBACK)mmi_bt_avrcp_ct_cmd_confirm);
    }

    RegisterHighlightHandler(mmi_bt_avrcp_ct_main_list_highlight_hdlr);

    ShowCategory184Screen(
        STR_GLOBAL_OK, /* Title ID*/
        IMG_GLOBAL_OK, /* Title ICON */
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_BT_AVRCP_CMD_NUM,
        mmi_bt_avrcp_ct_main_list_item,
        NULL,
        g_mmi_bt_avrcp_ct_curr_cmd,
        gui_buffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_avrcp_ct_send_cmd, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    SetKeyHandler(mmi_bt_avrcp_ct_send_cmd, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /*#ifdef __MMI_AVRCP_CT_SUPPORT__ */
#endif /* #ifdef __MMI_AVRCP_DEBUG__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_util_get_cmd_string
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_bt_avrcp_util_get_cmd_string(U8 command)
{
#ifdef __MMI_AVRCP_DEBUG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 2 ; i < MMI_BT_AVRCP_CMD_NUM ; i++)
    {
        if(command == g_mmi_bt_avrcp_cmd[i].cmd_value)
        {
            return g_mmi_bt_avrcp_cmd[i].str_id;
        }
    }
#endif

    return 0;
}

#ifdef __MMI_AVRCP_TEST__

U8  avrcp_test_counter = 0;
U8  avrcp_forward = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_different_down_cmd
 * DESCRIPTION
 *  Test when different down cmd comes before previous down cmd times up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_different_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;

    switch(avrcp_test_counter)
    {
        case 0 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_PLAY ;        /*play button down*/
            avrcp_test_counter ++ ;
        }
        break;
        case 1 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_STOP ;        /*stop button down*/
            avrcp_test_counter ++ ;
        }
        break;
        case 2 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_STOP | 0x80 ; /*stop button up*/
            avrcp_test_counter = 0 ;
        }
        break;
        default:
            avrcp_test_counter = 0 ;            
        break;     
    }

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

    if( avrcp_test_counter != 0 )
    {
        StartTimer(BT_AVRCP_TEST_TIMER, 1000, (FuncPtr)mmi_bt_avrcp_tst_different_down_cmd);
    }    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_same_down_cmd
 * DESCRIPTION
 *  Test when same down cmd comes before previous down cmd times up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_same_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;

    if(avrcp_test_counter <4)
    {
        if(avrcp_forward%2)
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_FORWARD;         /*stop button down*/
        }
        else
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_BACKWARD;         /*stop button down*/
        }
    }
    else
    {
        if(avrcp_forward%2)
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_FORWARD| 0x80;  /*stop button up*/
        }
        else
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_BACKWARD| 0x80;  /*stop button up*/
        }
        avrcp_forward ++ ;
    }
    
    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

    if( avrcp_test_counter < 4 )
    {
        avrcp_test_counter ++ ;
        StartTimer(BT_AVRCP_TEST_TIMER, 1000, (FuncPtr)mmi_bt_avrcp_tst_same_down_cmd);
    }
    else
    {
        avrcp_test_counter = 0;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_only_down_cmd
 * DESCRIPTION
 *  Test when only down cmd comes witout up cmd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_only_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;
    msg_p->frame_data[1] = MMI_AVRCP_POP_STOP; //MMI_AVRCP_POP_PLAY ;        /*play button down*/

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_only_up_cmd
 * DESCRIPTION
 *  Test when only up cmd comes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_only_up_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;
    msg_p->frame_data[1] = MMI_AVRCP_POP_PLAY | 0x80 ;        /*play button up*/

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

}

#endif /*__MMI_AVRCP_TEST__*/
#endif /* (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)) */

