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
 * Filename:
 * ---------
 * DateTimeGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes for date/time realted utilities.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 */

/**************************************************************

   FILENAME : DateTimeGprot.h

   PURPOSE     : .

   REMARKS     : nil

   AUTHOR      : Vijay Vaidya

   DATE     : .

**************************************************************/
#ifndef _MMI_DATETIMEGPROT_H
#define _MMI_DATETIMEGPROT_H

#include "MMIDataType.h"
// #include "DateTimeDef.h"
#include "DateTimeType.h"
#include "AlarmDef.h"
#include "app_datetime.h"

    #include "custom_mmi_default_value.h"
/* 
 * Define
 */
#define YEARFORMATE  2000

/* 
 * Typedef 
 */
typedef void (*DateTimeFuncPtr) (MYTIME *);
typedef void (*mmi_dt_set_time_res_funcptr) (MMI_BOOL , void*);

#ifdef __BUILD_DOM__
/*
 * DESCRIPTION
 *  Event ID of Reminder.
 *  Reminder will send evt to notify AP.
 */
typedef enum
{
    /*
     * [INTERNAL]
     *
     * Structure:
     *  srv_reminder_evt_struct
     */
    EVT_ID_SRV_DATETIME_CHANGE = SRV_DATETIME_BASE,
    EVT_ID_SRV_DATETIME_TOTAL
} srv_datetime_evt_id_enum;

#endif /*__BUILD_DOM__*/

#define SRV_DATETIME_CHANGE_FLAG_MIN   0x01
#define SRV_DATETIME_CHANGE_FLAG_HOUR  0x02
#define SRV_DATETIME_CHANGE_FLAG_DAY   0x04
#define SRV_DATETIME_CHANGE_FLAG_MONTH 0x08

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_REMINDER_NOTIFY, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER    
    U32 change;
	MYTIME old_time;
	MYTIME new_time;
} srv_datetimie_evt_struct;

/* 
 * Extern Global Variable
 */


/* 
 * Extern Global Function
 */
extern void DateTimerIndication(void *p);
extern void SetDateTime(void *t);
extern void mmi_dt_check_rtc_time(void);

extern FLOAT mmi_dt_get_tz(void);
extern void mmi_dt_set_dst(U8 dst);
extern void mmi_dt_set_rtc_dt(MYTIME *t);
extern void mmi_dt_set_dt(const MYTIME *time, mmi_dt_set_time_res_funcptr callback, void* usr_data);

#endif /* _MMI_DATETIMEGPROT_H */ 

