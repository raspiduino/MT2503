
#include "MMI_features.h"
#ifdef __MMI_BT_MAP_CLIENT__
#ifndef __SMS__BT_APP_PROT_H__
#define __SMS_BT_APP_PROT_H__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "SmsSrvGprot.h"
#include "ems.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "UmSrvDefs.h"

#include "SmsGuiInterfaceType.h"
#include "SmsAppGProt.h"
#include "SmsAppType.h"
#include "MenuCuiGprot.h"
#include "SmsUmBtMapGProt.h"
#include "SmsUmBtMapProt.h"

#define MMI_MSG_POPUP_TIME_OUT              UI_POPUP_NOTIFYDURATION_TIME_2000
#define mmi_sms_bt_POPUP_TIME_OUT              UI_POPUP_NOTIFYDURATION_TIME_2000
#define mmi_sms_bt_PROGRESS_TIME_OUT           1000*50

#define mmi_sms_bt_MAX_TIMESTAMP_SIZE          12

#define MMI_SMS_BT_MAX_BUFF_SIZE               2048


extern msg_context_struct g_msg_bt_cntx;

extern mmi_sms_bt_context_struct g_sms_bt_cntx;

extern MMI_ID g_sms_bt_gid;
extern mmi_sms_bt_context_struct g_sms_bt_cntx;  

#define MMI_SMS_BT_MAX_NUM_LEN             MAX_DIGITS_SMS

#define MMI_SMS_BT_MAX_RECIPIENTS_NUM      1

#define MMI_SMS_BT_MAX_ADDR_LEN         21

typedef struct
{
    mmi_id menu_cui_gid;
    mmi_menu_id highlighted_menu_id;
    U8 highlighted_item_id;
}mmi_sms_bt_menu_cui_data_struct;

/* SMS Application SIM Card ID Enum */
typedef enum
{
    /* SIM Card 1 */
    SMS_BT_SIM_1 = 0,
    /* SIM Card 2 */
    SMS_BT_SIM_2,
    /* SIM Card 2 */
    SMS_BT_SIM_3,
    /* SIM Card 2 */
    SMS_BT_SIM_4,
    /* Total SIM Card Number */
    SMS_BT_SIM_TOTAL,
    /* Unspecific SIM Card */
    SMS_BT_SIM_UNSPECIFIC
}mmi_sms_bt_sim_enum;
//////////////////////////////////////////////////////////////////////////////
typedef void (*SmsBtFullEditFuncPtr) (S8*);

typedef enum
{
    CUI_SMS_ADDR_TYPE_NUMBER,
    CUI_SMS_ADDR_TYPE_EMAIL_ADDR,
    CUI_SMS_ADDR_TYPE_TOTAL
}cui_sms_bt_address_type_enum;


typedef struct
{
    mmi_id editor_gid;
    U16 phone_number_title_id;
    SmsBtFullEditFuncPtr phone_number_done_func;
    MMI_BOOL phone_number_search_flag;
    cui_sms_bt_address_type_enum phone_number_addr_type;
    U16 phone_number_max_addr_len;
    S8 *phone_number_buff;
    MMI_BOOL is_refresh_scrn;
} cui_sms_bt_edit_phone_number_struct;

extern void cui_sms_bt_send_edit_phone_number(mmi_id parent_id, U16*);

//////////////////////////////////////////////////////////////////////////////



/**************************************************************
* Edit And Send Function
**************************************************************/
extern void mmi_sms_bt_entry_write_msg(mmi_sms_bt_send_case_enum send_msg_case);
#ifndef __MMI_UNIFIED_COMPOSER__    
extern void mmi_sms_bt_pre_entry_add_recipient(MMI_BOOL is_hide_save_menu);
#endif /* __MMI_UNIFIED_COMPOSER__ */
extern MMI_BOOL mmi_sms_bt_append_recipient(S8 *ucs2_addr);
extern U16 mmi_sms_bt_add_addr_list_to_recipient(S8 **ucs2_addr_list, U16 addr_count);
extern void mmi_sms_bt_remove_all_recipient(void);
extern void mmi_sms_bt_reset_recipient_data(void);

#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
extern void mmi_sms_bt_init_recipient_buffer(void);
extern U16 mmi_sms_bt_get_recipient_num(void);
extern S8* mmi_sms_bt_get_recipient_name_buffer(U8 index);
extern U16 mmi_sms_bt_check_recipient_number(U16 num);
extern MMI_BOOL mmi_sms_bt_update_recipient_name_number(U16 index, S8 *ucs2_addr, U16 offset);
extern MMI_BOOL mmi_sms_bt_delete_recipient_number(U16 index);
extern MMI_BOOL mmi_sms_bt_add_recipient_number(U16 index, S8 *ucs2_addr);
extern MMI_BOOL mmi_sms_bt_add_recipient(S8 *ucs2_name, S8 *ucs2_addr);
extern MMI_BOOL mmi_sms_bt_adjust_recipient_number(U16 index);
extern void mmi_sms_bt_set_recipient_number_flag(U16 num);
extern MMI_BOOL mmi_sms_bt_get_recipient_validy(U16 index);
extern U16 mmi_sms_bt_add_many_addr_to_recipient(S8 **ucs2_addr_list, U16 addr_count);
extern void mmi_sms_bt_set_recipient_validy(U16 index, MMI_BOOL is_valid);
extern void mmi_sms_bt_set_recipient_edit_flag(U16 index, U16 editor_flags, MMI_BOOL is_set_cat);
extern U16 mmi_sms_bt_get_recipient_edit_flag(U16 index);
extern void mmi_sms_bt_set_highlight_region(U8 highlight_state);
extern U16 mmi_sms_bt_get_recipient_name(U16 index, U16* name);
#endif /* !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) */

