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
 *  BarcodeReaderOP11.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Barcode Reader OP11 Header File
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BARCODEREADER_OP11_H
#define MMI_BARCODEREADER_OP11_H

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "wgui_inline_edit.h"
#include "BarcodereaderCameraSettingResDef.h"
#include "BarcodereaderOp11ResDef.h"
#include "FileMgr.h"
#include "BarcodereaderCommonProt.h"
#include "resource_barcodereader_skins.h"
//#include "PhoneBookTypes.h"
#include "vCard.h"
/****************************************************************************
* macro declare                                                                
*****************************************************************************/
#define MMI_BARCODEREADER_HELP_CONTENT_PHASE_COUNT      (STR_ID_BARCODEREADER_OP11_HELP_END - STR_ID_BARCODEREADER_OP11_HELP1)
#define MMI_BARCODEREADER_DM_SETTING_ITEM_COUNT         (STR_ID_BARCODEREADER_OP11_DM_SETTING_END - STR_ID_BARCODEREADER_OP11_DM_SETTING_START - 1)
#define MMI_BARCODEREADER_ENCODING_ITEM_COUNT           (STR_ID_BARCODEREADER_OP11_ENCODING_END - STR_ID_BARCODEREADER_OP11_ENCODING_START - 1)    
#define MMI_BARCODEREADER_SWITCH_COUNT                  (2)
#define MMI_BARCODEREADER_MAX_URL_LENGTH_OF_ALL_BRW		(256)
#define MMI_BARCODEREADER_MAX_URL_LENGTH_OF_EDITOR		(240)
#define MMI_BARCODEREADER_URL_LENGTH                    (768)
#define MMI_BARCODEREADER_SERVER_BUFFER                 (768 * ENCODING_LENGTH)
#define MMI_BARCODEREADER_MAX_URL_PREFIX_LENGTH			(20)
#define MMI_BARCODEREADER_HISTORY_NODE_COUNT            (20)
#define MMI_BARCODEREADER_CURR_VERSION                  "V1.0"
#define MMI_BARCODEREADER_HISTORY_FILE_PATH             L"z:\\@barcodereader\\"
#define MMI_BARCODEREADER_HISTORY_FILE_NAME             L"history.txt"
#define MMI_BARCODEREADER_POPUP_DURATION                (1000)
#define MMI_BARCODEREADER_DATETIME_STRING_BUFFER        (20)
#define MMI_BARCODEREADER_HINT_BUFFER_SIZE              (26*ENCODING_LENGTH)
#define MMI_BARCODEREADER_SCR_OSD_BUFFER_SIZE           (LCD_WIDTH * LCD_HEIGHT * (GDI_MAINLCD_BIT_PER_PIXEL >> 3))
#define MMI_BARCODEREADER_ATTR_SEPERATOR                '|'
#define MMI_BARCODEREADER_MAX_PREMIUM_SN_LENGHT         (16)
#define MMI_BARCODEREADER_URL_DEFAULT_ACTION            L"1"
#define MMI_BARCODEREADER_VCARD_DEFAULT_ACTION          L"4"
#define MMI_BARCODEREADER_URL_SHORTCUT_PREFIX           L"5410000000"
#define MMI_BARCODEREADER_HINT_POPUP_FADE_TIME          (1000)
#define MMI_BARCODEREADER_MAX_OPTION_MENU_LIST          (16)
#define MMI_BARCODEREADER_MAX_SMS_CONTENT              (670)
#define MMI_BARCODEREADER_DECODE_TIME                   (10000)
/* barcode service type name */
#define MMI_BARCODEREADER_FILE_EXT_NAME                 L".dat"

/* attr value */
#define MMI_BARCODEREADER_ATTR_TO_VALUE                 0x00000001
#define MMI_BARCODEREADER_ATTR_URL_VALUE                0x00000002
#define MMI_BARCODEREADER_ATTR_NAME_VALUE               0x00000004
#define MMI_BARCODEREADER_ATTR_FIXTEL_VALUE             0x00000008
#define MMI_BARCODEREADER_ATTR_MOBILETEL_VALUE          0x00000010
#define MMI_BARCODEREADER_ATTR_EMAIL_VALUE              0x00000020
#define MMI_BARCODEREADER_ATTR_EMAIL2_VALUE             0x00000040
#define MMI_BARCODEREADER_ATTR_BDAY_VALUE               0x00000080
#define MMI_BARCODEREADER_ATTR_ADR_VALUE                0x00000100
#define MMI_BARCODEREADER_ATTR_ORG_VALUE                0x00000200
#define MMI_BARCODEREADER_ATTR_NUMBER_VALUE             0x00000400
#define MMI_BARCODEREADER_ATTR_TITLE_VALUE              0x00000800
#define MMI_BARCODEREADER_ATTR_BODY_VALUE               0x00001000

