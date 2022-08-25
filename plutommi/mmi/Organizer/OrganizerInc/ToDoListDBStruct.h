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
 *	ToDoListDBStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing phonebook interface for java package
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_PIMEVTDBSTRUCT_H
#define _MMI_PIMEVTDBSTRUCT_H

#include "MMI_features.h"

#ifdef __MMI_TODOLIST__


#ifdef __J2ME__
#include "j2me_custom_option.h"
#if defined(SUPPORT_JSR_75_PIM)

#include "app_datetime.h"

#define MMI_TDL_JAVA_FIELD_SUBJECT             (0x0001)
#define MMI_TDL_JAVA_FIELD_START_TIME          (0x0002)
#define MMI_TDL_JAVA_FIELD_END_TIME            (0x0004)
#define MMI_TDL_JAVA_FIELD_CATEGORY            (0x0008)
#define MMI_TDL_JAVA_FIELD_ALARM               (0x0010)
#define MMI_TDL_JAVA_FIELD_ALARM_TIME          (0x0020)
#define MMI_TDL_JAVA_FIELD_REPEAT              (0x0040)
#define MMI_TDL_JAVA_FIELD_LOCATION            (0x0080)
#define MMI_TDL_JAVA_FIELD_DETAILS             (0x0100)
#define MMI_TDL_JAVA_FIELD_STATUS              (0x0200)
#define MMI_TDL_JAVA_FIELD_DONE_TIME           (0x0400)
#define MMI_TDL_JAVA_FIELD_PRIORITY            (0x0800)

typedef struct
{
	kal_uint16					index;  /* display index. */
	kal_uint16					handle; /* store index */
	applib_time_struct			startTime;	
	applib_time_struct			endTime;	
	kal_uint8					note[MAX_TODO_LIST_NOTE]; /* The subject field in todo */
	kal_uint16                  field_mask;
#ifdef JSR_75_PIM_EXTRA_DETAIL
	kal_uint8                   details[MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH];
#endif
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
	applib_time_struct          alarm_time;
#endif
	kal_uint8					alarm;			/* The alarm type field in todo */
	kal_uint8			        repeat;	
	kal_uint8					days;		
#ifdef JSR_75_PIM_EXTRA_TODO
	kal_uint8                   status;                                 /* completed, done or undone */
    kal_uint8                   Type;                               /* Type of task */
    kal_uint8                   Priority;                               /* Priority of task */
    applib_time_struct          complete_time;                          /* completed time */    
    kal_uint8                   Location[MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH];           /* Location of an Task */
#endif
} mmi_evtdb_java_entry_struct;

/*
   Add:
      sort_type : sort by which type, the result will return in response msg
      index:      0xFFFF
      return ---  index : sort by sort_type, handle: phsical index

   update:
      sort_type : sort type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      return ---  index/handle : no use

   delete:
      sort_type  : sort type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      return ---  index/handle : no use
*/

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8  sort_type;  // add by eric, reference to mmi_evtdb_sort_enum
   kal_uint16 index;      // change by eric
   kal_uint8   db_index;
   mmi_evtdb_java_entry_struct* entry_ptr;
} mmi_evtdb_java_set_entry_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 result;
   kal_uint16 index;
   kal_uint8   db_index;
   kal_uint8   detail;
   kal_uint16 handle;
} mmi_evtdb_java_set_entry_rsp_struct;


/*
    Get:
      sort_type : sort by which type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      count:      1

    Get Total:
      count:      0

*/


typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8  sort_type;
   kal_uint16 index;
   kal_uint16 count;
   kal_uint8   db_index;
   mmi_evtdb_java_entry_struct* entry_ptr;
} mmi_evtdb_java_get_entry_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 result;
   kal_uint16 count;
   kal_uint8   db_index;
   kal_uint8   detail;
} mmi_evtdb_java_get_entry_rsp_struct;
#endif /*SUPPORT_JSR_75_PIM*/
#endif /*ifdef __J2ME__*/
#endif /* __MMI_TODOLIST__ */
#endif //_MMI_PIMEVTDBSTRUCT_H
