#ifndef _MMA_SAP_H
#define _MMA_SAP_H


#ifdef __BUILD_DOM__
/*These following service primitives exported by MMA module.*/
<GROUP Message>
typedef enum {
#endif

    MSG_ID_WAP_MMA_TERMINATE_IND, /*When MMA starts to terminate itself, it sends MSG_ID_WAP_MMA_TERMINATE_IND to notify MMI.

                                    Direction: MMA -> Application
                                    Local paramter: None
                                    Peer buffer: None                                     
                                  */
    MSG_ID_WAP_MMA_UM_ENTRY_REQ, /*wap_mma_um_entry_req_struct, */
    MSG_ID_WAP_MMA_GET_SETTING_REQ,/*Applications can use this primitive to get MMS composing settings. For example, if Unified Composer is invoked by either MMI (creating a new MMS from scratch) or MMS application (editing from an existing MMS), it should send this primitive requesting MMS application to provide MMS default composing setting. The req_id field is to indentify this request.

                                    Direction: Application -> MMA
                                    Local paramter: wap_mma_get_setting_req_struct
                                    Peer buffer: None                                     
                                   */    
    MSG_ID_WAP_MMA_GET_SETTING_RSP, /*MMS adaptor responses the MMS default composing setting to applications, ex. Unified Composer. After receiving MSG_ID_WAP_MMA_GET_SETTING_REQ from application, MMS adaptor uses this primitive to provide MMS default setting value/range to application.
    
                                    Direction: MMA -> Application
                                    Local paramter: wap_mma_get_setting_rsp_struct
                                    Peer buffer: None                                     
                                   */
    MSG_ID_WAP_MMA_SET_SETTING_REQ, /*Applications can use this primitive to set MMS settings. The req_id field is to indentify this request.

                                    Direction: Application -> MMA
                                    Local paramter: wap_mma_set_setting_req_struct
                                    Peer buffer: None                                     
                                   */
    MSG_ID_WAP_MMA_SET_SETTING_RSP, /*wap_mma_set_setting_rsp_struct, */
    MSG_ID_WAP_MMA_GET_PROFILE_REQ, /*Obsolete*/
    MSG_ID_WAP_MMA_GET_PROFILE_RSP, /*Obsolete*/
    MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ, /* Applications can use this primitive to get current memory usage. The <b>req_id</b> field is to indentify this request.

                                    Direction: Application -> MMA
                                    Local paramter: wap_mma_get_mem_status_req_struct
                                    Peer buffer: None                                     
                                   */
    MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP, /*MMS adaptor responses the memory usage request to applications. After receiving MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ from application, MMS adaptor uses this primitive to provide MMS current memory usage to application.
    
                                    Direction: MMA -> Application
                                    Local paramter: wap_mma_get_mem_status_rsp_struct
                                    Peer buffer: None                                     
                                  */
    MSG_ID_WAP_MMA_SET_PROFILE_REQ, /*Applications can use this primitive to set MMS profile, like proxy address. The req_id field is to identify this request. 

                                    Direction: Application -> MMA
                                    Local paramter: wap_mma_set_profile_req_struct
                                    Peer buffer: None                                     
                                  */
    MSG_ID_WAP_MMA_SET_PROFILE_RSP, /*After receiving MSG_ID_WAP_MMA_SET_PROFILE_REQ from application, MMS adaptor sets the profile according to given parameter・s and send this primitive to application with its success / fail result.
    
                                    Direction: MMA -> Application
                                    Local paramter: wap_mma_set_profile_rsp_struct
                                    Peer buffer: None                                     
                                   */ 
    MSG_ID_WAP_MMA_GET_CONTENT_REQ, /*Applications may use this primitive to get needed MMS content by specifying the msg_id, mode and creation_mode. The primitive is usually used when editing from an existing MMS and, in this case, Unified Composer would know the msg_id and mode in MSG_ID_MMI_UC_START_REQ and creation_mode in MSG_ID_WAP_MMA_GET_SETTING_RSP.
    
                                    Since the MMS content will be returned as XML text saved in peer buffer and the XML text may not be able to transmit all in one primitive, the buffer_index field indicates which XML segment is requested. The buffer_index value always start as 0 and is incremented in the next request if the received MSG_ID_WAP_MMA_GET_CONTENT_RSP says there・s still XML text unsent. If the buffer_index field doesn・t equal to the expected value, the MMS adaptor would assert. The application is supposed to submit request(s) until the response more flag equal to 0 to finish the whole transaction, or application should abort the transaction by sending MSG_ID_WAP_MMA_GET_CONENT_REQ with mode equal to MMA_MODE_ABORT.
                                    
                                    Direction: Application -> MMA
                                    Local paramter: wap_mma_get_content_req_struct
                                    Peer buffer: None                                     
                                    */
    MSG_ID_WAP_MMA_GET_CONTENT_RSP, /*For every MSG_ID_WAP_MMA_GET_CONTENT_REQ, there must be one corresponding MSG_ID_WAP_MMA_GET_CONTENT_RSP returning the requested content. 

                                    The value of <b>msg_id</b> and <b>buffer_index</b> should reference the corresponding MSG_ID_WAP_MMA_GET_CONTENT_REQ. The buffer_index field indicates which XML segment will be returned since XML text may not transmit all in one primitive. The xml_size and xml_filepath value should be the same for the same msg_id. And if there・s still XML content left to be sent in the next round, we use the more field to tell.
                                    Direction: MMA -> Application
                                    Local paramter: wap_mma_get_content_rsp_struct
                                    Peer buffer: XML description file (2000 bytes)
                                    */
    MSG_ID_WAP_MMA_CREATE_REQ, /*This primitive is used for creating a new MMS based on a XML description file. The creation procedure is mandatory for applications like Unified Composer to preview, send and save a MMS. Application may send this primitive for several times to create an MMS file by specifying the MMS structure in XML description.  

                                For preview or save operation, application may start a progressing screen when sending this primitive and remove the screen when receving response from preview and save operation. For send operation, application may start a progressing screen when sending this primitive, update the screen when receiving indications and remove the screen when receving response from send operation. For better screen flow, the progressing screen should be removed after it has been put into history, which means deleting the progressing screen after a new screen has been displayed.

                                If the editor is started by MSG_ID_WAP_MMA_UC_START_REQ primitive, the mode field value should refer to it. When mode is MMA_MODE_SEND or MMA_MODE_FORWARD, the msg_id field should specified the source message ID. The buffer_index field indicates which XML segment is to be sent. It starts as 0 and incremented in the following primitive request if there is. If the buffer_index field doesn・t equal to the expected value, the MMS adaptor would assert. The xml_size and xml_filepath value should be the same for the same req_id. And if there・s still XML content left to be sent in the next round, we use the more field to tell.

                                Direction: Application -> MMA
                                Local paramter: wap_mma_create_req_struct
                                Peer buffer: XML description file (2000 bytes)
                                */
    MSG_ID_WAP_MMA_CREATE_RSP, /*After receiving a MSG_ID_WAP_MMA_CREATE_REQ, MMS adaptor would return a MSG_ID_WAP_MMA_CREATE_RSP to indicate the MMS creation processing result. The created MMS ID will be returned in the last MSG_ID_WAP_MMA_CREATE_RSP of which its corresponding request has more flag equal to FALSE. The buffer_index field indicates which XML segment is expected in the next MSG_ID_WAP_MMA_CREATE_REQ.
                                
                                Direction: MMA -> Application
                                Local paramter: wap_mma_create_rsp_struct
                                Peer buffer: None
                                */
    MSG_ID_WAP_MMA_FREE_MMS_CONTENT,	/*when viewer has copied the information from the MMA populated structure The MMA not need to free the memory of 
										 the structure viewer used to copy for its processing */

    MSG_ID_WAP_MMA_DELETE_REQ, /*Application can delete MMS messages by specifying message id in msg_id array. no_of_msg is the number of messges application want to delete.

                                 Direction: Application -> MMA
                                 Local paramter: wap_mma_delete_req_struct
                                 Peer buffer: None
                                 */
    MSG_ID_WAP_MMA_DELETE_RSP, /*After receiving MSG_ID_WAP_MMA_DELETE_REQ, MMS adaptor would try to delete the specified MMSs. The result will be returned in this primitive by MMS adaptor. 

                                Direction: MMA -> Application
                                Local paramter: wap_mma_delete_rsp_struct
                                Peer buffer: None
                                */
    MSG_ID_WAP_MMA_SAVE_REQ, /*Application can save MMSs to a specific message box by using this primitive after creation procedure. The box field indicates to which message box the MMSs should be saved. no_of_msg specify the number of message id in msg_id array.

                               Direction: Application -> MMA
                               Local paramter: wap_mma_save_req_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_SAVE_RSP, /*After receiving MSG_ID_WAP_MMA_SAVE_REQ, MMS adaptor would save the MMS to the specifed message box. Once the saving is done, MMS adaptor would send the result by this primitive back to application, ex. Unified Composer. If the destination folder is user defined template folder and there are  already MMA_MAX_USER_DEF_TEMPLATE_NUM messages in the folder, MMS adaptor will not save MMS to user defined template folder and will reply result MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL. If the message size is larger than defined maximum value, MMS adaptor will not save the message to user defined template folder and will reply result MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED. For progressing screen issue
    
                               Direction: MMA -> Application
                               Local paramter: wap_mma_save_rsp_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_PREVIEW_REQ, /*Obsolete*/
    MSG_ID_WAP_MMA_PREVIEW_RSP, /*Obsolete*/
    MSG_ID_WAP_MMA_SEND_REQ, /*Application can send an MMS by using this primitive after creation procedure. MMA will help application to resend the MMS message if MMA gets some errors. Application needs to implement resend mechanism by itself.

                               Direction: Application -> MMA
                               Local paramter: wap_mma_send_req_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_SEND_IND, /*After receiving MSG_ID_WAP_MMA_SEND_REQ, MMS adaptor would notify the caller application, ex. Unified Composer, the sending progress with this primitive until the sending is done. According to the percent and retry field in it, application can know the percentage of completion and retry time.

                               Direction: MMA -> Application
                               Local paramter: wap_mma_send_ind_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_SEND_RES, /*Once the MMS application receives the MSG_ID_WAP_SEND_IND, MMS application shall send this primitive to MMA. Then MMA will send next MSG_ID_WAP_SEND_IND to MMS applictoin. It is used to avoid MOD_MMI・s queue is full.

                               Direction: Application -> MMA
                               Local paramter: wap_mma_send_res_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_SEND_RSP, /*Once the MMS sending is completed, MMS adaptor responses the sending result to sender application, ex. Unified Composer, by this primitive. 

                               Direction: MMA -> Application
                               Local paramter: wap_mma_send_rsp_struct
                               Peer buffer: None
                               */
    MSG_ID_WAP_MMA_CANCEL_SEND_REQ, /*After sender application sends MSG_ID_WAP_MMA_SEND_REQ to MMS adaptor and before the sending is completed, sender/other application may cancel the sending transaction by using this primitive. 

                                   The msg_id field indicates which message sending should be canceled.

                                   If the cancellation is successful, both MSG_ID_WAP_MMA_SEND_RSP and  MSG_ID_WAP_MMA_CANCEL_SEND_RSP would be returned. MSG_ID_WAP_MMA_CANCEL_SEND_RSP is sent before MSG_ID_WAP_MMA_SEND_RSP.

                                   Direction: Application -> MMA
                                   Local paramter: wap_mma_cancel_send_req_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_CANCEL_SEND_RSP, /*After receiving MSG_ID_WAP_MMA_CANCEL_SEND_REQ, MMS adaptor would try to cancel the specified sending/pending transaction of the MMS. But MMS adaptor will reply MMA_RESULT_FAIL_MSGID_IS_USING if percentage of the sending transaction is 100% that means the message has been sent to server. The result will be returned in this primitive by MMS adaptor. 

                                   Direction: MMA -> Application
                                   Local paramter: wap_mma_cancel_send_rsp_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_DOWNLOAD_REQ, /*Application can download MMS message by specifying msg_id in this primitive. The msg_id must be the identifier of MMS notitication. 

                                   Direction: Application -> MMA
                                   Local paramter: wap_mma_download_req_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_DOWNLOAD_RSP, /*Once the MMS download is completed, MMS adaptor responses the download result to sender application, ex. Unified Composer, by this primitive. 

                                   Direction: MMA -> Application
                                   Local paramter: wap_mma_download_rsp_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_DOWNLOAD_IND, /*Once the MMS application sends the MSG_ID_WAP_DOWNLOAD_REQ, MMS adaptor responses the sending result to sender application, ex. Unified Composer, by this primitive. The percent field information will tell the Application about the amount of data that has already been downloaded and based on this the application will show the progress screen.

                                   Direction: MMA -> Application
                                   Local paramter: wap_mma_download_ind_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_DOWNLOAD_RES, /*Once the MMS application receives the MSG_ID_WAP_DOWNLOAD_IND, MMS application shall send this primitive to MMA. Then MMA will send next MSG_ID_WAP_DOWNLOAD_IND to MMS applictoin. It is used to avoid MOD_MMI・s queue is full.

                                   Direction: Application -> MMA
                                   Local paramter: wap_mma_download_res_struct
                                   Peer buffer: None
                                   */
    MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ, /*After sender application sends MSG_ID_WAP_MMA_DOWNLOAD_MMS_REQ to MMS adaptor and before the download is completed, sender/other application may cancel the sending transaction by using this primitive. 
                                          The msg_id field indicates which message sending should be canceled. 
                                          If the cancellation is successful, both MSG_ID_WAP_MMA_DOWNLOAD_RSP and  MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP would be returned.
                                   
                                          Direction: Application -> MMA
                                          Local paramter: wap_mma_cancel_download_req_struct
                                          Peer buffer: None
                                         */
    MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP, /*After receiving MSG_ID_WAP_CANCEL_DOWNLOAD_MMS_REQ, MMS adaptor would try to cancel download of  the specified MMS. But MMS adaptor will reply MMA_RESULT_FAIL_MSGID_IS_USING if percentage of the downloading transaction is 100% that means the message has been downloaded and is parsing. The result will be returned in this primitive by MMS adaptor. 

                                          Direction: MMA -> Application
                                          Local paramter: wap_mma_cancel_download_rsp_struct
                                          Peer buffer: None
                                        */
    MSG_ID_WAP_MMA_GET_MSG_INFO_REQ, /*Application can request MMS message information by specifying msg_id in this primitive. Then MMA will replies basic information of this MMS to application.

                                       Direction: Application -> MMA
                                       Local paramter: wap_mma_get_msg_info_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_GET_MSG_INFO_RSP, /*After receiving MSG_ID_WAP_MMA_GET_MSG_INFO_REQ, MMS adaptor would collect some basic information of the MMS specified to application. It only provide one from address.

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_get_msg_info_rsp_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_SET_READMARK_REQ, /*Application can send this primitive to MMA to change the read status of specifc MMS message. 

                                       Direction: Application -> MMA
                                       Local paramter: wap_mma_set_readmark_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_SET_READMARK_RSP, /*After receiving MSG_ID_WAP_MMA_SET_READMARK_RSP, MMS adaptor will reply the result to application by this primitive. 

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_set_readmark_rsp_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND, /*When MMA starts to download one MMS message in background, it will send the indication to application. Then application can show the blink icon on idle screen. 

                                                Direction: MMA -> Application
                                                Local paramter: wap_mma_start_immed_retrieval_ind_struct
                                                Peer buffer: None    
                                                */
    MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND, /*After MMA finish the immediate retrieval of one MMS message, it will send the indication to application. Then application can stop the blink icon on idle screen. One reminder is that application shall wait for a while (ex: 5 seconds) after stop_immed_retrieval_ind primitive is received. Because MMA may download lots of MMS one by one in background. No matter the immediate retrieval succeeds or fails, MMA should send MSG_ID_MMI_UM_NEW_MSG_IND to application. 

                                               Direction: MMA -> Application
                                               Local paramter: wap_mma_stop_immed_retrieval_ind_struct
                                               Peer buffer: None    
                                               */
    MSG_ID_WAP_MMA_SET_APP_DATA_REQ, /*Application can save some application data corresponding to one MMS into MMA.
                                       The current usage of app_data[] is as follows:
                                       app_data[0] is used for lock mode. (0: off, 1: on)
                                       app_data[1] is used to indicate if a message is corrupt. (0: message is not corrupt, 1: message is corrupt)

                                       Direction: Application -> MMA
                                       Local paramter: wap_mma_set_app_data_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_SET_APP_DATA_RSP, /*After receiving MSG_ID_WAP_MMA_SET_APP_DATA_REQ, MMS adaptor would update these data to corresponding MMS message.

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_set_app_data_rsp_struct
                                       Peer buffer: None    
                                       */
    MSG_ID_WAP_MMA_GET_MSG_LIST_REQ, /*After receiving MSG_ID_WAP_MMA_GET_MSG_LIST_REQ, MMS adaptor would reply all message ids under specific folder. If the number of MMS messages in folder is more than MMA_MAX_MSG_ARRAY_NUM, the more flag in wap_mma_get_msg_list_rsp_strcut will be KAL_TRUE. Application MUST send MSG_ID_WAP_MMA_GET_MSG_LIST_REQ with same req_id to MMA to retrieve message identifiers list. Otherwise, it will cause memory leak issue in MMA.

                                       Direction: Application -> MMA
                                       Local paramter: wap_mma_get_msg_list_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_GET_MSG_LIST_RSP, /*After receiving MSG_ID_WAP_MMA_GET_MSG_LIST_REQ, MMS adaptor would reply all message ids under specific folder. If the number of MMS messages in folder is more than MMA_MAX_MSG_ARRAY_NUM, the more flag in wap_mma_get_msg_list_rsp_strcut will be KAL_TRUE. Application MUST send MSG_ID_WAP_MMA_GET_MSG_LIST_REQ with same req_id to MMA to retrieve message identifiers list. Otherwise, it will cause memory leak issue in MMA.

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_get_msg_list_rsp_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_STORAGE_FULL_IND, /*If MMA failed to create MMS message, it will send this primitive to MOD_MMI.

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_storage_full_ind_struct
                                       Peer buffer: None    
                                       */
    MSG_ID_WAP_MMA_VIEW_MSG_IND, /*When UM tried to play one MMS, it will calls wap_um_entry_mms(folder_id and msg_index). This function will send MSG_ID_WAP_MMA_VIEW_MSG_IND to MOD_MMI. Then viewer application shall start to play the MMS. 

                                   Direction: Application -> MMA
                                   Local paramter: wap_mma_view_msg_ind_struct
                                   Peer buffer: None
                                   */    
    MSG_ID_WAP_MMA_MSG_IS_VALID_REQ, /*Application can use this primitive to check specified message existence according to the provided message ID list.
                                       Direction: Application -> MMA
                                       Local paramter: wap_mma_msg_is_valid_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_MSG_IS_VALID_RSP, /*MMA returns check result. If the result is successful, related information including existence and message box would be returned as an array to application. The returned array contains info corresponding to the message ID list entry in MSF_ID_WAP_MMA_MSG_IS_VALID_REQ.
                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_msg_is_valid_rsp_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_NOTIFY_EVENT_IND, /*Application can register interested event and MMA will notify application by using MSG_ID_WAP_MMA_NOTIFY_EVENT_IND once the event happens. Application registration mechanism is more flexible to notify application event if MMS application wants to know some information. How applications to register event can be determined by MMA module of each MMS solution.

                                       Direction: MMA -> Application
                                       Local paramter: wap_mma_notify_event_ind_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ, /*Application can use this primitive to get unread message list. The field start_index specifies the index of starting entry from which application requests to get unread message list information. The field num_of_msg_requested indicates number of messages application wants to get information. The value of num_of_msg_requested should not be greater than MMA_MAX_UNREAD_MSG_NUM.
                                              For example, there is 10 unread mms messages in inbox folder sorted by descending received date. If start_index is 0 and num_of_msg_requested is 5, MMA will reply 0 ~ 4 message entries to application. If start_index is 3 and num_of_msg_requested is 5, MMA will reply 3 ~ 7 message entries to application.

                                              Direction: Application -> MMA
                                              Local paramter: wap_mma_get_unread_msg_list_req_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP, /*After receiving MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ, MMS adaptor would collect unread message information and returns unread mms message list to application by this primitive. The field total_num_of_unread_msg specifies number of toal unread message in inbox folder. The field num_of_unread_msg specifies number of unread message items in unread_msg_list. If there is more unread message to be sent, we use more field to tell. 
                                              If there is one new mms message coming (application receive MSG_ID_WAP_MMA_NOTIFY_EVENT_IND with event_id MMA_EVENT_NEW_MSG or MSG_ID_MMI_UM_NEW_MSG_IND) before application finishes getting unread msg list transaction, application MUST reload the unread message list. Otherwise, the message list application received is not correct.

                                              Note: If user removes one MMS message in inbox through PhoneSuite, MMS applicaiton has to inform MMA_APP_HOMESCREEN. Then MMA_APP_HOMESCREEN HAS to update msg_list maintained by HomeScreen application.

                                              Direction: MMA -> Application
                                              Local paramter: wap_mma_get_unread_msg_list_rsp_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ, /*One received new MMS message can be recognized as one recent event. Before application delete the recent event by MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ. The recent event will be kept in recent event list maintained by MMA. Application can use this primitive to get recent event list. The field start_index specifies the index of starting entry from which application requests to get recent event information. The field num_of_evt_requested indicates number of events application wants to get information. The value of num_of_evt_requested should not be greater than MMA_MAX_EVT_NUM. 
                                              For example, there is 10 recent events. If start_index is 0 and num_of_evt_requested is 5, MMA will reply 0 ~ 4 event entries to application. If start_index is 3 and num_of_evt_requested is 5, MMA will reply 3 ~ 7 event entries to application.

                                              Direction: Application -> MMA
                                              Local paramter: wap_mma_get_recent_evt_list_req_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_RSP, /*After receiving MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ, MMS adaptor would collect recent event information and returns event list to application by this primitive. The field total_num_of_evt specifies number of total recent events. The field num_of_evt specifies number of event items in event_list. If there is more recent event to be sent, we use more field to tell.
                                              If there is one new mms message coming (application receive MSG_ID_WAP_MMA_NOTIFY_EVENT_IND with event_id MMA_EVENT_NEW_MSG or MSG_ID_MMI_UM_NEW_MSG_IND) before application finish getting recent event list transaction, application MUST reload the recent event list. Otherwise, the event list application received is not correct.

                                              Note: If user remove one MMS message in inbox through PhoneSuite, MMS applicaiton has to inform MMA_APP_HOMESCREEN. Then MMA_APP_HOMESCREEN HAS to update msg_list maintained by HomeScreen application.

                                              Direction: MMA -> Application
                                              Local paramter: wap_mma_get_recent_evt_list_rsp_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ, /*Application can delete recent event by specifying msg_id in this primitive. To delete all recent events, caller can specify msg_id field value as 0xFFFFFFFF.

                                            Direction: Application -> MMA
                                            Local paramter: wap_mma_delete_recent_evt_req_struct
                                            Peer buffer: None
                                            */
    MSG_ID_WAP_MMA_DELETE_RECENT_EVT_RSP, /*After receiving MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ, MMS adaptor would delete the specified event. The result will be returned in this primitive by MMS adaptor.

                                            Direction: MMA -> Application
                                            Local paramter: wap_mma_delete_recent_evt_rsp_struct
                                            Peer buffer: None
                                            */
    MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_REQ, /*Application can use this primitive to tell MMA to stop downloading any new MMS message (i.e., immediate retrieval can not be allowed).
                                              Once application uses this primitive to suspend MMA for downloading any new MMS message, application needs to use MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ to resume downloading new MMS message, otherwise, no new MMS messages can be received.

                                              Direction: Application -> MMA
                                              Local paramter: wap_mma_suspend_mms_service_req_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_RSP, /*After MMA receives MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_REQ, MMA won・t send MMS push to MMS service module. The push sent to MMA will be cached.

                                              Direction: MMA -> Application
                                              Local paramter: wap_mma_suspend_mms_service_rsp_struct
                                              Peer buffer: None
                                              */
    MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ, /*Application can use this primitive to resume sending push to MMS service.

                                             Direction: Application -> MMA
                                             Local paramter: wap_mma_resume_mms_service_req_struct
                                             Peer buffer: None
                                             */    
    MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_RSP, /*Once MMA receives MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ, MMA will start to send cached push to MMS service.

                                             Direction: MMA -> Application
                                             Local paramter: wap_mma_resume_mms_service_rsp_struct
                                             Peer buffer: None
                                             */
    MSG_ID_WAP_MMA_READY_IND, /*When MMA is ready after initialization, it uses MSG_ID_WAP_MMA_READY_IND to notify MMI.

                                Direction: MMA -> Application
                                Local paramter: None
                                Peer buffer: None
                                */
    MSG_ID_WAP_MMA_MMS_OBJ_IND, /*Application can use this primitive to notify MMA there is a MMS Notification saved in the file system and MMA need to handle it. The field mms_filepath indicate the file path of the mms. Application need to check the message type and use msg_type field to tell MMA. If the file is a notification, MMA will send it to MMS service.
                                  To know the file is a notification or a MMS, application can check the second byte of the file. If the second byte is 0x82, the file is a notification and MMA need to send it to MMS service. If the second byte is 0x80 or 0x84, the file is a MMS.

                                  Direction: Application -> MMA
                                  Local paramter: wap_mma_mms_obj_ind_struct
                                  Peer buffer: None
                                  */
    MSG_ID_WAP_MMA_MMS_OBJ_RES, /*When receiving MSG_ID_WAP_MMA_MMS_OBJ_IND, MMA need to send the message to MMS service if the message is a Notification. After the message is handled, MMA send response primitive MSG_ID_WAP_MMA_MMS_OBJ_RES to application.
                                Direction: MMA -> Application
                                Local paramter: wap_mma_mms_obj_res_struct
                                Peer buffer: None
                                */
    MSG_ID_WAP_MMA_DRM_ENCODE_DONE_IND, /*wap_mma_drm_encode_done_ind_struct, This primitive is for MMA module of OBIGO Q03C MMS V02 internal use*/
    MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ, /*Application can request MMS message information by specifying message id in msg_id array. no_of_msg is the number of messages in msg_id array.

                                           Direction: Application -> MMA
                                           Local paramter: wap_mma_get_msg_property_req_struct
                                           Peer buffer: None
                                           */
    MSG_ID_WAP_MMA_GET_MSG_PROPERTY_RSP, /*After receiving MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ, MMS adaptor would collect some information of the MMS specified by application. MMS property is stored in msg_property array.

                                           Direction: MMA -> Application
                                           Local paramter: wap_mma_get_msg_property_rsp_struct
                                           Peer buffer: None
                                           */    
	MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_REQ,	/*request for msg info including thumnail and mms attribute*/
	MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_RSP,	/*response for msg info including thumnail and mms attribute*/

    MSG_ID_WAP_MMA_GET_MSG_NUM_REQ, /*Application can request folder status by mma_query_option_enum. 

                                      Direction: Application -> MMA
                                      Local paramter: wap_mma_get_msg_num_req_struct
                                      Peer buffer: None
                                      */
    MSG_ID_WAP_MMA_GET_MSG_NUM_RSP, /*After receiving MSG_ID_WAP_MMA_GET_MSG_NUM_REQ, MMS adaptor would collect folder status according to req_tb[] carried in wap_mma_get_msg_num_req_struct and respond answer to application.
    
                                      Direction: MMA -> Application
                                      Local paramter: wap_mma_get_msg_num_rsp_struct
                                      Peer buffer: None
                                      */
    MSG_ID_WAP_MMA_SET_SIM_ID_REQ, /*Application can change sim id of specific message by this primitive.

                                     Direction: Application -> MMA
                                     Local paramter: wap_mma_set_sim_id_req_struct
                                     Peer buffer: None
                                     */
    MSG_ID_WAP_MMA_SET_SIM_ID_RSP, /*After receiving MSG_ID_WAP_MMA_SET_SIM_ID_REQ, MMS adaptor will respond result to application by this primitive.

                                     Direction: MMA -> Application
                                     Local paramter: wap_mma_set_sim_id_rsp_struct
                                     Peer buffer: None
                                     */
    MSG_ID_WAP_MMA_RR_MARK_REQ, /*Application can send this primitive to MMA to change the read report send status of specifc MMS message. 

                                       Direction: Application(BGSR) -> MMA
                                       Local paramter: wap_mma_rr_mark_req_struct
                                       Peer buffer: None
                                       */
    MSG_ID_WAP_MMA_RR_MARK_RSP, /*After receiving MSG_ID_WAP_MMA_RR_MARK_REQ, MMS adaptor will reply the result to application by this primitive. 

                                       Direction: MMA -> Application(BGSR)
                                       Local paramter: wap_mma_rr_mark_rsp_struct
                                       Peer buffer: None  
                                        */ 
   MSG_ID_WAP_MMA_CHG_MSG_STORAGE_REQ,
   MSG_ID_WAP_MMA_CHG_MSG_STORAGE_RSP,
   MSG_ID_WAP_MMA_CHECK_TEMPLATE_REQ,   /*Application can send this primitive to MMA to check the default template.
                                       Direction: MMA -> Application
                                       Local paramter: None
                                       Peer buffer: None
                                       */
   MSG_ID_WAP_MMA_CHECK_TEMPLATE_RSP,    /*When receiving MSG_ID_WAP_MMA_CHECK_TEMPLATE_REQ, Application need to send the message to MMA to send the check template result response.
                                Direction: Application -> MMA
                                Local paramter: wap_mma_check_template_rsp_struct
                                Peer buffer: None
                                */
   MSG_ID_WAP_MMA_DEF_TMPLT_GEN_DONE_IND,	/*An indication to show that the default templete generation is done*/
   MSG_ID_WAP_MMA_INSUFFICIENT_MEMORY_IND,
#ifdef __BUILD_DOM__
}mma_sap_enum ; 
#endif
      
#endif  /* End of _MMA_SAP_H */
