/*******************************************************************************************
 * Filename:    
 * Author :     
 * Date :       
 * Comment:     
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

/* add for RHR */
#include "kal_general_types.h"
#include "track_soc_apn.h"
#include "mmi_l3_enums.h"
#include "custom_config_account.h"

#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_uint16                      crc;
    kal_uint16                      port;
    kal_uint8                       server[100];
    nvram_GPRS_APN_struct           apn;
} track_nvram_data_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint32 track_account_id=0;
static nvram_GPRS_APN_struct apn_use = {0, "", "", ""};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern nvram_importance_parameter_struct G_importance_parameter_data;

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
static void srv_dtcnt_db_store_send_msg(kal_uint16 msg_id, void *req, int mod_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = (ilm_struct *)allocate_ilm(MOD_MMI);   
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = (module_type)mod_dst;
    ilm_send->sap_id = MMI_ABM_SAP;
    ilm_send->msg_id = (msg_type) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) req;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;    
    msg_send_ext_queue(ilm_send);    
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void Socket_cbm_bearer_info_ind_hdlr(void *info)
{
    app_cbm_bearer_info_ind_struct *bearer_info = (app_cbm_bearer_info_ind_struct *)info;
    if(info == NULL)
    {
        return;
    }
    if(bearer_info->error_cause != 0 || bearer_info->error != 0)
    {
        LOGD(L_SOC, L_V1, "msg_id=MSG_ID_APP_CBM_BEARER_INFO_IND error_cause:%d, error:%d", 
            bearer_info->error_cause, bearer_info->error);
    }
}

void srv_cbm_bearer_info_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_info_ind_struct *bearer_info = (mmi_abm_bearer_info_ind_struct *)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (bearer_info->status == CBM_ACTIVATING)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_ACTIVATING");
    }
    else if (bearer_info->status == CBM_ACTIVATED)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_ACTIVATED");
    }
    else if (bearer_info->status == CBM_DEACTIVATING)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_DEACTIVATING");
    }
    else
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_DEACTIVATED");
    }
    
    if (bearer_info->bearer_type & CBM_CSD)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_BEARER_CSD");
    }
    else if (bearer_info->bearer_type & CBM_PS)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_BEARER_PS");
    }
    else if (bearer_info->bearer_type & CBM_WIFI)
    {
        LOGD(L_SOC, L_V6, "SRV_CBM_BEARER_WIFI");
    }
}

void srv_cbm_app_bearer_info_ind_hdlr(void *info) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_cbm_bearer_info_ind_struct *bearer_info;
    kal_uint8 app_id; 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_info = (app_cbm_bearer_info_ind_struct*)info;
    app_id = cbm_get_app_id(bearer_info->account_id);
    
    if (app_id != CBM_INVALID_APP_ID)
    {
    }

    LOGD(L_SOC, L_V6, "account_id=%d, state=%d, bearer=%d, app_id=%d", 
        bearer_info->account_id, bearer_info->state, bearer_info->bearer, app_id);
}


void Socket_apn_req(void *par)
{
    static kal_uint8 vs_app_id;
    cbm_app_info_struct app_info = {0};
    kal_int8 s, result;
    kal_uint8 option;
    //mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)xzx_notify);
    //mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)xzx_get_host_by_name);

    LOGD(L_SOC, L_V6, "APN 设置");
    app_info.app_icon_id = 0;
    app_info.app_str_id = 0;
    app_info.app_type = DTCNT_APPTYPE_MRE_NET;
    s = cbm_register_app_id_with_app_info(&app_info, &vs_app_id);
    LOGD(L_SOC, L_V6, "s=%d", s);
    //vs_nw_socket_set_account_id();
    track_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, vs_app_id, KAL_FALSE);

    LOGD(L_SOC, L_V5, "APN 设置 ret=%d, xzx_account_id=%d", s, track_account_id);
    /* Create socket */               
}

