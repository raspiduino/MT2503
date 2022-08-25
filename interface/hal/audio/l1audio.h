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
 *  l1sp.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   Audio Task interface definition
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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

#ifndef L1AUDIO_H
#define L1AUDIO_H

//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"

#ifdef __MTK_TARGET__
//  #include "kal_release.h"
#if !defined(IC_BURNIN_TEST) && !defined(__MAUI_BASIC__)
//  #include "l1audio_trace.h"
#endif
  #include "med_status.h"
//  #include "app_buff_alloc.h"
//#ifndef MED_NOT_PRESENT
  #include "fs_type.h"
  #include "fsal.h"
//#endif

//  #include "stack_common.h"
//  #include "stack_msgs.h"
//  #include "app_ltlcom.h"       /* Task message communiction */
//  #include "syscomp_config.h"
//  #include "task_config.h"      /* Task creation */
//  #include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
//  #include "event_shed.h"       /* Event scheduler */
//  #include "stack_timer.h"      /* Stack timer */
#else
//  #include "kal_non_specific_general_types.h"
  #include "med_status.h"
  #include "fsal.h"
#endif

//#include "mp4_common.h"
//#include "BesSound_exp.h"

//#include "stack_config.h"

/* ------------------------------------------------------------------------------ */
/*  Function ptr prototype [HAL rule]                                             */ 
/* ------------------------------------------------------------------------------ */
// For In Process Call
typedef void (*in_proc_call_type)( kal_uint32 arg1, void* arg2 );

typedef void*      (*fp_audio_alloc_aud_mem)(kal_uint32 size, char* file_p, long line_p);
typedef void       (*fp_audio_free_aud_mem)(void** ptr, char* file_p, long line_p);
typedef void       (*fp_audio_set_path_volume)(kal_uint8 audio_mode);
typedef kal_uint8  (*fp_audio_get_active_mode)(void);
typedef void       (*fp_send_proc_call_req)(module_type src_mod_id, in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
typedef kal_bool   (*fp_get_meta_data_file)(kal_wchar *filename, void *aud_info_p);
typedef kal_bool   (*fp_get_meta_data_array)(kal_char *ptr, kal_uint32 size, void *aud_info_p);
typedef void       (*fp_send_classk_state)(kal_bool classk_state);
typedef kal_uint32 (*fp_get_vbat_value)(void);
typedef void       (*fp_send_vib_spk_is_calib)(void);

extern void *audio_alloc_ext_mem (kal_int32 size,char* file_p, long line_p);
extern void *audio_alloc_ext_mem_cacheable (kal_int32 size,char* file_p, long line_p);
extern void  audio_free_ext_mem (void **ptr,char* file_p, long line_p);
extern  void audio_vib_spk_is_calib();

#define audio_alloc_mem(size)	            audio_alloc_ext_mem(size,__FILE__,__LINE__)
#define audio_alloc_mem_cacheable(size)   audio_alloc_ext_mem_cacheable(size,__FILE__,__LINE__)
#define audio_free_mem(ptr)               audio_free_ext_mem(ptr,__FILE__,__LINE__)


#if !defined(DSP_DEBUG_LOG_AND_DUMP)
#define  SHERIF_WRITE(addr, value)   { *addr  = value; }
#define  SHERIF_AND(addr, value)     { *addr &= value; }
#define  SHERIF_OR(addr, value)      { *addr |= value; }
#else 
extern void sherif_assert_dump();
extern void sherif_write_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p); 
extern void sherif_and_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p); 
extern void sherif_or_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p); 
#define  SHERIF_WRITE(addr, value) sherif_write_dump(addr,value,__FILE__,__LINE__)
#define  SHERIF_AND(addr, value) sherif_and_dump(addr,value,__FILE__,__LINE__)
#define  SHERIF_OR(addr, value) sherif_or_dump(addr,value,__FILE__,__LINE__)
#endif

typedef struct {
   fp_audio_alloc_aud_mem      alloc_mem;          
   fp_audio_alloc_aud_mem      alloc_mem_cacheable;                                    
   fp_audio_free_aud_mem       free_mem;  
   fp_audio_set_path_volume    set_path_volume;
   fp_audio_get_active_mode    get_active_mode; 
   fp_send_proc_call_req       send_proc_call;
   fp_send_proc_call_req       send_proc_call2;
   fp_get_meta_data_file       get_meta_file;
   fp_get_meta_data_array      get_meta_array;
   fp_get_vbat_value           get_vbat_value;
   fp_send_classk_state        send_classk_state;
   fp_send_vib_spk_is_calib    send_vib_spk_is_calib;
} Media_Func_Reg_Type;

void  Audio_MedFuncReg(Media_Func_Reg_Type *func);

typedef void       (*fp_a2dp_set_br_from_qos_init)(kal_uint32 bit_rate_cur);
typedef kal_uint32 (*fp_a2dp_set_br_from_qos)(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32));

typedef struct {
   fp_a2dp_set_br_from_qos_init  a2dp_set_br_init;          
   fp_a2dp_set_br_from_qos       a2dp_set_br;
} BT_Func_Reg_Type;

//#define __AT_AUDIO_CMD__
void  Audio_BTFuncReg(BT_Func_Reg_Type *func);

/* ------------------------------------------------------------------------------ */
/*  Audio memory allocation.                                                      */
/* ------------------------------------------------------------------------------ */
#if defined(MT6276)
   #define  MAX_AUDIO_FUNCTIONS     30
#else
   #define  MAX_AUDIO_FUNCTIONS     18
#endif

#if defined(__AUDIO_AT_CMD__)
typedef struct {
  kal_bool   VBTON;
  kal_bool   VBTSYNC;
  kal_bool   LPK_U2D; //PCMIF loopback UL-->DL
  kal_uint16 PCM_CK_MODE;
} AFE_PCMIF_STRUCT_T;

typedef struct {
	 kal_bool EC_On;
	 kal_bool UL_NR_On;
	 kal_bool DL_NR_On;
} SPE_ECNRPARAM_STRUCT_T;

	kal_bool AFE_SetPCMBitClk(AFE_PCMIF_STRUCT_T *pcmcfg);
	void AFE_GetPCMBitClk(AFE_PCMIF_STRUCT_T *pcmcfg);
	void L1SP_SetECOn(kal_bool ec_on);
	void L1SP_SetNROn(kal_bool ul_nr_on,kal_bool dl_nr_on  );
	void L1SP_GetECNRStatus(SPE_ECNRPARAM_STRUCT_T *ecnrcfg);

#endif

/* ------------------------------------------------------------------------------ */
/*  Audio Function Definition                                                     */
/* ------------------------------------------------------------------------------ */
#define  L1SP_KEYTONE         0
#define  L1SP_TONE            1
#define  L1SP_SPEECH          2
#define  L1SP_SND_EFFECT      3
#define  L1SP_AUDIO           4
#define  L1SP_VOICE           5
#define  L1SP_DAI             6
#define  L1SP_LINEIN          7
#define  L1SP_MAX_AUDIO       8

#define  SRC_VOICE_DAC        0
#define  SRC_AUDIO_DAC        1
#define  SRC_EXT_INPUT        2

#define  SND_SRC_MAP   (kal_uint32)((SRC_VOICE_DAC<<L1SP_KEYTONE*2) |      \
                                    (SRC_VOICE_DAC<<L1SP_TONE*2) |         \
                                    (SRC_VOICE_DAC<<L1SP_SPEECH*2) |       \
                                    (SRC_VOICE_DAC<<L1SP_SND_EFFECT*2) |   \
                                    (SRC_AUDIO_DAC<<L1SP_AUDIO*2) |        \
                                    (SRC_VOICE_DAC<<L1SP_VOICE*2) |        \
                                    (SRC_VOICE_DAC<<L1SP_DAI*2) |          \
                                    (SRC_EXT_INPUT<<L1SP_LINEIN*2))

#define  INVALID_AUDIO_ID        MAX_AUDIO_FUNCTIONS

typedef  void  (*L1Audio_EventHandler)(void*);

typedef enum {
  MEDIA_BGSND,
  MEDIA_PCM_PLAYBACK,
  MEDIA_VM_PLAYBACK
} Media_Func_Type;

kal_int8 L1Audio_Disable_DSPSlowIdle(void);
kal_int8 L1Audio_Enable_DSPSlowIdle(void);

void L1Audio_Register_Handle(Media_Func_Type type, void *hdl);
void L1Audio_UnRegister_Handle(Media_Func_Type type);

void        L1Audio_SendILM(kal_uint16 msg_id, module_type src_module, module_type dst_module, void *local_param_ptr, void *peer_buf_ptr);
kal_uint16  L1Audio_GetAudioID( void );
void        L1Audio_FreeAudioID( kal_uint16 aud_id );
kal_bool    L1Audio_CheckAudioID( kal_uint16 audio_id );
void        L1Audio_SetEventHandler( kal_uint16 audio_id, L1Audio_EventHandler handler );
void        L1Audio_SetEvent( kal_uint16 audio_id, void *data );
void        L1Audio_LSetEvent( kal_uint16 audio_id, void *data );
kal_bool    L1Audio_CheckFlag( kal_uint16 audio_id );
void        L1Audio_SetFlag( kal_uint16 audio_id );
void        L1Audio_ClearFlag( kal_uint16 audio_id );
void        L1Audio_AllowSleep( kal_uint16 audio_id );
void        L1Audio_DisallowSleep( kal_uint16 audio_id );
void        L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData );
void        L1Audio_UnhookHisrHandler( kal_uint16 magic_no );
void        L1Audio_SetPostHisrHandler( L1Audio_EventHandler handler );
void        L1Audio_ResetPostHisrHandler( void );

void        L1Audio_EnterDedicatedMode( void );
void        L1Audio_LeaveDedicatedMode( void );
void        L1Audio_ResetDevice( void );

void        L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info );

#define  NUM_DEBUG_INFO      10
#define  VM_DEBUG_INFO       0
#define  VOIPEVL_DEBUG_INFO  1
#define  AMR_REC_DEBUG_INFO  2
#define  AWB_REC_DEBUG_INFO  3
#define  APM_DEBUG_INFO      4
#define  STEREO_RECORD_INFO  5
#define  AUDIO_DEBUG_MISC    6  // factory mode audio debug parameter 6
#define  CTM_DEBUG_INFO      7
#define  AVB_DEBUG_INFO      8
#define  VM_REC_DEBUG_INFO   9

/* -------------------------------- */
/*  AUDIO_DEBUG_MISC Definition     */
/* -------------------------------- */
#define  AAC_DSCE_CHANNEL_CHANGE 3000
#define  AUDIO_DBG_INFOVAL_AUDLP_DISABLE   32768
#define  AUDIO_DBG_VCP_FDISABLE   2222
#define  AUDIO_DBG_VCP_FENABLE    3333


void        L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO]);
kal_uint16  L1Audio_GetDebugInfo( kal_uint8 index );
/* ------------------------------------------------------------------------------ */
/*  Audio Front End Interface                                                     */
/* ------------------------------------------------------------------------------ */
/* -------------------------------- */
/*  Audio Output Device Definition  */
/* -------------------------------- */
#define  L1SP_BUFFER_0        0x01    /* NOTE: Don't use buffer definition directly   */
#define  L1SP_BUFFER_1        0x02    /*       Use speaker definition below           */
#define  L1SP_BUFFER_ST       0x04
#define  L1SP_BUFFER_EXT      0x08
#define  L1SP_BUFFER_EXT_G    0x10
#define  L1SP_STEREO2MONO     0x20     /* Do not use this term for speaker definition */
#define  L1SP_BUFFER_ST_M     (L1SP_BUFFER_ST|L1SP_STEREO2MONO)
#define  L1SP_EXT_DAC_BUF0    0x40 
#define  L1SP_EXT_DAC_BUF1    0x80

#define  L1SP_LNA_0           0
#define  L1SP_LNA_1           1
#define  L1SP_LNA_DIGITAL     2
#define  L1SP_LNA_FMRR        3

extern const kal_uint8  L1SP_MICROPHONE1;
extern const kal_uint8  L1SP_MICROPHONE2;
extern const kal_uint8  L1SP_SPEAKER1;
extern const kal_uint8  L1SP_SPEAKER2;
extern const kal_uint8  L1SP_LOUD_SPEAKER;


#define  EXT_DAC_I2S          0x1 
#define  EXT_DAC_LINEIN       0x2 
extern const unsigned char  L1SP_EXT_DAC_I2S_BCLK_SCALE;
extern const unsigned char  L1SP_EXT_DAC_STEP; // the minimum step that has change of volume      
extern const unsigned char  L1SP_EXT_DAC_STEP_UNIT; // the times of 0.5dB in the minimum volume change    
extern const unsigned char  L1SP_I2S_INPUT_SCALE;
extern void EXT_DAC_Init( void ); 
extern void EXT_DAC_SetPlaybackFreq( kal_uint16 frequency ); 
extern void EXT_DAC_TurnOnSpeaker( kal_uint8 src, kal_uint8 spk );
extern void EXT_DAC_TurnOffSpeaker( kal_uint8 spk ); 
extern void EXT_DAC_SetVolume( kal_uint8 spk, kal_uint8 vol );
extern void EXT_DAC_FixedLineInGain( kal_uint8 spk );
extern void I2S_Input_GPIO_TurnOn( void );
extern void I2S_Input_GPIO_TurnOff( void );

/* ------------------------------------------------------------------------------ */
/*  Audio Related Global Variables                                                */
/* ------------------------------------------------------------------------------ */
extern const signed short     Speech_Input_FIR_Coeff[6][45];
extern const signed short     Speech_Output_FIR_Coeff[6][45];
extern const unsigned short   Media_Playback_Maximum_Swing;
extern const signed short     Melody_FIR[25];

extern const unsigned short   DG_DL_Speech;
extern const unsigned short   DG_Microphone;
extern const unsigned short   DG_DAF;
extern const unsigned short   DG_MIDI;
extern const unsigned short   DG_IMY;
extern const unsigned short   DG_IMY_NOTE;
extern const unsigned short   DG_SMF_NOTE;
extern const unsigned short   DG_JTS_NOTE;

/* ------------------------------------------------------------------------------ */
/*  Key Tone Interface                                                            */
/* ------------------------------------------------------------------------------ */
void  KT_SetOutputDevice( kal_uint8 device );
void  KT_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration );
void  KT_Stop( void );
void  KT_StopAndWait(void);
void  KT_SetAmplitude( kal_int16 amp );
void  KT_SetFIR( kal_bool enable );
kal_bool KT_IsPlayable(void);

/* ------------------------------------------------------------------------------ */
/*  LINEIN Interface                                                            */
/* ------------------------------------------------------------------------------ */
void LINEIN_SetOutputDevice( kal_uint8 device );
void LINEIN_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void LINEIN_Open( void );
void LINEIN_Close( void );
void LINEIN_MuteSpeaker( kal_bool mute );
#if defined(__GAIN_TABLE_SUPPORT__)
void LINEIN_SetOutputGainControl (kal_uint32 gain);
void LINEIN_SetOutputGainControlDualPath( kal_uint32 ext_amp_gain );
#endif

/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
} L1SP_Tones;

typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
   kal_uint16   freq3;         /* Third frequency                              */
   kal_uint16   freq4;         /* Fourth frequency                             */
} L1SP_QTMF;

/* -------------------------------- */
/*  Example of Tone Definition      */
/* -------------------------------- */
/*
static const L1SP_Tones tone1_gsm[] = { { 425,   0,   0,   0,   0 } };
static const L1SP_Tones tone1_pcs[] = { { 350, 440,   0,   0,   0 } };
static const L1SP_Tones tone2_gsm[] = { { 425,   0, 500, 500,   0 } };
static const L1SP_Tones tone2_pcs[] = { { 480, 620, 500, 500,   0 } };
static const L1SP_Tones tone3_gsm[] = { { 425,   0, 200, 200,   0 } };
static const L1SP_Tones tone3_pcs[] = { { 480, 620, 200, 200,   0 } };
static const L1SP_Tones tone4[]     = { { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone5[]     = { { 425,   0, 200, 200,   1 },
                                        { 425,   0, 200, 200,   2 },
                                        { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone61[]    = { { 950,   0, 330,1000,   0 } };
static const L1SP_Tones tone62[]    = { {1400,   0, 330,1000,   0 } };
static const L1SP_Tones tone63[]    = { {1800,   0, 330,1000,   0 } };
static const L1SP_Tones tone7[]     = { { 425,   0, 200, 600,   1 },
                                        { 425,   0, 200,3000,   2 },
                                        { 425,   0, 200, 600,   3 },
                                        { 425,   0, 200,   0,   0 } };
*/

void  TONE_SetOutputDevice( kal_uint8 device );
void  TONE_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  TONE_Play( const L1SP_Tones *tonelist );
void  TONE_Stop( void );
void  TONE_StopAndWait( void );
void  TONE_SetAmplitude( kal_int16 amp );
void  TONE_SetFIR( kal_bool enable );
void  TONE_SetHandler( void (*handler)(void) );
void  TONE_PlayQTMF( const L1SP_QTMF *tonelist ); /* QTMF Play Interface */
void  DTMF_MCU_StopAndWait( void );


