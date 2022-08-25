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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  BTMMISetting.c
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 01 07 2013 bhupender.tabiyad
 * removed!
 * .
 *
 * 12 21 2012 bhupender.tabiyad
 * removed!
 * .
 *
 * 12 14 2012 bhupender.tabiyad
 * removed!
 * .
 *
 * 05 10 2012 zhanying.liu
 * removed!
 * .
 *
 * 09 25 2011 zhanying.liu
 * removed!
 * .feature set reduction code check in
 *
 * 09 20 2011 zhanying.liu
 * removed!
 * .remove S8 type
 *
 * 06 15 2011 zhanying.liu
 * removed!
 * .replace gpio header file and api with service header file and api
 *
 * 06 07 2011 zhanying.liu
 * removed!
 * .update
 *
 * 06 01 2011 zhanying.liu
 * removed!
 * .modify group create and enter & default rsk handler
 *
 * 05 29 2011 zhanying.liu
 * removed!
 * . change some bt string as global string ID
 *
 * 01 19 2011 zhanying.liu
 * removed!
 * .[BT] SLIM Support
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 11 27 2010 zhanying.liu
 * removed!
 * . add srv_ftps_set_permission() in FTP service
 *
 * 08 11 2010 zhanying.liu
 * removed!
 * .add MMI_FRM_FG_ONLY_SCRN in function mmi_frm_scrn_enter()
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
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__ 
#include "BTMMIObexGprots.h"
//#include "BtcmSrvGprot.h"
//#include "ConnectivityResDef.h"
//#include "CommonScreens.h"      /* mmi_display_popup */
//#include "ProfileGprots.h"    /* for playRequestedTone */
//#include "ProfilesSrvGprot.h"
#include "BTMMIOppGprots.h"
#include "BTMMIBipGprot.h"
#include "BTMMIFtpGprots.h"
//#include "GpioSrvGprot.h" /* for turn on/off backlight */
//#include "FileMgrGProt.h"
#include "FtpSrvGprots.h"
// RHR: add
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "fs_errcode.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
// RHR: add

typedef struct 
{
    U8 recv_drv; 
    U8 always_ask;
#ifdef __MMI_FTS_SUPPORT__
    U8 access_right;
#endif
#ifdef __MMI_BIP_SUPPORT__
    U16 bip_fldr_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 bip_fldr_name[SRV_FMGR_PATH_MAX_LEN + 1];
#endif
    U32 reserved;
} bt_setting_struct;

#ifdef _MMI_BT_ULTRA_SLIM_
static bt_setting_struct g_mmi_bt_setting_cntx;
#else
typedef struct 
{
    bt_setting_struct settings;
    U8 recv_drv; 
    U8 always_ask;
    U32 reserved;
} mmi_bt_setting_cntx_struct;

static mmi_bt_setting_cntx_struct g_mmi_bt_setting_cntx;

//#ifdef __MMI_BT_PROF_SETTING__
static void mmi_bt_save_setting(U32 setting_item);
//#endif

static MMI_BOOL mmi_btcomn_drive_valid(U8 drive, U8 always_ask);

#endif
//#ifdef __MMI_BT_PROF_SETTING__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_setting_int
 * DESCRIPTION
 *  Retrieve int type setting item value
 * PARAMETERS
 *  item [IN] bt_ff_item_enum
 * RETURNS
 *   >= 0: success
 *   < 0: fail
 *****************************************************************************/
S32 mmi_bt_get_setting_int(U32 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef _MMI_BT_ULTRA_SLIM_
	 bt_setting_struct* set = &g_mmi_bt_setting_cntx;
	 return set->recv_drv;

#else 
    bt_setting_struct* set = &g_mmi_bt_setting_cntx.settings;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
        case BTFF_ITEM_RECV_DRV:
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_GET_RECV_DRV, set->recv_drv);
#ifndef __MMI_BT_SLIM__
            if (set->always_ask)
                return 0;
#endif  // SLIM:memory reduction
            return set->recv_drv;

#ifdef __MMI_FTS_SUPPORT__
        case BTFF_ITEM_FTP_ACCESS:
            return set->access_right;
#endif
#if defined __BIP_PULL_SUPPORT__
        case BTFF_ITEM_BIP_FLDR_PATH:
            return (S32)set->bip_fldr_path;

        case BTFF_ITEM_BIP_FLDR_NAME:
            return (S32)set->bip_fldr_name;
#endif
        default:
            return -1;
    }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_setting_int
 * DESCRIPTION
 *  Save int type setting item value
 * PARAMETERS
 *  item [IN] bt_ff_item_enum
 *  value[IN] item value
 * RETURNS
 *   >= 0: success
 *   < 0: fail
 *****************************************************************************/
