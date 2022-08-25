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
*  AudioPlayerWalk.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player walk source file
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/




#include "MMI_features.h"

#ifdef __MMI_AUDPLY_WALK_PLAY__
#include "AudioPlayerType.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "AudioPlayerWalk.h"
#include "nvram_common_defs.h"
#include "plcacheSrv_agent_audply.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#ifdef __MMI_BTBOX_NOLCD__
#include "mmi_frm_input_event.h"
#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
#endif
#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_AVRCP_SUPPORT__ */
#endif
/*DRM related*/
#include "DRM_gprot.h"

#ifndef __MMI_BTBOX_NOLCD__
extern audply_struct g_audply;  /* defined in AudioPlayerSrc.c */
#else
btbox_audply_struct g_btbox_audply;
void mmi_audply_btbox_stop_action();
void mmi_audply_btbox_stop_playing(void);
#endif

#ifdef __MMI_BTBOX_NOLCD__
audioplay_btbox_struct audply_btbox_data;
#endif

//////////////////////////////////////////////////Cache handler code

/*Cache array*/
audply_walk_cache_int_struct cache_int_struct;

/*Temp cache array*/
audply_walk_cache_int_temp_struct cache_temp_struct;

/*Just for first time add cache*/
U8 Press_Prev;
MMI_BOOL is_in_confirm_popup;
//MMI_BOOL is_in_no_audio_popup;

/*For service new cache and load cache work*/
audply_walk_cache_service_work_struct new_cache_work;
audply_walk_temp_cache_service_work_struct temp_cache_work;

mmi_audply_walk_stack_node_struct temp_stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];

/*Just for slove stack overflow*/
UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

/*For service work use, need to save some temp data*/
audply_new_cache_temp_out_context_struct new_cache_work_temp;

static FS_Pattern_Struct audio_pattern_array[] = 
{
#ifdef DAF_DECODE
    {L"*.mp3"},
#ifdef MUSICAM_DECODE
    {L"*.mp2"},
#endif    
#endif
#ifdef AMR_CODEC
    {L"*.amr"},
#endif
#ifdef AAC_DECODE
    {L"*.aac"},
#endif 

#ifdef AMRWB_DECODE
    {L"*.awb"},
#endif 

#ifdef BSAC_DECODE
/* under construction !*/
#endif

#ifdef __DRM_V02__
    {L"*.odf"},
#endif

#ifdef WAV_CODEC
    {L"*.wav"},
#endif
#ifndef __MMI_BTBOX_NOLCD__
    {L"*.mid"},
    {L"*.midi"},
    {L"*.imy"},
#endif

#ifdef AIFF_DECODE
    {L"*.aif"},
    {L"*.aiff"},
    {L"*.aifc"},
#endif

#ifdef AU_DECODE
    {L"*.au"},
#endif

#ifdef SND_DECODE
    {L"*.snd"},
#endif

#ifdef M4A_DECODE
    {L"*.m4a"},
#endif 

#ifdef YAMAHA_MA3
    {L"*.mmf"},
#endif 

#ifdef WMA_DECODE
    {L"*.wma"},
#endif 

#if defined(__MMI_PURE_AUDIO__)
    {L"*.3gp"},
    {L"*.3g2"},
    {L"*.mp4"},
#endif

#ifdef __RM_DEC_SUPPORT__
    {L"*.ra"},
#endif
    
#ifdef __APE_DECODE__
    {L"*.ape"},
#endif    

#ifdef __FLAC_DECODE__
    {L"*.flac"},
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {L"*.ogg"},
#endif
};



static void mmi_audply_walk_add_cache(UI_character_type *filefullname);



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_is_audio_file
 * DESCRIPTION
 *   Check the file is audio file or not
 * PARAMETERS
 *  filename  : [In]  Filename
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_is_audio_file(CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    CHAR* dot;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || mmi_ucs2strlen(filename) < 3)
        return MMI_FALSE;


    dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot)
    {
        U8 i;
        U8 audio_pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
        MMI_BOOL found = MMI_FALSE;
        
        dot += 2;
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        for (i = 0; i < audio_pattern_array_size; i++)
        {
            if (mmi_ucs2cmp((CHAR*)(audio_pattern_array[i].Pattern+2), (CHAR*)app_ucs2_strtolower((kal_wchar*)file_ext)) == 0)
            {
                found = MMI_TRUE;
                break;
            }
        }
        if (found)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_walk_check_valid_file
 * DESCRIPTION
 *   Check the file is valid or not
 * PARAMETERS
 *  File_path  : [In]  File path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_walk_check_valid_file(CHAR *File_path)
{
    FS_HANDLE file_handler;
    
    file_handler = FS_Open((WCHAR*)File_path, FS_READ_ONLY);

    if(file_handler >= FS_NO_ERROR)   //Valid File
    {
        FS_Close(file_handler);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_search_prev_folder_index
 * DESCRIPTION
 *   Seaarch folder last no empty stack index
 * PARAMETERS
 *  stack  : [In]  folder stack index
 *  index  : [In]  Depth level
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_service_search_prev_folder_index(mmi_audply_walk_stack_node_struct *stack, S16 index)
{
    S16 i = index;
    mmi_audply_walk_stack_node_struct *active_stack = stack;
    S16 result;
    
    if(active_stack[i].fs_index == 0 && i != 0)
    {
        result = mmi_service_search_prev_folder_index(stack, i - 1);
    }
    else if(i == 0 && active_stack[i].fs_index == 0)
    {
        result = -1;
    }
    else
    {
        result = i;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_search_last_folder
 * DESCRIPTION
 *   Seaarch last folder
 * PARAMETERS
 *  path_buf  : [In]  current folder path
 *  index  : [In]  Depth level
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_service_search_last_folder(CHAR *path_buf, U16 *index)
{
    MMI_BOOL result = MMI_FALSE;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    U16 counter = 0, temp_index = 0;
    S32 return_value;
    CHAR *last_backlash;

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)path_buf);
    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
    
    file_handle = FS_FindFirstN((PU16)temp_path,
                                NULL,
                                0,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,
                                FS_FIND_DEFAULT);

    if(file_handle >= 0)
    {
        do
        {
            counter++;
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                MMI_ASSERT(last_backlash != NULL);
                *(last_backlash + 1) = 0;
                *last_backlash = 0;

                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                
                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
                //mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"\\");
                temp_index = counter;
            }

            return_value = FS_FindNextN(
                            file_handle,
                            NULL,
                            0,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            
            
        }while(return_value == FS_NO_ERROR);

        FS_FindClose(file_handle);

        if(temp_index != 0)   //Find folder
        {
            *index = temp_index;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)temp_path);
            result = MMI_TRUE;
        }
        else
        {
            *index = temp_index;
            result = MMI_FALSE;
        }
        
    }
    else   //Empty folder
    {
        result = MMI_FALSE;
    }

    return result;
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_search_index_folder_name
 * DESCRIPTION
 *   Get folder name by folder index
 * PARAMETERS
 *  stack  : [In]  current folder path stack index
 *  depth_level  : [In]  Depth level
 *  buf : [Out] Folder path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_service_search_index_folder_name(mmi_audply_walk_stack_node_struct *stack, 
                                                    S16 depth_level,
                                                    CHAR *buf)
{
    S16 i;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_walk_stack_node_struct *active_stack = stack;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    MMI_BOOL result = MMI_FALSE;
    
    kal_wsprintf((WCHAR*)buf, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);

    for(i=0; i<depth_level; i++)
    {
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)buf);
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
        
        if(active_stack[i].fs_index != 0)
        {
            file_handle = FS_FindFirstN((PU16)temp_path,
                                    NULL,
                                    0,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    active_stack[i].fs_index - 1,  //fs index begin with 0
                                    FS_FIND_DEFAULT);
            
            if(file_handle >= 0 && (file_info.Attributes & FS_ATTR_DIR))   //Get fodler name by index
            {
                FS_FindClose(file_handle);
                mmi_ucs2cat((CHAR*)buf, (CHAR*)buf_file_name);
                mmi_ucs2cat((CHAR*)buf, (CHAR*)L"\\");
            }
    
        }
        else
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_search_previous_folder
 * DESCRIPTION
 *   Get previous folder
 * PARAMETERS
 *  stack  : [In]  current folder path stack index
 *  index  : [In]  Depth level
 *  buf : [Out] Folder path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_audply_walk_prev_folder_result_enum mmi_service_search_previous_folder(mmi_audply_walk_stack_node_struct *stack, 
                                                       S16 index,
                                                       CHAR *path_buf)
{
    S16 i = index, j;
    MMI_BOOL result = MMI_FALSE;
    CHAR *last_backlash;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)path_buf);

    for( ; i >= 0 ; i--)   // depth level
    {
        j = stack[i].fs_index - 1;

        ////Back to last folder
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);    
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
        
        for( ; j >= 0 ; j--)  //Folder level
        {

            if(stack[i].fs_index - 1 - j >= SEARCH_PREV_FOLDER_INDEX)
            {
                FS_FindClose(file_handle);
                stack[i].fs_index = j + 1;

                last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                MMI_ASSERT(last_backlash != NULL);
                *(last_backlash + 1) = 0;
                *last_backlash = 0;

                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)temp_path);

                return AUDPLY_WALK_PREV_FOLDER_RESULT_CONTINUE;
            }
            
            file_handle = FS_FindFirstN((PU16)temp_path,
                                    NULL,
                                    0,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    j-1,
                                    FS_FIND_DEFAULT);
            if(file_handle >= 0 && (file_info.Attributes & FS_ATTR_DIR))
            {
                FS_FindClose(file_handle);
                stack[i].fs_index = j;

                last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                MMI_ASSERT(last_backlash != NULL);
                *(last_backlash + 1) = 0;
                *last_backlash = 0;

                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");

                mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)temp_path);

                return AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS;
            }
            else if(j == 0)  //return current folder
            {
                FS_FindClose(file_handle);
                stack[i].fs_index = j;

                last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                MMI_ASSERT(last_backlash != NULL);
                *(last_backlash + 1) = 0;
                *last_backlash = 0;

                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)temp_path);

                return AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL;
            }
            else
            {
                FS_FindClose(file_handle);
            }
        }

        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        stack[i].fs_index = 0;

        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
        
    }

    return AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_search_prev_folder
 * DESCRIPTION
 *   Get previous folder
 * PARAMETERS
 *  stack  : [In]  current folder path stack index
 *  depth_level  : [In]  Depth level
 *  File_path     :  [In] Current folder path
 *  buf : [Out] Folder path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_audply_walk_prev_folder_result_enum mmi_service_search_prev_folder(mmi_audply_walk_stack_node_struct *stack, 
                                           S16 depth_level, 
                                           CHAR *File_path,
                                           CHAR *prev_folder_path)
{
    S16 index = 0, i = 0, counter =0;
    S32 return_value = 0;
    MMI_BOOL ret;
    mmi_audply_walk_stack_node_struct *active_stack = stack;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_walk_prev_folder_result_enum result;

    memcpy(temp_stack, stack , sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
    
    i = mmi_service_search_prev_folder_index(active_stack, depth_level-1);

    if(i == -1)
    {
        mmi_ucs2cpy((CHAR*)prev_folder_path, (CHAR*)File_path);
        return MMI_FALSE;
    }

    if(File_path == NULL)
    {
        mmi_service_search_index_folder_name(temp_stack, depth_level, (CHAR*)temp_path);
    }
    else
    {
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)File_path);
    }

    //temp_stack[i].fs_index -- ;

    result = mmi_service_search_previous_folder(temp_stack, i, (CHAR*)temp_path);

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_CONTINUE)
    {
        return result;
    }

    i = mmi_service_search_prev_folder_index(temp_stack, depth_level-1);

    i++;

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS)
    {
        for(; i < MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY; i++)
        {        
            ret = mmi_service_search_last_folder((CHAR*)temp_path, &temp_stack[i].fs_index);

            if(ret == MMI_FALSE)
            {
                break;
            }
        }
    }

    if(mmi_ucs2cmp((CHAR*)File_path, (CHAR*)temp_path) == 0)  //Can't find prev folder
    {
        result = AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL;
    }
    else
    {
        result = AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS;
        mmi_ucs2cpy((CHAR*)prev_folder_path, (CHAR*)temp_path);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_walk_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    memset(&g_audply.walk, 0, sizeof(mmi_audply_walk_struct));
    #else
    memset(&g_btbox_audply.walk, 0, sizeof(mmi_audply_walk_struct));
    #endif
    //g_audply.walk.phase = MMI_AUDPLY_LIST_PHASE_INIT;
    //g_audply.walk.sort_type = FS_NO_SORT;
    #ifndef __MMI_BTBOX_NOLCD__
    g_audply.walk.search_handle = -1;
    #else
    g_btbox_audply.walk.search_handle = -1;
    #endif

    //reset cache
    //memset(&g_audply.walk.cache, 0, sizeof(mmi_audply_walk_cache_struct));
    //g_audply.walk.cache.head = g_audply.walk.cache.tail = g_audply.walk.cache.cache_buf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_wait_screen_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_audply_walk_wait_screen_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
    case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
                
        /* do not allow popup sliding for this waiting popup */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
        
            ShowCategory66Screen(
                STR_ID_AUDPLY_TITLE,
                GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
                0,
                0,
                0,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);

            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            break;
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}


