/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MtvSmsAppSendmsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Send related  
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/

/************************************
 * Header Files Include
 **************************************************************/
 
#include "mmi_include.h"
#ifdef __ATV_SMS_SUPPORT__

#include "mtvsmsiprot.h"
#include "custom_events_notify.h"
#include "wgui_categories_inputs.h"
#include "Phonebookresdef.h"
#include "wgui_include.h"  /* this file is used to solve set_left_softkey_icon missing error */
#include "Wgui_fixed_menus.h"
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

/* #include "APPSDKAppGProt.h" */
/**************************************************************
 * Const define
 **************************************************************/
#define MMI_MTV_SMS_SEND_INFO_TRACE1    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_INFO1,  send_info_data.is_sending, send_info_data.is_aborting, send_info_data.is_sent, send_info_data.send_case, send_info_data.send_result)
#define MMI_MTV_SMS_SEND_INFO_TRACE2    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_INFO2,  send_info_data.send_result, send_info_data.sim_id, send_info_data.call_back_func, send_info_data.caller_call_back)
#define MMI_MTV_SMS_SEND_SAVE_CNTX MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_SAVE_CNTX, save_del_para_data.del_send_succ_flag, save_del_para_data.save_sent_flag, save_del_para_data.del_send_fail_flag, save_del_para_data.save_send_fail_flag, save_del_para_data.send_result)
#define MMI_MTV_SMS_SEND_HANDLE1 MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_HANDLE1, mtv_sms_send_handle->recipient, mtv_sms_send_handle->reply_msg_id, mtv_sms_send_handle->content_ems, mtv_sms_send_handle->is_recipient_modified)
#define MMI_MTV_SMS_SEND_HANDLE2 MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_HANDLE2, mtv_sms_send_handle->send_msg_case, mtv_sms_send_handle->srv_send_handle, mtv_sms_send_handle->sim_id)

typedef void (*SmsSendResultCBFuncPtr) (mtv_sms_result_enum, void*);

/**************************************************************
 * Structure Declaration
 **************************************************************/
typedef struct
{
    MMI_BOOL is_sending;    /* To Control the abort action */
    MMI_BOOL is_aborting;   /* To Control the Send action */
    MMI_BOOL is_sent;       /* To control editor delete */
    mmi_mtv_sms_send_case_enum send_case;
    mtv_sms_result_enum send_result;
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    SmsSendResultCBFuncPtr call_back_func;
    MtvSmsSendCBFuncPtr caller_call_back;
} mmi_mtv_sms_send_info_struct;

typedef struct
{
    MMI_BOOL del_send_succ_flag;        //Whether Delete the sent msg
    MMI_BOOL del_send_fail_flag;        //Whether Delete the send failed msg
    MMI_BOOL save_send_fail_flag;       //Whether Save the send failed msg to Outbox
    MMI_BOOL save_sent_flag;
    MMI_BOOL send_result;
}mmi_mtv_sms_send_save_delete_struct; 

typedef struct
{
    MMI_BOOL is_recipient_modified;
    mmi_mtv_sms_send_case_enum send_msg_case;
    srv_sms_sim_enum sim_id;
    U16 reply_msg_id;
    U16 recipient[MTV_MTV_SMS_MAX_ADDR_LEN + 1];
    EMSData *content_ems;
    SMS_HANDLE srv_send_handle;
} mtv_sms_send_handle_struct;

typedef struct
{
    MMI_BOOL is_modify;
    U16 total_num;
    U16 recipient[MTV_MTV_SMS_MAX_ADDR_LEN + 1];
}mmi_mtv_sms_add_recipient_struct;



/**************************************************************
 * Global Variables Declaration
 **************************************************************/
extern const U16 gIndexIconsImageList[];


/**************************************************************
 * Global Function Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination
 **************************************************************/

/**************************************************************
 * Global Variables Declaration
 **************************************************************/

/**************************************************************
 * Static Variables Defination
 **************************************************************/
static mmi_mtv_sms_send_info_struct send_info_data;
static mmi_mtv_sms_add_recipient_struct mtv_recipient_data; 
static CHAR *mtv_recipient_buffer = NULL;
static mtv_sms_send_handle_struct* mtv_sms_send_handle = NULL;
static mmi_mtv_sms_send_save_delete_struct save_del_para_data;

/**************************************************************
 * Static Function Declaration
 **************************************************************/
static void mmi_mtv_sms_remove_edit_all_ems_objects(EMSData** ppEMS);

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

static void mmi_mtv_sms_entry_input_recipient(void);
static MMI_BOOL mmi_mtv_sms_append_recipient(S8 *ucs2_addr);
static void mmi_mtv_sms_start_send_msg_flow(mmi_mtv_sms_send_case_enum send_case);
static void mmi_mtv_sms_pre_entry_input_recipient(void);
static U8 mmi_mtv_sms_recipient_editor_del_cb(void * dummy);
static void mmi_mtv_sms_pre_send_msg(void);
static MMI_BOOL mmi_mtv_sms_init_send_handle_data(void);
static void mmi_mtv_sms_fill_handle_one_recipient_data(U8* ucs2_addr);

static void mmi_mtv_sms_pre_entry_sending(void);

static void mmi_mtv_sms_recipient_input_lsk_handler(void);
static void mmi_mtv_sms_get_recipient_from_editor(S8 *src);

static void mmi_mtv_sms_send_single_sms(void);
static void mmi_mtv_sms_entry_sending(void);
static void mmi_mtv_sms_send_msg_result_handle(mtv_sms_result_enum result, void *data);
static void mmi_mtv_sms_entry_abort_sending(void);
static MMI_BOOL mmi_mtv_sms_get_send_finish_popup_info(mtv_sms_send_handle_struct *handle, U16 *body_str_id, mmi_mtv_event_notify_enum *event_id);
static void mmi_mtv_sms_abort_send_msg(void);
static void mmi_mtv_sms_send_close_all_sending(void);
static void mmi_mtv_sms_deinit_send_handle_data(void);

