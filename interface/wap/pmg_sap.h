#ifdef __BUILD_DOM__
typedef enum {
#endif

    MSG_ID_WPS_PMG_READY_IND,   /* This primitive is used to notify Push Inbox application that PMG is ready */
    MSG_ID_WPS_PMG_CONFIG_REQ,  /*************************************************************************
                                  * This primitive is used to configure WAP PUSH settings in adaptation
                                  * layer. Push application is expected to send the primitive to PMG after
                                  * initialization and any modification has been made.                    
                                  *************************************************************************/
    MSG_ID_WPS_PMG_CONFIG_CNF,  /************************************************************************
                                  * The response primitive to MSG_ID_WPS_PMG_CONFIG_REQ, its existence is
                                  * mainly for future expansion purpose.                                 
                                  ************************************************************************/
    MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ,  /****************************************************************************
                                           * This primitive is used by push application to set its trust addresses
                                           * to PMG whenever it¡¦s modified. The trust addresses will not be in effect
                                           * unless the ¡§trust_enabled¡¨ in MSG_ID_WPS_PMG_CONFIG_REQ has been set to
                                           * \1. When the trust_enabled is set, the addresses entry in this
                                           * primitive will be checked against the received message. PHS will
                                           * discard the message straightaway if the address list is empty. Push
                                           * application may continually send this primitive to set for more trust
                                           * addresses, it does not have to wait for its response to return to send
                                           * the next list segment. While Push message can be sent to client
                                           * directly by PPG or indirectly through SMSC, a trust address can be set
                                           * as an IP or domain name of PPG or a phone number address pair of SC
                                           * (SMSC) and OA (PPG).                                                     
                                           ****************************************************************************/
    MSG_ID_WPS_PMG_TRUST_ADDR_LIST_CNF,  /*******************************************************************************
                                           * This is the response primitive to MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ, mainly
                                           * to notify application that its addresses has been set.                      
                                           *******************************************************************************/
    MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ,  /**********************************************************************************
                                           * This primitive is used by push application to send its black list
                                           * addresses to PMG whenever it¡¦s modified. The black list addresses will
                                           * not be in effect unless the ¡§black_list_enabled¡¨ in MSG_ID_WPS_PMG_CONFIG_REQ
                                           * has been set to 1. When the black_list_enabled is set, the addresses
                                           * entry in this primitive will be checked against the received message
                                           * after enabled white list check. PHS will discard the message
                                           * straightaway if any black list entry is matched. Push application may
                                           * continually send this primitive to set more black list addresses, and
                                           * it does not have to wait for its response to return to send the next
                                           * list segment.                                                                  
                                           **********************************************************************************/
    MSG_ID_WPS_PMG_BLACK_ADDR_LIST_CNF,  /**************************************************************************
                                           * This is the response primitive to MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ to
                                           * notify application that the specified black list addresses have been
                                           * set.                                                                   
                                           **************************************************************************/
    MSG_ID_WPS_PMG_NEW_MSG_IND,  /**************************************************************************
                                   * This primitive is used by adaption layer to notify application layer
                                   * that a new message has arrived. This primitive will only be sent if the
                                   * type of newly arrived message is enabled earlier on, in the case where
                                   * this message type has been disabled, the newly received message will be
                                   * deleted automatically. PMG will only send a message at a time, push
                                   * application must send the MSG_ID_WPS_PMG_NEW_MSG_RSP indicating it has
                                   * completed processing the current message before PMG would send the next
                                   * queued message.
                                   * 
                                   * The peer buffer of MSG_ID_WPS_PMG_NEW_MSG_IND contains the ¡§href¡¨
                                   * parameter of the SI or SL messages. Max length of an URL is 255 ASCII
                                   * characters (excluding zero-termination). In the case where href is
                                   * empty or not available, peer buffer will then be a NULL pointer,
                                   * application will be required to identify this as an empty URL.
                                   * <img name="SAP_SRV_PMG_peer_buffer" />                                 
                                   **************************************************************************/
    MSG_ID_WPS_PMG_NEW_MSG_RSP,  /********************************************************************************
                                   * This is the response primitive to MSG_ID_WPS_PMG_NEW_MSG_IND, used to trigger
                                   * PMG to send the next queued message to push application.                     
                                   ********************************************************************************/
    MSG_ID_WPS_PMG_DELETE_IND,  /*************************************************************************
                                  * This primitive is use by adaptation layer to notify application layer
                                  * that a message has been asynchronously deleted, most likely due to the
                                  * si-delete message. This indication will only be sent to application
                                  * layer if the associated message type has been enabled earlier on.     
                                  *************************************************************************/
    MSG_ID_WPS_PMG_REPLACE_IND,  /*************************************************************************
                                   * This primitive is use by adaption layer to notify application layer
                                   * that a message has been replaced by message. This indication will only
                                   * be sent to application layer if the associated message type has been
                                   * enabled earlier on.
                                   * 
                                   * The peer buffer of MSG_ID_WPS_PMG_REPLACE_IND contains the ¡§href¡¨
                                   * parameter of the SI or SL messages. Max length of an URL is 255 ASCII
                                   * characters (excluding zero-termination). In the case where href is
                                   * empty or not available, peer buffer will then be a NULL pointer,
                                   * application will be required to identify this as an empty URL.
                                   * <img name="SAP_SRV_PMG_peer_buffer" />                                
                                   *************************************************************************/
    MSG_ID_WPS_PMG_MSG_COUNT_REQ,  /**************************************************************************
                                     * This primitive is used by application layer to query adaptation layer
                                     * on the number of messge exists in storage which satisfy the specified
                                     * \conditions. For example, if msg_type set to PMG_MSGTYPE_SI, is_read =
                                     * PMG_PARAM_NO, is_expired = PMG_PARAM_YES and has_info = PMG_PARAM_NO,
                                     * the response primitive (MSG_ID_PMG_MSG_COUNT_RES) will then specify the
                                     * number of unread and expired SI messages currently in system. The
                                     * msgType allows PMG_MSGTYPE_SI and PMG_MSGTYPE_SL to be concatenated
                                     * together indicating both SI and SL messages must be included in query,
                                     * or using the PMG_MSGTYPE_NOT_SPECIFY indicating message type should not
                                     * be considered when performing query (for future expansion).            
                                     **************************************************************************/
    MSG_ID_WPS_PMG_MSG_COUNT_CNF,  /***************************************************************************************************
                                     * This is the response primitive to MSG_ID_WPS_PMG_MSG_COUNT_REQ,
                                     * containing the number of messages satisfying the query specified in MSG_ID_WPS_PMG_MSG_COUNT_REQ
                                     * primitive.                                                                                      
                                     ***************************************************************************************************/
    MSG_ID_WPS_PMG_MSG_LIST_REQ,  /**************************************************************************
                                    * This primitive is used by application to instruct adaptation layer to
                                    * construct a list of messages in time reversed order where messages
                                    * satisfy the conditions specified. The start_from parameter indicates
                                    * the index where message search will begin, application should fill in 0
                                    * for this parameter at first, and shall the constructed message list
                                    * requires more than 1 response primitive, this parameter should then be
                                    * filled with value of ¡§more¡¨ parameter as indicated by the response
                                    * primitive. The ¡§size¡¨ parameter indicates the maximum number of
                                    * messages to retrieve, should the response is not been able to fit into
                                    * a single MSG_ID_WPS_PMG_MSG_LIST_CNF primitive, application should
                                    * trigger this request again having startFrom set to the ¡§more¡¨ as
                                    * returned by previous response primitive, and ¡§size¡¨ set to
                                    * ¡§size_remain¡¨ as indicated.                                          
                                    **************************************************************************/
    MSG_ID_WPS_PMG_MSG_LIST_CNF,  /***************************************************************************
                                    * This is the response primitive to the MSG_ID_WPS_PMG_MSG_LIST_REQ,
                                    * contains a list of message that satisfy the specified conditions and is
                                    * placed in time reversed order (based on created field of the message of
                                    * the time when this message arrived). The returned message list has a
                                    * maximum size of PMG_MAX_MSG_LIST_SIZE, if the matched messages cannot
                                    * be fitted into the response primitive (indicated by a non-zero ¡§more¡¨
                                    * parameter), the application should then send the
                                    * MSG_ID_WPS_PMG_MSG_LIST_REQ again having ¡§start_from¡¨ parameter set to
                                    * value of ¡§more¡¨ parameter in this primitive so remaining messages can
                                    * be fetched. ¡§Size¡¨ parameter indicates the number of valid messages
                                    * stored in the list, and ¡§size_remain¡¨ indicates the number of messages
                                    * remain to be retrieved.                                                 
                                    ***************************************************************************/
    MSG_ID_WPS_PMG_GET_MSG_REQ,  /************************************************************************
                                   * This primitive is used to retrieve all detailed information regarding
                                   * to a specific message.                                               
                                   ************************************************************************/
    MSG_ID_WPS_PMG_GET_MSG_CNF,  /****************************************************************************
                                   * This is the response primitive to MSG_ID_WPS_PMG_GET_MSG_REQ. The
                                   * message data is stored in ¡§msg_data¡¨ parameter, in the scearnio where
                                   * message with requested msgID has been asynchronously deleted, the
                                   * ¡§msg_data¡¨ will then contains invalid data and will be indicated by the
                                   * ¡§status¡¨ parameter.
                                   * 
                                   * The peer buffer of MSG_ID_WPS_PMG_GET_MSG_CNF contains the ¡§href¡¨
                                   * parameter of the SI or SL messages. Max length of an URL is 255 ASCII
                                   * characters (excluding zero-termination). In the case where href is
                                   * empty or not available, peer buffer will then be a NULL pointer,
                                   * application will be required to identify this as an emptry URL.
                                   * <img name="SAP_SRV_PMG_peer_buffer" />                                   
                                   ****************************************************************************/
    MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ,  /***************************************************************************
                                           * This primitive is used to retrieve a list of INFO tags which may be
                                           * sent as part of SI messages. The ¡§start_from¡¨ parameter is used in the
                                           * same way as MSG_ID_WPS_PMG_MSG_LIST_REQ, where application should
                                           * specify a value of 0 initially, or the value of ¡§more¡¨ parameter from
                                           * response primitive in the case of incompleted list. Although INFO tag
                                           * is only available to SI messages, application querying INFO tag for a
                                           * SL message is still treated as valid, and the returned ¡§status¡¨ will
                                           * indicate an empty INFO tag list.                                        
                                           ***************************************************************************/
    MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF,  /*************************************************************************************************
                                           * This is the response primitive to MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ, where
                                           * ¡§size¡¨ indicates the number of valid INFO tag entries in
                                           * ¡§info_item_list_data¡¨ array, and ¡§more¡¨ parameter used to indicate
                                           * whether the list has completed (0). Application should send MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ
                                           * again having ¡§start_from¡¨ equals to value of ¡§more¡¨ parameter in the
                                           * scenario where list is not finished. The ¡§status¡¨ parameter is used to
                                           * indicate whether the request message ID is valid, in the scenario where
                                           * request message is asynchronously deleted or msg_id is not found in
                                           * storage, ¡§status¡¨ will then be set to PMG_STATUS_NOT_FOUND.                                 
                                           *************************************************************************************************/
    MSG_ID_WPS_PMG_DELETE_MSG_REQ,  /*************************************************************************
                                      * This primitive is used by application to instruct adaptation to delete
                                      * a particular message.                                                 
                                      *************************************************************************/
    MSG_ID_WPS_PMG_DELETE_MSG_CNF,  /* This is the response primitive to MSG_ID_WPS_PMG_DELETE_MSG_REQ. */
    MSG_ID_WPS_PMG_DELETE_ALL_REQ,  /*******************************************************************************
                                      * This primitive is used by application to instruct adaptation to delete
                                      * all message of a particular message type or a combination of message types.
                                      * Concatenating PMG_MSGTYPE_SI and PMG_MSGTYPE_SL together will result in
                                      * all messages of both types being deleted, specifying PMG_MSGTYPE_NOT_SPECIFY
                                      * as msg_type will result in all messages in storage being removed
                                      * regardless of the type (for future expansion).                              
                                      *******************************************************************************/
    MSG_ID_WPS_PMG_DELETE_ALL_CNF,  /* This is the response primitive to MSG_ID_WPS_PMG_DELETE_ALL_REQ. */
    MSG_ID_WPS_PMG_UPDATE_MSG_REQ,  /********************************************************************
                                      * This primitive is used by application to change the property of a
                                      * particular message.                                              
                                      ********************************************************************/
   MSG_ID_WPS_PMG_TURN_ON_OFF_PUSH_REQ,/*this primitive is used by application to request turn on/off push service*/

    MSG_ID_WPS_PMG_UPDATE_MSG_CNF,  /**********************************************************************************
                                      * This is the response primitive to MSG_ID_WPS_PMG_UPDATE_MSG_REQ. The ¡§status¡¨
                                      * parameter indicates whether the update request succeeded, or the
                                      * requested message has been asynchronously deleted due to message
                                      * replacement or deletion by SI-DELETE message.                                  
                                      **********************************************************************************/
    MSG_ID_WPS_PMG_UPDATE_ALL_MSG_REQ,  /********************************************************************
                                      * This primitive is used by application to change the property of a
                                      * particular message.                                              
                                      ********************************************************************/
    MSG_ID_WPS_PMG_UPDATE_ALL_MSG_CNF,
						/* This primitive is used by application to change the property of a
                                      * particular message.                                              
                                      ********************************************************************/

    MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ,  /*********************************************************************************
                                           * This primitive will be sent to push application when PHS requires
                                           * action be taken from user whenever a SIR message is received. Push application
                                           * is expected to display a ¡§New Message¡¨ popup if not on idle screen and
                                           * a confirmation dialog when user enters idle screen. The dialog may
                                           * consist of information such as host address and port. Push application
                                           * should also be able to handle multiple requests.                              
                                           *********************************************************************************/
    MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF,  /****************************************************************************
                                           * This is the response primitive to MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ. The
                                           * \result field informs whether PMG should accept the connection setup
                                           * request. After sending of this primitive, push application must ensure
                                           * the dialog is properly removed.                                          
                                           ****************************************************************************/
    MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ,  /****************************************************************************
                                            * This primitive will be sent to push application when PHS requires
                                            * action be taken from user when the message¡¦s address is unrecognized
                                            * (ie, untrusted). PHS would only trigger such dialog when the PHS¡¦
                                            * registry: /PHS/wlist/behaviour¡¨ is set to 1 (ie, ¡§notify¡¨), and push
                                            * application is expected to display a ¡§New Message¡¨ popup if not on idle
                                            * screen and a confirmation dialog when user enters idle screen. The
                                            * confirmation dialog may consists of incoming message¡¦s information like
                                            * message type, address, link URI, etc. Push application should be able
                                            * to handle multiple requests.                                             
                                            ****************************************************************************/
    MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF,  /**************************************************************************
                                            * This is the response primitive to MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ.
                                            * The result field informs whether PMG should accept the message incoming
                                            * request. After sending this primitive, push application must ensure the
                                            * dialog is properly removed.                                            
                                            **************************************************************************/
    MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND,  /*************************************************************************
                                                 * This primitive is sent to push application for it to display a ¡§inbox
                                                 * full¡¨ dialog when such situation occurs.                             
                                                 *************************************************************************/
    MSG_ID_WPS_PMG_DELETE_FOLDER_IND,  /**************************************************************************
                                         * This primitive is sent to push application to inform that the specified
                                         * push folder has been deleted by Unified Message application.           
                                         **************************************************************************/
    MSG_ID_WPS_PMG_DLG_QUERY_REQ,  /**************************************************************************
                                     * This primitive is used by push application to obtain the details of a
                                     * previously sent dialog request.
                                     **************************************************************************/
    MSG_ID_WPS_PMG_DLG_QUERY_CNF,  /**************************************************************************
                                     * This primitive is a response to MSG_ID_WPS_PMG_DLG_QUERY_REQ, carrying
                                     * the original request structure which was sent with
                                     * MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ or
                                     * MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ.
                                     **************************************************************************/
    MSG_ID_WPS_PMG_ERROR_DLG_IND,
    /*SKS*/
    MSG_ID_WPS_PMG_MSG_READ_STATUS_REQ,


#ifdef __BUILD_DOM__
} pmg_sap_enum;
#endif
