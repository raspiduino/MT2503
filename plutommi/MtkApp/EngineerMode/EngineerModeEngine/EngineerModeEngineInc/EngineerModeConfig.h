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
 *  EngineerModeConfig.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_EM_CONFIG_H
#define MMI_EM_CONFIG_H


#include "MMI_features.h"

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Internal Compile Option                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif 

#ifdef __MMI_EM_DEBUG__
//#define some sub option here


#endif /* __MMI_EM_DEBUG__ */ 


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/* 
 * Please note: 
 *
 * 1) Commonly not allow use ASSERT, TRACE in EM to save code sizet as EM is unseless to end users.,
 *
 * 2) To provide these just to speed your IT work and issue solving only,
 * all ASSERT and TRACE should be turned off in custom release load, 
 * and you can ask customer to turn on it here for e-service issue quickly.
 *
 * 3) FORBID to use MMI_ASSERT, MMI_TRACE, MMI_PRINT ... in EM 
 * Please use the ones defined as below as then can be turned off freely to save code size.
 * 
 * MMI_EM_ASSERT:   
 *      Used to check those important cases which can help for issue solving greatly, be very carefully to use it
 * MMI_IT_ASSERT:
 *      User to check common case which is valuable mainly in IT stage and bring little value on MP version
 *
 * MMI_EM_TRACE:
 *      For those trace can bring important value and can speed issue solving in long term.
 * MMI_EM_IT_TRACE:
 *      For IT stage only, unuseless almostly after feature MP
 *
 * MMI_EM_PARAM_CHECK: 
 *      Not use this for normally parame check which can be true according to your design. 
 *      just use it to remove those "useless" ones which not harm the quilty even remove it. 
 *      ex. MMI_EM_PARAM_CHECK(X); it can work only becaus the RD set it to wrong value himself.
 *      
 *      To check if parameter is valid called by programming skill which has valuable only in IT stage
 *      As lots of parameter check code is to avoid facitious techical programming error, 
 *      these error can be solved foever after IT or SQC while the check code is exist and waste code size forever,
 *      use it can help to remove these waste easily.
 *
 *
*/

/* Please apply these macro to those code which can be removed on customer release */

#ifdef __MMI_EM_DEBUG__

#define MMI_EM_ASSERT(X)                            MMI_ASSERT(X)
#define MMI_EM_IT_ASSERT(X)                         MMI_ASSERT(X)

#define MMI_EM_TRACE(X)                             MMI_TRACE X
#define MMI_EM_IT_TRACE(X)                          MMI_TRACE X

#define MMI_EM_PARAM_CHECK(X, Y)                    MMI_EM_ASSERT(!(X))

#else /* __MMI_EM_DEBUG__ */

#if (defined(__MTK_INTERNAL__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_SLIM_ENGINEER_MODE__ */

/*Turn off them to save code size */
#define MMI_EM_ASSERT(X)                            do{}while(0)
#define MMI_EM_IT_ASSERT(X)                         do{}while(0)

#define MMI_EM_TRACE(X)                             do{}while(0)
#define MMI_EM_IT_TRACE(X)                          do{}while(0)

#define MMI_EM_PARAM_CHECK(X, Y)                    do{}while(0)

#endif /* __MTK_INTERNAL__ && !__MMI_SLIM_ENGINEER_MODE__ */

#endif /* __MMI_EM_DEBUG__ */


/*----------------------------------------------------------------------------*/
/* Trace                                                                      */
/*----------------------------------------------------------------------------*/
/*
 *  Trace group, easy to change it, please use this define.
 *  The trace style should be:
 *
 *      TRC_MSG(MMI_EM_[L1 menu]_[item name]_xxx, "[EM][L1 menu][item name] xxx xxx xxx")
 * ex.
 *      TRC_MSG(MMI_EM_MISC_ADC_SHOW_VALUE, "[EM][MISC][ADC]mmi_em_misc_adc_show_value(adc=%d)")
 *
 *
 */

#define MMI_EM_TRC_INFO                               MMI_COMMON_TRC_G8_EM
#define MMI_EM_TRC_WARNING                            MMI_COMMON_TRC_G8_EM
#define MMI_EM_TRC_ERROR                              MMI_COMMON_TRC_G8_EM

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/


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

#endif /* MMI_EM_CONFIG_H */ 

