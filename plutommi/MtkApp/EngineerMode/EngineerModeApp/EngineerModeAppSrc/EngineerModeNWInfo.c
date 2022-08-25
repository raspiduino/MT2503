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
 *  EngineerModeNWInfo.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 * 
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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


#ifdef __MMI_EM_NW_NETWORK_INFO__
#include "ProtocolEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "PixcomFontEngine.h"
#include "MainMenuDef.h"
#include "CustomCfg.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"
#include "FactoryModeProt.h"
#include "AlarmDef.h"
#include "GpioSrvGprot.h"
#include "DateTimeGprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"
#include "EngineerModePCSNetwork.h"

#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "stack_config.h"

#include "idleappdef.h"
#include "EngineerModeUtil.h"
#include "CommonScreens.h"

#ifdef __MODEM_EM_MODE__
#include "FileMgr.h"
#include "ProfilesSrvGprot.h"

#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#endif /* #ifdef __MODEM_EM_MODE__ */

#if defined(__MMI_UCM__)
#include "UCMResDef.h"
#endif

#include "NetworkSetupGProt.h"

#ifdef __ENHANCED_UMTS_RF_CUSTOMIZATION__
#include "ul1d_rf_general.h"
#endif

#include "mmi_frm_utility_gprot.h"
#include "wgui_categories_util.h"
#include "PixcomFontEngine.h"
#include "AlertScreen.h"
#include "EngineerModeCommMem.h"

#include "IdleGprot.h"

#include "EngineerModeAppResDef.h"
#include "EngineerMode.h"
#include "mmi_rp_app_engineermode1_def.h"


#include "em_public_struct.h"

#ifdef __COSMOS_MMI__
#include "vapp_launcher_gprot.h"
#endif

/***
 * Define
 ***/
#define MAX_EM_MODE (sizeof(em_nw_info_event_index_table )/sizeof(U8))

#define MMI_EM_NW_CHK_MODE(_mode, _record)     ((_mode) & (_record))                  /* 0 EM_ON, 1 EM_OFF */
#define MMI_EM_NW_SET_ON(_mode, _record)       (_record) = (_mode) | (_record)        /* checkbox ON == 00 */
#define MMI_EM_NW_SET_OFF(_mode, _record)      (_record) = (~(_mode)) & (_record)     /* checkbox OFF == 01 */

#define MMI_EM_NW_INFO_SET_ON(_mode, _record)  (_record) = (_mode) | (_record)
#define MMI_EM_NW_INFO_SET_OFF(_mode, _record) (_record) = (~(_mode)) & (_record)
#define MMI_EM_NW_INFO_CHK(_mode, _record)     ((_mode) & (_record))? (1) : (0)

#define MAX_TRACER_SCREEN_NUM (17)
#define MAX_TRACER_LINE_NUM   (20)

#define TEXT_FORMAT_1   "%s:%2d%2d%2d"
#define TEXT_FORMAT_2   "%s:%d"
#define TEXT_FORMAT_3   "%4d %4d %4d %4d %4d %4d"
#define TEXT_FORMAT_4   "%s:%2d %2d"
#define TEXT_FORMAT_5   "%s:%2d%2d%2s"
#define TEXT_FORMAT_6   "%4s %4s %4s %4s %4s %4s"
#define TEXT_FORMAT_7   "%4s %4s %3s %3s %1s"
#define TEXT_FORMAT_8   "%4d %4d %3d %3d %1d"
#define TEXT_FORMAT_9   "%s:%d/%d"
#define TEXT_FORMAT_10  "%s:%2s"
#define TEXT_FORMAT_11  "%4d %4d %3s %3s %1d"
#define TEXT_FORMAT_12  "%s:%s"
#define TEXT_FORMAT_13  "%4s %4s %3s %3s %1s"
#define TEXT_FORMAT_14  "%s:%d  %s:%d"
#define TEXT_FORMAT_15  "%s:%s  %s:%s"
#define TEXT_FORMAT_16  "%s:%d %s:%d %s:%d"
#define TEXT_FORMAT_17  "%s:%s %s:%s %s:%s"
#define TEXT_FORMAT_18  "%d %d %d %d %d %d %d %d"
#define TEXT_FORMAT_19  "%s"
#define TEXT_FORMAT_20  "%s: %d/%d"
#define TEXT_FORMAT_21  "%s: %x%x%x%x%x%x %x%x%x%x%x%x"
#define TEXT_FORMAT_22  "%s: %s %x%x%x%x%x%x"
#define TEXT_FORMAT_23  "%s: %x%x%x%x%x%x %s"
#define TEXT_FORMAT_24  "%s: %s %s"
#define TEXT_FORMAT_25  "%s: %x%x%x%x%x%x"
#define TEXT_FORMAT_26  "%s: 0x%x"
#define TEXT_FORMAT_27  "%s: %d %d %d %d"
#define TEXT_FORMAT_28  "%s:%2s %s:%d"
#define TEXT_FORMAT_29  "%s:%d %s:%2s"
#define TEXT_FORMAT_30  "%s:%d %s:0x%x %s:%d"
#define TEXT_FORMAT_31  "%s:%d %s:0x%x"
#define TEXT_FORMAT_32  "%s%d%s%d: "
#define TEXT_FORMAT_33  "%d "
#define TEXT_FORMAT_34  "%s: %s %s %s "
#define TEXT_FORMAT_35  "%s%d: "
#define MAX_CHANNEL_TYPE_COUNT (sizeof(rr_channel_type_name)/sizeof(rr_channel_type_name[0]) )

/************************************/
/********  Local Variables **********/
/************************************/
typedef struct
{
    U8 index_screen;
    U8 mmi_screen_text[MAX_TRACER_LINE_NUM][60];
    U8 num_of_carriers;

    rr_em_cell_select_para_info_struct mmi_rr_em_cell_select_para_info;
    rr_em_channel_descr_info_struct mmi_rr_em_channel_descr_info;
    rr_em_ctrl_channel_descr_info_struct mmi_rr_em_ctrl_channel_descr_info;
    rr_em_rach_ctrl_para_info_struct mmi_rr_em_rach_ctrl_para_info;
    rr_em_lai_info_struct mmi_rr_em_lai_info;
    rr_em_radio_link_counter_info_struct mmi_rr_em_radio_link_counter_info;
    rr_em_measurement_report_info_struct mmi_rr_em_measurement_report_info;
    rr_em_channel_descr_info_struct channel_descr_info;
    mmrr_plmn_info_struct mmi_rr_em_plmn_info;
    rr_em_gprs_general_info_struct mmi_rr_em_gprs_general_info;
    rr_em_si2q_info_struct mmi_rr_em_si2q_info;
    rr_em_mi_info_struct mmi_rr_em_mi_info;
    rr_em_tbf_status_struct mmi_rr_em_tbf_info;
    rr_em_blk_info_struct mmi_rr_em_blk_info;

    rr_em_ca_list_info_struct mmi_rr_em_ca_list_info;
} mmi_em_network_info_struct;

typedef U8 (* MMI_EM_NW_INFO_SHOW_TEXT_LOG_CALLBACK)(U8 scr_num, U8 **mmi_screen_text);

typedef U8 (*arry_plum)[][6];

/************************************/
/********  Global Variables *********/
/************************************/
/* below string table is to follow the em_struct.h to display */
static const char *const rr_channel_type_name[] =
{
    "PBCCH", "PRACH", "PCCCH", "PDTCH", "PACCH", "BCCH",
    "N_BCCH", "E_BCCH", "CCCH", "PAG_CH", "RACH", "SDCCH4",
    "SDCCH4", "SDCCH4", "SDCCH4", "SDCCH8", "SDCCH8", "SDCCH8",
    "SDCCH8", "SDCCH8", "SDCCH8", "SDCCH8", "SDCCH8", "SDCCH",
    "SACCH",  "FACCH",  "TCH_EF", "TCH_F",  "TCH_H",  "TCH_H",
    "TCH_H",  "CBCH",   "PPCH"
};

static const char *const rr_cipher_algo_name[] =
{
    "OFF",
    "A51",
    "A52"
};

static const char *const rr_downlink_signal_fail_name[] =
{
    "DSF",
    "RLF"
};

