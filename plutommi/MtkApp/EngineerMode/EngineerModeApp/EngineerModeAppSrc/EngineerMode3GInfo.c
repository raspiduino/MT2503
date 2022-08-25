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
 * EngineerMode3GInfo.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for TDD/FDD.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_EM_NW_FDD_NETWORK_INFO__


#include "MMI_include.h"

#if defined(__MMI_ENGINEER_MODE__) && defined(__MODEM_EM_MODE__)

#include "MMIDataType.h"
    #include "custom_em.h"
    #include "EngineerModeResDef.h"
    #include "kal_general_types.h"
    #include "em_struct.h"
    #include "em_public_struct.h"
    #include "ps_public_struct.h"
    #include "l4c_common_enum.h"
    #include "gui_data_types.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "mmi_frm_history_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalMenuItems.h"
    #include "CustMenuRes.h"
    #include "wgui_categories_list.h"
    #include "GlobalResDef.h"
    #include "stack_msgs.h"
    #include "mmi_msg_struct.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "wgui_inline_edit.h"
    #include "CustDataRes.h"
    #include "ImeGprot.h"
    #include "stdio.h"
    #include "Unicodexdcl.h"
    #include "stdlib.h"
    #include "string.h"
    #include "stack_config.h"
    #include "wgui_categories.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_rp_app_idle_def.h"
    #include "IdleAppResDef.h"
    #include "wgui_categories_text_viewer.h"
    #include "mmi_frm_input_gprot.h"
#ifdef __MMI_TOUCH_SCREEN__
    #include "wgui_touch_screen.h"
#endif
    #include "gui_switch.h"
    #include "wgui.h"
    #include "gui.h"
    #include "gdi_include.h"
    #include "FontRes.h"
    #include "gui_themes.h"
    #include "gui_typedef.h"
    #include "wgui_include.h"

    #include "EngineerModeAppResDef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "stack_common.h"

    #include "wgui_categories_popup.h"

#include "ProtocolEvents.h"
#include "PixcomFontEngine.h"   

#include "SimCtrlSrvGprot.h"

#include "CommonScreens.h"


#ifdef __COSMOS_MMI_PACKAGE__

#include "Vapp_home_gprot.h"

#endif

#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "mmi_rp_app_engineermode1_def.h"

#include "UcmSrvGprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_EM_MOD_3G_INFO_SELECTED_ITEMS     (14)
  
#define MMI_EM_3G_INFO_CHK_MODE(_mode, _record)     ((_mode) & (_record))? (1) : (0)
#define MMI_EM_3G_INFO_SET_ON(_mode, _record)       _record = (_mode) | (_record)     /* checkbox ON == 00 */
#define MMI_EM_3G_INFO_SET_OFF(_mode, _record)      _record = ~(_mode) & (_record)    /* checkbox OFF == 01 */

#define MAX_EM_MODE (sizeof(em_3g_info_item_table)/sizeof(U8))
#define MAX_TRACER_SCREEN_NUM         (16)       
#define MAX_TRACER_LINE_NUM           (30)
#define SIM_MODE_1                    (1)
#define SIM_MODE_2                    (2)


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
 //   mmi_chset_convert


/***************************************************************************** 
 * Enum
 *****************************************************************************/
typedef struct
{
    kal_uint8 g_index_screen;
    kal_uint8 mmi_screen_text[MAX_TRACER_LINE_NUM][50];
    kal_uint8 num_of_carriers;

    kal_uint8 g_index_screen_show[MAX_TRACER_SCREEN_NUM];     /* if =1 show this scrn,else don't show*/

    mm_em_info_struct mmi_em_info;
    urr_umts_srnc_id_struct  mmi_urr_umts_srnc_id_info;
    
    meme_em_info_umts_cell_status_struct  mmi_meme_em_info_umts_cell_status_info;
    csce_em_serv_cell_s_status_ind_struct mmi_csce_em_serv_cell_s_status_ind_info;
    meme_em_info_h_serving_cell_ind_struct  mmi_meme_em_info_h_serving_cell_ind_info;
    meme_em_periodic_bler_report_ind  mmi_meme_em_periodic_bler_report_ind_info;
    slce_em_ps_data_rate_status_ind_struct  mmi_slce_em_ps_data_rate_status_ind_info;
    tcm_mmi_em_info_struct mmi_tcm_mmi_em_info;
    csce_em_info_multiple_plmn_struct  mmi_csce_em_info_multiple_plmn_info;
    
} mmi_em_3g_info_struct;

//mmi_chset_convert

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_em_3g_info_struct *g_mmi_em_3g_info;
static U8 em_3g_info_entry = 0;
U16 g_mmi_em_3g_info_cur_mode = 0;
kal_uint8 gIsOnEMTracer_3g = 0;
typedef struct {
    U16     string_id;
    U8      event_index;        
} em_3g_info_item_struct;

static const U8 em_3g_info_item_table [] = 
{
    MM_EM_INFO,
    URR_EM_INFO_UMTS_SRNC_ID_INFO,
    MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO,
    CSCE_EM_SERV_CELL_IND_STRUCT_INFO,
    MEME_EM_INFO_H_SERVING_CELL_INFO,
    MEME_EM_3G_BLER_IND_STRUCT_INFO,
    SLCE_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO,
    TCM_EM_CONTEXT_INFO,
    CSCE_EM_INFO_MULTIPLE_PLMN_STRUCT_INFO
};

typedef struct {
    U8 menu_list_item;
    U8 num_relevant;
    U8 index_1;    /*menu list item*/
    S32 index_2;
}mmi_em_menu_em_info_map_struct;

/*************************************************************

 It is a mapping table for EM 3G_info menu id and relevent structure,
 menu_list_item:
 Item1----Selected PLMN
 Item2----Access Class
 Item3----SRNC ID
 Item4----Serving Cell PLMN
 Item5----Serving Cell
 Item6----Active Cell
 Item7----Intra-freq monitored cell(1)
 Item8----Intra-freq monitored cell(2)
 Item9----deteced cell
 Item10----H-Serving Cell
 Item11----PDP Data Speed
 Item12----PS Service Infro
 Item13----Block Error Rate
 Item14----UE Transmission
 num_relevant:
 list_of_states[0]<-->mm_em_info_struct
 list_of_states[1]<-->urr_umts_srnc_id_struct
 list_of_states[2]<-->meme_em_info_umts_cell_status_struct
 list_of_states[3]<-->csce_em_serv_cell_s_status_ind_struct
 list_of_states[4]<-->meme_em_info_h_serving_cell_ind_struct
 list_of_states[5]<-->meme_em_periodic_bler_report_ind
 list_of_states[6]<-->slce_em_ps_data_rate_status_ind_struct
 list_of_states[7]<-->tcm_mmi_em_info_struct
 list_of_states[8]<-->csce_em_info_multiple_plmn_struct
 
********************************************************************/

static const mmi_em_menu_em_info_map_struct mmi_em_menu_em_info_map_tab [] =
{
    {1,     1,      0,      -1},
    {2,     1,      0,      -1},
    {3,     1,      1,      -1},
    {4,     1,      8,      -1},
    {5,     1,      3,      -1},
    {6,     1,      2,      -1},
    {7,     2,      2,       3},
    {8,     2,      2,       3},
    {9,     1,      2,      -1},
    {10,    1,      4,      -1},
    {11,    1,      7,      -1},
    {12,    1,      6,      -1},
    {13,    1,      5,      -1},
    {14,    1,      2,      -1}
};

typedef enum
{
    EM_3G_INFO_MODE,
    EM_TDD_MODE
}em_mode_enum;

static kal_uint8 g_index_screen = 0;

static char *romaNum[]={"0","I","II","III","IV","V","VI","VII","VIII","IX",
    "X","XI","XII","XIII","XIV","XV",
    "XVI","XVII","XVIII","XIX","XX","XXI",
    "XXII","XXIII","XXIV","XXV","XXVI","XXVII",
    "XXVIII","XXIX","XXX","XXXI","XXXII"};

U8 g_sim_mode = SIM_MODE_1;

U8  g_em_3g_comm_info = (0XF0);

