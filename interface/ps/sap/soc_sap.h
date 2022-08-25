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

/*------------------------SOC_MSG_CODE_BEGIN ---------------*/
#ifdef __BUILD_DOM__
     /*****************************************************************************
      * <GROUP  Messages>        
      *
      * socket sap primitive
      ******************************************************************************/
    typedef enum {
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* MSGS from TCPIP */
    MSG_ID_SOC_TCPIP_ACCEPT_IND = MSG_ID_SOC_CODE_BEGIN,
    MSG_ID_SOC_TCPIP_RECEIVE_IND,
    MSG_ID_SOC_TCPIP_ATTACH_CNF,
    MSG_ID_SOC_TCPIP_DETACH_CNF,
    MSG_ID_SOC_TCPIP_LISTEN_CNF,
    MSG_ID_SOC_TCPIP_BIND_CNF,
    MSG_ID_SOC_TCPIP_CONNECT_CNF,
    MSG_ID_SOC_TCPIP_DISCONNECT_CNF,
    MSG_ID_SOC_TCPIP_ERRMSG_IND, 
    MSG_ID_SOC_TCPIP_MTU_UPDATE_IND,
    MSG_ID_SOC_TCPIP_CLOSE_IND,
    MSG_ID_SOC_TCPIP_OPTION_CNF,
    MSG_ID_SOC_TCPIP_SHUTDOWN_CNF,
    /* DOM-NOT_FOR_SDK-END */
   
    MSG_ID_APP_SOC_NOTIFY_IND, /* Notification to application for some events, 
                                  e.g., socket is readable, socket is connected, 
                                  etc. In case of TCP half-write close by peer, 
                                  event_type will be SOC_CLOSE and error_cause 
                                  will be SOC_CONNRESET. 
                                  P.S. if application wants to accept this primitive, 
                                  it should run in its own task instead of a task containing 
                                  multiple applications, such as MMI. However, if application 
                                  wants to run in the task of MMI and also wants to receive this primitive, 
                                  it should use the "framework multiple protocol event handler" (since 08B). 
                                  Otherwise, the primitive may be received by other applications running in 
                                  the same task as you.

                                  Direction: SOC -> APP
                                  Local parameter: app_soc_notify_ind_struct
                                  Peer buffer: None
                                */
    MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, /* Notification to application a domain name of a host.
                                  P.S. if application wants to accept this primitive, 
                                  it should run in its own task instead of a task containing 
                                  multiple applications, such as MMI. However, if application 
                                  wants to run in the task of MMI and also wants to receive this primitive, 
                                  it should use the "framework multiple protocol event handler" (since 08B). 
                                  Otherwise, the primitive may be received by other applications running in 
                                  the same task as you.
    
                                  Direction: SOC -> APP
                                  Local parameter: app_soc_get_host_by_name_ind_struct
                                  Peer buffer: None
                                */
    MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND, /* Notification to application a domain name of a host.
                                  P.S. if application wants to accept this primitive, 
                                  it should run in its own task instead of a task containing 
                                  multiple applications, such as MMI. However, if application 
                                  wants to run in the task of MMI and also wants to receive this primitive, 
                                  it should use the "framework multiple protocol event handler" (since 08B). 
                                  Otherwise, the primitive may be received by other applications running in 
                                  the same task as you.
    
                                  Direction: SOC -> APP
                                  Local parameter: app_soc_get_host_by_addr_ind_struct
                                  Peer buffer: None
                                */
    MSG_ID_APP_SOC_GET_HOST_BY_SRV_IND, /* Notification to application the result of DNS SRV RR query.
                                  P.S. if application wants to accept this primitive, 
                                  it should run in its own task instead of a task containing 
                                  multiple applications, such as MMI. However, if application 
                                  wants to run in the task of MMI and also wants to receive this primitive, 
                                  it should use the "framework multiple protocol event handler" (since 08B). 
                                  Otherwise, the primitive may be received by other applications running in 
                                  the same task as you.
    
                                  Direction: SOC -> APP
                                  Local parameter: app_soc_get_host_by_srv_ind_struct
                                  Peer buffer: None
                                */
    MSG_ID_APP_SOC_GET_HOST_BY_NAPTR_IND, /* Notification to application the result of DNS NAPTR RR query.
                                  P.S. if application wants to accept this primitive, 
                                  it should run in its own task instead of a task containing 
                                  multiple applications, such as MMI. However, if application 
                                  wants to run in the task of MMI and also wants to receive this primitive, 
                                  it should use the "framework multiple protocol event handler" (since 08B). 
                                  Otherwise, the primitive may be received by other applications running in 
                                  the same task as you.
    
                                  Direction: SOC -> APP
                                  Local parameter: app_soc_get_host_by_naptr_ind_struct
                                  Peer buffer: None
                                */
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* MSG from CBM */
    MSG_ID_APP_SOC_DEACTIVATE_REQ,  
    MSG_ID_APP_SOC_ACTIVATE_REQ,

    /* MSG FROM SMSAL */
    MSG_ID_SMSAL_SOC_REG_PORT_CNF, 
    MSG_ID_SMSAL_SOC_DATA_IND,

    /* MSG from FLC */
    MSG_ID_FLC_SOC_UL_SSPDU_RESUME,

    /* MSGS FROM ABM */   
    MSG_ID_SOC_ABM_ACTIVATE_CNF,
    MSG_ID_SOC_ABM_DEACTIVATE_CNF,
    MSG_ID_SOC_ABM_DEACTIVATE_IND,
    MSG_ID_SOC_ABM_IPADDR_UPDATE_IND, 
    MSG_ID_SOC_ABM_RESUME_QOS_CTX_CNF,
    
    /* Message sent from SSL applications for logging plain text,
     * SOC simply ignores it */
    MSG_ID_APP_SSL_DATA_INPUT_MSG,
    MSG_ID_APP_SSL_DATA_OUTPUT_MSG,
    
    /* Message for UT */
    MSG_ID_INET_APP_UT_FUNC_REQ,
    MSG_ID_INET_APP_UT_FUNC_CNF,
    MSG_ID_INET_APP_UT_NOTIFY_IND,
    MSG_ID_INET_APP_UT_TXDATA_REQ,

    MSG_ID_SOC_BRIDGE_TIMER_EXPIRY,
    
    MSG_ID_SOC_CODE_END = MSG_ID_INET_APP_UT_TXDATA_REQ,
    /* DOM-NOT_FOR_SDK-END */
#ifdef __BUILD_DOM__
    } sap_app_soc_enum;
#endif

/*------------------- SOC_MSG_CODE_END----------------------*/

