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
 * DCDV30Srv.c
 *
 * Project:
 * --------
 * MAUI
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_OP01_DCD_V30__

#include "MMI_include.h"
#include "dcdagentdefine.h"
#include "dcdagentinterface.h"
#include "pldefine.h"

#include "app2soc_struct.h"
#include "soc_api.h"
#include "custom_events_notify.h"
#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "nwInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "kal_trace.h"
#include "Conversions.h"
#include "app_buff_alloc.h"
#include "app_url.h"
#include "app_mine.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#include "wbxmlp.h"
#include "wbxmlp_def.h"
#include "xml_def.h"
#include "custom_dcd.h"
#include "mmi_rp_app_dcd_def.h"
#include "DCDV30Prot.h"
#include "DCDV30Gprot.h"
#include "ModeSwitchSrvGProt.h"
#include "TimerEvents.h"
#include "Nvram_common_defs.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
#define	APPLICATION_ID_HDR		"X-WAP-Application-ID"
#define DCD_APPLICATION_ID		"application/x-oma-dcd:dcd.ua"

/* for debug */
#define DCD_DEBUG_MODE                        (1)


/*****************************************************************************
 * Enum
 *****************************************************************************/
/* state enum */
typedef enum
{
    DCD_STATE_IDLE,
    DCD_STATE_SYNCING,
    DCD_STATE_ALL
} mmi_dcd_state_enum;

/* roam shift enum */
typedef enum
{
    DCD_ROAM_SHIFT_TO_FOREIGN,
    DCD_ROAM_SHIFT_TO_HOME,
    DCD_ROAM_SHIFT_ALL
} mmi_dcd_roam_shift_enum;

/* dcd result enum */
typedef enum
{
    DCD_RET_SUCCESS,
    DCD_RET_FAILURE,
    DCD_RET_HIGH_PRIORITY_SYNC_EXIST,
    DCD_RET_SYNC_NOT_ALLOWED,
    DCD_RET_ALL
} mmi_dcd_result_enum;


/*****************************************************************************
 * Struct
 *****************************************************************************/
/* for parsing slc */
typedef struct tagTAGTOKEN
{
    char *  tag_name;
    int     token;
}TAGTOKEN;

typedef struct tagATTRSTARTTOKEN
{
    char*   name;
    char*   prefix;
    int     token;
}ATTRSTARTTOKEN;

typedef struct tagATTRVALUETOKEN
{
    char*   value;
    int     token;
}ATTRVALUETOKEN;

/* service context struct */
typedef struct
{
    srv_func_ptr                on_srv;
    HDCD_Agent                  agent_handle;
    mmi_dcd_state_enum          state;
    MMI_BOOL                    ttl_timer_on;
    MMI_BOOL                    retry_timer_on;
    MMI_BOOL                    immediate_retry;
    MMI_BOOL                    is_retrying;
    U32                         retry_times;
    MMI_BOOL                    is_syncing;
    MMI_BOOL                    is_roaming;
    mmi_dcd_conn_mode_enum      conn_mode;
    MMI_BOOL                    flight_mode;
    mmi_dcd_sync_req_type_enum  sync_type;
    U32                         last_sync_end;
    U32                         last_ttl_delay;
    MMI_BOOL                    wp_suspend_needed;
    mmi_dcd_setting_struct      setting;
} mmi_dcd_srv_cntx_struct;


/*****************************************************************************
 * Declarations
 *****************************************************************************/
/* static variables */
static mmi_dcd_srv_cntx_struct g_dcd_srv_cntx;
static U8 g_dcd_cbm_app_id = 0;
static MMI_BOOL g_dcd_is_ready_to_sync = MMI_FALSE;
static MMI_BOOL g_dcd_is_initialized = MMI_FALSE;
static kal_char *g_sl_url_p = NULL;
static kal_char *g_sl_action_p = NULL;

/* extern variables */
extern PAL_NET_DNS_DATA stDNS;

/*******************************************************************
non-roaming
    always connect   home only    manual        
man     v            v            v
start   v            v            v
svr     v            v            x
ttl     v            v            x
retry   v            v            x
*********************************************************************/
static U8 sync_allow_tbl_non_roming[5][3] = 
{
    /* always home  manual */
    {1,     1,      1}, /* man */
    {1,     1,      1}, /* start */
    {1,     1,      0}, /* svr */
    {1,     1,      0}, /* ttl */
    {1,     1,      0}  /* retry */
};

/********************************************************************
roaming
    always connect   home only                      manual
man     v            v(prompt user when roaming)    v(roaming)  
start   v            x(roaming)                     x(roaming)  
svr     v            x(roaming)                     x           
ttl     v            x(roaming)                     x           
retry   v            x(roaming)                     x           
*******************************************************************/
static U8 sync_allow_tbl_roming[5][3] = 
{
    /* always home  manual */
    {1,     1,      1}, /* man */
    {1,     0,      0}, /* start */
    {1,     0,      0}, /* svr */
    {1,     0,      0}, /* ttl */
    {1,     0,      0}  /* retry */
};

/* for parsing slc */
const static TAGTOKEN tag_tokens_slc[]=
{
    { "sl", 0x05 }
};

const static ATTRSTARTTOKEN attrstart_tokens_slc[] = 
{
	{ "action",		"execute-low",		0x05 },
	{ "action",		"execute-high",		0x06 },
	{ "action",		"cache",			0x07 },
	{ "href",		NULL,				0x08 },
	{ "href",		"http://",			0x09 },
	{ "href",		"http://www.",		0x0A },
	{ "href",		"https://",			0x0B },
	{ "href",		"https://www.",		0x0C }
};

const ATTRVALUETOKEN attrvalue_tokens_slc[]=
{
    /* attributes value tokens */
    { ".com/", 0x85 },
    { ".edu/", 0x86 },
    { ".net/", 0x87 },
    { ".org/", 0x88 }
};


/* main */
static void mmi_dcd_setting_init(void);
static MMI_BOOL mmi_dcd_set_server_url(void);
static MMI_BOOL mmi_dcd_set_max_permanence_num(void);
static void mmi_dcd_srv_cntx_init(void);
static MMI_BOOL mmi_dcd_engine_init(void);
static SDK_RESULT mmi_dcd_srv_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRLONG a_nParam1, BRLONG a_nParam2);
static MMI_BOOL mmi_dcd_check_sync_allowed(mmi_dcd_sync_req_type_enum sync_type, mmi_dcd_conn_mode_enum conn_mode, MMI_BOOL is_roaming);
static MMI_BOOL mmi_dcd_is_manual_sync(mmi_dcd_sync_req_type_enum sync_type, MMI_BOOL include_user_sync);
static MMI_BOOL mmi_dcd_is_callback_needed(mmi_dcd_sync_req_type_enum sync_type, EDCD_MSG_CODE a_eMsgCode, mmi_dcd_event_enum *evt_p);
static mmi_dcd_event_enum mmi_dcd_check_error_msg(EDCD_MSG_CODE a_eMsgCode);

/* sync */
static void mmi_dcd_startup_to_sync(void);
static void mmi_dcd_push_to_sync(char *push_url);
static void mmi_dcd_roam_to_sync(mmi_dcd_roam_shift_enum shift);
static mmi_dcd_result_enum mmi_dcd_start_sync(mmi_dcd_sync_req_type_enum req_type, char *url_data);
static EDCD_AGENT_RESULT mmi_dcd_sync_request(HDCD_Agent agent, mmi_dcd_sync_req_type_enum req_type, char *url_data);
static void mmi_dcd_retry(void);
static void mmi_dcd_stop_retry(void);
static void mmi_dcd_retry_timer_hdlr(void);
static void mmi_dcd_ttl_timer_hdlr(void);

/* network */
static void mmi_dcd_cbm_register_app_id(void);
static void mmi_dcd_sync_before(void);
static void mmi_dcd_sync_after(void);
static U8 mmi_dcd_hdlr_soc_notify_ind(void* msg);
static U8 mmi_dcd_hdlr_get_host_by_name_ind(void *msg);
static mmi_ret mmi_dcd_bearer_status_cb(mmi_event_struct *param);
static void mmi_dcd_postmessage(long nEventType, unsigned long param1, unsigned long param2, unsigned long platform);

/* wap push */
static int mmi_dcd_is_dcd_app_id(const S8 *header, const S8 *dcd);
static int mmi_dcd_toupper(int c);
static int mmi_dcd_stricmp(const char *s1, const char *s2);
static int mmi_dcd_strnicmp(const char *s1, const char *s2, unsigned int n);
static int mmi_dcd_get_attr_from_sl(const kal_wchar  *filename, kal_char **url,  kal_char **action);
static void mmi_dcd_xml_start_elem_hdlr(void *data, const kal_char*el, const kal_char**attr, kal_int32 error);
static int mmi_dcd_get_attr_from_slc(const kal_wchar *filename, kal_char **url, kal_char **action);
static kal_int32 mmi_dcd_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token);
static kal_int32 mmi_dcd_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token);
static void mmi_dcd_wbxml_stag_hdlr(void * resv, const kal_char  *tagname, const kal_char **attr);

