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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_nfc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NFC test functions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
 * KAL header
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "app_ltlcom.h"
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_msg_nfc.h"
#include "ft_fnc_nfc.h"
#if defined(__NFC_SUPPORT__)
/*************************************************************************
 * NFC header
 *************************************************************************/
// YH: i don't know why.... but this is very stupid....
#define MTK_NFC_PLATFORM_MAUI
#include "mtk_nfc_ext_msg.h"
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
static kal_uint16 ft_nfc_token;
/**
 * Step2: Add mapping of META op code to NFC message ID (one-to-one)
 */
kal_uint32 ConvertMetaNfcOpToNfcMessageId(kal_uint32 type)
{
    kal_uint32 result = META_NFC_NOT_SUPPORT_MSG_ID;
    switch(type)
    {
        case FT_NFC_OP_INIT_QUERY:
        {
            result = MSG_ID_NFC_SETTING_REQ;
            break;
        }
        /***************************************
         * Test mode feature
         **************************************/
        case FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON:
        {
            result = MSG_ID_NFC_TX_ALWAYSON_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON_WITHOUT_ACK_TEST:
        {
            result = MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_CARD_MODE_TEST:
        {
            result = MSG_ID_NFC_CARD_MODE_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_READER_MODE_TEST:
        {
            result = MSG_ID_NFC_READER_MODE_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_P2P_MODE_TEST:
        {
            result = MSG_ID_NFC_P2P_MODE_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_SWP_SELF_TEST:
        {
            result = MSG_ID_NFC_SWP_SELF_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_ANTENNA_SELF_TEST:
        {
            result = MSG_ID_NFC_ANTENNA_SELF_TEST_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_UID_ACCESS:
        {
            result = MSG_ID_NFC_TAG_UID_RW_REQ;
            break;
        }
        case FT_NFC_OP_TEST_MODE_CARD_MODE_EMULATION_TEST:
        {
            result = MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ;
            break;
        }
        /***************************************
         * Software Protocol test command
         **************************************/
        case FT_NFC_OP_SW_PROTOCOL_NOTIFICATION:
        {
            result = MSG_ID_NFC_NOTIFICATION_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_SECURE_ELEMENT_SET:
        {
            result = MSG_ID_NFC_SE_SET_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_DISCOVERY:
        {
            result = MSG_ID_NFC_DISCOVERY_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_TAG_READ:
        {
            result = MSG_ID_NFC_TAG_READ_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_TAG_WRITE:
        {
            result = MSG_ID_NFC_TAG_WRITE_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_TAG_DISCONNECT:
        {
            result = MSG_ID_NFC_TAG_DISCONN_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_TAG_FORMAT_TO_NDEF:
        {
            result = MSG_ID_NFC_TAG_F2NDEF_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_TAG_RAW_COMMUNICATION:
        {
            result = MSG_ID_NFC_TAG_RAWCOM_REQ;
            break;
        }
        case FT_NFC_OP_SW_PROTOCOL_P2P_COMMUNICATION:
        {
            result = MSG_ID_NFC_P2P_COMMUNICATION_REQ;
            break;
        }
        /***************************************
         * RAW data command
         **************************************/
        case FT_NFC_OP_RAW_DATA_COMMUNICATION:
        {
            result = MSG_ID_NFC_RD_COMMUNICATION_REQ;
            break;
        }
        /***************************************
         * Add META op code and request/response
         * message id mapping below
         * Example:
         * case: FT_NFC_OP_XXXX:
         * {
         *     result = MSG_ID_NFC_XXXX_REQ;
         *     break;
         * }
         **************************************/
        default:
            break;
    }
    return result;
}
/**
 * Step3: Add mapping of NFC message ID to META op code (many-to-one)
 *   Request message ID  ==> op code
 *   Response message ID ==> op code
 */
kal_uint32 ConvertNfcMessageIdToMetaNfcOp(kal_uint32 type)
{
    kal_uint32 result = FT_NFC_OP_END;
    switch(type)
    {
        case MSG_ID_NFC_SETTING_REQ:
        case MSG_ID_NFC_SETTING_RSP:
        {
            result = FT_NFC_OP_INIT_QUERY;
            break;
        }
        /***************************************
         * Test mode feature
         **************************************/
        case MSG_ID_NFC_TX_ALWAYSON_TEST_REQ:
        case MSG_ID_NFC_TX_ALWAYSON_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON;
            break;
        }
        case MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ:
        case MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON_WITHOUT_ACK_TEST;
            break;
        }
        case MSG_ID_NFC_CARD_MODE_TEST_REQ:
        case MSG_ID_NFC_CARD_MODE_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_CARD_MODE_TEST;
            break;
        }
        case MSG_ID_NFC_READER_MODE_TEST_REQ:
        case MSG_ID_NFC_READER_MODE_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_READER_MODE_TEST;
            break;
        }
        case MSG_ID_NFC_P2P_MODE_TEST_REQ:
        case MSG_ID_NFC_P2P_MODE_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_P2P_MODE_TEST;
            break;
        }
        case MSG_ID_NFC_SWP_SELF_TEST_REQ:
        case MSG_ID_NFC_SWP_SELF_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_SWP_SELF_TEST;
            break;
        }
        case MSG_ID_NFC_ANTENNA_SELF_TEST_REQ:
        case MSG_ID_NFC_ANTENNA_SELF_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_ANTENNA_SELF_TEST;
            break;
        }
        case MSG_ID_NFC_TAG_UID_RW_REQ:
        case MSG_ID_NFC_TAG_UID_RW_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_UID_ACCESS;
            break;
        }
        case MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ:
        case MSG_ID_NFC_CARD_EMULATION_MODE_TEST_RSP:
        {
            result = FT_NFC_OP_TEST_MODE_CARD_MODE_EMULATION_TEST;
            break;
        }
        /***************************************
         * Software Protocol test command
         **************************************/
        case MSG_ID_NFC_NOTIFICATION_REQ:
        case MSG_ID_NFC_NOTIFICATION_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_NOTIFICATION;
            break;
        }
        case MSG_ID_NFC_SE_SET_REQ:
        case MSG_ID_NFC_SE_SET_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_SECURE_ELEMENT_SET;
            break;
        }
        case MSG_ID_NFC_DISCOVERY_REQ:
        case MSG_ID_NFC_DISCOVERY_RSP:
        case MSG_ID_NFC_TAG_DET_RSP:
        case MSG_ID_NFC_P2P_DET_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_DISCOVERY;
            break;
        }
        case MSG_ID_NFC_TAG_READ_REQ:
        case MSG_ID_NFC_TAG_READ_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_TAG_READ;
            break;
        }
        case MSG_ID_NFC_TAG_WRITE_REQ:
        case MSG_ID_NFC_TAG_WRITE_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_TAG_WRITE;
            break;
        }
        case MSG_ID_NFC_TAG_DISCONN_REQ:
        case MSG_ID_NFC_TAG_DISCONN_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_TAG_DISCONNECT;
            break;
        }
        case MSG_ID_NFC_TAG_F2NDEF_REQ:
        case MSG_ID_NFC_TAG_F2NDEF_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_TAG_FORMAT_TO_NDEF;
            break;
        }
        case MSG_ID_NFC_TAG_RAWCOM_REQ:
        case MSG_ID_NFC_TAG_RAWCOM_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_TAG_RAW_COMMUNICATION;
            break;
        }
        case MSG_ID_NFC_P2P_COMMUNICATION_REQ:
        case MSG_ID_NFC_P2P_COMMUNICATION_RSP:
        {
            result = FT_NFC_OP_SW_PROTOCOL_P2P_COMMUNICATION;
            break;
        }
        /***************************************
         * RAW data command
         **************************************/
        case MSG_ID_NFC_RD_COMMUNICATION_REQ:
        case MSG_ID_NFC_RD_COMMUNICATION_RSP:
        {
            result = FT_NFC_OP_RAW_DATA_COMMUNICATION;
            break;
        }
        /***************************************
         * Add request/response message id
         * and META op code mapping below
         * Example:
         * case: MSG_ID_NFC_XXXX_REQ:
         * case: MSG_ID_NFC_XXXX_RSP:
         * {
         *     result = FT_NFC_OP_XXXX;
         *     break;
         * }
         **************************************/
        default:
            break;
    }
    return result;
}
/**
 * @param query_op_code the sub-code in NFC test category to be queried
 * @return 0: FT_CNF_OK (supported), 1: FT_CNF_FAIL (not supported)
 */
