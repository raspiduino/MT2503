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
 * mpl_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of mpl.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "drv_features_video.h"
#if defined(__VIDEO_ARCHI_V2__)

/*==== INCLUDES =========*/
#include "kal_public_api.h"
#include "kal_trace.h"
#include "media_common.h"
#include "mpl_common.h" // the common defition for MPL
#include "mpl_player.h" // the common defition for MPL
#include "l1audio.h"
//#include "rm_provider.h"
#include "fs_type.h"
#include "vcodec_v2_trc.h"

typedef void* (*_PFN_MPL_AUD_MEM_ALL_)(kal_int32 size, med_mem_type_enum type, char* file, long line);
typedef void (*_PFN_MPL_AUD_MEM_FREE_)(void** mem_p, med_mem_type_enum type, char* file, long line);
static _PFN_MPL_AUD_MEM_ALL_ mpl_aud_mem_alloc;
static _PFN_MPL_AUD_MEM_FREE_ mpl_aud_mem_free;
static kal_uint32 u4LastSampleRate = NULL;
/*****************************************************************************
 * FUNCTION
 *  _aud_player_mpl_alloc_mem
 * DESCRIPTION
 *  This function is to allocate memory.
 * PARAMETERS
 *  client_p      [IN]          MPL handle
 *  size          [IN]          Memory size
 *  type          [IN]          Memory type
 *  file          [IN]          File name
 *  line          [IN]          The line number in the file
 * RETURNS
 *
 *****************************************************************************/
static void* _mpl_player_aud_alloc_mem(mpl_player_client_t *client_p, kal_uint32 size, med_mem_type_enum type, char* file, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mpl_aud_mem_alloc((kal_int32)size, type, __FILE__, 0);
}

/*****************************************************************************
 * FUNCTION
 *  _aud_player_mpl_alloc_mem
 * DESCRIPTION
 *  This function is to allocate memory.
 * PARAMETERS
 *  client_p      [IN]          MPL handle
 *  size          [IN]          Memory size
 *  type          [IN]          Memory type
 *  file          [IN]          File name
 *  line          [IN]          The line number in the file
 * RETURNS
 *
 *****************************************************************************/
static void _mpl_player_aud_free_mem(mpl_player_client_t *client_p, void** mem_p, med_mem_type_enum type, char* file, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mpl_aud_mem_free(mem_p, type, __FILE__, 0);
}

/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_event
 * DESCRIPTION
 *  This function is called when the player is closed.
 * PARAMETERS
 *  result      [IN]           Open result.
 * RETURNS
 *
 *****************************************************************************/