static const char *const amr_info_bitwise_name[] =
{
    "AFS1220",  /* bit 0 */
    "AFS1020",  /* bit 1 */
    "AFS795",   /* bit 2 */
    "AFS740",   /* bit 3 */
    "AFS670",   /* bit 4 */
    "AFS590",   /* bit 5 */
    "AFS515",   /* bit 6 */
    "AFS475",   /* bit 7 */
    "AHS795",   /* bit 8 */
    "AHS740",   /* bit 9 */
    "AHS670",   /* bit 10 */
    "AHS590",   /* bit 11 */
    "AHS515",   /* bit 12 */
    "AHS475",   /* bit 13 */
    "X",        /* bit 14 */
    "X"         /* bit 15 */
};

static const U8 em_nw_info_event_index_table [] =
{
    RR_EM_CELL_SELECT_PARA_INFO,   /* 1 */
    RR_EM_CHANNEL_DESCR_INFO,      /* 2 */
    RR_EM_CTRL_CHANNEL_DESCR_INFO, /* 3 */
    RR_EM_RACH_CTRL_PARA_INFO,     /* 4 */
    RR_EM_LAI_INFO,                /* 5 */
    RR_EM_RADIO_LINK_COUNTER_INFO, /* 6 */
    RR_EM_MEASUREMENT_REPORT_INFO, /* 7 */
    CC_EM_CHANNEL_INFO,               /* 8 */
    CC_EM_CALL_INFO,               /* 9 */
    RR_EM_CA_LIST_INFO,            /* 10 */
    MMRR_EM_PLMN_INFO_STRUCT_INFO, /* 11 */
    RR_EM_GPRS_GENERAL_INFO,       /* 12 */
    RR_EM_SI2Q_INFO_STRUCT_INFO,   /* 13 */
    RR_EM_TBF_INFO,                /* 14 */
    RR_EM_BLK_INFO                 /* 15 */
};

static const MMI_EM_NW_INFO_SHOW_TEXT_LOG_CALLBACK g_mmi_em_nw_info_show_log_callback[] = 
{
    mmi_em_rr_measurement_report_info_logs,
    mmi_em_rr_measurement_report_info_logs_2,
    mmi_em_rr_cell_select_logs,
    mmi_em_rr_channel_descr_logs,
    mmi_em_rr_ctrl_channel_descr_logs,
    mmi_em_rr_rach_ctrl_para_info_logs,
    mmi_em_rr_lai_info_logs,
    mmi_em_rr_radio_link_counter_info_logs,
    mmi_em_rr_c1_c2_logs,
    mmi_em_rr_c1_c2_logs_2,
    mmi_em_rr_plmn_info_logs,
    mmi_em_rr_gprs_general_info_logs,
    mmi_em_rr_si2q_mi_info_logs,
    mmi_em_rr_tbf_info_logs,
    mmi_em_rr_blk_info_logs,
    mmi_em_rr_ca_list_info_logs,
    mmi_em_rr_ca_list_info_logs_2
};

static mmi_em_network_info_struct *g_mmi_em_network_info;

/*
   comm_info:
   gIsOnEMTracer 0x01
   currentEmCommand 0x02 EM_NONE/EM_START/EM_STOP
   
   nw_info_flag:
   nw_info_flag sim idx:     0001 1100
   nw info flag old sim idx: 1110 0000
*/

U8  g_em_nw_comm_info = (0XF0);

#define MMI_EM_NW_INFO_IS_TRACE     (0x01)//(00000001)
#define MMI_EM_NW_INFO_CUR_EM_COMM  (0x02)//(00000010)
#define MMI_EM_NW_INFO_SIM_IDX      (0x0C)//(00001100)
#define MMI_EM_NW_INFO_OLD_SIM_IDX  (0x30)//(00110000)

#define MMI_EM_NW_INFO_IS_TRACE_OFFSET    (0)
#define MMI_EM_NW_INFO_CUR_EM_COMM_OFFSET (0 + 1)
#define MMI_EM_NW_INFO_SIM_IDX_OFFSET     (0 + 1 + 1)
#define MMI_EM_NW_INFO_OLD_SIM_IDX_OFFSET (0 + 1 + 1 + 2)

#define MMI_EM_NW_GET_INFO(_offset, _bits) (g_em_nw_comm_info & (_bits)) >> (_offset);

#define MMI_EM_NW_SET_INFO(_offset, _bits, _data) do { \
                g_em_nw_comm_info = (((U32)(~_bits)) & g_em_nw_comm_info) | ((_data) << (_offset)); \
            } while(0)


static U8 em_nw_info_entry = 0;

U16 g_mmi_em_nw_mode_status[MMI_SIM_TOTAL] = {0};
U16 g_mmi_em_nw_cur_mode[MMI_SIM_TOTAL] = {0};

U16 g_mmi_em_nw_mode_status_history = 0xFFFF;

static const char* const g_mmi_em_nw_info_ca = "CA";
static const char* const g_mmi_em_nw_info_str_icm  = "icm";
static const char* const NA_SYMBOL = "X";
static const char* const g_mmi_em_nw_info_str_rxqual = "Rxqual_full";
static const char* const g_mmi_em_nw_info_str_rxqual_sub = "Rxqual_sub";
static const char* const g_mmi_em_nw_info_str_timeing_adv  = "Timing_adv";
static const char* const g_mmi_em_nw_info_str_multi_band = "MULTIBAND";
static const char* const g_mmi_em_nw_info_str_rr_state = "RR_STATE";
static const char* const g_mmi_em_nw_info_str_num_car = "NUM_CARRIERS";
static const char* const g_mmi_em_nw_info_str_c_i = "c_i";
static const char* const g_mmi_em_nw_info_str_pbcch = "PBCCH";
static const char* const g_mmi_em_nw_info_str_g_sup = "G_SUP";
static const char* const g_mmi_em_nw_info_str_mark = "-<>-<>-";
static const char* const g_mmi_em_nw_info_str_ms_txpwr = "MS_TXPWR";
static const char* const g_mmi_em_nw_info_str_crh = "CRH:";
static const char* const g_mmi_em_nw_info_str_rx_acc_min = "RX_ACC_MIN";
#ifdef __EGPRS_MODE__
static const char* const g_mmi_em_nw_info_str_bsn1 = "bsn1";
static const char* const g_mmi_em_nw_info_str_bsn2 = "bsn2";
#endif
static const char* const g_mmi_em_nw_info_str_tfi = "tfi";
static const char* const g_mmi_em_nw_info_str_umts_exits = "umts_exist";
static const char* const g_mmi_em_nw_info_str_emr_report = "emr_report";
static const char* const g_mmi_em_nw_info_str_no_instace = "no_of_instance";
static const char* const g_mmi_em_nw_info_str_present = "present";
static const char* const g_mmi_em_nw_info_str_rplmn = "RPLMN";
static const char* const g_mmi_em_nw_info_str_eplmn = "EPLMN";
static const char* const g_mmi_em_nw_info_str_fplmn = "FPLMN";
static const char* const g_mmi_em_nw_info_str_log_c = "arfcn rssi  c1  c2 G";
static const char* const g_mmi_em_nw_info_str_not_cntx = "no context";
static const char* const g_tbf_mode = "tbf_mode";
static const char* const g_rel = "rel";
static const char* const g_ws = "ws";
static const char* const g_ts = "ts";
static const char* const g_tai = "tai";
static const char* const g_tqi = "tqi";
static const char* const g_u_stat = "u_stat";
static const char* const g_macm = "macm";
static const char* const g_rlcm = "rlcm";
static const char* const g_d_stat = "d_stat";
static const char* const g_tfi = "tfi";
static const char* const g_gra = "gra";
static const char* const g_oct = "oct";


extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);

/************************************/
/********  Local Function **********/
/************************************/
static void mmi_em_network_info_init_mem(void);

static void mmi_em_network_info_init_context(void);

static void mmi_em_network_info_release_context(void);

static MMI_BOOL mmi_em_network_info_mem_stop_hdlr(void);

static void mmi_em_network_info_stop_req(void);

static MMI_RET mmi_em_nw_info_update_proc(mmi_event_struct *evt);

static void mmi_em_nw_info_list_exit_hdlr(cui_menu_event_struct *evt);

static MMI_RET mmi_em_nw_info_checkbox_list_proc(mmi_event_struct *evt);

static void mmi_em_nw_info_list_hdlr(cui_menu_event_struct *evt);

