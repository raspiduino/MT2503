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
 *  CallLogSrvConfig.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_CONFIG_H
#define SRV_CALL_LOG_CONFIG_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_common_app_trc.h"

#include "CallLogSrvGprot.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/*----------------------------------------------------------------------------*/
/* Internal Compile Option                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif 

#ifdef __SRV_CLOG_DEBUG__
#define __SRV_CLOG_DUMP__
//#define __SRV_CLOG_MEM_DEBUG__
//#define __SRV_CLOG_UT__
#endif /* __SRV_CLOG_DEBUG__ */ 


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
#ifndef __ULC_AT__
#ifndef __MMI_CLOG_ATCMD_SUPPORT__
#define __MMI_CLOG_ATCMD_SUPPORT__
#endif 
#endif
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


#ifndef __MMI_CLOG_PHB_SYNC_SUPPORT__
//#define __MMI_CLOG_PHB_SYNC_SUPPORT__
#endif

   
/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define  SRV_CLOG_MAX2(a, b)                        ((a) > (b) ? (a) : (b))
#define  SRV_CLOG_MAX3(a, b, c)                     (SRV_CLOG_MAX2(SRV_CLOG_MAX2(a, b), c))
#define  SRV_CLOG_MAX4(a, b, c, d)                  (SRV_CLOG_MAX2(SRV_CLOG_MAX2(a, b), SRV_CLOG_MAX2(c, d)))

/*----------------------------------------------------------------------------*/
/* TRACE                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_TRC_INFO                           MMI_COMMON_TRC_G4_CLOG
#define SRV_CLOG_TRC_WARNING                        MMI_COMMON_TRC_G4_CLOG
#define SRV_CLOG_TRC_ERROR                          MMI_COMMON_TRC_G4_CLOG


#ifndef __MTK_TARGET__
#define SRV_CLOG_TS(_a, _b, _c)                     (_c)

#ifdef __SRV_CLOG_DEBUG__
#define SRV_CLOG_TRC(X)                             do{srv_clog_print X; srv_clog_print("\n");}while(0)
#else 
#define SRV_CLOG_TRC(X)
#endif 

#else /* __MTK_TARGET__ */ 

#ifdef __SRV_CLOG_DEBUG__
#define SRV_CLOG_TS(_a, _b, _c)                     _a, _b
#define SRV_CLOG_TRC(X)                             MMI_TRACE X
#else
#define SRV_CLOG_TS(_a, _b, _c)                     (_c)
#define SRV_CLOG_TRC(X)                             
#endif

#endif /* __MTK_TARGET__ */ 


#ifdef __SRV_CLOG_DUMP__
/* Modify here to turn on dump or not */
#define SRV_CLOG_TARGET_DUMP_GRP                    (SRV_CLOG_DEBUG_MODE_ALL)
#define SRV_CLOG_MODIS_DUMP_GRP                     0 //(SRV_CLOG_DEBUG_MODE_ALL)

#define SRV_CLOG_DUMP(X)                            srv_clog_sel_dump(X)
#define SRV_CLOG_DUMP_LOG(idx, si_log)              srv_clog_si_dump_log(idx, si_log)  /* idx only for print */

#else /* __SRV_CLOG_DUMP__ */ 

#define SRV_CLOG_TARGET_DUMP_GRP                    (0)
#define SRV_CLOG_MODIS_DUMP_GRP                     (0)

#define SRV_CLOG_DUMP(X)                            do{}while(0)  
#define SRV_CLOG_DUMP_LOG(idx, si_log)              do{}while(0)

#endif /* __SRV_CLOG_DUMP__ */ 



#ifdef __MMI_CLOG_DEBUG__

#define SRV_CLOG_ASSERT(X)                          do{if (!(X)) SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_ALL); MMI_ASSERT(X); }while(0)
#define SRV_CLOG_IT_ASSERT(X)                       SRV_CLOG_ASSERT(X)

#define SRV_CLOG_TRACE(X)                           MMI_TRACE X
#define SRV_CLOG_IT_TRACE(X)                        MMI_TRACE X

#define SRV_CLOG_PARAM_CHECK(X, Y)                  SRV_CLOG_ASSERT(!(X))

#else /* __MMI_CLOG_DEBUG__ */

#ifndef __MMI_CLOG_SLIM__

#define SRV_CLOG_ASSERT(X)                          MMI_ASSERT(X)
#define SRV_CLOG_IT_ASSERT(X)                       do{}while(0)

