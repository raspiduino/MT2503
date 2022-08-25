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
 *  UDXMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX Agent logic control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_UDX_SUPPORT__
#include "ProtocolEvents.h"

#include "UDXProt.h"
#include "UDXGprot.h"
#include "mmi_rp_app_udx_def.h"
#include "mmi2udx_struct.h"
#include "custom_udx.h"
#include "UcmSrvGprot.h"
#include "CommonScreens.h"
#include "filemgrsrvgprot.h"
#include "filemgrcuigprot.h"
#include "filemgrgprot.h"
#include "menucuigprot.h"
#include "globalresdef.h"

#ifdef __MMI_UDX_VCARD_SUPPORT__
#include "PhonebookGprot.h"
#include "PhbSrvGprot.h"
#include "Phbcuigprot.h"
#include "App_usedetails.h"
#include "app_datetime.h"
#endif /* __MMI_UDX_VCARD_SUPPORT__ */

#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIObexGprots.h"
#include "BTMMIScrGprots.h"
#endif /* __MMI_OPP_SUPPORT__ */ 

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_udx_builder_pre_header_req(void);
static void mmi_udx_builder_header_rsp(void);
static void mmi_udx_builder_pre_data_req(void);
static void mmi_udx_builder_data_rsp(void);
static void mmi_udx_builder_pre_abort(void);
static void mmi_udx_builder_abort_rsp(void);
static void mmi_udx_builder_end_rsp(void);
static void mmi_udx_builder_error_hdlr(U8 error_code);
static void mmi_udx_builder_get_data_from_database(void);

static void mmi_udx_parser_header_rsp(void);
static void mmi_udx_parser_pre_header_req(void);
static void mmi_udx_parser_pre_body_req(void);
static void mmi_udx_parser_pre_data_req(void);
static void mmi_udx_parser_body_rsp(void);
static void mmi_udx_parser_pre_abort(void);
static void mmi_udx_parser_abort_rsp(void);
static void mmi_udx_parser_error_hdlr(U8 error_code);
static MMI_BOOL mmi_udx_parser_pre_parse_check(void);
static void mmi_udx_parser_end_ind(void);

static void mmi_udx_handle_app_processing(U8 type, MMI_BOOL set);
static void mmi_udx_builder_delete_udx_file(void);
static mmi_ret mmi_udx_app_data_change_notification(mmi_event_struct* param);
static void mmi_udx_enter_phb_select_record(void);
static void mmi_udx_builder_get_app_data_index_hdlr(void* index_hdlr, U16 num_count);

#ifdef __MMI_UDX_VCARD_SUPPORT__
static void mmi_udx_get_phb_data(void* index_array, U16 sequence);
static void mmi_udx_store_phb_data(void* data_buffer);
static void mmi_udx_store_phb_data_cb(S32 result, U16 store_index, void *user_data);
static void mmi_udx_malloc_phb_buffer(srv_phb_contact_info_struct *srv_entry);
static void mmi_udx_free_phb_buffer(srv_phb_contact_info_struct *srv_entry);
static void mmi_udx_birthday_to_asc_string(CHAR *bday, U16 b_year, U8 b_mon, U8 b_day);
static MMI_BOOL mmi_udx_birthday_retrieve(CHAR* bday, U16* y, U8* m, U8* d);
#endif /* __MMI_UDX_VCARD_SUPPORT__ */

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_udx_cntx_struct g_mmi_udx_cntx;

/* udx core api define table */
const mmi_udx_core_struct udx_support_type_func_tbl[MMI_UDX_TYPE_TOTAL + 1] =
{
#ifdef __MMI_UDX_VCARD_SUPPORT__
    {UDX_TYPE_VCARD,
     mmi_udx_enter_phb_select_record,
     mmi_udx_get_phb_data,
     mmi_udx_store_phb_data,
    },
#endif /* __MMI_UDX_VCARD_SUPPORT__ */

    /* add new type before this */
    {
     0xff, NULL, NULL, NULL
    }
};

/* udx type info table */
const mmi_udx_type_info_struct udx_support_type_string_tbl[MMI_UDX_TYPE_TOTAL + 1] =
{
#ifdef __MMI_UDX_VCARD_SUPPORT__
    {UDX_TYPE_VCARD,
     STR_ID_UDX_VCARD,
     STR_ID_UDX_VCARD_SELECT_QUERY,
     IMG_ID_UDX_VCARD
    },
#endif /* __MMI_UDX_VCARD_SUPPORT__ */

    /* add new type before this */
    {
     0xff, 0xffff, 0xffff, 0xffff
    }
};

const U8 udx_support_type_tbl[MMI_UDX_TYPE_TOTAL + 1] =
{
#ifdef __MMI_UDX_VCARD_SUPPORT__
    UDX_TYPE_VCARD,
#endif

    /* add new type */
    /*
    UDX_TYPE_VCALENDAR,
    UDX_TYPE_SMS,
    UDX_TYPE_MMS,
    UDX_TYPE_EMAIL */

    0xff
};


