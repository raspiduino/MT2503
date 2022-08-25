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
/*****************************************************************************
*
 * Filename:
 * ---------
 *  GPSMgrProt.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *  GPS Manager Internal APIs
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)

#ifndef _GPSMGRPROT_H_
#define _GPSMGRPROT_H_

#if defined(__AGPS_USER_PLANE__)
#define MAX_SUPL_REQ_NUM 5
#define NOTIFY_TIMER_ID_BEGIN GPS_MGR_NOTIFY_TIMER_ID_1
#define NOTIFY_TIMER_ID_END GPS_MGR_NOTIFY_TIMER_ID_5
#define MAX_NOTIFY_TIMER_ID (NOTIFY_TIMER_ID_END - NOTIFY_TIMER_ID_BEGIN + 1)
#define UART_WORK_MODE_COUNT 3

#define MMI_GPS_MGR_DEBUG
#define MMI_GPS_MGR_MA_NOT_ABORT_SUPL_WHEN_POS

/*#define MMI_GPS_MGR_OP01*/
#endif /* __AGPS_USER_PLANE__ */

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
typedef enum
{
    MMI_AGPS_STATE_TERMINATE,
    MMI_AGPS_STATE_START,
    MMI_AGPS_STATE_ACTIVITATE,
    MMI_AGPS_STATE_WAIT_CNF,
    MMI_AGPS_STATE_WORKING,
    MMI_AGPS_STATE_STAND_BY,
    MMI_AGPS_STATE_WAIT_POS,
    MMI_AGPS_STATE_ABORT,
    MMI_AGPS_STATE_SET_WORK_MODE,
    MMI_AGPS_STATE_GPS_INIT,
    MMI_AGPS_STATE_PUSH_WAIT,
    MMI_AGPS_STATE_NI_ERROR,
    MMI_AGPS_STATE_WAIT_RSP,
    MMI_AGPS_STATE_END
} mmi_agps_state_enum;

#endif /* __AGPS_USER_PLANE__ || __AGPS_CONTROL_PLANE__ */

typedef enum
{
    MMI_GPS_START_MODE_NI,
    MMI_GPS_START_MODE_SI,
    MMI_GPS_START_MODE_NORMAL,
    MMI_GPS_START_MODE_END
} mmi_gps_start_mode_enum;

typedef enum
{
    MMI_GPS_MGR_RESULT_SUCCESS = 0,
    MMI_GPS_MGR_RESULT_MORE_REQUEST = -1,
    MMI_GPS_MGR_RESULT_AGPS_OFF = -2,
    MMI_GPS_MGR_RESULT_WORK_MODE_DIFFER = -3,
    MMI_GPS_MGR_RESULT_OPEN_GPS_FAIL = -4,
    MMI_GPS_MGR_RESULT_FALSE_GPS_CALLBACK = -5,
    MMI_GPS_MGR_RESULT_GPS_ABORTING = -6,
    MMI_GPS_MGR_RESULT_UART_OPENING = -7,
    MMI_GPS_MGR_RESULT_PROFILE_ERROR = -8,
    MMI_GPS_MGR_MA_RAW_DATA = -9,
    MMI_GPS_MGR_RESULT_INVALID_REQ_ID = -10,
    MMI_GPS_MGR_RESULT_ECC_CALLING_ERROR = -11,
    MMI_GPS_MGR_RESULT_CP_IS_ONGOING = -12,
    MMI_GPS_MGR_RESULT_END
} mmi_gps_mgr_result_enum;


#if defined(__AGPS_CONTROL_PLANE__)
extern void mmi_gps_mgr_cp_init(void);
#endif /* __AGPS_CONTROL_PLANE__ */

#endif /* _GPSMGRPROT_H_ */
#endif /* __GPS_SUPPORT__ || __BT_GPS_SUPPORT__ */

