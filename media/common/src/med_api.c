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
 *   med_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_smalloc.h"
#include "med_utility.h"
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "tvo_main.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "app_mem_med.h"


/*****************************************************************************
 * FUNCTION
 *  media_get_int_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  buffer_p        [IN]        
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_get_int_buffer_ext(module_type src_mod_id, void **buffer_p, kal_uint32 buffer_size, char* file_p,long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ptr = (void*)med_alloc_int_mem_ext(buffer_size, file_p, line_p);
    (*buffer_p)= ptr;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_free_int_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  buffer_p        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_free_int_buffer_ext(module_type src_mod_id, void **buffer_p, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_free_int_mem_ext(buffer_p,file_p,line_p);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_get_ext_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  buffer_p        [IN]        
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_get_ext_buffer_ext(module_type src_mod_id, void **buffer_p, kal_uint32 buffer_size, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__)
    (*buffer_p) = applib_asm_alloc_nc_r_dbg(0, buffer_size, file_p, line_p);
#else

    (*buffer_p) = (void*)med_alloc_ext_mem_ext(buffer_size, MED_EXT_MEMORY_TYPE_NONCACHEABLE,file_p, line_p);

#endif /* __MED_IN_ASM__ */
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_free_ext_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  buffer_p        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_free_ext_buffer_ext(module_type src_mod_id, void **buffer_p, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__)
    applib_asm_free_r_dbg(0, *buffer_p, file_p, line_p);
    *buffer_p = NULL;
#else
    
    med_free_ext_mem_ext(buffer_p,file_p,line_p);

#endif
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_get_ext_buffer_with_property
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  property        [IN]
 *  buffer_p        [IN]        
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_get_ext_buffer_with_property(module_type src_mod_id, kal_uint8 location, void **buffer_p, kal_uint32 buffer_size, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__)
    if (location == MED_EXT_MEMORY_TYPE_CACHEABLE || location == MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE)
    {
        (*buffer_p) = applib_asm_alloc_r_dbg(0, buffer_size, file_p, line_p);
    }
    else if (location == MED_EXT_MEMORY_TYPE_FRAMEBUFFER || location == MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE)
    {
        (*buffer_p) = applib_asm_alloc_nc_r_dbg(0, buffer_size, file_p, line_p);
    }
#else
	
    (*buffer_p)= (void*)med_alloc_ext_mem_ext(buffer_size, location,file_p, line_p);
	
#endif
    return MED_RES_OK;
}


#endif /* MED_NOT_PRESENT */ 

