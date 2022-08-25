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
*  CallLogMisc.c
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
*============================================================================
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "kal_debug.h"

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)

#include "CphsSrvGprot.h"
#include "SimCtrlSrvGprot.h"

#include "CallLogProt.h"

#include "MMIDataType.h"
#include "mmi_rp_app_calllog_def.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "CallLogSrvGprot.h"
#include "GlobalResDef.h"
#include "CallLogConfig.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "menucuigprot.h"
#include "l4c_nw_cmd.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_SEC_PER_MIN                         (60)
#define MMI_CLOG_MIN_PER_HOUR                        (60)

#define MMI_CLOG_GRP_RANGE_SIZE                      (5)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
typedef struct
{
   /* mmi_clog_grp_type_enum type; */ /* Comment it as use it as array index for slim */
    MMI_ID grp_start;
   /* MMI_ID grp_end; */  /* Use MMI_CLOG_GRP_RANGE_SIZE to slim it */
} mmi_clog_grp_map_struct;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static S32 mmi_clog_is_gid_valid(MMI_ID gid);
static MMI_ID mmi_clog_get_free_gid(const mmi_clog_grp_map_struct *grp_map);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static const mmi_clog_grp_map_struct g_mmi_clog_grp_map_tbl[] = 
{
    {/*MMI_CLOG_GRP_TYPE_NM*/GRP_ID_CLOG_BEGIN},

    {/* MMI_CLOG_GRP_TYPE_MM, */            GRP_ID_CLOG_ROOT        /* , GRP_ID_CLOG_ROOT_LAST */},
    {/* MMI_CLOG_GRP_TYPE_LT, */            GRP_ID_CLOG_LAYOUT      /* , GRP_ID_CLOG_LAYOUT_LAST */},
    {/* MMI_CLOG_GRP_TYPE_VR, */            GRP_ID_CLOG_VIEWER      /* , GRP_ID_CLOG_VIEWER_LAST */},
    {/* MMI_CLOG_GRP_TYPE_OP, */            GRP_ID_CLOG_OPTION      /* , GRP_ID_CLOG_OPTION_LAST */},
    {/* MMI_CLOG_GRP_TYPE_ACT,*/            GRP_ID_CLOG_ACTION      /* , GRP_ID_CLOG_ACTION_LAST */},

#if 0  /* FlowReserved */      
#ifdef __MMI_CLOG_CALL_TIME__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_CLOG_CALL_COST__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_CLOG_SMS_COUNT__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_CLOG_GPRS_COUNT__
/* under construction !*/
#endif
#endif //0
};
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define SEG_ID_MMI_CLOG_PRINT


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_print
 * DESCRIPTION
 *  
 * PARAMETERS
 *  format      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_print(CHAR *format, ...)
{
#ifdef __MMI_CLOG_DEBUG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CLOG_PRINT_MAX_CHAR_LEN          (512)
    char log[MMI_CLOG_PRINT_MAX_CHAR_LEN];
    va_list arg_list;
    static U8 g_mmi_clog_debug_enable = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_clog_debug_enable)
        return;

    va_start(arg_list, format);

#ifdef __MTK_TARGET__
    vsnprintf(log, MMI_CLOG_PRINT_MAX_CHAR_LEN, format, arg_list);
#else 
    _vsnprintf(log, MMI_CLOG_PRINT_MAX_CHAR_LEN, format, arg_list);
#endif 

    log[MMI_CLOG_PRINT_MAX_CHAR_LEN - 1] = '\0';

    va_end(arg_list);

#ifdef __MTK_TARGET__
    /*
     * PRINT_INFORMATION_2(CCA_TRACE_INFO, "%s", log);
     */
#else 
    kal_printf("%s", log);
#endif 

#endif /* __MMI_CLOG_DEBUG__ */ 
}

#define SEG_ID_MMI_CLOG_STRING


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_w_cpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [OUT]         
 *  src         [IN]        
 *  dst_len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
WCHAR *mmi_clog_w_cpy(WCHAR *dst, const WCHAR *src, U32 dst_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 src_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_len = mmi_wcslen(src);
    if (src_len > dst_len)
        mmi_wcsncpy(dst, src, dst_len);
    else
        mmi_wcscpy(dst, src);
    return dst;
}

