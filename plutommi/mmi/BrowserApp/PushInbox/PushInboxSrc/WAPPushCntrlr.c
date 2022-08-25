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
 * PushMsgCntrlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the various controller API of Push message.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
//#include "WAPPushUIProts.h"

    #include "MMIDataType.h"
    #include "WAPPushCntrlr.h"
    #include "MMI_features.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "WAPPushSrvTypes.h"
    #include "WAPPushScreenHdlr.h"
    #include "WAPPushDMgr.h"
#ifdef __WAP_PUSH_SUPPORT__
#include "mmi_rp_app_mmi_wap_push_def.h"
static U16 g_push_cntrl_index;

mmi_wap_push_cntrlr_struct g_push_cntrlrDB[] =
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func, /* Currently there is no case when data is not ready */
		mmi_wap_push_static_list_check_data_func
	},
#endif
   #ifdef __MMI_WAP_PUSH_BLACK_LIST__

    {   
        SCR_ID_PUSH_BLACK_LIST,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func, /* Currently there is no case when data is not ready */
		mmi_wap_push_static_list_check_data_func
	},
  #endif
    /* End of synchronous dynamic screens */

    {   
        SCR_ID_PUSH_INBOX,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func, /* Currently there is no case when data is not ready */
		mmi_wap_push_static_list_check_data_func
	},
    /* End of Asynchronous dynamic screens */

    {   
        SCR_ID_PUSH_SETTING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {   
        SCR_ID_PUSH_ENTRY_SERVICE_MSG,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
  #ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST_OPTIONS,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
 
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    #endif
    {   
        SCR_ID_BRW_SEND_BY_OPTIONS,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
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
	#endif
    {   
        SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {   
        SCR_ID_UM_MESSAGE_OPTIONS,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
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
	#endif /* 0 */
    /* End of static list screens */
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__

    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},

    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
     #endif
    {   
        SCR_ID_BRW_PUSH_ADD_BOOKMARK,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    /* End of inline screens */

    {   
        SCR_ID_PUSH_ENABLE_PUSH,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
     #ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {   
        SCR_ID_PUSH_ENABLE_BL_SETTING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    #endif
     #ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_ENABLE_WL_SETTING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    #endif
    {   
        SCR_ID_PUSH_SL_SETTING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    /* End of selection screens */

    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_message_screen_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_message_screen_get_data_of_selected_msg_func,
		mmi_wap_push_message_screen_check_data_of_selected_msg_func
	},
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
    {   
        SCR_ID_PUSH_DISPALY_SIA_CNF,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_message_screen_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_message_screen_get_data_of_sia_dlg_func,
		mmi_wap_push_message_screen_check_data_of_sia_dlg_func
	},
#endif
    /* End of message screens */

    {   
        SCR_ID_BRW_NEW_PUSH_MESSAGE_IND,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {   
        SCR_ID_BRW_PUSH_MSG_DELETED,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    /* End of notification screens */

    {   
        SCR_ID_PUSH_GENERIC_PROCESSING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {
        SCR_ID_PUSH_POPUP_SCREEN,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {
        SCR_ID_PUSH_PROCESSING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    {
        SCR_ID_PUSH_ASYNC_PROCESSING,
        mmi_wap_push_static_list_create_func,
        mmi_wap_push_static_list_pre_func,
        mmi_wap_push_static_list_show_func,
        mmi_wap_push_static_list_post_func,
        mmi_wap_push_static_list_get_data_func,
		mmi_wap_push_static_list_check_data_func
	},
    /* End of processing screens */


    /* Please add New entry above this line */
    {0, NULL, NULL, NULL, NULL, NULL, NULL}
};




/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_cntrlrDB
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  Return pointer to the controller database.
 *****************************************************************************/
mmi_wap_push_cntrlr_struct* mmi_wap_push_get_cntrlrDB (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_push_cntrlrDB[g_push_cntrl_index]);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_cntrlr_DB_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_set_cntrlr_DB_id (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_push_cntrlrDB[incr].scrn_id != 0)
    {
        if (g_push_cntrlrDB[incr].scrn_id == screen_id)
        {
            g_push_cntrl_index = incr;
            return;
        }
        incr++;
    }
    ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_invoke_cntrlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
srv_wap_push_result_enum mmi_wap_push_invoke_cntrlr (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_result_enum ret_code = SRV_WAP_PUSH_FALSE;
    mmi_wap_push_cntrlr_struct *cntrlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr = mmi_wap_push_get_cntrlrDB();
    if (cntrlr == NULL)
    {
        ASSERT (0);
    }
    ret_code = cntrlr->create_func(screen_id);
    if (ret_code == SRV_WAP_PUSH_TRUE)
    {
        ret_code = SRV_WAP_PUSH_FALSE;
        ret_code = cntrlr->pre_func(screen_id);
        if (ret_code == SRV_WAP_PUSH_TRUE)
        {
            ret_code = SRV_WAP_PUSH_FALSE;
            ret_code = cntrlr->show_func(screen_id);
            if (ret_code == SRV_WAP_PUSH_TRUE)
            {
                ret_code = SRV_WAP_PUSH_FALSE;
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



/**********************************************************************************************************/
/*                                       START CODE FOR dynamic list screen                               */
/**********************************************************************************************************/


srv_wap_push_result_enum mmi_wap_push_dynamic_list_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dynamic_list_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dynamic_list_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dynamic_list_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_dynamic_list_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_dynamic_list_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR dynamic list screen                                 */
/**********************************************************************************************************/




/**********************************************************************************************************/
/*                                       START CODE FOR Async dynamic list screen                         */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_async_dynamic_list_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_async_dynamic_list_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_async_dynamic_list_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_async_dynamic_list_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_async_dynamic_list_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_async_dynamic_list_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR Async dynamic list screen                           */
/**********************************************************************************************************/










/**********************************************************************************************************/
/*                                       START CODE FOR static list screen                                */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_static_list_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_static_list_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_static_list_show_func (U16 screen_id)
{
    mmi_wap_push_scrhdlr_if_init(screen_id);
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_static_list_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_static_list_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_static_list_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR static list screen                                  */
/**********************************************************************************************************/










/**********************************************************************************************************/
/*                                       START CODE FOR Inline screen                                     */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_inline_screen_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_inline_screen_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_inline_screen_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_inline_screen_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_inline_screen_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_inline_screen_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR Inline screen                                       */
/**********************************************************************************************************/










/**********************************************************************************************************/
/*                                       START CODE FOR Selection screen                                  */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_selection_screen_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_selection_screen_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_selection_screen_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_selection_screen_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_selection_screen_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_selection_screen_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR Selection screen                                    */
/**********************************************************************************************************/








/**********************************************************************************************************/
/*                                       START CODE FOR Message screen                                    */
/**********************************************************************************************************/

srv_wap_push_result_enum mmi_wap_push_message_screen_pre_func (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_result_enum ret_code = SRV_WAP_PUSH_FALSE;
    mmi_wap_push_cntrlr_struct *cntrlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr = mmi_wap_push_get_cntrlrDB();
    if (cntrlr == NULL)
    {
        ASSERT (0);
    }
    ret_code = (srv_wap_push_result_enum)cntrlr->data_ready_check_func(screen_id);
    if (ret_code != SRV_WAP_PUSH_TRUE)
    {
        ret_code = (srv_wap_push_result_enum)cntrlr->get_async_data_func(screen_id);
        if (ret_code != MMI_TRUE)
        {
            ret_code = SRV_WAP_PUSH_ASYNC_WAIT;
        }
    }
    return ret_code;
}


MMI_BOOL mmi_wap_push_message_screen_get_data_of_selected_msg_func (U16 screen_id)
{
    mmi_wap_push_get_data_of_selected_message();
    return MMI_FALSE;
}



MMI_BOOL mmi_wap_push_message_screen_check_data_of_selected_msg_func (U16 screen_id)
{
    return mmi_wap_push_check_selected_msg_data_ready();
}

#ifndef __MMI_WAP_PUSH_SIA_SLIM__
MMI_BOOL mmi_wap_push_message_screen_get_data_of_sia_dlg_func (U16 screen_id)
{
    mmi_wap_push_get_data_of_sia_dlg();
    return MMI_FALSE;
}



MMI_BOOL mmi_wap_push_message_screen_check_data_of_sia_dlg_func (U16 screen_id)
{
    return mmi_wap_push_check_sia_dlg_data_ready();
}
#endif
/**********************************************************************************************************/
/*                                       END CODE FOR Message screen                                      */
/**********************************************************************************************************/








/**********************************************************************************************************/
/*                                       START CODE FOR Notification screen                               */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_notification_screen_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_notification_screen_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_notification_screen_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_notification_screen_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_notification_screen_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_notification_screen_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR Notification screen                                 */
/**********************************************************************************************************/









/**********************************************************************************************************/
/*                                       START CODE FOR Process screen                                    */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_process_screen_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_process_screen_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_process_screen_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_process_screen_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_process_screen_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_process_screen_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       End CODE FOR Process screen                                      */
/**********************************************************************************************************/








/**********************************************************************************************************/
/*                                       START CODE FOR Dummy screen                                      */
/**********************************************************************************************************/
srv_wap_push_result_enum mmi_wap_push_dummy_screen_create_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dummy_screen_pre_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dummy_screen_show_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



srv_wap_push_result_enum mmi_wap_push_dummy_screen_post_func (U16 screen_id)
{
    return SRV_WAP_PUSH_TRUE;
}



MMI_BOOL mmi_wap_push_dummy_screen_get_data_func (U16 screen_id)
{
    return MMI_TRUE;
}



MMI_BOOL mmi_wap_push_dummy_screen_check_data_func (U16 screen_id)
{
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       END CODE FOR Dummy screen                                        */
/**********************************************************************************************************/

#endif /* WAP_SUPPORT*/
