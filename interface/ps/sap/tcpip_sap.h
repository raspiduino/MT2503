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
 *   tcpip.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   tcpip related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __BUILD_DOM__
/***********************************
 * <GROUP  Messages>        
 *
 * tcpip sap primitive
 ***********************************/
typedef enum {
#endif
    
/*---------------TCPIP_MSG_CODE_BEGIN---------------------------*/
    MSG_ID_SOC_TCPIP_BEARER_REQ = MSG_ID_TCPIP_CODE_BEGIN,
    MSG_ID_SOC_TCPIP_ATTACH_REQ, /* Notify TCPIP layer to create a protocol control block with proto_type and attached to socket (socket_id).

                                    Direction: SOC -> TCPIP
                                    Local parameter : soc_tcpip_attach_req_struct
                                    Peer buffer : NULL
                                  */
    MSG_ID_SOC_TCPIP_BIND_REQ,   /* Notify TCPIP layer to bind socket identification (socket_id) with the local address (so_addr).

                                    Direction: SOC -> TCPIP
                                    Local parameter : soc_tcpip_bind_req_struct
                                    Peer buffer : NULL
                                  */
    MSG_ID_SOC_TCPIP_CONNECT_REQ, /* Notify TCPIP layer the peer address (so_addr). If the sock_type is IPPROTO_TCP, the TCP will set up 
                                     connection with the peer.

                                     Direction: SOC -> TCPIP
                                     Local parameter : soc_tcpip_connect_req_struct
                                     Peer buffer : NULL
                                   */
    MSG_ID_SOC_TCPIP_DISCONNECT_REQ, /* Clear the peer address and release the mbuf in the ARP queue.

                                        Direction: SOC -> TCPIP
                                        Local parameter : soc_tcpip_disconnect_req_struct
                                        Peer buffer : NULL
                                     */
    MSG_ID_SOC_TCPIP_LISTEN_REQ,  /* The message is used to notify TCPIP layer the listening socket identification, and maximum accepted 
                                     connection number (max_socket_no).

                                     Direction: SOC -> TCPIP
                                     Local parameter : soc_tcpip_listen_req_struct
                                     Peer buffer : NULL
                                   */
    MSG_ID_SOC_TCPIP_ACCEPT_RES,  /* Notify TCPIP layer the newly created socket identification (o_socket_id) and original listening socket 
                                     identification (n_socket_id) and accept the new connection. 

                                     Direction: SOC -> TCPIP
                                     Local parameter : soc_tcpip_accept_res_struct
                                     Peer buffer : NULL
                                   */
    MSG_ID_SOC_TCPIP_SEND_REQ,  /* Notify TCPIP the socket identification (socket_id), destination socket address (so_addr) and application 
                                   flag (flags). The TCPIP layer will send packet to the destination address.

                                   Direction: SOC -> TCPIP
                                   Local parameter : soc_tcpip_send_req_struct
                                   Peer buffer : peer_buff_struct
                                 */
    MSG_ID_SOC_TCPIP_DETACH_REQ, /* Close the socket and free the pcb block and resource.

                                    Direction: SOC -> TCPIP
                                    Local parameter : soc_tcpip_detach_req_struct
                                    Peer buffer : NULL
                                  */
    MSG_ID_SOC_TCPIP_SHUTDOWN_REQ, /* Notify the TCPIP to change the state that it can't receive and send data again.

                                      Direction: SOC -> TCPIP
                                      Local parameter : soc_tcpip_shutdown_req_struct
                                      Peer buffer : NULL
                                    */
    MSG_ID_SOC_TCPIP_SRPDU_RELEASE_RES, /* The socket uses the message to tell TCPIP that it had received some data 
                                           and how many free bytes space are there in the buffer.

                                           Direction: SOC -> TCPIP
                                           Local parameter : soc_tcpip_srpdu_release_res_struct
                                           Peer buffer : NULL
                                         */
    MSG_ID_SOC_TCPIP_OPTION_REQ,   /* Set or get the TCPIP option according to the is_set field.

                                      Direction: SOC -> TCPIP
                                      Local parameter : soc_tcpip_option_req_struct
                                      Peer buffer : NULL
                                    */
    MSG_ID_TCPIP_TCM_DATA_IND, /* When TCM receives downlink data packets from SNDCP, it uses 
                                  this message to send downlink data to TCPIP module. The data is 
                                  carried in peer_buff_ptr.

                                  Direction: TCM -> TCPIP
                                  Local parameter : tcpip_tcm_data_ind_struct
                                  Peer buffer : peer_buff_struct
                                */
    MSG_ID_TCPIP_PPP_DATA_IND, /* When PPP receives downlink data packets from L2R/TDT, it uses this message to send downlink data to TCPIP module. 
                                  The data is carried in peer_buff_ptr. The peer_buff header should be four byte alignment.

                                  Direction: PPP -> TCPIP
                                  Local parameter : NULL
                                  Peer buffer : peer_buff_struct
                                */
    MSG_ID_SOC_TCPIP_SET_ACCT_REQ, /* Set network id

                                      Direction: SOC -> TCPIP
                                      Local parameter : soc_tcpip_set_acct_req_struct
                                      Peer buffer : NULL
                                    */
    MSG_ID_SOC_TCPIP_BEARER_CTX_REQ, /* If the is_activated field is TRUE, the message tells the TCPIP layer the bearer information including the 
                                        maximum transmission unit (MTU), IP address, net mask, gate way and hardware address. Otherwise the message 
                                        deactivates the bearer.

                                        Direction: SOC -> TCPIP
                                        Local parameter : soc_tcpip_bearer_ctx_req_struct
                                        Peer buffer : NULL
                                      */
    
    MSG_ID_DHCP_TCPIP_ARP_PROBE_REQ, /* Send ARP request, ARP probes for duplicate IP address in the network.

                                        Direction: DHCP -> TCPIP
                                        Local parameter : dhcp_tcpip_arp_probe_req_struct
                                        Peer buffer : NULL
                                      */
    MSG_ID_DHCP_TCPIP_ARP_PROBE_CNF, /* Confirm the arp probe

                                        Direction: TCPIP -> DHCP
                                        Local parameter : dhcp_tcpip_arp_probe_cnf_struct
                                        Peer buffer : NULL
                                      */
    MSG_ID_DHCP_TCPIP_ARP_QUERY_REQ, /* ARP queries for duplicate IP address in the network.

                                        Direction: DHCP -> TCPIP
                                        Local parameter : dhcp_tcpip_arp_query_req_struct
                                        Peer buffer : NULL
                                      */
    MSG_ID_DHCP_TCPIP_ARP_QUERY_CNF, /* Confirm arp query

                                        Direction: TCPIP -> DHCP
                                        Local parameter : dhcp_tcpip_arp_query_cnf_struct
                                        Peer buffer : NULL
                                      */
    MSG_ID_DHCP_TCPIP_GW_ARP_PROBE_REQ, /* ARP probes for gateway address in the network.

                                           Direction: DHCP -> TCPIP
                                           Local parameter : dhcp_tcpip_gw_arp_probe_req_struct
                                           Peer buffer : NULL
                                         */
    MSG_ID_DHCP_TCPIP_GW_ARP_PROBE_CNF, /* Confirm gateway probe

                                           Direction: TCPIP -> DHCP
                                           Local parameter : dhcp_tcpip_gw_arp_probe_cnf_struct
                                           Peer buffer : NULL
                                         */


    MSG_ID_ABM_TCPIP_GET_BEARER_INFO_REQ, /* Get bearer information 

                                             Direction: ABM -> TCPIP
                                             Local parameter : abm_tcpip_get_bearer_info_req_struct
                                             Peer buffer : NULL
                                           */
    MSG_ID_ABM_TCPIP_GET_BEARER_INFO_CNF, /* Confirm the bearer information 

                                             Direction: TCPIP -> ABM
                                             Local parameter : abm_tcpip_get_bearer_info_cnf_struct
                                             Peer buffer : NULL
                                           */
    MSG_ID_ABM_TCPIP_BEARER_REQ, /* Set the bearer

                                    Direction: ABM -> TCPIP
                                    Local parameter : abm_tcpip_bearer_req_struct
                                    Peer buffer : NULL
                                  */
    
    MSG_ID_TCPIP_WNDRV_DATA_IND, /* WIFI data input notification

                                    Direction: WNDRV -> TCPIP
                                    Local parameter : tcpip_wndrv_data_ind_struct
                                    Peer buffer : peer_buff_struct
                                  */
    
    MSG_ID_TCPIP_LOOPBK_DATA_IND, /* Loop back input notification

                                     Direction: TCPIP -> TCPIP
                                     Local parameter : NULL
                                     Peer buffer : peer_buff_struct
                                   */
    
    MSG_ID_FLC_TCPIP_UL_TPDU_RESUME, /* flc_ul_tpdu, not used

                                        Direction: FLC -> TCPIP
                                        Local parameter : NULL
                                        Peer buffer : NULL
                                      */
    MSG_ID_SOC_TCPIP_DL_SRPDU_RESUME, /* flc_dl_srpdu, not used 

                                         Direction: SOC -> TCPIP
                                         Local parameter : NULL
                                         Peer buffer : NULL
                                       */
    MSG_ID_SOC_DL_SRPDU_HIGH_THRESHOLD_HIT, /* flc_srpdu_threshold, not used 

                                               Direction: SOC -> TCPIP
                                               Local parameter : NULL
                                               Peer buffer : NULL
                                             */
		
    MSG_ID_ABM_TCPIP_BEARER_INFO_IND, /* report the bearer data status to ABM 
    
                                         Direction: TCPIP -> ABM
                                         Local parameter : abm_tcpip_bearer_info_ind_struct
                                         Peer buffer : NULL
                                       */

		
    MSG_ID_ABM_TCPIP_RESET_BEARER_INFO_REQ, /* reset the bearer data 

                                               Direction: ABM -> TCPIP
                                               Local parameter : abm_tcpip_reset_bearer_info_req_struct
                                               Peer buffer : NULL
                                             */

    MSG_ID_ABM_TCPIP_RESET_BEARER_INFO_CNF, /*
                                               respond with the bearer data

                                               Direction: TCPIP -> ABM
                                               Local parameter : abm_tcpip_reset_bearer_info_cnf_struct
                                               Peer buffer : NULL
                                             */
                                             
    MSG_ID_TCPIP_CODE_END = MSG_ID_ABM_TCPIP_RESET_BEARER_INFO_CNF, 
/*---------------TCPIP_MSG_CODE_END---------------------------*/

#ifdef __BUILD_DOM__
} sap_tcpip_enum;
#endif