/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
 typedef enum {
  L1SP_NVRAM_INFO_INDEX_UNDEF = 0,
  L1SP_NVRAM_INFO_INDEX_PARAM,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,
  L1SP_NVRAM_INFO_INDEX_HD_RECORD,  
} L1SP_NVRAM_INFO_INDEX;

void        Spc_Speech_On( kal_uint8 RAT_Mode );
void        Spc_Speech_Off( void );
void        Spc_SetMicrophoneVolume( kal_uint8 mic_volume );
void        Spc_SetSidetoneVolume( kal_uint8 sidetone );
void        Spc_Default_Tone_Play(kal_uint8 toneIdx);
void        Spc_Default_Tone_Stop( void );
void        Spc_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ); 
void        Spc_SetInputSource( kal_uint8 src );
void        Spc_SetOutputDevice( kal_uint8 device );
void        Spc_SetSpeechMode_Adaptation( kal_uint8 mode );
void        Spc_ReceiveEMParameter(kal_uint8* buffer, kal_uint16 len);
void        L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index,kal_uint8* buffer, kal_uint16 len);

void        L1SP_SetOutputDevice( kal_uint8 device );
void        L1SP_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void        L1SP_Speech_On( kal_uint8 RAT_Mode );
void        L1SP_Speech_Off( void );

#define L1SP_AFE_MODE_UL_OPEN 0x1
#define L1SP_AFE_MODE_DL_OPEN 0x2
void        L1SP_Afe_On( kal_uint32 afe_mode );  //Modis
void        L1SP_Afe_Off( void );

void        L1SP_SetInputSource( kal_uint8 src );
kal_uint8   L1SP_GetInputSource( void );
void        L1SP_SetMicrophoneVolume( kal_uint8 mic_volume );
kal_uint8   L1SP_GetMicrophoneVolume( void );
void        L1SP_MuteSpeaker( kal_bool mute );
void        L1SP_MutePCMOuputPort ( kal_bool fMute );
void        L1SP_SetSidetoneVolume( kal_uint8 sidetone );
kal_uint8   L1SP_GetSidetoneVolume( void );
void        L1SP_MuteMicrophone( kal_bool mute );
kal_bool    L1SP_IsMicrophoneMuted( void );
void        L1SP_SetFIR( kal_bool enable );
void        L1SP_Set_DAI_Mode( kal_uint8 mode );
//@deprecated , when NVRAM move to driver side
void        L1SP_Write_Audio_Coefficients( const kal_int16 in_coeff[30], const kal_int16 out_coeff[30] );
// TODO:
void L1SP_Write_Audio_Coefficients_ByFirIndex( const kal_uint8 inOrOut2FirIndex, const kal_uint8 outFirIndex); 
//end TODO:
void        L1SP_SetAfeLoopback( kal_bool enable );
void        L1SP_SetAfeLoopback2( kal_bool enable );
void        L1SP_PCMIFLoopbackEn( kal_bool enable);
kal_bool    L1SP_GetAfeLoopbackStatus( void );
void        L1SP_SetReceiverTest( kal_bool enable ); // in l1audio_sp only
kal_bool    L1SP_IsBluetoothOn( void );
kal_bool    L1SP_IsSpeechOn( void );
void        L1SP_EnableSpeechEnhancement( kal_bool enable );
#define     FIRST_MIC (0)
kal_uint32  L1SP_GetFrameIntensity(kal_uint32 channel);
void        L1SP_GetIntensityExtremeValues(kal_uint32 *p_intensity_max_value, kal_uint32 *p_intensity_min_value);

void        L1SP_Write_WB_Audio_Coefficients( const kal_int16 in_coeff[90], const kal_int16 out_coeff[90] );
void        L1SP_SetDualMicNR( kal_bool enable );
void        L1SP_UpdateSpeechPara(kal_uint16 sph_m_para[16] );//NUM_MAX_MODE_PARAS
void        L1SP_LoadSpeechPara( void );
void        L1SP_Init_PCMPlayback(kal_uint8 sph_mode, kal_bool bDigitalGain, kal_uint16 digital_gain);

#define     NUM_DMNR_PARAM (44)
#define     NUM_WB_DMNR_PARAM (76)
#if defined(__DUAL_MIC_SUPPORT__)
#define     NUM_ABF_PARAM  (44)
void        L1SP_SetABFPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] );

void        L1SP_SetDMNRPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] );

#if defined(__AMRWB_LINK_SUPPORT__)
void        L1SP_SetWbDMNRPara( kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] );
#endif

#endif


/* deprecated function is replaced with functioins which have prefix "L1SP" */
void        AcousticLoopbackOn (void);
void        AcousticLoopbackOff (void);
void        AcousticLoopbackSpeechMode (kal_uint8 u1Mode);
kal_bool    AcousticLoopbackStatus(void);
void        AcousticLoopbackBypassMode (kal_uint8 u1Mode);
void        AcousticLoopbackLength (kal_uint32 u4Length);

#define     L1SP_DEFAULT_ACOUSTIC_LOOPBACK_LENGTH (1024) 
void        L1SP_AcousticLoopbackOn (void);
void        L1SP_AcousticLoopbackOff (void);
void        L1SP_AcousticLoopbackSpeechMode (kal_uint8 u1Mode);
kal_bool    L1SP_AcousticLoopbackStatus(void);
void        L1SP_AcousticLoopbackBypassMode (kal_uint8 u1Mode);
void        L1SP_AcousticLoopbackLength (kal_uint32 u4Length);


void        ABF_SetAcousticLoopback( kal_bool loopback );
kal_bool    ABF_GetAcousticLoopbackStatus( void );


/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
#define SPH_MODE_NORMAL  0
#define SPH_MODE_EARPHONE  1
#define SPH_MODE_LOUDSPK  2
#define SPH_MODE_BT_EARPHONE 3
#define SPH_MODE_BT_CORDLESS 4
#define SPH_MODE_BT_CARKIT   5
#define SPH_MODE_AUX1  6
#define SPH_MODE_AUX2  7
#define SPH_MODE_LINEIN_VIA_BT_CORDLESS 8
#define SPH_MODE_UNDEFINED  9

#define NUM_SPH_MODE      8
#define NUM_SPH_INPUT_FIR  6
#define NUM_SPH_OUTPUT_FIR 6

#define SPH_FIR_COEFF_NORMAL           0
#define SPH_FIR_COEFF_HEADSET          1
#define SPH_FIR_COEFF_HANDFREE         2
#define SPH_FIR_COEFF_BT               3
#define SPH_FIR_COEFF_VOIP_NORMAL      4
#define SPH_FIR_COEFF_VOIP_HANDFREE    5


#if defined(MT6223) || defined(MT6223P) || defined(MT6217) || defined(MT6219)
#define NUM_COMMON_PARAS 12
#define NUM_MODE_PARAS    8
#define NUM_VOL_PARAS     1
#else
#define NUM_COMMON_PARAS  8
#define NUM_MODE_PARAS   16
#define NUM_VOL_PARAS     4
#endif

#define NUM_FIR_COEFFS    45
#define NUM_WB_FIR_COEFFS    90

#define NUM_MAX_COMMON_PARAS 12
#define NUM_MAX_MODE_PARAS   16
#define NUM_MAX_VOL_PARAS     4

#define SPH_CORDLESS_PATH_BT         0  //default
#define SPH_CORDLESS_PATH_PCM        1
#define SPH_CORDLESS_PATH_UNDEFINED  2

void L1SP_SetCordLessPath( kal_uint8 uPath );
void L1SP_LoadCommonSpeechPara( kal_uint16 c_para[NUM_MAX_COMMON_PARAS] );
void L1SP_SetSpeechMode( kal_uint8 mode, kal_uint16 m_para[NUM_MAX_MODE_PARAS] );
void L1SP_SetWbSpeechPara( kal_uint16 m_para[NUM_MAX_MODE_PARAS] );
//@deprecated
void L1SP_SetSpeechVolumeLevel( kal_uint8 level, kal_uint16 v_para[NUM_MAX_VOL_PARAS] );
kal_uint8 L1SP_GetSpeechMode( void );

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex);

typedef enum {
	SPH_ENH_AND_FIR_SCENE_NORMAL = 0, //from 0 to 8, it is one to one mapping to speech mode. ie. SPH_MODE_NORMAL to SPH_MODE_LINEIN_VIA_BT_CORDLESS
	SPH_ENH_AND_FIR_SCENE_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_BT_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_BT_CORDLESS,
	SPH_ENH_AND_FIR_SCENE_BT_CARKIT, 
	SPH_ENH_AND_FIR_SCENE_AUX1,
	SPH_ENH_AND_FIR_SCENE_AUX2,
#ifndef __SMART_PHONE_MODEM__
	SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS,

	//VOIP related mode
	SPH_ENH_AND_FIR_SCENE_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_VOIP_LOADSPK,

	//CTM related
	SPH_ENH_AND_FIR_SCENE_CTM_BAUDOT,
	SPH_ENH_AND_FIR_SCENE_CTM_DIRECT,

	SPH_ENH_AND_FIR_SCENE_CTM_HCO_NORMAL, // using Eng Mode's selected_FIR_output_index to decide which is 
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_BT,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_LOUDSPK,

	SPH_ENH_AND_FIR_SCENE_CTM_VCO_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_BT,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK,
	
	SPH_ENH_AND_FIR_SCENE_INCALL_END, // useless, just make as the ending point for in-call scene

#ifdef __HD_RECORD__
	#include "aud_hdRecord_scene.h"
#endif //__HD_RECORD__
#endif // __SMART_PHONE_MODEM__ not exist
    
	SPH_ENH_AND_FIR_SCENE_UNDEF = 0xFFFF,  
} SPH_ENH_AND_FIR_SCENE;

typedef enum {
	SPH_ENH_AND_FIR_UPDATE_TYPE_ALL = 0,
	SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE = 0x2,
	SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR = 0x4,	
	SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE = 0x8,
	SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR = 0x10,
	
} SPH_ENH_AND_FIR_UPDATE_TYPE;

typedef enum {
  SPH_VC_NORMAL,
  SPH_VC_MAN,
  SPH_VC_WOMAN,
  SPH_VC_CHILD
} SPH_VOICE_CHANGER_MODE;

#if defined( __VOICE_CHANGER_SUPPORT__ )
kal_bool    L1SP_SetVoiceChangerMode(SPH_VOICE_CHANGER_MODE mode);
SPH_VOICE_CHANGER_MODE L1SP_GetVoiceChangerMode(void);
#endif

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. Please refer to "SPH_ENH_AND_FIR_SCENE"
	@updatedCoeff: [Input] Please refer to "SPH_ENH_AND_FIR_UPDATE_TYPE"
*/
void L1SP_SetSpeechEnhanceAndFir(kal_uint32 scene, kal_uint32 updatedCoeff);


/**
	MED can get nvram values from this function.
	
	@index: [Input] Identify which LID is going to provide
	@buffer: [Output] Buffer with the contain the result
	@len: [Input] Length of the output buffer
*/
void L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, void *buffer, kal_uint16 len);

// ============================================================================
// =============================== for HD record usage ========================
// ============================================================================

/**
	user: maybe META
	(related to customer folder)
	@return: number of enhancement mode sets, include speech used(in-call) and HD record used (when compile option opened)
*/
kal_int16 L1SP_GetNumOfAllEnhancementMode(void);

/**
	user: maybe META
	(related to customer folder)
	For example, if you want to query wb input fir numbers, please invoke L1SP_GetNumOfAllFir(1,0) to get the result.
	
	@isWideBand: [Input] 0 is narrow band (8k), >0 is wide band(16k)
	@isOutputFir: [Input] 0 is for input FIR, >0 is for output FIR 
	@return: number of FIR sets. includes speech used(in-call), recording used (when compile option opened)
*/
kal_int16 L1SP_GetNumOfAllFir(kal_uint8 isWideBand, kal_uint8 isOutputFir);

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "1 * @return" should be equal, because category is a 1D array.
	@categoryResult: [Output] An array indicate which tab(category) the enhancement belongs to. 
	  0 for "in-call", 1 for "voice-record", 2 for "vedio-record". For example: categoryResult[0] = 0, categoryResult[1] = 0 ....	  
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution
*/
kal_int16 L1SP_GetAllEnhancementModeCategory(kal_int16 inputBufLength, kal_int16 *categoryResult);

#define LEN_OF_ENHANCEMENT_MODE_NAME 30

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_MODE_NAME" should be equal. 	
	@nameResult: [Output] An array of names for different enhancement modes
	  (for every record, the max length is LEN_OF_ENHANCEMENT_MODE_NAME, i.e. 30) 
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution
*/
kal_int16 L1SP_GetAllEnhancementModeName(kal_int16 inputBufLength, kal_char *nameResult);

#define LEN_OF_ENHANCEMENT_CATEGORY_NAME 20

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_CATEGORY_NAME" should be equal. 	
	@categoryName: [Output] An array indicate each tab's name. For example, 
	                        tab 0 is named "in-call"; tab 1 is named "voice-record"; Tab 2 is named "video-record"
	                        The max length of name is LEN_OF_ENHANCEMENT_CATEGORY_NAME, i.e. 20. 
	@return: number of enhancement categories, when <= 0, it means some error occur when function execution
*/
kal_int16 L1SP_GetAllEnhancementCategoryName(kal_int16 inputBufLength, kal_char *categoryName);

/**
	user: should be META only
	(realted to customer folder)
	
	@return: number of all enhancement category
*/
kal_int16 L1SP_GetNumOfAllEnhancementCategory(void);

/**
	user: should be META only
	(realted to customer folder)
		
	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * 1" should be equal, because number of param is a 1D array. 	
	@paramNumOfCatg: [Output] An array indicate the number of enhancement mode parameters in each tab's (i.e. category). 
	  For example, category 0 has 32 parameters in each mode; category 1 has 16 parameters in each mode
	@return:  number of enhancement categories, when <= 0, it means some error occur when function execution
	
*/
kal_int16 L1SP_GetNumOfAllEnhancementCategoryParam(kal_int16 inputBufLength, kal_int16 *paramNumOfCatg);



/* ------------------------------------------------------------------------------ */
/*  AMR encoder buffer management                                                 */
/* ------------------------------------------------------------------------------ */
kal_uint32 AMR_DediEnc_BufferSize( void );
kal_uint16 AMR_DediEnc_SetBuffer( void *buf, kal_uint32 buf_size );

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
typedef enum {
   MEDIA_SUCCESS = MED_STAT_AUDIO_START,
   MEDIA_FAIL,
   MEDIA_REENTRY,                /* media reentry error                       */
   MEDIA_NOT_INITIALIZED,        /* media control is not initialized          */
   MEDIA_BAD_FORMAT,             /* media format error                        */
   MEDIA_BAD_PARAMETER,          /* media bad parameter error                 */
   MEDIA_BAD_COMMAND,            /* media bad command error                   */
   MEDIA_NO_HANDLER,             /* media no handler error                    */
   MEDIA_UNSUPPORTED_CHANNEL,    /* unsupported audio channel count           */
   MEDIA_UNSUPPORTED_FREQ,       /* unsupported audio freqency                */
   MEDIA_UNSUPPORTED_TYPE,       /* unsupported audio content                 */
   MEDIA_UNSUPPORTED_OPERATION,   /* unsupported operation on such audio type  */
   MEDIA_SEEK_FAIL,              /* seek fail indicator */
   MEDIA_SEEK_EOF,               /* seek end of file indicator */
   MEDIA_READ_FAIL,              /* read fail indicator */
   MEDIA_WRITE_FAIL,             /* write fail indicator */
   MEDIA_DISK_FULL,              /* disk full indicator */
   MEDIA_MERGE_TYPE_MISMATCH ,
   MEDIA_FILE_INCOMPLETE
} Media_Status;

typedef enum {
   MEDIA_NONE,
   MEDIA_DATA_REQUEST,
   MEDIA_DATA_NOTIFICATION,
   MEDIA_END,
   MEDIA_ERROR,
   MEDIA_DECODER_UNSUPPORT,
   MEDIA_REPEATED,
   MEDIA_TERMINATED,
   MEDIA_LED_ON,
   MEDIA_LED_OFF,
   MEDIA_VIBRATOR_ON,
   MEDIA_VIBRATOR_OFF,
   MEDIA_BACKLIGHT_ON,
   MEDIA_BACKLIGHT_OFF,
   MEDIA_EXTENDED_EVENT,
   MEDIA_READ_ERROR,
   MEDIA_UPDATE_DUR,
   MEDIA_STOP_TIME_UP,
   MEDIA_DEMO_TIME_UP,
   MEDIA_BUFFER_UNDERFLOW,
   MEDIA_READY_TO_PLAY,
   MEDIA_DATA_REFILL
} Media_Event;

