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
 *   cardav_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   CardDAV related message identity definition
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

/*---------------CARDAV_MSG_CODE_BEGIN---------------------------*/
#ifdef __BUILD_DOM__
/*********************************************************************
 * <GROUP Messages> 
 *
 * Messages of CarDDAV SAP 
 *********************************************************************/
typedef enum {
#endif
    MSG_ID_VCRD_SET_CHANNEL_REQ = MSG_ID_CARDAV_CODE_BEGIN, 
                                         /* This request is to create one instance of CardDAV protocol 

                                            Direction: MMI -> CARDAV
                                            Local parameter: vcrd_set_channel_req_struct
                                            Peer buffer: None */

    MSG_ID_VCRD_SET_CHANNEL_RSP,        /* This is the response for the CARDAV protocol instance create.

                                            Direction: CARDAV -> MMI
                                            Local parameter: vcrd_set_channel_rsp_struct
                                            Peer buffer: None */
    MSG_ID_VCRD_REMOVE_CHANNEL_REQ,     /* This request is to remove one instance of CardDAV protocol 

                                            Direction: MMI -> CARDAV
                                            Local parameter: vcrd_remove_channel_req_struct
                                            Peer buffer: None */

    MSG_ID_VCRD_REMOVE_CHANNEL_RSP,     /* This is the response to remove CARDAV protocol instance.

                                            Direction: CARDAV -> MMI
                                            Local parameter: vcrd_set_channel_rsp_struct
                                            Peer buffer: None */

    MSG_ID_VCRD_METHOD_REQ,             /* This request is to request one resource on CardDAV server.

                                            Direction: MMI -> CARDAV
                                            Local parameter: vcrd_method_req_struct
                                            Peer buffer: vcrd_method_req_peer_struct
                                                         vcrd_method_prop_peer_struct */

    MSG_ID_VCRD_METHOD_RSP,             /* This is the response for the CARDAV method request.

                                            Direction: CARDAV -> MMI
                                            Local parameter: vcrd_method_rsp_struct
                                            Peer buffer: vcrd_method_rsp_peer_struct */

    MSG_ID_VCRD_ABORT_REQ,              /* This request is to abort previous request.

                                            Direction: MMI -> CARDAV
                                            Local parameter: vcrd_abort_req_struct
                                            Peer buffer: None */

    MSG_ID_VCRD_ABORT_RSP,              /* This is the response for the abort request.

                                            Direction: Direction: CARDAV -> MMI
                                            Local parameter: vcrd_abort_rsp_struct
                                            Peer buffer: None */

    MSG_ID_VCRD_PROGRESS_IND,           /* This is the indication for the applicaiton to know the progress.

                                            Direction: CARDAV -> MMI
                                            Local parameter: vcrd_progress_ind_struct
                                            Peer buffer: None */

   
    MSG_ID_CARDAV_CODE_END = MSG_ID_VCRD_PROGRESS_IND,

#ifdef __BUILD_DOM__
} sap_cardav_enum;
#endif /* __BUILD_DOM__ */
/*---------------CARDAV_MSG_CODE_END---------------------------*/