#define SRV_CLOG_TRACE(X)                           MMI_TRACE X
#define SRV_CLOG_IT_TRACE(X)                        MMI_TRACE X

#define SRV_CLOG_PARAM_CHECK(X, Y)                  do{if ((X)) return (Y); }while(0)

#else /* __MMI_CLOG_SLIM__ */

#define SRV_CLOG_ASSERT(X)                          do{}while(0)
#define SRV_CLOG_IT_ASSERT(X)                       do{}while(0)

#define SRV_CLOG_TRACE(X)                           MMI_TRACE X
#define SRV_CLOG_IT_TRACE(X)                        MMI_TRACE X //do{}while(0)

#define SRV_CLOG_PARAM_CHECK(X, Y)                  do{}while(0)

#endif /* __MMI_CLOG_SLIM__ */

#endif /* __MMI_CLOG_DEBUG__ */


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*---------------------- Log number ------------------------------------------*/

/*
 * This constant is to define the max type operation in service, currently all type operation is base on
 * call log type only, no need to check other codes 
 * Please make sure it's the max value in really as we need to use it as memory size allocated to save memory.
 */
#ifdef __SRV_CLOG_UT__
#define SRV_CLOG_OP_TYPE_MAX_NUM					(SRV_CLOG_LOG_MAX_NUM)
#else /* __SRV_CLOG_UT__ */ 
#define SRV_CLOG_OP_TYPE_MAX_NUM                \
                    SRV_CLOG_MAX4(SRV_CLOG_MAX_DIALED_CLT_NUM, SRV_CLOG_MAX_MISSED_CLT_NUM, SRV_CLOG_MAX_RECVED_CLT_NUM, SRV_CLOG_MAX_REJED_CLT_NUM)
#endif /* __SRV_CLOG_UT__ */ 

/*---------------------- Instance --------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

#define SRV_CLOG_MAX_INST_NUM                       (1)
#define SRV_CLOG_INST_MAX_PRE_DEF_NUM               (1)

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

#ifdef __LOW_COST_SUPPORT_COMMON__
#define SRV_CLOG_MAX_INST_NUM                       (4)
#define SRV_CLOG_INST_MAX_PRE_DEF_NUM               (1)
#else
#define SRV_CLOG_MAX_INST_NUM                       (5)
#define SRV_CLOG_INST_MAX_PRE_DEF_NUM               (3)
#endif

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- Context ---------------------------------------------*/
#define SRV_CLOG_LOG_ID_STEP_LEN                    (1)        /* Max number allow AT commond to insert */
#define SRV_CLOG_MAX_NEW_LOG_BEFORE_READY           (100)
#define SRV_CLOG_LOG_ID_START                       (SRV_CLOG_MAX_NEW_LOG_BEFORE_READY * SRV_CLOG_LOG_ID_STEP_LEN)     /* The max new log number can be added before service is ready */

/*---------------------- Memory Manager --------------------------------------*/
#ifdef __SRV_CLOG_UT__
#define  SRV_CLOG_MEM_POOL_DYNC_SIZE				(1028)  /* temp for test */
#else 
#define  SRV_CLOG_MEM_POOL_DYNC_SIZE				(0)   
#endif 

/*---------------------- Job Manager -----------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__

#ifdef __SRV_CLOG_UT__
#define SRV_CLOG_MAX_JOB_NUM						(200)   /* temp for test */
#else 

#ifdef __LOW_COST_SUPPORT_COMMON__
#define SRV_CLOG_MAX_JOB_NUM						(10)
#else
#define SRV_CLOG_MAX_JOB_NUM						(40)
#endif
#endif 

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- Style -----------------------------------------------*/
#define SRV_CLOG_STL_MAX_BIT_SLOT_NUM               (1)

/*---------------------- Storage Manager--------------------------------------*/
/* For load logs */
/* max num of multiple access operation in one blocking process
   better to use control buffer less than 1K,
   should no more than 2014 / sizeof(srv_clog_st_log_struct) */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM     ((1 * 1024) / NVRAM_EF_CLOG_LOG_SIZE)   /* max multiple logs every read */
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define SRV_CLOG_ST_MULTI_LOGS_PER_LOAD_MAX_NUM     ((1 * 1024) / sizeof(srv_clog_st_log_struct))   /* max multiple logs every read */
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define SRV_CLOG_ST_MULTI_OP_MAX_NUM                (5)
#define SRV_CLOG_ST_SINGLE_OP_MAX_NUM               (20)    /* max single log store access */


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif 

#endif /* SRV_CALL_LOG_CONFIG_H */ 