kal_uint32 FT_NfcCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_bool NFC_task_and_FT_lib_not_match = KAL_FALSE;
    if(kal_get_task_by_index(INDX_NFC))
    {
        /**
         * sanity check to NFC tasks and FT library state:
         * The NFC task exists, but the library is not built with __NFC_SUPPORT__
         */
#if !defined(__NFC_SUPPORT__)
        ASSERT(NFC_task_and_FT_lib_not_match);
#endif // #if !defined(__NFC_SUPPORT__)
        if(ConvertMetaNfcOpToNfcMessageId(query_op_code) == META_NFC_NOT_SUPPORT_MSG_ID)
        {
            return FT_CNF_FAIL;
        }
        else
        {
            return FT_CNF_OK;
        }
    }
    else
    {
        /**
         * sanity check to NFC tasks and FT library state:
         * The NFC task does not exist, but the library is built with __NFC_SUPPORT__
         */
#if defined(__NFC_SUPPORT__)
        ASSERT(NFC_task_and_FT_lib_not_match);
#endif // #if defined(__NFC_SUPPORT__)
        return FT_CNF_FAIL;
    }
}
/**
 * unsupported op code handler
 */
void SendMetaNfcNotSupportedMessage(kal_uint16 token, kal_uint32 type)
{
    ilm_struct* metaResponseMessage;
    FT_NFC_CNF_HDR_T* metaResponseMessageHeader;
    metaResponseMessage               = FT_ALLOC_MSG( sizeof(FT_NFC_CNF_HDR_T) );
    metaResponseMessageHeader         = (FT_NFC_CNF_HDR_T *)metaResponseMessage->local_para_ptr;
    metaResponseMessageHeader->header.ft_msg_id = FT_NFC_CMD_CNF_ID;
    metaResponseMessageHeader->header.token     = token;
    metaResponseMessageHeader->type   = type;
    metaResponseMessageHeader->status = FT_CNF_NOT_SUPPORTED;
    metaResponseMessageHeader->length = 0;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaResponseMessage);
    return;
}
/**
 * @param metaMessage the input message from META tool for NFC test command processing
 */
