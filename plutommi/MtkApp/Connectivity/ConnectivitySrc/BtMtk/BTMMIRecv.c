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
 * BTMMIRecv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for centralizing profile receiving behavior.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"

/* RHR ADD */
#include "MMI_features.h"
/* RHR ADD end */

#ifdef __MMI_BT_SUPPORT__
//#include "CommonScreens.h"
#include "app_mine.h"
#include "fs_func.h"
//#include "FileMgrGProt.h"
#include "GpioSrvGprot.h"
//#include "ConnectivityResDef.h"
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif
#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
//#include "OppSrvGprot.h"
#endif

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#endif
#include "BTMMIObexGprots.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "NotificationGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "GlobalConstants.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "FileMgrType.h"
/* RHR ADD end */

/*****************************************************************
    Internal structure Definition
*****************************************************************/
#define BTR_TEMP_FOLDER  L"@BTRecv\\"
#define BTR_TEMP_EXT     L"tmp"
#define BTR_DEF_NAME     "BTRecv%02x"
#define BTR_DEF_FOLDER   L"Received\\"
    
#define BTR_MAX_NAME     (16)
#define BTR_MAX_FOLDER   (60) //"Recieved\Images\Photo\"
#define BTR_MAX_STORAGE  (24)
#define BTR_MAX_PATH     (260)
#define BTR_MAX_DUP      (127)
    
#define BTR_EVENT_NOTIFY    (SCR_BT_SEL_DRV1)
#define btr_handle(p)    (S32)((U32)p & 0x00ffffff)

typedef enum {
    BTR_STATE_PENDING,
    BTR_STATE_READY,
    BTR_STATE_DELETE,
    BTR_STATE_END
} btr_state_enum;

typedef enum {
    BTR_COMP_STORAGE,
    BTR_COMP_OBJ_PATH,
    BTR_COMP_OBJ_FLDR,
    BTR_COMP_END
} btr_comp_enum;

typedef struct _btr_inst{
    S32 handle;
    bt_recv_notify notify;
    U8 option;
    U8 state;
    S32 obj_size;
#ifndef __MMI_BT_SLIM__
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U32 drv_count;
    U8 *str_list[SRV_FMGR_DRV_TOTAL];
    struct {
        U16 id;
        U16 sel_item;
    } scrn;
#endif
    struct _btr_inst *next;
    struct _btr_store{
        WCHAR *folder;
        WCHAR *name;
        U16 fd_size;
        U16 nm_size;
        S32 drive;
        U32 magic;
        U8 truncate;
        U8 dup_cnt;
        U8 data[1];
    } store;
} btr_inst_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    btr_inst_struct *inst;
    U32 event;
    S32 retval;
} btr_evt_struct;

/*****************************************************************
    Internal function Declaration
*****************************************************************/
#ifndef __MMI_BT_SLIM__
static S32 btr_select_drive(btr_inst_struct *inst);
static void btr_deselect_drive(btr_inst_struct *inst);
static MMI_BOOL btr_show_sel_drv(mmi_scenario_id scenario, void* arg);
static MMI_RET btr_sel_drv_proc(mmi_event_struct *event);
static U16 get_avail_scrn(void);
#endif
static btr_inst_struct *btr_new_inst(
            bt_recv_notify notify,
            const bt_recv_obj_info *obj,
            const bt_recv_storage *storage,
            U32 option);
static void btr_del_inst(btr_inst_struct *inst);
static btr_inst_struct *btr_find_inst(S32 hd);
static void btr_notify(btr_inst_struct *inst, U32 evt, S32 retval);
static S32 btr_create_storage(btr_inst_struct *inst);
static S32 btr_destroy_storage(btr_inst_struct *inst);
static S32 btr_create_object(btr_inst_struct *inst);
static MMI_RET btr_event_proc(mmi_event_struct *evt);
static void btr_post_event(btr_inst_struct *inst, U32 event, S32 retval);
static S32 btr_conv_code(S32 code);
static void btr_start_post_hdlr(btr_inst_struct *inst);
static void add_to_inst_list(btr_inst_struct **head, btr_inst_struct *inst);
static void del_from_inst_list(btr_inst_struct **head, btr_inst_struct *inst);
static U32 inst_in_list(btr_inst_struct *head, btr_inst_struct *inst);
static void compose_path(WCHAR *path, struct _btr_store *store, U8 opt);
static WCHAR *update_path(WCHAR *path, CHAR drive, WCHAR *file);
static S32 get_avail_drive(S32 size);
static WCHAR *default_folder(const bt_recv_obj_info *obj);
#ifdef __MMI_BT_RECV_FDR_SWITCH__
static applib_mime_type_struct *mime_lookup(CHAR *mime, WCHAR *ext);
static WCHAR *select_folder(U8 mime_type, U16 mime_subtype);
#endif /* __MMI_BT_RECV_FDR_SWITCH__ */
static S32 gen_folder(WCHAR *path, U8 Attributes);
static MMI_BOOL btr_dup_name(WCHAR *path, struct _btr_store *store);
static S32 truncate_name(struct _btr_store *store, WCHAR *head);
static void update_prefix(WCHAR * name, U8 seq);
static WCHAR *default_name(WCHAR *ext);
static WCHAR *get_extension(WCHAR *name);
static MMI_BOOL valid_path(WCHAR *folder, WCHAR *name, S32 *length);
static MMI_BOOL valid_name(WCHAR *name);

