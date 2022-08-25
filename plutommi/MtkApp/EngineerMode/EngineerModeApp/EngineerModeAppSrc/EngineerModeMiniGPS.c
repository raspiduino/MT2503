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
 * EngineerModeMiniGPS.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for MiniGPS Engineering mode
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __GPS_SUPPORT__

#include "mmi_include.h"
#include "mdi_datatype.h"
#include "ProfilesSrvGProt.h"
#include "CommonScreens.h"      /* popup */
#include "math.h"
#include "inlinecuigprot.h"
#include "MainMenuDef.h"
#include "menucuigprot.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeGPS.h"
#include "EngineerModeMiniGPS.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeUtil.h"

#include "stack_common.h"
#include "stack_msgs.h"

#include "GPSGProt.h"
//#include "gps_uart_hdlr.h"      /* bee switch */

#include "rmmi_common_enum.h"
#include "mmi_gps_nvram_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
#include "gui_themes.h"
#include "mmi_media_app_trc.h"
#include "Wgui_categories_util.h"
#include "CustMenuRes.h"
#include "mdi_gps.h"
#include "GPSSetting.h"
#include "mmi_frm_scenario_gprot.h"
#include "gps_common.h"


#define EM_MINIGPS_TIMER_ELAPSE 1000
#define EM_MINIGPS_MAX_NMEA 17
#define EM_MINIGPS_MAX_NMEA_LEN 300
#define EM_MINIGPS_SKY_CHART_IMAGE_POS   MAIN_LCD_DEVICE_WIDTH/24
#define EM_MINIGPS_SKY_CHART_IMAGE_POS_X MMI_CONTENT_X + EM_MINIGPS_SKY_CHART_IMAGE_POS //2//
#define EM_MINIGPS_SKY_CHART_IMAGE_POS_Y MMI_CONTENT_Y + EM_MINIGPS_SKY_CHART_IMAGE_POS //2//
#define EM_MINIGPS_SKY_CHART_IMAGE_WIDTH MAIN_LCD_DEVICE_WIDTH/3 //120
#define EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT EM_MINIGPS_SKY_CHART_IMAGE_WIDTH //90
#define EM_MINIGPS_SKY_CHART_IMAGE_RADIUS (EM_MINIGPS_SKY_CHART_IMAGE_WIDTH/2 - EM_MINIGPS_SKY_CHART_IMAGE_POS)// 50 //40
#define EM_MINIGPS_SATELLITE_RADIUS      MAIN_LCD_DEVICE_WIDTH/30 ////
#define EM_MINIGPS_SATELLITE_SIGN_WIDTH  MAIN_LCD_DEVICE_WIDTH/24 //12
#define EM_MINIGPS_SATELLITE_SIGN_POS_X 2
//#define EM_MINIGPS_SATELLITE_NUMBER_POS_Y 270
#define GPS_PI 3.14159265358979323846

#define MMI_EM_MINI_GPS_MINI_CATCHER_LOG_CAP   	  	CUI_INLINE_ITEM_ID_BASE+0
#define MMI_EM_MINI_GPS_MINI_CATCHER_LOG_SEL      	CUI_INLINE_ITEM_ID_BASE+1
#define MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_CAP    	CUI_INLINE_ITEM_ID_BASE+2
#define MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_SEL    	CUI_INLINE_ITEM_ID_BASE+3
#define MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_CAP    	CUI_INLINE_ITEM_ID_BASE+4
#define MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_SEL	   	CUI_INLINE_ITEM_ID_BASE+5
#define MMI_EM_MINI_GPS_MINI_DEBUG_MSG_CAP   		CUI_INLINE_ITEM_ID_BASE+6
#define MMI_EM_MINI_GPS_MINI_DEBUG_MSG_SEL			CUI_INLINE_ITEM_ID_BASE+7
#define MMI_EM_MINI_GPS_MINI_BEE_CAP				CUI_INLINE_ITEM_ID_BASE+8
#define MMI_EM_MINI_GPS_MINI_BEE_SEL				CUI_INLINE_ITEM_ID_BASE+9
#define MMI_EM_MINI_GPS_MINI_BEE_DEBUG_CAP			CUI_INLINE_ITEM_ID_BASE+10
#define MMI_EM_MINI_GPS_MINI_BEE_DEBUG_SEL			CUI_INLINE_ITEM_ID_BASE+11


typedef struct
{
    U16 sate_id;
    S16 elevation;
    S16 azimuth;
    S16 snr;
}sate_t;

typedef struct
{
    MMI_BOOL is_enter_minigps;
    MMI_BOOL is_open_gps_by_minigps;
    MMI_BOOL is_own_screen;
    MMI_BOOL is_parser_enabled_by_other_app;
    S32 conn_port_handle;
    S32 port;
    MMI_BOOL minigps_catcher_log_selected_item;
    MMI_BOOL minigps_file_log_selected_item;
    MMI_BOOL minigps_pc_log_selected_item;
    MMI_BOOL minigps_debug_msg_selected_item;
    MMI_BOOL minigps_bee_selected_item;
    MMI_BOOL minigps_bee_debug_selected_item;

    gdi_handle draw_handle;
    gdi_handle base_handle;

    FLOAT   altitude;          /*Antenna Altitude above/below mean-sea-level (geoid)*/
    FLOAT   ground_speed;   /*Speed over ground, knots*/
    FLOAT   trace_degree;    /*Track mode degrees,north is 0*/

    FLOAT     longitude;
    FLOAT     latitude;
    FLOAT     accuracy;
    mdi_gps_nmea_utc_time_struct utc_time;
    mdi_gps_nmea_utc_date_struct utc_date;
    S8      north_south;
    S8      east_west;

    FLOAT   pdop;
    FLOAT   hdop;
    FLOAT   vdop;
    S8      fix_mode;

    S16     sates_in_view;
    sate_t rsv[MDI_GPS_NMEA_MAX_SVVIEW];

    S16 sates_in_view_gl;
    sate_t rsv_gl[MDI_GPS_NMEA_GL_MAX_SVVIEW];

    S16 sates_in_view_ga;
    sate_t rsv_ga[MDI_GPS_NMEA_GA_MAX_SVVIEW];


    WCHAR show_buffer[1024];
    CHAR nmea_buffer[EM_MINIGPS_MAX_NMEA][EM_MINIGPS_MAX_NMEA_LEN];
    U8 nmea_start;
    U8 nmea_end;
    U8 ttff_index;

    U32 hot_start_time;
    U32 warm_start_time;
    U32 cold_start_time;
    U32 begin_start_time;
    U32 end_start_time;
    MMI_BOOL is_hot_start;
    MMI_BOOL is_warm_start;
    MMI_BOOL is_cold_start;
    MMI_BOOL is_ttff;

    CHAR ttff_time_buffer[3][100];

    S8 last_fix_mode;

    MMI_BOOL is_use_agps;
#if defined(__AGPS_USER_PLANE__)
    supl_mmi_position_struct minigps_ma_position;
#endif
#if defined(__AGPS_CONTROL_PLANE__)
    U16 molr_req_id1;
    //U16 molr_req_id2;

    nvram_ef_agps_cp_config_struct agps_cp_config;
#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    U8 gps_pos_type;
#endif
	MMI_ID minigps_gid;
	MMI_ID setting_inline_id;
} em_minigps_context_struct;

static em_minigps_context_struct *g_minigps_ctx = NULL;

#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
extern U8 mmi_em_dev_minigps_get_pos_type(void);
extern nvram_ef_agps_qop_setting_struct mmi_em_dev_minigps_get_qop_setting();
#endif

#ifdef __AGPS_CONTROL_PLANE__
extern nvram_ef_agps_cp_config_struct mmi_em_dev_minigps_get_cp_setting(void);
#endif /* __AGPS_CONTROL_PLANE__ */

static void em_minigps_enter_main_src(void);
static void em_minigps_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length);
static void em_minigps_exit_main_src(void);
static void em_minigps_exit_sky_chart_src(void);
static void em_minigps_update_sky_chart_src(void);
static void em_minigps_enter_sky_chart_src(void);
static void em_minigps_enter_status_src(void);
static void em_minigps_exit_status_src(void);
static void em_minigps_update_status_string(void);
static void em_minigps_update_status_src(void);
static void em_minigps_enter_nmea_src(void);
static void em_minigps_exit_nmea_src(void);
static void em_minigps_update_nmea_src(void);
static void em_minigps_enter_setting_src(void);
//static void em_minigps_setting_highlight_handler(S32 index);
static void em_minigps_setting_save(void);
static void em_minigps_ttff_highlight_handle(S32 index);
static void em_minigps_ttff_enter_sky_chart(void);
static void em_minigps_enter_ttff_src(void);
static void em_minigps_exit_ttff_src(void);
static void em_minigps_update_ttff_src(void);
static void em_minigps_hot_start(void);
static void em_minigps_warm_start(void);
static void em_minigps_cold_start(void);

static void em_minigps_nmea_gga_callback(mdi_gps_nmea_gga_struct *param);
static void em_minigps_nmea_rmc_callback(mdi_gps_nmea_rmc_struct *param);
static void em_minigps_nmea_gsa_callback(mdi_gps_nmea_gsa_struct *param);
static void em_minigps_nmea_gsv_callback(mdi_gps_nmea_gsv_struct *param);
static void em_minigps_nmea_string_callback(const U8 *buffer, U32 length);

//static void em_minigps_nmea_gngsa_callback(void *param);
//static void em_minigps_nmea_gnrmc_callback(void *param);
static void em_minigps_nmea_gagsa_callback(void *param);
static void em_minigps_nmea_gagsv_callback(void *param);
static void em_minigps_nmea_glgsa_callback(void *param);
static void em_minigps_nmea_glgsv_callback(void *param);

#if defined(__AGPS_CONTROL_PLANE__)
static void em_minigps_agps_cp_callback(S32 type, void *buffer, U32 length);
#endif

#if defined(__AGPS_USER_PLANE__)
static void em_minigps_enter_ma_status_src(void);
static void em_minigps_exit_ma_status_src(void);
static void em_minigps_update_ma_status_string(void);
static void em_minigps_update_ma_status_src(void);
#endif

#ifdef __AGPS_CONTROL_PLANE__
static kal_uint8 mmi_em_dev_minigps_cp_loc_method_map(kal_uint8 loc_method);
#endif /* __AGPS_CONTROL_PLANE__ */

static mmi_ret mmi_em_dev_minigps_minigps_setting_proc(mmi_event_struct* evt);

static void mmi_em_dev_minigps_gps_power_saving_mode(mmi_menu_id mode_id);
static void em_minigps_nmea_accuracy_callback(void *param);
extern double gps_lcsp_gad_decoding_N1(U32 n);
extern double gps_lcsp_gad_decoding_N2(U32 n);

//extern MMI_BOOL is_enter_from_ext;