/* extern functions */
extern kal_bool dcd_pl_sock_check(kal_int8 sock);
extern kal_bool dcd_sock_queue_connected(kal_int8 sock);
extern kal_bool dcd_sock_queue_closed(kal_int8 sock);
extern kal_uint32 mmi_dcd_mem_initialize(void);
extern kal_uint32 mmi_dcd_mem_finalize(void);
extern const S8* mmi_da_get_header(S32 session_id, U32* header_len);
extern void vadp_p2v_hs_suspend_wallpaper(void);
extern void vadp_p2v_hs_resume_wallpaper(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_srv_initialize
 * DESCRIPTION
 *  initialize for dcd v30 srv
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_srv_initialize(srv_func_ptr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_INITIALIZE);
    
    mmi_dcd_mem_initialize();
    mmi_dcd_cbm_register_app_id();
    mmi_dcd_setting_init();
    mmi_dcd_srv_cntx_init();

    /* save callback ptr */
    g_dcd_srv_cntx.on_srv = callback_func;

    /* if dcd is off */
    if (!mmi_dcd_is_switch_on())
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return MMI_FALSE;
    }

    if (!mmi_dcd_engine_init())
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return MMI_FALSE;
    }

    if (g_dcd_srv_cntx.setting.dcd_restore)
    {
        g_dcd_srv_cntx.setting.dcd_restore = 0x00;
        mmi_dcd_save_setting_data();
    }

    /* dcd service ready now */
    g_dcd_is_initialized = MMI_TRUE;

    /* if network ready, start to sync */
    if (g_dcd_is_ready_to_sync)
    {
        mmi_dcd_startup_to_sync();
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_finalize
 * DESCRIPTION
 *  finalize dcd v30
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_FINALIZE);

    /* reset immediate retry flag */
    g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
    
    /* stop retry and ttl timer */
    if (g_dcd_srv_cntx.is_retrying)
    {
        mmi_dcd_stop_retry();
    }
    if (g_dcd_srv_cntx.ttl_timer_on)
    {
        StopTimer(DCD_TTL_TIMER);
        g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
    }
    if (g_dcd_srv_cntx.is_syncing)
    {
        mmi_dcd_stop_sync();
    }
    ret = emDCDAgent_End(g_dcd_srv_cntx.agent_handle);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
    }
    ret = emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
    }
    mmi_dcd_mem_finalize();
    g_dcd_srv_cntx.agent_handle = NULL;
    g_dcd_is_initialized = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_switch_on
 * DESCRIPTION
 *  dcd is switched on or not
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_switch_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flight_mode, sim_avalible, switch_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CHECK_SWITCH_ON);
    
    sim_avalible = srv_sim_ctrl_is_available(MMI_SIM1);
    flight_mode = g_dcd_srv_cntx.flight_mode;
    switch_on = (MMI_BOOL)(g_dcd_srv_cntx.setting.dcd_switch && sim_avalible && !flight_mode);
    
    MMI_TRACE(
        MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SWITCH_DETAIL_INFO,
        g_dcd_srv_cntx.setting.dcd_switch, sim_avalible, flight_mode, switch_on);
    
    return switch_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_service_available
 * DESCRIPTION
 *  service available check
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flight_mode, sim_avalible, srv_avalibale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    sim_avalible = srv_sim_ctrl_is_available(MMI_SIM1);
    flight_mode = g_dcd_srv_cntx.flight_mode;
    srv_avalibale = (MMI_BOOL)(sim_avalible && !flight_mode);
    return srv_avalibale;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_roaming
 * DESCRIPTION
 *  dcd is roaming or not
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_roaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd_srv_cntx.is_roaming;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_agent_handle
 * DESCRIPTION
 *  get dcd agent handle
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
HDCD_Agent mmi_dcd_get_agent_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd_srv_cntx.agent_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_main_syncing
 * DESCRIPTION
 *  check is main syncing, if yes, live wallpaper need to suspend
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_main_syncing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd_srv_cntx.wp_suspend_needed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_init
 * DESCRIPTION
 *  read setting value from nvram
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SETTING_INIT);
    
    ReadRecord(NVRAM_EF_DCD_SETTING_DATA_LID, 1, &g_dcd_srv_cntx.setting, NVRAM_EF_DCD_SETTING_DATA_SIZE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, error, __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_setting_data
 * DESCRIPTION
 *  save setting value to nvram
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_save_setting_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SAVE_SETTING_DATA);
    
    WriteRecord(NVRAM_EF_DCD_SETTING_DATA_LID, 1, &g_dcd_srv_cntx.setting, NVRAM_EF_DCD_SETTING_DATA_SIZE, &error);
	if (error != NVRAM_WRITE_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, error, __LINE__);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_setting_data
 * DESCRIPTION
 *  return setting data for app
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dcd_setting_struct* mmi_dcd_get_setting_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_dcd_srv_cntx.setting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_server_url
 * DESCRIPTION
 *  set server url
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_set_server_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SET_SERVER_URL);
    
    ret = emDCDAgent_SetConfigDCDServer(g_dcd_srv_cntx.agent_handle, (BRSTR)dcd_custom_get_url_refresh());
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_max_permanence_num
 * DESCRIPTION
 *  set max num of permance entry
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_set_max_permanence_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SET_MAX_PERMANENCE_NUM, MMI_DCD_MAX_SAVED_STORY_COUNT);
    
    ret = emDCDAgent_SetConfigMaxNumOfPermanenceEntry(g_dcd_srv_cntx.agent_handle, MMI_DCD_MAX_SAVED_STORY_COUNT);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_update_mode
 * DESCRIPTION
 *  set update mode to engine
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_set_update_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;
    EDCD_TTL_SYNC_LEVEL update_mode = eDCD_SLEVEL_NORMAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SET_UPDATE_MODE);
    
    if (g_dcd_srv_cntx.setting.dcd_update_mode == DCD_UPDATE_MODE_ONLY_TITLE)
    {
        update_mode = eDCD_SLEVEL_NORMAL;
    }
    else if (g_dcd_srv_cntx.setting.dcd_update_mode == DCD_UPDATE_MODE_TITLE_AND_HOMEPAGE)
    {
        update_mode = eDCD_SLEVEL_FIRST_STORY;
    }
    ret = emDCDAgent_SetConfigTTLSyncLevel(g_dcd_srv_cntx.agent_handle, update_mode);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_srv_cntx_init
 * DESCRIPTION
 *  init for service context
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_srv_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_CNTX_INIT);
    
    if (!g_dcd_is_ready_to_sync)
    {
        g_dcd_srv_cntx.is_roaming = MMI_FALSE;
    }
    g_dcd_srv_cntx.is_retrying = MMI_FALSE;
    g_dcd_srv_cntx.retry_timer_on = MMI_FALSE;
    g_dcd_srv_cntx.retry_times = 0;
    g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
    g_dcd_srv_cntx.is_syncing = MMI_FALSE;
    g_dcd_srv_cntx.state = DCD_STATE_IDLE;
    g_dcd_srv_cntx.sync_type = DCD_SYNC_REQ_TYPE_ALL;
    g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
    g_dcd_srv_cntx.last_sync_end = 0;
    g_dcd_srv_cntx.last_ttl_delay = 0;
    g_dcd_srv_cntx.wp_suspend_needed = MMI_FALSE;
    g_dcd_srv_cntx.conn_mode = (mmi_dcd_conn_mode_enum)g_dcd_srv_cntx.setting.dcd_conn_mode;
    g_dcd_srv_cntx.flight_mode = (MMI_BOOL)!srv_mode_switch_is_network_service_available();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_engine_init
 * DESCRIPTION
 *  initialize for dcd v30 engine
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_dcd_engine_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_ENGINE_INIT);
    
    g_dcd_srv_cntx.agent_handle = emDCDAgent_Create(EMBIDER_MEM_SIZE);
    if (!g_dcd_srv_cntx.agent_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return MMI_FALSE;
    }

    /* start dcd agent */
    ret = emDCDAgent_Start(g_dcd_srv_cntx.agent_handle, mmi_dcd_srv_message_proc, NULL);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
        g_dcd_srv_cntx.agent_handle = NULL;
        return MMI_FALSE;
    }

    /* restore if needed */
    if (g_dcd_srv_cntx.setting.dcd_restore)
    {
        ret = emDCDAgent_Restore(g_dcd_srv_cntx.agent_handle);
        if (ret != eDCD_SUCCESS)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        }
    }

    /* set dcd server */
    if (!mmi_dcd_set_server_url())
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
        g_dcd_srv_cntx.agent_handle = NULL;
        return MMI_FALSE;
    }

    /* set max permanence entry count */
    if (!mmi_dcd_set_max_permanence_num())
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
        g_dcd_srv_cntx.agent_handle = NULL;
        return MMI_FALSE;
    }

    /* set update mode */
    if (!mmi_dcd_set_update_mode())
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
        g_dcd_srv_cntx.agent_handle = NULL;
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_srv_message_proc
 * DESCRIPTION
 *  dcd srv message proc
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static SDK_RESULT mmi_dcd_srv_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRLONG a_nParam1, BRLONG a_nParam2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL callback_needed = MMI_FALSE;
    mmi_dcd_event_enum evt = DCD_EVT_ALL;
    mmi_dcd_sync_req_type_enum sync_type = DCD_SYNC_REQ_TYPE_ALL;
    S32 ttl_delay = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_MSG_PROC, a_eMsgCode);

    /* save sync_type for callback */
    sync_type = g_dcd_srv_cntx.sync_type;
    
    switch (a_eMsgCode)
    {
        case eDCD_MSG_SERVER_PKG_SYNC_START:
        case eDCD_MSG_TTL_PKG_SYNC_START:
        case eDCD_MSG_START_PKG_SYNC_START:
        case eDCD_MSG_RETRY_PKG_SYNC_START:
            /* when main sync start, we need to suspend live wallpaper because of performance */
            vadp_p2v_hs_suspend_wallpaper();
            g_dcd_srv_cntx.wp_suspend_needed = MMI_TRUE;
            break;
    
        case eDCD_MSG_SYNCPKG_SYNC_COMPLETE:
            /* check if need to callback */
            callback_needed = mmi_dcd_is_callback_needed(g_dcd_srv_cntx.sync_type, a_eMsgCode, &evt);
            if (callback_needed)
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_CALLBACK, evt);
                g_dcd_srv_cntx.on_srv(evt, sync_type);
            }
            break;

        case eDCD_MSG_SYNC_COMPLETE:
            /* check if need to callback */
            callback_needed = mmi_dcd_is_callback_needed(g_dcd_srv_cntx.sync_type, a_eMsgCode, &evt);

            /* check if main/man sync, if yes, need to update main/man sync status */
            if (!mmi_dcd_is_manual_sync(g_dcd_srv_cntx.sync_type, MMI_FALSE))
            {
                /* reset immediate retry flag */
                g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
                
                /* stop retry and ttl timer */
                if (g_dcd_srv_cntx.is_retrying)
                {
                    mmi_dcd_stop_retry();
                }
                if (g_dcd_srv_cntx.ttl_timer_on)
                {
                    StopTimer(DCD_TTL_TIMER);
                    g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
                }
                
                /* reset ttl */
                ttl_delay = emDCDAgent_GetSyncPkgTTL(g_dcd_srv_cntx.agent_handle);      
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_GET_PKG_TTL, ttl_delay);
                if (ttl_delay > 0)
                {
                    MMI_BOOL sync_allowed;
                    U32 ticks;
                    sync_allowed = mmi_dcd_check_sync_allowed(
                                    DCD_SYNC_REQ_TYPE_TTL, 
                                    g_dcd_srv_cntx.conn_mode,
                                    g_dcd_srv_cntx.is_roaming);
                    if (sync_allowed)
                    {
                        StartTimer(DCD_TTL_TIMER, ttl_delay, mmi_dcd_ttl_timer_hdlr);
                        g_dcd_srv_cntx.ttl_timer_on = MMI_TRUE;
                    }
                    kal_get_time(&ticks);
                    g_dcd_srv_cntx.last_sync_end = kal_ticks_to_milli_secs(ticks);
                    g_dcd_srv_cntx.last_ttl_delay = ttl_delay;
                }
            }

            /* reset sync scenario */
            g_dcd_srv_cntx.is_syncing = MMI_FALSE;
            g_dcd_srv_cntx.state = DCD_STATE_IDLE;
            g_dcd_srv_cntx.sync_type = DCD_SYNC_REQ_TYPE_ALL;

            mmi_dcd_sync_after();

            if (callback_needed)
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_CALLBACK, evt);
                g_dcd_srv_cntx.on_srv(evt, sync_type);
            }

            /* when sync complete, resume live wapppaper if needed */
            if (g_dcd_srv_cntx.wp_suspend_needed)
            {
                g_dcd_srv_cntx.wp_suspend_needed = MMI_FALSE;
                vadp_p2v_hs_resume_wallpaper();
            }
            break;

        case eDCD_MSG_ERR_SYNTEX:
        case eDCD_MSG_ERR_OTHER_CERTIFY: 
        case eDCD_MSG_ERR_NOT_FOUND_RESOURCE:
        case eDCD_MSG_ERR_INTERNAL_SYSTEM:
        case eDCD_MSG_ERR_TRAFFIC_CONTROL:
        case eDCD_MSG_ERR_NOT_SUPPORT_TERMINAL:
        case eDCD_MSG_ERR_NOT_REGISTER_USER: 
        case eDCD_MSG_ERR_VERSION_NUMBER:
        case eDCD_MSG_ERR_BEFORE_BUY_CITY:
        case eDCD_MSG_ERR_NOT_EXIST_CITY:
        case eDCD_MSG_ERR_VERSION_EXPIRED:
        case eDCD_MSG_ERR_FULL_BUY_CITY_COUNT: 
        case eDCD_MSG_ERR_LATEST_VERSION:
        case eDCD_MSG_ERR_FAIL_REMOVE_CITY:
        case eDCD_MSG_ERR_SYNCPKG_PARSING:
        case eDCD_MSG_ERR_NO_SYNCPKG:
        case eDCD_MSG_ERR_CONTENT_PARSING:
        case eDCD_MSG_ERR_NO_CONTENT:
        case eDCD_MSG_ERR_STORAGE_FULL:
        case eDCD_MSG_ERR_NETWORK_DISABLE:
        case eDCD_MSG_ERR_NETWORK_BUSY:
        case eDCD_MSG_ERR_CONNECT_TIME_OUT:
        case eDCD_MSG_ERR_DOWNLOAD_SYNCPKG:
        case eDCD_MSG_ERR_DOWNLOAD_CONTENT:
        case eDCD_MSG_ERR_DOWNLOAD_APPPKG:
        case eDCD_MSG_ERR_SYNC:
        case eDCD_MSG_ERR_INSUFFICIENT_MEMORY:
            /* if manual sync or error message is storage/memory full, need callback as per spec */
            if (mmi_dcd_is_manual_sync(g_dcd_srv_cntx.sync_type, MMI_TRUE) ||
                a_eMsgCode == eDCD_MSG_ERR_STORAGE_FULL ||
                a_eMsgCode == eDCD_MSG_ERR_INSUFFICIENT_MEMORY)
            {
                callback_needed = MMI_TRUE;
            }

            /* check some special error code, and change to callback event */
            evt = mmi_dcd_check_error_msg(a_eMsgCode);

            /* if not manual sync, need to retry */
            if (!mmi_dcd_is_manual_sync(g_dcd_srv_cntx.sync_type, MMI_TRUE))
            {
                /* if network disable */
                if (a_eMsgCode == eDCD_MSG_ERR_NETWORK_DISABLE)
                {
                    g_dcd_srv_cntx.immediate_retry = MMI_TRUE;
                    
                    /* network not available, retry is useless,
                       so we can just stop retry, if now is retrying */
                    if (g_dcd_srv_cntx.is_retrying)
                    {
                        mmi_dcd_stop_retry();
                    }
                }
                else
                {
                    g_dcd_srv_cntx.immediate_retry = MMI_FALSE;

                    /* retry times less than 2, need to retry */
                    if (g_dcd_srv_cntx.retry_times < 2)
                    {
                        mmi_dcd_retry();
                    }
                }
            }

            /* reset sync scenario */
            g_dcd_srv_cntx.is_syncing = MMI_FALSE;
            g_dcd_srv_cntx.state = DCD_STATE_IDLE;
            g_dcd_srv_cntx.sync_type = DCD_SYNC_REQ_TYPE_ALL;

            mmi_dcd_sync_after();

            /* callback app if needed */
            if (callback_needed)
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SRV_CALLBACK, evt);
                g_dcd_srv_cntx.on_srv(evt, sync_type);
            }

            /* when sync fail, resume live wapppaper if needed */
            if (g_dcd_srv_cntx.wp_suspend_needed)
            {
                g_dcd_srv_cntx.wp_suspend_needed = MMI_FALSE;
                vadp_p2v_hs_resume_wallpaper();
            }
            break;
            
        default:
            break;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_check_sync_allowed
 * DESCRIPTION
 *  check sync is allowed or not
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_dcd_check_sync_allowed(mmi_dcd_sync_req_type_enum sync_type, mmi_dcd_conn_mode_enum conn_mode, MMI_BOOL is_roaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_allowed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CHECK_SYNC_ALLOWED, sync_type, conn_mode, is_roaming);
    
    if (is_roaming)
    {
        is_allowed = (MMI_BOOL)sync_allow_tbl_roming[sync_type][conn_mode];
    }
    else
    {
        is_allowed = (MMI_BOOL)sync_allow_tbl_non_roming[sync_type][conn_mode];
    }
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SYNC_ALLOWED_RESULT, is_allowed);
    return is_allowed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_manual_sync
 * DESCRIPTION
 *  check the sync req type is manual update or not
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_is_manual_sync(mmi_dcd_sync_req_type_enum sync_type, MMI_BOOL include_user_sync)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CHECK_MANUAL_SYNC, sync_type, include_user_sync);
    
    if (sync_type == DCD_SYNC_REQ_TYPE_GETENTRYCONTENT ||
        sync_type == DCD_SYNC_REQ_TYPE_GETDATA2 ||
        sync_type == DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST ||
        sync_type == DCD_SYNC_REQ_TYPE_SEARCHCITY ||
        sync_type == DCD_SYNC_REQ_TYPE_GETCITYLIST ||
        sync_type == DCD_SYNC_REQ_TYPE_ADDWEATHERCITY ||
        sync_type == DCD_SYNC_REQ_TYPE_DELETEWEATHERCITY)
    {
        return MMI_TRUE;
    }

    if (sync_type == DCD_SYNC_REQ_TYPE_MAN && include_user_sync)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_callback_needed
 * DESCRIPTION
 *  check if need to callback
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_is_callback_needed(mmi_dcd_sync_req_type_enum sync_type, EDCD_MSG_CODE a_eMsgCode, mmi_dcd_event_enum *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL callback_needed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CHECK_CALLBACK_NEEDED, sync_type, a_eMsgCode);
    
    if (a_eMsgCode == eDCD_MSG_SYNCPKG_SYNC_COMPLETE)
    {
        switch(sync_type)
        {
            case DCD_SYNC_REQ_TYPE_MAN:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_USER_SYNCPKG_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_START:
            case DCD_SYNC_REQ_TYPE_SVR:
            case DCD_SYNC_REQ_TYPE_TTL:
            case DCD_SYNC_REQ_TYPE_RETRY:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_MAIN_SYNCPKG_SYNC_COMPLETE;
                break;

            default:
                break;
        }
    }
    else if (a_eMsgCode == eDCD_MSG_SYNC_COMPLETE)
    {
        switch(sync_type)
        {
            case DCD_SYNC_REQ_TYPE_MAN:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_USER_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_START:
            case DCD_SYNC_REQ_TYPE_SVR:
            case DCD_SYNC_REQ_TYPE_TTL:
            case DCD_SYNC_REQ_TYPE_RETRY:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_MAIN_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_GETENTRYCONTENT:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_GETENTRYCONTENT_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_GETDATA2:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_GETDATA2_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_GETBACKGROUNDLIST_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_SEARCHCITY:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_SEARCHCITY_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_GETCITYLIST:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_GETCITYLIST_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_ADDWEATHERCITY:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_ADDWEATHERCITY_SYNC_COMPLETE;
                break;

            case DCD_SYNC_REQ_TYPE_DELETEWEATHERCITY:
                callback_needed = MMI_TRUE;
                *evt_p = DCD_EVT_DELETEWEATHERCITY_SYNC_COMPLETE;
                break;

            default:
                break;
        }
    }
    return callback_needed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_check_error_msg
 * DESCRIPTION
 *  check the error msg, return callback event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_dcd_event_enum mmi_dcd_check_error_msg(EDCD_MSG_CODE a_eMsgCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_event_enum evt = DCD_EVT_ERR_SYNC_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CHECK_ERR_MSG, a_eMsgCode);
    
    switch (a_eMsgCode)
    {
        case eDCD_MSG_ERR_SYNTEX:
            evt = DCD_EVT_ERR_SYNTEX;
            break;

        case eDCD_MSG_ERR_OTHER_CERTIFY:
            evt = DCD_EVT_ERR_OTHER_CERTIFY;
            break;

        case eDCD_MSG_ERR_NOT_FOUND_RESOURCE:
            evt = DCD_EVT_ERR_NOT_FOUND_RESOURCE;
            break;

        case eDCD_MSG_ERR_INTERNAL_SYSTEM:
            evt = DCD_EVT_ERR_INTERNAL_SYSTEM;
            break;

        case eDCD_MSG_ERR_TRAFFIC_CONTROL:
            evt = DCD_EVT_ERR_TRAFFIC_CONTROL;
            break;

        case eDCD_MSG_ERR_NOT_SUPPORT_TERMINAL:
            evt = DCD_EVT_ERR_NOT_SUPPORT_TERMINAL;
            break;

        case eDCD_MSG_ERR_NOT_REGISTER_USER:
            evt = DCD_EVT_ERR_NOT_REGISTER_USER;
            break;

        case eDCD_MSG_ERR_VERSION_NUMBER:
            evt = DCD_EVT_ERR_VERSION_NUMBER;
            break;

        case eDCD_MSG_ERR_BEFORE_BUY_CITY:
            evt = DCD_EVT_ERR_BEFORE_BUY_CITY;
            break;

        case eDCD_MSG_ERR_NOT_EXIST_CITY:
            evt = DCD_EVT_ERR_NOT_EXIST_CITY;
            break;

        case eDCD_MSG_ERR_VERSION_EXPIRED:
            evt = DCD_EVT_ERR_VERSION_EXPIRED;
            break;

        case eDCD_MSG_ERR_FULL_BUY_CITY_COUNT:
            evt = DCD_EVT_ERR_FULL_BUY_CITY_COUNT;
            break;

        case eDCD_MSG_ERR_LATEST_VERSION:
            evt = DCD_EVT_ERR_LATEST_VERSION;
            break;

        case eDCD_MSG_ERR_FAIL_REMOVE_CITY:
            evt = DCD_EVT_ERR_FAIL_REMOVE_CITY;
            break;

        case eDCD_MSG_ERR_SYNCPKG_PARSING:
            evt = DCD_EVT_ERR_SYNCPKG_PARSING;
            break;

        case eDCD_MSG_ERR_NO_SYNCPKG:
            evt = DCD_EVT_ERR_NO_SYNCPKG;
            break;

        case eDCD_MSG_ERR_CONTENT_PARSING:
            evt = DCD_EVT_ERR_CONTENT_PARSING;
            break;

        case eDCD_MSG_ERR_NO_CONTENT:
            evt = DCD_EVT_ERR_NO_CONTENT;
            break;

        case eDCD_MSG_ERR_STORAGE_FULL:
            evt = DCD_EVT_ERR_STORAGE_FULL;
            break;

        case eDCD_MSG_ERR_NETWORK_DISABLE:
            evt = DCD_EVT_ERR_NETWORK_DISABLE;
            break;

        case eDCD_MSG_ERR_NETWORK_BUSY:
            evt = DCD_EVT_ERR_NETWORK_BUSY;
            break;

        case eDCD_MSG_ERR_CONNECT_TIME_OUT:
            evt = DCD_EVT_ERR_CONNECT_TIME_OUT;
            break;

        case eDCD_MSG_ERR_DOWNLOAD_SYNCPKG:
            evt = DCD_EVT_ERR_DOWNLOAD_SYNCPKG;
            break;

        case eDCD_MSG_ERR_DOWNLOAD_CONTENT:
            evt = DCD_EVT_ERR_DOWNLOAD_CONTENT;
            break;

        case eDCD_MSG_ERR_DOWNLOAD_APPPKG:
            evt = DCD_EVT_ERR_DOWNLOAD_APPPKG;
            break;

        case eDCD_MSG_ERR_INSUFFICIENT_MEMORY:
            evt = DCD_EVT_ERR_INSUFFICIENT_MEMORY;
            break;

        default:
            break;
    }
    return evt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_user_to_sync
 * DESCRIPTION
 *  user manual update, need to sync
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_user_to_sync(mmi_dcd_sync_req_type_enum req_type, char *url_data, MMI_BOOL *is_syncing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_result_enum ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_USER_TO_SYNC, req_type, g_dcd_srv_cntx.is_syncing);
    
    *is_syncing = MMI_FALSE;

    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(req_type, url_data);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
        
        if (ret == DCD_RET_HIGH_PRIORITY_SYNC_EXIST)
        {
            *is_syncing = MMI_TRUE;
            return MMI_TRUE;
        }
        else if (ret == DCD_RET_SUCCESS)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_startup_to_sync
 * DESCRIPTION
 *  when bootup or reset, startup to sync
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_startup_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_result_enum ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_STARTUP_TO_SYNC);

    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_push_to_sync
 * DESCRIPTION
 *  when received wap push and success to get url, need to sync
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_push_to_sync(char *push_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_result_enum  ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_PUSH_TO_SYNC);

    /* if dcd switch is off, wakeup app */
    if (!g_dcd_srv_cntx.setting.dcd_switch)
    {
        g_dcd_srv_cntx.setting.dcd_switch = MMI_TRUE;
        mmi_dcd_save_setting_data();
        g_dcd_srv_cntx.on_srv(DCD_EVT_WAKE_UP, g_dcd_srv_cntx.sync_type);
    }

    /* init dcd engine, if needed */
    if (!g_dcd_is_initialized)
    {
        if (!mmi_dcd_engine_init())
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
            return;
        }
        g_dcd_is_initialized = MMI_TRUE;
    }

    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_SVR, push_url);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_reset_to_sync
 * DESCRIPTION
 *  when restore to factory, need to sync
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_reset_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_dcd_result_enum  ret = DCD_RET_ALL;
    EDCD_AGENT_RESULT agent_result = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_RESET_TO_SYNC);

    if (g_dcd_srv_cntx.is_retrying)
    {
        mmi_dcd_stop_retry();
    }
    if (g_dcd_srv_cntx.ttl_timer_on)
    {
        StopTimer(DCD_TTL_TIMER);
        g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
    }
    if (g_dcd_srv_cntx.is_syncing)
    {
        mmi_dcd_stop_sync();
    }

    /* restore */
    agent_result = emDCDAgent_Restore(g_dcd_srv_cntx.agent_handle);
    if (agent_result != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, agent_result, __LINE__);
    }

    /* reset max num of permanence */
    mmi_dcd_set_max_permanence_num();

    /* reset update mode */
    mmi_dcd_set_update_mode();
    
    /* reset context */
    mmi_dcd_srv_cntx_init();

    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_to_sync
 * DESCRIPTION
 *  when switch on/off status changed, need to sync
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_switch_to_sync(MMI_BOOL switch_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SWITCH_TO_SYNC, switch_on);
    
    if (switch_on)
    {
        if (!mmi_dcd_engine_init())
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
            return;
        }
        g_dcd_is_initialized = MMI_TRUE;
        if (g_dcd_is_ready_to_sync)
        {
            mmi_dcd_startup_to_sync();
        }
    }
    else
    {
        g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
        
        if (g_dcd_srv_cntx.is_retrying)
        {
            mmi_dcd_stop_retry();
        }
        if (g_dcd_srv_cntx.ttl_timer_on)
        {
            StopTimer(DCD_TTL_TIMER);
            g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
        }
        if (g_dcd_srv_cntx.is_syncing)
        {
            mmi_dcd_stop_sync();
        }
        ret = emDCDAgent_End(g_dcd_srv_cntx.agent_handle);
        if (ret != eDCD_SUCCESS)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        }
        ret = emDCDAgent_Destroy(g_dcd_srv_cntx.agent_handle);
        if (ret != eDCD_SUCCESS)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        }
        g_dcd_srv_cntx.agent_handle = NULL;
        g_dcd_is_initialized = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_conn_to_sync
 * DESCRIPTION
 *  when connnect mode changed, need to sync
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_conn_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_dcd_result_enum  ret = DCD_RET_ALL;
	mmi_dcd_conn_mode_enum conn_mode = (mmi_dcd_conn_mode_enum)g_dcd_srv_cntx.setting.dcd_conn_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_CONN_TO_SYNC, 
        g_dcd_srv_cntx.conn_mode, conn_mode, g_dcd_srv_cntx.is_roaming);
    
    if ((g_dcd_srv_cntx.conn_mode == DCD_CONN_MODE_MANUAL && (conn_mode == DCD_CONN_MODE_ALWAYS || conn_mode == DCD_CONN_MODE_HOME)) ||
        (g_dcd_srv_cntx.conn_mode == DCD_CONN_MODE_HOME && g_dcd_srv_cntx.is_roaming && conn_mode == DCD_CONN_MODE_ALWAYS))
    {
        g_dcd_srv_cntx.conn_mode = conn_mode;

        /* start sync if allowed */
        if (mmi_dcd_is_switch_on())
        {
            ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
        }
    }
    else
    {
        g_dcd_srv_cntx.conn_mode = conn_mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_roam_to_sync
 * DESCRIPTION
 *  when dcd roam status changed, need to sync
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_roam_to_sync(mmi_dcd_roam_shift_enum shift)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_dcd_result_enum  ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_ROAM_TO_SYNC, shift, g_dcd_srv_cntx.setting.dcd_conn_mode);

    if (shift == DCD_ROAM_SHIFT_TO_HOME)
    {
        if (g_dcd_srv_cntx.setting.dcd_conn_mode == DCD_CONN_MODE_HOME)
        {
            /* start sync if allowed */
            if (mmi_dcd_is_switch_on())
            {
                ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_start_sync
 * DESCRIPTION
 *  begin to sync
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_dcd_result_enum mmi_dcd_start_sync(mmi_dcd_sync_req_type_enum req_type, char *url_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;
    MMI_BOOL sync_allowed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC, req_type);
    
    if (g_dcd_srv_cntx.is_syncing)
    {
        return DCD_RET_HIGH_PRIORITY_SYNC_EXIST;
    }
    
    if (mmi_dcd_is_manual_sync(req_type, MMI_TRUE))
    {
        sync_allowed = mmi_dcd_check_sync_allowed(DCD_SYNC_REQ_TYPE_MAN, g_dcd_srv_cntx.conn_mode, g_dcd_srv_cntx.is_roaming);
    }
    else
    {
        sync_allowed = mmi_dcd_check_sync_allowed(req_type, g_dcd_srv_cntx.conn_mode, g_dcd_srv_cntx.is_roaming);
    }
    
    if (!sync_allowed)
    {
        if (req_type == DCD_SYNC_REQ_TYPE_RETRY)
        {
            g_dcd_srv_cntx.is_retrying = MMI_FALSE;
        }
        return DCD_RET_SYNC_NOT_ALLOWED;
    }

    /* if manual update, no need to stop retry and ttl timer */
    if (!mmi_dcd_is_manual_sync(req_type, MMI_FALSE))
    {
        /* reset immediate sync flag */
        g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
        
        /* stop retry timer and ttl timer */
        if (!(g_dcd_srv_cntx.is_retrying && req_type == DCD_SYNC_REQ_TYPE_RETRY))
        {
            if (g_dcd_srv_cntx.retry_timer_on)
            {
                StopTimer(DCD_RETRY_TIMER);
                g_dcd_srv_cntx.retry_timer_on = MMI_FALSE;
            }
            g_dcd_srv_cntx.is_retrying = MMI_FALSE;
            g_dcd_srv_cntx.retry_times = 0;
        }
        if (g_dcd_srv_cntx.ttl_timer_on)
        {
            StopTimer(DCD_TTL_TIMER);
            g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
        }
    }

    g_dcd_srv_cntx.sync_type = req_type;
    ret = mmi_dcd_sync_request(g_dcd_srv_cntx.agent_handle, req_type, url_data);
    if (ret != eDCD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        g_dcd_srv_cntx.is_syncing = MMI_FALSE;
        g_dcd_srv_cntx.state = DCD_STATE_IDLE;
        return DCD_RET_FAILURE;
    }
    else
    {
        g_dcd_srv_cntx.is_syncing = MMI_TRUE;
        g_dcd_srv_cntx.state = DCD_STATE_SYNCING;
        return DCD_RET_SUCCESS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_request
 * DESCRIPTION
 *  send sync request
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static EDCD_AGENT_RESULT mmi_dcd_sync_request(HDCD_Agent agent, mmi_dcd_sync_req_type_enum req_type, char *url_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;
    EDCD_REQUEST_TYPE agent_req_type = eDCD_RT_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SYNC_REQUEST, req_type);

#if DCD_DEBUG_MODE
    if (url_data)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G8_DCD, "[DCD][SRV] url_data: %s", url_data);
    }
#endif

    /* sync preparation */
    mmi_dcd_sync_before();

    /* mapping request type to agent request type */
    switch (req_type)
    {
        case DCD_SYNC_REQ_TYPE_SVR:
            agent_req_type = eDCD_RT_SERVER_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_MAN:
            agent_req_type = eDCD_RT_USER_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_TTL:
            agent_req_type = eDCD_RT_TTL_EXPIRED_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_START:
            agent_req_type = eDCD_RT_START_REQUEST;
            break;  

        case DCD_SYNC_REQ_TYPE_RETRY:
            agent_req_type = eDCD_RT_RETRY_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_GETENTRYCONTENT:
            agent_req_type = eDCD_RT_GETENTRYCONTENT_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_GETDATA2:
            agent_req_type = eDCD_RT_DATA2_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST:
            agent_req_type = eDCD_RT_GETBACKGROUNDLIST_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_SEARCHCITY:
            agent_req_type = eDCD_RT_SEARCHCITY_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_GETCITYLIST:
            agent_req_type = eDCD_RT_GETCITYLIST_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_ADDWEATHERCITY:
            agent_req_type = eDCD_RT_ADDWEATHERCITY_REQUEST;
            break;

        case DCD_SYNC_REQ_TYPE_DELETEWEATHERCITY:
            agent_req_type = eDCD_RT_DELETEWEATHERCITY_REQUEST;
            break;

        default:
            agent_req_type = eDCD_RT_USER_REQUEST;
            break;
    }

    /* the server address maybe changed in EM */
    mmi_dcd_set_server_url();

    /* send sync request */
    ret = emDCDAgent_OnSyncRequest(agent, agent_req_type, (BRSTR)url_data);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stop_sync
 * DESCRIPTION
 *  stop sync process
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_stop_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_STOP_SYNC);
    
    if (g_dcd_srv_cntx.state == DCD_STATE_SYNCING)
    {
        ret = emDCDAgent_OnStopSyncRequest(g_dcd_srv_cntx.agent_handle);
        if (ret != eDCD_SUCCESS)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
        }
    }
    
    /* reset state */
    g_dcd_srv_cntx.is_syncing = MMI_FALSE;
    g_dcd_srv_cntx.sync_type = DCD_SYNC_REQ_TYPE_ALL;
    g_dcd_srv_cntx.state = DCD_STATE_IDLE;

    mmi_dcd_sync_after();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_retry
 * DESCRIPTION
 *  when sync fail, set retry timer and retry_delay
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_retry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 retry_delay = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_RETRY, g_dcd_srv_cntx.retry_times);
    
    g_dcd_srv_cntx.is_retrying = MMI_TRUE;
    g_dcd_srv_cntx.retry_times++;

    /* if first time retry, begin to sync 5 min later */
    if (g_dcd_srv_cntx.retry_times == 1)
    {
        retry_delay = 5 * 60 * 1000;
    }
    /* if second time retry, begin to sync 10 min later */
    else if (g_dcd_srv_cntx.retry_times == 2)
    {
        retry_delay = 10 * 60 * 1000;
    }
    else
    {
        ASSERT(0);
    }

    /* start retry timer */
    StartTimer(DCD_RETRY_TIMER, retry_delay, mmi_dcd_retry_timer_hdlr);
    g_dcd_srv_cntx.retry_timer_on = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stop_retry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_stop_retry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_STOP_RETRY);
    
    if (g_dcd_srv_cntx.retry_timer_on)
    {
        StopTimer(DCD_RETRY_TIMER);
        g_dcd_srv_cntx.retry_timer_on = MMI_FALSE;
    }
    g_dcd_srv_cntx.is_retrying = MMI_FALSE;
    g_dcd_srv_cntx.retry_times = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_retry_timer_hdlr
 * DESCRIPTION
 *  retry timer handler
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_retry_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_result_enum ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_RETRY_TIMER_HDLR);
    
    StopTimer(DCD_RETRY_TIMER);
    g_dcd_srv_cntx.retry_timer_on = MMI_FALSE;
    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_RETRY, NULL);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_ttl_timer_hdlr
 * DESCRIPTION
 *  ttl timer handler
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_ttl_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_result_enum ret = DCD_RET_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_TTL_TIMER_HDLR);
    
    StopTimer(DCD_TTL_TIMER);
    g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
    /* start sync if allowed */
    if (mmi_dcd_is_switch_on())
    {
        ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_TTL, NULL);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_user_sync_fail_abort
 * DESCRIPTION
 *  user sync fail and give up retrying, service need to check the ttl sync
 *  1. if ttl time is not expired, start ttl sync right now
 *  2. if ttl time is expired, start ttl sync 5min later
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_user_sync_fail_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sync_allowed = MMI_FALSE;
    U32 ticks, curr_milisecs, ttl_delay;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_USER_SYNC_FAIL_ABORT);
    
    sync_allowed = mmi_dcd_check_sync_allowed(DCD_SYNC_REQ_TYPE_TTL, g_dcd_srv_cntx.conn_mode, g_dcd_srv_cntx.is_roaming);
    if (!sync_allowed)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return;
    }

    /* reset ttl delay time */
    kal_get_time(&ticks);
    curr_milisecs = kal_ticks_to_milli_secs(ticks);
    if (g_dcd_srv_cntx.last_sync_end + g_dcd_srv_cntx.last_ttl_delay > curr_milisecs)
    {
        ttl_delay = g_dcd_srv_cntx.last_sync_end + g_dcd_srv_cntx.last_ttl_delay - curr_milisecs;
        ttl_delay = (ttl_delay > 200) ? ttl_delay : 200;
    }
    else
    {
        ttl_delay = 5 * 60 * 1000;
    }

    /* stop ttl timer and start ttl timer with new delay */
    if (g_dcd_srv_cntx.ttl_timer_on)
    {
        StopTimer(DCD_TTL_TIMER);
        g_dcd_srv_cntx.ttl_timer_on = MMI_FALSE;
    }
    StartTimer(DCD_TTL_TIMER, ttl_delay, mmi_dcd_ttl_timer_hdlr);
    g_dcd_srv_cntx.ttl_timer_on = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  
 * RETURNS
 *   void
 *****************************************************************************/