S32 mmi_bt_set_setting_int(U32 item, void* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef _MMI_BT_ULTRA_SLIM_
	{	 bt_setting_struct* set = &g_mmi_bt_setting_cntx;
		 set->recv_drv = *((U8 *)value);
	}

#else
	bt_setting_struct* set = &g_mmi_bt_setting_cntx.settings;
    switch (item)
    {
        case BTFF_ITEM_RECV_DRV:
        {
            U8 drv, ask;
            drv = *((U8 *)value);
            if (drv == 0)
                ask = 1;
            else
                ask = 0;
            if (!mmi_btcomn_drive_valid(drv, ask) ||
                (drv == set->recv_drv && ask == set->always_ask))
                return -1;
            set->recv_drv = drv;
            set->always_ask = ask;
            break;
        } 

#ifdef __MMI_FTS_SUPPORT__
        case BTFF_ITEM_FTP_ACCESS:
            set->access_right = (U8)(*((S32*)value));
            break;
#endif
        default:
            return -1;
    }
    
    mmi_bt_save_setting(item);

  
#endif
 return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_setting_string
 * DESCRIPTION
 *  Retrieve string type setting item value
 * PARAMETERS
 *  item [IN]   bt_ff_item_enum
 *  buff [OUT]  result buffer
 *  size[IN]    buffer size in bytes
 * RETURNS
 *   >= 0: success
 *   < 0: fail
 * REMARK
 *  1. string is UCS2 encoding
 *  2. if buff==NULL or size == 0, 
 *      return value represent the buffer size needed(including NULL terminator) 
 *****************************************************************************/
#ifndef _MMI_BT_ULTRA_SLIM_  /* discard everything from here to slim */
S32 mmi_bt_get_setting_string(U32 item, U16* buff, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined __BIP_PULL_SUPPORT__
    bt_setting_struct* set = &g_mmi_bt_setting_cntx.settings;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
#if defined __BIP_PULL_SUPPORT__
        case BTFF_ITEM_BIP_FLDR_PATH:
            if (buff && size)
                mmi_wcsncpy(buff, set->bip_fldr_path, (size-2)/2);
            return (mmi_wcslen(set->bip_fldr_path)+1)*2;
        case BTFF_ITEM_BIP_FLDR_NAME:
            if (buff && size)
                mmi_wcsncpy(buff, set->bip_fldr_name, (size-2)/2);
            return (mmi_wcslen(set->bip_fldr_name)+1)*2;
#endif
        default:
            return -1;
}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_setting_string
 * DESCRIPTION
 *  Save string type setting item value
 * PARAMETERS
 *  item [IN] bt_ff_item_enum
 *  data [IN] item value
 *  length[IN]: data length
 * RETURNS
 *   >= 0: success
 *   < 0: fail
 *****************************************************************************/
S32 mmi_bt_set_setting_string(U32 item, const U16* data, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined __BIP_PULL_SUPPORT__
    bt_setting_struct* set = &g_mmi_bt_setting_cntx.settings;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
#if defined __BIP_PULL_SUPPORT__
        case BTFF_ITEM_BIP_FLDR_PATH:
            if (!data || !length || (((U32)data) & 0x01))
                return -1;

            mmi_wcsncpy(set->bip_fldr_path, data, (sizeof(set->bip_fldr_path)-2)/2);
			mmi_bt_save_setting(item);
            break;
        case BTFF_ITEM_BIP_FLDR_NAME:
            if (!data || !length || (((U32)data) & 0x01))
                return -1;
        
            mmi_wcsncpy(set->bip_fldr_name, data, (sizeof(set->bip_fldr_name)-2)/2);
			mmi_bt_save_setting(item);
            break;
#endif
        default:
            return -1;
    }
    
    
#if defined __BIP_PULL_SUPPORT__
    return 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_nvram_read
 * DESCRIPTION
 *  This function is to retrieve drive info from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        U8 drv, ask;
        S16 err1 = 0;
        
        ReadValue(NVRAM_BT_RECEIVE_DRIVE, &drv, DS_BYTE, &err);
        ReadValue(NVRAM_BT_RECEIVE_DRIVE_ASK, &ask, DS_BYTE, &err1);
        if (err != NVRAM_READ_SUCCESS ||
            err1 != NVRAM_READ_SUCCESS ||
            !mmi_btcomn_drive_valid(drv, ask))
        {
            drv = SRV_FMGR_PUBLIC_DRV;
        }
        else if (ask)
        {
#ifndef __MMI_BT_SLIM__
            drv = 0;
#else
            drv = SRV_FMGR_PUBLIC_DRV;
#endif  // SLIM:memory reduction
        }

        mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &drv);
    }