/****************************************************************************
* enum declare                                                                
*****************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_MENULIST_PREVIEW = 0,
    MMI_BARCODEREADER_MENULIST_HISTORY,
    MMI_BARCODEREADER_MENULIST_SETTING,
    MMI_BARCODEREADER_MENULIST_HELP,

    MMI_BARCODEREADER_MENULIST_ALL
} mmi_barcodereader_menulist_enum;

typedef enum
{
    MMI_BARCODEREADER_OPTION_NONE = 0,
    MMI_BARCODEREADER_OPTION_HISTORY,
    MMI_BARCODEREADER_OPTION_CALL,
    MMI_BARCODEREADER_OPTION_SMS,
    MMI_BARCODEREADER_OPTION_SETTING,

    MMI_BARCODEREADER_OPTION_ALL
} mmi_barcodereader_option_enum;

typedef enum
{
    MMI_BARCODEREADER_DM_SETTING_ITEM_AUTO_RECOGNIZE = 0,
    MMI_BARCODEREADER_DM_SETTING_ITEM_SOUND,
    MMI_BARCODEREADER_DM_SETTING_ITEM_COVERAGE_NOTIFY,
    MMI_BARCODEREADER_DM_SETTING_ITEM_DIRECT_MODE,
    MMI_BARCODEREADER_DM_SETTING_ITEM_DIRECT_STORAGE,
    MMI_BARCODEREADER_DM_SETTING_ITEM_ENCODING,

    MMI_BARCODEREADER_DM_SETTING_ITEM_ALL
} mmi_barcodereader_dm_setting_item_enum;

typedef enum
{
    MMI_BARCODEREADER_DM_ENCODING_START,
#ifdef __MMI_CHSET_WESTERN_WIN__
        MMI_BARCODEREADER_DM_ENCODING_ASC,
#endif
        /*MMI_BARCODEREADER_DM_ENCODING_UCS2,*/
        MMI_BARCODEREADER_DM_ENCODING_UTF8,
#ifdef __MMI_CHSET_BIG5__
        MMI_BARCODEREADER_DM_ENCODING_BIG5,
#endif
#ifdef __MMI_CHSET_GB2312__
        MMI_BARCODEREADER_DM_ENCODING_GB2312,
#endif
#ifdef __MMI_CHSET_HKSCS__
       MMI_BARCODEREADER_DM_ENCODING_HKSCS,
#endif
        MMI_BARCODEREADER_DM_ENCODING_ALL
}mmi_barcodereader_dm_encoding_enum;

typedef enum
{
    MMI_BARCODEREADER_SWITCH_OFF = 0,
    MMI_BARCODEREADER_SWITCH_ON,

    MMI_BARCODEREADER_SWITCH_ALL
} mmi_barcodereader_switch_enum;

typedef enum
{
    MMI_BARCODEREADER_MODE_TYPE_NONE = 0,
    MMI_BARCODEREADER_MODE_TYPE_BASIC,
    MMI_BARCODEREADER_MODE_TYPE_PREMIUM,

    MMI_BARCODEREADER_MODE_TYPE_ALL
} mmi_barcodereader_mode_type_enum;

typedef enum
{
    MMI_BARCODEREADER_SERVICE_TYPE_VCARD = 0,
    MMI_BARCODEREADER_SERVICE_TYPE_CALL,
    MMI_BARCODEREADER_SERVICE_TYPE_URL,
    MMI_BARCODEREADER_SERVICE_TYPE_SMS,

    MMI_BARCODEREADER_SERVICE_TYPE_ALL
} mmi_barcodereader_service_type_enum;