// Note : New defined media format should always be added at the last one,    
// otherwise it may induce unsync media format problem between MMI/MED and L1Audio.
typedef enum {
   MEDIA_FORMAT_GSM_FR,
   MEDIA_FORMAT_GSM_HR,
   MEDIA_FORMAT_GSM_EFR,
   MEDIA_FORMAT_AMR,
   MEDIA_FORMAT_AMR_WB,
   MEDIA_FORMAT_DAF,
   MEDIA_FORMAT_AAC,
   MEDIA_FORMAT_PCM_8K,
   MEDIA_FORMAT_PCM_16K,
   MEDIA_FORMAT_G711_ALAW,
   MEDIA_FORMAT_G711_ULAW,
   MEDIA_FORMAT_DVI_ADPCM,
   MEDIA_FORMAT_VRD,
   MEDIA_FORMAT_WAV,
   MEDIA_FORMAT_WAV_ALAW,
   MEDIA_FORMAT_WAV_ULAW,
   MEDIA_FORMAT_WAV_DVI_ADPCM,
   MEDIA_FORMAT_SMF,
   MEDIA_FORMAT_IMELODY,
   MEDIA_FORMAT_SMF_SND,
   MEDIA_FORMAT_MMF,
   MEDIA_FORMAT_AU,
   MEDIA_FORMAT_AIFF,
   MEDIA_FORMAT_VRSI,
   MEDIA_FORMAT_WMA,
   MEDIA_FORMAT_M4A,
   MEDIA_FORMAT_WAV_DVI_ADPCM_16K,
   MEDIA_FORMAT_VOIPEVL,
   MEDIA_FORMAT_AAC_PLUS,
   MEDIA_FORMAT_AAC_PLUS_V2,
   MEDIA_FORMAT_BSAC,
   MEDIA_FORMAT_MUSICAM = 32,
   MEDIA_FORMAT_AWB_PLUS,
   MEDIA_FORMAT_AWB_PLUS_EXTEND,
   MEDIA_FORMAT_WAV_16K,
   MEDIA_FORMAT_MP4_AAC,
   MEDIA_FORMAT_MP4_AMR,
   MEDIA_FORMAT_MP4_AMR_WB,
   MEDIA_FORMAT_MP4_BSAC,
   MEDIA_FORMAT_DRA,
   MEDIA_FORMAT_COOK,
   MEDIA_FORMAT_APE,
   MEDIA_FORMAT_PCM,
   MEDIA_FORMAT_JTS,
   MEDIA_FORMAT_VORBIS,
   MEDIA_FORMAT_FLAC,
   MEDIA_FORMAT_A2DP,
   MEDIA_FORMAT_AMR_TRANSMIT,
   MEDIA_FORMAT_MIXER = 100,
   MEDIA_FORMAT_UNKNOWN
} Media_Format;

typedef enum {
   MEDIA_AUD_COMP_LOUDSPEAKER,
   MEDIA_AUD_COMP_EARPHONE, 
   MEDIA_AUD_COMP_LOUDSPEAKER_RINGTONE
} Media_Aud_Comp_Mode;

typedef struct {
   const kal_uint8   *smffile;
   kal_int32         filesize;            /* MIDI file size             */
   kal_int16         repeats;             /* 0 -> endless               */
   STFSAL            *pstFSAL;
} Media_SMF_Param;

typedef struct {
   const kal_uint8   *imyfile;
   kal_int32         filesize;            /* MIDI file size             */
   kal_int16         repeats;             /* 0 -> endless               */
   kal_int16         default_instrument;  /* default instrument(1~128)  */
} Media_iMelody_Param;

typedef struct {
   const kal_uint8 *wavefile;
   kal_int32       filesize;            /* Wave file size             */
   kal_int16       repeats;             /* 0 -> endless               */
   kal_int16       format;              /* add for direct wave        */
   kal_uint16      sampling_rate;       /* add for direct wave        */
} Media_Wav_Param;

typedef struct {
   const kal_uint8 *toneSeq;
   kal_int32     toneSeqLen;          /* tone sequence data length  */
   kal_int16     repeats;             /* 0 -> endless               */
} Media_ToneSeq_Param;

typedef struct{
   const kal_uint8 *mmffile;
   kal_int32 filesize;
   kal_int16 repeats;
} Media_MMF_Param;

typedef struct{
   const kal_uint8 *amrfile;
   kal_int32 filesize;
   kal_int16 repeats;
} Media_AMR_Param;

typedef struct {
   Media_Format   mediaType;
   kal_uint32     vmParam;
} Media_VM_PCM_Param;

typedef struct {
   kal_bool       isStereo;
   kal_int8       bitPerSample;
   kal_uint16     sampleFreq;
   kal_bool       forceVoice;
} Media_PCM_Stream_Param;

typedef struct {
   int          nSamples;
   int          nChannels; 
   int          nRegions; 
   int          nFrameBits; 
   int          sampRate; 
   int          cplStart; 
   int          cplQbits;
} Media_COOK_Param;

typedef struct {
   kal_uint32     fileSize;
   kal_uint32     dataSize;
   kal_uint32     sampleCount;
   kal_bool       valid;
   kal_bool       is_I2S;
   kal_uint16     format;
   kal_uint16     sampleFreq;
   kal_uint16     channel;
} Media_Record_File_Info;

typedef enum {
   MEDIA_CTRL_MAX_SWING,
   MEDIA_CTRL_KEY_SHIFT
} Media_Ctrl;

typedef enum {
   MEDIA_CHANNEL_NONE = 0,
   MEDIA_CHANNEL_MAIN,
   MEDIA_CHANNEL_SUB
} Media_Channel;

typedef enum {
   MEDIA_FREE_SPACE_MODE,
   MEDIA_DATA_COMSUME_MODE
} Media_Buffer_Mode;

typedef struct {
   kal_uint16     sample_rate;
   kal_uint8      channel_num;
} Media_Ext_DAF_strm;

typedef enum {
   AUDIO_RECORD_MODE_IDLE,
   AUDIO_RECORD_MODE_SPEECH,
   AUDIO_RECORD_MODE_FM,
   AUDIO_RECORD_MODE_I2S
} Audio_Record_Mode;

typedef enum {
   AUDIO_RECORD_QUALITY_LOW,
   AUDIO_RECORD_QUALITY_HIGH
} Audio_Record_Quality;

typedef struct {
   Media_Format uFormat;
   kal_uint32   uByteRate;
   kal_wchar    pFileExtension[5];
} Audio_Record_Format;

typedef enum {
   MEDIA_CALI_NONE = 0,
   MEDIA_CALI_DC,
   MEDIA_CALI_VIB
} Media_CaliType;

typedef enum {
   AUDPARAM_RESET_BUFFER,
   AUDPARAM_SET_EMPTY_BUFFER_DONE_CALLBACK,
   AUDPARAM_SET_SILENCE_INFO,
   AUDPARAM_SET_HEADER_INFO,
   AUDPARAM_AUTO_FILL_SILENCE_BY_TIMESTAMP,
} Audio_Param_Type;

typedef struct {
   Media_Format uFormat;
   kal_uint32   uChannelNum;
   kal_uint32   uSampleRate;
   kal_uint32   uSubFrameNum;  //reserved
   kal_uint32   uFrameDur;     //us
} Audio_Stream_Info;

// Audio Streaming Sender
typedef struct sender_stream_handle SSHdl;
struct sender_stream_handle {
   void (*PutData)( SSHdl *hdl, kal_uint8 *, kal_uint32 );
   void (*Flush)( SSHdl *hdl );

   kal_uint8 *rb_base;
   kal_int32 rb_size;
   kal_int32 rb_read;
   kal_int32 rb_write;
   kal_int32 rb_threshold;
   void (*callback)( void * );
   kal_bool wait;
   kal_int32 rb_read_total;
} ;
kal_bool is_SSHdl_valid(SSHdl *hdl);

#define RTP_REC_BUF_NUM 4
#define RTP_REC_BUF_SIZE 16*1024

typedef struct aud_rtp_rec_frame RTP_Rec_Frame;

struct aud_rtp_rec_frame {
   kal_uint32    timeStamp;
   kal_uint32    dataLength;
   kal_uint8     *dataAddress;
   RTP_Rec_Frame *nextFrame;
};

typedef struct aud_rtp_rec_info {
   kal_uint32    state;
   kal_uint32    frameCount;
   kal_uint32    timeStamp;
   RTP_Rec_Frame *frame;
} RTP_Rec_Info;

typedef struct aud_rtp_rec_slot{
   RTP_Rec_Info  info;
   kal_uint32    write;       // Internal use
   RTP_Rec_Frame *lastFrame;
   kal_uint8     buf[RTP_REC_BUF_SIZE];
} RTP_Rec_Slot;

typedef struct aud_rtp_rec_buf{
   kal_uint8    index;
   kal_uint8    pre_index;
   RTP_Rec_Slot bufSlot[RTP_REC_BUF_NUM];
} RTP_Rec_Buf;

typedef struct {
   kal_uint32      fc_format;
   kal_uint8       *rb_base;         // Pointer to the ring buffer
   kal_int32       rb_size;          // Size of the ring buffer
   kal_int32       write;
   kal_int32       read;
   void            *param;           // Extend parameter or information
   kal_uint8       fc_operation;
} AUD_RB_INFO;

typedef  struct mhdl MHdl;
typedef  struct media_handle Media_Handle;

struct media_handle {
   kal_uint8      state;
   kal_bool       stop_flag;
   kal_int8       repeat_count;
   kal_uint8      volume_level;
   kal_uint8      index;
   kal_int32      start_time;
   kal_int32      current_time;
   kal_int32      stop_time;
   kal_uint32     data;
   void           (*handler)( Media_Handle *handle, Media_Event event );
   void           *param;
   void           *pApplicateData;
   kal_bool       appflag;
};

struct mhdl {
   kal_uint8      state;
   kal_uint8      volume_level;
   kal_bool       fSeekTable;
   kal_uint32     start_time;
   kal_uint32     current_time;
   kal_uint32     stop_time;
   kal_uint32     data;
   void           (*handler)( MHdl *handle, Media_Event event );
   void           *param;
   void           *private_data;
   void               *pFileInfo;

   kal_bool           bIsPause;
   kal_bool           lastUpdateDur;
   kal_bool           isUnderflow;
   Media_Format       mediaType;
   kal_uint16         aud_id;
   // DSP ring buffer control variables
   kal_uint16         dsp_rb_base;
   kal_uint16         dsp_rb_size;
   kal_uint16         dsp_rb_end;
   // Media ring buffer control variables
   AUD_RB_INFO        rbInfo;
   kal_uint16         fc_aud_id;
   kal_uint8          fc_state;
   
   kal_bool           eof;
   kal_bool           waiting;
   kal_bool           mono2stereo;
   kal_bool           fStoreFileOffset;
   Media_Status       eSeekLastRet;
   kal_uint32         uSeekProgress;
   kal_uint32         uCurSeekFrm;
   Media_Status       eGetDurLastRet;
   kal_bool           bReadingData;
   kal_bool           isTrim;
   kal_bool           isAllocRingBuffer;
   kal_uint32         uGetDurProgress;
   kal_uint32         uCurGetDurFrm;
   kal_uint32         uStoreStartTime;
   kal_uint32         uTotalDuration;
   SSHdl              *ss_handle;
   void               *pApplicateData;

   void           (*SetBuffer)( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
   void           (*GetWriteBuffer)( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len );
   void           (*GetReadBuffer)( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len );
   void           (*WriteDataDone)( MHdl *hdl, kal_uint32 len );
   void           (*FinishWriteData) (MHdl *hdl);
   void           (*ResetMediaBuf) (MHdl *hdl);
   void           (*ReadDataDone)( MHdl *hdl, kal_uint32 len );
   void           (*DataFinished)( MHdl *hdl );
   void           (*SetStoreFlag)( MHdl *hdl, kal_bool fStoreLastFileOffset );
   void           (*StoreFileOffset)(MHdl *hdl);
   void           (*SetFileOffset)(MHdl *hdl, kal_uint32 uCurOffset);
   kal_uint32     (*GetFileOffset)(MHdl *hdl);
   kal_int32      (*GetFreeSpace)( MHdl *hdl );
   kal_int32      (*GetDataCount)( MHdl *hdl );
   Media_Status   (*SetLevel)( MHdl *hdl, kal_uint8 level );
   kal_uint8      (*GetLevel)( MHdl *hdl );
   Media_Status   (*SetStartTime)( MHdl *hdl, kal_uint32 msStartTime );
   Media_Status   (*SetStopTime)( MHdl *hdl, kal_uint32 msStopTime );
   kal_uint32     (*GetCurrentTime)( MHdl *hdl );
   kal_uint32     (*GetTotalDuration)( MHdl *hdl );
   void           (*BuildCache) ( MHdl *hdl, Media_Status *eGetDurLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber);
   void           (*SetCacheTbl)( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize );
   kal_uint32     (*GetCacheDuration)(MHdl *hdl);
   void           (*SelectChannel)( MHdl *hdl, Media_Channel channel);
   Media_Status   (*ReachValidRegion)( MHdl *hdl );  // to make sure the data is enough for PDL case
   void           (*SetUserData)( MHdl *hdl, void* pAppData);
   void           (*GetUserData)( MHdl *hdl, void** pAppData);
   Media_Status   (*Trim)( MHdl *hdl );
   void           (*SetBufferInternal)( MHdl *hdl , kal_uint32 uSize);
   void           (*FreeBufferInternal)( MHdl *hdl);

   Media_Status   (*Play)( MHdl *hdl );
   Media_Status   (*Record)( MHdl *hdl );
   Media_Status   (*Stop)( MHdl *hdl );
   Media_Status   (*Pause)( MHdl *hdl );
   Media_Status   (*Resume)( MHdl *hdl );
   Media_Event    (*Process)( MHdl *hdl, Media_Event event );
   Media_Status   (*Close)( MHdl *hdl );

//#if defined(__STREAM_REC_SUPPORT__)
   RTP_Rec_Buf        *rtp_rec_buf;
   kal_uint32         timeStamp;
   kal_uint32         timeStampInterval;
   kal_uint32         recRead;
//#endif
   void               (*SetDataRequestThreshold)( MHdl *hdl, Media_Buffer_Mode mode, kal_uint32 threshold, void* param);
   kal_uint32         DataRequestThreshold;
   kal_int32          LastRingBufferRead;
   Media_Buffer_Mode  DataRequestMode;
   Media_Status       (*SetParameter)   ( MHdl *hdl, kal_uint32 uType, void *pParam);
   Media_Status       (*EmptyThisBuffer)( MHdl *hdl, void *pBufHeader);
   void               *pStrmStruct;
};

#define  MEDIA_VMP_AS_SPEECH     ((void*)0)
#define  MEDIA_VMP_AS_RINGTONE   ((void*)1)
#define  MEDIA_VMP_AMR           ((void*)0)
#define  MEDIA_VMP_AMR_WB        ((void*)2)

#define MAX_DESCRIPTION     80
typedef struct tWMADescription
{
   kal_uint32 time; // duration in milli-second
   kal_uint32 bitRate;
   kal_uint32 sampleRate;
   kal_uint32 trackNum;
   kal_bool stereo;
   kal_wchar title[MAX_DESCRIPTION+1];
   kal_wchar artist[MAX_DESCRIPTION+1];
   kal_wchar album[MAX_DESCRIPTION+1];
   kal_wchar author[MAX_DESCRIPTION+1];
   kal_wchar genre[MAX_DESCRIPTION+1];
   kal_wchar copyright[MAX_DESCRIPTION+1];
   kal_wchar date[MAX_DESCRIPTION+1];
   kal_wchar comment[MAX_DESCRIPTION+1];
   union
   {
      struct
      {
         kal_uint8 CRC;
         kal_uint8 channel_mode;
         kal_uint8 bit_rate_index;
         Media_Format mediaFormat;
      } DAF;
   } details;
} audInfoStruct;

typedef enum
{
 MEDIA_FORMAT_CHECK_SUCCESS = 0,
 MEDIA_FORMAT_CHECK_FAIL,
 MEDIA_FORMAT_CHECK_BAD_FILE,
 MEDIA_FORMAT_CHECK_INTERNAL_ERROR
}Media_Format_Check_Result;

typedef enum
{
 MEDIA_Check_FORMAT_3GPP,
 MEDIA_Check_FORMAT_MP3,
 MEDIA_Check_FORMAT_IMY,
 MEDIA_Check_FORMAT_MIDI,
 MEDIA_Check_FORMAT_SPMIDI, 
 MEDIA_Check_FORMAT_M4A,
 MEDIA_Check_FORMAT_MP4,
 MEDIA_Check_FORMAT_ASF,
 MEDIA_Check_FORMAT_DCF,
 MEDIA_Check_FORMAT_WAVE,
 MEDIA_Check_FORMAT_AAC,
 MEDIA_Check_FORMAT_AMR,
 MEDIA_Check_FORMAT_AWB, 
 MEDIA_Check_FORMAT_WMA,
 MEDIA_Check_FORMAT_WMV, 
 MEDIA_Check_FORMAT_UNKNOWN
}Media_Check_Format;

typedef enum
{
 /*audio codec*/
 MEDIA_AUDIO_CODEC_AAC,
 MEDIA_AUDIO_CODEC_AAC_PLUS,
 MEDIA_AUDIO_CODEC_EAAC_PLUS,
 MEDIA_AUDIO_CODEC_AMR,
 MEDIA_AUDIO_CODEC_AWB,
 MEDIA_AUDIO_CODEC_WMA,
 MEDIA_AUDIO_CODEC_MP3,
 MEDIA_AUDIO_CODEC_UNKNOWN
}Media_Check_Audio_Codec;

typedef enum
{
 /*video codec*/
 MEDIA_VIDEO_CODEC_H263,
 MEDIA_VIDEO_CODEC_H264,
 MEDIA_VIDEO_CODEC_MPEG4,
 MEDIA_VIDEO_CODEC_WMV,
 /**/
 MEDIA_VIDEO_CODEC_UNKNOWN
}Media_Check_Video_Codec;

typedef enum
{
 MEDIA_VCP_MED,
 MEDIA_VCP_FM,
 MEDIA_VCP_MATV,
 MEDIA_VCP_BT,
 MEDIA_VCP_L1
}Media_VCP_DS_Module;

typedef enum
{
	MEDIA_SPEECH_FEATURE_NONE = 0x00000000,
	MEDIA_SPEECH_FEATURE_NB_DMNR = 0x00000001,
	MEDIA_SPEECH_FEATURE_WB_DMNR = 0x00000002,
	MEDIA_SPEECH_FEATURE_WB_LINK_SUPPORT = 0x00000004,
	MEDIA_SPEECH_FEATURE_HD_RECORD = 0x00000008,
	MEDIA_SPEECH_FEATURE_STEREO_RECORD = 0x00000010,
}Media_Speech_Feature;
void  Media_EnableVolumeProtection(kal_bool enable);
void  Media_SetOutputDevice( kal_uint8 device );
void  Media_SetOutputVolume( kal_uint8 volume1, kal_int8 Media_SetOutputVolume );
void  Media_SetOutputVolume_ST( kal_uint8 volume );
void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level );
void  Media_SetBuffer( kal_uint16 *buffer, kal_uint32 buf_len );
void  Media_GetWriteBuffer( kal_uint16 **buffer, kal_uint32 *buf_len );
void  Media_WriteDataDone( kal_uint32 len );
void  Media_DataFinished( void );
void  Media_GetReadBuffer( kal_uint16 **buffer, kal_uint32 *buf_len );
void  Media_ReadDataDone( kal_uint32 len );
void  Media_GetFileHeader( kal_uint8 **header, kal_uint32 *len );
void  Media_SetRBThreshold( kal_uint16 threshold );   /* Ring buffer threshold in words */
void  Media_SetRBOffset( kal_uint32 uOffset );   /* Ring buffer offset in words */
kal_int32 Media_GetDataCount( void );

