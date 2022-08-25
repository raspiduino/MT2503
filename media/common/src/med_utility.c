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
 * med_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of media task.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "kal_trace.h"
#include "app_ltlcom.h" /* Task message communiction */

/* global includes */
#include "l1audio.h"

/* local includes */
#include "med_main.h"
#include "med_global.h"
#include "med_mem.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_smalloc.h"
#include "med_utility.h"
#include "med_trc.h"

#include "mpl_common.h" // the common defition for MPL


#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "med_mem.h"
#include "stdio.h"
#include "stack_config.h"
#include "fs_type.h"
#include "fs_func.h"

#if defined(__DRM_SUPPORT__)
#include "Drm_gprot.h"
#endif

#define POOL_LOCK  (1)

#if defined(__MED_STREAM_MOD__)
#define SMP_LOCK_COUNT     (1)
#define SMP_EVENT_COUNT    (0)
#else
#define SMP_LOCK_COUNT     (0)
#define SMP_EVENT_COUNT    (0)
#endif

#if defined(__MED_ATV_MOD__)
    #define MTV_LOCK_COUNT_FG   (0)
    #define MTV_LOCK_COUNT_BG   (0)
    #define MTV_EVENT_COUNT    (1)
#elif defined(__MED_MTV_MOD__)
    #define MTV_LOCK_COUNT_FG   (1 + 3)  // player 1, CMMB/MBBMS ESG 3
    #ifdef __CMMB_CAS_MBBMS_SUPPORT__
        #define MTV_LOCK_COUNT_BG   (3)       // MBBMS reminder
    #else
        #define MTV_LOCK_COUNT_BG   (0)
    #endif
    #ifdef __CMMB_DS_SUPPORT__
        #define MTV_EVENT_COUNT    (1)
    #else
        #define MTV_EVENT_COUNT    (0)
    #endif    
#else
    #define MTV_LOCK_COUNT_FG   (0)
    #define MTV_LOCK_COUNT_BG   (0)
    #define MTV_EVENT_COUNT    (0)
#endif

/* Media Provider total resource */
#define MP_LOCK_COUNT (SMP_LOCK_COUNT)
#define MP_EVENT_COUNT (SMP_EVENT_COUNT)

/* MED total resource */
#define MED_LOCK_COUNT (POOL_LOCK + MTV_LOCK_COUNT_FG + MAXOF(MP_LOCK_COUNT, MTV_LOCK_COUNT_BG))
#define MED_EVENT_COUNT (MP_EVENT_COUNT + MTV_EVENT_COUNT)

/* convert to total resource */
#define RES_LOCK_COUNT (MED_LOCK_COUNT)
#if MED_EVENT_COUNT == 0
    #define RES_EVENT_COUNT (1)    // for compile
#else
    #define RES_EVENT_COUNT (MED_EVENT_COUNT)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

typedef struct
{
    kal_mutexid pool_lock;
    kal_mutexid locks[RES_LOCK_COUNT];
    kal_eventgrpid events[RES_EVENT_COUNT];

} med_resource_context_t;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
}
timer_table_struct;

timer_table_struct med_timer_table[MAX_NUM_OF_MED_TIMER];
kal_mutexid med_mem_mutex;

#if 1 //ndef MED_LOW /*Always turn on this utility*/
/*****************************************************************************
 * FUNCTION
 *  med_util_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        (>=4)
 *  src             [?]         
 *  src_size        [IN]        (>=1) it is used to prevent from infinte loop when src data are not utf8
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnt, c;
    kal_uint16 ucs2;
    kal_uint32 dest_count = 0;
    kal_uint32 src_count = 0;
    kal_uint8 utf8_bytes_per_char[16] = {1, 1, 1, 1, 1, 1, 1, 1,
                                         0, 0, 0, 0, 2, 2, 3, 4 };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_size -= ((dest_size % 2) + 2); /* make it a even number + null terminator */

    while ((dest_count < dest_size) && (src_count < src_size) && ((c = *src) != 0))
    {
        cnt = utf8_bytes_per_char[c >> 4];
        switch (cnt)
        {
            case 1:
                dest[dest_count] = c;
                dest[dest_count + 1] = 0;
                dest_count += 2;
                src++;
                src_count++;
                break;
            case 2:
                ucs2 = ((kal_uint16) (c & 0x1F) << 6) | (kal_uint16) (src[1] & 0x3F);
                dest[dest_count] = ucs2 & 0xFF;
                dest[dest_count + 1] = ucs2 >> 8;
                dest_count += 2;
                src += 2;
                src_count += 2;
                break;
            case 3:
                ucs2 =
                    ((kal_uint16) (c & 0x0F) << 12) | ((kal_uint16) (src[1] & 0x3F) << 6) | (kal_uint16) (src[2] &
                                                                                                          0x3F);
                dest[dest_count] = ucs2 & 0xFF;
                dest[dest_count + 1] = ucs2 >> 8;
                dest_count += 2;
                src += 3;
                src_count += 3;
                break;
            case 4:
                src += 4;   /* skip it since we don't support UCS4 */
                src_count += 4;
                break;
            case 0:
                src++;      /* something wrong with the src, skip it */
                src_count++;
                break;
        }
    }
    dest[dest_count] = 0;
    dest[dest_count + 1] = 0;
    return dest_count + 2;
}


