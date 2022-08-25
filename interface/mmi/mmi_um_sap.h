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
 * mmiapi_um_sap.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __BUILD_DOM__
/**************************************************************************************
  * Description
  * <pre>
  *   When message application is ready after boot up , message application should send
  *   this primitive to inform UM of its ready state.
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_ready_ind_struct
  **************************************************************************************/
#define MSG_ID_MMI_UM_READY_IND

/**************************************************************************************
  * Description
  * <pre>
  *   UM queries message number of each message box in message application. The
  *   msg_type in primitive is used to specify which type of message UM requests to get
  *   number information. The app_id in primitive is used to specify which application
  *   use this primitive and UM would always be 0. The sim_id is used to specify which
  *   SIM information UM wants to get. Currently, sim_id would always
  *   SRV_UM_SIM_GSM_SIM1 | SRV_UM_SIM_GSM_SIM2.
  * </pre>
  * Note
  *   UM -> APP
  * See Also
  *   Local Parameter: srv_um_get_msg_num_req_struct
  *   Response Message: MSG_ID_MMI_UM_GET_MSG_NUM_RSP
  **************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_NUM_REQ

/**************************************************************************************
  * Description
  * <pre>
  *   Message application responses the message number of each message box to UM. After
  *   receiving MSG_ID_MMI_UM_GET_MSG_NUM_REQ from UM, message application should use
  *   this primitive to provide number of each message box to UM.
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_get_msg_num_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_GET_MSG_NUM_REQ
  **************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_NUM_RSP

/***************************************************************************************
  * Description
  * <pre>
  *     UM queries message list information in message application. Message application
  *     must prepare a message index list sorted in descending order of time for each
  *     message box. UM uses this primitive to get this list information from message
  *     applications. The start_entry in local parameter specifies the list index of
  *     starting entry from which UM requests to get list information. The list index
  *     starts from 0. The following picture is the example of start_entry.
  *
  *     Ex. The entry specified by start_entry = 2 is filled by gray color
  *
  *     <img name="MSG_ID_MMI_UM_GET_LIST_REQ_1" />
  *
  *     In normal cases, UM would use this primitive to get all index information of the
  *     list. Therefore, the start_entry in the first primitive would be zero. If the
  *     list information is too much to be contained in one response primitive, UM would
  *     use this primitive with different value of start_entry repeatedly to get list
  *     information until all the information is obtained. The app_id in primitive is
  *     used to specify which application use this primitive and UM would always be 0.
  *     The sim_id is used to specify which SIM information UM wants to get. Currently,
  *     sim_id would always SRV_UM_SIM_GSM_SIM1 | SRV_UM_SIM_GSM_SIM2.
  * </pre>
  * Note
  *     APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_get_msg_list_req_struct
  *   Response Message: MSG_ID_MMI_UM_GET_MSG_LIST_RSP
  ***************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_LIST_REQ

/**************************************************************************************
  * Description
  * <pre>
  *   Message applications response list information to UM. After receiving
  *   MSG_ID_MMI_UM_GET_MSG_LIST_REQ, message applications should use this primitive to
  *   response list information. Message application must prepare a message index list
  *   sorted in descending order of time for each message box. Message applications
  *   should refer to msg_type and msg_box_type in MSG_ID_MMI_UM_GET_MSG_LIST_REQ to
  *   provide correspondent list information and also fill in msg_type and msg_box_type
  *   in this primitive to indicate UM the type of the list information in this
  *   primitive. Msg_type and msg_box_type in this primitive should be the same as
  *   msg_type and msg_box_type in MSG_ID_MMI_UM_GET_MSG_LIST_REQ.
  *
  *   Message applications should refer to start_entry in
  *   MSG_ID_MMI_UM_GET_MSG_LIST_REQ to determine from whch list entry message
  *   applications should provide list information. For example, if the value of
  *   start_entry in MSG_ID_MMI_UM_GET_MSG_LIST_REQ is zero, then list information
  *   should be provided from the 1st list entry. That is, the total list information
  *   would be provided. Message applications should also fill in start_entry in this
  *   primitive to indicate UM the list index of first entry in this primitive.
  *   Start_entry in this primitive should be the same as start_entry in
  *   MSG_ID_MMI_UM_GET_MSG_LIST_REQ..
  *
  *   Ex. The entry specified by start_entry = 0 is filled by gray color and list
  *   information after (and including) this entry should be provided.
  *
  *   <img name="MSG_ID_MMI_UM_GET_MSG_LIST_RSP" />
  *
  *   List information includes message index and message timestamp. Message index with
  *   message type and message box type should be able to uniquely identify a message.
  *   Message timestamp should be given in seconds since 1.Jan. 1970 GMT. If there is
  *   no timestamp information for the message, the timestamp field should be set to
  *   zero.
  *
  *   The list information should be provided in list_info[ ] of this primitive .The
  *   maximum number of list_info[ ] is SRV_UM_MAX_GET_MSG_LIST_NUMBER and if total
  *   number of list information needed to provide exceeds
  *   SRV_UM_MAX_GET_MSG_LIST_NUMBER, more of this primitive should be KAL_TRUE which
  *   indicate UM to send MSG_ID_MMI_UM_GET_MSG_LIST_REQ again to get remaining list
  *   information. Otherwise, more should be KAL_FALSE to indicate UM that all the list
  *   information is provided. Msg_number is used to specify the number of list_info[ ]
  *   provided by this primitive.
  * </pre>
  *
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_get_msg_list_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_GET_MSG_LIST_REQ
  **************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_LIST_RSP

/**************************************************************************************
  * Description
  * <pre>
  *   UM queries message information from message application. Message application must
  *   prepare an message id list sorted in descending order of time for each message
  *   box. UM uses this primitive to get message information from message applications.
  *
  *   Difference between MSG_ID_MMI_UM_GET_MSG_INFO_REQ, this primitive defines every
  *   message identifier for each message. These message identifiers may not be sorted.
  *
  *   The app_id in primitive is used to specify which application use this primitive
  *   and UM would always be 0. The sim_id is used to specify which SIM information UM
  *   wants to get. Currently, sim_id would always SRV_UM_SIM_GSM_SIM1 |
  *   SRV_UM_SIM_GSM_SIM2.
  * </pre>
  * Note
  *   UM -&gt; APP
  * See Also
  *   Local Parameter: srv_um_get_msg_info_req_struct
  *   Response Message: MSG_ID_MMI_UM_GET_MSG_INFO_RSP
  **************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_INFO_REQ

/**************************************************************************************
  * Description
  * <pre>
  *   Message applications response message information to UM. After receiving
  *   MSG_ID_MMI_UM_GET_MSG_INFO_REQ, message applications should use this primitive to
  *   response message information. Message applications should refer to msg_type and
  *   msg_id in MSG_ID_MMI_UM_GET_MSG_INFO_REQ to provide correspondent message
  *   information and also fill in msg_type and msg_id in this primitive to indicate UM
  *   the type of the message information in this primitive.
  *
  *   Message information includes message index, message timestamp, address type,
  *   address length, address, subject length, subject, and icon id. Message index with
  *   message type and message box type should be able to uniquely identify a message.
  *   Message timestamp should be given in seconds since 1.Jan. 1970 GMT. If there is
  *   no timestamp information for the message, the timestamp field should be set to
  *   zero. Address type is defined in srv_um_addr_enum enum. Address length is the number of
  *   characters (rather than bytes) in address. Address is the sender address for MT
  *   message and receiver address for MO message. If there are more than one addesses
  *   in the message, only the first address should be provided. If the address type is
  *   phone number and the phonebook has this phone number entry, then application
  *   should provide the corresponding name for this phone number in phonebook, rather
  *   than phone number. Subject Length is the number of characters (rather than bytes)
  *   in subject. Subject is the message subject. For message without subject, ex. SMS,
  *   this field should be filled in part of beginning message content. The icon id
  *   specifies which icon should be display in message list for this message .
  *
  *   The message information should be provided in msg_info[ ] of this primitive .The
  *   maximum number of list_info[ ] is SRV_UM_MAX_GET_MSG_INFO_NUMBER. If the array is
  *   not full, please assign the msg_id to be zero to indicate the end of the array.
  * </pre>
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_get_msg_info_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_GET_MSG_INFO_REQ
  **************************************************************************************/
