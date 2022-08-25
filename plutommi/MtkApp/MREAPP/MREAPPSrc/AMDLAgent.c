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
*  AMDLAgent.c
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
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
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



#include "MMI_features.h"
//#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
#include "MreDLTaskMgr.h"
#include "AMDLAgent.h"
#include "AMUtil.h"
#include "fs_func.h"
#include "AMConfig.h"
#include "AlertScreen.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "mmi_rp_app_am_def.h"
#include "AMDef.h"
#include "ammainscreen.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "MMI_mre_trc.h"
//#include "MRESrvDownloadGprot.h"
#include "MRESrvDownload.h"


#ifdef MRE_DOWNLOAD_SRV
extern mmi_am_ms_struct g_am_ms_cntx;



/************************************************************************/
/* DS VECTOR START                                                      */
/************************************************************************/
typedef struct _DS_VECTOR
{
    DS_U32 size;
    void* ary[DS_VECTOR_CAPACITY];
}DS_VECTOR;


DS_HANDLE ds_vector_get(void)
{
    static DS_VECTOR vec;
    //THISmset(&vec, 0, sizeof(vec));
    return &vec;
}

DS_BOOL ds_vector_insert(DS_HANDLE h, void* data,  DS_U32 index)
{
    DS_U32 i = 0;
    DS_VECTOR* vec_p = (DS_VECTOR*)h;

    ASSERT(vec_p && (index <= vec_p->size) && data);

    if (DS_VECTOR_CAPACITY == (vec_p->size + 1))
    {
        return DS_FALSE;
    }

    for (i = vec_p->size; i > index; i--)
    {
        vec_p->ary[i] = vec_p->ary[i - 1];
    }

    vec_p->ary[i] = data;
    vec_p->size++;

    return DS_TRUE;
}

void * ds_vector_delete(DS_HANDLE h, DS_U32 index)
{
    void * data = NULL;
    DS_U32 i = 0;
    DS_VECTOR* vec_p = (DS_VECTOR*)h;

    ASSERT(vec_p && index < vec_p->size);

    data  = vec_p->ary[index];

    for (i = index; i < vec_p->size - 1; i++)
    {
        vec_p->ary[i] = vec_p->ary[i + 1];
    }

    vec_p->ary[i] = NULL;
    vec_p->size--;
    return data;
}

extern DS_U32 ds_vector_size(DS_HANDLE h)
{
    DS_VECTOR* vec_p = (DS_VECTOR*)h;

    ASSERT(vec_p);

    return vec_p->size;
}

void ds_vector_clear(DS_HANDLE h)
{
    DS_VECTOR* vec_p = (DS_VECTOR*)h;

    ASSERT(vec_p);
    memset(vec_p, 0, sizeof(DS_VECTOR));
}

DS_S32 ds_vector_find(DS_HANDLE h, const void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DS_U32 i = 0;
    DS_VECTOR* vec_p = (DS_VECTOR*)h;

    ASSERT(vec_p && data);

    for (i = 0; i < vec_p->size; i++)
    {
        if (vec_p->ary[i] == data)
        {
            return i;
        }
    }

    //ASSERT(0);
    return -1;
}

extern void ds_vector_sort(DS_HANDLE h, DS_BOOL (*cmp)(void* data1, void* data2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DS_VECTOR* vec_p = (DS_VECTOR*)h;
    DS_S32 i, j;
    DS_U32 * data = (DS_U32 *)DS_VECTOR_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(vec_p && cmp);
    if (0 == vec_p->size)
        return;

    i = vec_p->size - 1, j = 0;

    while (i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (cmp(DS_VECTOR_DATA[j], DS_VECTOR_DATA[j + 1]))
            {
                data[j] ^= data[j + 1];
                data[j + 1] ^= data[j];
                data[j] ^= data[j + 1];
            }
        }

    }


}


/************************************************************************/
/* DS VECTOR END                                                        */
/************************************************************************/



/************************************************************************/
/* DS DLAgent START                                                     */
/************************************************************************/


typedef struct _mmi_am_dla_ctx_struct mmi_am_dla_ctx_struct;
typedef struct _DLA_ELEM_BASE DLA_ELEM_BASE;
typedef struct _DLA_ELEM_VTBL DLA_ELEM_VTBL;

typedef mmi_am_dla_ctx_struct CTX;

struct _DLA_ELEM_VTBL
{
    DLA_BOOL (*v_start)(DLA_ELEM_BASE* elem_p);
    DLA_BOOL (*v_pause)(DLA_ELEM_BASE* elem_p);
    DLA_BOOL (*v_resume)(DLA_ELEM_BASE* elem_p);
    DLA_BOOL (*v_remove)(DLA_ELEM_BASE* elem_p);
    DLA_BOOL (*v_view)(DLA_ELEM_BASE* elem_p);
};

/* the COMMON struct of eleTHISnt */
struct _DLA_ELEM_BASE
{
    DLA_ELEM_VTBL * m_vptr;
    DLA_APID m_ap_id;
    DLA_ELEM_STS m_sts;
    //DLA_WSPTR m_apname;
    DLA_WSPTR m_path;
    DLA_U32 m_exist;
    DLA_U32 m_total;    
    DLA_S32 m_ds_ap_id;
    DLA_U32 m_err_id;
    DLA_U16 m_name_id;
};


/*
typedef struct
{

DLA_ELEM_VTBL
}DLA_ELEM_MGR;
*/


/* eleTHISnt of downloading */
typedef struct
{
    DLA_ELEM_BASE m_elem;
}DLA_ELEM_DOWNLOADING;

/* eleTHISnt of waiting */
typedef struct
{
    DLA_ELEM_BASE m_elem;
}DLA_ELEM_WAITING;

/* eleTHISnt of paused */
typedef struct
{
    DLA_ELEM_BASE m_elem;
}DLA_ELEM_PAUSED;

/* eleTHISnt of failure */
typedef struct
{
    DLA_ELEM_BASE m_elem;
}DLA_ELEM_FAILURE;

/* eleTHISnt of operation */
typedef union 
{
    DLA_ELEM_BASE m_elem;
    DLA_ELEM_DOWNLOADING m_elem_dl;
    DLA_ELEM_WAITING m_elem_wt;
    DLA_ELEM_PAUSED m_elem_ps;
    DLA_ELEM_FAILURE m_elem_fl;
}DLA_ELEM;


struct _mmi_am_dla_ctx_struct
{
    //void* m_lst_hdl;
    DLA_S32 m_ap_idx_hl_main_curr;
    DLA_S32 m_ap_idx_hl_list_curr;
    DLA_APID m_ap_id_curr;
    //DLA_WSPTR m_name_curr;
    DLA_U32 m_name_id_curr;

    //FS_HANDLE m_hdl_mre_phone;
    //FS_HANDLE m_hdl_mre_card;
    S8 m_drv_mre_phone;
    S8 m_drv_mre_card;

    DLA_ELEM_BASE * m_elem_p;
};    

/* STS-OP mapping record */
typedef struct
{
    DLA_ELEM_STS m_sts;
    U16 m_sts_string_id;
    DLA_ELEM_OP m_op[DLA_ELEM_OP_TOTAL - 1];
}mmi_am_dla_rcd_sts_op_struct;

typedef struct
{
    DLA_ELEM_OP m_op;
    void* m_fp;
}mmi_am_dla_rcd_op_func_struct;


/* rtti-sts table */
static mmi_am_dla_rcd_sts_op_struct sts_op_tbl[] = 
{
    {DLA_ELEM_STS_NONE},
    {DLA_ELEM_STS_DOWNLOADING, STR_ID_AM_DLA_TXT_DOWNLOADING, {DLA_ELEM_OP_VIEW, DLA_ELEM_OP_PAUSE, DLA_ELEM_OP_REMOVE}},
    {DLA_ELEM_STS_WAITING, STR_ID_AM_DLA_TXT_WAITING, {DLA_ELEM_OP_VIEW, DLA_ELEM_OP_PAUSE, DLA_ELEM_OP_REMOVE}},
    {DLA_ELEM_STS_PAUSED, STR_ID_AM_DLA_TXT_PAUSED, {DLA_ELEM_OP_VIEW, DLA_ELEM_OP_RESUME, DLA_ELEM_OP_REMOVE}},
    {DLA_ELEM_STS_FAILURE, STR_ID_AM_DLA_TXT_FAILURE, {DLA_ELEM_OP_VIEW, DLA_ELEM_OP_START, DLA_ELEM_OP_REMOVE}},
    {DLA_ELEM_STS_END}
};

// static mmi_am_dla_rcd_op_func_struct op_func_tbl[] = 
// {
//     
// };

static mmi_am_dla_ctx_struct* sg_dla_ctx_p = NULL;
static DLA_APID apid_outside = 0;

/* DLA memory */
static void* mmi_am_dla_malloc(DLA_U32 size);
static void mmi_am_dla_free(void* data);