/*****************************************************************************
 * FUNCTION
 *  med_util_ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        (>=1)
 *  src             [?]         
 *  src_size        [IN]        (>=2)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 med_util_ucs2_to_utf8(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 lb, hb;
    kal_uint32 dest_count = 0;
    kal_uint32 src_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_size -= 1; /* one byte space for null terminator */

    lb = src[0];
    hb = src[1];
    while (dest_count < dest_size && src_count < src_size &&    /* not exceed limited size */
           (lb != 0 || hb != 0))    /* src does not encounter null terminator */
    {
        if (hb == 0 && (lb & 0x80) == 0)
        {
            dest[dest_count++] = lb;
        }
        else
        {
            if (hb & 0xF8 == 0)
            {
                dest[dest_count++] = 0xC0 | (hb << 2) | (lb >> 6);
            }
            else
            {
                dest[dest_count++] = 0xE0 | (hb >> 4);
                dest[dest_count++] = 0x80 | ((hb & 0x0F) << 2) | (lb >> 6);
            }
            dest[dest_count++] = 0x80 | (lb & 0x3F);
        }
        src_count += 2;
        lb = src[src_count];
        hb = src[src_count + 1];
    }
    dest[dest_count] = 0;
    return dest_count + 1;
}

#endif /* MED_LOW */ 



/*****************************************************************************
 * Declaration
 *****************************************************************************/
static med_resource_context_t g_med_resource_context;


/*****************************************************************************
 * Private Function
 *****************************************************************************/
static kal_mutexid med_get_lock_unprotected(void)
{
    kal_uint32 i;
    kal_mutexid lock = NULL;

    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.locks); i++)
    {
        if (g_med_resource_context.locks[i] != NULL)
        {
            lock = g_med_resource_context.locks[i];
            g_med_resource_context.locks[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_med_resource_context.locks));

    return lock;
}

kal_mutexid med_get_lock(void)
{
    kal_mutexid lock = NULL;

    kal_take_mutex(g_med_resource_context.pool_lock);

    lock = med_get_lock_unprotected();

    kal_give_mutex(g_med_resource_context.pool_lock);

    return lock;
}

void med_return_lock(kal_mutexid lock)
{
    kal_uint32 i;

    kal_take_mutex(g_med_resource_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.locks); i++)
    {
        if (g_med_resource_context.locks[i] == NULL)
        {
            g_med_resource_context.locks[i] = lock;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_med_resource_context.locks));

    kal_give_mutex(g_med_resource_context.pool_lock);
}

kal_eventgrpid med_get_event(void)
{
    kal_uint32 i;
    kal_eventgrpid event = NULL;

    kal_take_mutex(g_med_resource_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.events); i++)
    {
        if (g_med_resource_context.events[i] != NULL)
        {
            event = g_med_resource_context.events[i];
            g_med_resource_context.events[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_med_resource_context.events));

    kal_give_mutex(g_med_resource_context.pool_lock);

    return event;
}

void med_return_event(kal_eventgrpid event)
{
    kal_uint32 i;

    kal_take_mutex(g_med_resource_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.events); i++)
    {
        if (g_med_resource_context.events[i] == NULL)
        {
            g_med_resource_context.events[i] = event;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_med_resource_context.events));

    kal_give_mutex(g_med_resource_context.pool_lock);
}

#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

/*****************************************************************************
 * FUNCTION
 *  med_utility_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_utility_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_char lock_name[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_NUM_OF_MED_TIMER; i++)
    {
        med_timer_table[i].event_id = NULL;
    }

    /* init external memory */
    med_set_ext_memory_pool((unsigned char*)med_context_p->ext_mem_p, MED_EXT_MEM_SIZE);

    /* init audio memory */
    med_set_aud_memory_pool((unsigned char*)med_context_p->aud_mem_p, MED_AUD_MEM_SIZE);

    /* init video memory */
    #ifdef __VIDEO_STANDALONE_MEMORY__
    med_set_vid_memory_pool((unsigned char*)med_context_p->vid_mem_p, MED_VID_MEM_SIZE);
    #endif
    
    med_mem_mutex = kal_create_mutex("MED MEM");

    /* init lock pool */
    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.locks); i++)
    {
        sprintf(lock_name, "MEDLK%d", i);
        g_med_resource_context.locks[i] = kal_create_mutex(lock_name);
    }

    /* init event pool */
    for (i = 0; i < ARRAY_SIZE(g_med_resource_context.events); i++)
    {
        sprintf(lock_name, "MEDEV%d", i);
        g_med_resource_context.events[i] = kal_create_event_group(lock_name);
    }

    /* shared lock for lock pool */
    g_med_resource_context.pool_lock = med_get_lock_unprotected();
    return KAL_TRUE;
}

#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  med_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == MED_BASE_TIMER_ID)
    {
        /* Execute event's timeout handler */
        evshed_timer_handler(med_context_p->event_scheduler_ptr);
    }
}



/*****************************************************************************
 * FUNCTION
 *  med_timer_expiry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_MED_TIMER)
    {
        med_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (med_timer_table[(kal_uint32) (timer_id)].callback_func) (med_timer_table[(kal_uint32) (timer_id)].arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id            [IN]        
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void med_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (period * 7) >> 5;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == 0)
    {
        temp = 1;
    }
    med_timer_table[timer_id].callback_func = timer_expiry;
    med_timer_table[timer_id].arg = arg;
    med_timer_table[timer_id].event_id = evshed_set_event(
                                            med_context_p->event_scheduler_ptr,
                                            (kal_timer_func_ptr) med_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  med_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (med_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(med_context_p->event_scheduler_ptr, &(med_timer_table[timer_id].event_id));
        med_timer_table[timer_id].event_id = NULL;
    }

}

#define MED_INT_MEM_INVALID_ADDR 0xFFFFFFF0
/*****************************************************************************
 * FUNCTION
 *  med_alloc_int_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_int_mem_ext(kal_int32 size,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return (address_t)MED_INT_MEM_INVALID_ADDR;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_int_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_int_mem_ext(void **pointer,char* file_p, long line_p)
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
 *  med_alloc_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_ext_mem_ext(kal_int32 size, kal_uint8 location, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__)
	if (location == MED_EXT_MEMORY_TYPE_NONCACHEABLE || location == MED_EXT_MEMORY_TYPE_FRAMEBUFFER || location == MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE)
	{
		p = applib_asm_alloc_nc_r_dbg(0, size, file_p, line_p);
	}
	else if (location == MED_EXT_MEMORY_TYPE_CACHEABLE || location == MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE)
	{
		p = applib_asm_alloc_r_dbg(0, size, file_p, line_p);
	}
	else
	{
		kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] get buffer from: %s, %d",file_p,line_p);
		kal_take_mutex(med_mem_mutex);
		p = (void*)med_ext_smalloc_ext((size_type) size, location, file_p, line_p);
		kal_give_mutex(med_mem_mutex);

		/* remove ASSERT, let MED control the fail case */
		/* ASSERT(p != NULL); */
	}
