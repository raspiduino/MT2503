/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
*  mdi_swflash.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Interface to access SWFlash related functions.
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
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#if defined(__MMI_SWFLASH__)

/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef __MTK_TARGET__
#include <windows.h>    /* for soc_api.h */
#endif 

#include "stdC.h"
#include "mmi_platform.h"
#include "mmi_frm_gprot.h"
#include "fat_fs.h"
#include "lcd_if.h"             /* lcd interface */
#include "gdi_include.h"        /* include data type */
#include "lcd_sw_rnd.h"
#include "gui.h"
#include "med_api.h"            /* media task */
#include "med_main.h"
#include "med_struct.h"
#include "mdi_datatype.h"
#include "mdi_swflash.h"
#include "med_smalloc.h"        /* MMI Shall not inc this: Paul plz help check */

#include "ProfileGprots.h"


#include "rtfiles.h"
#include "soc_api.h"
#include "app2soc_struct.h"
#include "FileMgr.h"
#include "FileManagerGprot.h"
#include "kal_trace.h"          /* Debug Info */
#include "fs_type.h"
/* NVRAM */
#include "IdleAppDef.h"
#include "SWflashDef.h"
#include "SWFlashProt.h"
#include "mdi_audio.h"
#include "GlobalDefs.h"
/*****************************************************************************
* Local variable                                                     
*****************************************************************************/
mdi_swflash_info_struct wgui_swflash_info;
mdi_swflash_context_struct g_mdi_swflash_cntx;
mdi_swflash_context_struct *mdi_swflash_p = &g_mdi_swflash_cntx;

#ifdef SWFLASH_NEOMTEL

#include "s3w_common.h"
#include "s3w_adapter.h"
#include "s3w_interface.h"

typedef struct
{
    MDI_RESULT errorNo;
    MMI_ID_TYPE stringId;
	mmi_event_notify_enum type;	
} mdi_swflash_error_info_struct;
typedef mdi_swflash_error_info_struct mdi_swflash_error_info_table;
const static mdi_swflash_error_info_table g_mdi_swflash_error_info_table[] = 
{
    
    {MDI_RES_SWFLASH_ERR_FILE_ERROR, STR_GLOBAL_INVALID_FORMAT, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_OPEN_FILE, STR_GLOBAL_ERROR, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_GET_FILE_SIZE, STR_GLOBAL_ERROR, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE , STR_ID_SWFLASH_NOTIFY_TOO_BIG, MMI_EVENT_FAILURE},
    { MDI_RES_SWFLASH_ERR_READ_FILE, STR_ID_SWFLASH_ZDD_FILE_INVALID, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL, STR_ID_SWFLASH_ZDD_FILE_INVALID, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_DECIPHER, STR_GLOBAL_INVALID_FORMAT, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_CREATE_INSTANCE,  STR_GLOBAL_ERROR, MMI_EVENT_FAILURE},
    {MDI_RES_SWFLASH_ERR_LOAD,  STR_GLOBAL_ERROR, MMI_EVENT_FAILURE},
    
    {MDI_RES_SWFLASH_ERR_FAILED, STR_GLOBAL_ERROR, MMI_EVENT_FAILURE},
	
    {MDI_RES_SWFLASH_SUCCEED, STR_GLOBAL_OK, MMI_EVENT_SUCCESS}
};

MMI_ID_TYPE mdi_swflash_get_mdi_error_info (MDI_RESULT error_code, mmi_event_notify_enum* type_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
     *type_p = MMI_EVENT_FAILURE;	
	
    for (i = 0; g_mdi_swflash_error_info_table[i].errorNo != 0; i++)
    {
        if (g_mdi_swflash_error_info_table[i].errorNo == error_code)
        {
			*type_p = g_mdi_swflash_error_info_table[i].type;
			return g_mdi_swflash_error_info_table[i].stringId;
        }
    }
	
    return STR_GLOBAL_ERROR;
	
}
/*****************************************************************************
* FUNCTION
*  mdi_swflash_init
* DESCRIPTION
*  init values
* PARAMETERS
*  void
* RETURNS          void
*  
*****************************************************************************/

