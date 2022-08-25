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
 *  CallLogConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_CALL_LOG_CONFIG_H
#define MMI_CALL_LOG_CONFIG_H


#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "MMI_features.h"
#include "CallLogSrvIprot.h"
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Internal Compile Option                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif 

#ifdef __MMI_CLOG_DEBUG__
// #define __MMI_CLOG_PRINT__
// #define __MMI_CLOG_SIM_SYNC_TEST__
//#define __MMI_CLOG_REVISE_LOGS_TEST__
#endif /* __MMI_CLOG_DEBUG__ */ 

#if (defined(__MMI_VUI_HOMESCREEN__) || \
    defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
#ifndef __MMI_CLOG_ADP__
#define __MMI_CLOG_ADP__
#endif 
#endif 

/*  when support AT Command to operate Calllog, we should receive Calllog Service's event to refresh screen. 
 *  Currently, only AT Command can be excuted in background; __ULC_AT__ means Not support AT clog command.
 *  If still find other method to operate Calllog in background, we should modify this compile option dependency
 */
#if !defined(__ULC_AT__) || defined(__MMI_CLOG_MARK_SEVERAL__)
#ifndef __MMI_CLOG_EVENT_REFRESH_SUPPORT__
#define __MMI_CLOG_EVENT_REFRESH_SUPPORT__
#endif
#endif /* __ULC_AT__ */


#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))
#ifndef __MMI_CLOG_ACCESSORIES__
#define __MMI_CLOG_ACCESSORIES__
#endif
#endif

#if defined(__MMI_MAINLCD_96X64__)
  #define __MMI_CLOG_FPBW__
#endif /*__MMI_MAINLCD_96X64__*/

#if defined(__MMI_CLOG_SLIM__)
    #define __MMI_CLOG_COMPUND_ACTION_RESPOND_HOOK_KEY__
    #define __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__
    #define __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__    
  #if !defined(__MMI_CLOG_FPBW__)
    #define __MMI_CLOG_COMPUND_ACTION_EDIT_BEFORE_CALL__
    #define __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__
    #define __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__
  #endif /*__MMI_MAINLCD_96X64__*/
#endif /*__MMI_CLOG_SLIM__*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/* Internal ASSERT, can turn off it to save code size, or can add dump info before ASSERT */
#ifdef __MMI_CLOG_DEBUG__

#define MMI_CLOG_ASSERT(X)                          MMI_ASSERT(X)
#define MMI_CLOG_IT_ASSERT(X)                       MMI_ASSERT(X)

#define MMI_CLOG_TRACE(X)                           MMI_TRACE X
#define MMI_CLOG_IT_TRACE(X)                        MMI_TRACE X

#define MMI_CLOG_PARAM_CHECK(X, Y)                  MMI_CLOG_ASSERT(!(X))

#else /* __MMI_CLOG_DEBUG__ */

#ifndef __MMI_CLOG_SLIM__

#define MMI_CLOG_ASSERT(X)                          MMI_ASSERT(X)
#define MMI_CLOG_IT_ASSERT(X)                       do{}while(0)

#define MMI_CLOG_TRACE(X)                           MMI_TRACE X
#define MMI_CLOG_IT_TRACE(X)                        MMI_TRACE X

#define MMI_CLOG_PARAM_CHECK(X, Y)                  do{if ((X)) return (Y); }while(0)

#else /* __MMI_CLOG_SLIM__ */

#define MMI_CLOG_ASSERT(X)                          do{}while(0)
#define MMI_CLOG_IT_ASSERT(X)                       do{}while(0)

#define MMI_CLOG_TRACE(X)                           MMI_TRACE X
#define MMI_CLOG_IT_TRACE(X)                        MMI_TRACE X //do{}while(0)

#define MMI_CLOG_PARAM_CHECK(X, Y)                  do{}while(0)

#endif /* __MMI_CLOG_SLIM__ */

#endif /* __MMI_CLOG_DEBUG__ */