#else
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] get buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    p = (void*)med_ext_smalloc_ext((size_type) size, location, file_p, line_p);
    kal_give_mutex(med_mem_mutex);

    /* remove ASSERT, let MED control the fail case */
    /* ASSERT(p != NULL); */
#endif
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_ext_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__)
    applib_asm_free_r_dbg(0, *pointer, file_p, line_p);
	*pointer = NULL;
#else
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] free buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_ext_sfree((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  med_free_aud_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_aud_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][AUD] free buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_aud_sfree((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_vid_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_vid_mem_ext(void **pointer,char* file_p, long line_p)
{
#ifdef __VIDEO_STANDALONE_MEMORY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][VID] free buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_vid_sfree((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  med_alloc_temp_ext_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *_med_alloc_temp_ext_mem(kal_int32 size, unsigned short location, void (*callback)(void*),char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] get temp buffer from: %s, %d",file_p,line_p);

    kal_take_mutex(med_mem_mutex);
    p = (void*)med_ext_smalloc_temp((size_type) size, location, callback, file_p, line_p);
    kal_give_mutex(med_mem_mutex);

    return p;


}


/*****************************************************************************
 * FUNCTION
 *  med_alloc_temp_ext_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_temp_ext_mem_ext(kal_int32 size, void (*callback)(void*), char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _med_alloc_temp_ext_mem(size, MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE, callback, file_p, line_p);
}

/*****************************************************************************
 * FUNCTION
 *  med_alloc_temp_ext_mem_ext_nc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void *med_alloc_temp_ext_mem_ext_nc(kal_int32 size, void (*callback)(void*), char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return _med_alloc_temp_ext_mem(size, MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE, callback, file_p, line_p);;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_temp_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_temp_ext_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] free temp buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_ext_sfree_temp((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  med_release_temp_ext_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_release_temp_ext_mem_ext(kal_int32 size,char* file_p, long line_p)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MED, TRACE_INFO, "[MED][EXT] release temp buffer: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_ext_release_temporyary(size);
    kal_give_mutex(med_mem_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  med_check_disc_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_name        [?]         
 *  free_byte       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(dir, 0, 6);
    kal_mem_cpy(dir, dir_name, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) < free_byte)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OK;
        }
    }
    else
    {
        return MED_RES_NO_DISC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_get_media_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 med_get_media_type(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;
    kal_wchar temp[6];
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = file_name + kal_wstrlen(file_name) - 5;

    kal_mem_cpy(temp, p, 2 * 6);

    for (i = 0; i < 5; i++)
    {
        if (temp[i] >= 97 /* 'a' */  && temp[i] <= 122 /* 'z' */ )
        {
            temp[i] -= 32 /* ('a'-'A') */ ;
        }
    }

    p = &temp[2];
#ifdef __VM_CODEC_SUPPORT__
    if (kal_wstrcmp(p, L".VM") == 0)
    {
        return MED_TYPE_GSM_EFR;
    }
#endif /*__VM_CODEC_SUPPORT__*/
#ifdef AU_DECODE
    if (kal_wstrcmp(p, L".AU") == 0)
    {
        return MED_TYPE_AU;
    }
#endif /* AU_DECODE */ 

    p = &temp[1];
    if (kal_wstrcmp(p, L".IMY") == 0)
    {
        return MED_TYPE_IMELODY;
    }
    if (kal_wstrcmp(p, L".MID") == 0)
    {
        return MED_TYPE_SMF;
    }
    if (kal_wstrcmp(p, L".WAV") == 0)
    {
        return MED_TYPE_WAV;
    }
#if defined(YAMAHA_MA3)
    if (kal_wstrcmp(p, L".MMF") == 0)
    {
        return MED_TYPE_MMF;
    }
#endif /* defined(YAMAHA_MA3)*/ 
    if (kal_wstrcmp(p, L".PCM") == 0)
    {
        return MED_TYPE_PCM_8K;
    }
    if (kal_wstrcmp(p, L".DVI") == 0)
    {
        return MED_TYPE_DVI_ADPCM;
    }

#ifdef DAF_DECODE
    if (kal_wstrcmp(p, L".MP3") == 0)
    {
        return MED_TYPE_DAF;
    }
    if (kal_wstrcmp(p, L".MP2") == 0)
    {
        return MED_TYPE_MUSICAM;
    }
#endif /* DAF_DECODE */ 
#ifdef AMR_DECODE
    if (kal_wstrcmp(p, L".AMR") == 0)
    {
        return MED_TYPE_AMR;
    }
#endif /* AMR_DECODE */
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
    if (kal_wstrcmp(p, L".AWB") == 0)
    {
        return MED_TYPE_AMR_WB;
    }
#endif /* defined(AMRWB_DECODE) || defined(AMRWB_ENCODE) */ 
#ifdef AAC_DECODE
    if (kal_wstrcmp(p, L".AAC") == 0)
    {
        return MED_TYPE_AAC;
    }
#endif /* AAC_DECODE */
#ifdef M4A_DECODE
    if (kal_wstrcmp(p, L".M4A") == 0)
    {
        return MED_TYPE_M4A;
    }
#endif /* M4A_DECODE */
#ifdef __APE_DECODE__
    if (kal_wstrcmp(p, L".APE") == 0)
    {
        return MED_TYPE_APE;
    }
#endif /* __APE_DECODE__ */

#ifdef __VORBIS_DECODE__
    if (kal_wstrcmp(p, L".OGG") == 0)
    {
        return MED_TYPE_VORBIS;
    }
#endif

#if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
    if (kal_wstrcmp(p, L".MP4") == 0)
    {
        return MED_TYPE_MP4;
    }
    if (kal_wstrcmp(p, L".MPG") == 0)
    {
        return MED_TYPE_MP4;
    }
    if (kal_wstrcmp(p, L".3GP") == 0)
    {
        return MED_TYPE_3GP;
    }
    if (kal_wstrcmp(p, L".3G2") == 0)
    {
        return MED_TYPE_3GP;
    }
    if (kal_wstrcmp(p, L".3GA") == 0)
    {
        return MED_TYPE_3GP;
    }
#endif /* MED_PURE_AUDIO */

#if defined(JPG_DECODE) || defined(JPG_ENCODE)
    if (kal_wstrcmp(p, L".JPG") == 0)
    {
        return MED_TYPE_JPG;
    }
#endif /* defined(JPG_DECODE) || defined(JPG_ENCODE) */ 
#if defined(GIF_DECODE)
    if (kal_wstrcmp(p, L".JPG") == 0)
    {
        return MED_TYPE_GIF;
    }
#endif /* defined(GIF_DECODE) */ 
#ifdef AIFF_DECODE
    if (kal_wstrcmp(p, L".AIF") == 0)
    {
        return MED_TYPE_AIFF;
    }
#endif /* AIFF_DECODE */
#ifdef SND_DECODE
    if (kal_wstrcmp(p, L".SND") == 0)
    {
        return MED_TYPE_NONE;
    }
#endif /* SND_DECODE */

#if defined(__MED_VR_MOD__) && defined(__VM_CODEC_SUPPORT__)
    if (kal_wstrcmp(p, L".VRD") == 0)
    {
        return MED_TYPE_VR;
    }
#endif /* __MED_VR_MOD__ && __VM_CODEC_SUPPORT__ */ 

#ifdef WMA_DECODE
    if (kal_wstrcmp(p, L".WMA") == 0)
    {
        return MED_TYPE_WMA;
    }
#endif /* WMA_DECODE */ 

#ifdef __DRM_SUPPORT__
    if (
#ifdef __DRM_V02__
    /* Make sure it is not multi-part ODF */
        (kal_wstrcmp(p, L".ODF") == 0 && !DRM_is_archive(0, file_name))||
#endif            
        kal_wstrcmp(p+1, L".DM") == 0 ||
        kal_wstrcmp(p, L".DCF") == 0)
    {
        kal_char *ext = NULL;
        kal_wchar temp_file_name[10];
        
        /* Single part ODF , get single part ODF content extension name */
        ext = (kal_char *)DRM_get_content_ext(0, file_name);
        
        if(ext != NULL)
        {
            kal_wsprintf(temp_file_name, "A.%s", ext);
            return med_get_media_type(temp_file_name);
        }
        else
        {
            return MED_TYPE_NONE;
        }
    }

#endif /* defined(__DRM_SUPPORT__) */

    p = &temp[0];
#ifdef AIFF_DECODE
    if (kal_wstrcmp(p, L".AIFF") == 0 || kal_wstrcmp(p, L".AIFC") == 0)
    {
        return MED_TYPE_AIFF;
    }
#endif /* AIFF_DECODE */
    if (kal_wstrcmp(p, L".MIDI") == 0)
    {
        return MED_TYPE_SMF;
    }
#ifdef BSAC_DECODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BSAC_DECODE */
#ifdef __FLAC_DECODE__
    if (kal_wstrcmp(p, L".FLAC") == 0)
    {
        return MED_TYPE_FLAC;
    }
#endif
#if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
    if (kal_wstrcmp(p, L".3GPP") == 0)
    {
        return MED_TYPE_3GP;
    }
#endif /* MED_PURE_AUDIO */

#if defined(__RM_DEC_SUPPORT__)
    p = &temp[0];
    if (kal_wstrcmp(p, L".RMVB") == 0)
    {
        return MED_TYPE_RMVB;
    }
    
    p = &temp[2];
    if (kal_wstrcmp(p, L".RM") == 0)
    {
        return MED_TYPE_RM;
    }
    if (kal_wstrcmp(p, L".RA") == 0)
    {
        return MED_TYPE_RA;
    }
    if (kal_wstrcmp(p, L".RV") == 0)
    {
        return MED_TYPE_RV;
    }
#endif /* __RM_DEC_SUPPORT__ */
            
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    p = &temp[1];
    if (kal_wstrcmp(p, L".FLV") == 0)
    {
        return MED_TYPE_FLV;
    }
    if (kal_wstrcmp(p, L".F4V") == 0)
    {
        return MED_TYPE_F4V;
    }
    if (kal_wstrcmp(p, L".F4A") == 0)
    {
        return MED_TYPE_F4A;
    }
#endif /*__FLV_FILE_FORMAT_SUPPORT__*/




    return MED_TYPE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  med_get_media_type_from_mma_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 med_get_media_type_from_mma_type(kal_uint8 mma_type)
{
#ifdef __MED_MMA_MOD__
    switch(mma_type)
    {
        case MMA_TYPE_MIDI:      return MED_TYPE_SMF;
        case MMA_TYPE_TONE:      return MED_TYPE_TONE;
        case MMA_TYPE_WAV:       return MED_TYPE_WAV;
        case MMA_TYPE_IMY:       return MED_TYPE_IMELODY;
        case MMA_TYPE_AMR:       return MED_TYPE_AMR;
        case MMA_TYPE_DAF:       return MED_TYPE_DAF;
        case MMA_TYPE_MUSICAM:   return MED_TYPE_MUSICAM;
        case MMA_TYPE_AAC:       return MED_TYPE_AAC;
        case MMA_TYPE_AU:        return MED_TYPE_AU;
        case MMA_TYPE_AWB:       return MED_TYPE_AMR_WB;
        case MMA_TYPE_WMA:       return MED_TYPE_WMA;
        case MMA_TYPE_M4A:       return MED_TYPE_M4A;
        case MMA_TYPE_AIFF:      return MED_TYPE_AIFF;
        case MMA_TYPE_RA:        return MED_TYPE_RA;
        case MMA_TYPE_RM:        return MED_TYPE_RM;
        case MMA_TYPE_RMVB:      return MED_TYPE_RMVB;
        case MMA_TYPE_RV:        return MED_TYPE_RV;
        case MMA_TYPE_APE:       return MED_TYPE_APE;
        case MMA_TYPE_FLV:       return MED_TYPE_FLV;
        case MMA_TYPE_F4V:       return MED_TYPE_F4V;
        case MMA_TYPE_F4A:       return MED_TYPE_F4A;
        case MMA_TYPE_VORBIS:    return MED_TYPE_VORBIS;
        case MMA_TYPE_FLAC:      return MED_TYPE_FLAC;
        default:                 return MED_TYPE_NONE;
    }
#endif /*__MED_MMA_MOD__*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  med_get_mma_type_from_media_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 med_get_mma_type_from_media_type(kal_uint8 media_type)
{
#ifdef __MED_MMA_MOD__
    switch(media_type)
    {
        case MED_TYPE_SMF:       return MMA_TYPE_MIDI;
        case MED_TYPE_WAV:       return MMA_TYPE_WAV;
        case MED_TYPE_IMELODY:   return MMA_TYPE_IMY;
        case MED_TYPE_AMR:       return MMA_TYPE_AMR;
        case MED_TYPE_DAF:       return MMA_TYPE_DAF;
        case MED_TYPE_MUSICAM:   return MMA_TYPE_MUSICAM;
        case MED_TYPE_AAC:       return MMA_TYPE_AAC;
        case MED_TYPE_AU:        return MMA_TYPE_AU;
        case MED_TYPE_AMR_WB:    return MMA_TYPE_AWB;
        case MED_TYPE_WMA:       return MMA_TYPE_WMA;
        case MED_TYPE_M4A:       return MMA_TYPE_M4A;
        case MED_TYPE_AIFF:      return MMA_TYPE_AIFF;
        case MED_TYPE_RA:        return MMA_TYPE_RA;
        case MED_TYPE_RM:        return MMA_TYPE_RM;
        case MED_TYPE_RMVB:      return MMA_TYPE_RMVB;
        case MED_TYPE_RV:        return MMA_TYPE_RV;
        case MED_TYPE_APE:       return MMA_TYPE_APE;
        case MED_TYPE_FLV:       return MMA_TYPE_FLV;
        case MED_TYPE_F4V:       return MMA_TYPE_F4V;
        case MED_TYPE_F4A:       return MMA_TYPE_F4A;
        case MED_TYPE_VORBIS:    return MMA_TYPE_VORBIS;
        case MED_TYPE_FLAC:      return MMA_TYPE_FLAC;
        default:                 return -1; /* Unknown */
    }
#endif /*__MED_MMA_MOD__*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  med_get_media_format_from_codec_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 med_get_media_format_from_codec_type(kal_uint16 codec_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format format = MEDIA_FORMAT_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (codec_type)
    {
        case MEDIA_CODEC_AUD_RA_8_LBR:
            format = MEDIA_FORMAT_COOK;
            break;
        case MEDIA_CODEC_AUD_AAC:
            format = MEDIA_FORMAT_AAC;
            break;
        case MEDIA_CODEC_AUD_HE_AAC:
            format = MEDIA_FORMAT_AAC_PLUS;
            break;
        case MEDIA_CODEC_AUD_AMR:
            format = MEDIA_FORMAT_AMR;
            break;
        case MEDIA_CODEC_AUD_AMR_WB:
            format = MEDIA_FORMAT_AMR_WB;
            break;
        case MEDIA_CODEC_AUD_BSAC:
            format = MEDIA_FORMAT_BSAC;
            break;
        case MEDIA_CODEC_AUD_PCM:
            format = MEDIA_FORMAT_PCM_8K;
            break;
        case MEDIA_CODEC_AUD_MPEGLAYER3:
            format = MEDIA_FORMAT_DAF;
            break;
        case MEDIA_CODEC_AUD_MPEG:
            format = MEDIA_FORMAT_MUSICAM;
            break;
        case MEDIA_CODEC_AUD_DRA:
            format = MEDIA_FORMAT_DRA;
            break;
        /* decoder does not support. Provider should fill it out */
        case MEDIA_CODEC_AUD_RA_VOICE:
        case MEDIA_CODEC_AUD_RA_8_HBR:
        default:
            ASSERT(0);
    }
    return format;
}

/*****************************************************************************
 * FUNCTION
 *  med_retrieve_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 *  path            [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_retrieve_file_path(kal_wchar *file_name, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(path, file_name);
    p = path + kal_wstrlen(path);
    while (p > path)
    {
        if (*p == L'\\')
        {
            *(p + 1) = 0;
            return KAL_TRUE;
        }
        p--;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  med_remove_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_remove_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = file_name + kal_wstrlen(file_name);
    while (p > file_name)
    {
        if (*p == L'\\')
        {
            *(p + 1) = 0;
            return KAL_TRUE;
        }
        p--;
    }
    return KAL_FALSE;
}

/* crc */
#ifdef __RICH_AUDIO_PROFILE__

static kal_uint32 const crc_table[256] = 
{
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL,
    0x076dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L,
    0x0edb8832L, 0x79dcb8a4L, 0xe0d5e91eL, 0x97d2d988L,
    0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L, 0x90bf1d91L,
    0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
    0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L,
    0x136c9856L, 0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL,
    0x14015c4fL, 0x63066cd9L, 0xfa0f3d63L, 0x8d080df5L,

    0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L, 0xa2677172L,
    0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
    0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L,
    0x32d86ce3L, 0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L,
    0x26d930acL, 0x51de003aL, 0xc8d75180L, 0xbfd06116L,
    0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L, 0xb8bda50fL,
    0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
    0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL,

    0x76dc4190L, 0x01db7106L, 0x98d220bcL, 0xefd5102aL,
    0x71b18589L, 0x06b6b51fL, 0x9fbfe4a5L, 0xe8b8d433L,
    0x7807c9a2L, 0x0f00f934L, 0x9609a88eL, 0xe10e9818L,
    0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
    0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL,
    0x6c0695edL, 0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L,
    0x65b0d9c6L, 0x12b7e950L, 0x8bbeb8eaL, 0xfcb9887cL,
    0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L, 0xfbd44c65L,

    0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
    0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL,
    0x4369e96aL, 0x346ed9fcL, 0xad678846L, 0xda60b8d0L,
    0x44042d73L, 0x33031de5L, 0xaa0a4c5fL, 0xdd0d7cc9L,
    0x5005713cL, 0x270241aaL, 0xbe0b1010L, 0xc90c2086L,
    0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
    0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L,
    0x59b33d17L, 0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL,

    0xedb88320L, 0x9abfb3b6L, 0x03b6e20cL, 0x74b1d29aL,
    0xead54739L, 0x9dd277afL, 0x04db2615L, 0x73dc1683L,
    0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
    0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L,
    0xf00f9344L, 0x8708a3d2L, 0x1e01f268L, 0x6906c2feL,
    0xf762575dL, 0x806567cbL, 0x196c3671L, 0x6e6b06e7L,
    0xfed41b76L, 0x89d32be0L, 0x10da7a5aL, 0x67dd4accL,
    0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,

    0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L,
    0xd1bb67f1L, 0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL,
    0xd80d2bdaL, 0xaf0a1b4cL, 0x36034af6L, 0x41047a60L,
    0xdf60efc3L, 0xa867df55L, 0x316e8eefL, 0x4669be79L,
    0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
    0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL,
    0xc5ba3bbeL, 0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L,
    0xc2d7ffa7L, 0xb5d0cf31L, 0x2cd99e8bL, 0x5bdeae1dL,

    0x9b64c2b0L, 0xec63f226L, 0x756aa39cL, 0x026d930aL,
    0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
    0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L,
    0x92d28e9bL, 0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L,
    0x86d3d2d4L, 0xf1d4e242L, 0x68ddb3f8L, 0x1fda836eL,
    0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L, 0x18b74777L,
    0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
    0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L,

    0xa00ae278L, 0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L,
    0xa7672661L, 0xd06016f7L, 0x4969474dL, 0x3e6e77dbL,
    0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L, 0x37d83bf0L,
    0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
    0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L,
    0xbad03605L, 0xcdd70693L, 0x54de5729L, 0x23d967bfL,
    0xb3667a2eL, 0xc4614ab8L, 0x5d681b02L, 0x2a6f2b94L,
    0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL, 0x2d02ef8dL
};

#endif /*__RICH_AUDIO_PROFILE__*/

/*
 * NAME: crc->calculate()
 * DESCRIPTION:   compute CRC-32 value (ISO 3309)
 */


/*****************************************************************************
 * FUNCTION
 *  med_crc_calculate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length)
{
#ifdef __RICH_AUDIO_PROFILE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register kal_uint32 crc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (crc = 0xffffffffL; length >= 8; length -= 8)
    {
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    }

    switch (length)
    {
        case 7:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 6:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 5:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 4:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 3:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 2:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 1:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 0:
            break;
    }

    return crc ^ 0xffffffffL;

#else /*__RICH_AUDIO_PROFILE__*/
    return 0;
#endif /*__RICH_AUDIO_PROFILE__*/

}



/*****************************************************************************
 * FUNCTION
 *  med_debug_print_result
 * DESCRIPTION
 *  print result to trace
 * PARAMETERS
 *  result        [IN]      result  
 * RETURNS
 *  void 
 *****************************************************************************/
void med_debug_print_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define SWITCH_CASE_RESULT_MACRO(__RES_NAME__)
#else
#define SWITCH_CASE_RESULT_MACRO(__RES_NAME__)\
    case MED_RES_##__RES_NAME__:\
        kal_trace(TRACE_GROUP_4, MED_TRC_RES_##__RES_NAME__, line);\
        break;
#endif    
    switch(result)
    {
        SWITCH_CASE_RESULT_MACRO(OK);                       /* 0 */
        SWITCH_CASE_RESULT_MACRO(FAIL);
        SWITCH_CASE_RESULT_MACRO(BUSY);
        SWITCH_CASE_RESULT_MACRO(DISC_FULL);
        SWITCH_CASE_RESULT_MACRO(OPEN_FILE_FAIL);
        SWITCH_CASE_RESULT_MACRO(END_OF_FILE);
        SWITCH_CASE_RESULT_MACRO(TERMINATED);
        SWITCH_CASE_RESULT_MACRO(BAD_FORMAT);
        SWITCH_CASE_RESULT_MACRO(INVALID_FORMAT);
        SWITCH_CASE_RESULT_MACRO(ERROR);
        SWITCH_CASE_RESULT_MACRO(NO_DISC);                  /* 10 */
        SWITCH_CASE_RESULT_MACRO(NOT_ENOUGH_SPACE);
        SWITCH_CASE_RESULT_MACRO(INVALID_HANDLE);
        SWITCH_CASE_RESULT_MACRO(NO_HANDLE);
        SWITCH_CASE_RESULT_MACRO(RESUME);
        SWITCH_CASE_RESULT_MACRO(BLOCKED);
        SWITCH_CASE_RESULT_MACRO(MEM_INSUFFICIENT);
        SWITCH_CASE_RESULT_MACRO(BUFFER_INSUFFICIENT);
        SWITCH_CASE_RESULT_MACRO(FILE_EXIST);
        SWITCH_CASE_RESULT_MACRO(WRITE_PROTECTION);
        SWITCH_CASE_RESULT_MACRO(PARAM_ERROR);              /* 20 */
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_CHANNEL);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_FREQ);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_TYPE);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_OPERATION);
        SWITCH_CASE_RESULT_MACRO(PARSER_ERROR);
        SWITCH_CASE_RESULT_MACRO(VIDEO_ERROR);
        SWITCH_CASE_RESULT_MACRO(AUDIO_ERROR);
        SWITCH_CASE_RESULT_MACRO(FSAL_ERROR);
        SWITCH_CASE_RESULT_MACRO(MP4_PRODUCER_ERROR);
        SWITCH_CASE_RESULT_MACRO(MP4_SAMPLEDATA_ERROR);     /* 30 */
        SWITCH_CASE_RESULT_MACRO(MP4_NO_VIDEO_TRACK);
        SWITCH_CASE_RESULT_MACRO(MP4_NO_AUDIO_TRACK);
        SWITCH_CASE_RESULT_MACRO(ID_MISMATCH);
        SWITCH_CASE_RESULT_MACRO(ID_EXIST);
        SWITCH_CASE_RESULT_MACRO(TRAINING_CONTINUE);
        SWITCH_CASE_RESULT_MACRO(NO_SOUND);
        SWITCH_CASE_RESULT_MACRO(TOO_SIMILAR);
        SWITCH_CASE_RESULT_MACRO(TOO_DIFFERENT);
        SWITCH_CASE_RESULT_MACRO(NO_MATCH);
        SWITCH_CASE_RESULT_MACRO(SPEAK_TOO_LONG);
        SWITCH_CASE_RESULT_MACRO(SPEAK_TOO_SHORT);          /* 40 */
        SWITCH_CASE_RESULT_MACRO(AUDIO_END);
        SWITCH_CASE_RESULT_MACRO(VIDEO_END);
        SWITCH_CASE_RESULT_MACRO(VIDEO_IMAGE_TOO_LARGE);
        SWITCH_CASE_RESULT_MACRO(VIDEO_FILE_TOO_LARGE);
        SWITCH_CASE_RESULT_MACRO(VIDEO_FRAME_RATE_TOO_HIGH);
        SWITCH_CASE_RESULT_MACRO(VRSI_OK);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_UNINITIALIZED);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_BUSY);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_MEM_INSUFFICIENT);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DATA_ERROR);       /* 50 */
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_LIBRARY_CORRUPT);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_BAD_GRAMMAR);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_LANG_NOT_SUPPORT);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_NO_MATCH_TAG);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_TTS_TOO_LONG);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_SESSION);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_NO_SOUND);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_CMD_TRN_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_CMD_RCG_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DGT_RCG_FAIL);     /* 60 */
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DGT_ADP_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_UNKNOWN);
        SWITCH_CASE_RESULT_MACRO(STOP_FM_RECORD);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_SPEED);
        SWITCH_CASE_RESULT_MACRO(A2DP_CLOSE);
        SWITCH_CASE_RESULT_MACRO(A2DP_DISCOVER_SEP_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_GET_SEP_CAP_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_NO_MATCH_CAP);
        SWITCH_CASE_RESULT_MACRO(A2DP_CONFIG_STREAM_FAIL);   /* 70 */
        SWITCH_CASE_RESULT_MACRO(A2DP_RECONFIG_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_OPEN_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_START_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_PAUSE_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(HFP_CLOSE);
        SWITCH_CASE_RESULT_MACRO(IMG_DECODE_TIME_OUT);
        SWITCH_CASE_RESULT_MACRO(ROOT_DIR_FULL);
        SWITCH_CASE_RESULT_MACRO(BR_IMAGE_ERROR);
        SWITCH_CASE_RESULT_MACRO(BR_MODULE_ERROR);
        SWITCH_CASE_RESULT_MACRO(BR_OUT_OF_MEMORY);     /* 80 */
        SWITCH_CASE_RESULT_MACRO(BR_OVER_VERSION);
        SWITCH_CASE_RESULT_MACRO(PDL_AUDIO_UNDERFLOW);
        SWITCH_CASE_RESULT_MACRO(PDL_VIDEO_UNDERFLOW);
        SWITCH_CASE_RESULT_MACRO(STREAM_BEARER_DISCONNECTED);
        SWITCH_CASE_RESULT_MACRO(STREAM_INVALID_SDP);    /* 85 */
        SWITCH_CASE_RESULT_MACRO(STREAM_RTSP_SET_CHANNEL_FAIL);
        SWITCH_CASE_RESULT_MACRO(STREAM_RTSP_REQUEST_FAIL);
        SWITCH_CASE_RESULT_MACRO(STREAM_PLAY_FINISH);
        SWITCH_CASE_RESULT_MACRO(STREAM_BUFFER_UNDERFLOW);
        SWITCH_CASE_RESULT_MACRO(STREAM_BUFFER_OVERFLOW);    /* 90 */
        SWITCH_CASE_RESULT_MACRO(STREAM_INVALID_RESOLUTION);
        SWITCH_CASE_RESULT_MACRO(STREAM_STOP_TIMEOUT);
        SWITCH_CASE_RESULT_MACRO(VDOEDT_ENCODE_FAIL);
        SWITCH_CASE_RESULT_MACRO(DECODER_NOT_SUPPORT);
        SWITCH_CASE_RESULT_MACRO(REACH_STOP_TIME);
        SWITCH_CASE_RESULT_MACRO(VIDEO_UNSUPPORT_DECODE_SIZE);
        SWITCH_CASE_RESULT_MACRO(VIDEO_ALREADY_STOPPED);
        default:
            kal_trace(TRACE_GROUP_4, MED_TRC_RES_UNKNOWN_ENUM, result, line);
            break;
    }
}  