#ifdef __MMI_FTS_SUPPORT__
    {
        U8 access;
        ReadValue(NVRAM_FTP_ACCESS_RIGHT, &access, DS_BYTE, &err);
        if (err != NVRAM_READ_SUCCESS || access >= FTP_PERMISSION_COUNT)
        {
            access = FTP_PERMISSION_READ_ONLY;
        }            
        mmi_bt_set_setting_int(BTFF_ITEM_FTP_ACCESS, &access);
    }
#endif
#if defined __BIP_PULL_SUPPORT__
    {
        U16* path;
        path = OslMalloc(sizeof(g_mmi_bt_setting_cntx.settings.bip_fldr_path));
        ReadRecord(
            NVRAM_EF_BT_BIP_SETTING_LID,
            NVRAM_EF_BT_BIP_SETTING_TOTAL,
            path,
            NVRAM_EF_BT_BIP_SETTING_SIZE,
            &err);
        if (err != NVRAM_READ_SUCCESS || mmi_wcslen(path) == 0)
        {
            kal_wsprintf(path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_IMAGES);
        }

        mmi_bt_set_setting_string(BTFF_ITEM_BIP_FLDR_PATH, path, (mmi_wcslen(path) + 1) * 2);
        ReadRecord(
            NVRAM_EF_BT_BIP_SET_FOLDER_LID,
            NVRAM_EF_BT_BIP_SETTING_TOTAL,
            path,
            NVRAM_EF_BT_BIP_SETTING_SIZE,
            &err);
        if (err != NVRAM_READ_SUCCESS || mmi_wcslen(path) == 0)
        {
            kal_wsprintf(path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_IMAGES);
        }

        mmi_bt_set_setting_string(BTFF_ITEM_BIP_FLDR_NAME, path, (mmi_wcslen(path)+1)*2);
        OslMfree(path);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_nvram_write
 * DESCRIPTION
 *  This function is to update drive info to NVRAM
 * PARAMETERS
 *  drive
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_save_setting(U32 setting_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_setting_struct* set = &g_mmi_bt_setting_cntx.settings;
    S16 err1 = NVRAM_WRITE_SUCCESS;
    S16 err2 = NVRAM_WRITE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (setting_item)
    {
        case BTFF_ITEM_RECV_DRV:
            WriteValue(NVRAM_BT_RECEIVE_DRIVE, &set->recv_drv, DS_BYTE, &err1);
            WriteValue(NVRAM_BT_RECEIVE_DRIVE_ASK, &set->always_ask, DS_BYTE, &err2);
            break;

#ifdef __MMI_FTS_SUPPORT__
        case BTFF_ITEM_FTP_ACCESS:
            WriteValue(NVRAM_FTP_ACCESS_RIGHT, &set->access_right, DS_BYTE, &err1);
            break;
#endif

#if defined __BIP_PULL_SUPPORT__
        case BTFF_ITEM_BIP_FLDR_PATH:
            WriteRecord(
                NVRAM_EF_BT_BIP_SETTING_LID,
                NVRAM_EF_BT_BIP_SETTING_TOTAL, 
                set->bip_fldr_path, 
                NVRAM_EF_BT_BIP_SETTING_SIZE,
                &err1);
            break;

        case BTFF_ITEM_BIP_FLDR_NAME:
            WriteRecord(
                NVRAM_EF_BT_BIP_SET_FOLDER_LID,
                NVRAM_EF_BT_BIP_SETTING_TOTAL, 
                set->bip_fldr_name, 
                NVRAM_EF_BT_BIP_SETTING_SIZE,
                &err1);
            break;
#endif

        default:
            return;
    }

    MMI_ASSERT(err1 == NVRAM_WRITE_SUCCESS && err2 == NVRAM_WRITE_SUCCESS);
}
//#endif /* __MMI_BT_PROF_SETTING__ */


MMI_BOOL mmi_bt_storage_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        SRV_FMGR_DRVLIST_HANDLE drvlist;
        S32 count;

        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
        count = srv_fmgr_drivelist_count(drvlist);
        srv_fmgr_drivelist_destroy(drvlist);

        return (count > 1) ? MMI_TRUE : MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_drive_available
 * DESCRIPTION
 *  This function is to judge whether receive drive is available now
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
MMI_BOOL mmi_bth_drive_available(U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drive == 0)
    {
        return MMI_TRUE;
    }
    
    if (FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_drive_valid
 * DESCRIPTION
 *  This function is to judge whether the drive letter is valid
 * PARAMETERS
 *  drive
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_btcomn_drive_valid(U8 drive, U8 always_ask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (always_ask == 1)
    {
        return MMI_TRUE;
    }
    else if (always_ask == 0)
    {
        return srv_fmgr_drv_is_valid((U8)drive);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*******************************************************************************
 *                            Screen  part
 *******************************************************************************/

typedef struct 
{
    U8* storage_list[SRV_FMGR_DRV_TOTAL + 1];
    S32 highlight_index;      /* highlight drive index should change if OTG remove */
    U8  highlight_drive;        /* highlight drive should change if OTG remove */
    U8  count_storage;          /*count of dirve including "Always ask"*/
    U8  sel_drive;

#ifdef __MMI_FTS_SUPPORT__
    S32 sel_access;
    U8* access_list[2];
#endif
#ifdef __MMI_BIP_SUPPORT__
    U16 bip_fldr_name[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 bip_fldr_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 base_scrn;
#endif
    U16 storage_set_gid;
    U16 share_set_gid;
    U16 permission_set_gid;
    //U32 reserved;
} mmi_bt_setting_scr_cntx_struct;

static mmi_bt_setting_scr_cntx_struct g_mmi_bt_setting_scr_cntx;

static MMI_BOOL mmi_btcomn_is_receiving(void);

//#ifdef __MMI_BT_PROF_SETTING__
//static void pre_entry_storage_setting(void);
static void entry_storage_setting(void);
static void storage_setting_hilite_hdlr(S32 index);
static MMI_BOOL storage_setting_validate(void);
static void storage_setting_save(void);
static void storage_setting_done(void);
static void storage_setting_quit(void);

// void mmi_bt_storage_setting_hilight_hdlr(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/

//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
//     ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

//     SetLeftSoftkeyFunction(mmi_bt_entry_storage_setting, KEY_EVENT_UP);
//     //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);

//     ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
//     SetCenterSoftkeyFunction(mmi_bt_entry_storage_setting, KEY_EVENT_UP);
// }


void mmi_bt_storage_setting_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive;
    U16 strID;
    CHAR* hintStr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = (CHAR)mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV);
    if (drive)
    {
        strID = srv_fmgr_drv_get_string((U8)drive);
    }
    else
    {
        strID = STR_GLOBAL_ALWAYS_ASK;
    }

    hintStr = (CHAR*)GetString(strID);
    mmi_ucs2cpy((CHAR*)hintData[index], hintStr);
}

static mmi_ret mmi_bt_storage_set_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_setting_scr_cntx.storage_set_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_mmi_bt_setting_scr_cntx.storage_set_gid) == 0)
            {
                mmi_frm_group_close(g_mmi_bt_setting_scr_cntx.storage_set_gid);
            }
            break;
    }

    return MMI_RET_OK;
}