#define MSG_ID_MMI_UM_GET_MSG_INFO_RSP

/**************************************************************************************
  * Description
  * <pre>
  *   UM requests message applications to delete the whole message box. Msg_type in
  *   this primitive specifies type of message to delete. Msg_box_type is a bit mask to
  *   specify which types of message box to delete so that more than one type of
  *   message box could be requested to be deleted in one
  *   MSG_ID_MMI_UM_DELETE_FOLDER_REQ primitive. The app_id in primitive is used to
  *   specify which application use this primitive and UM would always be 0.
  * </pre>
  * Note
  *   UM -&gt; APP
  * See Also
  *   Local Parameter: srv_um_delete_folder_req_struct
  *   Response Message: MSG_ID_MMI_UM_DELETE_FOLDER_RSP
  **************************************************************************************/
#define MSG_ID_MMI_UM_DELETE_FOLDER_REQ

/***********************************************************************************
  * Description
  * <pre>
  *   Message applications response the result of deleting message box to UM. After
  *   receiving MSG_ID_MMI_UM_DELETE_FOLDER_REQ, message applications should try to
  *   delete the message box(es) specified in the MSG_ID_MMI_UM_DELETE_FOLDER_REQ.
  *   After deletion, message applications should use this primitive to inform UM of
  *   the result of deletion.
  * </pre>
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_delete_folder_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_DELETE_FOLDER_REQ
  ***********************************************************************************/
