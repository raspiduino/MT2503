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
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYERS
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYERS SOLE AND EXCLUSIVE REMEDY AND MEDIATEKS ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEKS OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
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
 * EngineerModeGPS.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __GPS_SUPPORT__

#include "EngineerModeGPS.h"
#include "EngineerModeMiniGPS.h"
#include "inlinecuigprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "gps_init.h"
#include "MDI_gps.h"
#include "gpssetting.h"
#include "menucuigprot.h"
#include "MMIDataType.h"

#include "mmi_rp_app_engineermode1_def.h"
#include "mmi_gps_nvram_def.h"

#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "ImeGprot.h"
#include "GlobalResDef.h"
#include "GPSGprot.h"
#include "cbm_api.h"
#include "Wgui_categories_util.h"


#define MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_CAP     	CUI_INLINE_ITEM_ID_BASE+0
#define MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_SEL     	CUI_INLINE_ITEM_ID_BASE+1
#define MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_CAP     	CUI_INLINE_ITEM_ID_BASE+2
#define MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL     	CUI_INLINE_ITEM_ID_BASE+3
#define MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_CAP     	CUI_INLINE_ITEM_ID_BASE+4
#define MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_SEL   	CUI_INLINE_ITEM_ID_BASE+5
#define MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_CAP   CUI_INLINE_ITEM_ID_BASE+6
#define MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_EDT  	CUI_INLINE_ITEM_ID_BASE+7
#define MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_CAP  		CUI_INLINE_ITEM_ID_BASE+8
#define MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_SEL  		CUI_INLINE_ITEM_ID_BASE+9
#define MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_CAP  	CUI_INLINE_ITEM_ID_BASE+10
#define MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_EDT		CUI_INLINE_ITEM_ID_BASE+11
#define MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_CAP  		CUI_INLINE_ITEM_ID_BASE+12
#define MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_SEL  		CUI_INLINE_ITEM_ID_BASE+13
#define MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_CAP 	 	CUI_INLINE_ITEM_ID_BASE+14
#define MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_SEL			CUI_INLINE_ITEM_ID_BASE+15
#define MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_CAP 	 	CUI_INLINE_ITEM_ID_BASE+16
#define MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_SEL			CUI_INLINE_ITEM_ID_BASE+17
#define MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_CAP 	 	CUI_INLINE_ITEM_ID_BASE+18
#define MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_SEL		CUI_INLINE_ITEM_ID_BASE+19
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_CAP 	 	CUI_INLINE_ITEM_ID_BASE+20
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_SEL			CUI_INLINE_ITEM_ID_BASE+21
#define MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_CAP     	CUI_INLINE_ITEM_ID_BASE+22
#define MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_TXT     	CUI_INLINE_ITEM_ID_BASE+23
#define MMI_EM_DEV_MINI_GPS_VER_ACCU_CAP     	    CUI_INLINE_ITEM_ID_BASE+24
#define MMI_EM_DEV_MINI_GPS_VER_ACCU_SEL     	    CUI_INLINE_ITEM_ID_BASE+25
#define MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_CAP     	CUI_INLINE_ITEM_ID_BASE+26
#define MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_TXT     	CUI_INLINE_ITEM_ID_BASE+27
#define MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_CAP         CUI_INLINE_ITEM_ID_BASE+28
#define MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_SEL         CUI_INLINE_ITEM_ID_BASE+29
#define MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_CAP     CUI_INLINE_ITEM_ID_BASE+30
#define MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_TXT     CUI_INLINE_ITEM_ID_BASE+31
#define MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_CAP        CUI_INLINE_ITEM_ID_BASE+32
#define MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_SEL        CUI_INLINE_ITEM_ID_BASE+33
#define MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_CAP    CUI_INLINE_ITEM_ID_BASE+34
#define MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_SEL    CUI_INLINE_ITEM_ID_BASE+35
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_CAP    CUI_INLINE_ITEM_ID_BASE+36
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_TXT    CUI_INLINE_ITEM_ID_BASE+37
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_CAP    CUI_INLINE_ITEM_ID_BASE+38
#define MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_TXT    CUI_INLINE_ITEM_ID_BASE+39

#define MMI_GPS_MAX_LOC_AGE_BUFFER_LEN 6
#define MMI_GPS_HOR_ACCU_BUFFER_LEN 4

#define MMI_GPS_MAX_SUPL_NOTIFY_TIME_BUFFER_LEN 8
#define MMI_GPS_MAX_SUPL_UT_TIMER_LEN 4

void em_gps_enter_main_src(void);
MMI_ID mmi_em_dev_minigps_get_parent_id(void);
static void		mmi_em_dev_minigps_alloc_mem(void);
static mmi_ret  mmi_em_dev_minigps_proc(mmi_event_struct* evt);

#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
static void		mmi_em_dev_minigps_molr_setting_scr(void);
static mmi_ret 	mmi_em_dev_minigps_molr_setting_proc(mmi_event_struct* evt);
U8 				mmi_em_dev_minigps_get_pos_type(void);
nvram_ef_agps_qop_setting_struct mmi_em_dev_minigps_get_qop_setting();
#endif /* defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__) */

#if defined(__AGPS_USER_PLANE__)
static void		mmi_em_dev_minigps_up_setting_scr(void);
static mmi_ret  mmi_em_dev_minigps_up_setting_proc(mmi_event_struct* evt);
static void 	mmi_em_dev_minigps_up_setting_save(void);
static void     mmi_em_dev_minigps_open_socket_connection(void);
#endif /* #if defined(__AGPS_USER_PLANE__) */

#ifdef __AGPS_CONTROL_PLANE__
static void		mmi_em_dev_minigps_cp_setting_scr(void);
static mmi_ret  mmi_em_dev_minigps_cp_setting_proc(mmi_event_struct* evt);
static void 	mmi_em_dev_minigps_cp_setting_ask_if_save(void);
static void		mmi_em_dev_minigps_cp_setting_save(void);
static void 	mmi_em_dev_minigps_cp_setting_exit(void);
nvram_ef_agps_cp_config_struct mmi_em_dev_minigps_get_cp_setting(void);
#endif /* __AGPS_CONTROL_PLANE__ */

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
MMI_BOOL    mmi_em_dev_minigps_get_auto_reset_apgs(void);
void		mmi_em_dev_minigps_reset_agps_data(void);
static void	mmi_em_dev_minigps_auto_reset_apgs_data(void);
static mmi_ret 	mmi_em_dev_minigps_auto_reset_apgs_data_proc(mmi_event_struct* evt);
#endif
static void	mmi_em_dev_minigps_gps_em_shortcut(void);
static mmi_ret 	mmi_em_dev_minigps_gps_em_shortcut_proc(mmi_event_struct* evt);

static MMI_BOOL     mmi_em_dev_minigps_stop_proc(void);
typedef struct
{
#ifdef __AGPS_CONTROL_PLANE__
    nvram_ef_agps_cp_config_struct agps_cp_config;
    U8 agps_cp_molr_type_selected_item;
	U8 agps_cp_loc_method_selected_item;
    U8 agps_cp_external_address_selected_item;
    U8 exter_addr[NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN];
    U8 agps_cp_mlc_number_selected_item;
    U8 mlc_number[NVRAM_EF_AGPS_CP_MLC_NUM_LEN];
	MMI_ID em_cp_setting_inline_id;
#endif

#if defined(__AGPS_USER_PLANE__)
	nvram_em_minigps_up_setting_struct minigps_up_setting;
    nvram_ef_agps_supl_notify_struct agps_supl_notify;
	U8 agps_up_payload_selected_item;
	U8 agps_up_molr_prefer_selected_item;
	U8 agps_up_soc_conn_selected_item;
	U8 agps_up_supl_tls_selected_item;
	MMI_ID em_up_setting_inline_id;
#endif

#if	defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
        nvram_ef_agps_qop_setting_struct agps_qop_setting;
	U8 agps_molr_selected_item;
	MMI_ID em_molr_setting_inline_id;
	MMI_ID em_auto_reset_menu_id;
#endif
	U8 gps_em_shortcut_is_on;
	U8 gps_auto_reset_is_on;
        U8 app_id;
	MMI_ID em_shortcut_menu_id;
	MMI_ID em_gps_gid;
} mmi_em_dev_minigps_cntx_struct;