Media_Status  Media_Play( Media_Format format, void (*media_handler)( Media_Event event ), void *param );
kal_uint32    Media_GetRecordedTime( void );
void          Media_SetRecordedStopTime( kal_uint32 uStopTime );
Media_Status  Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param );

#if defined(__DUAL_MIC_SUPPORT__)
kal_uint32    Media_GetRecordDataRate(Media_Format format, void *param);
#endif

Media_Status  Media_SpkVibration_Enable( kal_bool fEnable );
void          Media_Stop( void );
Media_Status  Media_Pause( void );
Media_Status  Media_Resume( void );
Media_Status  Media_Control( Media_Ctrl ctrl_no, kal_int32 ctrl_val );
Media_Status  Media_SetLevel( kal_uint8 level );
kal_uint8     Media_GetLevel( void );
kal_bool      Media_IsCSDMode(void);
void          Media_MuteSpeaker( kal_bool mute );
Media_Status Media_RecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info );
void          Media_EnableHardwareMuteSleep(kal_bool enable);
kal_bool      Media_IsPlaybackOn( void );

void          Media_SetUserData(Media_Handle *hdl, void* pAppData);
void          Media_GetUserData(Media_Handle *hdl, void** pAppData);
void          Media_GetMaxMinRate(Media_Format eFormat, kal_int32* max, kal_int32* min);
void          Media_GetMMACapability(Media_Format eFormat, kal_uint8* concurrent);
Media_Status  Media_FastPassMode(void* hdl, Media_Format eFormat);
void  Media_SetMelodyFilter( kal_uint16 len, const kal_int16 *filter );

Media_Status  Media_GetSilencePattern( Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern );
Media_Status  Media_GetSilenceLength( Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint32 *len );
Media_Status  Media_GetFileHeaderLength( Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint32 *len );
Media_Status  Media_GetFileHeaderPattern( Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern );
Media_Status  Media_GetSilenceFormat( Media_Format uFormat, kal_uint32 *uChannelNum, kal_uint32 *uSampleRate, kal_uint8 *pBuf, kal_uint32 uBufLen);
kal_uint32    Media_GetPlaybackPrebufferFrameNum(Media_Format uFormat);
kal_bool      Media_IsFormatSupported(Media_Format uFormat, kal_uint32 channelNum, kal_uint32 freq);
kal_bool      Media_IsSeekable(STFSAL *pstFSAL, Media_Format uFormat);
kal_bool      Media_IsPauseable(STFSAL *pstFSAL, Media_Format uFormat);
void          Media_PowerOff(void);
Media_Status  Media_GetRecordFormat( Audio_Record_Mode uMode, Audio_Record_Quality uQuality, Audio_Record_Format *pFormatStruct );
kal_uint32    Media_GetRecordFormatByteRate( Media_Format uFormat, Audio_Record_Mode uMode, void *Param );
kal_uint32    Media_GetAudioPlaybackRingBufferMinSize(Media_Format uFormat);
kal_uint32    Media_GetSpeechFeatureCapability(void);

//[Karaoke]
typedef enum {
	MEDIA_KARAREC_MIX_NONE,
  MEDIA_KARAREC_MIX_LEFT,
  MEDIA_KARAREC_MIX_RIGHT,
  MEDIA_KARAREC_MIX_BOTH,
  MEDIA_KARAREC_MIX_MONO
}Media_KaraRec_Mix_CH;


typedef enum {
	MEDIA_KARAPLAY_MIX_NONE,
	MEDIA_KARAPLAY_PLAY_MIX_ONLY,
  MEDIA_KARAPLAY_REC_MIX_ONLY,
  MEDIA_KARAPLAY_PLAY_REC_MIX
}Media_Kara_opt_mode;


kal_bool      Media_SetKaraoke(kal_bool enable);
kal_bool      Media_IsKaraoke(void);
void          Media_SetKaraOperationMode(Media_Kara_opt_mode mode);
Media_Kara_opt_mode Media_GetKaraOperationMode(void);
void          Media_SetKaraRecMixChannel(Media_KaraRec_Mix_CH channel);
Media_KaraRec_Mix_CH Media_GetKaraRecMixChannel(void);

//[AFE: classK]
void          Media_SetChargePump(kal_bool enable, Media_VCP_DS_Module module);
kal_bool      Media_IsChargePump(void);

//For Slim ver. BLISRC SWIP prebuild table
void          Media_SetBLISRC(kal_bool enable);
/* ------------------------------------------------------------------------------ */

Media_Handle   *JSmf_Open( void (*handler)( Media_Handle *handle, Media_Event event ), kal_uint32 *requiredBufSize );
void           JSmf_SetBuffer( Media_Handle *handle, kal_int8 *buffer, kal_uint32 buf_len, Media_SMF_Param **param );
Media_Status   JSmf_Close( Media_Handle *handle );
Media_Status   JSmf_Play( Media_Handle *handle );
Media_Status   JSmf_Stop( Media_Handle *handle );
Media_Status   JSmf_Pause( Media_Handle *handle );
Media_Status   JSmf_Resume( Media_Handle *handle );
Media_Status   JSmf_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JSmf_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JSmf_GetCurrentTime( Media_Handle *handle );
kal_int32      JSmf_GetDuration( Media_Handle *handle );
kal_int32      JSmf_GetMidiDuration( const kal_uint8 *mid );
Media_Event    JSmf_QueryExtEvent( Media_Handle *handle, kal_int32 *note );
kal_bool       JSmf_isSpMidi( Media_Handle *handle );

kal_bool       JMidi_isBankQuerySupported( void );
void           JMidi_GetBankList( kal_bool custom, const kal_int16 **buf, kal_int16 *len);
void           JMidi_GetProgramList( kal_int16 bank, const kal_int8 **buf, kal_int16 *len);
const kal_uint8*JMidi_GetProgramName( kal_int16 bank, kal_int8 prog );
const kal_uint8*JMidi_GetKeyName( kal_int16 bank, kal_int8 prog, kal_int8 key );

Media_Handle   *JMidi_OpenDevice( kal_uint32 *requiredBufSize );
void           JMidi_SetBuffer( Media_Handle *handle, kal_int8 *buffer, kal_uint32 buf_len );
Media_Status   JMidi_CloseDevice( Media_Handle *handle );
Media_Status   JMidi_SendLongMsg( Media_Handle *handle, const kal_uint8 *buf, kal_uint16 len );
Media_Status   JMidi_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 );
Media_Status   JMidi_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JMidi_GetLevel( Media_Handle *handle );
Media_Status   JMidi_SetTempo( Media_Handle *handle, kal_int32 milliTempo );
kal_int32      JMidi_GetTempo( Media_Handle *handle );
Media_Status   JMidi_SetRate( Media_Handle *handle, kal_int32 milliRate );
kal_int32      JMidi_GetRate( Media_Handle *handle );
Media_Status   JMidi_SetTSRate( Media_Handle *handle, kal_int32 Rate );   // For Time Stretch
Media_Status   JMidi_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt );
kal_int32      JMidi_GetPitchTranspose( Media_Handle *handle );
Media_Status   JMidi_SetChannelVolume( Media_Handle *handle, kal_int8 channel, kal_uint8 level );
kal_int8       JMidi_GetChannelVolume( Media_Handle *handle, kal_int8 channel );
Media_Status   JMidi_SetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 bank, kal_int8 program );
void           JMidi_GetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 *bank, kal_int8 *program );


Media_Handle   *JTone_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_ToneSeq_Param **param );
Media_Status   JTone_Close( Media_Handle *handle );
Media_Status   JTone_Play( Media_Handle *handle );
Media_Status   JTone_Stop( Media_Handle *handle );
Media_Status   JTone_Pause( Media_Handle *handle );
Media_Status   JTone_Resume( Media_Handle *handle );
Media_Status   JTone_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JTone_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JTone_GetCurrentTime( Media_Handle *handle );
kal_int32      JTone_GetDuration( Media_Handle *handle );
Media_Status   JTone_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JTone_GetLevel( Media_Handle *handle );
Media_Status   JTone_SetPitchShift(Media_Handle *handle, kal_int8 pitch_shift);
kal_int8       JTone_GetPitchShift(Media_Handle *handle);
Media_Status   JTone_SetSpeed(Media_Handle *handle, kal_uint32 speed_factor);
Media_Status   JTone_SetProgram(Media_Handle *handle, kal_uint8 program);
Media_Status   JTone_SetPlayStyle(Media_Handle *handle, kal_uint8 play_style);
Media_Status 	 JTone_SetRate( Media_Handle *handle, kal_int32 milliRate );
kal_int32      JTone_GetRate( Media_Handle *handle );

Media_Handle   *JImy_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_iMelody_Param **param );
Media_Status   JImy_Close( Media_Handle *handle );
Media_Status   JImy_Play( Media_Handle *handle );
Media_Status   JImy_Stop( Media_Handle *handle );
Media_Status   JImy_Pause( Media_Handle *handle );
Media_Status   JImy_Resume( Media_Handle *handle );
Media_Status   JImy_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JImy_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JImy_GetCurrentTime( Media_Handle *handle );
kal_int32      JImy_GetDuration( Media_Handle *handle );
Media_Status   JImy_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JImy_GetLevel( Media_Handle *handle );
Media_Status   JImy_SetTSRate( Media_Handle *handle, kal_int32 rate);  // For Time Stretch

Media_Handle   *JWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_Wav_Param **param );
Media_Status   JWav_Close( Media_Handle *handle );
Media_Status   JWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize);
void           JWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len);
Media_Status   JWav_Play( Media_Handle *handle );
Media_Status   JWav_Stop( Media_Handle *handle );
Media_Status   JWav_Pause( Media_Handle *handle );
Media_Status   JWav_Resume( Media_Handle *handle );
Media_Status   JWav_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JWav_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JWav_GetCurrentTime( Media_Handle *handle );
kal_int32      JWav_GetDuration( Media_Handle *handle );
Media_Status   JWav_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JWav_GetLevel( Media_Handle *handle );

Media_Handle   *JXWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ));
Media_Status   JXWav_Close( Media_Handle *handle );
Media_Status   JXWav_Load(Media_Handle *handle, kal_uint32 *requiredBufSize);
void           JXWav_SetBuffer(Media_Handle *handle, kal_int16 *buffer, kal_uint32 buf_len);
Media_Status   JXWav_Play( Media_Handle *handle );
Media_Status   JXWav_Stop( Media_Handle *handle );
Media_Status   JXWav_Pause( Media_Handle *handle );
Media_Status   JXWav_Resume( Media_Handle *handle );
kal_int32      JXWav_GetCurrentTime( Media_Handle *handle );
Media_Status   JXWav_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JXWav_GetLevel( Media_Handle *handle );

Media_Handle   *JAmr_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_AMR_Param **param );
Media_Status   JAmr_Close( Media_Handle *handle );
Media_Status   JAmr_Play( Media_Handle *handle );
Media_Status   JAmr_Stop( Media_Handle *handle );
Media_Status   JAmr_Pause( Media_Handle *handle );
Media_Status   JAmr_Resume( Media_Handle *handle );
Media_Status   JAmr_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
Media_Status   JAmr_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
kal_int32      JAmr_GetCurrentTime( Media_Handle *handle );
Media_Status   JAmr_SetLevel( Media_Handle *handle, kal_uint8 level );
kal_uint8      JAmr_GetLevel( Media_Handle *handle );
Media_Status   JAmr_GetDuration( const kal_uint8 *amrfile, kal_int32 amrsize, kal_int32 *duration );

/* ------------------------------------------------------------------------------ */

// For Audio Equalizer
void AudioPP_Equalizer_SetMag( kal_int8 magnitude[8] );
void AudioPP_Equalizer_TurnOn( void );
void AudioPP_Equalizer_TurnOff( void );
kal_bool AudioPP_Equalizer_IsEnable( void );
void AEQ_Activate( kal_int16 asp_fs, kal_bool rampup );  /* l1audio internal use */
void AudioPP_Equalizer_DisableShift(void);

//For flexible audio equalizer
void AudioPP_Equalizer_SetMag_Flexible(kal_int8 *band_mag);
void Media_SetBesEQInitParam(kal_uint8 *pBuf, kal_uint32 u4Len);
void Media_Equalizer_TransformMag_ToBarNum (kal_int8 *band_mag, kal_int8 *bar_mag, kal_uint32 bar_num);
void Media_Equalizer_TransformMag_ToBandNum (kal_int8 *bar_mag, kal_int8 *band_mag, kal_uint32 bar_num);
kal_int16 Media_QueryBesEQMaxBandNum(void);

// For Audio Compensation Filter
void Media_SelectAudioCompensation(Media_Aud_Comp_Mode mode);
void Media_SetAudioCompensation(Media_Aud_Comp_Mode mode, const kal_int16 *coeff);

void Audio_Compensation_Activate( kal_uint16 uSampleRate );      /* l1audio internal use */
void Audio_Compensation_Deactivate(void);      /* l1audio internal use */

// For Audio BesLoudness Data
kal_uint32 Media_QueryBesLoudnessVersion(void);
void Media_SetBesLoudnessCustomCoeff(kal_uint32 *hsf_coeffs, kal_uint32 *bpf_coeffs);
void Media_SetBesLoudnessCustomCoeff_v3(void *pBuf, kal_uint32 uLen);

// For Audio SWFIR
void Media_SetAudioCompensation_SWFIR(void *pBuf, kal_uint32 uLen);

//vibration spk: current sensor
void Media_SetVibrInitParam(void *pBuf, kal_uint32 uLen);
void Media_VIB_Calibration_Write(void(*VIB_Calibration_CallBack)(void *cali_data));
void Media_Vibrate_CF_Check(void);
kal_bool Media_Is_Vibrator_Calibration(void);
Media_CaliType Media_GetCalibrationType(void);
void AFE_Retrieve_VIB_CF_Data(kal_int32 data);

//For META, runtime apply the audio compensation filter coefficient

typedef enum {
   MEDIA_ACF_DSP_FIR,
   MEDIA_ACF_HW_FIR,
   MEDIA_ACF_DSP_IIR,
   MEDIA_ACF_NONSUPPORT
} MEDIA_ACF_Filter_Type;

typedef enum {
   MEDIA_ACF_LoudSpeaker_mode,
   MEDIA_ACF_Earphone_mode,
   MEDIA_ACF_LoudSpeaker_Ringtone_mode
} MEDIA_ACF_OUTPUT_MODE;

void ACF_SetFilterCoeff(kal_int16 *coeff, MEDIA_ACF_OUTPUT_MODE mode);
MEDIA_ACF_Filter_Type ACF_GetFilterType( void );

// For Hardware FIR
void Audio_HW_FIR_Reset( void );                         /* l1audio internal use */