#define MSG_ID_MMI_UM_DELETE_FOLDER_RSP

/**************************************************************************************
  * Description
  * <pre>
  *   When new message arrives , message application should send this primitive to
  *   inform UM of coming of the new message. The sim_id is used to specify which SIM
  *   information UM wants to get. Currently, sim_id would always SRV_UM_SIM_GSM_SIM1 |
  *   SRV_UM_SIM_GSM_SIM2.
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_new_msg_ind_struct
  **************************************************************************************/
#define MSG_ID_MMI_UM_NEW_MSG_IND

/**********************************************************************************
  * Description
  * <pre>
  *   Message applications indicate UM to delete the whole message box. msg_type in
  *   this primitive specifies which type of message issues this primitive.
  *   msg_box_type is a bit mask to specify which types of message box to delete.
  *   Moreover, this primitive only supports to delete one folder at one time.
  * </pre>
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_delete_all_ind_struct
  *   Response Message: MSG_ID_MMI_UM_DELETE_ALL_RES
  **********************************************************************************/
#define MSG_ID_MMI_UM_DELETE_ALL_IND

/*************************************************************************************
  * Description
  * <pre>
  *   After receiving MSG_ID_MMI_UM_DELETE_ALL_IND, UM would enter a processing screen
  *   and then respond message applications by this primitive. Message applications
  *   should delete their own screens from history after getting
  *   MSG_ID_MMI_UM_DELETE_ALL_RES. And after issuing MSG_ID_MMI_UM_DELETE_ALL_RES, UM
  *   would use MSG_ID_MMI_UM_DELETE_FOLDER_REQ to request message applications to
  *   delete message folders.
  * </pre>
  * Note
  *   UM -&gt; APP
  * See Also
  *   Local Parameter: srv_um_delete_all_res_struct
  *   Response Message: MSG_ID_MMI_UM_DELETE_ALL_IND
  *************************************************************************************/
#define MSG_ID_MMI_UM_DELETE_ALL_RES

/**************************************************************************************
  * Description
  * <pre>
  *   Message applications indicate UM which menu item should be highlighted when the
  *   screen goes back to inbox, unsent, sent or draft list. If the message box has not
  *   been entered when UM receives this primitive, UM would ignore this primitive. If
  *   the message specified in the local parameter does not exist, UM would also ignore
  *   this primitive.
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_highlight_msg_ind_struct
  **************************************************************************************/
#define MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND

/***********************************************************
  * Description
  *   Do nothing, old message.
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_highlight_decided_by_UM_struct
  ***********************************************************/
#define MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND

/************************************************************************************
  * Description
  * <pre>
  *   Message applications indicate UM to refresh the message information. This
  *   primitive is used by message applications to notify UM there is some change in
  *   messages of message application by abnormal ways. For example, if SMS or MMS
  *   messages is added or deleted by AT command, then message application should
  *   notify UM by this primitive.
  *
  *   When UM receives this primitive, UM would check if current screen is one of the
  *   following screens, which are message main menu, inbox list, outbox list, sent
  *   list, drafts list, and delete folder. If NOT, UM would do nothing. if YES, UM
  *   would re-enter current screen so that the latest information would be got from
  *   message applications.
  *
  *   The field msg_box_type in srv_um_refresh_ind_struct is used to specify which
  *   types of message boxes needs refreshed. If all message boxes needs refreshed or
  *   the type of message boxes needed refreshed cannot be determined, the value of
  *   this field can be filled in bit-wise OR the all enum value of
  *   mmi_um_msg_box_type_enum.
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_refresh_ind_struct
  ************************************************************************************/