#define SEG_ID_MMI_CLOG_TIME


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_time_utc2app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamp       [IN]        
 *  app_time        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_time_utc2app(U32 timestamp, applib_time_struct *app_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 local_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, app_time, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_duration_val2app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  duration        [IN]        
 *  hour            [OUT]       
 *  min             [OUT]       
 *  sec             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_duration_val2app(U32 duration, U32 *hour, U32 *min, U32 *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *hour = duration / (MMI_CLOG_MIN_PER_HOUR * MMI_CLOG_SEC_PER_MIN);
    *min = (duration % (MMI_CLOG_MIN_PER_HOUR * MMI_CLOG_SEC_PER_MIN)) / MMI_CLOG_MIN_PER_HOUR;
    *sec = (duration % (MMI_CLOG_MIN_PER_HOUR * MMI_CLOG_SEC_PER_MIN)) % MMI_CLOG_MIN_PER_HOUR;
}

#define SEG_ID_MMI_CLOG_LOG

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_bit2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_clog_bit2idx(U32 bit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = 0;                                                    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
                                                                
    while ((idx < sizeof(U32) * 8) && !((0x01 << idx) & bit))    
    {                                                           
        idx++;                                                  
    }                                                           
   return idx;     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_cid_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clog_is_cid_empty(srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (log->data.call_log.cid[0] == '\0' || log->data.call_log.is_private_cid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_name_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clog_is_name_empty(srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (log->data.call_log.name[0] == '\0');
}

#define SEG_ID_MMI_CLOG_RESOURCE


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_clt_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_STR_ID mmi_clog_get_clt_str_id(srv_clog_clt_enum clt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id = STR_GLOBAL_EMPTY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (clt)
    {
        case SRV_CLOG_CLT_DIALED:
            str_id = STR_ID_CLOG_DIALED_CALL;
            break;

        case SRV_CLOG_CLT_MISSED:
            str_id = STR_ID_CLOG_MISSED_CALL;
            break;

        case SRV_CLOG_CLT_RECVED:
            str_id = STR_ID_CLOG_RECVED_CALL;
            break;
#ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__
        case SRV_CLOG_CLT_REJED:
            break;
#endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
        default:
            break;
    }
    return str_id;
}

#define SEG_ID_MMI_CLOG_GROUP
/* should enter group once allocated, can not allocate more than one at the same time */

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_alloc_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_alloc_gid(mmi_clog_grp_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_ASSERT(type >= 0 && type < sizeof(g_mmi_clog_grp_map_tbl) / sizeof(mmi_clog_grp_map_struct));
    
    return mmi_clog_get_free_gid((const mmi_clog_grp_map_struct *)&g_mmi_clog_grp_map_tbl[type]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_free_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_map     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_ID mmi_clog_get_free_gid(const mmi_clog_grp_map_struct *grp_map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (grp = grp_map->grp_start; grp <= grp_map->grp_start + MMI_CLOG_GRP_RANGE_SIZE; grp++)
    {
        if (!mmi_frm_group_is_present(grp))
            return grp;
    }

    MMI_CLOG_ASSERT(0);
    return GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_gid_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_is_gid_valid(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_ASSERT(GRP_ID_CLOG_ROOT_LAST - GRP_ID_CLOG_ROOT >= MMI_CLOG_GRP_RANGE_SIZE &&
                       GRP_ID_CLOG_LAYOUT_LAST - GRP_ID_CLOG_LAYOUT >= MMI_CLOG_GRP_RANGE_SIZE &&
                       GRP_ID_CLOG_VIEWER_LAST - GRP_ID_CLOG_VIEWER >=  MMI_CLOG_GRP_RANGE_SIZE && 
                       GRP_ID_CLOG_OPTION_LAST - GRP_ID_CLOG_OPTION >= MMI_CLOG_GRP_RANGE_SIZE && 
                       GRP_ID_CLOG_ACTION_LAST - GRP_ID_CLOG_ACTION >= MMI_CLOG_GRP_RANGE_SIZE);

    for (i = 0; i < sizeof(g_mmi_clog_grp_map_tbl) / sizeof(mmi_clog_grp_map_struct); i++)
    {
        if (gid >= g_mmi_clog_grp_map_tbl[i].grp_start && gid <= g_mmi_clog_grp_map_tbl[i].grp_start + MMI_CLOG_GRP_RANGE_SIZE)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_valid_act_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_get_valid_act_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_get_active_id();
    if (MMI_CLOG_IS_GID_INVALID(gid))
        gid = GRP_ID_ROOT;
    return gid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_scrn_in_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid         [IN]        
 *  scrn_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clog_is_scrn_in_active(MMI_ID gid, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gid == mmi_frm_group_get_active_id() && scrn_id == mmi_frm_scrn_get_active_id())
        return MMI_TRUE;
    return MMI_FALSE;
}


#define SEG_ID_MMI_CLOG_INST


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_inst_by_act_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_clog_get_inst_by_act_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID act_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_gid = mmi_frm_group_get_active_id();
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    if (!mmi_clog_is_gid_valid(act_gid))
    {
        MMI_CLOG_ASSERT(0);
        return NULL;
    }
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    return mmi_frm_group_get_user_data(act_gid);
}

#define SEG_ID_MMI_CLOG_ALERT


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id          [IN]        
 *  evt             [IN]        
 *  parent_gid      [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_popup(MMI_STR_ID str_id, mmi_event_notify_enum evt, MMI_ID parent_gid, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_popup_display_simple_ext(str_id, evt, parent_gid, user_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  str_id              [IN]        
 *  evt                 [IN]        
 *  parent_gid          [IN]        
 *  user_data           [IN]     
 *  flags               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_confirm(
        mmi_confirm_type_enum type,
        MMI_STR_ID str_id,
        mmi_event_notify_enum evt,
        MMI_ID parent_gid,
        void *user_data,
        U32 flags)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, type);
    arg.parent_id = parent_gid;
    arg.user_tag = user_data;
    
    /* Only set the value not equal to the default value set in mmi_confirm_property_init */
    if (!MMI_CLOG_CHECK_BIT(flags, MMI_CLOG_ALERT_FLAG_AUTO_DISMISS))
        arg.f_auto_dismiss = MMI_FALSE;  /* Default is MMI_TRUE */
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__    
    if (MMI_CLOG_CHECK_BIT(flags, MMI_CLOG_ALERT_FLAG_ENTER_HISTORY))
        arg.f_enter_history = MMI_TRUE;  /* Default is MMI_FALSE */
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    if (MMI_CLOG_CHECK_BIT(flags, MMI_CLOG_ALERT_FLAG_HIDE_CSK))
        arg.f_auto_map_empty_softkey = MMI_FALSE; /* Default is MMI_TRUE */
    
    return mmi_confirm_display_ext(str_id, evt, &arg);
}

#define SEG_ID_MMI_CLOG_MINI_TAB_BAR


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_update_mini_tab_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_update_mini_tab_bar(void)
{
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_enable_mini_tab_bar(MAIN_MENU_CALL_LOG);

#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
}

#define SEG_ID_MMI_CLOG_CPHS

/* should call this menu in main menu/advanced/call cost in 3parts */

#ifdef __MMI_CLOG_CALL_COST__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_cphs_srv_avail_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_sim_enum mmi_clog_get_cphs_srv_avail_sim(mmi_sim_enum sim_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum cur_sim_id;
    mmi_sim_enum avail_sim_id = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cur_sim_id = (mmi_sim_enum)MMI_CLOG_IDX2BIT(i);
        if (MMI_CLOG_CHECK_BIT(sim_id, cur_sim_id))
        {
            if (srv_cphs_is_service_available(SRV_CPHS_GROUP_OTHER_SUPP_SERVICES, SRV_CPHS_SERVICE_AOC, cur_sim_id))
                MMI_CLOG_SET_BIT(avail_sim_id, cur_sim_id);
        }
    }
    return avail_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_check_cphs_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_check_cphs_service(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM < 3)
    U32 avail_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avail_sim_id = mmi_clog_get_cphs_srv_avail_sim((mmi_sim_enum)MMI_SIM_ALL);
#endif /*(MMI_MAX_SIM_NUM < 3)*/

//.REVIEW
#if (MMI_MAX_SIM_NUM >= 3)
    // Todo
#else /* (MMI_MAX_SIM_NUM >= 3) */

#ifndef __MMI_DUAL_SIM__
    if (avail_sim_id == 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CLOG_CALL_COST, MMI_TRUE);
    }

#else /* __MMI_DUAL_SIM__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
#endif /* (MMI_MAX_SIM_NUM >= 3) */
}

#endif /* __MMI_CLOG_CALL_COST__ */

#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */


