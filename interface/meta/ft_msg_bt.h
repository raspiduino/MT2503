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
 *   ft_msg_bt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of BT category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_BT_H__
#define __FT_MSG_BT_H__
#include "ft_msg_common.h"
/*******************************************************************************
*  HCI REQ/CNF
*******************************************************************************/

typedef enum {
     FT_BT_OP_HCI_SEND_COMMAND = 0
    ,FT_BT_OP_HCI_CLEAN_COMMAND
    ,FT_BT_OP_HCI_SEND_DATA
    ,FT_BT_OP_HCI_TX_PURE_TEST
    ,FT_BT_OP_HCI_RX_TEST_START
    ,FT_BT_OP_HCI_RX_TEST_END
    ,FT_BT_OP_HCI_TX_PURE_TEST_V2
    ,FT_BT_OP_HCI_RX_TEST_START_V2
    ,FT_BT_OP_ENABLE_NVRAM_ONLINE_UPDATE
    ,FT_BT_OP_DISABLE_NVRAM_ONLINE_UPDATE
    ,FT_BT_OP_ENABLE_PCM_CLK_SYNC_SIGNAL
    ,FT_BT_OP_DISABLE_PCM_CLK_SYNC_SIGNAL
    ,FT_BT_OP_POWER_ON_EX
    ,FT_BT_OP_POWER_OFF_EX
    ,FT_BT_OP_POWER_ON_EX2
    ,FT_BT_OP_END
} FT_BT_OP;


typedef struct {
    kal_uint16      opcode;
    kal_uint8       len;
    kal_uint8       cmd[256];
} FT_BT_HCI_CMD;

typedef struct {
    kal_uint16           con_hdl;
    kal_uint16           len;
    kal_uint8            buffer[1021];
} FT_BT_HCI_BUFFER;
typedef struct {
    kal_uint16           con_hdl;
    kal_uint16           len;
    kal_uint16           total_pks;
} FT_BT_HCI_TX_PURE_TEST;
typedef struct {
    kal_uint32           used_time;
    kal_uint16           len;
} FT_BT_HCI_TX_PURE_TEST_STAT;
typedef struct {
    kal_uint32       used_time;
    kal_uint16       sent_num;
} FT_BT_HCI_TX_PURE_TEST_STAT_V2;

typedef struct {
    kal_uint32           used_time;
    kal_uint16           len;
} FT_BT_HCI_RX_PURE_TEST_STAT;

typedef struct
{
   kal_uint32         used_time;
   kal_uint16         len;
   kal_uint8          stop_flag;
}FT_BT_HCI_RX_PURE_TEST_STAT_V2;

typedef struct
{
    kal_uint8     m_u1Flag; /**< indicator that the FT task polling for the power on state */
    FT_BT_HCI_CMD hci; /**< command buffer for the power on sequence */
}FT_BT_POWER_ON_EX2_REQ_T;

typedef union {
    // for power on/off
    kal_uint8                m_u1Flag;
    kal_uint32               dummy;
    FT_BT_HCI_CMD            hci;
    FT_BT_HCI_BUFFER         buf;
    FT_BT_HCI_TX_PURE_TEST   txpuretest;
    FT_BT_POWER_ON_EX2_REQ_T poweron_ex2;
} FT_BT_CMD;

typedef struct {
    kal_uint8       event;
    kal_uint16      handle;
    kal_uint8       len;
    kal_int8        status;
    kal_uint8       parms[256];
} FT_BT_HCI_EVENT;

typedef struct {
    kal_uint16           len;
    kal_uint8            data[1021];
} FT_BT_HCI_PACKET;

typedef union {
    kal_uint32                      dummy;
    FT_BT_HCI_EVENT                 hcievent;
    FT_BT_HCI_BUFFER                hcibuffer;
    FT_BT_HCI_PACKET                hcipacket;
    FT_BT_HCI_TX_PURE_TEST_STAT     txstat;
    FT_BT_HCI_RX_PURE_TEST_STAT     rxstat;
    FT_BT_HCI_TX_PURE_TEST_STAT_V2  txstat_v2;
    FT_BT_HCI_RX_PURE_TEST_STAT_V2  rxstat_v2;
} FT_BT_RESULT;

typedef struct {
    FT_H      header;
    FT_BT_OP  op;
    FT_BT_CMD cmd;
} FT_BT_REQ;

typedef struct {
    FT_H         header;
    FT_BT_OP     op;
    kal_int32    status;
    kal_uint8    eventtype;
    FT_BT_RESULT result;
} FT_BT_CNF;
#endif // #ifndef __FT_MSG_BT_H__