extern void mmi_frm_send_ilm(oslModuleType dest_mod_id, oslMsgType msg_id,
                        oslParaType *local_para, oslPeerBuffType *peer_buff);

#define EM_NW_NETWORK_INFO
/*-----------------------------------------------------------------------------*/
/*-------------------------- Network -> Network info --------------------------*/
/*-----------------------------------------------------------------------------*/

static void mmi_em_network_info_init_mem(void)
{
	
	
    U16 sim_idx;
    
    
    
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);

    if (g_mmi_em_nw_mode_status[sim_idx])
    {
        mmi_em_network_info_init_context();
    }
    else
    {
        mmi_em_network_info_release_context();
    }
}

static void mmi_em_network_info_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mmi_em_network_info)
    {
        MMI_EM_REG_STOP_FUNC(mmi_em_network_info_mem_stop_hdlr);
        mmi_em_comm_mem_hold();

        g_mmi_em_network_info = MMI_EM_MALLOC(sizeof(mmi_em_network_info_struct));
    
    }
    
    if (g_mmi_em_network_info)
    {
        memset(g_mmi_em_network_info, 0, sizeof(mmi_em_network_info_struct));
    }
}

static void mmi_em_network_info_release_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_network_info)
    {
        MMI_EM_FREE(g_mmi_em_network_info);
        g_mmi_em_network_info = NULL;
        MMI_EM_UNREG_STOP_FUNC(mmi_em_network_info_mem_stop_hdlr);
        mmi_em_comm_mem_stop_hold();
    }
}

static MMI_BOOL mmi_em_network_info_mem_stop_hdlr(void)
{
    mmi_em_network_info_stop_req();
    mmi_em_network_info_release_context();
    return MMI_TRUE;
}

/*****************************************
 * common functions
 ****************************************/
static void mmi_em_nw_info_get_list_states(U8 *list_of_states, U16 *mode_status)
{
    U32 i;
    U16 mode = 0x01;
    


    for (i = 0; i < MAX_EM_MODE; i++)
    {
        if (MMI_EM_NW_CHK_MODE(mode, *mode_status))
        {
            list_of_states[i] = 1;
        }
        else
        {
            list_of_states[i] = 0;
        }
        mode = mode * 2;
    }
}

/*****************************************
 * List handler
 ****************************************/
void mmi_em_nw_info_checkbox_list_hdlr(cui_menu_event_struct *evt)
{
    MMI_ID menu_id;
    MMI_ID group_id;
    S32 sim_idx;
    
    
    sim_idx = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);

    if (mmi_em_ctrl_sim_is_available((mmi_sim_enum)(0x01 << sim_idx)))
    {
        MMI_EM_NW_SET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX, (U8)sim_idx);
        group_id = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                       GRP_ID_AUTO_GEN, 
                       mmi_em_nw_info_checkbox_list_proc, NULL,
                       MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
        menu_id = cui_menu_create(group_id, CUI_MENU_SRC_TYPE_RESOURCE, CUI_MENU_TYPE_APPSUB,
                      MENU_ID_EM_NW_NETWORK_INFO_LIST,
                      MMI_TRUE, NULL);
        cui_menu_run(menu_id);
    }
}

static MMI_RET mmi_em_nw_info_checkbox_list_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_em_nw_info_list_pre_hdlr(menu_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_em_nw_info_list_hdlr(menu_evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }

    return MMI_RET_OK;
}

void mmi_em_nw_info_list_pre_hdlr(cui_menu_event_struct *evt)
{
	
    U8 list_of_states[MAX_EM_MODE] = {0};
    U32 sim_idx;
    
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);

    mmi_em_nw_info_get_list_states(list_of_states, &g_mmi_em_nw_mode_status[sim_idx]);
    cui_menu_set_checkbox_state(evt->sender_id, list_of_states);
}

static void mmi_em_nw_info_list_hdlr(cui_menu_event_struct *evt)
{
    U32 i;
    U32 sim_idx;
    U16 mode = 0x01;
    U8 list_of_states[MAX_EM_MODE] = {0};
    
    
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);

    cui_menu_get_checkbox_state(evt->sender_id, list_of_states);
    
    g_mmi_em_nw_mode_status_history = g_mmi_em_nw_mode_status[sim_idx];
    
    for (i = 0;i < MAX_EM_MODE; i++)
    {
        if (list_of_states[i])
        {
            MMI_EM_NW_SET_ON(mode, g_mmi_em_nw_mode_status[sim_idx]);
        }
        if (0 == list_of_states[i])
        {
            MMI_EM_NW_SET_OFF(mode, g_mmi_em_nw_mode_status[sim_idx]);
        }
        mode = mode * 2;
    }
    mmi_em_nw_info_list_exit_hdlr(evt);
}

static void mmi_em_nw_info_list_exit_hdlr(cui_menu_event_struct *evt)
{
    mmi_em_display_confirm(
        STR_GLOBAL_UPDATE,
        mmi_em_get_root_group(),
        MMI_EVENT_QUERY,
        mmi_em_nw_info_update_proc);
        
    cui_menu_close(evt->sender_id);
}


static MMI_RET mmi_em_nw_info_update_proc(mmi_event_struct *evt)
{
    switch (((mmi_alert_result_evt_struct*) evt)->result)
    {
        case MMI_ALERT_CNFM_YES:
        {
            SendEmStartMsg();
            break;
        }
            
        case MMI_ALERT_CNFM_NO:
        {
            U32 sim_idx;
            sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);
            g_mmi_em_nw_mode_status[sim_idx] = g_mmi_em_nw_mode_status_history ;
            break;
        }
            
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  SendEmStartMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendEmStartMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old_sim_idx = 0;
    U8 sim_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NW_SET_INFO(MMI_EM_NW_INFO_CUR_EM_COMM_OFFSET, MMI_EM_NW_INFO_CUR_EM_COMM, 1);
    
    old_sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_OLD_SIM_IDX_OFFSET, MMI_EM_NW_INFO_OLD_SIM_IDX);
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);
    
    if (old_sim_idx != ((U8)(0x03)) && old_sim_idx != sim_idx)
    {
        mmi_em_network_info_stop_req();
        mmi_em_network_info_release_context();
    }

    MMI_EM_NW_SET_INFO(MMI_EM_NW_INFO_OLD_SIM_IDX_OFFSET, MMI_EM_NW_INFO_OLD_SIM_IDX, sim_idx);
    mmi_em_network_info_init_mem();
    
    EngineerModeStartReq(MOD_AS);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStartReq(U32 mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (em_nw_info_entry == 0)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_UPDATE_RSP, (PsIntFuncPtr)EngineerModeStartRes, MMI_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, (PsIntFuncPtr)mmi_em_parsing_data, MMI_FALSE);   
    }
    mmi_em_nw_send_start_req((module_type)mod_id);
}

static void mmi_em_network_info_stop_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U32 sim_idx = 0;
    mmi_em_update_req_struct *em_start_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

    memset(em_start_req->info_request, EM_OFF, EM_INFO_REQ_NUM);
    
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_OLD_SIM_IDX_OFFSET, MMI_EM_NW_INFO_OLD_SIM_IDX);
    
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_idx)),
        MSG_ID_MMI_EM_UPDATE_REQ,
        (oslParaType*)em_start_req,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_send_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id      [IN]        
 *  info_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_nw_send_start_req(module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_update_req_struct *em_start_req;
    U32 i = 0;
    U8 sim_idx;
    U8 list_of_states[MAX_EM_MODE] = {0};
    U8 cur_list_states[MAX_EM_MODE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_idx = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);
    
    mmi_em_nw_info_get_list_states(list_of_states, &g_mmi_em_nw_mode_status[sim_idx]);

    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

    memset((void*)em_start_req->info_request, EM_NC, EM_INFO_REQ_NUM);

    if (em_nw_info_entry == 0)
    {
        /* it is the first to send em info update */
         for (i = 0;i < MAX_EM_MODE; i++)
         {
             if (list_of_states[i])
             {
                 em_start_req->info_request[em_nw_info_event_index_table[i]] = EM_ON;//list_of_states[i];
             }
         }
         g_mmi_em_nw_cur_mode[sim_idx] = g_mmi_em_nw_mode_status[sim_idx];
    }
    else
    {
        mmi_em_nw_info_get_list_states(cur_list_states, &g_mmi_em_nw_cur_mode[sim_idx]);
        for (i = 0;i < MAX_EM_MODE; i++)
        {
            if (list_of_states[i] == cur_list_states[i])
            {
                em_start_req->info_request[em_nw_info_event_index_table [i]] = EM_NC;
            }
            else
            {
                em_start_req->info_request[em_nw_info_event_index_table [i]] = !list_of_states[i];        
            }
        }
        g_mmi_em_nw_cur_mode[sim_idx] = g_mmi_em_nw_mode_status[sim_idx];
    }
    em_nw_info_entry++;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_idx)),
        MSG_ID_MMI_EM_UPDATE_REQ,
        (oslParaType*)em_start_req,
        NULL);
}