void mdi_swflash_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mdi_swflash_p->instance = NULL;
    mdi_swflash_p->decipher_buffer = NULL;
    
    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->decode_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;
    mdi_swflash_p->fd = -1 ;
    mdi_swflash_p->is_first_frame = MMI_FALSE;
    mdi_swflash_p->is_loop= MMI_FALSE;
    mdi_swflash_p->is_fromplayer= MMI_FALSE;
    mdi_swflash_p->post_blt = NULL;
    mdi_swflash_p->pre_blt = NULL;
    mdi_swflash_p->back_buffer = NULL;
	
    /* 20071207 add by Yvonne: default mode is swflash player */
    mdi_swflash_p->play_purpose = MDI_SWFLASH_PURPOSE_PLAYER;
}

/*****************************************************************************
* FUNCTION
*  mdi_swflash_set_imei
* DESCRIPTION
*  
* PARAMETERS
*  imei            imei number
* RETURNS          void
*  
*****************************************************************************/

void mdi_swflash_set_imei(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(mdi_swflash_p->imei, imei, 16);
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_malloc_mem
* DESCRIPTION
* malloc_mem
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mdi_swflash_malloc_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_swflash_p->mem_ptr== NULL)
    {
        media_get_ext_buffer_cacheable(MOD_MMI, (void **)&mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
        MMI_ASSERT(mdi_swflash_p->mem_ptr != NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_free_mem
* DESCRIPTION
* free_mem
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mdi_swflash_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_swflash_p->mem_ptr!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->mem_ptr);
        mdi_swflash_p->mem_ptr = NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  mdi_swflash_open_file
* DESCRIPTION
*  
* PARAMETERS
*  filename        file full name        
*  playmode        play mode        
*  info            the info of swflash works
* RETURNS          open result
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_open_file(const S8 *filename, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
    int nSize = 0;
    int outsize = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_OPENFILE);
    mdi_swflash_p->fd = -1;
    /* If a swflash content is already opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
    {
        return MDI_RES_SWFLASH_ERR_FAILED; 
    }
	
    if ((mdi_swflash_p->fd = FS_Open((const WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return MDI_RES_SWFLASH_ERR_OPEN_FILE; 
    }
	
    if ((ret = FS_GetFileSize(mdi_swflash_p->fd, (U32*)& nSize)) != RTF_NO_ERROR)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_GET_FILE_SIZE; 
    }
	
    if (nSize <= 0 )
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_GET_FILE_SIZE; 
    }
	
	if (nSize > MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE; 
    }		
	
    /* decipher */
    /* alloc buffer */
    //media_get_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer, nSize);
    media_get_ext_buffer_cacheable(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer, nSize);
    //mdi_swflash_p->decipher_buffer=(U8 *)applib_mem_screen_alloc(nSize);
    MMI_ASSERT(mdi_swflash_p->decipher_buffer != NULL);
    
    ret= mmi_swflash_vis_decipher(mdi_swflash_p->fd, (const S8 *)filename, nSize, mdi_swflash_p->decipher_buffer,&wgui_swflash_info.type, &outsize);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MMI_SWFLASH_APP_DECIPHER,ret);
	
    
    if(ret == MMI_TRUE)
    {
        mdi_swflash_p->size = outsize;
        mdi_swflash_malloc_mem();
        mdi_swflash_p->playmode = playmode;
        wgui_swflash_info.width = LCD_WIDTH;
        wgui_swflash_info.height= LCD_WIDTH;
		info->width = LCD_WIDTH;
        info->height= LCD_WIDTH;
		
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        if(mdi_swflash_p->decipher_buffer != NULL)
        {    
           // applib_mem_screen_free(mdi_swflash_p->decipher_buffer);
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer);
            mdi_swflash_p->decipher_buffer = NULL;
        }
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd=-1;
        return MDI_RES_SWFLASH_ERR_DECIPHER;          
    }
	
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_close_file
* DESCRIPTION
*  close file and release resource
* PARAMETERS
*  void
* RETURNS   close result
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_CLOSEFILE);
    
    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->decode_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;
	
    /*stop loop and stop updating screen*/
    mdi_swflash_p->is_loop = MMI_FALSE;
    s3wa_cancel_timer(mdi_swflash_p,(void *)&(mdi_swflash_p->playmode));
    
    /* free handle */
	mdi_swflash_register_blt_callback(NULL,NULL);
    if(mdi_swflash_p->decipher_buffer != NULL)
    {
		media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer);
        //applib_mem_screen_free(mdi_swflash_p->decipher_buffer);
        mdi_swflash_p->decipher_buffer = NULL;
    }
	
    if(mdi_swflash_p->back_buffer!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->back_buffer);
        mdi_swflash_p->back_buffer = NULL;
    }
    if (mdi_swflash_p->fd != -1)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        mdi_swflash_free_mem();
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        mdi_swflash_free_mem();
        return MDI_RES_SWFLASH_ERR_FAILED; 
	}
    
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_open_id
* DESCRIPTION
*  open works by resource id
* PARAMETERS
*  id              resource id       
*  playmode        play mode        
*  info            works info
* RETURNS          open result
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_open_id(U16 id, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pData = NULL;
    U32 nSize = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_OPENID);
	
    /* If a swflash content is alredy opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
        return MDI_RES_SWFLASH_ERR_FAILED;  
	
    pData = (U8*)GetImage(id);
    if (pData == NULL)
    {
        return MDI_RES_SWFLASH_ERR_FAILED;  
    }
	
    nSize = *(pData + 4) * 256*256 +  *(pData + 3) * 256 + *(pData + 2);
	
    mdi_swflash_p->decipher_buffer = pData+8;
    mdi_swflash_malloc_mem();
    mdi_swflash_p->size = nSize;
    mdi_swflash_p->playmode = playmode;
    wgui_swflash_info.width = LCD_WIDTH;
    wgui_swflash_info.height= LCD_WIDTH;
    info->width = LCD_WIDTH;
    info->height = LCD_WIDTH;
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_close_id
* DESCRIPTION
*  close resource id
* PARAMETERS
*  void
* RETURNS close result
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_close_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_CLOSEID);
	
    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;
    mdi_swflash_p->size = 0;
    mdi_swflash_p->playmode = 0;
    wgui_swflash_info.width = 0;
    wgui_swflash_info.height= 0;
	
    mdi_swflash_p->decipher_buffer = NULL;
	
    if(mdi_swflash_p->back_buffer!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->back_buffer);
        mdi_swflash_p->back_buffer = NULL;
    }
    mdi_swflash_free_mem();
    mdi_swflash_register_blt_callback(NULL,NULL);
    return MDI_RES_SWFLASH_SUCCEED;
	
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_on_end
* DESCRIPTION
*  callback for play end
* PARAMETERS
*  None
* RETURNS          
*  None
*****************************************************************************/
void mdi_swflash_on_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_APP_RELEASE,mdi_swflash_p->instance); 
    if (mdi_swflash_p->instance!= NULL)
    {
        s3wi_release(mdi_swflash_p->instance);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_APP_RELEASE, (int)mdi_swflash_p->instance);
        mdi_swflash_p->instance= NULL;
    }   
    if(mdi_swflash_p->is_loop == MMI_TRUE)
    {
        mdi_swflash_play(mdi_swflash_p->swflash_layer_handle, 0, MDI_DEVICE_SPEAKER_BOTH, NULL);
    }
	
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_set_is_from_player
* DESCRIPTION
*  set from player flag
* PARAMETERS
*  from_player     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mdi_swflash_set_is_from_player(MMI_BOOL from_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->is_fromplayer = from_player;
}