typedef enum
{
    MMI_BARCODEREADER_ACTION_TYPE_NOT = 0,
    MMI_BARCODEREADER_ACTION_TYPE_DO,
    MMI_BARCODEREADER_ACTION_TYPE_EDIT,
    MMI_BARCODEREADER_ACTION_TYPE_EDIT_AND_DO,
    MMI_BARCODEREADER_ACTION_TYPE_SAVE,
    MMI_BARCODEREADER_ACTION_TYPE_SAVE_AND_DO,
    MMI_BARCODEREADER_ACTION_TYPE_EDIT_AND_SAVE,
    MMI_BARCODEREADER_ACTION_TYPE_EDIT_AND_SAVE_AND_DO,
    MMI_BARCODEREADER_ACTION_TYPE_RESERVED1,
    MMI_BARCODEREADER_ACTION_TYPE_RESERVED2,

    MMI_BARCODEREADER_ACTION_TYPE_ALL
} mmi_barcodereader_action_type_enum;

typedef enum
{
    /* SMS */
    MMI_BARCODEREADER_ATTR_TO = 0,
    MMI_BARCODEREADER_ATTR_BODY,
    /* MMI_BARCODEREADER_ATTR_TITLE */

    /* URL */
    MMI_BARCODEREADER_ATTR_URL,
    /* MMI_BARCODEREADER_ATTR_TITLE */

    /* VCARD */
    MMI_BARCODEREADER_ATTR_NAME,
    MMI_BARCODEREADER_ATTR_FIXTEL,
    MMI_BARCODEREADER_ATTR_MOBILETEL,
    MMI_BARCODEREADER_ATTR_EMAIL,
    MMI_BARCODEREADER_ATTR_EMAIL2,
    MMI_BARCODEREADER_ATTR_BDAY,
    MMI_BARCODEREADER_ATTR_ADR,
    MMI_BARCODEREADER_ATTR_ORG,

    /* TEL */
    MMI_BARCODEREADER_ATTR_NUMBER,
    MMI_BARCODEREADER_ATTR_TITLE,

    MMI_BARCODEREADER_ATTR_ALL
} mmi_barcodereader_attr_enum;

typedef enum
{
    MMI_BARCODEREADER_STATE_EXIT = 0,
    MMI_BARCODEREADER_STATE_PREVIEW,
    MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE,

    MMI_BARCODEREADER_STATE_ALL
} mmi_barcodereader_state_enum;

typedef enum
{
    MMI_BARCODEREADER_TOUCH_NONE,
    MMI_BARCODEREADER_TOUCH_LSK,
    MMI_BARCODEREADER_TOUCH_RSK,

    MMI_BARCODEREADER_TOUCH_ALL
} mmi_barcodereader_touch_enum;

typedef enum
{
    MMI_BARCODEREADER_SN_FULL = 16,
    MMI_BARCODEREADER_SN_DEFAULT_ACTION = 15,
    MMI_BARCODEREADER_SN_SHORTCUT = 6,

    MMI_BARCODEREADER_SN_ALL
} mmi_barcodereader_sn_enum;

typedef enum
{
    MMI_BARCODEREADER_ENCODING_TYPE_UTF8 = 0,
    MMI_BARCODEREADER_ENCODING_TYPE_GB2312,
    MMI_BARCODEREADER_ENCODING_TYPE_UNICODE,

    MMI_BARCODEREADER_ENCODING_TYPE_ALL
} mmi_barcodereader_encoding_type_enum;

typedef enum
{
    MMI_BARCODEREADER_INPUT_METHOD_TYPE_DONE = 0,
    MMI_BARCODEREADER_INPUT_METHOD_TYPE_INPUTMETHOD,

    MMI_BARCODEREADER_INPUT_METHOD_TYPE_ALL
}mmi_barcodereader_inputmethod_option_enum;

typedef enum
{
    MMI_BARCODEREADER_URL_PREFIX_TYPE_RESERVED,
    MMI_BARCODEREADER_URL_PREFIX_TYPE_HTTP,
    MMI_BARCODEREADER_URL_PREFIX_TYPE_HTTP_WWW,
    MMI_BARCODEREADER_URL_PREFIX_TYPE_HTTPS,
    MMI_BARCODEREADER_URL_PREFIX_TYPE_HTTPS_WWW,
    MMI_BARCODEREADER_URL_PREFIX_TYPE_RTSP,

    MMI_BARCODEREADER_URL_PREFIX_TYPE_ALL
}mmi_barcodereader_ulr_prefix_type;

