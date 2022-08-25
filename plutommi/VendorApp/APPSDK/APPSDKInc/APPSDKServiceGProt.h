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
 *  APPSDKServiceGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKSERVICE_H_
#define _SDKSERVICE_H_

#include "MMI_features.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#ifdef __MMI_TODOLIST__
/****************************************************************************
 * TodolistSrvGprot.h
 ****************************************************************************/
#include "TodolistSrvGprot.h"
#include "TodolistGprot.h"

extern U16 srv_tdl_add(
                const void *data, 
                srv_tdl_vcal_enum vcal_type, 
                U16 *index);
extern U16 srv_tdl_delete(const U16 index, const srv_tdl_vcal_enum vcal_type);
extern U16 srv_tdl_update(
                const void *data, 
                const srv_tdl_vcal_enum vcal_type,  
                const U16 index);
extern U16 srv_tdl_get(
                void *buff, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type, 
                const U16 index);
extern U16 srv_tdl_get_all_index(
                 srv_tdl_event_task_struct *list, 
                 const U16 buff_size, 
                 const srv_tdl_vcal_enum vcal_type, 
                 U16 *count);
extern U16 srv_tdl_get_free(U16 *count, const srv_tdl_vcal_enum vcal_type);
extern U16 srv_tdl_get_max(U16 *count, const srv_tdl_vcal_enum vcal_type);
extern MMI_BOOL srv_tdl_is_full(const srv_tdl_vcal_enum vcal_type);
extern MMI_BOOL srv_tdl_is_empty(const srv_tdl_vcal_enum vcal_type);
extern U16 srv_tdl_search(
                srv_tdl_event_task_struct *list, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search, 
                U16 *count);
extern U16 srv_tdl_search_ext(
                srv_tdl_event_task_struct *list, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search, 
                U16 *count,
                const srv_tdl_external_search_check_funcptr funcptr);
extern U16 srv_tdl_sort(
                srv_tdl_event_task_struct* list, 
                const U16 buff_size,
                const srv_tdl_sort_type_enum sort_type);    
U16 srv_tdl_sort_ext(
                srv_tdl_event_task_struct *list, 
                const U16 count,
                const srv_tdl_sort_type_enum sort_type, 
                const srv_tdl_external_sort_compare_funcptr funcptr);
extern S16 srv_tdl_task_compare_priority(U16 index1, U16 index2);                
#if 0  // API revised by Todolist owner W10.45
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern MMI_BOOL srv_tdl_event_search_check_monthly(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date);
extern MMI_BOOL srv_tdl_event_search_check_daily(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date);
extern U16 srv_tdl_get_new_index(const srv_tdl_vcal_enum type);
#endif /* __MMI_TODOLIST__ */ 

/****************************************************************************
 * other module
 ****************************************************************************/

#endif /* _SDKSERVICE_H_ */ 

