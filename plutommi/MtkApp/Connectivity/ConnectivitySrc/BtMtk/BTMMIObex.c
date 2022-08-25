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
 * BTMMIObex.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for dispatch primitive from goep obex to different applications.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#include "FileMgrSrvGProt.h"
#include "Bluetooth_struct.h"
#include "BTMMIObexGprots.h"
#include "BTMMIObex.h"

#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif
#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#include "OppSrvGprot.h"
#endif

#ifdef __MMI_OPP_SUPPORT__
#include "BTSendCUIGprot.h"
#endif

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#include "BipSrvGprot.h"
#endif

#ifdef __MMI_BT_RECV_FDR_SWITCH__
#include "app_mine.h"
#endif
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "app_ltlcom.h"
#include "string.h"
#include "kal_public_api.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "obconfig.h"
/* auto add by kw_check end */

U16 g_obj_tmp_buff[(SRV_FMGR_PATH_MAX_LEN+1)];

extern void mmi_bt_obex_auth_ind_hdlr(goep_auth_ind_struct *auth_ind);

static auth_ind_handler_struct *g_auth_ind_handler_list;

kal_uint8 mmi_register_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len, AUTH_IND_HANDLER auth_chal_handler);

void mmi_deregister_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len);

#if OBEX_AUTHENTICATION
static AUTH_IND_HANDLER find_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len);
#endif
static void mmi_bt_truncate_ucs_name_with_ext(U16 *dst_name,U16 *src_name, U16 size);

#define UUID_EQUAL(uuid1, uuid2, uuid_len)                          \
   ((uuid1 && uuid2 && kal_mem_cmp(uuid1, uuid2, uuid_len) == 0) || \
         (((uuid1 == 0 || uuid1[0] == 0) && uuid_len == 0) && uuid2 == 0))


#ifdef __MMI_BT_RECV_FDR_SWITCH__
static S8 * mmi_btcomn_get_extension(const U16 *name);
static applib_mime_type_struct * mmi_btcomn_mime_type_lookup(S8 *mime_string, S8 *ext);
static void mmi_btcomn_get_folder(U16 *folder, U8 mime_type, U16 mime_subtype);
#endif /* __MMI_BT_RECV_FDR_SWITCH__ */


#define FTP_OPP_FUNCTION
#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) || \
    defined (__MMI_OPP_SUPPORT__)
/*****************************************************************
    INTERNAL STATIC FUNCTIONS
*****************************************************************/
static void mmi_bt_obex_msg_hdlr(void *msg, int mod_src, void *ilm_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_event_hdlr_init
 * DESCRIPTION
 *  This function is to initialize FTP protocol event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_obex_event_hdlr_init(void)
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
#if OBEX_AUTHENTICATION
/* under construction !*/
#endif
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)	
/* under construction !*/
#endif
#endif
}

#define OBEX_HANDLER_FUNCTION

#if OBEX_AUTHENTICATION
kal_bool DefAuthHandling = KAL_FALSE;
#endif

extern void mmi_bt_obex_disconnect_ind_hdlr(goep_disconnect_ind_struct *disconnect_ind);


#define OBEX_HANDLER_FUNCTION
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
#if OBEX_AUTHENTICATION
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_OPP_SUPPORT__)        
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_OPP_SUPPORT__) */ 
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
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

#if OBEX_AUTHENTICATION
/*****************************************************************************
 * FUNCTION
 *  find_auth_ind_handler
 * DESCRIPTION
 *  search auth_ind handler according uuid
 * PARAMETERS
 *  uuid            [IN]         
 *  uuid_len        [IN]        
 * RETURNS
 *   not NULL: success
 *   NULL: fail
 *****************************************************************************/
static AUTH_IND_HANDLER find_auth_ind_handler(kal_uint8 uuid[], kal_uint8 uuid_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    auth_ind_handler_struct *item = g_auth_ind_handler_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the uuid */
    while (item != NULL)
    {
        if (UUID_EQUAL(uuid, item->uuid, uuid_len))
        {
            return item->auth_ind_handler;
        }
        item = item->next;
    }
    return NULL;
}
#endif

#ifdef __MMI_FTC_SUPPORT__
//static U8 mmi_bt_obex_profile_share_buffer[MMI_OBEX_PROFILE_SHARE_BUF_SIZE];

//#ifdef __MMI_BT_RX_ENHANCE__
//static U8 mmi_bt_obex_profile_inter_buffer[MMI_OBEX_PROFILE_SHARE_BUF_SIZE];
//#endif /* __MMI_BT_RX_ENHANCE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_get_profile_shared_buffer
 * DESCRIPTION
 *  To return all foreground profiles used internal buffer ptr.
 *  For the 2 Buffer Design
 * PARAMETERS
 *  uuid            [IN]         
 *  uuid_len        [IN]        
 * RETURNS
 *   not NULL: success
 *   NULL: fail
 *****************************************************************************/
// U8 *mmi_bt_obex_get_profile_shared_buffer(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/

//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_MMI_OBEX_GET_PROFILE_SHARED_BUF);
    
//     memset(mmi_bt_obex_profile_share_buffer, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);
//     return mmi_bt_obex_profile_share_buffer;
// }


#ifdef __MMI_BT_RX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_get_profile_shared_int_buffer
 * DESCRIPTION
 *  To return all foreground profiles used internal buffer ptr.
 *  For the 2 Buffer Design
 * PARAMETERS
 *  uuid            [IN]         
 *  uuid_len        [IN]        
 * RETURNS
 *   not NULL: success
 *   NULL: fail
 *****************************************************************************/
// U8 *mmi_bt_obex_get_profile_shared_int_buffer(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/