void mmi_dcd_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *header = NULL;
    U32 header_len = 0;
    int is_dcd_app;
    S8 *sl_url = NULL;
	S8 *sl_action = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_RECEIVE_DA_FILE);

    header = mmi_da_get_header(session_id, &header_len);
    if (!header)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return;
    }
    is_dcd_app = mmi_dcd_is_dcd_app_id(header, DCD_APPLICATION_ID);
    if (!is_dcd_app)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
        return;
    }
    
    if (mime_subtype == MIME_SUBTYPE_SL)
    {
        mmi_dcd_get_attr_from_sl(filepath, &sl_url, &sl_action);
    }
    else if (mime_subtype == MIME_SUBTYPE_SLC)
    {
        mmi_dcd_get_attr_from_slc(filepath, &sl_url, &sl_action);
    }
    
    if (sl_url)
    {
        mmi_dcd_push_to_sync((char*)sl_url);
    }

    FS_Delete((WCHAR *)filepath);

	if (sl_url)
		free_ctrl_buffer(sl_url);
	if (sl_action)
		free_ctrl_buffer(sl_action);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_dcd_app_id
 * DESCRIPTION
 *  compare application id with dcd specific application id
 * PARAMETERS
 *  header      [IN]        Sl protocol header
 *  dcd         [IN]        Dcd specific application id
 * RETURNS
 *   0 : FALSE
 *   1 : YES
 *****************************************************************************/
