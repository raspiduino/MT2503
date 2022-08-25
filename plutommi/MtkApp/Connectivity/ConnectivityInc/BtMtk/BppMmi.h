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
 * BppMmi.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BPP application declaration.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef BPP_MMI_H
#define BPP_MMI_H
#include "MMI_features.h"

#ifdef __MMI_BPP_SUPPORT__
/* auto add by kw_check begin */
#include "FileMgrSrvGProt.h"
#include "BppCuiGprot.h"
#include "InlineCuiGprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "BppSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "BppXhtmlGprot.h"
#include "menucuigprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_draw_manager.h"
#include "wgui_touch_screen.h"
#include "AlertScreen.h"
/* auto add by kw_check end */
/*****************************************************************
    Definition
*****************************************************************/
#define BPP_TEXT_LEN        (32)
#define MAX_ZOOM_LEVEL      (6)
#define BPP_ZOOM_UNIT       (10)
#define ZOOM_MIN_SIZE       (10)
#define BPP_MAX_DEV_NAME    (32)
#define BPP_MAX_ITEMS       (5)    
#define BPP_MAX_ITEM_VALUES (10)
#define BPP_MAX_COPIES      (10)
#define BPP_MAX_PASS_LEN    (16)
#define BPP_MAX_AUTH_LEN    (64)

#define EVT_BPP_DATA_HELPER (EVT_BT_PRINT_MAX+1)

#define BPP_MAGIC_NUMBER    (0x76543218)

#define BPP_STORAGE_DRIVE   SRV_FMGR_PRIVATE_DRV
#define ArrayCount(ele)     (sizeof(ele) / sizeof(ele[0]))
#define BppAttrs(attrs)     attrs, ArrayCount(attrs)         

enum {
    FLAG_AUTO_ON =  0x01,
    FLAG_PREVIEW =  0x02,
    FLAG_ZOOM =     0x04,
    FLAG_ROTATE =   0x08,
    FLAG_NEW_JOB =  0x10,
    FLAG_DISC =     0x20,
    FLAG_USER_CANCEL = 0x40,
    FLAG_SELF_CLOSE = 0x80,
    FLAG_END
};

enum {
    E_OK = BPP_E_OK,
    E_FAIL = BPP_E_FAIL,
    E_PENDING = BPP_E_PENDING,
    E_EXIT = BPP_E_EXIT,
    E_BUSY = BPP_E_BUSY,
    E_CANCEL = BPP_E_CANCEL,
    E_LINK_DISC = BPP_E_LINK_DISC,
    E_DISK_FULL = BPP_E_DISK_FULL,
    E_ABORT,
    E_END
};

enum {
    BPP_OP_NONE,
    BPP_OP_GET_ATTR,
    BPP_OP_PRINT_DOC
};

enum {
    ITEM_ID_NAME_TITLE = CUI_INLINE_ITEM_ID_BASE,
    ITEM_ID_NAME,
    ITEM_ID_COPIES_TITLE,
    ITEM_ID_COPIES,
    ITEM_ID_SIZE_TITLE,
    ITEM_ID_SIZE,
    ITEM_ID_ORIENT_TITLE,
    ITEM_ID_ORIENT,
    ITEM_ID_SIDES_TITLE,
    ITEM_ID_SIDES,
    ITEM_ID_QUALITY_TITLE,
    ITEM_ID_QUALITY,
    ITEM_ID_END
};

#define OnGroupEvents \
            case EVT_ID_POST_CB_RST: \
            case EVT_ID_GROUP_ENTER: \
            case EVT_ID_GROUP_ACTIVE: \
            case EVT_ID_GROUP_INACTIVE: \
            case EVT_ID_GROUP_FOCUSED: \
            case EVT_ID_GROUP_DEFOCUSED: \
            case EVT_ID_GROUP_GOBACK: \
            case EVT_ID_GROUP_GOBACK_IN_END_KEY: \
            case EVT_ID_GROUP_DELETE_REQ: \
            case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY: \
            case EVT_ID_GROUP_EXIT: \
            case EVT_ID_GROUP_DEINIT: \
            case EVT_ID_GROUP_REDRAW_START: \
            case EVT_ID_GROUP_REDRAW_DONE

