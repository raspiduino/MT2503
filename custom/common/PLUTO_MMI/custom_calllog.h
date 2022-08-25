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
 * custom_calllog.h 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef CUSTOM_CALL_LOG_H
#define CUSTOM_CALL_LOG_H

#ifdef __CLOG_STORAGE_BY_MMI__  /* Only apply this configuration for CallLog V02 version which storage calllog in PLUTO_MMI or COSMOS_MMI layer */


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Usage comments                                                             */
/*----------------------------------------------------------------------------*/
/* 1. Naming rule
 *    1) If named like MMI_CLOG_XXX, it's a fixed dependency, NO customlized.
 *    2) If named like CUSTOM_CLOG_XXX, it can be customilized.
 *
 * 2. Number abilities
 *    1) Please choose a proper log number abilities after belence the gains and the cost,
 *        more logs need more ROM/RAM size and may cost low performance, 
 *        some rough cost for reference:
 *       ->. 1 log needs one NVRAM record(~40 size), some RAM size (?)  
 *       ->. 1 log cache need RAM size (?)
 *       ->. 
 *    2) suggestion total log number no more than 750 (Missed/Dialed/Received: 250)
 *    3) The max unread number and total number of missed call is no more than 250 as use U8 type, 
 *      the value larger than 250 are reserved for other usage in the future.
 *    4) The number length is sync to PHB
 *
 * 3. Name abilities
 *    In sync with PHB scenario, CallLogApp does not same name information but to get it 
 *    from PHB, so it use PHB configuration for name abilities.
 *
 * 4. Styles
 *
 *
 *
 *
 */


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/






/*---------------------- Number abilities ------------------------------------*/
/* Usage:
 * 1. Customer can set the max log number supported in CallLogApp.
 *
 * 2. The number threholds are split in several levels:
 *    a. Total number of all logs, e.g.  total 100.
 *    b. Total number of each log type from all SIM cards, e.g. call log: 100; sms log: 50.
 *    c. Total number of each log type per SIM card, e.g. SIM1 call log: 50; SIM2 call log 50.
 *    d. Total number of each sub log type per SIM card, e.g, SIM1 missed call log 30, SIM2 dialed call log: 30.
 *   
 * 3. The above number threholds are indenpendent with each others, 
 *    one potential limitation is the number of log from each SIM card should be the same.
 *   
 * 4. Once add a new log, CallLogApp needs to check all these number threholds to  
 *    know if need to delete one oldest log and which log is the oldest one.
 *
 * 5. Customer can choice if to use MAX_PHB_LN_ENTRY as the total number therhold,
 *    if use it, the load should be rebuilded once it' s changed, but easy to know where it is,
 *    if not, customer can set a number in the follow, just to remake CallLogApp yet.
 *
 */



/* Its count is CUSTOM_CLOG_MAX_LOG_NUM or same as CUSTOM_CLOG_MAX_LOG_NUM */


#ifdef __GEMINI__

#if (GEMINI_PLUS == 4)

#define CUSTOM_CLOG_SIM_NUM                     (4)

#elif (GEMINI_PLUS == 3)

#define CUSTOM_CLOG_SIM_NUM                     (3)

#else /* GEMINI_PLUS == 2 */

#define CUSTOM_CLOG_SIM_NUM                     (2)

#endif /* GEMINI_PLUS */

#else /* __GEMINI__ */

#define CUSTOM_CLOG_SIM_NUM                     (1)

#endif /* __GEMINI__ */


#define CUSTOM_CLOG_MAX_DIALED_CLT_NUM                      (MAX_PHB_LN_ENTRY * CUSTOM_CLOG_SIM_NUM)
#define CUSTOM_CLOG_MAX_MISSED_CLT_NUM                      (MAX_PHB_LN_ENTRY * CUSTOM_CLOG_SIM_NUM)
#define CUSTOM_CLOG_MAX_RECVED_CLT_NUM                      (MAX_PHB_LN_ENTRY * CUSTOM_CLOG_SIM_NUM)
#define CUSTOM_CLOG_MAX_REJED_CLT_NUM                       (0)

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define CUSTOM_CLOG_NUM_PER_RECORD  3
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/* dependency */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define CUSTOM_CLOG_MAX_CLT_NUM                             \
                                    CUSTOM_CLOG_MAX_DIALED_CLT_NUM +\
                                    CUSTOM_CLOG_MAX_MISSED_CLT_NUM + \
                                    CUSTOM_CLOG_MAX_RECVED_CLT_NUM
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define CUSTOM_CLOG_MAX_CLT_NUM                             \
                                    CUSTOM_CLOG_MAX_DIALED_CLT_NUM +\
                                    CUSTOM_CLOG_MAX_MISSED_CLT_NUM + \
                                    CUSTOM_CLOG_MAX_RECVED_CLT_NUM + \
                                    CUSTOM_CLOG_MAX_REJED_CLT_NUM
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
                                    
/* dependency */
#define CUSTOM_CLOG_MAX_SLT_NUM                             (0)
//dependency
#define CUSTOM_CLOG_MAX_NWPD_NUM                            (0)

/* The max number of all logs supported in CallLog application including all types from all SIM cards */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define CUSTOM_CLOG_MAX_LOG_NUM     (CUSTOM_CLOG_MAX_CLT_NUM )

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define CUSTOM_CLOG_MAX_LOG_NUM                                 \
                                    CUSTOM_CLOG_MAX_CLT_NUM +   \
                                    CUSTOM_CLOG_MAX_SLT_NUM +   \
                                    CUSTOM_CLOG_MAX_NWPD_NUM    
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/* The max count of timestamp and duration for one same log number, after meger; we name it as log group
   the min value of it is 1, not smaller than 1; 
   if don't support calllog merger, such as in OP02 project, should define it as 1 to save RAM and ROM */
#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__OP02__))
#define CUSTOM_CLOG_TIME_DETAIL_MAX_NUM       (5)
#else
#define CUSTOM_CLOG_TIME_DETAIL_MAX_NUM       (5)
#endif
#if defined(__BT_PBAP_CLIENT__)
#define MMI_CLOG_PBAPC_ENTRIES              30
#define MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES  MMI_CLOG_PBAPC_ENTRIES
#define MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES  MMI_CLOG_PBAPC_ENTRIES
#define MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES  MMI_CLOG_PBAPC_ENTRIES
#define MMI_CLOG_PBAPC_ALL_CALL_ENTRIES                                 \
	                                       MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES +\
	                                       MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES +\
	                                       MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES

#endif

/*---------------------- Name abilities --------------------------------------*/




/*---------------------- Style -------------------------------------*/


#endif /* __CLOG_STORAGE_BY_MMI__ */

#endif /* CUSTOM_CALL_LOG_H */