U8 g_3g_popup_gourp_id;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static MMI_BOOL mmi_em_3g_info_mem_stop_hdlr(void);
static void mmi_em_3g_info_release_context(void);
static void mmi_em_3g_info_display_screen_n(kal_uint8 screen_num);

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
MMI_ID g_gourp_id;
U16 g_mmi_em_3g_info_mode_status = 0;
U16 g_mmi_em_3g_info_mode_status_history = 0;
em_mode_enum g_em_mode;



 /***************************************************************************** 
 * Extern Function
 *****************************************************************************/
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);
//extern U8 mmi_frm_entry_new_screen(U16 new_scrn_id, exit_func_ptr new_exit_handler, entry_func_ptr new_entry_handler, void *flag);



 /*****************************************************************************
 * FUNCTION
 *  mmi_em_audio_debug_info_init
 * DESCRIPTION
 *  set debug info at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_em_3g_info_list_pre_hdlr(MMI_ID owner_gid)
 {
     U32 i;
     U16 mode = 0x01;
     U8 list_of_states[MAX_EM_MOD_3G_INFO_SELECTED_ITEMS] = {0};
 
     
     for (i = 0;i < MAX_EM_MOD_3G_INFO_SELECTED_ITEMS; i++)
     {
         if (MMI_EM_3G_INFO_CHK_MODE(mode, g_mmi_em_3g_info_mode_status))
         {
             list_of_states[i] = 1;
         }
         else
         {
             list_of_states[i] = 0;
         }
         mode = mode * 2;
     }
     cui_menu_set_checkbox_state(owner_gid, list_of_states);
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_stop_3g_info_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE Message;
    mmi_em_update_req_struct *em_start_req;
    U8 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

    for (i=0;i<EM_INFO_REQ_NUM;i++)
	{
        em_start_req->info_request[i] = EM_OFF;
    }

    //Message.oslDataPtr = (oslParaType*) em_start_req;
    //Message.oslPeerBuffPtr = NULL;
    //Message.oslSrcId = MOD_MMI;
    if(g_sim_mode == SIM_MODE_1)
        //Message.oslDestId = MOD_L4C;
        mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);
    
#if (MMI_MAX_SIM_NUM >= 2)
    else if(g_sim_mode == SIM_MODE_2)
        //Message.oslDestId = MOD_L4C_2;
        mmi_frm_send_ilm(MOD_L4C_2,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);
 #endif
    //OslMsgSendExtQueue(&Message);

}


static MMI_BOOL mmi_em_3g_info_mem_stop_hdlr(void)
{
     mmi_em_stop_3g_info_req();
     mmi_em_3g_info_release_context();
     return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_3g_info_release_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_3g_info)
	{
        MMI_EM_FREE(g_mmi_em_3g_info);
        g_mmi_em_3g_info = NULL;
        MMI_EM_UNREG_STOP_FUNC(mmi_em_3g_info_mem_stop_hdlr);
        mmi_em_comm_mem_stop_hold();
	}
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_3g_info_init_context(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_mmi_em_3g_info == NULL)
     {
          MMI_EM_REG_STOP_FUNC(mmi_em_3g_info_mem_stop_hdlr);
          mmi_em_comm_mem_hold();
        g_mmi_em_3g_info = MMI_EM_MALLOC(sizeof(mmi_em_3g_info_struct));
     }
         
     if (g_mmi_em_3g_info)
     {
         memset(g_mmi_em_3g_info, 0, sizeof(mmi_em_3g_info_struct));   //set 0
     }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_3g_info_init_mem(void)
{
     S32 i;
     U16 mode = 0x01;
     MMI_BOOL is_on = MMI_FALSE;

     for (i = 0; i < MAX_EM_MOD_3G_INFO_SELECTED_ITEMS; i++)
     {
         if (MMI_EM_3G_INFO_CHK_MODE(mode, g_mmi_em_3g_info_mode_status))
         {
             is_on = MMI_TRUE;
             break;
         }
         mode = mode * 2;
     }

     if (is_on)
     {
         mmi_em_3g_info_init_context();     //some item have been selected
     }
     else
     {
         mmi_em_3g_info_release_context();  //no item be selected
     }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_display_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 page_count = 0;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_em_3g_info)
    {
     return;
    }
    memset(g_mmi_em_3g_info->mmi_screen_text, 0, sizeof(g_mmi_em_3g_info->mmi_screen_text));

    g_index_screen = 0;
    for(i=0 ; i<MAX_TRACER_SCREEN_NUM; i++)
    {
        if(g_mmi_em_3g_info->g_index_screen_show[i] == 1)    // set initial screen index
            break;
    }
    g_index_screen = i;

    MMI_ASSERT(page_count <= MAX_TRACER_SCREEN_NUM);

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
#endif

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_start_rsp(void *inMsg)
{
#if defined(__MODEM_EM_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_update_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND1,6);
    if (rsp_p->result)
    {
        //EngineerModeStatusUpdate_3g(0, 0);
        //EngineerModeSuccessNotice(NULL);
        mmi_em_success_popup();
    }
    else
    {
        //EngineerModeErrorNotice(NULL);
        mmi_em_fail_popup();
    }

#endif 
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_get_mm_em_info_value(mm_em_info_struct *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
        U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    for (i = 0; i < 3; i++)
    {
        g_mmi_em_3g_info->mmi_em_info.mcc[i] = data_ptr->mcc[i];
        g_mmi_em_3g_info->mmi_em_info.mnc[i] = data_ptr->mnc[i];
    }
    g_mmi_em_3g_info->mmi_em_info.common_access_class = data_ptr->common_access_class;
    g_mmi_em_3g_info->mmi_em_info.cs_access_class = data_ptr->cs_access_class;
    g_mmi_em_3g_info->mmi_em_info.ps_access_class = data_ptr->ps_access_class;
    
     
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
 static void mmi_em_get_urr_umts_srnc_id_value(urr_umts_srnc_id_struct *data_ptr)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    g_mmi_em_3g_info->mmi_urr_umts_srnc_id_info.srnc = data_ptr->srnc;
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_get_meme_em_info_umts_cell_status_value(meme_em_info_umts_cell_status_struct *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info.num_cells = data_ptr->num_cells;
    g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info.tx_power = data_ptr->tx_power;
    for (i = 0; i < 32; i++)
    {
        g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info.umts_cell_list[i] = data_ptr->umts_cell_list[i];    
    }
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
static void mmi_get_csce_em_serv_cell_s_status_ind_value(csce_em_serv_cell_s_status_ind_struct *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info.msg_len = data_ptr->msg_len;
     g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info.ref_count = data_ptr->ref_count;
     g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info.serv_cell = data_ptr->serv_cell;
 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
static void mmi_em_get_meme_em_info_h_serving_cell_ind_value(meme_em_info_h_serving_cell_ind_struct *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     g_mmi_em_3g_info->mmi_meme_em_info_h_serving_cell_ind_info.EDCH_Serving_PSC = data_ptr->EDCH_Serving_PSC;
     g_mmi_em_3g_info->mmi_meme_em_info_h_serving_cell_ind_info.EDCH_Serving_UARFCN = data_ptr->EDCH_Serving_UARFCN;
     g_mmi_em_3g_info->mmi_meme_em_info_h_serving_cell_ind_info.HSDSCH_Serving_PSC = data_ptr->HSDSCH_Serving_PSC;
     g_mmi_em_3g_info->mmi_meme_em_info_h_serving_cell_ind_info.HSDSCH_Serving_UARFCN = data_ptr->HSDSCH_Serving_UARFCN;
     
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
static void mmi_em_get_meme_em_periodic_bler_report_ind_value(meme_em_periodic_bler_report_ind *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
        U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     g_mmi_em_3g_info->mmi_meme_em_periodic_bler_report_ind_info.num_trch = data_ptr->num_trch;

     for (i = 0; i < 8; i++)
     {
         g_mmi_em_3g_info->mmi_meme_em_periodic_bler_report_ind_info.TrCHBler[i] = data_ptr->TrCHBler[i];
     }
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
static void mmi_em_get_slce_em_ps_data_rate_status_ind_value(slce_em_ps_data_rate_status_ind_struct * data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
        U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     for (i = 0; i < 8; i++)
     {    
        g_mmi_em_3g_info->mmi_slce_em_ps_data_rate_status_ind_info.ps_data_status[i] = data_ptr->ps_data_status[i];
     }
     g_mmi_em_3g_info->mmi_slce_em_ps_data_rate_status_ind_info.ps_number = data_ptr->ps_number;
}

 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
static void mmi_em_get_tcm_mmi_em_info_value(tcm_mmi_em_info_struct* data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     int i;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     for (i = 0; i < GPRS_MAX_PDP_SUPPORT; i++)
     {
        g_mmi_em_3g_info->mmi_tcm_mmi_em_info.data_speed[i] = data_ptr->data_speed[i];
     }

    g_mmi_em_3g_info->mmi_tcm_mmi_em_info.num_of_valid_entries = data_ptr->num_of_valid_entries;
 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_get_csce_em_info_multiple_plmn_value(csce_em_info_multiple_plmn_struct *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_3g_info->mmi_csce_em_info_multiple_plmn_info.multi_plmn_count = data_ptr->multi_plmn_count;

    for (i = 0; i < 6; i++)
    {
        g_mmi_em_3g_info->mmi_csce_em_info_multiple_plmn_info.multi_plmn_id[i] = data_ptr->multi_plmn_id[i];
    }
}

U8 cntt=1;
 /*****************************************************************************
  * FUNCTION
  *  mmi_em_rr_process_logs
  * DESCRIPTION
  *  
  * PARAMETERS
  *  em_info             [IN]        
  *  pdu_buff_ptr        [?]         
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_em_3g_info_get_peer_buff_data(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_mmi_em_3g_info)
     {
     /************   test   *****************/
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

     switch (em_info)
     {
         case MM_EM_INFO:
         {
             mm_em_info_struct *data_ptr;
             kal_uint16 mm_pdu_len;
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */

           //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_1);
             
             data_ptr = (mm_em_info_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_mm_em_info_value((mm_em_info_struct*) data_ptr);
         }
         break;
          
         case URR_EM_INFO_UMTS_SRNC_ID_INFO:
         {
             urr_umts_srnc_id_struct *data_ptr;
             kal_uint16 mm_pdu_len;
     
          //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_2);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (urr_umts_srnc_id_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_urr_umts_srnc_id_value((urr_umts_srnc_id_struct*) data_ptr);
         }
         break;
       

         case MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO:  //ABM_ACT://
         {
             meme_em_info_umts_cell_status_struct *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_3);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (meme_em_info_umts_cell_status_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_meme_em_info_umts_cell_status_value((meme_em_info_umts_cell_status_struct*) data_ptr);

         }
         break;
         
         case CSCE_EM_SERV_CELL_IND_STRUCT_INFO:  //ABM_ACT_ECC://
         {
             csce_em_serv_cell_s_status_ind_struct  *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_4);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (csce_em_serv_cell_s_status_ind_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_get_csce_em_serv_cell_s_status_ind_value((csce_em_serv_cell_s_status_ind_struct*) data_ptr);         
         }
         break;
         case MEME_EM_INFO_H_SERVING_CELL_INFO:
         {
             meme_em_info_h_serving_cell_ind_struct *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_5);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (meme_em_info_h_serving_cell_ind_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_meme_em_info_h_serving_cell_ind_value((meme_em_info_h_serving_cell_ind_struct*) data_ptr);
         }
         break;
         case MEME_EM_3G_BLER_IND_STRUCT_INFO:
         {
             meme_em_periodic_bler_report_ind *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_6);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (meme_em_periodic_bler_report_ind*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_meme_em_periodic_bler_report_ind_value((meme_em_periodic_bler_report_ind*) data_ptr);
         }
             break;
         case SLCE_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO:
         {
             slce_em_ps_data_rate_status_ind_struct *data_ptr;
             kal_uint16 mm_pdu_len;
     
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_7);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (slce_em_ps_data_rate_status_ind_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_slce_em_ps_data_rate_status_ind_value((slce_em_ps_data_rate_status_ind_struct*) data_ptr);

             
         }
             break;
         case TCM_EM_CONTEXT_INFO:
         {
             tcm_mmi_em_info_struct *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_8);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (tcm_mmi_em_info_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_tcm_mmi_em_info_value((tcm_mmi_em_info_struct*) data_ptr);
             
             break;
         }
        
         case CSCE_EM_INFO_MULTIPLE_PLMN_STRUCT_INFO:
         {
             csce_em_info_multiple_plmn_struct *data_ptr;
             kal_uint16 mm_pdu_len;
             
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_9);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (csce_em_info_multiple_plmn_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_csce_em_info_multiple_plmn_value((csce_em_info_multiple_plmn_struct*) data_ptr);
             break;
         }
        

         default:
         //	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND_10);
             break;
     }


     }
     free_peer_buff(pdu_buff_ptr);

}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
void mmi_em_3g_info_exit_screen(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsOnEMTracer_3g = 0;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_tracer_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

   for (i = (g_index_screen - 1 + MAX_TRACER_SCREEN_NUM) % MAX_TRACER_SCREEN_NUM; 
       i != g_index_screen; i=(( i - 1 ) + MAX_TRACER_SCREEN_NUM) % MAX_TRACER_SCREEN_NUM)
   {
      if(g_mmi_em_3g_info->g_index_screen_show[i] == 1)
       {
           break;
       }
   }

   g_index_screen = i;
   
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
    #endif

    
    mmi_em_3g_info_display_screen_n(g_index_screen);

}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_tracer_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


     for (i = (g_index_screen + 1) % MAX_TRACER_SCREEN_NUM; 
          i != g_index_screen; i = (i + 1)% MAX_TRACER_SCREEN_NUM)
     {
        if(g_mmi_em_3g_info->g_index_screen_show[i] == 1)
        {
            break;
        }
     }

     g_index_screen = i;

    
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
    #endif
    
    mmi_em_3g_info_display_screen_n(g_index_screen);

}
 
 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
void mmi_em_3g_info_tracer_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
   // SetKeyHandler(mmi_em_3g_info_tracer_key_up, KEY_UP_ARROW, KEY_EVENT_DOWN);

    SetKeyDownHandler(mmi_em_3g_info_tracer_key_up,KEY_UP_ARROW);
   
   // SetKeyHandler(mmi_em_3g_info_tracer_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

   SetKeyDownHandler(mmi_em_3g_info_tracer_key_down, KEY_DOWN_ARROW);

   // SetKeyHandler(mmi_em_3g_info_tracer_key_up, KEY_VOL_UP, KEY_EVENT_DOWN);
  //  SetKeyHandler(mmi_em_3g_info_tracer_key_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);

   SetKeyDownHandler(mmi_em_3g_info_tracer_key_up, KEY_VOL_UP);
   SetKeyDownHandler(mmi_em_3g_info_tracer_key_down,KEY_VOL_DOWN);

#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif 
#endif


}
 
/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
void mmi_em_3g_info_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     stFontAttribute debug_print_font = {0, 0, 0, SMALL_FONT, 0, 0};
     color c;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     c = gui_color(color_r, color_g, color_b);

     UI_fill_rectangle(
         0,
         20,
         //MMI_STATUS_BAR_HEIGHT,
         MAIN_LCD_device_width-1,
         MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
         c);

     UI_set_font(&debug_print_font);
     c = gui_color(0, 0, 0);
     UI_set_text_color(c);
}
 
 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
void mmi_em_3g_info_display_line_n(kal_int32 *text_pos, kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 temp_str[200]={0};

    S32 width = 0, height = 0;
    stFontAttribute     MMI_small_font=         {   0,0,0,SMALL_FONT,0,1    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((char*) temp_str, (char*) str, sizeof(temp_str) / 2 - 1);
 //   Get_StringWidthHeight((U8*) temp_str, (S32*) & alignment_width, (S32*) & alignment_height);

    gui_set_font(&MMI_small_font);

    gui_measure_string((UI_string_type) temp_str, &width, &height);

    if ((S32)(*text_pos+height) < (S32)(MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT-1) )
    {
        gui_move_text_cursor(0, *text_pos);
        *text_pos += height;
        gui_print_text((UI_string_type) temp_str);
    }
}


/*-------------------------------------------------------------------*/
/*                       3G info screen(16)                          */
/*                                                                   */
/*-------------------------------------------------------------------*/


// Screen1----Selected PLMN
// Screen2----Access Class
// Screen3----SRNC ID
// Screen4----Serving Cell PLMN
// Screen5----Serving Cell
// Screen6----Active Cell
// Screen7----Intra-freq monitored cell(1)
// Screen8----Intra-freq monitored cell(2)
// Screen9----Inter-freq monitored cell(1)
// Screen10----Inter-freq monitored cell(2)
// Screen11----deteced cell
// Screen12----H-Serving Cell
// Screen13----PDP Data Speed
// Screen14----PS Service Infro
// Screen15----Block Error Rate
// Screen16----UE Transmission

/*SCREEN 1: Selected PLMN*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn1(
            kal_uint8 screen_num,
            mm_em_info_struct  *mmi_em_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page one */

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Selected PLMN", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    if (mmi_em_info->mnc[2] == 0xF)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],
         "%x%x%x%x%x",mmi_em_info->mcc[0],mmi_em_info->mcc[1],mmi_em_info->mcc[2],
         mmi_em_info->mnc[0],mmi_em_info->mnc[1]);
    }
    else
    {
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],
             "%x%x%x%x%x%x",mmi_em_info->mcc[0],mmi_em_info->mcc[1],mmi_em_info->mcc[2],
             mmi_em_info->mnc[0],mmi_em_info->mnc[1],mmi_em_info->mnc[2]);
    }


    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
}


/*SCREEN 2: Access Class*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn2(
            kal_uint8 screen_num,
            mm_em_info_struct  *mmi_em_info)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    char *str[4];

    str[0] = "NOT_BARRED";
    str[1] = "EMERGENCY_ONLY";
    str[2] = "ALL_BARRED";
    str[3] = "N/A";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 2 */
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Access Class", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%s", "Common Access Class", str[mmi_em_info->common_access_class]);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%s", "CS Access Class", str[mmi_em_info->cs_access_class]);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%s", "PS Access Class", str[mmi_em_info->ps_access_class]);
    
    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}

