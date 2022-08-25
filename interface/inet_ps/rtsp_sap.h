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
 *  permission of MediaTek Inc. (C) 2004
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   rtsp_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   rtsp related message identity definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*---------------RTSP_MSG_CODE_BEGIN---------------------------*/
#ifdef _BUILD_DOM_
/***************************************************************
* <GROUP Messages>
*
* RTSP sap primitive
***************************************************************/
typedef enum{
#endif
    MSG_ID_RTSP_SET_CHANNEL_REQ = RTSP_MSG_CODE_BEGIN,  /* Configure a dedicated channel for RTSP requests

                                                        Direction: MED -> RTSP
                                                        Local parameter: rtsp_set_channel_req_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_SET_CHANNEL_RSP,                        /* Response to the channel configuration request
    
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_set_channel_rsp_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_REMOVE_CHANNEL_REQ,                     /* Remove a configured channel identified by channel ID
    
                                                        Direction: MED -> RTSP
                                                        Local parameter: rtsp_remove_channel_req_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_REMOVE_CHANNEL_RSP,                     /* Response to the channel remove request
    
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_remove_channel_rsp_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_REQUEST_REQ,                            /* Send a RTSP request with URL, RTSP method and RTSP method as parameters
    
                                                        Direction: MED -> RTSP
                                                        Local parameter: rtsp_request_req_struct
                                                        Peer buffer: rtsp_request_req_peer_struct
                                                        */

    MSG_ID_RTSP_REQUEST_RSP,                            /* Response to the RTSP request
    
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_request_rsp_struct
                                                        Peer buffer: rtsp_request_rsp_peer_struct
                                                        */

    MSG_ID_RTSP_DISCONNECT_IND,                         /* Disconnect indication if there's socket or network error from lower layer
    
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_disconnect_ind_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_CHANNEL_INFO_IND,                       /* Disconnect indication if there's socket or network error from lower layer
    
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_channel_info_ind_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_NOTIFY_INTERLEAVED_DATA_IND,            /* Notify uplayer that there is interleaved binary data waiting for reading
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_notify_interleaved_data_ind_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_RECV_INTERLEAVED_DATA_IND,              /* Notify RTSP to receive interleaved binary data from socket
                                                        Direction: RTSP -> RTSP
                                                        Local parameter: rtsp_recv_interleaved_data_ind_struct
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSP_SEND_INTERLEAVED_DATA_REQ,              /* Notify uplayer that there is binary data waiting for reading
                                                        Direction: MED -> RTSP
                                                        Local parameter: rtsp_send_interleaved_data_req_struct
                                                        Peer buffer: peer_buff_struct
                                                        */

    MSG_ID_RTSP_SEND_INTERLEAVED_DATA_RSP,              /* Notify uplayer that there is binary data waiting for reading
                                                        Direction: RTSP -> MED
                                                        Local parameter: rtsp_send_rtcp_rsp_struct
                                                        Peer buffer: NULL
                                                        */
                       
    MSG_ID_RTSPD_START,         /* START RTSP SERVER
                                                        Direction: MMI -> RTSP
                                                        Local parameter: rtspd_lauch_param
                                                        Peer buffer: NULL
                                                        */

    MSG_ID_RTSPD_STOP,          /* STOP RTSP SERVER
                                                        Direction: MMI -> RTSP
                                                        Local parameter: NULL
                                                        Peer buffer: NULL
                                                        */


    MSG_ID_RTSP_CODE_END = MSG_ID_RTSP_SEND_INTERLEAVED_DATA_RSP,  /* End of the RTSP MSG definition */
#ifdef _BUILD_DOM_
} rtsp_sap_enum;
#endif
/*---------------RTSP_MSG_CODE_END---------------------------*/