//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/

//     memset(mmi_bt_obex_profile_inter_buffer, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);
//     return mmi_bt_obex_profile_inter_buffer;
// }
#endif /* __MMI_BT_RX_ENHANCE__ */


#endif /* (__MMI_FTC_SUPPORT__) || (__MMI_OPP_SUPPORT__) */

#endif /* (__MMI_FTS_SUPPORT__) || (__MMI_FTC_SUPPORT__) || (__MMI_OPP_SUPPORT__) */


#endif /*__MMI_BT_SUPPORT__*/

#ifdef __MMI_BT_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_truncate_ucs_name_with_ext
 * DESCRIPTION
 *  This function is to cut name if name is too long
 * PARAMETERS
 * path     [OUT]
 * drive    [IN]
 * folder   [IN]
 * file     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_bt_truncate_ucs_name_with_ext(U16 *dst_name,U16 *src_name, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *p_ext_name;
    U16 p_ext_len;
    S32 copy_len;
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    len = mmi_wcslen(src_name);
        
    if (len < size)
    {
        mmi_wcscpy(dst_name, src_name);
    }
    else
    {
        p_ext_name = mmi_wcsrchr(src_name, L'.');
        if (p_ext_name)
        {
            p_ext_len = mmi_wcslen(p_ext_name);

            if (p_ext_len > 5)
            {
                p_ext_name[5] = L'\0';
                p_ext_len = 5;
            }
            
            copy_len = size - p_ext_len - 2;
    
            if (copy_len > 0)
            {
                mmi_wcsncpy(dst_name, src_name, copy_len);
                mmi_wcscat(dst_name, L"~");            
                mmi_wcscat(dst_name, p_ext_name);
            }
        }
        else
        {
            mmi_wcsncpy(dst_name, src_name, (size - 1));
        }
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_path
 * DESCRIPTION
 *  This function is to update part of path
 * PARAMETERS
 * path     [OUT]
 * drive    [IN]
 * file     [IN]
 * RETURNS
 *  U16 *
 *****************************************************************************/
U16 * mmi_bt_update_path(U16 *path, U8 drive, U16 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *p1 = NULL, *p2 = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path);

    if (drive)
    {
        path[0] = (U16)drive;
    }

    if (file)
    {
        /* find last '\' */
        p2 = path;
        for (p1 = mmi_wcschr(p2, L'\\'); p1; p1 = mmi_wcschr(p2, L'\\'))
        {
            p2 = p1+1;
        }
        
        mmi_wcscpy(p2, file);
    }

    return path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_fldr_name
 * DESCRIPTION
 *  This function is to update part of path
 * PARAMETERS
 * fldr     [OUT]
 * path     [IN]
 * RETURNS
 *  U16 *
 *****************************************************************************/
U16 * mmi_bt_get_fldr_name(U16 *name, const U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *p1 = NULL, *p2 = NULL, *p3 = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path && name);

    p3 = mmi_wcschr(path, L'\\');
    
    MMI_ASSERT(p3);
    
    p3++;

    
    /* find last '\' */
    for (p1 = mmi_wcschr(p3, L'\\'); p1; p1 = mmi_wcschr(p2, L'\\'))
    {
        p2 = p1+1;
    }

    if (p2 == NULL)
    {
        mmi_wcscpy(name, L"root");
    }
    else
    {
        mmi_wcsncpy(name, p3, p2 - p3 - 1);
    }

    return name;
}


U16 * mmi_bt_make_prefix(U16 *name, U16 size, U16 *old_name, U16 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 prefix[10];
    S32 l1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(prefix, "Dup(%d)", num);

    l1 = mmi_wcslen(prefix);

    mmi_wcscpy(name, prefix);

    mmi_bt_truncate_ucs_name_with_ext((U16 *)(name+l1),old_name, (U16)(size-l1));    

    return name;
}

#ifdef __MMI_OPP_SUPPORT__
btsend_callback send_callback;

/*****************************************************************************
* FUNCTION
*  mmi_vclndr_opp_group_proc
* DESCRIPTION
*  Proc function of opp group.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_send_object_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_BT_SENDING_SUCC:
        case EVT_ID_CUI_BT_SENDING_FAIL:
            if (send_callback != NULL)
            {
                send_callback(NULL, NULL);
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_object
 * DESCRIPTION
 *  This function is to send object via Available bluetooth profile
 * PARAMETERS
 *  obj [IN]
 *  app [IN]
 *  prof [IN]
 *  option [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_send_object(btsend_obj_struct* obj,
                        btsend_app_struct* app,
                        btsend_prof_enum prof,
                        btsend_opt_enum option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_bt_sending_para_struct para;
    cui_bt_sending_obj_struct para_obj;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para_obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
    para_obj.data.u.file.path = (U16*)obj->data.u.file.path;
    para_obj.data.u.file.is_sfn = obj->data.u.file.is_sfn;
    
    para.obj = &para_obj;
    if (option == BTSEND_OPT_NORMAL)
    {
        para.option = CUI_BT_SENDIND_OPT_NORMAL;
    }
    else
    {
        para.option = CUI_BT_SENDIND_OPT_DEFAULT_DEVICE;
    }
    send_callback = app->callback;
    gid = mmi_frm_group_create(GRP_ID_ROOT, 
                               GRP_ID_AUTO_GEN, 
                               mmi_send_object_group_proc, 
                               NULL);
    mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    cui_bt_sending_launch(gid, &para);
    return MMI_RET_OK;
}

#endif /* __MMI_OPP_SUPPORT__*/

#endif /* __MMI_BT_SUPPORT__ */