MMI_BOOL is_enter_from_ext;

mmi_em_dev_minigps_cntx_struct *g_gps_cntx_p = NULL;

MMI_EM_INIT_ASM(dev_minigps, g_gps_cntx_p, sizeof(mmi_em_dev_minigps_cntx_struct))
/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_alloc_mem
 * DESCRIPTION
 *  malloc memory for minigps' structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_alloc_mem()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_gps_cntx_p == NULL)
    {
	    MMI_EM_ASM_INIT_FUNC(dev_minigps);
        MMI_ASSERT(g_gps_cntx_p != NULL);
/*	    if (!g_gps_cntx_p)
	    {
	        MMI_ASSERT(!"minigps malloc memery fail!");
	    }*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_stop
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_free_mem()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
	if(g_gps_cntx_p->gps_auto_reset_is_on == 1){
	    mmi_em_dev_minigps_reset_agps_data();
	}*/
    MMI_EM_ASM_FREE_FUNC(dev_minigps);
    MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_minigps));

    if(is_enter_from_ext == MMI_TRUE){
        mmi_em_dev_minigps_stop_proc();
        is_enter_from_ext = MMI_FALSE;
    }
}

#if defined(__AGPS_CONTROL_PLANE__)||defined(__AGPS_USER_PLANE__)
static const cui_inline_item_caption_struct g_mmi_em_minigps_molr_pos_type_cap =
{
    STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE,
};

static const U16 g_mmi_em_minigps_molr_pos_type_str[] =
{
#if defined(__AGPS_USER_PLANE__)
	STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_UP,
#endif
	STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_CP,
	STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_GPS
};

static cui_inline_item_select_struct g_mmi_em_minigps_molr_pos_type_sel =
{
    sizeof(g_mmi_em_minigps_molr_pos_type_str)/sizeof(g_mmi_em_minigps_molr_pos_type_str[0]), 0, (U16*)g_mmi_em_minigps_molr_pos_type_str,
};


static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_hor_accu_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_HOR_ACCU_VAL,
};
static const cui_inline_item_text_edit_struct g_mmi_em_minigps_qop_hor_accu_val_txt =
{
        0,
        STR_GLOBAL_EDIT,
        MMI_GPS_MAX_LOC_AGE_BUFFER_LEN,
        IMM_INPUT_TYPE_NUMERIC,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
};


static const U16 g_mmi_em_minigps_qop_on_off[2] = {STR_GLOBAL_OFF,STR_GLOBAL_ON};

static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_ver_accu_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_VER_ACCU,
};
static cui_inline_item_select_struct g_mmi_em_minigps_qop_ver_accu_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_qop_on_off,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_ver_accu_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_VER_ACCU_VAL,
};
static const cui_inline_item_text_edit_struct g_mmi_em_minigps_qop_ver_accu_val_txt =
{
        0,
        STR_GLOBAL_EDIT,
        MMI_GPS_MAX_LOC_AGE_BUFFER_LEN,
        IMM_INPUT_TYPE_NUMERIC,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
};


static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_max_loc_age_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_MAX_LOC_AGE,
};
static cui_inline_item_select_struct g_mmi_em_minigps_qop_max_loc_age_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_qop_on_off,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_max_loc_age_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_MAX_LOC_AGE_VAL,
};
static const cui_inline_item_text_edit_struct g_mmi_em_minigps_qop_max_loc_age_val_txt =
{
        0,
        STR_GLOBAL_EDIT,
        MMI_GPS_MAX_LOC_AGE_BUFFER_LEN,
        IMM_INPUT_TYPE_NUMERIC,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
};


static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_rsp_time_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_RSP_TIME,
};
static cui_inline_item_select_struct g_mmi_em_minigps_qop_rsp_time_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_qop_on_off,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_qop_rsp_time_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_QOP_RSP_TIME_VAL,
};
static const U16 g_mmi_em_minigps_qop_rsp_time[8] = {STR_ID_EM_DEV_MINI_GPS_RSP_TIME_0,STR_ID_EM_DEV_MINI_GPS_RSP_TIME_1,
                                                     STR_ID_EM_DEV_MINI_GPS_RSP_TIME_2,STR_ID_EM_DEV_MINI_GPS_RSP_TIME_3,
                                                     STR_ID_EM_DEV_MINI_GPS_RSP_TIME_4,STR_ID_EM_DEV_MINI_GPS_RSP_TIME_5,
                                                     STR_ID_EM_DEV_MINI_GPS_RSP_TIME_6,STR_ID_EM_DEV_MINI_GPS_RSP_TIME_7};
static const cui_inline_item_select_struct g_mmi_em_minigps_qop_rsp_time_val_sel =
{
     8, 0, (U16*)g_mmi_em_minigps_qop_rsp_time,
};

static const cui_inline_set_item_struct g_mmi_em_minigps_molr_pos_type_inline[] =
{
    {MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&g_mmi_em_minigps_molr_pos_type_cap},
	{MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_molr_pos_type_sel},
    {MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_CAP,     CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_qop_hor_accu_val_cap},
    {MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_TXT,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_mmi_em_minigps_qop_hor_accu_val_txt},
    {MMI_EM_DEV_MINI_GPS_VER_ACCU_CAP,         CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_mmi_em_minigps_qop_ver_accu_cap},
    {MMI_EM_DEV_MINI_GPS_VER_ACCU_SEL,         CUI_INLINE_ITEM_TYPE_SELECT,   0,  (void*)&g_mmi_em_minigps_qop_ver_accu_sel},
    {MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_CAP,     CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&g_mmi_em_minigps_qop_ver_accu_val_cap},
    {MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_TXT,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_mmi_em_minigps_qop_ver_accu_val_txt},
    {MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_CAP,      CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&g_mmi_em_minigps_qop_max_loc_age_cap},
    {MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_SEL,      CUI_INLINE_ITEM_TYPE_SELECT,   0,  (void*)&g_mmi_em_minigps_qop_max_loc_age_sel},
    {MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_CAP,  CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&g_mmi_em_minigps_qop_max_loc_age_val_cap},
    {MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_TXT,  CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_mmi_em_minigps_qop_max_loc_age_val_txt},
    {MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_CAP,     CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L7, (void*)&g_mmi_em_minigps_qop_rsp_time_cap},
    {MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_SEL,     CUI_INLINE_ITEM_TYPE_SELECT,   0,  (void*)&g_mmi_em_minigps_qop_rsp_time_sel},
    {MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L8, (void*)&g_mmi_em_minigps_qop_rsp_time_val_cap},
    {MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_SEL, CUI_INLINE_ITEM_TYPE_SELECT,   0,  (void*)&g_mmi_em_minigps_qop_rsp_time_val_sel},
};

static cui_inline_struct g_mmi_em_minigps_molr_pos_type_inline_scr =
{
    16,
    STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING,
    NULL,
#ifdef __MMI_INLINE_SLIM__
    CUI_INLINE_SCREEN_LOOP,
#else
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_minigps_molr_pos_type_inline,
};

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_get_pos_type
 * DESCRIPTION
 *  read position type value from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_em_dev_minigps_get_pos_type()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadRecord(NVRAM_EF_EM_GPS_POS_TYPE_LID, 1, &data, NVRAM_EF_EM_GPS_POS_TYPE_SIZE, &error);
    if (data == 0xff)
    {
        data = 0;
        WriteRecord(NVRAM_EF_EM_GPS_POS_TYPE_LID, 1, &data, NVRAM_EF_EM_GPS_POS_TYPE_SIZE, &error);
    }
	return data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_get_qop_setting
 * DESCRIPTION
 *  get setting values of control plane from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
