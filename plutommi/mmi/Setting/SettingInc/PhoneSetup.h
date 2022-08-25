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

/*******************************************************************************
 * Filename:
 * ---------
 *  PhoneSetup.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef PHONESETUP_H_
#define PHONESETUP_H_
/*************************************************************
 *  Header File Dependance Check
 *************************************************************/
#include "MMI_features.h"
#include "mmi_phnset_dispchar.h"
#include "Menucuigprot.h"
#include "Filemgrsrvgprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "PhoneSetupResList.h"
#include "kal_non_specific_general_types.h"
#include "PhoneSetupSlim.h"
#ifdef __MMI_BTD_BOX_UI_STYLE__
#include "gui_picker.h"
#endif
/* auto add by kw_check end */
/*************************************************************
 *  Defination
 *************************************************************/
#if 0
/* under construction !*/
#endif 
#define MAX_SS_INLINE_EDIT          4

#define PHNSET_HOME_CITY 0
#define PHNSET_FOREIGN_CITY 1

#ifndef UI_character_type
#ifdef __UCS2_ENCODING
typedef U16 UI_character_type;
#else 
typedef U8 UI_character_type;
#endif 
#endif /* UI_character_type */ 
/*************************************************************
 *  Enum Value
 *************************************************************/


typedef enum
{
    MMI_SETTING_TVOUT_FORMAT_PAL = 0,
    MMI_SETTING_TVOUT_FORMAT_NTSC
} mmi_setting_tvout_format_enum;

typedef enum
{
    MMI_SETTING_TVOUT_AUD_PATH_BOTH = 0,
    MMI_SETTING_TVOUT_AUD_PATH_TV
} mmi_setting_tvout_aud_path_enum;

#ifdef __GEMINI__
typedef enum
{
	MMI_PHNSET_UART_SIM1 = 0,
	MMI_PHNSET_UART_SIM2,
	MMI_PHNSET_UART_SIM3,	
	MMI_PHNSET_UART_SIM4,	
	MMI_PHNSET_UART_SIM_NONE
}mmi_phnset_uart_sim_config_enum;
#endif 

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
typedef enum
{
    /*
     * MMI_PHNSET_IDLECLKTYPE_NONE,
     */
    MMI_PHNSET_IDLECLKTYPE_ANALOG,
    MMI_PHNSET_IDLECLKTYPE_DIGITAL,
    MMI_PHNSET_IDLECLKTYPE_MAX
} PHNSET_IDLECLKTYPE_ENUM;
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */ 
/*************************************************************
 *  Structure Defination
 *************************************************************/
typedef struct
{
    U16 filename[(SRV_FMGR_PATH_MAX_LEN + 1)];
    U16 is_short;
} mmi_phnset_wp_ss_pwrdisp_common_filename_struct;
typedef struct
{
#ifdef __MMI_BTD_BOX_UI_STYLE__
    mmi_id curHightlightItem;
    U8 time_text[40];
    U8 year_text[40];
    U8 monthday_text[40];
#else
    U8 month;
    U8 date;
    U8 hour;
    U8 minutes;
	U8 sec;
	U8 unused1;
    U16 year;
#endif  //__MMI_BTD_BOX_UI_STYLE__
	MYTIME prev_time;
} PHNSET_DATETIME_STRUCT;

/*
 *** Phone Setup context structure
 */