MMI_EM_INIT_ASM(dev_gps_minigps, g_minigps_ctx, sizeof(em_minigps_context_struct))
/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_minigps_mem_alloc
 * DESCRIPTION
 *  malloc memory for app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_minigps_mem_alloc(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_EM_ASM_INIT_FUNC(dev_gps_minigps);
        MMI_ASSERT(g_minigps_ctx != NULL);
/*	if (!g_minigps_ctx)
	{
		MMI_ASSERT(!"minigps malloc memery fail!");
	}*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_gps_minigps_minigps_exit
 * DESCRIPTION
 *  exit screen group and free memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_gps_minigps_minigps_exit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	em_minigps_exit_main_src();
	MMI_EM_ASM_FREE_FUNC(dev_gps_minigps);
	MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_gps_minigps));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_gps_minigps_main_src_proc
 * DESCRIPTION
 *  the handle function of main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_dev_gps_minigps_main_src_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	cui_menu_event_struct * menu_evt = (cui_menu_event_struct *)evt;
	cui_event_inline_common_struct *inline_common_evt = (cui_event_inline_common_struct*)evt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(inline_common_evt->sender_id == g_minigps_ctx ->setting_inline_id){
		mmi_em_dev_minigps_minigps_setting_proc(evt);
		return MMI_RET_OK;
	}
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
				cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
				break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
			switch(menu_evt->highlighted_menu_id){
				case MENU_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART:
					em_minigps_enter_sky_chart_src();
					break;
				case MENU_ID_EM_DEV_MINI_GPS_MINI_STATUS:
					em_minigps_enter_status_src();
					break;
    			case MENU_ID_EM_DEV_MINI_GPS_MINI_NMEA:
					em_minigps_enter_nmea_src();
					break;
    			case MENU_ID_EM_DEV_MINI_GPS_MINI_SETTING:
					em_minigps_enter_setting_src();
					break;
    			case MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF:
					em_minigps_enter_ttff_src();
					break;
			#if defined(__AGPS_USER_PLANE__)
    			case MENU_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS:
					em_minigps_enter_ma_status_src();
					break;
			#endif
				case MENU_ID_EM_DEV_MINI_GPS_MINI_SLEEP_MODE:
				case MENU_ID_EM_DEV_MINI_GPS_MINI_WAKE_MODE:
				case MENU_ID_EM_DEV_MINI_GPS_MINI_STOP_MODE:
					mmi_em_dev_minigps_gps_power_saving_mode(menu_evt->highlighted_menu_id);
					break;
				default:
					break;
			}
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
			break;
		case EVT_ID_GROUP_DEINIT:
			mmi_em_dev_gps_minigps_minigps_exit();
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_gps_minigps_main_src_draw
 * DESCRIPTION
 *  draw main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_gps_minigps_main_src_draw(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    mmi_id minigps_menu_id;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    g_minigps_ctx->minigps_gid = mmi_frm_group_create(mmi_em_dev_minigps_get_parent_id(),
                               GRP_ID_AUTO_GEN,
                               mmi_em_dev_gps_minigps_main_src_proc, NULL);
    mmi_frm_group_enter(g_minigps_ctx->minigps_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	minigps_menu_id = cui_menu_create(g_minigps_ctx->minigps_gid,
					CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,
                    MENU_ID_EM_DEV_MINI_GPS_MINIGPS,
                    MMI_TRUE,
                    NULL);
	cui_menu_run(minigps_menu_id);
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_cold_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_cold_start_by_mdi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_gps_uart_clear_nvram();
}

static void em_minigps_do_cold_start_register_hdlr(void)
{
    SetProtocolEventHandler(em_minigps_cold_start_by_mdi, MSG_ID_MMI_AGPS_RESET_POSITIONING_IND);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_minigps_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_minigps_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_minigps_ctx == NULL){
	mmi_em_dev_minigps_minigps_mem_alloc();
        g_minigps_ctx->conn_port_handle = -1;
        g_minigps_ctx->is_enter_minigps = MMI_TRUE;
        g_minigps_ctx->is_open_gps_by_minigps = MMI_FALSE;
        g_minigps_ctx->nmea_start = 0;
        g_minigps_ctx->nmea_end = 0;
    }
	gdi_layer_get_base_handle(&g_minigps_ctx->base_handle);

    em_minigps_do_cold_start_register_hdlr();

    em_minigps_enter_main_src();
}

kal_uint8 lcs_get_bcd_byte(kal_uint8 ch){
	kal_uint8 type = ch&0xf0;
	if(ch=='*') return 0xa;
	else if(ch=='#') return 0xb;
	ch = ch - type;
	switch(type){
		case 0x30: // 0~9
			return ch;
		case 0x40: // A~B
		case 0x60: // a~b
			return (ch+0xc);
		default:
			return 0xf; //can't recognized it
	}
}

kal_uint8 lcs_convert_to_general_bcd(kal_uint8 *source, kal_uint8 *dest, kal_uint8 max_dest_len)
{
    kal_uint8 i = 0;
    kal_uint8 lower_byte, upper_byte;
	kal_uint8 cur, offset = 0;

    if ((source == NULL) || (dest == NULL))
    {
        return 0;
    }
	// filter the valid number
	cur = 0;
	if(source[0]=='+'){
		*dest++ = 0x91;
		i = 1;
		offset = 1;
	}
	else i=0;

	//check the validity 0~9, *, #, abc, ABC
	for(;i<max_dest_len;i++){
		if((source[i]>='0' && source[i]<='9')||
		   (source[i]>='a' && source[i]<='c')||
		   (source[i]>='A' && source[i]<='C')||
		   source[i]=='*' || source[i]=='#'
		){
			source[cur++] = source[i];
		}
	}
    if(cur<max_dest_len) source[cur] = RMMI_END_OF_STRING_CHAR;
	i = 0;
    while (source[i] != RMMI_END_OF_STRING_CHAR)
    {
		lower_byte = lcs_get_bcd_byte(source[i]);
		upper_byte = lcs_get_bcd_byte(source[i + 1]);

		if (i >> 1 >= cur)
		{
			return (i >> 1)+offset;
		}

		*((kal_uint8*) dest + (i >> 1)) = (upper_byte << 4) + lower_byte;

		if (source[i + 1] == RMMI_END_OF_STRING_CHAR)
		{
			if (i >> 1 >= cur)
			{
				return (i >> 1) + 1 + offset;
			}

			*((kal_uint8*) dest + (i >> 1)) |= 0xf0;
			return (i >> 1) + 1 + offset;
		}
        i += 2;
    }
    if (i >> 1 >= cur)
    {
        return (i >> 1) + offset;
    }

    *((kal_uint8*) dest + (i >> 1)) = 0xff;
    return (i >> 1) + offset;

}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_main_src
 * DESCRIPTION
 *  open gps/agps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_main_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    MMI_BOOL can_use_agps;
    nvram_ef_agps_qop_setting_struct agps_qop_setting;
#endif
#if defined (__AGPS_USER_PLANE__)
	nvram_em_minigps_up_setting_struct agps_up_setting;
    supl_mmi_qop_struct qop;
#endif
#if defined(__AGPS_CONTROL_PLANE__)
    mmi_ss_molr_begin_req_struct molr_info;
   // S32 ret1;
   // S32 ret2;
   // MMI_BOOL need_store = MMI_FALSE;
	U8 exter_addr[NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN/2];
	U8 mlc_num[NVRAM_EF_AGPS_CP_MLC_NUM_LEN/2];
#endif /* __AGPS_CONTROL_PLANE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_minigps_ctx->is_enter_minigps == MMI_TRUE)
    {
    #if defined(__GPS_SUPPORT__)
        g_minigps_ctx->port = mdi_get_gps_port();
    #endif

    g_minigps_ctx->is_use_agps = MMI_FALSE;

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    g_minigps_ctx->gps_pos_type = mmi_em_dev_minigps_get_pos_type();
    can_use_agps = mmi_gps_check_if_can_use_agps();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_CAN_USE_AGPS,can_use_agps);
        agps_qop_setting = mmi_em_dev_minigps_get_qop_setting();

    #if defined(__AGPS_CONTROL_PLANE__)
        if (can_use_agps && g_minigps_ctx->gps_pos_type == EM_GPS_POS_TYPE_AGPS_CP)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_CP_MODE);
            memset(&molr_info, 0, sizeof(mmi_ss_molr_begin_req_struct));

	    g_minigps_ctx->agps_cp_config = mmi_em_dev_minigps_get_cp_setting();

            g_minigps_ctx->agps_cp_config.molr_location_method = mmi_em_dev_minigps_cp_loc_method_map(g_minigps_ctx->agps_cp_config.molr_location_method);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_MOLR_TYPE,g_minigps_ctx->agps_cp_config.molr_type);
			if (g_minigps_ctx->agps_cp_config.molr_type == 0)
            {
                molr_info.molr.molr_Type = L4C_SS_MOLR_Type_locationEstimate;
                molr_info.molr.validity = L4C_SS_LCS_MOLRArg_lcs_QoS_valid;
                if (g_minigps_ctx->agps_cp_config.molr_location_method != EM_GPS_CP_LOC_METHOD_END)
                {
                    molr_info.molr.validity |= L4C_SS_LCS_MOLRArg_locationMethod_valid;
                    molr_info.molr.locationMethod = (L4C_SS_LocationMethod)g_minigps_ctx->agps_cp_config.molr_location_method;
                }
                molr_info.molr.lcs_QoS.validity = L4C_SS_LCS_QoS_horizontal_accuracy_valid;
                molr_info.molr.lcs_QoS.horizontal_accuracy.numOctets = 1;
                molr_info.molr.lcs_QoS.horizontal_accuracy.stringData[0] = agps_qop_setting.hor_acc;

                if (agps_qop_setting.ver_acc_used)
                {
                    molr_info.molr.lcs_QoS.validity |= L4C_SS_LCS_QoS_vertical_accuracy_valid;
                    molr_info.molr.lcs_QoS.vertical_accuracy.numOctets = 1;
                    molr_info.molr.lcs_QoS.vertical_accuracy.stringData[0] = agps_qop_setting.ver_acc;
                }
                else
                {
                    molr_info.molr.lcs_QoS.vertical_accuracy.numOctets = 0;
                    molr_info.molr.lcs_QoS.vertical_accuracy.stringData[0] = 0;
                }

                if (agps_qop_setting.max_loc_age_used)
                {
                    molr_info.molr.validity |= L4C_SS_LCS_MOLRArg_ageOfLocationInfo_valid;
                    molr_info.molr.ageOfLocationInfo = agps_qop_setting.max_loc_age;
                }
                else
                {
                    molr_info.molr.ageOfLocationInfo = 0;
                }

                if (agps_qop_setting.rsp_time_used)
                {
                    molr_info.molr.lcs_QoS.validity |= L4C_SS_LCS_QoS_responseTime_valid;
                    molr_info.molr.lcs_QoS.responseTime.responseTimeCategory = agps_qop_setting.rsp_time;
                }
                else
                {
                    molr_info.molr.lcs_QoS.validity |= L4C_SS_LCS_QoS_responseTime_valid;
                    molr_info.molr.lcs_QoS.responseTime.responseTimeCategory = L4C_SS_ResponseTimeCategory_delaytolerant;
                }
            }
            else if (g_minigps_ctx->agps_cp_config.molr_type == 1)
            {
                molr_info.molr.molr_Type = L4C_SS_MOLR_Type_assistanceData;
                molr_info.molr.validity = L4C_SS_LCS_MOLRArg_gpsAssistanceData_valid;

                if (g_minigps_ctx->agps_cp_config.molr_location_method != EM_GPS_CP_LOC_METHOD_END)
                {
                    molr_info.molr.validity |= L4C_SS_LCS_MOLRArg_locationMethod_valid;
                    molr_info.molr.locationMethod = (L4C_SS_LocationMethod)g_minigps_ctx->agps_cp_config.molr_location_method;
                }
                molr_info.molr.gpsAssistanceData.numOctets = 6;
                molr_info.molr.gpsAssistanceData.stringData[0] = 0x6F;
                molr_info.molr.gpsAssistanceData.stringData[1] = 0;
                molr_info.molr.gpsAssistanceData.stringData[2] = 0;
                molr_info.molr.gpsAssistanceData.stringData[3] = 0;
                molr_info.molr.gpsAssistanceData.stringData[4] = 0;
                molr_info.molr.gpsAssistanceData.stringData[5] = 0;
            }
			if (g_minigps_ctx->agps_cp_config.molr_external_address_valid)
			{
				molr_info.molr.validity |= L4C_SS_LCS_MOLRArg_lcsClientExternalID_valid;
				molr_info.molr.lcsClientExternalID.validity = L4C_SS_LCSClientExternalID_externalAddress_valid;


				mmi_ucs2_to_asc((CHAR*)exter_addr,(CHAR*)g_minigps_ctx->agps_cp_config.molr_external_address);
				molr_info.molr.lcsClientExternalID.externalAddress.numOctets =
								lcs_convert_to_general_bcd((kal_uint8*)exter_addr,
								(kal_uint8*)molr_info.molr.lcsClientExternalID.externalAddress.stringData,
								mmi_ucs2strlen((CHAR*)g_minigps_ctx->agps_cp_config.molr_external_address));
			}

			if (g_minigps_ctx->agps_cp_config.molr_mlc_number_valid)
			{
							molr_info.molr.validity |= L4C_SS_LCS_MOLRArg_mlc_Number_valid;
							//molr_info.molr.lcsClientExternalID.validity = L4C_SS_LCSClientExternalID_externalAddress_valid;

							mmi_ucs2_to_asc((CHAR*)mlc_num,(CHAR*)g_minigps_ctx->agps_cp_config.molr_mlc_number);
							molr_info.molr.mlc_Number.numOctets =
								lcs_convert_to_general_bcd((kal_uint8*)mlc_num,
								(kal_uint8*)molr_info.molr.mlc_Number.stringData,
								mmi_ucs2strlen((kal_uint8*)g_minigps_ctx->agps_cp_config.molr_mlc_number));
			}

            mmi_gps_mgr_start_molr(
                        &molr_info,
                        MDI_GPS_UART_MODE_LOCATION,
                        &g_minigps_ctx->molr_req_id1,
                        em_minigps_agps_cp_callback);
            //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_CP_START_MOLR,g_minigps_ctx->molr_req_id1);

            mdi_gps_uart_open((U16)g_minigps_ctx->port,MDI_GPS_UART_MODE_RAW_DATA,em_minigps_gps_callback);
            g_minigps_ctx->is_use_agps = MMI_TRUE;
        }
    #endif /* __AGPS_CONTROL_PLANE__ */

    #if defined(__AGPS_USER_PLANE__)
        if (can_use_agps && g_minigps_ctx->gps_pos_type == EM_GPS_POS_TYPE_AGPS_UP)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_UP_MODE);

            mmi_gps_setting_get_up_setting(&agps_up_setting);
            /* set qop filter */
           /* qop.horacc = 22;
            qop.veracc_used = MMI_FALSE;
            qop.maxLocAge_used = MMI_FALSE;
            qop.delay_used = MMI_FALSE;*/

            qop.horacc = agps_qop_setting.hor_acc;
            qop.veracc_used = (kal_bool)agps_qop_setting.ver_acc_used;
            qop.maxLocAge_used = (kal_bool)agps_qop_setting.max_loc_age_used;
            qop.delay_used = (kal_bool)agps_qop_setting.rsp_time_used;
            if (qop.veracc_used == KAL_TRUE)
            {
                qop.veracc = agps_qop_setting.ver_acc;
            }
            else
            {
                qop.veracc = 0;
            }

            if (qop.maxLocAge_used == KAL_TRUE)
            {
                qop.maxLocAge = agps_qop_setting.max_loc_age;
            }
            else
            {
                qop.maxLocAge = 0;
            }

            if (qop.delay_used == KAL_TRUE)
            {
                qop.delay = agps_qop_setting.rsp_time;
            }
            else
            {
                qop.delay = 0;
            }

            if(agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_MB_ONLY || agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_PREF_MB)
            {
                mmi_gps_mgr_open_gps(g_minigps_ctx->port,
                                        MDI_GPS_UART_MODE_LOCATION,
                                        MMI_GPS_WORK_MODE_MB,
                                        &qop,
                                        em_minigps_gps_callback);
                mdi_gps_uart_open((U16)g_minigps_ctx->port,MDI_GPS_UART_MODE_RAW_DATA,em_minigps_gps_callback);
            }
            else if(agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_MA_ONLY || agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_PREF_MA)
            {
                mmi_gps_mgr_open_gps(g_minigps_ctx->port,
                                        MDI_GPS_UART_MODE_LOCATION,
                                        MMI_GPS_WORK_MODE_MA,
                                        &qop,
                                        em_minigps_gps_callback);
                mdi_gps_uart_open((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
            }
			/*
				mmi_gps_mgr_open_gps(g_minigps_ctx->port,
                                        MDI_GPS_UART_MODE_LOCATION,
                                        agps_up_setting.molr_prefer,
                                        &qop,
                                        em_minigps_gps_callback);
                mdi_gps_uart_open((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
            }
			*/
            g_minigps_ctx->is_use_agps = MMI_TRUE;
        }
    #endif /* __AGPS_USER_PLANE__ */
#endif // #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)


        if (g_minigps_ctx->is_use_agps == MMI_FALSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_GPS_MINIGPS_GPS_ONLY);
            if (g_minigps_ctx->port >= 0 && g_minigps_ctx->conn_port_handle == -1)
            {
                g_minigps_ctx->conn_port_handle = mdi_gps_uart_open((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_LOCATION, em_minigps_gps_callback);
                if (g_minigps_ctx->conn_port_handle >= 0 )
                {
                    mdi_gps_set_work_port((U8)g_minigps_ctx->port);
                    g_minigps_ctx->is_open_gps_by_minigps = MMI_TRUE;
                }
                else if (g_minigps_ctx->conn_port_handle == MDI_RES_GPS_UART_ERR_PORT_ALREADY_OPEN)
                {
                    mdi_gps_set_work_port((U8)g_minigps_ctx->port);
                    g_minigps_ctx->is_open_gps_by_minigps = MMI_FALSE;
                }
                /*add this to let GPS send raw data to mmi task then file logging can work*/
                mdi_gps_uart_open((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
                g_minigps_ctx->is_use_agps = MMI_FALSE;
            }
        }

        g_minigps_ctx->is_enter_minigps = MMI_FALSE;
    }

        g_minigps_ctx->is_parser_enabled_by_other_app = mdi_gps_is_parser_enabled();
        if (!g_minigps_ctx->is_parser_enabled_by_other_app)
        {
            mdi_gps_enable_parser();
        }
	mmi_em_dev_gps_minigps_main_src_draw();
}

#if defined(__AGPS_CONTROL_PLANE__)
static void em_minigps_agps_cp_callback(S32 type, void *buffer, U32 length)
{
    em_minigps_gps_callback((mdi_gps_parser_info_enum)type, buffer, length);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  em_minigps_gps_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
        case MDI_GPS_PARSER_NMEA_GGA:
            em_minigps_nmea_gga_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_RMC:
            em_minigps_nmea_rmc_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GSA:
            em_minigps_nmea_gsa_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GSV:
            em_minigps_nmea_gsv_callback(buffer);
            break;
        /*case MDI_GPS_PARSER_NMEA_SENTENCE:
            em_minigps_nmea_string_callback(buffer, length);
            break; */
        case MDI_GPS_PARSER_RAW_DATA:
            em_minigps_nmea_string_callback(buffer, length);
            break;
    #if defined(__AGPS_USER_PLANE__)
        case MDI_GPS_PARSER_MA_STATUS:
            if (g_minigps_ctx)
                memcpy(&g_minigps_ctx->minigps_ma_position, buffer, sizeof(supl_mmi_position_struct));
            break;
    #endif

        case MDI_GPS_PARSER_NMEA_GAGSA:
            em_minigps_nmea_gagsa_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GAGSV:
            em_minigps_nmea_gagsv_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GLGSA:
            em_minigps_nmea_glgsa_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GLGSV:
            em_minigps_nmea_glgsv_callback(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_ACC:
            em_minigps_nmea_accuracy_callback(buffer);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_exit_main_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_main_src(void)
{
    if (!g_minigps_ctx)
    {
        return;
    }
#if defined(__AGPS_CONTROL_PLANE__)
    if (g_minigps_ctx->is_use_agps == MMI_TRUE &&
        g_minigps_ctx->gps_pos_type == EM_GPS_POS_TYPE_AGPS_CP &&
        //g_minigps_ctx->molr_req_id1 != 0 &&
        g_minigps_ctx->molr_req_id1 != 0)
    {
        mmi_gps_mgr_stop_molr(g_minigps_ctx->molr_req_id1);
       // mmi_gps_mgr_stop_molr(g_minigps_ctx->molr_req_id2);
        g_minigps_ctx->molr_req_id1 = 0;
       // g_minigps_ctx->molr_req_id2 = 0;
        mdi_gps_uart_close(g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
    }
#endif

#if defined (__AGPS_USER_PLANE__)
    if (g_minigps_ctx->is_use_agps == MMI_TRUE &&
        g_minigps_ctx->gps_pos_type == EM_GPS_POS_TYPE_AGPS_UP)
    {
	    mmi_gps_mgr_close_gps((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_LOCATION, em_minigps_gps_callback);
	   /* if(agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_MB_ONLY)
	    {
	        mmi_gps_mgr_close_gps((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
	    }
	    else if(agps_up_setting.molr_prefer == EM_GPS_UP_MOLR_MA_ONLY)
	    {
	        mdi_gps_uart_close((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
	    }*/
        mdi_gps_uart_close((U16)g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);
    }
#endif

    if(g_minigps_ctx->is_use_agps == MMI_FALSE)
    {
        if (g_minigps_ctx->is_open_gps_by_minigps == MMI_TRUE)
        {
           if(!g_minigps_ctx->is_parser_enabled_by_other_app)
           {
               mdi_gps_disable_parser();
           }

            mdi_gps_uart_close(g_minigps_ctx->port, MDI_GPS_UART_MODE_LOCATION, em_minigps_gps_callback);
            mdi_gps_uart_close(g_minigps_ctx->port, MDI_GPS_UART_MODE_RAW_DATA, em_minigps_gps_callback);

            g_minigps_ctx->conn_port_handle = -1;
            g_minigps_ctx->is_open_gps_by_minigps = MMI_FALSE;
        }
    }

    gui_cancel_timer(em_minigps_update_sky_chart_src);
    gui_cancel_timer(em_minigps_update_status_string);
    gui_cancel_timer(em_minigps_update_nmea_src);
#if defined (__AGPS_USER_PLANE__)
    gui_cancel_timer(em_minigps_update_ma_status_string);
#endif
    g_minigps_ctx->is_enter_minigps = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_sky_chart_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_sky_chart_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U8 *guiBuffer;              /* Buffer holding history data */
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }


	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_SKY_CHART,
		em_minigps_exit_sky_chart_src,
		em_minigps_enter_sky_chart_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}

    gdi_layer_create(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, &g_minigps_ctx->draw_handle);

//    guiBuffer = mmi_frm_scrn_get_gui_buf(g_minigps_ctx->minigps_gid,SCR_ID_EM_DEV_MINIGPS_SKY_CHART);

    ShowCategory221Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_WHITE,
        NULL);

    g_minigps_ctx->sates_in_view = 0;
    g_minigps_ctx->sates_in_view_gl = 0;
    g_minigps_ctx->sates_in_view_ga = 0;

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	em_minigps_update_sky_chart_src();
	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_sky_chart_src);
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_draw_sky_chart
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_sky_chart_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(em_minigps_update_sky_chart_src);
    if (g_minigps_ctx)
    {
        gdi_layer_free(g_minigps_ctx->draw_handle);
        g_minigps_ctx->draw_handle = 0;
    }
}

static _em_minigps_draw_sate_in_view(sate_t *rsv, U32 sate_num, S32 c_width, S32 c_height, gdi_color sate_color, CHAR* temp)
{
    S32 x;
    S32 y;
    U32 satellite_pos_x;
    U32 satellite_pos_y;
    U32 next_x;

    x = (S32)(EM_MINIGPS_SKY_CHART_IMAGE_RADIUS *
        cos(rsv->elevation * GPS_PI / 180) *
        sin(rsv->azimuth * GPS_PI / 180) +
        EM_MINIGPS_SKY_CHART_IMAGE_POS_X +
        EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2);

    y = (S32)((-1) * (EM_MINIGPS_SKY_CHART_IMAGE_RADIUS *
        cos(rsv->elevation * GPS_PI / 180) *
        cos(rsv->azimuth * GPS_PI / 180)) +
        EM_MINIGPS_SKY_CHART_IMAGE_POS_Y +
        EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2);

    if (rsv->snr > 0)
    {
        gdi_draw_solid_circle((S32)x, (S32)y, EM_MINIGPS_SATELLITE_RADIUS, sate_color);
    }
    else
    {
        gdi_draw_solid_circle((S32)x, (S32)y, EM_MINIGPS_SATELLITE_RADIUS, GDI_COLOR_RED);
    }
    gdi_draw_circle(x, y, EM_MINIGPS_SATELLITE_RADIUS, GDI_COLOR_BLACK);
    gui_move_text_cursor(x - c_width/2 , y - c_height/2);
    sprintf(temp, "%02d", rsv->sate_id);
    gui_printf(temp);

    /*gui_move_text_cursor(
        EM_MINIGPS_SATELLITE_SIGN_POS_X + i * (EM_MINIGPS_SATELLITE_SIGN_WIDTH + 2),
        EM_MINIGPS_SATELLITE_NUMBER_POS_Y);*/
    satellite_pos_x = EM_MINIGPS_SATELLITE_SIGN_POS_X + sate_num * (2*c_width + 5);
    satellite_pos_y = EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 10 * (c_height + 5);

    next_x = satellite_pos_x + c_width;
    while ((next_x) >= MAIN_LCD_DEVICE_WIDTH)
    {
        S32 sate_per_row = (MAIN_LCD_DEVICE_WIDTH - EM_MINIGPS_SATELLITE_SIGN_POS_X) / (2*c_width + 5) + 1;

        //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MiniGPS] skychart, LCD Width[%d], sate_num[%d], c_w[%d], c_h[%d]", MAIN_LCD_DEVICE_WIDTH, sate_num, c_width, c_height);
        //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MiniGPS] skychart, old_x[%d], old_y[%d]", satellite_pos_x, satellite_pos_y);

        sate_num -= sate_per_row;
        next_x -= MAIN_LCD_DEVICE_WIDTH;

        satellite_pos_x = EM_MINIGPS_SATELLITE_SIGN_POS_X + sate_num * (2*c_width + 5);
        satellite_pos_y += 3 * (c_height + 5);
        //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MiniGPS] skychart, new_x[%d], new_y[%d]", satellite_pos_x, satellite_pos_y);
    }

    //gui_set_font(&MMI_medium_font);
    gui_move_text_cursor(
        satellite_pos_x,
        satellite_pos_y);
    sprintf(temp, "%02d", rsv->sate_id);
    gui_printf(temp);

    gdi_draw_solid_rect(
        satellite_pos_x + 2,
        satellite_pos_y - rsv->snr/2 - 2,
        satellite_pos_x + EM_MINIGPS_SATELLITE_SIGN_WIDTH,
        satellite_pos_y - 2,
        GDI_COLOR_GREEN);
    gdi_draw_rect(
        satellite_pos_x + 2,
        satellite_pos_y - rsv->snr/2 - 2,
        satellite_pos_x + EM_MINIGPS_SATELLITE_SIGN_WIDTH,
        satellite_pos_y - 2,
        GDI_COLOR_BLACK);

    gui_move_text_cursor(
        satellite_pos_x,
        satellite_pos_y - rsv->snr/2 - 2 - c_height);
    sprintf(temp, "%02d", rsv->snr);
    gui_printf(temp);
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_update_sky_chart_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_sky_chart_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 x;
	S32 y;
	CHAR temp[100];
	U32 end_time;
    S32 c_height;
    S32 c_width;
    U32 satellite_pos_x;
    U32 satellite_pos_y;
    U32 sate_num = 0;

    CHAR ascii_buffer[20];
    CHAR acc_temp[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
	gdi_layer_set_active(g_minigps_ctx->draw_handle);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_push_clip();
	/*Draw*/
    gui_set_font(&MMI_small_font);
    gui_push_text_clip();
    gui_set_text_clip(
        MMI_CONTENT_X,
        MMI_CONTENT_Y,
        MMI_CONTENT_X + MMI_CONTENT_WIDTH,
        LCD_HEIGHT - 20);
    gui_set_text_color(gui_color(0, 0, 0));

    /*gdi_image_draw_id(
        EM_MINIGPS_SKY_CHART_IMAGE_POS_X,
        EM_MINIGPS_SKY_CHART_IMAGE_POS_Y,
       EM_MINIGIS_SKY_CHART_IMG_ID);*/

    gui_line(EM_MINIGPS_SKY_CHART_IMAGE_POS_X,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2,
             gui_color(0, 0, 0));

    gui_line(EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_Y,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2,
             EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT,
             gui_color(0, 0, 0));

    gdi_draw_circle(EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_RADIUS,
                    GDI_COLOR_BLACK);

    gdi_draw_circle(EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_RADIUS * 2 / 3,
                    GDI_COLOR_BLACK);

    gdi_draw_circle(EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2,
                    EM_MINIGPS_SKY_CHART_IMAGE_RADIUS / 3,
                    GDI_COLOR_BLACK);
    gui_measure_character(L'N',&c_width,&c_height);
    gui_move_text_cursor(
            EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2 - c_width/2,
            EM_MINIGPS_SKY_CHART_IMAGE_POS_Y - c_height/2);
    sprintf(temp, "%c", 'N');
    gui_printf(temp);

    gui_move_text_cursor(
            EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH / 2 - c_width/2,
            EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT - c_height/2);
    sprintf(temp, "%c", 'S');
    gui_printf(temp);

    gui_move_text_cursor(
            EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH - c_width/2,
            EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2 - c_height/2);
    sprintf(temp, "%c", 'E');
    gui_printf(temp);

    gui_move_text_cursor(
            EM_MINIGPS_SKY_CHART_IMAGE_POS_X  - c_width/2,
            EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + EM_MINIGPS_SKY_CHART_IMAGE_HEIGHT / 2 - c_height/2);
    sprintf(temp, "%c", 'W');
    gui_printf(temp);

/*    g_minigps_ctx.sates_in_view = 2;
    g_minigps_ctx.rsv[0].sate_id = 1;
    g_minigps_ctx.rsv[0].elevation = 45;
    g_minigps_ctx.rsv[0].azimuth = 45;
    g_minigps_ctx.rsv[0].snr = 20;
    g_minigps_ctx.rsv[1].sate_id = 11;
    g_minigps_ctx.rsv[1].elevation = 30;
    g_minigps_ctx.rsv[1].azimuth = 30;
    g_minigps_ctx.rsv[1].snr = 40;*/

    for (i = 0; i < g_minigps_ctx->sates_in_view; i++)
    {
        _em_minigps_draw_sate_in_view(&g_minigps_ctx->rsv[i], sate_num, c_width, c_height, GDI_COLOR_GREEN, temp);
        sate_num++;
    }

    for (i = 0; i < g_minigps_ctx->sates_in_view_gl; i++)
        {
        _em_minigps_draw_sate_in_view(&g_minigps_ctx->rsv_gl[i], sate_num, c_width, c_height, GDI_COLOR_GREEN, temp);
        sate_num++;
    }

    for (i = 0; i < g_minigps_ctx->sates_in_view_ga; i++)
    {
        _em_minigps_draw_sate_in_view(&g_minigps_ctx->rsv_ga[i], sate_num, c_width, c_height, GDI_COLOR_GREEN, temp);
        sate_num++;
    }

    if (g_minigps_ctx->utc_date.year >= 0 && g_minigps_ctx->utc_date.year <= 99 &&
        g_minigps_ctx->utc_date.month > 0 && g_minigps_ctx->utc_date.month <= 12 &&
        g_minigps_ctx->utc_date.day > 0 && g_minigps_ctx->utc_date.day <= 31)
    {
        sprintf(temp, "20%02d/%02d/%02d" ,g_minigps_ctx->utc_date.year,g_minigps_ctx->utc_date.month,g_minigps_ctx->utc_date.day);
    }
    else
    {
        strcpy(temp, "0000/00/00");
    }

    gui_move_text_cursor(
        EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
        EM_MINIGPS_SKY_CHART_IMAGE_POS_Y);
    gui_printf(temp);

    if (g_minigps_ctx->utc_time.hour <= 24 && g_minigps_ctx->utc_time.hour >= 0 &&
        g_minigps_ctx->utc_time.minute < 60 && g_minigps_ctx->utc_time.minute >= 0 &&
        g_minigps_ctx->utc_time.second < 60 && g_minigps_ctx->utc_time.second >= 0)
    {
       sprintf(temp, "%02d:%02d:%02d" ,g_minigps_ctx->utc_time.hour,g_minigps_ctx->utc_time.minute,g_minigps_ctx->utc_time.second);
        }
    else
        {
        strcpy(temp, "00:00:00");
        }
	gui_move_text_cursor(
		EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
		EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + c_height + 5);
	gui_printf(temp);

	if (g_minigps_ctx->fix_mode == '1')
	{
		strcpy(temp, "Can't Fixed");
	}
	else if (g_minigps_ctx->fix_mode == '2' || g_minigps_ctx->fix_mode == '3')
	{
		sprintf(temp, "%cD Fixed", g_minigps_ctx->fix_mode);
	}
	else
	{
		strcpy(temp, "No NMEA");
	}
	gui_move_text_cursor(
		EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
		EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 2 * (c_height + 5));
	gui_printf(temp);

	sprintf(temp, "%c %f", g_minigps_ctx->north_south, g_minigps_ctx->latitude);
	gui_move_text_cursor(
		EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
		EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 3 * (c_height + 5));
	gui_printf(temp);

	sprintf(temp, "%c %f", g_minigps_ctx->east_west, g_minigps_ctx->longitude);
	gui_move_text_cursor(
		EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
		EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 4 * (c_height + 5));
	gui_printf(temp);

    if (g_minigps_ctx->is_ttff == MMI_TRUE)
	{
		if (g_minigps_ctx->is_hot_start == MMI_TRUE ||
			g_minigps_ctx->is_warm_start == MMI_TRUE ||
			g_minigps_ctx->is_cold_start == MMI_TRUE)
		{
			kal_get_time(&end_time);
		}
		else
		{
			end_time = g_minigps_ctx->end_start_time;
		}
		sprintf(
			temp,
			"%d:%2d",
			kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000 / 60,
            (kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000 )% 60);
		gui_move_text_cursor(
			EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
			EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 5 * (c_height + 5));
	    gui_printf(temp);
	}

/*Number: --> Num:*/
    sprintf(temp, "Num: %d", g_minigps_ctx->sates_in_view + g_minigps_ctx->sates_in_view_gl + g_minigps_ctx->sates_in_view_ga);
	gui_move_text_cursor(
		EM_MINIGPS_SKY_CHART_IMAGE_POS_X,
		EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 6 * (c_height + 5));
	gui_printf(temp);

    sprintf(temp, "Direction: %f", g_minigps_ctx->trace_degree);
    gui_move_text_cursor(
        EM_MINIGPS_SKY_CHART_IMAGE_POS_X,
        EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 7 * (c_height + 5));
    gui_printf(temp);

    //sprintf(temp, "Acc: %.1f", g_minigps_ctx->accuracy);
    sprintf(ascii_buffer, "%f",g_minigps_ctx->accuracy);
    for(i = 0;i <= mmi_ucs2strlen(ascii_buffer);i++)
    {
    	if(ascii_buffer[i] == '.' || i == mmi_ucs2strlen(ascii_buffer))
    	{
    		acc_temp[i] = '\0';
    		break;
	}
    	else
    		acc_temp[i] = ascii_buffer[i];
    }
    sprintf(temp, "Acc: %s",acc_temp);
    gui_move_text_cursor(
        //EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH - 25,
        EM_MINIGPS_SKY_CHART_IMAGE_POS_X + EM_MINIGPS_SKY_CHART_IMAGE_WIDTH + c_width,
        EM_MINIGPS_SKY_CHART_IMAGE_POS_Y + 6 * (c_height + 5));
    gui_printf(temp);

	gui_pop_text_clip();
	gdi_layer_blt(g_minigps_ctx->base_handle, g_minigps_ctx->draw_handle, 0, 0, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
	gdi_layer_pop_clip();
	gdi_layer_set_active(g_minigps_ctx->base_handle);

	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_sky_chart_src);
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_status_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->is_own_screen = MMI_TRUE;
    em_minigps_update_status_string();
    buffer_size = mmi_ucs2strlen((CHAR *)g_minigps_ctx->show_buffer);

	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_STATUS,
		em_minigps_exit_status_src,
		em_minigps_enter_status_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}
    ShowCategory74Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_STATUS,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)g_minigps_ctx->show_buffer,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_status_src);
	g_minigps_ctx->is_own_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_exit_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_status_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_cancel_timer(em_minigps_update_status_src);
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_update_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_status_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->is_own_screen = MMI_TRUE;
    em_minigps_update_status_string();
    buffer_size = mmi_ucs2strlen((CHAR *)g_minigps_ctx->show_buffer);

	mmi_frm_scrn_close_active_id();
	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_STATUS,
		em_minigps_exit_status_src,
		em_minigps_enter_status_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}

    ShowCategory74Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_STATUS,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)g_minigps_ctx->show_buffer,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_status_src);
	g_minigps_ctx->is_own_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_status_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp[128];
    CHAR time_date_buffer[20];
    CHAR ascii_buffer[128];
    CHAR acc_temp[20];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    mmi_ucs2cpy((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"Date: ");
    if (g_minigps_ctx->utc_date.year >= 0 && g_minigps_ctx->utc_date.year <= 99 &&
        g_minigps_ctx->utc_date.month > 0 && g_minigps_ctx->utc_date.month <= 12 &&
        g_minigps_ctx->utc_date.day > 0 && g_minigps_ctx->utc_date.day <= 31)
    {
       sprintf(time_date_buffer, "20%02d/%02d/%02d" ,g_minigps_ctx->utc_date.year,g_minigps_ctx->utc_date.month,g_minigps_ctx->utc_date.day);
    }
    else
    {
        strcpy(time_date_buffer, "0000/00/00");
    }
	kal_wsprintf(temp, "%s", time_date_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nTime: ");
    if (g_minigps_ctx->utc_time.hour <= 24 && g_minigps_ctx->utc_time.hour >= 0 &&
        g_minigps_ctx->utc_time.minute < 60 && g_minigps_ctx->utc_time.minute >= 0 &&
        g_minigps_ctx->utc_time.second < 60 && g_minigps_ctx->utc_time.second >= 0)
    {
        sprintf(time_date_buffer, "%02d:%02d:%02d" ,g_minigps_ctx->utc_time.hour,g_minigps_ctx->utc_time.minute,g_minigps_ctx->utc_time.second);
    }
    else
    {
        strcpy(time_date_buffer, "00:00:00");
    }
	kal_wsprintf(temp, "%s", time_date_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nLat: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->latitude);
	kal_wsprintf(temp, "%c %s", g_minigps_ctx->north_south, ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nLon: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->longitude);
	kal_wsprintf(temp, "%c %s", g_minigps_ctx->east_west, ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nAlt: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->altitude);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nSpeed: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->ground_speed);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	if (g_minigps_ctx->fix_mode == '1')
	{
       mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nFixed: Can't Fixed");
	}
	else if (g_minigps_ctx->fix_mode == '2' || g_minigps_ctx->fix_mode == '3')
	{
		mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nFixed: ");
		kal_wsprintf(temp, "%cD Fixed", g_minigps_ctx->fix_mode);
		mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
	}
	else
	{
		mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nFixed: No NMEA");
	}

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nDirection: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->trace_degree);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nPDOP: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->pdop);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nHDOP: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->hdop);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nVDOP: ");
	sprintf(ascii_buffer, "%f", g_minigps_ctx->vdop);
	kal_wsprintf(temp, "%s", ascii_buffer);
	mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

        mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\Acc: ");
        sprintf(ascii_buffer, "%f", g_minigps_ctx->accuracy);
        //kal_wsprintf(temp, "%s", ascii_buffer);
        for(i = 0;i <= mmi_ucs2strlen(ascii_buffer);i++)
    		{
    			if(ascii_buffer[i] == '.' || i == mmi_ucs2strlen(ascii_buffer))
    			{
    				acc_temp[i] = '\0';
    				break;
    			}
    			else
    				acc_temp[i] = ascii_buffer[i];
    		}
    		kal_wsprintf(temp, "%s", acc_temp);
    		mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
    		
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_nmea_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_nmea_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }

	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_NMEA,
		em_minigps_exit_nmea_src,
		em_minigps_enter_nmea_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}
    gdi_layer_create(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, &g_minigps_ctx->draw_handle);

	ShowCategory221Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_NMEA,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_WHITE,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	em_minigps_update_nmea_src();
	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_nmea_src);
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_exit_nmea_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_nmea_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(em_minigps_update_nmea_src);
    if (g_minigps_ctx)
    {
        gdi_layer_free(g_minigps_ctx->draw_handle);
        g_minigps_ctx->draw_handle = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_update_nmea_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_nmea_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
	U8 j;
    U8 k;
    U8 line_num;
    S32 nmea_len;
    S32 w;
    S32 h;
	CHAR temp[10][83];
	CHAR* sring_point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
	gdi_layer_set_active(g_minigps_ctx->draw_handle);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_push_clip();
/*Draw*/
	gui_set_font(&MMI_small_font);
	gui_push_text_clip();
	gui_set_text_clip(
		MMI_CONTENT_X,
		MMI_CONTENT_Y,
		MMI_CONTENT_X + MMI_CONTENT_WIDTH,
		LCD_HEIGHT - 29);
	gui_set_text_color(gui_color(0, 0, 0));

	w = gui_get_character_width('a');
	h = gui_get_character_height();

	i = g_minigps_ctx->nmea_end;
	j = 0;
	while (i != g_minigps_ctx->nmea_start)
	{
		for (k = 0; k < 10; k++)
		{
		    temp[k][0] = 0;
		}

		line_num = 0;
		nmea_len = strlen(g_minigps_ctx->nmea_buffer[i]);
		sring_point = &g_minigps_ctx->nmea_buffer[i][0];

		while (nmea_len > (LCD_WIDTH / w))
		{
		    strncpy(temp[line_num], sring_point, LCD_WIDTH / w);
		    temp[line_num][LCD_WIDTH / w] = 0;
			line_num++;
			sring_point = &g_minigps_ctx->nmea_buffer[i][line_num * (LCD_WIDTH / w)];
		    nmea_len = nmea_len - LCD_WIDTH / w;
		}

		if (nmea_len > 0 && line_num == 0)
		{
			strcpy(temp[line_num], sring_point);
			line_num++;
		}

		for (k = 0; k < line_num; k++)
		{
		gui_move_text_cursor(MMI_CONTENT_X, MMI_CONTENT_Y + j * h);
		    gui_printf(temp[k]);
			j++;
		}

		i++;
		if (i >= EM_MINIGPS_MAX_NMEA)
		{
			i = 0;
		}

		if ( (17 - j) < (strlen(g_minigps_ctx->nmea_buffer[i]) / (LCD_WIDTH / w)))
		{
		    break;
		}
	}

	gui_pop_text_clip();

	gdi_layer_blt(g_minigps_ctx->base_handle, g_minigps_ctx->draw_handle, 0, 0, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
	gdi_layer_pop_clip();
	gdi_layer_set_active(g_minigps_ctx->base_handle);

	gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_nmea_src);
}

