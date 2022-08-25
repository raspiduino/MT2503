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
 *
 * Filename:
 * ---------
 *  ft_bt_customize.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains ft task customized funcitons in META mode.
 *
 * Author:
 * -------
 *  
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
#ifndef _FT_BT_CUSTOMIZE_H_
#define _FT_BT_CUSTOMIZE_H_

#ifndef TRUE
#define TRUE  (1==1)
#endif /* TRUE */

#ifndef FALSE
#define FALSE (0==1)  
#endif /* FALSE */

typedef struct  _ListEntry 
{
    struct _ListEntry *Flink;
    struct _ListEntry *Blink;

} ListEntry;

#define BT_STATUS_SUCCESS (0)

#define HCI_CMD_PARM_LEN (248)

#define BT_PACKET_HEADER_LEN (14)

#define HCI_CONTROLLER_EVENT (1)
#define HCI_DATA_IND         (2)
#define HCI_PACKET_HANDLED   (3)
#define HCI_COMMAND_HANDLED  (4)
#define HCI_SEND_IND         (5)
#define HCI_INIT_STATUS      (6)
#define HCI_DEINIT_STATUS    (7)
#define HCI_TRANSPORT_ERROR  (8)
#define HCI_BLUETOOTH_LOGO   (9)
#define HCI_VENDOR_SPECIFIC  (10)
#define HCI_META_PKT_SENT_OUT	(11)

typedef unsigned short U16;
typedef unsigned char  U8;
typedef unsigned char  BOOL;

typedef struct _HciCommand {
    ListEntry node;      
    U8        header[3];
    U8        parms[HCI_CMD_PARM_LEN];
    
} HciCommand;

typedef struct _HciEvent {
   U8  event;  
   U8  len;    
   U8  *parms;  
} HciEvent;

typedef struct _HciBuffer
{
    ListEntry      node;     
    U16 len;      
    U8  *buffer;   
    U8  flags;  
} HciBuffer;

typedef struct _HciMetaBuffer
{
    U16        con_hdl;
    U16        len;      
    U8         *buffer;   
} HciMetaBuffer;

typedef struct _BtPacket
{
    ListEntry    node;    
    U8          *data;    
    U16          dataLen; 
    U8           flags;   
    U8          priority_type;
    void        *ulpContext;
    U8          *tail;
    U16          tailLen;
    U16          llpContext;
    U16          remoteCid;
    U8           hciPackets;
    U8           headerLen;
    U8           header[BT_PACKET_HEADER_LEN];
} BtPacket;



typedef struct _HciCallbackParms {
    U16  status;     
    U16 hciHandle;   
    U8 morePacketWaiting;
    union {
        HciEvent   *hciEvent;  
        HciBuffer  *rxBuff;     
        BtPacket   *packet;     
        HciCommand *cmd;        
        HciMetaBuffer  *rxMetaBuff;   
        unsigned char              txNumber[40];
    } ptr;
} HciCallbackParms;


typedef void (*RadioHandlerCallback)(U8 event, HciCallbackParms *parms);

typedef void (*powerOnFunc) (U8 uart_setting);
typedef U8 (*powerOnQueryFunc) (void);
typedef void (*registerHciFunc) (RadioHandlerCallback);
typedef U16 (*sendHciDataFunc) (U16, U16, U8*);
typedef U16 (*sendHciCommandFunc) (U16, U8, void *, BOOL, BOOL);
typedef U16 (*startTxPureTestFunc) (U16, U16, U16);
typedef void (*generalFunc) (void);
typedef U16 (*generalFunc2) (void);

typedef struct _MetaEntry
{
    powerOnFunc powerOn;
    powerOnQueryFunc powerOnQuery;
    generalFunc powerOff;
    generalFunc resetHci;
    registerHciFunc registerHci;
    generalFunc2 cleanCmd;
    sendHciDataFunc sendHciData;
    generalFunc2 checkTxAvail;
    sendHciCommandFunc sendHciCommand;
    startTxPureTestFunc startTxPureTest;
    generalFunc2 queryTxPureTest;
    generalFunc2 txRxInit;
} MetaEntry;


U8 Custom_BTQueryPowerOnState(void);
void  Custom_BTPowerOn(U8 uart_setting);
void  Custom_BTPowerOff(void);
void Custom_Meta_ResetHci(void);
void  Custom_Meta_RegisterHciEventHandler(RadioHandlerCallback callback );		
U16 Custom_Meta_CleanCommand(void);
U16 Custom_Meta_SendHciData(U16 con_hdl,U16 data_len,U8 *raw_data);
U16 Custom_Meta_CheckTxAvail(void);
U16 Custom_Meta_SendHciCommand(U16 opCode, U8 parmLen, HciCommand *cmd);
U16 Custom_Meta_StartTxPureTest(U16  con_hdl, U16  u2PktLen, U16 u2PktNum);
U16 Custom_Meta_QueryTxPureTest(void);

#endif /* _FT_BT_CUSTOMIZE_H_ */ 