typedef struct
{

    S32 curHightlightItem;
#ifndef __MMI_PHNSET_SLIM__    
    U16 ScrAnchor;  /* Screen Anchor */
#endif

    /* Set Time and Date */
#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
    U8 curDTUpdateStatus;
#endif
#ifdef __MMI_DUAL_CLOCK__
	U8 city_flag;		/* 0->home city, 1->foreign city */
	U8 foreign_city; 	/* DateAndTime*/
	U8 *CurForeignCityStrPtr;
	U16 CurForeignCityStrID;/* DateAndTime*/
#endif
	U8 currentCity;	
    U16 CurHomeCityStrID;
    U8 *CurHomeCityStrPtr;
    U32 CurTimeFmt;
    U32 CurDateFmt;
	U32 CurDateSep;
    S32 currentDST;
#ifndef __MMI_PHNSET_SLIM__    
    S32 prevDST;
    U8 *AM_PM_flag;
#endif

    PHNSET_DATETIME_STRUCT settime;
#ifndef __MMI_PHNSET_SLIM__    

    /* NITZ */
    pBOOL NITZDirtyFlag;
    U8 curNITZStatus;
#endif    
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_DUAL_CLOCK__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif /* __MMI_DUAL_CLOCK__ */
#endif
    /* Phone Setup */
    U8 curShowDtStatus;
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
    U8 curShowOwnNumStatus;
#if defined(__MMI_DUAL_SIM_MASTER__)    
/* under construction !*/
#endif
#endif
#if 0
#if defined(__MMI_OPERATOR_NAME_MENU__)
/* under construction !*/
#endif 
#endif

#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif
#ifndef __MMI_PHNSET_SLIM__    

    pBOOL ShowDtDirtyFlag;
    pBOOL ShowOwnNumDirtyFlag;
#endif
#if 0
#if defined(__MMI_OPERATOR_NAME_MENU__)
/* under construction !*/
#endif 
#endif

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    U8 curScrSwitchEffect;
#endif  /* __MMI_SCREEN_SWITCH_EFFECT__ */
    
#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
	U8 curBtBoxDialerType;
    U8 curBtBoxPickerType;
#endif
#if 0   
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif
#ifdef __MMI_DUAL_CLOCK__
	U8 curDualClockStatus;
	pBOOL ShowDualClockDirtyFlag;
#endif /* __MMI_DUAL_CLOCK__ */

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 MenuStyle;
#endif 

#ifdef __MMI_MOTION_DIAL__
    U8 DialStyle;
#endif /* __MMI_MOTION_DIAL__ */

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
    U8 EncodingType;
#endif 

    /* Language */
    U8 **ppLang;
#ifndef __MMI_PHNSET_SLIM__    
    U8 LP;
    U8 UsrLangIdx;
#endif    
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    U8 curFlightMode;   /* current mode */
#endif
    U8 selFlightMode;   /* selected mode */
#ifdef __MMI_WLAN_FEATURES__
    U8 curFlightMode2;
#endif

    /* Wallpaper & Screen Saver */
#ifndef __MMI_PHNSET_SLIM__    
    pBOOL storage_invalid;
    U8 WPSSPreviewScrFlag;
#endif    
#ifndef __SLIM_AT__
    U16 curtWpID;
#endif
#ifdef __MMI_SUB_WALLPAPER__
    U16 curtSubWpID;
#endif 
#ifndef __SLIM_AT__
    U16 curSsID;
#endif
#ifndef __SLIM_AT__
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    U16 curtPwrOnID;
    U16 curtPwrOffID;
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
#endif
#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    U16 curtCLKType;
#endif 

    S32 SSWaitStatusInlineHilite;
#ifndef __MMI_PHNSET_SLIM__    
    S32 SSStatusInlineHilite;
    S32 curSSStatus;
    S32 curSSWaitTime;
    S32 isShort;
#endif    

    /* Wallpaper & Screen Saver shall code identifier */
    phnset_wpss_type_enum wpss_type;

    U16 SysWPSSList[MMI_MAX_DISPCHAR_IMG + MMI_MAX_DISPCHAR_VDO];
#ifndef __MMI_PHNSET_SLIM__    
    U16 DwnlWPSSList[MAX_DL_WPSS_NUMBERS];
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    U16 pen_speed;
    U16 pen_color;
    U8 is_default_calibration_set;
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#ifdef __GEMINI__
	U8 uart_status;
#endif	/* __GEMINI__ */

#ifdef __MMI_VUI_HOMESCREEN__
	U8 vui_home_screen;  /* for VUI interactive screen */
#endif

#ifdef __MMI_VUI_MAINMENU__
	U8 vui_mm_effect;    /* for VUI main menu effect */
#endif
	
    U8 isCorrectSet;
#ifdef __MMI_CHANGABLE_FONT__
    U8 font_size;
#endif
    /* Look! Here might be structure alignment problem */
} PHNSET_CNTX;

/* Dynamic FlightMode struct and enum */
#ifdef __GEMINI__
 //xjdan
typedef enum
{
    MTPNP_NO_SIM_INSERTED    = 0,
    MTPNP_ONLY_SIM1_INSERTED = 1,
    MTPNP_ONLY_SIM2_INSERTED = 2,
    MTPNP_DUAL_SIM_INSERTED  = 3,
    MTPNP_SIM_INSERT_STATUS_NONE = 0xFF
} dualmode_sim_insert_status_enum; 

typedef enum
{
    MTPNP_SIM1_ONLY_CONFIG  = 0,
    MTPNP_SIM2_ONLY_CONFIG  = 1,
    MTPNP_DAUL_SIM_CONFIG   = 2,
    MTPNP_FLIGHTMODE_CONFIG = 3,
    MTPNP_SIM_CONFIG_STATUS_NONE  = 0xFF
} dualmode_sim_config_status_enum; 

typedef struct
{
    dualmode_sim_insert_status_enum sim_insert;
    dualmode_sim_config_status_enum src_status;
    dualmode_sim_config_status_enum dest_status;
}DUALMODE_SWITCH_STATUS;

typedef enum
{
    PHNSET_LANGUAGE1,
    PHNSET_LANGUAGE2,
    PHNSET_LANGUAGE3,
    PHNSET_LANGUAGE4,
    PHNSET_LANGUAGE5,
    PHNSET_LANGUAGE6,
    PHNSET_LANGUAGE7,
    PHNSET_LANGUAGE8,
    PHNSET_LANGUAGE9,
    PHNSET_LANGUAGE10,
    PHNSET_LANGUAGE11,
    PHNSET_LANGUAGE12,
    PHNSET_LANGUAGE13,
    PHNSET_LANGUAGE14,
    PHNSET_LANGUAGE15,
    PHNSET_LANGUAGE16,
    PHNSET_LANGUAGE17,
    PHNSET_LANGUAGE18,
    PHNSET_LANGUAGE19,
    PHNSET_LANGUAGE20,

    PHNSET_LANGUAGE_TOTAL
} phnset_language_menu_id;

