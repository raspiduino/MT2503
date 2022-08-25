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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ntpd_mem.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements memory management.
 *
 * Author:
 * -------
 *   
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* //#ifdef __MTK_TARGET__ */

#ifndef _NTPD_MEM_C
#define _NTPD_MEM_C

#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Trace */
//#include "MMI_trc_Int.h"
//#include "mmi_conn_app_trc.h"
#include "ntpd_trc.h"


#define NTPD_ADM_SIZE   (8 * 1024)      /* 8K */

static kal_uint8 g_ntpd_mem_addr[NTPD_ADM_SIZE];
static KAL_ADM_ID g_ntpd_mem_id = NULL;


/*****************************************************************************
 * FUNCTION
 *  ntpd_mem_cpy
 * DESCRIPTION
 *  copy the memory.
 * PARAMETERS
 *  dst     [IN]        Destination buffer
 *  src     [IN]        Source buffer,
 *  len     [IN]        Src length.
 * RETURNS
 *  void
 *****************************************************************************/
void *ntpd_mem_cpy(void *dst, const void *src, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *dst0;
    kal_uint8 *src0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst == NULL || src == NULL)
    {
        return NULL;
    }

    dst0 = (kal_uint8*) dst;
    src0 = (kal_uint8*) src;

    while (len--)
    {
        *dst0++ = *src0++;
    }

    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_create_mem_pool
 * DESCRIPTION
 *  create the memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 or -1
 *****************************************************************************/
int ntpd_create_mem_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_CREATE_MEM);

    if (g_ntpd_mem_id == NULL)
    {
        g_ntpd_mem_id = kal_adm_create(g_ntpd_mem_addr, NTPD_ADM_SIZE, NULL, KAL_FALSE);

        ASSERT(g_ntpd_mem_id);

        return 0;
    }

    /* //kal_trace(TRACE_INFO, INFO_NTPD_MEM_ID, g_ntpd_mem_id); */

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_delete_mem_pool
 * DESCRIPTION
 *  create the memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 or -1
 *****************************************************************************/
int ntpd_delete_mem_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* //kal_trace(TRACE_INFO, INFO_NTPD_DELETE_MEM_ID, g_ntpd_mem_id); */

    ret = kal_adm_delete(g_ntpd_mem_id);
    g_ntpd_mem_id = NULL;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_malloc
 * DESCRIPTION
 *  alloc the memory.
 * PARAMETERS
 *  size        [IN]        Memory size
 * RETURNS
 *  void
 *****************************************************************************/