/* static MMI_BOOL storage_check_set_otg2phone(void) */
/* { */
/*     mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx; */
/*     SRV_FMGR_DRVLIST_HANDLE drvlist; */
/*     U8 drive; */
/*     S32 storage_count, i; */
/*     MMI_BOOL res = MMI_FALSE; */

/*     drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE); */
/*     storage_count = srv_fmgr_drivelist_count(drvlist); */

/*     drive = (U8)mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV); */
/*     cntx->sel_storage = (drive == 0) ? */
/*         storage_count: /\* Always ask case *\/ */
/*         srv_fmgr_drivelist_get_index_by_drv_letter(drvlist, drive); */

/*     if (cntx->sel_storage < 0) */
/*     { */
/*         for (i = 0; i < storage_count; ++i) */
/*         { */
/*             drive = srv_fmgr_drivelist_get_drv_letter(drvlist, i); */
/*             if (srv_fmgr_drv_get_type(drive) == SRV_FMGR_DRV_PHONE_TYPE) */
/*             { */
/*                 g_mmi_bt_setting_cntx.settings.recv_drv = drive; */
/*                 cntx->sel_storage = i; */
/*                 break; */
/*             } */
/*         } */

/*         if (g_mmi_bt_setting_cntx.settings.recv_drv < 0) /\* no phone case, set as always ask *\/ */
/*         { */
/*             g_mmi_bt_setting_cntx.settings.recv_drv = 0; */
/*         } */

/*         mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &g_mmi_bt_setting_cntx.settings.recv_drv); */
/*         res = MMI_TRUE; */
/*     } */