#endif /* __GEMINI__ */

// String-passing callback function type.
typedef S32 (*PFN_STR_CB)(U8 index, WCHAR *wstr_buf, S32 buf_len);

typedef struct
{
    MMI_ID group_id;
    U16 menu_title_str_id;
    U16 menu_icon_id;
    U16 menu_item_num;
    /* string list pointer one of them must be set */
    U16 *menu_item_str_id_list; /* array of string id */
    PU8 *menu_item_str_list;    /* array of string list */
    PFN_STR_CB menu_item_str_cb;
    U8 highlighted_item_idx;
} phnset_radio_button_menu_data_struct;
/*************************************************************
 *  Global Variable
 *************************************************************/
extern PHNSET_CNTX *g_phnset_cntx_p;
extern void change_font_Theme(void);

/*************************************************************
 *  Function Prototype
 *************************************************************/
extern void EntryPhnsetLang(void);
extern void EntryPhnsetScr(void);

/* END:  add day light saving setting */
// TODO: MOVE TO GPROT.H
extern void EntryPhnsetSetDT(void);

/* __MMI_SEPARATE_DT_SETTING__ */
/*
extern S16 PhnsetSetTimeFormat(U8 timeformat);
extern S16 PhnsetSetDateFormat(U8 dateformat);
*/
extern void EntryPhnsetSetHomeCity(void);
extern void ExitPhnsetSetHomeCity(void);
extern void PhnsetHomeCityIdxHiliteHandler(S32 index);
extern void PhnsetSetHomeCity(void);
extern void ExitFunctionHomeCity(void);
extern void PhnsetHCMultiTapCompleteHdlr(void);
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
extern U8 PhnsetGetMainMenuStyle(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
extern void PhnsetReadIdleClockType(void);
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */ 

#ifdef __MMI_CHANGABLE_FONT__
extern void PhnsetReadFontSize(void);
extern void EntryPhnsetFontSize(MMI_ID parent_gid);
extern void PhnsetSetFontSize(void);
#endif /* __MMI_CHANGABLE_FONT__ */ 

#ifdef __USB_IN_NORMAL_MODE__
//extern pBOOL mmi_usb_check_path_exported(S8 *path);
#endif 

extern MMI_BOOL PhnsetSetCharsetByLang(void);


extern mmi_ret mmi_phnset_disp_setup_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);

extern mmi_ret mmi_phnset_time_and_date_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);

extern void mmi_phnset_appcreate_menucui_create(MMI_ID parent_gid, MMI_ID group_id, U16 menu_id, mmi_proc_func proc);

extern void mmi_phnset_init_radio_button_menu(phnset_radio_button_menu_data_struct *menu_data);

extern void mmi_phnset_init_on_off_radio_button_menu(MMI_ID group_id, U16 title_id, U16 icon_id, U8 highlight_item);


#if (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_init
* DESCRIPTION
* main menu effect init function in bootup.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phnset_menu_effect_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_shortcut_mananger_launch
 * DESCRIPTION
 *  phone setting shortcut manager lanuch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phnset_menu_effect_launch(MMI_ID parent_id);

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_type_hint
* DESCRIPTION
* main menu effect HINT.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phnset_menu_effect_type_hint(void);
#endif /*  (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__) */

#ifdef __MMI_VUI_LAUNCHER_KEY__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_manager_init
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phnset_widget_manager_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_widget_manager_launch
 * DESCRIPTION
 *  phone setting widget manager lanuch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phnset_widget_manager_launch(MMI_ID parent_id);


/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_init
* DESCRIPTION
*  shortcut manger init function
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
extern void  mmi_phnset_shortcut_manager_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_shortcut_mananger_launch
 * DESCRIPTION
 *  phone setting shortcut manager lanuch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phnset_shortcut_mananger_launch(MMI_ID parent_id);
#endif
/*****************************************************************************
* FUNCTION
 *  mmi_phnset_launcher_switch_launch
 * DESCRIPTION
 *  phone setting launcher switch launch switch app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
extern void mmi_phnset_launcher_switch_launch(void);

/*****************************************************************************
* FUNCTION
*  mmi_phnset_launcher_switch_hint
* DESCRIPTION
* Lanucher switch setting menu hint string.
* PARAMETERS
*  evt        [VOID]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phnset_launcher_switch_hint(void);
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_wallpaper_screen_lock_direct_set_file
 * DESCRIPTION
 *  Set cache file 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phnset_wallpaper_screen_lock_direct_set_file(void* obj, const WCHAR* file_name);
#endif /* __MMI_VUI_SCREEN_LOCK_KEY__ */

#endif /* PHONESETUP_H_ */ 