static int mmi_dcd_is_dcd_app_id(const S8 *header, const S8 *dcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const S8 * p1, * p2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( (header == NULL) || (dcd == NULL))
		return 0;

	p1 = header;
	while ( *p1 != 0 )
	{
		while ( (*p1 != 0) && (*p1 == ' '))
			p1++;
		p2 = p1; 
		while ( *p2 != '\0')
		{
			if ( *p2 == ':' || *p2 == ' ')
				break;
			p2++;
		}
		if ( mmi_dcd_strnicmp(p1, APPLICATION_ID_HDR, p2-p1) == 0 )
		{
			p1 = p2;
			while ( *p1 == ' ')
				p1++;
			if ( *p1 == ':' )
				p1++;
			while ( *p1 == ' ')
				p1++;

			p2 = p1;
			while ( *p2 != 0 )
			{
				if ( *p2 == '\r' || *p2 == '\n')
					break;
				p2 ++;
			}
			if ( mmi_dcd_strnicmp(p1, dcd, p2-p1) == 0 )
				return 1;
		}

		p1 = p2;
		while( (*p1 != 0)  &&  (*p1 != '\r') && (*p1 != '\n'))
		{
			p1++;
		}

		if ( *p1 == '\r' || *p1 == '\n')
		{
			while ( *p1 == '\r' || *p1 == '\n' )
				p1 ++;
		}
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_toupper
 * DESCRIPTION
 *  convert a char to upper 
 * PARAMETERS
 *  c       [IN]        A char
 * RETURNS
 *  upper char
 *****************************************************************************/
static int mmi_dcd_toupper(int c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( c >= 'a' && c <= 'z' )
		c = c - 'a' + 'A';
	return c;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stricmp
 * DESCRIPTION
 *  compare two strings
 * PARAMETERS
 *  s1      [IN]        String
 *  s2      [IN]        String
 * RETURNS
 *  0     : same
 *  Non 0 : different
 *****************************************************************************/
static int mmi_dcd_stricmp(const char *s1, const char *s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (*s1 != '\0' && mmi_dcd_toupper(*s1) == mmi_dcd_toupper(*s2))
	{
		s1++;
		s2++;
	}
	
	return mmi_dcd_toupper(*(unsigned char *) s1) - mmi_dcd_toupper(*(unsigned char *) s2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_strnicmp
 * DESCRIPTION
 *  compare two strings with specific length
 * PARAMETERS
 *  s1      [IN]        String
 *  s2      [IN]        String
 *  n       [IN]        Specific length
 * RETURNS
 *  0     : same
 *  Non 0 : different
 *****************************************************************************/
static int mmi_dcd_strnicmp(const char *s1, const char *s2, unsigned int n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (n == 0)
		return 0;
	if (s1 == NULL || s2 == NULL)
		return 1;
	
	while (n-- != 0 && mmi_dcd_toupper(*s1) == mmi_dcd_toupper(*s2))
	{
		if (n == 0 || *s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	
	return mmi_dcd_toupper(*(unsigned char *) s1) - mmi_dcd_toupper(*(unsigned char *) s2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_attr_from_sl
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  filename        [IN]        File name of wap push sl
 *  url             [IN]        [out]       buf to save url
 *  action          [IN]        [out]       buf to save action
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
static int mmi_dcd_get_attr_from_sl(const kal_wchar  *filename, kal_char **url,  kal_char **action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	XML_PARSER_STRUCT parser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sl_url_p = NULL;
    g_sl_action_p = NULL;
	xml_new_parser (&parser);
    xml_register_element_handler(&parser, mmi_dcd_xml_start_elem_hdlr, NULL);
	xml_register_data_handler(&parser, NULL);
	xml_parse(&parser, (kal_wchar*)filename);
	xml_close_parser(&parser);

    if (url)
    {
	    *url = g_sl_url_p;
    }
    if (action)
    {
	    *action = g_sl_action_p;
    }
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_xml_start_elem_hdlr
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 * data        [IN]        Reserved
 * el          [IN]        Element name string
 * attr        [IN]        Attribute list
 *  error       [IN]        [out]       Error code
 * RETURNS   
 *  if < 0: failed(?)
 *****************************************************************************/
static void mmi_dcd_xml_start_elem_hdlr(void *data, const kal_char*el, const kal_char**attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( mmi_dcd_stricmp(el, "sl") == 0)
	{
		i = 0;
		while ( attr[i] != NULL)
		{
			if ( mmi_dcd_stricmp(attr[i], "href") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_url_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_url_p, attr[i]);
			}
			else if ( mmi_dcd_stricmp(attr[i], "action") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_action_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_action_p, attr[i]);
			}
			i++;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_attr_from_slc
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  filename        [IN]        File name of wap push slc
 *  url             [IN]        [out]       buf to save url
 *  action          [IN]        [out]       buf to save action
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
static int mmi_dcd_get_attr_from_slc(const kal_wchar *filename, kal_char **url, kal_char **action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    WP_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sl_url_p = NULL;
    g_sl_action_p = NULL;

    if ((hd = wbxml_new_parser()) == -1)
    {
        return -1;
    }
    wbxml_register_header_handler(hd, NULL);
    wbxml_register_data_handler (hd, NULL);
    wbxml_register_element_handler (hd, mmi_dcd_wbxml_stag_hdlr, NULL);
    wbxml_register_get_name_handler(hd, mmi_dcd_get_tagname_by_token, mmi_dcd_get_attrname_by_token);

    ret = wbxml_parse(hd, (char*)filename, 0);
    if (ret < 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_COMMON_FAIL, __LINE__);
    }
    wbxml_close_parser(hd); 

    if (url)
    {
	    *url = g_sl_url_p;
    }
    if (action)
    {
	    *action = g_sl_action_p;
    }
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_tagname_by_token
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr         [IN]        Buf to save tag name
 *  tagcp       [IN]        Tag space code page
 *  token       [IN]        Token of tag
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
static kal_int32 mmi_dcd_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len, index=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (tag_tokens_slc[index].tag_name == NULL)
        {
            ASSERT(tag_tokens_slc[index].tag_name != NULL);
            return 0; /* cannot find token in tag token space */
        }
        if (tag_tokens_slc[index].token == token)
        {
            len = strlen(tag_tokens_slc[index].tag_name);
            if (len < WBXML_MAX_BUFFER_SIZE)
            {
                strcpy(ptr, tag_tokens_slc[index].tag_name);
                return len;
            }
            else    /* len is over 2k */
            {
                ASSERT(len < WBXML_MAX_BUFFER_SIZE);
                return -1;
            }
        }
        index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_attrname_by_token
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr         [IN]        Buf to save attribute name or attribute value
 *  prefix      [IN]        Buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp      [IN]        Attribute code page
 *  token       [IN]        Token of attrstart or attrvalue
 * RETURNS
 *  if < 0, failed
 *****************************************************************************/
static kal_int32 mmi_dcd_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len1, len2, index=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (token < 128) /* attrstart token */
    {
        while(1)
        {
            if (attrstart_tokens_slc[index].name == NULL)
            {
                ASSERT(attrstart_tokens_slc[index].name != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrstart_tokens_slc[index].token == token)
            {/* find token in token space */
                if ((len1 = strlen(attrstart_tokens_slc[index].name)) < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrstart_tokens_slc[index].name);
                }
                if (attrstart_tokens_slc[index].prefix != NULL)
                {/* prefix is not NULL, copy it to attrvalue */
                    if ((len2 = strlen(attrstart_tokens_slc[index].prefix))<WBXML_MAX_BUFFER_SIZE)
                    {
                        strcpy(prefix, attrstart_tokens_slc[index].prefix);
                    }
                }
                if (len1 < WBXML_MAX_BUFFER_SIZE)
                {
                    return len1;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len1 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
    else            /* attrvalue token */
    {
        while(1)
        {
            if (attrvalue_tokens_slc[index].value == NULL)
            {
                ASSERT(attrvalue_tokens_slc[index].value != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrvalue_tokens_slc[index].token == token)
            {
                len2 = strlen(attrvalue_tokens_slc[index].value);
                if (len2 < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrvalue_tokens_slc[index].value);
                    return len2;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len2 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_wbxml_stag_hdlr
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  resv          [IN]        Reserved
 *  tagname       [IN]        Element name string
 *  attr          [IN]        Attribute list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_wbxml_stag_hdlr(void * resv, const kal_char  *tagname, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( mmi_dcd_stricmp(tagname, "sl") == 0)
	{
		i = 0;
		while ( attr[i] != NULL)
		{
			if ( mmi_dcd_stricmp(attr[i], "href") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_url_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_url_p, attr[i]);
			}
			else if ( mmi_dcd_stricmp(attr[i], "action") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_action_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_action_p, attr[i]);
			}
			i++;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_acct_id
 * DESCRIPTION
 *  get the account id of dcd
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mmi_dcd_get_acct_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32		networkAccountID;
    kal_uint32      cbm_net_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkAccountID = CBM_DCD_ACCT_ID;
    cbm_net_id = cbm_set_app_id(networkAccountID, g_dcd_cbm_app_id);
    return cbm_net_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cbm_register_app_id
 * DESCRIPTION
 *  register application id for network manager
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_cbm_register_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int8  ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_cbm_app_id == 0)
    {
        ret = cbm_register_app_id(&g_dcd_cbm_app_id);
        if (ret != CBM_OK)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FAIL_WITH_CAUSE, ret, __LINE__);
            g_dcd_cbm_app_id = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_before
 * DESCRIPTION
 *  register protocol event handler before sync
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_sync_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 state = SRV_CBM_DEACTIVATED | SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATING;
    U32 type  = SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_EDGE | SRV_CBM_BEARER_UMTS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SYNC_BEFORE);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,           mmi_dcd_hdlr_soc_notify_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, mmi_dcd_hdlr_get_host_by_name_ind, MMI_TRUE);
    srv_cbm_register_bearer_info(g_dcd_cbm_app_id, state, type, mmi_dcd_bearer_status_cb, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_after
 * DESCRIPTION
 *  deregister protocol event handler after sync
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_sync_after(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SYNC_AFTER);
    
    mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,           mmi_dcd_hdlr_soc_notify_ind);
    mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, mmi_dcd_hdlr_get_host_by_name_ind);
    srv_cbm_deregister_bearer_info(g_dcd_cbm_app_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_hdlr_soc_notify_ind
 * DESCRIPTION
 *  This is the callback function for SOCKET.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_dcd_hdlr_soc_notify_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int8    sock;
	kal_uint8   event_type;   /* soc_event_enum */
	kal_int8    error_cause;  /* used only when EVENT is close/connect */
    kal_bool    result;
	kal_int32   detail_cause; /* refer to cm_cause_enum if error_cause is SOC_BEARER_FAIL */
	app_soc_notify_ind_struct* soc_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SOC_NOTIFY_IND);
    
	soc_ind = (app_soc_notify_ind_struct*) msg;
	sock = soc_ind->socket_id;
	event_type = soc_ind->event_type;
	result = soc_ind->result;
	error_cause = soc_ind->error_cause;
	detail_cause = soc_ind->detail_cause;

    MMI_TRACE(
        MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SOC_NOTIFY_INFO,
        soc_ind->socket_id, soc_ind->event_type, soc_ind->result, soc_ind->msg_len, 
        soc_ind->ref_count, soc_ind->error_cause, soc_ind->detail_cause);

    /* to check whether the socket is used by dcd */
    if (!dcd_pl_sock_check(sock))
    {
        return MMI_FALSE;
    }

	switch(event_type)
	{
	case SOC_READ:		
		if(result == KAL_TRUE)
		{
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_RECEIVE_ENABLE, sock+1, 0);
		}
		break;

	case SOC_WRITE:	
		if (result == KAL_TRUE)
		{
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_SEND_ENABLE, sock+1, 0);
		}
		break;

	case SOC_CONNECT:		
		if(result == KAL_TRUE)
		{
            dcd_sock_queue_connected(sock);
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CONNECT_SUCCESS, sock+1, 0);
		}
        else
        {
            unsigned long net_err_type;
            if(error_cause == SOC_BEARER_FAIL && detail_cause == INSUFF_RESOURCE) 
            {
                net_err_type = SOCKET_ERR_NET_BUSY;
            } 
            else 
            {
                net_err_type = SOCKET_ERR_NET_DISABLE; 
            }
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CONNECT_FAIL, sock+1, net_err_type);
		}
		break;

	case SOC_CLOSE:
		if (result == KAL_TRUE)
		{
            dcd_sock_queue_closed(sock);
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CLOSED, sock+1, 0);
		}
		break;

    default:
        break;
	}
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_hdlr_get_host_by_name_ind
 * DESCRIPTION
 *  This is the callback function for gethostbyname.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_dcd_hdlr_get_host_by_name_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_uint8 *p;
    app_soc_get_host_by_name_ind_struct * addr_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_GET_HOST_IND);
    
    addr_ind = (app_soc_get_host_by_name_ind_struct *)msg;
    if (addr_ind->request_id != DCD_GET_HOST_REQ_ID)
    {
        return MMI_FALSE;
    }
    
    p = (kal_uint8*)&stDNS.m_nIP;
    for ( i = 0; i < addr_ind->addr_len; i++)
    {
        *p++ = addr_ind->addr[i];
    }
    mmi_dcd_postmessage(eMSG_NETWORK, eNET_DNS_GETHOST, 0, 0);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_bearer_status_cb
 * DESCRIPTION
 *  This is the callback function for bearer information.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_dcd_bearer_status_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nwaccount;
    srv_cbm_bearer_info_struct *info = (srv_cbm_bearer_info_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_BEARER_STATUS_CB, info->account_id, info->state);
    
    nwaccount = mmi_dcd_get_acct_id();
    if (info->account_id != nwaccount)
    {
        return MMI_RET_OK;
    }
	switch(info->state)
	{
		case SRV_CBM_ACTIVATING:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_ACTIVATED:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_DEACTIVATING:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_DEACTIVATED:
			mmi_dcd_postmessage(eMSG_NETWORK, eNET_PPP_CLOSE, 0, 0);
			break;

		default:
			break;
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_postmessage
 * DESCRIPTION
 *  This is the callback function for gethostbyname.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_postmessage(long nEventType, unsigned long param1, unsigned long param2, unsigned long platform)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	emEventType Event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_POST_MESSAGE, 
        Event.EventType, Event.nPlatformType, Event.nParam1, Event.nParam2);
    
	Event.EventType = (EMBIDER_EVENT)nEventType;
	Event.nPlatformType = platform;
	Event.nParam1       = param1;
	Event.nParam2       = param2;
	emDCDAgent_PostMessage(g_dcd_srv_cntx.agent_handle, (BRVOID*)&Event);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_network_indication
 * DESCRIPTION
 *  event hdlr for EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED
 *  and EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_dcd_network_indication(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_NETWORK_IND, g_dcd_is_initialized, evt->evt_id);
    
    if (!g_dcd_is_initialized && mmi_dcd_is_switch_on())
    {
        return MMI_RET_OK;
    }
    if (evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED)
    {        
        srv_nw_info_service_availability_changed_evt_struct *service_evt;
        service_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;
        if (service_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
        {
            if (!g_dcd_is_ready_to_sync)
            {
                g_dcd_is_ready_to_sync = MMI_TRUE;
                g_dcd_srv_cntx.is_roaming = srv_nw_info_is_roaming(MMI_SIM1);
                mmi_dcd_startup_to_sync();
            }
            /* sync fail and cause is network not available, 
               immediate retry to sync when network ok as per spec */
            else if (g_dcd_srv_cntx.immediate_retry)
            {
                mmi_dcd_result_enum ret = DCD_RET_ALL;
                g_dcd_srv_cntx.immediate_retry = MMI_FALSE;
                if (mmi_dcd_is_switch_on())
                {
                    ret = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_RETRY, NULL);
                    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_START_SYNC_RESULT, ret);
                }
            }
        }
    }
    else if (evt->evt_id == EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED)
    {        
        MMI_BOOL  foreign_roaming;
        srv_nw_info_roaming_status_changed_evt_struct *roaming_evt;
        roaming_evt = (srv_nw_info_roaming_status_changed_evt_struct*)evt;
        foreign_roaming = roaming_evt->is_roaming_now;
        if (!g_dcd_is_ready_to_sync)
        {
            g_dcd_is_ready_to_sync = MMI_TRUE;
            g_dcd_srv_cntx.is_roaming = foreign_roaming;
            mmi_dcd_startup_to_sync();
        }
        else if (g_dcd_srv_cntx.is_roaming && !foreign_roaming)
        {
            g_dcd_srv_cntx.is_roaming = foreign_roaming;
            mmi_dcd_roam_to_sync(DCD_ROAM_SHIFT_TO_HOME);
        }
        else if (!g_dcd_srv_cntx.is_roaming && foreign_roaming)
        {
            g_dcd_srv_cntx.is_roaming = foreign_roaming;
            mmi_dcd_roam_to_sync(DCD_ROAM_SHIFT_TO_FOREIGN);
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_finalize_evt_hdlr
 * DESCRIPTION
 *  event hdlr for EVT_ID_SRV_SHUTDOWN_DEINIT
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_dcd_finalize_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FINALIZE_EVT_HDLR);
    
    mmi_dcd_finalize();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sim_unavailable_hdlr
 * DESCRIPTION
 *  event hdlr for EVT_ID_SRV_SIM_CTRL_UNAVAILABLE
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_dcd_sim_unavailable_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_SIM_UNAVAILABLE_HDLR);
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_flymode_switch_finish_hdlr
 * DESCRIPTION
 *  fly mode switch finish hdlr
 * PARAMETERS
 *          
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_flymode_switch_finish_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *switch_evt = (srv_mode_switch_notify_struct*)evt;
    MMI_BOOL pre_switch, curr_switch, on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_TRC_FLYMODE_SWITCH, switch_evt->gsm_select_mode);

    on = (switch_evt->gsm_select_mode == SRV_MODE_SWITCH_FLIGHT_MODE) ? MMI_TRUE : MMI_FALSE;
    
    if (g_dcd_srv_cntx.flight_mode != on)
    {
        pre_switch = mmi_dcd_is_switch_on();
        g_dcd_srv_cntx.flight_mode = on;
        curr_switch = mmi_dcd_is_switch_on();
        if (pre_switch != curr_switch)
        {
            mmi_dcd_switch_to_sync(curr_switch);
        }
    }
    return MMI_RET_OK;
}


#endif /* __MMI_OP01_DCD_V30__ */

