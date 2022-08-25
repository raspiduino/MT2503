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
 *   ft_fnc_gps.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GPS test functions
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
#include "ft_msg_gps.h"
#include "ft_fnc_gps.h"
#if defined(__GPS_SUPPORT__)
/*************************************************************************
 * GPS header
 *************************************************************************/
#include "gps_meta_struct.h"
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
static kal_uint16 ft_gps_token;
/**
 * Step2: Add mapping of META op code to GPS message ID (one-to-one)
 */
kal_uint32 ConvertMetaGpsOpToGpsMessageId(kal_uint32 type)
{
    kal_uint32 result = META_GPS_NOT_SUPPORT_MSG_ID;
    switch(type)
    {
        case FT_GPS_OP_OPEN:
        {
            result = META_GPS_OP_OPEN;
            break;
        }
        case FT_GPS_OP_CLOSE:
        {
            result = META_GPS_OP_CLOSE;
            break;
        }
        case FT_GPS_OP_WRITE_CMD:
        {
            result = META_GPS_OP_WRITE_CMD;
            break;
        }
        default:
            break;
    }
    return result;
}
/**
 * Step3: Add mapping of GPS message ID to META op code (many-to-one)
 *   Request message ID  ==> op code
 *   Response message ID ==> op code
 */
kal_uint32 ConvertGpsMessageIdToMetaGpsOp(kal_uint32 type)
{
    kal_uint32 result = FT_GPS_OP_END;
    switch(type)
    {
        case META_GPS_OP_OPEN:
        {
            result = FT_GPS_OP_OPEN;
            break;
        }
        case META_GPS_OP_CLOSE:
        {
            result = FT_GPS_OP_CLOSE;
            break;
        }
        case META_GPS_OP_WRITE_CMD:
        {
            result = FT_GPS_OP_WRITE_CMD;
            break;
        }
        default:
            break;
    }
    return result;
}
/**
 * @param query_op_code the sub-code in GPS test category to be queried
 * @return 0: FT_CNF_OK (supported), 1: FT_CNF_FAIL (not supported)
 */
kal_uint32 FT_GpsCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_bool GPS_task_and_FT_lib_not_match = KAL_FALSE;
    if(kal_get_task_by_index(INDX_GPS))
    {
        /**
         * sanity check to GPS tasks and FT library state:
         * The GPS task exists, but the library is not built with __GPS_SUPPORT__
         */
#if !defined(__GPS_SUPPORT__)
        ASSERT(GPS_task_and_FT_lib_not_match);
#endif // #if !defined(__GPS_SUPPORT__)
        if(ConvertMetaGpsOpToGpsMessageId(query_op_code) == META_GPS_NOT_SUPPORT_MSG_ID)
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
         * sanity check to GPS tasks and FT library state:
         * The GPS task does not exist, but the library is built with __GPS_SUPPORT__
         */
#if defined(__GPS_SUPPORT__)
        ASSERT(GPS_task_and_FT_lib_not_match);
#endif // #if defined(__GPS_SUPPORT__)
        return FT_CNF_FAIL;
    }
}
/**
 * unsupported op code handler
 */
void SendMetaGpsNotSupportedMessage(kal_uint16 token, kal_uint32 type)
{
    ilm_struct* metaResponseMessage;
    FT_GPS_CNF_HDR_T* metaResponseMessageHeader;
    metaResponseMessage               = FT_ALLOC_MSG( sizeof(FT_GPS_CNF_HDR_T) );
    metaResponseMessageHeader         = (FT_GPS_CNF_HDR_T *)metaResponseMessage->local_para_ptr;
    metaResponseMessageHeader->header.ft_msg_id = FT_GPS_CMD_CNF_ID;
    metaResponseMessageHeader->header.token     = token;
    metaResponseMessageHeader->type   = type;
    metaResponseMessageHeader->status = FT_CNF_NOT_SUPPORTED;
    metaResponseMessageHeader->length = 0;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaResponseMessage);
    return;
}
/**
 * @param metaMessage the input message from META tool for GPS test command processing
 */
