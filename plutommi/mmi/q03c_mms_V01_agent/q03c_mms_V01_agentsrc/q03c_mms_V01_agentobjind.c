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
 * q03c_mms_v01_agentobjind.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#if defined(OBIGO_Q03C_MMS_V01)

#include "mmi_frm_gprot.h"
#include "CommonScreens.h"
#include "DLAgentDef.h"
#include "SimDetectionGprot.h"
#include "app_asyncfile.h"
#include "q03c_mms_V01_agentResDef.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_V01_agentobjind.h"
#include "mea_api.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif


/* Global Context*/
static mmi_mmsv01_agent_notification_context_struct notification_context_struct;
static mmi_mmsv01_agent_notification_context_struct *g_mmi_mmsv01_notification_context = &notification_context_struct;
/*Object Indication List*/
static mmi_mmsv01_agent_notification_list g_notification_list[MMSV01_AGENT_MMS_MAX_PUSH_NUM];



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_start_object_indication_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_start_object_indication_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_START_TIMER);
	 StartTimer(MMSV01_AGENT_SEND_TIMER, MMSV01_AGENT_SEND_TIMER_VALUE, mmi_mmsv01_agent_handle_obj_timer_expiry);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_stop_object_indication_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_stop_object_indication_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_STOP_TIMER);
    StopTimer(MMSV01_AGENT_SEND_TIMER);
}