#ifndef __MMI_BTBOX_NOLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_entry_wait_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_walk_entry_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
    }

    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_AUDPLY_WAITSCREEN, 
        mmi_audply_walk_wait_screen_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

   mmi_frm_scrn_create(
        GRP_ID_AUDPLY_WAITSCREEN, 
        SCR_ID_AUDPLY_WAITSCREEN, 
        mmi_audply_walk_wait_screen_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_stack_correct_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_audply_walk_stack_correct_confirm_callback(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_1:
            case MMI_ALERT_CNFM_2:
            case MMI_ALERT_CNFM_3:
                // handle softkey event here
                break;
            case MMI_ALERT_CNFM_OK:
                // handle softkey event here
                break;
            case MMI_ALERT_CNFM_YES:
            {
                //clear filename
                #ifndef __MMI_BTBOX_NOLCD__
                if (g_audply.walk.filefullname != NULL)
                {
                    g_audply.walk.filefullname[0] = 0;
                }
                mmi_audply_walk_cache_init();
                mmi_audply_walk_reset();
                kal_wsprintf(g_audply.walk.path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
                g_audply.walk.search_handle = -1;
                g_audply.walk.stack_index = 0;
                g_audply.walk.total = 0;
                Press_Prev = 2;
                g_audply.walk.auto_walk_done = MMI_FALSE;
                #else
                if (g_btbox_audply.walk.filefullname != NULL)
                {
                    g_btbox_audply.walk.filefullname[0] = 0;
                }
                mmi_audply_walk_cache_init();
                mmi_audply_walk_reset();
                kal_wsprintf(g_btbox_audply.walk.path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
                g_btbox_audply.walk.search_handle = -1;
                g_btbox_audply.walk.stack_index = 0;
                g_btbox_audply.walk.total = 0;
                Press_Prev = 2;
                g_btbox_audply.walk.auto_walk_done = MMI_FALSE;
                #endif
                break;
            }
            case MMI_ALERT_CNFM_NO:
            {
                mmi_audply_walk_entry_wait_screen();
                break;
               }
        }
    }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_cache_init
 * DESCRIPTION
 *   Init cache and temp cache array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_cache_init(void)
{
    memset(&cache_int_struct, 0, sizeof(audply_walk_cache_int_struct));
    memset(&cache_temp_struct, 0, sizeof(audply_walk_cache_int_temp_struct));
    cache_int_struct.cache_state = AUDPLY_WALK_CACHE_STATE_FINISH;
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_query_cache_cntx_pointer
 * DESCRIPTION
 *   For new cache job temp cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void*
 *****************************************************************************/
void* mmi_audply_query_cache_cntx_pointer()
{
    return new_cache_work.file_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_query_cache_cntx_stack_pointer
 * DESCRIPTION
 *   For new cache job temp cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void*
 *****************************************************************************/
void* mmi_audply_query_cache_cntx_stack_pointer()
{
    return new_cache_work.stack;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_query_temp_cache_cntx_pointer
 * DESCRIPTION
 *   For temp cache job temp cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void*
 *****************************************************************************/
void* mmi_audply_query_temp_cache_cntx_pointer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Get Last Cache file*/
    index = cache_int_struct.Cache_footer_index;
    index++;
    if(index >= MMI_AUDPLY_CACHE_NUM)
    {
        index = index - MMI_AUDPLY_CACHE_NUM;
    }
    mmi_ucs2cpy((CHAR *)temp_cache_work.file_path,(CHAR *)cache_int_struct.cache_buffer[index].Cache_file_path);

    return temp_cache_work.file_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_is_the_first_file
 * DESCRIPTION
 *   Check the current file is the folder's first file
 * PARAMETERS
 *  file_path: [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_check_is_the_first_file(CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    MMI_BOOL ret = MMI_TRUE;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)file_path);

    last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    last_backlash += 2;
    
    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)last_backlash);
    last_backlash -= 2;
    *(last_backlash + 1) = 0;
    *last_backlash = 0;

    mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"*.*");

    file_handle = FS_FindFirstN((PU16)temp_path2,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,  //fs index begin with 0
                                FS_FIND_DEFAULT);
    if(file_handle >= 0)
    {
        FS_FindClose(file_handle);
        if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path) == 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
        //ASSERT(0);  //Current is not a valid file
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_valid_cache_buffer_index
 * DESCRIPTION
 *   Get Valid cache buffer index
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_get_valid_cache_buffer_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    FS_HANDLE file_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index) //Cache is empty
    {
        ret = MMI_FALSE;
        return ret;
    }
    do
    {
        file_handler = FS_Open((WCHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path, FS_READ_ONLY);

        if(file_handler >= FS_NO_ERROR)  //Valid cache file
        {
            FS_Close(file_handler);
            ret = MMI_TRUE;
            return ret;
        }
        else
        {
            cache_int_struct.Cache_header_index--;
            if(cache_int_struct.Cache_header_index < 0)
            {
                cache_int_struct.Cache_header_index += MMI_AUDPLY_CACHE_NUM;
            }

            if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index) //Cache is empty
            {
                ret = MMI_FALSE;
                return ret;
            }
        }
        
    }while(1);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_save_cache_to_file
 * DESCRIPTION
 *   For cache test use, save cache info to file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_save_cache_to_file()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_copy_temp_to_cache
 * DESCRIPTION
 *   Copy temp cache info to cache array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_copy_temp_to_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 cache_index, temp_cache_index, cache_index2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_index = cache_int_struct.Cache_footer_index;
    temp_cache_index = cache_temp_struct.Cache_header_index;
    cache_index2 = cache_int_struct.Cache_header_index + 1;

    if(cache_index2 >= MMI_AUDPLY_CACHE_NUM)
    {
        cache_index2 -= MMI_AUDPLY_CACHE_NUM;
    }
    
    do
    {
        memcpy(&(cache_int_struct.cache_buffer[cache_index]), 
               &(cache_temp_struct.cache_buffer[temp_cache_index]),
               sizeof(audply_walk_cache_struct));

        cache_index --;
        if((cache_index < 0 ))
        {
            cache_index += MMI_AUDPLY_CACHE_NUM;
        }

        temp_cache_index --;

        if(temp_cache_index < 0 )
        {
            temp_cache_index += MMI_AUDPLY_RECACHE_NUM;
        }
        
    }while(temp_cache_index != cache_temp_struct.Cache_footer_index && cache_index != cache_index2);

    cache_temp_struct.Cache_header_index = temp_cache_index;
    cache_int_struct.Cache_footer_index = cache_index;

    mmi_audply_save_cache_to_file();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_save_temp_cache_to_file
 * DESCRIPTION
 *   Save temp cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_save_temp_cache_to_file()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_add_cache
 * DESCRIPTION
 *   Add cache
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_add_cache(CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    MMI_BOOL from_cache_end;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 Counter = 0, return_value;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_get_valid_cache_buffer_index();

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)file_path);
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    last_backlash += 2;
    
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)last_backlash);

    last_backlash -= 2;
    *(last_backlash + 1) = 0;
    *last_backlash = 0;

    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
    
    if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index)  //First time add cache
    {
        from_cache_end = MMI_FALSE;
    }
    else
    {
        from_cache_end = MMI_TRUE;
    }

    if(from_cache_end == MMI_TRUE)
    {
        //file_handle = FS_Open(temp_path, FS_READ_ONLY);
        if(new_cache_work.current_file_handler == -1)
        {
            new_cache_work.current_file_handler = FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                cache_int_struct.Cache_index + 1,  //First find right index
                                FS_FIND_DEFAULT);

            if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) != 0) //Some file had been deleted
            {
                //To do
            }
        }
        
        return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0) //No more file
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter + cache_int_struct.Cache_index;
            cache_int_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            #ifndef __MMI_BTBOX_NOLCD__
            g_audply.walk.correcting_stack = MMI_FALSE;    
            #else
            g_btbox_audply.walk.correcting_stack = MMI_FALSE;    
            #endif
            #ifndef __MMI_BTBOX_NOLCD__
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            #endif
            return MMI_FALSE;
        }
        
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)temp_path);
            //cache_int_struct.Cache_header_index++;
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter + cache_int_struct.Cache_index;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR || ((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0)))
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0)//No more file
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter + cache_int_struct.Cache_index;
            cache_int_struct.Cache_index = 0;
            FS_FindClose(new_cache_work.current_file_handler);
            new_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            #ifndef __MMI_BTBOX_NOLCD__
            g_audply.walk.correcting_stack = MMI_FALSE;    
            #else
            g_btbox_audply.walk.correcting_stack = MMI_FALSE;    
            #endif
            #ifndef __MMI_BTBOX_NOLCD__
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            #endif
            return MMI_FALSE;
        }
        else
        {
            cache_int_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    else
    {
        cache_int_struct.Cache_index = 0;
        new_cache_work.current_file_handler = -1;
        new_cache_work.current_file_handler= FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,  //fs index begin with 0
                                FS_FIND_DEFAULT);
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)temp_path);
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            Counter++;
            return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR || ((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0))) //No more file
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2)) == 0) //No more file
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            /*Add Current file to cache*/
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);

            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter + cache_int_struct.Cache_index;

            cache_int_struct.Cache_index = 0;
            FS_FindClose(new_cache_work.current_file_handler);
            new_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            #ifndef __MMI_BTBOX_NOLCD__
            g_audply.walk.correcting_stack = MMI_FALSE;    
            #else
            g_btbox_audply.walk.correcting_stack = MMI_FALSE;    
            #endif    
            #ifndef __MMI_BTBOX_NOLCD__
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            #endif
            return MMI_FALSE;
        }
        else
        {
            cache_int_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_add_cache_temp
 * DESCRIPTION
 *   Add  temp cache
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_add_cache_temp(CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    MMI_BOOL from_cache_end;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 Counter = 0, return_value;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_get_valid_cache_buffer_index();

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)file_path);
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    last_backlash += 2;
    
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)last_backlash);

    last_backlash -= 2;
    *(last_backlash + 1) = 0;
    *last_backlash = 0;

    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");

    if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)  //First time add cache
    {
        from_cache_end = MMI_FALSE;
    }
    else
    {
        from_cache_end = MMI_TRUE;
    }

    if(from_cache_end == MMI_TRUE)
    {
        //file_handle = FS_Open(temp_path, FS_READ_ONLY);
        if(temp_cache_work.current_file_handler == -1)
        {
            temp_cache_work.current_file_handler = FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                cache_temp_struct.Cache_index + 1,  //First find right index
                                FS_FIND_DEFAULT);

            if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) != 0) //Some file had been deleted
            {
                //To do
            }
        }
        
        return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0) //No more file
        {
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            cache_temp_struct.Cache_header_index++;    
            
            if(cache_temp_struct.Cache_header_index >= MMI_AUDPLY_RECACHE_NUM)
            {
                cache_temp_struct.Cache_header_index = cache_temp_struct.Cache_header_index - MMI_AUDPLY_RECACHE_NUM;
            }

            if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)
            {
                cache_temp_struct.Cache_footer_index++;
                if(cache_temp_struct.Cache_footer_index >= MMI_AUDPLY_RECACHE_NUM)
                {
                    cache_temp_struct.Cache_footer_index = cache_temp_struct.Cache_footer_index - MMI_AUDPLY_RECACHE_NUM;
                }
            }
            
            mmi_ucs2cpy((CHAR*)cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].Cache_file_path, (CHAR*)temp_path);
            //cache_int_struct.Cache_header_index++;
            Counter++;
            cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].FS_Index = Counter + cache_temp_struct.Cache_index;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR || ((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0)))
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0)//No more file
        {
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_temp_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    else
    {
        cache_temp_struct.Cache_index = 0;
        temp_cache_work.current_file_handler = -1;
        temp_cache_work.current_file_handler= FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,  //fs index begin with 0
                                FS_FIND_DEFAULT);
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            cache_temp_struct.Cache_header_index++;

            if(cache_temp_struct.Cache_header_index >= MMI_AUDPLY_RECACHE_NUM)
            {
                cache_temp_struct.Cache_header_index = cache_temp_struct.Cache_header_index - MMI_AUDPLY_RECACHE_NUM;
            }

            if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)
            {
                cache_temp_struct.Cache_footer_index++;
                if(cache_temp_struct.Cache_footer_index >= MMI_AUDPLY_RECACHE_NUM)
                {
                    cache_temp_struct.Cache_footer_index = cache_temp_struct.Cache_footer_index - MMI_AUDPLY_RECACHE_NUM;
                }
            }        
            mmi_ucs2cpy((CHAR*)cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].Cache_file_path, (CHAR*)temp_path);
            cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].FS_Index = Counter;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            Counter++;
            return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR || ((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) == 0))) //No more file
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if((mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2)) == 0) //No more file
        {
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_temp_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_add_cache_previous_folder
 * DESCRIPTION
 *   Add  previous folder file to cache
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_add_cache_previous_folder(CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    MMI_BOOL from_cache_end;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 Counter = 0, return_value;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_get_valid_cache_buffer_index();

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)new_cache_work_temp.previous_folder_path);
    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
    
    if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index)  //First time add cache
    {
        from_cache_end = MMI_FALSE;
    }
    else
    {
        from_cache_end = MMI_TRUE;
    }

    if(from_cache_end == MMI_TRUE)
    {
        //file_handle = FS_Open(temp_path, FS_READ_ONLY);
        if(new_cache_work.current_file_handler == -1)
        {
            new_cache_work.current_file_handler = FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                cache_int_struct.Cache_index + 1,  //First find right index
                                FS_FIND_DEFAULT);

            if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) != 0) //Some file had been deleted
            {
                //To do
            }
        }
        
        return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        if(return_value < FS_NO_ERROR) //No more file
        {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = 0;
            cache_int_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            return MMI_FALSE;
        }
        
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)temp_path);
            //cache_int_struct.Cache_header_index++;
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter + cache_int_struct.Cache_index;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR)
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(return_value < FS_NO_ERROR)//No more file
        {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);
            Counter++;
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = 0;
            cache_int_struct.Cache_index = 0;
            FS_FindClose(new_cache_work.current_file_handler);
            new_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_int_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    else
    {
        cache_int_struct.Cache_index = 0;
        new_cache_work.current_file_handler = -1;
        new_cache_work.current_file_handler= FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,  //fs index begin with 0
                                FS_FIND_DEFAULT);
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)temp_path);
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = Counter;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            Counter++;
            return_value = FS_FindNextN(
                            new_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR) //No more file
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(return_value < FS_NO_ERROR) //No more file
        {
            /*Add Current file to cache*/
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_audply_walk_add_cache((UI_character_type *)file_path);

            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = 0;

            cache_int_struct.Cache_index = 0;
            FS_FindClose(new_cache_work.current_file_handler);
            new_cache_work.current_file_handler = -1;
            mmi_audply_save_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_int_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_add_temp_cache_previous_folder
 * DESCRIPTION
 *   Add  previous folder file to temp cache
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_add_temp_cache_previous_folder(CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    MMI_BOOL from_cache_end;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 Counter = 0, return_value;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_get_valid_cache_buffer_index();

    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)new_cache_work_temp.previous_folder_path);
    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
    
    if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)  //First time add cache
    {
        from_cache_end = MMI_FALSE;
    }
    else
    {
        from_cache_end = MMI_TRUE;
    }

    if(from_cache_end == MMI_TRUE)
    {
        //file_handle = FS_Open(temp_path, FS_READ_ONLY);
        if(temp_cache_work.current_file_handler == -1)
        {
            temp_cache_work.current_file_handler = FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                cache_temp_struct.Cache_index + 1,  //First find right index
                                FS_FIND_DEFAULT);

            if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path2) != 0) //Some file had been deleted
            {
                //To do
            }
        }
        
        return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        if(return_value < FS_NO_ERROR) //No more file
        {
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            cache_temp_struct.Cache_header_index++;    
            
            if(cache_temp_struct.Cache_header_index >= MMI_AUDPLY_RECACHE_NUM)
            {
                cache_temp_struct.Cache_header_index = cache_temp_struct.Cache_header_index - MMI_AUDPLY_RECACHE_NUM;
            }

            if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)
            {
                cache_temp_struct.Cache_footer_index++;
                if(cache_temp_struct.Cache_footer_index >= MMI_AUDPLY_RECACHE_NUM)
                {
                    cache_temp_struct.Cache_footer_index = cache_temp_struct.Cache_footer_index - MMI_AUDPLY_RECACHE_NUM;
                }
            }
            
            mmi_ucs2cpy((CHAR*)cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].Cache_file_path, (CHAR*)temp_path);
            //cache_int_struct.Cache_header_index++;
            Counter++;
            cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].FS_Index = Counter + cache_temp_struct.Cache_index;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR)
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(return_value < FS_NO_ERROR)//No more file
        {
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_temp_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    else
    {
        cache_temp_struct.Cache_index = 0;
        temp_cache_work.current_file_handler = -1;
        temp_cache_work.current_file_handler= FS_FindFirstN((PU16)temp_path,
                                audio_pattern_array,
                                pattern_array_size,
                                0,
                                0,
                                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                &file_info,
                                  (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0,  //fs index begin with 0
                                FS_FIND_DEFAULT);
        do
        {
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            cache_temp_struct.Cache_header_index++;

            if(cache_temp_struct.Cache_header_index >= MMI_AUDPLY_RECACHE_NUM)
            {
                cache_temp_struct.Cache_header_index = cache_temp_struct.Cache_header_index - MMI_AUDPLY_RECACHE_NUM;
            }

            if(cache_temp_struct.Cache_header_index == cache_temp_struct.Cache_footer_index)
            {
                cache_temp_struct.Cache_footer_index++;
                if(cache_temp_struct.Cache_footer_index >= MMI_AUDPLY_RECACHE_NUM)
                {
                    cache_temp_struct.Cache_footer_index = cache_temp_struct.Cache_footer_index - MMI_AUDPLY_RECACHE_NUM;
                }
            }        
            mmi_ucs2cpy((CHAR*)cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].Cache_file_path, (CHAR*)temp_path);
            cache_temp_struct.cache_buffer[cache_temp_struct.Cache_header_index].FS_Index = Counter;

            if(Counter > CACHE_JOB_NUM)
            {
                break;
            }

            Counter++;
            return_value = FS_FindNextN(
                            temp_cache_work.current_file_handler,
                            audio_pattern_array,
                            pattern_array_size,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(return_value < FS_NO_ERROR) //No more file
            {
                break;
            }
        }while(1);
        //FS_FindClose(file_handle);
        
        if(return_value < FS_NO_ERROR) //No more file
        {
            /*Add Current file to cache*/
            cache_temp_struct.Cache_index = 0;
            FS_FindClose(temp_cache_work.current_file_handler);
            temp_cache_work.current_file_handler = -1;
            mmi_audply_save_temp_cache_to_file();
            return MMI_FALSE;
        }
        else
        {
            cache_temp_struct.Cache_index += Counter;
            return MMI_TRUE;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_prev_media_file_folder
 * DESCRIPTION
 *   Get previous media file floder
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_audply_walk_prev_folder_result_enum mmi_audply_get_prev_media_file_folder(CHAR *full_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    mmi_audply_walk_prev_folder_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                  */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)full_file_path);
    result = mmi_service_search_prev_folder(new_cache_work_temp.temp_stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, (CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)new_cache_work_temp.previous_folder_path);

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL || result == AUDPLY_WALK_PREV_FOLDER_RESULT_CONTINUE)
    {
        memcpy(new_cache_work_temp.temp_stack, temp_stack , sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
        mmi_ucs2cpy((CHAR*)full_file_path, (CHAR*)new_cache_work_temp.previous_folder_path);
        return result;
    }
            
    do
    {
        mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"*.*");
        file_handle = FS_FindFirstN((PU16)new_cache_work_temp.previous_folder_path,
                                    audio_pattern_array,
                                    pattern_array_size,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    0,  //fs index begin with 0
                                    FS_FIND_DEFAULT);

        if(file_handle >= 0) // Current folder has media files
        {
            FS_FindClose(file_handle);
            break;
        }
        else
        {
            FS_FindClose(file_handle);
            last_backlash = mmi_ucs2rchr((CHAR*)new_cache_work_temp.previous_folder_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
    
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"\\");
            result = mmi_service_search_prev_folder(temp_stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, (CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)new_cache_work_temp.previous_folder_path);
        }                
    }while(result == AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS);

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)new_cache_work_temp.previous_folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"\\");
    }
    memcpy(new_cache_work_temp.temp_stack, temp_stack , sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
    mmi_ucs2cpy((CHAR*)full_file_path, (CHAR*)new_cache_work_temp.previous_folder_path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_prev_media_file_folder_ext
 * DESCRIPTION
 *   Get previous media file floder
 * PARAMETERS
 *  file_path : [In] current file path
 *  stack  : [In] Current file folder stack index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_audply_walk_prev_folder_result_enum mmi_audply_get_prev_media_file_folder_ext(CHAR *full_file_path, mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    mmi_audply_walk_prev_folder_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                  */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)full_file_path);
    result = mmi_service_search_prev_folder(stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, (CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)new_cache_work_temp.previous_folder_path);

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_FAIL || result == AUDPLY_WALK_PREV_FOLDER_RESULT_CONTINUE)
    {
        memcpy(stack, temp_stack , sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
        mmi_ucs2cpy((CHAR*)full_file_path, (CHAR*)new_cache_work_temp.previous_folder_path);
        return result;
    }
            
    do
    {
        mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"*.*");
        file_handle = FS_FindFirstN((PU16)new_cache_work_temp.previous_folder_path,
                                    audio_pattern_array,
                                    pattern_array_size,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    0,  //fs index begin with 0
                                    FS_FIND_DEFAULT);

        if(file_handle >= 0) // Current folder has media files
        {
            break;
        }
        else
        {
            FS_FindClose(file_handle);
            last_backlash = mmi_ucs2rchr((CHAR*)new_cache_work_temp.previous_folder_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
    
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"\\");
            result = mmi_service_search_prev_folder(temp_stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, (CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)new_cache_work_temp.previous_folder_path);
        }                
    }while(result == AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS);

    if(result == AUDPLY_WALK_PREV_FOLDER_RESULT_SUCCESS)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)new_cache_work_temp.previous_folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        mmi_ucs2cat((CHAR*)new_cache_work_temp.previous_folder_path, (CHAR*)L"\\");
    }
    memcpy(stack, temp_stack , sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
    mmi_ucs2cpy((CHAR*)full_file_path, (CHAR*)new_cache_work_temp.previous_folder_path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_stack_info_by_path
 * DESCRIPTION
 *   Get stack info by folder path
 * PARAMETERS
 *  file_path : [In] current file path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_get_stack_info_by_path(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handler;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    mmi_audply_walk_stack_node_struct *temp_stack = new_cache_work_temp.temp_stack;
    S16 i, index, Counter = 0, return_value;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*----------------------------------------------------------------*/
    /* Code body                                                */
    /*----------------------------------------------------------------*/

    memset(temp_stack, 0, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);

    /*Get depth level*/
    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)path);
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    *(last_backlash + 1) = 0;
    *last_backlash = 0;
    
    for(i = 0; i < MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY; i++)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        if(last_backlash == NULL)
        {
            break;
        }
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
    }

    if(i != 0)
    {
        i--;
    }
    else
    {
        return; //Current is the driver E
    }
    
    /*get  stack info*/
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)path);
    
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    *(last_backlash + 1) = 0;
    *last_backlash = 0;
    
    for(; i>=0; i--)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        last_backlash += 2;
    
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)last_backlash);
        last_backlash -= 2;
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"*.*");
        file_handler = FS_FindFirstN(temp_path2,
                                    NULL,
                                    0,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    0,  //fs index begin with 0
                                    FS_FIND_DEFAULT);
        if(file_handler >= 0)
        {
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    temp_stack[i].fs_index = Counter+1;
                    goto END;
                }
            }
        }
        do
        {
            Counter++;
            return_value = FS_FindNextN(
                            file_handler,
                            NULL,
                            0,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    temp_stack[i].fs_index = Counter+1;
                    goto END;
                }
            }
        }while(return_value == FS_NO_ERROR);

        END:
            FS_FindClose(file_handler);
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');        
            *(last_backlash + 1) = 0;
            *last_backlash = 0;    
            Counter = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_stack_info_by_path_ext
 * DESCRIPTION
 *   Get stack info by folder path
 * PARAMETERS
 *  file_path : [In] current file path
 *  stack : [In] current file path stack index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_get_stack_info_by_path_ext(CHAR *path, mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handler;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    mmi_audply_walk_stack_node_struct *temp_stack = stack;
    S16 i, index, Counter = 0, return_value;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*----------------------------------------------------------------*/
    /* Code body                                                */
    /*----------------------------------------------------------------*/

    memset(temp_stack, 0, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);

    /*Get depth level*/
    mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)path);
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    *(last_backlash + 1) = 0;
    *last_backlash = 0;
    
    for(i = 0; i < MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY; i++)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        if(last_backlash == NULL)
        {
            break;
        }
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
    }

    if(i != 0)
    {
        i--;
    }
    else
    {
        return; //Current is the driver E
    }
    
    /*get  stack info*/
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)path);
    
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    *(last_backlash + 1) = 0;
    *last_backlash = 0;
    
    for(; i>=0; i--)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        last_backlash += 2;
    
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)last_backlash);
        last_backlash -= 2;
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"*.*");
        file_handler = FS_FindFirstN(temp_path2,
                                    NULL,
                                    0,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    0,  //fs index begin with 0
                                    FS_FIND_DEFAULT);
        if(file_handler >= 0)
        {
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    temp_stack[i].fs_index = Counter+1;
                    goto END;
                }
            }
        }
        do
        {
            Counter++;
            return_value = FS_FindNextN(
                            file_handler,
                            NULL,
                            0,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    temp_stack[i].fs_index = Counter+1;
                    goto END;
                }
            }
        }while(return_value == FS_NO_ERROR);

        END:
            FS_FindClose(file_handler);
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');        
            *(last_backlash + 1) = 0;
            *last_backlash = 0;    
            Counter = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_cache_do_validtion_stack
 * DESCRIPTION
 *   Validtion stack info
 * PARAMETERS
 *  file_path : [In] current file path
 *  stack : [In] current file path stack index
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_cache_do_validtion_stack(CHAR *path, mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handler;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    mmi_audply_walk_stack_node_struct temp_stack_test[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
    S16 i, j, index, Counter = 0, return_value;
    FS_DOSDirEntry file_info;    
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*----------------------------------------------------------------*/
    /* Code body                                                */
    /*----------------------------------------------------------------*/

    file_handler = FS_Open((WCHAR*)path, FS_READ_ONLY);

    if(file_handler >= FS_NO_ERROR)
    {
        FS_Close(file_handler);
    }
    else
    {
        return MMI_FALSE;
    }

    memcpy(temp_stack_test, stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
    mmi_service_search_index_folder_name(temp_stack_test, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, (CHAR*)temp_path);

    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)path);
    last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);
    *(last_backlash + 1) = 0;
    *last_backlash = 0;
    
    if(mmi_ucs2cmp((CHAR*)temp_path2, (CHAR*)temp_path) == 0)
    {
        return MMI_TRUE;
    }

    j = mmi_service_search_prev_folder_index(temp_stack_test, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY-1);
    /*Correct  stack num*/
    mmi_ucs2cpy((CHAR*)temp_path2, (CHAR*)path);
    
    for(; j>=0; j--)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        last_backlash += 2;
    
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)last_backlash);
        last_backlash -= 2;
        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)temp_path2, (CHAR*)L"*.*");
        file_handler = FS_FindFirstN(temp_path2,
                                    NULL,
                                    0,
                                    0,
                                    0,
                                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                    &file_info,
                                      (PU16)buf_file_name,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    0,  //fs index begin with 0
                                    FS_FIND_DEFAULT);
        if(file_handler >= 0)
        {
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    temp_stack_test[j].fs_index = Counter;
                    goto END;
                }
            }
        }
        Counter++;
        do
        {
            return_value = FS_FindNextN(
                            file_handler,
                            NULL,
                            0,
                            0,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
            if(file_info.Attributes & FS_ATTR_DIR)
            {
                if(mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)temp_path)==0)
                {
                    FS_FindClose(file_handler);
                    temp_stack_test[j].fs_index = Counter;
                    goto END;
                }
            }
        }while(return_value == FS_NO_ERROR);

        END:
            FS_FindClose(file_handler);
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');        
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
        
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_cache_comp_file_folder
 * DESCRIPTION
 *   Campare file folder
 * PARAMETERS
 *  file_path : [In] current file path
 *  File_path2 : [In] previous file folder
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_cache_comp_file_folder(CHAR *File_path, CHAR *File_path2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR *last_backlash;
    /*----------------------------------------------------------------*/
    /* Code body                                                */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR *)temp_path, (CHAR *)File_path);
    mmi_ucs2cpy((CHAR *)temp_path2, (CHAR *)File_path2);

    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);    
    *(last_backlash + 1) = 0;
    *last_backlash = 0;

    last_backlash = mmi_ucs2rchr((CHAR*)temp_path2, (U16)L'\\');
    *(last_backlash + 1) = 0;
    *last_backlash = 0;

    if(mmi_ucs2cmp((CHAR *)temp_path, (CHAR *)temp_path2) == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_auddply_cache_work_event_hdlr
 * DESCRIPTION
 *   File handler event handler
 * PARAMETERS
 *  event : [In] event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_auddply_cache_work_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_plc_work_finish_struct *evt;
    CHAR *File_path;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (mmi_evt_plc_work_finish_struct *)event;

    if(event->evt_id == EVT_ID_PLC_WORK_FINISH)
    {
        if(evt->work_type == PLC_WORK_NEW_CACHE)
        {
            if(evt->is_canceled == MMI_FALSE)
            {
                if((cache_int_struct.Cache_header_index - cache_int_struct.Cache_footer_index < MMI_AUDPLY_RECACHE_NUM) &&
                      (cache_int_struct.Cache_header_index - cache_int_struct.Cache_footer_index > 0))
                {
                    File_path = mmi_audply_query_temp_cache_cntx_pointer();
                    cache_temp_struct.cache_state = AUDPLY_WALK_CACHE_STATE_CACHING;
                    memset(&cache_temp_struct, 0, sizeof(audply_walk_cache_int_temp_struct));
                    plcache_audply_load_cache(File_path);
                }
                cache_int_struct.cache_state = AUDPLY_WALK_CACHE_STATE_FINISH;
            }
        }

        if(evt->work_type == PLC_WORK_LOAD_CACHE)
        {
            cache_temp_struct.cache_state = AUDPLY_WALK_CACHE_STATE_FINISH;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_save_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_walk_save_record(CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    mmi_audply_walk_record_struct walk_record = {0};
    S16 error;
    U16 stack_size = sizeof(mmi_audply_walk_stack_node_struct) * MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    memcpy(&walk_record, this->stack, stack_size);
    walk_record.stack_index = this->stack_index;
    mmi_ucs2cpy((CHAR*)&(walk_record.current_path), buffer); //(CHAR*)g_audply.walk.filefullname);
    WriteRecord(NVRAM_EF_AUDPLY_WALK_LID, 1, (void*)&walk_record, sizeof(mmi_audply_walk_record_struct), &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_next_backwards_folder
 * DESCRIPTION
 *   Get next folder for press next
 * PARAMETERS
 *  file_path : [In] Current file path
 *  Stack : [In] Current file path stack info
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_get_next_backwards_folder(CHAR* file_path, mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Index, Stack_index;
    S32 Counter = 0, return_value;
    CHAR *File_path = file_path;
    CHAR* last_backlash;
    FS_HANDLE ret = FS_NO_ERROR;
    FS_DOSDirEntry file_info;    
    mmi_audply_walk_stack_node_struct tmp_stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(stack[0].fs_index== 0) //Root Folder
    {
        return MMI_FALSE;
    }

    Index = mmi_service_search_prev_folder_index(stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY - 1);

    memcpy(tmp_stack, stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
    
    last_backlash = mmi_ucs2rchr((CHAR*)File_path, (U16)L'\\');
    MMI_ASSERT(last_backlash != NULL);

    *(last_backlash + 1) = 0;
    *last_backlash = 0;
        
    for(; Index >= 0; Index--)
    {
        last_backlash = mmi_ucs2rchr((CHAR*)File_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        Stack_index = tmp_stack[Index].fs_index;
        Stack_index ++;

        mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"*.*");

        ret = FS_FindFirstN(
                (PU16)File_path,
                NULL,
                0,
                0,    /* only search media files in this phase. */
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)buf_file_name,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                Stack_index-1,
                FS_FIND_DEFAULT);

        if(ret >= FS_NO_ERROR && (file_info.Attributes & FS_ATTR_DIR)) //Search next folder done
        {
            FS_FindClose(ret);
            tmp_stack[Index].fs_index = Stack_index;
            last_backlash = mmi_ucs2rchr((CHAR*)File_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);

            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)File_path, (CHAR*)buf_file_name);
            mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"\\");
            memcpy(stack, tmp_stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
            return MMI_TRUE;
        }
        else if(ret < FS_NO_ERROR)
        {
            tmp_stack[Index].fs_index = 0;
        }
        else
        {
            Counter = 0;
            do
            {
                Counter++;
                return_value = FS_FindNextN(
                                ret,
                                    NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                if(file_info.Attributes & FS_ATTR_DIR) // Find
                {
                    FS_FindClose(ret);
                    tmp_stack[Index].fs_index = Stack_index + Counter;
                    last_backlash = mmi_ucs2rchr((CHAR*)File_path, (U16)L'\\');
                    MMI_ASSERT(last_backlash != NULL);

                    *(last_backlash + 1) = 0;
                    *last_backlash = 0;
                    mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"\\");
                    mmi_ucs2cat((CHAR*)File_path, (CHAR*)buf_file_name);
                    mmi_ucs2cat((CHAR*)File_path, (CHAR*)L"\\");
                    memcpy(stack, tmp_stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
                    return MMI_TRUE;
                }
            }while(return_value == FS_NO_ERROR);
            if(return_value != FS_NO_ERROR)
            {
                FS_FindClose(ret);
                tmp_stack[Index].fs_index = 0;
            }
        }

        last_backlash = mmi_ucs2rchr((CHAR*)File_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_first_folder
 * DESCRIPTION
 *   Get next first folder for press next
 * PARAMETERS
 *  file_path : [In] Current file path
 *  Stack : [In] Current file path stack info
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_get_first_folder(CHAR* file_path, mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE File_handler = FS_NO_ERROR;
    FS_DOSDirEntry file_info;    
    CHAR* folder_path = file_path;
    CHAR *last_backlash;
    mmi_audply_walk_stack_node_struct *active_stack = stack;
    S32 return_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"*.*");
    File_handler = FS_FindFirstN(
                    (PU16)folder_path,
                    NULL,
                    0,
                    FS_ATTR_DIR,    /* only search media files in this phase. */
                    0,
                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                    &file_info,
                    (PU16)buf_file_name,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    0,
                    FS_FIND_DEFAULT);

    if(File_handler >= FS_NO_ERROR && (file_info.Attributes & FS_ATTR_DIR) )
    {
        FS_FindClose(File_handler);
        last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)buf_file_name);
        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        mmi_audply_walk_get_stack_info_by_path_ext(folder_path, stack);
        return MMI_TRUE;
    }

    if(File_handler < FS_NO_ERROR)  //Empty folder
    {
        return MMI_FALSE;
    }

    do
    {
        return_value = FS_FindNextN(
                                File_handler,
                                    NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);

        
        if(return_value >= FS_NO_ERROR && (file_info.Attributes & FS_ATTR_DIR) )
        {
            FS_FindClose(File_handler);
            last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);

            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)folder_path, (CHAR*)buf_file_name);
            mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
            mmi_audply_walk_get_stack_info_by_path_ext(folder_path, stack);
            return MMI_TRUE;
        }
        
    }while(return_value == FS_NO_ERROR);

    if(return_value < FS_NO_ERROR)
    {
        FS_FindClose(File_handler);
        last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        return MMI_FALSE;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_folder
 * DESCRIPTION
 *   walk folder to get next media file folder  for press next
 * PARAMETERS
 *  file_path : [In] Current file path
 *  Stack : [In] Current file path stack info
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_audply_walk_folder_result_enum mmi_audply_walk_folder(CHAR* folder_path, mmi_audply_walk_stack_node_struct *active_stack, S32 Index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE File_handler = FS_NO_ERROR;
    FS_DOSDirEntry file_info;
    CHAR *last_backlash;
    MMI_BOOL ret;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"*.*");
    
    File_handler = FS_FindFirstN(
                    (PU16)folder_path,
                    audio_pattern_array,
                    pattern_array_size,
                    0,    /* only search media files in this phase. */
                    0,
                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                    &file_info,
                    (PU16)buf_file_name,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    Index,
                    FS_FIND_DEFAULT);

    if(File_handler >= FS_NO_ERROR && !(file_info.Attributes & FS_ATTR_DIR)) //Found
    {
        last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;
    #ifndef __MMI_BTBOX_NOLCD__
        g_audply.walk.search_handle = File_handler;
    #else
        g_btbox_audply.walk.search_handle = File_handler;
    #endif

        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)buf_file_name);

        return AUDPLY_WALK_FOLDER_RESULT_SUCCESS;
    }
    else if(File_handler >= FS_NO_ERROR && (file_info.Attributes & FS_ATTR_DIR))
    {
        FS_FindClose(File_handler);
        last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        if(active_stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY-1].fs_index!= 0)
        {
            if(mmi_audply_walk_get_next_backwards_folder(folder_path, active_stack) == MMI_TRUE)
            {
                //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
            }
            else
            {
                return AUDPLY_WALK_FOLDER_RESULT_FAIL;
            }
        }
        else
        {
            ret = mmi_audply_walk_get_first_folder(folder_path, active_stack);
            if(ret == MMI_TRUE)
            {
                //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
            }
            else
            {
                if(mmi_audply_walk_get_next_backwards_folder(folder_path, active_stack) == MMI_TRUE)
                {
                    //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                    return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
                }
                else
                {
                    return AUDPLY_WALK_FOLDER_RESULT_FAIL;
                }
            }
        }
    }
    else
    {
        last_backlash = mmi_ucs2rchr((CHAR*)folder_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);

        *(last_backlash + 1) = 0;
        *last_backlash = 0;

        mmi_ucs2cat((CHAR*)folder_path, (CHAR*)L"\\");
        if(active_stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY-1].fs_index!= 0)
        {
            if(mmi_audply_walk_get_next_backwards_folder(folder_path, active_stack) == MMI_TRUE)
            {
                //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
            }
            else
            {
                return AUDPLY_WALK_FOLDER_RESULT_FAIL;
            }
        }
        else
        {
            ret = mmi_audply_walk_get_first_folder(folder_path, active_stack);
            if(ret == MMI_TRUE)
            {
                //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
            }
            else
            {
                if(mmi_audply_walk_get_next_backwards_folder(folder_path, active_stack) == MMI_TRUE)
                {
                    //return mmi_audply_walk_get_next_folder_media_file(folder_path, active_stack, 0);
                    return AUDPLY_WALK_FOLDER_RESULT_CONTINUE;
                }
                else
                {
                    return AUDPLY_WALK_FOLDER_RESULT_FAIL;
                }
            }
        }
    }

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_next_folder_media_file
 * DESCRIPTION
 *   Get next media file folder  for press next
 * PARAMETERS
 *  file_path : [In] Current file path
 *  Stack : [In] Current file path stack info
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_walk_get_next_folder_media_file(CHAR* folder_path, mmi_audply_walk_stack_node_struct *active_stack, S32 Index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                         */
    /*----------------------------------------------------------------*/
    mmi_audply_walk_folder_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        result = mmi_audply_walk_folder(folder_path, active_stack, Index);
        Index = 0;
    } while (result == AUDPLY_WALK_FOLDER_RESULT_CONTINUE);

    return (MMI_BOOL)result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_next_media_file
 * DESCRIPTION
 *   Get next media file for press next
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_walk_get_next_media_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                         */
    /*----------------------------------------------------------------*/
    S32 return_value, index;
    FS_DOSDirEntry file_info;    
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1] = {0};
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_stack_node_struct* stack = g_audply.walk.stack;
    #else
    mmi_audply_walk_stack_node_struct* stack = g_btbox_audply.walk.stack;
    #endif
    MMI_BOOL ret;
    CHAR *last_backlash;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif

    mmi_ucs2cpy((CHAR *)temp_path, (CHAR*)this->path_cache);
    
    this->searching = MMI_TRUE;
    
    if(this->search_handle != -1)  //Current file not closed
    {
        return_value = FS_FindNextN(
                                this->search_handle,
                                    audio_pattern_array,
                                pattern_array_size,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);

        if(return_value >= FS_NO_ERROR  && !(file_info.Attributes & FS_ATTR_DIR)) //Found
        {
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            mmi_ucs2cpy((CHAR*)this->filefullname, (CHAR*)temp_path);
            //mmi_audply_walk_save_record((CHAR*)temp_path);
            this->searching = MMI_FALSE;
            this->total++;
            return MMI_TRUE;
        }
        else if(return_value >= FS_NO_ERROR  && (file_info.Attributes & FS_ATTR_DIR)) //No Media file, Only folder
        {
            FS_FindClose(this->search_handle);
            this->search_handle = -1;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)buf_file_name);
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            
            ret = mmi_audply_walk_get_next_folder_media_file((CHAR *)temp_path, stack, 0);

            if(ret == MMI_TRUE)
            {
                this->total++;
                mmi_ucs2cpy((CHAR*)this->filefullname, (CHAR*)temp_path);
                //mmi_audply_walk_save_record((CHAR*)temp_path);
                this->searching = MMI_FALSE;
                last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                MMI_ASSERT(last_backlash != NULL);

                *(last_backlash + 1) = 0;
                *last_backlash = 0;
                mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)temp_path);
                return MMI_TRUE;
            }
            else
            {
                this->searching = MMI_FALSE;
                return MMI_FALSE;
            }
        }
        else
        {
            FS_FindClose(this->search_handle);
            this->search_handle = -1;
            
            //ret = mmi_audply_walk_get_first_folder((CHAR *)temp_path, stack);

            //if(ret == MMI_FALSE)

            if(stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY-1].fs_index!= 0 || (ret = mmi_audply_walk_get_first_folder((CHAR *)temp_path, stack)) == MMI_FALSE)
            {
                if(mmi_audply_walk_get_next_backwards_folder((CHAR *)temp_path, stack) == MMI_TRUE)
                {
                    ret =  mmi_audply_walk_get_next_folder_media_file((CHAR *)temp_path, stack, 0);

                    if(ret == MMI_TRUE)
                    {
                        this->total++;
                        mmi_ucs2cpy((CHAR*)this->filefullname, (CHAR*)temp_path);
                        //mmi_audply_walk_save_record((CHAR*)temp_path);
                        this->searching = MMI_FALSE;
                        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                        MMI_ASSERT(last_backlash != NULL);

                        *(last_backlash + 1) = 0;
                        *last_backlash = 0;
                        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                        mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)temp_path);
                        
                        return MMI_TRUE;
                    }
                    else
                    {
                        this->searching = MMI_FALSE;
                        return MMI_FALSE;
                    }
                }
                else
                {
                    this->searching = MMI_FALSE;
                    return MMI_FALSE;
                }
            }
            //else
            else if (ret == MMI_TRUE)
            {
                ret = mmi_audply_walk_get_next_folder_media_file((CHAR *)temp_path, stack, 0);

                if(ret == MMI_TRUE)
                {
                    this->total++;
                    mmi_ucs2cpy((CHAR*)this->filefullname, (CHAR*)temp_path);
                    //mmi_audply_walk_save_record((CHAR*)temp_path);
                    
                    this->searching = MMI_FALSE;
                    last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
                    MMI_ASSERT(last_backlash != NULL);

                    *(last_backlash + 1) = 0;
                    *last_backlash = 0;
                    mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
                    mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)temp_path);

                    return MMI_TRUE;
                }
                else
                {
                    this->searching = MMI_FALSE;
                    return MMI_FALSE;
                }
            }
        }
    }
    else
    {
    #ifndef __MMI_BTBOX_NOLCD__
        if(Press_Prev == 0 || this->total == 0)
        #else
        if(Press_Prev == 0)
        #endif 
        {
            index = cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index;
        }
        else
        {
            index = cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index+1;
        }
        
        ret =  mmi_audply_walk_get_next_folder_media_file((CHAR *)temp_path, stack, index);
        
        if(ret == MMI_TRUE)
        {
            this->total++;
            mmi_ucs2cpy((CHAR*)this->filefullname, (CHAR*)temp_path);
            //mmi_audply_walk_save_record((CHAR*)temp_path);
            this->searching = MMI_FALSE;
            last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);

            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
            mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)temp_path);
            return MMI_TRUE;
        }
        else
        {
            this->searching = MMI_FALSE;
            return MMI_FALSE;
        }
        
    }
    
}