/*SCREEN 3: SRNC ID*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn3(
            kal_uint8 screen_num,
            urr_umts_srnc_id_struct  *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 3 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "SRNC ID", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d", "SRNC ID", data->srnc);

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


/*SCREEN 4: Serving Cell PLMN*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn4(
            kal_uint8 screen_num,
            csce_em_info_multiple_plmn_struct  *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 4 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Serving Cell PLMN", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    for (j = 1; j <= data->multi_plmn_count; j++ )
    {

        if (data->multi_plmn_id[j-1].mnc3 == 0xf)
        {
            sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s%d: %x%x%x%x%x", "PLMN", j, 
            data->multi_plmn_id[j-1].mcc1,
            data->multi_plmn_id[j-1].mcc2,
            data->multi_plmn_id[j-1].mcc3,
            data->multi_plmn_id[j-1].mnc1,
            data->multi_plmn_id[j-1].mnc2);  
        }
        else
        {
           sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s%d: %x%x%x%x%x%x", "PLMN", j, 
            data->multi_plmn_id[j-1].mcc1,
            data->multi_plmn_id[j-1].mcc2,
            data->multi_plmn_id[j-1].mcc3,
            data->multi_plmn_id[j-1].mnc1,
            data->multi_plmn_id[j-1].mnc2,
            data->multi_plmn_id[j-1].mnc3); 
        }
    
    }
    
    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}

/*SCREEN 5: Serving Cell*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn5(
            kal_uint8 screen_num,
            csce_em_serv_cell_s_status_ind_struct  *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 5 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Serving Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    if (g_em_mode == EM_3G_INFO_MODE)
    {
         sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s  %s", "uarfcn",
            "psc","rscp","ecn0","rssi","band","cell_id");
    }
    else if(g_em_mode == EM_TDD_MODE)
    {
         sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s", "uarfcn",
            "psc","rscp","rssi","band","cell_id");        
    }

    
    if (g_em_mode == EM_3G_INFO_MODE)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%d   %d   %d      %d      %d      %d   0x%x",
            data->serv_cell.uarfcn_DL, 
            data->serv_cell.psc,
            (data->serv_cell.rscp)/4096, 
            (data->serv_cell.ec_no)/4096,
            data->serv_cell.rssi, 
            data->serv_cell.band, 
            data->serv_cell.cell_identity);
    }
    else if(g_em_mode == EM_TDD_MODE)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%d  %d  %d  %d  %d  0x%x",
            data->serv_cell.uarfcn_DL, 
            data->serv_cell.psc,
            data->serv_cell.rscp/4096, 
            data->serv_cell.rssi, 
            data->serv_cell.band, 
            data->serv_cell.cell_identity);        
    }


    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


/*SCREEN 6: Active Cell*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn6(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 6 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Active Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s  %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");

   
    for (j=0; j<data->num_cells ;j++)
    {
        if(data->umts_cell_list[j].cell_type == 4)    // active cell
        {
            sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%5d %5d %4d %4d    %5d %5d      0x%x",
                data->umts_cell_list[j].UARFCN, 
                data->umts_cell_list[j].PSC,
                (data->umts_cell_list[j].RSCP)/4096,
               
                (data->umts_cell_list[j].ECN0)/4096, 
                
                data->umts_cell_list[j].RSSI,
               
                data->umts_cell_list[j].Band, 
                data->umts_cell_list[j].Cell_identity);
        }
        
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}



int g_flag_intra = -1;
/*SCREEN 7: Intra-freq monitored cell(1)*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn7(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct  *data,
            csce_em_serv_cell_s_status_ind_struct *tag)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    U8 j, cnt=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 7 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Intra-Freq Monitored Cell(1)", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
   
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s  %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");

    for (j=0; j<data->num_cells && cnt<16 ;j++)
    {
        if(data->umts_cell_list[j].cell_type == 0 && 
                    tag->serv_cell.uarfcn_DL == data->umts_cell_list[j].UARFCN)    // intra monitored cell
        {
            sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%5d %5d %4d %4d    %5d %5d      0x%x",
                data->umts_cell_list[j].UARFCN,
                data->umts_cell_list[j].PSC,
                (data->umts_cell_list[j].RSCP)/4096,
              
                (data->umts_cell_list[j].ECN0)/4096, 
             
                data->umts_cell_list[j].RSSI,
             
                data->umts_cell_list[j].Band, 
                data->umts_cell_list[j].Cell_identity);
            cnt++;
        }
        
    }

    if(j < data->num_cells)
    {
        g_flag_intra = j;
    }
    else
    {
        g_flag_intra = -1;
    }

    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }


    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


/*SCREEN 8: Intra-freq monitored cell(2)*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn8(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct  *data,
            csce_em_serv_cell_s_status_ind_struct *tag)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    U8 j, cnt=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 8*/
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Intra-Freq Monitored Cell(2)", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s  %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");

    if(g_flag_intra == -1)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }
    else
    {
            for (j=g_flag_intra; j<data->num_cells && cnt<16 ;j++)
            {
                if(data->umts_cell_list[j].cell_type == 0 &&  
                    tag->serv_cell.uarfcn_DL == data->umts_cell_list[j].UARFCN)    // intra monitored cell
                {
                    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"5d %5d %4d %4d    %5d %5d      0x%x",
                    data->umts_cell_list[j].UARFCN,
                    data->umts_cell_list[j].PSC,
                    (data->umts_cell_list[j].RSCP)/4096,
                
                    (data->umts_cell_list[j].ECN0)/4096, 
                  
                    data->umts_cell_list[j].RSSI,
                  
                    data->umts_cell_list[j].Band, 
                    data->umts_cell_list[j].Cell_identity);
                  cnt++;
                }
                
            }
    }

    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
 
}



int g_flag_inter = -1;
/*SCREEN 9:Inter-freq monitored cell(1)*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn9(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct  *data,
            csce_em_serv_cell_s_status_ind_struct *tag)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    U8 j, cnt=0;

    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 9 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Inter-Freq Monitored Cell(1)", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s  %s  %s  %s  %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");


    for (j=0; j<data->num_cells && cnt<16 ;j++)
    {
        if(data->umts_cell_list[j].cell_type == 0 &&   
                    tag->serv_cell.uarfcn_DL != data->umts_cell_list[j].UARFCN)    // inter monitored cell
        {
            sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%5d %5d %4d %4d    %5d %5s      0x%x",
                    data->umts_cell_list[j].UARFCN,
                    data->umts_cell_list[j].PSC,
                    (data->umts_cell_list[j].RSCP)/4096,
                   
                    (data->umts_cell_list[j].ECN0)/4096, 
               
                    data->umts_cell_list[j].RSSI,
              
                    romaNum[data->umts_cell_list[j].Band], 
                    data->umts_cell_list[j].Cell_identity);
            cnt++;
        }
        
    }

    if(j < data->num_cells)
    {
        g_flag_inter = j;
    }
    else
    {
        g_flag_inter = -1;
    }
    

    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
 
}


/*SCREEN 10: Inter-freq monitored cell(2)*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn10(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct  *data,
            csce_em_serv_cell_s_status_ind_struct *tag)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    U8 j, cnt=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 8*/
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Inter-Freq Monitored Cell(2)", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s %s %s %s %s %s %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");

    if(g_flag_inter == -1)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }
    else
    {
            for (j=g_flag_inter; j<data->num_cells && cnt<16 ;j++)
            {
                if(data->umts_cell_list[j].cell_type == 0 &&   
                    tag->serv_cell.uarfcn_DL != data->umts_cell_list[j].UARFCN)    // inter monitored cell
                {
                    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%d %d %d %d %d %d 0x%x",
                        data->umts_cell_list[j].UARFCN,
                        data->umts_cell_list[j].PSC,
                        (data->umts_cell_list[j].RSCP)/4096,
                       
                        (data->umts_cell_list[j].ECN0)/4096, 
                      
                        data->umts_cell_list[j].RSSI,
                       
                        data->umts_cell_list[j].Band, 
                        data->umts_cell_list[j].Cell_identity);
                    cnt++;
                }
                
            }
    }

    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
 
}



/*SCREEN 11: deteced cell*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn11(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j, flag = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 11 */
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Detected Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s %s %s %s %s %s %s", "uarfcn",
    "psc","rscp","ecn0","rssi","band","cell_id");

   
    for (j=0; j<data->num_cells ;j++)
    {
        if(data->umts_cell_list[j].cell_type == 2)    // detected cell
        {
            sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%d %d %d %d %d %d 0x%x",
                data->umts_cell_list[j].UARFCN,
                data->umts_cell_list[j].PSC,
                (data->umts_cell_list[j].RSCP)/4096,
                
                (data->umts_cell_list[j].ECN0)/4096, 
                
                data->umts_cell_list[j].RSSI,
               
                data->umts_cell_list[j].Band, 
                data->umts_cell_list[j].Cell_identity);
            flag++;
        }
        
    }
    
    if(flag == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


/*SCREEN 12: H-Serving Cell*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn12(
            kal_uint8 screen_num,
            meme_em_info_h_serving_cell_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 12 */

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "H-Serving Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s : %d / %d", "HS-DSCH Serving Cell",
           data->HSDSCH_Serving_UARFCN, data->HSDSCH_Serving_PSC);

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s : %d / %d", "E-DCH Serving Cell",
       data->EDCH_Serving_UARFCN, data->EDCH_Serving_PSC);

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}


/*SCREEN 13: PDP Data Speed*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn13(
            kal_uint8 screen_num,
            tcm_mmi_em_info_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    kal_uint8 j = 0;

    char *str[7];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 13 */

    str[0] = "NONE";
    str[1] = "GPRS";
    str[2] = "EDGE";
    str[3] = "UMTS";
    str[4] = "HSDPA";
    str[5] = "HSUPA";
    str[6] = "HSDPA/HSUPA";

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "PDP Data Speed", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");

    for (j = 0; j < data->num_of_valid_entries; j++)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s: %d ","NSAPI", data->data_speed[j].nsapi);
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s: %s ","Speed", str[data->data_speed[j].data_speed_value]);
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"--------------");
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }
    

    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*SCREEN 14: PS Service Information*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn14(
            kal_uint8 screen_num,
            slce_em_ps_data_rate_status_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    kal_uint8 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 14 */

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "PS Service Information", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s  %s  %s     %s ","RAB ID", "RB ID", "UL RATE", "DL RATE");
    
    for (j = 0; j < data->ps_number; j++)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%d           %d        %d    %d", data->ps_data_status[j].RAB_ID,data->ps_data_status[j].RB_ID,
                data->ps_data_status[j].UL_rate, data->ps_data_status[j].DL_rate);
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }
    
    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*SCREEN 15: Block Error Rate */
kal_uint8 mmi_em_3g_info_get_data_for_scrn15(
            kal_uint8 screen_num,
            meme_em_periodic_bler_report_ind  *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    kal_uint8 j = 0;   
    float channel_id = 0.0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 15 */


    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "Block Error Rate", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    
    for (j = 0; j < data->num_trch; j++)
    {
        if(data->TrCHBler[j].TotalCRC != 0)
            channel_id = (float)(data->TrCHBler[j].BadCRC) / (float)(data->TrCHBler[j].TotalCRC)*100.0;
        else
            channel_id = 0.0;
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s: %d, %f%%",
     "Transport Channel ID",data->TrCHBler[j].TrCHId, channel_id);
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++],"%s", "No signal...");
    }
    
    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*SCREEN 16: UE Transmission*/
kal_uint8 mmi_em_3g_info_get_data_for_scrn16(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct  *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 15 */

    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%s:%d/%d", "UE Transmission", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "-------------------------");
    
    sprintf((char*)g_mmi_em_3g_info->mmi_screen_text[i++], "%d %s",data->tx_power , "dbm");
   
    g_mmi_em_3g_info->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*-------------------------------------------------------------------*/
/*                         SCREEN END                                */
/*                                                                   */
/*-------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
kal_uint8 mmi_show_3g_info_screen_text_log(int screen_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 screen_num_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     switch (screen_number)
     {
         case 0:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn1((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_em_info);
             break;
         case 1:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn2((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_em_info);
             break;
         case 2:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn3((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_urr_umts_srnc_id_info);
             break;
         case 3:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn4((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_csce_em_info_multiple_plmn_info);
             break;
         case 4:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn5((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 5:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn6((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info);
             break;
         case 6:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn7((kal_uint8)screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info, &g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 7:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn8((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info, &g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 8:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn9((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info, &g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 9:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn10((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info, &g_mmi_em_3g_info->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 10:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn11((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info);
             break;


        case 11:
            screen_num_id = mmi_em_3g_info_get_data_for_scrn12((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_h_serving_cell_ind_info);
            break;
        case 12:
            screen_num_id = mmi_em_3g_info_get_data_for_scrn13((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_tcm_mmi_em_info);
            break;
        case 13:
            screen_num_id = mmi_em_3g_info_get_data_for_scrn14((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_slce_em_ps_data_rate_status_ind_info);
            break;
        case 14:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn15((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_periodic_bler_report_ind_info);
             break;
        case 15:
             screen_num_id = mmi_em_3g_info_get_data_for_scrn16((kal_uint8) screen_number, &g_mmi_em_3g_info->mmi_meme_em_info_umts_cell_status_info);
             break;
             

         default:
             break;

    }
    return screen_num_id;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_display_screen_n(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_pos = 20;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(screen_num < MAX_TRACER_SCREEN_NUM);

    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    mmi_em_3g_info_tracer_screen_color_init(255, 255, 255);

    mmi_show_3g_info_screen_text_log(screen_num);

    

    for (i = 0; i < MAX_TRACER_LINE_NUM; i++)
    {
        if (g_mmi_em_3g_info->mmi_screen_text[i][0] == '\0')
        {
            break;
        }
        mmi_em_3g_info_display_line_n(&text_pos, g_mmi_em_3g_info->mmi_screen_text[i]);
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}

/*****************************************************************************
* FUNCTION
*  mmi_em_3g_info_is_in_call
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_em_3g_info_is_in_call(void)
{
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, 
					SRV_UCM_CALL_TYPE_ALL , NULL) > 0)																				/*Have calling*/
   		 { //SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE
        	if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, 
									SRV_UCM_VIDEO_CALL_TYPE_ALL , NULL) > 0)															/*If on VT call screen*/
            return MMI_FALSE;
          else
            return MMI_TRUE;
    }
        return MMI_FALSE;
}