#define OnMenuEvents \
            case EVT_ID_CUI_MENU_LIST_ENTRY: \
            case EVT_ID_CUI_MENU_LIST_EXIT: \
            case EVT_ID_CUI_MENU_ITEM_HILITE: \
            case EVT_ID_CUI_MENU_ITEM_SELECT: \
            case EVT_ID_CUI_MENU_ITEM_TAP: \
            case EVT_ID_CUI_MENU_ITEM_CSK_SELECT: \
            case EVT_ID_CUI_MENU_CLOSE_REQUEST: \
            case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE

#define OnInlineEvents \
            case EVT_ID_CUI_INLINE_SUBMIT: \
            case EVT_ID_CUI_INLINE_ABORT: \
            case EVT_ID_CUI_INLINE_CSK_PRESS: \
            case EVT_ID_CUI_INLINE_SET_KEY: \
            case EVT_ID_CUI_INLINE_NOTIFY: \
            case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE: \
            case EVT_ID_CUI_INLINE_GROUP_DEINIT: \
            case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE

#define OnCuiEvents \
            case EVT_ID_CUI_BT_CM_POWER_ON_RESULT: \
            case EVT_ID_CUI_BT_CM_DEFAULT_DEVICE: \
            case EVT_ID_CUI_BT_CM_DEVICE_SELECT

#define OnAlertEvents \
            case EVT_ID_ALERT_QUIT

/*****************************************************************
    Inline template
*****************************************************************/
static const cui_inline_item_caption_struct SettingTitles[] = {
    {STR_BT_BPP_PRINTER_NAME},
    {STR_BT_BPP_SETTING_COPIES},
    {STR_BT_BPP_SP_MEDIA_SIZE},
    {STR_BT_BPP_SETTING_ORIENTATION},
    {STR_BT_BPP_SETTING_SIDES},
    {STR_BT_BPP_SETTING_QUALITY}
};

static const cui_inline_set_item_struct StaticSetItems[] = 
{
    {ITEM_ID_NAME_TITLE,    CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1, &SettingTitles[0]},
    {ITEM_ID_NAME,          CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0, NULL},
};

static const cui_inline_set_item_struct DynamicSetItems[] = 
{
    {ITEM_ID_COPIES_TITLE,  CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L2, &SettingTitles[1]},
    {ITEM_ID_COPIES,        CUI_INLINE_ITEM_TYPE_SELECT,        0,              NULL},
    {ITEM_ID_SIZE_TITLE,    CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L3, &SettingTitles[2]},
    {ITEM_ID_SIZE,          CUI_INLINE_ITEM_TYPE_SELECT,        0,              NULL},
    {ITEM_ID_ORIENT_TITLE,  CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L4, &SettingTitles[3]},
    {ITEM_ID_ORIENT,        CUI_INLINE_ITEM_TYPE_SELECT,        0,              NULL},
    {ITEM_ID_SIDES_TITLE,   CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L5, &SettingTitles[4]},
    {ITEM_ID_SIDES,         CUI_INLINE_ITEM_TYPE_SELECT,        0,              NULL},
    {ITEM_ID_QUALITY_TITLE, CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L6, &SettingTitles[5]},
    {ITEM_ID_QUALITY,       CUI_INLINE_ITEM_TYPE_SELECT,        0,              NULL},
};

static const cui_inline_item_softkey_struct SettingSKs = 
{
    {
        {STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS},
        {STR_GLOBAL_BACK,   IMG_GLOBAL_BACK},
        {0,                 IMG_GLOBAL_COMMON_CSK},
    }
};

static const cui_inline_struct SettingProps = 
{
    ArrayCount(StaticSetItems),
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    &SettingSKs,
    StaticSetItems
};

/*****************************************************************
    Data Structure
*****************************************************************/
typedef bt_print_margin_struct  bpp_margin_struct;
typedef bt_print_page_struct    bpp_page_struct;
typedef bt_print_data_struct    bpp_app_data_struct;

typedef struct {
    MMI_EVT_GROUP_PARAM_HEADER
    WCHAR *storage;
} evt_bpp_data_helper;

typedef struct {
    S32 x1;
    S32 x2;
    S32 y1;
    S32 y2;
} bpp_region_struct;

typedef struct {
    U32 width;
    U32 height;
} bpp_dimension;

typedef struct {
    U8 l_margin;
    U8 t_margin;
    U8 r_margin;
    U8 b_margin;
} bpp_page_config_struct;

typedef struct {
    WCHAR *path;
    U32 type;
    bpp_dimension real_size;
    bpp_dimension size;
} bpp_obj_desc_struct;