#define MSG_ID_MMI_UM_REFRESH_IND

/****************************************************
  * Description
  * <pre>
  *   canel new message indication
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_get_msg_num_req_struct
  ****************************************************/
#define MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND

/**************************************************************************************
  * Description
  * <pre>
  *   This message is used to entry mark several screen from other application(SMS, MMS
  *   and Wap Push). Because entry mark several screen must come from application, the
  *   application should notify UM to display the mark several screen.
  * </pre>
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_entry_mark_several_req_struct
  *   Response Message: MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP
  **************************************************************************************/
#define MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ

/***************************************************************************************
  * Description
  * <pre>
  *   UM should notify application the status of entry mark several screen. If success
  *   to enter mark several screen, application should remove its screen in the history.
  *   Because when press RSK ¡§Back¡¨ in mark several screen, the screen flow should go
  *   back to folder not back to option list.
  *   If fail to enter mark several screen, application should not remove its screen in
  *   the history.
  * </pre>
  * Note
  *   UM -&gt; APP
  * See Also
  *   Local Parameter: srv_um_entry_mark_several_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ
  ***************************************************************************************/
#define MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP

/**************************************************************************************
  * Description
  * <pre>
  *   UM informs application to active operation in corresponding to messages by this
  *   primitive. End user can choose several messages and one action provided by UM to
  *   accomplish this process. In every primitive, UM supports few number of message in
  *   order to achieve the abort function. In this way, e.g.
  *   SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP defines as 5. If there are 20 messages need to be
  *   executed, UM should send 4 primitives to process all messages.
  * </pre>
  * Note
  *   UM -&gt; APP
  * See Also
  *   Local Parameter: srv_um_mark_several_op_req_struct
  *   Request Message: MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ
  **************************************************************************************/
#define MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ

/*************************************************************************************
  * Description
  * <pre>
  *   After processing the operation, application responses UM the status of each
  *   message operation. If success to process, the result of msg_id is TRUE, else the
  *   result of msg_id is FALSE. For example, UM send the request to MMS to move 4
  *   messages to archive. There are 3 messages can be moved and one (delivery report)
  *   can¡¦t. After moving the 3 MMS to archive folder, MMS should send the reponse to
  *   UM. This message informs UM 3 messages moved successfully but one message fails.
  *   Thus, UM can notify end user "message can't be moved to archive".
  * </pre>
  * Note
  *   APP -&gt; UM
  * See Also
  *   Local Parameter: srv_um_mark_several_op_rsp_struct
  *   Response Message: MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ
  *************************************************************************************/
#define MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP

/**********************************************************************************************
  * Description
  * <pre>
  *   This message requests application to traverse all the messages and filter out the
  *   messages um needs. This primitive is similar to MSG_ID_MMI_UM_GET_MSG_LIST_REQ
  *   but more powerful.
  *
  *   For each message, application must fill in required field into
  *   srv_um_msg_detail_struct and pass it into traverse function one by one.
  *   In srv_um_msg_detail_struct, msg_type and msg_id are mandatory field.
  *   As for other fields, application need to check the bit mask of "field" parameter
  *   in srv_um_traverse_msg_req_struct to decide which field is necessary.
  *
  *   Ex: if field = 0x0011 (SRV_UM_DETAIL_SUBJECT | SRV_UM_DETAIL_MSG_BOX)
  *       application must assign the subject pointer and the type of message box
  *       into srv_um_msg_detail_struct before calling traverse function.
  *
  *   After calling the traverse function, application should check the return value.
  *   If it returns SRV_UM_RESULT_OK, application can traverse the next message.
  *   Otherwise, application must stop to traverse message and send
  *   MSG_ID_MMI_UM_TRAVERSE_MSG_RSP back to UM.
  *
  *   In general case, the memory prepared by UM only can sustain arround 40 ~ 50
  *   messages. Therefore, for every 40 messages, traverse function will return
  *   SRV_UM_RESULT_BUFFER_FULL. In this case, application should send the response
  *   message back to UM and wait for the next request message.
  *
  *   In next request message, UM may setup the start_entry as 40. Then application
  *   start to traverse the message from the 40th entry. This sequence will repeat
  *   serveral times until go through all the messages
  *
  *   Ex:  There are totally 95 messages.
  *   1st MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, start_entry = 0
  *       MSG_ID_MMI_UM_TRAVERSE_MSG_RSP,                   more = KAL_TRUE
  *   2nd MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, start_entry = 40
  *       MSG_ID_MMI_UM_TRAVERSE_MSG_RSP,                   more = KAL_TRUE
  *   3rd MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, start_entry = 80
  *       MSG_ID_MMI_UM_TRAVERSE_MSG_RSP,                   more = KAL_FALSE
  *
  *   The box type indicates applicaton only needs to traverse the messages belongs
  *   to the box type. But the box type is presented in bitwise format. If we
  *   want to support conversation box, the box type will be
  *   SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_OUTBOX
  *
  *   P.S. Due to message service limitation, the box type only set one type at one time
  *        The request message will be at least sent two times to get the messages in
  *        inbox and outbox separately.
  *
  * </pre>
  * Note
  *   UM -> APP
  * See Also
  *   Local Parameter: srv_um_traverse_msg_req_struct
  *   Response Message: MSG_ID_MMI_UM_TRAVERSE_MSG_RSP
  **********************************************************************************************/
