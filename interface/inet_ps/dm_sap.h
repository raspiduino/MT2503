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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *    syncml_sap.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*------------------------MSG_ID_DM_CODE_BEGIN ---------------*/

#ifdef __BUILD_DOM__
/***********************************
* <GROUP  Messages>        
*
* dm sap primitive
 ********************************/
typedef enum {
#endif

MSG_ID_DM_GET_ACC_REQ = MSG_ID_DM_CODE_BEGIN,/*this pimitive used by DMPS to get dm data account

                                                              Direction:MOD_DM->MOD_MMI
                                                                                                    Local parameter: dm_get_acc_req_struct
                                                              Peer buffer: null
                                                            */ 
MSG_ID_DM_GET_ACC_CNF,/*this pimitive used by DMUI to send dm data account

                                                          Direction:MOD_MMI->MOD_DM
                                                          Local parameter: dm_get_acc_cnf_struct
                                                          Peer buffer: null
                                                        */ 

MSG_ID_DM_PS_INIT_FINISH_IND,/*this pimitive used by DMPS to identify DMPS can received message

                                                          Direction:MOD_DM->MOD_MMI
                                                          Local parameter: null
                                                          Peer buffer: null
                                                        */ 

MSG_ID_DM_SRV_INIT_FINISH_IND,/*this pimitive used by DMUI to identify DM PS can send message to DM UI

                                                              Direction:MOD_MMI->MOD_DM
                                                              Local parameter: null
                                                              Peer buffer: null
                                                            */ 

MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND, /*this pimitive used to inform DMUI that a notify is received abd start to initiat a session

                                                                                           Direction:MOD_DM->MOD_MMI
                                                                                           Local parameter: dm_ui_mode_struct
                                                                                           Peer buffer: null
                                                                                         */ 
MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES,  /*this pimitive is used by DM MMI send the result of initial

                                                                                    Direction:MOD_MMI->MOD_DM
                                                                                    Local parameter: dm_ui_struct
                                                                                    Peer buffer: null
                                                                                  */ 
MSG_ID_DM_GET_BOOTSTRAP_USERPIN_REQ_IND,  /*this pimitive used to send request of user pinto DM MMI

                                                                                        Direction:MOD_DM->MOD_MMI
                                                                                        Local parameter: null
                                                                                        Peer buffer: null
                                                                                      */ 
MSG_ID_DM_GET_BOOTSTRAP_USERPIN_RES,  /*this pimitive is a reponse about user pin 

                                                                                Direction:MOD_MMI->MOD_DM
                                                                                Local parameter: dm_get_bootstrap_userpin_rsp_struct
                                                                                Peer buffer: null
                                                                              */ 
MSG_ID_DM_UPDATE_REQ_IND,  /*this pimitive used to send a update request to DM MMI

                                                         Direction:MOD_DM->MOD_MMI
                                                         Local parameter: dm_dl_ind_struct
                                                         Peer buffer: null
                                                       */ 
MSG_ID_DM_UPDATE_RES,  /*this pimitive is a reponse to DM by MMI

                                                 Direction:MOD_MMI->MOD_DM
                                                 Local parameter: dm_dd_rsp_struct
                                                 Peer buffer: null
                                               */ 
MSG_ID_DM_ALERT_REQ_IND,  /*this pimitive used to send a alert request to DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_alert_struct
                                                        Peer buffer: null
                                                      */ 
MSG_ID_DM_ALERT_RES,  /*this pimitive is a reponse to DM by MMI

                                            Direction:MOD_MMI->MOD_DM
                                            Local parameter: dm_alert_rsp_struct
                                            Peer buffer: null
                                          */ 
MSG_ID_DM_RESET_IND,    /*this pimitive used to send a reset request to DM MMI

                                                Direction:MOD_DM->MOD_MMI
                                                Local parameter: null
                                                Peer buffer: null
                                              */ 
MSG_ID_DM_DL_PROGRESS_IND,  /*This pimitive is DM MMI use bu itself

                                                          Direction:MOD_MMI->MOD_MMI
                                                          Local parameter: dm_dl_progress_struct
                                                          Peer buffer: null
                                                        */ 
MSG_ID_DM_SESSION_START_IND,    /*this pimitive used to send a start session information to DM MMI

                                                                Direction:MOD_DM->MOD_MMI
                                                                Local parameter: dm_session_progress_struct
                                                                Peer buffer: null
                                                              */ 
MSG_ID_DM_SESSION_FINISH_IND,   /*this pimitive used to send a session finish information to DM MMI

                                                                Direction:MOD_DM->MOD_MMI
                                                                Local parameter: dm_session_progress_struct
                                                                Peer buffer: null
                                                              */ 
MSG_ID_DM_INTERNAL,  /*This pimitive is internal of DM

                                           Direction:MOD_DM->MOD_MMI
                                           Local parameter: ike_tcpip_read_req_struct
                                           Peer buffer: null
                                         */ 
MSG_ID_DM_NETWORK_SERVICE_AVAILABLE_IND,    /*This pimitive is internal of DM

                                                                                         Direction:MOD_DM->MOD_DM
                                                                                         Local parameter: null
                                                                                         Peer buffer: null
                                                                                       */ 
MSG_ID_DM_NETWORK_SERVICE_NOT_AVAILABLE_IND,   /*This pimitive is internal of DM

                                                                                                 Direction:MOD_DM->MOD_DM
                                                                                                 Local parameter: null
                                                                                                 Peer buffer: null
                                                                                               */ 
MSG_ID_DM_PUSH_IND,  /*this pimitive used by DM MMI that a push comming

                                           Direction:MOD_MMI->MOD_MMI
                                           Local parameter: dm_push_struct
                                           Peer buffer: null
                                         */ 
MSG_ID_DM_CANCEL_REQ,  /*This pimitive used to cancel DM session

                                                 Direction:MOD_MMI->MOD_DM
                                                 Local parameter: null
                                                 Peer buffer: null
                                               */ 
MSG_ID_DM_START_DL_REQ_IND,  /*this pimitive used to send a start download request to DM MMI

                                                           Direction:MOD_DM->MOD_MMI
                                                           Local parameter: dm_start_dl_res_ind_struct
                                                           Peer buffer: null
                                                         */ 
MSG_ID_DM_DL_REPORT,  /*this pimitive used byDM MMI to send download information to DM

                                            Direction:MOD_MMI->MOD_DM
                                            Local parameter: dm_dl_report_struct
                                            Peer buffer: null
                                          */ 
MSG_ID_DM_PS_STATUS_IND,    /*This pimitive is used to send DM satus to DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_ps_status_ind_struct
                                                        Peer buffer: null
                                                      */ 
MSG_ID_MMI_DMUI_LAWMO_CMD_IND,  /*DM UI initernal used. send lawmo request to other modul

                                                        Direction:MOD_MMI->MOD_MMI
                                                     Local parameter: 
                                                        Peer buffer: null
                                                    */ 

MSG_ID_MMI_DMUI_LAWMO_CMD_RSP,  /*DM UI initernal used. send lawmo request to other modul

                                                        Direction:MOD_MMI->MOD_MMI
                                                     Local parameter: 
                                                        Peer buffer: null
                                                   */ 

MSG_ID_DM_LAWMO_REQ,    /*DM UI initernal used. send lawmo request to DM UI

                                                        Direction:MOD_PS->MOD_MMI
                                                        Local parameter: dm_lawmo_req_struct
                                                        Peer buffer: null
                                                          */ 

MSG_ID_DM_LAWMO_RSP,    /*DM UI initernal used. send lawmo request to DM PS

                                                            Direction:MOD_MMI->MOD_PS
                                                            Local parameter: dm_lawmo_result_struct
                                                            Peer buffer: null
                                                          */ 

MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND,    /*This pimitive is used to send SCOMO install to DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_scomo_install_by_server_ind_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF,    /*This pimitive is used to send SCOMO install confirm to DM PS

                                                        Direction:MOD_MMI->MOD_DM
                                                        Local parameter: dm_scomo_install_by_server_cnf_struct
                                                        Peer buffer: null
                                                      */                                                       

MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND,    /*This pimitive is used to send DM remove DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_scomo_remove_by_server_ind_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF,    /*This pimitive is used to send SCOMO remove confirm to DM PS

                                                        Direction:MOD_MMI->MOD_DM
                                                        Local parameter: dm_scomo_remove_by_server_cnf_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_REMOVE_BY_USER_REQ,    /*This pimitive is used to send delete request to DM PS

                                                        Direction:MOD_MMI-> MOD_DM
                                                        Local parameter: dm_scomo_remove_by_user_req_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_REMOVE_BY_USER_RSP,    /*This pimitive is used to send DM response to DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_scomo_remove_by_user_rsp_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_INSTALL_BY_USER_REQ,    /*This pimitive is used to send setup request to DM PS

                                                        Direction:MOD_MMI->MOD_DM
                                                        Local parameter: dm_scomo_install_by_user_req_struct
                                                        Peer buffer: null
                                                      */ 

MSG_ID_DM_SCOMO_INSTALL_BY_USER_RSP,    /*This pimitive is used to send DM response to DM MMI

                                                        Direction:MOD_DM->MOD_MMI
                                                        Local parameter: dm_scomo_install_by_user_rsp_struct
                                                        Peer buffer: null
                                                      */ 
/* DOM-NOT_FOR_SDK-END */ 

    MSG_ID_DM_NODE_OP_READ_REQ,    /*This pimitive is used by self regist, to send request to DM PS

                                                        Direction:MOD_MMI->MOD_PS
                                                        Local parameter: dm_node_op_read_req_struct
                                                        Peer buffer: null
                                                      */ 
                                                      
    MSG_ID_DM_NODE_OP_UPDATE_REQ,    /*This pimitive is used by DM PS, send result to DM MMI

                                                        Direction:MOD_PS->MOD_MMI
                                                        Local parameter: dm_node_op_read_rsp_struct
                                                        Peer buffer: null
                                                      */ 
                                                      
    MSG_ID_DM_NODE_OP_READ_RSP,/*This pimitive is used by DM PS, to send update result to DM MMI

                                                        Direction:MOD_PS->MOD_MMI
                                                        Local parameter: dm_node_op_read_rsp_struct
                                                        Peer buffer: null
                                                      */ 
                                                      
    MSG_ID_DM_NODE_OP_UPDATE_RSP,    /*This pimitive is used by DM PS, to send update result to DM MMI

                                                        Direction:MOD_PS->MOD_MMI
                                                        Local parameter: dm_node_op_update_rsp_struct
                                                        Peer buffer: null
                                                      */ 
    MSG_ID_DM_USER_INIT_FOTA_REQ,
    MSG_ID_DM_USER_INIT_FOTA_RSP,
#ifdef __BUILD_DOM__
} dm_sap_enum;
#endif

/*------------------------MSG_ID_DM_CODE_END-- ---------------*/