//////////////////////////////////////////////////
//static void mmi_audply_walk_search_internal(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_cache_set_caching_state
 * DESCRIPTION
 *   Set Caching state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_cache_set_caching_state(void)
{
    cache_int_struct.cache_state = AUDPLY_WALK_CACHE_STATE_CACHING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_cache_do_validation
 * DESCRIPTION
 *   Do cache validation
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_audply_cache_validation_result mmi_audply_cache_do_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_walk_record_struct walk_record;
    S16 error;
    S16 cache_number, Index;
    FS_HANDLE file_handle;
    S16 footer;
    S16 i,j;
    CHAR *File_path = NULL;
    FS_DOSDirEntry file_info;  
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type temp_path2[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_walk_stack_node_struct *stack;
    CHAR *last_backlash;
    U8 pattern_array_size = sizeof(audio_pattern_array) / sizeof(FS_Pattern_Struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    
    //wait FS ready to validate
    if(this->search_handle != -1)
    {
        FS_FindClose(this->search_handle);
        this->search_handle = -1;
    }
    
    //gui_cancel_timer(mmi_audply_cache_do_validation);
    StopTimer(AUDIO_PLAYER_DO_CACHE_TIMER);
    if (FS_GetDevStatus((U8)MMI_AUDPLY_WALK_DEFAULT_PATH, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        //gui_start_timer(500, mmi_audply_cache_do_validation);
        StartTimer(AUDIO_PLAYER_DO_CACHE_TIMER, 500, mmi_audply_cache_do_validation);
        return CACHE_VALIDATION_FAIL;
    }
       
    //first cancel temp cache work if exist
    Press_Prev = 2;
    memset(&cache_temp_struct, 0, sizeof(audply_walk_cache_int_temp_struct));
    srv_plc_audply_cancel_work(PLC_WORK_LOAD_CACHE);

    /*check break point*/
    ReadRecord(NVRAM_EF_AUDPLY_WALK_LID,1,(void*)&walk_record,sizeof(mmi_audply_walk_record_struct), &error);
    if (!mmi_audply_walk_is_audio_file((CHAR*)walk_record.current_path))
    {
        memset(walk_record.current_path, 0, sizeof(walk_record.current_path));
    }
    if(error != NVRAM_READ_SUCCESS)
    {
        srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
        walk_record.stack_index = 0xFF;
        WriteRecord(NVRAM_EF_AUDPLY_WALK_LID, 1, (void*)&walk_record, sizeof(mmi_audply_walk_record_struct), &error);
        //reset cache
        mmi_audply_walk_cache_init();
        this->total = 0;
        return CACHE_VALIDATION_BREAK_POINT_NOT_EXIST;
    }
    file_handle = FS_Open(walk_record.current_path, FS_READ_ONLY);
    if(file_handle < FS_NO_ERROR)
    {
        kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
        if(this->search_handle != -1)
        {
            this->search_handle = -1;
            FS_Close(this->search_handle);
        }
        this->stack_index = 0;
        srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
        walk_record.stack_index = 0xFF;
        WriteRecord(NVRAM_EF_AUDPLY_WALK_LID, 1, (void*)&walk_record, sizeof(mmi_audply_walk_record_struct), &error);
        //reset cache
        mmi_audply_walk_cache_init();
        this->total = 0;
        return CACHE_VALIDATION_BREAK_POINT_NOT_EXIST;
    }
    FS_Close(file_handle);
    /*check break point done*/
    mmi_audply_walk_get_stack_info_by_path_ext((CHAR *)walk_record.current_path, this->stack);
    /*check cache status*/
    if(cache_int_struct.cache_state != AUDPLY_WALK_CACHE_STATE_FINISH)
    {
        srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
        cache_int_struct.Cache_footer_index = 0;
        cache_int_struct.Cache_header_index = 0;
        //reset cache
        mmi_audply_walk_cache_init();
        File_path = mmi_audply_query_cache_cntx_pointer();
        stack = mmi_audply_query_cache_cntx_stack_pointer();
        mmi_ucs2cpy((CHAR *)File_path, (CHAR *)walk_record.current_path);
        memcpy(stack, &walk_record.stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
        Press_Prev = 0;
        plcache_audply_new_cache((CHAR *)File_path, stack);
        this->correcting_stack = MMI_TRUE;
        return CACHE_VALIDATION_FAIL;
    }    
    /*check cache status done*/
    
    /*check file number*/
    /*check file number done*/
    
    /*check if files in cache exist*/
    footer = cache_int_struct.Cache_footer_index;
    cache_number = (cache_int_struct.Cache_header_index + MMI_AUDPLY_CACHE_NUM
        - footer)%MMI_AUDPLY_CACHE_NUM;
    for(i = 0;i < cache_number; i++)
    {
        Index = cache_int_struct.Cache_header_index - i;

        if(Index < 0)
        {
            Index = Index + MMI_AUDPLY_CACHE_NUM;
        }

        mmi_ucs2cpy((CHAR*)temp_path, (CHAR *)cache_int_struct.cache_buffer[Index].Cache_file_path);
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        last_backlash += 2;
        mmi_ucs2cpy((CHAR *)temp_path2, last_backlash);
        last_backlash -= 2;
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");
        
        file_handle = FS_FindFirstN(
                    (PU16)temp_path,
                    audio_pattern_array,
                    pattern_array_size,
                    0,    /* only search media files in this phase. */
                    0,
                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                    &file_info,
                    (PU16)buf_file_name,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    cache_int_struct.cache_buffer[Index].FS_Index,
                    FS_FIND_DEFAULT);
        if(file_handle < FS_NO_ERROR)  //File not exist
        {
            srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
            //reset cache
            mmi_audply_walk_cache_init();
            File_path = mmi_audply_query_cache_cntx_pointer();
            stack = mmi_audply_query_cache_cntx_stack_pointer();
            mmi_ucs2cpy((CHAR *)File_path, (CHAR *)walk_record.current_path);
            memcpy(stack, &walk_record.stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
            Press_Prev = 0;
            plcache_audply_new_cache((CHAR *)File_path, stack);
            this->correcting_stack = MMI_TRUE;
            return CACHE_VALIDATION_FAIL;
        }
        else
        {
            if(mmi_ucs2cmp((CHAR *)temp_path2, (CHAR *)buf_file_name) != 0)
            {
                FS_FindClose(file_handle);
                srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
                //reset cache
                mmi_audply_walk_cache_init();
                File_path = mmi_audply_query_cache_cntx_pointer();
                stack = mmi_audply_query_cache_cntx_stack_pointer();
                    mmi_ucs2cpy((CHAR *)File_path, (CHAR *)walk_record.current_path);
                memcpy(stack, &walk_record.stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
                Press_Prev = 0;
                plcache_audply_new_cache((CHAR *)File_path, stack);
                this->correcting_stack = MMI_TRUE;
                return CACHE_VALIDATION_FAIL;
            }
        }
        FS_FindClose(file_handle);
    }
    /*check if files in cache exist done*/

    /*do some additional test*/
    return CACHE_VALIDATION_SUCCESS;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_audply_walk_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        default:
            break;    
    }
    return MMI_RET_OK;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_add_cache
 * DESCRIPTION
 *  add cache to head
 *  head can loop while cache is full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_walk_add_cache(UI_character_type *filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_audply_walk_is_audio_file((CHAR*)filefullname) || mmi_ucs2cmp((CHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path, (CHAR*)filefullname) == 0)
        return;
    
    index = cache_int_struct.Cache_header_index;
    cache_int_struct.Cache_header_index ++;
    if(cache_int_struct.Cache_header_index >= MMI_AUDPLY_CACHE_NUM)
    {
        cache_int_struct.Cache_header_index -= MMI_AUDPLY_CACHE_NUM;
    }

    if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index)
    {
        cache_int_struct.Cache_footer_index++;
        if(cache_int_struct.Cache_footer_index >= MMI_AUDPLY_CACHE_NUM)
        {
            cache_int_struct.Cache_footer_index = cache_int_struct.Cache_footer_index - MMI_AUDPLY_CACHE_NUM;
        }
    }
    mmi_ucs2cpy((CHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path, (CHAR*)filefullname);

    if(cache_int_struct.Cache_footer_index != index)
    {
        if(mmi_audply_walk_cache_comp_file_folder((CHAR *)filefullname, (CHAR *)cache_int_struct.cache_buffer[index].Cache_file_path) == MMI_TRUE)
        {
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index =
            cache_int_struct.cache_buffer[index].FS_Index + 1;
        }
        else  //Not the same folder 
        {
            cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = 0;
        }
    }
    else
    {
        cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WALK_ADD_CACHE, cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].FS_Index,
        cache_int_struct.Cache_footer_index, cache_int_struct.Cache_header_index, cache_int_struct.Cache_index, cache_int_struct.cache_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_cache
 * DESCRIPTION
 *  create cache when first enter or cache 101-200 when user switch previous 100 times
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_walk_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_search_cache
 * DESCRIPTION
 *  add cache to head
 * PARAMETERS
 *  filefullname  [OUT]  the result filefullname
 * RETURNS
 *  MMI_BOOL   cache of this index exists or not
 *****************************************************************************/
static MMI_BOOL mmi_audply_walk_search_cache(U8 *filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(cache_int_struct.Cache_header_index == cache_int_struct.Cache_footer_index) //Cache is empty
    {
        return MMI_FALSE;
    }
    else
    {
        Index = cache_int_struct.Cache_header_index - 1;
        if(Index < 0)
        {
            Index += MMI_AUDPLY_CACHE_NUM;
        }
        
        if(Index == cache_int_struct.Cache_footer_index) //Cache is empty
        {
            return MMI_FALSE;
        }
        cache_int_struct.Cache_header_index = Index;
        mmi_ucs2cpy((CHAR*)filefullname, (CHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path);
        return MMI_TRUE;
    }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_update_stack
 * DESCRIPTION
 *  need to update all the stack info
 * PARAMETERS
 *  stack  [OUT]  mmi_audply_walk_stack_node_struct stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_update_stack(mmi_audply_walk_stack_node_struct *stack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    memcpy((void*)&(this->stack), (void*)stack, sizeof(mmi_audply_walk_stack_node_struct)*MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY);
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_search_cancel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_search_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    //ClearProtocolEventHandler(MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
        this->search_handle = -1;
    }

    this->searching = MMI_FALSE;
    this->total = 0;
    memset(&cache_temp_struct, 0, sizeof(audply_walk_cache_int_temp_struct));
    srv_plc_audply_cancel_work(PLC_WORK_LOAD_CACHE);
    srv_plc_audply_cancel_work(PLC_WORK_NEW_CACHE);
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_reset_context();
    #else
    audply_btbox_data.filefullname[0] = 0;
    #endif

    #if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);
    }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_next_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_audply_walk_get_next_confirm_callback(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                //clear filename
                if (this->filefullname != NULL)
                {
                    this->filefullname[0] = 0;
                }
                mmi_audply_walk_cache_init();
                mmi_audply_walk_reset();
                kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
                this->search_handle = -1;
                this->stack_index = 0;
                this->total = 0;
                Press_Prev = 2;
                this->auto_walk_done = MMI_FALSE;
                is_in_confirm_popup = MMI_FALSE;
                break;
            }
            case MMI_ALERT_CNFM_NO:
            {
                GoBackHistory();
                is_in_confirm_popup = MMI_FALSE;
                break;
            }
            case MMI_POPUP_INTERRUPT_EXIT:
            case MMI_ALERT_CNFM_CANCEL:
            {
                is_in_confirm_popup = MMI_FALSE;
                break;
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_get_prev(U8 *filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S16 index, temp_index;
    mmi_audply_walk_stack_node_struct stack[MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY];
    CHAR *last_backlash;
    CHAR *File_path;
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    if (!g_audply.in_main_screen)
        return MMI_FALSE;
    #endif

    #ifndef __MMI_BTBOX_NOLCD__
    if (this->searching && cache_int_struct.cache_state != AUDPLY_WALK_CACHE_STATE_FINISH)
    {
        mmi_popup_display_ext(
                    STR_GLOBAL_PLEASE_WAIT, 
                    MMI_EVENT_FAILURE,
                    NULL);
        return MMI_FALSE;
    }
    #endif

    if (FS_GetDevStatus((U8)MMI_AUDPLY_WALK_DEFAULT_PATH, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

    this->filefullname = filefullname;

    ret = mmi_audply_walk_search_cache(this->filefullname);

    if(ret == MMI_TRUE)   //Get cache
    {
        if(this->search_handle != -1)
        {
            FS_FindClose(this->search_handle);
            this->search_handle = -1;
        }

        /*Work for next*/
        Press_Prev = 1;

        if(cache_int_struct.Cache_header_index > cache_int_struct.Cache_footer_index)
        {
            index = cache_int_struct.Cache_header_index - cache_int_struct.Cache_footer_index;
        }
        else
        {
            index = cache_int_struct.Cache_header_index + MMI_AUDPLY_CACHE_NUM - cache_int_struct.Cache_footer_index;
        }

        index = MMI_AUDPLY_CACHE_NUM - index;

        temp_index = cache_int_struct.Cache_header_index + 1;

        if(temp_index >=  MMI_AUDPLY_CACHE_NUM)
        {
            temp_index -= MMI_AUDPLY_CACHE_NUM;
        }

        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path);
        mmi_audply_walk_save_record((CHAR*)temp_path);
        last_backlash = mmi_ucs2rchr((CHAR*)temp_path, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 2) = 0;
        *(last_backlash + 3) = 0;

        mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR *)temp_path);
        
        mmi_audply_walk_get_stack_info_by_path_ext((CHAR*)temp_path, stack);
        mmi_audply_walk_update_stack(stack);
    
        if(cache_temp_struct.cache_state == AUDPLY_WALK_CACHE_STATE_FINISH  &&
           (index >= MMI_AUDPLY_RECACHE_NUM) &&
           (cache_temp_struct.Cache_footer_index != cache_temp_struct.Cache_header_index))
        {
            mmi_audply_copy_temp_to_cache();
        }

        
        if((cache_temp_struct.Cache_footer_index == cache_temp_struct.Cache_header_index) &&
           (cache_temp_struct.cache_state != AUDPLY_WALK_CACHE_STATE_CACHING))
        {
            File_path = mmi_audply_query_temp_cache_cntx_pointer();
            cache_temp_struct.cache_state = AUDPLY_WALK_CACHE_STATE_CACHING;
            plcache_audply_load_cache(File_path);
        }

        return MMI_TRUE;
    }
    else
    {
        if (this->total > 0)
        {
            //stop it first
            #ifndef __MMI_BTBOX_NOLCD__
            mmi_audply_stop_playing();
            
            mmi_popup_display_ext(
                        STR_ID_AUDPLY_FIRST_HINT, 
                        MMI_EVENT_FAILURE,
                        NULL);
            #else
            //mmi_audply_btbox_stop_action();
            mmi_audply_btbox_stop_playing();
            #endif
        }
        else
        {
            //is_in_no_audio_popup = MMI_TRUE;
            #ifndef __MMI_BTBOX_NOLCD__
            this->filefullname[0] = 0;
            g_audply.title[0] = 0;
            mmi_popup_display_ext(
                        STR_ID_AUDPLY_ERR_NO_AUDIO_FILE, 
                        MMI_EVENT_FAILURE,
                        NULL);
            #endif
        }
        
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_get_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_walk_get_next(U8 *filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MMI_BOOL search_again;
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WALK_GET_NEXT, this->searching, cache_int_struct.cache_state, this->auto_walk_done, is_in_confirm_popup);

    #ifndef __MMI_BTBOX_NOLCD__
    if(is_in_confirm_popup == MMI_TRUE)
        return MMI_FALSE;
    
    if (this->searching && cache_int_struct.cache_state != AUDPLY_WALK_CACHE_STATE_FINISH)
    {
        mmi_popup_display_ext(
                    STR_GLOBAL_PLEASE_WAIT, 
                    MMI_EVENT_FAILURE,
                    NULL);
        return MMI_FALSE;
    }
    #endif

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    if (FS_GetDevStatus((U8)MMI_AUDPLY_WALK_DEFAULT_PATH, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

    this->filefullname = filefullname;

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    do {
        ret = mmi_audply_walk_get_next_media_file();
        if (ret == MMI_TRUE)
        {
            if (!mmi_audply_walk_is_audio_file(this->filefullname))
            {
                this->total--;
                search_again = MMI_TRUE;
            }
            else if (this->auto_walk_done &&
                mmi_ucs2cmp((CHAR*)cache_int_struct.cache_buffer[cache_int_struct.Cache_header_index].Cache_file_path, (CHAR*)this->filefullname) == 0)
            {
                search_again = MMI_TRUE;
            }
            else
            {
                search_again = MMI_FALSE;
            }
        }
        else
        {
            search_again = MMI_FALSE;
        }
    } while (search_again);
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WALK_GET_NEXT_RESULT, this->stack_index, this->stack[0].fs_index, 
        this->stack[1].fs_index, this->stack[2].fs_index, this->stack[3].fs_index, this->stack[4].fs_index);
    
    if (ret == MMI_TRUE)
    {
        mmi_audply_walk_save_record((CHAR*)this->filefullname);

    #ifndef __MMI_BTBOX_NOLCD__
        if (Press_Prev != 0)
        {
            mmi_audply_walk_add_cache((UI_character_type*)this->filefullname);
        }
    #else
        {
            mmi_audply_walk_add_cache((UI_character_type*)this->filefullname);
        }
    #endif
    }

    if(Press_Prev == 0)   //Just for add cache
    {
        Press_Prev = 2;
    }
    //mmi_service_search_prev_folder(g_audply.walk.stack, MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY, NULL);

#ifndef __MMI_BTBOX_NOLCD__
    if(ret == MMI_FALSE)
    {
        //stop it first
        mmi_audply_stop_playing();
        
        if (this->total > 0)
        {   
            mmi_confirm_property_struct arg;
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
            arg.softkey[0].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_YES));
            arg.softkey[2].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_NO));
            arg.callback = (mmi_proc_func)mmi_audply_walk_get_next_confirm_callback;
            mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_AUDPLY_LAST_HINT)), MMI_EVENT_QUERY, &arg);
            is_in_confirm_popup = MMI_TRUE;
        }
        else
        {
            //is_in_no_audio_popup = MMI_TRUE;
            this->filefullname[0] = 0;
            g_audply.title[0] = 0;
            mmi_popup_display_ext(
                        STR_ID_AUDPLY_ERR_NO_AUDIO_FILE, 
                        MMI_EVENT_FAILURE,
                        NULL);
        }
        
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
#else
    return ret;
#endif
}

//CHAR buf_test[256] = L"E:\Records\Copy of Copy of A\5.mp3";


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_walk_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_walk_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    mmi_audply_walk_record_struct walk_record;
    S16 error;
    U16 stack_size = sizeof(mmi_audply_playlist_stack_node_struct) * MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetProtocolEventHandler(mmi_audply_walk_search_internal, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    mmi_audply_walk_reset();

    //mmi_audply_walk_cache_do_validtion_check_bootup();

    //read play by record
    #ifndef __MMI_BTBOX_NOLCD__
    ReadValue(NVRAM_AUDPLY_PLAY_STYLE, &g_audply.play_style, DS_BYTE, &error);

    //just to make sure only file order style use in BTBox
    if (g_audply.play_style != AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        g_audply.play_style = AUDPLY_PLAY_STYLE_BY_FILE_ORDER;
        WriteValue(NVRAM_AUDPLY_PLAY_STYLE, &g_audply.play_style, DS_BYTE, &error);
    }
    #endif

    //read record and init
    ReadRecord(NVRAM_EF_AUDPLY_WALK_LID, 1, (void*)&walk_record, sizeof(mmi_audply_walk_record_struct), &error);
    if (!mmi_audply_walk_is_audio_file((CHAR*)walk_record.current_path))
    {
        memset(walk_record.current_path, 0, sizeof(walk_record.current_path));
    }
    if (walk_record.current_path[0] != 0 && FS_Open((WCHAR *)walk_record.current_path, FS_READ_ONLY) >= FS_NO_ERROR &&
        walk_record.stack_index < MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY)
    {
        memcpy(this->stack, &walk_record, stack_size);
        this->stack_index = walk_record.stack_index;
        //if (walk_record.current_path[0] != 0)
        {
            CHAR* last_backlash = NULL;
            
            /* update path cache. */
            last_backlash = mmi_ucs2rchr((CHAR*)walk_record.current_path, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 2) = 0;
            *(last_backlash + 3) = 0;
            //*last_backlash = 0;
            mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)walk_record.current_path);
            this->search_handle = -1;

            //cache
            
        }
    }
    else
    {
        kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
        this->search_handle = -1;
        this->stack_index = 0;
    }

    Press_Prev = 2;
    is_in_confirm_popup = MMI_FALSE;

    #ifdef __MMI_BTBOX_NOLCD__
    this->filefullname = (U8*)audply_btbox_data.filefullname;
    g_btbox_audply.new_play_time = 0;
    #endif
    //is_in_no_audio_popup = MMI_FALSE;
    //mmi_audply_walk_cache_init();
    //mmi_audply_walk_cache_new_cache();
    //mmi_audply_walk_cache_do_test();
    //mmi_audply_walk_cache_do_validtion_stack(NULL,walk_record.stack);
}

#ifdef __MMI_BTBOX_NOLCD__

#define MMI_AUDPLY_CARAOKE_SUPPORT_3KEY
#define DELAY_PLAY_TIME 100
#define MMI_BTBOX_ERROR_CHECK_DURA 50

static FS_Pattern_Struct audio_pattern_karaoke_array[] = 
{
#ifdef DAF_DECODE
    {L"*.mp3"},
#ifdef MUSICAM_DECODE
    {L"*.mp2"},
#endif    
#endif
    {L"*.wav"},
#ifdef __FLAC_DECODE__
    {L"*.flac"},
#endif
#ifdef AAC_DECODE
    {L"*.aac"},
#endif 

};


void mmi_audply_btbox_play_action();
void mmi_audply_btbox_play_pause_action();
void mmi_audply_btbox_do_resume_action(void);
void mmi_audply_btbox_launch();
void mmi_audply_btbox_init_volume();
void mmi_audply_btbox_exit();
MMI_BOOL mmi_audply_btbox_support_karaoke(CHAR *filename);
MMI_BOOL mmi_audply_btbox_background_callback_hdlr(mdi_result result, void *user_data);
void mmi_audply_btbox_resume(void);
void mmi_audply_btbox_pause_action();
void mmi_audply_btbox_get_prev();
void mmi_audply_btbox_get_next();


#ifdef __MMI_A2DP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  btbox_a2dp_is_output_to_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    returns if a2dp currently could and should be available
 *****************************************************************************/
MMI_BOOL btbox_a2dp_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_power_on = MMI_FALSE;
    MMI_BOOL in_flight_mode = MMI_FALSE;
    MMI_BOOL output_to_bt = MMI_FALSE;
	MMI_BOOL dev_cap=MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_DIALER_SUPPORT__)
    if(!srv_a2dp_is_output_to_bt())
    {
        return MMI_FALSE;
    }
#endif

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_is_wait_open_bt
 * DESCRIPTION
 *  return if it's waiting for opening bt
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_btbox_is_wait_open_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return audply_btbox_data.wait_open_bt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_bt_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_codec      [IN]
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_bt_stop(MMI_BOOL stop_codec, MMI_BOOL notify_opener) //bql: dummy para of stop_codec
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* always stop codec*/
    if( btbox_a2dp_is_output_to_bt() )
    {
        av_bt_close_codec();
        av_bt_close(notify_opener);
    }
    audply_btbox_data.wait_open_bt = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_bt_open_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL prev_wait_open_bt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_wait_open_bt = audply_btbox_data.wait_open_bt;

    audply_btbox_data.wait_open_bt = MMI_FALSE;

    switch (result)
    {
    case AV_BT_CALLBACK_EVENT_OPEN_OK:
        if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
        {
            av_bt_open_codec(KAL_TRUE);      
        }
        else
        {
            av_bt_open_codec(KAL_FALSE); //bql: i do not get the reason why open_codec first but clos_codec again if STATE is IDLE
        
            if (audply_btbox_data.to_resume && 
				audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
            {
                audply_btbox_data.to_resume = KAL_FALSE;
                mmi_audply_btbox_do_resume_action();
            }
            else
            {   //bql: what if (g_audply.state == STATE_IDLE) ? Do we also need to do_play_action?
                audply_btbox_data.to_resume = KAL_FALSE;
                mmi_audply_btbox_play_action();
            }
            if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_IDLE)
            {
                av_bt_close_codec();
            }
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
    case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    case AV_BT_CALLBACK_EVENT_OPEN_SCO:
#endif
        if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
        {
            av_bt_close_codec();
        }
        else if (audply_btbox_data.to_resume)
        {
            ASSERT(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE);
            audply_btbox_data.to_resume = KAL_FALSE;                            
            mmi_audply_btbox_do_resume_action();
        }
        else
        {
            mmi_audply_btbox_play_action();
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
        mmi_audply_btbox_bt_stop(KAL_TRUE, KAL_FALSE);
        audply_btbox_data.to_resume = KAL_FALSE;     
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
    case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
        {
            av_bt_close_codec();
        }
        else if (prev_wait_open_bt == MMI_TRUE)
        {
            if (audply_btbox_data.to_resume && 
				audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
            {
                audply_btbox_data.to_resume = KAL_FALSE;                             
                mmi_audply_btbox_do_resume_action();
            }
            else
            {
                mmi_audply_btbox_play_action();
            }
        }    
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY && 
			btbox_a2dp_is_output_to_bt())
        {
            audply_btbox_data.wait_open_bt = MMI_TRUE;
            av_bt_open((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), 
				        audply_btbox_data.filefullname, 
                        mmi_audply_btbox_bt_open_callback, 
                        KAL_FALSE,
                        KAL_TRUE);
        }
        else
        {
            av_bt_close(KAL_FALSE);
        }
        break;
    case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        if (mmi_a2dp_is_output_to_bt() && av_bt_is_streaming() &&
            audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
        {
            mmi_audply_btbox_pause_action();
            if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
            {
                av_bt_close_codec();
            }
            if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
            {
                audply_btbox_data.to_resume = KAL_TRUE;
                av_bt_pause();
            }
        }
        break;
    case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
        if (audply_btbox_data.to_resume)
        {
            if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
            {
                mmi_audply_btbox_resume();
            }
            else if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_IDLE && 
				     !audply_btbox_data.wait_open_bt)
            {
                av_bt_close(KAL_FALSE);
            }
        }
        break;
    }
}

#endif


#ifdef __MMI_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_audply_btbox_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_get_active_id()!= GRP_ID_AUDPLY_MAIN)
    {
        return result;
    }
   
    if (key_events == MMI_AVRCP_KEY_CANCELED)
    {
        /*the return value do not mean anything in key canceled event*/
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }

    if (audply_btbox_data.filefullname[0] == 0)
    {
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }
	
    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                if(audply_btbox_data.is_processing_karaoke == MMI_TRUE)
                {
                    //mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PROCOSSING, NULL);
                    return MMI_RET_OK;
                }
				if(((audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY) && (command == MMI_AVRCP_POP_PAUSE)) ||
					((audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE) && (command == MMI_AVRCP_POP_PLAY)))
                  mmi_audply_btbox_play_pause_action();
            }
            break;

        case MMI_AVRCP_POP_STOP:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_btbox_stop_playing();
            }
            break;

        case MMI_AVRCP_POP_FORWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
                if(audply_btbox_data.wait_next == MMI_FALSE)
			    {
                    mmi_audply_btbox_get_next();
			    }
            }
            break;

        case MMI_AVRCP_POP_BACKWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
				if(audply_btbox_data.wait_next == MMI_FALSE)
			    {
                    mmi_audply_btbox_get_prev();
			    }
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

