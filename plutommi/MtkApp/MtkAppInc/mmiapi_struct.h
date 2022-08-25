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
 * mmiapi_struct.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines message structures of MMI.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MMIAPI_STRUCT_
#define _MMIAPI_STRUCT_


#include "MMIDataType.h"

#include "mmiapi_enum.h"

#include "kal_non_specific_general_types.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "MMI_features.h"
#include "l4c_aux_struct.h"
#include "mcd_l4_common.h"
#include "custom_mmi_default_value.h"

#ifndef MAX_DIGITS_SMS
#define MAX_DIGITS_SMS           21
#endif

typedef struct
{
    kal_bool is_blocking;
    kal_bool is_gui;
    kal_bool result;
    int result_int;
    void *result_ptr;
} mmiapi_blocking_data_struct;

typedef struct
{
    LOCAL_PARA_HDR mmiapi_remote_proc_call_enum type;
    void *func_ptr;                 /* Function to be executed remotely */
    void (*finish_callback) (void); /* Callback after operation finished */
    void *blocking_data;            /* Blocking operation */
    union
    {
        int i;                                      /* Integer argument */
        void *p;                                    /* Pointer argument */
    } _u;
      kal_bool(*validate_callback) (kal_uint32);    /* Check whether to execute or not */
    kal_uint32 optional_param;                      /* Optional argument used validate_callback */
} mmiapi_remote_proc_call_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 action_type;
    module_type src_mod_id;
} mmiapi_action_register_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 action_type;
} mmiapi_action_notify_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
    #ifdef __MMI_WAP_DUAL_SIM__
	kal_uint32 sim_info;
    #endif /* __MMI_WAP_DUAL_SIM__ */

} mmiapi_unread_push_icon_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 type;
} mmiapi_mms_icon_ind_struct;

typedef struct
{
    kal_uint16 src_mod_id;
    kal_uint8 action_type;
} mmiapi_action_msg_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 src_mod_id;
    kal_uint8 action;
    kal_uint32 reserved;
} mmiapi_device_get_ctrl_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 result;
} mmiapi_device_get_ctrl_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 src_mod_id;
    kal_uint8 type;
    kal_uint8 level;
    kal_uint32 reserved;
} mmiapi_device_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint8 type;
    kal_uint8 level;
} mmiapi_device_play_rsp_struct;

#ifdef MMIAPI_USING_SMS
typedef struct
{
    LOCAL_PARA_HDR l4c_number_struct addr;
    int port_number;
    kal_uint8 *msg; /* this field should be free by free_ctrl_buffer */
    int msg_length;
    kal_uint16 dcs;
    kal_bool isNotDispSendingIcon;
    kal_bool isSlave; /* If support Dual SIM, register master port: 0, slave SIM port: 1 */
    kal_int32 vm_id;
    kal_uint16 sim_id;
    void *blocking_data;
} mmiapi_sms_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *blocking_data;
} mmiapi_sms_send_abort_req_struct;

typedef struct
{
    module_type mod_src; //09B revise
    kal_int32 vm_id;
    kal_uint8 *msg; /* this field should be free by free_ctrl_buffer */
} mmiapi_sms_send_user_data_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 vm_id;
} mmiapi_sms_send_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    kal_bool enable;
    kal_bool remove_reminder_data;
    kal_bool isSlave; /* If support Dual SIM, register master port: 0, slave SIM port: 1 */
    kal_int32 vm_id;
    kal_uint16 sim_id;
    void *blocking_data;
} mmiapi_sms_register_port_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_uint16 cause;
    kal_int32 vm_id;
} mmiapi_sms_register_port_rsp_struct;
#ifndef __MVM__
typedef struct
{
    LOCAL_PARA_HDR int port_number;
    kal_bool only_new;
    void *blocking_data;
} mmiapi_sms_check_incoming_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR int result;  /* 0: TEXT_MSG  1:BIN_MSG  -1: no message */
} mmiapi_sms_check_incoming_msg_rsp_struct;
#endif /*__MVM__*/
typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_timestamp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 scts[7];
} mmiapi_sms_get_incoming_msg_timestamp_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_address_req_struct;