/******************************************************************************
 *  Function    -  track_socket_apn_init
 *
 *  Purpose     -  APN初始化
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_socket_apn_init()
{
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    LOGD(L_SOC, L_V5, "");
    info_req = (mmi_abm_update_account_info_req_struct *) construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET); 
    if(info_req == NULL)
    {
        LOGD(L_SOC, L_V1, "ERROR! 严重错误!");
        track_cust_restart(56, 0);
    }
    info_req->action = MMI_ABM_PROFILE_ADD; 
    //info_req->account_id = 0x3e00;  //00 表示第 1 个 account
    info_req->account_id = 0x00017e00;
    //xzx_account_id
    //xzx_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, 0, KAL_FALSE);
    //info_req->account_id = xzx_account_id;
    info_req->bearer_type = CBM_PS; //bearer 的类型为 GPRS
    srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);
    //srv_dtcnt_store_update_acc_apinfo();
    Socket_apn_req((void*)0);
}


void Socket_prof_query_ind_hdlr(void *info)
{
    mmi_abm_profile_query_ind_struct *ind;
    mmi_abm_profile_query_rsp_struct *rsp  =  NULL;
    //static char *dest_name = {"cmnet"};

    LOGD(L_SOC, L_V5, "");
    ind = (mmi_abm_profile_query_ind_struct*) info;
    
    rsp  = (mmi_abm_profile_query_rsp_struct  *)construct_local_para(sizeof(mmi_abm_profile_query_rsp_struct), TD_RESET); 
    if(rsp != NULL)
    {
        rsp->account_id  = ind->account_id;//account_id;
        /*填入 MSG_ID_MMI_ABM_PROFILE_QUERY_IND 消息中的 account_id*/ 
        
        track_fun_strncpy((char *)rsp->content.ps_account_info.apn, apn_use.apn, MAX_GPRS_APN_LEN);
        track_fun_strncpy(rsp->content.user_name, apn_use.username, MAX_GPRS_USER_NAME_LEN);
        track_fun_strncpy(rsp->content.password, apn_use.password, MAX_GPRS_PASSWORD_LEN);
        rsp->content.ps_account_info.apn_length = strlen((char *)rsp->content.ps_account_info.apn);
        rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.hcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
        rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;                
        rsp->result = KAL_TRUE;
        
        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_PROFILE_QUERY_RSP, (void *)rsp, MOD_ABM);
    }
    else
    {
        LOGD(L_SOC, L_V1, "ERROR! 严重错误!");
        track_cust_restart(57, 0);
    }
}

void Socket_store_bearer_init_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_init_ind_struct *ind;
    mmi_abm_bearer_init_rsp_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_BEARER_INIT_IND_HDLR);
    LOGD(L_SOC, L_V6, "");
    ind = (mmi_abm_bearer_init_ind_struct*) info;
    rsp = (mmi_abm_bearer_init_rsp_struct *)construct_local_para(sizeof(mmi_abm_bearer_init_rsp_struct), TD_RESET);
    if(rsp != NULL)
    {
        rsp->ori_acct_id = ind->account_id;
        rsp->rel_acct_id = rsp->ori_acct_id & 0xFFFFFF00;
        LOGD(L_SOC, L_V5, "rel_acct_id=%d", rsp->rel_acct_id);
        rsp->bearer_type = CBM_PS;
        rsp->result = KAL_TRUE;
        rsp->cause = 0;
        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_BEARER_INIT_RSP, (void *)rsp, MOD_ABM);
    }
    else
    {
        LOGD(L_SOC, L_V1, "ERROR! 严重错误!");
        track_cust_restart(58, 0);
    }
}