static void _mpl_player_aud_on_event(mpl_player_client_t *client, mpl_player_event_t event, media_error_t mpl_result)
{
    switch(event)
    {
        case MPL_PLAYER_EVENT_OPEN:
            break;
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  MPL_GetContentDescInfo_EX
* DESCRIPTION
*  This function is to get audio content info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
Media_Status MPL_GetContentDescInfo(
    med_type_enum media_type,
    STFSAL *pstFSAL, audInfoStruct *contentInfo, 
    void* (*mem_alloc)(kal_int32 size, med_mem_type_enum type, char* file, long line), 
    void (*mem_free)(void** mem_p, med_mem_type_enum type, char* file, long line))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_player_t *mpl_player_p;
    mpl_player_client_t mpl_client;
    mpl_player_open_t open_req;
    mpl_player_get_media_info_t media_info;
    mpl_player_get_meta_t meta_struct;
    media_error_t eErr;
    FS_FileInfo rFileInfo;
    kal_wchar *file_name = NULL;
    kal_int32 u4Err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

    kal_trace(TRACE_GROUP_1, VID_TRC_MPL_SESSION_PARSER_GET_CONTENT, media_type);

    switch(media_type)
    {
        #if defined(__VE_SP_RM__)
        case MED_TYPE_RM:
        //RM_GetContentDescInfo_EX(pstFSAL, contentInfo, mem_alloc, mem_free);
            break;
        #endif /*defined(__VE_SP_RM__)*/
        case MED_TYPE_MP4:
        case MED_TYPE_3GP:
            break;
        case MED_TYPE_FLV:
            break;
        default:
            return MEDIA_BAD_FORMAT;
    }
    mpl_aud_mem_alloc = mem_alloc;
    mpl_aud_mem_free = mem_free;
    mpl_client.mem_alloc_func = _mpl_player_aud_alloc_mem;
    mpl_client.mem_free_func = _mpl_player_aud_free_mem;
    mpl_client.on_event = _mpl_player_aud_on_event;

    //return MEDIA_SUCCESS;

    mpl_player_p = construct_media_session(&mpl_client);
    ASSERT(mpl_player_p != NULL);

    /* Construct open struct */
    kal_mem_set(&open_req, 0, sizeof(mpl_player_open_t));
    mpl_player_p->get_default(mpl_player_p, MPL_OPEN_PARAM, &open_req);

    if (pstFSAL != NULL)
    {
        if (pstFSAL->hFile == -1)
        {
            open_req.data = pstFSAL->pbFile;
            open_req.data_size = pstFSAL->uRamFileSize;
            open_req.media_mode      = MED_MODE_ARRAY;
        }
        else
        {
            file_name = get_ctrl_buffer(261*2);
            u4Err = FS_GetFileInfo(pstFSAL->hFile, &rFileInfo);
            if (u4Err < 0)
            {
            #ifdef MPL_DEBUG_INFO_TRACE
                kal_trace(TRACE_GROUP_1, VID_TRC_MPL_SESSION_FAIL, u4Err, __LINE__);
            #endif
                free_ctrl_buffer(file_name);
                mpl_player_p->destroy(mpl_player_p);
                return MEDIA_FAIL;
            }
            kal_wstrcpy((void*)file_name, (kal_wchar *)rFileInfo.FullName);
            open_req.data            = (void*)file_name;
            open_req.data_size       = (kal_uint32)kal_wstrlen(file_name);
            open_req.media_mode      = MED_MODE_FILE;
        }
        
        open_req.media_type      = media_type;
        open_req.scenario_id     = MPL_INFO;
        open_req.enable_aud_only = (kal_bool)KAL_TRUE;
    }
    else
    {
        mpl_player_p->destroy(mpl_player_p);
        return MEDIA_FAIL;
    }

    eErr = mpl_player_p->open(mpl_player_p, &open_req);
    if (eErr != MED_S_OK)
    {
        /* temp solution */
        contentInfo->bitRate = 0;
        contentInfo->trackNum = 0;
        contentInfo->sampleRate = u4LastSampleRate;
        kal_trace(TRACE_GROUP_1, VID_TRC_MPL_SESSION_PARSER_AUD_INFO, contentInfo->time, contentInfo->bitRate, contentInfo->sampleRate, contentInfo->trackNum, contentInfo->stereo);
        /* temp solution -- end*/
        if (file_name)
        {
            free_ctrl_buffer(file_name);
        }
        mpl_player_p->destroy(mpl_player_p);
        return MEDIA_FAIL;
    }

    if (file_name)
    {
        free_ctrl_buffer(file_name);
    }

    /* media infomation */
    mpl_player_p->get_media_info(mpl_player_p, &media_info);
    contentInfo->time = (media_info.aud_duration > media_info.vid_duration)?(media_info.aud_duration):(media_info.vid_duration) ;
    contentInfo->bitRate = 0;
    contentInfo->sampleRate = media_info.audio_sampling_rate;
    contentInfo->trackNum = 0;
    contentInfo->stereo = (media_info.audio_channel_num > 1)? KAL_TRUE : KAL_FALSE;

    u4LastSampleRate = media_info.audio_sampling_rate;
    kal_trace(TRACE_GROUP_1, VID_TRC_MPL_SESSION_PARSER_AUD_INFO, contentInfo->time, contentInfo->bitRate, contentInfo->sampleRate, contentInfo->trackNum, contentInfo->stereo);

    /* meta */
    meta_struct.title_desc_ptr = contentInfo->title;
    meta_struct.title_desc_len = MAX_DESCRIPTION;
    meta_struct.artist_desc_ptr = contentInfo->artist;
    meta_struct.artist_desc_len = MAX_DESCRIPTION;
    meta_struct.album_desc_ptr = contentInfo->album;
    meta_struct.album_desc_len = MAX_DESCRIPTION;
    meta_struct.author_desc_ptr = contentInfo->author;
    meta_struct.author_desc_len = MAX_DESCRIPTION;
    meta_struct.copyright_desc_ptr = contentInfo->copyright;
    meta_struct.copyright_desc_len = MAX_DESCRIPTION;
    meta_struct.date_desc_ptr = contentInfo->date;
    meta_struct.date_desc_len = MAX_DESCRIPTION;

    mpl_player_p->get_meta(mpl_player_p, &meta_struct);

    mpl_player_p->close(mpl_player_p);
    mpl_player_p->destroy(mpl_player_p);
#endif
    return MEDIA_SUCCESS;
}

/*****************************************************************************
* FUNCTION
*  MPL_GetContentDescInfo_EX
* DESCRIPTION
*  This function is to get audio content info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
Media_Status MPL_GetMetaData(med_type_enum media_type, kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void* (*mem_alloc)(kal_uint32 size), void (*mem_free)(void** mem_p))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(media_type)
    {
        #if defined(__VE_SP_RM__)
        case MED_TYPE_RM:
        //RM_GetMetaData_EX(filename, pbBuf, uSize, contentInfo, mem_alloc, mem_free);
        return MEDIA_SUCCESS;
        //break;
        #endif /*defined(__VE_SP_RM__)*/
        default:
            return MEDIA_BAD_FORMAT;
    }    
}

#endif /* defined (__VIDEO_ARCHI_V2__) */