/* vtbl function - base */
static DLA_BOOL v_pb_start(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_pb_pause(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_pb_resume(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_pb_remove(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_pb_view(DLA_ELEM_BASE* elem_p);


/* vtbl function - derived */
static DLA_BOOL v_dl_start(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_dl_pause(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_dl_resume(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_dl_remove(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_dl_view(DLA_ELEM_BASE* elem_p);

//static DLA_BOOL v_wt_start(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_wt_pause(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_wt_resume(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_wt_remove(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_wt_view(DLA_ELEM_BASE* elem_p);

//static DLA_BOOL v_ps_start(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_ps_pause(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_ps_resume(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_ps_remove(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_ps_view(DLA_ELEM_BASE* elem_p);

static DLA_BOOL v_fl_start(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_fl_pause(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_fl_resume(DLA_ELEM_BASE* elem_p);
//static DLA_BOOL v_fl_remove(DLA_ELEM_BASE* elem_p);
static DLA_BOOL v_fl_view(DLA_ELEM_BASE* elem_p);



/* operation of  any element */
static DLA_BOOL mmi_am_dla_list_init(void);
static DLA_BOOL mmi_am_dla_list_exit(void);

static DLA_ELEM_STS mmi_am_dla_convert_sts(MRE_DLTM_STATUS sts);
static void mmi_am_dla_option_list_entry_again(void);
static DLA_S32 mmi_am_dla_list_reload(DLA_S32 idx);
static DLA_BOOL mmi_am_dla_list_elem_add(DLA_ELEM_BASE** elem_pp, DLA_APID id);
//static DLA_BOOL mmi_am_dla_list_elem_delete(const DLA_ELEM_BASE* elem_cp);
static DLA_ELEM_BASE* mmi_am_dla_list_elem_get(DLA_APID id);
//static DLA_BOOL mmi_am_dla_list_elem_set(const DLA_ELEM_BASE* elem_cp, DLA_APID id);
static DLA_ELEM_STS mmi_am_dla_list_elem_get_sts(const DLA_ELEM_BASE* elem_cp);
static void mmi_am_dla_list_elem_set_sts(DLA_ELEM_BASE * elem_p, DLA_ELEM_STS sts);
static DLA_U32 mmi_am_dla_list_elem_get_err_id(S32 err_code);
static DLA_BOOL mmi_am_dla_list_elem_is_op_valid(DLA_ELEM_STS sts, DLA_ELEM_OP op);
static DLA_BOOL mmi_am_dla_list_elem_op(DLA_ELEM_BASE* elem_cp, DLA_ELEM_OP op);
//static void mmi_am_dla_list_elem_sort(const DLA_ELEM_BASE* elem_cp);
//static DS_BOOL mmi_am_dla_list_elem_compare(void* data1, void* data2);

/**********************************************************************
* SCREEN PART START
***********************************************************************/
static void mmi_am_dla_popup(UI_string_type str_ptr, mmi_event_notify_enum type);
static void mmi_am_dla_update_scrn(const DLA_ELEM_BASE * elem_cp);
static mmi_ret mmi_am_dla_list_grp_cb(mmi_event_struct *evt);
static mmi_ret mmi_am_dla_list_option_menu_cb(mmi_event_struct *evt);
static void mmi_am_dla_list_option(void);
static S32 mmi_am_dla_list_item_update_cb(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void mmi_am_dla_list_item_hl_cb(S32 index);
static void mmi_am_dla_ds_sts_cb(S32 result, const mre_dltm_node *changed_node);
static mmi_ret mmi_am_dla_option_download_confirm_cb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_am_dla_list_option_remove_confirm_cb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_am_dla_op_outside_download_confirm_cb(mmi_alert_result_evt_struct * evt);
#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_am_dla_tap_cb(mmi_tap_type_enum tap_type, S32 index);
#endif



/**********************************************************************
* SCREEN PART END
***********************************************************************/

static DLA_BOOL mmi_am_dla_check_mre_folder(void);
static S8 mmi_am_dla_get_drv(void);


extern DLA_HANDLE mmi_am_dla_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    DS_OUTLOG("[DLA] mmi_am_dla_init S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 0);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_init())
    {
        return NULL;
    }

    if (NULL != sg_dla_ctx_p)
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_init already init");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 0);
        return sg_dla_ctx_p;
    }

    sg_dla_ctx_p = mmi_am_dla_malloc(sizeof(mmi_am_dla_ctx_struct));
    if (NULL == sg_dla_ctx_p)
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_malloc mmi_am_dla_ctx_struct");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E2, 0);
        return sg_dla_ctx_p;
    }
    mmi_am_dla_check_mre_folder();

    if (DLA_FALSE == mmi_am_dla_list_init())
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_list_init");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E3, 0);
        mmi_am_dla_free(sg_dla_ctx_p);
        return NULL;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E);

    return sg_dla_ctx_p;
}

extern void mmi_am_dla_exit(DLA_HANDLE h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_dla_ctx_struct* ctx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ASSERT(h);

    DS_OUTLOG("[DLA] mmi_am_dla_exit S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 1);
    ctx_p = (mmi_am_dla_ctx_struct *)h;

    if (DLA_FALSE == mmi_am_dla_list_exit())
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_list_exit");
    }


    mmi_am_dla_free(ctx_p);


    DS_OUTLOG("[DLA] mmi_am_dla_exit E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 1);
    sg_dla_ctx_p = NULL;

    mre_dltm_deinit();
}

/* DLA logic of screen */
extern void mmi_am_dla_option_download(DLA_HANDLE h, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_ret = FS_NO_ERROR;
    DLA_STR drv_asc[10] = {0};
    DLA_U16 drv_ucs[10] = {0};
    FS_DiskInfo disk_info;
    DLA_U32 free_space = 0;
    mmi_confirm_property_struct arg;
    //mmi_am_shortcut_info_struct *sc_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(h);


    /* whether it can get home drvier */
    if (mmi_am_get_home_driver() == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_GLOBAL_INSERT_MEMORY_CARD),
            MMI_EVENT_FAILURE,
            PARENT_ID,
            NULL);
        return;
    }

    /* check mre folder and create mre folder in Removable Drv and System Drv. */
    if (!mmi_am_dla_check_mre_folder())
    {
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
            MMI_EVENT_FAILURE,
            PARENT_ID,
            NULL);
        DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- create mre folder failure");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 2);
        return;
    }

    /* card */
    if (0 < sg_dla_ctx_p->m_drv_mre_card)
    {

        sprintf(drv_asc, "%c:\\", mmi_am_get_removeable_driver());
        mmi_asc_to_wcs(drv_ucs, (PS8) drv_asc);
        fs_ret = FS_GetDiskInfo((kal_uint16*) drv_ucs, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (fs_ret >= FS_NO_ERROR)
        {
            free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        }
        DS_OUTLOG("[DLA] card space %d", free_space);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 21, free_space, 0, 0, 0, 0, 0);
        if (free_space < MMI_AM_DOWNLOAD_BLOCK_SIZE)
        {
            mmi_popup_display_simple(
                (WCHAR*) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                MMI_EVENT_FAILURE,
                PARENT_ID,
                NULL);
            return;
        }
    }
    /* phone */
    else
    {
        if (0 < sg_dla_ctx_p->m_drv_mre_phone)
        {
            sprintf(drv_asc, "%c:\\", mmi_am_get_system_driver());
            mmi_asc_to_wcs(drv_ucs, (PS8) drv_asc);
            fs_ret = FS_GetDiskInfo((kal_uint16*) drv_ucs, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
            if (fs_ret >= FS_NO_ERROR)
            {
                free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            }
            DS_OUTLOG("[DLA] phone space %d", free_space);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 22, free_space, 0, 0, 0, 0, 0);
            if (free_space < MMI_AM_DOWNLOAD_BLOCK_SIZE)
            {
                mmi_popup_display_simple(
                    (WCHAR*) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                    MMI_EVENT_FAILURE,
                    PARENT_ID,
                    NULL);
                return;
            }
        }
        else
        {
            ASSERT(0);
        }
    }

    /*
    sc_info = mmi_am_config_get_am_sc_list();
    sg_dla_ctx_p->m_ap_id_curr = id;
    sg_dla_ctx_p->m_name_curr = (DLA_WSPTR)sc_info[sg_dla_ctx_p->m_ap_idx_hl_main_curr].p_name;
    */    
    /* ask user if wish to download the app */
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func) mmi_am_dla_option_download_confirm_cb;
    arg.parent_id = PARENT_ID;
    mmi_confirm_display((WCHAR*) get_string(STR_GLOBAL_DOWNLOAD_ASK), MMI_EVENT_QUERY, &arg);




}

extern void mmi_am_dla_option_launch(DLA_HANDLE h, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
    mmi_am_dla_ctx_struct* ctx_p = NULL;
    DLA_ELEM_BASE* elem_p = NULL;
    DLA_BOOL ret_b = DLA_FALSE;
    */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

}

extern void mmi_am_dla_option_show_status(DLA_HANDLE h, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_am_dla_ctx_struct* ctx_p = NULL;
    DLA_ELEM_BASE* elem_p = NULL;
    //DLA_BOOL ret_b = DLA_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(h);
    //ctx_p = (mmi_am_dla_ctx_struct *)h;

    elem_p = (DLA_ELEM_BASE*)mmi_am_dla_list_elem_get(id);
    if (NULL == elem_p)
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_list_elem_get id[%d]", id);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 31, id, 0, 0, 0, 0, 0);
        ASSERT(0);
        return;
    }

    if (DLA_FALSE == mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_VIEW))
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_list_elem_op apid[%d], sts[%d], op[%d]", 
            elem_p->m_ap_id, elem_p->m_sts, DLA_ELEM_OP_VIEW);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 32, 
            elem_p->m_ap_id, elem_p->m_sts, DLA_ELEM_OP_VIEW, 0, 0, 0);

        return;
    }
}

extern void mmi_am_dla_option_list_entry(DLA_HANDLE h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_am_dla_ctx_struct* ctx_p = NULL;
    //DLA_ELEM_BASE* elem_p = NULL;
    //DLA_BOOL ret_b = DLA_FALSE;

    MMI_ID      parent_grp_id;
    MMI_ID      ret_mmi_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(h);
    //ctx_p = (mmi_am_dla_ctx_struct*)h;

    parent_grp_id = mmi_frm_group_get_active_id(); 
    parent_grp_id = GRP_ID_ROOT;

    ret_mmi_id = mmi_frm_group_create(
        parent_grp_id, 
        SCR_ID_DLA_APP, 
        mmi_am_dla_list_grp_cb,
        NULL);

    if (!ret_mmi_id)  
    {
        mmi_am_dla_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                 
        DS_OUTLOG("[DLA] [F] mmi_frm_group_create SCR_ID_DLA_APP");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 41);
        return;
    }

    ret_mmi_id = mmi_frm_group_enter(ret_mmi_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (!ret_mmi_id)  
    {
        mmi_am_dla_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[DLA] [F] mmi_frm_group_enter SCR_ID_DLA_APP");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 42);
        return;
    }

    mmi_am_dla_option_list_entry_again();



    return;

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
#endif

extern void mmi_am_dla_op_outside_download(DLA_HANDLE h, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_BOOL exist_b = DLA_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    apid_outside = id;

    if (0 <= mre_dltm_get_handle((S32)id))
    {
        exist_b = DLA_TRUE;
    }

    if (exist_b)
    {
        mmi_am_dla_popup((U16*)get_string(STR_ID_AM_DLA_TXT_EXIST), MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[DLA] [P] mmi_am_dla_op_outside_download exist");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 5);
    }
    else
    {
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.callback = (mmi_proc_func) mmi_am_dla_op_outside_download_confirm_cb;
        arg.parent_id = PARENT_ID;
        mmi_confirm_display((WCHAR*) get_string(STR_GLOBAL_DOWNLOAD_ASK), MMI_EVENT_QUERY, &arg);
        DS_OUTLOG("[DLA] [P] mmi_am_dla_op_outside_download not exist");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E2, 5);
    }
}

/* DLA param setting / getting */
extern DLA_APID mmi_am_dla_hl2id(DLA_HANDLE h, DLA_S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_dla_ctx_struct* ctx_p = NULL;
    //DLA_ELEM_BASE* elem_p = NULL;
    mmi_am_shortcut_info_struct *sc_info = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    ASSERT(h);
    ASSERT(0 <= idx);

    ctx_p = (mmi_am_dla_ctx_struct*)h;

    /* IMPORTANT */
    ctx_p->m_ap_idx_hl_main_curr = idx;

    /* get shortcut app appid and name */
    sc_info = mmi_am_config_get_am_sc_list();
    ctx_p->m_ap_id_curr = (DLA_APID)sc_info[ctx_p->m_ap_idx_hl_main_curr].dl_app_id;
    //ctx_p->m_name_curr = (DLA_WSPTR)sc_info[ctx_p->m_ap_idx_hl_main_curr].p_name;
    ctx_p->m_name_id_curr = (DLA_U16) sc_info[ctx_p->m_ap_idx_hl_main_curr].name_id;


    return ctx_p->m_ap_id_curr;

}

extern DLA_ELEM_STS mmi_am_dla_get_elem_sts(DLA_HANDLE h, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_am_dla_ctx_struct* ctx_p = NULL;
    DLA_ELEM_BASE* elem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    ASSERT(h);

    elem_p = mmi_am_dla_list_elem_get(id);
    if (NULL != elem_p)
    {
        return mmi_am_dla_list_elem_get_sts(elem_p);
    }
    else
    {
        return DLA_ELEM_STS_NONE;
    }
}

extern void mmi_am_dla_set_elem_sts(DLA_HANDLE h, DLA_APID id, DLA_ELEM_STS sts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_am_dla_ctx_struct* ctx_p = NULL;
    DLA_ELEM_BASE* elem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    ASSERT(h);
    ASSERT(DLA_ELEM_STS_NONE < sts && DLA_ELEM_STS_END > sts);

    elem_p = mmi_am_dla_list_elem_get(id);
    if (NULL != elem_p)
    {
        mmi_am_dla_list_elem_set_sts(elem_p, sts);
    }
}

extern DLA_BOOL mmi_am_dla_set_download_path(DLA_HANDLE h, const DLA_WSPTR path, DLA_S32 size)
{
    return DLA_TRUE;
}

extern DLA_BOOL mmi_am_dla_get_download_path(DLA_HANDLE h, DLA_WSPTR path, DLA_S32 size)
{
    return DLA_TRUE;
}

extern void mmi_am_dla_tcard_plugout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_U32 i = 0;
    DLA_WSTR tmp = 0;
    DLA_ELEM_BASE * elem_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    DS_OUTLOG("mmi_am_dla_tcard_plugout_hdlr S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 28);

    if (NULL == sg_dla_ctx_p)
    { 
        DS_OUTLOG("mmi_am_dla_tcard_plugout_hdlr E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 28);
        return;
    }
    if (0 == sg_dla_ctx_p->m_drv_mre_card)
        return;
    tmp = sg_dla_ctx_p->m_drv_mre_card;
    sg_dla_ctx_p->m_drv_mre_card = 0;
    mmi_am_dla_check_mre_folder();

    DS_OUTLOG("mmi_am_dla_tcard_plugout_hdlr size[%d]", DS_VECTOR_SIZE());
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 281, 
        DS_VECTOR_SIZE(), 0, 0, 0, 0, 0);

    for (i = 0; i < DS_VECTOR_SIZE(); i++)
    {
        if ((((DLA_ELEM_BASE*)DS_VECTOR_DATA[i])->m_path[0]) == tmp)
        {
            elem_p = DS_VECTOR_DELETE(i);
            if (sg_dla_ctx_p->m_elem_p == elem_p)
            {
                sg_dla_ctx_p->m_elem_p = NULL;
            }
            elem_p->m_vptr->v_remove(elem_p);
            if ((DLA_S32)i < sg_dla_ctx_p->m_ap_idx_hl_list_curr)
            {
                --(sg_dla_ctx_p->m_ap_idx_hl_list_curr); // modified the curr hl one
            }

            DS_OUTLOG("mmi_am_dla_tcard_plugout_hdlr i[%d], path[%c], id[%d]", i, tmp, elem_p->m_ap_id);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 282, 
                i, tmp, elem_p->m_ap_id, 0, 0, 0);

            mmi_am_dla_free(elem_p->m_vptr);
            mmi_am_dla_free(elem_p);  
            i--;
        }
    }

    if (sg_dla_ctx_p->m_ap_idx_hl_list_curr >= (DLA_S32)DS_VECTOR_SIZE())
    {
        sg_dla_ctx_p->m_ap_idx_hl_list_curr = DS_VECTOR_SIZE() - 1;
    }
    elem_p = DS_VECTOR_DATA[sg_dla_ctx_p->m_ap_idx_hl_list_curr];
    mmi_am_dla_update_scrn(elem_p);


    DS_OUTLOG("mmi_am_dla_tcard_plugout_hdlr E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 28);


}

extern void mmi_am_dla_tcard_plugin_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL == sg_dla_ctx_p)
        return;

    if (0 < sg_dla_ctx_p->m_drv_mre_card)
        return;
    mmi_am_dla_check_mre_folder();
}