#define MSG_ID_MMI_UM_TRAVERSE_MSG_REQ


/************************************************************************************
  * Description
  * <pre>
  *   After traverse the messages, application sends this primitive to notify UM
  *   the status of process.
  *
  *     Case 1: Traverse function return SRV_UM_RESULT_BUFFER_FULL
  *         set result as KAL_TRUE
  *         set more as KAL_TRUE
  *
  *     Case 2: Traverse function return other error code
  *         set result as KAL_FALSE
  *         set more as KAL_FALSE or KAL_TRUE, no use
  *
  *     Case 3: Traverse function return SRV_UM_RESULT_OK and application traverses all the messages
  *         set result as KAL_TRUE
  *         set more as KAL_FALSE
  *
  *   Set msg_number as the number of message that had traversed in this primitive message,
  *   but not including the last message in filter function with failed error code.
  *
  *   ex:  the traverse callback function is invoked 7 times, and the last time you get
  *        SRV_UM_RESULT_BUFFER_FULL.  Then the msg_number should be 6.
  *
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_traverse_msg_rsp_struct
  *   Request Message: MSG_ID_MMI_UM_TRAVERSE_MSG_REQ
  ************************************************************************************/
#define MSG_ID_MMI_UM_TRAVERSE_MSG_RSP

/************************************************************************************
  * Description
  * <pre>
  *     Use this message to get the corresponding thread id
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_lookup_thread_req_struct
  *   Request Message: MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ
  ************************************************************************************/
#define MSG_ID_MMI_UM_GET_THREAD_ID_REQ

/************************************************************************************
  * Description
  * <pre>
  *     User this message to get the corresponding name in phone database
  * </pre>
  * Note
  *   APP -> UM
  * See Also
  *   Local Parameter: srv_um_lookup_number_req_struct
  *   Response Message: MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ
  ************************************************************************************/
#define MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ

#endif  /* __BUILD_DOM__ */



#ifndef __BUILD_DOM__
	MSG_ID_MMI_UM_READY_IND,
	MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
	MSG_ID_MMI_UM_GET_MSG_NUM_RSP,
	MSG_ID_MMI_UM_GET_MSG_LIST_REQ,
	MSG_ID_MMI_UM_GET_MSG_LIST_RSP,
	MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
	MSG_ID_MMI_UM_GET_MSG_INFO_RSP,
	MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
	MSG_ID_MMI_UM_DELETE_FOLDER_RSP,
	MSG_ID_MMI_UM_NEW_MSG_IND,
	MSG_ID_MMI_UM_DELETE_ALL_IND,
	MSG_ID_MMI_UM_DELETE_ALL_RES,
	MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND,
	MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND,
	MSG_ID_MMI_UM_REFRESH_IND,
	MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND,
	MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ,
	MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP,
	MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ,
    MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP,
    MSG_ID_MMI_UM_TRAVERSE_MSG_REQ,
    MSG_ID_MMI_UM_TRAVERSE_MSG_RSP,
    MSG_ID_MMI_UM_GET_THREAD_ID_REQ,
    MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ,
    MSG_ID_MMI_UM_RESERVED_2_REQ,
    MSG_ID_MMI_UM_RESERVED_2_RSP,
#endif  /* __BUILD_DOM__ */