/*----------------------------------------------------------------------------*/
/* Trace                                                                      */
/*----------------------------------------------------------------------------*/
/* Trace group, easy to change it */
#define MMI_CLOG_TRC_INFO                               TRACE_GROUP_9
#define MMI_CLOG_TRC_WARNING                            TRACE_GROUP_9
#define MMI_CLOG_TRC_ERROR                              TRACE_GROUP_9

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
/*
 * For customer: 
 * Only the following style combinations have passed the SQC and reach MP quality,
 * it's strongly recommended not to modify it, or we'll not ensure the quality 
 * as we not SQC it due to so many small combinations and some style such as SRV_CLOG_STYLE_MERGE_THREAD
 * may be supported in the future.
 * If really need, please let us know and schedule SQC for it or make sure to apply
 * enough test to qulity it.
 * thanks
 */

/* The limitation style of log number */
#define MMI_CLOG_STYLE_NUM                                                                       \
                                                (SRV_CLOG_STYLE_NUM_TOTAL_LIMITED |              \
                                                 SRV_CLOG_STYLE_NUM_TYPE_LIMITED)
/* The Merge style of log data */
#if defined(__OP02__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#define MMI_CLOG_STYLE_MERGE                    (0)  /* don't merge logs */
#else
#define MMI_CLOG_STYLE_MERGE                                                                     \
                                                (SRV_CLOG_STYLE_MERGE_IN_SIM_ID |                \
                                                 SRV_CLOG_STYLE_MERGE_IN_LOG_TYPE |              \
                                                 SRV_CLOG_STYLE_MERGE_BY_PHB_ID |                \
                                                 SRV_CLOG_STYLE_MERGE_IN_SUB_TYPE)
#endif /* __OP02__ || __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__ */





/* The PHB sync style of PHB sync feature */
#define MMI_CLOG_STYLE_PHB_SYNC                                                                  \
                                                (SRV_CLOG_STYLE_PHB_SYNC_ADD |                   \
                                                 SRV_CLOG_STYLE_PHB_SYNC_DELETE |                \
                                                 SRV_CLOG_STYLE_PHB_SYNC_UPDATE)

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
/* The SIM sync style of SIM sync feature */
#define MMI_CLOG_STYLE_SIM_SYNC                                                                  \
                                                (SRV_CLOG_STYLE_SIM_SYNC_READ |                  \
                                                 SRV_CLOG_STYLE_SIM_SYNC_WRITE |                 \
                                                 SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH |           \
                                                 SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD)

#else /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

/* The SIM sync style of SIM sync feature */
#define MMI_CLOG_STYLE_SIM_SYNC                      (0)

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

#ifdef __MMI_CLOG_SIM_SYNC_TEST__

/* For easy test without SIM card changed, temp to remark SIM sync style */
#ifdef MMI_CLOG_STYLE_SIM_SYNC
#undef MMI_CLOG_STYLE_SIM_SYNC
#define MMI_CLOG_STYLE_SIM_SYNC                                                                  \
                                                (SRV_CLOG_STYLE_SIM_SYNC_READ |                  \
                                                 SRV_CLOG_STYLE_SIM_SYNC_WRITE |                 \
                                                 SRV_CLOG_STYLE_SIM_SYNC_FORCE_SYNC |            \
                                                 SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH |           \
                                                 SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD)
#endif /* MMI_CLOG_STYLE_SIM_SYNC */ 
#endif /* __MMI_CLOG_SIM_SYNC_TEST__ */ 

#ifdef __MMI_CLOG_TAB_SUPPORT__

/* The default layout style when enter CallLog from mainmenu */
#define  MMI_CLOG_MAINMENU_DEF_LT_TYPE               (MMI_CLOG_LT_TYPE_TAB)     /* MMI_CLOG_LT_TYPE_TAB */
/* The default log list or tab page to be shown when enter from mainmenu */
#define  MMI_CLOG_MAINMENU_DEF_LT_ID                 (MMI_CLOG_LT_ID_DIALED_CALL)