/*     srv_fmgr_drivelist_destroy(drvlist); */
/*     return res; */
/* } */


WCHAR* mmi_bt_get_storage_setting_string(void)
{
    S32 drive;
    U16 strID;

    drive = mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV);
    strID = (drive == 0) ?
        STR_GLOBAL_ALWAYS_ASK :
        (U16)srv_fmgr_drv_get_string((U8)drive);
        
    return (WCHAR*)GetString(strID);
}


//static void pre_entry_storage_setting(void)
void mmi_bt_entry_storage_setting(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id == GRP_ID_INVALID)
    {
        group_id = GRP_ID_ROOT;
    }
    
    g_mmi_bt_setting_scr_cntx.storage_set_gid = mmi_frm_group_create_ex(
        group_id,
        GRP_ID_AUTO_GEN,
        mmi_bt_storage_set_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (mmi_btcomn_is_receiving())
    {
        /* We don't allow to change receive drive during receiving periods */
        //mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            g_mmi_bt_setting_scr_cntx.storage_set_gid,
            NULL);

        //mmi_frm_group_close(g_mmi_bt_setting_scr_cntx.storage_set_gid);
        return;
    }

    entry_storage_setting();
}


static void entry_storage_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drive;
    U8* guiBuff = NULL;
    U32 i;
    MMI_BOOL otg2phone = MMI_FALSE;
    MMI_BOOL highlight_flag;
    S32 drive_type;
    S32 tmp_highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_BT_SET_STORAGE, NULL, entry_storage_setting, NULL);
    if (mmi_frm_scrn_enter(
            g_mmi_bt_setting_scr_cntx.storage_set_gid,
            SCR_BT_SET_STORAGE,
            NULL,
            entry_storage_setting,
            MMI_FRM_FULL_SCRN))
    {
        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
        cntx->count_storage = (U8)srv_fmgr_drivelist_count(drvlist);

        for (i = 0; i < cntx->count_storage; ++i)
        {
            drive = srv_fmgr_drivelist_get_drv_letter(drvlist, i);
            cntx->storage_list[i] = (U8*)GetString(srv_fmgr_drv_get_string(drive));

        }
#ifndef __MMI_BT_SLIM__
        ++(cntx->count_storage);
        cntx->storage_list[cntx->count_storage - 1] = (U8*)GetString(STR_GLOBAL_ALWAYS_ASK);
#endif  // SLIM:memory reduction

        drive = (U8)mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV);
        tmp_highlight_index = (drive == 0) ?
            (cntx->count_storage - 1): /* Always ask case */
            srv_fmgr_drivelist_get_index_by_drv_letter(drvlist, drive);

        /* if appear from history, and setting is not OTG, find appropriate highlight index */
        guiBuff = mmi_frm_scrn_get_active_gui_buf();
        if (guiBuff && (tmp_highlight_index >= 0))
        {
            highlight_flag = MMI_FALSE;
            if (cntx->highlight_drive == 0)
            {
                cntx->highlight_index = cntx->count_storage - 1;
                highlight_flag = MMI_TRUE;
            }
            else
            {
                for (i = 0; i < (cntx->count_storage - 1); ++i)
                {
                    drive = srv_fmgr_drivelist_get_drv_letter(drvlist, i);
                    if (drive == cntx->highlight_drive) /* highlight the same device, even if the OTG removed */
                    {
                        cntx->highlight_index = i;
                        highlight_flag = MMI_TRUE;
                        break;
                    }
                }
            }

            if (!highlight_flag) /* can't find the device due to the OTG device removed */
            {
                drive_type = srv_fmgr_drv_get_type(cntx->highlight_drive);
                for (i = 0; i < (cntx->count_storage - 1); ++i) /* try to find the next one */
                {
                    drive = srv_fmgr_drivelist_get_drv_letter(drvlist, i);
                    if (srv_fmgr_drv_get_type(drive) >= drive_type)
                    {
                        cntx->highlight_index = i;
                        cntx->highlight_drive = drive;
                        break;
                    }
                }

                cntx->highlight_index = cntx->highlight_index < cntx->count_storage ?
                    cntx->highlight_index :
                    (cntx->count_storage - 1);
            }
        }
        else
        {
            cntx->highlight_index = tmp_highlight_index;
        }
        
        
        if (cntx->highlight_index < 0) /* setting is OTG, no matter first entry or appear from history */
        {
            for (i = 0; i < cntx->count_storage; ++i)
            {
                drive = srv_fmgr_drivelist_get_drv_letter(drvlist, i);
                if (srv_fmgr_drv_get_type(drive) == SRV_FMGR_DRV_PHONE_TYPE)
                {
                    cntx->sel_drive = cntx->highlight_drive;
                    mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &drive);
                    cntx->highlight_index = i;
                    cntx->highlight_drive = drive;
                    otg2phone = MMI_TRUE;
                }
            }
        }
        
        srv_fmgr_drivelist_destroy(drvlist);

        RegisterHighlightHandler(storage_setting_hilite_hdlr);

        ShowCategory36Screen(
            STR_GLOBAL_STORAGE,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (S32)cntx->count_storage,
            cntx->storage_list,
            (U16)cntx->highlight_index,
            NULL);

        SetLeftSoftkeyFunction(storage_setting_save, KEY_EVENT_UP);
        SetRightSoftkeyFunction(storage_setting_quit, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
        SetCenterSoftkeyFunction(storage_setting_save, KEY_EVENT_UP);
    }

    if (otg2phone)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_OTG_REMOVED_USE_PHONE),
            MMI_EVENT_FAILURE,
            g_mmi_bt_setting_scr_cntx.storage_set_gid,
            NULL);
    }
}