/******************************************************************************
 *  Function    -  Socket_get_account_id
 *
 *  Purpose     -  account_id 查询
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint32 Socket_get_account_id()
{
    return track_account_id;
}

/******************************************************************************
 *  Function    -  track_socket_apn_auto_set
 *
 *  Purpose     -  判断是否自动设置APN
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_socket_apn_auto_set(void)
{
    LOGD(L_SOC, L_V4, "");
    if(G_importance_parameter_data.apn.custom_apn_valid && strlen(G_importance_parameter_data.apn.apn) > 0)
    {
        track_fun_strncpy(apn_use.apn, G_importance_parameter_data.apn.apn, MAX_GPRS_APN_LEN);
        track_fun_strncpy(apn_use.username, G_importance_parameter_data.apn.username, MAX_GPRS_USER_NAME_LEN);
        track_fun_strncpy(apn_use.password, G_importance_parameter_data.apn.password, MAX_GPRS_PASSWORD_LEN);
        LOGD(L_SOC, L_V4, "使用自定义 APN:%s, username:%s, password:%s", apn_use.apn, apn_use.username, apn_use.password);
    }
    else
    {
        track_custom_gprs_apn_struct *apn_cust = OTA_track_net_get_apn((char *)track_drv_get_imsi(0));
        if(apn_cust != NULL)
        {
            track_fun_strncpy(apn_use.apn, apn_cust->APN, MAX_GPRS_APN_LEN);
            track_fun_strncpy(apn_use.username, apn_cust->UserName, MAX_GPRS_USER_NAME_LEN);
            track_fun_strncpy(apn_use.password, apn_cust->Passwd, MAX_GPRS_PASSWORD_LEN);
            LOGD(L_SOC, L_V4, "使用自适应 APN:%s, username:%s, password:%s", apn_use.apn, apn_use.username, apn_use.password);
        }
        else
        {
            memset(&apn_use, 0, sizeof(nvram_GPRS_APN_struct));
            LOGD(L_SOC, L_V1, "使用自适应查找失败!");
        }
    }
}

/******************************************************************************
 *  Function    -  track_socket_apn_view
 *
 *  Purpose     -  当前APN查看
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 21-09-2013,  ZengPing  written
 * ----------------------------------------
*******************************************************************************/
char *track_socket_apn_view(void)
{
    static char tmp[200] = {0};
    if(G_importance_parameter_data.apn.custom_apn_valid && strlen(G_importance_parameter_data.apn.apn) > 0)
    {
        snprintf(tmp, 200, "Currently use APN:%s, UserName:%s, Password:%s\r\nCurrently set APN:%s, UserName:%s, Password:%s", 
            apn_use.apn, apn_use.username, apn_use.password,
            G_importance_parameter_data.apn.apn, G_importance_parameter_data.apn.username, G_importance_parameter_data.apn.password);
    }
    else
    {
        snprintf(tmp, 200, "Currently use APN:%s, UserName:%s, Password:%s\r\nCurrently set APN:%s, UserName:%s, Password:%s", 
            apn_use.apn, apn_use.username, apn_use.password,
            apn_use.apn, apn_use.username, apn_use.password);
    }
    return tmp;
}