void mmi_em_nw_fresh_active_scrn(void)
{
     mmi_frm_scrn_create(GRP_ID_ROOT, SCR_ID_DUMMY, NULL, NULL);

     mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_DUMMY);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_parsing_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_parsing_data(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_rr_process_logs(msg->em_info, msg->info);

#ifndef __COSMOS_MMI__
    if (mmi_idle_is_active() || mmi_em_is_in_call())
#else
    if (vapp_launcher_is_active() || mmi_em_is_in_call())
#endif
    {
        /* display the trace information on screen */
        if (g_mmi_em_network_info)
        {
            //kal_prompt_trace(MOD_MMI, "[EM] mmi_em_parsing_data(), g_mmi_em_network_info");
            if (MMI_EM_NW_INFO_CHK(0X01, g_em_nw_comm_info))
            {
                mmi_em_nw_fresh_active_scrn();
            }
            else
            {
                mmi_em_show_screen();
            }
        }
    }
}


static mmi_ret mmi_em_nw_info_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_avt = (mmi_frm_scrn_active_evt_struct*)evt;
            
            if (active_avt->is_first_active)
            {
                MMI_EM_NW_INFO_SET_ON(0X01, g_em_nw_comm_info);
               // ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
            }
			ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
            mmi_em_display_screen_n(g_mmi_em_network_info->index_screen);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_pen_down_handler(mmi_em_tracer_pen_down);
        #endif

		
 //  #ifdef __PLUTO_MMI_PACKAGE__
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
 //  #endif

   #ifdef __COSMOS_MMI_PACKAGE__    
       SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
   #endif
	
            break;
        }
            
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_EM_NW_INFO_SET_OFF(0X01, g_em_nw_comm_info);
            break;
        }
            
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
           
            if (key_evt->key_type == KEY_EVENT_UP)
            {
                if (KEY_UP_ARROW == key_evt->key_code || KEY_VOL_UP == key_evt->key_code)
                {
                    mmi_em_tracer_key_up();
                    return MMI_RET_KEY_HANDLED;
                }
                if (KEY_DOWN_ARROW == key_evt->key_code || KEY_VOL_DOWN == key_evt->key_code)
                {
                    mmi_em_tracer_key_down();
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

MMI_ID g_nw_popup_gourp_id;    /*This group is for EM NW_info to popup*/


static mmi_ret mmi_em_nw_info_group_proc(mmi_event_struct* evt)
{
	   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
			g_nw_popup_gourp_id = 0;
            break;
        }
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
void mmi_em_show_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI__
    if (mmi_idle_is_active() || mmi_em_is_in_call())
#else
    if (vapp_launcher_is_active() || mmi_em_is_in_call())
#endif
    {
	g_nw_popup_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
							   GRP_ID_AUTO_GEN, mmi_em_nw_info_group_proc, NULL);

		mmi_frm_group_enter(g_nw_popup_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
		
        mmi_frm_scrn_create(
            g_nw_popup_gourp_id,
            SCR_ID_EM_NW_INFO_LOG,
            mmi_em_nw_info_scrn_proc, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_key_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_network_info->index_screen == 0)
    {
        g_mmi_em_network_info->index_screen = MAX_TRACER_SCREEN_NUM - 1;
    }
    else
    {
        g_mmi_em_network_info->index_screen--;
    }
    mmi_em_display_screen_n(g_mmi_em_network_info->index_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_key_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_em_network_info->index_screen++;
    if (g_mmi_em_network_info->index_screen >= MAX_TRACER_SCREEN_NUM)
    {
        g_mmi_em_network_info->index_screen = 0;
    }
    mmi_em_display_screen_n(g_mmi_em_network_info->index_screen);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_pen_down
 * DESCRIPTION
 *
 * PARAMETERS
 *  pos     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_pen_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if y position is in button bar or not */
    if (pos.y >= MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT - 1)
    {
        /* If in button bar,  the event handler will be passed to gerneral handler. (softkey handler)  */
        wgui_general_pen_down_hdlr(pos);
    }
    else
    {
        /* If not in button bar,  execute dedicate handler.  */
        mmi_em_tracer_key_down();
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */


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
void mmi_em_rr_process_logs(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mm_pdu_len;
    void * buff_data = NULL;
    void * srouce_data = NULL;
    U32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_network_info)
    {
        buff_data = (void*)get_peer_buff_pdu(pdu_buff_ptr, &mm_pdu_len);
        switch (em_info)
        {
            case RR_EM_CELL_SELECT_PARA_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_cell_select_para_info;
                size = sizeof(rr_em_cell_select_para_info_struct);
            }
            break;
            case RR_EM_CHANNEL_DESCR_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_channel_descr_info;
                size = sizeof(rr_em_channel_descr_info_struct);
            }
            break;
            case RR_EM_CTRL_CHANNEL_DESCR_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_ctrl_channel_descr_info;
                size = sizeof(rr_em_ctrl_channel_descr_info_struct);
            }
                break;
            case RR_EM_RACH_CTRL_PARA_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_rach_ctrl_para_info;
                size = sizeof(rr_em_rach_ctrl_para_info_struct);
            }
                break;
            case RR_EM_LAI_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_lai_info;
                size = sizeof(rr_em_lai_info_struct);
            }
                break;
            case RR_EM_RADIO_LINK_COUNTER_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_radio_link_counter_info;
                size = sizeof(rr_em_radio_link_counter_info_struct);
            }
            break;
            case RR_EM_MEASUREMENT_REPORT_INFO:
            {
                 srouce_data = &g_mmi_em_network_info->mmi_rr_em_measurement_report_info;
                size = sizeof(rr_em_measurement_report_info_struct);
            }
            break;
            case MMRR_EM_PLMN_INFO_STRUCT_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_plmn_info;
                size = sizeof(mmrr_plmn_info_struct);
                break;
            }
            case RR_EM_GPRS_GENERAL_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_gprs_general_info;
                size = sizeof(rr_em_gprs_general_info_struct);
                break;
            }
            case RR_EM_SI2Q_INFO_STRUCT_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_si2q_info;
                size = sizeof(rr_em_si2q_info_struct);
                break;
            }
            case RR_EM_MI_INFO_STRUCT_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_mi_info;
                size = sizeof(rr_em_mi_info_struct);
                break;
           }
           case RR_EM_TBF_INFO:
           {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_tbf_info;
                size = sizeof(rr_em_tbf_status_struct);
                break;
            }
            case RR_EM_BLK_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_blk_info;
                size = sizeof(rr_em_blk_info_struct);
                break;
            }
            case RR_EM_CA_LIST_INFO:
            {
                srouce_data = &g_mmi_em_network_info->mmi_rr_em_ca_list_info;
                size = sizeof(rr_em_ca_list_info_struct);
                break;
            }
            default:
                break;
        }
    
        memcpy(srouce_data, buff_data, size);
    }
    free_peer_buff(pdu_buff_ptr);
}

static const char* g_mmi_em_nw_info_str_title[] = 
{
    "Measure Rep",
    "Measure Rep",
    "Cell Selection",
    "Channel Descr",
    "Ctrl Channel",
    "RACH Ctrl",
    "LAI",
    "DSC/RLC Cnt",
    "Nebr/Srv Cell",
    "Nebr/Srv Cell",
    "PLMN Info",
    "GPRS Info",
    "Si2q/mi Info",
    "TBF Info",
    "BLK Info",
    "CA List Info(1/2)",
    "CA List Info(2/2)"
};