static void storage_setting_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_setting_scr_cntx.highlight_index = index;

    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
#ifndef __MMI_BT_SLIM__
    if (index == (cntx->count_storage - 1))
    {
        cntx->highlight_drive = 0;
    }
    else
#endif  // SLIM:memory reduction
    {
        cntx->highlight_drive = srv_fmgr_drivelist_get_drv_letter(drvlist, index);
    }
    
    srv_fmgr_drivelist_destroy(drvlist);
}


static MMI_BOOL storage_setting_validate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    SRV_FMGR_DRVLIST_HANDLE drvlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BT_SLIM__
    if (cntx->highlight_index == cntx->count_storage - 1)
    {
        cntx->sel_drive = 0;
    }
    else
#endif  // SLIM:memory reduction
    {
        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
        cntx->sel_drive = srv_fmgr_drivelist_get_drv_letter(drvlist, (S32)cntx->highlight_index);
        srv_fmgr_drivelist_destroy(drvlist);
    }
    
    if (mmi_btcomn_is_receiving())
    {
        /* We don't allow to change receive drive during receiving periods */
        //mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            g_mmi_bt_setting_scr_cntx.storage_set_gid,
            NULL);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


static void storage_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    U16 string_id = 0;
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage_setting_validate())
    {
        if ((mmi_bth_drive_available(cntx->sel_drive)) ||
            ((U8)mmi_bt_get_setting_int(BTFF_ITEM_RECV_DRV) == cntx->sel_drive))
        {
            storage_setting_done();
        }
        else
        {
            drv_type = srv_fmgr_drv_get_type(cntx->sel_drive);
            if (drv_type >= SRV_FMGR_DRV_CARD_TYPE && drv_type <= SRV_FMGR_DRV_CARD_2_TYPE)
            {
                string_id = STR_GLOBAL_MC_REMOVED;
            }
            else if (drv_type >= SRV_FMGR_DRV_OTG_TYPE && drv_type <= SRV_FMGR_DRV_OTG_8_TYPE)
            {
                string_id = STR_GLOBAL_OTG_REMOVED;
            }
            
            mmi_popup_display_simple(
                (WCHAR*)GetString(string_id), /* use string_id */
                MMI_EVENT_FAILURE,
                g_mmi_bt_setting_scr_cntx.storage_set_gid,    
                NULL);
        }
    }
    else
    {
        storage_setting_quit();
    }
}

static void storage_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &cntx->sel_drive);
    //mmi_popup_display_simple(
    //    (WCHAR*)GetString(STR_GLOBAL_DONE),
    //    MMI_EVENT_SUCCESS,
    //    g_mmi_bt_setting_scr_cntx.storage_set_gid,
    //    NULL);

    mmi_frm_scrn_close(g_mmi_bt_setting_scr_cntx.storage_set_gid, SCR_BT_SET_STORAGE);
}


static void storage_setting_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_group_close(g_mmi_bt_setting_scr_cntx.storage_set_gid);
    mmi_frm_scrn_close(g_mmi_bt_setting_scr_cntx.storage_set_gid, SCR_BT_SET_STORAGE);
}


#ifdef __MMI_FTS_SUPPORT__
//static void pre_entry_permission_setting(void);
static void entry_permission_setting(void);
static void permission_setting_hilite_hdlr(S32 index);
static void permission_setting_done(void);
static void permission_setting_quit(void);

// void mmi_bt_permission_setting_hilight_hdlr(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
    
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
//     ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