void *ntpd_malloc(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(g_ntpd_mem_id, size + sizeof(kal_uint32));

    if (size >= 512)
    {
        /* //kal_trace(TRACE_FUNC, FUNC_NTPD_MALLOC, size); */
    }

    if (ptr == NULL)
    {
        ASSERT(0);
        return NULL;
    }

    *(kal_uint32*) ptr = size;
    ptr = (kal_uint8*) ptr + sizeof(kal_uint32);

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_free
 * DESCRIPTION
 *  free the memory.
 * PARAMETERS
 *  ptr     [IN]        Memory address
 * RETURNS
 *  void
 *****************************************************************************/
void ntpd_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr)
    {
        mem_addr = (void*)((kal_uint8*) ptr - sizeof(kal_uint32));
        kal_adm_free(g_ntpd_mem_id, mem_addr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_calloc
 * DESCRIPTION
 *  alloc the memory and clear it.
 * PARAMETERS
 *  n           [IN]        Memory number
 *  size        [IN]        Size
 * RETURNS
 *  void
 *****************************************************************************/
void *ntpd_calloc(kal_uint32 n, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;
    kal_uint32 len = n * size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = (void*)ntpd_malloc(len);

    if (ptr)
    {
        kal_mem_set(ptr, 0, len);
    }

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_realloc
 * DESCRIPTION
 *  alloc the memory.
 * PARAMETERS
 *  ptr         [IN]        Old memory pointer
 *  size        [IN]        Memory size
 * RETURNS
 *  void
 *****************************************************************************/
void *ntpd_realloc(void *ptr, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 old_size;
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr != NULL && size == 0)
    {
        ntpd_free(ptr);
        return NULL;
    }

    if (ptr == NULL)
    {
        p = ntpd_malloc(size);

        if (p == NULL)
        {
            return NULL;
        }

        return p;
    }

    old_size = *(kal_uint32*) ((kal_uint8*) ptr - sizeof(kal_uint32));

    if (size <= old_size)
    {
        return ptr;
    }

    p = ntpd_malloc(size);

    if (p == NULL)
    {
        return NULL;
    }

    ntpd_mem_cpy(p, ptr, old_size);
    ntpd_free(ptr);

    return p;

}


/*****************************************************************************
 * FUNCTION
 *  ntpd_get_max_alloc_size
 * DESCRIPTION
 *  get the max alloc memory size.
 * PARAMETERS
 *  void
 * RETURNS
 *  return the max memory size
 *****************************************************************************/
kal_uint32 ntpd_get_max_alloc_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = kal_adm_get_max_alloc_size(g_ntpd_mem_id);

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_get_total_left_size
 * DESCRIPTION
 *  get the left memory size.
 * PARAMETERS
 *  void
 * RETURNS
 *  return the left memory size
 *****************************************************************************/
kal_uint32 ntpd_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = kal_adm_get_total_left_size(g_ntpd_mem_id);

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_strlen
 * DESCRIPTION
 *  get the length of string.
 * PARAMETERS
 *  str     [IN]        String
 * RETURNS
 *  return the string length
 *****************************************************************************/
unsigned int ntpd_strlen(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return 0;
    }

    start = str;

    while (*str)
    {
        str++;
    }

    return str - start;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_strdup
 * DESCRIPTION
 *  duplicate the string.
 * PARAMETERS
 *  str     [IN]        String
 * RETURNS
 *  void
 *****************************************************************************/
void *ntpd_strdup(void *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *dst = NULL;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return NULL;
    }

    len = ntpd_strlen((const char*)str) + 1;
    dst = ntpd_malloc(len);

    if (dst == NULL)
    {
        return NULL;
    }

    return ntpd_mem_cpy(dst, str, len);
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_strrchr
 * DESCRIPTION
 *  search the char in the string.
 * PARAMETERS
 *  s       [IN]        String
 *  i       [IN]        Char
 * RETURNS
 *  return the location on success, otherwise return NULL.
 *****************************************************************************/
char *ntpd_strrchr(const char *s, int i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *last = NULL;
    char c = i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(s != NULL);

    while (*s)
    {
        if (*s == c)
        {
            last = s;
        }
        s++;
    }

    if (*s == c)
    {
        last = s;
    }

    return (char*)last;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_strlcpy
 * DESCRIPTION
 *  copy string
 * PARAMETERS
 *  dst     [OUT]       Destination string
 *  src     [IN]        Source string
 *  siz     [IN]        The src length
 * RETURNS
 *  return the length copied on success.
 *****************************************************************************/
int ntpd_strlcpy(char *dst, const char *src, int siz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *d = dst;
    const char *s = src;
    size_t n = siz;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Copy as many bytes as will fit */
    if (n != 0 && --n != 0)
    {
        do
        {
            if ((*d++ = *s++) == 0)
            {
                break;
            }
        } while (--n != 0);
    }

    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0)
    {
        if (siz != 0)
        {
            *d = '\0';  /* NUL-terminate dst */
        }

        while (*s++)
        {
            ;
        }
    }

    return (s - src - 1);   /* count does not include NUL */
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_string_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cp      [?]     
 * RETURNS
 *  
 *****************************************************************************/
char *ntpd_string_alloc(char *cp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *ret = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cp && strlen(cp) != 0)
    {
        ret = ntpd_malloc(strlen(cp) + 1);
        strcpy(ret, cp);
    }

    return ret;
}

#endif /* _NTPD_MEM_C */ 

// //#endif /* __MTK_TARGET__ */

