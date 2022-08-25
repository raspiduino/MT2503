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
 * med_utility.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of utiltiy of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _MED_UTILITY_H
#define _MED_UTILITY_H

#include "med_smalloc.h"
#include "..\..\applib\mem\include\app_mem_med.h"
#include "kal_general_types.h"
#include "kal_common_defs.h"
#include "kal_public_defs.h"
#include "med_main.h"
#include "mpl_common.h"

/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef MED_UNUSED
#define MED_UNUSED(p) ((void)(p))
#endif

#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define SELF(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))

#define MED_BASE_TIMER_ID 0x0000
#define MED_ASSERT(expr)                \
    do {                                \
        if (!(expr)) { ASSERT(0); }     \
    } while (0)
    
/* aud  timer ids on event scheduler */
typedef enum
{
    AUD_TIMER_CRESCENDO = 0,
    IMAGE_CODEC_RETRY_TIMER,
    VID_FRAME_TIMER,   
    VID_PDL_BUFFERING_TIMER,    
    RTP_DTMF_TIMER,
    RTP_SIMU_TIMER,
    RTP_DTMF_TIMEOUT_TIMER,
#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
    CAM_XENON_FLASH_CHECK_TIMER,
#endif    
    RTP_DATA_TIMEOUT_TIMER,
#if defined(__MEDIA_VT__)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    AUD_BT_SET_PATH_TIMER,
    VID_CHECK_RECORD_LIMIT_TIMER,
#if defined(__CMMB_CAS_SMD_SUPPORT__) && defined(__MTK_TARGET__)
    NAGRA_CSL_TIMER_BASE,
    NAGRA_CSL_TIMER1,
    NAGRA_CSL_TIMER2,
    NAGRA_CSL_TIMER3,
    NAGRA_CSL_TIMER4,
    NAGRA_CSL_TIMER5,
#endif /* defined(__CMMB_CAS_SMD_SUPPORT__) && defined(__MTK_TARGET__) */
#ifdef __CMMB_SUPPORT__
    MTV_SCAN_PROGRESS_TIMER,
    MTV_MSK_RETRIEVE_TIMER,
#endif
#if defined(STREAM_SUPPORT)
    STREAM_DL_TIMEOUT_TIMER,
    STREAM_RTCP_REPORT_TIMER,
    STREAM_VID_EOF_TIMER,
    STREAM_AUD_EOF_TIMER,
    STREAM_BUFFER_HIGH_RETRY_TIMER,
#endif
    MEDIA_PLAYER_RECOVER_TIMER,
    VID_DELAY_OPEN_TIMER,
    VID_MJPG_PLAYTIME_TIMER,
#if defined(TV_OUT_SUPPORT)
    TVO_CONNECT_POLLING_TIMER,
#endif 
#if defined(__MED_BT_HF_MOD__)
	AUD_BT_DIALER_SCO_IND_TIMER,
#endif

    MAX_NUM_OF_MED_TIMER
}
med_timer_enum;

/* aud timer periods */
#define AUD_TIMER_PERIOD 2000

extern void *med_alloc_int_mem_ext(kal_int32 size,char* file_p, long line_p);
extern void *med_alloc_ext_mem_ext(kal_int32 size,kal_uint8 location,char* file_p, long line_p);
extern void *med_alloc_temp_ext_mem_ext(kal_int32 size, void (*callback)(void*), char* file_p, long line_p);
extern void *med_alloc_temp_ext_mem_ext_nc(kal_int32 size, void (*callback)(void*), char* file_p, long line_p);
extern void med_free_int_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_ext_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_aud_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_temp_ext_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_release_temp_ext_mem_ext(kal_int32 size,char* file_p, long line_p);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  med_ext_left_size
 * DESCRIPTION
 *  Get MED left external memory size.
 * PARAMETERS
 *  void
 * RETURNS
 *  the left size
 *****************************************************************************/
extern size_type med_ext_left_size(void);

/* 
 * Interface to allocate / free media external memory 
 */

/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem
 * DESCRIPTION
 *  Allocate non-cacheable memory from MED external memory pool. Only for PLUTOMMI Package.
 * PARAMETERS
 *  size        : [IN]  the request memory size
 * RETURNS
 *  void*, memory pointer
 *****************************************************************************/