/* ---- AudioPP Manager Structure --- */
#define APM_PROPERTY_READ_WRITE 0
#define APM_PROPERTY_READ_ONLY  1

typedef enum {
   APM_TASKID_REVERB,
   APM_TASKID_SURROUND_LSPK,
   APM_TASKID_SURROUND_EARP,
   APM_TASKID_LOUDNESS,
   APM_TASKID_SBC,
   APM_TASKID_AVB,
   APM_TASKID_SPT,
   APM_TASKID_TS,
   APM_TASKID_EQ,
   APM_TASKID_BASS,
   APM_TASKID_I2S_RECORD,
   APM_TASKID_AVM,
   APM_TASKID_OAEP,
   APM_TASKID_CF,
   APM_TASKID_I2S_SOURCE,
   APM_TASKID_REMIX,
} APM_TaskID;

typedef struct APM_InfoStruct {
   kal_bool   isEOF;
   kal_bool   isChange;
   kal_bool   isStereo;
   kal_uint32 sampleFreq;
} APM_Info;

typedef struct APM_BufStruct {
   kal_int16   *inBuf;           // Input buffer
   kal_uint32  inBufLen;         //    size in Word
   kal_int16   *outBuf;          // Output buffer
   kal_uint32  outBufLen;        //    in Word
} APM_Buffer;

typedef struct APM_TCM_STRUCT {
   kal_uint32 *tcmBuf;          // TCM buffer
   kal_uint32 tcmBufLen;        //    in World
} APM_TCM;

/* ---- Audio Post-Processing Interface ---- */
void HOST_APM_Register(APM_TaskID taskID);
void HOST_APM_UnRegister(APM_TaskID taskID);
void APM_Init( void );                                                 /* l1audio internal use */
void APM_ClearBuffer(void);                                            /* l1audio internal use */
void APM_Activate( kal_int16 asp_type, kal_int16 freqInd);             /* l1audio internal use */
void APM_Deactivate(void);                                             /* l1audio internal use */
void APM_SetEOF(void);                                                 /* l1audio internal use, in each audio driver */
kal_bool APM_IsEOF(void);                                              /* l1audio internal use, in each audio driver */
void APM_NOTIFY_MEDIA_END(void (*HookFunc)(void *data, Media_Event event), void *data, kal_bool isNew, Media_Event event);   /* l1audio internal use */
void APM_EXECUTE_END_HANDLER(void);                                    /* l1audio internal use */
kal_int32 APM_AV_DelayCount(void);                                     /* For AV sync, return samples/6        */
void APM_AV_ConsumeDelay(kal_int32 numInt);                            /* For AV sync, consume interrupt count */
kal_uint8 *APM_Allocate_Buffer(kal_uint32 bufSize);                    /* l1audio internal use */
void APM_Release_Buffer(void);                                         /* l1audio internal use */
void APM_NotifyDropFrame(kal_bool isDrop);                             /* l1audio internal use */
void APM_SetPP_Param( APM_TaskID apm_Id, kal_uint32 runTimeParamSize, void *pRuntimeParam, kal_uint32 bsInitParSize, void *bsInitPar );
kal_bool APM_IsRunning(void);

/* ------------------------------------------------------------------------------ */
//#ifndef MED_NOT_PRESENT
//-- For Time Stretch
Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode);
void AudioPP_TS_Close(void);
kal_uint16 AudioPP_TS_GetSpeed(void);
kal_bool AudioPP_TS_IsEnable(void);
kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL);
//#endif

//-- For Reverb
/*enum ReverbMode{
   CONCERT = 0,
   SHOWER,
   CHURCH,
   SMALLROOM,
   OPERA,
   BATHROOM
};*/
extern void AudioPP_Reverb_SetMode( kal_uint32 reverb_mode );
extern Media_Status AudioPP_Reverb_TurnOn(void);
extern void AudioPP_Reverb_TurnOff(void);
extern void AudioPP_Reverb_Enable(void);             /* l1audio internal use */
extern void AudioPP_Reverb_Disable(kal_bool wait);   /* l1audio internal use */

/* Internal Use */
void AudioPP_TS_Init(void);                          /* l1audio internal use */
void AudioPP_TS_Activate(kal_bool voice_init);       /* l1audio internal use */
void AudioPP_Close(void);                            /* l1audio internal use */
void AudioPP_Disable(void);                          /* l1audio internal use */
void AudioPP_Enable(void);                           /* l1audio internal use */
void AudioPP_SetMediaFormat(Media_Format eFormat);   /* l1audio internal use for Midi */
kal_int32 AudioPP_GetTSRate( void );                 /* l1audio internal use for Midi */

//-- For 3D Surround
extern void AudioPP_Surround_Enable( void );
extern void AudioPP_Surround_Disable( void );
extern void AudioPP_Surround_ModeSelect(int mode);

/*  Bass Enhancement*/
void AudioPP_BassEnhance_Enable( void );
void AudioPP_BassEnhance_Disable( void );
void AudioPP_BassEnhance_Registry( void );           /* l1audio internal use */

// Loudness
void AudioPP_Loudness_Enable( void );
void AudioPP_Loudness_Disable( void );
kal_uint32 AudioPP_Loudness_GetMode( void );   /* l1audio internal use */

// LGE BT System (AVM)
void AudioPP_AVM_Enable( void );
void AudioPP_AVM_Disable( void );

// LGE OAEP (Audio Effect Package for Opera)
void AudioPP_OAEP_Enable( void );
void AudioPP_OAEP_Disable( void );
void AudioPP_OAEP_SetEffectMode( kal_uint32 mode, void *param );
void AudioPP_OAEP_SetOutputType( kal_uint32 eType );

// Disable / enable bessound
void AudioPP_DisableBesSound( void );
void AudioPP_EnableBesSound( void );

/* ------------------------------------------------------------------------------ */
void SPT_Open( void );
void SPT_Close( void );
void SPT_GetSpectrum( kal_uint8 top[16], kal_uint8 val[16] );
void SPT_PutPcmData( const kal_int16 *pcm, kal_int32 len, kal_bool mono );    /* L1audio internal use */

/* FM Radio Interface */
void  FMR_PowerOn(void);
void  FMR_PowerOff(void);
kal_uint8 FMR_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up);
void  FMR_SetFreq(kal_int16 curf);
void FMR_AutoSearch(kal_uint8 dir, void(*fm_handler)(kal_int16 *data));
kal_int16 FMR_ManualSearch(kal_uint8 dir);
kal_int16 FMR_GetFreq(void);
void  FMR_Mute(kal_uint8 mute);
void  FMR_Mono(kal_uint8 MS);
void  FMR_Standby(kal_uint8 standby);
void FMR_SetOutputDevice( kal_uint8 device );
void  FMR_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
kal_uint8 FMR_GetSignalLevel(kal_int16 curf);
void FMR_EvaluateRSSIThreshold(void);
void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
kal_uint16 FMR_GetIFCount(kal_int16 curf);
kal_uint16 FMR_ReadByte(kal_uint8 addr);
void FMR_WriteByte(kal_uint8 addr, kal_uint16 data);
void FMR_SoftMuteOnOff(kal_uint8 On_Off);
void FMR_SoftMuteStage(kal_uint8 stage);
void FMR_StereoBlendStage(kal_uint8 stage);
kal_uint8 FMR_GetChipID(void);
kal_uint8 FMR_Get_H_L_side(kal_int16 curf);
kal_uint8 FMR_Get_stereo_mono(void);
kal_uint8 FMR_CheckOption(void);
kal_bool FMR_IsActive(void);
kal_bool FMR_HWSearch( void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_valid ), kal_int16 wStartFreq, kal_bool is_up, kal_int16 wSpace, kal_bool is_preset );
void FMR_HWSearchForceStop(void);

/* ------------------------------------------------------------------------------ */

/* A/V Sync Interface */

kal_uint32 Media_A2V_GetInterruptCount(void);
void Media_A2V_EnableInterrupt(kal_bool bFlag, kal_uint32 start_count);
void Media_A2V_HookInterrupt(void (*a2v_lisr)(void));
void Media_A2V_SetTimeStamp(kal_uint16 wTimeStamp);
void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount);
kal_uint16 Media_A2V_GetAudioFrameCount(void);
kal_uint16 Media_A2V_GetVideoFrameCount(void);
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetRecInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetRecInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex);
kal_uint32 Media_A2V_GetAudioPlaybackDelay(Media_Format eFormat);
kal_uint32 Media_A2V_GetAudioRecordDelay(Media_Format eFormat);
Media_Status Media_A2V_Audio_GetPlayTime(kal_uint64 *puMiliSecond, kal_uint64 uAudioSeekPointTime, kal_uint32 speed_scale, kal_uint8 bAudioSamplingFreqIndex, Media_Format eFormat);
Media_Status Media_A2V_Video_GetPlayTime(kal_uint64 *puMiliSecond, kal_uint32 speed_scale, kal_uint8 bAudioSamplingFreqIndex, Media_Format eFormat);
void Media_A2V_SetPlaybackTimerBase(kal_uint32 uPlaybackTimeBase, kal_bool bResetPreviousInterruptCount);
void Media_A2V_DisableDspSleep(kal_bool disable);

void Media_A2V_SetMediaFormat(Media_Format format);
void Media_A2V_SetFreq(kal_uint32 uSamplingFreq);
void Media_A2V_SetSpeedScale(kal_uint32 speed_scale);

void Media_A2V_SetInterruptTime(kal_uint16 msTime);
Media_Status Media_A2V_Audio_GetPlayTime_S( kal_uint64 *puMiliSecond, kal_uint64 uAudioSeekPointTime );
Media_Status Media_A2V_Video_GetPlayTime_S(kal_uint64 *puMiliSecond);

/* ------------------------------------------------------------------------------ */
typedef enum {
   POC_AMR_NONE   = 0x00,
   POC_AMR_0475   = 0x01,
   POC_AMR_0515   = 0x02,
   POC_AMR_0590   = 0x04,
   POC_AMR_0670   = 0x08,
   POC_AMR_0740   = 0x10,
   POC_AMR_0795   = 0x20,
   POC_AMR_1020   = 0x40,
   POC_AMR_1220   = 0x80,
   POC_AMR_ALL    = 0xFF
} PoC_AMR_Type;

void PoC_AMR_SetBuffer(kal_uint16 *buf, kal_uint32 len);
PoC_AMR_Type PoC_AMR_GetVocoderCapability(void);
Media_Status PoC_AMR_EncodeStart( PoC_AMR_Type vocoder, void (*media_handler)(void), kal_int32 frame_threshold );
Media_Status PoC_AMR_EncodeStop( void );
Media_Status PoC_AMR_DecodeStart( void );
Media_Status PoC_AMR_DecodeStop( void );
kal_int32 PoC_AMR_GetFrameCount( void );
kal_int32 PoC_AMR_GetPayload( kal_uint8 *buf, kal_int32 len, kal_int32 frames );
Media_Status PoC_AMR_PutPayload( const kal_uint8 *buf, kal_int32 len );

/* ------------------------------------------------------------------------------ */
/* VR SD Interface */
typedef enum
{
   VR_FINISHED,
   VR_OK,
   VR_FAILED,
   VR_CONTINUE,
   VR_NO_SOUND,
   VR_TOO_SIM,
   VR_TOO_DIFF,
   VR_SDMODEL_NOT_READY,
   VR_MISMATCH_ID,
   VR_EXISTENT_ID,
   VR_FLASH_DISK_FULL,
   VR_FLASH_ERROR,
   VR_STOP,
   VR_TOO_LONG,
   VR_TOO_SHORT
} VR_Result;

VR_Result VR_GetParameters(kal_int16 *SimThrld, kal_int16 *DiffThrld, kal_int16 *RejThrld);
VR_Result VR_SetParemeters (kal_int16 SimThrld, kal_int16 DiffThrld, kal_int16 RejThrld);
kal_uint32 VR_GetBufferSize(void);
void VR_SetBuffer(kal_uint8 *RTmemory);
VR_Result  VR_SetDatabaseDir(kal_uint8 *Dir);
VR_Result VR_TRA_Start(kal_uint16 wID, kal_uint16 *mdIDList, kal_uint16 *mdIDListLen, void (*vr_handler)(void *parameter ));
VR_Result VR_TRA2Start(void);
VR_Result VR_RCG_Start(kal_uint16 *mdIDList,kal_uint16 *mdIDListLen,void(*vr_handler)(void *parameter));
VR_Result VR_Process(kal_uint16 *RcgID);
void VR_Stop(void);
kal_int32 VR_GetEngineVer(void);
/* ------------------------------------------------------------------------------ */

typedef void* VRSI_Handle;

typedef enum {
   VRSI_OK,
   VRSI_FAIL
}VRSI_Status;

typedef enum {
   VRSI_PROCESS,
   VRSI_PLAY_REQUEST,
   VRSI_RECOG_MPR,
   VRSI_RECOG_OK,
   VRSI_DIGIT_RECOG_MPR,
   VRSI_DIGIT_RECOG_OK,
   VRSI_DIGIT_ADAPT_MPR,
   VRSI_DIGIT_ADAPT_OK,
   VRSI_TRAIN_TAG_1ST_MPR,
   VRSI_TRAIN_TAG_2ND_MPR,
   VRSI_TRAIN_TAG_OK,
   VRSI_ADD_TAGS_OK,
   VRSI_TTS_OK,
   VRSI_PLAY_TAG_OK,
   VRSI_START_CAPTURE_TIMER,
   VRSI_START_PLAYBACK_TIMER,
   VRSI_START_PROCESS_TIMER,
   VRSI_START_QUICK_TIMER,
   VRSI_STOP_TIMER,
   VRSI_ERROR
}VRSI_Event;

typedef enum {
   VRSI_ERR_NO,
   VRSI_ERR_UNINITIALIZED,
   VRSI_ERR_STATE_UNMATCH,
   VRSI_ERR_BUSY,
   VRSI_ERR_INSUFFICIENT_MEM,
   VRSI_ERR_TOO_MANY_TAGS,
   VRSI_ERR_WRONG_DATA_DIR,
   VRSI_ERR_WRONG_DATA_FILE,
   VRSI_ERR_LIBRARY_CORRUPT,
   VRSI_ERR_DB_FULL,
   VRSI_ERR_DB_ERROR,
   VRSI_ERR_NO_MATCH_TAG,
   VRSI_ERR_NO_SOUND,
   VRSI_ERR_LANG_NOT_SUPPORT,
   VRSI_ERR_BAD_GRAMMAR,
   VRSI_ERR_ADD_TAGS_FAIL,
   VRSI_ERR_TRAIN_TAG_FAIL,
   VRSI_ERR_RECOG_FAIL,
   VRSI_ERR_DIGIT_RECOG_FAIL,
   VRSI_ERR_DIGIT_ADAPT_FAIL,
   VRSI_ERR_TTS_TOO_LONG,
   VRSI_ERR_EVALUATE_VER,  // evaluation version : only allow 15 times recog.
   VRSI_ERR_UNKNOWN
}VRSI_ErrMsg;


typedef enum{
   VRSI_LANG_TAIWAN,
   VRSI_LANG_CHINA,
   VRSI_LANG_AMERICAN,
   VRSI_LANG_BRITISH
}VRSI_Language;

// data structure
typedef struct{
   kal_uint16 *pTagName;
   kal_int32 tagLong;
   kal_uint16 tagID;
   kal_uint8 isPeopleName;
}VRSI_Tag_Param;

typedef struct {
   kal_uint16 **ppTagName;
   kal_int32 *pTagLong;
   kal_uint8  *pIsPeopleName;
   kal_uint16 numTag;
}VRSI_AddTags_Param;


typedef struct {
   kal_uint16 *pTagID;
   //kal_int32 *pTagLong;
   kal_uint16 **ppTagName;
   kal_uint16 numTag;
}VRSI_AddTags_Result;

typedef struct {
   kal_uint16 *pTagID;
   kal_int32 *pTagLong;
   kal_uint16 **ppTagName;
   kal_uint16 numTag;
   kal_uint16 resType;
   kal_int16 preCmd;
   kal_int16 postCmd;
}VRSI_Recog_Result;

typedef struct {
   kal_uint16 digitLen;
   kal_uint16 *pDigits;
}VRSI_Digit_Recog_Result;