void FT_NFC_Operation(ilm_struct* metaMessage)
{
    /* Tunnel header */
    FT_NFC_REQ_HDR_T* requestHeader = ((FT_NFC_REQ_HDR_T *)(metaMessage->local_para_ptr) );
    if(requestHeader)
    {
        ilm_struct *nfcMessage;
        kal_uint32 support_code = FT_NfcCheckFunctionSupported((kal_uint32) requestHeader->type );
        if(FT_CNF_FAIL == support_code)
        {
            SendMetaNfcNotSupportedMessage(requestHeader->header.token, requestHeader->type);
            return;
        }
        nfcMessage        = FT_ALLOC_MSG(requestHeader->length);
        ft_nfc_token      = requestHeader->header.token;
        if(nfcMessage)
        {
            /* Tunneling */
            nfc_msg_struct* nfcMessageHeader = (nfc_msg_struct*)nfcMessage->local_para_ptr;
            if(nfcMessageHeader)
            {
                kal_mem_cpy(nfcMessage->local_para_ptr, (void*)((unsigned int)metaMessage->local_para_ptr + sizeof(FT_NFC_REQ_HDR_T)), requestHeader->length);
                // Add flexibility that the tool can do all of the logic without modifying FT task
                /*
                 * This case is the specific API both META DLL and FT task synced
                 * or else the FT just simply pass the message to NFC task
                 */
                if(nfcMessageHeader->msg_type == META_NFC_FIXED_OP_CODE_MSG_ID)
                {
                    nfcMessageHeader->msg_type = ConvertMetaNfcOpToNfcMessageId((kal_uint32)requestHeader->type);
                }
                if(metaMessage->peer_buff_ptr)
                {
                    kal_uint16 pdu_length;
                    get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                    nfcMessage->peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
                    if( NULL != nfcMessage->peer_buff_ptr )
                    {
                        void* nfcMessagePdu  = get_pdu_ptr(nfcMessage->peer_buff_ptr, &pdu_length);
                        void* metaMessagePdu = get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                        kal_mem_cpy(nfcMessagePdu, metaMessagePdu, pdu_length);
                    }
                    else
                    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                        ASSERT(0);
                    }
                }
                FT_SEND_MSG(MOD_FT, MOD_NFC, MMI_MMI_SAP, MSG_ID_NFC_TEST_REQ, nfcMessage);
            }
            else
            {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                ASSERT(0);
            }
        }
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            ASSERT(0);
        }
    }
    else
    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        ASSERT(0);
    }
}
/**
 * Confirm message handler for MOD_NFC
 */