void mmi_mmsv01_agent_check_and_restart_object_indication_timer()
{
    if (g_mmi_mmsv01_notification_context->state != MMSV01_AGENT_OBJ_STATE_BUSY)
    {
        mmi_mmsv01_agent_stop_object_indication_timer();
        mmi_mmsv01_agent_start_object_indication_timer();

    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_handle_obj_timer_expiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_handle_obj_timer_expiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the State.If Busy Just Restart the timer */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_PRINT_STATE, g_mmi_mmsv01_notification_context->state);

    if ((g_mmi_mmsv01_notification_context->state != MMSV01_AGENT_OBJ_STATE_BUSY)
#if defined( __USB_IN_NORMAL_MODE__) && defined (MMS_IN_LARGE_STORAGE)
              &&  !mmi_usb_is_in_mass_storage_mode()
#endif
       )
      {
        
        mmi_mmsv01_agent_check_and_send_object_req();
        
      }
      else
      {
        /* Start the timer Again */
          mmi_mmsv01_agent_start_object_indication_timer(); 
      }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_reset_push_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_reset_push_slot(kal_uint8 index)
{
    g_notification_list[index].filename_int = 0;
    g_notification_list[index].sim_id = 0;
    g_notification_list[index].date.LastModified = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_send_object_indication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_send_object_indication(kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SEND_OBJ_IND);

    if (g_notification_list[index].filename_int != 0)
    {
        kal_uint8 complete_file_path[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};
		kal_uint8 temp_buf[20] = {0,};
		
		

		g_mmi_mmsv01_notification_context->in_process_push_index = index;
        
        MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(complete_file_path, g_notification_list[index].sim_id);

		mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
		kal_wsprintf((kal_uint16 *)temp_buf, "%u.mms", (S8*) g_notification_list[index].filename_int);
		mmi_ucs2cat((S8*) complete_file_path, (S8*)temp_buf);       

        g_mmi_mmsv01_notification_context->state = MMSV01_AGENT_OBJ_STATE_BUSY;

		mmi_mmsv01_agent_send_obj_ind((kal_wchar*)  complete_file_path, g_notification_list[index].sim_id);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_INVALID_INDEX);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_oldest_push_for_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id        [IN]
 * RETURNS
 *  index
 *****************************************************************************/

kal_uint8 mmi_mmsv01_agent_get_oldest_push_for_sim(kal_uint8 sim_id)
{
    kal_uint8 index = 0;
    kal_uint32 min_date = 0XFFFFFFFF;
    kal_uint32 min_date_index = 0;

    for(index = 0; index < MMSV01_AGENT_MMS_MAX_PUSH_NUM; index++)
    {
        if (g_notification_list[index].filename_int != 0 &&
            g_notification_list[index].sim_id == sim_id)
        {
            if (g_notification_list[index].date.LastModified < min_date)
            {
                min_date = g_notification_list[index].date.LastModified;
                min_date_index = index;
            }
        }
    }

    return min_date_index;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_oldest_push_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  index
 *****************************************************************************/

kal_uint8 mmi_mmsv01_agent_get_oldest_push_index()
{
    kal_uint8 index = 0;
    kal_uint32 min_date = 0XFFFFFFFF;
    kal_uint32 min_date_index = 0;

    for(index = 0; index < MMSV01_AGENT_MMS_MAX_PUSH_NUM; index++)
    {
        if (g_notification_list[index].filename_int != 0)
        {
            if (g_notification_list[index].date.LastModified < min_date)
            {
                min_date = g_notification_list[index].date.LastModified;
                min_date_index = index;
            }
        }
    }

    return min_date_index;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_add_in_object_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_add_in_object_list(kal_uint8 sim_id, kal_uint8 filename_int , kal_uint32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	if ((sim_id ==   MMI_SIM_ID_SIM1 &&
		g_mmi_mmsv01_notification_context->sim1_push_count < MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM) 
#ifdef __MMI_MMS_DUAL_SIM__				
		||(sim_id ==   MMI_SIM_ID_SIM2 &&
		g_mmi_mmsv01_notification_context->sim2_push_count < MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM)
#endif 
	    )
    {
        /*Find the empty slot*/
        kal_uint8 index = 0;

        for(index = 0; index < MMSV01_AGENT_MMS_MAX_PUSH_NUM; index++)
        {
            if(g_notification_list[index].filename_int == 0)
            {
                /*This slot is unused so can be used*/
                g_notification_list[index].filename_int = filename_int;
                g_notification_list[index].sim_id = sim_id;
                g_notification_list[index].date.LastModified = date;
                break;
            }

        }
        
        if (index == MMSV01_AGENT_MMS_MAX_PUSH_NUM)
        {
            /*Just to catch erreoneous condition*/
            ASSERT(0);
        }
    }
    else
    {
        /* Max push is reached for this sim
        so replace the oldest push with the new one*/
        kal_uint8 index = mmi_mmsv01_agent_get_oldest_push_for_sim(sim_id);
        /*Delete the file corresponding to that index*/
        mmi_mmsv01_agent_obj_ind_delete_node_and_file(index);
        g_notification_list[index].filename_int = filename_int;
        g_notification_list[index].sim_id = sim_id;
        g_notification_list[index].date.LastModified = date;        
    }

	if (MMI_SIM_ID_SIM1 == sim_id)
	{
		g_mmi_mmsv01_notification_context->sim1_push_count++;
	}
#ifdef __MMI_MMS_DUAL_SIM__
	else if (MMI_SIM_ID_SIM2 == sim_id)
	{
		g_mmi_mmsv01_notification_context->sim2_push_count++;
	}
#endif /* __MMI_MMS_DUAL_SIM__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_init_push_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_init_push_info(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_INIT_PUSH_LIST, sim_id);
    if (MMI_SIM_ID_SIM1 == sim_id)
    {
        g_mmi_mmsv01_notification_context->sim1_push_count = 0;
    }
#ifdef __MMI_MMS_DUAL_SIM__
    else if (MMI_SIM_ID_SIM2 == sim_id)
    {
        g_mmi_mmsv01_notification_context->sim2_push_count = 0;
    }
#endif /* __MMI_MMS_DUAL_SIM__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_int_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8  mmi_mmsv01_agent_get_int_file_name(U8 filename[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 filename_temp[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(filename_temp, 0, 20);
    mmi_ucs2_to_asc((S8*) filename_temp, (S8*) filename);
    while (filename_temp[count] && filename_temp[count] != '.')
    {
        ++count;
    }
    if (filename_temp[count] == '.')
    {
        filename_temp[count] = 0;
        return (U8) atoi((S8*) filename_temp);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_mmsv01_agent_file_type mmi_mmsv01_agent_get_file_type(kal_uint8* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 second_byte[1] = {0, };
    U32 size = 0;
    FS_HANDLE file_hnd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    file_hnd = FS_Open((const WCHAR*)filepath, FS_READ_ONLY);
    FS_Seek(file_hnd, 1, FS_FILE_BEGIN);
    FS_Read(file_hnd, &second_byte, 1, &size);
    
    FS_Close(file_hnd);
    if (second_byte[0] == 0x82)
    {
        return MMS_V01_AGENT_FILE_TYPE_NOTIFICATION;
    }
    if (second_byte[0] == 0x86)
    {
        return MMS_V01_AGENT_DELIVERY_REPORT;
    }
    if (second_byte[0] == 0x88)
    {
        return MMS_V01_AGENT_READ_REPORT;
    }
    return MMS_V01_AGENT_TOTAL;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_get_file_name_and_add_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         [?]
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_get_file_name_and_add_to_list(U8 filename[], U8 sim_id, kal_uint32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // umms_file_type mms_type = 0;
    U8 file_name_int = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    file_name_int = mmi_mmsv01_agent_get_int_file_name(filename);
    /*To find erreneous conetionn*/
    ASSERT(file_name_int);    /*0 as filename int is impossible*/
    mmi_mmsv01_agent_add_in_object_list(sim_id, file_name_int, date);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_read_noti_file_frm_sys_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_read_noti_file_frm_sys_drv(kal_wchar* filepath, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    U8 path[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};
    U8 filename[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_READ_FROM_SYS_DRIVE, sim_id);
    mmi_ucs2cpy((S8*) path, (S8*) filepath);
    mmi_ucs2cat((S8*) path, (S8*) L"\\");
    mmi_ucs2cat((S8*) path, (S8*) MMSV01_AGENT_MMS_SEARCH_FILE_EXT);

    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    ((SRV_FMGR_PATH_MAX_LEN+1) + 1) * ENCODING_LENGTH)) >= 0)
    {
        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
				U8 complete_file_path[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};
				kal_uint8 mms_type = 0;

				mmi_ucs2cpy((S8*) complete_file_path, (S8*) filepath);
				mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
				mmi_ucs2cat((S8*) complete_file_path, (S8*) filename);   
			
				mms_type = mmi_mmsv01_agent_get_file_type(complete_file_path);
				if (mms_type != MMS_V01_AGENT_TOTAL)
				{
					mmi_mmsv01_agent_LastModifiedDate lastModifieddt = {0,};
					lastModifieddt.DateTime = file_info.CreateDateTime;
					mmi_mmsv01_agent_get_file_name_and_add_to_list(filename, sim_id, lastModifieddt.LastModified);
				}
				else
				{
					FS_Delete((const WCHAR*)complete_file_path);
					/*Delete the file*/
				}
            }
        } while ((FS_FindNext
                  (fh_cur, &file_info, (U16*) filename,
                   ((SRV_FMGR_PATH_MAX_LEN+1)  + 1) * ENCODING_LENGTH) == FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_init_object_ind_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_mmsv01_agent_init_object_ind_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE file_handle = 0;
	kal_wchar *ucs2_filepath = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read the Files from the System Folder and Create the Link List */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJECT_IND_INIT);
    mmi_mmsv01_agent_init_push_info((U8) MMI_SIM_ID_SIM1);
#ifdef __MMI_MMS_DUAL_SIM__
    mmi_mmsv01_agent_init_push_info((U8) MMI_SIM_ID_SIM2);
#endif 
	
   	ucs2_filepath = OslMalloc(MMSV01_MAX_OBJ_IND_FILE_PATH_LEN);

    MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(ucs2_filepath, MMI_SIM_ID_SIM1);

	file_handle = FS_Open(ucs2_filepath, FS_READ_ONLY);

    if (file_handle > 0)
    {
		mmi_mmsv01_agent_read_noti_file_frm_sys_drv(ucs2_filepath, (U8) MMI_SIM_ID_SIM1);
		FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJ_IND_SYS_FOLDER_NOT_EXISTS);
        FS_CreateDir((PU16) ucs2_filepath);
    }



#ifdef __MMI_MMS_DUAL_SIM__
    MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(ucs2_filepath, MMI_SIM_ID_SIM2);
    file_handle = FS_Open(ucs2_filepath, FS_READ_ONLY);
    if (file_handle > 0)
    {
        mmi_mmsv01_agent_read_noti_file_frm_sys_drv(ucs2_filepath, (U8) MMI_SIM_ID_SIM2);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJ_IND_SYS_FOLDER_NOT_EXISTS);
        FS_CreateDir(ucs2_filepath);
    }
#endif /* __MMI_MMS_DUAL_SIM__ */

    if (ucs2_filepath)
	{
		OslMfree(ucs2_filepath);
	}

    mmi_mmsv01_agent_start_object_indication_timer();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_handle_mms_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action_type                 [IN]        
 *  filename                    [IN]        
 *  download_url                [IN]        
 *  mime_type_str_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_handle_mms_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 second_byte[1] = {0, };
    kal_uint8 sim_id = 0;
    FS_FileInfo fileinfo = {0,};
    FS_HANDLE file_hnd = -1;
    U32 size = 0;
	mmi_mmsv01_agent_LastModifiedDate lastModifieddt = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_HANDLE_MMS_FILE, filename, action_type);

	if ((S32) MMI_DA_PUSH_SIM1 == action_type)
    {
        sim_id = MMI_SIM_ID_SIM1;
    }
#ifdef __MMI_MMS_DUAL_SIM__
    else if ((S32) MMI_DA_PUSH_SIM2 == action_type)
    {
        sim_id = MMI_SIM_ID_SIM2;
    }
#endif /* __MMI_MMS_DUAL_SIM__ */ 
    else
    {
        sim_id = MMI_SIM_ID_SIM1;
    }

    file_hnd = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    FS_GetFileInfo(file_hnd,&fileinfo);
    FS_Seek(file_hnd, 1, FS_FILE_BEGIN);
    FS_Read(file_hnd, &second_byte, 1, &size);
	lastModifieddt.DateTime = fileinfo.DirEntry->CreateDateTime;
    FS_Close(file_hnd);

    if (second_byte[0] == MMS_V01_AGENT_NOTIFICATION_TYPE ||
		second_byte[0] == MMS_V01_AGENT_DELIVERY_REPORT_TYPE ||
		second_byte[0] == MMS_V01_AGENT_READ_REPORT_TYPE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_FILE_TYPE, second_byte[0]);
        mmi_mmsv01_agent_save_mms_to_drv(filename, sim_id,lastModifieddt.LastModified);
    }
    else
    {
        /* Just Ignore this right now
        May add the handling for this later */
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJECT_FILE_IS_NORMAL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_check_and_send_object_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_check_and_send_object_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_uint8 in_process_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mea_mmsV01_agent_is_wap_ready())
    {

        if (((g_mmi_mmsv01_notification_context->sim1_push_count > 0) 
#ifdef __MMI_MMS_DUAL_SIM__
             && (g_mmi_mms_V01_agent_ctx.is_sim1_valid == TRUE))
		 ||	((g_mmi_mmsv01_notification_context->sim2_push_count > 0)
              && (g_mmi_mms_V01_agent_ctx.is_sim2_valid == TRUE)
#endif
          ))
        {
            in_process_index = mmi_mmsv01_agent_get_oldest_push_index();
            
            if (!mea_mmsV01_agent_get_no_of_free_msg())
			{
				if (g_mmi_mmsv01_notification_context->failed_count % MMSV01_AGENT_SHOW_FULL_POPUP_COUNT == 0)
				{
				    if (mmi_mmsv01_agent_check_popup())
                    {
						mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_MAX_NUMBER_OF_MSG), MMI_EVENT_FAILURE);						
					}
                    g_mmi_mmsv01_notification_context->failed_count = 1;
				}
				else
				{
					g_mmi_mmsv01_notification_context->failed_count++;
				}

				mmi_mmsv01_agent_stop_object_indication_timer();
				mmi_mmsv01_agent_start_object_indication_timer();

				return;

			}
			else
			{        
				kal_uint8 complete_file_path[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};
				kal_uint8 temp_buf[20] = {0,};
				kal_int32 size = 0;

                MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(complete_file_path, 
                                                    g_notification_list[in_process_index].sim_id);


				mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
				kal_wsprintf((kal_uint16 *)temp_buf, "%u.mms", (S8*) g_notification_list[in_process_index].filename_int);
				mmi_ucs2cat((S8*) complete_file_path, (S8*)temp_buf);
				
				size = applib_get_file_size((kal_wchar*)complete_file_path);

				if (mea_mmsv01_agent_get_mms_free_space() < size )
				{
					if (g_mmi_mmsv01_notification_context->failed_count % MMSV01_AGENT_SHOW_FULL_POPUP_COUNT == 0)
					{
						/* Time to show the pop-up */
						if (mmi_mmsv01_agent_check_popup())
						{
							mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_STORAGE_FULL), MMI_EVENT_FAILURE);							
						}
                        g_mmi_mmsv01_notification_context->failed_count = 1;
					}
					else
					{
                        g_mmi_mmsv01_notification_context->failed_count++;
					}
					mmi_mmsv01_agent_stop_object_indication_timer();
					mmi_mmsv01_agent_start_object_indication_timer();
					return;
				}
			}
            /*Reset failed count to zero*/
            g_mmi_mmsv01_notification_context->failed_count = 0;
			mmi_mmsv01_agent_send_object_indication(in_process_index);
        }
    }
    else
    {
        /* Can avoid this as this function will automatically called when new push is recieved*/
        mmi_mmsv01_agent_stop_object_indication_timer();
        mmi_mmsv01_agent_start_object_indication_timer();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_save_mms_to_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  drv_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_save_mms_to_drv(PU16 filename, kal_uint8 sim_id, kal_uint32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Concatinate the File Path and the name and then Send Copy Request */
    kal_wchar* full_file_path = NULL;
	kal_uint8 filename_int = 0;
    int fh = 0;
	U8 temp_buff[20];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SAVE_MMS_TO_DRV, sim_id);

	full_file_path = OslMalloc(MMSV01_MAX_OBJ_IND_FILE_PATH_LEN);

    MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(full_file_path, sim_id);
		
	mmi_ucs2cat((S8*) full_file_path, (S8*) L"\\");

    filename_int = mmi_mmsv01_agent_generate_unique_file_name_int(sim_id);

	kal_wsprintf((kal_uint16*) temp_buff, "%u.mms" , filename_int);

    mmi_ucs2cat((S8*) full_file_path, (S8*) temp_buff);
 
    fh = FS_Move(filename, (U16*) full_file_path, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    if (fh == FS_NO_ERROR)
    {
          
        mmi_mmsv01_agent_add_in_object_list(sim_id, filename_int, date);
        if ((g_mmi_mmsv01_notification_context->state != MMSV01_AGENT_OBJ_STATE_BUSY))
        {
#if defined( __USB_IN_NORMAL_MODE__) && defined (MMS_IN_LARGE_STORAGE)
              if (mmi_usb_is_in_mass_storage_mode())
              {
                    mmi_mmsv01_agent_stop_object_indication_timer();
                    mmi_mmsv01_agent_start_object_indication_timer();
              }
              else
#endif
              {
                    mmi_mmsv01_agent_check_and_send_object_req();
              }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJ_STATE_BUSY);
           /* Do Nothing */
        }
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_COPY_REQ_IS_UN_SUCESS, fh);
        /* Log the error with the File Name */
    }

	if (full_file_path)
	{
		OslMfree(full_file_path);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_generate_unique_file_name_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_mmsv01_agent_generate_unique_file_name_int(kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[20];
    U8 filename_int = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp, 0, 20);
   
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UNIQUE_FILE_NAME_ENTRY);

	if ((sim_id ==   MMI_SIM_ID_SIM1 &&
		g_mmi_mmsv01_notification_context->sim1_push_count >= MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM) 
#ifdef __MMI_MMS_DUAL_SIM__				
		||(sim_id ==   MMI_SIM_ID_SIM2 &&
		g_mmi_mmsv01_notification_context->sim2_push_count >= MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM)
#endif 
		)
    {
        /*Find oldest push for this SIM and remove that push and replace it with new push*/
		kal_uint8 index = mmi_mmsv01_agent_get_oldest_push_for_sim(sim_id);

        filename_int = g_notification_list[index].filename_int;

		mmi_mmsv01_agent_obj_ind_delete_node_and_file(index);
    }
    else
    {
		/*Find a unused filename int */				
		
		kal_uint8 index_1 = 1;
        kal_uint8 index_2 = 0;
        kal_bool used = FALSE;

        for (index_1 = 1; index_1 < MMSV01_AGENT_MMS_MAX_ONE_SIM_PUSH_NUM; index_1++)
        {

            used = FALSE;
			for (index_2 = 0; index_2 <= MMSV01_AGENT_MMS_MAX_PUSH_NUM; index_2++)
	        {

			    if ((g_notification_list[index_2].sim_id == sim_id) &&
				    g_notification_list[index_2].filename_int == index_1)
			    {
				    used = TRUE;
			    }
            }

            if (!used)
            {
                break;
            }
        }

		filename_int = index_1;
	}
        
  
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UNIQUE_FILE_NAME_GENERATE, filename_int);

	return filename_int;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_obj_ind_delete_node_and_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename_int        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_mmsv01_agent_obj_ind_delete_node_and_file(kal_uint8 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 complete_file_path[MMSV01_MAX_OBJ_IND_FILE_PATH_LEN] = {0,};
	kal_uint8 temp_buf[20] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMSV01_AGENT_MAKE_SIM_SPECIFIC_SYSTEM_FOLDER_PATH(complete_file_path, g_notification_list[index].sim_id);

	mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
	kal_wsprintf((kal_uint16 *)temp_buf, "%u.mms", (S8*) g_notification_list[index].filename_int);
	mmi_ucs2cat((S8*) complete_file_path, (S8*)temp_buf);

    FS_Delete((const WCHAR*)complete_file_path);


	if (MMI_SIM_ID_SIM1 == g_notification_list[index].sim_id)
    {
        g_mmi_mmsv01_notification_context->sim1_push_count--;
    }
#ifdef __MMI_MMS_DUAL_SIM__
    else if (MMI_SIM_ID_SIM2 == g_notification_list[index].sim_id)
    {
        g_mmi_mmsv01_notification_context->sim2_push_count--;
    }
#endif /* __MMI_MMS_DUAL_SIM__ */ 

	mmi_mmsv01_agent_reset_push_slot(index);


}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_object_indication_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename_int        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_mmsv01_agent_object_indication_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mmsv01_agent_mms_obj_res_struct *rsp_data = (mmi_mmsv01_agent_mms_obj_res_struct*) inMsg;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*Change the state to normal*/



    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_OBJ_IND_RSP, rsp_data->result);


   
    if (rsp_data->result != MEA_RESULT_OK)
    {
		g_mmi_mmsv01_notification_context->state = MMSV01_AGENT_OBJ_STATE_NORMAL;
		g_mmi_mmsv01_notification_context->in_process_push_index = 0xff;

        mmi_mmsv01_agent_stop_object_indication_timer();
        mmi_mmsv01_agent_start_object_indication_timer();

    }
    else
    {
        mmi_mmsv01_agent_obj_ind_delete_node_and_file(g_mmi_mmsv01_notification_context->in_process_push_index);
		/* Reset the in process filename int and in process sim id */
		g_mmi_mmsv01_notification_context->state = MMSV01_AGENT_OBJ_STATE_NORMAL;
		g_mmi_mmsv01_notification_context->in_process_push_index = 0xff;

#if defined ( __USB_IN_NORMAL_MODE__) && defined (MMS_IN_LARGE_STORAGE)
        if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_mmsv01_agent_stop_object_indication_timer();
            mmi_mmsv01_agent_start_object_indication_timer();
        }
        else
#endif
        {
            mmi_mmsv01_agent_check_and_send_object_req();
        }
	}
}

#endif  /* OBIGO_Q03C_MMS_V01  */