static const U16 g_mmi_em_minigps_minigps_setting_onoff_str[2] =
{
	STR_GLOBAL_OFF,
	STR_GLOBAL_ON
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_catcher_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_CATCHER,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_catcher_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_file_dump_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_FILE_DUMP,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_file_dump_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_pc_tool_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_PC_TOOL,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_pc_tool_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_debug_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_DUBG_MSG,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_debug_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};

#ifdef __BEE_SUPPORT__
static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_bee_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_SWITCH,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_bee_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_minigps_setting_bee_debug_cap =
{
	STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_DEBUG,
};

static cui_inline_item_select_struct g_mmi_em_minigps_minigps_setting_bee_debug_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_minigps_setting_onoff_str,
};
#endif /* __BEE_SUPPORT__ */

static const cui_inline_set_item_struct g_mmi_em_minigps_minigps_setting_inline[] =
{
    {MMI_EM_MINI_GPS_MINI_CATCHER_LOG_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&g_mmi_em_minigps_minigps_setting_catcher_cap},
    {MMI_EM_MINI_GPS_MINI_CATCHER_LOG_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_catcher_sel},
    {MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_minigps_setting_file_dump_cap},
    {MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_file_dump_sel},
    {MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_mmi_em_minigps_minigps_setting_pc_tool_cap},
    {MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_pc_tool_sel},
    {MMI_EM_MINI_GPS_MINI_DEBUG_MSG_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&g_mmi_em_minigps_minigps_setting_debug_cap},
    {MMI_EM_MINI_GPS_MINI_DEBUG_MSG_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_debug_sel},
    #ifdef __BEE_SUPPORT__
    {MMI_EM_MINI_GPS_MINI_BEE_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&g_mmi_em_minigps_minigps_setting_bee_cap},
    {MMI_EM_MINI_GPS_MINI_BEE_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_bee_sel},
    {MMI_EM_MINI_GPS_MINI_BEE_DEBUG_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&g_mmi_em_minigps_minigps_setting_bee_debug_cap},
    {MMI_EM_MINI_GPS_MINI_BEE_DEBUG_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_minigps_setting_bee_debug_sel},
    #endif
};