nvram_ef_agps_qop_setting_struct mmi_em_dev_minigps_get_qop_setting()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL need_store = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_AGPS_QOP_SETTING_LID, 1, (void*)&g_gps_cntx_p->agps_qop_setting, NVRAM_EF_AGPS_QOP_SETTING_SIZE, &error);
    if (g_gps_cntx_p->agps_qop_setting.hor_acc == 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.hor_acc = 18;
        need_store = MMI_TRUE;
    }

    if (g_gps_cntx_p->agps_qop_setting.ver_acc_used == 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.ver_acc_used = 0;
        need_store = MMI_TRUE;
    }
    if (g_gps_cntx_p->agps_qop_setting.ver_acc == 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.ver_acc = 18;
        need_store = MMI_TRUE;
    }

    if (g_gps_cntx_p->agps_qop_setting.max_loc_age_used== 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.max_loc_age_used = 0;
        need_store = MMI_TRUE;
    }
    if (g_gps_cntx_p->agps_qop_setting.max_loc_age == 0xffff)
    {
        g_gps_cntx_p->agps_qop_setting.max_loc_age = 60;
        need_store = MMI_TRUE;
    }

    if (g_gps_cntx_p->agps_qop_setting.rsp_time_used== 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.rsp_time_used = 0;
        need_store = MMI_TRUE;
    }
	if (g_gps_cntx_p->agps_qop_setting.rsp_time == 0xff)
    {
        g_gps_cntx_p->agps_qop_setting.rsp_time = 6;
        need_store = MMI_TRUE;
    }


    if (need_store)
    {
        WriteRecord(NVRAM_EF_AGPS_QOP_SETTING_LID, 1, (void*)&g_gps_cntx_p->agps_qop_setting, NVRAM_EF_AGPS_QOP_SETTING_SIZE, &error);
    }
    return g_gps_cntx_p->agps_qop_setting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_set_qop_setting
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_set_qop_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 max_loc_age_chr[MMI_GPS_MAX_LOC_AGE_BUFFER_LEN];
    U16 max_loc_age_ucs2[MMI_GPS_MAX_LOC_AGE_BUFFER_LEN];
    U32 max_loc_age;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,
                                     MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_SEL,
                                     &(g_gps_cntx_p->agps_molr_selected_item));
    WriteRecord(NVRAM_EF_EM_GPS_POS_TYPE_LID,1,&(g_gps_cntx_p->agps_molr_selected_item),NVRAM_EF_EM_GPS_POS_TYPE_SIZE,&error);

	cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_TXT,(void *)(max_loc_age_ucs2));
    mmi_ucs2_to_asc((CHAR*)max_loc_age_chr, (CHAR*)max_loc_age_ucs2);
    max_loc_age = atoi((U8 *)max_loc_age_chr);
    if (max_loc_age < 1 || max_loc_age > 254)
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_FAILURE, NULL);
        return;
    }
    g_gps_cntx_p->agps_qop_setting.hor_acc = max_loc_age;

    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_VER_ACCU_SEL,(void *)&(g_gps_cntx_p->agps_qop_setting.ver_acc_used));
    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_TXT,(void *)(max_loc_age_ucs2));
    mmi_ucs2_to_asc((CHAR*)max_loc_age_chr, (CHAR*)max_loc_age_ucs2);
    max_loc_age = atoi((U8 *)max_loc_age_chr);
    if (max_loc_age < 1 || max_loc_age > 254)
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_FAILURE, NULL);
        return;
    }
    g_gps_cntx_p->agps_qop_setting.ver_acc = max_loc_age;

    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_SEL,(void *)&(g_gps_cntx_p->agps_qop_setting.max_loc_age_used));
    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_TXT,(void *)(max_loc_age_ucs2));
    mmi_ucs2_to_asc((CHAR*)max_loc_age_chr, (CHAR*)max_loc_age_ucs2);
    max_loc_age = atoi((U8 *)max_loc_age_chr);
    if (max_loc_age < 1 || max_loc_age > 65534)
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_FAILURE, NULL);
        return;
    }
    g_gps_cntx_p->agps_qop_setting.max_loc_age = max_loc_age;


    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_SEL,(void *)&(g_gps_cntx_p->agps_qop_setting.rsp_time_used));
    cui_inline_get_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_SEL,(void *)&(g_gps_cntx_p->agps_qop_setting.rsp_time));

	WriteRecord(NVRAM_EF_AGPS_QOP_SETTING_LID, 1, (void*)&g_gps_cntx_p->agps_qop_setting, NVRAM_EF_AGPS_QOP_SETTING_SIZE, &error);
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED),
                        MMI_EVENT_SUCCESS,
                        g_gps_cntx_p->em_gps_gid,
                        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_molr_setting_scr
 * DESCRIPTION
 *  entry molr setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_molr_setting_scr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hor_vacc_buf[MMI_GPS_HOR_ACCU_BUFFER_LEN * 2];
    U8 ver_vacc_buf[MMI_GPS_HOR_ACCU_BUFFER_LEN * 2];
    U8 max_loc_age[MMI_GPS_MAX_LOC_AGE_BUFFER_LEN * 2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gps_cntx_p->em_molr_setting_inline_id = cui_inline_create(g_gps_cntx_p->em_gps_gid, &g_mmi_em_minigps_molr_pos_type_inline_scr);
	g_gps_cntx_p->agps_molr_selected_item = mmi_em_dev_minigps_get_pos_type();

	cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,
								 MMI_EM_DEV_MINI_GPS_MOLR_POS_TYPE_SEL,
								 (void *)(g_gps_cntx_p->agps_molr_selected_item));

    mmi_em_dev_minigps_get_qop_setting();

    kal_wsprintf((WCHAR *)hor_vacc_buf, "%d", g_gps_cntx_p->agps_qop_setting.hor_acc);
	cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_HOR_ACCU_VAL_TXT,(void *)(hor_vacc_buf));

    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_VER_ACCU_SEL,(void *)(g_gps_cntx_p->agps_qop_setting.ver_acc_used));
    kal_wsprintf((WCHAR *)ver_vacc_buf, "%d", g_gps_cntx_p->agps_qop_setting.ver_acc);
    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_VER_ACCU_VAL_TXT,(void *)(ver_vacc_buf));

    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_SEL,(void *)(g_gps_cntx_p->agps_qop_setting.max_loc_age_used));
    kal_wsprintf((WCHAR *)max_loc_age, "%d", g_gps_cntx_p->agps_qop_setting.max_loc_age);
    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_LOC_AGE_VAL_TXT,(void *)(max_loc_age));
    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_SEL,(void *)(g_gps_cntx_p->agps_qop_setting.rsp_time_used));
    cui_inline_set_value(g_gps_cntx_p->em_molr_setting_inline_id,MMI_EM_DEV_MINI_GPS_MAX_RSP_TIME_VAL_SEL,(void *)(g_gps_cntx_p->agps_qop_setting.rsp_time));

    cui_inline_run(g_gps_cntx_p->em_molr_setting_inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_molr_setting_proc
 * DESCRIPTION
 *  process the molr setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_dev_minigps_molr_setting_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
        mmi_em_dev_minigps_set_qop_setting();
		cui_inline_close(inline_evt->sender_id);
		break;
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(inline_evt->sender_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}
#endif /* defined(__AGPS_CONTROL_PLANE__)||defined(__AGPS_USER_PLANE__) */


#if defined(__AGPS_USER_PLANE__)
static const cui_inline_item_caption_struct g_mmi_em_minigps_up_payload_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD,
};

static const U16 g_mmi_em_minigps_up_payload_str[3] =
{
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_BOTH,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_RRLP,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_RRC
};

static cui_inline_item_select_struct g_mmi_em_minigps_up_payload_sel =
{
    3, 0, (U16*)g_mmi_em_minigps_up_payload_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_up_molr_pref_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF,
};

static const U16 g_mmi_em_minigps_up_molr_pref_str[5] =
{
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MB,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MA,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_NONE,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MB_ONLY,
	STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MA_ONLY
};

static cui_inline_item_select_struct g_mmi_em_minigps_up_molr_pref_sel =
{
    5, 0, (U16*)g_mmi_em_minigps_up_molr_pref_str,
};


static const cui_inline_item_caption_struct g_mmi_em_minigps_soc_conn_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SOC_CONN,
};