/* DLA TST */
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
#endif



/* DLA memory */
static void* mmi_am_dla_malloc(DLA_U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    // TODO: modify.
    ASSERT(size);
    p = mmi_am_malloc(size);
    //p = get_ctrl_buffer(size);
    if (p)
    {
        memset(p, 0, size);
    }


    return p;
}
static void mmi_am_dla_free(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    // TODO: modify.
    ASSERT(data);
    mmi_am_free(data);
    //free_ctrl_buffer(data);
}



/* the operation of elements in the download list*/
static DLA_BOOL mmi_am_dla_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_am_dla_list_reload(0);
    return DLA_TRUE;
}

static DLA_BOOL mmi_am_dla_list_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_U32 i = 0;
    DLA_ELEM_BASE* elem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("[DLA] mmi_am_dla_list_exit S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 6);
    for (i = 0; i < DS_VECTOR_SIZE(); i++)
    {
        elem_p = DS_VECTOR_DATA[i];
        mmi_am_dla_free(elem_p->m_vptr);
        mmi_am_dla_free(elem_p);
    }
    DS_VECTOR_CLEAR();

    DS_OUTLOG("[DLA] mmi_am_dla_list_exit E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 6);
    return DLA_TRUE;
}

static DLA_ELEM_STS mmi_am_dla_convert_sts(MRE_DLTM_STATUS sts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_ELEM_STS ret_sts = DLA_ELEM_STS_NONE;
    //mre_dltm_node * iter = NULL;
    //DLA_ELEM_BASE * elem_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sts)
    {
    case MRE_DLTM_STATE_WAITING:
        {
            ret_sts = DLA_ELEM_STS_WAITING;
        }
        break;
    case MRE_DLTM_STATE_DOWNLOAD:
        {
            ret_sts = DLA_ELEM_STS_DOWNLOADING;
        }
        break;
    case MRE_DLTM_STATE_PAUSE:
        {
            ret_sts = DLA_ELEM_STS_PAUSED;
        }
        break;
    case MRE_DLTM_STATE_FAILURE:
        {
            ret_sts = DLA_ELEM_STS_FAILURE;
        }
        break;
    default:
        ret_sts = DLA_ELEM_STS_NONE;
        break;
    }

    return ret_sts;
}

static void mmi_am_dla_option_list_entry_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_BOOL ret_b = DLA_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_b = mmi_frm_scrn_enter(SCR_ID_DLA_APP, 
        SCR_ID_DLA_LIST, 
        NULL, 
        mmi_am_dla_option_list_entry_again, 
        MMI_FRM_UNKNOW_SCRN);
    if (!ret_b)
    {
        mmi_am_dla_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[DLA] [F] mmi_frm_scrn_enter SCR_ID_DLA_LIST");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 7);
        return;
    }

    if (DS_VECTOR_SIZE() > 0 && 
        ((DLA_U32)sg_dla_ctx_p->m_ap_idx_hl_list_curr >= DS_VECTOR_SIZE()))
    {
        sg_dla_ctx_p->m_ap_idx_hl_list_curr = DS_VECTOR_SIZE() - 1;

    }

    if (DS_VECTOR_SIZE())
    {

        ShowCategory427Screen((WCHAR*)GetString(STR_ID_AM_DLA_TXT_DOWNLOADING),
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            NULL,
            DS_VECTOR_SIZE(),
            mmi_am_dla_list_item_update_cb,
            sg_dla_ctx_p->m_ap_idx_hl_list_curr,
            NULL);

        SetLeftSoftkeyFunction(mmi_am_dla_list_option, KEY_EVENT_UP);   

    }
    else
    {
        ShowCategory427Screen((WCHAR*)GetString(STR_ID_AM_DLA_TXT_DOWNLOADING),
            NULL,
            L"",
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            NULL,
            DS_VECTOR_SIZE(),
            mmi_am_dla_list_item_update_cb,
            sg_dla_ctx_p->m_ap_idx_hl_list_curr,
            NULL);
    }


    RegisterHighlightHandler(mmi_am_dla_list_item_hl_cb);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_am_dla_tap_cb);
#endif

    //wgui_register_tap_callback(mmi_demo1_clients_tap_callback);
}

static DLA_S32 mmi_am_dla_list_reload(DLA_S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mre_dltm_node * iter = NULL;
    DLA_ELEM_BASE * elem_p = NULL;
    DLA_ELEM_BASE * tmp = NULL;
    DLA_S32 ds_id = -1;
    mmi_am_shortcut_info_struct *sc_info = NULL;
    extern mmi_am_cntx_struct g_am_cntx;
    S32 max = 0;
    DLA_BOOL found_b = DLA_FALSE;
    DLA_BOOL ret_b = DLA_FALSE;
    DLA_U32 i = 0;
    DLA_S32 ret_idx = idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("[DLA] mmi_am_dla_list_reload S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 8);

    if (0 > ret_idx)
        ret_idx = 0;

    tmp = DS_VECTOR_DATA[ret_idx];
    if (tmp)
    {
        ds_id = tmp->m_ds_ap_id;
    }

    for (i = 0; i < DS_VECTOR_SIZE(); i++)
    {
        elem_p = DS_VECTOR_DATA[i];
        mmi_am_dla_free(elem_p->m_vptr);
        mmi_am_dla_free(elem_p);
    }
    DS_VECTOR_CLEAR();    

    sc_info = mmi_am_config_get_am_sc_list();
    DS_OUTLOG("[DLA] mmi_am_dla_list_reload max[%d]", max);

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 81,
        max, 0, 0, 0, 0, 0);

    iter = mre_dltm_get_first();
    while (iter)
    {
        elem_p = mmi_am_dla_malloc(sizeof(DLA_ELEM_BASE));
        if (NULL == elem_p)
        {
            DS_OUTLOG("[DLA] [F] mmi_am_dla_list_reload DLA_ELEM_BASE");
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 82);
            ASSERT(elem_p);
            break;
        }
        elem_p->m_vptr = mmi_am_dla_malloc(sizeof(DLA_ELEM_VTBL));
        if (NULL == elem_p->m_vptr)
        {
            DS_OUTLOG("[DLA] [F] mmi_am_dla_list_reload DLA_ELEM_VTBL");
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 83);
            ASSERT(elem_p->m_vptr);
            break;
        }
        elem_p->m_ap_id = iter->id;
        elem_p->m_sts = DLA_ELEM_STS_NONE;//mmi_am_dla_convert_sts(iter->state);
        elem_p->m_path = (DLA_WSPTR)iter->filename;
        elem_p->m_exist = iter->download_info.download_size;
        elem_p->m_total = iter->download_info.total_size;
        elem_p->m_ds_ap_id = iter->handle;
        elem_p->m_err_id = mmi_am_dla_list_elem_get_err_id(iter->err_code);
        max = mmi_am_config_get_am_sc_num();
        while (max--)
        {
            if (sc_info[max].dl_app_id == iter->id)
            {
                elem_p->m_name_id = sc_info[max].name_id;
                found_b = DLA_TRUE;
                break;
            }
        }

        DS_OUTLOG("[DLA] mmi_am_dla_list_reload ap_id[%d], sts[%d], path[%c], exist[%d], total[%d], name_id[%d]", 
            elem_p->m_ap_id, 
            elem_p->m_sts,
            elem_p->m_path[0],
            elem_p->m_exist,
            elem_p->m_total,
            elem_p->m_name_id);

        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 84,
            elem_p->m_ap_id, 
            elem_p->m_sts,
            elem_p->m_path[0],
            elem_p->m_exist,
            elem_p->m_total,
            elem_p->m_name_id);
        if (!found_b)
        {
            mmi_am_dla_free(elem_p->m_vptr);
            mmi_am_dla_free(elem_p);
            DS_OUTLOG("[DLA] [F] mmi_am_dla_list_reload apid[%d] was not found in the sc_info", iter->id);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 85);         
            //ASSERT(0);
        }
        else
        {

            /* sorting */
            for (i = 0; i < DS_VECTOR_SIZE(); i++)
            {
                if (mmi_am_dla_convert_sts(iter->state) < ((DLA_ELEM_BASE*)DS_VECTOR_DATA[i])->m_sts)
                {
                    break;
                }
            }
            ret_b = DS_VECTOR_INSERT(elem_p, i);
            DS_OUTLOG("[DLA] mmi_am_dla_list_reload insert pos[%d]", i);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 86,
                i, 0, 0, 0, 0, 0);

            if (!ret_b)
            {
                mmi_am_dla_free(elem_p->m_vptr);
                mmi_am_dla_free(elem_p);
                DS_OUTLOG("[DLA] [F] DS_VECTOR_PUSHPACK FULL");
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 87);
                //ASSERT(0);
            }

            mmi_am_dla_list_elem_set_sts(elem_p, mmi_am_dla_convert_sts(iter->state));

        }

        iter = mre_dltm_get_next();
    }    

    found_b = DLA_FALSE;
    if (tmp) // the one was exist before reload.
    {
        // checking the index
        for (i = 0; i < DS_VECTOR_SIZE(); i++)
        {
            if (ds_id == ((DLA_ELEM_BASE *)DS_VECTOR_DATA[i])->m_ds_ap_id)
            {
                found_b = DLA_TRUE;
                break;
            }
        }
        if (found_b)
        {
            ret_idx = i;
        }
        //return DS_VECTOR_FIND(tmp);
    }

    DS_OUTLOG("[DLA] mmi_am_dla_list_reload ret_idx[%d] found_b[%d]", ret_idx, found_b);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 88,
        ret_idx, found_b, 0, 0, 0, 0);

    DS_OUTLOG("[DLA] mmi_am_dla_list_reload E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 8);

    return ret_idx;
}