/******************************************************************************
 *  Function    -  track_socket_get_use_apn
 *
 *  Purpose     -  返回当前使用的APN数据
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
nvram_GPRS_APN_struct *track_socket_get_use_apn(void)
{
    if(G_importance_parameter_data.apn.custom_apn_valid)
    {
        apn_use.custom_apn_valid = G_importance_parameter_data.apn.custom_apn_valid;
        track_fun_strncpy(apn_use.apn, G_importance_parameter_data.apn.apn, MAX_GPRS_APN_LEN);
        track_fun_strncpy(apn_use.username, G_importance_parameter_data.apn.username, MAX_GPRS_USER_NAME_LEN);
        track_fun_strncpy(apn_use.password, G_importance_parameter_data.apn.password, MAX_GPRS_PASSWORD_LEN);
        LOGD(L_SOC, L_V4, "使用自定义 APN:%s, username:%s, password:%s", apn_use.apn, apn_use.username, apn_use.password);
    }
    return &apn_use;
}

void track_socket_check_apn_diskdata()
{
    track_nvram_data_struct nvramdata = {0};
    nvram_GPRS_APN_struct *use_apn;
    kal_uint16 crc;
    kal_uint16 port;
    kal_uint8  server[100];
    kal_bool   valid = KAL_FALSE, ret;
    int va;

    ret = Track_nvram_read(DISK1_LAST_LID, 1, (kal_uint8 *)&nvramdata, sizeof(track_nvram_data_struct));
    //LOGD(L_SOC, L_V4, "%d, %p, %p, %d", ret, (kal_uint8 *)&nvramdata + 2, &nvramdata, sizeof(track_nvram_data_struct) - 2);
    crc = GetCrc16((kal_uint8 *)&nvramdata + 2, sizeof(track_nvram_data_struct) - 2);
    if(crc == nvramdata.crc)
        LOGD(L_SOC, L_V4, "CRC 校验匹配. (%X)", crc);
    else
        LOGD(L_SOC, L_V4, "CRC 校验不匹配. (%X,%X)", crc, nvramdata.crc);
    use_apn = track_socket_get_use_apn();
    LOGD(L_SOC, L_V4, "%d, (%s, %s, %s)", use_apn->custom_apn_valid, use_apn->apn, use_apn->username, use_apn->password);
    if(nvramdata.apn.custom_apn_valid != use_apn->custom_apn_valid
        || strcmp(nvramdata.apn.apn, use_apn->apn)
        || strcmp(nvramdata.apn.username, use_apn->username)
        || strcmp(nvramdata.apn.password, use_apn->password))
    {
        nvramdata.apn.custom_apn_valid = use_apn->custom_apn_valid;
        strncpy(nvramdata.apn.apn, use_apn->apn, MAX_GPRS_APN_LEN);
        strncpy(nvramdata.apn.username, use_apn->username, MAX_GPRS_USER_NAME_LEN);
        strncpy(nvramdata.apn.password, use_apn->password, MAX_GPRS_PASSWORD_LEN);
        LOGD(L_SOC, L_V4, "APN 数据发送变动.");
        valid = KAL_TRUE;
    }
    else
    {
        LOGD(L_SOC, L_V4, "APN 数据无改变.");
    }
    if(G_importance_parameter_data.server2.conecttype == 1)
    {
        char *domain = track_domain_decode(G_importance_parameter_data.server2.url);
        LOGD(L_APP, L_V5, "domain:%s", domain);
        snprintf(server, 100, "%s", domain);
    }
    else
    {
        snprintf(server, 100, "%d.%d.%d.%d", 
            G_importance_parameter_data.server2.server_ip[0],
            G_importance_parameter_data.server2.server_ip[1],
            G_importance_parameter_data.server2.server_ip[2],
            G_importance_parameter_data.server2.server_ip[3]);
    }
    port = G_importance_parameter_data.server2.server_port;
    if(strcmp(nvramdata.server, server) || nvramdata.port != port)
    {
        LOGD(L_SOC, L_V4, "SERVER 数据发生改变.(%s)%d,(%s)%d", nvramdata.server, nvramdata.port, server, port);
        strncpy(nvramdata.server, server, 100);
        nvramdata.port = port;
        valid = KAL_TRUE;
    }
    else
    {
        LOGD(L_SOC, L_V4, "SERVER 数据无改变.");
    }
    if(valid)
    {
        nvramdata.crc = GetCrc16((kal_uint8 *)&nvramdata + 2, sizeof(track_nvram_data_struct) - 2);
        LOGD(L_SOC, L_V4, "crc:%X, %d", nvramdata.crc, sizeof(track_nvram_data_struct));
        LOGH(L_SOC, L_V7, &nvramdata, sizeof(track_nvram_data_struct));
        Track_nvram_write(DISK1_LAST_LID, 1, (kal_uint8*)&nvramdata, sizeof(track_nvram_data_struct));
    }
}