typedef struct {
    S32 result;
    gdi_handle hd_draw;
    U32 flags;
    bpp_region_struct bk_region;
    bpp_region_struct pg_region;
    bpp_obj_desc_struct obj;
    U32 zoom_level;
    bpp_dimension page;
    bpp_dimension obj_size;
    bpp_dimension zoom_size[MAX_ZOOM_LEVEL];
    bpp_dimension page_size;
    bpp_dimension last;
} bpp_preview_struct;

typedef struct {
    U32 type;
    U32 option;
    MMI_ID gid;
    bpp_page_config_struct page;
    bpp_app_data_struct data;
} bpp_app_info_struct;

typedef struct {
    U8 *str;
    U64 data; 
} bpp_item_value_struct;

typedef struct {
    U8 count;
    U8 focus;
    U8 chosen;
    U8 enable;
    U16 id;
    bpp_item_value_struct values[BPP_MAX_ITEM_VALUES];
} bpp_item_struct;

typedef struct {
    PrinterAddr addr;
    WCHAR dev_name[BPP_MAX_DEV_NAME+1];
    U32 flags;
    bpp_item_struct items[ArrayCount(DynamicSetItems)/2];
} bpp_setting_struct;

typedef struct _bpp_inst {
    U32 magic;
    
    BppHandle h_srv;
    S32 h_cm_srv;
    U32 job_id;
    U32 op_code;
    U32 flags;

    MMI_ID group_id;
    MMI_ID cid_device;
    MMI_ID cid_setting;
    MMI_ID pid_getting;

    bpp_app_info_struct app;
    bpp_page_struct     page;
    bpp_obj_desc_struct obj;
    bpp_preview_struct *preview;
    bpp_setting_struct *setting;

    U16 prog_rate;

    WCHAR *txt_buff;
    WCHAR *auth_title;
    WCHAR *auth_pass;
    struct _bpp_inst *next;
} bpp_inst_struct;

typedef struct {
    U32 flags;
    BppHandle h_bearer;
    bpp_inst_struct *inst;
    PrinterAddr addr;
} bpp_mmi_cntx_struct;

/*****************************************************************
    Global constant
*****************************************************************/
static const MMI_STR_ID DefaultSizeStrID[] =
{
    STR_BT_BPP_SETTING_PAPER_A4,
    STR_BT_BPP_SETTING_PAPER_4X6,
    STR_BT_BPP_SETTING_PAPER_US
};

static const WCHAR* MediaSizeStr[] =
{
    L"A10",
    L"A9",
    L"A8",
    L"A7",
    L"A6",
    L"A5",
    L"A5",
    L"A4",
    L"A4-Tab",
    L"A4-Extra",
    L"A3",
    L"A2",
    L"A1",
    L"A0",
    L"2A0",
    L"B10",
    L"B9",
    L"B8",
    L"B7",
    L"B6",
    L"B6/C4",
    L"B5",
    L"B5-Exra",
    L"B4",
    L"B3",
    L"B2",
    L"B1",
    L"B0",
    L"C10",
    L"C9",
    L"C8",
    L"C7",
    L"C7/C6",
    L"C6",
    L"C6/C5",
    L"C5",
    L"C4",
    L"C3",
    L"C2",
    L"C1",
    L"C0",
    L"4x6",
    L"Letter"
};

static const CHAR *ImageMime[] = 
{
    "image/jpeg",
    "image/gif",
    "image/bmp",
    "image/vnd.wap.wbmp",
    "image/png",
    "image/svg+xml",
};

static const MMI_STR_ID SidedStrID[] =
{
    STR_BT_BPP_SETTING_SIDES_ONE,
    STR_BT_BPP_SETTING_SIDES_TWO_LONG,
    STR_BT_BPP_SETTING_SIDES_TWO_SHORT
};

static const MMI_STR_ID OrientationStrID[] =
{
    STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT,
    STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP,
    STR_BT_BPP_SETTING_ORIENTATION_R_PORTRAIT,
    STR_BT_BPP_SETTING_ORIENTATION_R_LANDSCAP
};

static const MMI_STR_ID QualityStrID[] =
{
    STR_BT_BPP_SETTING_QUALITY_DRAFT,
    STR_GLOBAL_NORMAL,
    STR_GLOBAL_HIGH
};

