/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   media_common.h
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_COMMON_H
#define _MEDIA_COMMON_H
#include "kal_general_types.h"
#ifndef MAKE_FOURCC
#define MAKE_FOURCC(a,b,c,d) (((kal_uint32)a)|(((kal_uint32)b)<<8)|(((kal_uint32)c)<<16)|(((kal_uint32)d)<<24))
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

#ifndef UNUSED
#define UNUSED(p) ((void)(p))
#endif

#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define SELF(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))


#define MED_INVALID_TIME 0xFFFFFFFF

/* Media sample */

/* external memory allocation */
#if defined(__VIDEO_ARCHI_V2__)
typedef enum
{
    MEDIA_PROVIDER_MEM_CORE        = 0x01,
    MEDIA_PROVIDER_MEM_AUDIO       = 0x02,
    MEDIA_PROVIDER_MEM_VIDEO       = 0x03

} media_provider_memory_type_t;


//extern void* media_session_alloc_ext_mem_impl(kal_uint16 app_id, kal_uint32 size, const char* file_p, long line_p);
//extern void* media_session_alloc_cacheable_ext_mem_impl(kal_uint16 app_id, kal_uint32 size, const char* file_p, long line_p);
//extern void media_session_free_ext_mem_impl(kal_uint16 app_id, void** p, const char* file_p, long line_p);

//#define media_session_alloc_ext_mem(app_id, size) media_session_alloc_ext_mem_impl(app_id, size, __FILE__, __LINE__)
//#define media_session_alloc_cacheable_ext_mem(app_id, size) media_session_alloc_cacheable_ext_mem_impl(app_id, size, __FILE__, __LINE__)
//#define media_session_free_ext_mem(app_id, pointer) media_session_free_ext_mem_impl(app_id, pointer, __FILE__, __LINE__)

extern kal_uint32 media_session_get_provider_mem_size(kal_uint8 media_type, kal_uint8 media_mode, media_provider_memory_type_t mem_type);
#endif /* __VIDEO_ARCHI_V2__ */
extern void vid_send_call_proc_req(void (*proc)(void*), void* param);

#endif /* _MEDIA_COMMON_H */