/*  For remove frm history code, so use group and proc screen */
static mmi_ret mmi_em_3g_info_group_proc(mmi_event_struct* evt)
{
	switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
			g_3g_popup_gourp_id = 0;
            break;
        }
	}
	   return MMI_RET_OK;
            
}

static mmi_ret mmi_em_3g_info_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_avt = (mmi_frm_scrn_active_evt_struct*)evt;
            
            if (active_avt->is_first_active)
            {
                MMI_EM_3G_INFO_SET_ON(0X01, g_em_3g_comm_info);
            }
			ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
            mmi_em_3g_info_display_screen_n(g_index_screen);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_pen_down_handler(mmi_em_3g_info_tracer_key_down);
        #endif
		
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

   #ifdef __COSMOS_MMI_PACKAGE__    
       SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
   #endif
            break;
        }
            
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_EM_3G_INFO_SET_OFF(0X01, g_em_3g_comm_info);
            break;
        }
            
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
           
            if (key_evt->key_type == KEY_EVENT_UP)
            {
                if (KEY_UP_ARROW == key_evt->key_code || KEY_VOL_UP == key_evt->key_code)
                {
                    mmi_em_3g_info_tracer_key_up();
                    return MMI_RET_KEY_HANDLED;
                }
                if (KEY_DOWN_ARROW == key_evt->key_code || KEY_VOL_DOWN == key_evt->key_code)
                {
                    mmi_em_3g_info_tracer_key_down();
                    return MMI_RET_KEY_HANDLED;
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
*  mmi_em_show_screen
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_3g_info_show_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
	MMI_BOOL status;
    #endif /*__COSMOS_MMI_PACKAGE__*/

    #ifndef __COSMOS_MMI_PACKAGE__
    kal_uint16 current_screen;
    #endif /*__COSMOS_MMI_PACKAGE__*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, 
					SRV_UCM_VIDEO_CALL_TYPE_ALL , NULL) > 0)
    {
         return;
    }

#ifndef __COSMOS_MMI__
    if (mmi_idle_is_active() || mmi_em_3g_info_is_in_call())
#else
    if (vapp_launcher_is_active() || mmi_em_3g_info_is_in_call())
#endif
    {
	g_3g_popup_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
							   GRP_ID_AUTO_GEN, mmi_em_3g_info_group_proc, NULL);

		mmi_frm_group_enter(g_3g_popup_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
		
        mmi_frm_scrn_create(
            g_3g_popup_gourp_id,
            SCR_ID_EM_NW_INFO_LOG,
            mmi_em_3g_info_scrn_proc, NULL);
    }

}

 void mmi_em_3g_fresh_active_scrn(void)
 {
	  /*mmi_frm_scrn_create(GRP_ID_ROOT, SCR_ID_DUMMY, NULL, NULL);*/
	  
	   mmi_frm_scrn_enter
          (GRP_ID_ROOT, 
          SCR_ID_DUMMY, 
          NULL, 
          mmi_em_3g_fresh_active_scrn, 
          MMI_FRM_FULL_SCRN);
	  
	  
 
	  mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_DUMMY);
}


 /*****************************************************************************
  * FUNCTION
  * 
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  *  
  *****************************************************************************/
void mmi_em_3g_info_parsing_data(void *info)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;
     

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_em_3g_info_get_peer_buff_data(msg->em_info, msg->info);
     
     /* display the trace information on screen */
     if (g_mmi_em_3g_info != NULL)
     {
     	if (MMI_EM_3G_INFO_CHK_MODE(0X01, g_em_3g_comm_info))
			mmi_em_3g_fresh_active_scrn();
		else
        mmi_em_3g_info_show_screen();
     }
}
 
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
static void mmi_em_3g_info_get_list_states(U8 *list_of_states, U8 *list_of_menu_selected)
{
    U8 i;
    for (i = 0; i < MAX_EM_MODE; i++)
    {
       list_of_states[i] = EM_OFF; 
    }
    
    for (i = 0; i < MAX_EM_MOD_3G_INFO_SELECTED_ITEMS; i++)
    {
        if(list_of_menu_selected[i] == 1)
        {
            if(mmi_em_menu_em_info_map_tab[i].num_relevant == 1)
                list_of_states[mmi_em_menu_em_info_map_tab[i].index_1] = EM_ON;
            else if(mmi_em_menu_em_info_map_tab[i].num_relevant == 2)
                {
                    list_of_states[mmi_em_menu_em_info_map_tab[i].index_1] = EM_ON;
                    list_of_states[mmi_em_menu_em_info_map_tab[i].index_2] = EM_ON;
                }
        }
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_get_menu_selected(U8 *list_of_selected, U16 *mode_status)
{
     U32 i;
     U16 mode = 0x01;
     
     for (i = 0;i < 14; i++)
     {
         if (MMI_EM_3G_INFO_CHK_MODE(mode, *mode_status))
         {
             
             list_of_selected[i] = 1;
         }
         else
         {
             list_of_selected[i] = 0;
         }
         mode = mode * 2;
     } 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_trace_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_3g_info != NULL)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, (PsIntFuncPtr)mmi_em_3g_info_parsing_data, MMI_FALSE);
    }
    else 
    {
        mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, NULL);
    }
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_UPDATE_RSP, (PsIntFuncPtr)mmi_em_3g_info_start_rsp, MMI_FALSE);
 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_info_send_start_req(module_type mod_id)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 //    MYQUEUE Message;
     mmi_em_update_req_struct *em_start_req;
     U8 i=0;
     U8 list_of_menu_selected[MAX_EM_MOD_3G_INFO_SELECTED_ITEMS] = {0};
     U8 list_of_states[MAX_EM_MODE] = {0};
     U8 cur_list_states[MAX_EM_MODE] = {0};

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_em_3g_info_get_menu_selected(list_of_menu_selected, &g_mmi_em_3g_info_mode_status);
     mmi_em_3g_info_get_list_states(list_of_states, list_of_menu_selected);
     
     mmi_em_3g_info_show_screen();

   //  Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
     em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

     for (i=0;i<EM_INFO_REQ_NUM;i++)
     {
         em_start_req->info_request[i] = EM_OFF;
     }

     if (em_3g_info_entry == 0)
     {
        /* it is the first to send em info update */
         for (i = 0;i < MAX_EM_MODE; i++)
         {
             if (list_of_states[i] != EM_OFF)
             {
                 em_start_req->info_request[em_3g_info_item_table [i]] = list_of_states[i];
             }
         }
         g_mmi_em_3g_info_cur_mode = g_mmi_em_3g_info_mode_status;
     }
     else
     {
         mmi_em_3g_info_get_menu_selected(list_of_menu_selected, &g_mmi_em_3g_info_cur_mode);
         mmi_em_3g_info_get_list_states(cur_list_states, list_of_menu_selected);
         /* it is the first to send em info update */
         for (i=0;i<MAX_EM_MODE;i++)
         {
             if (cur_list_states[i] == list_of_states[i])
             {
                 em_start_req->info_request[em_3g_info_item_table [i]] = EM_NC;
             }
             else
             {
                 em_start_req->info_request[em_3g_info_item_table [i]] = list_of_states[i];       
             }
         }
         g_mmi_em_3g_info_cur_mode = g_mmi_em_3g_info_mode_status;
     }
     em_3g_info_entry++;

   //  Message.oslDataPtr = (oslParaType*) em_start_req;
    // Message.oslPeerBuffPtr = NULL;
   //  Message.oslSrcId = MOD_MMI;
     if(g_sim_mode == SIM_MODE_1)
       // Message.oslDestId = MOD_L4C;
       mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);

#if (MMI_MAX_SIM_NUM >= 2)
     else if(g_sim_mode == SIM_MODE_2)
       // Message.oslDestId = MOD_L4C_2;
       mmi_frm_send_ilm(MOD_L4C_2,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);
  #endif
   // OslMsgSendExtQueue(&Message);

  //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND1,4);

}

 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
 void EngineerModeStartReq_3G(U32 mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND1,3);
    mmi_em_3g_info_display_init();
    mmi_em_3g_info_trace_on_ind(); 
    mmi_em_3g_info_send_start_req((module_type)mod_id);
}
 
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_set_show_screen_index()
{
    U8 i,j;
    U8 list_of_menu_selected[MAX_EM_MOD_3G_INFO_SELECTED_ITEMS];

    if(!g_mmi_em_3g_info)
    {
        return;
    }
    
    mmi_em_3g_info_get_menu_selected(list_of_menu_selected, &g_mmi_em_3g_info_mode_status);
    
    for (i=0,j=0; i<MAX_TRACER_SCREEN_NUM; i++,j++)  //j: 0~13 (14)
    {
        if(list_of_menu_selected[j] == 1)
        {
            g_mmi_em_3g_info->g_index_screen_show[i] = 1;
        }
        else
        {
            g_mmi_em_3g_info->g_index_screen_show[i] = 0;
        }
        if(i==6)
        {
            if(list_of_menu_selected[j] == 1)
            {
                g_mmi_em_3g_info->g_index_screen_show[7] = 1;
                i = 7;
            }
            else
            {
                g_mmi_em_3g_info->g_index_screen_show[7] = 0;
                i = 7;
            }
        }
        if(i==8)
        {
            if(list_of_menu_selected[j] == 1)
            {
                g_mmi_em_3g_info->g_index_screen_show[9] = 1;
                i = 9;
            }
            else
            {
                g_mmi_em_3g_info->g_index_screen_show[9] = 0;
                i = 9;
            }
        }
    }
           
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void mmi_em_3g_info_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_3g_info_init_mem();
    mmi_em_set_show_screen_index();
    EngineerModeStartReq_3G(MOD_AS);
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_em_3g_info_update_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND1,2);
	 
    switch (alert->result)
    {
    case MMI_ALERT_CNFM_YES:
    	mmi_em_3g_info_send_msg();
    	break;
    case MMI_ALERT_CNFM_NO:
        g_mmi_em_3g_info_mode_status = g_mmi_em_3g_info_mode_status_history;
    	break;
	default:
		break;
    }

    return MMI_RET_OK;
}
 

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_3g_info_list_exit_hdlr(cui_menu_event_struct *evt)
{
	mmi_confirm_property_struct arg;

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_em_3g_info_update_proc;
    arg.parent_id = g_gourp_id;
    arg.f_auto_map_empty_softkey =  MMI_FALSE;
	arg.user_tag = (void *)evt->sender_id;

    mmi_confirm_display((WCHAR *)get_string(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &arg);
	cui_menu_close(evt->sender_id);
}

 /*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
 static void mmi_em_3g_info_list_hdlr(cui_menu_event_struct *evt)
 {
     U32 i;
     U16 mode = 0x01;
     U8 list_of_menu_selected[MAX_EM_MOD_3G_INFO_SELECTED_ITEMS] = {0};
 
     g_mmi_em_3g_info_mode_status_history = g_mmi_em_3g_info_mode_status;  /*save history record*/
 
     cui_menu_get_checkbox_state(evt->sender_id, list_of_menu_selected);
     for (i = 0;i < MAX_EM_MOD_3G_INFO_SELECTED_ITEMS; i++)
     {
         if (1 == list_of_menu_selected[i])
         {
             mode = mode;
             MMI_EM_3G_INFO_SET_ON(mode, g_mmi_em_3g_info_mode_status);  //Set on status to g_mmi_em_3g_info_mode_status
         }
         
         if (0 == list_of_menu_selected[i])
         {
             mode = mode;
             MMI_EM_3G_INFO_SET_OFF(mode, g_mmi_em_3g_info_mode_status); //Set off status
         }
         mode = mode * 2;
     }
  //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_3G_INFO_IND1,1);
    mmi_em_3g_info_list_exit_hdlr(evt);
 }
 

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_em_3g_info_checkbox_list_proc(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
	    case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_em_3g_info_list_pre_hdlr(menu_evt->sender_id);
			break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
			if (MENU_ID_EM_3G_INFO_NEW_ROOT == menu_evt->parent_menu_id)
			{
			    mmi_em_3g_info_list_hdlr(menu_evt);		//set bit mask
			}
            cui_menu_close(menu_evt->sender_id);
			break;
        case EVT_ID_GROUP_DEINIT:

            break;
        default:
            break;	
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_3g_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
		                   GRP_ID_AUTO_GEN, mmi_em_3g_info_checkbox_list_proc, NULL);
	mmi_frm_group_enter(g_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
	menu_id = cui_menu_create(g_gourp_id, CUI_MENU_SRC_TYPE_RESOURCE, CUI_MENU_TYPE_APPSUB,
		                    MENU_ID_EM_3G_INFO_NEW_ROOT,
		                    MMI_TRUE, NULL);
	cui_menu_run(menu_id);

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
#endif

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
extern void mmi_em_3g_info_menu_event_hdlr(cui_menu_event_struct *evt)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->highlighted_menu_id)
    {
        case MENU_ID_EM_SIM1:
            if (g_sim_mode == SIM_MODE_2 && g_mmi_em_3g_info_mode_status != 0)
            {
                mmi_display_popup(get_string(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE);
                break;
            }
            g_sim_mode = SIM_MODE_1;
                mmi_em_3g_entry();
            break;

        default:
            break;
            
    }

    g_em_mode = EM_3G_INFO_MODE;
}