static DLA_BOOL mmi_am_dla_list_elem_add(DLA_ELEM_BASE** elem_pp, DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
    DLA_ELEM_BASE* elem_p = NULL;
    DLA_BOOL ret_b = DLA_FALSE;
    */
    mmi_am_shortcut_info_struct *sc_info = NULL;
    S8 drv = 0;
    U16 file_name[DLA_MAX_FILE_LEN] = {0};
    //DLA_S32 i = 0;
    S32 ds_apid = 0;
    //DLA_ELEM_BASE* tmp_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_pp);

    DS_OUTLOG("[DLA] mmi_am_dla_list_elem_add S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 9);

    (*elem_pp) = mmi_am_dla_malloc(sizeof(DLA_ELEM_BASE));
    if (NULL == (*elem_pp))
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_malloc DLA_ELEM_BASE");
        ASSERT((*elem_pp));
        return DLA_FALSE;
    }
    (*elem_pp)->m_vptr = mmi_am_dla_malloc(sizeof(DLA_ELEM_VTBL));
    if (NULL == (*elem_pp)->m_vptr)
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_malloc DLA_ELEM_VTBL");
        ASSERT((*elem_pp)->m_vptr);
        return DLA_FALSE;
    }
    /*
    (*elem_pp)->m_path = mmi_am_dla_malloc(sizeof(DLA_WSTR)*DLA_MAX_FILE_LEN);
    if (NULL == (*elem_pp)->m_path)
    {
    DS_OUTLOG("[DLA] [F] mmi_am_dla_malloc m_path");
    ASSERT((*elem_pp)->m_path);
    return DLA_FALSE;
    }
    */

    //(*elem_pp)->m_apname = sg_dla_ctx_p->m_name_curr;
    (*elem_pp)->m_name_id = (DLA_U16)sg_dla_ctx_p->m_name_id_curr;

    /* init the ap id & path */
    (*elem_pp)->m_ap_id = id;

    // build the path.
    sc_info = mmi_am_config_get_am_sc_list();
    if (sg_dla_ctx_p->m_drv_mre_card > 0)
    {
        drv = sg_dla_ctx_p->m_drv_mre_card;
    }
    else
    {
        ASSERT(sg_dla_ctx_p->m_drv_mre_phone > 0);
        drv = sg_dla_ctx_p->m_drv_mre_phone;
    }
    (*elem_pp)->m_path = (DLA_WSPTR)mmi_am_dla_malloc(sizeof(DLA_WSTR)*DLA_MAX_FILE_LEN);
    kal_wsprintf((*elem_pp)->m_path, "%c:\\"MMI_AM_MRE_HOME_DIR"\\", drv);
    mmi_asc_to_wcs(file_name, sc_info[sg_dla_ctx_p->m_ap_idx_hl_main_curr].file_name);
    mmi_wcscat((*elem_pp)->m_path, file_name);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    ds_apid = mre_dltm_add(id, (U16 *)((*elem_pp)->m_path));
    mmi_am_dla_free((*elem_pp)->m_path);

    if (MRE_DLTM_RET_APP_HAVE_EXIST == ds_apid)
    {
        mmi_am_dla_free((*elem_pp)->m_vptr);
        mmi_am_dla_free((*elem_pp));
        DS_OUTLOG("[DLA] [F] MRE_DLTM_RET_APP_HAVE_EXIST");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 91);
        return DLA_FALSE;
    }

    if (MRE_DLTM_MAX_NODE_COUNT == ds_apid)
    {
        mmi_am_dla_free((*elem_pp)->m_vptr);
        mmi_am_dla_free((*elem_pp));
        DS_OUTLOG("[DLA] [F] MRE_DLTM_MAX_NODE_COUNT");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 92);
        return DLA_FALSE;
    }

    (*elem_pp)->m_path = (DLA_WSPTR)((mre_dltm_get_node(ds_apid))->filename);
    (*elem_pp)->m_ds_ap_id = ds_apid;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (DLA_FALSE == DS_VECTOR_PUSHPACK((void*)(*elem_pp)))
    {
        mmi_am_dla_free((*elem_pp)->m_vptr);
        mmi_am_dla_free((*elem_pp));
        DS_OUTLOG("[DLA] [F] DS_VECTOR_PUSHPACK FULL");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_FAILURE, 93);
        return DLA_FALSE;
    }

    // [USER OP] option download.
    mmi_am_dla_list_elem_set_sts((*elem_pp), DLA_ELEM_STS_DOWNLOADING);

    DS_OUTLOG("[DLA] mmi_am_dla_list_elem_add E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 9);

    return DLA_TRUE;

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
#endif

static DLA_ELEM_BASE* mmi_am_dla_list_elem_get(DLA_APID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < DS_VECTOR_SIZE(); i++)
    {
        if (((DLA_ELEM_BASE*)DS_VECTOR_DATA[i])->m_ap_id == id)
        {
            return DS_VECTOR_DATA[i];
        }
    }
    return NULL;

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
#endif

static DLA_ELEM_STS mmi_am_dla_list_elem_get_sts(const DLA_ELEM_BASE * elem_cp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(elem_cp);
    return elem_cp->m_sts;
}

static void mmi_am_dla_list_elem_set_sts(DLA_ELEM_BASE * elem_p, DLA_ELEM_STS sts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //DLA_U32 i = 0;
    DLA_S32 ret_s32 = 0;
    //DLA_BOOL ret_changed_sts_b = DLA_FALSE;
    DLA_BOOL ret_b = DLA_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ASSERT(elem_p && (DLA_ELEM_STS_NONE < sts && DLA_ELEM_STS_END > sts));

    ret_s32 = DS_VECTOR_FIND(elem_p);
    if (-1 == ret_s32)
    {
        ASSERT(0);
        return;
    }

    //memset(elem_p->m_vptr, 0, sizeof(DLA_ELEM_VTBL));
    elem_p->m_vptr->v_start = v_pb_start;
    elem_p->m_vptr->v_pause = v_pb_pause;
    elem_p->m_vptr->v_resume = v_pb_resume;
    elem_p->m_vptr->v_remove = v_pb_remove;
    elem_p->m_vptr->v_view = v_pb_view;

    if (elem_p->m_sts != sts)
    {
        elem_p->m_sts = sts;
        //ret_changed_sts_b = DLA_TRUE;
    }


    switch (sts)
    {
    case DLA_ELEM_STS_DOWNLOADING:
        {
            elem_p->m_vptr->v_start = v_dl_start;
            elem_p->m_vptr->v_pause = v_dl_pause;
            elem_p->m_vptr->v_view = v_dl_view;

            // [AUTO OP] there is already one in downloading status.
            if (0 < ret_s32 && 
                DLA_ELEM_STS_DOWNLOADING == ((DLA_ELEM_BASE*)DS_VECTOR_DATA[0])->m_sts)
            {
                if (DLA_ELEM_STS_DOWNLOADING == sts)
                {
                    mmi_am_dla_list_elem_set_sts(elem_p, DLA_ELEM_STS_WAITING);
                    break;
                }
            }

        }break;
    case DLA_ELEM_STS_WAITING:
        {
            elem_p->m_vptr->v_pause = v_wt_pause;
            elem_p->m_vptr->v_view = v_wt_view;
        }break;
    case DLA_ELEM_STS_PAUSED:
        {
            elem_p->m_vptr->v_resume = v_ps_resume;
            elem_p->m_vptr->v_view = v_ps_view;
        }break;
    case DLA_ELEM_STS_FAILURE:
        {
            elem_p->m_vptr->v_start = v_fl_start;
            elem_p->m_vptr->v_view = v_fl_view;            
        }break;
    default:
        {
            ASSERT(0);
        }break;
    }

    // the first download one auto started or added by user.
    if (/*(0 == ret_s32) && */(DLA_ELEM_STS_DOWNLOADING == elem_p->m_sts))
    {
        ret_b = elem_p->m_vptr->v_start(elem_p);
        if (!ret_b)
        {
            mmi_am_dla_list_elem_set_sts(elem_p, DLA_ELEM_STS_FAILURE);
        }
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

static DLA_U32 mmi_am_dla_list_elem_get_err_id(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_U32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    switch (err_code)
    {
    case MRE_DLTM_RET_ERR:
    case MRE_DLTM_RET_NET_ERR:
    case MRE_DLTM_RET_SAVE_ERR:
    case MRE_DLTM_RET_NOT_EXIST:
    case MRE_DLTM_RET_OTHER_ERR:
    case MRE_DLTM_RET_FILE_NOT_EXIST:
    case MRE_DLTM_RET_IO_ERROR:
        {
            ret = STR_ID_AM_DLA_TXT_FAILED_TO_DOWNLOAD;//STR_GLOBAL_ERROR;
        }break;
    case MRE_DLTM_RET_SPACE_FULL:
        {
            ret = STR_GLOBAL_MEMORY_FULL;
        }break;
    default:
        {
            ret = 0;
        }break;
    }

    return ret;

}

static DLA_BOOL mmi_am_dla_list_elem_is_op_valid(DLA_ELEM_STS sts, DLA_ELEM_OP op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_dla_rcd_sts_op_struct* rcd_p = sts_op_tbl;
    DLA_U32 i = 0;
    /*
    DLA_ELEM_OP op_tmp = DLA_ELEM_OP_NONE;
    DLA_ELEM_STS sts_tmp = DLA_ELEM_STS_NONE;
    */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((DLA_ELEM_STS_NONE < sts) && (DLA_ELEM_STS_END > sts) && 
        (DLA_ELEM_OP_NONE < op) && (DLA_ELEM_OP_TOTAL > op));


    for (; DLA_ELEM_STS_END != rcd_p->m_sts; rcd_p++)
    {
        if (sts == rcd_p->m_sts)
        {
            for (i = 0; i < (sizeof(rcd_p->m_op) / sizeof(DLA_ELEM_OP)); i++)
            {
                if (op == rcd_p->m_op[i])
                {
                    return DLA_TRUE;
                }
            }
            break;
        }
    }

    return DLA_FALSE;
}

static DLA_BOOL mmi_am_dla_list_elem_op(DLA_ELEM_BASE* elem_cp, DLA_ELEM_OP op)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_BOOL ret_b = DLA_FALSE;
    DLA_ELEM_STS sts = DLA_ELEM_STS_NONE;
    DLA_BOOL ret_sts_changed_b = DLA_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_cp);

    sts = elem_cp->m_sts;

    ret_b = mmi_am_dla_list_elem_is_op_valid(elem_cp->m_sts, op);
    if (DLA_FALSE == ret_b)
    {
        DS_OUTLOG("[DLA] [F] mmi_am_dla_list_elem_is_op_valid sts[%d], op[%d]", elem_cp->m_sts, op);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 10, 
            elem_cp->m_sts, op, 0, 0, 0, 0);
        //ASSERT(0);
        return DLA_FALSE;
    }

    switch (op)
    {
    case DLA_ELEM_OP_START:
        {
            // start the failure one.
            ret_b = elem_cp->m_vptr->v_start(elem_cp);
            sts = DLA_ELEM_STS_DOWNLOADING;
            ret_sts_changed_b = DLA_TRUE;
        }break;
    case DLA_ELEM_OP_PAUSE:
        {
            ret_b = elem_cp->m_vptr->v_pause(elem_cp);
            //sts = DLA_ELEM_STS_PAUSED;
            //ret_sts_changed_b = DLA_TRUE;
        }break;
    case DLA_ELEM_OP_RESUME:
        {
            ret_b = elem_cp->m_vptr->v_resume(elem_cp);
            sts = DLA_ELEM_STS_DOWNLOADING;
            ret_sts_changed_b = DLA_TRUE;
        }break;
    case DLA_ELEM_OP_REMOVE:
        {
            ret_b = elem_cp->m_vptr->v_remove(elem_cp);
        }break;
    case DLA_ELEM_OP_VIEW:
        {
            ret_b = elem_cp->m_vptr->v_view(elem_cp);
        }break;
    default:
        {

        }break;

    }

#if 1
    // [AUTO OP] shift the current one next status after user opration
    if (ret_sts_changed_b && ret_b)
    {
        mmi_am_dla_list_elem_set_sts(elem_cp, sts);
        //sg_dla_ctx_p->m_ap_idx_hl_list_curr = DS_VECTOR_FIND(elem_cp);
    }
#endif


    return ret_b;
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
#endif


/*
static DLA_BOOL mmi_am_dla_list_elem_start(const DLA_ELEM_BASE* elem_cp)
{
return DLA_TRUE;
}

static DLA_BOOL mmi_am_dla_list_elem_pause()
{
return DLA_TRUE;
}

static DLA_BOOL mmi_am_dla_list_elem_resume()
{
return DLA_TRUE;
}

static DLA_BOOL mmi_am_dla_list_elem_set_sts(CTX * ctx_p, DLA_ELEM_STS sts)
{

}
*/

/**********************************************************************
* SCREEN PART START
***********************************************************************/
static void mmi_am_dla_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    mmi_popup_property_struct arg;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_get_active_id();


    mmi_popup_property_init(&arg);              
    arg.callback = NULL;       
    arg.user_tag = NULL;          
    arg.parent_id = parent_gid; 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
    mmi_popup_display(                          
        str_ptr,                                
        type,                                   
        &arg);  

}