static const U16 g_mmi_em_minigps_soc_conn_str[2] = {STR_GLOBAL_OFF,STR_GLOBAL_ON};

static cui_inline_item_select_struct g_mmi_em_minigps_soc_conn_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_soc_conn_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_supl_tls_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_TLS_SETTING,
};

static const U16 g_mmi_em_minigps_supl_tls_str[2] = {STR_GLOBAL_ON,STR_GLOBAL_OFF};

static cui_inline_item_select_struct g_mmi_em_minigps_supl_tls_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_supl_tls_str,
};

/* supl nofity timer setting */
static const cui_inline_item_caption_struct g_mmi_em_minigps_supl_notify_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_NOTIFY,
};
static const cui_inline_item_text_edit_struct g_mmi_em_minigps_supl_notify_txt =
{
        0,
        STR_GLOBAL_EDIT,
        MMI_GPS_MAX_SUPL_NOTIFY_TIME_BUFFER_LEN,
        IMM_INPUT_TYPE_NUMERIC,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
};

/* supl ut timer setting */
static const cui_inline_item_caption_struct g_mmi_em_minigps_supl_ut_timer_cap =
{
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_UT_TIMER,
};
static const cui_inline_item_text_edit_struct g_mmi_em_minigps_supl_ut_timer_txt =
{
        0,
        STR_GLOBAL_EDIT,
        MMI_GPS_MAX_SUPL_UT_TIMER_LEN,
        IMM_INPUT_TYPE_NUMERIC,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
};

static const cui_inline_set_item_struct g_mmi_em_minigps_up_setting_inline[] =
{
    {MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&g_mmi_em_minigps_up_payload_cap},
    {MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_up_payload_sel},
    {MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_up_molr_pref_cap},
    {MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_up_molr_pref_sel},
    {MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_mmi_em_minigps_soc_conn_cap},
    {MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_soc_conn_sel},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&g_mmi_em_minigps_supl_tls_cap},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_supl_tls_sel},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_supl_notify_cap},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_TXT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_CENTER_JUSTIFY, 0, (void*)&g_mmi_em_minigps_supl_notify_txt},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_supl_ut_timer_cap},
    {MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_TXT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT| CUI_INLINE_ITEM_CENTER_JUSTIFY, 0, (void*)&g_mmi_em_minigps_supl_ut_timer_txt},
};

static cui_inline_struct g_mmi_em_minigps_up_setting_inline_scr =
{
    12,
    STR_ID_EM_DEV_MINI_GPS_UP_SETTING,
    NULL,
#ifdef __MMI_INLINE_SLIM__
    CUI_INLINE_SCREEN_LOOP,
#else
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_minigps_up_setting_inline,
};

static void mmi_em_dev_minigps_set_supl_notify_setting(void)
{
    U8 max_supl_notify_chr[MMI_GPS_MAX_SUPL_NOTIFY_TIME_BUFFER_LEN];
    U16 max_supl_notify_ucs2[MMI_GPS_MAX_SUPL_NOTIFY_TIME_BUFFER_LEN];
    U32 max_supl_notify;

    cui_inline_get_value(g_gps_cntx_p->em_up_setting_inline_id, MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_TXT,(void *)(max_supl_notify_ucs2));
    mmi_ucs2_to_asc((CHAR*)max_supl_notify_chr, (CHAR*)max_supl_notify_ucs2);
    max_supl_notify = atoi((CHAR *)max_supl_notify_chr);
    g_gps_cntx_p->agps_supl_notify.notify_time = max_supl_notify;

    if (max_supl_notify < 1 || max_supl_notify > 65534)
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_FAILURE, NULL);
        return;
    }

    mmi_gps_setting_set_supl_notify_setting(&g_gps_cntx_p->agps_supl_notify);

    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED),
                        MMI_EVENT_SUCCESS,
                        g_gps_cntx_p->em_gps_gid,
                        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_up_setting_scr
 * DESCRIPTION
 *  cui of up related settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_up_setting_scr()
{
    U8 notify_time_buffer[MMI_GPS_MAX_SUPL_NOTIFY_TIME_BUFFER_LEN * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_cntx_p->em_up_setting_inline_id = cui_inline_create(g_gps_cntx_p->em_gps_gid, &g_mmi_em_minigps_up_setting_inline_scr);

    mmi_gps_setting_get_up_setting(&g_gps_cntx_p->minigps_up_setting);
    mmi_gps_setting_get_supl_notify_setting(&g_gps_cntx_p->agps_supl_notify);

	cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id,MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_SEL,(void *)(g_gps_cntx_p->minigps_up_setting.payload));
	cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id,MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_SEL,(void *)(g_gps_cntx_p->minigps_up_setting.molr_prefer));
	cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id,MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_SEL,(void *)(g_gps_cntx_p->agps_up_soc_conn_selected_item));
	cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id,MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_SEL,(void *)(g_gps_cntx_p->agps_up_supl_tls_selected_item));

    kal_wsprintf((WCHAR *)notify_time_buffer, "%d", g_gps_cntx_p->agps_supl_notify.notify_time);
    cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id, MMI_EM_DEV_MINI_GPS_UP_SUPL_NOTIFY_TXT,(void *)(notify_time_buffer));

    kal_wsprintf((WCHAR *)notify_time_buffer, "%d", g_gps_cntx_p->minigps_up_setting.ut_timer);
    cui_inline_set_value(g_gps_cntx_p->em_up_setting_inline_id, MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_TXT,(void *)(notify_time_buffer));

	cui_inline_run(g_gps_cntx_p->em_up_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_up_setting_proc
 * DESCRIPTION
 *  process of minigps up setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_dev_minigps_up_setting_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
	cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
		cui_inline_get_value(inline_evt->sender_id,MMI_EM_DEV_MINI_GPS_UP_PAY_LOAD_SEL,&(g_gps_cntx_p->agps_up_payload_selected_item));
		cui_inline_get_value(inline_evt->sender_id,MMI_EM_DEV_MINI_GPS_UP_MOLR_PRE_SEL,&(g_gps_cntx_p->agps_up_molr_prefer_selected_item));
		cui_inline_get_value(inline_evt->sender_id,MMI_EM_DEV_MINI_GPS_UP_SOC_CONN_SEL,&(g_gps_cntx_p->agps_up_soc_conn_selected_item));
		cui_inline_get_value(inline_evt->sender_id,MMI_EM_DEV_MINI_GPS_UP_SUPL_TLS_SEL,&(g_gps_cntx_p->agps_up_supl_tls_selected_item));
		mmi_em_dev_minigps_up_setting_save();

        mmi_em_dev_minigps_set_supl_notify_setting();
		cui_inline_close(inline_evt->sender_id);
		break;

    case EVT_ID_CUI_INLINE_NOTIFY:
		if(notify_evt->event_type == CUI_INLINE_NOTIFY_USER_DEFINED_SELECT_SET_FOCUS)
			{
				cui_inline_set_screen_attributes(notify_evt->sender_id,
												 CUI_INLINE_SET_ATTRIBUTE,
												 CUI_INLINE_SCREEN_CHANGED);
			}
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(inline_evt->sender_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_up_setting_save
 * DESCRIPTION
 *  save minigps up setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_up_setting_save()
{
    mmi_em_dev_minigps_open_socket_connection();

    if (g_gps_cntx_p->agps_up_supl_tls_selected_item == 0)
    {
        g_gps_cntx_p->minigps_up_setting.use_tls = KAL_TRUE;
    }
    else
    {
        g_gps_cntx_p->minigps_up_setting.use_tls = KAL_FALSE;
    }

    g_gps_cntx_p->minigps_up_setting.payload = g_gps_cntx_p->agps_up_payload_selected_item;

	g_gps_cntx_p->minigps_up_setting.molr_prefer = g_gps_cntx_p->agps_up_molr_prefer_selected_item;

    /* ut timer */
    {
        U8 max_supl_ut_timer_chr[MMI_GPS_MAX_SUPL_UT_TIMER_LEN];
        U16 max_supl_ut_timer_ucs2[MMI_GPS_MAX_SUPL_UT_TIMER_LEN];
        U32 max_supl_ut_timer;

        cui_inline_get_value(g_gps_cntx_p->em_up_setting_inline_id, MMI_EM_DEV_MINI_GPS_UP_SUPL_UT_TIMER_TXT,(void *)(max_supl_ut_timer_ucs2));
        mmi_ucs2_to_asc((CHAR*)max_supl_ut_timer_chr, (CHAR*)max_supl_ut_timer_ucs2);
        max_supl_ut_timer = atoi((CHAR *)max_supl_ut_timer_chr);

        if (max_supl_ut_timer < 1 || max_supl_ut_timer > 254)
        {
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_FAILURE, NULL);
            return;
        }
        g_gps_cntx_p->minigps_up_setting.ut_timer = (U8)max_supl_ut_timer;
    }

    mmi_gps_setting_set_up_setting(&g_gps_cntx_p->minigps_up_setting);

    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED),
                                MMI_EVENT_SUCCESS,
                                g_gps_cntx_p->em_gps_gid,
                                NULL);
}