/*****************************************************************
    Global variable Definition
*****************************************************************/
static WCHAR g_obj_tmp_buff[SRV_FMGR_PATH_MAX_LEN+1];
static btr_inst_struct *g_btr_inst_list;
static MMI_BOOL g_recv_disabled;

#define BT_RECEIVE_API_DEFINITION
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_receiving
 * DESCRIPTION
 *  This function is exported to the app, to indicate whether BT is receving data.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is receiving data
                    FALSE : otherwise
 *****************************************************************************/
MMI_BOOL mmi_bt_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_receving = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_OPP_SUPPORT__
    {
        is_receving = mmi_opp_is_receiving();
        result |= is_receving;
    }
    #endif

    #ifdef __MMI_BIP_SUPPORT__
    {
        is_receving = mmi_bt_bip_is_receiving();
        result |= is_receving;
    }
    #endif

    #ifdef __MMI_FTS_SUPPORT__
    {
        is_receving = mmi_ftp_server_is_receiving();
        result |= is_receving;
    }
    #endif
    #ifdef __MMI_FTC_SUPPORT__
    {
        is_receving = mmi_ftp_client_is_receiving();
        result |= is_receving;
    }
    #endif

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_RECEVING_DATA, result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_receiving
 * DESCRIPTION
 *  This function is exported to the app, to indicate whether BT is receving data.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is receiving data
                    FALSE : otherwise
 *****************************************************************************/
void mmi_bt_disable_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_DISABLE_RECEIVING);
    g_recv_disabled = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_receiving
 * DESCRIPTION
 *  This function is exported to the app, 
 *        indicate whether BT is receving data.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is receiving data
                    FALSE : otherwise
 *****************************************************************************/
void mmi_bt_enable_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_ENABLE_RECEIVING);
    g_recv_disabled = MMI_FALSE;
}


MMI_BOOL mmi_bt_receiving_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_RECEIVING_DISABLED, g_recv_disabled);
    
    return g_recv_disabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_receive_init
 * DESCRIPTION
 *  This function is to save user data
 * PARAMETERS
 *  None
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_receive_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path = g_obj_tmp_buff;
    S32 drv_num, i;
    SRV_FMGR_DRVLIST_HANDLE fh;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    drv_num = srv_fmgr_drivelist_count(fh);
    
    for (i = 0; i < drv_num; i++) {
        S32 retval;
        U8 drv;
        drv = srv_fmgr_drivelist_get_drv_letter(fh, i);
        kal_wsprintf(path, "%c:\\%w", drv, BTR_TEMP_FOLDER);

        retval = FS_GetAttributes(path);
        if (retval >= FS_NO_ERROR && (retval & FS_ATTR_HIDDEN))
            FS_XDelete(path,FS_FILE_TYPE, NULL, 0);
    }
    srv_fmgr_drivelist_destroy(fh);
}

/*
	Parameter: 
		notify: callback for async event notification
		obj: receiving object info, could not be NULL
		storage: receiving storage info, NULL will apply default storage.
		option: receiving options, see btrecv_opt_enum
	Return value:
		>= 0: success case, receiving handle is returned.
		< 0 && != PENDING: fail case.
		PENDING: async receiving start case, receiving info will be available when BTRECV_EV_READY received.
		See also btrecv_ret_enum.
	Remark: This API should be called before each receiving activity happens.
*/
S32 mmi_bt_start_receive(
        bt_recv_notify notify,
        const bt_recv_obj_info *obj,
        const bt_recv_storage *storage,
        U8 option)
{
    btr_inst_struct *inst;
    S32 retval = BTRECV_RET_SUCC;
    
    if (!notify || !obj)
        return BTRECV_RET_FAIL;

    inst = btr_new_inst(notify, obj, storage, option);

    if (option & BTRECV_OPT_KEEP_NAME &&
        !valid_path(inst->store.folder, inst->store.name, NULL))
    {
        retval = BTRECV_RET_FAIL;
        goto fail;
    }

    if (inst->store.drive < 0)
    {
        retval = BTRECV_RET_MEMORY_FULL;
        goto fail;
    }

    if (inst->store.drive == 0)
    {
#ifndef __MMI_BT_SLIM__
        retval = btr_select_drive(inst);
        if (retval == BTRECV_RET_PENDING)
            return inst->handle;
        if (retval < 0)
            goto fail;
#else
        goto fail;
#endif
    }
    
    btr_start_post_hdlr(inst);

    return (S32)inst->handle;

fail:
    btr_post_event(inst, BTRECV_EV_START, retval);
    return (S32)inst->handle;
}