avrcp_finish:

	return result;    
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 


static MMI_RET mmi_btbox_plug_in_audio_completed_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
       return;
    }
    
    if(mmi_frm_group_get_active_id()== GRP_ID_AUDPLY_MAIN)
    {
        mmi_audply_btbox_init_volume();
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_BT_AUDPLY, mmi_audply_btbox_background_callback_hdlr, NULL);

        if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
        {
               //BT Box Todo: Notify memory not insert
               MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_MEMORY_CARD_ERROR);
               mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND,NULL);
               return;
        }
    
        if(audply_btbox_data.filefullname[0] == 0) /*First entry*/
        {
            g_btbox_audply.new_play_time = 0;
            Press_Prev = 0;
            ret = mmi_audply_walk_get_next(this->filefullname);
            if(ret == MMI_FALSE)
            {
                //To Do: Add Notify, not any more music files
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_NO_MORE_FILE);
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC,NULL);
            }
            else
            {
                mmi_audply_btbox_play_pause_action();
            }
        }
        else
        {
            Press_Prev = 2;
            if(this->total == 0)
            {
                this->total++;
            }
            mmi_audply_btbox_play_pause_action();
            if(cache_int_struct.cache_state == AUDPLY_WALK_CACHE_STATE_FINISH)
            {
                if(cache_int_struct.Cache_header_index == 0 && cache_int_struct.Cache_footer_index == 0)
                {
                    mmi_audply_walk_add_cache(audply_btbox_data.filefullname);
                }
            }
        }
    }
    else
    {
        //mmi_audply_btbox_launch();
        mdi_audio_resume_background_play();
    }
    audply_btbox_data.is_init_done = MMI_TRUE;
}