static void mmi_am_dla_update_scrn(const DLA_ELEM_BASE * elem_cp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    


    DS_OUTLOG("mmi_am_dla_update_scrn S");    
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 11);

    // update.

    mmi_frm_get_active_scrn_id(&group_id, &scrn_id); 

    // list screen.
    if (SCR_ID_DLA_LIST == scrn_id)
    {
        mmi_am_dla_option_list_entry_again();
        return;
    }

    // detail screen.
    if (NULL == elem_cp)
    {
        // last one was done in detail view screen.
        if (SCR_ID_DLA_LIST_DETAIL == scrn_id)
        {
            //mmi_ret ret = 0;
            //MMI_ID group_id = 0;
            //MMI_ID scrn_id = 0;
            //ret = mmi_frm_scrn_close(group_id, SCR_ID_DLA_LIST_DETAIL);
            mmi_frm_scrn_close_active_id();
            //ret = 0;
        }

        return; // not located in dla.
    }

    if (SCR_ID_DLA_LIST_DETAIL == scrn_id && 
        elem_cp  == DS_VECTOR_DATA[sg_dla_ctx_p->m_ap_idx_hl_list_curr]) // the one need to be updated
    {
        if (DLA_ELEM_STS_DOWNLOADING == elem_cp->m_sts)
        {

            DLA_WSTR tmp_buf_wsz[32] = {0};
            U16 percentage = elem_cp->m_total ? (DLA_U32)(((FLOAT)elem_cp->m_exist / elem_cp->m_total) * 100) : 0;   
            kal_wsprintf(tmp_buf_wsz, "%d KB/%d KB", elem_cp->m_exist >> 10, elem_cp->m_total >> 10);
            UpdateCategory402Value(percentage, (PU8)tmp_buf_wsz);
        }     
        else if (DLA_ELEM_STS_FAILURE == elem_cp->m_sts)
        {
            elem_cp->m_vptr->v_view((DLA_ELEM_BASE *)elem_cp);
        }
    }



    DS_OUTLOG("mmi_am_dla_update_scrn E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 11);
}

static mmi_ret mmi_am_dla_list_grp_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 i;
    //mmi_ret ret = MMI_RET_OK;
    //cui_menu_event_struct *evt_menu = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt);

    //evt_menu = (cui_menu_event_struct*)evt;

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
        //ret = mmi_am_grp_first_entry();
        break;

    case EVT_ID_GROUP_ACTIVE:
        //ret = mmi_am_grp_active();
        break;

    case EVT_ID_GROUP_INACTIVE:
        //ret = mmi_am_grp_inactive();
        break;

    case EVT_ID_GROUP_DEINIT:

        //ret = mmi_am_grp_deinit();
        //mmi_am_dla_list_reload();
        break;

        /************************* Menu CUI event *****************************/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_ITEM_HILITE:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
    case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_ABORT:
        {
            //cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            /*ret = */mmi_am_dla_list_option_menu_cb(evt);
        }
        break;


    }

    return MMI_RET_OK;
}

static mmi_ret mmi_am_dla_list_option_menu_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    cui_event_inline_submit_struct *submit_struct_p = NULL;
    DLA_ELEM_BASE * elem_p = NULL;
    mmi_menu_id  menu_ids[DLA_ELEM_OP_TOTAL - 1] = {0};
    DLA_U32 i = 0;
    DLA_U32 span = MENU_ID_DLA_OPTION_LIST_NONE - DLA_ELEM_OP_NONE;
#if 0
/* under construction !*/
#endif
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    elem_p = (DLA_ELEM_BASE*)DS_VECTOR_DATA[sg_dla_ctx_p->m_ap_idx_hl_list_curr];



    menu_evt = (cui_menu_event_struct *)evt;

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            if (NULL != elem_p)
            {
                for (i = DLA_ELEM_OP_NONE + 1; i < DLA_ELEM_OP_TOTAL - 1; i++)
                {
                    if (DLA_ELEM_OP_NONE != sts_op_tbl[elem_p->m_sts].m_op[i - 1])
                    {
                        menu_ids[i - 1] = sts_op_tbl[elem_p->m_sts].m_op[i - 1] + span;
                    }
                    else
                    {
                        break;
                    }
                }

                //menu_ids[i - 1] = MENU_ID_DLA_OPTION_LIST_TST;

                cui_menu_set_currlist(menu_evt->sender_id, /*i*/i  - 1, menu_ids); // TODO: DO NOT FORGET
                cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_RETRY, (WCHAR*)GetString(STR_ID_AM_DLA_LIST_OPTION_RETRY));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_PAUSE, (WCHAR*)GetString(STR_GLOBAL_PAUSE));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_RESUME, (WCHAR*)GetString(STR_GLOBAL_RESUME));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_REMOVE, (WCHAR*)GetString(STR_GLOBAL_REMOVE));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_DETAIL, (WCHAR*)GetString(STR_ID_AM_DLA_OPTION_DOWNLOAD_STATUS));           
                //cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_LIST_TST, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));           

            }



            break;
        }
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            submit_struct_p = (cui_event_inline_submit_struct *)evt;
            switch (submit_struct_p->item_id)
            {

                //mmi_demo1_list1_setting_confirm(svr_addr_p);

            }
        }break;
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
            case MENU_ID_DLA_OPTION_LIST_RETRY:
                {
                    mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_START);
                }
                break;
            case MENU_ID_DLA_OPTION_LIST_PAUSE:
                {
                    mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_PAUSE);

                }
                break;
            case MENU_ID_DLA_OPTION_LIST_RESUME:
                {
                    mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_RESUME);

                }
                break;
            case MENU_ID_DLA_OPTION_LIST_REMOVE:
                {

                    /* ask user if wish to remove the item from list */
                    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
                    arg.callback = (mmi_proc_func) mmi_am_dla_list_option_remove_confirm_cb;
                    arg.parent_id = SCR_ID_DLA_APP;
                    mmi_confirm_display((WCHAR*) get_string(STR_GLOBAL_REMOVE), MMI_EVENT_QUERY, &arg);

                }
                break;
            case MENU_ID_DLA_OPTION_LIST_DETAIL:
                {
                    mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_VIEW);

                }
                break;
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
#endif
            default:
                {
                    ASSERT(0);
                }
                break;
            }
            //if (MENU_ID_DLA_OPTION_LIST_TST != menu_evt->highlighted_menu_id)
            //{
            cui_inline_close(menu_evt->sender_id);
            //}
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
        }break;

    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;
    }
    return MMI_RET_OK;
}


static void mmi_am_dla_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id = 0;
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = MENU_ID_DLA_OPTION_LIST;
    cui_gid = cui_menu_create(SCR_ID_DLA_APP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        menu_id,
        MMI_FALSE, 
        NULL);	                            
    cui_menu_set_default_title(cui_gid,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        NULL//(UI_image_type)get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID))
        );
    cui_menu_run(cui_gid);
}