/*
	Parameter: 
		hd: receiving handle.
		reason: indicate normal or abnormal stop case.
	Return value:
		None.
	Remark: This API should be called after each receiving finished.
*/
void mmi_bt_stop_receive(S32 hd, S32 retval)
{
    btr_inst_struct *inst = btr_find_inst(hd);

    if (!inst)
        return;

#ifndef __MMI_BT_SLIM__
    if (inst->state == BTR_STATE_PENDING)
        btr_deselect_drive(inst);
#endif

    if (retval == BTRECV_RET_SUCC)
        retval = btr_create_object(inst);
    else
        btr_destroy_storage(inst);

    btr_post_event(inst, BTRECV_EV_DONE, retval);
}

/*
	Parameter: 
		hd: receiving handle.
		info: receiving info corresponding to the specific handle.
	Return value:
		See also btrecv_ret_enum.
	Remark: This API is to retrieve receiving information.
*/
S32 mmi_bt_get_receive_info(S32 hd, void *info, U8 opt)
{
    btr_inst_struct *inst = btr_find_inst(hd);

    if (!inst || !info)
        return BTRECV_RET_FAIL;

    if (inst->state < BTR_STATE_READY)
        return BTRECV_RET_FAIL;

    switch (opt) {
    case BTRECV_INFO_STORAGE:
        compose_path((WCHAR *)info, &inst->store, BTR_COMP_STORAGE);
        break;
    case BTRECV_INFO_OBJ_PATH:
        compose_path((WCHAR *)info, &inst->store, BTR_COMP_OBJ_PATH);
        break;
    case BTRECV_INFO_OBJ_FLDR:
        compose_path((WCHAR *)info, &inst->store, BTR_COMP_OBJ_FLDR);
        break;
    }

    return BTRECV_RET_SUCC;
}


#define BT_RECEIVE_INTERNAL_DEFINITION
static void btr_start_post_hdlr(btr_inst_struct *inst)
{
    WCHAR *path = g_obj_tmp_buff;
    S32 retval = BTRECV_RET_SUCC;
    
    retval = btr_create_storage(inst);
    if (retval < 0)
    {
        btr_post_event(inst, BTRECV_EV_START, retval);
        return;
    }

    kal_wsprintf(path, "%c:\\%w", inst->store.drive, inst->store.folder);
    retval = gen_folder(path, 0);
    if (retval < 0)
    {
        retval = btr_conv_code(retval);
        btr_post_event(inst, BTRECV_EV_START, retval);
        return;
    }

    btr_post_event(inst, BTRECV_EV_START, 0);
}


#ifndef __MMI_BT_SLIM__
static S32 btr_select_drive(btr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    SRV_FMGR_DRVLIST_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);

    count = srv_fmgr_drivelist_count(fh);

    if (count == 0)
    {
        srv_fmgr_drivelist_destroy(fh);
        return BTRECV_RET_FAIL;
    }

    if (count == 1)
    {
        inst->store.drive = srv_fmgr_drivelist_get_drv_letter(fh, 0);
        srv_fmgr_drivelist_destroy(fh);
        return BTRECV_RET_SUCC;
    }

    srv_fmgr_drivelist_destroy(fh);

    inst->scrn.id = get_avail_scrn();
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT, 
        MMI_EVENT_QUERY,
        btr_show_sel_drv,
        (void *)inst);

    return BTRECV_RET_PENDING;
}

static void btr_deselect_drive(btr_inst_struct *inst)
{
    if (inst->scrn.id == 0)
        return;

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DEFAULT,
        btr_show_sel_drv, (void *)inst);

    if (mmi_frm_scrn_is_present(GRP_ID_ROOT, inst->scrn.id, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_ROOT, inst->scrn.id);
    }
}