void mmi_audply_btbox_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    mmi_input_event_notify_param param;
    g_btbox_audply.walk.auto_walk_done = MMI_FALSE;
    if(mmi_frm_group_get_active_id()== GRP_ID_AUDPLY_MAIN)
    {
        mmi_audply_cache_do_validation();
        param.aud_cb = mmi_btbox_plug_in_audio_completed_callback;
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PLUG_IN, &param);
    }
}


void mmi_audply_btbox_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    if(mmi_frm_group_get_active_id()== GRP_ID_AUDPLY_MAIN)
    {
        mmi_audply_btbox_exit();
        mmi_audply_walk_search_cancel_hdlr();
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PLUG_OUT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(audply_btbox_data.is_processing_karaoke == MMI_TRUE)
    {
        return;
    }
    
    if (audply_btbox_data.volume < MDI_AUD_VOL_EX_MUTE_MAX)
    {
        S16 error;
        audply_btbox_data.volume ++;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_INC_VOLUME, audply_btbox_data.volume, audply_btbox_data.play_state);

        if (audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_IDLE)
        {
#if 1 
            mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(audply_btbox_data.volume)));
#else
/* under construction !*/
#endif
        }

        WriteValueSlim(NVRAM_AUDPLY_VOLUME, &audply_btbox_data.volume, DS_BYTE);

        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_VOLUME_UP, NULL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(audply_btbox_data.is_processing_karaoke == MMI_TRUE)
    {
        return;
    }
    
    if (audply_btbox_data.volume > MDI_AUD_VOL_EX_MUTE_MIN)
    {
        S16 error;
        audply_btbox_data.volume--;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_DEC_VOLUME, audply_btbox_data.volume, audply_btbox_data.play_state);
          
        if (audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_IDLE)
        {
#if 1
            mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(audply_btbox_data.volume)));