static S32 mmi_am_dla_list_item_update_cb(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    DLA_ELEM_BASE **tmp_pp = NULL;
    DLA_WSTR tmp_percentage_wsz[32] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_pp = (DLA_ELEM_BASE**)&DS_VECTOR_DATA[start_index];
    //mmi_am_dla_list_elem_set_sts(tmp_pp[0], DLA_ELEM_STS_FAILURE); // test
    for (i = 0 ; i < data_size; i++)
    {
        //kal_wsprintf(tmp_tst_wsz, "APID [%d]", tmp_pp[i]->m_ap_id);
        tmp_percentage_wsz[0] = 0;
        mmi_ucs2cpy((S8*)menu_data[i].item_list[0], /*(S8*)tmp_tst_wsz*/(S8*)GetString(tmp_pp[i]->m_name_id));

        if (0 < tmp_pp[i]->m_total)
        {
            kal_wsprintf(tmp_percentage_wsz, "%d", (S32)((FLOAT)tmp_pp[i]->m_exist / tmp_pp[i]->m_total * 100));
            mmi_wcscat(tmp_percentage_wsz, L"%");
        }

        mmi_ucs2cpy((S8*)menu_data[i].item_list[1], (S8*)tmp_percentage_wsz);
        mmi_ucs2cpy((S8*)menu_data[i].item_list[2], GetString(sts_op_tbl[tmp_pp[i]->m_sts].m_sts_string_id));
        menu_data[i].image_list[0] = (U8*)GetImage((U16)(IMG_GLOBAL_L1 + i + start_index));
    }

    return i;
}

static void mmi_am_dla_list_item_hl_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sg_dla_ctx_p);
    sg_dla_ctx_p->m_ap_idx_hl_list_curr = index;

}

static void mmi_am_dla_ds_sts_cb(S32 result, const mre_dltm_node *changed_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_BOOL ret_b = DLA_FALSE;
    DLA_ELEM_BASE ** elem_pp = NULL;
    DLA_ELEM_BASE * elem_p = NULL;
    DLA_U32 i = 0;
    //DLA_ELEM_STS sts = DLA_ELEM_STS_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // not init dla or list empty.
    if (NULL == sg_dla_ctx_p || 0 == DS_VECTOR_SIZE())
    {
        DS_OUTLOG("mmi_am_dla_ds_sts_cb sg_dla_ctx_p[0x%x], DS_VECTOR_SIZE[%d]", sg_dla_ctx_p, DS_VECTOR_SIZE());
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 121, 
            sg_dla_ctx_p, DS_VECTOR_SIZE(), 0, 0, 0, 0);
        return;
    }

    // sort
    if (MRE_DLTM_RET_SUCCESS == result ||
        MRE_DLTM_RET_NODE_MOVED == result ||
        MRE_DLTM_RET_NODE_REMOVED == result ||
        MRE_DLTM_RET_NODE_PAUSED == result ||
        MRE_DLTM_RET_NODE_WAITING == result ||
        MRE_DLTM_RET_ERR == result ||
        MRE_DLTM_RET_NET_ERR == result ||
        MRE_DLTM_RET_SAVE_ERR == result ||
        MRE_DLTM_RET_NOT_EXIST == result ||
        MRE_DLTM_RET_OTHER_ERR == result ||
        MRE_DLTM_RET_FILE_NOT_EXIST == result ||
        MRE_DLTM_RET_IO_ERROR == result ||
        MRE_DLTM_RET_SPACE_FULL == result)
    {

        DS_OUTLOG("mmi_am_dla_ds_sts_cb sort result[%d]", result);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 122, 
            result, 0, 0, 0, 0, 0);

        if (MRE_DLTM_RET_SUCCESS == result &&
            changed_node && 
            0 == changed_node->download_info.total_size)
        {
            sg_dla_ctx_p->m_ap_idx_hl_list_curr = mmi_am_dla_list_reload(sg_dla_ctx_p->m_ap_idx_hl_list_curr);
            if (-1 == sg_dla_ctx_p->m_ap_idx_hl_list_curr)
            {
                sg_dla_ctx_p->m_ap_idx_hl_list_curr = 0;
            }
            else if ((DLA_S32)DS_VECTOR_SIZE() <= sg_dla_ctx_p->m_ap_idx_hl_list_curr)
            {
                if (DS_VECTOR_SIZE() > 0)
                    sg_dla_ctx_p->m_ap_idx_hl_list_curr = DS_VECTOR_SIZE() - 1;
            }
        }
        else
        {
            sg_dla_ctx_p->m_ap_idx_hl_list_curr = mmi_am_dla_list_reload(sg_dla_ctx_p->m_ap_idx_hl_list_curr);
            if (-1 == sg_dla_ctx_p->m_ap_idx_hl_list_curr)
            {
                sg_dla_ctx_p->m_ap_idx_hl_list_curr = 0;
            }
            else if ((DLA_S32)DS_VECTOR_SIZE() <= sg_dla_ctx_p->m_ap_idx_hl_list_curr)
            {
                if (DS_VECTOR_SIZE() > 0)
                    sg_dla_ctx_p->m_ap_idx_hl_list_curr = DS_VECTOR_SIZE() - 1;
            }
        }

    }


    if (NULL == changed_node)
    {
        DS_OUTLOG("mmi_am_dla_ds_sts_cb result[%d]", result);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 123, 
            result, 0, 0, 0, 0, 0);
    }
    else
    {
        DS_OUTLOG("[DLA] mmi_am_dla_ds_sts_cb result[%d], state[%d], [%d/%d], apid[%d]", 
            result, 
            changed_node->state, 
            changed_node->download_info.download_size,
            changed_node->download_info.total_size,
            changed_node->id);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 124,
            result, 
            changed_node->state, 
            changed_node->download_info.download_size,
            changed_node->download_info.total_size,
            changed_node->id,
            0);

        elem_pp = (DLA_ELEM_BASE **)DS_VECTOR_DATA;

        for (i = 0;i < DS_VECTOR_SIZE(); i++)
        {
            if (elem_pp[i]->m_ap_id == changed_node->id)
            {
                ret_b = DLA_TRUE;
                break;
            }
        }

        ASSERT(ret_b);
        DS_OUTLOG("vector size[%d] idx[%d]", DS_VECTOR_SIZE(), i);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 125,
            DS_VECTOR_SIZE(), i, 0, 0, 0, 0);

        elem_p = elem_pp[i];
    }

    switch (result)
    {
        // downloading
    case MRE_DLTM_RET_SUCCESS:
        {
            //ASSERT(changed_node->download_info.download_size >= (S32)elem_pp[i]->m_exist);
            //ASSERT(changed_node->download_info.total_size == (S32)elem_pp[i]->m_total);
            elem_p->m_total = changed_node->download_info.total_size;
            elem_p->m_exist = changed_node->download_info.download_size;
            //mmi_am_dla_list_elem_set_sts(elem_p, DLA_ELEM_STS_DOWNLOADING);
        }
        break;
        // finished
    case MRE_DLTM_RET_DONE:
        {
            //ASSERT(changed_node->download_info.total_size == elem_pp[i]->m_total);
            //ASSERT(changed_node->download_info.total_size == elem_pp[i]->m_exist);
            //mmi_am_ms_shortcut_app_download_suc(elem_p->m_ap_id, elem_p->m_path);
            mmi_am_ms_set_app_download(g_am_ms_cntx.hl_idx, (S8)(elem_p->m_path[0]));
        }
        break;
    default:
        {

            DS_OUTLOG("default result[%d] idx[%d]", result, i);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 126,
                result, i, 0, 0, 0, 0);

        }
        break;
    }

    //elem_p = DS_VECTOR_DATA[sg_dla_ctx_p->m_ap_idx_hl_list_curr];


    mmi_am_dla_update_scrn(elem_p);
}

mmi_ret mmi_am_dla_ds_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_dltm_notify_struct *dltm_evt = (srv_mre_dltm_notify_struct*)evt;

    mmi_am_dla_ds_sts_cb(dltm_evt->result, dltm_evt->changed_node);
    //temp_download_app_cb(dltm_evt->result, dltm_evt->changed_node);
    return MMI_TRUE;
}

static mmi_ret mmi_am_dla_option_download_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_BOOL ret_b = DLA_FALSE;
    DLA_ELEM_BASE* elem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sg_dla_ctx_p);


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                elem_p = mmi_am_dla_list_elem_get(sg_dla_ctx_p->m_ap_id_curr);
                if (elem_p)
                {
                    DS_OUTLOG("[DLA] [F] elem_p->m_ap_id already exist");
                    ASSERT(0);
                }

                ret_b = mmi_am_dla_list_elem_add(&elem_p, sg_dla_ctx_p->m_ap_id_curr);
                if (DLA_FALSE == ret_b)
                {
                    DS_OUTLOG("[DLA] [F] mmi_am_dla_list_elem_add list full");
                    mmi_popup_display_simple(
                        (WCHAR*) get_string(STR_ID_AM_DLA_POP_LIST_FULL),
                        MMI_EVENT_FAILURE,
                        PARENT_ID,
                        NULL);
                }
                else
                {
                    mmi_popup_display_simple(
                        (WCHAR*) get_string(STR_GLOBAL_ADD),
                        MMI_EVENT_SUCCESS,
                        PARENT_ID,
                        NULL);
                }
            }
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}

static mmi_ret mmi_am_dla_list_option_remove_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //DLA_BOOL ret_b = DLA_FALSE;
    DLA_ELEM_BASE* elem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sg_dla_ctx_p);


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                elem_p = (DLA_ELEM_BASE*)DS_VECTOR_DATA[sg_dla_ctx_p->m_ap_idx_hl_list_curr];
                ASSERT(elem_p);
                mmi_am_dla_list_elem_op(elem_p, DLA_ELEM_OP_REMOVE);
            }
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}

static mmi_ret mmi_am_dla_op_outside_download_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ds_apid = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                S8 drv = 0;
                DLA_WSTR filename[DLA_MAX_FILE_LEN] = {0};  //Download filepath
                //mmi_am_quick_launch_info_struct *ql_info;

                drv = mmi_am_dla_get_drv();
                // no device to save.
                if (0 == drv)
                {
                    mmi_popup_display_simple((WCHAR*) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                        MMI_EVENT_FAILURE,
                        PARENT_ID,
                        NULL);
                    break;
                }

                // build the path.
                //ql_info = mmi_am_config_get_ql_info_by_appid((mmi_am_shortcut_id_enum)apid_outside);                    
                //kal_wsprintf(filename, "%c:\\"MMI_AM_MRE_HOME_DIR"\\%s", drv, ql_info->file_name);
                // TODO: start to download

                ds_apid = mre_dltm_add(apid_outside, (U16*)filename);

                if (MRE_DLTM_RET_APP_HAVE_EXIST == ds_apid)
                {
                    mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_DLA_TXT_EXIST),
                        MMI_EVENT_FAILURE,
                        PARENT_ID,
                        NULL);
                }
                else if (MRE_DLTM_MAX_NODE_COUNT == ds_apid)
                {
                    mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_DLA_POP_LIST_FULL),
                        MMI_EVENT_FAILURE,
                        PARENT_ID,
                        NULL);
                }
                else
                {
                    mmi_popup_display_simple((WCHAR*) get_string(STR_GLOBAL_ADD),
                        MMI_EVENT_SUCCESS,
                        PARENT_ID,
                        NULL);
                }

            }
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_am_dla_tap_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DLA_ELEM_BASE * elem_p = (DLA_ELEM_BASE*)DS_VECTOR_DATA[index];
    DLA_ELEM_OP op = DLA_ELEM_OP_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    op = sts_op_tbl[elem_p->m_sts].m_op[0];

    if (ENUM_TAP_ON_HIGHLIGHTED_ITEM == tap_type)
    {   

        mmi_am_dla_list_elem_op(elem_p, op);
    }
}