static MMI_BOOL btr_show_sel_drv(mmi_scenario_id scenario, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btr_inst_struct * inst = (btr_inst_struct *)arg;
    SRV_FMGR_DRVLIST_HANDLE fh;
    S32 count, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);

    count = srv_fmgr_drivelist_count(fh);
    if (count == 0)
    {
        srv_fmgr_drivelist_destroy(fh);
        btr_post_event(inst, BTRECV_EV_START, BTRECV_RET_FAIL);
        return MMI_FALSE;
    }

    if (count == 1)
    {
        inst->store.drive = srv_fmgr_drivelist_get_drv_letter(fh, 0);
        srv_fmgr_drivelist_destroy(fh);

        btr_start_post_hdlr(inst);
        
        return MMI_FALSE;
    }
    for (i = 0; i < count; i++)
    {
        U8 drv;
        MMI_STR_ID str_id;
        drv = srv_fmgr_drivelist_get_drv_letter(fh, i);
        str_id = srv_fmgr_drv_get_string(drv);
        inst->str_list[i] = (U8 *)GetString(str_id);
    }
    inst->drv_count = count;
    inst->drv_list = fh;
    inst->scrn.sel_item = 0;

    mmi_frm_scrn_create(GRP_ID_ROOT, inst->scrn.id, btr_sel_drv_proc, inst);

    return MMI_TRUE;
}