#endif

#endif /*__MMI_EM_NW_FDD_NETWORK_INFO__*/


/**************************************************************
	Below is 3G_Info TDD
**************************************************************/
/*-------------------------------- 3G Info TDD -------------------------------------------*/

#ifdef __MMI_EM_NW_TDD_NETWORK_INFO__

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"
#include "em_struct.h" 
#include "em_public_struct.h"

#if defined(__MMI_ENGINEER_MODE__) 

#include "ProtocolEvents.h"
//#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "PixcomFontEngine.h"   
#include "MainMenuDef.h"
#include "CustomCfg.h"

#include "MenuCuiGprot.h"
//#include "audioInc.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"
#include "FactoryModeProt.h"
#include "AlarmDef.h"
#include "gpioInc.h"
#include "DateTimeGprot.h"
//#include "Simdetectiondef.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"



#include "mmi_rp_app_engineermode1_def.h"



#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"

#include "idleappdef.h"
#ifdef __MMI_TOUCH_SCREEN__
#endif 
#include "EngineerModeUtil.h"
#include "CommonScreens.h"

#ifdef __EM_MODE__
#include "FileMgr.h"
//#include "UserProfilesResDef.h"

/*
#include "ProfilesDefs.h"
#include "Profiles_Prot.h"
#include "ProfileGprots.h"
#include "ProfilesGexdcl.h"
#include "ProfileMgrGProt.h"
*/
#include "ProfilesSrvGprot.h"

#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#endif /* #ifdef __EM_MODE__ */

#if defined(__MMI_UCM__)
#include "UCMResDef.h"
#endif

#include "NetworkSetupGProt.h"

#if 0
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif

#ifdef __ENHANCED_UMTS_RF_CUSTOMIZATION__
#include "ul1d_rf_general.h"
#endif

#include "EngineerModeCommMem.h"

#include "UcmSrvGprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MAX_EM_MOD_TDD_SELECTED_ITEMS         (9)  

#define MMI_EM_TDD_CHK_MODE(_mode, _record)     ((_mode) & (_record))? (1) : (0)
#define MMI_EM_TDD_SET_ON(_mode, _record)       _record = (_mode) | (_record)     /* checkbox ON == 00 */
#define MMI_EM_TDD_SET_OFF(_mode, _record)      _record = ~(_mode) & (_record)    /* checkbox OFF == 01 */


#define EM_LOG_SCREEN_ID 907

#define MAX_EM_MODE (sizeof(em_tdd_item_table)/sizeof(U8))

#define MAX_TRACER_TDD_SCREEN_NUM         (12)       
#define MAX_TRACER_LINE_NUM           (30)

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
 //   mmi_chset_convert


/***************************************************************************** 
 * Enum
 *****************************************************************************/
typedef struct
{
    kal_uint8 g_index_screen;
    kal_uint8 mmi_screen_text[MAX_TRACER_LINE_NUM][50];
    kal_uint8 num_of_carriers;

    kal_uint8 g_index_screen_show[MAX_TRACER_TDD_SCREEN_NUM];     /* if =1 show this scrn,else don't show*/

    mm_em_info_struct mmi_em_info;
    urr_umts_srnc_id_struct  mmi_urr_umts_srnc_id_info;
    
    meme_em_info_umts_cell_status_struct  mmi_meme_em_info_umts_cell_status_info;
    csce_em_serv_cell_s_status_ind_struct mmi_csce_em_serv_cell_s_status_ind_info;
  //  meme_em_info_h_serving_cell_ind_struct  mmi_meme_em_info_h_serving_cell_ind_info;
 //   meme_em_periodic_bler_report_ind  mmi_meme_em_periodic_bler_report_ind_info;
    slce_em_ps_data_rate_status_ind_struct  mmi_slce_em_ps_data_rate_status_ind_info;
    tcm_mmi_em_info_struct mmi_tcm_mmi_em_info;
  //  csce_em_info_multiple_plmn_struct  mmi_csce_em_info_multiple_plmn_info;

    ul2_em_periodic_bler_report_ind mmi_ul2_em_periodic_bler_report_ind_info;
    meme_em_info_gsm_cell_status_struct mmi_meme_em_info_gsm_cell_status_info;
    
} mmi_em_tdd_struct;

//mmi_chset_convert

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_em_tdd_struct *g_mmi_em_tdd;

static U8 em_tdd_entry = 0;

U16 g_mmi_em_tdd_cur_mode = 0;

kal_uint8 gIsOnEMTracer_tdd = 0;

MMI_BOOL is_idle = MMI_FALSE;


typedef struct {

    U16     string_id;
    U8      event_index;        
} em_tdd_item_struct;



static const U8 em_tdd_item_table [] = 
{
    MM_EM_INFO,
    URR_EM_INFO_UMTS_SRNC_ID_INFO,
    MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO,
    CSCE_EM_SERV_CELL_IND_STRUCT_INFO,
    SLCE_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO,
    TCM_EM_CONTEXT_INFO,
    MEME_EM_INFO_GSM_CELL_STATUS_STRUCT_INFO,
    UL2_EM_3G_BLER_IND_STRUCT_INFO
};

typedef struct {
    U8 menu_list_item;
    U8 num_relevant;
    U8 index_1;    /*menu list item*/
    U8 index_2;
}mmi_em_menu_em_info_map_struct;

static const mmi_em_menu_em_info_map_struct mmi_em_menu_em_info_map_tab [] =
{
    {1,     1,      0,      -1},
    {2,     1,      0,      -1},
    {3,     1,      1,      -1},
    {4,     1,      3,      -1},
    {5,     1,      2,      -1},
    {6,     1,      6,      -1},
    {7,     1,      5,      -1},
    {8,     1,      4,      -1},
    {9,     1,      7,      -1}
};


static kal_uint8 g_index_screen_tdd = 0;

static char *romaNum[]={"0","I","II","III","IV","V","VI","VII","VIII","IX",
    "X","XI","XII","XIII","XIV","XV",
    "XVI","XVII","XVIII","XIX","XX","XXI",
    "XXII","XXIII","XXIV","XXV","XXVI","XXVII",
    "XXVIII","XXIX","XXX","XXXI","XXXII"};

static U8 g_popup_flag = 0;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static MMI_BOOL mmi_em_tdd_mem_stop_hdlr(void);
static void mmi_em_tdd_release_context(void);

static void mmi_em_tdd_display_screen_n(kal_uint8 screen_num);


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
static MMI_ID g_gourp_id;