#else
/* under construction !*/
#endif
        }

        WriteValueSlim(NVRAM_AUDPLY_VOLUME, &audply_btbox_data.volume, DS_BYTE);

        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_VOLUME_DOWN,NULL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_pause_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_btbox_pause_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_PAUSE)
    {
        return;
    }

    StopTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER);

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE;
            break;
        case MDI_AUDIO_TERMINATED:
            /* Stop file but let progress bar stop where it is */
            audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE;
            mdi_audio_stop_file();
            break;
        default:
            //audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE;
            break;
    } /* end switch */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_stop_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_btbox_stop_action();
#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
}


void mmi_audply_btbox_stop_action()
{
    audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE;
    StopTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER);
    mdi_audio_stop_file();
}


void mmi_audply_btbox_play_completed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE; 
	mmi_audply_btbox_stop_playing();
    /*if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
    {
        mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
    }*/
    
    if(audply_btbox_data.is_prev_press == MMI_TRUE)
    {
        ret = mmi_audply_walk_get_prev(this->filefullname);
    }
    else
    {
        ret = mmi_audply_walk_get_next(this->filefullname);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAY_COMPLETED, ret);
    if((ret == MMI_FALSE) &&(audply_btbox_data.is_prev_press == MMI_FALSE))
    {
        if (this->total > 0 && audply_btbox_data.is_play_success == MMI_TRUE)
        {
            if (this->filefullname != NULL)
            {
                this->filefullname[0] = 0;
            }
            mmi_audply_walk_cache_init();
            mmi_audply_walk_reset();
            this->filefullname = (U8*)audply_btbox_data.filefullname;
            kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
            this->search_handle = -1;
            this->stack_index = 0;
            this->total = 0;
            Press_Prev = 0;
            this->auto_walk_done = MMI_FALSE;
            mmi_audply_walk_get_next(this->filefullname);
            audply_btbox_data.wait_next = MMI_TRUE;
            StartTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER, 10, mmi_audply_btbox_play_pause_action);
            //mmi_audply_btbox_play_pause_action();
        }
        else
        {
            this->filefullname[0] = 0;
            mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC, NULL);
            //To Do: Notify no file
        }
    }
    else if((ret == MMI_FALSE) &&(audply_btbox_data.is_prev_press == MMI_TRUE))
    {
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_FIRST_FILE, NULL);
        audply_btbox_data.wait_next = MMI_TRUE;
        audply_btbox_data.is_prev_press = MMI_FALSE;
        StartTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER, 10, mmi_audply_btbox_play_pause_action);
        //mmi_audply_btbox_play_pause_action();
    }
    else
    {
        //mmi_audply_btbox_play_pause_action();
        audply_btbox_data.wait_next = MMI_TRUE;
        StartTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER, 10, mmi_audply_btbox_play_pause_action);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_btbox_play_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 error_time;
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAY_CALLBACK_HDLR, audply_btbox_data.play_state, result);
    /* ignore it */
    if (audply_btbox_data.play_state!= AUDPLY_WALK_BTBOX_STATE_PLAY)
    {
        return;
    }

    /* handle result */

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            if(audply_btbox_data.is_prev_press == MMI_TRUE)
            {
                audply_btbox_data.is_prev_press = MMI_FALSE;
            }
            g_btbox_audply.new_play_time = 0;
            mmi_audply_btbox_play_completed();
            break;
        case MDI_AUDIO_TERMINATED:
            StopTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER);
            mdi_audio_stop_file();
		#if defined(__MMI_A2DP_SUPPORT__)
            mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE); 
        #endif
            audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE; 
            break;
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
            mdi_audio_stop_file();
		#if defined(__MMI_A2DP_SUPPORT__)
            mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE); 
        #endif
            audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE; 
            break;
    #endif /* __DRM_SUPPORT__ */
        default:
            {
                StopTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER);
                g_btbox_audply.new_play_time = 0;
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_INVALID_ERROR, NULL);
                kal_get_time(&error_time);
                error_time = error_time - audply_btbox_data.Error_callback_time;
                audply_btbox_data.Error_callback_time = kal_ticks_to_milli_secs(error_time);
                if(audply_btbox_data.is_prev_press == MMI_TRUE &&
                   audply_btbox_data.Error_callback_time > MMI_BTBOX_ERROR_CHECK_DURA)
                {
                    audply_btbox_data.is_prev_press == MMI_FALSE;
                }
                
                mmi_audply_btbox_play_completed();
              //mdi_audio_stop_file();
                //audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE; 
            }
            break;
    }
}