static MMI_RET btr_sel_drv_proc(mmi_event_struct *event)
{
    btr_inst_struct * inst = (btr_inst_struct *)event->user_data;

    switch (event->evt_id) {
    case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *evt = 
                (mmi_frm_scrn_active_evt_struct *)event;
            
            mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            
            ShowCategory36Screen(
                STR_GLOBAL_STORAGE,
                GetRootTitleIcon(MENU_CONN_BT_MAIN),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                inst->drv_count,
                inst->str_list,
                inst->scrn.sel_item,
                evt->gui_buffer);
            //ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        break;

     case EVT_ID_SCRN_INACTIVE:

        mmi_frm_end_scenario(MMI_SCENARIO_ID_DEFAULT);

        break;

    case EVT_ID_WGUI_LSK_CLICK:
    case EVT_ID_WGUI_CSK_CLICK:

        inst->store.drive = srv_fmgr_drivelist_get_drv_letter(
                                inst->drv_list, inst->scrn.sel_item);
        mmi_frm_scrn_close(GRP_ID_ROOT, inst->scrn.id);

        return MMI_RET_KEY_HANDLED;

    case EVT_ID_WGUI_RSK_CLICK:

        mmi_frm_scrn_close(GRP_ID_ROOT, inst->scrn.id);

        return MMI_RET_KEY_HANDLED;

    case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *evt = (cat_evt_struct *)event;

            inst->scrn.sel_item = evt->item_index;
        }
        break;

    case EVT_ID_SCRN_DEINIT:

        srv_fmgr_drivelist_destroy(inst->drv_list);
        if (inst->store.drive)        
            btr_start_post_hdlr(inst);
        else
            btr_post_event(inst, BTRECV_EV_START, BTRECV_RET_FAIL);

        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

static U16 get_avail_scrn(void)
{
    U16 base = SCR_BT_SEL_DRV1;
    U8 mask = 0, i;
    btr_inst_struct *inst = g_btr_inst_list;

    for (; inst; inst = inst->next)
    {
        if (inst->scrn.id)
            mask |= 1<<(inst->scrn.id-base);
    }

    for (i = 0; i < 4; i++)
        if (!(mask & (1 << i)))
            return base+i;

    MMI_ASSERT(0);

    return 0;
}

#endif

static btr_inst_struct *btr_new_inst(
        bt_recv_notify notify,
        const bt_recv_obj_info *obj,
        const bt_recv_storage *storage,
        U32 option)
{
    btr_inst_struct *inst, t_inst;

    memset(&t_inst, 0, sizeof(t_inst));

    /* fix length part */
    t_inst.notify = notify;
    t_inst.option = option;
    t_inst.obj_size = obj->size;

    if (storage && storage->drive)
        t_inst.store.drive = storage->drive;
    else
        t_inst.store.drive = get_avail_drive(obj->size);

    /* variable length part */
    if (storage && storage->folder)
        t_inst.store.folder = storage->folder;
    else
        t_inst.store.folder = default_folder(obj);

    if (obj->name && valid_name(obj->name))
        t_inst.store.name = obj->name;
    else
        t_inst.store.name = default_name(get_extension(obj->name));

    t_inst.store.nm_size = (mmi_wcslen(t_inst.store.name)+1) * 2;
    t_inst.store.fd_size = (mmi_wcslen(t_inst.store.folder)+1) * 2;

    inst = get_ctrl_buffer(sizeof(t_inst));
    *inst = t_inst;

    inst->store.folder = (WCHAR *)get_ctrl_buffer(t_inst.store.fd_size);
    inst->store.name = (WCHAR *)get_ctrl_buffer(t_inst.store.nm_size);

    mmi_wcscpy(inst->store.name, t_inst.store.name);
    mmi_wcscpy(inst->store.folder, t_inst.store.folder);

    inst->handle = btr_handle(inst);
    inst->state = BTR_STATE_PENDING;
    
    add_to_inst_list(&g_btr_inst_list, inst);

    return inst;
}

static void btr_del_inst(btr_inst_struct *inst)
{
    del_from_inst_list(&g_btr_inst_list, inst);
    free_ctrl_buffer(inst->store.folder);
    free_ctrl_buffer(inst->store.name);
    free_ctrl_buffer(inst);
}

static btr_inst_struct *btr_find_inst(S32 hd)
{
    btr_inst_struct *inst = g_btr_inst_list;

    for (; inst; inst = inst->next)
        if (inst->handle == hd)
            return inst;

    return NULL;
}

static void btr_notify(btr_inst_struct *inst, U32 evt, S32 retval)
{
    switch (evt) {
    case BTRECV_EV_START:
        if (retval == BTRECV_RET_SUCC) 
        {
            inst->state = BTR_STATE_READY;
            inst->notify(inst->handle, evt, retval);
        }
        else
        {
            inst->notify(inst->handle, evt, retval);
            btr_del_inst(inst);
        }
        break;

    case BTRECV_EV_DONE:
        inst->notify(inst->handle, evt, retval);
        btr_del_inst(inst);
        break;

    default:
        break;
    }
}

static MMI_RET btr_event_proc(mmi_event_struct *evt)
{
    btr_evt_struct *notify = (btr_evt_struct *)evt;

    if (notify->evt_id == BTR_EVENT_NOTIFY &&
        inst_in_list(g_btr_inst_list, notify->inst)) {
        btr_notify(notify->inst, notify->event, notify->retval);
    }

    return MMI_RET_OK;
}

static void btr_post_event(btr_inst_struct *inst, U32 event, S32 retval)
{
    btr_evt_struct evt;

    if ((event == BTRECV_EV_START && retval != BTRECV_RET_SUCC) ||
        event == BTRECV_EV_DONE)
    {
        if (inst->state == BTR_STATE_DELETE)
            return;

        inst->state = BTR_STATE_DELETE;
    }
    
    MMI_FRM_INIT_EVENT(&evt, BTR_EVENT_NOTIFY);
    evt.inst = inst;
    evt.event = event;
    evt.retval = retval;

    mmi_frm_post_event((mmi_event_struct *)&evt, btr_event_proc, NULL);
}

static S32 btr_create_storage(btr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[BTR_MAX_NAME], *path = g_obj_tmp_buff;
    S32 retval;
    U32 i = 0, magic = inst->handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%c:\\%w", inst->store.drive, BTR_TEMP_FOLDER);

    retval = gen_folder(path, FS_ATTR_DIR|FS_ATTR_HIDDEN);
    if (retval >= 0) {
        do {
            magic = (magic & 0x00ffffff) | ((i << 24) & 0xff000000);
            kal_wsprintf(name, "%08x.%w", magic, BTR_TEMP_EXT);
            update_path(path, 0, name);

            retval = FS_GetAttributes(path);
            if (retval == FS_FILE_NOT_FOUND ||
                retval == FS_PATH_NOT_FOUND) {
                inst->store.magic = magic;
                return BTRECV_RET_SUCC;
            }
            if (retval < 0)
                break;
        } while (i++ < BTR_MAX_DUP);
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_GEN_TEMP_OBJ, retval);
    
    if (retval < 0)
        retval = btr_conv_code(retval);
    else
        retval = BTRECV_RET_FAIL;

    return retval;
}


static S32 btr_destroy_storage(btr_inst_struct *inst)
{
    WCHAR *path = g_obj_tmp_buff;

    compose_path(path, &inst->store, BTR_COMP_STORAGE);

    FS_Delete(path);

    return BTRECV_RET_SUCC;
}

static S32 btr_create_object(btr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *o_path = g_obj_tmp_buff;
    WCHAR s_path[BTR_MAX_STORAGE];
    S32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_path(s_path, &inst->store, BTR_COMP_STORAGE);
    
    compose_path(o_path, &inst->store, BTR_COMP_OBJ_PATH);
    
    retval = gen_folder(o_path, 0);
    if (retval < FS_NO_ERROR)
    {
        FS_Delete(s_path);
        return BTRECV_RET_FAIL;
    }

    if (inst->option & BTRECV_OPT_KEEP_NAME)
        retval = FS_Rename(s_path, o_path); 
    else 
    {
        do {
            retval = FS_Rename(s_path, o_path);
        } while (retval == FS_FILE_EXISTS && btr_dup_name(o_path, &inst->store));
    }
    
    if (retval == FS_FILE_EXISTS)
    {
        FS_Delete(o_path);
        retval = FS_Rename(s_path, o_path);
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_RELEASE_TEMP_OBJ, retval);

    if (retval < FS_NO_ERROR)
    {
        FS_Delete(s_path);
        retval = btr_conv_code(retval);
    }
    else
        retval = BTRECV_RET_SUCC;

    return retval;
}

static S32 btr_conv_code(S32 code)
{
    S32 retval;

    switch (code) {
        case FS_DISK_FULL:
            retval = BTRECV_RET_MEMORY_FULL;
            break;
            
        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_DISCARD_SECTOR_ERROR:
        case FS_MSDC_PRESNET_NOT_READY:
        case FS_MSDC_NOT_PRESENT:
        case FS_MEDIA_CHANGED:
            retval = BTRECV_RET_MSDC_MISSED;
            break;
            
        default:
            retval = BTRECV_RET_FAIL;
            break;
        }

    return retval;
}

static void add_to_inst_list(btr_inst_struct **head, btr_inst_struct *inst)
{
    btr_inst_struct *move;
    
    if (*head == NULL)
    {
        *head = inst;
        return;
    }

    for (move = *head; move->next; move = move->next);
    
    move->next = inst;
}

static void del_from_inst_list(btr_inst_struct **head, btr_inst_struct *inst)
{
    btr_inst_struct *move, *prev;
    
    if (*head == NULL)
        return;
    if (*head == inst) {
        *head = (*head)->next;
        return;            
    }
    
    prev = *head; 
    move = (*head)->next;

    for (; move; move = move->next, prev = prev->next)
        if (move == inst) {
            prev->next = move->next;
            break;
        }
}

static U32 inst_in_list(btr_inst_struct *head, btr_inst_struct *inst)
{
    if (head == NULL)
        return 0;

    for (; head; head = head->next)
    {
        if (inst == head)
            return 1;
    }

    return 0;
}

static void compose_path(WCHAR *path, struct _btr_store *store, U8 opt)
{
    if (opt == BTR_COMP_STORAGE)
    {
        kal_wsprintf(path, "%c:\\%w%08x.%w",
            store->drive,
            BTR_TEMP_FOLDER,
            store->magic,
            BTR_TEMP_EXT);
    }
    if (opt == BTR_COMP_OBJ_PATH)
    {
        truncate_name(store, 0);
            
        kal_wsprintf(path, "%c:\\%w%w",
            store->drive,
            store->folder,
            store->name);
    }
    if (opt == BTR_COMP_OBJ_FLDR)
    {
        kal_wsprintf(path, "%c:\\%w",
            store->drive,
            store->folder);
    }
}

static WCHAR *update_path(WCHAR *path, CHAR drive, WCHAR *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p1 = NULL, *p2 = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path);

    if (drive)
        path[0] = (WCHAR)drive;

    if (file)
    {
        /* find last '\' */
        p2 = path;
        for (p1 = mmi_wcschr(p2, L'\\'); p1; p1 = mmi_wcschr(p2, L'\\'))
            p2 = p1+1;

        mmi_wcscpy(p2, file);
    }

    return path;
}

