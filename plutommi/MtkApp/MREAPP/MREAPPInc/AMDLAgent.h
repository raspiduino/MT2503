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
*  AMDLAgent.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/


#ifndef AM_DLA_H
#define AM_DLA_H

#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)

/*
#if defined(WIN32) && defined(_DEBUG)
#include <windows.h>
#ifndef ASSERT
#define ASSERT
#endif
#endif
*/
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"

    /************************************************************************/
    /* SWITCH START                                                         */
    /************************************************************************/
#define DLA_ELEM_SIZE MRE_DLTM_MAX_NODE_COUNT
#define DLA_MAX_FILE_LEN 260
    /************************************************************************/
    /* SWITCH END                                                           */
    /************************************************************************/


    /************************************************************************/
    /* DS VECTOR START                                                      */
    /************************************************************************/
#define DS_VECTOR_CAPACITY DLA_ELEM_SIZE
#define DS_BUF_SIZE 512

#define DS_FALSE MMI_FALSE
#define DS_TRUE MMI_TRUE

    typedef void* DS_HANDLE;
    typedef U32 DS_U32;
    typedef S32 DS_S32;
    typedef S8 DS_S8;
    typedef U8 DS_U8;
    typedef S16 DS_S16;
    typedef WCHAR DS_U16;
    typedef MMI_BOOL DS_BOOL;

    extern DS_HANDLE ds_vector_get(void);
    extern DS_BOOL ds_vector_insert(DS_HANDLE h, void* data, DS_U32 index);
    extern void * ds_vector_delete(DS_HANDLE h, DS_U32 index);
    extern DS_U32 ds_vector_size(DS_HANDLE h);
    extern void ds_vector_clear(DS_HANDLE h);
    extern DS_S32 ds_vector_find(DS_HANDLE h, const void* data);
    extern void ds_vector_sort(DS_HANDLE h, DS_BOOL (*cmp)(void* data1, void* data2));
    //extern void * ds_vector_findi(DS_VECTOR * vec_p, U32 index);

    typedef struct _DS_VECTOR DS_VECTOR;
#define DS_VECTOR_DATA ((DS_VECTOR*)ds_vector_get())->ary
#define DS_VECTOR_INSERT(d, i) ds_vector_insert(ds_vector_get(), d, i)
#define DS_VECTOR_PUSHPACK(d) ds_vector_insert(ds_vector_get(), d, ((DS_VECTOR*)ds_vector_get())->size)
#define DS_VECTOR_DELETE(i) ds_vector_delete(ds_vector_get(), i)
#define DS_VECTOR_SIZE() ds_vector_size(ds_vector_get())
#define DS_VECTOR_CLEAR() ds_vector_clear(ds_vector_get())
#define DS_VECTOR_FIND(d) ds_vector_find(ds_vector_get(), d)
#define DS_VECTOR_SORT(f) ds_vector_sort(ds_vector_get(), f)


#if defined(WIN32) && defined(_DEBUG)


    extern void win32_setdata(int line, const char* file);
    extern void win32_outlog(const char* log, ...);

#define DS_OUTLOG win32_setdata(__LINE__, __FILE__); win32_outlog 
    //#define DS_OUTLOG(...)

#else /* defined(WIN32) && defined(_DEBUG) */


    extern void target_setdata(DS_S32 line, const DS_S8* file);
    extern void target_outfile(const DS_S8* log, ...);
    extern void target_catcher(const DS_S8* log, ...);

#define DS_OUTLOG(...)
    /*
    #undef DS_OUTLOG
    #define DS_OUTLOG target_setdata(__LINE__, __FILE__); target_catcher

    #undef DS_OUTLOG
    #define DS_OUTLOG target_setdata(__LINE__, __FILE__); target_outfile
    */

#endif /* defined(WIN32) && defined(_DEBUG) */

    /************************************************************************/
    /* DS VECTOR END                                                        */
    /************************************************************************/


    /************************************************************************/
    /* DLAgent START                                                        */
    /************************************************************************/
