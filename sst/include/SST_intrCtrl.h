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
 *   SST_intrCtrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file for non-release version of interrupt control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SST_INTRCTRL_H__
#define __SST_INTRCTRL_H__

#include "emi_sw.h"
#include "us_timer.h"
#include "reg_base.h"

#define __HARD_REAL_TIME_CHECK__

#if defined(MT6238) || defined(MT6239)
#define SET_HW_LIMIT() EMI_DISABLE_GMC_HIGHPRIO(1, 1, 0)
#elif defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
#define SET_HW_LIMIT() EMI_Set_GMCBW_HardMode_NonReentrant()
#else
#define SET_HW_LIMIT() 
#endif 

#if defined(MT6238) || defined(MT6239)
#define RESTORE_HW_LIMIT() EMI_ENABLE_GMC_HIGHPRIO(1, 1, 0)
#elif defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
#define RESTORE_HW_LIMIT() EMI_Set_GMCBW_SoftMode_NonReentrant()
#else
#define RESTORE_HW_LIMIT() 
#endif 

#if defined(__HW_US_TIMER_SUPPORT__)
#define GET_AND_SAVED_TIME(v) do{\
                                 IRQMaskCounter = ust_get_current_time();\
                                 IRQMaskValue = v;\
                              }while(0)

#define GET_CURRENT_TIME(v) do{\
                                v = ust_get_current_time();\
                             }while(0)

#define GET_SAVED_TIME(v,s)  do{\
                                v = IRQMaskCounter;\
                                s = IRQMaskValue;\
                             }while(0)
                             
#define GET_DURATION(d,t1,t2) do{\
                                 d=ust_get_duration(t1,t2);\
                              }while(0)

#else /* __HW_US_TIMER_SUPPORT__ */

#define GET_AND_SAVED_TIME(v) do{\
                                v |= *(volatile kal_uint16 *)(TDMA_base + 0x00) << 16;\
                             }while(0)

#define GET_CURRENT_TIME(v) do{\
                                v = *(volatile kal_uint16 *)(TDMA_base + 0x00);\
                                if(v == 0) {\
                                   v = *(volatile kal_uint16 *)(TDMA_base + 0x00);\
                                }\
                             }while(0)

#define GET_SAVED_TIME(v,s)  do{\
                                v=s>>16;\
                             }while(0)

#define GET_DURATION(d,t1,t2) do{\
                                 if(t2 >= t1)\
                                 {\
                                    d=t2-t1;\
                                 } else {\
                                    d = *(volatile kal_uint16 *)(TDMA_base + 0x04);\
                                    d = (d - t1) +t2;\
                                 }\
                              }while(0)

#endif /* __HW_US_TIMER_SUPPORT__ */

#endif /* __SST_INTRCTRL_H__ */