static void mmi_em_nw_info_get_screen_txt_buffer(U8 **buf)
{
    U32 i;

    for (i = 0; i < MAX_TRACER_LINE_NUM; i++)
    {
        buf[i]= g_mmi_em_network_info->mmi_screen_text[i];
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_screen_color_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  color_r     [IN]
 *  color_g     [IN]
 *  color_b     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b)
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
        0,
        MAIN_LCD_device_width - 1,
        MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
        c);

    UI_set_font(&debug_print_font);
    c = gui_color(0, 0, 0);
    UI_set_text_color(c);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_display_screen_n
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_display_screen_n(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 text_pos = 0;
    U8 *mmi_screen_text[MAX_TRACER_LINE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    MMI_ASSERT(screen_num < MAX_TRACER_SCREEN_NUM);
    
    //kal_prompt_trace(MOD_MMI, "mmi_em_display_screen_n()");
    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    mmi_em_tracer_screen_color_init(255, 255, 255);

    mmi_em_nw_info_get_screen_txt_buffer(mmi_screen_text);
    
    sprintf((char*)mmi_screen_text[i++], 
        TEXT_FORMAT_9, g_mmi_em_nw_info_str_title[screen_num], screen_num + 1, MAX_TRACER_SCREEN_NUM);
    
    sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_mark);
    
    if (em_nw_info_update_is_allowed_show(screen_num))
    {
        i = g_mmi_em_nw_info_show_log_callback[screen_num](screen_num, mmi_screen_text);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_not_cntx);
    }
    
    mmi_screen_text[i++][0] = '\0';

    for (i = 0; i < MAX_TRACER_LINE_NUM; i++)
    {
        if (g_mmi_em_network_info->mmi_screen_text[i][0] == '\0')
        {
            break;
        }
        mmi_em_display_line_n(&text_pos, g_mmi_em_network_info->mmi_screen_text[i]);
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_display_line_n
 * DESCRIPTION
 *
 * PARAMETERS
 *  text_pos        [?]
 *  str             [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_display_line_n(U32 *text_pos, U8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern stFontAttribute MMI_small_font;
    U8 temp_str[200] = {0};
    U16 alignment_width = 0, alignment_height = 0;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*) temp_str, (S8*) str, sizeof(temp_str) / 2 - 1);
    Get_StringWidthHeight((U8*) temp_str, (S32*) & alignment_width, (S32*) & alignment_height);

    gui_set_font(&MMI_small_font);

    gui_measure_string((UI_string_type) temp_str, &width, &height);

    if ((S32)(*text_pos+height) < (S32)(MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT-1) )
    {
        gui_move_text_cursor(0, *text_pos);
        *text_pos += height;
        gui_print_text((UI_string_type) temp_str);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_measurement_report_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_measurement_report_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_measurement_report_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_measurement_report_info_struct *rr_em_measurement_report_info = 
        (rr_em_measurement_report_info_struct*) &g_mmi_em_network_info->mmi_rr_em_measurement_report_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page one */
    sprintf(
       (char*)mmi_screen_text[i++],
       TEXT_FORMAT_2,
       "SERV_ARFCN",
       rr_em_measurement_report_info->serving_arfcn);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        "RSSI",
        rr_em_measurement_report_info->serv_rla_in_quarter_dbm);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "BSIC", rr_em_measurement_report_info->serving_bsic);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        "C1_SERV_CELL",
        rr_em_measurement_report_info->c1_serv_cell);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        "C2_SERV_CELL",
        rr_em_measurement_report_info->c2_serv_cell);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_10,
        "C31",
         NA_SYMBOL);
            
#ifdef __AMR_SUPPORT__
     if (rr_em_measurement_report_info->amr_info_valid != MMI_FALSE)
     {
         U32 k=0, j=0, value=0;
         S8 buf[40]= {'\0'};
         S8 buf_temp[10] = {'\0'};
         U8 acs_index[4];

         for (k = 0; k < 4; k++)
            acs_index[k] = 15;   /* init string : X */

         /* acs info */
         for (k = 16; k > 0; k--)
         {
             if (EM_IS_SET(rr_em_measurement_report_info->acs, k-1))
             {
                 if (j < 4)
                 {
                     acs_index[j] = k-1;
                     j++;
                 }
             }
         }

         sprintf((char*)buf, "%s,%s,%s,%s", 
             amr_info_bitwise_name[acs_index[0]], amr_info_bitwise_name[acs_index[1]],
             amr_info_bitwise_name[acs_index[2]], amr_info_bitwise_name[acs_index[3]]);

         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, "acs", buf);
         buf[0]= 0 ;

            /* icm info */
         for (k=16; k>0; k--)
         {
             if (EM_IS_SET(rr_em_measurement_report_info->icm, k-1))
             {
                 sprintf((char*)buf,"%s, ", amr_info_bitwise_name[k-1]);
             }
         }
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, g_mmi_em_nw_info_str_icm, buf);

         /* cmr info */
         value  = (U8)(rr_em_measurement_report_info->cmr_cmc_cmiu_cmid>>6);
         if (value<4)
             sprintf((char*)buf_temp, TEXT_FORMAT_12, "cmr", amr_info_bitwise_name[acs_index[value]]);
         
         sprintf((char*)buf, "%s", buf_temp);
         buf_temp[0]= 0 ;

         /* cmc info */
         value  = (U8)((rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x30)>>4);
         if (value<4)
             sprintf((char*)buf_temp, TEXT_FORMAT_12, "cmc", amr_info_bitwise_name[acs_index[value]]);
         sprintf((char*)buf, "%s %s", buf, buf_temp);
         buf_temp[0]= 0 ;

         sprintf((char*)mmi_screen_text[i++], "%s", buf);
         buf[0]= 0 ;

         /* cmiu info */
         value  = (U8)((rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x0C)>>2);
         if (value<4)
            sprintf((char*)buf_temp, TEXT_FORMAT_12, "cmiu", amr_info_bitwise_name[acs_index[value]]);
         sprintf((char*)buf, "%s", buf_temp);
         buf_temp[0]= 0 ;

         /* cmid info */
         value  = (U8)(rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x03);
         if (value<4)
             sprintf((char*)buf_temp, TEXT_FORMAT_12, "cmid", amr_info_bitwise_name[acs_index[value]]);
         sprintf((char*)buf, "%s %s", buf, buf_temp);
         buf_temp[0]= 0 ;

         sprintf((char*)mmi_screen_text[i++], "%s", buf);
         buf[0]= 0 ;
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_c_i,rr_em_measurement_report_info->c_i );
    }
    else
    {
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "acs", NA_SYMBOL );
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_mmi_em_nw_info_str_icm, NA_SYMBOL );
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "cmr_c_iu_id", NA_SYMBOL );
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_mmi_em_nw_info_str_c_i, NA_SYMBOL );
    }
#endif /* #ifdef __AMR_SUPPORT__ */

    //mmi_screen_text[i++][0] = '\0';
    
    return i;
}