static const MMI_STR_ID CopiesStrID[] =
{
    STR_GLOBAL_1,
    STR_GLOBAL_2,
    STR_GLOBAL_3,
    STR_GLOBAL_4,
    STR_GLOBAL_5,
    STR_GLOBAL_6,
    STR_GLOBAL_7,
    STR_GLOBAL_8,
    STR_GLOBAL_9,
    STR_GLOBAL_10
};

static const MMI_STR_ID PrintStatusStrID[] =
{
    STR_GLOBAL_NONE,
    STR_BT_BPP_NOTICE,
    STR_BT_BPP_MEDIA_JAM,
    STR_BT_BPP_PAUSED,
    STR_BT_BPP_DOOR_OPEN,
    STR_BT_BPP_MEDIA_LOW,
    STR_BT_BPP_MEIDA_EMPTY,
    STR_BT_BPP_OUTP_AREA_ALMOST_FULL,
    STR_BT_BPP_OUTP_AREA_FULL,    
    STR_BT_BPP_SUPPLY_LOW,
    STR_BT_BPP_SUPPLY_EMPTY,
    STR_BT_BPP_SUPPLY_FAILURE
};

#ifdef __MMI_ICON_BAR_SUPPORT__
typedef struct {
    MMI_IMG_ID enable_id;
    MMI_IMG_ID disable_id;
    MMI_STR_ID str_id;
} bpp_toolbar_data;

#define BPP_TOOLBAR_ICON_COUNT      (3)
static const bpp_toolbar_data BppIcons[BPP_TOOLBAR_ICON_COUNT] = {
    {IMG_BPP_TB_PRINT, IMG_BPP_TB_PRINT_DISABLED, STR_GLOBAL_PRINT},
    {IMG_BPP_TB_ZOOM_IN, IMG_BPP_TB_ZOOM_IN_DISABLED, STR_BT_BPP_SP_ZOOM_IN},
    {IMG_BPP_TB_ZOOM_OUT, IMG_BPP_TB_ZOOM_OUT_DISABLED, STR_BT_BPP_SP_ZOOM_OUT}
};
#endif

/*****************************************************************
    Predefined CSS rules
*****************************************************************/
static const xhtml_prop_struct PageProps[] = 
{
    {XHTML_PROP_SIZE,           "%dmm %dmm"},
    {XHTML_PROP_COUNTER,        "pages"},
    {XHTML_PROP_MARGIN_TOP,     "%dmm"},
    {XHTML_PROP_MARGIN_RIGHT,   "%dmm"},
    {XHTML_PROP_MARGIN_BOTTOM,  "%dmm"},
    {XHTML_PROP_MARGIN_LEFT,    "%dmm"}
};

static const xhtml_prop_struct TopProps[] = 
{
    {XHTML_PROP_COLOR,            "#1CA3C9"},
    {XHTML_PROP_BK_COLOR,         "#fff"},
    {XHTML_PROP_BORDER_BOTTOM,    "3pt solid #eee"},
    {XHTML_PROP_TEXT_ALIGN,       "left"},
    {XHTML_PROP_VERTICAL_ALIGN,   "bottom"},
    {XHTML_PROP_WIDTH,            "%dmm"},
    {XHTML_PROP_CONTENT,          "\"%s\""}
};

static const xhtml_prop_struct BottomProps[] = 
{
    {XHTML_PROP_COLOR,            "#1CA3C9"},
    {XHTML_PROP_BK_COLOR,         "#fff"},
    {XHTML_PROP_TEXT_ALIGN,       "center"},
    {XHTML_PROP_VERTICAL_ALIGN,   "top"},
    {XHTML_PROP_LINE_HEIGHT,      "10pt"},
    {XHTML_PROP_WIDTH,            "%dmm"},
    {XHTML_PROP_CONTENT,          "%s"}
};

static const xhtml_prop_struct TableProps[] = 
{
    {XHTML_PROP_BORDER_COLLAPSE,    "collapse"},
    {XHTML_PROP_BORDER_SPACE,       "0pt"},
};
static const xhtml_prop_struct CenterProps[] =
{
    {XHTML_PROP_TEXT_ALIGN,         "center"}
};

static const xhtml_prop_struct MailTableProps[] = 
{
    {XHTML_PROP_BORDER_WIDTH,   "0px"},
    {XHTML_PROP_TEXT_ALIGN,     "left"}
};

static const xhtml_prop_struct MailDivProps[] =
{
    {XHTML_PROP_MARGIN_BOTTOM,  "1%"}
};