void mmi_audply_btbox_get_play_time(void)
{
    mdi_audio_get_progress_time(&g_btbox_audply.new_play_time);
    StartTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER, 500, mmi_audply_btbox_get_play_time);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_KARAOKE_GET_PLAY_TIME, g_btbox_audply.new_play_time);
}


void mmi_audply_btbox_play()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_A2DP_SUPPORT__
	audply_btbox_data.to_resume = KAL_FALSE;
	if (btbox_a2dp_is_output_to_bt())
	{
		if (audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
		{
			mmi_audply_btbox_stop_action();
			av_bt_close_codec(); 
		}	 
		audply_btbox_data.wait_open_bt = MMI_TRUE;
		
		av_bt_open(
				(srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), 
				audply_btbox_data.filefullname, 
				mmi_audply_btbox_bt_open_callback, 
				KAL_FALSE, //bql: the meaning of this para (sbc_only)?
				KAL_TRUE);
	}
	else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        mmi_audply_btbox_play_action();
    }
}


void mmi_audply_btbox_play_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    mdi_result result;
    U8 volume = audply_btbox_data.volume;
    U32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_btbox_data.wait_next = MMI_FALSE;
    handle = DRM_open_file((PU16)audply_btbox_data.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WALK_PLAY_FILE, handle, audply_btbox_data.play_state);
    if (handle >= FS_NO_ERROR)
    {  
        DRM_close_file(handle);
    }
    else
    {
        if(audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_IDLE)
        {
            //mmi_audply_btbox_stop_action();
            mmi_audply_btbox_stop_playing();
        }
        return;
    }

    audply_btbox_data.is_support_pause = mdi_audio_is_file_seekable(audply_btbox_data.filefullname);

    mdi_audio_get_duration(audply_btbox_data.filefullname, &duration);

#ifdef __KARAOKE_SUPPORT__
    if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
    {
        mdi_audio_get_duration(audply_btbox_data.filefullname, &duration);
        mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE, NULL);
        kal_sleep_task(2);
        mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_PLAY_MIX_ONLY,NULL);
        
        if(audply_btbox_data.is_orignal_enable == MMI_TRUE)
        {
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
        }
        else
        {
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
        }
        
        if(audply_btbox_data.play_by_background != MMI_TRUE)
        {
            g_btbox_audply.new_play_time = 0;
        }
        audply_btbox_data.is_processing_karaoke = MMI_FALSE;
    }
#endif

    kal_get_time(&audply_btbox_data.Error_callback_time); 

    mdi_audio_suspend_background_play();
    
    result = mdi_audio_play_file_portion_with_vol_path(
                   audply_btbox_data.filefullname,
                   g_btbox_audply.new_play_time,
                   0,
                   DEVICE_AUDIO_PLAY_ONCE,
                   NULL,
                   mmi_audply_btbox_play_callback_hdlr,
                   NULL,
                      #if 1// && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
                   (U8)MDI_AUD_VOL_EX_MUTE(volume),
                   #else
/* under construction !*/
                   #endif
                   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_WALK_PLAY_RESULT, result, g_btbox_audply.new_play_time);
    if (result == MDI_AUDIO_SUCCESS)
    {
        /*if(audply_btbox_data.is_prev_press == MMI_TRUE)
        {
            audply_btbox_data.is_prev_press = MMI_FALSE;
        }*/
        audply_btbox_data.play_state= AUDPLY_WALK_BTBOX_STATE_PLAY;
        audply_btbox_data.is_play_success = MMI_TRUE;
        audply_btbox_data.need_resume_play = MMI_TRUE;
        StartTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER, 500, mmi_audply_btbox_get_play_time);
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_INVALID_ERROR, NULL);
        mmi_audply_btbox_play_completed();
    }
    else
    {
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_INVALID_ERROR, NULL);
        audply_btbox_data.play_state= AUDPLY_WALK_BTBOX_STATE_IDLE;
        mmi_audply_btbox_play_completed();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_btbox_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_A2DP_SUPPORT__
    if (btbox_a2dp_is_output_to_bt())
    {
        audply_btbox_data.to_resume = KAL_TRUE;
        audply_btbox_data.wait_open_bt = MMI_TRUE;
        av_bt_open((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), 
			        audply_btbox_data.filefullname, 
                    mmi_audply_btbox_bt_open_callback, 
                    KAL_FALSE,
                    KAL_TRUE);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        /* do resume action */
        mmi_audply_btbox_do_resume_action();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_btbox_do_resume_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_btbox_do_resume_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* In case it is muted by profile switching */
#if 1
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)MDI_AUD_VOL_EX_MUTE(audply_btbox_data.volume));
#else
/* under construction !*/
#endif /*__MMI_FTE_SUPPORT__*/

#ifdef __KARAOKE_SUPPORT__
    if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
    {
        mdi_audio_get_duration(audply_btbox_data.filefullname, &duration);
        mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE, NULL);
        kal_sleep_task(2);        
        mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_PLAY_MIX_ONLY,NULL);
        
        if(audply_btbox_data.is_orignal_enable == MMI_TRUE)
        {
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
        }
        else
        {
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
        }
        
        audply_btbox_data.is_processing_karaoke = MMI_FALSE;
    }
#endif

    result = mdi_audio_resume(mmi_audply_btbox_play_callback_hdlr, NULL);    

    if (result == MDI_AUDIO_SUCCESS)
    {
        audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_PLAY;
        StartTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER, 500, mmi_audply_btbox_get_play_time);
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        /* Play paused when file finished */
        mmi_audply_btbox_play_completed();
    }
    else
    {
        audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_IDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* do pause action */
	mmi_audply_btbox_pause_action();
#ifdef __MMI_A2DP_SUPPORT__
    if(btbox_a2dp_is_output_to_bt() )
    {
        if( audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_PLAY )
        {
            av_bt_close_codec();
            av_bt_close(KAL_FALSE);
        }
    }
#endif /* __MMI_A2DP_SUPPORT__ */
}


void mmi_audply_btbox_pause_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PAUSE_ACTION,audply_btbox_data.play_state,
              audply_btbox_data.wait_next,
              audply_btbox_data.is_support_pause);
    if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY &&
       !audply_btbox_data.wait_next)
    {
        if(audply_btbox_data.is_support_pause)
        {
            result = mdi_audio_pause(mmi_audply_btbox_pause_callback_hdlr, NULL);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PAUSE_RESULT,result);
            if (result == MDI_AUDIO_SUCCESS)
            {
                audply_btbox_data.play_state = AUDPLY_WALK_BTBOX_STATE_PAUSE;
            }
            else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
            {
                //mmi_audply_btbox_stop_action();
                mmi_audply_btbox_stop_playing();
            }
            else
            {
       
            }
        }
        else
        {
            //mmi_audply_btbox_stop_action();
			mmi_audply_btbox_stop_playing();
        }
        audply_btbox_data.need_resume_play = MMI_FALSE;
    }
}


void mmi_audply_btbox_play_pause_action()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY_PAUSE_ACTION,audply_btbox_data.play_state);
    audply_btbox_data.kacaroke_timer_enable = MMI_FALSE;
    StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_TIMER);
    StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
    if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
    {
        //mmi_audply_btbox_pause_action();
		mmi_audply_pause();
    }
    else if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
    {
        if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            if(mmi_audply_btbox_support_karaoke((CHAR *)audply_btbox_data.filefullname) == MMI_FALSE)
            {
                audply_btbox_data.is_kacaroke_enable = MMI_FALSE;
                audply_btbox_data.is_orignal_enable = MMI_FALSE;
                audply_btbox_data.is_processing_karaoke = MMI_FALSE;
                mmi_frm_input_event_notify_remove(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE);
				//mmi_audply_btbox_do_resume_action();
				mmi_audply_btbox_resume();
            }
            else
            {
				//mmi_audply_btbox_do_resume_action();
				mmi_audply_btbox_resume();
            }
        }
        else
        {
            //mmi_audply_btbox_do_resume_action();
			mmi_audply_btbox_resume();
        }
    }
    else
    {
        if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            if(mmi_audply_btbox_support_karaoke((CHAR *)audply_btbox_data.filefullname) == MMI_FALSE)
            {
                audply_btbox_data.is_kacaroke_enable = MMI_FALSE;
                audply_btbox_data.is_orignal_enable = MMI_FALSE;
                audply_btbox_data.is_processing_karaoke = MMI_FALSE;
                mmi_frm_input_event_notify_remove(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE);
                //mmi_audply_btbox_play_action();
                mmi_audply_btbox_play();
            }
            else
            {
                //mmi_audply_btbox_play_action();
				mmi_audply_btbox_play();
            }
        }
        else
        {
            //mmi_audply_btbox_play_action();
            mmi_audply_btbox_play();
        }
    }
    audply_btbox_data.play_by_background = MMI_FALSE;
}

void mmi_audply_btbox_get_prev()
{
    MMI_BOOL result;
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
       //BT Box Todo: Notify memory not insert
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_MEMORY_CARD_ERROR);
       mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND,NULL);
       return;
    }

    StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER);
    if (this->searching && cache_int_struct.cache_state != AUDPLY_WALK_CACHE_STATE_FINISH)
    {
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PROCOSSING,NULL);
        StartTimer(AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER, 100, mmi_audply_btbox_get_prev);
        return;
    }

    if(audply_btbox_data.is_processing_karaoke == MMI_TRUE)
    {
        return;
    }
    
    audply_btbox_data.is_prev_press = MMI_TRUE;
    g_btbox_audply.new_play_time = 0;
    
    if(audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_PLAY)
    {
        audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_IDLE;
		mmi_audply_btbox_stop_action();
#ifdef __MMI_A2DP_SUPPORT__
		mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
        if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            audply_btbox_data.is_processing_karaoke = MMI_TRUE;
            //mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        }
        result = mmi_audply_walk_get_prev((U8*)audply_btbox_data.filefullname);
        if(result == MMI_FALSE)
        {
            //To do: Notify first file
            if (this->total > 0 && audply_btbox_data.is_play_success == MMI_TRUE)
            {
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_FIRST_FILE, NULL);
            }
            else
            {
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC, NULL);
            }
            if(audply_btbox_data.filefullname[0] != 0)
            {
                mmi_audply_btbox_play_pause_action();
            }
            audply_btbox_data.is_processing_karaoke = MMI_FALSE;
        }
    }
    else
    {
        mmi_audply_btbox_stop_action();
#ifdef __MMI_A2DP_SUPPORT__
		mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
        if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            audply_btbox_data.is_processing_karaoke = MMI_TRUE;
            //mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        }
        result = mmi_audply_walk_get_prev((U8*)audply_btbox_data.filefullname);
        if(result == MMI_FALSE)
        {
            audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_IDLE;
            //To do: Notify first file
            if (this->total > 0 && audply_btbox_data.is_play_success == MMI_TRUE)
            {
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_FIRST_FILE, NULL);
            }
            else
            {
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC, NULL);
            }

            if(audply_btbox_data.filefullname[0] != 0)
            {
                mmi_audply_btbox_play_pause_action();
            }
            audply_btbox_data.is_processing_karaoke = MMI_FALSE;
        }
        else
        {
            mmi_audply_btbox_play_pause_action();
        }
    }
    
}