static U32 mmi_em_rr_measurement_report_info_log_format(U8 param, U8 **mmi_screen_text, U32 i, const char* print_str)
{
    if (param != 0xff)
    {
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, print_str, param);
    }
    else
    {
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, print_str, NA_SYMBOL);
    }
    
    return i;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_measurement_report_info_logs_2
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_measurement_report_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_measurement_report_info_logs_2(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_measurement_report_info_struct *rr_em_measurement_report_info = 
        (rr_em_measurement_report_info_struct*) &g_mmi_em_network_info->mmi_rr_em_measurement_report_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        g_mmi_em_nw_info_str_g_sup,
        rr_em_measurement_report_info->serv_gprs_supported);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        g_mmi_em_nw_info_str_pbcch,
        rr_em_measurement_report_info->gprs_pbcch_present);
    g_mmi_em_network_info->num_of_carriers = rr_em_measurement_report_info->num_of_carriers;
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        g_mmi_em_nw_info_str_num_car,
        rr_em_measurement_report_info->num_of_carriers);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_rr_state, rr_em_measurement_report_info->rr_state);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        g_mmi_em_nw_info_str_multi_band,
        rr_em_measurement_report_info->multiband_report);

    i = mmi_em_rr_measurement_report_info_log_format(rr_em_measurement_report_info->timing_advance,
            mmi_screen_text,
            i, g_mmi_em_nw_info_str_timeing_adv);
            
    i = mmi_em_rr_measurement_report_info_log_format(rr_em_measurement_report_info->rxqual_sub, 
            mmi_screen_text,
            i, g_mmi_em_nw_info_str_rxqual_sub);

    i = mmi_em_rr_measurement_report_info_log_format(rr_em_measurement_report_info->rxqual_full, 
            mmi_screen_text,
            i, g_mmi_em_nw_info_str_rxqual);

    //mmi_screen_text[i++][0] = '\0';

    return i;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_cell_select_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                      [IN]
 *  rr_em_cell_select_para_info     [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_cell_select_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 2;
    rr_em_cell_select_para_info_struct *rr_em_cell_select_para_info = 
         (rr_em_cell_select_para_info_struct*) &g_mmi_em_network_info->mmi_rr_em_cell_select_para_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_crh, rr_em_cell_select_para_info->crh);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_ms_txpwr, rr_em_cell_select_para_info->ms_txpwr);
    sprintf(
       (char*)mmi_screen_text[i++],
       TEXT_FORMAT_2,
       g_mmi_em_nw_info_str_rx_acc_min,
       rr_em_cell_select_para_info->rxlev_access_min);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_channel_descr_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                      [IN]
 *  rr_em_channel_descr_info        [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_channel_descr_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_channel_descr_info_struct *rr_em_channel_descr_info = 
        (rr_em_channel_descr_info_struct*) &g_mmi_em_network_info->mmi_rr_em_channel_descr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rr_em_channel_descr_info->channel_type < MAX_CHANNEL_TYPE_COUNT)
    {
        sprintf(
           (char*)mmi_screen_text[i++],
            TEXT_FORMAT_12,
            "CH_TYPE",
            rr_channel_type_name[rr_em_channel_descr_info->channel_type]);
    }
    else
    {
         sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CH_TYPE", rr_em_channel_descr_info->channel_type);
    }

    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_14,
        "HOPPING",
        rr_em_channel_descr_info->hopping_flag,
        "MAIO",
        rr_em_channel_descr_info->maio);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_16,
        "HSN",
        rr_em_channel_descr_info->hsn,
        "TN",
        rr_em_channel_descr_info->tn,
        "TSC",
        rr_em_channel_descr_info->tsc);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MA_NUMBER", rr_em_channel_descr_info->num_of_carriers);

#ifdef __AMR_SUPPORT__
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "AMR_VALID", rr_em_channel_descr_info->amr_valid);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_14,
        "MR_VER",
        rr_em_channel_descr_info->mr_ver,
        "ICMI",
        rr_em_channel_descr_info->icmi);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "START_CODEC", rr_em_channel_descr_info->start_codec_mode);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_1,
        "THRESHOLD",
        rr_em_channel_descr_info->threshold[0],
        rr_em_channel_descr_info->threshold[1],
        rr_em_channel_descr_info->threshold[2]);

    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_1,
        "HYSTERESIS",
        rr_em_channel_descr_info->hysteresis[0],
        rr_em_channel_descr_info->hysteresis[1],
        rr_em_channel_descr_info->hysteresis[2]);
#endif /* __AMR_SUPPORT__ */

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, "Cipher_algo", rr_cipher_algo_name[rr_em_channel_descr_info->cipher_algo]);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_ctrl_channel_descr_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_ctrl_channel_descr_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_ctrl_channel_descr_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 2;
    rr_em_ctrl_channel_descr_info_struct *rr_em_ctrl_channel_descr_info = 
       (rr_em_ctrl_channel_descr_info_struct *)&g_mmi_em_network_info->mmi_rr_em_ctrl_channel_descr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MSCR", rr_em_ctrl_channel_descr_info->mscr);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "ATT", rr_em_ctrl_channel_descr_info->att);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CCCH_CONF", rr_em_ctrl_channel_descr_info->ccch_conf);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MFRMS", rr_em_ctrl_channel_descr_info->bs_pa_mfrms);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        "BS_AG_BLKS",
        rr_em_ctrl_channel_descr_info->bs_ag_blks_res);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CBQ2", rr_em_ctrl_channel_descr_info->cbq2);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "T3212", rr_em_ctrl_channel_descr_info->t3212);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_rach_ctrl_para_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                      [IN]
 *  rr_em_rach_ctrl_para_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_rach_ctrl_para_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2 , j = 0;
    U8 str_buf[40];
    rr_em_rach_ctrl_para_info_struct *rr_em_rach_ctrl_para_info = 
        (rr_em_rach_ctrl_para_info_struct *)&g_mmi_em_network_info->mmi_rr_em_rach_ctrl_para_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MAX RETRANS", rr_em_rach_ctrl_para_info->max_retrans);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CBA", rr_em_rach_ctrl_para_info->cba);
    sprintf((char*)mmi_screen_text[i++], "ACC_Class");

    /* Bit 15 - Bit 8 */
    j = rr_em_rach_ctrl_para_info->acc_class[1];
    sprintf((char*)str_buf, TEXT_FORMAT_18, EM_IS_SET(j,7), EM_IS_SET(j,6), EM_IS_SET(j,5), EM_IS_SET(j,4), EM_IS_SET(j,3), EM_IS_SET(j,2), EM_IS_SET(j,1), EM_IS_SET(j,0));
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, str_buf);

    /* Bit 7 - Bit 0 */
    j = rr_em_rach_ctrl_para_info->acc_class[0];
    str_buf[0]=0;
    sprintf((char*)str_buf, TEXT_FORMAT_18, EM_IS_SET(j,7), EM_IS_SET(j,6), EM_IS_SET(j,5), EM_IS_SET(j,4), EM_IS_SET(j,3), EM_IS_SET(j,2), EM_IS_SET(j,1), EM_IS_SET(j,0));
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, str_buf);

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CB_support", rr_em_rach_ctrl_para_info->CB_supported);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "TX_INTEGER", rr_em_rach_ctrl_para_info->tx_integer);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "RE_EST", rr_em_rach_ctrl_para_info->re);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_lai_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num          [IN]
 *  rr_em_lai_info      [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_lai_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_lai_info_struct *rr_em_lai_info = (rr_em_lai_info_struct *)&g_mmi_em_network_info->mmi_rr_em_lai_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(
        (char*)mmi_screen_text[i++],
         TEXT_FORMAT_1,
         "MCC",
         rr_em_lai_info->mcc[0],
         rr_em_lai_info->mcc[1],
         rr_em_lai_info->mcc[2]);
    if (rr_em_lai_info->mnc[2] != 0x0f)
    {
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_1,
            "MNC",
            rr_em_lai_info->mnc[0],
            rr_em_lai_info->mnc[1],
            rr_em_lai_info->mnc[2]);
    }
    else
    {
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_5,
            "MNC",
            rr_em_lai_info->mnc[0],
            rr_em_lai_info->mnc[1],
            "F");
    }
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_4, "LAC", rr_em_lai_info->lac[0], rr_em_lai_info->lac[1]);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CELL_ID", rr_em_lai_info->cell_id);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_radio_link_counter_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_radio_link_counter_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_radio_link_counter_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_radio_link_counter_info_struct *rr_em_radio_link_counter_info = 
        (rr_em_radio_link_counter_info_struct *)&g_mmi_em_network_info->mmi_rr_em_radio_link_counter_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rr_em_radio_link_counter_info->is_dsf)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, rr_downlink_signal_fail_name[0]);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, rr_downlink_signal_fail_name[1]);
    }

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MAX_VALUE", rr_em_radio_link_counter_info->max_value);
    sprintf(
        (char*)mmi_screen_text[i++],
        TEXT_FORMAT_2,
        "CUR_VALUE",
        rr_em_radio_link_counter_info->current_value);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "DTX_IND", rr_em_radio_link_counter_info->dtx_ind);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "DTX_USED", rr_em_radio_link_counter_info->dtx_used);

    //mmi_screen_text[i++][0] = '\0';
    return i;
}