static const xhtml_prop_struct MailParaProps[] =
{
    {XHTML_PROP_MARGIN_LEFT,    "1mm"}
};

static const xhtml_prop_struct ImageClassProps[] =
{
    {XHTML_PROP_VERTICAL_ALIGN,   "top"},
    {XHTML_PROP_TEXT_ALIGN,      "left"}
};

static xhtml_prop_struct TextClassProps[] = 
{
    {XHTML_PROP_SIZE,   "%dmm %dmm"},
    {XHTML_PROP_COLOR,  "black"},
    {XHTML_PROP_VERTICAL_ALIGN, "top"},
    {XHTML_PROP_TEXT_ALIGN, XHTML_LEFT},
};

static const xhtml_rule_struct SysPageRule = 
{
    XHTML_STYLE_PAGE, NULL, STYLE_RULE_SYSTEM, BppAttrs(PageProps)
};

static const xhtml_rule_struct SysTopRule = 
{
    XHTML_STYLE_TOP, NULL, STYLE_RULE_SYSTEM, BppAttrs(TopProps)
};

static const xhtml_rule_struct SysBottomRule = 
{
    XHTML_STYLE_BOTTOM, NULL, STYLE_RULE_SYSTEM, BppAttrs(BottomProps)
};

static const xhtml_rule_struct SysTableRule = 
{
    XHTML_ELE_TABLE, NULL, STYLE_RULE_ELEMENT, BppAttrs(TableProps)
};

static const xhtml_rule_struct SysCenterRule = 
{
    "center", XHTML_ELE_DIV, STYLE_RULE_CLASS, BppAttrs(CenterProps)
};

static const xhtml_rule_struct MailTableRule = 
{
    XHTML_ELE_TABLE, NULL, STYLE_RULE_ELEMENT, BppAttrs(MailTableProps)
};

static const xhtml_rule_struct MailParaRule = 
{
    XHTML_ELE_PARA, NULL, STYLE_RULE_ELEMENT, BppAttrs(MailParaProps)
};

static const xhtml_rule_struct MailDivRule =
{
    XHTML_ELE_DIV, NULL, STYLE_RULE_ELEMENT, BppAttrs(MailDivProps)
};

static const CHAR ImageClass[] = "img-css";
static const xhtml_rule_struct ImageClassRule = 
{
    ImageClass, NULL, STYLE_RULE_CLASS, BppAttrs(ImageClassProps)
};

static const CHAR TextTile[] = "ebook reader";
static const CHAR PageHeader[] = "";
static const CHAR PageFooter[] = "\" Page \" counter(pages)";
static const CHAR TextClass[] = "text-css";
static xhtml_rule_struct TextClassRule = 
{
    TextClass, NULL, STYLE_RULE_CLASS, BppAttrs(TextClassProps)
};


static const xhtml_rule_struct* ContactStyleRules[] = 
{
    &SysPageRule,
    &SysTableRule,
    &SysCenterRule
};

static const xhtml_rule_struct* CalendarStyleRules[] = 
{
    &SysPageRule,
    &SysTableRule,
    &SysCenterRule
};

static const xhtml_rule_struct* MessageStyleRules[] = 
{
    &SysPageRule
};

static const xhtml_rule_struct* MailStyleRules[] = 
{
    &SysPageRule,
    &MailTableRule,
    &MailDivRule,
    &MailParaRule
};

static const xhtml_rule_struct* TextStyleRules[] = 
{
    &SysPageRule,
    &SysBottomRule,
    &SysTableRule,
    &SysCenterRule,
    &TextClassRule
};

static const xhtml_rule_struct *ImageStyleRules[] =
{
    &SysPageRule,
    &SysTableRule,
    &SysCenterRule,
    &ImageClassRule
};

/*****************************************************************
    API Prototype
*****************************************************************/
static MMI_RET bpp_app_proc(mmi_event_struct *evt);
static MMI_RET bpp_data_helper_proc(evt_bpp_data_helper *evt);
static S32 bpp_srv_notify_hdlr(BppHandle h_srv, U32 notify, U32 para);
static S32 bpp_bearer_notify_hdlr(BppHandle h_srv, U32 notify, U32 para);

static void bpp_group_event_hdlr(bpp_inst_struct *inst, mmi_event_struct *evt);

static void bpp_menu_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt);
static void bpp_preview_menu_hdlr(bpp_inst_struct *inst, cui_menu_event_struct *evt);
static void bpp_setting_menu_hdlr(bpp_inst_struct *inst, cui_menu_event_struct *evt);