#endif

static DLA_BOOL mmi_am_dla_check_mre_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE memory_card_hdl = -1, system_hdl = -1;    /* create mre folder return value */
    S8 mre_path[20];
    U16 mre_path_w[20];
    FS_HANDLE fd = -1;
    S8 file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sg_dla_ctx_p);

    DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() ------- [S]");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 13);

    /* Firstly, create a mre folder in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- remove_driver:%d", file_drv);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 131,
        file_drv, 0, 0, 0, 0, 0);
    if (sg_dla_ctx_p->m_drv_mre_card > 0)  
    {
        memory_card_hdl = FS_NO_ERROR;
    }
    else if (file_drv != 0)
    {
        memset(mre_path, 0, sizeof(mre_path));
        memset(mre_path_w, 0, sizeof(mre_path_w));
        sprintf(mre_path, "%c:\\%s", file_drv, MMI_AM_MRE_HOME_DIR);
        mmi_asc_to_wcs(mre_path_w, mre_path);

        if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= 0)     /* mre is not folder */
        {
            DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- mre is not folder");

            FS_Close(fd);
            FS_Delete(mre_path_w);
        }

        memory_card_hdl = FS_CreateDir(mre_path_w);
        DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- memory_card_hdl:%d", memory_card_hdl);
        if (memory_card_hdl == FS_NO_ERROR || memory_card_hdl == FS_FILE_EXISTS)
        {
            //sg_dla_ctx_p->m_hdl_mre_card = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY);
            memory_card_hdl = FS_NO_ERROR;
            //FS_Close(sg_dla_ctx_p->m_hdl_mre_card);
        }

        sg_dla_ctx_p->m_drv_mre_card = file_drv;

        fd = -1;
    }
    else
    {
        sg_dla_ctx_p->m_drv_mre_card = 0;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 132,
        sg_dla_ctx_p->m_drv_mre_card, 0, 0, 0, 0, 0);


    /* Secondly, create a mre folder in system driver */
    file_drv = mmi_am_get_system_driver();
    DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- system_driver:%d", file_drv);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 133,
        file_drv, 0, 0, 0, 0, 0);
    if (sg_dla_ctx_p->m_drv_mre_phone > 0)
    {
        system_hdl = FS_NO_ERROR;
    }
    else if (file_drv != 0)
    {
        memset(mre_path, 0, sizeof(mre_path));
        memset(mre_path_w, 0, sizeof(mre_path_w));
        sprintf(mre_path, "%c:\\%s", file_drv, MMI_AM_MRE_HOME_DIR);
        mmi_asc_to_wcs(mre_path_w, mre_path);

        if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= 0)     /* mre is not folder */
        {
            DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- mre is not folder");

            FS_Close(fd);
            FS_Delete(mre_path_w);
        }

        system_hdl = FS_CreateDir(mre_path_w);
        DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() -- system_hdl:%d", system_hdl);
        if (system_hdl == FS_NO_ERROR || system_hdl == FS_FILE_EXISTS)
        {
            //sg_dla_ctx_p->m_hdl_mre_phone = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY);
            system_hdl = FS_NO_ERROR;
            //FS_Close(sg_dla_ctx_p->m_hdl_mre_phone);
        }

        sg_dla_ctx_p->m_drv_mre_phone = file_drv;
    }
    else
    {
        sg_dla_ctx_p->m_drv_mre_phone = 0;
    }


    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 134,
        sg_dla_ctx_p->m_drv_mre_phone, 0, 0, 0, 0, 0);

    DS_OUTLOG(
        "mmi_am_dla_check_mre_folder() --memory_card_hdl:%d system_hdl:%d",
        memory_card_hdl,
        system_hdl);

    if (memory_card_hdl < FS_NO_ERROR && system_hdl < FS_NO_ERROR)
    {
        DS_OUTLOG("[DLA] mmi_am_dla_check_mre_folder() ------- [E1]");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 13);
        return DLA_FALSE;
    }



    DS_OUTLOG("[DLA] mmi_am_check_mre_folder() ------- [E2]");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 13);
    return DLA_TRUE;
}

static S8 mmi_am_dla_get_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FS_HANDLE memory_card_hdl = -1, system_hdl = -1;    /* create mre folder return value */
    //FS_HANDLE fd = -1;
    S8 file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DS_OUTLOG("[DLA] mmi_am_dla_get_drv() ------- [S]");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 14);

    /* Firstly, create a mre folder in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    DS_OUTLOG("[DLA] mmi_am_dla_get_drv() -- remove_driver:%d", file_drv);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 141, 
        file_drv, 0, 0, 0, 0, 0);
    if (file_drv != 0)
    {
        DS_OUTLOG("[DLA] mmi_am_dla_get_drv() ------- [E1]");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 14);
        return file_drv;
    }


    /* Secondly, create a mre folder in system driver */
    file_drv = mmi_am_get_system_driver();
    DS_OUTLOG("[DLA] mmi_am_dla_get_drv() -- system_driver:%d", file_drv);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 142, 
        file_drv, 0, 0, 0, 0, 0);
    if (file_drv != 0)
    {
        DS_OUTLOG("[DLA] mmi_am_dla_get_drv() ------- [E2]");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E2, 14);
        return file_drv;
    }

    DS_OUTLOG("[DLA] mmi_am_dla_get_drv() ------- [E3]");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 14);
    return 0;
}



/* vtbl function - base */
static DLA_BOOL v_pb_start(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    USED(elem_p);
    ASSERT(0);
    return DLA_TRUE;
}

static DLA_BOOL v_pb_pause(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    USED(elem_p);
    ASSERT(0);
    return DLA_TRUE;
}

static DLA_BOOL v_pb_resume(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    USED(elem_p);
    ASSERT(0);
    return DLA_TRUE;
}