static S32 get_avail_drive(S32 size)
{
#ifdef _MMI_BT_ULTRA_SLIM_
		 return mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV);
	
#else
#ifndef LGLT

    return mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV);

#else

    S32 count, i;
    S32 avail_drv = -1;
    WCHAR path[4];
    SRV_FMGR_DRVLIST_HANDLE fh;

    fh = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    count = srv_fmgr_drivelist_count(fh);
    for (i = 0; i < count; i++)
    {
        FS_DiskInfo info;
        int retval, space;
        S32 drive;

        drive = srv_fmgr_drivelist_get_drv_letter(fh, i);
        kal_wsprintf(path, "%c:\\", drive);
        
        retval = FS_GetDiskInfo(path, &info, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE);
        if ( retval < FS_NO_ERROR)
            continue;

        space = info.FreeClusters * info.SectorsPerCluster * info.BytesPerSector;
        /* reserve extra space */
        space -= 256;

        if (size < space)
        {
            if (drive == SRV_FMGR_PUBLIC_DRV)
            {
                avail_drv = drive;
                break;
            }
            if (avail_drv < 0)
                avail_drv = drive;
        }
    }
    srv_fmgr_drivelist_destroy(fh);

    return avail_drv;
    
#endif
#endif 
}

static WCHAR *default_folder(const bt_recv_obj_info *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_RECV_FDR_SWITCH__
    applib_mime_type_struct *mime = NULL;
    WCHAR *extension = NULL;
    U8 type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!obj)
        return BTR_DEF_FOLDER;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_GET_RECV_FDR1, obj->type, 0);

#ifdef __MMI_BT_RECV_FDR_SWITCH__
    if (!obj->type || obj->type == MIME_TYPE_UNKNOWN)
    {
        /* we need to search MIME type by mime_string and extension */
        if (obj->name)
            extension = get_extension(obj->name);

        if (extension)
            extension++;
        mime = mime_lookup(obj->mime, extension);
    }

    if (mime)
        type = mime->mime_type;
    else
        type = obj->type;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_GET_RECV_FDR2, type, 0);

    return select_folder(type, 0);
#else
    return BTR_DEF_FOLDER;
#endif
}

#ifdef __MMI_BT_RECV_FDR_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_mime_type_lookup
 * DESCRIPTION
 *  This function is to lookup mimetype by mime_string and file extension
 * PARAMETERS
 *  mime_string [IN]
 *  ext         [IN]
 * RETURNS
 *  applib_mime_type_struct *
 *****************************************************************************/
static applib_mime_type_struct *mime_lookup(CHAR *mime, WCHAR *ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *type = NULL;
    CHAR extension[8];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext)
        mmi_wcs_n_to_asc(extension, ext, (sizeof(extension)-1)*2);
    
    if (ext && mime)
        type = applib_mime_type_look_up(mime, extension, 0, 0);
    
    if (!type && mime)
        type = applib_mime_type_look_up(mime, NULL, 0, 0);
    
    if (!type && ext)
        type = applib_mime_type_look_up(NULL, extension, 0, 0);

    return type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_get_folder
 * DESCRIPTION
 *  This function is to get appropriate folder by mime_type and mime_subtype
 * PARAMETERS
 *  folder          [OUT]
 *  mime_type       [IN]
 *  mime_subtype    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static WCHAR *select_folder(U8 mime_type, U16 mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mime_type) {
    case MIME_TYPE_AUDIO:
        folder = FMGR_DEFAULT_FOLDER_AUDIO;
        break;
    case MIME_TYPE_IMAGE:
        folder = FMGR_DEFAULT_FOLDER_IMAGES;
        break;
    case MIME_TYPE_VIDEO:
        folder = FMGR_DEFAULT_FOLDER_VIDEO;
        break;
    case MIME_TYPE_APPLICATION:
        if (mime_subtype == MIME_SUBTYPE_THEME)
            folder = FMGR_DEFAULT_FOLDER_THEMES;
        else
            folder = FMGR_DEFAULT_FOLDER_RECEIVED;
        break;
    default:
        folder = FMGR_DEFAULT_FOLDER_RECEIVED;
        break;
    }

    if(0)
    {
    }
#ifdef M3D_MMI_SUPPORT
    else if(mime_subtype == MIME_SUBTYPE_M3D)
        folder = FMGR_DEFAULT_FOLDER_IMAGES;
#endif
#ifdef __MMI_EBOOK_READER__
    else if(mime_subtype == MIME_SUBTYPE_PDB ||
        (mime_type == MIME_TYPE_TEXT && mime_subtype == MIME_SUBTYPE_PLAIN))
        folder = FMGR_DEFAULT_FOLDER_EBOOKS;
#endif
#if defined(__MMI_BARCODEREADER__) && !defined(__MMI_OP01_BARCODEREADER__)
    else if(mime_subtype == MIME_SUBTYPE_MBC)
        folder = FMGR_DEFAULT_FOLDER_BARCODE;
#endif
#ifdef LANGLN_DIGIDEA
    else if(mime_subtype == MIME_SUBTYPE_DZD)
        folder = FMGR_DEFAULT_FOLDER_LANGLN;
#endif
#ifdef __MMI_MESSAGES_EMS__
    else if(mime_subtype == MIME_SUBTYPE_EMS)
        folder = FMGR_DEFAULT_FOLDER_IMAGES;
#endif

    return folder;
}

#endif /* __MMI_BT_RECV_FDR_SWITCH__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_gen_folder
 * DESCRIPTION
 *  This function is to generate receive folder
 * PARAMETERS
 * fldr_path   [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 gen_folder(WCHAR *path, U8 Attributes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retval = FS_NO_ERROR;
    U16 *p1 = NULL, *p2 = NULL, t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path);

    for (p1 = mmi_wcschr(path, L'\\'); p1; p1 = mmi_wcschr(p2, L'\\'))
    {
        p2 = p1 + 1;
        t = *p2;
        *p2 = L'\0';
        
        retval = FS_GetAttributes(path);
        if (retval == FS_PATH_NOT_FOUND || retval == FS_FILE_NOT_FOUND)
        {
            retval = FS_CreateDir(path);

            if (retval >= 0 && Attributes)
                FS_SetAttributes(path, Attributes);
        }
        *p2 = t;

        if (retval < FS_NO_ERROR)
            break;
    }

    /* path format error */
    MMI_ASSERT(p2);

    if (retval >= 0 && Attributes)
        FS_SetAttributes(path, Attributes);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_GEN_FOLDER, retval);

    return retval;
}

static MMI_BOOL btr_dup_name(WCHAR *path, struct _btr_store *store)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR prefix[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store->dup_cnt >= BTR_MAX_DUP)
        return MMI_FALSE;

    store->dup_cnt++;
    if (store->dup_cnt == 1)
    {
        /* This is the 1st time add dup prefix, 
            we must consider of truncate case */
        kal_wsprintf(prefix, "Dup(%02d)", store->dup_cnt);
        truncate_name(store, prefix);
    }
    else
    {
        update_prefix(store->name, store->dup_cnt);
    }

    compose_path(path, store, BTR_COMP_OBJ_PATH);

    return MMI_TRUE;
}

static S32 truncate_name(struct _btr_store *store, WCHAR *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *name = store->name, *ext;
    WCHAR *d, *s, *t = NULL;
    S32 i, size, name_len, ext_len = 0, head_len = 0, space;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store->truncate && !head)
        return store->nm_size/2 - 1;
    
    name_len = mmi_wcslen(name);
    if (head)
        head_len = mmi_wcslen(head);

    valid_path(store->folder, store->name, &space);

    if (!head && space >= 0)
        return name_len;

    if (head && space > 0) {
        size = name_len + ((space >= head_len) ? head_len:space);
    }
    else {
        size = name_len + space;
    }
    t = get_ctrl_buffer((size+1)*2);

    ext = get_extension(name);
    if (ext) {
        ext_len = mmi_wcslen(ext);
        if (ext_len >= size - head_len) {
            /* At least reserve header space */
            ext_len = size - head_len - 1;
        }
    }
    name_len = size - head_len - ext_len;

    for (i = 0, d = t, s = head; i < head_len; i++)
        *d++ = *s++;
    for (i = 0, s = name; i < name_len; i++)
        *d++ = *s++;
    for (i = 0, s = ext; i < ext_len; i++)
        *d++ = *s++;
    
    *d = '\0';

    store->truncate = 1;

    free_ctrl_buffer(name);
    store->name = t;
    store->nm_size = (size + 1)*2;
    
    return size;
}

static void update_prefix(WCHAR * name, U8 seq)
{
    WCHAR num[10];
    WCHAR *p = mmi_wcsstr(name, L"Dup(");
    MMI_ASSERT(p);

    p += 4;
    kal_wsprintf(num, "%02d", seq);
    *p++ = num[0];
    *p = num[1];
}

static WCHAR *default_name(WCHAR *ext)
{
    static S32 seq = 0;
    WCHAR *name = g_obj_tmp_buff;

    kal_wsprintf(name, BTR_DEF_NAME, seq++);

    if (ext && valid_name(ext))
        mmi_wcscat(name, ext);

    return name;
}

static WCHAR * get_extension(WCHAR *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR * p;
    U16 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!name) return NULL;
    
    len = mmi_wcslen(name);
    
    for (p = &name[len]; p > name; p--) {
        if (*p == L'.')
            return p;
        
        if (*p == L'\\' || *p == L'/')
            return NULL;
    }

    return NULL;
}

static MMI_BOOL valid_path(WCHAR *folder, WCHAR *name, S32 *over_len)
{
    S32 len = 3; // "X:\"

    len += mmi_wcslen(folder);
    len += mmi_wcslen(name);

    if (over_len)
        *over_len = BTR_MAX_PATH - 1 - len;

    if (len <= BTR_MAX_PATH - 1)
        return MMI_TRUE;

    return MMI_FALSE;
}


static MMI_BOOL valid_name(WCHAR *name)
{
    WCHAR *p;
    static const char lfn[] = ".+,;=[]";
    static const char sfn[] = " $%'-_@~`!(){}^#&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    for (p = name; *p != '\0'; p++)
    {
        if (*p == 0xFFFF) /* UCS2 convert failure mark */
            return MMI_FALSE;

        if (*p < 0x80 && !strchr(lfn, (char)*p) && !strchr(sfn, (char)*p))
            return MMI_FALSE;
    }

    p--;
    if (*p == 0x2E)
        return MMI_FALSE;
    
    return MMI_TRUE;
}


#endif /* __MMI_BT_SUPPORT__ */