#define med_alloc_ext_mem(size)                 med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_NONCACHEABLE,__FILE__,__LINE__)


/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem_cacheable
 * DESCRIPTION
 *  Allocate cacheable memory from MED external memory pool. Only for PLUTOMMI Package.
 * PARAMETERS
 *  size        : [IN]  the request memory size
 * RETURNS
 *  void*, memory pointer
 *****************************************************************************/
#define med_alloc_ext_mem_cacheable(size)       med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_CACHEABLE,__FILE__,__LINE__)


/*****************************************************************************
 * FUNCTION
 *  med_free_ext_mem
 * DESCRIPTION
 *  Free MED external memory. Only for PLUTOMMI Package.
 * PARAMETERS
 *  pointer     : [IN]  memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
#define med_free_ext_mem(pointer)               med_free_ext_mem_ext(pointer,__FILE__,__LINE__)

/* DOM-NOT_FOR_SDK-BEGIN */
#define med_alloc_ext_mem_framebuffer(size)     med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_FRAMEBUFFER,__FILE__,__LINE__)
#define med_alloc_ext_mem_topmost_noncacheable(size)         med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE,__FILE__,__LINE__)
#define med_alloc_ext_mem_topmost_cacheable(size) med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE,__FILE__,__LINE__)
#define med_alloc_aud_mem(size)                 med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE,__FILE__,__LINE__)
#define med_alloc_aud_mem_cacheable(size)       med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE,__FILE__,__LINE__)
#define med_alloc_aud_mem_topmost(size)         med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_NONCACHEABLE,__FILE__,__LINE__)
#define med_alloc_aud_mem_topmost_cacheable(size)         med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE,__FILE__,__LINE__)
#define med_free_aud_mem(pointer)               med_free_aud_mem_ext(pointer,__FILE__,__LINE__)
#ifdef __VIDEO_STANDALONE_MEMORY__
#define med_alloc_vid_mem(size)                 med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_VIDEO_NONCACHEABLE,__FILE__,__LINE__)
#define med_alloc_vid_mem_cacheable(size)       med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_VIDEO_CACHEABLE,__FILE__,__LINE__)
#define med_free_vid_mem(pointer)               med_free_vid_mem_ext(pointer,__FILE__,__LINE__)
#endif
/* 
 * Interface to allocate / free application share memory 
 */
#ifdef __MED_IN_ASM__
#define med_alloc_asm_mem(id, size)             applib_asm_alloc_nc_r(id, size)
#define med_alloc_asm_mem_cacheable(id, size)   applib_asm_alloc_r(id, size)
#define med_alloc_asm_mem_framebuffer(id, size) applib_asm_alloc_nc_r(id, size)
#define med_alloc_asm_mem_topmost_noncacheable(id, size)    applib_asm_alloc_nc_r(id, size)
#define med_alloc_asm_mem_topmost_cacheable(id, size)       applib_asm_alloc_r(id, size)
#define med_free_asm_mem(id, ptr)               do {applib_asm_free_r(id, *(ptr)); *(ptr)=NULL;}while(0);
#else 
#define med_alloc_asm_mem(id, size)             med_alloc_ext_mem(size)
#define med_alloc_asm_mem_cacheable(id, size)   med_alloc_ext_mem_cacheable(size)
#define med_alloc_asm_mem_framebuffer(id, size) med_alloc_ext_mem_framebuffer(size)
#define med_alloc_asm_mem_topmost_noncacheable(id, size) med_alloc_ext_mem_topmost_noncacheable(size)
#define med_alloc_asm_mem_topmost_cacheable(id, size)    med_alloc_ext_mem_topmost_cacheable(size)
#define med_free_asm_mem(id, ptr)               med_free_ext_mem(ptr)
#endif  

/* 
 * Interface to allocate / free application share memory 
 */
