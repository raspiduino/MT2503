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
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  nfc_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  NFC SAP
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
MSG_ID_NFC_DEFERRED_CALL_REQ = MSG_ID_NFC_MSG_CODE_BEGIN,
MSG_ID_NFC_LIB_INIT,
MSG_ID_NFC_LIB_DEINIT,
MSG_ID_NFC_LIB_INIT_REQ,   // for MMI NFC on/off
MSG_ID_NFC_LIB_INIT_RSP,   // for MMI NFC on/off
MSG_ID_NFC_LIB_DEINIT_REQ, // for MMI NFC on/off
MSG_ID_NFC_LIB_DEINIT_RSP, // for MMI NFC on/off
MSG_ID_NFC_TEST_SUITE_REQ, // from inject msg
MSG_ID_NFC_TEST_SUITE_MSG, // from NOD_NFC
MSG_ID_NFC_TEST_REQ,
MSG_ID_NFC_TEST_RSP,
MSG_ID_NFC_LIB_MMI_EVENT_NOTIFY, // for MMI Event Notificaiton

/* App -> NFC Service */
MSG_ID_NFC_NTF_INITIAL_REQ,
MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_REQ, 
MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_REQ,
MSG_ID_NFC_REMOTE_DEV_CONNECT_REQ,
MSG_ID_NFC_REMOTE_DEV_DISCONNECT_REQ,
MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_REQ,
MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ,
MSG_ID_NFC_NDEF_CHECK_NDEF_REQ,
MSG_ID_NFC_NDEF_WRITE_REQ,
MSG_ID_NFC_NDEF_READ_REQ,
MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_REQ,
MSG_ID_NFC_SE_NTF_REGISTER_REQ,
MSG_ID_NFC_SE_NTF_UNREGISTER_REQ,
MSG_ID_NFC_SE_GET_SECURE_ELEMENT_LIST_REQ,
MSG_ID_NFC_SE_SET_MODE_REQ,

/* NFC Service -> App for RSP*/
MSG_ID_NFC_NTF_INITIAL_RSP,
MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_RSP,
MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_RSP,
MSG_ID_NFC_REMOTE_DEV_CONNECT_RSP,
MSG_ID_NFC_REMOTE_DEV_DISCONNECT_RSP,
MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_RSP,
MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_RSP,
MSG_ID_NFC_NDEF_CHECK_NDEF_RSP,
MSG_ID_NFC_NDEF_WRITE_RSP,
MSG_ID_NFC_NDEF_READ_RSP,
MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_RSP,
MSG_ID_NFC_SE_NTF_REGISTER_RSP,
MSG_ID_NFC_SE_NTF_UNREGISTER_RSP,
MSG_ID_NFC_SE_GET_SECURE_ELEMENT_LIST_RSP,
MSG_ID_NFC_SE_SET_MODE_RSP,
MSG_ID_NFC_CHECK_OWNER_RSP,


/* NFC Service -> App for CB */
MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_CB_IND,
MSG_ID_NFC_REMOTE_DEV_CONNECT_CB_IND,
MSG_ID_NFC_REMOTE_DEV_DISCONNECT_CB_IND,
MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_CB_IND,
MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_CB_IND,
MSG_ID_NFC_NDEF_CHECK_NDEF_CB_IND,
MSG_ID_NFC_NDEF_WRITE_CB_IND,
MSG_ID_NFC_NDEF_READ_CB_IND,
MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_CB_IND,
MSG_ID_NFC_SE_NTF_REGISTER_CB_IND,
MSG_ID_NFC_SE_SET_MODE_CB_IND,  

/* NFC Lib -> NFC Service */
MSG_ID_NFC_DEFERRED_CALL_CB_IND,

/*others*/
MSG_ID_NFC_PUSH_INFO_REGISTER,
MSG_ID_NFC_PUSH_REGISTRY_NOTIFICATION,