//     SetLeftSoftkeyFunction(mmi_bt_entry_permission_setting, KEY_EVENT_UP);
//     //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

//     ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
//     SetCenterSoftkeyFunction(mmi_bt_entry_permission_setting, KEY_EVENT_UP);
// }


void mmi_bt_permission_setting_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 perm = (U8)mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);
    CHAR* hintStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (perm == FTP_PERMISSION_FULL_CONTROL)
    {
        hintStr = (CHAR*)GetString(STR_FTP_OPTION_FULLY_CONTROL);
    }
    else
    {
        hintStr = (CHAR*)GetString(STR_FTP_OPTION_READ_ONLY);
    }

    mmi_ucs2cpy((CHAR*)hintData[index], hintStr);
}


static mmi_ret mmi_bt_permission_set_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_setting_scr_cntx.permission_set_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_mmi_bt_setting_scr_cntx.permission_set_gid) == 0)
            {
                mmi_frm_group_close(g_mmi_bt_setting_scr_cntx.permission_set_gid);
            }
            break;
    }

    return MMI_RET_OK;
}


WCHAR* mmi_bt_get_permission_setting_string(void)
{
    U8 perm = (U8)mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);

    if (perm == FTP_PERMISSION_FULL_CONTROL)
    {
        return (WCHAR*)GetString(STR_FTP_OPTION_FULLY_CONTROL);
    }
    else
    {
        return (WCHAR*)GetString(STR_FTP_OPTION_READ_ONLY);
    }
}


void mmi_bt_entry_permission_setting(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->sel_access = mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);
    cntx->access_list[0] = (U8*)GetString(STR_FTP_OPTION_FULLY_CONTROL);
    cntx->access_list[1] = (U8*)GetString(STR_FTP_OPTION_READ_ONLY);
    if (group_id == GRP_ID_INVALID)
    {
        group_id = GRP_ID_ROOT;
    }
    
    g_mmi_bt_setting_scr_cntx.permission_set_gid = mmi_frm_group_create_ex(
        group_id,
        GRP_ID_AUTO_GEN,
        mmi_bt_permission_set_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_permission_setting();
}


static void entry_permission_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    U8* guiBuff;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_BT_SET_PERMISSION, NULL, entry_permission_setting, NULL);
    if (mmi_frm_scrn_enter(
            g_mmi_bt_setting_scr_cntx.permission_set_gid,
            SCR_BT_SET_PERMISSION,
            NULL,
            entry_permission_setting,
            MMI_FRM_FULL_SCRN))
    {
        guiBuff = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(permission_setting_hilite_hdlr);
        
        ShowCategory36Screen(
            STR_BT_SET_SHARE_PERMISSION,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            2,
            cntx->access_list,
            (U16)cntx->sel_access,
            guiBuff);

        SetLeftSoftkeyFunction(permission_setting_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(permission_setting_quit, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(permission_setting_done, KEY_EVENT_UP);
    }
}


static void permission_setting_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_setting_scr_cntx.sel_access = index;
}
       

static void permission_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_set_setting_int(BTFF_ITEM_FTP_ACCESS, &cntx->sel_access);
    srv_ftps_set_permission(cntx->sel_access);

    //mmi_popup_display_simple(
    //    (WCHAR*)GetString(STR_GLOBAL_DONE),
    //    MMI_EVENT_SUCCESS,
    //    g_mmi_bt_setting_scr_cntx.permission_set_gid,
    //    NULL);

    mmi_frm_scrn_close(g_mmi_bt_setting_scr_cntx.permission_set_gid, SCR_BT_SET_PERMISSION);
}
        

static void permission_setting_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


#elif defined __MMI_BIP_SUPPORT__ 


static void pre_select_image_folder(void);
static void img_fldr_setting_done(U16* path, int is_short);

void mmi_bt_img_fldr_setting_hilight_hdlr(void)
{
#ifdef __BIP_PULL_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->base_scrn = mmi_frm_scrn_get_active_id();

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(pre_select_image_folder, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
#endif
}


void mmi_bt_img_fldr_setting_hint_hdlr(U16 index)
{
#ifdef __BIP_PULL_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* fldrName = (CHAR*)mmi_bt_get_setting_int(BTFF_ITEM_BIP_FLDR_NAME);
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)hintData[index], fldrName);
#endif
}


