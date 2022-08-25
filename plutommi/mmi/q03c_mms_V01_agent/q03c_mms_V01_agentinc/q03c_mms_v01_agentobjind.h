/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  q03c_mms_v01_agentobjind.h
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  This file contains declaration of APIs defined in q03c_mms_v01_agentobjind.c and definitions of 
 *  structures and unions used in q03c_mms_v01_agentobjind.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef Q03CMMSV01AGENTRECV_H
#define Q03CMMSV01AGENTRECV_H

#if defined (OBIGO_Q03C_MMS_V01)

#include "MMI_features.h"
#include "FileMgrGprot.h"
#include "FileMgrSrvGProt.h"
#include "q03c_mms_v01_adp_struct.h"


#define MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(x,y)      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\@mmsv01obj%d", \
      SRV_FMGR_SYSTEM_DRV, y);


/* Max push count for each sim*/
#define   MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM         10
/*Total push count*/
#ifdef __MMI_MMS_DUAL_SIM__
#define   MMSV01_AGENT_MMS_MAX_PUSH_NUM                 MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM * 2
#else 
#define   MMSV01_AGENT_MMS_MAX_PUSH_NUM                 MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM
#endif

/* Failed popup max count, popup will be shown after count reaches this value*/
#define   MMSV01_AGENT_SHOW_FULL_POPUP_COUNT   60

/*search file extension*/
#define   MMSV01_AGENT_MMS_SEARCH_FILE_EXT                  L"*.mms"

#define   MMSV01_AGENT_SEND_TIMER_VALUE                      (30000)


#define MMS_V01_AGENT_NOTIFICATION_TYPE 0x82
#define MMS_V01_AGENT_DELIVERY_REPORT_TYPE 0x86
#define MMS_V01_AGENT_READ_REPORT_TYPE 0x88



typedef enum
{
    MMS_V01_AGENT_NONE,
	MMS_V01_AGENT_FILE_TYPE_NOTIFICATION,
    MMS_V01_AGENT_DELIVERY_REPORT,
    MMS_V01_AGENT_READ_REPORT,
    MMS_V01_AGENT_NORMAL_MMS,
    MMS_V01_AGENT_TOTAL
} mmi_mmsv01_agent_file_type;

typedef enum
{
	MMSV01_AGENT_OBJ_STATE_NONE,
    MMSV01_AGENT_OBJ_STATE_NORMAL,
    MMSV01_AGENT_OBJ_STATE_BUSY,
    MMSV01_AGENT_OBJ_STATE_TOTAL
} mmi_mmsv01_agent_obj_state;

typedef enum
{
    MMSV01_AGENT_DRV_NONE,
	MMSV01_AGENT_DRV_SYS,
    MMSV01_AGENT_DRV_PUBLIC,
    MMSV01_AGENT_DRV_TOTAL
} mmi_mmsv01_agent_drv_type;

typedef union
{
	FS_DOSDateTime DateTime;
	kal_uint32 LastModified;
}mmi_mmsv01_agent_LastModifiedDate;


typedef struct _mmi_mmsv01_agent_notification_struct
{
    mmi_mmsv01_agent_obj_state state;
    kal_uint8 sim1_push_count;
#ifdef __MMI_MMS_DUAL_SIM__
    kal_uint8 sim2_push_count;
#endif 
    kal_uint8 in_process_push_index;
    kal_uint8 failed_count;
} mmi_mmsv01_agent_notification_context_struct;


typedef struct _mmi_mmsv01_agent_notification_list
{
    kal_uint8 sim_id;
    kal_uint8 filename_int;
	mmi_mmsv01_agent_LastModifiedDate date;   
} mmi_mmsv01_agent_notification_list;

extern void mmi_mmsv01_agent_init_object_ind_data(void);
extern void mmi_mmsv01_agent_object_indication_rsp(void *inMsg);
extern void mmi_mmsv01_agent_save_mms_to_drv(PU16 filename, kal_uint8 sim_id, kal_uint32 date);
extern kal_uint8 mmi_mmsv01_agent_generate_unique_file_name_int(kal_uint8 sim_id);
extern void mmi_mmsv01_agent_handle_obj_timer_expiry(void);
extern void mmi_mmsv01_agent_check_and_send_object_req(void);
extern void mmi_mmsv01_agent_obj_ind_delete_node_and_file(kal_uint8 index);
extern void mmi_mmsv01_agent_check_and_restart_object_indication_timer(void);

#endif  /* OBIGO_Q03C_MMS_V01 */

#endif /* Q03CMMSV01AGENTRECV_H */ 