void FT_GPS_Operation(ilm_struct* metaMessage)
{
    /* Tunnel header */
    FT_GPS_REQ_HDR_T* requestHeader = ((FT_GPS_REQ_HDR_T *)(metaMessage->local_para_ptr) );
    if(requestHeader)
    {
        ilm_struct *gpsMessage;
        kal_uint32 support_code = FT_GpsCheckFunctionSupported((kal_uint32) requestHeader->type );
        if(FT_CNF_FAIL == support_code)
        {
            SendMetaGpsNotSupportedMessage(requestHeader->header.token, requestHeader->type);
            return;
        }
        gpsMessage        = FT_ALLOC_MSG(requestHeader->length);
        ft_gps_token      = requestHeader->header.token;
        if(gpsMessage)
        {
            /* Tunneling */
            meta_gps_op_req_struct* gpsMessageHeader = (meta_gps_op_req_struct*)gpsMessage->local_para_ptr;
            if(gpsMessageHeader)
            {
                kal_mem_cpy(gpsMessage->local_para_ptr, (void*)((unsigned int)metaMessage->local_para_ptr + sizeof(FT_GPS_REQ_HDR_T)), requestHeader->length);
                if(metaMessage->peer_buff_ptr)
                {
                    kal_uint16 pdu_length;
                    get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                    gpsMessage->peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
                    if( NULL != gpsMessage->peer_buff_ptr )
                    {
                        void* gpsMessagePdu  = get_pdu_ptr(gpsMessage->peer_buff_ptr, &pdu_length);
                        void* metaMessagePdu = get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                        kal_mem_cpy(gpsMessagePdu, metaMessagePdu, pdu_length);
                    }
                    else
                    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                        ASSERT(0);
                    }
                }
                FT_SEND_MSG(MOD_FT, MOD_GPS, MMI_MMI_SAP, MSG_ID_META_GPS_OP_REQ, gpsMessage);
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
void FT_GPS_MetaMessageTunnel(const ilm_struct* gpsMessage, kal_uint32 meta_op_type)
{
    ilm_struct *metaMessage = FT_ALLOC_MSG(sizeof(FT_GPS_CNF_HDR_T) + gpsMessage->local_para_ptr->msg_len);
    if(metaMessage)
    {
        FT_GPS_CNF_HDR_T* confirmHeader = (FT_GPS_CNF_HDR_T*)metaMessage->local_para_ptr;
        /* Tunneling */
        if(confirmHeader)
        {
            confirmHeader->header.ft_msg_id = FT_GPS_CMD_CNF_ID;
            confirmHeader->header.token     = ft_gps_token;
            confirmHeader->type             = meta_op_type;
            confirmHeader->status           = FT_CNF_OK;
            confirmHeader->length           = gpsMessage->local_para_ptr->msg_len;
            kal_mem_cpy((void*)((unsigned int)metaMessage->local_para_ptr + sizeof(FT_GPS_CNF_HDR_T)), gpsMessage->local_para_ptr, confirmHeader->length);
            if(gpsMessage->peer_buff_ptr)
            {
                kal_uint16 pdu_length;
                get_pdu_ptr(gpsMessage->peer_buff_ptr, &pdu_length);
                metaMessage->peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
                if( NULL != gpsMessage->peer_buff_ptr )
                {
                    void* metaMessagePdu = get_pdu_ptr(metaMessage->peer_buff_ptr, &pdu_length);
                    void* gpsMessagePdu  = get_pdu_ptr(gpsMessage->peer_buff_ptr, &pdu_length);
                    kal_mem_cpy(metaMessagePdu, gpsMessagePdu, pdu_length);
                }
                else
                {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                    ASSERT(0);
                }
            }
            _FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaMessage, ft_gps_token);
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
 * Handler for GPS task ACK message
 */
void FT_GPS_RespnoseHandler(const ilm_struct* gpsMessage)
{
    meta_gps_op_rsp_struct* gpsMessageHeader = (meta_gps_op_rsp_struct*)gpsMessage->local_para_ptr;
    if(gpsMessageHeader)
    {
        kal_uint32 meta_op_type;
        if(gpsMessageHeader->rsp_type == META_GPS_OPEN_SUCCESS ||
                gpsMessageHeader->rsp_type == META_GPS_OPEN_FAIL)
        {
            meta_op_type = FT_GPS_OP_OPEN;
        }
        else if(gpsMessageHeader->rsp_type == META_GPS_CLOSE_DONE)
        {
            meta_op_type = FT_GPS_OP_CLOSE;
        }
        else
        {
            meta_op_type = FT_GPS_OP_WRITE_CMD;
        }
        FT_GPS_MetaMessageTunnel(gpsMessage, meta_op_type);
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
 * Handler for GPS task data indication message
 */
void FT_GPS_DataHandler(const ilm_struct* gpsMessage)
{
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
    FT_GPS_MetaMessageTunnel(gpsMessage, FT_GPS_DATA_IND);
}
/**
 * Confirm message handler for MOD_GPS
 * handling MSG_ID_META_GPS_OP_RSP and MSG_ID_META_GPS_DATA_IND
 */
void FT_GPS_ConfirmHandler(ilm_struct* gpsMessage)
{
    if(gpsMessage->msg_id == MSG_ID_META_GPS_OP_RSP)
    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        FT_GPS_RespnoseHandler(gpsMessage);
    }
    else if(gpsMessage->msg_id == MSG_ID_META_GPS_DATA_IND)
    {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        FT_GPS_DataHandler(gpsMessage);
    }
    else
    {
        kal_bool UNHANDLED_GPS_MSG = KAL_FALSE;
        ASSERT(UNHANDLED_GPS_MSG);
    }
}
#else // #if defined(__GPS_SUPPORT__)
/**
 * unsupported op code handler
 */
void SendMetaGpsNotSupportedMessage(kal_uint16 token, kal_uint32 type)
{
    ilm_struct* metaResponseMessage;
    FT_GPS_CNF_HDR_T* metaResponseMessageHeader;
    metaResponseMessage               = FT_ALLOC_MSG( sizeof(FT_GPS_CNF_HDR_T) );
    metaResponseMessageHeader         = (FT_GPS_CNF_HDR_T *)metaResponseMessage->local_para_ptr;
    metaResponseMessageHeader->header.ft_msg_id = FT_GPS_CMD_CNF_ID;
    metaResponseMessageHeader->header.token     = token;
    metaResponseMessageHeader->type   = type;
    metaResponseMessageHeader->status = FT_CNF_NOT_SUPPORTED;
    metaResponseMessageHeader->length = 0;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, metaResponseMessage);
    return;
}
kal_uint32 FT_GpsCheckFunctionSupported(kal_uint32 query_op_code)
{
    return FT_CNF_FAIL;
}
void FT_GPS_Operation(ilm_struct *metaMessage)
{
    /* Tunnel header */
    FT_GPS_REQ_HDR_T* requestHeader = ((FT_GPS_REQ_HDR_T *)(metaMessage->local_para_ptr) );
    if(requestHeader)
    {
        kal_uint32 support_code = FT_GpsCheckFunctionSupported((kal_uint32) requestHeader->type );
        if(FT_CNF_FAIL == support_code)
        {
            SendMetaGpsNotSupportedMessage(requestHeader->header.token, requestHeader->type);
            return;
        }
    }
}
void FT_GPS_ConfirmHandler(ilm_struct *ptrMsg)
{
}
#endif // #if !defined(__GPS_SUPPORT__)