static cui_inline_struct g_mmi_em_minigps_minigps_setting_inline_scr =
{
	2 * (3
	+ 1
#ifdef __BEE_SUPPORT__
	+ 2
#endif /* __BEE_SUPPORT__ */
	),
    STR_ID_EM_DEV_MINI_GPS_MINI_SETTING,
    NULL,
#ifdef __MMI_INLINE_SLIM__
    CUI_INLINE_SCREEN_LOOP,
#else
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_minigps_minigps_setting_inline,
};


static mmi_ret mmi_em_dev_minigps_minigps_setting_proc(mmi_event_struct* evt)
{
	cui_event_inline_submit_struct* submit_evt;
	cui_event_inline_notify_struct *notify_evt;
	cui_event_inline_abort_struct  *abort_evt;

	switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
		submit_evt = (cui_event_inline_submit_struct*) evt;
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_CATCHER_LOG_SEL, &(g_minigps_ctx->minigps_catcher_log_selected_item));
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_SEL, &(g_minigps_ctx->minigps_file_log_selected_item));
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_SEL, &(g_minigps_ctx->minigps_pc_log_selected_item));
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_DEBUG_MSG_SEL, &(g_minigps_ctx->minigps_debug_msg_selected_item));
	#ifdef __BEE_SUPPORT__
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_BEE_SEL, &(g_minigps_ctx->minigps_bee_selected_item));
		cui_inline_get_value(submit_evt->sender_id,MMI_EM_MINI_GPS_MINI_BEE_DEBUG_SEL, &(g_minigps_ctx->minigps_bee_debug_selected_item));
	#endif /* __BEE_SUPPORT__ */
		em_minigps_setting_save();
		cui_inline_close(submit_evt->sender_id);
		break;

    case EVT_ID_CUI_INLINE_CSK_PRESS:
        break;

	case EVT_ID_CUI_INLINE_NOTIFY:
		notify_evt = (cui_event_inline_notify_struct *)evt;
		if(notify_evt->event_type == CUI_INLINE_NOTIFY_USER_DEFINED_SELECT_SET_FOCUS)
		{
			cui_inline_set_screen_attributes(notify_evt->sender_id,
											CUI_INLINE_SET_ATTRIBUTE,
										    CUI_INLINE_SCREEN_CHANGED);
		}
		break;

    case EVT_ID_CUI_INLINE_ABORT:
		abort_evt = (cui_event_inline_abort_struct *)evt;
        cui_inline_close(abort_evt->sender_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_setting_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_setting_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer;
//    U8  inline_item_index = 0;
//	MMI_BOOL ret;
//	MMI_ID minigps_setting_gid;
//    MMI_ID minigps_setting_inline_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_minigps_ctx->minigps_gid,SCR_ID_EM_DEV_MINIGPS_SETTING);
    if (!guiBuffer)
    {
        if (mdi_gps_nmea_get_catcher_logging() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_catcher_log_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_catcher_log_selected_item = MMI_FALSE;
        }

        if (mdi_gps_nmea_get_file_logging() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_file_log_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_file_log_selected_item = MMI_FALSE;
        }

        if (mdi_gps_nmea_get_agent_logging() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_pc_log_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_pc_log_selected_item = MMI_FALSE;
        }

         if (mdi_gps_nmea_get_debug_info() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_debug_msg_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_debug_msg_selected_item = MMI_FALSE;
        }
    #ifdef __BEE_SUPPORT__
        if (mdi_gps_nmea_get_hotstill_setting() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_bee_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_bee_selected_item = MMI_FALSE;
        }
        if (mdi_gps_nmea_get_hotstill_debug_setting() == MMI_TRUE)
        {
            g_minigps_ctx->minigps_bee_debug_selected_item = MMI_TRUE;
        }
        else
        {
            g_minigps_ctx->minigps_bee_debug_selected_item = MMI_FALSE;
        }
    #endif
    }

  /*  minigps_setting_gid = mmi_frm_group_create(mmi_em_get_root_group(),
                               GRP_ID_AUTO_GEN,
                               mmi_em_dev_minigps_minigps_setting_proc, NULL);
    mmi_frm_group_enter(minigps_setting_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    minigps_setting_inline_id = cui_inline_create(minigps_setting_gid, &g_mmi_em_minigps_minigps_setting_inline_scr);
*/
	g_minigps_ctx ->setting_inline_id = cui_inline_create(g_minigps_ctx->minigps_gid, &g_mmi_em_minigps_minigps_setting_inline_scr);
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_CATCHER_LOG_SEL, (void *)(g_minigps_ctx->minigps_catcher_log_selected_item));
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_FILE_DUMP_LOG_SEL, (void *)(g_minigps_ctx->minigps_file_log_selected_item));
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_PC_TOOL_LOG_SEL, (void *)(g_minigps_ctx->minigps_pc_log_selected_item));
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_DEBUG_MSG_SEL, (void *)(g_minigps_ctx->minigps_debug_msg_selected_item));
#ifdef __BEE_SUPPORT__
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_BEE_SEL, (void *)(g_minigps_ctx->minigps_bee_selected_item));
	cui_inline_set_value(g_minigps_ctx ->setting_inline_id,MMI_EM_MINI_GPS_MINI_BEE_DEBUG_SEL,(void *)(g_minigps_ctx->minigps_bee_debug_selected_item));