#ifdef __MED_IN_ASM__
#define med_alloc_mem(id, size, file, line)                     applib_asm_alloc_nc_r_dbg(id, size, file, line)
#define med_alloc_mem_cacheable(id, size, file, line)           applib_asm_alloc_r_dbg(id, size, file, line)
#define med_alloc_mem_framebuffer(id, size, file, line)         applib_asm_alloc_nc_r_dbg(id, size, file, line)
#define med_alloc_mem_topmost_noncacheable(id, size, file, line)applib_asm_alloc_nc_r_dbg(id, size, file, line)
#define med_alloc_mem_topmost_cacheable(id, size, file, line)   applib_asm_alloc_r_dbg(id, size, file, line)
#define med_free_mem(id, ptr, file, line)                       do {applib_asm_free_r_dbg(id, *(ptr), file, line); *(ptr)=NULL;}while(0);
#else 
#define med_alloc_mem(id, size, file, line)                     med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_NONCACHEABLE,file, line)
#define med_alloc_mem_cacheable(id, size, file, line)           med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_CACHEABLE,file,line)
#define med_alloc_mem_framebuffer(id, size, file, line)         med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_FRAMEBUFFER,file,line)
#define med_alloc_mem_topmost_noncacheable(id, size, file, line)med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE,file,line)
#define med_alloc_mem_topmost_cacheable(id, size, file, line)   med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE,file,line)
#define med_free_mem(id, ptr, file, line)                       med_free_ext_mem_ext(ptr,file,line)
#endif 


#ifdef __MED_IN_ASM__
#define med_alloc_temp_ext_mem(size,callback)   applib_mem_ap_cache_alloc_dbg(size,callback,__FILE__,__LINE__)
#define med_alloc_temp_ext_mem_noncacheable(size,callback)   applib_mem_ap_cache_alloc_nc_dbg(size,callback,__FILE__,__LINE__)
#define med_free_temp_ext_mem(pointer)          applib_mem_ap_cache_free_dbg(*(pointer),__FILE__,__LINE__)
#define med_release_temp_ext_mem(size)          applib_mem_ap_cache_free_till_enough_int(size,__FILE__,__LINE__)
#else
#define med_alloc_temp_ext_mem(size,callback)   med_alloc_temp_ext_mem_ext(size,callback,__FILE__,__LINE__)
#define med_alloc_temp_ext_mem_noncacheable(size,callback)   med_alloc_temp_ext_mem_ext_nc(size,callback,__FILE__,__LINE__)
#define med_free_temp_ext_mem(pointer)          med_free_temp_ext_mem_ext(pointer,__FILE__,__LINE__)
#define med_release_temp_ext_mem(size)          med_release_temp_ext_mem_ext(size,__FILE__,__LINE__)
#endif /* __MED_IN_ASM__ */

/* 
 * (phased out)Interface to allocate / free media internal memory 
 */
#define med_alloc_int_mem(size)                 med_alloc_int_mem_ext(size,__FILE__,__LINE__)
#define med_free_int_mem(pointer)               med_free_int_mem_ext(pointer,__FILE__,__LINE__)

/*==== Functions =====*/

extern kal_bool med_utility_init(void);
extern kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);
extern kal_int32 med_util_ucs2_to_utf8(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);
extern void med_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void med_stop_timer(kal_uint8 timer_id);
extern kal_int32 med_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte);
extern kal_int16 med_get_media_type(kal_wchar *file_name);
extern kal_int16 med_get_media_type_from_mma_type(kal_uint8 mma_type);
extern kal_uint16 med_get_media_format_from_codec_type(kal_uint16 codec_type);
extern kal_int16 med_get_mma_type_from_media_type(kal_uint8 media_type);
extern kal_uint32 med_get_vid_custom_format_index(kal_uint32 codec_type);
extern kal_bool med_retrieve_file_path(kal_wchar *file_name, kal_wchar *path);
extern kal_bool med_remove_file_name(kal_wchar *file_name);
extern void med_debug_print_result(kal_int32 result, kal_uint32 line);
extern med_result_enum med_error_to_result_enum(media_error_t ret);

#if defined(__DIRECT_SENSOR_SUPPORT__)
extern kal_uint32 med_get_med_int_dcm_mem(kal_uint32 size);
extern void med_free_med_int_dcm_mem(void);
#endif

/* lock & event pool */
extern kal_mutexid med_get_lock(void);
extern void med_return_lock(kal_mutexid lock);
extern kal_eventgrpid med_get_event(void);
extern void med_return_event(kal_eventgrpid event);

/* crc */
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);
/* DOM-NOT_FOR_SDK-END */
#endif /* _MED_UTILITY_H */ 

#endif /* MED_NOT_PRESENT */ 