/*****************************************************************************
* FUNCTION
*  mdi_swflash_play
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS          MDI_RESULT
*  
*****************************************************************************/

MDI_RESULT mdi_swflash_play(
							gdi_handle layer_handle,
							U16 repeat_count,
							U8 audio_path,
							play_result_callback play_result_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char ret = 0;
    S32 width, height,offsetx,offsety;
    s3w_data_info data_info;
    U8 count =0;
    
    U32 buffer_size = 0;
    U8 bpp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_PLAY);
    
    MMI_ASSERT(layer_handle != NULL);
    if(repeat_count == 0)
    {
        mdi_swflash_p->is_loop=MMI_TRUE;   
        mdi_swflash_p->is_fromplayer =MMI_FALSE;
    }
    else
    {
        mdi_swflash_p->is_loop=MMI_FALSE;
    }
    mdi_swflash_p->swflash_layer_handle = layer_handle;
    mdi_swflash_p->play_result = play_result_hdlr;
    mdi_swflash_p->is_ready_update = MMI_FALSE;
    bpp=2;
	
    gdi_layer_push_and_set_active(mdi_swflash_p->swflash_layer_handle);
    gdi_layer_get_buffer_ptr(&mdi_swflash_p->decode_buffer);
    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_position(&offsetx,&offsety);
    mdi_swflash_p->layer_width = width;
    mdi_swflash_p->layer_height = height;
    mdi_swflash_p->layer_offsetx = offsetx;
    mdi_swflash_p->layer_offsety = offsety;
    gdi_layer_clear_background(GDI_COLOR_WHITE);
	
    buffer_size = mdi_swflash_p->layer_width*mdi_swflash_p->layer_height*bpp;
    gdi_layer_pop_and_restore_active();
	
	/*player init*/
    s3wi_memory_init((char *)mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
    data_info.data_type = S3W_DATA_MEMORY;
    data_info.file_type = S3W_CONTENTS_FILE;
    data_info.file_url[0] = 0x00;
    data_info.stream = mdi_swflash_p->decipher_buffer;
    data_info.stream_size = mdi_swflash_p->size;
    data_info.stream_self_free = 0;
	
    if (mdi_swflash_p->play_purpose == MDI_SWFLASH_PURPOSE_PLAYER)
    {    
        ret=s3h_isValidFile(NULL, &data_info);
		if(ret !=1)
		{
            return MDI_RES_SWFLASH_ERR_FILE_ERROR; 
		}  
    }
    
	if(mdi_swflash_p->back_buffer == NULL)
    {
        media_get_ext_buffer_cacheable(MOD_MMI, (void **)&mdi_swflash_p->back_buffer, buffer_size);
        MMI_ASSERT(mdi_swflash_p->back_buffer != NULL);
    }
    mdi_swflash_p->instance = s3wi_create(mdi_swflash_p, NULL, 
		MMI_SWFLASH_MEM_BUFFER_SIZE*0.8, MMI_SWFLASH_PERFORMANCE);
    if(mdi_swflash_p->instance == NULL)
    {
        return MDI_RES_SWFLASH_ERR_CREATE_INSTANCE; 
    }
	
    
    ret=s3wi_load(mdi_swflash_p->instance, &data_info, S3W_DATA_MEMORY,
		TRUE, FALSE);/*default: do not loop and play back ground sound*/
    if(ret == 0)
    {
        s3wi_release( mdi_swflash_p->instance);
        mdi_swflash_p->instance = NULL;
        return MDI_RES_SWFLASH_ERR_LOAD; 
    }
    
    /*sound control*/
    if ((IsSilentModeActivated()==MMI_TRUE||IsMeetingModeActivated() ==MMI_TRUE)
		&& (mdi_swflash_p->playmode == VIS_PLAYER))
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
	
    if(mdi_swflash_p->playmode == VIS_PLAYER)
    {
        mdi_audio_set_headset_mode_output_path(audio_path);
    }
	
    if(mdi_swflash_p->playmode == VIS_PLAYER)
    {
        s3wi_sound_on(mdi_swflash_p->instance);
    }
    else
    {
        s3wi_sound_off(mdi_swflash_p->instance);
    }
    /*begin to play*/
    s3wi_play(mdi_swflash_p->instance);
	
    /*if it is the reenter after interruptted,then just one frame and no sound*/
    if (audio_path == 0xFF)
    {
        mdi_swflash_p->is_first_frame= MMI_TRUE;
        s3wi_sound_off(mdi_swflash_p->instance);
    }
    /*wait till the decode screen is ready*/
    for(count=0;count<10;count++)/*try 10 times ,avoid to block MMI tash too long*/
    {
        if(mdi_swflash_p->is_ready_update == MMI_FALSE)
        {
            ret=s3wi_process(mdi_swflash_p->instance, (void *)&(mdi_swflash_p->playmode));
        }
        else
        {
            break;
        }
    }    
    return MDI_RES_SWFLASH_SUCCEED;
	
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_stop
* DESCRIPTION
*  play stop
* PARAMETERS
*  void
* RETURNS          MDI_RESULT
*  
*****************************************************************************/

MDI_RESULT mdi_swflash_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_STOP);
    if(mdi_swflash_p->instance != NULL)
    {
        mdi_swflash_p->is_loop = MMI_FALSE;
        s3wi_stop(mdi_swflash_p->instance);
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_pause
* DESCRIPTION
*  play pause
* PARAMETERS
*  void
* RETURNS          MDI_RESULT
*  
*****************************************************************************/

MDI_RESULT mdi_swflash_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_PAUSE);
    if(mdi_swflash_p->instance != NULL)
    {
        ret=s3wi_pause(mdi_swflash_p->instance);
        if(ret==1)
        {
            return MDI_RES_SWFLASH_SUCCEED;
        }
        else
        {
            return MDI_RES_SWFLASH_ERR_FAILED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_resume
* DESCRIPTION
*  swflash resume
* PARAMETERS
*  void
* RETURNS          MDI_RESULT
*  
*****************************************************************************/

MDI_RESULT mdi_swflash_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_RESUME);
    if(mdi_swflash_p->instance != NULL)
    {
        ret=s3wi_resume(mdi_swflash_p->instance);
        
        if(ret==1)
        {
            return MDI_RES_SWFLASH_SUCCEED;
        }
        else
        {
            return MDI_RES_SWFLASH_ERR_FAILED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_check_download_file
* DESCRIPTION
*  start download the swflash file from server
* PARAMETERS
*  descriptor_filename     [IN]        Cmp filename (descriptor for how to dl)
*  total_len               [OUT]       Total size
*  current_len             [OUT]       Current downloaded size
*  category                [?]         the category of works
* RETURNS
*  Check download result
* RETURN VALUE LIST
*  MDI_RES_SWFLASH_SUCCEED              succeed
*  MDI_RES_SWFLASH_ERR_FILE_ERROR       file access error
*  MDI_RES_SWFLASH_ERR_ENGINE_ERROR     engine error
*****************************************************************************/
MDI_RESULT mdi_swflash_check_download_file(
										   U16 *descriptor_filename,
										   U32 *total_len,
										   U32 *current_len,
										   U32 *category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 file_size;
    U32 read_size;
    S32 fs_ret;
    PS8 filedata_buf_p = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_SWFLASH_CHECK_DOWNLAOD_FILE);
    
    MMI_ASSERT(descriptor_filename != NULL);
	
    /* init category */
    *category = 0;
	
    /* open file */
    file_handle = FS_Open((U16*) descriptor_filename, FS_READ_ONLY);
	
    if (file_handle >= 0)
    {
        /* read from memory */
        FS_GetFileSize(file_handle, &file_size);
		
        if (file_size > MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)
        {
            /* file size too big */
            FS_Close(file_handle);
            return MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE; 
        }
        else if (file_size == 0)
        {
            FS_Close(file_handle);
            return MDI_RES_SWFLASH_SUCCEED; 
        }
		
        /* alloc buffer */
        media_get_ext_buffer_cacheable(MOD_MMI, (void **)&filedata_buf_p, file_size);
		
        /* mem allocate shall not failed */
        MMI_ASSERT(filedata_buf_p != NULL);
		
        fs_ret = FS_Read(file_handle, (U16*) filedata_buf_p, file_size, &read_size);
        FS_Close(file_handle);
		
        /* fs read error 1 */
        if (fs_ret < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_READ_FILE;
        }
		
        /* fs read error 2 */
        if (file_size != read_size)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL;
        }
        
		/* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
        filedata_buf_p = NULL;
		
        *total_len=read_size;
        *current_len = read_size;
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        /* open file error */
        return MDI_RES_SWFLASH_ERR_OPEN_FILE;
    }
	
	
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_key_down_event
* DESCRIPTION
*  transfer key_down_event to cim engine
* PARAMETERS
*  key     [IN]        
* RETURNS
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_key_down_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long vis_key = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_UPDATEFRAME);
	
    switch (key)
    {
	case KEY_0:
		vis_key = SIS3_KEY_0;
		break;
	case KEY_1:
		vis_key = SIS3_KEY_1;
		break;
	case KEY_2:
		vis_key = SIS3_KEY_2;
		break;
	case KEY_3:
		vis_key = SIS3_KEY_3;
		break;
	case KEY_4:
		vis_key = SIS3_KEY_4;
		break;
	case KEY_5:
		vis_key = SIS3_KEY_5;
		break;
	case KEY_6:
		vis_key = SIS3_KEY_6;
		break;
	case KEY_7:
		vis_key = SIS3_KEY_7;
		break;
	case KEY_8:
		vis_key = SIS3_KEY_8;
		break;
	case KEY_9:
		vis_key = SIS3_KEY_9;
		break;
	case KEY_STAR:
		vis_key = SIS3_KEY_ASTERISK;    /* "*" shows in next position in motion dial */
		break;
	case KEY_POUND:
		vis_key = SIS3_KEY_POUND;
		break;
	case KEY_UP_ARROW:
		vis_key = SIS3_KEY_UP;
		break;
	case KEY_DOWN_ARROW:
		vis_key = SIS3_KEY_DOWN;
		break;
	case KEY_LEFT_ARROW:
		vis_key = SIS3_KEY_LEFT;
		break;
	case KEY_RIGHT_ARROW:
		vis_key = SIS3_KEY_RIGHT;
		break;
	case KEY_ENTER:
		vis_key = SIS3_KEY_SELECT;
		break;
	case KEY_SEND:
		vis_key = SIS3_KEY_SEND;
		break;
	case KEY_CLEAR:
		vis_key = SIS3_KEY_CANCEL;
		break;
#ifdef __MMI_MOTION_DIAL__
	case '*':
		vis_key = SIS3_KEY_EX4; /* "*" shows in the same position */
		break;
	case '+':
		vis_key = SIS3_KEY_EX1;
		break;
	case 'p':
		vis_key = SIS3_KEY_EX0;
		break;
	case 'w':
		vis_key = SIS3_KEY_EX3;
		break;
	case 'c':
		vis_key = SIS3_KEY_EX2;
		break;
#endif /* __MMI_MOTION_DIAL__ */            
#ifdef __MMI_MOTION_MAINMENU__
	case 'L':
		vis_key = SIS3_KEY_EX5;
		break;
#endif /* __MMI_MOTION_MAINMENU__  */
	default:
		ASSERT(0);
		break;
    }
	
    s3wi_key_down(mdi_swflash_p->instance, vis_key);
	s3wi_key_pressed(mdi_swflash_p->instance, vis_key);
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_key_up_event
* DESCRIPTION
*  transfer key_up_event to cim engine
* PARAMETERS
*  key     [IN]        
* RETURNS
*  
*****************************************************************************/
MDI_RESULT mdi_swflash_key_up_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long vis_key = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    /* MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MMI_SWFLASH_MDI_CIM_UPDATEFRAME); */
	
    switch (key)
    {
	case KEY_0:
		vis_key = SIS3_KEY_0;
		break;
	case KEY_1:
		vis_key = SIS3_KEY_1;
		break;
	case KEY_2:
		vis_key = SIS3_KEY_2;
		break;
	case KEY_3:
		vis_key = SIS3_KEY_3;
		break;
	case KEY_4:
		vis_key = SIS3_KEY_4;
		break;
	case KEY_5:
		vis_key = SIS3_KEY_5;
		break;
	case KEY_6:
		vis_key = SIS3_KEY_6;
		break;
	case KEY_7:
		vis_key = SIS3_KEY_7;
		break;
	case KEY_8:
		vis_key = SIS3_KEY_8;
		break;
	case KEY_9:
		vis_key = SIS3_KEY_9;
		break;
	case KEY_STAR:
		vis_key = SIS3_KEY_ASTERISK;  /* "*" shows in next position in motion dial */
		break;
	case KEY_POUND:
		vis_key = SIS3_KEY_POUND;
		break;
	case KEY_UP_ARROW:
		vis_key = SIS3_KEY_UP;
		break;
	case KEY_DOWN_ARROW:
		vis_key = SIS3_KEY_DOWN;
		break;
	case KEY_LEFT_ARROW:
		vis_key = SIS3_KEY_LEFT;
		break;
	case KEY_RIGHT_ARROW:
		vis_key = SIS3_KEY_RIGHT;
		break;
	case KEY_ENTER:
		vis_key = SIS3_KEY_MENU;
		break;
	case KEY_SEND:
		vis_key = SIS3_KEY_SEND;
		break;
	case KEY_CLEAR:
		vis_key = SIS3_KEY_CANCEL;
		break;
#ifdef __MMI_MOTION_DIAL__           
	case '*':
		vis_key = SIS3_KEY_EX4; /* "*" shows in the same position */
		break;
	case '+':
		vis_key = SIS3_KEY_EX1;
		break;
	case 'p':
		vis_key = SIS3_KEY_EX0;
		break;
	case 'w':
		vis_key = SIS3_KEY_EX3;
		break;
	case 'c':
		vis_key = SIS3_KEY_EX2;
		break;
#endif /* __MMI_MOTION_DIAL__ */            
#ifdef __MMI_MOTION_MAINMENU__
	case 'L':
		vis_key = SIS3_KEY_EX5;
		break;
#endif /* __MMI_MOTION_MAINMENU__  */
		
	default:
		ASSERT(0);
		break;
    }
	
    s3wi_key_released(mdi_swflash_p->instance, vis_key);
	
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_register_blt_callback
* DESCRIPTION
*  register the pre and post draw function
* PARAMETERS
*  void
* RETURNS          void
*  
*****************************************************************************/
void mdi_swflash_register_blt_callback(
        mdi_swflash_predraw pre_blt_callback, 
        mdi_swflash_postdraw post_blt_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mdi_swflash_p->pre_blt = pre_blt_callback;
    mdi_swflash_p->post_blt= post_blt_callback;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_transform_info
* DESCRIPTION
*  store the attribute of works to screen string buffer 
* PARAMETERS
*  str        [in] print string pointer
* RETURNS
*  MDI_RESULT whether transform succeed
*****************************************************************************/
MDI_RESULT mdi_swflash_transform_info(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = -1;
    unsigned char* cpname=NULL;
    s3w_data_info data_info;
    s3_char_set_type charset;
    S8 swflash_size[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /*player init*/
    
    s3wi_memory_init((char *)mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
	
    data_info.data_type = S3W_DATA_MEMORY;
    data_info.file_type = S3W_CONTENTS_FILE;
    data_info.file_url[0] = 0x00;
    data_info.stream = mdi_swflash_p->decipher_buffer;
    data_info.stream_size = mdi_swflash_p->size;
    data_info.stream_self_free = 0;
    
    ret=s3h_isValidFile(NULL, &data_info);
	if(ret !=1)
	{
        return MDI_RES_SWFLASH_ERR_FILE_ERROR;
	}  
    
    mdi_swflash_p->instance = s3wi_create(mdi_swflash_p, NULL, 
		MMI_SWFLASH_MEM_BUFFER_SIZE*0.8, MMI_SWFLASH_PERFORMANCE);
    if(mdi_swflash_p->instance == NULL)
    {
        return MDI_RES_SWFLASH_ERR_CREATE_INSTANCE;
    }
	
	
    ret=s3wi_load(mdi_swflash_p->instance, &data_info, S3W_DATA_MEMORY,
		TRUE, FALSE);
    if(ret == 0)
    {
        return MDI_RES_SWFLASH_ERR_LOAD;
    }
	
    /*get cp name:only load success, then s3wi_extract_cpcode can run*/
    ret = s3wi_extract_cpcode(mdi_swflash_p->instance, NULL,NULL);
    if(ret != 0)
    {  
        media_get_ext_buffer_cacheable(MOD_MMI, (void **)&(cpname), sizeof(unsigned char)*ret+2);
		memset(cpname,0,sizeof(unsigned char)*ret+2);
        s3wi_extract_cpcode(mdi_swflash_p->instance, cpname,&charset);
        mmi_ucs2cpy(wgui_swflash_info.company, (S8*)cpname);
    }
    else
    {
        memset(wgui_swflash_info.company,0,MMI_SWFLASH_MAX_STR_LEN);
    }
	
    /*fill in other info*/
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_TITLE));
    if(wgui_swflash_info.title != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.title);
    }
    
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY));
	
    switch (wgui_swflash_info.type)
    {
		
	case MMI_SWFLASH_TYPE_ANIMATION:
		mmi_ucs2cat(str, (PS8) L" ");
		mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_ANIMATION));
		break;
	case MMI_SWFLASH_TYPE_GAME:
		mmi_ucs2cat(str, (PS8) L" ");
		mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_CRAZYGAME));
		break;
		
	case MMI_SWFLASH_TYPE_KALAOK:
		mmi_ucs2cat(str, (PS8) L" ");
		mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_KARAOK));
		break;
		
	case MMI_SWFLASH_TYPE_MTV:
		mmi_ucs2cat(str, (PS8) L" ");
		mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_MOVIECLIP));
		break;
	default:
		mmi_ucs2cat(str, (PS8) L" ");
		mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_UNKNOWN));
		break;
    }
	
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_SIZE));
	
    mmi_ucs2cat(str, (PS8) L" ");
    sprintf(swflash_size, "%u", wgui_swflash_info.size);
    mmi_asc_to_ucs2((PS8) & str[mmi_ucs2strlen((PS8) str) << 1],(PS8) swflash_size);
    mmi_ucs2cat(str, (PS8) L" ");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_BYTE));
    
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_DATE));
	
    if (wgui_swflash_info.date != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.date);
    }
	
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_TIME));
	
    if (wgui_swflash_info.time != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.time);
    }
	
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_COMPANY));
	
    if (wgui_swflash_info.company != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.company);
    }
    
    mmi_ucs2cat(str, (PS8) L"\0");
	
    if(cpname != NULL)
    {
		media_free_ext_buffer(MOD_MMI, (void **)&(cpname));
    }
	
    s3wi_unload(mdi_swflash_p->instance);
    s3wi_release(mdi_swflash_p->instance);
    mdi_swflash_p->instance = NULL;
    return MDI_RES_SWFLASH_SUCCEED;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_down_event