#endif
	cui_inline_run(g_minigps_ctx ->setting_inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_setting_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    if (g_minigps_ctx->minigps_catcher_log_selected_item == 1)
    {
        mdi_gps_nmea_set_catcher_logging(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_catcher_logging(MMI_FALSE);
    }

    if (g_minigps_ctx->minigps_file_log_selected_item == 1)
    {
        mdi_gps_nmea_set_file_logging(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_file_logging(MMI_FALSE);
    }

    if (g_minigps_ctx->minigps_pc_log_selected_item == 1)
    {
        mdi_gps_nmea_set_agent_logging(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_agent_logging(MMI_FALSE);
    }

    if (g_minigps_ctx->minigps_debug_msg_selected_item == 1)
    {
        mdi_gps_nmea_set_debug_info(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_debug_info(MMI_FALSE);
    }
#ifdef __BEE_SUPPORT__
    if (g_minigps_ctx->minigps_bee_selected_item == 1)
    {
        mdi_gps_nmea_set_hotstill_setting(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_hotstill_setting(MMI_FALSE);
    }
    if (g_minigps_ctx->minigps_bee_debug_selected_item == 1)
    {
        mdi_gps_nmea_set_hotstill_debug_setting(MMI_TRUE);
    }
    else
    {
        mdi_gps_nmea_set_hotstill_debug_setting(MMI_FALSE);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_ttff_highlight_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_ttff_highlight_handle(S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_minigps_ctx->ttff_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_ttff_enter_sky_chart
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_ttff_enter_sky_chart(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_minigps_ctx->ttff_index)
    {
        case EM_GPS_HOT_START:
            em_minigps_hot_start();
            break;
        case EM_GPS_WARM_START:
            em_minigps_warm_start();
            break;
        case EM_GPS_COLD_START:
            em_minigps_cold_start();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_ttff_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_ttff_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *StringItem1[3];
	U8 *StringItem2[3];
    U8 i;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    if (g_minigps_ctx->is_use_agps)
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_EM_DEV_MINI_GPS_AGPS_IS_ON),
            IMG_GLOBAL_ERROR,
            0,
            2000,
            0);
        return;
    }

	g_minigps_ctx->is_own_screen = MMI_TRUE;
	g_minigps_ctx->is_ttff = MMI_TRUE;

	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_TTFF,
		em_minigps_exit_ttff_src,
		em_minigps_enter_ttff_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}

	guiBuffer = mmi_frm_scrn_get_gui_buf(g_minigps_ctx->minigps_gid,SCR_ID_EM_DEV_MINIGPS_TTFF);
	nNumofItem = GetNumOfChild_Ext(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF);
	GetSequenceStringIds_Ext(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF, nStrItemList);

    for (i = 0; i < nNumofItem; i++)
	{
        StringItem1[i] = (U8*) GetString(nStrItemList[i]);
	}
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[0], "%d sec", g_minigps_ctx->hot_start_time);
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[1], "%d sec", g_minigps_ctx->warm_start_time);
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[2], "%d sec", g_minigps_ctx->cold_start_time);

    for (i = 0; i < nNumofItem; i++)
	{
        StringItem2[i] = (U8*)g_minigps_ctx->ttff_time_buffer[i];
	}

    SetParentHandler(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF);

    RegisterHighlightHandler(em_minigps_ttff_highlight_handle);

    ShowCategory354Screen(
        (U8*) GetString(STR_ID_EM_DEV_MINI_GPS_MINI_TTFF),
        NULL,
        STR_GLOBAL_DONE,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        StringItem1,
        StringItem2,
        (PU16) gIndexIconsImageList,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(em_minigps_ttff_enter_sky_chart, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	g_minigps_ctx->is_own_screen = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_exit_ttff_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_ttff_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_minigps_ctx)
    {
        return;
    }
    if (mmi_frm_is_in_backward_scenario() || (g_minigps_ctx && g_minigps_ctx->is_own_screen == MMI_FALSE))
    {
        g_minigps_ctx->is_ttff = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_update_ttff_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_ttff_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *StringItem1[3];
	U8 *StringItem2[3];
    U8 i;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->is_own_screen = MMI_TRUE;
	g_minigps_ctx->is_ttff = MMI_TRUE;

	mmi_frm_scrn_close_active_id();
	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_TTFF,
		em_minigps_exit_ttff_src,
		em_minigps_enter_ttff_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_minigps_ctx->minigps_gid,SCR_ID_EM_DEV_MINIGPS_TTFF);

    nNumofItem = GetNumOfChild_Ext(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF);

	GetSequenceStringIds_Ext(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF, nStrItemList);
    for (i = 0; i < nNumofItem; i++)
	{
        StringItem1[i] = (U8*) GetString(nStrItemList[i]);
	}
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[0], "%d sec", g_minigps_ctx->hot_start_time);
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[1], "%d sec", g_minigps_ctx->warm_start_time);
	kal_wsprintf((WCHAR *)g_minigps_ctx->ttff_time_buffer[2], "%d sec", g_minigps_ctx->cold_start_time);

    for (i = 0; i < nNumofItem; i++)
	{
        StringItem2[i] = (U8*)&g_minigps_ctx->ttff_time_buffer[i][0];
	}

    SetParentHandler(MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory354Screen(
        (U8*) GetString(STR_ID_EM_DEV_MINI_GPS_MINI_TTFF),
        NULL,
        STR_GLOBAL_DONE,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        StringItem1,
        StringItem2,
        (PU16) gIndexIconsImageList,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	g_minigps_ctx->is_own_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_hot_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_hot_start(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    kal_get_time(&g_minigps_ctx->begin_start_time);

    mdi_gps_uart_cmd(g_minigps_ctx->port,MDI_GPS_UART_GPS_HOT_START,NULL);
	/*start*/
	g_minigps_ctx->is_hot_start = MMI_TRUE;
	g_minigps_ctx->is_own_screen = MMI_TRUE;
	em_minigps_enter_sky_chart_src();
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_warm_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_warm_start(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    kal_get_time(&g_minigps_ctx->begin_start_time);

	/*start*/
    mdi_gps_uart_cmd(g_minigps_ctx->port,MDI_GPS_UART_GPS_WARM_START,NULL);
	g_minigps_ctx->is_warm_start = MMI_TRUE;
	g_minigps_ctx->is_own_screen = MMI_TRUE;
	em_minigps_enter_sky_chart_src();
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_cold_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_cold_start(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    kal_get_time(&g_minigps_ctx->begin_start_time);
	/*start*/
    mdi_gps_uart_cmd(g_minigps_ctx->port,MDI_GPS_UART_GPS_COLD_START,NULL);
	g_minigps_ctx->is_cold_start = MMI_TRUE;
	g_minigps_ctx->is_own_screen = MMI_TRUE;
	em_minigps_enter_sky_chart_src();
}

/*****************************************************************************
 * FUNCTION
 *  em_minigps_nmea_gga_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_nmea_gga_callback(mdi_gps_nmea_gga_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gga_struct *gga_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_minigps_ctx)
    {
        g_minigps_ctx->altitude = gga_data->altitude;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_nmea_rmc_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_nmea_rmc_callback(mdi_gps_nmea_rmc_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_rmc_struct *rmc_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->latitude = rmc_data->latitude;
    g_minigps_ctx->longitude = rmc_data->longitude;
    g_minigps_ctx->ground_speed = rmc_data->ground_speed;
    g_minigps_ctx->trace_degree = rmc_data->trace_degree;
    memcpy(&(g_minigps_ctx->utc_time), &(rmc_data->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
    memcpy(&(g_minigps_ctx->utc_date), &(rmc_data->utc_date),sizeof(mdi_gps_nmea_utc_date_struct));
    g_minigps_ctx->north_south = rmc_data->north_south;
    g_minigps_ctx->east_west = rmc_data->east_west;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_nmea_gsa_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_nmea_gsa_callback(mdi_gps_nmea_gsa_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gsa_struct *gsa_data = param;
    U32 end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->pdop = gsa_data->pdop;
    g_minigps_ctx->hdop = gsa_data->hdop;
    g_minigps_ctx->vdop = gsa_data->vdop;

    g_minigps_ctx->fix_mode = gsa_data->fix_mode;
#ifdef EM_MINIGPS_TTFF_NEED_3D_FIXED
    if (g_minigps_ctx->last_fix_mode != '3' && g_minigps_ctx->fix_mode == '3')
#else
    if (g_minigps_ctx->last_fix_mode != '2' &&
        g_minigps_ctx->last_fix_mode != '3' &&
        (g_minigps_ctx->fix_mode == '2' || g_minigps_ctx->fix_mode == '3'))
#endif
	{
	    if (g_minigps_ctx->is_hot_start == MMI_TRUE ||
			g_minigps_ctx->is_warm_start == MMI_TRUE ||
			g_minigps_ctx->is_cold_start == MMI_TRUE)
	    {
		kal_get_time(&g_minigps_ctx->end_start_time);
    end_time = g_minigps_ctx->end_start_time;
		if (g_minigps_ctx->is_hot_start == MMI_TRUE)
		{
			g_minigps_ctx->hot_start_time =
				kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
		}
		if (g_minigps_ctx->is_warm_start == MMI_TRUE)
		{
			g_minigps_ctx->warm_start_time =
				kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
		}
		if (g_minigps_ctx->is_cold_start == MMI_TRUE)
		{
			g_minigps_ctx->cold_start_time =
				kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
		}
              g_minigps_ctx->is_hot_start = MMI_FALSE;
              g_minigps_ctx->is_warm_start = MMI_FALSE;
			g_minigps_ctx->is_cold_start = MMI_FALSE;
		if (mmi_frm_scrn_get_active_id() == SCR_ID_EM_DEV_MINIGPS_STATUS)
		{
		    em_minigps_update_ttff_src();
		}
	}
    }
    g_minigps_ctx->last_fix_mode = g_minigps_ctx->fix_mode;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_nmea_gsv_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_nmea_gsv_callback(mdi_gps_nmea_gsv_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gsv_struct *gsv_data = param;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->sates_in_view = gsv_data->sates_in_view;
    for (i = 0; i < MDI_GPS_NMEA_MAX_SVVIEW; i++)
    {
        g_minigps_ctx->rsv[i].sate_id = gsv_data->rsv[i].sate_id;
        g_minigps_ctx->rsv[i].elevation = gsv_data->rsv[i].elevation;
        g_minigps_ctx->rsv[i].azimuth = gsv_data->rsv[i].azimuth;
        g_minigps_ctx->rsv[i].snr = gsv_data->rsv[i].snr;
    }
}



/*****************************************************************************
 * FUNCTION
 *  em_minigps_nmea_string_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_nmea_string_callback(const U8 *buffer, U32 length)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(EM_MINIGPS_MAX_NMEA_LEN >= length);
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->nmea_start++;

	if (g_minigps_ctx->nmea_start >= EM_MINIGPS_MAX_NMEA)
	{
		g_minigps_ctx->nmea_start = 0;
	}
	if (g_minigps_ctx->nmea_start == g_minigps_ctx->nmea_end)
	{
		g_minigps_ctx->nmea_end++;

		if (g_minigps_ctx->nmea_end >= EM_MINIGPS_MAX_NMEA)
		{
			g_minigps_ctx->nmea_end = 0;
		}
	}
	strncpy(g_minigps_ctx->nmea_buffer[g_minigps_ctx->nmea_start], (CHAR *)buffer, length);
	g_minigps_ctx->nmea_buffer[g_minigps_ctx->nmea_start][length] = 0;
}

static void em_minigps_nmea_gagsa_callback(void *param)
{
    gps_common_nmea_gsa_struct *gsa_data = (gps_common_nmea_gsa_struct*)param;
    U32 end_time;

    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->pdop = gsa_data->pdop;
    g_minigps_ctx->hdop = gsa_data->hdop;
    g_minigps_ctx->vdop = gsa_data->vdop;

    g_minigps_ctx->fix_mode = gsa_data->fix_mode;
    //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MiniGPS] em_minigps_nmea_gagsa_callback(), fixed mode=%c", gsa_data->fix_mode);

#ifdef EM_MINIGPS_TTFF_NEED_3D_FIXED
    if (g_minigps_ctx->last_fix_mode != '3' && g_minigps_ctx->fix_mode == '3')
#else
    if (g_minigps_ctx->last_fix_mode != '2' &&
        g_minigps_ctx->last_fix_mode != '3' &&
        (g_minigps_ctx->fix_mode == '2' || g_minigps_ctx->fix_mode == '3'))
#endif
    {
        if (g_minigps_ctx->is_hot_start == MMI_TRUE ||
            g_minigps_ctx->is_warm_start == MMI_TRUE ||
            g_minigps_ctx->is_cold_start == MMI_TRUE)
        {
        kal_get_time(&g_minigps_ctx->end_start_time);
        end_time = g_minigps_ctx->end_start_time;
        if (g_minigps_ctx->is_hot_start == MMI_TRUE)
        {
            g_minigps_ctx->hot_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        if (g_minigps_ctx->is_warm_start == MMI_TRUE)
        {
            g_minigps_ctx->warm_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        if (g_minigps_ctx->is_cold_start == MMI_TRUE)
        {
            g_minigps_ctx->cold_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        g_minigps_ctx->is_hot_start = MMI_FALSE;
        g_minigps_ctx->is_warm_start = MMI_FALSE;
        g_minigps_ctx->is_cold_start = MMI_FALSE;
        if (mmi_frm_scrn_get_active_id() == SCR_ID_EM_DEV_MINIGPS_STATUS)
        {
            em_minigps_update_ttff_src();
        }
    }
    }
    g_minigps_ctx->last_fix_mode = g_minigps_ctx->fix_mode;
}

static void em_minigps_nmea_gagsv_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_common_nmea_gsv_struct *gsv_data = (gps_common_nmea_gsv_struct*)param;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->sates_in_view_ga = gsv_data->sates_in_view;
    for (i = 0; i < gsv_data->sates_in_view; i++)
    {
        g_minigps_ctx->rsv_ga[i].sate_id = gsv_data->rsv[i].sate_id;
        g_minigps_ctx->rsv_ga[i].elevation = gsv_data->rsv[i].elevation;
        g_minigps_ctx->rsv_ga[i].azimuth = gsv_data->rsv[i].azimuth;
        g_minigps_ctx->rsv_ga[i].snr = gsv_data->rsv[i].snr;
    }
}


static void em_minigps_nmea_glgsa_callback(void *param)
{
    gps_common_nmea_gsa_struct *gsa_data = (gps_common_nmea_gsa_struct*)param;
    U32 end_time;

    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->pdop = gsa_data->pdop;
    g_minigps_ctx->hdop = gsa_data->hdop;
    g_minigps_ctx->vdop = gsa_data->vdop;

    g_minigps_ctx->fix_mode = gsa_data->fix_mode;
    //kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MiniGPS] em_minigps_nmea_glgsa_callback(), fixed mode=%c", gsa_data->fix_mode);

#ifdef EM_MINIGPS_TTFF_NEED_3D_FIXED
    if (g_minigps_ctx->last_fix_mode != '3' && g_minigps_ctx->fix_mode == '3')
#else
    if (g_minigps_ctx->last_fix_mode != '2' &&
        g_minigps_ctx->last_fix_mode != '3' &&
        (g_minigps_ctx->fix_mode == '2' || g_minigps_ctx->fix_mode == '3'))
#endif
    {
        if (g_minigps_ctx->is_hot_start == MMI_TRUE ||
            g_minigps_ctx->is_warm_start == MMI_TRUE ||
            g_minigps_ctx->is_cold_start == MMI_TRUE)
        {
        kal_get_time(&g_minigps_ctx->end_start_time);
        end_time = g_minigps_ctx->end_start_time;
        if (g_minigps_ctx->is_hot_start == MMI_TRUE)
        {
            g_minigps_ctx->hot_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        if (g_minigps_ctx->is_warm_start == MMI_TRUE)
        {
            g_minigps_ctx->warm_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        if (g_minigps_ctx->is_cold_start == MMI_TRUE)
        {
            g_minigps_ctx->cold_start_time =
                kal_ticks_to_milli_secs(end_time - g_minigps_ctx->begin_start_time) / 1000;
        }
        g_minigps_ctx->is_hot_start = MMI_FALSE;
        g_minigps_ctx->is_warm_start = MMI_FALSE;
        g_minigps_ctx->is_cold_start = MMI_FALSE;
        if (mmi_frm_scrn_get_active_id() == SCR_ID_EM_DEV_MINIGPS_STATUS)
        {
            em_minigps_update_ttff_src();
        }
    }
    }
    g_minigps_ctx->last_fix_mode = g_minigps_ctx->fix_mode;
}

static void em_minigps_nmea_glgsv_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_common_nmea_gsv_struct *gsv_data = (gps_common_nmea_gsv_struct*)param;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->sates_in_view_gl = gsv_data->sates_in_view;
    for (i = 0; i < gsv_data->sates_in_view; i++)
    {
        g_minigps_ctx->rsv_gl[i].sate_id = gsv_data->rsv[i].sate_id;
        g_minigps_ctx->rsv_gl[i].elevation = gsv_data->rsv[i].elevation;
        g_minigps_ctx->rsv_gl[i].azimuth = gsv_data->rsv[i].azimuth;
        g_minigps_ctx->rsv_gl[i].snr = gsv_data->rsv[i].snr;
    }
}
static void em_minigps_nmea_accuracy_callback(void *param)
{
    gps_common_nmea_accuracy_struct*acc = (gps_common_nmea_accuracy_struct*)param;

    if(!g_minigps_ctx)
    {
        return;
   }
    g_minigps_ctx->accuracy = acc->accuracy;
}
void em_minigps_init_test(void)
{
    mmi_em_dev_minigps_minigps_init();
}


#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_enter_ma_status_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->is_own_screen = MMI_TRUE;
    em_minigps_update_ma_status_string();
    buffer_size = mmi_ucs2strlen((CHAR *)g_minigps_ctx->show_buffer);

	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_MA_STATUS,
		em_minigps_exit_ma_status_src,
		em_minigps_enter_ma_status_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}
    ShowCategory74Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)g_minigps_ctx->show_buffer,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_ma_status_src);
    g_minigps_ctx->is_own_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_exit_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_exit_ma_status_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_cancel_timer(em_minigps_update_ma_status_src);
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_update_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_ma_status_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
	MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    g_minigps_ctx->is_own_screen = MMI_TRUE;
    em_minigps_update_ma_status_string();
    buffer_size = mmi_ucs2strlen((CHAR *)g_minigps_ctx->show_buffer);

	mmi_frm_scrn_close_active_id();
	ret = mmi_frm_scrn_enter(
		g_minigps_ctx->minigps_gid,
		SCR_ID_EM_DEV_MINIGPS_MA_STATUS,
		em_minigps_exit_ma_status_src,
		em_minigps_enter_ma_status_src,
		MMI_FRM_FULL_SCRN
	);
	if(ret == MMI_FALSE){
		return ;
	}

    ShowCategory74Screen(
        STR_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)g_minigps_ctx->show_buffer,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    gui_start_timer(EM_MINIGPS_TIMER_ELAPSE, em_minigps_update_ma_status_src);
	g_minigps_ctx->is_own_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_minigps_enter_status_src
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_minigps_update_ma_status_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp[128];
    CHAR ascii_buffer[128];
    DOUBLE    temp_f;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_minigps_ctx)
    {
        return;
    }
    mmi_ucs2cpy((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"Lat: ");
	temp_f = gps_lcsp_gad_decoding_N1(g_minigps_ctx->minigps_ma_position.pos_estimate.latitude);
    sprintf(ascii_buffer, "%f", temp_f);
    if (g_minigps_ctx->minigps_ma_position.pos_estimate.latitude_sign == SUPL_MMI_SIGN_NORTH)
    {
        kal_wsprintf(temp, "N %s", ascii_buffer);
    }
    else
    {
        kal_wsprintf(temp, "S %s", ascii_buffer);
    }
    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nLon: ");
	temp_f = gps_lcsp_gad_decoding_N2(g_minigps_ctx->minigps_ma_position.pos_estimate.longtude);
    sprintf(ascii_buffer, "%f", temp_f);
    kal_wsprintf(temp, "%s", ascii_buffer);
    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nAlt: ");
    sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.pos_estimate.altitude_info.altitude);
    kal_wsprintf(temp, "%s", ascii_buffer);
    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);

    switch (g_minigps_ctx->minigps_ma_position.velocity.type)
    {
        case SUPL_MMI_VELOCITY_HOR:
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nSpeed: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hor_velocity.hor_speed.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hor_velocity.hor_speed.data[0]);
            }
            else if (g_minigps_ctx->minigps_ma_position.velocity.v.hor_velocity.hor_speed.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hor_velocity.hor_speed.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hor_velocity.hor_speed.data[1] << 8));
            }
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            break;
        case SUPL_MMI_VELOCITY_HOR_AND_VER:
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nSpeed: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.hor_speed.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.hor_speed.data[0]);
            }
            else if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.hor_speed.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.hor_speed.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.hor_speed.data[1] << 8));
            }
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nDirection: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.ver_direction.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.ver_direction.data[0]);
            }
            /*else if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.ver_direction.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.ver_direction.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hv_velocity.ver_direction.data[1] << 8));
            }*/
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            break;
        case SUPL_MMI_VELOCITY_HOR_UNCERT:
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nSpeed: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hor_uncertainty.hor_speed.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hor_uncertainty.hor_speed.data[0]);
            }
            else if (g_minigps_ctx->minigps_ma_position.velocity.v.hor_uncertainty.hor_speed.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hor_uncertainty.hor_speed.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hor_uncertainty.hor_speed.data[1] << 8));
            }
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            break;
        case SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT:
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nSpeed: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.hor_speed.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.hor_speed.data[0]);
            }
            else if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.hor_speed.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.hor_speed.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.hor_speed.data[1] << 8));
            }
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nDirection: ");
            if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.ver_direction.num_bits == 1)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.ver_direction.data[0]);
            }
            /*else if (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.ver_direction.num_bits == 2)
            {
                sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.ver_direction.data[0] +
                        (g_minigps_ctx->minigps_ma_position.velocity.v.hv_uncertainty.ver_direction.data[1] << 8));
            }*/
            else
            {
                sprintf(ascii_buffer, "%f", 0.0);
            }
            kal_wsprintf(temp, "%s", ascii_buffer);
            mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
            break;
    }
    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR *)L"\r\nTime Stemp: ");
    sprintf(ascii_buffer, "%f", (FLOAT)g_minigps_ctx->minigps_ma_position.time_stamp);
    kal_wsprintf(temp, "%s", ascii_buffer);
    mmi_ucs2cat((CHAR*)g_minigps_ctx->show_buffer, (CHAR*)temp);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_gps_power_saving_mode
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_gps_power_saving_mode(mmi_menu_id mode_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL send_cmd = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(mode_id){
		case MENU_ID_EM_DEV_MINI_GPS_MINI_SLEEP_MODE:
			mdi_gps_uart_cmd((U16)g_minigps_ctx->port,MDI_GPS_UART_GPS_SLEEP,NULL);
			send_cmd = MMI_TRUE;
			break;
		case MENU_ID_EM_DEV_MINI_GPS_MINI_WAKE_MODE:
			mdi_gps_uart_cmd((U16)g_minigps_ctx->port,MDI_GPS_UART_GPS_WAKE_UP,NULL);
			send_cmd = MMI_TRUE;
			break;
		case MENU_ID_EM_DEV_MINI_GPS_MINI_STOP_MODE:
			mdi_gps_uart_cmd((U16)g_minigps_ctx->port,MDI_GPS_UART_GPS_STOP,NULL);
			send_cmd = MMI_TRUE;
			break;
		default:
	 		break;
	}
	if(send_cmd){
		mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DONE),
								MMI_EVENT_SUCCESS,
								g_minigps_ctx ->minigps_gid,
								NULL);
	}
}


#ifdef __AGPS_CONTROL_PLANE__
static kal_uint8 mmi_em_dev_minigps_cp_loc_method_map(kal_uint8 loc_method)
{
    kal_uint8 l4c_loc_method = EM_GPS_CP_LOC_METHOD_END;
    switch(loc_method){
        case EM_GPS_CP_LOC_METHOD_NONE:
            break;
	    case EM_GPS_CP_LOC_METHOD_AGPS:
            l4c_loc_method = L4C_SS_LocationMethod_assistedGPS;
            break;
        case EM_GPS_CP_LOC_METHOD_MB_EOTD:
            l4c_loc_method = L4C_SS_LocationMethod_msBasedEOTD;
            break;
        case EM_GPS_CP_LOC_METHOD_MA_EOTD:
            l4c_loc_method = L4C_SS_LocationMethod_msAssistedEOTD;
            break;
        case EM_GPS_CP_LOC_METHOD_MB_OTDOA:
            l4c_loc_method = L4C_SS_LocationMethod_msBasedOTDOA;
            break;
        default:
            break;
    }
    return l4c_loc_method;
}
#endif /* __AGPS_CONTROL_PLANE__ */

#endif /* defined(__GPS_SUPPORT__) */