/* The default layout style when enter CallLog by sendkey */
#define  MMI_CLOG_SENDKEY_DEF_LT_TYPE                (MMI_CLOG_LT_TYPE_TAB)
/* The default log list to be show when enter from sendkey */
#ifdef __OP01__   /* For CMCC */
#define  MMI_CLOG_SENDKEY_DEF_LT_ID                  (MMI_CLOG_LT_ID_ALL_CALL)
#else 
#define  MMI_CLOG_SENDKEY_DEF_LT_ID                  (MMI_CLOG_LT_ID_DIALED_CALL)
#endif /* __OP01__ */

#else /* __MMI_CLOG_TAB_SUPPORT__ */ 

/* The default layout style when enter CallLog from mainmenu */
#define  MMI_CLOG_MAINMENU_DEF_LT_TYPE               (MMI_CLOG_LT_TYPE_LIST)
/* The default log list or tab page to be shown when enter from mainmenu */
#define  MMI_CLOG_MAINMENU_DEF_LT_ID                 (MMI_CLOG_LT_ID_UNKNOWN)   /* Main menu */

/* The default layout style when enter CallLog by sendkey */
#define  MMI_CLOG_SENDKEY_DEF_LT_TYPE                (MMI_CLOG_LT_TYPE_LIST)
/* The default log list to be show when enter from sendkey */
#define  MMI_CLOG_SENDKEY_DEF_LT_ID                  (MMI_CLOG_LT_ID_ALL_CALL)  /* No use for List style */

#endif /* __MMI_CLOG_TAB_SUPPORT__ */ 

/* Default viewer mode */
#define MMI_CLOG_VR_DEF_MODE                         (MMI_CLOG_VR_MODE_FLAT)
/* Default viewer style */
#define MMI_CLOG_VR_DEF_STYLE                        (MMI_CLOG_VR_STYLE_FLAT)

/* Max number of APP instance */
#define MMI_CLOG_INST_MAX_NUM                        (1)
/* Max nubmer of layout instance, only one layout screen is needed in one APP instance
   when support Mark Several feature, we should need two layout screen in one APP instance,
   one for layout list screen, another for Mark Serveral screen */
#ifdef __MMI_CLOG_MARK_SEVERAL__
#define MMI_CLOG_LT_INST_MAX_NUM                     (MMI_CLOG_INST_MAX_NUM * 2)
#else
#define MMI_CLOG_LT_INST_MAX_NUM                     (MMI_CLOG_INST_MAX_NUM)
#endif
/* Max number of action instance, two action instances are needed in one APP instance, 
   one for layout option menu, one for viewer option menu */
#define MMI_CLOG_ACT_INST_MAX_NUM                    (MMI_CLOG_INST_MAX_NUM * 2)
/* Max number of option menu instance, only one instance needed in one APP instance 
   as it's option menu and shall be auto closed when select one menu item */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define MMI_CLOG_OP_INST_MAX_NUM                     (MMI_CLOG_INST_MAX_NUM * 2)
#else
#define MMI_CLOG_OP_INST_MAX_NUM                     (MMI_CLOG_INST_MAX_NUM)
#endif
/* Max number of viewer instance, only one viewer screen is needed in one APP instance */
#define MMI_CLOG_VR_INST_MAX_NUM                     (MMI_CLOG_INST_MAX_NUM)
/* Max layout page ids supported */
#ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__
#define MMI_CLOG_LT_ID_MAX_NUM                          (MMI_CLOG_LT_ID_ALL_CALL /* MMI_CLOG_LT_ID_MAX_ITEM */) /* not support reject now */
#else /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
#define MMI_CLOG_LT_ID_MAX_NUM                          (MMI_CLOG_LT_ID_MAX_ITEM) /* not support reject now */
#endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

#endif /* MMI_CALL_LOG_CONFIG_H */ 