* DESCRIPTION
*  transfer pen_down_event to vis engine
* PARAMETERS
*  pos       [IN]coordinate        
* RETURNS
*  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
*****************************************************************************/
MMI_BOOL mdi_swflash_pen_down_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_DN, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_up_event
* DESCRIPTION
*  transfer pen_down_event to vis engine
* PARAMETERS
*  pos       [IN]coordinate        
* RETURNS
*  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
*****************************************************************************/
MMI_BOOL mdi_swflash_pen_up_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_UP, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_move_event
* DESCRIPTION
*  transfer pen_down_event to vis engine
* PARAMETERS
*  pos       [IN]coordinate        
* RETURNS
*  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
*  
*****************************************************************************/
MMI_BOOL mdi_swflash_pen_move_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_UP_MOVE, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    
	
}
#endif

/*****************************************************************************
* FUNCTION
*  mdi_swflash_init_data
* DESCRIPTION
*  initial parameter
*  This parameter is set according to the need of each category
* PARAMETERS
*  data_ptr       [IN]     parameter from category        
* RETURNS
*  void  
*****************************************************************************/
void mdi_swflash_init_data(mdi_swflash_para* data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->para_ptr = data_ptr;
    
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_change_play_mode
* DESCRIPTION
*  SWFlash default mode is player.
*  This function changes mode according user definition
* PARAMETERS
*  data_ptr       [IN]     parameter from category        
* RETURNS
*  void  
*****************************************************************************/
void mdi_swflash_change_play_purpose(S32 play_purpose)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->play_purpose = play_purpose;
}


/*****************************************************************************
* FUNCTION
*  mdi_swflash_get_play_mode
* DESCRIPTION
*  Get swflash player purpose
* PARAMETERS
*  void        
* RETURNS
*  S32  
*****************************************************************************/
S32 mdi_swflash_get_play_purpose(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mdi_swflash_p->play_purpose);
}
#endif /*SWFLASH_NEOMTEL*/
#endif /* defined(__MMI_SWFLASH__) */ 

