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
 *   ft_msg_nfc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of NFC test category of FT Library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __FT_MSG_NFC_H__
#define __FT_MSG_NFC_H__
#include "ft_msg_common.h"
typedef enum
{
    /***************************************
     * Chip power on/off ; Query capability
     **************************************/
     FT_NFC_OP_INIT_QUERY = 0
    /***************************************
     * Test mode feature
     **************************************/
    ,FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON
    ,FT_NFC_OP_TEST_MODE_TX_ALWAYS_ON_WITHOUT_ACK_TEST
    ,FT_NFC_OP_TEST_MODE_CARD_MODE_TEST
    ,FT_NFC_OP_TEST_MODE_READER_MODE_TEST
    ,FT_NFC_OP_TEST_MODE_P2P_MODE_TEST
    ,FT_NFC_OP_TEST_MODE_SWP_SELF_TEST
    ,FT_NFC_OP_TEST_MODE_ANTENNA_SELF_TEST
    ,FT_NFC_OP_TEST_MODE_UID_ACCESS
    ,FT_NFC_OP_TEST_MODE_CARD_MODE_EMULATION_TEST
    /***************************************
     * Software Protocol test command
     **************************************/
    ,FT_NFC_OP_SW_PROTOCOL_NOTIFICATION
    ,FT_NFC_OP_SW_PROTOCOL_SECURE_ELEMENT_SET
    ,FT_NFC_OP_SW_PROTOCOL_DISCOVERY
    ,FT_NFC_OP_SW_PROTOCOL_TAG_READ
    ,FT_NFC_OP_SW_PROTOCOL_TAG_WRITE
    ,FT_NFC_OP_SW_PROTOCOL_TAG_DISCONNECT
    ,FT_NFC_OP_SW_PROTOCOL_TAG_FORMAT_TO_NDEF
    ,FT_NFC_OP_SW_PROTOCOL_TAG_RAW_COMMUNICATION
    ,FT_NFC_OP_SW_PROTOCOL_P2P_COMMUNICATION
    /***************************************
     * RAW data command
     **************************************/
    ,FT_NFC_OP_RAW_DATA_COMMUNICATION
    ,FT_NFC_OP_END
}FT_NFC_CMD_TYPE;

typedef struct
{
    /// FT request/confirm common header
    FT_H       header;
    /// command type
    kal_uint32 type;
    /// data length in local parameter (only the request payload part)
    kal_uint32 length;
}FT_NFC_REQ_HDR_T;

typedef struct
{
    /// FT request/confirm common header
    FT_H       header;
    /// command type
    kal_uint32 type;
    /// confirm status (0: FT_CNF_OK, 1: FT_CNF_FAIL, 2: FT_CNF_NOT_SUPPORTED)
    kal_uint32 status;
    /// data length in local parameter (only the confirm payload part)
    kal_uint32 length;
}FT_NFC_CNF_HDR_T;

#define META_NFC_NOT_SUPPORT_MSG_ID 0xFFFFFFFF
#define META_NFC_FIXED_OP_CODE_MSG_ID 0xFFFFFFFE

#endif // #ifndef __FT_MSG_NFC_H__