#define MMI_UDX_INIT
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_init_cntx
 * DESCRIPTION
 *  udx cntx init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_INIT_CNTX);
    
    memset(&g_mmi_udx_cntx, 0, sizeof(mmi_udx_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_ini_data_change_register
 * DESCRIPTION
 *  udx cntx init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_ini_data_change_register(void)
{
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
}


#define MMI_UDX_BUILDER
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_select_data_record
 * DESCRIPTION
 *  udx builder show select data req confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_select_data_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_UDX_LOG2(MMI_UDX_BUILLD_FILE_DATA_REQ, g_mmi_udx_cntx.udx_agent.type_selected, g_mmi_udx_cntx.udx_agent.type_index);

    /* select data record for all data type */
    /* g_mmi_udx_cntx.udx_agent.type_index ini value is 0 */
    if (g_mmi_udx_cntx.data_type_state[g_mmi_udx_cntx.udx_agent.type_index] == 1)
    {
        /* after select reset the state array */
        g_mmi_udx_cntx.data_type_state[g_mmi_udx_cntx.udx_agent.type_index] = 0;

        udx_support_type_func_tbl[g_mmi_udx_cntx.udx_agent.type_index].show_select_scr();
        return;
    }

    /* after all app data record have been seletcted, will come here*/      
    if (g_mmi_udx_cntx.udx_agent.type_selected != 0)
    {
        MMI_UDX_LOG1(MMI_UDX_AGENT_DATA_TYPE_SELECTED, g_mmi_udx_cntx.udx_agent.type_selected);
        
	    mmi_udx_builder_entry_fmgr();
	}
    /* Do not select any data record */
	else
	{
	    mmi_udx_builder_data_type_select_fail();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_pre_header_req
 * DESCRIPTION
 *  udx agent builder build header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_pre_header_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG1(MMI_UDX_BUILDER_PRE_BEGIN, g_mmi_udx_cntx.udx_agent.type_selected);
    
    MMI_ASSERT(g_mmi_udx_cntx.udx_agent.type_selected != 0);

    /* MAUI_01479102 : this solution is just to fix the issue, and need to 
     * revise
     */
    for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
    {
        if (g_mmi_udx_cntx.udx_agent.type_selected & udx_support_type_tbl[i])
        {
            switch (udx_support_type_tbl[i])
            {
            #ifdef __MMI_UDX_VCARD_SUPPORT__
                case UDX_TYPE_VCARD:
                    if (!mmi_phb_check_ready(MMI_TRUE))
                    {                
                        mmi_udx_builder_delete_udx_file();
                        return;
                    }
                    else
                    {
                        mmi_udx_handle_app_processing(UDX_TYPE_VCARD, MMI_TRUE);
                    }
                    break;
            #endif
            
                case UDX_TYPE_VCALENDAR:
                case UDX_TYPE_SMS:
                case UDX_TYPE_MMS:
                case UDX_TYPE_EMAIL:                
                default:
                    MMI_ASSERT(0);
                    break;
              }
    
        }
    }
    /* MAUI_01479102 : this solution is just to fix the issue, and need to 
     * revise
     */

    g_mmi_udx_cntx.info_str = STR_ID_UDX_BUILDING;
    g_mmi_udx_cntx.percentage = 0;
    
    mmi_udx_entry_show_processing_percentage();

    mmi_udx_builder_header_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_header_rsp
 * DESCRIPTION
 *  udx agent builder pre build : build body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_header_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_BUILDER_PRE_BUILD);
    
    if (g_mmi_udx_cntx.udx_agent.error_code == UDX_CODE_NO_ERROR)
    {
        /* set the sequence to an invalid value */
        g_mmi_udx_cntx.udx_agent.sequence = 0xffff;
        mmi_udx_builder_run(MMI_UDX_BUILDER_DATA_REQ);
    }
    else
    {
        mmi_udx_builder_error_hdlr(g_mmi_udx_cntx.udx_agent.error_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_pre_data_req
 * DESCRIPTION
 *  udx agent builder pre build : to get data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_pre_data_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL build_continue = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_udx_cntx.udx_agent.sequence == 0xffff                                       /* the first enter */
        || g_mmi_udx_cntx.udx_agent.sequence > g_mmi_udx_cntx.udx_agent.sequence_max - 1    /* the last enter */
        )
    {
        /* the last enter */
        if (g_mmi_udx_cntx.udx_agent.sequence > g_mmi_udx_cntx.udx_agent.sequence_max - 1)
        {
            mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_curr, MMI_FALSE);
        }
          
        for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
        {
            if (g_mmi_udx_cntx.udx_agent.type_selected & udx_support_type_tbl[i])
            {
                build_continue = MMI_TRUE;
                
                g_mmi_udx_cntx.udx_agent.type_curr = udx_support_type_tbl[i];
                g_mmi_udx_cntx.udx_agent.sequence = 1;

                g_mmi_udx_cntx.udx_agent.type_selected &= ~(g_mmi_udx_cntx.udx_agent.type_curr);

                mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_curr, MMI_TRUE);
                
                switch (g_mmi_udx_cntx.udx_agent.type_curr)
                {
                #ifdef __MMI_UDX_VCARD_SUPPORT__
                    case UDX_TYPE_VCARD:
                        g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.vcard_num;
                        break;
                #endif
                
                    case UDX_TYPE_VCALENDAR:                    
                        g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.vcalendar_num;
                        break;
                        
                    case UDX_TYPE_SMS:                    
                        g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.sms_num;
                        break;
                        
                    case UDX_TYPE_MMS:                    
                        g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.mms_num;
                        break;
                        
                    case UDX_TYPE_EMAIL:                
                        g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.email_num;
                        break;
                        
                    default:
                        MMI_ASSERT(0);
                        break;
                  }

                  MMI_UDX_LOG2(MMI_UDX_BUILDER_PRE_DATA_REQ, g_mmi_udx_cntx.udx_agent.type_curr, g_mmi_udx_cntx.udx_agent.sequence_max);

                  break;
            }
        }
    }
    else                    /* build next sequence req */
    {
        build_continue = MMI_TRUE;
        g_mmi_udx_cntx.udx_agent.sequence++;
    }

    if (build_continue)     /* build next */
    {
        mmi_udx_update_processing_percentage();
        mmi_udx_builder_get_data_from_database();
    }
    else                    /* build end */
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_END_REQ);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_data_rsp
 * DESCRIPTION
 *  udx agent builder data rsp : to get next data or error handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_data_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.udx_agent.error_code == UDX_CODE_NO_ERROR)
    {
        mmi_udx_builder_pre_data_req();
    }
    else
    {
        mmi_udx_builder_error_hdlr(g_mmi_udx_cntx.udx_agent.error_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_pre_abort
 * DESCRIPTION
 *  udx agent builder pre abort : send abort msg to udx task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_pre_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* release data list index buffer for each database */
    mmi_udx_builder_app_list_cui_close();
    
    mmi_udx_builder_abort_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_abort_rsp
 * DESCRIPTION
 *  udx agent builder abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_abort_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);

    mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_curr, MMI_FALSE);

    mmi_udx_builder_delete_udx_file();
 
	if (!g_mmi_udx_cntx.cancel_by_user)
    {   
        /* if cancel by sim invalid, all screens are deleted by idle */
        return;
	}   

    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_ID_UDX_ABORTED), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        NULL);

    mmi_udx_agent_delete_scr(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_end_rsp
 * DESCRIPTION
 *  udx agent builder end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_end_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);

    /* will send it by bt */
#if defined(__MMI_OPP_SUPPORT__)
    if (g_mmi_udx_cntx.udx_agent.error_code == UDX_ERR_NO_ERROR
        && mmi_bt_is_to_display_bt_menu())
    {
        if (g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_OTHER_APP
            || g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_BUILDER)
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_DONE), 
                MMI_EVENT_SUCCESS, 
                GRP_ID_ROOT, 
                NULL);
            
            g_mmi_udx_cntx.first_play_tone = MMI_TRUE;

            /* insert log screen node in the top of group */
            mmi_udx_insert_node(SCR_ID_UDX_SEND_WAY, mmi_udx_builder_entry_send_way, MMI_FRM_NODE_AT_LATEST_FLAG);
            mmi_udx_agent_delete_scr();
        }
    }
    else