// API functions
VRSI_Status VRSI_Init( void (*vrsi_handler)( VRSI_Event event ));
kal_uint32 VRSI_GetMemRequest(kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag );
VRSI_Status VRSI_SetMem(kal_uint8 *memory, kal_uint32 size, kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag ,kal_uint16 *vrsiDir); 
VRSI_Status VRSI_Add_Tags(const kal_uint8 *grammar, VRSI_AddTags_Param *param );
VRSI_Status VRSI_Train_Tag (const kal_uint8 *grammar, VRSI_Tag_Param *param );
VRSI_Status VRSI_Recog(const kal_uint8 *grammar );
VRSI_Status VRSI_Digit_Recog( VRSI_Language  lang, kal_uint16 limit );
VRSI_Status VRSI_Digit_Adapt( VRSI_Language  lang );
VRSI_Status VRSI_Play_Tag( const kal_uint8 *grammar , kal_uint16 tagID ,void* param  );
VRSI_Status VRSI_TTS_Play( VRSI_Language lang, kal_uint16 *pText );
VRSI_Status VRSI_Process( void );
void VRSI_ReadPrompt (  kal_uint8 *promptLen, const kal_uint16 **prompt );
void VRSI_MMI_Confirmed( void );
void VRSI_ReadResult( void **result );
VRSI_ErrMsg VRSI_GetErrMsg( void );
VRSI_Status VRSI_Gram_GetTagNum(const kal_uint8 *grammar , kal_int32 *tagNum );
VRSI_Status VRSI_Gram_ReadTagIDs(const kal_uint8 *grammar, kal_uint16 *pTagID , kal_int32 bufferSize, kal_int32 *readTagNum);
VRSI_Status VRSI_Gram_DeleteAllTags( const kal_uint8 *grammar );
VRSI_Status VRSI_DeleteTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_int32 *delTagNum, kal_uint16 *pDelTagID );
VRSI_Status VRSI_TagExist( const kal_uint8 *grammar, kal_uint16 tagID, kal_bool *bExist  );
VRSI_Status VRSI_ReadTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_uint16 **ppTagName, kal_int32 *pTagLong );
VRSI_Status VRSI_Stop( void );
VRSI_Status VRSI_Close( void );
VRSI_Status VRSI_QueryTagId(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 *tagID );
VRSI_Status VRSI_QueryNextTagId(const kal_uint8 *grammar, kal_uint16 *tagID );
VRSI_Status VRSI_QueryAllTagIds(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 buf_size, kal_uint16 *id_buf, kal_uint16 *tagNum, kal_bool *getAll );

MHdl *BGSND_Open(void(*handler)(MHdl *, Media_Event), void *param);
Media_Status BGSND_Play( MHdl *hdl );
void BGSND_Stop( MHdl *hdl );
Media_Status BGSND_Close(MHdl *hdl);
void BGSND_SetOutputDevice( kal_uint8 device );
void BGSND_ConfigULMixer( MHdl *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
void BGSND_ConfigDLMixer( MHdl *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );

// L1CTM interface 
typedef enum{
   DIRECT_MODE,
   BAUDOT_MODE       
} L1Ctm_Interface; 

typedef enum{
   CTM_MO_SUCCESS,
   CTM_MO_FAIL, 
   CTM_MT_DETECTED, 
   CTM_CHAR_SENT, 
   CTM_CHAR_RECEIVED,
   CTM_TX_BURST_START,
   CTM_TX_BURST_END   
} L1Ctm_Event; 

typedef struct
{
    kal_int16   cprm_tone_demod_down_samp;                  // 1 (0, 1)   
} CTM_Param;

typedef void (*L1Ctm_Callback)(L1Ctm_Event , void*); 
kal_uint32 L1Ctm_GetMemReq(void);
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, kal_uint8 *buf, kal_uint32 buf_len, CTM_Param *ctm_param);
void L1Ctm_Close(void);
void L1Ctm_StartNegotiation(void);
kal_uint32 L1Ctm_TxPutText(const kal_uint8 *text, kal_uint32 len, kal_uint32 *left_space);
kal_uint32 L1Ctm_RxGetText(kal_uint8 *text, kal_uint32 len, kal_uint32 *left_count);

// eCall modem interface
typedef enum {
   eCALL_OPERATION_SUCCESS,
   eCALL_OPERATION_FAIL,
   eCALL_OPERATION_ALREADY_OPEN,
   eCALL_OPERATION_ALREADY_CLOSE,
   eCALL_OPERATION_DURING_TRANSMISSION
} eCall_Modem_Status;

typedef enum {
   eCALL_EVENT_SEND_START,
   eCALL_EVENT_RECV_START,
   eCALL_EVENT_RECV_NACK,
   eCALL_EVENT_RECV_LL_ACK,
   eCALL_EVENT_RECV_HL_ACK_CORRECT,
   eCALL_EVENT_RECV_HL_ACK_MISMATCH,
   eCALL_EVENT_PSAP_RECV_MSD
} eCall_Modem_Event;

typedef void (*eCall_Callback)(eCall_Modem_Event event, void *param);

eCall_Modem_Status eCall_IVS_Open(eCall_Callback handler);
eCall_Modem_Status eCall_IVS_Close(void);
eCall_Modem_Status eCall_IVS_PutMSD(const kal_uint8 *pMSD, const kal_uint32 uLen);
eCall_Modem_Status eCall_IVS_SendStart(void);
eCall_Modem_Status eCall_PSAP_Open(eCall_Callback handler);
eCall_Modem_Status eCall_PSAP_Close(void);
eCall_Modem_Status eCall_PSAP_SendStart(void);

// WMA API
//Media_Event WMA_Process( Media_Handle *hdl, Media_Event event );
//Media_Status WMA_SetStartTime( Media_Handle *hdl, kal_int32 msStartTime );
//Media_Status WMA_SetStopTime( Media_Handle *hdl, kal_int32 msStopTime );
//kal_int32 WMA_GetCurrentTime( Media_Handle *hdl );
//kal_int32 WMA_GetDuration( STFSAL *pstFSAL );
//Media_Status WMA_SetLevel( Media_Handle *hdl, kal_uint8 level );
//kal_uint8 WMA_GetLevel( Media_Handle *hdl );
//Media_Handle *WMA_Open(void(*handler)( Media_Handle *handle, Media_Event event ), STFSAL *pstFSAL);
//Media_Status WMA_Close( Media_Handle *hdl );
//void WMA_SetBuffer( Media_Handle *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
//Media_Status WMA_Play( Media_Handle *hdl );
//Media_Status WMA_Stop( Media_Handle *hdl );
//Media_Status WMA_Pause( Media_Handle *hdl );
//Media_Status WMA_Resume( Media_Handle *hdl );
//Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo );

// AAC interface
//Media_Event AAC_Process( Media_Handle *hdl, Media_Event event );
//Media_Status AAC_SetStartTime( Media_Handle *hdl, kal_int32 msStartTime );
//Media_Status AAC_SetStopTime( Media_Handle *hdl, kal_int32 msStopTime );
//kal_int32 AAC_GetCurrentTime( Media_Handle *hdl );
//kal_int32 AAC_GetDuration( STFSAL *pstFSAL );
//Media_Status AAC_SetLevel( Media_Handle *hdl, kal_uint8 level );
//kal_uint8 AAC_GetLevel( Media_Handle *hdl );
//Media_Handle *AAC_Open(void(*handler)( Media_Handle *handle, Media_Event event ), STFSAL *pstFSAL);
//Media_Status AAC_Close( Media_Handle *hdl );
//void AAC_SetBuffer( Media_Handle *hdl, kal_uint8 *buffer, kal_uint32 buf_len );
//Media_Status AAC_Play( Media_Handle *hdl );
//Media_Status AAC_Stop( Media_Handle *hdl );
//Media_Status AAC_Pause( Media_Handle *hdl );
//Media_Status AAC_Resume( Media_Handle *hdl );
//Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo );
//kal_bool AAC_IsPPSupport( STFSAL *pstFSAL);
/* ------------------------------------------------------------------------------ */
//#ifndef MED_NOT_PRESENT
/* -------------------------------------------- */
/* Sound effect interface */
typedef struct {
   STFSAL           *pstFSAL;
   kal_int16         repeats;             /* 0 -> endless               */
   Media_Format  format;
} Snd_Param;

void sndProcess( Media_Handle *hdl );
Media_Status SND_GetFormat(STFSAL *pstFSAL, Media_Format *pFormat);
Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), Snd_Param **param);
Media_Status SND_Close(Media_Handle *hdl);
Media_Status SND_Play( Media_Handle *hdl );
void SND_Stop( Media_Handle *hdl );
void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
void SND_SetOutputDevice( kal_uint8 device );


/* SBC event */
typedef enum{
   A2DP_DATA_NOTIFY
} A2DP_Event;

typedef void (*A2DP_Callback)(A2DP_Event , void*);

typedef struct{
    kal_uint32 (*GetPayload)(kal_uint8 *, kal_uint32, kal_uint32 *);
    void (*GetPayloadDone)(void);
    void (*QueryPayloadSize)(kal_uint32 *, kal_uint32 *);
    kal_uint32 (*AdjustBitRateFromQos)(kal_uint8); // return adjusted bit rate
    kal_uint32 (*SetBitRate)(kal_uint32); // return adjusted bit rate
    kal_uint8 state;
} A2DP_codec_struct;

#ifndef __BT_A2DP_CODEC_TYPES__
#define __BT_A2DP_CODEC_TYPES__
typedef struct
{
	kal_uint8 min_bit_pool;
	kal_uint8 max_bit_pool;
	kal_uint8 block_len; // b0: 16, b1: 12, b2: 8, b3: 4
	kal_uint8 subband_num; // b0: 8, b1: 4
	kal_uint8 alloc_method; // b0: loudness, b1: SNR
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 16000
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
} bt_a2dp_sbc_codec_cap_struct;

typedef struct
{
	kal_uint8 layer; // b0: layerIII, b1: layerII, b0: layerI
	kal_bool CRC;
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
	kal_bool MPF; // is support MPF-2
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
	kal_bool VBR; // is support VBR
	kal_uint16 bit_rate; // bit-rate index in ISO 11172-3 , b0:0000 ~ b14: 1110
} bt_a2dp_mp3_codec_cap_struct; /* all MPEG-1,2 Audio */

typedef struct
{
	kal_uint8 object_type; // b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
	kal_uint16 sample_rate; // b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
	kal_uint8 channels; // b0: 2, b1: 1
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // constant/peak bits per second in 23 bit UiMsbf, 0:unknown
} bt_a2dp_aac_codec_cap_struct; /* all MPEG-2,4 AAC */

typedef struct
{
	kal_uint8 version; // 1:ATRAC, 2:ATRAC2, 3:ATRAC3
	kal_uint8 channel_mode; // b0: joint stereo, b1: dual, b2: single
	kal_uint8 sample_rate; // b0: 48000, b1: 44100
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // bit-rate index in ATRAC, b0: 0x0012 ~ b18: 0x0000
	kal_uint16 max_sul; // sound unit length in 16 bits UiMsbf
} bt_a2dp_atrac_codec_cap_struct; /* all ATRAC family */

typedef union
{
	kal_uint8 aptx_cap;
} vendor_codec_cap_union;

typedef struct
{
	kal_uint16 id;
	vendor_codec_cap_union cap;
} vendor_codec_struct;

typedef struct
{
	kal_uint32 vendor_id;  
	vendor_codec_struct vendor_codec;
} bt_a2dp_vendor_codec_cap_struct; /* vendor specific codec */

typedef union
{
	bt_a2dp_sbc_codec_cap_struct sbc;
	bt_a2dp_mp3_codec_cap_struct mp3;
	bt_a2dp_aac_codec_cap_struct aac;
	bt_a2dp_atrac_codec_cap_struct atrac;
	bt_a2dp_vendor_codec_cap_struct vend;
} bt_a2dp_audio_codec_cap_struct;

typedef struct
{
	kal_uint8 codec_type; // SBC, MP3
	bt_a2dp_audio_codec_cap_struct codec_cap;
} bt_a2dp_audio_cap_struct;

#endif /* __BT_A2DP_CODEC_TYPES__ */

typedef struct
{
	kal_uint32 min_bit_rate;
} bt_a2dp_sbc_codec_info_struct;

#define SBC_MID_QUALITY 1
#define SBC_HIGH_QUALITY 2
#define SBC_BEST_QUALITY 3

void SBC_Init(void);
kal_uint32 SBC_GetMemReq(void);
A2DP_codec_struct *SBC_Open( Media_Format aud_fmt, A2DP_Callback pHandler, bt_a2dp_sbc_codec_cap_struct *sbc_config_data, kal_uint8 *buf, kal_uint32 buf_len);
void SBC_Close(void);
void SBC_InitiateBitPool(kal_uint8 channel_mode, kal_uint8 sample_rate, kal_uint8 *min, kal_uint8 *max );
void SBC_AdjustBitpool( kal_uint8 max_bitpool, kal_uint8 min_bitpool );
kal_uint32 SBC_SetQualityLevel(kal_uint32 level);
extern void sbc_initiate_internal(const kal_uint8 code[16]);
void SBC_SetLevelVolume( kal_uint8 uCurStep, kal_uint8 uTotalStep );
void SBC_MuteSpeaker( kal_bool mute );
void SBC_QueryInfo(bt_a2dp_sbc_codec_info_struct *info);

void BT_SetLevelVolume( kal_uint8 uCurStep, kal_uint8 uTotalStep );
void BT_MuteSpeaker( kal_bool mute );

kal_uint32 A2DP_DAF_GetMemReq(void);
A2DP_codec_struct *A2DP_DAF_Open( MHdl *mhdl_handle, A2DP_Callback pHandler, bt_a2dp_mp3_codec_cap_struct *daf_config_data, kal_uint8 *buf, kal_uint32 buf_len);
void A2DP_DAF_Close( MHdl *mhdl_handle );

typedef enum {
    PLAYBACK_CH_NORMAL = 0,
    PLAYBACK_CH_LEFT   = 1,
    PLAYBACK_CH_RIGHT  = 2
} Playback_Channel_Type;

typedef struct {
    Playback_Channel_Type channel_type;
    kal_uint32 start_time;
    kal_uint32 offset;
} A2DP_Stream_Start_Param;

typedef enum {
    A2DP_STREAM_DEVICE_BTD1 = 0x1,
    A2DP_STREAM_DEVICE_BTD2 = 0x2
} A2DP_Stream_Device;

void Media_Set_A2DP_Stream_Start_Time(A2DP_Stream_Start_Param *p_param);
kal_uint32 Media_Get_A2DP_Reserved_Bytes(void);
kal_uint32 Media_Get_A2DP_Delay_Timing(A2DP_Stream_Device device);
kal_uint32 Media_Add_A2DP_Next_Device_Start_Time(kal_uint8 *p_in, kal_uint8 *p_out, kal_uint32 payload_len, kal_uint32 start_time);
kal_uint32 Media_Check_A2DP_Stream(kal_uint8 *p_payload, kal_uint32 payload_len);

MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *VM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *DAF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *COOK_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *WAV_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *WAV_OpenRender(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param); // Internal use
MHdl *AIFF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *AU_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *AAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *BSAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *M4A_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *PCM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *WMA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param);
MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param);
MHdl *AWB_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *APE_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *DRA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *VORBIS_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *VORBIS_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *FLAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);
MHdl *A2DPDec_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param);

Media_Status AU_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AIFF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status WAV_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status M4A_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status MP4_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status DAF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status WMA_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status VM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status PCM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status AWB_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status APE_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status VORBIS_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status JSmf_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status JImy_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  );
Media_Status FLAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
Media_Status A2DP_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );

Media_Status AAC_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status DAF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status JSmf_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status JImy_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status WMA_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status WAV_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AIFF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AU_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status AWB_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status M4A_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status APE_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );
Media_Status VORBIS_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );

Media_Format AAC_GetMediaFormat_Detail_v2(kal_uint8 *pBuf, kal_uint32 uBufLen, kal_uint32 *uChannel, kal_uint32 *uSampleRate); /* L1Audio Internal Use */
Media_Format AAC_GetMediaFormat_Detail(STFSAL *pstFSAL, kal_uint32 *uChannel, kal_uint32 *uSampleRate); /* L1Audio Internal Use */
Media_Format AAC_GetMediaFormat(STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool AAC_IsPPSupport(STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool M4A_IsPPSupport(STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool WAV_IsPPSupport(STFSAL *pstFSAL);   /* L1Audio Internal Use */
kal_bool AAC_IsADIF( STFSAL *pstFSAL);
kal_bool APE_IsSeekable( STFSAL *pstFSAL);

void AAC_Plus_Forbidden(void);

//#endif /*ifndef MED_NOT_PRESENT */

// KH
MHdl *VM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param);

/* VoRTP interface */
typedef kal_uint32 VORTP_STATUS;
#define VORTP_STATUS_SUCCESS                (VORTP_STATUS)0
#define VORTP_STATUS_FAIL                   (VORTP_STATUS)1
#define VORTP_STATUS_NOT_SUPPORTED_CONFIG   (VORTP_STATUS)2

typedef kal_uint32 VORTP_EVENT;
#define VORTP_EVENT_FATAL_ERROR   (VORTP_EVENT)0
#define VORTP_EVENT_UL_READY      (VORTP_EVENT)1
#define VORTP_EVENT_DL_ERROR      (VORTP_EVENT)2
#define VORTP_EVENT_TONE_FINISH   (VORTP_EVENT)3

#define RTP_CAP_UNSPECIFIED    0
typedef enum {
   RTP_CODEC_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
   RTP_CODEC_SUPPORT = 1,
   RTP_CODEC_UNSUPPORT = 2
} rtp_cap_bool;

typedef enum {
   AudRTP_STATUS_SUCCESS,
   AudRTP_STATUS_FAIL,
   AudRTP_STATUS_NOT_OCTET_ALIGN,
   AudRTP_STATUS_NOT_SINGLE_CHANNEL,
   AudRTP_STATUS_UNSUPPORT_CHANNEL_NUM,
   AudRTP_STATUS_SAMPLE_RATE_NOT_SUPPORT,
   AudRTP_STATUS_TYPE_NOT_SUPPORT
} AudRTP_STATUS;

typedef enum {
   AudRTP_EVENT_BUF_OVERFLOW = 0x100,
   AudRTP_EVENT_BUF_UNDERFLOW = 0x200,
   AudRTP_EVENT_PACKET_LOSS = 0x400,
   AudRTP_EVENT_MEDIA_ERROR = 0x800
} AudRTP_EVENT;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool octet_align, mode_change_neighbor, crc, robust_sorting;
   enum {
      AMR_MODE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      AMR_MODE_0_0475 = 0x1,
      AMR_MODE_1_0515 = 0x2,
      AMR_MODE_2_0590 = 0x4,
      AMR_MODE_3_0670 = 0x8,
      AMR_MODE_4_0740 = 0x10,
      AMR_MODE_5_0795 = 0x20,
      AMR_MODE_6_1020 = 0x40,
      AMR_MODE_7_1220 = 0x80,
      AMR_MODE_ALL = 0xFF
   } mode_set;
   kal_uint16 mode_change_period;
   kal_uint16 interleaving; // defines the maximum number of frame-blocks allowed in an interleaving group
   kal_uint16 channels; // indicates max. number of channels
} rtp_audio_amr_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool annexb;
} rtp_audio_g729_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   enum {
      G7231_BITRATE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      G7231_BITRATE_0530 = 1,
      G7231_BITRATE_0630 = 2
   } bitrate;
   rtp_cap_bool annexa;   
} rtp_audio_g7231_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool cn_payload;
} rtp_audio_g726_cap_struct;

