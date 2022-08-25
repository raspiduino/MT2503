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
 * ABM_DEF.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ABM internal type definitions.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ABM_DEF_H
#define _ABM_DEF_H

//#define ABM_CBM_UT_TEST

/* Should be define to NULL after release */
#ifdef  __MTK_INTERNAL__
/* under construction !*/
#else
#define ABM_DEBUG_ASSERT(exp)
#endif

#include "reg_base.h"
#include "soc_consts.h" /* for network unit test */
#include "cbm_consts.h"

#include "kal_public_api.h"
#include "abm_trc.h"
//#include "kal_internal_api.h"
 
#ifdef __NWK_APP_UT__
#ifndef NWK_APP_UT_TEST
#define NWK_APP_UT_TEST 1
#endif
#endif

/* MACRO to log error when received wrong message */
#define ABM_LOG_MSG_ERROR(msg_id) {kal_trace(TRACE_ERROR, ERROR_ABM_MSG_1, msg_id);}
/* MACRO to log error when received message in unexpected state */
#define ABM_LOG_MSG_ERROR_STATE(msg_id, state) {kal_trace(TRACE_ERROR, ERROR_ABM_MSG_2, msg_id, state);}
#define ABM_LOG_MSG_ERROR_APP_STATE(msg_id, state, app_id) {kal_trace(TRACE_ERROR, ERROR_ABM_MSG_3, msg_id, state, app_id);}
#define ABM_LOG_STATE(state, result) {kal_trace(TRACE_STATE, STATE_ABM_TRANSITION, result, state);}

#define ABM_DEFAULT_QOS     (0)         /* ref. SOC_DEFAULT_QOS_PROFILE */
#define ABM_ANY_QOS             (0xff)    /* abm_get_ps_slot_by_acct_id() */
#define ABM_UNKNOWN_BEARER     (0xff) /* ref. SOC_UNKNOWN_BEARER_CTX, waiting for PS response,
                                                                     * do not touch this value, sync with TCM */
#define ABM_ANY_BEARER       (0x80)  /* ref. SOC_UNKNOWN_BEARER_CTX, waiting for PS response */
#define ABM_NULL_BEARER     (0)    /* for message to SOC when no bearer context exists */

#define ABM_MAX_DYNAMIC_QOS_ID_NUM  20
#define ABM_MAX_APP_ACCT_NUM        4
#define ABM_MAX_APP_ID_LIST_NUM     8

#define ABM_GPRS_TIMEOUT_VAL        (KAL_TICKS_1_MIN * 2)       /* 2 min */
#define ABM_MAX_DL_FILTERS          (8)

#define MIN_HDR_SIZE                (40)

#ifdef __CBM_BEARER_SWITCH__
#define ABM_MAX_BEARER_FALLBACK_TYPE_NUM    (3)
#else
#define ABM_MAX_BEARER_FALLBACK_TYPE_NUM    (0)
#endif

#define ABM_MAX_ALWAYS_ASK_TYPE_NUM    (0)

#define ABM_MAX_REPORT_BEARER_NUM   (1+ABM_MAX_BEARER_FALLBACK_TYPE_NUM+ABM_MAX_ALWAYS_ASK_TYPE_NUM)

#define ABM_MAX_DIALUP_NUM          (GPRS_MAX_PDP_SUPPORT + 1)

typedef enum
{
    ABM_DEFAULT_TIMER = 0,    /* for postponing socket close */
    ABM_PS_TIMER,       /* for select */
    ABM_MAX_TIMER
} abm_timer_enum;

typedef enum
{
    ABM_PORTAL_NONE = 0,
    ABM_PORTAL_VERIFYING,
    ABM_PORTAL_VERIFIED
} abm_portal_state_enum;

/* ABM state macros */
typedef enum
{
    ABM_INACTIVE = 0,
    ABM_INIT,
    ABM_OPENING,
    ABM_ACTIVE,
    ABM_CLOSING,
    ABM_RECOVERING,
    ABM_RENEWING,
    ABM_BEARER_STATE_TOTAL
} abm_account_state_enum;

/* ABM state macros */
typedef enum
{
    ABM_APP_INACTIVE = 0,
    ABM_APP_INIT,
    ABM_APP_OPENING,
    ABM_APP_ACTIVE,
    ABM_APP_CLOSING,
    ABM_APP_REACTIVE,
    ABM_APP_REINIT,
    ABM_APP_BEARER_STATE_TOTAL
} abm_app_account_state_enum;