static U32 mmi_em_rr_c1_c2_logs_format(U8 **mmi_screen_text, U32 start_idx, U32 end_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2, j;
    rr_em_measurement_report_info_struct  *rr_em_measurement_report_info = 
        (rr_em_measurement_report_info_struct*) &g_mmi_em_network_info->mmi_rr_em_measurement_report_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_log_c);
    for (j = start_idx; j < end_idx; j++)
    {
        if (((rr_em_measurement_report_info->nc_info_status[j] & 0x03) == 0x03) &&
            (rr_em_measurement_report_info->c1[j] != -1) && (rr_em_measurement_report_info->c2[j] != -1))
        {
            sprintf(
                (char*)mmi_screen_text[i++],
                TEXT_FORMAT_8,
                rr_em_measurement_report_info->nc_arfcn[j],
                rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                rr_em_measurement_report_info->c1[j],
                rr_em_measurement_report_info->c2[j],
                (rr_em_measurement_report_info->nc_info_status[j] & 0x04 ? 1 : 0));
        }
        else
        {
            sprintf(
                (char*)mmi_screen_text[i++],
                TEXT_FORMAT_11,
                rr_em_measurement_report_info->nc_arfcn[j],
                rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                NA_SYMBOL,
                NA_SYMBOL,
                0);
        }
    }
    //mmi_screen_text[i++][0] = '\0';
    return i;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_c1_c2_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_measurement_report_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_c1_c2_logs(U8 screen_num, U8 **mmi_screen_text)
{
    return mmi_em_rr_c1_c2_logs_format(mmi_screen_text, 0, 6);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_c1_c2_logs_2
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 *  rr_em_measurement_report_info       [?]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_c1_c2_logs_2(U8 screen_num, U8 **mmi_screen_text)
{
    return mmi_em_rr_c1_c2_logs_format(mmi_screen_text, 6, 12);
}

static U32 mmi_em_rr_plmu_info_log_format(U8 **mmi_screen_text, U32 i, U8 (*plum)[][6], U32 arry_size)
{
    U32 j = 0;

    for (j = 0;j < arry_size;j += 2)
    {
        if ((*plum)[j][0] == 0xff && (*plum)[j+1][0] == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, g_mmi_em_nw_info_str_fplmn, NA_SYMBOL, NA_SYMBOL);
        }
        else if ((*plum)[j][0] == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_22, g_mmi_em_nw_info_str_fplmn, NA_SYMBOL,
                    (*plum)[j+1][0], (*plum)[j+1][1],
                    (*plum)[j+1][2], (*plum)[j+1][3],
                    (*plum)[j+1][4], (*plum)[j+1][5]);
        }
        else if ((*plum)[j+1][0] == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_23, g_mmi_em_nw_info_str_fplmn,
                    (*plum)[j+1][0], (*plum)[j+1][1],
                    (*plum)[j+1][2], (*plum)[j+1][3],
                    (*plum)[j+1][4], (*plum)[j+1][5], NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_21, g_mmi_em_nw_info_str_fplmn,
                    (*plum)[j][0], (*plum)[j][1],
                    (*plum)[j][2], (*plum)[j][3],
                    (*plum)[j][4], (*plum)[j][5],
                    (*plum)[j+1][0], (*plum)[j+1][1],
                    (*plum)[j+1][2], (*plum)[j+1][3],
                    (*plum)[j+1][4], (*plum)[j+1][5]);
        }
    }

    return i;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_plmn_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_plmn_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    mmrr_plmn_info_struct * cntx = &g_mmi_em_network_info->mmi_rr_em_plmn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "HP_PLMN_SRCH", cntx->is_higher_pri_plmn_srch);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_20, "HP_PS_TIMER", cntx->hp_count_down_timer , cntx->hp_timeout_timer);

    /* RPLMN */
    if (g_mmi_em_network_info->mmi_rr_em_plmn_info.rplmn[0] == 0xff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_mmi_em_nw_info_str_rplmn, NA_SYMBOL);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_25, g_mmi_em_nw_info_str_rplmn,
                cntx->rplmn[0], cntx->rplmn[1],
                cntx->rplmn[2], cntx->rplmn[3],
                cntx->rplmn[4], cntx->rplmn[5]);
    }

    /* EQ_PLMN1 - EQ_PLMN4 */
    i = mmi_em_rr_plmu_info_log_format(mmi_screen_text, i, (arry_plum)cntx->eq_plmn, 5);

    /* EQ_PLMN5 */
    if (cntx->eq_plmn[4][0] == 0xff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_mmi_em_nw_info_str_eplmn, NA_SYMBOL);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_23, g_mmi_em_nw_info_str_eplmn,
                cntx->eq_plmn[4][0], cntx->eq_plmn[4][1],
                cntx->eq_plmn[4][2], cntx->eq_plmn[4][3],
                cntx->eq_plmn[4][4], cntx->eq_plmn[4][5], NA_SYMBOL);
    }
    
    /* FPLMN1 - FPLMN4 */
    i = mmi_em_rr_plmu_info_log_format(mmi_screen_text, i, (arry_plum)cntx->forbid_plmn, 4);

    //mmi_screen_text[i++][0] = '\0';

    return i;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_gprs_general_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
static const char * const g_support = "support";

U8 mmi_em_rr_gprs_general_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_gprs_general_info_struct* cntx = &g_mmi_em_network_info->mmi_rr_em_gprs_general_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], "GPRS_%s:%d", g_support, cntx->gprs_support);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "sgsn_r", cntx->sgsn_r);
    sprintf((char*)mmi_screen_text[i++], "pfc_%s:%d", g_support, cntx->pfc_support);
    sprintf((char*)mmi_screen_text[i++], "epcr_%s:%d", g_support, cntx->epcr_support);
    sprintf((char*)mmi_screen_text[i++], "bep_%s:%d", g_support, cntx->bep_period);
    sprintf((char*)mmi_screen_text[i++], "egprs_%s:%d", g_support, cntx->egprs_support);

    //mmi_screen_text[i++][0] = '\0';

    return i;

}


static U32 mmi_em_rr_si2q_mi_info_logs_format(U8 ** mmi_screen_text)
{
    U32 i = 2;
    rr_em_si2q_info_struct * cntx = &g_mmi_em_network_info->mmi_rr_em_si2q_info;
    
    
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_present, cntx->present);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_no_instace, cntx->no_of_instance);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_emr_report, cntx->emr_report);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_umts_exits, cntx->umts_parameter_exist);

    return i;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_si2q_mi_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_si2q_mi_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], "---Si2q---");
    i = mmi_em_rr_si2q_mi_info_logs_format(mmi_screen_text);

    sprintf((char*)mmi_screen_text[i++], "---mi---");
    i = mmi_em_rr_si2q_mi_info_logs_format(mmi_screen_text);
    //mmi_screen_text[i++][0] = '\0';

    return i;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_tbf_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_tbf_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2;
    rr_em_tbf_status_struct *cntx = &g_mmi_em_network_info->mmi_rr_em_tbf_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cntx->ul_tbf_status == 0xff) && (cntx->dl_tbf_status == 0xff))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_tbf_mode, NA_SYMBOL);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_tbf_mode, cntx->tbf_mode);
    }

    if (cntx->ul_tbf_status == 0xff)
    {
        sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_mark);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, g_u_stat, NA_SYMBOL, g_rel, cntx->ul_rel_cause);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, g_ws, NA_SYMBOL, g_ts, NA_SYMBOL, "usf", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, g_mmi_em_nw_info_str_tfi, NA_SYMBOL, g_tai, NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, g_oct, NA_SYMBOL,g_gra, NA_SYMBOL, g_tqi, NA_SYMBOL );
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_mark);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_u_stat , cntx->ul_tbf_status, g_rel, cntx->ul_rel_cause);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_30, g_ws, cntx->ul_window_size , g_ts , cntx->ul_ts_allocation,  "usf", cntx->ul_usf);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_rlcm, cntx->ul_rlc_mode, g_macm, cntx->ul_mac_mode);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_mmi_em_nw_info_str_tfi, cntx->ul_tfi, g_tai, cntx->ul_tai);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14,  g_oct, cntx->number_rlc_octect, g_gra, cntx->ul_granularity);
    }

    sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_mark);

    if (cntx->dl_tbf_status == 0xff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, g_d_stat, NA_SYMBOL, g_rel, cntx->dl_rel_cause);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, g_ws, NA_SYMBOL, g_ts, NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, g_rlcm, NA_SYMBOL, g_macm, NA_SYMBOL);
    #ifdef __EGPRS_MODE__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, g_mmi_em_nw_info_str_tfi, NA_SYMBOL, g_tai, NA_SYMBOL, "om", NA_SYMBOL);
    #else
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, g_mmi_em_nw_info_str_tfi, NA_SYMBOL, g_tai, NA_SYMBOL);
    #endif
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_d_stat, cntx->dl_tbf_status, g_rel, cntx->dl_rel_cause);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_31, g_ws, cntx->dl_window_size, g_ts, cntx->dl_ts_allocation);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_rlcm, cntx->dl_rlc_mode, g_macm, cntx->dl_mac_mode);
    #ifdef __EGPRS_MODE__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_16, g_tfi, cntx->dl_tfi, g_tai, cntx->dl_tai, "om", cntx->dl_out_of_memory);
    #else
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_tfi, cntx->dl_tfi, g_tai, cntx->dl_tai);
    #endif
    }
    //mmi_screen_text[i++][0] = '\0';

    return i;
}