typedef struct {
   kal_uint16 ptime;
   kal_uint16 maxptime;
   rtp_cap_bool cn_payload;
   enum {
      G711_RATE_UNSPECIFIED = RTP_CAP_UNSPECIFIED,
      G711_RATE_8000 = 1
   } rate;
   kal_uint8 channel; // the maximum
} rtp_audio_g711_cap_struct;

typedef enum {
   UNSUPPORTED = 0,
   AAC_LBR = 1,
   AAC_HBR = 2
} AudRTP_AAC_MODE;

typedef struct {

  // MP4A_LATM  // RFC 3016
    kal_uint32    rate;   // indicates the RTP time stamp clock rate
    kal_uint32    bitrate;
    kal_bool      cpresent;
    kal_uint16    ptime;

  // MPEG4_GENERIC  // RFC3640
    AudRTP_AAC_MODE        mode;
    kal_uint32    streamType;
    kal_uint32    uSizeLength;
    kal_uint32    uIndexLength;
    kal_uint32    uIndexDeltaLength;
    kal_uint32    uConstantSize;
    kal_uint32    uConstantDuration;
    kal_uint32    uMaxDisplacement;
    kal_uint32    uDeinterleaveBufSize;

  // common
    kal_uint32    profile_level_id;  // indicate MP4 audio profile level
    kal_uint8     *config;
    kal_uint32    object;  // MP4 Audio object type 

    kal_uint32    channel;
    kal_uint32    sample_rate;
#if defined(BSAC_DECODE)
/* under construction !*/
/* under construction !*/
#endif // #if defined(BSAC_DECODE)
} rtp_audio_aac_cap_struct;

typedef struct {
    kal_uint32    channel;
    kal_uint32    sample_rate;
    kal_uint32    byteOrder;  // 0: file;  1: transmission
} rtp_audio_dra_cap_struct;

typedef struct {
    kal_int32          nSamples;
    kal_int32          nChannels; 
    kal_int32          nRegions; 
    kal_int32          nFrameBits; 
    kal_int32          sampRate; 
    kal_int32          cplStart; 
    kal_int32          cplQbits;
} rtp_audio_cook_cap_struct;

typedef enum {
   RTP_AUDIO_NONE = 0,
   RTP_AUDIO_AMR = 1,
   RTP_AUDIO_G729 = 2,
   RTP_AUDIO_G7231 = 4,
   RTP_AUDIO_G726_16 = 8,
   RTP_AUDIO_G726_24 = 16,
   RTP_AUDIO_G726_32 = 32,
   RTP_AUDIO_G726_40 = 64,
   RTP_AUDIO_PCMA = 128,
   RTP_AUDIO_PCMU = 256,
   RTP_AUDIO_CN = 512,
   RTP_AUDIO_AWB = 1024,
   RTP_AUDIO_MP4A_LATM_AAC = 2048,
   RTP_AUDIO_MPEG4_GENERIC_AAC = 4096,
   RTP_AUDIO_AWB_PLUS = 8192,
   RTP_AUDIO_BSAC = 16384,
   RTP_AUDIO_MP2 = 32768,
   RTP_AUDIO_MP3 = 65536,
   RTP_AUDIO_ACCESS_UNIT_AAC = 0x20000,
   RTP_AUDIO_DRA = 0x40000,
   RTP_AUDIO_COOK = 0x60000
} rtp_audio_codec_type;

Media_Format AudRTPtoMediaFormat(rtp_audio_codec_type rtpType);

typedef union {
   rtp_audio_amr_cap_struct   amr;
   rtp_audio_g729_cap_struct  g729;
   rtp_audio_g7231_cap_struct g7231;
   rtp_audio_g726_cap_struct  g726;
   rtp_audio_g711_cap_struct  g711;
   rtp_audio_aac_cap_struct   aac;
   rtp_audio_dra_cap_struct   dra;
   rtp_audio_cook_cap_struct   cook;
} rtp_audio_codec_cap;

typedef struct AudRTPDownlinkHandleStruct AudRTP_DL_HANDLE;
typedef void (*AudRTP_DL_CALLBACK)( AudRTP_EVENT event, AudRTP_DL_HANDLE *handle,
                                   void *host_data );

typedef struct{
   kal_uint8  *pAddrs;
   kal_uint32 uPktSize;
   kal_uint32 uSeqNum;
   kal_uint32 uTimeStamp;   
}JitterBuf;

typedef struct {
   kal_uint32 uSeqNum;
   kal_uint32 uPos;
   kal_uint32 uFrameCount;
} rtpPacketInfo;

#define MAX_JIT_PKT_CNT 5
#define MAX_KEEP_PKT_CNT 10

struct AudRTPDownlinkHandleStruct {
   AudRTP_STATUS         (*GetCodecCapability)(AudRTP_DL_HANDLE *handle,
                                               rtp_audio_codec_type codec_type,
                                               rtp_audio_codec_cap *codec_cap );
   AudRTP_STATUS         (*Config)(AudRTP_DL_HANDLE *handle,
                                   rtp_audio_codec_type codec_type,
                                   rtp_audio_codec_cap *codec_cap,
                                   AudRTP_DL_CALLBACK callback,
                                   void *host_data, kal_uint32 session_id );
   kal_uint32            (*GetBufferSize)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*SetBuffer)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size );
   AudRTP_STATUS         (*Close)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*Start)(AudRTP_DL_HANDLE *handle, kal_uint32 start_time );
   AudRTP_STATUS         (*Stop)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*PutPacket)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size);
   AudRTP_STATUS         (*CheckPkts)(AudRTP_DL_HANDLE *hdl, kal_uint32 start_seq, kal_uint32 diff_thre);
   AudRTP_STATUS         (*GetPlayTime)(AudRTP_DL_HANDLE *handle, kal_uint32 *p_current_time);
   AudRTP_STATUS         (*GetBufferStatus)(AudRTP_DL_HANDLE *handle, kal_uint32 *puCurBufDur, kal_uint32 *puBufFreeSize, kal_uint32 *puBufTotalSize, kal_uint32 *puMinBufTotalDur);

   AudRTP_STATUS         (*AddAccessUnit)(AudRTP_DL_HANDLE *handle, kal_uint8* au, kal_uint32 size, kal_uint32 timestamp);
   // Add Access Unit
   AudRTP_STATUS         (*RTP_Parser)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer, 
                                      kal_uint32 buffer_size, kal_uint8 *au, 
                                      kal_uint32 au_size, kal_uint32 *timestamp);

   kal_uint32            (*GetSamplingFreq)(AudRTP_DL_HANDLE *handle );
   kal_uint8             (*GetChannelNum)(AudRTP_DL_HANDLE *handle );
   void                  (*SetVolumeLevel)( AudRTP_DL_HANDLE *handle, kal_uint8 level );
   AudRTP_STATUS         (*GetMediaFormat)(AudRTP_DL_HANDLE *hdl, Media_Format *format );
   AudRTP_STATUS         (*AddStartDelayTime)(AudRTP_DL_HANDLE *handle, kal_uint32 msDesired, kal_uint32 *msResult);
   
   // internal use
   void                  (*callback)( AudRTP_EVENT event, AudRTP_DL_HANDLE *handle,
                                   void *host_data );
   rtp_audio_codec_cap   stCodecCap;
   rtp_audio_codec_type  eAudCodecType;
   JitterBuf             stJitBuf[MAX_JIT_PKT_CNT];
   rtpPacketInfo         pastPacketInfo[MAX_KEEP_PKT_CNT];
   kal_uint32            pastPacketIndex;
   MHdl                  *psMHdl;
   kal_uint32            host_data;
   kal_uint32            session_id;
   kal_uint32            uPrePacketNum;
   kal_uint32            uPreTimeStamp;
   kal_uint32            uTotalFrameInBuf;
   kal_uint32            uJitterBufPacketCnt;
   kal_uint32            uState;
   kal_uint32            uPacketLossCnt;

//#if defined(__STREAM_REC_SUPPORT__)
   // RTP recording
   kal_uint32            (*GetRecBufferSize)(AudRTP_DL_HANDLE *handle );
   AudRTP_STATUS         (*SetRecBuffer)(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer );
   AudRTP_STATUS         (*SetRecCallback)(AudRTP_DL_HANDLE *handle,
                                           void (*recCallback)( RTP_Rec_Info *info) );
   void                  (*recCallback)( RTP_Rec_Info *info);
//#endif

};

AudRTP_DL_HANDLE *RTPAudio_OpenDLChannel( rtp_audio_codec_type codec_type );
AudRTP_STATUS AudRTP_GetCodecCapability(rtp_audio_codec_type rtpType, rtp_audio_codec_cap *codec_cap);

AudRTP_STATUS AudRTP_AAC_GetCodecCapability(AudRTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );
AudRTP_STATUS AudRTP_AMR_GetCodecCapability(AudRTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );
AudRTP_STATUS AudRTP_DAF_GetCodecCapability(AudRTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );
AudRTP_STATUS AudRTP_AWP_GetCodecCapability(AudRTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );
AudRTP_STATUS AudRTP_DRA_GetCodecCapability(AudRTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );

typedef struct VoRTPUplinkHandleStruct VORTP_UL_HANDLE;
typedef struct VoRTPDownlinkHandleStruct VORTP_DL_HANDLE;
typedef void (*VORTP_UL_CALLBACK)( VORTP_EVENT event, VORTP_UL_HANDLE *handle, void *host_data );
typedef void (*VORTP_DL_CALLBACK)( VORTP_EVENT event, VORTP_DL_HANDLE *handle, void *host_data );
typedef void (*VORTP_TONE_CALLBACK)( VORTP_EVENT event, void *host_data );

struct VoRTPUplinkHandleStruct {
   rtp_audio_codec_type (*GetAvailableCodecs)( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type *alt_codec_type );
   VORTP_STATUS         (*GetCodecCapability)( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               kal_bool alternated );
   VORTP_STATUS         (*Config)            ( VORTP_UL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               VORTP_UL_CALLBACK callback, 
                                               void *host_data,
                                               kal_uint32 session_id );
   kal_uint32           (*GetBufferSize)     ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*SetBuffer)         ( VORTP_UL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size );
   VORTP_STATUS         (*Close)             ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*Start)             ( VORTP_UL_HANDLE *handle, kal_uint32 timestamp );
   VORTP_STATUS         (*Stop)              ( VORTP_UL_HANDLE *handle );
   VORTP_STATUS         (*SetMix)            ( VORTP_UL_HANDLE *handle, kal_bool enable ); // default on
   kal_int32            (*GetPacketCount)    ( VORTP_UL_HANDLE *handle );
   kal_uint32           (*GetPacket)         ( VORTP_UL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size, 
                                               rtp_audio_codec_type *codec_type );
   /* Below is for internal use */
   kal_uint8 			state;
   VORTP_UL_CALLBACK 	callback;
   void 				*host_data;
   kal_uint32 			session_id;
   kal_uint32 			timestamp;
};

struct VoRTPDownlinkHandleStruct {
   rtp_audio_codec_type (*GetAvailableCodecs)( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type *alt_codec_type );
   VORTP_STATUS         (*GetCodecCapability)( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               kal_bool alternated );
   VORTP_STATUS         (*Config)            ( VORTP_DL_HANDLE *handle, 
                                               rtp_audio_codec_type codec_type, 
                                               rtp_audio_codec_cap *codec_cap,
                                               VORTP_DL_CALLBACK callback, 
                                               void *host_data,
                                               kal_uint32 session_id );
   kal_uint32           (*GetBufferSize)     ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*SetBuffer)         ( VORTP_DL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size );
   VORTP_STATUS         (*Close)             ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*Start)             ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*Stop)              ( VORTP_DL_HANDLE *handle );
   VORTP_STATUS         (*PutPacket)         ( VORTP_DL_HANDLE *handle, 
                                               kal_uint8 *buffer, 
                                               kal_uint32 buffer_size, 
                                               rtp_audio_codec_type codec_type );
   /* Below is for internal use */
   kal_uint8 			state;
   VORTP_DL_CALLBACK 	callback;
   void 				*host_data;
   kal_uint32 			session_id;
};

// Internal Use
void audRTP_putRecDataCircular( MHdl *hdl, kal_uint32 dataLen);

VORTP_UL_HANDLE *PoCAMR_OpenULChannel( void );
VORTP_DL_HANDLE *PoCAMR_OpenDLChannel( void );

void Vortp_HookSndHandler(void (*handler)(void*), void *userData );
void Vortp_UnhookSndHandler(void);
VORTP_UL_HANDLE *VoRTP_OpenULChannel( void );
VORTP_DL_HANDLE *VoRTP_OpenDLChannel( void );
VORTP_STATUS VoRTP_StartInbandTone( 
   kal_uint32 freq1, kal_uint32 freq2, 
   kal_int32 amp_dbm0, kal_uint32 duration_msec, 
   VORTP_TONE_CALLBACK callback, void *host_data  );
VORTP_STATUS VoRTP_StopInbandTone( void );
void VoRTP_Init( void );
void VoRTP_SetEventLogging( kal_bool enable );

kal_bool BT_PcmLoopbackTest(void);

/* Ket tone detection interface*/
void KtDetectStart(void (*callback)(kal_int16 key,kal_int32 keyLength));
void KtDetectStop( void );

// AFE interface 
void AFE_GetMappedGain(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level,
                   kal_uint8 *AnalogGain, kal_int8 *DigitalGain);

Media_Format_Check_Result media_get_codec_type( void *p_filename, Media_Check_Format media_format,
                         Media_Check_Video_Codec *p_video_codec, Media_Check_Audio_Codec *p_audio_codec);
Media_Format_Check_Result media_get_format_type( void *file_name, Media_Check_Format *p_media_format);
kal_bool media_codec_type_check ( void *p_filename, Media_Check_Video_Codec video_codec, Media_Check_Audio_Codec audio_codec);

// mp4 audio format to media format
Media_Format MP4_Audio_Type_To_Media_Format(MP4_Audio_Type );
/*====================start of  l1TTS interface ===================*/
typedef enum
{
	TTS_STR_TEXT,     /*regard input as normal text */
	TTS_STR_PHN_SBL,  /*regard input as phonetic symbol*/
	TTS_STR_CHAR      /*regard input as character set. When this type is set, the engine usually synthesize character by character*/
}TTS_STR_TYPE;

typedef kal_uint8    TTS_LANG;
typedef kal_uint8    TTS_TYPE;
typedef kal_uint8    TTS_GENDER;

//The following definition may be extended in the future.

//TTS_LANGUAGE definition
#define	TTS_LANG_ENG   0x1;	/*English*/
#define	TTS_LANG_TWN   0x2;	/*Taiwan-accent Chinese*/
#define	TTS_LANG_MDN   0x4;	/*Mandarin*/

//TTS_TYPE definition
#define	TTS_TYPE_GENERAL  0x1	/*General Purpose TTS*/
#define	TTS_TYPE_DIC      0x2	/*Dictionary*/
#define	TTS_TYPE_NAME     0x4	/*Name*/
#define	TTS_TYPE_GPS      0x8	/*GPS, traffic guiding*/
#define	TTS_TYPE_WEATHER  0x10	/*weather report*/
#define	TTS_TYPE_STOCK    0x20	/*stock report*/

//TTS_GENDER definition
#define	TTS_GENDER_MALE   0x1
#define	TTS_GENDER_FEMALE 0x2
#define	TTS_GENDER_BOY    0x4
#define	TTS_GENDER_GIRL   0x8