/* Whether bearer is activated or deactivated by socket or not */
typedef enum
{
    ABM_STATE_NULL = 0x00,
    ABM_STATE_SOC_ACTIVATE = 0x01, /* Activate by SOC */
    ABM_STATE_SOC_DEACTIVATE = 0x02, /* Deactivate by SOC */
    ABM_STATE_MMI_CNMGR_DEACTIVATE = 0x04, /* Deactivate by MMI connection management */
    ABM_STATE_MMI_APP_DEACTIVATE = 0x08, /* Deactivate APP bearer by MMI */
    ABM_STATE_MMI_NON_APP_DEACTIVATE = 0x10, /* Deactivate non-app bearer by MMI */
    ABM_STATE_MMI_CBM_DEACTIVATE = 0x20, /* Deactivate by MMI connection management */
    ABM_STATE_TOTAL
} abm_bearer_state_enum;

typedef enum
{
    ABM_NWK_SRV_DISALLOW_NULL = 0x00,
    ABM_NWK_SRV_DISALLOW_LAWMO = 0x01, /* Activate by SOC */
    ABM_NWK_SRV_DISALLOW_COMMON = 0x02, /* Deactivate by SOC */
    ABM_NWK_SRV_DISALLOW_TOTAL
} abm_nwk_srv_disallow_enum;

typedef enum
{
    ABM_APP_OPT_NONE,
    //ABM_APP_OPT_BEARER_FB_L1                   = 0x0001,
    //ABM_APP_OPT_BEARER_FB_L2                   = 0x0002,
    ABM_APP_OPT_BEARER_FB_WIFI_TO_PS           = 0x0004,
    //ABM_APP_OPT_NON_AUTO_FB_L1                 = 0x0008,
    ABM_APP_OPT_NON_AUTO_DEACT                 = 0x0010,
    //ABM_APP_OPT_ALWAYS_ASK                     = 0x0020,
    ABM_APP_OPT_REG_BEARER                     = 0x0040,
    ABM_APP_OPT_BEARER_SWITCH                  = 0x0080,
    ABM_APP_OPT_BEARER_DISCONNECT              = 0x0100,
    ABM_APP_OPT_TOTAL
}abm_app_option_enum;

typedef enum
{
    ABM_APP_IN_FB_L1                            = 0x01,
    ABM_APP_IN_NON_AUTO_FB_L1                   = 0x02,
    ABM_APP_IN_FB_L2                            = 0x04,
    ABM_APP_IN_FB_L2_WIFI_TO_PS                 = 0x08,
    ABM_APP_FB_STATE_TOTAL
}abm_app_fallback_status_enum;

typedef enum
{
    ABM_RCV_FROM_SIM1 = 0x01,
    ABM_RCV_FROM_SIM2 = 0x02,
    ABM_RCV_FROM_SIM3 = 0x04,
    ABM_RCV_FROM_SIM4 = 0x08,
    ABM_RCV_TOTAL
} abm_received_rsp_enum;

typedef enum
{
    ABM_UT_SEND_PS_DISC = 0,       /* 0 */
    ABM_UT_SEND_CC_DISC,       /* 1 */
    ABM_UT_SEND_SUPC_DISC,     /* 2 */
    ABM_UT_BEARER_INIT_CNF,        /* 3 */
    ABM_UT_SETUP_REQ,              /* 4 */
    ABM_UT_DISC_REQ,               /* 5 */
    ABM_UT_SET_ACCT_ID,            /* 6 */
    ABM_UT_SEND_SUPC_CONN,          /* 7 */
    ABM_UT_FUNC_NUM
} abm_ut_app_func_enum;

typedef enum
{
    ABM_NVRAM_PS_LID,
    ABM_NVRAM_PS_QOS_LID,
    ABM_NVRAM_TOTAL_LID
} abm_nvram_lid_enum;

typedef enum
{
    ABM_RET_OK                  = CBM_OK,  /* success */
    ABM_RET_ERROR               = CBM_ERROR,
    ABM_RET_LIMIT_RESOURCE      = CBM_LIMIT_RESOURCE,
    ABM_RET_INVALID_ACCT_ID     = CBM_INVALID_ACCT_ID, /* invalid application id*/
    ABM_RET_INVALID_SIM_ID      = CBM_INVALID_SIM_ID, /* invalid SIM id */
    ABM_RET_BEARER_FAIL         = CBM_BEARER_FAIL, /* bearer fail */
    ABM_RET_REACTIVE            = CBM_DISC_BY_CM - 1,
    ABM_RET_ACTIVE              = CBM_DISC_BY_CM - 2,
    ABM_RET_NOT_DONE            = CBM_DISC_BY_CM - 3,
    ABM_RET_TOTAL
} abm_state_result_error_enum;

#endif /* _ABM_DEF_H */ 