static void img_fldr_setting_done(U16* path, int is_short)
{
#ifdef __BIP_PULL_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_setting_scr_cntx_struct* cntx = &g_mmi_bt_setting_scr_cntx;
    U16* name = NULL;
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!path)
    {
        GoBackToHistory(cntx->base_scrn);
        return;
    }

    if (mmi_bt_bip_server_is_working())
    {
        mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                          MMI_EVENT_FAILURE);
        DeleteUptoScrID(cntx->base_scrn);
        return;
    }

    mmi_bt_set_setting_string(BTFF_ITEM_BIP_FLDR_PATH, (U16*)path, mmi_wcslen((U16*)path) * 2 + 2);
        
    length = sizeof(cntx->bip_fldr_name);
    if (is_short)
    {
        name = OslMalloc(length);
        srv_fmgr_fs_path_get_display_name((WCHAR*)path, (WCHAR*)name, (length + 1) * 2);
        mmi_bt_set_setting_string(BTFF_ITEM_BIP_FLDR_NAME, name, length);
        OslMfree(name);
    }
    else
    {
        mmi_bt_set_setting_string(BTFF_ITEM_BIP_FLDR_NAME, (U16*)path, length);
    }

    //mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteUptoScrID(cntx->base_scrn);
#endif
}
#endif /* __MMI_FTS_SUPPORT__ */


#if defined __BIP_PULL_SUPPORT__
static void select_image_folder_done(void* path, int is_short);

static void select_image_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    mmi_fmgr_select_path_and_enter(APP_BIP,
                                   FMGR_SELECT_FOLDER,
                                   filter,
                                   (CHAR*)L"root",
                                   select_image_folder_done);
}


static void pre_select_image_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_bip_server_is_working())
    {
        mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                          MMI_EVENT_FAILURE);
    }
    else
    {
        select_image_folder();
    }
}


static void select_image_folder_done(void* path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //img_fldr_setting_done((U16*)path, is_short);
}
#endif /* __MMI_BIP_SUPPORT__ */

//#endif /* __MMI_BT_PROF_SETTING__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_btcomn_is_receving
 * DESCRIPTION
 *  This function is exported to the app, to indicate whether BT is receving data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_btcomn_is_receiving(void)
{
    MMI_BOOL result = MMI_FALSE;

#if defined(__MMI_OPP_SUPPORT__)
    {
        result |= mmi_opp_accepted_file();
    }
#endif

#if defined(__MMI_BIP_SUPPORT__)
    {
        result |= mmi_bt_bip_is_receiving();
    }
#endif

#if defined(__MMI_FTC_SUPPORT__)
    {
        result |= mmi_ftp_client_is_receiving();
    }
#endif

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_RECEVING_DATA, result);

    return result;
}

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_fmrdo_notify_hdlr
 * DESCRIPTION
 *  notify hdlr of storage change.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* extern BOOL mmi_bt_storage2card_hdlr(U32 notify_flag, void* para) */
/* { */
/*     U8 drv; */

/*     switch(notify_flag) */
/*     { */
/*         case MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK: */
/*             if (mmi_btcomn_is_receiving()) */
/*             { */
/*                 MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_STORAGE2CARD_DISALLOWED); */
/*                 return MMI_FALSE; */
/*             } */
/*             else */
/*             { */
/*                 MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_STORAGE2CARD_ALLOWED); */
/*                 return MMI_TRUE; */
/*             } */
/*             break; */

/*         case MMI_FMGR_NOTIFY_SET_STORAGE: */
/*             drv = *((U8*)para); */
/*             mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &drv); */
/*             break; */

/*         default: */
/*             break; */
/*     } */

/*     return MMI_TRUE; */
/* } */


MMI_RET mmi_bt_setting_storage_fmgr_notify_hdlr(mmi_event_struct *param)
{
    srv_fmgr_notification_set_def_storage_event_struct* event;
    
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
            event = (srv_fmgr_notification_set_def_storage_event_struct*)param;
            if (event->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if (mmi_btcomn_is_receiving())
                {
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SETTING_STORAGE_FMGR_NOTIFY_HDLR_NOT_ALLOW, event->state);
                    return MMI_RET_ERR;
                }
            }
            else if (event->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                if (mmi_btcomn_is_receiving())
                {
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SETTING_STORAGE_FMGR_NOTIFY_HDLR_NOT_ALLOW, event->state);
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SETTING_STORAGE_FMGR_NOTIFY_HDLR_ALLOW, event->state);
                    mmi_bt_set_setting_int(BTFF_ITEM_RECV_DRV, &(event->drv_letter));
                }
            }
            break;
    }

    return MMI_RET_OK;
}

#endif /*__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__*/

#endif /* _MMI_BT_ULTRA_SLIM_ */
#endif /* __MMI_BT_SUPPORT__ */ 