/* constants for values of field dwParamId */
#if defined(IFLY_TTS)
#define TTS_ATTR_INPUT_CODEPAGE    0x00000101	/* input code page, e.g. GBK */
#define TTS_ATTR_TEXT_SCOPE        0x00000103	/* text scope, e.g. number */
#define TTS_ATTR_INPUT_MODE        0x00000200	/* input mode, e.g. from fixed buffer, from callback */
#define TTS_ATTR_PROGRESS_CALLBACK 0x00000206	/* progress callback entry */
#define TTS_ATTR_READ_DIGIT        0x00000302	/* how to read digit, e.g. read as number, read as value  */
#define TTS_ATTR_CHINESE_NUMBER_1  0x00000303	/* how to read number "1" in Chinese */
#define TTS_ATTR_PHONEME_WATCH     0x00000402	/* how to watch phoneme, e.g. Chinese Pin-Yin */
#define TTS_ATTR_WATCH_CALLBACK    0x00000403	/* watch callback entry */
#define TTS_ATTR_SPEAK_STYLE       0x00000501	/* speak style */
#else
#define TTS_ATTR_INPUT_CODEPAGE    0x00000000	/* input code page, e.g. GBK */
#define TTS_ATTR_TEXT_SCOPE        0x00000103	/* text scope, e.g. number */
#define TTS_ATTR_INPUT_MODE        0x00000200	/* input mode, e.g. from fixed buffer, from callback */
#define TTS_ATTR_PROGRESS_CALLBACK 0x00000206	/* progress callback entry */
#define TTS_ATTR_READ_DIGIT        0x00000302	/* how to read digit, e.g. read as number, read as value  */
#define TTS_ATTR_CHINESE_NUMBER_1  0x00000303	/* how to read number "1" in Chinese */
#define TTS_ATTR_PHONEME_WATCH     0x00000402	/* how to watch phoneme, e.g. Chinese Pin-Yin */
#define TTS_ATTR_WATCH_CALLBACK    0x00000403	/* watch callback entry */
#define TTS_ATTR_SPEAK_STYLE       0x00000501	/* speak style */
#endif

/* constants for values of attribute TTSATTR_INPUT_CODEPAGE */
#define TTS_CODEPAGE_GBK             936   /* GBK (default) */
#define TTS_CODEPAGE_BIG5            950   /* Big5 */
#define TTS_CODEPAGE_UTF16LE         1200  /* UTF-16 little-endian */
#define TTS_CODEPAGE_UTF16BE         1201  /* UTF-16 big-endian */

/* constants for values of attribute TTSATTR_TEXT_SCOPE */
#define TTS_SCOPE_UNLIMITED          0     /* unlimited scope (default) */
#define TTS_SCOPE_CHINESE_NUMBER     1     /* Chinese number */
#define TTS_SCOPE_CHINESE_VALUE      2     /* Chinese value */
#define TTS_SCOPE_CHINESE_DATETIME   3     /* Chinese date or time */

/* constants for values of attribute TTSATTR_INPUT_MODE */
#define TTS_INPUT_FIXED_BUFFER       0     /* from fixed buffer */
#define TTS_INPUT_CALLBACK           1     /* from callback */

/* constants for values of attribute TTSATTR_READ_DIGIT */
#define TTS_READDIGIT_AUTO           0     /* decide automatically (default) */
#define TTS_READDIGIT_AS_NUMBER      1     /* say digit as number */
#define TTS_READDIGIT_AS_VALUE       2     /* say digit as value */

/* constants for values of attribute TTSATTR_CHINESE_NUMBER_1 */
#define TTS_CHNUM1_READ_YAO          0     /* read number "1" [yao1] in chinese (default) */
#define TTS_CHNUM1_READ_YI           1     /* read number "1" [yi1] in chinese */

/* constants for values of attribute TTSATTR_PHONEME_WATCH */
#define TTS_PHONEME_NONE             0     /* none (default) */
#define TTS_PHONEME_PINYIN           1     /* Chinese Pin-Yin */

/* constants for values of attribute TTSATTR_SPEAK_STYLE */
#define TTSSTYLE_PLAIN			0		/* plain speak style */
#define TTSSTYLE_NORMAL			1		/* normal speak style (default) */
#define TTSSTYLE_VIVID			2		/* vivid speak style */

typedef enum {
   TTS_END,
   TTS_ERROR,
   TTS_DATA_REQUEST,
   TTS_WATCH,                  /* TTS tell current synth information      */
   TTS_PROGRESS,               /* TTS tell the synth progress             */
   TTS_PROCESS
} TTS_Event;

typedef struct _tagTTSProcessData TTS_PROCESS_DATA;
struct _tagTTSProcessData
{
   const void *lpcSylText;   /* the pointer of text      */
   kal_uint32 dwTextLen;     /* length of text (in byte) */
   const void *lpcSylPhone;  /* pointer of pinyin        */
   kal_uint32 dwPhoneLen;    /* length of pinyin(in byte)*/
   kal_uint16 wSylType;      /* text type                */
};

typedef struct _tagTTSProgress TTSPROGRESS;
struct _tagTTSProgress
{
   kal_uint32    dwProcPos;  /* the offset(in byte) of currently synthesizing context of original input text*/
   kal_uint32    dwProcLen;  /* the length(in byte) of currently synthesizing context of original input text*/
};

typedef struct _tagTTSAttr TTS_ATTR;
struct _tagTTSAttr
{
   kal_uint32    dwAttrId;      /* attribute id */
   kal_uint32    varAttrValue;  /* attribute value */
};

typedef struct ttsHandle TTS_Handle;

struct ttsHandle {
	void (*handler)(TTS_Handle *hdl, TTS_Event event, void *data);
	kal_uint32 speed;
	kal_uint32 pitch;
	kal_uint32 volume;
	Media_Status (*SetBuffer)(TTS_Handle *hdl, kal_uint8* buffer, kal_uint32 buf_len);
	kal_uint32   (*GetBufSize)(TTS_Handle *hdl);
	Media_Status (*Play)(TTS_Handle *hdl, kal_wchar* string, TTS_STR_TYPE strType);
	Media_Status (*Pause)(TTS_Handle *hdl);
	Media_Status (*Resume)(TTS_Handle *hdl);
	Media_Status (*Stop)(TTS_Handle *hdl);
	Media_Status (*Close)(TTS_Handle *hdl);
	Media_Status (*SetPitch)(TTS_Handle *hdl, kal_uint32 pitch);
	Media_Status (*SetVolume)(TTS_Handle *hdl, kal_uint32 volume);
	Media_Status (*SetSpeed)(TTS_Handle *hdl, kal_uint32 speed);
	Media_Status (*SetAttr)(TTS_Handle *hdl, kal_uint32 dwAttrId, kal_uint32 varAttrValue);
	Media_Status (*Process)(TTS_Handle *hdl, TTS_Event event);
	kal_uint32  errMsg;
	TTS_STR_TYPE   strType;
	TTS_LANG    lang;
	TTS_TYPE    type;
	TTS_GENDER  gender;
/*other internal variable*/
#if defined(SINOVOICE_TTS)
   kal_uint16 *voiceBuf;
   kal_uint32 buf_r;
   kal_uint32 buf_end;
#endif
#if defined(IFLY_TTS) || defined(SINOVOICE_TTS)
   kal_bool  dataReq;
   kal_uint16 aud_id;
#if defined(IFLY_TTS)
   void *customHdl;
#else//SINOVOICE
   kal_uint16 flag;
   unsigned long customHdl;
#endif
   void *text;
#endif
	kal_uint16 state;
   MHdl *spcmHdl;
   Media_Event event;
   kal_wchar dataDir[100];
   kal_bool  bProcessDone;
};

TTS_Handle *TTS_Open(void(*callback)(TTS_Handle *hdl, TTS_Event event, void *data), TTS_LANG lang, TTS_TYPE type, TTS_GENDER gender);
/*====================end of l1TTS interface ===================*/

#define TLBR_STATE_IDLE  0
#define TLBR_STATE_INIT  1
#define TLBR_STATE_REC   2

#define BYTES_PER_FRAME  320
#define KT_AMP           0x3FFF
//#define HW_AGC_SETTING     0x460F

#define VOICE_INPUT_FILTER_FLAG     0x1 
#define VOICE_OUTPUT_FILTER_FLAG    0x2

typedef struct{
   kal_uint8 *pBuf;
   kal_uint32 uSize;
   kal_uint8  bAnalogSpkGain;
   kal_uint8  uAnalogMicGain;
   kal_uint16 uFreq;
   kal_uint16 uUL_DigGain;
   kal_uint16 uDL_DigGain;
   kal_uint16 uKT_AMP;
   kal_uint16 uMode; // 0: Normal Mode, 1: Loud Speaker Mode
}ToneLBR_Para;

void ToneLoopBackRec(void(*callback)( kal_uint8 *pBuf, kal_uint16 mode ), ToneLBR_Para *pstPara );

/*====================start of 3G interface ===================*/
#define RAT_2G_MODE  0
#define RAT_3G_MODE  1 
#define RAT_3G324M_MODE 2

typedef enum {
   SP3G_CODEC_READY,
   SP3G_CODEC_CLOSED,
   SP3G_UL_DATA_NOTIFY,
   SP3G_UL_DATA_DEALY_TICK
} SP3G_Event;

void SP3G_Request(void);
void SP3G_UL_SetFrameType(kal_uint8 amr_frame_type);
void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len);
void SP3G_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 sub_flow_id, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow);
void SP3G_Closed_Confirm( void );
void SP3G_Rab_Deest( void );
void SP3G_Rab_Est( kal_uint32 rab_id, kal_uint8 default_speech_codec ); //Cosine_NAS_Sync_Ind
void SP3G_SetDTX(kal_bool on);
//void SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag);
kal_uint8 SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag, kal_uint8 *dl_frame_number);
kal_uint8 SP3GVT_DL_DropSpeechFrame(kal_uint32 number, kal_uint8 *dl_frame_number);
void SP3GVT_UL_GetSpeechFrame(kal_uint8 *ul_data, kal_uint32 ul_space, kal_uint32 *size);
void SP3GVT_SetDelayValue(kal_uint32 delay);
/*====================end of 3G interface =====================*/

/*====================start of PCM2WAY interface =====================*/
typedef enum {
  P2W_FORMAT_NORMAL = 0,
  P2W_FORMAT_VOIP,
  P2W_FORMAT_CAL,          //calibration 
  P2W_FORMAT_WB_CAL,       //wb calibration
  P2W_FORMAT_WB_NORMAL     //normal usage for WB p2w
}P2W_Format;

typedef enum {
  P2W_APP_TYPE_UNDER_CALL = 0, //p2w acts as I/O to get/put pcm data under phone call
  P2W_APP_TYPE_WHITOUT_CALL,   //p2w acts as I/O to get/put pcm data when idle
  P2W_APP_TYPE_VOIP,           //VOIP, speech quality like phone call but not under calling
  P2W_APP_TYPE_REC_ONLY_CAL,   //dmnr calibration, record only
  P2W_APP_TYPE_REC_PLAY_CAL    //dmnr calibration, record and playback at the same time
  ,P2W_APP_TYPE_UNDEFINE = 0xFFFF
}P2W_App_Type;

void PCM2WAY_Start(void (*pcm2way_hdlr)(void), kal_uint32 type); //@type please refer to P2W_App_Type
void PCM2WAY_Stop(kal_uint32 type);

void PCM2Way_SetFormat(kal_uint32 format);

void PCM2WAY_GetFromMic(kal_uint16 *ul_buf);
void PCM2WAY_PutToSpk(const kal_uint16 *dl_data);
void PCM2WAY_FillSpk(kal_uint16 value);
void PCM2WAY_QueryBufSize(P2W_Format format, kal_uint32 *mic_bufsize, kal_uint32 *spk_bufsize);
/*====================end of PCM2WAY interface =====================*/
/*====================start of I2S input mode interface =====================*/
typedef enum {
   I2S_BYPASS_MODE = 0,
   I2S_RECORD_MODE = 1,
   I2S_BYPASS_AND_RECORD_MODE = 2
} I2S_Input_Mode;

Media_Status I2S_Open( void );
Media_Status I2S_Close( void );
kal_bool I2S_is_I2S_open( void );
kal_bool I2S_is_FM( void );
Media_Status FM_I2S_Open(void);
Media_Status FM_I2S_Close(void);
extern const kal_uint16 Media_I2S_INPUT_MODE_SR;
extern const char Media_I2S_SLAVE_MODE;

void I2SIN_TurnOnSpeaker(void);
void I2SIN_TurnOffSpeaker(void);
void I2SIN_MuteSpeaker( kal_bool mute );
void I2SIN_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void I2SIN_SetOutputDevice( kal_uint8 device );
void I2SIN_MuteDSP( kal_bool fMute );
kal_bool I2SIN_CheckDataValid(void);

/*====================end   of I2S input mode interface =====================*/

/*====================start of AFE =====================*/
typedef enum
{
	PHONE_MODE_HANDSET = 0,
	PHONE_MODE_HEADSET,
	PHONE_MODE_HANDFREE,
	PHONE_MODE_BT_EARPHONE,
	PHONE_MODE_MAX
} PHONE_MODE_T; 

typedef enum
{
   AFE_BUFFER_NONE = 0,    /* No use on AFE */
   AFE_BUFFER_AUDIO,       /* Audio buffer  */
   AFE_BUFFER_VOICE,       /* Voice buffer  */
   AFE_BUFFER_MIC,         /* MIC PGA       */
   AFE_BUFFER_MAX          
} AFE_BUFFER_T;

void AFE_GetPathUsage(kal_uint8 u1AudFunc, PHONE_MODE_T ePhoneMode, AFE_BUFFER_T *peBuffer);
void AFE_GetPGAGainInfo(AFE_BUFFER_T eBuffer, kal_int16 *pi2MaxGain, 
                        kal_uint16 *pu2Step, kal_uint16 *pu2TotalLevel);
kal_bool AFE_GetNVRAMDigitalGainSupport(void);

void AFE_FastCloseSpk(void);
void AFE_AudAccDetInit(void); 
void AFE_DC_Calibration(kal_uint16* pwdc_offset, void(*DC_Calibration_CallBack)(kal_uint16 *pwdc_offset)); 
void AFE_DC_Calibration_Register_Callback( void(*DC_Calibration_CallBack2)(kal_uint32 msg_name, void *data));
void AFE_Retrieve_DC_Cali_Data(kal_int32 data);

kal_bool AFE_SPKAMP_OCDetect(void);

kal_uint8 AFE_TurnOnMicBias( void );
void AFE_TurnOffMicBias( void ); 
void AFE_GetExtPGAGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map);
void AFE_GetPGAGainMap(AFE_BUFFER_T eBuffer, kal_uint16 u2TotalLevel, kal_int8 *pPGA_Map);
void L1SP_SetOutputGainControl(kal_uint32 vol);
void Media_SetOutputGainControl(kal_uint32 vol, kal_uint32 ext_amp_gain);
void TONE_SetOutputGainControl(kal_uint32 vol);
void KT_SetOutputGainControl(kal_uint32 vol);
void FMR_SetOutputGainControl(kal_uint32 vol);
void FMR_SetDualPathGainControl(kal_uint32 ext_amp_gain );
void L1SP_SetMicGainControl(kal_uint32 vol);
void l1audio_consoleDVT(kal_char *string);
/*====================end   of AFE =====================*/

extern void custom_cfg_audio_ec_range
(
 kal_uint8 *min_vol, /* min volume level */
 kal_uint8 *max_vol /* max volume level */
 );

extern kal_uint8 custom_cfg_hw_aud_output_path
(
   kal_uint8 speaker_id /*audio_type_enum*/
   
   /* return  l1sp audio output device enum */
);

extern kal_uint8 custom_cfg_hw_aud_input_path
(
   kal_uint8 mic_id /* audio_input_path_enum */
);

/*==================== start of VAD interface =====================*/
typedef enum {
   VAD_EVENT_ACTIVE,
   VAD_EVENT_INACTIVE
} VAD_Event;

typedef void (*VAD_Callback)(VAD_Event event, void *param);

// Operation functions
Media_Status VAD_Enable(VAD_Callback handler);
Media_Status VAD_Disable(void);
Media_Status VAD_SetSensitivity(kal_uint8 threshold);
void VAD_Init(void);

// Query functions
kal_bool VAD_IsEnable(void);
kal_uint8 VAD_GetSensitivity(void);

void VAD_SetInterval(kal_uint32 msTime);
/*==================== end of VAD interface =======================*/

/*==================== start of Remix interface =====================*/
Media_Status AudioPP_Remix_TurnOn( STFSAL *pstFSAL, kal_uint32 msRecordStartTime, kal_uint32 msAudioSeekTime );
Media_Status AudioPP_Remix_TurnOff( void );
void AudioPP_Remix_SetMode( Media_KaraRec_Mix_CH channelMode);
void AudioPP_Remix_SetAudioGain( kal_uint16 gain);
void AudioPP_Remix_SetVoiceGain( kal_uint16 gain);
/*==================== end of Remix interface =======================*/


Media_Status Media_PCM_Clock_Enable (kal_bool b_enable);
Media_Status Media_PCM_Interface_Enable (kal_uint8 type);

#endif


