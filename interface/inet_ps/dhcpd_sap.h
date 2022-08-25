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
 *   dhcpd_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DHCP related message identity definition
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

/*---------------DHCP_MSG_CODE_BEGIN---------------------------*/
#ifdef __BUILD_DOM__
/*********************************************************************
 * <GROUP Messages> 
 *
 * Messages of DHCPD SAP 
 *********************************************************************/
typedef enum {
#endif
    /* ABM sends this message to DHCP to ask DHCP client for requesting a set
       of network configuration parameters from any DHCP server in the attached
       network.

       The MAC address have to be passed to DHCP through mac_addr for setting
       the chaddr field in the DHCP request messages. By default, the
       parameters listed in abm_dhcp_get_ip_cnf_struct will be returned.
       If additional parameters are needed, the requested parameters can be
       passed to DHCP through parameters in this message. To request the
       additional parameters, each requested parameter is filled in the
       parameters array according to the option code specified in RFC 2132.
       The list ends by an entry of 0x00.

       Note that the handler of the additional requested options is not
       implemented in the DHCP task and the abm_dhcp_get_ip_cnf_struct,
       to request additional parameters, the implementers of ABM and DHCP
       should negotiate first to handle the new option properly.

       Direction: ABM -> DHCP
       Local parameter: abm_dhcpd_active_ind_struct
       Peer buffer: None 
     */
    MSG_ID_ABM_DHCPD_ACTIVE_IND = MSG_ID_DHCPD_CODE_BEGIN,


    /* This message returns the result of the process of requesting network
       configurations from the DHCP server. A KAL_TRUE value in the result
       field in the returned message indicates that the request operation is
       finished successfully and the configuration parameters are stored in
       the fields. Otherwise, KAL_FALSE is set in the result field indicates
       that the request process failed. Additional message from DHCP server
       may be returned in the message field.

       Direction: DHCP -> ABM
       Local parameter: abm_dhcps_active_res_struct
       Peer buffer: None 
     */
    MSG_ID_ABM_DHCPD_ACTIVE_RES,


    /* DHCPD sends the message when it doesn't block during receiving the data.
       
       Direction: DHCP -> DHCP
       Local parameter: None
       Peer buffer: None 
     */
    MSG_ID_DHCPD_RECV_DATA_IND,


    /* This message is sent from ABM to DHCP in two different conditions.
       1. When DHCP is in the BOUNDED states (BOUND, RENEWING, REBINDING),
          this message is used to send a DHCPRELEASE message to release the
          allocated IP address.

       2. ABM can also use this message to abort the address allocation
          process, when the user intend to abort the address allocation
          process. When DHCP received this message in UNBOUNDED states
          (INIT-REBOOT, REBOOTING, INIT, SELECTING, and REQUESTING),
          DHCP will reset all variables in the task and go back to INIT stae.

       Direction: ABM -> DHCP
       Local parameter: abm_dhcpd_deactive_ind_struct
       Peer buffer: None 
    */
    MSG_ID_ABM_DHCPD_DEACTIVE_IND,
       

    /* After a DHCPRELEASE message is sent, this confirmation message will be
       returned from DHCP task to ABM task. No response from the server for
       the DHCPRELEASE message, therefore, no error could be happened.
       ABM has to handle the condition that a MSG_ID_ABM_DHCP_GET_IP_CNF
       message is queued when the ABM_DHCP_RELEASE_REQ is sent. In this case,
       an MSG_ID_ABM_DHCP_GET_IP_CNF message followed by an
       MSG_ID_ABM_DHCP_RELEASE_CNF message will arrive ABM's external queue.

       Direction: DHCP -> ABM
       Local parameter: abm_dhcpd_deactive_ind_struct
       Peer buffer: None 
     */
    MSG_ID_ABM_DHCPD_DEACTIVE_RES,

   
    MSG_ID_DHCPD_CODE_END = MSG_ID_ABM_DHCPD_DEACTIVE_RES,

#ifdef __BUILD_DOM__
} sap_dhcps_enum;
#endif /* __BUILD_DOM__ */
/*---------------DHCP_MSG_CODE_END---------------------------*/

