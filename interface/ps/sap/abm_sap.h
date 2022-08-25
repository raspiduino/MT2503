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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   abm.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   ABM related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

	/*-------------- ABM_MSG_CODE_BEGIN ------------------------*/
#ifdef __BUILD_DOM__
   /*****************************************************************************
    * <GROUP  Messages>        
    *
    * abm sap primitive
   ******************************************************************************/
   typedef enum {
#endif

   /* DOM-NOT_FOR_SDK-BEGIN */
   /* Message from SUPC */
   MSG_ID_SUPC_ABM_WIFI_INIT_CNF = MSG_ID_ABM_CODE_BEGIN,
   MSG_ID_SUPC_ABM_WIFI_DEINIT_CNF,
   MSG_ID_SUPC_ABM_WIFI_CONNECT_CNF,
   MSG_ID_SUPC_ABM_WIFI_CONNECT_IND,
   MSG_ID_SUPC_ABM_WIFI_DISCONNECT_CNF,
   MSG_ID_SUPC_ABM_WIFI_DISCONNECT_IND,
   MSG_ID_SUPC_ABM_WIFI_AP_LIST_CNF,

   /* Message from SOC */
   MSG_ID_SOC_ABM_ACTIVATE_REQ,
   MSG_ID_SOC_ABM_DEACTIVATE_REQ,
   MSG_ID_SOC_ABM_IPADDR_CONFLICT_IND,
   MSG_ID_SOC_ABM_RESUME_QOS_CTX_REQ,

   /* Message from L4C */
   MSG_ID_L4C_PS_ABM_SETUP_RSP,
   MSG_ID_L4C_PS_ABM_DISC_RSP,
   MSG_ID_L4C_PS_ABM_DISC_IND,
   MSG_ID_L4C_PS_ABM_NW_ATTACH_IND,
   //MSG_ID_L4C_PS_ABM_QOS_TFT_MODIFY_RSP,	// Karen
   MSG_ID_L4C_PS_ABM_REACTIVATE_RSP,
   MSG_ID_L4C_PS_ABM_PDP_MODIFY_IND, //__GPRS_BEARER_REPORT_NEGOTIATED_QOS__

   MSG_ID_L4C_CC_ABM_SETUP_RSP,
   MSG_ID_L4C_CC_ABM_DISC_RSP,
   MSG_ID_L4C_CC_ABM_DISC_IND,

   MSG_ID_L4CABM_START_REQ,
   MSG_ID_L4CABM_GET_GPRS_ACCOUNT_INFO_REQ,
   MSG_ID_L4CABM_SET_GPRS_ACCOUNT_INFO_REQ,

   MSG_ID_L4C_ABM_DISALLOW_GPRS_AND_CSD_RSP,   
   MSG_ID_L4C_ABM_ALLOW_GPRS_AND_CSD_RSP,

   MSG_ID_L4C_ABM_DIALUP_CONNECT_IND,
   MSG_ID_L4C_ABM_DIALUP_CONNECTING_IND,
   MSG_ID_L4C_ABM_DIALUP_DISC_IND,
   MSG_ID_L4C_ABM_DIALUP_DISC_RSP,
   MSG_ID_L4C_PS_ABM_RESET_DIALUP_INFO_RSP,
   MSG_ID_L4C_PS_ABM_GET_DIALUP_INFO_RSP,
   MSG_ID_L4C_PS_ABM_DIALUP_INFO_IND,
   MSG_ID_L4C_ABM_GPRS_STATUS_IND, //add by hogan temporarily 080223

   /* Message to MMI */
   MSG_ID_MMI_ABM_WIFI_INIT_CNF,
   MSG_ID_MMI_ABM_WIFI_DEINIT_CNF,
   MSG_ID_MMI_ABM_WIFI_CONNECT_CNF,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF,
   MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF,
   MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_IND,
   MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_IND,
   MSG_ID_MMI_ABM_WIFI_CONNECT_IND,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND,
   MSG_ID_MMI_ABM_WIFI_SET_PS_MODE_CNF,
   MSG_ID_MMI_ABM_WIFI_WPS_INFO_IND,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_START_CNF,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STOP_CNF,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGOUT_CNF,
   MSG_ID_MMI_ABM_IPADDR_UPDATE_IND,
   MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND,
   MSG_ID_MMI_ABM_IPADDR_CHANGE_CNF,
   MSG_ID_MMI_ABM_BEARER_INIT_IND,
   MSG_ID_MMI_ABM_BEARER_DEINIT_IND,
   MSG_ID_MMI_ABM_PROFILE_QUERY_IND,

   MSG_ID_MMI_ABM_NET_STATUS_IND,
   MSG_ID_MMI_ABM_SET_TX_PWR_CNF,

   #if 1
   MSG_ID_MMI_ABM_WIFI_SET_ROAMING_PARA_CNF,
   MSG_ID_MMI_ABM_WIFI_SET_SCAN_DWELL_TIME_CNF,
   MSG_ID_MMI_ABM_WIFI_SET_SCAN_DESIRED_SSID_LIST_CNF,
   MSG_ID_MMI_ABM_WIFI_SET_SNIFFER_MODE_CNF,
   MSG_ID_MMI_ABM_IOT_LISTENED_AP_INFO_IND,
   #endif
   
   /* Message from MMI */
   MSG_ID_MMI_ABM_WIFI_INIT_REQ,
   MSG_ID_MMI_ABM_WIFI_DEINIT_REQ,
   MSG_ID_MMI_ABM_WIFI_CONNECT_REQ,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_REQ,
   MSG_ID_MMI_ABM_WIFI_AP_LIST_REQ,
   MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ,
   MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_REJ,
   MSG_ID_MMI_ABM_WIFI_SET_PS_MODE_REQ,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_START_REQ,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STOP_REQ,
   MSG_ID_MMI_ABM_WIFI_PORTAL_LOGOUT_REQ,
   MSG_ID_MMI_ABM_IPADDR_CHANGE_REQ,
   MSG_ID_MMI_ABM_BEARER_INIT_RSP,
   MSG_ID_MMI_ABM_BEARER_DEINIT_RSP,
   MSG_ID_MMI_ABM_PROFILE_QUERY_RSP,
   MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ,
   MSG_ID_MMI_ABM_UPDATE_APP_INFO_REQ,

   MSG_ID_MMI_ABM_DISCONNECT_REQ,
   MSG_ID_MMI_ABM_GET_BEARER_INFO_REQ,
   MSG_ID_MMI_ABM_RESET_BEARER_INFO_REQ,
   MSG_ID_MMI_ABM_NWK_SRV_REQ,
   MSG_ID_MMI_ABM_BEARER_EVENT_CONNECT_REQ,

   MSG_ID_MMI_ABM_SHARE_BEARER_QUERY_REQ,
   MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_REQ,
   MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_REQ,

   MSG_ID_MMI_ABM_SET_TX_PWR_REQ,

   #if 1
   MSG_ID_MMI_ABM_WIFI_SET_ROAMING_PARA_REQ,
   MSG_ID_MMI_ABM_WIFI_SET_SCAN_DWELL_TIME_REQ,
   MSG_ID_MMI_ABM_WIFI_SET_SCAN_DESIRED_SSID_LIST_REQ,
   MSG_ID_MMI_ABM_WIFI_SET_SNIFFER_MODE_REQ,
   #endif
   
   /* Message to MMI CBM */
   //MSG_ID_MMI_ABM_ACTIVE_IND,
   MSG_ID_MMI_ABM_DISCONNECT_CNF,
   //MSG_ID_MMI_ABM_DEACTIVE_IND,
   MSG_ID_MMI_ABM_GET_BEARER_INFO_CNF,
   MSG_ID_MMI_ABM_RESET_BEARER_INFO_CNF,
   MSG_ID_MMI_ABM_BEARER_INFO_IND,
   //MSG_ID_MMI_ABM_ASK_ACCT_IND,
   //MSG_ID_MMI_ABM_ALLOW_ACTIVATE_GPRS_CSD_RSP,
   //MSG_ID_MMI_ABM_DISALLOW_ACTIVATE_GPRS_CSD_RSP,  
   MSG_ID_MMI_ABM_NWK_SRV_CNF,
   MSG_ID_MMI_ABM_BEARER_EVENT_CONNECT_CNF,

   MSG_ID_MMI_ABM_SHARE_BEARER_QUERY_CNF,
   MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_CNF,
   MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_CNF,

   MSG_ID_MMI_ABM_BEARER_CONNECT_RESULT_IND,

   /* DOM-NOT_FOR_SDK-END */

   MSG_ID_APP_CBM_BEARER_EVENT_NOTIFY_IND, /* This primitive is for CBM to report the bearer event to the application 
                                    * (include MMI).
                                    * a. bearer event will be reported to the application when always ask or bearer fallback event occurs.
                                    * b. if application didn't receive this event through MMI callback, it needs to specified which module it
                                    *     wants to receive this event.
                                    * c. after application received the event, it needs to send back the response to ABM.
                                    *     The TRUE response is to receive the bearer event.
                                    *     The FALSE reponse is to reject the bearer event.
                                    * d. after application received the bearer event notification and it didn't reject the event, it needs to communicate 
                                    *     with its MMI to call always ask or bearer fallback CUI to display the UI to ask users.
                                    * e. if application has recevied the event and finds that it cannot display the UI, 
                                    *     it needs to call "cbm_abort_app_bearer_event" to abort the event.
                                    *
                                    * Direction: CBM -> APP
                                    * Local parameter: app_cbm_bearer_event_notify_ind_struct
                                    * Peer buffer: None
                                    */
   MSG_ID_APP_CBM_BEARER_EVENT_NOTIFY_RSP, /* This primitive is for application to send back the respons after it 
                                    * receive the bearer event notification indication. (include MMI).
                                    * a. after application received the event, it needs to send back the response to ABM.
                                    *     The TRUE response is to receive the bearer event.
                                    *     The FALSE reponse is to reject the bearer event.
                                    *
                                    * Direction: APP -> CBM
                                    * Local parameter: app_cbm_bearer_event_notify_rsp_struct
                                    * Peer buffer: None
                                    */
   MSG_ID_APP_CBM_BEARER_INFO_IND, /* This primitive is for CBM to report the bearer status to the application 
                                    * (include MMI).
                                    * a. BEARER_INFO_IND will be reported to the module which activates the bearer.
                                    * b. CBM_BEARER_FAILED indicates that the data link layer is disconnected, 
                                    *    we are out of coverage.
                                    * c. CBM_DHCP_ERROR indicates that the data link layer is connected but get 
                                    *    IP failed, VoIP should retry login after timeout
                                    * d. CBM_CANCEL_ACT_BEARER  indicates that the activation operation is 
                                    *    canceled by user. Thus, when AP receives this error message, 
                                    *    it has not to display any error message. This error cause is defined 
                                    *    for the function of "always-ask".  
                                    * e. If the bearer state is "CBM_BEARER_NEED_FALLBACK", it indicates that 
                                    *    the situation of bearer fallback occurs. Application needs to stop 
                                    *    the timer if it has started one.  If application doesn't stop the timer 
                                    *    based on this state, it has to start the timer after the bearer is in 
                                    *    activated state.
                                    * f. If application doesn't start the timer when it receive the 
                                    *    APP_CBM_BEARER_INFO_IND(ACTIVATING), it has to start the timer when 
                                    *    the bearer is activated. That is to say, it can start the timer when 
                                    *    it receives the APP_CBM_BEARER_INFO_IND(ACTIVATED).
                                    *
                                    * Direction: CBM -> APP
                                    * Local parameter: app_cbm_bearer_info_ind_struct
                                    * Peer buffer: None
                                    */
   MSG_ID_APP_CBM_NVRAM_OPERATION_IND, /* This primitive is for the application to get the NVRAM operation result.
                                          Once application has changed the NVRAM profile setting, the result
                                          can be obtained through this message if the operation mode it chooses
                                          is non-blocking.

                                          Direction: CBM -> APP
                                          Local parameter: app_cbm_nvram_operation_ind_struct
                                          Peer buffer: None
                                        */
   /* DOM-NOT_FOR_SDK-BEGIN */

   //MSG_ID_MMI_ABM_WIFI_AP_LIST_QUERY_RSP,
   //MSG_ID_MMI_ABM_WIFI_AP_LIST_QUERY_IND,
   MSG_ID_MMI_ABM_BEARER_DISCONNECT_REQ,
   MSG_ID_MMI_ABM_BEARER_DISCONNECT_CNF,
   MSG_ID_MMI_ABM_BEARER_STATUS_IND,
   MSG_ID_ABM_CODE_END = MSG_ID_MMI_ABM_BEARER_STATUS_IND,
	/*--------------- ABM_MSG_CODE_END--------------------*/
   /* DOM-NOT_FOR_SDK-END */
   
#ifdef __BUILD_DOM__
   } sap_app_cbm_enum;
#endif


