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
 *  ft_bt_customize.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains ft task customized bt funcitons in META mode.
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "ft_bt_customize.h"

MetaEntry metaEntry;

void Custom_BTRegister(MetaEntry *entry)
{
    memcpy(&metaEntry, entry, sizeof(MetaEntry));
}

void Custom_BTPowerOn(U8 uart_setting)
{
    #ifdef __BTMTK__
        metaEntry.powerOn(uart_setting);
    #endif
}

U8 Custom_BTQueryPowerOnState(void)
{
    #ifdef __BTMTK__
        return metaEntry.powerOnQuery();
    #else
        return 0x00;
    #endif
}

void Custom_BTPowerOff(void)
{
    #ifdef __BTMTK__
        metaEntry.powerOff();
    #endif
}
void Custom_Meta_ResetHci(void)
{
    #ifdef __BTMTK__
        metaEntry.resetHci();
    #endif
}

void  Custom_Meta_RegisterHciEventHandler( RadioHandlerCallback callback )		
{
	#ifdef __BTMTK__
	   metaEntry.registerHci(callback);
    #endif
}

U16  Custom_Meta_CleanCommand(void)
{
    #ifdef __BTMTK__
        return metaEntry.cleanCmd();
    #else
        return 0x00;
    #endif
}

U16 Custom_Meta_SendHciData(U16 con_hdl,U16 data_len,U8 *raw_data)
{
    #ifdef __BTMTK__
        return metaEntry.sendHciData(con_hdl,data_len,raw_data);
    #else
        return 0x00;
    #endif
}
U16 Custom_Meta_CheckTxAvail(void)
{
    #ifdef __BTMTK__
        return metaEntry.checkTxAvail();
    #else
        return 0x00;
    #endif
}
U16 Custom_Meta_SendHciCommand(U16 opCode, U8 parmLen, HciCommand *cmd)
{
    #ifdef __BTMTK__
        return metaEntry.sendHciCommand(opCode,parmLen,cmd,(0==1), (1==1));
    #else
        return 0x00;
    #endif
}

U16 Custom_Meta_StartTxPureTest(U16  con_hdl, U16  u2PktLen, U16 u2PktNum)
{
    #ifdef __BTMTK__
        return metaEntry.startTxPureTest(con_hdl,u2PktLen,u2PktNum);
    #else
        return 0x00;
    #endif
}

U16 Custom_Meta_QueryTxPureTest(void)
{
    #ifdef __BTMTK__
        return metaEntry.queryTxPureTest();
    #else
        return 0x00;
    #endif

}

U16 Meta_TxRxInit()
{
    return metaEntry.txRxInit();
}


