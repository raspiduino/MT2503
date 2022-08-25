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
 * fmr_main.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      fmr_main defined structure
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef _FMR_MAIN_H_
#define _FMR_MAIN_H_
#include "kal_public_api.h"
#include "kal_public_defs.h"
void FMR_Init(void);
void FMR_ChkSearchStop(void);
#if (defined(MT6616))
void FMR_HCI_Event_Hdlr(kal_bool isReadyRead);
#endif
#if (defined(MT6626))
//extern void FMR_BT_Do_Chip_Force_Reset(void);
extern void FMR_BT_Do_Chip_Force_Reset_Done(void);
#endif
#if (defined(MT6250FM))
extern void FMDrv_SetRCCal(void);
#endif
#if (defined(MT6250FM))||(defined(MT6260FM))||(defined(MT6261FM))
#define FM_ESD_RECOVERY 1
#endif
//#ifdef __FM_RADIO_RDS_SUPPORT__
void FMR_EINTChk(void);

void FMR_RDS_ChkEvent(void * param);
#define FM_BASE_TIMER_ID (0x0000)
#define FM_RDS_BLER_CHECK_INTERVAL           1500
#if defined(__CLASSK_CP_SUPPORT__)
#define FM_CLASSK_CHECK_RSSI_INTERVAL		5000	//5s
#endif
#if (FM_ESD_RECOVERY == 1)
#define FM_ESD_TIMER_INTERVAL		5000	//5s
#endif

typedef enum
{
    FM_RDS_BLER_CHECK_TIMER,
#if defined(__CLASSK_CP_SUPPORT__)
	FM_CLASSK_CHECK_RSSI_TIMER,
#endif
#if (FM_ESD_RECOVERY == 1)
	FM_ESD_TIMER,		
#endif
    MAX_NUM_OF_FM_TIMER
} fm_timer_enum;

typedef enum
{
    FM_POWERON_STATE = 0,
    FM_POWEROFF_STATE,
    FM_STATE_TOTAL
} fm_state_enum;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} fm_timer_table_struct;

typedef struct
{
    fm_state_enum fm_state;
    //stack_timer_struct base_timer;
    event_scheduler *event_scheduler_ptr;
} fm_context_struct;
//#endif
#if (defined(MT5192FM))
#define FM_BASE_TIMER_ID (0x0000)
#define FM_MLoop_CHECK_INTERVAL           20
typedef enum
{
    FM_MLoop_CHECK_TIMER,
    MAX_NUM_OF_FM_TIMER
} fm_timer_enum;

typedef enum
{
    FM_POWERON_STATE = 0,
    FM_POWEROFF_STATE,
    FM_STATE_TOTAL
} fm_state_enum;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} fm_timer_table_struct;

typedef struct
{
    fm_state_enum fm_state;
    stack_timer_struct base_timer;
    event_scheduler *event_scheduler_ptr;
} fm_context_struct;
#endif
#endif /* _FMR_MAIN_H_ */