typedef struct
{
    LOCAL_PARA_HDR l4_addr_bcd_struct incoming_address;
} mmiapi_sms_get_incoming_msg_address_rsp_struct;
#ifndef __MVM__
typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 *message;  /* this field should be free by free_ctrl_buffer */
    int message_len;
} mmiapi_sms_get_incoming_msg_rsp_struct;
#endif /*__MVM__*/
typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
} mmiapi_sms_get_host_address_req_struct;

typedef struct
{
    LOCAL_PARA_HDR l4_addr_bcd_struct host_address;
} mmiapi_sms_get_host_address_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 port_number;
    U16 con_len;
    U8 *content;
    U16 address[MAX_DIGITS_SMS + 1];
    MYTIME time;
    U8 type;
    U8 dcs;
    U16 sim_id;
} mmiapi_sms_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR module_type mod_id;
    kal_bool isSlave; /* If support Dual SIM, master port: 0, slave SIM port: 1 */
    kal_uint16 sim_id;
} mmiapi_sms_get_smsc_addr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR int result;
    int sc_addr_len;
    kal_char sc_addr[MAX_DIGITS_SMS + 1];
} mmiapi_sms_get_smsc_addr_rsp_struct;

#endif /* MMIAPI_USING_SMS */
#ifndef __MVM__
#ifdef MMIAPI_USING_UI
typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
    kal_uint8 *editor_buffer;
    int maxlen;
    int type;
    kal_bool is_must_input;
    void (*editor_cb)(kal_bool result, int text_len);
} mmiapi_ui_enter_fullscreen_editor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR void * blocking_data;
    kal_uint16 year;
    kal_uint8 month;
    kal_uint8 day;
    void ( *callback)(kal_bool date_udpated,kal_uint16 year,kal_uint8 month,kal_uint8 day);

}mmiapi_ui_show_mmi_datefield_req_struct;

typedef struct
{
    LOCAL_PARA_HDR void * blocking_data;
    kal_bool  data_updated;
    kal_uint16 year;
    kal_uint8 month;
    kal_uint8 day;
     void ( *callback)(kal_bool date_udpated,kal_uint16 year,kal_uint8 month,kal_uint8 day);
}mmiapi_ui_show_mmi_datefield_rsp_struct;
typedef struct
{
    LOCAL_PARA_HDR void * blocking_data;
    kal_uint16 * title;
    kal_uint16 ** menu_list;
    kal_int32 * menu_ids;
    kal_int32 menu_num;
    void (*textbox_callback)();
}mmiapi_ui_show_mmi_menu_req_struct;


typedef struct
{
    LOCAL_PARA_HDR void * blocking_data;
    kal_uint16 * title;
    kal_uint16 * ticker;
    kal_uint16 ** menu_list;
    kal_uint8 *  editor_buffer;
    kal_int32 * menu_ids;
    kal_int32 maxLen;
    kal_int32 constraint;
    kal_int32 menu_num;
    kal_bool is_must_input;
    kal_bool is_editable;
    kal_bool is_multiline;
    int border;
    void (*textbox_callback)();
    void (*textbox_enter_callback)();
    void (*textbox_exit_callback)();
}mmiapi_ui_show_mmi_textbox_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    int text_length;
    void (*jui_editor_textbox_callback)();
    int dummy_para1;
    int dummy_para2;
    int dummy_para3;
    int dummy_prar4;
} mmiapi_ui_show_mmi_textbox_editor_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    int text_length;
    void (*jui_editor_cb)(kal_bool result, int text_len);
    int dummy_para1;
    int dummy_para2;
    int dummy_para3;
    int dummy_prar4;
} mmiapi_ui_enter_fullscreen_editor_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
} mmiapi_ui_enter_idle_screen_req_struct;

#endif /* MMIAPI_USING_UI */
#endif /*__MVM__*/
/* backlight control */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
    kal_uint8 disable_timer;
} mmiapi_backlight_control_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
    kal_uint8 disable_timer;
} mmiapi_backlight_control_rsp_struct;

/* led control */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
} mmiapi_led_control_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
} mmiapi_led_control_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 strNumber[183]; /* MUST with null terminator */
    kal_uint32 call_type; /* mmi_ucm_call_type_enum */
}mmi_make_call_req_ind_struct;