static void bpp_cui_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt);
static void bpp_power_on_hdlr(bpp_inst_struct *inst, MMI_ID cid, MMI_BOOL result);
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
static void bpp_auto_on_hdlr(MMI_BOOL result);
#endif
static void bpp_sel_device_hdlr(bpp_inst_struct *inst, MMI_ID cid, MMI_BOOL result, PrinterAddr *addr);

static void bpp_setting_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt);

static U32 bpp_is_ready(void);
static void bpp_start_app(bpp_inst_struct *inst);
static void bpp_stop_app(bpp_inst_struct *inst, U32 result);

static S32 bpp_power_on(bpp_inst_struct *inst);
static S32 bpp_sel_device(bpp_inst_struct *inst);
static void bpp_set_app_data(bpp_inst_struct *inst, bt_print_data_struct *data);

static bpp_preview_struct *bpp_new_preview(bpp_inst_struct *inst);
static S32 bpp_init_preview(bpp_inst_struct *inst);
static S32 bpp_show_preview(bpp_inst_struct *inst);
static S32 bpp_draw_preview(bpp_inst_struct *inst, bpp_region_struct *region);
static S32 bpp_draw_background(bpp_region_struct *region);
static S32 bpp_draw_paper(bpp_preview_struct *p);
static S32 bpp_draw_image(bpp_preview_struct *p);
static S32 bpp_draw_text(WCHAR *text, bpp_region_struct *page, bpp_region_struct *img);
static S32 bpp_zoom_preview(bpp_inst_struct *inst, U32 opt);
static void bpp_show_preview_options(bpp_inst_struct *inst);
static U32 bpp_fit_region(U32 w_box, U32 h_box, U32 *w_max, U32 *h_max);
static void bpp_del_preview(bpp_inst_struct *inst);
static S32 bpp_preview_enable(bpp_app_data_struct *app_data);
static S32 bpp_zoom_enable(bpp_preview_struct *p, U32 type);
static void bpp_init_zoom(bpp_dimension *zoom_size, U32* zoom_level,
                          bpp_dimension *obj_size, bpp_dimension *page_size);

static MMI_RET bpp_preview_enter_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_preview_exit_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_preview_scrn_hdlr(mmi_event_struct *evt);
static void bpp_preview_draw_hdlr(dm_coordinates *screen);
static void bpp_preview_lsk_hdlr(void);
static void bpp_preview_csk_hdlr(void);
static void bpp_preview_rsk_hdlr(void);
static void bpp_preview_zoom_in_hdlr(void);
static void bpp_preview_zoom_out_hdlr(void);
#ifdef __MMI_ICON_BAR_SUPPORT__
static void bpp_preview_toolbar_hdlr(S32 idx);
#endif


static bpp_setting_struct *bpp_new_setting(bpp_inst_struct *inst);
static void bpp_abort_setting(bpp_inst_struct *inst);
static void bpp_apply_setting(bpp_inst_struct *inst);
static void bpp_show_setting(bpp_inst_struct *inst);
static void bpp_update_setting(bpp_inst_struct *inst, bpp_setting_struct *set);
static void bpp_save_setting(bpp_inst_struct *inst);
static void bpp_fill_setting_items(MMI_ID cid, bpp_setting_struct *setting);
static void bpp_set_setting_item(bpp_item_struct *item, 
                                 U64 scope, U64 select, U32 size,
                                 const U8 **str_list, const MMI_STR_ID *str_id_list);
static void bpp_show_setting_options(bpp_inst_struct *inst);
static void bpp_init_setting_options(bpp_inst_struct *inst, MMI_ID opt_id);
static void bpp_del_setting(bpp_inst_struct *inst);

static S32 bpp_print_hdlr(bpp_inst_struct *inst);
static void bpp_setting_abort_hdlr(bpp_inst_struct *inst, cui_event_inline_abort_struct *evt);
static void bpp_setting_notify_hdlr(bpp_inst_struct *inst, cui_event_inline_notify_struct *evt);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void bpp_setting_tap_hdlr(mmi_tap_type_enum tap_type, S32 index);
#endif

static void bpp_show_progress(bpp_inst_struct *inst, U32 mode);
static MMI_ID bpp_show_confirm(bpp_inst_struct *inst, WCHAR *text);