/****************************************************************************
* structure declare                                                                
*****************************************************************************/
#define MMI_BARCODEREADER_APP_CALL_ATTR_ALL     (MMI_BARCODEREADER_ATTR_NUMBER_VALUE    |\
                                                 MMI_BARCODEREADER_ATTR_TITLE_VALUE)

#define MMI_BARCODEREADER_APP_SMS_ATTR_ALL      (MMI_BARCODEREADER_ATTR_TO_VALUE        |\
                                                 MMI_BARCODEREADER_ATTR_BODY_VALUE      |\
                                                 MMI_BARCODEREADER_ATTR_TITLE_VALUE)

#define MMI_BARCODEREADER_APP_VCARD_ATTR_ALL    (MMI_BARCODEREADER_ATTR_NAME_VALUE      |\
                                                 MMI_BARCODEREADER_ATTR_FIXTEL_VALUE    |\
                                                 MMI_BARCODEREADER_ATTR_MOBILETEL_VALUE |\
                                                 MMI_BARCODEREADER_ATTR_EMAIL_VALUE     |\
                                                 MMI_BARCODEREADER_ATTR_EMAIL2_VALUE    |\
                                                 MMI_BARCODEREADER_ATTR_BDAY_VALUE      |\
                                                 MMI_BARCODEREADER_ATTR_ADR_VALUE       |\
                                                 MMI_BARCODEREADER_ATTR_ORG_VALUE )

#define MMI_BARCODEREADER_APP_URL_ATTR_ALL     (MMI_BARCODEREADER_ATTR_URL_VALUE    |\
                                                MMI_BARCODEREADER_ATTR_TITLE_VALUE)
/****************************************************************************
* structure declare                                                                
*****************************************************************************/
typedef struct
{
    S32 item_index[10];                         /* 0 -- auto_recognize, 1 -- sound, 2 -- coverage_notify, 3 -- confirm_popup , 4 -- direct_mode , 5 -- 10 reserved */
    U8 server[MMI_BARCODEREADER_SERVER_BUFFER]; /* the size is the same to URL */
} mmi_barcodereader_dm_record_setting_struct;

typedef struct
{
    PS8 item[MMI_BARCODEREADER_DM_SETTING_ITEM_COUNT][MMI_BARCODEREADER_SWITCH_COUNT];
    PS8 item_encoding[MMI_BARCODEREADER_ENCODING_ITEM_COUNT];
    /* selected item */
    S32 item_index[MMI_BARCODEREADER_DM_SETTING_ITEM_COUNT];
    U8 server[MMI_BARCODEREADER_SERVER_BUFFER];
    U8 tmp_server[MMI_BARCODEREADER_SERVER_BUFFER + ENCODING_LENGTH];

    MMI_BOOL is_loaded;
    MMI_BOOL is_server_changed;
} mmi_barcodereader_dm_setting_cntx_struct;

typedef struct
{
    U8 version[11];
    U8 index[MMI_BARCODEREADER_HISTORY_NODE_COUNT];
    U16 time[MMI_BARCODEREADER_HISTORY_NODE_COUNT][MMI_BARCODEREADER_DATETIME_STRING_BUFFER *ENCODING_LENGTH];
    U16 mode[MMI_BARCODEREADER_HISTORY_NODE_COUNT];
    U16 service_type[MMI_BARCODEREADER_HISTORY_NODE_COUNT];
    U16 file_name[MMI_BARCODEREADER_HISTORY_NODE_COUNT][FMGR_MAX_FILE_LEN *ENCODING_LENGTH];
    U16 file_title[MMI_BARCODEREADER_HISTORY_NODE_COUNT][FMGR_MAX_FILE_LEN *ENCODING_LENGTH];
} mmi_barcodereader_history_struct;

typedef struct
{
    HILITE_STR ct_element[MMI_BARCODEREADER_ATTR_ALL];
    U32 ct_mask;
    U32 mode;
    U32 service_type;
    U32 action_type;
    MMI_BOOL is_all_null;
    MMI_BOOL is_special_url;
} mmi_barcodereader_app_content_struct;

typedef struct
{
    S32 service_type;
    S32 default_action_type;
} mmi_barcodereader_service_and_default_action_mapping_table_struct;