/* Get battery info */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 src_mod_id;
} mmiapi_get_battery_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 battery_level;
} mmiapi_get_battery_level_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 src_mod_id;
} mmiapi_battery_level_notify_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} mmiapi_battery_level_notify_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 battery_level;
} mmiapi_battery_level_notify_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 src_mod_id;
} mmiapi_battery_level_notify_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} mmiapi_battery_level_notify_stop_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 id;
    kal_uint8 type;
} mmiapi_gpio_post_vib_req_struct;

/* for MoDIS only */
#ifndef __MTK_TARGET__
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16	input[1000];
    kal_int32	editor_style;
} mmi_direct_input_req_struct;
#endif	/* __MTK_TARGET__ */
#ifndef __MVM__
/*--------------the flowing for DateField---------------------*/
#define  MMIAPI_UI_CLNDR_DAY_LEN           3*ENCODING_LENGTH
#define  MMIAPI_UI_CLNDR_MON_LEN           3*ENCODING_LENGTH
#define  MMIAPI_UI_CLNDR_YEAR_LEN          6*ENCODING_LENGTH

#define MMIAPI_UI_CLNDR_COLUMN 7
#define MMIAPI_UI_CLNDR_ROW 6

#define MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN (5 * ENCODING_LENGTH)

#define MMIAPI_UI_CLNDR_MAX_ROW 24

#define  MMIAPI_UI_CLNDR_TITLE_LEN            12*ENCODING_LENGTH

#define MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN  (4)
#define MMIAPI_UI_CLNDR_VERTICAL_LIST_CELL_LEN  (6)
#define MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN (5 * ENCODING_LENGTH)

#define MMIAPI_UI_CLNDR_CELL_SIZE sizeof(gui_calendar_cell_struct)

#define MMIAPI_UI_CLNDR_START_WEEKDAY 0
#define MMIAPI_UI_CLNDR_TOTAL_WEEKDAY 7

#define MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE 5
#define MMIAPI_UI_CLNDR_MAX_DATE_BUF_SIZE 3
#define MMIAPI_UI_CLNDR_MAX_TIME_BUF_SIZE 3

#define MMIAPI_UI_CLNDR_WEEK_SYMBOL_LEN 1

#define  MMIAPI_UI_CLNDR_START_YEAR     1970      /* the frist year in the database table */
#define  MMIAPI_UI_CLNDR_MONTH_DAYS   31
#define  MMIAPI_UI_CLNDR_END_YEAR         2030    /* the frist year in the database table */

typedef enum
{
    MMIAPI_UI_CLNDR_KEY_UP = 0,
    MMIAPI_UI_CLNDR_KEY_DOWN,
    MMIAPI_UI_CLNDR_KEY_LEFT,
    MMIAPI_UI_CLNDR_KEY_RIGHT,
    MMIAPI_UI_CLNDR_KEY_TOTAL
} MMIAPI_UI_CLNDR_KEY_ENUM;

typedef enum CLNDR_CLNDAR_MOVEMENT
{
    MMIAPI_UI_CLNDR_NEXT_MONTH,
    MMIAPI_UI_CLNDR_PRIVOUS_MONTH,
    MMIAPI_UI_CLNDR_NEXT_WEEK,
    MMIAPI_UI_CLNDR_PRIVOUS_WEEK,
#ifdef __MMI_TOUCH_SCREEN__
    MMIAPI_UI_CLNDR_NEXT_YEAR,
    MMIAPI_UI_CLNDR_PRIVOUS_YEAR,
    MMIAPI_UI_CLNDR_NEXT_PERIOD,
    MMIAPI_UI_CLNDR_PRIVOUS_PERIOD,
    MMIAPI_UI_CLNDR_NEXT_MULTI_PERIOD,
    MMIAPI_UI_CLNDR_PRIVOUS_MULTI_PERIOD,
#endif /* __MMI_TOUCH_SCREEN__ */
    MMIAPI_UI_CLNDR_CLNDAR_MOVEMENT_TOTAL
} MMIAPI_UI_CLNDR_CLNDAR_MOVEMENT_ENUM;

/*-------------------the above for DateField ------------------------*/
#endif /*__MVM__*/
#endif /* _MMIAPI_STRUCT_ */