static void bpp_show_update_fail(bpp_inst_struct *inst, U32 result);
static MMI_RET bpp_trouble_enter_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_trouble_exit_hdlr(mmi_scrn_essential_struct *info);
static void bpp_trouble_lsk_hdlr(void);

static MMI_RET bpp_printing_enter_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_printing_exit_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_printing_scrn_proc(mmi_event_struct *evt);
static void bpp_printing_rsk_hdlr(void);

static void bpp_start_operation(bpp_inst_struct *inst);
static void bpp_alert_event_hdlr(bpp_inst_struct *inst, mmi_alert_result_evt_struct *evt);

static void bpp_power_on_hdlr(bpp_inst_struct *inst, MMI_ID cid, MMI_BOOL result);

static void bpp_update_attr_hdlr(bpp_inst_struct *inst, U32 result);

static void bpp_print_doc(bpp_inst_struct *inst);
static void bpp_update_attr(bpp_inst_struct *inst);

static MMI_RET bpp_auth_enter_hdlr(mmi_scrn_essential_struct *info);
static MMI_RET bpp_auth_scrn_proc(mmi_event_struct *evt);
static void bpp_auth_valid_hdlr(U8 *text, U8 *cursor, S32 length);
static void bpp_auth_lsk_hdlr(void);
static void bpp_auth_rsk_hdlr(void);

static bpp_inst_struct *bpp_new_inst(bpp_app_info_struct *app);
static bpp_inst_struct *bpp_find_inst(BppHandle h_srv);
static void bpp_del_inst(bpp_inst_struct *inst);

static void bpp_alert(U32 type, MMI_ID gid, MMI_STR_ID str_id, U32 event);
static void bpp_set_page_info(bpp_inst_struct *inst, U64 media_size, U8 orient);
static S32 adjust_dimension(bpp_dimension *obj, bpp_dimension *box, U32 b_rotate);
static S32 max_dimension(bpp_dimension *max, bpp_dimension *obj, bpp_dimension *box);
static void format_prog_text(WCHAR *text, U16 prog_rate);
static U32 bpp_conv_result(U32 srv_result);

static void bpp_job_start_hdlr(bpp_inst_struct *inst, U32 status);
static void bpp_job_status_hdlr(bpp_inst_struct *inst, U32 status);
static void bpp_job_finish_hdlr(bpp_inst_struct *inst, U32 result);

static void bpp_notify_data_req(bpp_inst_struct *inst);
static void bpp_notify_job_start(bpp_inst_struct *inst);
static void bpp_notify_job_complete(bpp_inst_struct *inst, U32 result);

static void bpp_event_result_hdlr(bpp_inst_struct *inst, mmi_post_result_event_struct *evt);

static void bpp_data_req_hdlr(bpp_inst_struct *inst);
static void bpp_accept_data_req(bpp_inst_struct *inst);
static void bpp_notify_data_req(bpp_inst_struct *inst);
static void bpp_data_helper(bpp_inst_struct *inst);
static MMI_RET bpp_data_helper_proc(evt_bpp_data_helper *evt);

static void bpp_show_auth(bpp_inst_struct *inst);
static void bpp_update_prog_info(bpp_inst_struct *inst, U16 percent);
static void bpp_get_dev_name(WCHAR *buff, PrinterAddr *addr);
static S32 bpp_compatible_image(bpp_inst_struct *inst, U32 img_type);
static CHAR * get_image_mime(U32 img_type);

static S32 bpp_apply_app_style(bpp_inst_struct *inst, void *xhtml);
static S32 bpp_apply_page_style(void *xhtml, bpp_page_struct *page);
static S32 bpp_apply_top_style(void *xhtml, bpp_page_struct *page);
static S32 bpp_apply_bottom_style(void *xhtml, bpp_page_struct *page);
static S32 bpp_apply_text_class_style(void *xhtml, bpp_page_struct *page);
static S32 bpp_compose_image(bpp_inst_struct *inst, bt_print_data_struct *store);
static S32 bpp_compose_image_head(void *xhtml, bpp_inst_struct *inst);
static S32 bpp_compose_image_body(void *xhtml, bpp_inst_struct *inst);
static S32 bpp_compose_text(bpp_inst_struct *inst, bt_print_data_struct *store);

static WCHAR *bpp_default_app_file(bpp_inst_struct *inst);
static U8 bpp_flag_count(U64 num);

#endif /* __MMI_BPP_SUPPORT__ */

#endif /* BPP_MMI_H */