U16 g_mmi_em_tdd_mode_status = 0;
U16 g_mmi_em_tdd_mode_status_history = 0;


 /*****************************************************************************
 * FUNCTION
 *  mmi_em_audio_debug_info_init
 * DESCRIPTION
 *  set debug info at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_em_tdd_list_pre_hdlr(MMI_ID owner_gid, U16 sim_mod)
 {
     U32 i;
     U16 mode = 0x01;
     U8 list_of_menu_selected[MAX_EM_MOD_TDD_SELECTED_ITEMS] = {0};
 
     
     for (i = 0;i < MAX_EM_MOD_TDD_SELECTED_ITEMS; i++)
     {
         if (MMI_EM_TDD_CHK_MODE(mode, sim_mod))
         {
             list_of_menu_selected[i] = 1;
         }
         else
         {
             list_of_menu_selected[i] = 0;
         }
         mode = mode * 2;
     }
     cui_menu_set_checkbox_state(owner_gid, list_of_menu_selected);
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_stop_tdd_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // MYQUEUE Message;
    mmi_em_update_req_struct *em_start_req;
    U8 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

    for (i=0;i<EM_INFO_REQ_NUM;i++)
	{
        em_start_req->info_request[i] = EM_OFF;
    }

   // Message.oslDataPtr = (oslParaType*) em_start_req;
    //Message.oslPeerBuffPtr = NULL;
   // Message.oslSrcId = MOD_MMI;
   // Message.oslDestId = MOD_L4C;
   // OslMsgSendExtQueue(&Message);
   mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);

}


static MMI_BOOL mmi_em_tdd_mem_stop_hdlr(void)
{
     mmi_em_stop_tdd_req();
     mmi_em_tdd_release_context();
     return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_tdd_release_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_tdd)
	{
        MMI_EM_FREE(g_mmi_em_tdd);
        g_mmi_em_tdd = NULL;
        MMI_EM_UNREG_STOP_FUNC(mmi_em_tdd_mem_stop_hdlr);
        mmi_em_comm_mem_stop_hold();
	}
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_tdd_init_context(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_mmi_em_tdd == NULL)
     {
        MMI_EM_REG_STOP_FUNC(mmi_em_tdd_mem_stop_hdlr);  
        mmi_em_comm_mem_hold();
        g_mmi_em_tdd = MMI_EM_MALLOC(sizeof(mmi_em_tdd_struct));
     }
         
     if (g_mmi_em_tdd)
     {
         memset(g_mmi_em_tdd, 0, sizeof(mmi_em_tdd_struct));   //set 0

         g_mmi_em_tdd->mmi_urr_umts_srnc_id_info.srnc = -1;
         g_mmi_em_tdd->mmi_em_info.mnc[0] = 0xf;
         g_mmi_em_tdd->mmi_em_info.mnc[1] = 0xf;
         g_mmi_em_tdd->mmi_em_info.mnc[2] = 0xf;
         g_mmi_em_tdd->mmi_em_info.mcc[0] = 0xf;
         g_mmi_em_tdd->mmi_em_info.mcc[1] = 0xf;
         g_mmi_em_tdd->mmi_em_info.mcc[2] = 0xf;
     }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_tdd_init_mem(void)
{
     S32 i;
     U16 mode = 0x01;
     MMI_BOOL is_on = MMI_FALSE;

     for (i = 0; i < MAX_EM_MOD_TDD_SELECTED_ITEMS; i++)
     {
         if (MMI_EM_TDD_CHK_MODE(mode, g_mmi_em_tdd_mode_status))
         {
             is_on = MMI_TRUE;
             break;
         }
         mode = mode * 2;
     }

     if (is_on)
     {
         mmi_em_tdd_init_context();     //some item have been selected
     }
     else
     {
         mmi_em_tdd_release_context();  //no item be selected
     }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_display_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 page_count = 0;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_em_tdd)
    {
     return;
    }
    memset(g_mmi_em_tdd->mmi_screen_text, 0, sizeof(g_mmi_em_tdd->mmi_screen_text));

    g_index_screen_tdd = 0;
    for(i=0 ; i<MAX_TRACER_TDD_SCREEN_NUM; i++)
    {
        if(g_mmi_em_tdd->g_index_screen_show[i] == 1)    // set initial screen index
            break;
    }
    g_index_screen_tdd = i;

    MMI_ASSERT(page_count <= MAX_TRACER_TDD_SCREEN_NUM);

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
#endif

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_start_rsp(void *inMsg)
{
#if defined(__EM_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_update_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_tdd_IND1,6);
    if (rsp_p->result)
    {
        //EngineerModeStatusUpdate_3g(0, 0);
        //EngineerModeSuccessNotice(EM_UPDATE_SUCCESS_TEXT);
    }
    else
    {
       // EngineerModeErrorNotice(EM_UPDATE_ERROR_TEXT);
    }

#endif 
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_get_mm_em_info_value(mm_em_info_struct *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
        U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    for (i = 0; i < 3; i++)
    {
        g_mmi_em_tdd->mmi_em_info.mcc[i] = data_ptr->mcc[i];
        g_mmi_em_tdd->mmi_em_info.mnc[i] = data_ptr->mnc[i];
    }
    g_mmi_em_tdd->mmi_em_info.common_access_class = data_ptr->common_access_class;
    g_mmi_em_tdd->mmi_em_info.cs_access_class = data_ptr->cs_access_class;
    g_mmi_em_tdd->mmi_em_info.ps_access_class = data_ptr->ps_access_class;
    
     
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
static void mmi_em_get_urr_umts_srnc_id_value(urr_umts_srnc_id_struct *data_ptr)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    g_mmi_em_tdd->mmi_urr_umts_srnc_id_info.srnc = data_ptr->srnc;
 }

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_em_get_meme_em_info_umts_cell_status_value(meme_em_info_umts_cell_status_struct *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info.num_cells = data_ptr->num_cells;
    g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info.workingFreq= data_ptr->workingFreq;
    for (i = 0; i < 64; i++)
    {
        g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info.umts_cell_list[i] = data_ptr->umts_cell_list[i];    
    }
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
static void mmi_get_csce_em_serv_cell_s_status_ind_value(csce_em_serv_cell_s_status_ind_struct *data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     g_mmi_em_tdd->mmi_csce_em_serv_cell_s_status_ind_info.msg_len = data_ptr->msg_len;
     g_mmi_em_tdd->mmi_csce_em_serv_cell_s_status_ind_info.ref_count = data_ptr->ref_count;
     g_mmi_em_tdd->mmi_csce_em_serv_cell_s_status_ind_info.serv_cell = data_ptr->serv_cell;
 
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
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
static void mmi_em_get_slce_em_ps_data_rate_status_ind_value(slce_em_ps_data_rate_status_ind_struct * data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
        U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     for (i = 0; i < 8; i++)
     {    
        g_mmi_em_tdd->mmi_slce_em_ps_data_rate_status_ind_info.ps_data_status[i] = data_ptr->ps_data_status[i];
     }
     g_mmi_em_tdd->mmi_slce_em_ps_data_rate_status_ind_info.ps_number = data_ptr->ps_number;
}

 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
static void mmi_em_get_tcm_mmi_em_info_value(tcm_mmi_em_info_struct* data_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     int i,j,k;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     for (i = 0; i < GPRS_MAX_PDP_SUPPORT; i++)
     {
        g_mmi_em_tdd->mmi_tcm_mmi_em_info.data_speed[i] = data_ptr->data_speed[i];
     }

    g_mmi_em_tdd->mmi_tcm_mmi_em_info.num_of_valid_entries = data_ptr->num_of_valid_entries;
 
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
#endif


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static mmi_em_get_ul2_em_periodic_bler_report_ind_value(ul2_em_periodic_bler_report_ind* data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_tdd->mmi_ul2_em_periodic_bler_report_ind_info.num_trch = data_ptr->num_trch;
    for (i = 0; i < 8; i++)
    {
       g_mmi_em_tdd->mmi_ul2_em_periodic_bler_report_ind_info.TrCHBler[i] = data_ptr->TrCHBler[i];
    }   
}



static mmi_em_get_meme_em_info_gsm_cell_status_value(meme_em_info_gsm_cell_status_struct* data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_tdd->mmi_meme_em_info_gsm_cell_status_info.num_cells = data_ptr->num_cells;
    
    for (i = 0; i < 6; i++)
    {
       g_mmi_em_tdd->mmi_meme_em_info_gsm_cell_status_info.gsm_cell_list[i] = data_ptr->gsm_cell_list[i];
    }   
    
}




 /*****************************************************************************
  * FUNCTION
  *  mmi_em_rr_process_logs
  * DESCRIPTION
  *  
  * PARAMETERS
  *  em_info             [IN]        
  *  pdu_buff_ptr        [?]         
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_em_tdd_get_peer_buff_data(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U8 i;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_mmi_em_tdd)
     {
    
     switch (em_info)
     {
         case MM_EM_INFO:
         {
             mm_em_info_struct *data_ptr;
             kal_uint16 mm_pdu_len;

          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_1);
             
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (mm_em_info_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_mm_em_info_value((mm_em_info_struct*) data_ptr);
         }
         break;
             
         case URR_EM_INFO_UMTS_SRNC_ID_INFO:
         {
             urr_umts_srnc_id_struct *data_ptr;
             kal_uint16 mm_pdu_len;

         //    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_2);
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (urr_umts_srnc_id_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_urr_umts_srnc_id_value((urr_umts_srnc_id_struct*) data_ptr);
         }
         break;

         
         case MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO:  //ABM_ACT://
         {
             meme_em_info_umts_cell_status_struct *data_ptr;
             kal_uint16 mm_pdu_len;
     
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_3);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (meme_em_info_umts_cell_status_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_meme_em_info_umts_cell_status_value((meme_em_info_umts_cell_status_struct*) data_ptr);
         }
         break;
         case CSCE_EM_SERV_CELL_IND_STRUCT_INFO:  //ABM_ACT_ECC://
         {
             csce_em_serv_cell_s_status_ind_struct  *data_ptr;
             kal_uint16 mm_pdu_len;
     
          //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_4);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (csce_em_serv_cell_s_status_ind_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_get_csce_em_serv_cell_s_status_ind_value((csce_em_serv_cell_s_status_ind_struct*) data_ptr);            
         }
         break;
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
         case SLCE_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO:
         {
             slce_em_ps_data_rate_status_ind_struct *data_ptr;
             kal_uint16 mm_pdu_len;
     
         //    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_5);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (slce_em_ps_data_rate_status_ind_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_slce_em_ps_data_rate_status_ind_value((slce_em_ps_data_rate_status_ind_struct*) data_ptr);

             
         }
         break;
         case TCM_EM_CONTEXT_INFO:
         {
             tcm_mmi_em_info_struct *data_ptr;
             kal_uint16 mm_pdu_len;
     
        //     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_6);
     
             /* Get the pdu_ptr where MM peer msg will be stored for transmission */
             data_ptr = (tcm_mmi_em_info_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
             mmi_em_get_tcm_mmi_em_info_value((tcm_mmi_em_info_struct*) data_ptr);
             
             break;
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
         #endif

         case UL2_EM_3G_BLER_IND_STRUCT_INFO:
         {
            ul2_em_periodic_bler_report_ind *data_ptr;
            kal_uint16 mm_pdu_len;
    
        //    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_7);
    
            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (ul2_em_periodic_bler_report_ind*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_get_ul2_em_periodic_bler_report_ind_value((ul2_em_periodic_bler_report_ind*) data_ptr);
            
            break;
         }

         case MEME_EM_INFO_GSM_CELL_STATUS_STRUCT_INFO:
         {
            meme_em_info_gsm_cell_status_struct *data_ptr;
            kal_uint16 mm_pdu_len;

       //     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_8);
            
            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (meme_em_info_gsm_cell_status_struct*) get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_get_meme_em_info_gsm_cell_status_value((meme_em_info_gsm_cell_status_struct*) data_ptr);
            
            break;
            
         }

         default:
         //   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND_9);
             break;
     }
            
 

     }
     free_peer_buff(pdu_buff_ptr);

}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
void mmi_em_tdd_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsOnEMTracer_tdd = 0;
    is_idle = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_tracer_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cnt = 1,i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

   for (i = g_index_screen_tdd-1; i != g_index_screen_tdd; i=(( i - 1 ) + MAX_TRACER_TDD_SCREEN_NUM) % MAX_TRACER_TDD_SCREEN_NUM)
   {
      if(g_mmi_em_tdd->g_index_screen_show[i] == 1)
       {
           break;
       }
   }

   g_index_screen_tdd = i;
   
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
    #endif

    
    mmi_em_tdd_display_screen_n(g_index_screen_tdd);

}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_tracer_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        U8 cnt = 1;
        U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


     for (i = g_index_screen_tdd+1; i != g_index_screen_tdd; i = (i+1)%16)
     {
        if(g_mmi_em_tdd->g_index_screen_show[i] == 1)
        {
            break;
        }
     }

     g_index_screen_tdd = i;

    
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
    #endif
    
    mmi_em_tdd_display_screen_n(g_index_screen_tdd);

}
 
 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
void mmi_em_tdd_tracer_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_em_tdd_tracer_key_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_em_tdd_tracer_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_em_tdd_tracer_key_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_em_tdd_tracer_key_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);

}
 


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
* 
*****************************************************************************/
void mmi_em_tdd_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     stFontAttribute debug_print_font = {0, 0, 0, SMALL_FONT, 0, 0};
     color c;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     c = gui_color(color_r, color_g, color_b);

     UI_fill_rectangle(
         0,
         20,
         //MMI_STATUS_BAR_HEIGHT,
         MAIN_LCD_device_width-1,
         MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
         c);

     UI_set_font(&debug_print_font);
     c = gui_color(0, 0, 0);
     UI_set_text_color(c);
}
 
 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
void mmi_em_tdd_display_line_n(kal_int32 *text_pos, kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 temp_str[200]={0};
    kal_uint16 alignment_width = 0, alignment_height = 0;
    S32 width = 0, height = 0;
    
    stFontAttribute     MMI_small_font=         {   0,0,0,SMALL_FONT,0,1    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((char*) temp_str, (char*) str, sizeof(temp_str) / 2 - 1);
 //   Get_StringWidthHeight((U8*) temp_str, (S32*) & alignment_width, (S32*) & alignment_height);

    gui_set_font(&MMI_small_font);

    gui_measure_string((UI_string_type) temp_str, &width, &height);

    if ((S32)(*text_pos+height) < (S32)(MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT-1) )
    {
        gui_move_text_cursor(0, *text_pos);
        *text_pos += height;
        gui_print_text((UI_string_type) temp_str);
    }
}


/*-------------------------------------------------------------------*/
/*                       TDD screen(12)                              */
/*                                                                   */
/*-------------------------------------------------------------------*/


// Screen1----Selected PLMN
// Screen2----Access Class
// Screen3----SRNC ID
// Screen4----Serving Cell
// Screen5----UMTS Cell(1)
// Screen6----UMTS Cell(2)
// Screen7----UMTS Cell(3)
// Screen8----UMTS Cell(4)
// Screen9----GSM Cell
// Screen10----PDP Data Speed
// Screen11----PS Service Infro
// Screen12----Block Error Rate


/*SCREEN 1: Selected PLMN*/
kal_uint8 mmi_em_tdd_get_data_for_scrn1(
            kal_uint8 screen_num,
            mm_em_info_struct  *mmi_em_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page one */

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "Selected PLMN", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    if (mmi_em_info->mnc[0] == 0xf && mmi_em_info->mnc[1] == 0xf && mmi_em_info->mnc[2] == 0xf &&
        mmi_em_info->mcc[0] == 0xf && mmi_em_info->mcc[1] == 0xf && mmi_em_info->mcc[2] == 0xf)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],
             "%s","NA");
    }
    else if (mmi_em_info->mnc[2] != 0xF)
    {
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],
             "%x%x%x%x%x%x",mmi_em_info->mcc[0],mmi_em_info->mcc[1],mmi_em_info->mcc[2],
             mmi_em_info->mnc[0],mmi_em_info->mnc[1],mmi_em_info->mnc[2]);
    }
    else
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],
        "%x%x%x%x%x",mmi_em_info->mcc[0],mmi_em_info->mcc[1],mmi_em_info->mcc[2],
        mmi_em_info->mnc[0],mmi_em_info->mnc[1]);
    }


    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
}


/*SCREEN 2: Access Class*/
kal_uint8 mmi_em_tdd_get_data_for_scrn2(
            kal_uint8 screen_num,
            mm_em_info_struct  *mmi_em_info)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    char *str[4];

    str[0] = "NOT_BARRED";
    str[1] = "EMERGENCY_ONLY";
    str[2] = "ALL_BARRED";
    str[3] = "N/A";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 2 */
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "Access Class", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%s", "Common Access Class", str[mmi_em_info->common_access_class]);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%s", "CS Access Class", str[mmi_em_info->cs_access_class]);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%s", "PS Access Class", str[mmi_em_info->ps_access_class]);
    
    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}

/*SCREEN 3: SRNC ID*/
kal_uint8 mmi_em_tdd_get_data_for_scrn3(
            kal_uint8 screen_num,
            urr_umts_srnc_id_struct  *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 3 */
    
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "SRNC ID", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    if(data->srnc == 0xFFFF)
    {
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%s", "SRNC ID", "NA");
    }
    else
    {
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d", "SRNC ID", data->srnc);
    }

    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


/*SCREEN 4: Serving Cell*/
kal_uint8 mmi_em_tdd_get_data_for_scrn4(
            kal_uint8 screen_num,
            csce_em_serv_cell_s_status_ind_struct  *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    kal_uint8 index = 0;
    U8 *str_band[3];

    str_band[0] = "Band A";
    str_band[1] = "Band E";
    str_band[2] = "Band F";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 4 */
    
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "Serving Cell", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s   %s   %s   %s    %s     %s", "uarfcn",
            "psc","rscp","rssi","band","cell_id");        

    switch(data->serv_cell.band)
    {
        case 1:
            index = 0;
            break;
        case 5:
            index = 1;
            break;
        case 6:
            index = 2;
            break;
        default:
            index = 0;
            break;
    }

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%d  %d  %d  %d  %s    %x",
        data->serv_cell.uarfcn_DL, 
        data->serv_cell.psc,
        data->serv_cell.rscp/4096, 
        data->serv_cell.rssi, 
        str_band[index], 
        data->serv_cell.cell_identity);        



    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
    
}