#ifdef __EGPRS_MODE__
static U32 mmi_em_rr_blk_info_logs_format(U8 **mmi_screen_text, U32 i, U16 bsn1, U16 bsn2)
{
#ifdef __EGPRS_MODE__
    if (bsn1 == 0xffff && bsn2 == 0xffff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, g_mmi_em_nw_info_str_bsn1, NA_SYMBOL, g_mmi_em_nw_info_str_bsn2, NA_SYMBOL);
    }
    else if (bsn1 == 0xffff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, g_mmi_em_nw_info_str_bsn1, NA_SYMBOL, g_mmi_em_nw_info_str_bsn2,  bsn2);
    }
    else if (bsn2 == 0xffff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_29, g_mmi_em_nw_info_str_bsn1, bsn1, g_mmi_em_nw_info_str_bsn2,  NA_SYMBOL);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, g_mmi_em_nw_info_str_bsn1, bsn1, g_mmi_em_nw_info_str_bsn2,  bsn2);
    }
#else
    if (bsn1 == 0xffff)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, g_mmi_em_nw_info_str_bsn1, NA_SYMBOL);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, g_mmi_em_nw_info_str_bsn1, bsn1);
    }
#endif
    return i;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_blk_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_blk_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 2;
    rr_em_blk_info_struct* cntx = &g_mmi_em_network_info->mmi_rr_em_blk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_16, "UL_cs", cntx->ul_coding_scheme,"cv", cntx->ul_cv, "tlli", cntx->ul_tlli);

#ifdef __EGPRS_MODE__
    i = mmi_em_rr_blk_info_logs_format(mmi_screen_text, i, cntx->ul_bsn1, cntx->ul_bsn2);
#endif
    sprintf((char*)mmi_screen_text[i++], g_mmi_em_nw_info_str_mark);

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14,  "DL_cs", cntx->dl_coding_scheme, "rxq", cntx->dl_rxqual);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "sigvar", cntx->dl_sign_var,"cval", cntx->dl_c_value_in_rx_level );

#ifdef __EGPRS_MODE__
    i = mmi_em_rr_blk_info_logs_format(mmi_screen_text, i, cntx->dl_bsn1, cntx->dl_bsn2);
#endif

#ifdef __EGPRS_MODE__
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "g_mb", cntx->dl_gmsk_mean_bep_lev, "8_mb", cntx->dl_8psk_mean_bep_lev);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_mb_1", cntx->dl_tn_mean_bep_lev[0], cntx->dl_tn_mean_bep_lev[1],
                   cntx->dl_tn_mean_bep_lev[2], cntx->dl_tn_mean_bep_lev[3]);

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_mb_2", cntx->dl_tn_mean_bep_lev[4], cntx->dl_tn_mean_bep_lev[5],
                   cntx->dl_tn_mean_bep_lev[6], cntx->dl_tn_mean_bep_lev[7]);
#endif
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_IL_1", cntx->dl_tn_interference_lev[0], cntx->dl_tn_interference_lev[1],
                   cntx->dl_tn_interference_lev[2], cntx->dl_tn_interference_lev[3]);

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_IL_2", cntx->dl_tn_interference_lev[4], cntx->dl_tn_interference_lev[5],
                   cntx->dl_tn_interference_lev[6], cntx->dl_tn_interference_lev[7]);

    //mmi_screen_text[i++][0] = '\0';

    return i;
}


static void mmi_em_rr_ca_list_info_log_format(U32 j, U32 i, U32 limited, U8 **mmi_screen_text)
{
    kal_uint8 buffer[40];
    rr_em_ca_list_info_struct *cntx = &g_mmi_em_network_info->mmi_rr_em_ca_list_info;
    
    
    if (j < limited)
    {
    	sprintf((PS8)buffer, TEXT_FORMAT_33, cntx->arfcn_list[j]);
    	strcat((char*)mmi_screen_text[i],(PS8)buffer);
    }
    else
    {
    	sprintf((PS8)buffer, TEXT_FORMAT_19, NA_SYMBOL);
    	strcat((char*)mmi_screen_text[i],(PS8)buffer);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_ca_list_info_logs
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_ca_list_info_logs(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 2 , j=0, num=0;
    kal_uint8 buffer[40];
    rr_em_ca_list_info_struct* cntx = &g_mmi_em_network_info->mmi_rr_em_ca_list_info;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "no_of_channel", cntx->number_of_channels);

    if (cntx->number_of_channels > 33) /* 33 items for each page */
    {
        num = 33;
    }
    else
    {
        num = cntx->number_of_channels;
    }

    for (j=0; j<33; j++)
    {
        if ((j%3) == 0)
        {
            sprintf((PS8)buffer, TEXT_FORMAT_32, g_mmi_em_nw_info_ca,j,"-",j+2);
            strcpy((PS8)mmi_screen_text[i], (PS8)buffer);
        }

        mmi_em_rr_ca_list_info_log_format(j, i, num, mmi_screen_text);

        if ((j%3) == 2)
            i++;
    }

    //mmi_screen_text[i++][0] = '\0';

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_ca_list_info_logs2
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_num                          [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_em_rr_ca_list_info_logs_2(U8 screen_num, U8 **mmi_screen_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 2 , j=0, num=0;
    rr_em_ca_list_info_struct *cntx = &g_mmi_em_network_info->mmi_rr_em_ca_list_info;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->number_of_channels <= 33)
    {
        num = 0 ;
    }
    else
    {
        num = cntx->number_of_channels-33; /* 33 items for each page */
    }

    for (j=33; j<64; j++)
    {
        if ((j%3) == 0)
        {
            if (j<63)
            {
                sprintf((PS8)mmi_screen_text[i], TEXT_FORMAT_32, g_mmi_em_nw_info_ca,j,"-",j+2);
            }
            else
            {
                sprintf((PS8)mmi_screen_text[i], TEXT_FORMAT_35, g_mmi_em_nw_info_ca,j);
            }
        }

        mmi_em_rr_ca_list_info_log_format(j, i, num+33, mmi_screen_text);

        if (((j%3)==2) || (j==63))
            i++;
    }

    //mmi_screen_text[i++][0] = '\0';

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStartRes
 * DESCRIPTION
 *
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStartRes(void *inMsg)
{
#if defined(__EM_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_update_rsp_struct *rsp_p = (mmi_em_update_rsp_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeStatusUpdate(0, 0);
    }
    mmi_em_display_notify_popup(rsp_p->result);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStatusUpdate
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_id          [IN]
 *  info_req        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStatusUpdate(U32 mod_id, U32 info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_network_info)
    {
        g_mmi_em_network_info->channel_descr_info.channel_type = DEFAULT_CHANNEL;
    }
    MMI_EM_NW_INFO_SET_OFF(0x02, g_em_nw_comm_info);
}


/**************************************************************
 **  FUNCTION NAME     : em_nw_info_update_is_allowed_show
 **
 **  PURPOSE           : Entry EM Network Events function.
 **
 **  INPUT PARAMETERS  : nil
 **
 **  OUTPUT PARAMETERS : void
 **
 **  RETURNS           : void
 **
 **  REMARKS           :
 **************************************************************/
MMI_BOOL em_nw_info_update_is_allowed_show(U8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8 list_of_states[MAX_EM_MODE] = {0};
    U8 sim_flag = MMI_EM_NW_GET_INFO(MMI_EM_NW_INFO_SIM_IDX_OFFSET, MMI_EM_NW_INFO_SIM_IDX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nw_info_get_list_states(list_of_states, &g_mmi_em_nw_mode_status[sim_flag]);
/*
    for (i = 0;i < MAX_EM_MODE;i++)
    {
        if (em_nw_info_event_index_table[i] == event)
        {
            if (list_of_states[i])
            {
                return MMI_TRUE;
            }
            break;
        }
    }
*/
	if (list_of_states[event] == 0)
		return MMI_FALSE;
	else 
		return MMI_TRUE;
}


#endif /* __MMI_EM_NW_NETWORK_INFO__ */