typedef struct
{
    PU16 text_buffer;
    PU16 formatted_text_buffer;

    U8 paritydata;
    U8 encoding;

    U16 file_path[FMGR_MAX_PATH_LEN];
    S16 url_addr[MMI_BARCODEREADER_URL_LENGTH + 1];

    MMI_BOOL stop_decode;
} mmi_barcodereader_decode_struct;

typedef struct
{
    U16 preview_width;
    U16 preview_height;
    U16 image_width;
    U16 image_height;

    PS8 hint1_buf;
    PS8 hint2_buf;
    MMI_BOOL hint_fade;

    gdi_handle base_layer_handle;
    gdi_handle osd_layer_handle;
    gdi_handle preview_layer_handle;
    gdi_handle background_layer;

    U32 base_UI_device_width;
    U32 base_UI_device_height;

    PU8 osd_layer_buf_ptr;
    barcodereader_osd_layeout_struct *active_barcodereader_osd_ptr;
} mmi_barcodereader_preview_struct;

typedef struct
{
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
} mmi_barcodereader_memory_struct;

typedef struct
{
    mmi_barcodereader_state_enum curr_state;
    mmi_barcodereader_state_enum prev_state;
    mmi_barcodereader_state_enum next_state;
    MMI_BOOL is_barcodereader_running;
} mmi_barcodereader_app_state_struct;

typedef struct
{
    MMI_BOOL is_draw_status_bar;
    MMI_BOOL is_draw_title_bar;
    MMI_BOOL is_draw_softkey_bar;
} mmi_barcodereader_draw_osd_struct;

typedef struct
{
    U16 af_zone0_x;
    U16 af_zone1_x;
    U16 af_zone2_x;
    U16 af_zone3_x;
    U16 af_zone4_x;
    U16 af_zone5_x;
    U16 af_zone6_x;
    U16 af_zone7_x;
    U16 af_zone8_x;
    U16 af_zone9_x;
    U16 af_zone0_y;
    U16 af_zone1_y;
    U16 af_zone2_y;
    U16 af_zone3_y;
    U16 af_zone4_y;
    U16 af_zone5_y;
    U16 af_zone6_y;
    U16 af_zone7_y;
    U16 af_zone8_y;
    U16 af_zone9_y;

    mmi_barcodereader_af_states af_state;
    mmi_barcodereader_af_animtaion_process af_animation_process;
    U8 af_result;
    MMI_BOOL is_capturing;
    MMI_BOOL is_af_canceled;
} mmi_barcodereader_af_struct;

typedef struct
{
    U32 attr;
    U32 value;
    U16 string_id;
} mmi_barcodereader_attribute_struct;

typedef struct
{
    S32 zoom_index;
    S32 zoom_width;
    S32 zoom_height;
    S32 digit_width;
    S32 digit_height;
    S32 point_width;
    S32 point_height;
} mmi_barcodereader_zoom_struct;

typedef struct
{
    U32 value;
    S8  string[20];
    S8  character;
} mmi_barcodereader_url_prefix_struct;

typedef struct
{
    mmi_barcodereader_error_struct last_error;
    mmi_barcodereader_dm_record_setting_struct record;
    mmi_barcodereader_dm_setting_cntx_struct setting_cntx;

    /* history */
    mmi_barcodereader_history_struct history;
    S32 history_curr_index;
    S32 history_index_to_add;
    MMI_BOOL history_full;
    U16 temp_file_title[FMGR_MAX_FILE_LEN *ENCODING_LENGTH];

    mmi_barcodereader_app_content_struct app_content;

    mmi_barcodereader_decode_struct result;

    mmi_barcodereader_preview_struct preview_data;

    mmi_barcodereader_memory_struct memory;

    mmi_barcodereader_app_state_struct app_state;

    mmi_barcodereader_draw_osd_struct osd;

    mmi_barcodereader_touch_enum touch_obj;

    mmi_barcodereader_af_struct af;

    /* zoom */
    mmi_barcodereader_zoom_struct zoom;

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    U8 preview_watchdog_duration;
#endif

    U8 rename_option_index;
    U8 edit_server_option_index;
    PS8 scr_asm_buffer_ptr;

    mmi_id save_number_cui_id;
    mmi_vcard_field_data_struct vcard_data;
    MMI_BOOL vcard_buffer_using;

    mmi_id sms_cui_id;
    
} mmi_barcodereader_op11_cntx_struct;

extern wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];



#endif /* MMI_BARCODEREADER_OP11_H */ 