U8 g_flag_utms = -1;
/*SCREEN 5: UTMS Cell(1)*/
kal_uint8 mmi_em_tdd_get_data_for_scrn5(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;
    char flag;
    U8 cnt = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 5 */
    
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "UMTS Cell(1)", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s : %d", "Working Freq" ,data->workingFreq);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s  %s  %s  %s       %s", "uarfcn",
    "psc","rscp","SC","tslscp");

   // sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s %s %s %s %s %s %s", "      ",
   // "   ","dbm ","db  ","dbm ","    ","       ");



   for (j=0; j<data->num_cells && cnt<16 ;j++)
   {
            if(data->umts_cell_list[j].isServingCell == KAL_TRUE)
            {
                flag = 'T';
            }
            else
            {
                flag = 'F';
            }
           sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%5d  %3d   %3d   %c   %d/%d/%d/%d/%d/%d",
               data->umts_cell_list[j].UARFCN,
               data->umts_cell_list[j].CELLPARAID,
               data->umts_cell_list[j].RSCP,
               flag,
               data->umts_cell_list[j].ISCP[0],
               data->umts_cell_list[j].ISCP[1],
               data->umts_cell_list[j].ISCP[2],
               data->umts_cell_list[j].ISCP[3],
               data->umts_cell_list[j].ISCP[4],
               data->umts_cell_list[j].ISCP[5]
            );
           cnt++;
       }
       
   
   
   if(j < data->num_cells)
   {
       g_flag_utms = j;
   }
   else
   {
       g_flag_utms = -1;
   }
   
   if(cnt == 0)
   {
       sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
   }


    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*SCREEN 6: UTMS Cell(2)*/
kal_uint8 mmi_em_tdd_get_data_for_scrn6(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;
    char flag;
    U8 cnt = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 6 */
    
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "UMTS Cell(2)", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    if(g_flag_utms == -1)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    else
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s : %d", "Working Freq" ,data->workingFreq);
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s  %s  %s  %s       %s", "uarfcn",
        "psc","rscp","SC","tslscp");


        for (j=g_flag_utms; j<data->num_cells && cnt<16 ;j++)
        {
            if(data->umts_cell_list[j].isServingCell == KAL_TRUE)
            {
                flag = 'T';
            }
            else
            {
                flag = 'F';
            }
            sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%5d  %3d   %3d   %c   %d/%d/%d/%d/%d/%d",
               data->umts_cell_list[j].UARFCN,
               data->umts_cell_list[j].CELLPARAID,
               data->umts_cell_list[j].RSCP,
                flag,
               data->umts_cell_list[j].ISCP[0],
               data->umts_cell_list[j].ISCP[1],
               data->umts_cell_list[j].ISCP[2],
               data->umts_cell_list[j].ISCP[3],
               data->umts_cell_list[j].ISCP[4],
               data->umts_cell_list[j].ISCP[5]
            );

           cnt++;
       }
    }
   
   if(j < data->num_cells)
   {
       g_flag_utms = j;
   }
   else
   {
       g_flag_utms = -1;
   }
   
   if(cnt == 0)
   {
       sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
   }

    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}

/*SCREEN 7: UTMS Cell(3)*/
kal_uint8 mmi_em_tdd_get_data_for_scrn7(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;
    char flag;
    U8 cnt = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 7 */
    
     sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "UMTS Cell(3)", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
     sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    
     if(g_flag_utms == -1)
     {
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
     }
     else
     {
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s : %d", "Working Freq" ,data->workingFreq);
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s  %s  %s  %s       %s", "uarfcn",
         "psc","rscp","SC","tslscp");

    
         for (j=g_flag_utms; j<data->num_cells && cnt<16 ;j++)
         {
             if(data->umts_cell_list[j].isServingCell == KAL_TRUE)
             {
                 flag = 'T';
             }
             else
             {
                 flag = 'F';
             }
             sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%5d  %3d   %3d   %c   %d/%d/%d/%d/%d/%d",
                data->umts_cell_list[j].UARFCN,
                data->umts_cell_list[j].CELLPARAID,
                data->umts_cell_list[j].RSCP,
                 flag,
                data->umts_cell_list[j].ISCP[0],
                data->umts_cell_list[j].ISCP[1],
                data->umts_cell_list[j].ISCP[2],
                data->umts_cell_list[j].ISCP[3],
                data->umts_cell_list[j].ISCP[4],
                data->umts_cell_list[j].ISCP[5]
             );

            cnt++;
        }
     }
    
    if(j < data->num_cells)
    {
        g_flag_utms = j;
    }
    else
    {
        g_flag_utms = -1;
    }
    
    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    
     g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
     MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
     return 1;

}

/*SCREEN 8: UTMS Cell(4)*/
kal_uint8 mmi_em_tdd_get_data_for_scrn8(
            kal_uint8 screen_num,
            meme_em_info_umts_cell_status_struct *data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;
    char flag;
    U8 cnt = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 8 */
    
     sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "UMTS Cell(4)", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
     sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    
     if(g_flag_utms == -1)
     {
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
     }
     else
     {
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s : %d", "Working Freq" ,data->workingFreq);
         sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s  %s  %s  %s       %s", "uarfcn",
         "psc","rscp","SC","tslscp");

    
         for (j=g_flag_utms; j<data->num_cells && cnt<16 ;j++)
         {
             if(data->umts_cell_list[j].isServingCell == KAL_TRUE)
             {
                 flag = 'T';
             }
             else
             {
                 flag = 'F';
             }
             sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%5d  %3d   %3d   %c   %d/%d/%d/%d/%d/%d",
                data->umts_cell_list[j].UARFCN,
                data->umts_cell_list[j].CELLPARAID,
                data->umts_cell_list[j].RSCP,
                 flag,
                data->umts_cell_list[j].ISCP[0],
                data->umts_cell_list[j].ISCP[1],
                data->umts_cell_list[j].ISCP[2],
                data->umts_cell_list[j].ISCP[3],
                data->umts_cell_list[j].ISCP[4],
                data->umts_cell_list[j].ISCP[5]
             );

            cnt++;
        }
     }
    
    if(j < data->num_cells)
    {
        g_flag_utms = j;
    }
    else
    {
        g_flag_utms = -1;
    }
    
    if(cnt == 0)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    
     g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
     MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
     return 1;

}

/*SCREEN 9: GSM Info*/
kal_uint8 mmi_em_tdd_get_data_for_scrn9(
            kal_uint8 screen_num,
            meme_em_info_gsm_cell_status_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j,  cnt = 0;
    U8 str_band_index = 6;

    char flag;
    U8 *str_band[10];

    str_band[0] = "E-GSM 900";
    str_band[1] = "DCS 1800 ";
    str_band[2] = "PCS 1900 ";
    str_band[3] = "GSM 450  ";
    str_band[4] = "GSM 480  ";
    str_band[5] = "GSM 850  ";
    str_band[6] = "XXX      ";

    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 13 */


    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "GSM Info", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s          %s  %s  %s  %s", "band",
            "arfcn","bsic","rssi","bsicverified");

     for (j=0; j<data->num_cells && cnt<6 ;j++)
         {
             if(data->gsm_cell_list[j].verified == KAL_TRUE)
             {
                 flag = 'T';
             }
             else
             {
                 flag = 'F';
             }
            /* For showing band  */
             if(data->gsm_cell_list[j].arfcn<=885 && data->gsm_cell_list[j].arfcn>=512 )
             {
                if(data->gsm_cell_list[j].frequency_band == 0)
                  str_band_index = 1;
                else
                    str_band_index = 2;
             }
             else if((data->gsm_cell_list[j].arfcn<=124 && data->gsm_cell_list[j].arfcn>=0)
                || (data->gsm_cell_list[j].arfcn<=1023 && data->gsm_cell_list[j].arfcn>=975))
             {
                str_band_index = 0;
             }
             else if(data->gsm_cell_list[j].arfcn<=293 && data->gsm_cell_list[j].arfcn>=259)
             {
                str_band_index = 3;
             }
             else if(data->gsm_cell_list[j].arfcn<=340 && data->gsm_cell_list[j].arfcn>=306)
             {
                str_band_index = 4;
             }
             else if(data->gsm_cell_list[j].arfcn<=251 && data->gsm_cell_list[j].arfcn>=128)
             {
                str_band_index = 5;
             }
             else
             {
                str_band_index = 6;
             }

           /* end */
           
            sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s   %3d     %3d     %3d     %c",
                str_band[str_band_index],
                data->gsm_cell_list[j].arfcn,
                data->gsm_cell_list[j].bsic,
                data->gsm_cell_list[j].rssi,
                flag);
            cnt++;
        }
    
    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;     
}



/*SCREEN 10: PDP Data Speed*/
kal_uint8 mmi_em_tdd_get_data_for_scrn10(
            kal_uint8 screen_num,
            tcm_mmi_em_info_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j, flag = 0;

    char *str[7];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 13 */

    str[0] = "NONE";
    str[1] = "GPRS";
    str[2] = "EDGE";
    str[3] = "UMTS";
    str[4] = "HSDPA";
    str[5] = "HSUPA";
    str[6] = "HSDPA/HSUPA";

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "PDP Data Speed", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");

    for (j = 0; j < data->num_of_valid_entries; j++)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s: %d ","NSAPI", data->data_speed[j].nsapi);
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s: %s ","Speed", str[data->data_speed[j].data_speed_value]);
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"------");
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    

    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*SCREEN 11: PS Service Information*/
kal_uint8 mmi_em_tdd_get_data_for_scrn11(
            kal_uint8 screen_num,
            slce_em_ps_data_rate_status_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j, flag = 0;

    char *str[7];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 11 */

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "PS Service Information", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s %s %s %s ","RAB_ID", "RB_ID", "UL_RATE", "DL_RATE");
    
    for (j = 0; j < data->ps_number; j++)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], " %d            %d          %d          %d", data->ps_data_status[j].RAB_ID,data->ps_data_status[j].RB_ID,
                data->ps_data_status[j].UL_rate, data->ps_data_status[j].DL_rate);
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    
    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*SCREEN 12: Block Error Rate */
kal_uint8 mmi_em_tdd_get_data_for_scrn12(
            kal_uint8 screen_num,
            ul2_em_periodic_bler_report_ind  *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j, flag = 0;

    char *str[7];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page 12 */

    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s:%d/%d", "Block Error Rate", screen_num + 1, MAX_TRACER_TDD_SCREEN_NUM);
    sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "-------------------------");
    
    
    for (j = 0; j < data->num_trch; j++)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++], "%s: %d, %f%c",
     "Transport Channel ID",data->TrCHBler[j].TrCHId, (float)(data->TrCHBler[j].BadCRC) / (float)(data->TrCHBler[j].TotalCRC)*100.0,'%');
    }

    if(j == 0)
    {
        sprintf((char*)g_mmi_em_tdd->mmi_screen_text[i++],"%s", "No signal...");
    }
    
    g_mmi_em_tdd->mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;    
    
}

/*-------------------------------------------------------------------*/
/*                         SCREEN END                                */
/*                                                                   */
/*-------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
kal_uint8 mmi_show_tdd_screen_text_log(int screen_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 screen_num_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     switch (screen_number)
     {
         case 0:
             screen_num_id = mmi_em_tdd_get_data_for_scrn1((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_em_info);
             break;
         case 1:
             screen_num_id = mmi_em_tdd_get_data_for_scrn2((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_em_info);
             break;
         case 2:
             screen_num_id = mmi_em_tdd_get_data_for_scrn3((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_urr_umts_srnc_id_info);
             break;
         case 3:
             screen_num_id = mmi_em_tdd_get_data_for_scrn4((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_csce_em_serv_cell_s_status_ind_info);
             break;
         case 4:
             screen_num_id = mmi_em_tdd_get_data_for_scrn5((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info);
             break;
         case 5:
             screen_num_id = mmi_em_tdd_get_data_for_scrn6((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info);
             break;
         case 6:
             screen_num_id = mmi_em_tdd_get_data_for_scrn7((kal_uint8)screen_number, &g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info);
             break;
         case 7:
             screen_num_id = mmi_em_tdd_get_data_for_scrn8((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_meme_em_info_umts_cell_status_info);
             break;

        case 8:
            screen_num_id = mmi_em_tdd_get_data_for_scrn9((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_meme_em_info_gsm_cell_status_info);
            break;
        case 9:
            screen_num_id = mmi_em_tdd_get_data_for_scrn10((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_tcm_mmi_em_info);
            break;
        case 10:
             screen_num_id = mmi_em_tdd_get_data_for_scrn11((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_slce_em_ps_data_rate_status_ind_info);
             break;
        case 11:
             screen_num_id = mmi_em_tdd_get_data_for_scrn12((kal_uint8) screen_number, &g_mmi_em_tdd->mmi_ul2_em_periodic_bler_report_ind_info);
             break;
             

         default:
             break;

    }
    return screen_num_id;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_display_screen_n(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_pos = 20;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(screen_num < MAX_TRACER_TDD_SCREEN_NUM);

    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    mmi_em_tdd_tracer_screen_color_init(255, 255, 255);

    mmi_show_tdd_screen_text_log(screen_num);

    

    for (i = 0; i < MAX_TRACER_LINE_NUM; i++)
    {
        if (g_mmi_em_tdd->mmi_screen_text[i][0] == '\0')
        {
            break;
        }
        mmi_em_tdd_display_line_n(&text_pos, g_mmi_em_tdd->mmi_screen_text[i]);
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}

/*****************************************************************************
* FUNCTION
*  mmi_em_tdd_is_in_call
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_em_tdd_is_in_call(void)
{
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, 
					SRV_UCM_CALL_TYPE_ALL , NULL) > 0)																				/*Have calling*/
   		 { //SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE
        	if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, 
									SRV_UCM_VIDEO_CALL_TYPE_ALL , NULL) > 0)															/*If on VT call screen*/
            return MMI_FALSE;
          else
            return MMI_TRUE;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_em_show_screen
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_tdd_show_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 current_screen;

    MMI_ID gourp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI,"[EM TDD]Enter show screen");
    