#define DLA_TRUE MMI_TRUE
#define DLA_FALSE MMI_FALSE


#define USED(o)

#include "mmi_rp_app_am_def.h"
#define PARENT_ID GRP_ID_AM

    typedef void * DLA_HANDLE;
    typedef U32 DLA_APID;
    typedef WCHAR * DLA_WSPTR;
    typedef S8 * DLA_SPTR;
    typedef WCHAR DLA_WSTR;
    typedef S8 DLA_STR;
    typedef MMI_BOOL DLA_BOOL;
    typedef S32 DLA_S32;
    typedef U32 DLA_U32;
    typedef U16 DLA_U16;



    /* the status of element */
    typedef enum
    {
        DLA_ELEM_STS_NONE = 0, // do not be modified! 
        DLA_ELEM_STS_DOWNLOADING,
        DLA_ELEM_STS_WAITING,
        DLA_ELEM_STS_PAUSED,
        DLA_ELEM_STS_FAILURE,
        DLA_ELEM_STS_END
    }DLA_ELEM_STS;

    /* the operation of one element */
    typedef enum
    {
        DLA_ELEM_OP_NONE = 0, // do not be modified! 
        DLA_ELEM_OP_VIEW,
        DLA_ELEM_OP_START,
        DLA_ELEM_OP_PAUSE,
        DLA_ELEM_OP_RESUME,
        DLA_ELEM_OP_REMOVE,
        DLA_ELEM_OP_TOTAL
    }DLA_ELEM_OP;

    /*
    #define DLA_VTBL(c) \
    struct _##c##VTBL \
    { \
    DLA_BOOL (*v_##c##_start)(DLA_ELEM_BASE* elem_p);\
    DLA_BOOL (*v_##c##_pause)(DLA_ELEM_BASE* elem_p);\
    DLA_BOOL (*v_##c##_resume)(DLA_ELEM_BASE* elem_p);\
    DLA_BOOL (*v_##c##_remove)(DLA_ELEM_BASE* elem_p);\
    DLA_BOOL (*v_##c##_view)(DLA_ELEM_BASE* elem_p);\
    }c##VTBL;
    */

    extern DLA_HANDLE mmi_am_dla_init(void);
    extern void mmi_am_dla_exit(DLA_HANDLE h);

    /* DLA logic of screen */
    extern void mmi_am_dla_option_download(DLA_HANDLE h, DLA_APID id);
    extern void mmi_am_dla_option_launch(DLA_HANDLE h, DLA_APID id);
    extern void mmi_am_dla_option_show_status(DLA_HANDLE h, DLA_APID id);
    extern void mmi_am_dla_option_list_entry(DLA_HANDLE h);
    //extern void mmi_am_dla_option_list_leave(DLA_HANDLE h);
    extern void mmi_am_dla_op_outside_download(DLA_HANDLE h, DLA_APID id);

    /* DLA param setting / getting */
    extern DLA_APID mmi_am_dla_hl2id(DLA_HANDLE h, DLA_S32 idx);
    extern DLA_ELEM_STS mmi_am_dla_get_elem_sts(DLA_HANDLE h, DLA_APID id);
    extern void mmi_am_dla_set_elem_sts(DLA_HANDLE h, DLA_APID id, DLA_ELEM_STS sts);
    extern DLA_BOOL mmi_am_dla_set_download_path(DLA_HANDLE h, const DLA_WSPTR path, DLA_S32 size);
    extern DLA_BOOL mmi_am_dla_get_download_path(DLA_HANDLE h, DLA_WSPTR path, DLA_S32 size);

    /* DLA interupt handle */
    extern void mmi_am_dla_tcard_plugout_hdlr(void);
    extern void mmi_am_dla_tcard_plugin_hdlr(void);

    /* DLA TST */
    //extern void mmi_am_dla_tst_option_entry_set_status(void);



    /************************************************************************/
    /* DLAgent END                                                          */
    /************************************************************************/
#ifdef __cplusplus
};
#endif

#endif

#endif