U8 em_gps_soc_id = 255;
/*****************************************************************************
 * FUNCTION
 *  em_gps_open_soc
 * DESCRIPTION
	open socket
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_open_soc(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 val = 0;
    nvram_ef_agps_profile_struct agps_profile;
    U32 data_account;
    U8 sim_id;
    sockaddr_struct soc_addr;
    //MMI_BOOL ip_valid;
    U32 nwk_account_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(em_gps_soc_id == 255)
    {
        cbm_register_app_id(&g_gps_cntx_p->app_id);

        sim_id = mmi_gps_setting_get_sim();
        data_account = mmi_gps_setting_get_data_account(sim_id);
        mmi_gps_setting_get_profile(&agps_profile);

        nwk_account_id = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)sim_id, g_gps_cntx_p->app_id, MMI_FALSE);

        em_gps_soc_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0/*IPPROTO_TCP*/, MOD_MMI, nwk_account_id);

        /* set socket options */
        val = KAL_TRUE;
        soc_setsockopt(em_gps_soc_id , SOC_NBIO, &val, sizeof(val));

        val = SOC_READ|SOC_WRITE|SOC_CONNECT|SOC_CLOSE;
        soc_setsockopt(em_gps_soc_id, SOC_ASYNC, &val, sizeof(val));

        soc_addr.sock_type = SOC_SOCK_STREAM;
        soc_addr.addr_len = IP_ADDR_LEN;
        soc_addr.port = agps_profile.port;
        soc_addr.addr[0] = 1;
        soc_addr.addr[1] = 1;
        soc_addr.addr[2] = 1;
        soc_addr.addr[3] = 1;

        soc_connect(em_gps_soc_id,&soc_addr);