static DLA_BOOL v_pb_remove(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    DS_OUTLOG("[DLA] v_pb_remove S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 20);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_remove(elem_p->m_ds_ap_id))
    {
        DS_OUTLOG("[DLA] v_pb_remove E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 20);
        return DLA_FALSE;
    }

    DS_OUTLOG("[DLA] v_pb_remove E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 20);


    return DLA_TRUE;
}


static DLA_BOOL v_pb_view(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    USED(elem_p);
    ASSERT(0);
    return DLA_TRUE;
}


/* vtbl function - derived */
// 1.auto
// 2.use op the first one only
static DLA_BOOL v_dl_start(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DLA_S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);
    DS_OUTLOG("[DLA] v_dl_start S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 15);
    DS_OUTLOG("[DLA] v_dl_start ap_handle[%d]", elem_p->m_ds_ap_id);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_LOG, 151, 
        elem_p->m_ds_ap_id, 0, 0, 0, 0, 0);
    ret = mre_dltm_start(elem_p->m_ds_ap_id);
    if (MRE_DLTM_RET_SUCCESS != ret && MRE_DLTM_RET_DOWNLOADING_ERR != ret)
    {
        DS_OUTLOG("[DLA] v_dl_start E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 15);
        return DLA_FALSE;
    }
    DS_OUTLOG("[DLA] v_dl_start E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 15);
    return DLA_TRUE;
}
static DLA_BOOL v_dl_pause(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);
    DS_OUTLOG("[DLA] v_dl_pause S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 16);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_pause(elem_p->m_ds_ap_id))
    {
        DS_OUTLOG("[DLA] v_dl_pause E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 16);
        return DLA_FALSE;
    }
    DS_OUTLOG("[DLA] v_dl_pause E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 16);
    return DLA_TRUE;
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
#endif

static void mmi_am_dla_dl_view_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR tmp_name_wsz[32] = {0};
    WCHAR tmp_status_wsz[32] = {0};
    WCHAR tmp_buf_wsz[64] = {0};
    DLA_ELEM_BASE * elem_p = sg_dla_ctx_p->m_elem_p;
    DLA_U32 percent = 0;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("[DLA] v_dl_view S");    
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 18);
    if (NULL == elem_p)
    {
        mmi_am_dla_update_scrn(elem_p);
        return;
    }

    percent = elem_p->m_total ? (DLA_U32)(((FLOAT)elem_p->m_exist / elem_p->m_total) * 100) : 0;

    //EntryNewScreen(SCR_ID_DLA_LIST_DETAIL, NULL, NULL, NULL);
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    group_id = mmi_frm_group_get_top_parent_group_id(group_id);
    mmi_frm_scrn_enter(
        group_id, 
        SCR_ID_DLA_LIST_DETAIL,
        NULL,
        mmi_am_dla_dl_view_again,
        MMI_FRM_FULL_SCRN);

    kal_wstrcpy(tmp_name_wsz, (WCHAR*)GetString(elem_p->m_name_id));

    mmi_wcscat(tmp_status_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_STATUS));
    mmi_wcscat(tmp_status_wsz, L":");
    mmi_wcscat(tmp_status_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_DOWNLOADING));

    kal_wsprintf(tmp_buf_wsz, "%d KB/%d KB", elem_p->m_exist >> 10, elem_p->m_total >> 10);

    ShowCategory402Screen((PU8) tmp_name_wsz,
        0,  
        0,
        0,
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        (PU8)tmp_status_wsz,
        (U16)percent,
        (PU8)tmp_buf_wsz);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    DS_OUTLOG("[DLA] v_dl_view E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 18);
}

static DLA_BOOL v_dl_view(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    // update.
    ASSERT(elem_p);

    sg_dla_ctx_p->m_elem_p = elem_p;
    mmi_am_dla_dl_view_again();

    return DLA_TRUE;
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
#endif

static DLA_BOOL v_wt_pause(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    DS_OUTLOG("[DLA] v_wt_pause S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 19);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_pause(elem_p->m_ds_ap_id))
    {
        DS_OUTLOG("[DLA] v_wt_pause E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 19);
        return DLA_FALSE;
    }

    DS_OUTLOG("[DLA] v_wt_pause E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 19);
    return DLA_TRUE;
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
#endif

static void mmi_am_dla_wt_view_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static DLA_U16 tmp_buf_wsz[128] = {0};
    S32 size = 0;
    DLA_ELEM_BASE * elem_p = sg_dla_ctx_p->m_elem_p;
    U8 *gui_buffer = NULL;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    DS_OUTLOG("[DLA] v_wt_view S");
    memset(tmp_buf_wsz, 0, sizeof(tmp_buf_wsz));
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 21);
    if (NULL == elem_p)
    {
        mmi_am_dla_update_scrn(elem_p);
        return;
    }

    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    group_id = mmi_frm_group_get_top_parent_group_id(group_id);
    //EntryNewScreen(SCR_ID_DLA_LIST_DETAIL, NULL, NULL, NULL);
    mmi_frm_scrn_enter(
        group_id, 
        SCR_ID_DLA_LIST_DETAIL,
        NULL,
        mmi_am_dla_wt_view_again,
        MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_STATUS));
    mmi_wcscat(tmp_buf_wsz, L":\r");
    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_WAITING));

    size = 2*mmi_wcslen(tmp_buf_wsz) + 2;

    ShowCategory74Screen(
        elem_p->m_name_id,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)tmp_buf_wsz,
        size,
        (PU8)gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    DS_OUTLOG("[DLA] v_wt_view E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 21);

}
static DLA_BOOL v_wt_view(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //DLA_U16 tmp_buf_wsz[128] = {0};
    //S32 size = 0;

    //U8 *gui_buffer = NULL;
    //MMI_ID group_id = 0;
    //MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    sg_dla_ctx_p->m_elem_p = elem_p;
    mmi_am_dla_wt_view_again();
    return DLA_TRUE;
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
#endif

static DLA_BOOL v_ps_resume(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    DS_OUTLOG("[DLA] v_ps_resume S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 22);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_start(elem_p->m_ds_ap_id))
    {
        DS_OUTLOG("[DLA] v_ps_resume E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 22);
        return DLA_FALSE;
    }

    DS_OUTLOG("[DLA] v_ps_resume E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 22);
    return DLA_TRUE;
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
#endif

static void mmi_am_dla_ps_view_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR tmp_name_wsz[32] = {0};
    WCHAR tmp_status_wsz[32] = {0};
    WCHAR tmp_buf_wsz[64] = {0};
    DLA_ELEM_BASE * elem_p = sg_dla_ctx_p->m_elem_p;
    DLA_U32 percent = 0;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("[DLA] v_ps_view S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 24);
    if (NULL == elem_p)
    {
        mmi_am_dla_update_scrn(elem_p);
        return;
    }

    percent = elem_p->m_total ? (DLA_U32)(((FLOAT)elem_p->m_exist / elem_p->m_total) * 100) : 0; 

    //EntryNewScreen(SCR_ID_DLA_LIST_DETAIL, NULL, NULL, NULL);
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id); 
    group_id = mmi_frm_group_get_top_parent_group_id(group_id);
    mmi_frm_scrn_enter(
        group_id, 
        SCR_ID_DLA_LIST_DETAIL,
        NULL,
        mmi_am_dla_ps_view_again,
        MMI_FRM_FULL_SCRN);

    kal_wstrcpy(tmp_name_wsz, (WCHAR*)GetString(elem_p->m_name_id));

    mmi_wcscat(tmp_status_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_STATUS));
    mmi_wcscat(tmp_status_wsz, L":");
    mmi_wcscat(tmp_status_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_PAUSED));

    kal_wsprintf(tmp_buf_wsz, "%d KB/%d KB", elem_p->m_exist >> 10, elem_p->m_total >> 10);

    ShowCategory402Screen((PU8) tmp_name_wsz,
        0,  
        0,
        0,
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        (PU8)tmp_status_wsz,
        (U16)percent,
        (PU8)tmp_buf_wsz);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);


    DS_OUTLOG("[DLA] v_ps_view E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 24);
}

static DLA_BOOL v_ps_view(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    sg_dla_ctx_p->m_elem_p = elem_p;
    mmi_am_dla_ps_view_again();

    return DLA_TRUE;
}

static DLA_BOOL v_fl_start(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    DS_OUTLOG("[DLA] v_fl_start S");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 25);
    if (MRE_DLTM_RET_SUCCESS != mre_dltm_start(elem_p->m_ds_ap_id))
    {
        DS_OUTLOG("[DLA] v_fl_start E1");
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E1, 25);
        return DLA_FALSE;
    }
    DS_OUTLOG("[DLA] v_fl_start E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 25);


    return DLA_TRUE;
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
#endif

static void mmi_am_dla_fl_view_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static DLA_WSTR tmp_buf_wsz[128] = {0};
    S32 size = 0;

    U8 *gui_buffer = NULL;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;
    DLA_ELEM_BASE * elem_p = sg_dla_ctx_p->m_elem_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_ID_DLA_LIST_DETAIL, NULL, NULL, NULL);
    DS_OUTLOG("[DLA] v_fl_view S");
    memset(tmp_buf_wsz, 0, sizeof(tmp_buf_wsz));
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_S, 27);
    if (NULL == elem_p)
    {
        mmi_am_dla_update_scrn(elem_p);
        return;
    }
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    group_id = mmi_frm_group_get_top_parent_group_id(group_id);
    mmi_frm_scrn_enter(
        group_id, 
        SCR_ID_DLA_LIST_DETAIL,
        NULL,
        mmi_am_dla_fl_view_again,
        MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    // TODO: unkown content

    //kal_wsprintf(tmp_name_wsz, "%s", elem_p->m_apname);

    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_STATUS));
    mmi_wcscat(tmp_buf_wsz, L":\r");
    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_FAILURE));
    mmi_wcscat(tmp_buf_wsz, L"\r\r");
    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_EXIST));
    mmi_wcscat(tmp_buf_wsz, L"/");
    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_TOTAL));
    mmi_wcscat(tmp_buf_wsz, L"\r");
    kal_wsprintf(&tmp_buf_wsz[mmi_wcslen(tmp_buf_wsz)], "%d KB/%d KB\r\r", elem_p->m_exist >> 10, elem_p->m_total >> 10);
    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(STR_ID_AM_DLA_TXT_REASON));
    mmi_wcscat(tmp_buf_wsz, L":\r");

    mmi_wcscat(tmp_buf_wsz, (WCHAR*)GetString(elem_p->m_err_id));

    size = 2*mmi_wcslen(tmp_buf_wsz) + 2;

    ShowCategory74Screen(
        elem_p->m_name_id,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)tmp_buf_wsz,
        size,
        (PU8)gui_buffer);


    /*                                            
    ShowCategory79Screen(        
    tmp_name_wsz,
    0,
    0,
    0,
    (WCHAR*)GetString(STR_GLOBAL_BACK),
    (PU8) GetImage(IMG_GLOBAL_BACK),
    MMI_FALSE,
    MMI_FALSE,
    (PU8)gui_buffer,
    size,
    (PU8)tmp_buf_wsz);
    */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    DS_OUTLOG("[DLA] v_fl_view E");
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DLA_E, 27);

}
static DLA_BOOL v_fl_view(DLA_ELEM_BASE* elem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(elem_p);

    sg_dla_ctx_p->m_elem_p = elem_p;
    mmi_am_dla_fl_view_again();
    return DLA_TRUE;
}



/**********************************************************************
* SCREEN PART END
***********************************************************************/


/************************************************************************/
/* DS DLAgent END                                                       */
/************************************************************************/
#else /* #ifdef MRE_DOWNLOAD_SRV */
void mmi_am_dla_op_outside_download(DLA_HANDLE h, DLA_APID id)
{
    return;
}
mmi_ret mmi_am_dla_ds_cb(mmi_event_struct *evt)
{
    return MMI_TRUE;
}
#endif /* #ifdef MRE_DOWNLOAD_SRV */


#if defined(WIN32) && defined(_DEBUG)

#include <stdio.h>
static const char* sg_file = NULL;
static int sg_line = 0;

void win32_setdata(int line, const char* file)
{
    sg_file = file;
    sg_line = line;
}

void win32_outlog(const char* log, ...)
{
    DS_S8 buf[DS_BUF_SIZE] = {0};
    va_list ap;
    va_start(ap, log);
    vsprintf(buf, log, ap);
    sprintf(&buf[strlen(buf)], " line[%d], file[%s]", sg_line, sg_file);
    va_end(ap);
    printf(buf);
}

#else /* defined(WIN32) && defined(_DEBUG) */

#define LOG_FOLDER L"DS_LOG\\"
#define LOG_FILE L"ds.txt"

static const char* sg_file = NULL;
static int sg_line = 0;


static FS_HANDLE ds_fileopen(const DS_U16* name);
static DS_S32 ds_filewrite(FS_HANDLE hdl, const DS_U16* txt, UINT size);
//static DS_S32 ds_fileread(FS_HANDLE hdl, DS_U16* txt, UINT size);
static DS_S32 ds_fileclose(FS_HANDLE hdl);


extern void target_setdata(DS_S32 line, const DS_S8* file)
{
    sg_file = file;
    sg_line = line;
}

extern void target_outfile(const DS_S8* log, ...)
{
    char buf[DS_BUF_SIZE] = {0};
    DS_U16 wszBuf[DS_BUF_SIZE] = {0};
    FS_HANDLE file_hdl = -1;

    va_list ap;
    va_start(ap, log);
    vsprintf(buf, log, ap);
    sprintf(&buf[strlen(buf)], " line[%d], file[%s]", sg_line, sg_file);
    va_end(ap);

    mmi_asc_n_to_wcs(wszBuf, buf, DS_BUF_SIZE);

    file_hdl = ds_fileopen(LOG_FILE);
    if (-1 == file_hdl)
    {
        return;
    }

    if (!ds_filewrite(file_hdl, wszBuf, 2*kal_wstrlen(wszBuf) + 2))
    {
        return;
    }

    if (0 > ds_fileclose(file_hdl))
    {
        return;
    }
}

extern void target_catcher(const DS_S8* log, ...)
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
#endif
}


static FS_HANDLE ds_fileopen(const DS_U16* name)
{
    DS_S32 drv = FS_NO_ERROR;
    DS_U16 pathname[80] = {0};
    FS_HANDLE folder_hdl = -1;
    FS_HANDLE file_hdl = -1;

    ASSERT(name);

    drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);

    if (FS_NO_ERROR > drv)
    {
        return file_hdl;
    }

    // THISrge pathnaTHIS
    kal_wsprintf(pathname, "%c:\\", (U8)drv);
    kal_wstrcat(pathname, LOG_FOLDER);

    // create if the path is not exist
    folder_hdl = FS_Open(pathname, FS_OPEN_DIR | FS_READ_ONLY);
    if (FS_NO_ERROR > folder_hdl)
    {
        folder_hdl = FS_CreateDir(pathname);
        ASSERT(folder_hdl >= FS_NO_ERROR);
    }
    else
    {
        FS_Close(folder_hdl);
    }

    kal_wstrcat(pathname, name);

    file_hdl = FS_Open(pathname, FS_READ_WRITE);
    if (FS_NO_ERROR > file_hdl)
    {
        file_hdl = FS_Open(pathname, FS_READ_WRITE | FS_CREATE);
    }

    return file_hdl;
}

static DS_S32 ds_filewrite(FS_HANDLE hdl, const DS_U16* txt, DS_U32 size)
{
    DS_S8 szbuf[DS_BUF_SIZE] = {0};
    DS_U16 wszbuf[DS_BUF_SIZE] = {0};
    DS_S32 len = 0;
    DS_U32 written = 0;

    ASSERT((FS_NO_ERROR <= hdl) && txt && (0 < size) && (DS_BUF_SIZE >=size));

    if (FS_NO_ERROR > FS_Seek(hdl, 0, FS_FILE_END))
    {
        return -1;
    }


    kal_wstrncpy(wszbuf, txt, size);
    mmi_wcs_n_to_asc(szbuf, wszbuf, size);
    strcat(&szbuf[strlen(szbuf)], "\r\n");

    len = strlen(szbuf);
    if (FS_NO_ERROR > FS_Write(hdl, szbuf, len, &written))
    {
        return -1;
    }

    return written;
}

static DS_S32 ds_fileclose(FS_HANDLE hdl)
{
    ASSERT(hdl);
    return FS_Close(hdl);
}

#endif /* defined(WIN32) && defined(_DEBUG) */

#endif /* __MRE_AM__ */