void mmi_audply_btbox_get_next()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
       //BT Box Todo: Notify memory not insert
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_MEMORY_CARD_ERROR);
       mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND,NULL);
       return;
    }

    StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER);
    if (this->searching && cache_int_struct.cache_state != AUDPLY_WALK_CACHE_STATE_FINISH)
    {
        mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PROCOSSING,NULL);
        StartTimer(AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER, 100, mmi_audply_btbox_get_prev);
        return;
    }

    if(audply_btbox_data.is_processing_karaoke == MMI_TRUE)
    {
        return;
    }
    
    g_btbox_audply.new_play_time = 0;
    audply_btbox_data.is_prev_press = MMI_FALSE;
    
    if(audply_btbox_data.play_state != AUDPLY_WALK_BTBOX_STATE_PLAY)
    {
        if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PAUSE)
        {
            mmi_audply_btbox_stop_action();
#ifdef __MMI_A2DP_SUPPORT__
		mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
        }
        else
        {
            StopTimer(AUDIO_PLAYER_PROGRESS_TIME_TIMER); 
        }
        audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_IDLE;
        //mmi_audply_btbox_stop_action();
        /*if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        }*/
        result = mmi_audply_walk_get_next(this->filefullname);
        if(result == MMI_FALSE)
        {
            if (this->total > 0 && audply_btbox_data.is_play_success == MMI_TRUE)
            {
                if (this->filefullname != NULL)
                {
                    this->filefullname[0] = 0;
                }
                mmi_audply_walk_cache_init();
                mmi_audply_walk_reset();
                this->filefullname = (U8*)audply_btbox_data.filefullname;
                kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
                this->search_handle = -1;
                this->stack_index = 0;
                this->total = 0;
                Press_Prev = 0;
                this->auto_walk_done = MMI_FALSE;
                mmi_audply_walk_get_next(this->filefullname);
            }
            else
            {
                this->filefullname[0] = 0;
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC, NULL);
                //To Do: Notify no file
            }
        }
    }
    else
    {
        mmi_audply_btbox_stop_action();
#ifdef __MMI_A2DP_SUPPORT__
		mmi_audply_btbox_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
        if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
        {
            audply_btbox_data.is_processing_karaoke = MMI_TRUE;
            //mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        }
        result = mmi_audply_walk_get_next(this->filefullname);
        if(result == MMI_FALSE)
        {
            if (this->total > 0 && audply_btbox_data.is_play_success == MMI_TRUE)
            {
                if (this->filefullname != NULL)
                {
                    this->filefullname[0] = 0;
                }
                mmi_audply_walk_cache_init();
                mmi_audply_walk_reset();
                this->filefullname = (U8*)audply_btbox_data.filefullname;
                kal_wsprintf(this->path_cache, "%c:\\", (CHAR)MMI_AUDPLY_WALK_DEFAULT_PATH);
                this->search_handle = -1;
                this->stack_index = 0;
                this->total = 0;
                Press_Prev = 0;
                this->auto_walk_done = MMI_FALSE;
                mmi_audply_walk_get_next(this->filefullname);
                mmi_audply_btbox_play_pause_action();
            }
            else
            {
                this->filefullname[0] = 0;
                mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC, NULL);
                //To Do: Notify no file
            }
        }
        else
        {
            mmi_audply_btbox_play_pause_action();
        }
    }
}

static MMI_RET mmi_btbox_audio_completed_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_KARAOKE_CB_RESULT, mmi_frm_group_get_active_id());
    StopTimer(AUDIO_PLAYER_KARAOKE_CB_TIMER);
    if(mmi_frm_group_get_active_id()== GRP_ID_AUDPLY_MAIN)
    {    
        //mmi_audply_play_with_karaoke();
        //StartTimer(AUDIO_PLAYER_KARAOKE_CB_TIMER, 100, mmi_audply_btbox_play_action);  
		StartTimer(AUDIO_PLAYER_KARAOKE_CB_TIMER, 100, mmi_audply_btbox_play);
          //mmi_audply_btbox_play_pause_action();
        return 0;
    }
}


MMI_BOOL mmi_audply_btbox_support_karaoke(CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    CHAR* dot;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || mmi_ucs2strlen(filename) < 3)
        return MMI_FALSE;


    dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot)
    {
        U8 i;
        U8 audio_pattern_array_size = sizeof(audio_pattern_karaoke_array) / sizeof(FS_Pattern_Struct);
        MMI_BOOL found = MMI_FALSE;
        
        dot += 2;
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        for (i = 0; i < audio_pattern_array_size; i++)
        {
            if (mmi_ucs2cmp((CHAR*)(audio_pattern_karaoke_array[i].Pattern+2), (CHAR*)file_ext) == 0)
            {
                found = MMI_TRUE;
                break;
            }
        }
        if (found)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


#ifdef __KARAOKE_SUPPORT__
static void mmi_audply_btbox_karaoke()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_input_event_notify_param param = {0};
    param.aud_cb = mmi_btbox_audio_completed_callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_audply_btbox_support_karaoke((CHAR *)audply_btbox_data.filefullname) == MMI_FALSE)
    {
        return;
    }
    
    if(audply_btbox_data.is_kacaroke_enable == MMI_FALSE)
    {
        audply_btbox_data.is_processing_karaoke = MMI_TRUE;
        if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
        {
            audply_btbox_data.is_kacaroke_enable = MMI_TRUE;
            //mmi_audply_btbox_stop_action();
			mmi_audply_btbox_stop_playing();
            mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE, &param);
            //mmi_audply_btbox_play_pause_action();
        }
        else
        {
        	//mmi_audply_btbox_stop_action();
			mmi_audply_btbox_stop_playing();
            audply_btbox_data.is_kacaroke_enable = MMI_TRUE;
            mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE, &param);
        }
    }
    else
    {
        if(audply_btbox_data.is_orignal_enable == MMI_TRUE)
        {
            if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
            {
                //mmi_audply_btbox_stop_action();
				mmi_audply_btbox_stop_playing();
                mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE, NULL);
                audply_btbox_data.is_kacaroke_enable = MMI_FALSE;
                audply_btbox_data.is_orignal_enable = MMI_FALSE;
                //mmi_audply_btbox_play_action();
				mmi_audply_btbox_play();
            }
            else
            {
                mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
                audply_btbox_data.is_kacaroke_enable = MMI_FALSE;
                audply_btbox_data.is_orignal_enable = MMI_FALSE;
            }
            mmi_frm_input_event_notify_remove(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE);
        }
        else
        {
            audply_btbox_data.is_orignal_enable = MMI_TRUE;
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
        }
    }
}
#endif


#ifdef __KARAOKE_SUPPORT__
static void mmi_audply_btbox_play_karaoke_switch()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY_KARAOKE_SWITCH,
              audply_btbox_data.kacaroke_timer_enable,
              audply_btbox_data.is_orignal_enable,
              audply_btbox_data.is_kacaroke_enable);
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
       //BT Box Todo: Notify memory not insert
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_MEMORY_CARD_ERROR);
       mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND,NULL);
       return;
    }
    
    if(audply_btbox_data.kacaroke_timer_enable == MMI_TRUE)
    {
        StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_TIMER);
        mmi_audply_btbox_karaoke();
        audply_btbox_data.kacaroke_timer_enable = MMI_FALSE;
    }
    else
    {
        StartTimer(AUDIO_PLAYER_KARAOKE_SWITCH_TIMER,300,mmi_audply_btbox_play_pause_action);
        audply_btbox_data.kacaroke_timer_enable = MMI_TRUE;
    }
}
#endif


static MMI_RET mmi_btbox_audio_launch_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_KARAOKE_CB_RESULT, mmi_frm_group_get_active_id());
    if(mmi_frm_group_get_active_id() == GRP_ID_AUDPLY_MAIN)
    {
        mmi_audply_btbox_launch();
    }
}


static mmi_ret mmi_audply_btbox_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    mmi_input_event_notify_param param = {0};
    param.aud_cb = mmi_btbox_audio_launch_callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            audply_btbox_data.is_init_done = MMI_FALSE;
            mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_ENTER_AUDIO_PLAYER, &param);
            break;

        case EVT_ID_GROUP_INACTIVE:
            mmi_audply_btbox_exit();
            break;
        case EVT_ID_BTBOX_PLAY_PAUSE:
            if(audply_btbox_data.is_processing_karaoke == MMI_TRUE || audply_btbox_data.is_init_done == MMI_FALSE)
            {
                //mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PROCOSSING, NULL);
                return MMI_RET_OK;
            }
            #ifdef MMI_AUDPLY_CARAOKE_SUPPORT_3KEY
			#ifdef __KARAOKE_SUPPORT__
            mmi_audply_btbox_play_karaoke_switch();
			#endif
            #else
            mmi_audply_btbox_play_pause_action();
            #endif
            break;
        case EVT_ID_BTBOX_NEXT:
            StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
            if(audply_btbox_data.wait_next == MMI_FALSE && audply_btbox_data.is_init_done == MMI_TRUE)
            {
                mmi_audply_btbox_get_next();
            }
            break;
        case EVT_ID_BTBOX_PREV:
            StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
            if(audply_btbox_data.wait_next == MMI_FALSE && audply_btbox_data.is_init_done == MMI_TRUE)
            {
                mmi_audply_btbox_get_prev();
            }
            break;
        case EVT_ID_BTBOX_VOL_UP:
            mmi_audply_btbox_inc_volume();
            break;
        case EVT_ID_BTBOX_VOL_DOWN:
            //mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_ENTER_AUDIO_PLAYER, NULL);
            mmi_audply_btbox_dec_volume();
            break;
        #ifdef __MMI_BTB_AT_KEY_SUPPORT__
		#ifdef __KARAOKE_SUPPORT__
        case EVT_ID_BTBOX_KARAOKE_SWITCH:
            if(audply_btbox_data.is_processing_karaoke == MMI_TRUE || audply_btbox_data.is_init_done == MMI_FALSE)
            {
                //mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_PROCOSSING, NULL);
                return MMI_RET_OK;
            }
            mmi_audply_btbox_karaoke();
            break;    
        #endif
		#endif
        default:
            break;
    }
    
    return MMI_RET_OK;
}


void mmi_audply_btbox_init_volume()
{
    mmi_audply_walk_record_struct walk_record;
    memset(&audply_btbox_data, 0, sizeof(audioplay_btbox_struct));
    ReadValueSlim(NVRAM_AUDPLY_VOLUME, &audply_btbox_data.volume, DS_BYTE);
    ReadRecordSlim(NVRAM_EF_AUDPLY_WALK_LID, 1, (void*)&walk_record, sizeof(mmi_audply_walk_record_struct));
    if(walk_record.stack_index < MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY)
    {
        mmi_ucs2cpy((CHAR*)audply_btbox_data.filefullname, (CHAR*)walk_record.current_path);
    }
    else
    {
        audply_btbox_data.filefullname[0] = 0;
        mmi_audply_walk_init();
    }
}


void mmi_audply_btbox_exit()
{
    StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_TIMER);
    StopTimer(AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER);
    StopTimer(AUDIO_PLAYER_KARAOKE_CB_TIMER);
    StopTimer(AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER);
    //mmi_audply_btbox_stop_action();
	mmi_audply_btbox_stop_playing();
    if(audply_btbox_data.is_kacaroke_enable == MMI_TRUE)
    {
        //mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        //mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
        audply_btbox_data.is_kacaroke_enable = MMI_FALSE;
        audply_btbox_data.is_orignal_enable = MMI_FALSE;
        mmi_frm_input_event_notify_remove(BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE);
    }
    audply_btbox_data.is_processing_karaoke = MMI_FALSE;
    audply_btbox_data.is_init_done = MMI_FALSE;
    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_BT_AUDPLY);
}


MMI_BOOL mmi_audply_btbox_background_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"callback result = %d", result);
    
    if (result == MDI_AUDIO_TERMINATED)
    {
          return MMI_TRUE;
    }
    
    if (mdi_audio_is_background_play_suspended())
    {
        return MMI_TRUE;
    }
    
    if(audply_btbox_data.play_state == AUDPLY_WALK_BTBOX_STATE_PLAY)
    {
        return MMI_TRUE;
    }
    else
    {
        if(audply_btbox_data.need_resume_play == MMI_TRUE)
        {
            audply_btbox_data.play_by_background = MMI_TRUE;
            mmi_audply_btbox_play_pause_action();
        }
    }
    return MMI_TRUE;
}

void mmi_audply_btbox_launch()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    #ifndef __MMI_BTBOX_NOLCD__
    mmi_audply_walk_struct* this = &(g_audply.walk);
    #else
    mmi_audply_walk_struct* this = &(g_btbox_audply.walk);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_BTBOX_LAUNCH);
    /*Check Memory card status*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_audply_btbox_init_volume();
    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_BT_AUDPLY, mmi_audply_btbox_background_callback_hdlr, NULL);
            
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
       //BT Box Todo: Notify memory not insert
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_MEMORY_CARD_ERROR);
       mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND,NULL);
       audply_btbox_data.is_init_done = MMI_TRUE;
       return;
    }
    
    if(audply_btbox_data.filefullname[0] == 0) /*First entry*/
    {
        Press_Prev = 0;
        g_btbox_audply.new_play_time = 0;
        ret = mmi_audply_walk_get_next(this->filefullname);
        if(ret == MMI_FALSE)
        {
            //To Do: Add Notify, not any more music files
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_NO_MORE_FILE);
            mmi_frm_input_event_notify(BTBOX_AUDPLY_NOTIFY_NO_MUSIC,NULL);
        }
        else
        {
            mmi_audply_btbox_play_pause_action();
        }
    }
    else
    {
        Press_Prev = 2;
        if(this->total == 0)
        {
            this->total++;
        }
        mmi_audply_btbox_play_pause_action();
        if(cache_int_struct.cache_state == AUDPLY_WALK_CACHE_STATE_FINISH)
        {
            if(cache_int_struct.Cache_header_index == 0 && cache_int_struct.Cache_footer_index == 0)
            {
                mmi_audply_walk_add_cache(audply_btbox_data.filefullname);
            }
        }
    }
#ifdef __MMI_AVRCP_SUPPORT__
    mmi_bt_avrcp_set_cmd_hdlr(mmi_audply_btbox_bt_avrcp_cmd_hdlr);
#endif
    audply_btbox_data.is_init_done = MMI_TRUE;
}


mmi_ret mmi_auddply_bt_box_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    kal_bool is_enable = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->evt_id)
    {
        case EVT_ID_INPUT_EVENT_APP_SWITCH:
        case EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY:
            MMI_TRACE(MOD_MMI_MEDIA_APP,MMI_AUDPLY_TRC_EVENT_HANDLE);
            if(mmi_frm_input_event_is_app_switch_to(GRP_ID_AUDPLY_MAIN))
            {
                ReadValueSlim(NVRAM_AUDPLY_ENABLE, &is_enable, DS_BYTE);
                if(is_enable == MMI_FALSE)
                {
                    return MMI_RET_LOCAL_APP_UNLAUNCHED;
                }
                MMI_TRACE(MOD_MMI_MEDIA_APP,MMI_AUDPLY_TRC_EVENT_HANDLE_SWITCH_AUDPLY);
                if(mmi_frm_group_get_active_id() != GRP_ID_AUDPLY_MAIN)
                {
                    //mmi_audply_btbox_launch();
                    /*Enter Group*/
                    if(mmi_frm_group_get_active_id() != GRP_ID_AUDPLY_MAIN)
                    {
                         mmi_frm_group_close(mmi_frm_group_get_active_id());
                    }
    
                    if(!mmi_frm_group_is_present(GRP_ID_AUDPLY_MAIN))
                    {
                         mmi_frm_group_create_ex(GRP_ID_ROOT, 
                                                 GRP_ID_AUDPLY_MAIN, 
                                                 mmi_audply_btbox_proc, 
                                                 NULL, 
                                                 NULL);
                    }
                }
                return MMI_RET_LOCAL_APP_LAUNCHED;
            }
            /*
            else
            {
                mmi_frm_input_event_switch_to_next_app();
            }*/
            break;
        default    :
            break;
    }
}
#endif


#endif  //__MMI_AUDPLY_WALK_PLAY__