#ifndef __COSMOS_MMI__
    if (mmi_idle_is_active() || mmi_em_tdd_is_in_call() || is_idle)
#else
    if (vapp_launcher_is_active() || mmi_em_tdd_is_in_call() || is_idle)
#endif
    {
    	/* Enter new screen */
    if (gIsOnEMTracer_tdd == 0)
    {
    		gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
		                   GRP_ID_AUTO_GEN, NULL, NULL);
		                   
		    mmi_frm_group_enter(gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
		                   	                   
			if (mmi_frm_scrn_enter(gourp_id,SCR_ID_EM_TDD,mmi_em_tdd_exit_screen,NULL,MMI_FRM_FULL_SCRN) != MMI_TRUE)
				{
					 kal_prompt_trace(MOD_MMI,"[EM TDD]!= MMI_TRUE");
					return;
				}

				is_idle = MMI_TRUE;
    }

    	/* Show category */
    	kal_prompt_trace(MOD_MMI,"[EM TDD]on idle!!");
     if (gIsOnEMTracer_tdd == 0) 
     {
         ShowCategory7Screen(0, 0, STR_ID_EM_3G_INFO_NEXT, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
        //STR_GLOBAL_BACK, IMG_GLOBAL_BACK
         SetLeftSoftkeyFunction(mmi_em_tdd_tracer_key_down,KEY_EVENT_UP);
         SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
     }

     gIsOnEMTracer_tdd = 1;

     /* register key handler */
     mmi_em_tdd_tracer_key();
     mmi_em_tdd_display_screen_n(g_index_screen_tdd);

    }
    
 /*   
    else
        if (gIsOnEMTracer_tdd == 0)
    {
    	kal_prompt_trace(MOD_MMI,"[EM TDD]Close screen");
       mmi_frm_scrn_close_active_id();
       mmi_frm_group_close(gourp_id);
    }
    */

}

 /*****************************************************************************
  * FUNCTION
  * 
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  *  
  *****************************************************************************/
void mmi_em_tdd_parsing_data(void *info)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;
     

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

    // MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_tdd_IND1,5);
     
     mmi_em_tdd_get_peer_buff_data(msg->em_info, msg->info);
     

     /* display the trace information on screen */

     if (g_mmi_em_tdd != NULL)
     {
        mmi_em_tdd_show_screen();
     }
     

}
 
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/ 
static void mmi_em_tdd_get_list_states(U8 *list_of_states, U8 *list_of_menu_selected)
{
    U8 i;
    for (i = 0; i < MAX_EM_MODE; i++)
    {
       list_of_states[i] = EM_OFF; 
    }
    
    for (i = 0; i < MAX_EM_MOD_TDD_SELECTED_ITEMS; i++)
    {
        if(list_of_menu_selected[i] == 1)
        {
            if(mmi_em_menu_em_info_map_tab[i].num_relevant == 1)
                list_of_states[mmi_em_menu_em_info_map_tab[i].index_1] = EM_ON;
            else if(mmi_em_menu_em_info_map_tab[i].num_relevant == 2)
                {
                    list_of_states[mmi_em_menu_em_info_map_tab[i].index_1] = EM_ON;
                    list_of_states[mmi_em_menu_em_info_map_tab[i].index_2] = EM_ON;
                }
        }
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_get_menu_selected(U8 *list_of_selected, U16 *mode_status)
{
     U32 i;
     U16 mode = 0x01;
     
     for (i = 0;i < MAX_EM_MOD_TDD_SELECTED_ITEMS; i++)
     {
         if (MMI_EM_TDD_CHK_MODE(mode, *mode_status))
         {
             
             list_of_selected[i] = 1;
         }
         else
         {
             list_of_selected[i] = 0;
         }
         mode = mode * 2;
     } 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_trace_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_tdd != NULL)
    {
       // SetProtocolEventHandler((PsIntFuncPtr)mmi_em_tdd_parsing_data,MSG_ID_MMI_EM_STATUS_IND);
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, (PsIntFuncPtr)mmi_em_tdd_parsing_data, MMI_FALSE);
    }
    else 
    {
       // ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);
        mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, NULL);
    }
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_UPDATE_RSP, (PsIntFuncPtr)mmi_em_tdd_start_rsp, MMI_FALSE);
 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_tdd_send_start_req(module_type mod_id)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
//     MYQUEUE Message;
     mmi_em_update_req_struct *em_start_req;
     U8 i=0;
     U8 list_of_menu_selected[MAX_EM_MOD_TDD_SELECTED_ITEMS] = {0};
     U8 list_of_states[MAX_EM_MODE] = {0};
     U8 cur_list_states[MAX_EM_MODE] = {0};

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_em_tdd_get_menu_selected(list_of_menu_selected, &g_mmi_em_tdd_mode_status);
     mmi_em_tdd_get_list_states(list_of_states, list_of_menu_selected);///////////////////////////
     
    // mmi_em_tdd_show_screen();//??????????

    // Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
     em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

     for (i=0;i<EM_INFO_REQ_NUM;i++)
     {
         em_start_req->info_request[i] = EM_OFF;
     }

     if (em_tdd_entry == 0)
     {
        /* it is the first to send em info update */
         for (i = 0;i < MAX_EM_MODE; i++)
         {
             if (list_of_states[i] != EM_OFF)
             {
                 em_start_req->info_request[em_tdd_item_table [i]] = list_of_states[i];
             }
         }
         g_mmi_em_tdd_cur_mode = g_mmi_em_tdd_mode_status;
     }
     else
     {
         mmi_em_tdd_get_menu_selected(list_of_menu_selected, &g_mmi_em_tdd_cur_mode);
         mmi_em_tdd_get_list_states(cur_list_states, list_of_menu_selected);
         /* it is the first to send em info update */
         for (i=0;i<MAX_EM_MODE;i++)
         {
             if (cur_list_states[i] == list_of_states[i])
             {
                 em_start_req->info_request[em_tdd_item_table [i]] = EM_NC;
             }
             else
             {
                 em_start_req->info_request[em_tdd_item_table [i]] = list_of_states[i];       
             }
         }
         g_mmi_em_tdd_cur_mode = g_mmi_em_tdd_mode_status;
     }
     em_tdd_entry++;

    // Message.oslDataPtr = (oslParaType*) em_start_req;
    // Message.oslPeerBuffPtr = NULL;
    // Message.oslSrcId = MOD_MMI;
    // Message.oslDestId = MOD_L4C;
    // OslMsgSendExtQueue(&Message);
    
    mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_EM_UPDATE_REQ,(oslParaType*)em_start_req,NULL);

   //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_tdd_IND1,4);

}

 /*****************************************************************************
  * FUNCTION
  *  
  * DESCRIPTION
  *  
  * PARAMETERS
  *  
  * RETURNS
  * 
  *****************************************************************************/
 void EngineerModeStartReq_tdd(U32 mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_tdd_IND1,3);
    mmi_em_tdd_display_init();
    mmi_em_tdd_trace_on_ind(); 
    mmi_em_tdd_send_start_req(mod_id);
}
 
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_em_set_show_screen_index_tdd()
{
    U8 i,j;
    U8 list_of_menu_selected[MAX_EM_MOD_TDD_SELECTED_ITEMS];

    if(!g_mmi_em_tdd)
    {
        return;
    }

    mmi_em_tdd_get_menu_selected(list_of_menu_selected, &g_mmi_em_tdd_mode_status); 


    for (i=0,j=0; i<MAX_TRACER_TDD_SCREEN_NUM; i++,j++)  //
    {
        if(list_of_menu_selected[j] == 1)
        {
            g_mmi_em_tdd->g_index_screen_show[i] = 1;
            if(j == 4)
            {
               g_mmi_em_tdd->g_index_screen_show[4] = 1; 
               g_mmi_em_tdd->g_index_screen_show[5] = 1; 
               g_mmi_em_tdd->g_index_screen_show[6] = 1; 
               g_mmi_em_tdd->g_index_screen_show[7] = 1; 
               i = 7;   
            }
            
        }
        else
        {
            g_mmi_em_tdd->g_index_screen_show[i] = 0;
            if(j == 4)
            {
               g_mmi_em_tdd->g_index_screen_show[4] = 0; 
               g_mmi_em_tdd->g_index_screen_show[5] = 0; 
               g_mmi_em_tdd->g_index_screen_show[6] = 0; 
               g_mmi_em_tdd->g_index_screen_show[7] = 0; 
               i = 7;   
            }
        }
    }
           
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void SendEmStartMsg_TDD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_tdd_init_mem();
    mmi_em_set_show_screen_index_tdd();
    EngineerModeStartReq_tdd(MOD_AS);
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_em_tdd_update_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    MMI_ID *menu_id = (MMI_ID*) evt->user_data;

    
  //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_TDD_IND1,2);

	 
    switch (alert->result)
    {
    case MMI_ALERT_CNFM_YES:
    	SendEmStartMsg_TDD();
    	break;
    case MMI_ALERT_CNFM_NO:
        g_mmi_em_tdd_mode_status = g_mmi_em_tdd_mode_status_history;
    	break;
	default:
		break;
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, (PsIntFuncPtr)mmi_em_tdd_parsing_data, MMI_FALSE);
    
    

    return MMI_RET_OK;
}
 

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_tdd_list_exit_hdlr(cui_menu_event_struct *evt)
{
	mmi_confirm_property_struct arg;

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_em_tdd_update_proc;
    arg.parent_id = g_gourp_id;
    arg.f_auto_map_empty_softkey =  MMI_FALSE;
	arg.user_tag = (void *)evt->sender_id;

    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, NULL);
    mmi_confirm_display((WCHAR *)get_string(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &arg);
	cui_menu_close(evt->sender_id);
}

 /*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
 static void mmi_em_tdd_list_hdlr(cui_menu_event_struct *evt , U16 *sim_mode)
 {
     U32 i;
     U16 mode = 0x01;
     U8 list_of_menu_selected[MAX_EM_MOD_TDD_SELECTED_ITEMS] = {0};
 
     g_mmi_em_tdd_mode_status_history = g_mmi_em_tdd_mode_status;  /*save history record*/
 
     cui_menu_get_checkbox_state(evt->sender_id, list_of_menu_selected);
     for (i = 0;i < MAX_EM_MOD_TDD_SELECTED_ITEMS; i++)
     {
         if (1 == list_of_menu_selected[i])
         {
             MMI_EM_TDD_SET_ON(mode, *sim_mode);  //Set on status to g_mmi_em_tdd_mode_status
         }
         
         if (0 == list_of_menu_selected[i])
         {
             MMI_EM_TDD_SET_OFF(mode, *sim_mode); //Set off status
         }
         mode = mode * 2;
     }

  //  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_tdd_IND1,1);
    mmi_em_tdd_list_exit_hdlr(evt);
 }
 

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_em_tdd_checkbox_list_proc(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
	    case EVT_ID_CUI_MENU_LIST_ENTRY:
            if(MENU_ID_EM_TDD == menu_evt->parent_menu_id)
            {
                mmi_em_tdd_list_pre_hdlr(menu_evt->sender_id,g_mmi_em_tdd_mode_status);                
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_em_tdd_list_hdlr(menu_evt,&g_mmi_em_tdd_mode_status);		//set bit mask
            break;
        default:
            break;
			
	}
	return MMI_RET_OK;
}



static void mmi_em_enter_tdd_mainmenu()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
		                   GRP_ID_AUTO_GEN, mmi_em_tdd_checkbox_list_proc, NULL);
	mmi_frm_group_enter(g_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
	menu_id = cui_menu_create(g_gourp_id, CUI_MENU_SRC_TYPE_RESOURCE, CUI_MENU_TYPE_APPSUB,
		                    MENU_ID_EM_TDD,
		                    MMI_TRUE, NULL);
	cui_menu_run(menu_id);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_audio_debug_info_init
 * DESCRIPTION
 *  set debug info at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_em_enter_tdd(cui_menu_event_struct *evt)
{
    //SetLeftSoftkeyFunction(mmi_em_enter_tdd_mainmenu,KEY_EVENT_UP);

	if (evt->highlighted_menu_id == MENU_ID_EM_TDD)
	{
             mmi_em_enter_tdd_mainmenu();
        }
}

#endif

#endif /*__MMI_EM_NW_TDD_NETWORK_INFO__*/