med_result_enum med_error_to_result_enum(media_error_t ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_GROUP_4, VID_TRC_ERROR_TO_RET, ret);
    
    if (ret == MED_S_ASYNC)
    {
        return MED_RES_OK_ASYNC;
    }
    else if (ret == MED_S_TERMINATED)
    {
        return MED_RES_TERMINATED;
    }
    else if (ret == MED_E_CORRUPTED_DATA)
    {
        return MED_RES_INVALID_FORMAT;
    }
    else if (ret == MED_E_STREAM_UNSUPPORTED_BANDWIDTH)
    {
        return MED_RES_STREAM_UNSUPPORTED_BANDWIDTH;
    }
    else if (ret == MED_E_NO_REQUIRED_TRACK)
    {
        return MED_RES_NO_REQUIRED_TRACK;
    }
    else if (ret == MED_E_OVER_LIMIT || ret == MED_E_DECODER_NOT_SUPPORT)
    {
        return MED_RES_DECODER_NOT_SUPPORT;
    }
    else if (ret == MED_E_FRAME_RATE_TOO_HIGH)
    {
        return MED_RES_VIDEO_FRAME_RATE_TOO_HIGH;
    }
    else if (ret == MED_E_INVALID_RESOLUTION)
    {
        return MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE;
    }
    else if (ret == MED_E_MEM_INSUFFICIENT || ret == MED_E_OUT_OF_MEMORY)
    {
        return MED_RES_MEM_INSUFFICIENT;
    }
    else if (ret == MED_E_BAD_FORMAT)
    {
        return MED_RES_BAD_FORMAT;
    }
    else if (ret == MED_E_OPEN_FILE_FAIL)
    {
        return MED_RES_OPEN_FILE_FAIL;
    }
    else if (ret == MED_E_AUDIO_ERROR)
    {
        return MED_RES_AUDIO_ERROR;
    }
    else if (ret == MED_E_VIDEO_ERROR)
    {
        return MED_RES_VIDEO_ERROR;
    }
    else if (ret == MED_E_AUDIO_TRACK_ERROR) /* Only audio erorr */
    {
        return MED_RES_AUDIO_TRACK_ERROR;
    }
    else if (ret == MED_E_VIDEO_TRACK_ERROR) /* Only visual erorr */
    {
        return MED_RES_VIDEO_TRACK_ERROR;
    }
    else if (ret == MED_E_STOP_TIME_REACHED)
    {
        return MED_RES_STOP_TIME_REACHED;
    }
    else if (ret == MED_S_PLAY_FINISH)
    {
        return MED_RES_PLAY_FINISH;
    }
    else if (ret == MED_E_STREAM_BUFFER_UNDERFLOW)
    {
        return MED_RES_STREAM_BUFFER_UNDERFLOW;
    }
    else if (ret == MED_E_PDL_AUDIO_UNDERFLOW)
    {
        return MED_RES_PDL_AUDIO_UNDERFLOW;
    }
    else if (ret == MED_E_PDL_VIDEO_UNDERFLOW)
    {
        return MED_RES_PDL_VIDEO_UNDERFLOW;
    }
    else if (ret == MED_E_STREAM_BUFFER_OVERFLOW)
    {
        return MED_RES_STREAM_BUFFER_OVERFLOW;
    }
    else if (ret == MED_E_MP4_NO_VIDEO_TRACK)
    {
        return MED_RES_MP4_NO_VIDEO_TRACK;
    }
    else if (ret == MED_E_END_OF_FILE)
    {
        return MED_RES_END_OF_FILE;
    }
    else if (ret == MED_E_DISC_FULL)
    {
        return MED_RES_DISC_FULL;
    }
    else if (ret == MED_E_BUSY)
    {
        return  MED_RES_BUSY;
    }
    else if (ret == MED_E_SIZE_LIMIT_LESS_THAN_MIN_SIZE)
    {
        return MED_RES_BUFFER_INSUFFICIENT;
    }
    else if (ret == MED_E_VIDEO_NO_FRAME_ENCODED)
    {
        return MED_RES_VIDEO_NO_FRAME_ENCODED;
    }
    else if (ret >= 0)
    {
        return MED_RES_OK;
    }

    return MED_RES_FAIL;
}

#endif /* MED_NOT_PRESENT */ 