#endif /* __MMI_OPP_SUPPORT__ */

    {
        mmi_udx_builder_error_hdlr(g_mmi_udx_cntx.udx_agent.error_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_get_data_from_database
 * DESCRIPTION
 *  UDX agent buider get data from database
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_get_data_from_database(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type_index = MMI_UDX_TYPE_TOTAL;
    void *data_hdlr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_BUILDER_DATA_REQ);
    
    /* add new type */
    switch (g_mmi_udx_cntx.udx_agent.type_curr)
    {
    #ifdef __MMI_UDX_VCARD_SUPPORT__
        case UDX_TYPE_VCARD:
            type_index = MMI_UDX_TYPE_VCARD;
            data_hdlr = g_mmi_udx_cntx.udx_agent.vcard_index_hdlr;
            break;
    #endif /* __MMI_UDX_VCARD_SUPPORT__ */
    
        case UDX_TYPE_VCALENDAR:            
        case UDX_TYPE_SMS:            
        case UDX_TYPE_MMS:            
        case UDX_TYPE_EMAIL:            
        default:
            MMI_ASSERT(0);
            break;
    }

    (udx_support_type_func_tbl[type_index].get_data)(data_hdlr, g_mmi_udx_cntx.udx_agent.sequence);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_delete_udx_file
 * DESCRIPTION
 *  udx agent builder abort and del temp file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_delete_udx_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.file_path[0] != 0 || g_mmi_udx_cntx.file_path[1] != 0)
    {
        FS_Delete((U16*)g_mmi_udx_cntx.file_path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_error_hdlr
 * DESCRIPTION
 *  udx agent builder error hdlr, header rsp/data rsp/end rsp all call this api
 *  as long as it fail
 * PARAMETERS
 *  error_code          [IN]        builder error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_error_hdlr(U8 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);
    MMI_UDX_LOG1(MMI_UDX_AGENT_ERROR_CODE_IS, error_code);
    
    mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_curr, MMI_FALSE);
    
    switch (error_code)
    {
        case UDX_CODE_NO_ERROR:
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_DONE), 
                MMI_EVENT_SUCCESS, 
                GRP_ID_ROOT, 
                NULL);
            
            mmi_udx_agent_delete_scr();
            break;
        }
        case UDX_CODE_DISK_FULL_ERROR:    
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
            
            mmi_udx_builder_delete_udx_file();
            
            mmi_udx_agent_delete_scr();
            break;
        }
        case UDX_CODE_NEW_XML_ERROR:
        case UDX_CODE_ENCODING_ERROR:
        case UDX_CODE_MISMATCH_ERROR:
        case UDX_CODE_ATTRIBUTE_ERROR:
        case UDX_CODE_ENTITY_ERROR:
        case UDX_CODE_XML_DOC_ERROR:
        case UDX_CODE_STAG_ERROR:
        case UDX_CODE_ETAG_ERROR:
        case UDX_CODE_DATA_ERROR:
        case UDX_CODE_UNEXPECTED_ERROR:
        default:
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_UNFINISHED), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
            
            mmi_udx_builder_delete_udx_file();

            mmi_udx_agent_delete_scr();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_run
 * DESCRIPTION
 *  udx agent builder error hdlr
 * PARAMETERS
 *  builder_state          [IN]        builder state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_run(U8 builder_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (builder_state)
    {
        case MMI_UDX_BUILDER_HEADER_REQ:
            mmi_udx_builder_pre_header_req();
            break;

        case MMI_UDX_BUILDER_HEADER_RSP:
            mmi_udx_builder_header_rsp();
            break;

        case MMI_UDX_BUILDER_DATA_REQ:
            mmi_udx_builder_pre_data_req();
            break;

        case MMI_UDX_BUILDER_DATA_RSP:
            mmi_udx_builder_data_rsp();
            break;

        case MMI_UDX_BUILDER_ABORT_REQ:
            mmi_udx_builder_pre_abort();
            break;

        case MMI_UDX_BUILDER_ABORT_RSP:
            mmi_udx_builder_abort_rsp();
            break;

        case MMI_UDX_BUILDER_END_REQ:
            mmi_udx_builder_end_req();
            break;

        case MMI_UDX_BUILDER_END_RSP:
            mmi_udx_builder_end_rsp();
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
}


#define MMI_UDX_PARSER
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_paser_get_file_header_info
 * DESCRIPTION
 *  UDX agent get file header info req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_paser_get_file_header_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_udx_parser_run(MMI_UDX_PARSER_HEADER_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_pre_header_req
 * DESCRIPTION
 *  UDX agent parser pre get header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_pre_header_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_PARSER_PRE_HEADER_REQ);
    
    /* to check if the file exist or can be read */    
    if (!mmi_udx_parser_pre_parse_check())
    {
        return;
    }

    /* set udx parse part */
    g_mmi_udx_cntx.udx_agent.parse_part = UDX_PARSE_PART_HEADER;
    
    mmi_udx_parser_header_req();
    mmi_udx_show_processing(STR_ID_UDX_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_header_rsp
 * DESCRIPTION
 *  UDX agent get file info done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_header_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);
    MMI_UDX_LOG1(MMI_UDX_GET_FIEL_INFO_DONE, g_mmi_udx_cntx.udx_agent.error_code);

    if (g_mmi_udx_cntx.udx_agent.error_code == UDX_CODE_NO_ERROR)
    {
        if (g_mmi_udx_cntx.parse_header_only)
        {
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 
                || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
            #ifndef __MMI_BACKGROUND_CALL__
                || srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0            
            #endif
                )
            {
                mmi_udx_insert_node(SCR_ID_UDX_FILE_VIEW_INFO, mmi_udx_parser_entry_view_header_info, MMI_FRM_NODE_AT_LATEST_FLAG);
            }
            else
            {
				mmi_udx_parser_entry_view_header_info();
            }
        }
        /* continue parse the body after header is parsed done */
        else
        {
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 
                || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
            #ifndef __MMI_BACKGROUND_CALL__
                || srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0            
            #endif
                )
            {
                mmi_udx_insert_node(SCR_ID_UDX_DATA_TYPE_SELECT, mmi_udx_parser_entry_data_type_select, MMI_FRM_NODE_AT_LATEST_FLAG);
            }
            else
            {
				mmi_udx_parser_entry_data_type_select();
            }
        }
    }
    else
    {
        mmi_udx_parser_error_hdlr(g_mmi_udx_cntx.udx_agent.error_code);
    }
    
    mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING);

    /* close fmgr only entry from UDX agent */
    if (g_mmi_udx_cntx.start_from == MMI_UDX_PARSE_FROM_PARSER)
    {
        cui_file_selector_close(g_mmi_udx_cntx.fmgr_gid);
    }
    
    cui_menu_close(g_mmi_udx_cntx.parse_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_pre_body_req
 * DESCRIPTION
 *  UDX agent parser pre get data body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_pre_body_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(g_mmi_udx_cntx.udx_agent.type_selected != 0);

    /* to check if the file exist or can be read */    
    if (!mmi_udx_parser_pre_parse_check())
    {
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING);
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_DATA_TYPE_SELECT);
        return;
    }

    /* MAUI_01479102 : this solution is just to fix the issue, and need to 
     * revise
     */    
    memset(&g_mmi_udx_cntx.data_type_state, 0, MMI_UDX_TYPE_TOTAL);

    for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
    {
        if (g_mmi_udx_cntx.udx_agent.type_selected & udx_support_type_tbl[i])
        {
            switch (udx_support_type_tbl[i])
            {
        #ifdef __MMI_UDX_VCARD_SUPPORT__
                case UDX_TYPE_VCARD:
                    if (!mmi_phb_check_ready(MMI_TRUE))
                    {                
                        return;
                    }
                    else
                    {
                        mmi_udx_handle_app_processing(UDX_TYPE_VCARD, MMI_TRUE);
                    }
                    break;
        #endif
            
                case UDX_TYPE_VCALENDAR:
                case UDX_TYPE_SMS:
                case UDX_TYPE_MMS:
                case UDX_TYPE_EMAIL:                
                default:
                    MMI_ASSERT(0);
                    break;
              }
    
        }
    }
    /* MAUI_01479102 : this solution is just to fix the issue, and need to 
     * revise
     */

    g_mmi_udx_cntx.udx_agent.sequence = 0;
    
    g_mmi_udx_cntx.info_str = STR_ID_UDX_PARSE_SAVING;
    g_mmi_udx_cntx.percentage = 0;
    g_mmi_udx_cntx.udx_agent.type_old = g_mmi_udx_cntx.data_type_array[0];
    g_mmi_udx_cntx.udx_agent.type_curr = g_mmi_udx_cntx.data_type_array[0];

    /* set udx parse part */
    g_mmi_udx_cntx.udx_agent.parse_part = UDX_PARSE_PART_BODY;
    
    mmi_udx_entry_show_processing_percentage();
    
    mmi_udx_parser_body_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_body_rsp
 * DESCRIPTION
 *  UDX agent parser body rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_body_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.udx_agent.error_code == UDX_CODE_NO_ERROR)
    {
        mmi_udx_parser_pre_data_req();
    }
    /* fail when parsing body */
    else
    {
		MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);

        mmi_udx_parser_error_hdlr(g_mmi_udx_cntx.udx_agent.error_code);
        
        /* insert log screen node in the top of group */
        mmi_udx_insert_node(SCR_ID_UDX_PARSE_LOG, mmi_udx_parser_end_show_log, MMI_FRM_NODE_AT_LATEST_FLAG);

        mmi_udx_agent_delete_scr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_pre_data_req
 * DESCRIPTION
 *  UDX agent parser pre get next data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_pre_data_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.udx_agent.type_curr != g_mmi_udx_cntx.udx_agent.type_old)
    {
        mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_old, MMI_FALSE);

        g_mmi_udx_cntx.udx_agent.type_old = g_mmi_udx_cntx.udx_agent.type_curr;

        mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_curr, MMI_TRUE);
    }

    if (g_mmi_udx_cntx.udx_agent.type_curr != 0xff)
    {     
        switch (g_mmi_udx_cntx.udx_agent.type_curr)
        {
        #ifdef __MMI_UDX_VCARD_SUPPORT__
            case UDX_TYPE_VCARD:
                g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.header_info.vcard_record;
                break;
        #endif
        
            case UDX_TYPE_VCALENDAR:                    
                g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.header_info.vcalendar_record;
                break;
                
            case UDX_TYPE_SMS:                    
                g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.header_info.sms_record;
                break;
                
            case UDX_TYPE_MMS:                    
                g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.header_info.mms_record;
                break;
                
            case UDX_TYPE_EMAIL:                
                g_mmi_udx_cntx.udx_agent.sequence_max = g_mmi_udx_cntx.udx_agent.header_info.email_record;
                break;
                
            default:
                MMI_ASSERT(0);
                break;
        }

        mmi_udx_update_processing_percentage();
    }
    
    mmi_udx_parser_data_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_pre_abort
 * DESCRIPTION
 *  UDX agent parser pre abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_pre_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG1(MMI_UDX_PARSER_PRE_ABORT, g_mmi_udx_cntx.udx_agent.state);
    
    mmi_udx_parser_abort_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_abort_rsp
 * DESCRIPTION
 *  UDX agent parser end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_abort_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_PARSER_ABORT);    
	MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);

    mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_old, MMI_FALSE);

	if (!g_mmi_udx_cntx.cancel_by_user)
	{
		return;
	}

    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_ID_UDX_ABORTED), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        NULL);
    
    if (g_mmi_udx_cntx.udx_agent.parse_part == UDX_PARSE_PART_BODY)
    {
        /* insert log screen node in the top of group */
        mmi_udx_insert_node(SCR_ID_UDX_PARSE_LOG, mmi_udx_parser_end_show_log, MMI_FRM_NODE_AT_LATEST_FLAG);

        mmi_udx_agent_delete_scr();
    }
    else
    {    
        mmi_udx_parser_header_del_scr();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_end_ind
 * DESCRIPTION
 *  UDX agent parser end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_end_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL show_done = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_PARSER_END);    
	MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);

    mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_old, MMI_FALSE);

    for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
    {
        if (g_mmi_udx_cntx.udx_agent.parse_log[i].lost_count
            || g_mmi_udx_cntx.udx_agent.parse_log[i].storage_full)
        {
            show_done = MMI_FALSE;
            break;
        }
    }

    if (show_done)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_DONE), 
            MMI_EVENT_SUCCESS, 
            GRP_ID_ROOT, 
            NULL);
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_UDX_DATA_NOT_ADDED), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
    }

    /* insert log screen node in the top of group */
    mmi_udx_insert_node(SCR_ID_UDX_PARSE_LOG, mmi_udx_parser_end_show_log, MMI_FRM_NODE_AT_LATEST_FLAG);

    mmi_udx_agent_delete_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_pre_parse_check
 * DESCRIPTION
 *  to check if the file exist or can be read
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_udx_parser_pre_parse_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*) g_mmi_udx_cntx.file_path, FS_READ_ONLY);
    if (fh >= 0)
    {
        FS_Close(fh);
        return MMI_TRUE;
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string((U16)srv_fmgr_fs_error_get_string((S32)fh)), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);

        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_error_hdlr
 * DESCRIPTION
 *  parser error code hdlr
 * PARAMETERS
 *  error_code        [IN]        parser error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_error_hdlr(U8 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_AGENT_STATE_INIT);
    MMI_UDX_LOG1(MMI_UDX_AGENT_ERROR_CODE_IS, error_code);
    
    mmi_udx_handle_app_processing(g_mmi_udx_cntx.udx_agent.type_old, MMI_FALSE);
    
    switch (error_code)
    {
        case UDX_CODE_NO_ERROR:
            break;
        case UDX_CODE_FILE_NOT_FOUND_ERROR:
            
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_FILE_NOT_FOUND), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);

            break;

        case UDX_CODE_DISK_FULL_ERROR:    
        case UDX_CODE_NEW_XML_ERROR:
        case UDX_CODE_ENCODING_ERROR:
        case UDX_CODE_MISMATCH_ERROR:
        case UDX_CODE_ATTRIBUTE_ERROR:
        case UDX_CODE_ENTITY_ERROR:
        case UDX_CODE_XML_DOC_ERROR:
        case UDX_CODE_STAG_ERROR:
        case UDX_CODE_ETAG_ERROR:
        case UDX_CODE_DATA_ERROR:
        case UDX_CODE_UNEXPECTED_ERROR:
        default:    
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_INVALID_FORMAT), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);

            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_run
 * DESCRIPTION
 *  UDX agent parser control function
 * PARAMETERS
 *  parser_state        [IN]        parser state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_run(U8 parser_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (parser_state)
    {
        case MMI_UDX_PARSER_HEADER_REQ:
            mmi_udx_parser_pre_header_req();
            break;
            
        case MMI_UDX_PARSER_HEADER_RSP:
            mmi_udx_parser_header_rsp();
            break;
            
        case MMI_UDX_PARSER_BODY_REQ:
            mmi_udx_parser_pre_body_req();
            break;

        case MMI_UDX_PARSER_BODY_RSP:
            mmi_udx_parser_body_rsp();
            break;

        case MMI_UDX_PARSER_ABORT_REQ:
            mmi_udx_parser_pre_abort();
            break;

        case MMI_UDX_PARSER_ABORT_RSP:
            mmi_udx_parser_abort_rsp();
            break;
            
        case MMI_UDX_PARSER_END_IND:
            mmi_udx_parser_end_ind();
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
}


#define MMI_UDX_CORE_API
#ifdef __MMI_UDX_VCARD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_get_phb_data
 * DESCRIPTION
 *  udx get phb data
 * PARAMETERS
 *  void* index_array   [IN] phb index stored in phb
 *  U16 sequence        [IN] current index need get 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_get_phb_data(void* index_array, U16 sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    udx_vcard_data_struct *udx_vcard;
    srv_phb_contact_info_struct srv_contact;
    U16 temp_buffer[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U16 store_index = 0;
    U16* data_index  = (U16*) index_array;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_entry_exist(data_index[sequence - 1]))
    {    
        mmi_udx_builder_data_req(NULL, sequence);
        return;
    }
    else
    {    
        store_index = data_index[sequence - 1];
    }
    
    udx_vcard = (udx_vcard_data_struct *) OslMalloc(sizeof(udx_vcard_data_struct));        
    memset(udx_vcard, 0, sizeof(udx_vcard_data_struct));

    /* if get SIM card phone, only get name and number */
    if (srv_phb_get_storage(store_index) != PHB_STORAGE_NVRAM)
    {
        srv_phb_get_name(store_index, (U16 *) udx_vcard->n, MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_get_number(store_index, temp_buffer, MMI_PHB_NUMBER_PLUS_LENGTH);
        mmi_ucs2_to_asc((CHAR *) udx_vcard->tel_cell, (CHAR *) temp_buffer);
    }
    else
    {
        mmi_udx_malloc_phb_buffer(&srv_contact);
        
        srv_phb_oplib_get_contact_info(store_index, &srv_contact);

        mmi_ucs2cpy((CHAR*)udx_vcard->n, (const CHAR*)srv_contact.field_data.name);
        mmi_ucs2cpy((CHAR*)udx_vcard->l_n, (const CHAR*)srv_contact.field_data.l_name);
        mmi_ucs2_to_asc((CHAR*)udx_vcard->tel_cell, (CHAR*)srv_contact.field_data.number);

        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            udx_vcard->dyn_num[i].type = srv_contact.field_data.opt_num[i]->type;
            mmi_ucs2_to_asc((CHAR*)udx_vcard->dyn_num[i].number, (CHAR*)srv_contact.field_data.opt_num[i]->number);
        }

        mmi_ucs2cpy((CHAR*)udx_vcard->adr_mailbox, (const CHAR*)srv_contact.field_data.pobox);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_detail, (const CHAR*)srv_contact.field_data.extension);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_street, (const CHAR*)srv_contact.field_data.street);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_city, (const CHAR*)srv_contact.field_data.city);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_province, (const CHAR*)srv_contact.field_data.state);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_postcode, (const CHAR*)srv_contact.field_data.postalcode);
        mmi_ucs2cpy((CHAR*)udx_vcard->adr_country, (const CHAR*)srv_contact.field_data.country);
        
        mmi_ucs2_to_asc((CHAR*)udx_vcard->url, (CHAR*)srv_contact.field_data.url);
        mmi_ucs2cpy((CHAR*)udx_vcard->org_name, (const CHAR*)srv_contact.field_data.company_name);
        mmi_ucs2cpy((CHAR*)udx_vcard->title, (const CHAR*)srv_contact.field_data.title);
        
        mmi_ucs2_to_asc((CHAR*)udx_vcard->email, (CHAR*)srv_contact.field_data.email_address);
        mmi_ucs2_to_asc((CHAR*)udx_vcard->email_home, (CHAR*)srv_contact.field_data.email_address2);

        mmi_udx_birthday_to_asc_string(
            (CHAR*)udx_vcard->bday, 
            srv_contact.field_data.b_year, 
            srv_contact.field_data.b_month, 
            srv_contact.field_data.b_day);
        
        mmi_udx_free_phb_buffer(&srv_contact);
    }
    
    mmi_udx_builder_data_req(udx_vcard, sequence);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_store_phb_data
 * DESCRIPTION
 *  udx store phb data
 * PARAMETERS
 *  void* index_array   [IN] phb index stored in phb
 *  U16 sequence        [IN] current index need get 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_store_phb_data(void* data_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    udx_vcard_data_struct *udx_vcard = (udx_vcard_data_struct *) data_buffer;
    srv_phb_contact_info_struct srv_contact ; 
    U8 select_storage;
    MMI_BOOL num_valid = MMI_TRUE;
	U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_storage_status(PHB_STORAGE_NVRAM) != SRV_PHB_STORAGE_STATUS_FULL)
    {
        select_storage = PHB_STORAGE_NVRAM;
    }
    else
    {
        mmi_udx_store_data_continue(MMI_TRUE, MMI_FALSE);
        return;
    }

    mmi_udx_malloc_phb_buffer(&srv_contact);
    
    mmi_ucs2cpy((CHAR*) srv_contact.field_data.name, (CHAR *) udx_vcard->n);
    mmi_ucs2cpy((CHAR*) srv_contact.field_data.l_name, (CHAR *) udx_vcard->l_n);
    mmi_asc_to_ucs2((CHAR *) srv_contact.field_data.number, (CHAR *) udx_vcard->tel_cell);
    
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        srv_contact.field_data.opt_num[i]->type = udx_vcard->dyn_num[i].type;
        mmi_asc_to_ucs2((CHAR*)srv_contact.field_data.opt_num[i]->number, (CHAR*)udx_vcard->dyn_num[i].number);
    }
    
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.pobox, (CHAR *) udx_vcard->adr_mailbox);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.extension, (CHAR *) udx_vcard->adr_detail);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.street, (CHAR *) udx_vcard->adr_street);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.city, (CHAR *) udx_vcard->adr_city);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.state, (CHAR *) udx_vcard->adr_province);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.country, (CHAR *) udx_vcard->adr_country);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.postalcode, (CHAR *) udx_vcard->adr_postcode);
    
    mmi_asc_to_ucs2((CHAR *) srv_contact.field_data.url, (CHAR *) udx_vcard->url);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.company_name, (CHAR *) udx_vcard->org_name);
    mmi_ucs2cpy((CHAR *) srv_contact.field_data.title, (CHAR *) udx_vcard->title);
    
    mmi_asc_to_ucs2((CHAR *) srv_contact.field_data.email_address, (CHAR *) udx_vcard->email);
    mmi_asc_to_ucs2((CHAR *) srv_contact.field_data.email_address2, (CHAR *) udx_vcard->email_home);

    if (*udx_vcard->bday != 0)
    {
        mmi_udx_birthday_retrieve(
            (CHAR*)udx_vcard->bday,
            &(srv_contact.field_data.b_year),
            &(srv_contact.field_data.b_month),
            &(srv_contact.field_data.b_day));
    }
    
    /* added by Li Ding */
    srv_phb_remove_invalid_number(srv_contact.field_data.number); 
    if (!srv_phb_check_valid_number_ex(srv_contact.field_data.number, MMI_FALSE))
    {
        srv_contact.field_data.number[0] = 0;
        num_valid = MMI_FALSE;
    }
    
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        srv_phb_remove_invalid_number(srv_contact.field_data.opt_num[i]->number);
        if (!srv_phb_check_valid_number_ex(srv_contact.field_data.opt_num[i]->number, MMI_FALSE))
        {
            srv_contact.field_data.opt_num[i]->number[0] = 0;
            num_valid = MMI_FALSE;
        }
    }

    /* If any one number is invalid, the whole contact item should be discarded */
    if (!num_valid)
    {
        srv_contact.field_data.name[0] = 0;
        srv_contact.field_data.l_name[0] = 0;
            
        /* free phb buffer in mmi_udx_store_phb_data_cb */
        srv_phb_oplib_add_contact(
            select_storage,
            SRV_PHB_INVALID_INDEX,
            &srv_contact,
            mmi_udx_store_phb_data_cb,
            NULL);
        
        mmi_udx_free_phb_buffer(&srv_contact);
        
        return;
    }
    
    srv_phb_remove_invalid_name(srv_contact.field_data.name);
    srv_phb_remove_invalid_name(srv_contact.field_data.l_name);
    
    if (!applib_is_valid_email_address_unicode(srv_contact.field_data.email_address))
    {
        srv_contact.field_data.email_address[0] = 0;
    }
    if (!applib_is_valid_email_address_unicode(srv_contact.field_data.email_address2))
    {
        srv_contact.field_data.email_address2[0] = 0;
    }

    if (!srv_phb_check_valid_url(srv_contact.field_data.url))
    {
        srv_contact.field_data.url[0] = 0;
    }
    /* end */
    
    /* free phb buffer in mmi_udx_store_phb_data_cb */
    srv_phb_oplib_add_contact(
        select_storage,
        SRV_PHB_INVALID_INDEX,
        &srv_contact,
        mmi_udx_store_phb_data_cb,
        NULL);
    
    mmi_udx_free_phb_buffer(&srv_contact);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_store_phb_data_cb
 * DESCRIPTION
 *  store phb data callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_store_phb_data_cb(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL store_result = (result >= 0) ? MMI_TRUE : MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_udx_store_data_continue(MMI_FALSE, store_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_malloc_phb_buffer
 * DESCRIPTION
 *  malloc buffer for fetching phb data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_malloc_phb_buffer(srv_phb_contact_info_struct *srv_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 size = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_entry, 0, sizeof(srv_phb_contact_info_struct));
    
    /* split contact infr to 4 block to get buffer respectively */    
	/* size == 164 */
    size += (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH * 2;
    size += (MMI_PHB_NUMBER_PLUS_LENGTH + 1) * ENCODING_LENGTH;
    size += sizeof(mmi_phb_wcs_num_struct) * 3;
    srv_entry->field_data.name = (U16*)OslMalloc(size);
    memset(srv_entry->field_data.name, 0, size);
    srv_entry->field_data.l_name = srv_entry->field_data.name + (MMI_PHB_NAME_FIELD_LENGTH + 1);
    srv_entry->field_data.number = srv_entry->field_data.l_name + (MMI_PHB_NAME_FIELD_LENGTH + 1);
    srv_entry->field_data.opt_num[0] = (mmi_phb_wcs_num_struct*)(srv_entry->field_data.number + (MMI_PHB_NUMBER_PLUS_LENGTH + 1));
    srv_entry->field_data.opt_num[1] = (mmi_phb_wcs_num_struct*)(srv_entry->field_data.opt_num[0] + 1);
    srv_entry->field_data.opt_num[2] = (mmi_phb_wcs_num_struct*)(srv_entry->field_data.opt_num[1] + 1);

    /* size == 364 */
    size = 0;
    size += (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH * 7;
    srv_entry->field_data.pobox = (U16*)OslMalloc(size);
    memset(srv_entry->field_data.pobox, 0, size);
    srv_entry->field_data.extension= srv_entry->field_data.pobox + (MMI_PHB_ADDRESS_LENGTH + 1); 
    srv_entry->field_data.street = srv_entry->field_data.extension + (MMI_PHB_ADDRESS_LENGTH + 1); 
    srv_entry->field_data.city = srv_entry->field_data.street + (MMI_PHB_ADDRESS_LENGTH + 1); 
    srv_entry->field_data.state = srv_entry->field_data.city + (MMI_PHB_ADDRESS_LENGTH + 1); 
    srv_entry->field_data.postalcode = srv_entry->field_data.state + (MMI_PHB_ADDRESS_LENGTH + 1); 
    srv_entry->field_data.country = srv_entry->field_data.postalcode + (MMI_PHB_ADDRESS_LENGTH + 1); 

	/* size == 171 */
    size = 0;
    size += (MMI_PHB_URL_LENGTH + 1) * ENCODING_LENGTH;
    size += (MMI_PHB_COMPANY_LENGTH + 1) * ENCODING_LENGTH;
    size += (MMI_PHB_TITLE_LENGTH + 1) * ENCODING_LENGTH;
    srv_entry->field_data.url = (U16*)OslMalloc(size);
    memset(srv_entry->field_data.url, 0, size);
    srv_entry->field_data.company_name = srv_entry->field_data.url + (MMI_PHB_URL_LENGTH + 1); 
    srv_entry->field_data.title = srv_entry->field_data.company_name + (MMI_PHB_COMPANY_LENGTH + 1); 

	/* 244 */
    size = 0;
    size += (MMI_PHB_EMAIL_LENGTH + 1) * ENCODING_LENGTH * 2; 
    srv_entry->field_data.email_address = (U16*)OslMalloc(size);
    memset(srv_entry->field_data.email_address, 0, size);
    srv_entry->field_data.email_address2 = srv_entry->field_data.email_address + (MMI_PHB_EMAIL_LENGTH + 1); 

    /* set field mask */
    srv_entry->field_mask = SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_ENTRY_FIELD_OPTIONAL | SRV_PHB_ENTRY_FIELD_ADDRESS |
                            SRV_PHB_ENTRY_FIELD_TITLE | SRV_PHB_ENTRY_FIELD_URL | SRV_PHB_ENTRY_FIELD_BDAY;
                            
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_free_phb_buffer
 * DESCRIPTION
 *  free buffer for fetching phb data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_free_phb_buffer(srv_phb_contact_info_struct *srv_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_entry->field_data.name != NULL)
    {
        OslMfree(srv_entry->field_data.name);
    }   
    
    if (srv_entry->field_data.pobox != NULL)
    {
        OslMfree(srv_entry->field_data.pobox);
    }

    if (srv_entry->field_data.url != NULL)
    {
        OslMfree(srv_entry->field_data.url);
    }

    if (srv_entry->field_data.email_address != NULL)
    {
        OslMfree(srv_entry->field_data.email_address);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_birthday_to_asc_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Store index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_udx_birthday_to_asc_string(CHAR* bday, U16 b_year, U8 b_mon, U8 b_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (b_year < MMI_PHB_BDAY_MIN_YEAR_INT || b_year > MMI_PHB_BDAY_MAX_YEAR_INT)
    {
		bday[0] = 0; 
        return;
    }
	if (b_mon < 1 || b_mon > 12)
	{
		bday[0] = 0; 
        return;
	}
    if (b_day < 1 || b_day > 31)
    {
        bday[0] = 0;
		return;
    }

	sprintf(bday, "%4d%02d%02d", b_year, b_mon, b_day);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_birthday_retrieve
 * DESCRIPTION
 *  trasport string to digit
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Store index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static MMI_BOOL mmi_udx_birthday_retrieve(CHAR* bday, U16* y, U8* m, U8* d)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	CHAR *cursor;
    CHAR ascii_buff[5];
    applib_time_struct t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = bday;
    if (cursor && cursor[0])
    {
        /* Year */
        strncpy(ascii_buff, cursor, 4);
        ascii_buff[4] = '\0';
        t.nYear = (U16)atoi(ascii_buff);
        cursor += 4;
        /* Month */
        if (*cursor == '-' || *cursor == '/')
        {
            cursor++;
        }
        strncpy(ascii_buff, cursor, 2);
        ascii_buff[2] = '\0';
        t.nMonth = (U8)atoi(ascii_buff);
        cursor += 2;
        /* Day */
        if (*cursor == '-' || *cursor == '/')
        {
            cursor++;
        }    
        strncpy(ascii_buff, cursor, 2);
        ascii_buff[2] = '\0';
        t.nDay = (U8)atoi(ascii_buff);
        
        t.nHour = 0;
        t.nMin = 0;
        t.nSec = 0;
        t.DayIndex = 0;
        if (applib_dt_check_valid_by_app(MMI_PHB_BDAY_MIN_YEAR_INT, MMI_PHB_BDAY_MAX_YEAR_INT, &t))
        {
            *y = t.nYear;
            *m = t.nMonth;
            *d = t.nDay;
			return MMI_TRUE;
        }
        else
        {
            *y = 0;
            *m = 0;
            *d = 0;
			return MMI_FALSE;
        }
    }
	else
	{
		*y = 0;
		*m = 0;
		*d = 0;
		return MMI_FALSE;
	}
}
#endif /* __MMI_UDX_VCARD_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_init_cntx
 * DESCRIPTION
 *  udx cntx init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_enter_phb_select_record(void)
{
#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_udx_cntx.phb_list_gid = cui_phb_list_multi_select_contact_create(GRP_ID_UDX_MAIN);
    
    cui_phb_list_select_contact_set_field_filter(g_mmi_udx_cntx.phb_list_gid, SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER);
 
    cui_phb_list_multi_select_contact_run(g_mmi_udx_cntx.phb_list_gid);    
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_contact_select_cui_evt_hdlr
 * DESCRIPTION
 *  udx proc function about selecting contact
 * PARAMETERS
 *  mmi_event_struct *evt         [IN]    event     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_contact_select_cui_evt_hdlr(mmi_event_struct *param)
{
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_multi_select_contact_result_struct *evt = (cui_phb_multi_select_contact_result_struct *) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SELECT_MULTI_CONTACT:
        {
            if (evt->count == 0 || evt->store_index == NULL)
            {
                /* will go back multi_select_contact_screen */
                mmi_popup_display_simple(
                    (WCHAR*)get_string(STR_ID_UDX_NO_DATA_TYPE_SELECTED), 
                    MMI_EVENT_WARNING, 
                    GRP_ID_ROOT, 
                    NULL);
                
                if (evt->store_index == NULL)
                {
                    MMI_ASSERT(evt->count == 0);
                    /* If do not select only data record, disable the data type */
                    g_mmi_udx_cntx.udx_agent.type_selected &= ~udx_support_type_tbl[g_mmi_udx_cntx.udx_agent.type_index];
                }
            }
            else
            {
                mmi_udx_builder_get_app_data_index_hdlr(evt->store_index, evt->count);
                /* close the group when udx build finish */
            }
            break;
        }
        case EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL:
        {
            cui_phb_list_multi_select_contact_close(evt->sender_id);
            break;
        }
    }
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_app_list_cui_close
 * DESCRIPTION
 *  close phb select list cui to free phb buffer. note: because udx use the phb buffer,
 *  we should keep phb cui active until udx do not need this buffer;
 *  two condition will enter here: 1-build end rsp 2-build abort rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_app_list_cui_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_BUILDER)
    {
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
        cui_phb_list_multi_select_contact_close(g_mmi_udx_cntx.phb_list_gid);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_udx_app_data_change_notification
 * DESCRIPTION
 *  phb update event callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_udx_app_data_change_notification(mmi_event_struct* param)
{
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
      return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_handle_app_processing
 * DESCRIPTION
 *  set other app to processing or reset
 * PARAMETERS
 *  type           [IN]
 *  set            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_handle_app_processing(U8 type, MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set)
    {
        switch (type)
        {
        #ifdef __MMI_UDX_VCARD_SUPPORT__
            case UDX_TYPE_VCARD:
                mmi_phb_udx_set_processing();
                g_mmi_udx_cntx.phb_is_processing = MMI_TRUE;
                break;
        #endif
        
            case UDX_TYPE_VCALENDAR:                    
                 break;
                
            case UDX_TYPE_SMS:                    
                 break;
                
            case UDX_TYPE_MMS:                    
                 break;
                
            case UDX_TYPE_EMAIL:                
                 break;
            default:
                break;
        }
    }
    else
    {
        switch (type)
        {
        #ifdef __MMI_UDX_VCARD_SUPPORT__
            case UDX_TYPE_VCARD:
                mmi_phb_udx_reset_processing();
                g_mmi_udx_cntx.phb_is_processing = MMI_FALSE;
                break;
        #endif
        
            case UDX_TYPE_VCALENDAR:                    
                 break;
                
            case UDX_TYPE_SMS:                    
                 break;
                
            case UDX_TYPE_MMS:                    
                 break;
                
            case UDX_TYPE_EMAIL:                
                 break;
            default:
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_get_user_info
 * DESCRIPTION
 *  get the data user info
 * PARAMETERS
 *  user_info           [out]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_get_user_info(CHAR *user_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    mmi_phb_my_number_struct myCard;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, (void*)&myCard, sizeof(mmi_phb_my_number_struct), &pError);

    srv_phb_convert_to_name(
        (U16*) user_info,
        myCard.name,    
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
        myCard.l_name,
#else
        NULL,
#endif
        MMI_PHB_NAME_LENGTH);

    if (!mmi_ucs2strlen((const CHAR *) user_info))
    {
        /* get default user info */
        mmi_ucs2ncpy(user_info, (const CHAR *) UDX_CUSTOM_USER_INFO, MMI_PHB_NAME_LENGTH);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_get_app_data_index_hdlr
 * DESCRIPTION
 *  get the data handler and data count, after each data select done
 * PARAMETERS
 *  index_hdlr          [IN]        data index array
 *  num_count           [IN]        data count
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_get_app_data_index_hdlr(void* index_hdlr, U16 num_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG1(MMI_UDX_GET_DATA_HDLR, num_count);
    
    switch (udx_support_type_tbl[g_mmi_udx_cntx.udx_agent.type_index])
    {    
        case UDX_TYPE_VCARD:
        {
            g_mmi_udx_cntx.udx_agent.vcard_index_hdlr = index_hdlr;
            g_mmi_udx_cntx.udx_agent.vcard_num = num_count;
            break;
        }    
        case UDX_TYPE_VCALENDAR:
            g_mmi_udx_cntx.udx_agent.vcalendar_index_hdlr = index_hdlr;
            g_mmi_udx_cntx.udx_agent.vcalendar_num = num_count;
            break;
            
        case UDX_TYPE_SMS:
            g_mmi_udx_cntx.udx_agent.sms_index_hdlr = index_hdlr;
            g_mmi_udx_cntx.udx_agent.sms_num = num_count;
            break;
            
        case UDX_TYPE_MMS:
            g_mmi_udx_cntx.udx_agent.mms_index_hdlr = index_hdlr;
            g_mmi_udx_cntx.udx_agent.mms_num = num_count;
            break;
            
        case UDX_TYPE_EMAIL:
            g_mmi_udx_cntx.udx_agent.email_index_hdlr = index_hdlr;
            g_mmi_udx_cntx.udx_agent.email_num = num_count;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }

    //g_mmi_udx_cntx.udx_agent.type_index++;
      
    mmi_udx_builder_select_data_record();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_udx_store_data_continue
 * DESCRIPTION
 *  after save the data to app, call it to continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_store_data_continue(MMI_BOOL storage_full, MMI_BOOL store_success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG3(MMI_UDX_STORE_DATA_CONTINUE, storage_full, store_success, g_mmi_udx_cntx.udx_agent.sequence);

    /* as long as data was stored, the log should be increased */
    g_mmi_udx_cntx.udx_agent.parse_log[mmi_udx_get_data_type_index(g_mmi_udx_cntx.udx_agent.type_curr)].storage_full = storage_full;
    
    g_mmi_udx_cntx.udx_agent.parse_log[mmi_udx_get_data_type_index(g_mmi_udx_cntx.udx_agent.type_curr)].parse_success_count++;
    
    if (store_success)
    {
        g_mmi_udx_cntx.udx_agent.parse_log[mmi_udx_get_data_type_index(g_mmi_udx_cntx.udx_agent.type_curr)].store_success_count++;
    }

    if (g_mmi_udx_cntx.udx_agent.state == MMI_UDX_PARSER_BODY_REQ)
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_BODY_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_send_msg
 * DESCRIPTION
 *  UDX agent send message function
 * PARAMETERS
 *  msg_id          [IN]        message id
 *  p_local_para    [IN]        local_para_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_UDX;
    ilm_send->sap_id = MMI_UDX_SAP;
    ilm_send->msg_id = (kal_uint16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_get_data_use_way
 * DESCRIPTION
 *  get the data use way
 * PARAMETERS
 *  void
 * RETURNS
 *  U8                              data use way
 *****************************************************************************/
U8 mmi_udx_get_data_use_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 use_way;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_UDX_DATA_USE_WAY, &use_way, DS_BYTE, &pError);

    MMI_UDX_LOG1(MMI_UDX_CONFLICT_SOLUTION, use_way);

    return use_way;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_get_data_type_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_type
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_udx_get_data_type_index(U8 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_UDX_TYPE_TOTAL; index++)
    {
        if (data_type == udx_support_type_tbl[index])
        {
            return index;
        }
    }

    return 0x00;
}


#define MMI_UDX_EXTERNAL_API
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_init
 * DESCRIPTION
 *  init function, call by MMI_TASK when bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG(MMI_UDX_AGENT_INIT);
    
    mmi_udx_ini_data_change_register();

    /* udx protocol hdlr init*/ 
    mmi_udx_init_protocol();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_building_launch
 * DESCRIPTION
 *  build UDX file from other app
 * PARAMETERS
 *  index_hdlr          [IN]        data index arrary
 *  count               [IN]        data counts
 *  data_type           [IN]        data type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_building_launch(mmi_id caller_id, void* index_hdlr, U16 count, U8 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG2(MMI_UDX_BUILD_FILE, count, data_type);
    
    if (count == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_UDX_NO_DATA_TYPE_SELECTED), 
            MMI_EVENT_WARNING, 
            GRP_ID_ROOT, 
            NULL);

        return;
    }

    MMI_ASSERT(index_hdlr != NULL);
    
    mmi_udx_init_cntx();
        
    switch(data_type)
    {
        case UDX_TYPE_VCARD:
            g_mmi_udx_cntx.udx_agent.type_curr = UDX_TYPE_VCARD;
            g_mmi_udx_cntx.udx_agent.type_selected = UDX_TYPE_VCARD;
            g_mmi_udx_cntx.udx_agent.vcard_num = count;
            g_mmi_udx_cntx.udx_agent.vcard_index_hdlr = index_hdlr;
            break;
            
        case UDX_TYPE_VCALENDAR:
            g_mmi_udx_cntx.udx_agent.type_curr = UDX_TYPE_VCALENDAR;
            g_mmi_udx_cntx.udx_agent.type_selected = UDX_TYPE_VCALENDAR;
            g_mmi_udx_cntx.udx_agent.vcalendar_num = count;
            g_mmi_udx_cntx.udx_agent.vcalendar_index_hdlr = index_hdlr;
            break;
            
        case UDX_TYPE_SMS:
            g_mmi_udx_cntx.udx_agent.type_curr = UDX_TYPE_SMS;
            g_mmi_udx_cntx.udx_agent.type_selected = UDX_TYPE_SMS;
            g_mmi_udx_cntx.udx_agent.sms_num = count;
            g_mmi_udx_cntx.udx_agent.sms_index_hdlr = index_hdlr;
            break;
            
        case UDX_TYPE_EMAIL:
            g_mmi_udx_cntx.udx_agent.type_curr = UDX_TYPE_EMAIL;
            g_mmi_udx_cntx.udx_agent.type_selected = UDX_TYPE_EMAIL;
            g_mmi_udx_cntx.udx_agent.email_num = count;
            g_mmi_udx_cntx.udx_agent.email_index_hdlr = index_hdlr;
            break;
            
        case UDX_TYPE_MMS:
            g_mmi_udx_cntx.udx_agent.type_curr = UDX_TYPE_MMS;
            g_mmi_udx_cntx.udx_agent.type_selected = UDX_TYPE_MMS;
            g_mmi_udx_cntx.udx_agent.mms_num = count;
            g_mmi_udx_cntx.udx_agent.mms_index_hdlr = index_hdlr;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    g_mmi_udx_cntx.start_from = MMI_UDX_BUILD_FROM_OTHER_APP;
    MMI_UDX_LOG1(MMI_UDX_AGENT_START_FROM_SCR, g_mmi_udx_cntx.start_from);

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UDX_MAIN, mmi_udx_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_UDX_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_set_caller(GRP_ID_UDX_MAIN, caller_id);
    
    mmi_udx_builder_entry_fmgr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parse_file_from_fmgr
 * DESCRIPTION
 *  UDX Agent is busy or not
 * PARAMETERS
 *  pop_up          [IN]        if need to show popup by UDX agent
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_udx_parsing_launch(mmi_id caller_id, CHAR *path)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path != NULL);
    
    if (mmi_udx_is_busy(MMI_TRUE))
    {
        return;
    }
    
    mmi_udx_init_cntx();
    
    g_mmi_udx_cntx.start_from = MMI_UDX_PARSE_FROM_FILEMGR;
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UDX_MAIN, mmi_udx_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_UDX_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_group_set_caller(GRP_ID_UDX_MAIN, caller_id);
    
    mmi_ucs2cpy(g_mmi_udx_cntx.file_path, path);
    
    mmi_udx_parser_entry_parse_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_is_busy
 * DESCRIPTION
 *  UDX Agent is busy or not
 * PARAMETERS
 *  pop_up          [IN]        if need to show popup by UDX agent
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_udx_is_busy(MMI_BOOL pop_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG1(MMI_UDX_AGENT_STATE_IS, g_mmi_udx_cntx.udx_agent.state);
    
    if (g_mmi_udx_cntx.udx_agent.state != MMI_UDX_AGENT_STATE_INIT)
    {
        if (pop_up)
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_UDX_BUSY), 
                MMI_EVENT_WARNING, 
                GRP_ID_ROOT, 
                NULL);
        }
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_is_reentry
 * DESCRIPTION
 *  UDX Agent is not allow reentry
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_udx_is_reentry(MMI_BOOL popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_UDX_MAIN))
    {
        if (popup)
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_UDX_BUSY), 
                MMI_EVENT_WARNING, 
                GRP_ID_ROOT, 
                NULL);
        }
    
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_phb_is_processing
 * DESCRIPTION
 * 
 * PARAMETERS
 *  MMI_BOOL  is_popup  whether need popup or not
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_udx_phb_is_processing(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.phb_is_processing)
    {
        if (is_popup)
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_UDX_IS_PROCESSING), 
                MMI_EVENT_WARNING, 
                GRP_ID_ROOT, 
                NULL);
        }
    }
    
    return g_mmi_udx_cntx.phb_is_processing;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_delete_fmgr_service_screen
 * DESCRIPTION
 *  when buid from app and stay on fmgr group, phb database is changed by phonesuit, 
 *  so we should close UDX group and go back phb;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_delete_fmgr_service_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_OTHER_APP)
    {
        mmi_frm_group_close(GRP_ID_UDX_MAIN);   
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_driver_plug_out_event_hdlr
 * DESCRIPTION
 *  when driver is plug out, will handle it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_udx_driver_plug_out_event_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct *evt 
            = (srv_fmgr_notification_dev_plug_event_struct*)param;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_UDX_MAIN))
    {
        return MMI_RET_OK;
    }
    
    if (g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_OTHER_APP
        || g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_BUILDER)
    {
        for (i = 0; i < evt->count; i++)
        {
            if (evt->drv_letters[i] == g_mmi_udx_cntx.file_path[0])
            {
                cui_filename_editor_close(g_mmi_udx_cntx.filename_gid);
            }
        }
    }
    else if (g_mmi_udx_cntx.start_from == MMI_UDX_PARSE_FROM_FILEMGR
                || g_mmi_udx_cntx.start_from == MMI_UDX_PARSE_FROM_PARSER)
    {
        for (i = 0; i < evt->count; i++)
        {
            if (evt->drv_letters[i] == g_mmi_udx_cntx.file_path[0])
            {
                mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_DATA_TYPE_SELECT);
            }
        }
    }
    else
    {
        
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_fmgr_highlight_to_udx
 * DESCRIPTION
 *  highlight udx in filemgr option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_fmgr_to_udx_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_id != MENU_ID_UDX_FMGR_FWD_UDX)
    {
        return;
    }
    
    mmi_udx_parsing_launch(GRP_ID_ROOT, (CHAR*)filepath);
}


#endif /* __MMI_UDX_SUPPORT__ */