static void mmi_mtv_sms_send_processing_handler(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_set_save_and_delete_para(void);
static void mmi_mtv_sms_send_msg_req(mtv_sms_send_handle_struct *send_handle, SrvSmsCallbackFunc callback_func);
static void mmi_mtv_sms_send_delete_handle(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_save_msg_req(mtv_sms_send_handle_struct *send_handle, srv_sms_status_enum set_status, SrvSmsCallbackFunc callback_func);
static void mmi_mtv_sms_send_save_handle(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_get_recipient_from_phb(U16 index);
static void mmi_mtv_sms_recipient_content_changed_call_back(void);
static void mmi_mtv_sms_list_entry_write_msg_ems_cut_confirm_lsk_func(void);
static U8 mmi_mtv_sms_sending_scrn_del_callback(void* dummy);

static void mmi_mtv_sms_entry_dual_sim_select(MMI_ID scr_id, MMI_ID root_id);

/**************************************************************
 * Function Definition
**************************************************************/
void mmi_mtv_sms_send_register_call_back(MtvSmsSendCBFuncPtr call_back)
{
    send_info_data.caller_call_back = call_back;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_remove_edit_all_ems_objects
 * DESCRIPTION
 *  remvoe all ems object for edit
 * PARAMETERS
 *  ppEMS       [IN]    eMS data for edit
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_remove_edit_all_ems_objects(EMSData** ppEMS)
{}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_copy_ems_parameters
 * DESCRIPTION
 *  Get previous parameter back 
 * PARAMETERS
 *  ppEMS       [IN]    eMS data for edit
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_copy_ems_parameters(EMSData* pEMS_dst, EMSData* pEMS_src)
{
    EMSSetDCS(pEMS_dst, pEMS_src->dcs);
    pEMS_dst->PortNum = pEMS_src->PortNum;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_start_send_msg_get_sendcase
 * DESCRIPTION
 *  get preset sendcase and Entry Write or Send Message screen
 * PARAMETERS
 *  void       [IN]    void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_start_send_msg_get_sendcase(void)
{
    mmi_mtv_sms_send_case_enum send_case = mmi_mtv_sms_get_send_msg_case();
    mmi_mtv_sms_start_send_msg_flow(send_case);
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_send_msg_case
 * DESCRIPTION
 *  set send message case state
 * PARAMETERS
 *  send_msg_case        [IN]  	send msg case      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_set_send_msg_case(mmi_mtv_sms_send_case_enum send_msg_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	send_info_data.send_case = send_msg_case;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_write_msg_ems_cut_confirm
 * DESCRIPTION
 *  to show confirm to cut screen if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_write_msg_ems_cut_confirm()
{
    mmi_mtv_sms_send_case_enum send_case = mmi_mtv_sms_get_send_msg_case();
    switch (send_case)
    {
        case MTV_SMS_SEND_CASE_EDIT_DRAFT:
        case MTV_SMS_SEND_CASE_EDIT_UNSENT:
        case MTV_SMS_SEND_CASE_RESEND:
        case MTV_SMS_SEND_CASE_SEND_DRAFT:
        case MTV_SMS_SEND_CASE_FORWARD:
        {
            EMSData *pEMS = MtvGetEMSDataForView(NULL, 0);

            MMI_ASSERT(pEMS != NULL);

            if ((pEMS->listHead != NULL) && 
                ((send_case == MTV_SMS_SEND_CASE_EDIT_DRAFT) ||
                 (send_case == MTV_SMS_SEND_CASE_EDIT_UNSENT) ||
                 (send_case == MTV_SMS_SEND_CASE_FORWARD))&&
                 !IsScreenPresent(SCR_ID_MTV_SMS_VIEWER))
            {
                mmi_mtv_sms_entry_confirm_generic(
                    SCR_ID_MTV_SMS_CONFIRM_REMOVE,
                    STR_ID_MTV_SMS_REMOVE_OBJECT_CONFIRM,
                    mmi_mtv_sms_list_entry_write_msg_ems_cut_confirm_lsk_func,
                    GoBackHistory);
            }
            else
            {
                mmi_mtv_sms_start_send_msg_get_sendcase();
            }
            break;
        }
        default:
             mmi_mtv_sms_start_send_msg_get_sendcase();
             break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_entry_write_msg_ems_cut_confirm_lsk_func
 * DESCRIPTION
 *  entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_entry_write_msg_ems_cut_confirm_lsk_func(void)
{
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_CONFIRM_REMOVE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_send_msg_case
 * DESCRIPTION
 *  get send message case state
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_msg_send_case_enum
 *****************************************************************************/
mmi_mtv_sms_send_case_enum mmi_mtv_sms_get_send_msg_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return send_info_data.send_case;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_init_send_handle_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_init_send_handle_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_sms_send_handle != NULL)
    {
        OslMfree(mtv_sms_send_handle);
        mtv_sms_send_handle = NULL;
    }
    mtv_sms_send_handle = OslMalloc(sizeof(mtv_sms_send_handle_struct));
    MMI_ASSERT(mtv_sms_send_handle != NULL);
    memset(mtv_sms_send_handle, 0, sizeof(mtv_sms_send_handle_struct));
    mtv_sms_send_handle->content_ems = g_mtv_sms_cntx.edit_ems_data;
    if (mmi_mtv_sms_get_send_msg_case() == MTV_SMS_SEND_CASE_REPLY)
    {
        mtv_sms_send_handle->reply_msg_id = g_mtv_sms_cntx.curr_msg_id;
    }
    else
    {
        mtv_sms_send_handle->reply_msg_id = SRV_SMS_INVALID_MSG_ID;
    }
    mtv_sms_send_handle->send_msg_case = mmi_mtv_sms_get_send_msg_case();
    mtv_sms_send_handle->is_recipient_modified = mtv_recipient_data.is_modify;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_start_send_msg_flow
 * DESCRIPTION
 *  Entry Write or Send Message screen
 * PARAMETERS
 *  send_case       [IN]    Send Msg Case
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_start_send_msg_flow(mmi_mtv_sms_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_SMS_ENTRY_WRITE_MSG_1, send_case);*/

    /* mmi_mtv_sms_set_send_msg_case(send_case); */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_ENTRY_WRITE, send_case);

    if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_ID_MTV_SMS_NOT_AVAIABLE),
            MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    else
    {
        U16 msg_index = SRV_SMS_INVALID_MSG_ID;
        MMI_BOOL is_add_num = MMI_FALSE;
        MMI_BOOL is_entry_editor = MMI_TRUE;
        MMI_BOOL is_entry_recipient = MMI_TRUE;
        MMI_BOOL is_reset_edit_data = MMI_TRUE;
        MMI_BOOL is_reset_recipient_data = MMI_TRUE;


        switch (send_case)
        {
            case MTV_SMS_SEND_CASE_EDIT_DRAFT:
            case MTV_SMS_SEND_CASE_EDIT_UNSENT:
            case MTV_SMS_SEND_CASE_RESEND:
            case MTV_SMS_SEND_CASE_SEND_DRAFT:
            case MTV_SMS_SEND_CASE_FORWARD:
            {
                U8 result;
                MtvGetEMSDataForView(NULL, 0);
                MtvGetEMSDataForEdit(NULL, 1);
                result = MTVCopyEMSViewToEditBuffer();
                MTVReleaseEMSViewBuffer();
                is_reset_edit_data = MMI_FALSE;


               /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
                if (result != EMS_OK)
                {
                    if (result == EMS_NULL_POINTER)
                    {
                        mmi_mtv_sms_display_popup(
                            (STR_ID_MTV_SMS_DATA_EXCEEDED),
                            MMI_MTV_SMS_NOTIFY_FAILURE);
                    }
                    else
                    {
                        mmi_mtv_sms_display_popup(
                            (STR_ID_MTV_SMS_DATA_EXCEEDED),
                            MMI_MTV_SMS_NOTIFY_FAILURE);
                   }
                    return;
                }
                else
                {
                    switch (send_case)
                    {
                        case MTV_SMS_SEND_CASE_EDIT_DRAFT:
                        case MTV_SMS_SEND_CASE_EDIT_UNSENT:
                        {
                            EMSData *pEMS;
                            MtvGetEMSDataForEdit(&pEMS, 0);
                            mmi_mtv_sms_remove_edit_all_ems_objects(&pEMS);
                            msg_index = g_mtv_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                            break;
                        }
                        case MTV_SMS_SEND_CASE_FORWARD:
                        {    
                            EMSData *pEMS;
                            MtvGetEMSDataForEdit(&pEMS, 0);
                            mmi_mtv_sms_remove_edit_all_ems_objects(&pEMS);
                            break;
                        }

                        case MTV_SMS_SEND_CASE_RESEND:
                            msg_index = g_mtv_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                            is_entry_editor = MMI_FALSE;
                            break;

                        case MTV_SMS_SEND_CASE_SEND_DRAFT:
                            msg_index = g_mtv_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                            is_entry_editor = MMI_FALSE;
                            break;
                            
                        default:
                            MMI_ASSERT(0);
                            break;
                    }
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                #endif
                }
                break;
            }

            case MTV_SMS_SEND_CASE_REPLY:
            case MTV_SMS_SEND_CASE_ARCHIVE_REPLY:
            {
                msg_index = g_mtv_sms_cntx.curr_msg_id;
                is_add_num = MMI_TRUE;
                break;
            }

            case MTV_SMS_SEND_CASE_WRITE_NEW_MSG:
            {
                break;
            }

            default:
            {
                is_reset_edit_data = MMI_FALSE;
                is_reset_recipient_data = MMI_FALSE;
                break;
            }
        }

        send_info_data.msg_id = msg_index;

        if (is_reset_edit_data == MMI_TRUE)
        {
            MTVReleaseEMSEditBuffer();
        }

        if (is_reset_recipient_data == MMI_TRUE)
        {
            mmi_mtv_sms_reset_recipient_data();
        }

        if ((is_add_num == MMI_TRUE) && (msg_index != SRV_SMS_INVALID_MSG_ID))
        {
            {
                S8 ucs2_addr[(MMI_MTV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

                srv_sms_get_msg_address(msg_index, ucs2_addr);

                if ((ucs2_addr[0] != '\0') || (ucs2_addr[1] != '\0'))
                {

                    mmi_mtv_sms_append_recipient(ucs2_addr);

                    if (send_case == MTV_SMS_SEND_CASE_RESEND)
                    {
                        is_entry_recipient = MMI_FALSE;
                    }
                }
            }
        }

        if (is_entry_editor == MMI_TRUE)
        {
            mmi_mtv_sms_pre_entry_editor();
        }
        else if (is_entry_recipient == MMI_TRUE)
        {
            mmi_mtv_sms_edit_send_entry();
        }
        else
        {
            mmi_mtv_sms_pre_send_msg();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_edit_send_entry
 * DESCRIPTION
 *  Pre-Entry Add Recipient Screen Function
 * PARAMETERS
 *  is_external     [IN] Is from other application (TRUE) or SMS application (FALSE)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_edit_send_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_send_sms();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_send_msg
 * DESCRIPTION
 *  Pre Send message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_mtv_sms_pre_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_send_sms();
}

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_is_sent
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_mtv_sms_get_is_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return send_info_data.is_sent;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_is_sent_false
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_mtv_sms_set_is_sent_false(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info_data.is_sent = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_is_sent_true
 * DESCRIPTION
 *  set whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_mtv_sms_set_is_sent_true(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info_data.is_sent = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_append_recipient
 * DESCRIPTION
 *  Append Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_append_recipient(S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if (mmi_ucs2strlen(ucs2_addr) > 0)
    {
        U16 *dst_addr = (U16 *)mtv_recipient_data.recipient;
        U16 addr_len;
        addr_len = mmi_ucs2strlen((CHAR*)ucs2_addr);
        MMI_ASSERT(addr_len <= MMI_MTV_SMS_MAX_ADDR_LEN);
        memcpy(dst_addr, ucs2_addr, MMI_MTV_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
        dst_addr[addr_len] = 0;
        mtv_recipient_data.total_num++;
    }
    mtv_recipient_data.is_modify = MMI_FALSE;
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_reset_recipient_data
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_reset_recipient_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mtv_recipient_data, 0, sizeof(mmi_mtv_sms_add_recipient_struct));
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_is_recipient_modify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_set_is_recipient_modify(MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_recipient_data.is_modify = set;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_send_sms(void)
{
    if(mtv_recipient_data.total_num > 1)
    {
        mmi_mtv_sms_display_popup(STR_GLOBAL_ERROR, MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    else 
    {
        if((send_info_data.send_case == MTV_SMS_SEND_CASE_RESEND)&& mtv_recipient_data.total_num == 1)
        {
            mmi_mtv_sms_pre_entry_sending();
        }
        else
        {
            mmi_mtv_sms_pre_entry_input_recipient();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_input_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_input_recipient(void)
{      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mtv_recipient_buffer)
    {
        mtv_recipient_buffer = (CHAR*)OslMalloc((MTV_MTV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
    }
    memset(mtv_recipient_buffer, 0, ((MTV_MTV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH));
    memcpy((WCHAR*)mtv_recipient_buffer, (CHAR*)(mtv_recipient_data.recipient), ((MTV_MTV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH));
    mmi_mtv_sms_entry_input_recipient();
};



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_input_recipient
 * DESCRIPTION
 *  entry recipient edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_entry_input_recipient(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTV_SMS_RECIPIENT_EDITOR, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry_input_recipient, NULL);
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);

    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_RECIPIENT_EDITOR;
#ifdef __MMI_WGUI_CSK_ENABLE__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif /*__MMI_WGUI_CSK_ENABLE__*/

    if (!mmi_ucs2strlen(mtv_recipient_buffer))
    {   
        wgui_cat9007_show(
            get_string(STR_ID_MTV_SMS_SEND_INPUT_RECIPIENT_TITLE),
            get_string(STR_SCR_PBOOK_VIEW_CAPTION), 
            0, 
            get_string(STR_GLOBAL_BACK), 
            0, 
            IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING, 
            (U8 *)mtv_recipient_buffer, 
            MTV_MTV_SMS_MAX_ADDR_LEN , 
            NULL,
            mmi_mtv_sms_recipient_content_changed_call_back,
            0,
            NULL);
        ChangeLeftSoftkey(STR_SCR_PBOOK_VIEW_CAPTION, 0);
#ifdef __MMI_WGUI_CSK_ENABLE__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    }
    else
    {
        wgui_cat9007_show(
            get_string(STR_ID_MTV_SMS_SEND_INPUT_RECIPIENT_TITLE),
            get_string(STR_GLOBAL_SEND), 
            0, 
            get_string(STR_GLOBAL_BACK), 
            0, 
            IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING, 
            (U8 *)mtv_recipient_buffer, 
            MTV_MTV_SMS_MAX_ADDR_LEN , 
            NULL,
            mmi_mtv_sms_recipient_content_changed_call_back,
            0,
            NULL);
        ChangeLeftSoftkey(STR_GLOBAL_SEND, 0);
#ifdef __MMI_WGUI_CSK_ENABLE__
        ChangeCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
#endif
    }

#ifdef __MMI_WGUI_CSK_ENABLE__
    SetCenterSoftkeyFunction(mmi_mtv_sms_recipient_input_lsk_handler, KEY_EVENT_UP);
#endif /*__MMI_WGUI_CSK_ENABLE__*/
    SetLeftSoftkeyFunction(mmi_mtv_sms_recipient_input_lsk_handler, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_MTV_SMS_RECIPIENT_EDITOR, mmi_mtv_sms_recipient_editor_del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_recipient_content_changed_call_back
 * DESCRIPTION
 *  change lsk string
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_recipient_content_changed_call_back(void)
{
    MMI_ASSERT(mtv_recipient_buffer);
    if (!mmi_ucs2strlen(mtv_recipient_buffer))
    {   
        set_left_softkey_label((UI_string_type) get_string(STR_SCR_PBOOK_VIEW_CAPTION));
        set_left_softkey_icon(NULL);
#ifdef __MMI_WGUI_CSK_ENABLE__
        set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
        set_softkey_icon((PU8)get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
#endif
    }
    else
    {
        set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_SEND));
        set_left_softkey_icon(NULL);
#ifdef __MMI_WGUI_CSK_ENABLE__
        set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
        set_softkey_icon((PU8)get_image(IMG_GLOBAL_SEND_MSG_CSK), MMI_CENTER_SOFTKEY);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_recipient_input_lsk_handler
 * DESCRIPTION
 *  handle lsk in recipient editor
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_recipient_input_lsk_handler(void)
{
    MMI_ASSERT(mtv_recipient_buffer);
    if (mmi_ucs2strlen((const CHAR *)mtv_recipient_buffer))
    {
        if (srv_sms_check_ucs2_number((S8 *)mtv_recipient_buffer))
        {
            mmi_mtv_sms_get_recipient_from_editor(mtv_recipient_buffer);
            mmi_mtv_sms_pre_entry_sending();
        }
        else
        {
            mmi_mtv_sms_display_popup((STR_GLOBAL_INVALID_NUMBER), MMI_MTV_SMS_NOTIFY_FAILURE);
        }
    }
    else
    {
        if (mmi_matv_sms_entry_phb_list_group((MMI_MTV_SMS_PHB_SEND_SMS_REQ)))
        {
            mmi_matv_sms_register_phb_list_callback(mmi_mtv_sms_get_recipient_from_phb);
        }
    }
}



void mmi_mtv_sms_get_recipient_from_phb(U16 index)
{
    U16 temp_buff[MMI_PHB_NUMBER_LENGTH + 1];
    srv_phb_get_number(index, temp_buff , MMI_PHB_NUMBER_LENGTH);
    if (srv_sms_check_ucs2_number((S8 *)temp_buff))
    {
        mmi_ucs2ncpy((CHAR *)mtv_recipient_buffer, (const CHAR *)temp_buff, MTV_MTV_SMS_MAX_ADDR_LEN);
    }
    else
    {
        mmi_mtv_sms_display_popup((STR_GLOBAL_INVALID_NUMBER), MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    mmi_matv_sms_phb_list_close();
}


void mmi_mtv_sms_get_recipient_from_editor(S8 *temp_addr)
{
    U16 addr_len;
    
    addr_len = mmi_ucs2strlen((CHAR *)temp_addr);
    MMI_ASSERT(addr_len <= MMI_MTV_SMS_MAX_ADDR_LEN);
    if (mmi_ucs2cmp((const char *)temp_addr, (const char *)(mtv_recipient_data.recipient)) != 0)
    {
        temp_addr[addr_len * ENCODING_LENGTH] = 0;
        temp_addr[addr_len * ENCODING_LENGTH + 1] = 0;
        mmi_ucs2ncpy((CHAR*)mtv_recipient_data.recipient,(CHAR*)temp_addr, MMI_MTV_SMS_MAX_ADDR_LEN + 1);
        mtv_recipient_data.is_modify = MMI_TRUE;
        mtv_recipient_data.total_num = 1;
    }
};


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_recipient_editor_del_cb
 * DESCRIPTION
 *  call to delete buffer of edit
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 mmi_mtv_sms_recipient_editor_del_cb(void * dummy)
{
    if (!mtv_recipient_buffer)
    {
         OslMfree(mtv_recipient_buffer);
         mtv_recipient_buffer = NULL;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_sending
 * DESCRIPTION
 *  preprocess of sending
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_valid() == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_GLOBAL_NOT_AVAILABLE),
            MMI_MTV_SMS_NOTIFY_FAILURE);
        return;
    }
    else if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_ID_MTV_SMS_NOT_AVAIABLE),
            MMI_MTV_SMS_NOTIFY_FAILURE);
        return;
    }
    else
    {
        if (mmi_mtv_sms_init_send_handle_data())
        {
            S32 invalid_recipient = 0;
            if (mtv_recipient_data.total_num > 0)
            {
                U16 addr_len;
           
                if (mtv_recipient_data.total_num > MMI_MTV_SMS_MAX_RECIPIENTS_NUM)
                {
                    mtv_recipient_data.total_num = MMI_MTV_SMS_MAX_RECIPIENTS_NUM;
                }
                if (srv_sms_check_ucs2_number((S8 *)mtv_recipient_data.recipient))
                {
                    addr_len = mmi_ucs2strlen((const CHAR*)mtv_recipient_data.recipient);
                    MMI_ASSERT(addr_len <= MTV_MTV_SMS_MAX_ADDR_LEN);
                    mmi_mtv_sms_fill_handle_one_recipient_data((U8*)mtv_recipient_data.recipient);
                }
                else
                {
                    ++invalid_recipient;
                }
                if (invalid_recipient)
                {
                    mmi_mtv_sms_display_popup((STR_GLOBAL_INVALID_NUMBER), MMI_MTV_SMS_NOTIFY_FAILURE);
                }
                else
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    send_info_data.sim_id = SRV_SMS_SIM_1;
                    mmi_mtv_sms_send_single_sms();
                #endif
                }
            }
        }
        else
        {
            mmi_mtv_sms_display_popup((STR_ID_MTV_SMS_NOT_AVAIABLE), MMI_MTV_SMS_NOTIFY_FAILURE);
        }
        MMI_MTV_SMS_SEND_INFO_TRACE1;
        MMI_MTV_SMS_SEND_INFO_TRACE2;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_fill_handle_one_recipient_data
 * DESCRIPTION
 *  Add a recipient into handle data
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_fill_handle_one_recipient_data(U8* ucs2_addr)
{
    mmi_ucs2ncpy((CHAR *)mtv_sms_send_handle->recipient, (const CHAR *)ucs2_addr, MTV_MTV_SMS_MAX_ADDR_LEN);
};


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WGUI_CSK_ENABLE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WGUI_CSK_ENABLE__
/* under construction !*/
#endif /*__MMI_WGUI_CSK_ENABLE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WGUI_CSK_ENABLE__
/* under construction !*/
#endif /*__MMI_WGUI_CSK_ENABLE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  mmi_mtv_sms_send_single_sms
 * DESCRIPTION
 *  send one sms
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_mtv_sms_send_single_sms(void)
{
    mtv_recipient_data.total_num = 1;
    send_info_data.is_sending = MMI_TRUE;
    send_info_data.is_aborting = MMI_FALSE;
    mtv_sms_send_handle->sim_id = send_info_data.sim_id;
    mmi_mtv_sms_entry_sending();
    mmi_mtv_sms_set_save_and_delete_para();
    mmi_mtv_sms_send_msg_req(mtv_sms_send_handle, mmi_mtv_sms_send_processing_handler);
    
    MMI_MTV_SMS_SEND_INFO_TRACE1;
    MMI_MTV_SMS_SEND_INFO_TRACE2;
    MMI_MTV_SMS_SEND_SAVE_CNTX;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_sending
 * DESCRIPTION
 *  Entry sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_pre_entry_processing_screen(
        SCR_ID_MTV_SMS_POPUP_SENDING, 
        0, 
        0,
        NULL, 
        STR_GLOBAL_CANCEL, 
        mmi_mtv_sms_abort_send_msg, 
        STR_ID_MTV_SMS_SENDING);
    SetRightSoftkeyFunction(mmi_mtv_sms_abort_send_msg, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(
        SCR_ID_MTV_SMS_POPUP_SENDING,
        (HistoryDelCBPtr)mmi_mtv_sms_sending_scrn_del_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_sending_scrn_del_callback
 * DESCRIPTION
 *  delte sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_mtv_sms_sending_scrn_del_callback(void* dummy)
{
    if (mtv_sms_send_handle && mtv_sms_send_handle->srv_send_handle)
    {
        srv_sms_clear_send_callback(mtv_sms_send_handle->srv_send_handle);
        srv_sms_abort_send(mtv_sms_send_handle->srv_send_handle);
    }
    mmi_mtv_sms_deinit_send_handle_data();
    MMI_MTV_SMS_SEND_INFO_TRACE1;
    MMI_MTV_SMS_SEND_INFO_TRACE2;
    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_save_and_delete_para
 * DESCRIPTION
 *  set send result save and delete handle parameters
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_set_save_and_delete_para(void)
{
    mmi_mtv_sms_send_case_enum send_msg_case = mtv_sms_send_handle->send_msg_case;

        save_del_para_data.save_send_fail_flag = MMI_TRUE;
    
        /* Only save the first SMS if all of the SMS is sent. */
        if ((srv_sms_is_save_sent_sms_setting(mtv_sms_send_handle->sim_id) == MMI_TRUE))
        {
            save_del_para_data.save_sent_flag = MMI_TRUE;
        }
        else
        {
            save_del_para_data.save_sent_flag = MMI_FALSE;
        }

    if (((send_msg_case == MTV_SMS_SEND_CASE_EDIT_UNSENT) ||
         (send_msg_case == MTV_SMS_SEND_CASE_RESEND) ||
         (send_msg_case == MTV_SMS_SEND_CASE_EDIT_DRAFT) ||
         (send_msg_case == MTV_SMS_SEND_CASE_SEND_DRAFT)))
    {
        save_del_para_data.del_send_fail_flag = MMI_TRUE;
        save_del_para_data.del_send_succ_flag = MMI_TRUE;
    }
    else
    {
        save_del_para_data.del_send_fail_flag = MMI_FALSE;
        save_del_para_data.del_send_succ_flag = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_processing_handler
 * DESCRIPTION
 *  send one sms processing handler, no UI respond
 * PARAMETERS
 *  dummy
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_mtv_sms_send_processing_handler(srv_sms_callback_struct *callback_data)
{
    if (mtv_sms_send_handle)
    {
        MMI_BOOL result = callback_data->result;
        srv_sms_cause_enum cause = callback_data->cause;
        mtv_sms_result_enum send_result = MTV_SMS_SEND_RESULT_OK;
        SmsSendResultCBFuncPtr send_result_func = mmi_mtv_sms_send_msg_result_handle;

        
        MMI_MTV_SMS_SEND_SAVE_CNTX;
        MMI_MTV_SMS_SEND_HANDLE1;
        MMI_MTV_SMS_SEND_HANDLE2;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_PROCESSING_PROC,  result, mtv_sms_send_handle->srv_send_handle, mtv_sms_send_handle);

        save_del_para_data.send_result = result;
        mtv_sms_send_handle->srv_send_handle = NULL;
        if (result == MMI_TRUE)
        {
            if (save_del_para_data.del_send_succ_flag == MMI_TRUE)
            {
                srv_sms_delete_msg(send_info_data.msg_id, mmi_mtv_sms_send_delete_handle, (void*)mtv_sms_send_handle);
            }
            else
            {
                if(save_del_para_data.save_sent_flag)
                {
                    mmi_mtv_sms_save_msg_req(mtv_sms_send_handle, SRV_SMS_STATUS_SENT, mmi_mtv_sms_send_save_handle);
                }
                else
                {
                    if (send_result_func != NULL)
                    {
                        send_result_func(send_result, (void*)callback_data->user_data);
                    }
                }
            }
        }
        
        else
        {
            switch (cause)
            {
                case SRV_SMS_CAUSE_DATA_EXCEED:
                {
                    send_result = MTV_SMS_SEND_RESULT_DATA_EXCEED;
                    if (send_result_func != NULL)
                    {
                        send_result_func(send_result, (void*)callback_data->user_data);
                    }
                    break;
                }

                case SRV_SMS_CAUSE_NOT_READY:
                case SRV_SMS_CAUSE_SEND_BUSY:
                {
                    send_result = MTV_SMS_SEND_RESULT_NOT_READY;
                    if (send_result_func != NULL)
                    {
                        send_result_func(send_result, (void*)callback_data->user_data);
                    }
                    break;
                }

                case SRV_SMS_CAUSE_SEND_ABORT:
                {
                    send_result = MTV_SMS_SEND_RESULT_CANCEL;
                    if (send_result_func != NULL)
                    {
                        send_result_func(send_result, (void*)callback_data);
                    }
                    break;
                }
                default:
                {
                    /* 1> Delete first, then save
                     * 2> If need to delete the send failed message, 
                     *    it also need to save it to oubox
                     */
                    if (save_del_para_data.del_send_fail_flag == MMI_TRUE)
                    {
                        srv_sms_delete_msg(send_info_data.msg_id, mmi_mtv_sms_send_delete_handle, (void*)mtv_sms_send_handle);
                    }
                    else
                    {
                        /* whether need save the send failed message to outbox */
                        if (save_del_para_data.save_send_fail_flag == MMI_TRUE)
                        {
                            mmi_mtv_sms_save_msg_req(mtv_sms_send_handle, SRV_SMS_STATUS_UNSENT, mmi_mtv_sms_send_save_handle);
                        }
                        else
                        {
                            send_result = MTV_SMS_SEND_RESULT_ERROR;
                            send_result_func(send_result, (void*)mtv_sms_send_handle);
                        }
                    }
                }
           }
        }
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_PROCESSING_PROC,  0, 1, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_msg_req
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_send_msg_req(mtv_sms_send_handle_struct *send_handle, SrvSmsCallbackFunc callback_func)
{
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        SMS_HANDLE srv_send_handle;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        srv_send_handle = srv_sms_get_send_handle();
        if (srv_send_handle)
        {
            srv_sms_set_address(srv_send_handle, (S8*)send_handle->recipient);
            srv_sms_set_content_ems(srv_send_handle, (void*)send_handle->content_ems);
            srv_sms_set_sim_id(srv_send_handle, send_handle->sim_id);
            if (send_handle->reply_msg_id != SRV_SMS_INVALID_MSG_ID)
            {
                srv_sms_set_reply_msg_id(srv_send_handle, send_handle->reply_msg_id);
            }
            send_handle->srv_send_handle = srv_send_handle;
            srv_sms_send_msg(srv_send_handle, callback_func, (void*)send_handle);
        }
        else
        {
            srv_sms_callback_struct fail_cal_back_cntx;
            fail_cal_back_cntx.result = MMI_FALSE;
            fail_cal_back_cntx.cause = SRV_SMS_CAUSE_SEND_BUSY;
            
            callback_func(&fail_cal_back_cntx);
        }
        MMI_MTV_SMS_SEND_HANDLE1;
        MMI_MTV_SMS_SEND_HANDLE2;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_msg_result_handle
 * DESCRIPTION
 *  Send message handle function, UI respond and sending flow result
 * PARAMETERS
 *  result          [IN]    The Save Result
 *  data            [IN]    Dummy
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_send_msg_result_handle(mtv_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_finished = MMI_TRUE;
    srv_sms_callback_struct *callback_data = (srv_sms_callback_struct*) data;
    mtv_sms_send_handle_struct *handle = (mtv_sms_send_handle_struct*) callback_data->user_data;
    MtvSmsSendCBFuncPtr caller_call_back = send_info_data.caller_call_back;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info_data.send_result = result;
    MMI_MTV_SMS_SEND_HANDLE1;
    MMI_MTV_SMS_SEND_HANDLE2;
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SEND_RESAULT_PROC, result, mtv_sms_send_handle->srv_send_handle, mtv_sms_send_handle);
    ClearDelScrnIDCallbackHandler(
        SCR_ID_MTV_SMS_POPUP_SENDING,
        (HistoryDelCBPtr)mmi_mtv_sms_sending_scrn_del_callback);

    switch (result)
    {
        case MTV_SMS_SEND_RESULT_OK:
        case MTV_SMS_SEND_RESULT_ERROR:
        case MTV_SMS_SEND_RESULT_SENT_AND_SAVED:
        case MTV_SMS_SEND_RESULT_SENT_BUT_SAVE_FAIL:
        case MTV_SMS_SEND_RESULT_SEND_FAIL_BUT_SAVED:
        case MTV_SMS_SEND_RESULT_SEND_FAIL_AND_SAVE_FAIL:
        {
            if ((GetActiveScreenId()==SCR_ID_MTV_SMS_POPUP_SENDING || IsScreenPresent(SCR_ID_MTV_SMS_POPUP_SENDING)) ||
                (GetActiveScreenId()==SCR_ID_MTV_SMS_POPUP_CANCELING || IsScreenPresent(SCR_ID_MTV_SMS_POPUP_CANCELING)))
            {
                U16 body_str_id;
                mmi_mtv_event_notify_enum event_id;
                mmi_mtv_sms_get_send_finish_popup_info(handle, &body_str_id, &event_id);
                mmi_mtv_sms_display_popup(
                    (body_str_id),
                    event_id);
              
                if (is_finished == MMI_TRUE)
                {
                    send_info_data.is_sending = MMI_FALSE;
                    mmi_mtv_sms_set_is_sent_true();
                }
               caller_call_back(result);
            }
            
            mmi_mtv_sms_send_close_all_sending();
            mmi_mtv_sms_deinit_send_handle_data();
            return;
        }
       case MTV_SMS_SEND_RESULT_CANCEL:
       {
           if (GetActiveScreenId()==SCR_ID_MTV_SMS_POPUP_CANCELING ||
               IsScreenPresent(SCR_ID_MTV_SMS_POPUP_CANCELING))
           {
               mmi_mtv_sms_display_popup(
                   (STR_ID_MTV_SMS_SENT_CANCELED),
                   MMI_MTV_SMS_NOTIFY_OK);
           }

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif
           mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_SENDING);
           mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_CANCELING);
           return;
       }

        case MTV_SMS_SEND_RESULT_NOT_READY:
        {
            mmi_mtv_sms_display_popup(
                (STR_ID_MTV_SMS_NOT_AVAIABLE),
                MMI_MTV_SMS_NOTIFY_FAILURE);
            break;
        }

        case MTV_SMS_SEND_RESULT_DATA_EXCEED:
        {
            mmi_mtv_sms_display_popup(
                (STR_ID_MTV_SMS_DATA_EXCEEDED),
                MMI_MTV_SMS_NOTIFY_FAILURE);
            break;
        }

        case MTV_SMS_SEND_RESULT_MEM_FULL:
        {
            mmi_mtv_sms_display_popup(
                (STR_GLOBAL_MEMORY_FULL),
                MMI_MTV_SMS_NOTIFY_FAILURE);
            break;
        }


        default:
        {
            mmi_mtv_sms_display_popup(
                (STR_GLOBAL_FAILED_TO_SEND),
                MMI_MTV_SMS_NOTIFY_FAILURE);
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_SENDING);
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_CANCELING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_delete_handle
 * DESCRIPTION
 *  handle send processing delete result
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_send_delete_handle(srv_sms_callback_struct *callback_data)
{
    if (mtv_sms_send_handle)
    {
        mtv_sms_result_enum send_result = MTV_SMS_SEND_RESULT_OK;
        SmsSendResultCBFuncPtr send_result_func = mmi_mtv_sms_send_msg_result_handle;
        if (save_del_para_data.send_result)
        {
            if (save_del_para_data.save_sent_flag)
            {
                mmi_mtv_sms_save_msg_req(mtv_sms_send_handle, SRV_SMS_STATUS_SENT, mmi_mtv_sms_send_save_handle);
            }
            else
            {
                send_result = MTV_SMS_SEND_RESULT_OK;
                if (send_result_func != NULL)
                {
                     send_result_func(send_result, (void*)callback_data);
                }
            }
        }
        else
        {
            mmi_mtv_sms_save_msg_req(mtv_sms_send_handle, SRV_SMS_STATUS_UNSENT, mmi_mtv_sms_send_save_handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_save_msg_req
 * DESCRIPTION
 *  save Msg Request
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_save_msg_req(mtv_sms_send_handle_struct *send_handle, srv_sms_status_enum set_status, SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE srv_save_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_save_handle = srv_sms_get_save_handle();
    {
        srv_sms_set_address(srv_save_handle, (S8*)send_handle->recipient);
    }

    srv_sms_set_status(srv_save_handle, set_status);
    srv_sms_set_content_ems(srv_save_handle, (void*)send_handle->content_ems);
    srv_sms_set_sim_id(srv_save_handle, send_handle->sim_id);
    srv_sms_save_msg(srv_save_handle, callback_func, (void*)send_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_save_handle
 * DESCRIPTION
 *  Save Msg handler
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_send_save_handle(srv_sms_callback_struct *callback_data)
{
    if (mtv_sms_send_handle)
    {
        MMI_BOOL save_result = callback_data->result;
        mtv_sms_result_enum send_result = MTV_SMS_SEND_RESULT_OK;
        SmsSendResultCBFuncPtr send_result_func = mmi_mtv_sms_send_msg_result_handle;
        
        if (!save_del_para_data.send_result) /* send */
        {
            if (save_result == MMI_TRUE)
            {
                send_result = MTV_SMS_SEND_RESULT_SEND_FAIL_BUT_SAVED;
            }
            else
            {
                send_result = MTV_SMS_SEND_RESULT_SEND_FAIL_AND_SAVE_FAIL;
            }
            if (send_result_func != NULL)
            {
                send_result_func(send_result, (void*)callback_data);
            }
        }
        else /* send failed */
        {
            if (save_result == MMI_TRUE)
            {
                send_result = MTV_SMS_SEND_RESULT_SENT_AND_SAVED;
            }
            else
            {
                send_result = MTV_SMS_SEND_RESULT_SENT_BUT_SAVE_FAIL;
            }
            if (send_result_func != NULL)
            {
                send_result_func(send_result, (void*)callback_data);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_send_close_all_sending
 * DESCRIPTION
 *  cosle sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_send_close_all_sending(void)
{
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_RECIPIENT_EDITOR);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_SENDING);
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_CANCELING);
        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_deinit_send_handle_data
 * DESCRIPTION
 *  deinit send handle data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_deinit_send_handle_data(void)
{
    if (!mtv_sms_send_handle)
    {
        OslMfree(mtv_sms_send_handle);
        mtv_sms_send_handle = NULL;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_abort_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_mtv_sms_abort_send_msg(void)
{
    send_info_data.is_aborting = MMI_TRUE;
    if (send_info_data.is_sending == MMI_TRUE)
    {
        mmi_mtv_sms_entry_abort_sending();
    }
    if (mtv_sms_send_handle && mtv_sms_send_handle->srv_send_handle)
    {
        srv_sms_abort_send(mtv_sms_send_handle->srv_send_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_abort_sending
 * DESCRIPTION
 *  Entry abort sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_abort_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_pre_entry_processing_screen(
        SCR_ID_MTV_SMS_POPUP_CANCELING, 
        0, 
        0,
        NULL, 
        0, 
        NULL, 
        STR_GLOBAL_CANCELLING);
    MMI_MTV_SMS_SEND_INFO_TRACE1;
    MMI_MTV_SMS_SEND_INFO_TRACE2;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_send_finish_popup_info
 * DESCRIPTION
 *  Get the popup information for sending fininsh notification  
 * PARAMETERS
 *  body_str_id     [IN] Body string ID Pointer
 *  image_id        [IN] Image ID Pointer
 *  tone_id         [IN] Tone ID Pointer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_get_send_finish_popup_info(mtv_sms_send_handle_struct *handle, U16 *body_str_id, mmi_mtv_event_notify_enum *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_sms_result_enum send_result = send_info_data.send_result;

    switch (send_result)
    {
        case MTV_SMS_SEND_RESULT_OK:
        case MTV_SMS_SEND_RESULT_SENT_AND_SAVED:
            *body_str_id = STR_GLOBAL_SENT;
            *event_id = MMI_MTV_SMS_MESSAGE_SENT;
            break;

        case MTV_SMS_SEND_RESULT_SENT_BUT_SAVE_FAIL:
            *body_str_id = STR_ID_MTV_SMS_SENT_FAILED_NOT_SAVED;
            *event_id = MMI_MTV_SMS_MESSAGE_SENT;
            break;

        case MTV_SMS_SEND_RESULT_SEND_FAIL_BUT_SAVED:
            *body_str_id = STR_ID_MTV_SMS_SENT_FAILED_SAVED;
            *event_id = MMI_MTV_SMS_NOTIFY_FAILURE;
            break;

        case MTV_SMS_SEND_RESULT_SEND_FAIL_AND_SAVE_FAIL:
            *body_str_id = STR_ID_MTV_SMS_SENT_FAILED_NOT_SAVED;
            *event_id = MMI_MTV_SMS_NOTIFY_FAILURE;
            break;

        case MTV_SMS_SEND_RESULT_ERROR:
            *body_str_id = STR_ID_MTV_SMS_SENT_FAILED;
            *event_id = MMI_MTV_SMS_NOTIFY_FAILURE;
            break;
        
        default:
            MMI_ASSERT(0);
            break;

    }  
    return MMI_TRUE;
}


#endif  /* __MMI_ATV_SMS_SUPPORT__ */