void FT_NFC_ConfirmHandler(ilm_struct* nfcMessage)
{
    nfc_msg_struct* nfcMessageHeader = (nfc_msg_struct*)nfcMessage->local_para_ptr;
    if(nfcMessageHeader)
    {
        ilm_struct *metaMessage = FT_ALLOC_MSG(sizeof(FT_NFC_CNF_HDR_T) + nfcMessage->local_para_ptr->msg_len);
        if(metaMessage)
        {
            FT_NFC_CNF_HDR_T* confirmHeader = (FT_NFC_CNF_HDR_T*)metaMessage->local_para_ptr;
            /* Tunneling */
            if(confirmHeader)
            {
                confirmHeader->header.ft_msg_id = FT_NFC_CMD_CNF_ID;
                confirmHeader->header.token     = ft_nfc_token;
                confirmHeader->type             = ConvertNfcMessageIdToMetaNfcOp((kal_uint32)nfcMessageHeader->msg_type);
                confirmHeader->length           = nfcMessage->local_para_ptr->msg_len;
                kal_mem_cpy((void*)((unsigned int)metaMessage->local_para_ptr + sizeof(FT_NFC_CNF_HDR_T)), nfcMessage->local_para_ptr, confirmHeader->length);
                if(nfcMessage->peer_buff_ptr)
                {
                    kal_uint16 pdu_length;
                    get_pdu_ptr(nfcMessage->peer_buff_ptr, &pdu_length);
                    nfcMessage->peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
                    if( NULL != nfcMessage->peer_buff_ptr )
                    {
                        void* metaMessagePdu = get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                        void* nfcMessagePdu  = get_pdu_ptr(nfcMessage->peer_buff_ptr, &pdu_length);
                        kal_mem_cpy(metaMessagePdu, nfcMessagePdu, pdu_length);
                    }
                    else
                    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                        ASSERT(0);
                    }
                }
                _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaMessage, ft_nfc_token);
            }
            else
            {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                ASSERT(0);
            }
        }
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            ASSERT(0);
        }
    }
    else
    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        ASSERT(0);
    }
}
#else // #if defined(__NFC_SUPPORT__)
/**
 * unsupported op code handler
 */
void SendMetaNfcNotSupportedMessage(kal_uint16 token, kal_uint32 type)
{
    ilm_struct* metaResponseMessage;
    FT_NFC_CNF_HDR_T* metaResponseMessageHeader;
    metaResponseMessage               = FT_ALLOC_MSG( sizeof(FT_NFC_CNF_HDR_T) );
    metaResponseMessageHeader         = (FT_NFC_CNF_HDR_T *)metaResponseMessage->local_para_ptr;
    metaResponseMessageHeader->header.ft_msg_id = FT_NFC_CMD_CNF_ID;
    metaResponseMessageHeader->header.token     = token;
    metaResponseMessageHeader->type   = type;
    metaResponseMessageHeader->status = FT_CNF_NOT_SUPPORTED;
    metaResponseMessageHeader->length = 0;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaResponseMessage);
    return;
}
kal_uint32 FT_NfcCheckFunctionSupported(kal_uint32 query_op_code)
{
    return FT_CNF_FAIL;
}
void FT_NFC_Operation(ilm_struct *metaMessage)
{
    /* Tunnel header */
    FT_NFC_REQ_HDR_T* requestHeader = ((FT_NFC_REQ_HDR_T *)(metaMessage->local_para_ptr) );
    if(requestHeader)
    {
        kal_uint32 support_code = FT_NfcCheckFunctionSupported((kal_uint32) requestHeader->type );
        if(FT_CNF_FAIL == support_code)
        {
            SendMetaNfcNotSupportedMessage(requestHeader->header.token, requestHeader->type);
            return;
        }
    }
}
void FT_NFC_ConfirmHandler(ilm_struct *ptrMsg)
{
}
#endif // #if !defined(__NFC_SUPPORT__)