/*
        agps_profile.data_account = mmi_gps_setting_get_data_account(mmi_gps_setting_get_sim());
        em_gps_soc_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, agps_profile.data_account);
        val = KAL_TRUE;
        ret = soc_setsockopt(em_gps_soc_id , SOC_NBIO, &val, sizeof(val));
        val = SOC_READ|SOC_WRITE|SOC_CONNECT|SOC_CLOSE;
        ret = soc_setsockopt(em_gps_soc_id, SOC_ASYNC, &val, sizeof(val));

        cbm_open_bearer(agps_profile.data_account);*/
    }
    else
    {
        /*MMI_PRINT(MOD_MMI, TRACE_GROUP_1, "em_gps_soc_id=%d", em_gps_soc_id);*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  em_gps_close_soc
 * DESCRIPTION

 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_close_soc(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(em_gps_soc_id != 255)
    {
        soc_close(em_gps_soc_id);
        cbm_deregister_app_id(g_gps_cntx_p->app_id);
        em_gps_soc_id = 255;
        GoBackHistory();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_open_socket_connection
 * DESCRIPTION
 *  open or close socket connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_open_socket_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_gps_cntx_p->agps_up_soc_conn_selected_item == 1){
	    em_gps_open_soc();
	}else if(g_gps_cntx_p->agps_up_soc_conn_selected_item == 0){
		em_gps_close_soc();
	}
}

#endif /* defined(__AGPS_USER_PLANE__) */

static MMI_BOOL em_gps_wait_chip_reset = MMI_FALSE;
MMI_BOOL b_em_gps_reset_chip_104 = MMI_FALSE;
MMI_BOOL b_em_gps_reset_chip_103 = MMI_FALSE;

void em_gps_gps_reset_chip_on_104(void)
{
    b_em_gps_reset_chip_104 = MMI_TRUE;
    b_em_gps_reset_chip_103 = MMI_FALSE;
    DisplayPopup((U8*)GetString(STR_GLOBAL_ON), 0, 0, 1500, 0);
}
void em_gps_gps_reset_chip_off_104(void)
{
    b_em_gps_reset_chip_104 = MMI_FALSE;
    DisplayPopup((U8*)GetString(STR_GLOBAL_OFF), 0, 0, 1500, 0);
}

void em_gps_gps_reset_chip_on_103(void)
{
    b_em_gps_reset_chip_103 = MMI_TRUE;
    b_em_gps_reset_chip_104 = MMI_FALSE;
    DisplayPopup((U8*)GetString(STR_GLOBAL_ON), 0, 0, 1500, 0);
}
void em_gps_gps_reset_chip_off_103(void)
{
    b_em_gps_reset_chip_103 = MMI_FALSE;
    DisplayPopup((U8*)GetString(STR_GLOBAL_OFF), 0, 0, 1500, 0);
}

static S16 em_gps_port = 0;
static U8 em_gps_cmd_type = 0;
/*****************************************************************************
 * FUNCTION
 *  em_gps_gps_callback
 * DESCRIPTION
 *  DUMMY function for gps callback to open port
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void em_gps_gps_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
    return;
}


/*****************************************************************************
 * FUNCTION
 *  em_gps_uart_p_callback
 * DESCRIPTION
 *  callback function for SYSTEM_START_OK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_uart_p_callback(mdi_gps_parser_p_info_enum type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type == MDI_GPS_PARSER_P_SYSTEM_START_OK)
    {
        if(em_gps_wait_chip_reset == MMI_TRUE)
        {
            switch (em_gps_cmd_type)
            {
                case EM_GPS_SEND_CMD_WARM_START:
                {
                    mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_WARM_START,NULL);
                    break;
                }
                case EM_GPS_SEND_CMD_COLD_START:
                {
                    mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_COLD_START,NULL);
                    break;
                }
                case EM_GPS_SEND_CMD_CLEAR_NVRAM:
                {
                    mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_CLEAR_NVRAM,NULL);
                    break;
                }
				case EM_GPS_SEND_CMD_AGPS_START:
				{
					mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_AGPS_START,NULL);
                    break;
				}
                default:
                {
                    mdi_gps_register_p_callback(NULL);
                    mdi_gps_uart_close(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
					break;
                }
            }
            em_gps_wait_chip_reset = MMI_FALSE;
            em_gps_cmd_type = 0;
        }
        else
        {
            mdi_gps_register_p_callback(NULL);
            mdi_gps_uart_close(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
            DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_OK, 0, 500, 0);
        }
    }
}

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_reset_data_to_factory(Send PMTK106)
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_reset_agps_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef GPS_MOD_ON_BROAD
        em_gps_port = 0;
    #else
        em_gps_port = mdi_get_gps_port();
    #endif
    mdi_gps_register_p_callback(em_gps_uart_p_callback);
    ret = mdi_gps_uart_open(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
    mdi_gps_set_work_port((U8)em_gps_port);
    if(ret == MDI_RES_GPS_UART_READY_TO_WRITE)
    {
        mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_AGPS_START,NULL);
        em_gps_wait_chip_reset = MMI_FALSE;
        return;
    }
    em_gps_wait_chip_reset = MMI_TRUE;
    em_gps_cmd_type = EM_GPS_SEND_CMD_AGPS_START;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  em_gps_reset_data_104(Send PMTK104)
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_reset_data_104(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef GPS_MOD_ON_BROAD
        em_gps_port = 0;
    #else
        em_gps_port = mdi_get_gps_port();
    #endif
    mdi_gps_register_p_callback(em_gps_uart_p_callback);
    ret = mdi_gps_uart_open(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
    mdi_gps_set_work_port((U8)em_gps_port);
    if(ret == MDI_RES_GPS_UART_READY_TO_WRITE)
    {
        mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_CLEAR_NVRAM,NULL);
        em_gps_wait_chip_reset = MMI_FALSE;
        return;
    }
    em_gps_wait_chip_reset = MMI_TRUE;
    em_gps_cmd_type = EM_GPS_SEND_CMD_CLEAR_NVRAM;
}

/*****************************************************************************
 * FUNCTION
 *  em_gps_reset_data_103(Send PMTK103)
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_reset_data_103(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef GPS_MOD_ON_BROAD
        em_gps_port = 0;
    #else
        em_gps_port = mdi_get_gps_port();
    #endif
    mdi_gps_register_p_callback(em_gps_uart_p_callback);
    ret = mdi_gps_uart_open(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
    mdi_gps_set_work_port((U8)em_gps_port);
    if(ret == MDI_RES_GPS_UART_READY_TO_WRITE)
    {
        mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_COLD_START,NULL);
        em_gps_wait_chip_reset = MMI_FALSE;
        return;
    }
    em_gps_wait_chip_reset = MMI_TRUE;
    em_gps_cmd_type = EM_GPS_SEND_CMD_COLD_START;
}

/*****************************************************************************
 * FUNCTION
 *  em_gps_reset_data_102(Send PMTK102)
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_gps_reset_data_102(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef GPS_MOD_ON_BROAD
        em_gps_port = 0;
    #else
        em_gps_port = mdi_get_gps_port();
    #endif
    mdi_gps_register_p_callback(em_gps_uart_p_callback);
    ret = mdi_gps_uart_open(em_gps_port, MDI_GPS_UART_MODE_LOCATION, em_gps_gps_callback);
    mdi_gps_set_work_port((U8)em_gps_port);
    if(ret == MDI_RES_GPS_UART_READY_TO_WRITE)
    {
        mdi_gps_uart_cmd(em_gps_port,MDI_GPS_UART_GPS_WARM_START,NULL);
        em_gps_wait_chip_reset = MMI_FALSE;
        return;
    }
    em_gps_wait_chip_reset = MMI_TRUE;
    em_gps_cmd_type = EM_GPS_SEND_CMD_WARM_START;
}

#ifdef __AGPS_CONTROL_PLANE__
static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_molr_type_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR,
};

static const U16 g_mmi_em_minigps_cp_molr_type_str[2] =
{
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR_LOC_EST,
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR_ASS_DATA
};

static cui_inline_item_select_struct g_mmi_em_minigps_cp_molr_type_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_cp_molr_type_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_loc_method_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD,
};

static const U16 g_mmi_em_minigps_cp_loc_method_str[5] =
{
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_NONE,
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_AGPS,
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MB_EOTD,
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MA_EOTD,
	STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MB_OTDOA
};

static cui_inline_item_select_struct g_mmi_em_minigps_cp_loc_method_sel =
{
    5, 0, (U16*)g_mmi_em_minigps_cp_loc_method_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_exter_addr_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_EADDR,
};

static const U16 g_mmi_em_minigps_cp_exter_addr_str[2] = {STR_GLOBAL_OFF,STR_GLOBAL_ON};

static cui_inline_item_select_struct g_mmi_em_minigps_cp_exter_addr_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_cp_exter_addr_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_exter_addr_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_EADDR_VALUE,
};

static const cui_inline_item_fullscreen_edit_struct g_mmi_em_minigps_cp_exter_addr_val_edit =
{
    0,
    0,
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_EADDR_VALUE,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_SENTENCE,
    NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN/2,
    NULL
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_mlc_num_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MLC,
};

static const U16 g_mmi_em_minigps_cp_mlc_num_str[2] = {STR_GLOBAL_OFF,STR_GLOBAL_ON};

static cui_inline_item_select_struct g_mmi_em_minigps_cp_mlc_num_sel =
{
    2, 0, (U16*)g_mmi_em_minigps_cp_mlc_num_str,
};

static const cui_inline_item_caption_struct g_mmi_em_minigps_cp_mlc_num_val_cap =
{
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MLC_VALUE,
};

static const cui_inline_item_fullscreen_edit_struct g_mmi_em_minigps_cp_mlc_num_val_edit =
{
    0,
    0,
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MLC_VALUE,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_SENTENCE,
    NVRAM_EF_AGPS_CP_MLC_NUM_LEN/2,
    NULL
};

static const cui_inline_set_item_struct g_mmi_em_minigps_cp_setting_inline[] =
{
	{MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&g_mmi_em_minigps_cp_molr_type_cap},
	{MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_cp_molr_type_sel},
	{MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_mmi_em_minigps_cp_loc_method_cap},
	{MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_cp_loc_method_sel},
	{MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_mmi_em_minigps_cp_exter_addr_cap},
	{MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_cp_exter_addr_sel},
    {MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&g_mmi_em_minigps_cp_exter_addr_val_cap},
    {MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_EDT, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&g_mmi_em_minigps_cp_exter_addr_val_edit},
    {MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&g_mmi_em_minigps_cp_mlc_num_cap},
    {MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_minigps_cp_mlc_num_sel},
    {MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&g_mmi_em_minigps_cp_mlc_num_val_cap},
    {MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_EDT, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&g_mmi_em_minigps_cp_mlc_num_val_edit},
};

static cui_inline_struct g_mmi_em_minigps_cp_setting_inline_scr =
{
    12,
    STR_ID_EM_DEV_MINI_GPS_CP_SETTING,
    NULL,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_minigps_cp_setting_inline,
};

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_get_cp_setting
 * DESCRIPTION
 *  get setting values of control plane from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
nvram_ef_agps_cp_config_struct mmi_em_dev_minigps_get_cp_setting()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL need_store = MMI_FALSE;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_AGPS_CP_CONFIG_LID, 1, (void*)&g_gps_cntx_p->agps_cp_config, NVRAM_EF_AGPS_CP_CONFIG_SIZE, &error);
    if (g_gps_cntx_p->agps_cp_config.molr_type == 0xff)
    {
        g_gps_cntx_p->agps_cp_config.molr_type = 0;
        need_store = MMI_TRUE;
    }

    if (g_gps_cntx_p->agps_cp_config.molr_location_method == 0xff)
    {
        g_gps_cntx_p->agps_cp_config.molr_location_method = 0;
        need_store = MMI_TRUE;
    }

    if (g_gps_cntx_p->agps_cp_config.molr_external_address_valid == 0xff)
    {
        g_gps_cntx_p->agps_cp_config.molr_external_address_valid = 0;
        need_store = MMI_TRUE;
    }

    for (i = 0; i < NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN; i++)
    {
        if (g_gps_cntx_p->agps_cp_config.molr_external_address[i] != 0xff)
        {
            break;
        }
    }

    if (i == NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN)
    {
        kal_mem_set(
            g_gps_cntx_p->agps_cp_config.molr_external_address,
            0,
            sizeof(g_gps_cntx_p->agps_cp_config.molr_external_address));
        need_store = MMI_TRUE;
    }

	if (g_gps_cntx_p->agps_cp_config.molr_mlc_number_valid == 0xff)
    {
        g_gps_cntx_p->agps_cp_config.molr_mlc_number_valid = 0;
        need_store = MMI_TRUE;
    }

	for (i = 0; i < NVRAM_EF_AGPS_CP_MLC_NUM_LEN; i++)
    {
        if (g_gps_cntx_p->agps_cp_config.molr_mlc_number[i] != 0xff)
        {
            break;
        }
    }

	if (i == NVRAM_EF_AGPS_CP_MLC_NUM_LEN)
    {
        kal_mem_set(
            g_gps_cntx_p->agps_cp_config.molr_mlc_number,
            0,
            sizeof(g_gps_cntx_p->agps_cp_config.molr_mlc_number));
        need_store = MMI_TRUE;
    }

    if (need_store)
    {
        WriteRecord(NVRAM_EF_AGPS_CP_CONFIG_LID, 1, (void*)&g_gps_cntx_p->agps_cp_config, NVRAM_EF_AGPS_CP_CONFIG_SIZE, &error);
    }
	return g_gps_cntx_p->agps_cp_config;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_cp_setting_scr
 * DESCRIPTION
 *  enter setting screen of control plane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_minigps_cp_setting_scr()
{
  	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gps_cntx_p->em_cp_setting_inline_id = cui_inline_create(g_gps_cntx_p->em_gps_gid, &g_mmi_em_minigps_cp_setting_inline_scr);

	mmi_em_dev_minigps_get_cp_setting();
	cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL,(void *)(g_gps_cntx_p->agps_cp_config.molr_type));
	cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_SEL,(void *)(g_gps_cntx_p->agps_cp_config.molr_location_method));
	cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_SEL,(void *)(g_gps_cntx_p->agps_cp_config.molr_external_address_valid));

	if(mmi_ucs2strlen((CHAR*)g_gps_cntx_p->agps_cp_config.molr_external_address) == 0)
	{
		cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_EDT,(void *)GetString((U16) (STR_GLOBAL_NONE)));
	}else{
		cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_EDT,(void *)(g_gps_cntx_p->agps_cp_config.molr_external_address));
		mmi_ucs2cpy((CHAR*)g_gps_cntx_p->exter_addr,(CHAR*)g_gps_cntx_p->agps_cp_config.molr_external_address);
	}
	cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_SEL,(void *)(g_gps_cntx_p->agps_cp_config.molr_mlc_number_valid));
	if(mmi_ucs2strlen((CHAR*)g_gps_cntx_p->agps_cp_config.molr_mlc_number) == 0)
	{
		cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_EDT,(void *)GetString((U16) (STR_GLOBAL_NONE)));
	}else{
		cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_EDT,(void *)(g_gps_cntx_p->agps_cp_config.molr_mlc_number));
		mmi_ucs2cpy((CHAR*)g_gps_cntx_p->mlc_number,(CHAR*)g_gps_cntx_p->agps_cp_config.molr_mlc_number);
	}
    cui_inline_run(g_gps_cntx_p->em_cp_setting_inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_cp_setting_proc
 * DESCRIPTION
 *  process settings of control plane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_dev_minigps_cp_setting_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
	cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
		mmi_em_dev_minigps_cp_setting_ask_if_save();
		break;

	case EVT_ID_CUI_INLINE_NOTIFY:
           if(notify_evt->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED &&
		            notify_evt->item_id == MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL)
           {
				cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL,&(g_gps_cntx_p->agps_cp_molr_type_selected_item));
				/* get select value before changed */
				if(g_gps_cntx_p->agps_cp_molr_type_selected_item == 0){
					g_gps_cntx_p->agps_cp_loc_method_selected_item = EM_GPS_CP_LOC_METHOD_NONE;
				}else{
					g_gps_cntx_p->agps_cp_loc_method_selected_item = EM_GPS_CP_LOC_METHOD_AGPS;
				}
				cui_inline_set_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_SEL,(void *)(g_gps_cntx_p->agps_cp_loc_method_selected_item));
		}
		break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(inline_evt->sender_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_minigps_cp_setting_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_cp_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MOLR_TYPE_SEL,&(g_gps_cntx_p->agps_cp_molr_type_selected_item));
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_LOC_METHOD_SEL,&(g_gps_cntx_p->agps_cp_loc_method_selected_item));
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_SEL,&(g_gps_cntx_p->agps_cp_external_address_selected_item));
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_EXTER_ADDR_VAL_EDT,g_gps_cntx_p->exter_addr);
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_SEL,&(g_gps_cntx_p->agps_cp_mlc_number_selected_item));
	cui_inline_get_value(g_gps_cntx_p->em_cp_setting_inline_id,MMI_EM_DEV_MINI_GPS_CP_MLC_NUM_VAL_EDT,g_gps_cntx_p->mlc_number);

    g_gps_cntx_p->agps_cp_config.molr_type = (g_gps_cntx_p->agps_cp_molr_type_selected_item);
	g_gps_cntx_p->agps_cp_config.molr_location_method = (g_gps_cntx_p->agps_cp_loc_method_selected_item);
	g_gps_cntx_p->agps_cp_config.molr_external_address_valid= (g_gps_cntx_p->agps_cp_external_address_selected_item);
	g_gps_cntx_p->agps_cp_config.molr_mlc_number_valid= (g_gps_cntx_p->agps_cp_mlc_number_selected_item);
	mmi_ucs2cpy((CHAR*)g_gps_cntx_p->agps_cp_config.molr_external_address, (CHAR*)g_gps_cntx_p->exter_addr);
	mmi_ucs2cpy((CHAR*)g_gps_cntx_p->agps_cp_config.molr_mlc_number, (CHAR*)g_gps_cntx_p->mlc_number);

	WriteRecord(NVRAM_EF_AGPS_CP_CONFIG_LID, 1, (void*)&g_gps_cntx_p->agps_cp_config, NVRAM_EF_AGPS_CP_CONFIG_SIZE, &error);
	mmi_frm_scrn_close_active_id();
	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED),
							MMI_EVENT_SUCCESS,
							g_gps_cntx_p->em_gps_gid,
							NULL);
	cui_inline_close(g_gps_cntx_p->em_cp_setting_inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  em_gps_not_save_agps_cp_config
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_minigps_cp_setting_exit(void)
{
	cui_inline_close(g_gps_cntx_p->em_cp_setting_inline_id);
	mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_cp_setting_ask_if_save
* DESCRIPTION
*  show screen to ask user if need save the change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_dev_minigps_cp_setting_ask_if_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        (UI_string_type)GetString(STR_GLOBAL_YES),
        (PU8)GetImage(IMG_GLOBAL_YES),
        (UI_string_type)GetString(STR_GLOBAL_NO),
        (PU8)GetImage(IMG_GLOBAL_NO),
        (UI_string_type) GetString(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_em_dev_minigps_cp_setting_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_em_dev_minigps_cp_setting_exit, KEY_EVENT_UP);
}

#endif /*__AGPS_CONTROL_PLANE__*/


#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_auto_reset_apgs_data
* DESCRIPTION
*  whether show sms number
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_dev_minigps_auto_reset_apgs_data()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gps_cntx_p->em_auto_reset_menu_id = cui_menu_create(g_gps_cntx_p->em_gps_gid,
					CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPSUB,
                    MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS,
                    MMI_TRUE,
                    NULL);
	if(g_gps_cntx_p->gps_auto_reset_is_on == 1)
	{
		cui_menu_set_currlist_highlighted_id(g_gps_cntx_p->em_auto_reset_menu_id,MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_ON);
	}else {
		cui_menu_set_currlist_highlighted_id(g_gps_cntx_p->em_auto_reset_menu_id,MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_OFF);
	}

	cui_menu_run(g_gps_cntx_p->em_auto_reset_menu_id);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_auto_reset_apgs_data_proc
* DESCRIPTION
*  set engineermode auto_reset_gps on/off
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_em_dev_minigps_auto_reset_apgs_data_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct * menu_evt;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	menu_evt = (cui_menu_event_struct *)evt;
	switch(evt->evt_id)
		{
			case EVT_ID_CUI_MENU_ITEM_SELECT:
				if(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_ON){
						g_gps_cntx_p->gps_auto_reset_is_on = 1;
				}else if(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_OFF){
						g_gps_cntx_p->gps_auto_reset_is_on = 0;
				}
				cui_menu_close(g_gps_cntx_p->em_auto_reset_menu_id);
				break;
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
				cui_menu_close(g_gps_cntx_p->em_auto_reset_menu_id);
				break;
			default:
				break;
		}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_auto_reset_apgs_value
* DESCRIPTION
*  set engineermode auto_reset_gps on/off
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_em_dev_minigps_get_auto_reset_apgs(void)
{
    if(g_gps_cntx_p->gps_auto_reset_is_on == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif // #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)


/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_gps_em_shortcut
* DESCRIPTION
*  whether show sms number
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_dev_minigps_gps_em_shortcut()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gps_cntx_p->em_shortcut_menu_id = cui_menu_create(g_gps_cntx_p->em_gps_gid,
					CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPSUB,
                    MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT,
                    MMI_TRUE,
                    NULL);
	g_gps_cntx_p->gps_em_shortcut_is_on = mmi_gps_setting_get_em_on_off();
	if(g_gps_cntx_p->gps_em_shortcut_is_on == 1)
	{
		cui_menu_set_currlist_highlighted_id(g_gps_cntx_p->em_shortcut_menu_id,MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_ON);
	}else {
		cui_menu_set_currlist_highlighted_id(g_gps_cntx_p->em_shortcut_menu_id,MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_OFF);
	}

	cui_menu_run(g_gps_cntx_p->em_shortcut_menu_id);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_gps_em_shortcut_proc
* DESCRIPTION
*  set engineermode shortcut on/off
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_em_dev_minigps_gps_em_shortcut_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct * menu_evt;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	menu_evt = (cui_menu_event_struct *)evt;
	switch(evt->evt_id)
		{
			case EVT_ID_CUI_MENU_ITEM_SELECT:
				if(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_ON){
						g_gps_cntx_p->gps_em_shortcut_is_on = 1;
				}else if(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_OFF){
						g_gps_cntx_p->gps_em_shortcut_is_on = 0;
				}
				mmi_gps_setting_set_em_on_off((MMI_BOOL)g_gps_cntx_p->gps_em_shortcut_is_on);
				cui_menu_close(g_gps_cntx_p->em_shortcut_menu_id);
				break;
			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
				cui_menu_close(g_gps_cntx_p->em_shortcut_menu_id);
				break;
			default:
				break;
		}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_enter_main_src
* DESCRIPTION
*  enter the main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
void mmi_em_dev_minigps_enter_main_src(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID em_gps_menu_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_em_dev_minigps_alloc_mem();

	if (mmi_frm_group_is_present(g_gps_cntx_p->em_gps_gid))
    {
        mmi_frm_group_close(g_gps_cntx_p->em_gps_gid);
    }

    if(is_enter_from_ext == MMI_TRUE){
        g_gps_cntx_p->em_gps_gid = mmi_frm_group_create(GRP_ID_ROOT,
                               GRP_ID_AUTO_GEN,
                               mmi_em_dev_minigps_proc, NULL);
    } else {
    g_gps_cntx_p->em_gps_gid = mmi_frm_group_create(mmi_em_get_root_group(),
                               GRP_ID_AUTO_GEN,
                               mmi_em_dev_minigps_proc, NULL);
    }

    mmi_frm_group_enter(g_gps_cntx_p->em_gps_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	em_gps_menu_id = cui_menu_create(g_gps_cntx_p->em_gps_gid,
					CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPSUB,
                    MENU_ID_EM_DEV_MINI_GPS,
                    MMI_TRUE,
                    NULL);
	cui_menu_run(em_gps_menu_id);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_proc
* DESCRIPTION
*  the handle function of main screen's event
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static mmi_ret  mmi_em_dev_minigps_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct * menu_evt = (cui_menu_event_struct *)evt;

#if defined(__AGPS_CONTROL_PLANE__) || defined(__AGPS_USER_PLANE__)
	cui_event_inline_common_struct *inline_common_evt = (cui_event_inline_common_struct*)evt;
#endif

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__AGPS_CONTROL_PLANE__) || defined(__AGPS_USER_PLANE__)
	if(inline_common_evt->sender_id == g_gps_cntx_p->em_molr_setting_inline_id){
			mmi_em_dev_minigps_molr_setting_proc(evt);
			return MMI_RET_OK;
	}

    #ifdef __AGPS_CONTROL_PLANE__
    	if(inline_common_evt->sender_id == g_gps_cntx_p->em_cp_setting_inline_id){
    			mmi_em_dev_minigps_cp_setting_proc(evt);
    			return MMI_RET_OK;
    	}
    #endif

    #if defined(__AGPS_USER_PLANE__)
    	if(inline_common_evt->sender_id == g_gps_cntx_p->em_up_setting_inline_id){
    			mmi_em_dev_minigps_up_setting_proc(evt);
    			return MMI_RET_OK;
    	}
    #endif

#endif

	if(menu_evt->sender_id == g_gps_cntx_p->em_shortcut_menu_id){
			mmi_em_dev_minigps_gps_em_shortcut_proc(evt);
			return MMI_RET_OK;
	}
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
	else if(menu_evt->sender_id == g_gps_cntx_p->em_auto_reset_menu_id)
	{		mmi_em_dev_minigps_auto_reset_apgs_data_proc(evt);
			return MMI_RET_OK;
	}
#endif

	switch(evt->evt_id)
		{
			case EVT_ID_CUI_MENU_LIST_ENTRY:
				cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
				break;
			case EVT_ID_CUI_MENU_ITEM_SELECT:
				switch(menu_evt->highlighted_menu_id){
					case MENU_ID_EM_DEV_MINI_GPS_MINIGPS:
						mmi_em_dev_minigps_minigps_init();
						break;
				#if defined(__AGPS_CONTROL_PLANE__)||defined(__AGPS_USER_PLANE__)
					case MENU_ID_EM_DEV_MINI_GPS_MOLR_SETTING:
						mmi_em_dev_minigps_molr_setting_scr();
						break;
				#endif

				#ifdef __AGPS_CONTROL_PLANE__
    				case MENU_ID_EM_DEV_MINI_GPS_CP_SETTING:
						mmi_em_dev_minigps_cp_setting_scr();
						break;
				#endif

				#if defined(__AGPS_USER_PLANE__)
					case MENU_ID_EM_DEV_MINI_GPS_UP_SETTING:
						mmi_em_dev_minigps_up_setting_scr();
						break;
				#endif

                #if defined(__AGPS_CONTROL_PLANE__)||defined(__AGPS_USER_PLANE__)
    				case MENU_ID_EM_DEV_MINI_GPS_RESET_AGPS:
						mmi_em_dev_minigps_reset_agps_data();
						break;
					case MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS:
						mmi_em_dev_minigps_auto_reset_apgs_data();
						break;
                #endif

					case MENU_ID_EM_DEV_MINI_GPS_FACTORY_RESET:
						em_gps_reset_data_104();
						break;
					case MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT:
						mmi_em_dev_minigps_gps_em_shortcut();
						break;
					default:
						break;
				}
				break;

			case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                cui_menu_close(menu_evt->sender_id);
			    break;

            case EVT_ID_CUI_MENU_LIST_EXIT:
                break;

            case EVT_ID_GROUP_DEINIT:
			    mmi_em_dev_minigps_free_mem();
				break;
			default:
				break;
		}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_stop_proc
* DESCRIPTION
*  enter main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_em_dev_minigps_stop_proc(void)
{
    MMI_EM_UNREG_STOP_FUNC(mmi_em_dev_minigps_stop_proc);
    mmi_em_comm_mem_ap_deinit();
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_continue_entry
* DESCRIPTION
*  enter main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_dev_minigps_continue_entry()
{
    MMI_EM_REG_STOP_FUNC(mmi_em_dev_minigps_stop_proc);
	mmi_em_dev_minigps_enter_main_src();
}

/*****************************************************************************
* FUNCTION
*  em_gps_enter_main_src
* DESCRIPTION
*  enter main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
void em_gps_enter_main_src()
{
    if (!mmi_em_comm_mem_ap_init(mmi_em_dev_minigps_continue_entry)){
          return;
    }
    is_enter_from_ext  = MMI_TRUE;
    mmi_em_dev_minigps_continue_entry();
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_minigps_get_parent_id
* DESCRIPTION
*  enter main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
MMI_ID mmi_em_dev_minigps_get_parent_id()
{
    return g_gps_cntx_p->em_gps_gid;
}

/*****************************************************************************
* FUNCTION
*  HighlightEMGPSMain
* DESCRIPTION
*  Highlight of main screen
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
void HighlightEMGPSMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_dev_minigps_enter_main_src, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif  /* __GPS_SUPPORT__*/