extern void mmi_sms_bt_set_send_msg_case(mmi_sms_bt_send_case_enum send_msg_case);
extern mmi_sms_bt_send_case_enum mmi_sms_bt_get_send_msg_case(void);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
extern void mmi_sms_bt_set_send_type(mmi_sms_bt_msg_type_enum send_type);
extern mmi_sms_bt_msg_type_enum mmi_sms_bt_get_send_type(void);
extern mmi_sms_bt_msg_type_enum mmi_sms_bt_get_preferred_msg_type(void);
void mmi_msg_remove_email_address_from_text_only_msgtxt(S8 *data, U16 text_length);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern MMI_BOOL mmi_sms_bt_get_is_sent(void);
extern void mmi_sms_bt_set_is_sent_false(void);



extern void mmi_sms_bt_write_msg_by_uc(void);

extern void mmi_sms_bt_pre_entry_editor(void);
extern void mmi_sms_bt_entry_editor(void);



/**************************************************************
* Viewer Function
**************************************************************/


/************************************************
******* MISC ***********************************
***********************************************/

extern void mmi_sms_bt_send_sms_dummy(void);


/********************************************
****** Util.h ******************************
********************************************/

extern EMSTATUS mmi_sms_bt_add_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_bt_add_gsm_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_bt_add_data_to_ems_data(
                            EMSData *ems_data,
                            U16 src_port,
                            U16 dest_port,
                            S8 *file_path,
                            S8 *content_buff,
                            U32 buff_size);
extern U16 mmi_sms_bt_convert_to_extension_char_buff(S8 *dest_buf, S8 *src_buf, U16 char_num);
extern void mmi_sms_bt_asc_to_wchar(S8 *dest_buf, S8 *src_buf, U32 src_buf_len);

extern MMI_BOOL mmi_sms_bt_is_ems_content_empty(EMSData *ems_data);
//** Common UI **//
// show progressing screen **//
void mmi_sms_bt_entry_processing_generic_sg(void);
void mmi_sms_bt_set_and_entry_processing_sg(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId);
// show progressing screen **//




//** editor **//
void mmi_sms_bt_entry_editor(void);

/********************************************
****** GProt.h ******************************
********************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_allow_send_sms
 * DESCRIPTION
 *  Check whether allow to send SMS;
 *  The below cases is not allow to SMS:
 *  1> SIM Card is invalid;
 *  2> SMS is not ready;
 *  3> It is existed scenario related to sending SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  Result of Whether allow to send SMS
 * RETURN VALUES
 *  MMI_TRUE    :   Allow to send SMS
 *  MMI_FALSE   :   Don't allow to send SMS
 *****************************************************************************/
extern MMI_BOOL mmi_sms_bt_is_allow_send_sms(void);



typedef struct
{
    U16 result;             /* srv_sms_cause_enum */
    U16 request_type;       /* mmi_sms_request_type_enum */
    U8 number[21 + 1];          /* Optional. Destination phone number. Needed in send case. Must contain NULL terminator */
    MMI_BOOL display_popup;     /* TRUE to display popup. Please set TRUE in general cases */
    MMI_BOOL delete_sms_screen; /* TRUE to delete SMS framework screens in history.  Please set TRUE in general cases */
    /* Note: if is_display_pupup is FALSE, then current screen would not be deleted even if it belongs to SMS framwork screens because it is not in history.  */
} mmi_sms_bt_api_result_handler_struct;

typedef enum
{
    MMI_SMS_BT_REQ_SEND,
    MMI_SMS_BT_REQ_SAVE,
    MMI_SMS_BT_REQ_TOTAL
} mmi_sms_bt_request_type_enum;



/*************************************************************************************
************************* extern variable ********************************************
*************************************************************************************/

extern MMI_ID g_sms_bt_gid;
extern mmi_sms_bt_context_struct g_sms_bt_cntx;


/*************************************************************************************
************************* ems based ********************************************
*************************************************************************************/
extern EMSData *SmsBtGetEMSDataForEdit(EMSData **p, U8 force);
extern EMSData *SmsBtGetEMSDataForView(EMSData **p, U8 force);
extern void SmsBtReleaseEMSEditBuffer(void);
extern void SmsBtReleaseEMSViewBuffer(void);
extern EMSTATUS mmi_sms_bt_add_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_bt_add_gsm_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_bt_add_data_to_ems_data(
                            EMSData *ems_data,
                            U16 src_port,
                            U16 dest_port,
                            S8 *file_path,
                            S8 *content_buff,
                            U32 buff_size);
extern U16 mmi_sms_bt_convert_to_extension_char_buff(S8 *dest_buf, S8 *src_buf, U16 char_num);
extern void mmi_sms_bt_asc_to_wchar(S8 *dest_buf, S8 *src_buf, U32 src_buf_len);

extern MMI_BOOL mmi_sms_bt_is_ems_content_empty(EMSData *ems_data);
extern srv_sms_msg_data_struct *mmi_sms_bt_get_msg_data_for_forward(void);
#endif /* __SMS_APP_PROT_H__ */

#endif