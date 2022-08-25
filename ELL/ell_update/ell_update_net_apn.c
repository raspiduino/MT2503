/*******************************************************************************************
 *
 * Filename:
 * Author :
 * Date :
 * Comment:
 *
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "ell_update.h"
#include "ell_update_net_apn.h"
#include "flash_disk_internal.h"
#include "custom_config_account.h"
#include "flash_opt.h"
#include "ell_fota_memory_define.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static U32 vs_account_id = 0;
static nvram_GPRS_APN_struct ell_use_apn = {0};
static ell_nvram_data_struct ell_data = {0};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern track_custom_gprs_apn_struct *track_net_get_apn(char *imsi);

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#if Global_Functions
#endif /* 0 */
U32 ell_get_vs_account_id(void)
{
    return vs_account_id;
}

static void srv_dtcnt_db_store_send_msg(kal_uint16 msg_id, void *req, int mod_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = (module_type)mod_dst;
    ilm_send->sap_id = MMI_ABM_SAP;
    ilm_send->msg_id = (msg_type) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) req;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_send);
}

void ell_socket_apn_auto_set(void)
{
    kal_int32 result;
    kal_uint16 crc;
    extern NOR_FLASH_DISK_Data FlashDiskDriveData[NOR_BOOTING_NOR_DISK_NUM];

    result = readRawDiskData(&FlashDiskDriveData[1], DISK1_LAST_SECTOR_ADD, (kal_uint8*)&ell_data, sizeof(ell_nvram_data_struct));
    crc = ell_GetCrc16((kal_uint8 *)&ell_data + 2, sizeof(ell_nvram_data_struct) - 2);
    EllLog("%X,%X, %d, %d, Server:%s,%d", crc, ell_data.crc, ell_data.apn.custom_apn_valid, sizeof(ell_nvram_data_struct), ell_data.server, ell_data.port);
    if(crc == ell_data.crc && ell_data.apn.custom_apn_valid)
    {
        strncpy(ell_use_apn.apn, ell_data.apn.apn, MAX_GPRS_APN_LEN);
        strncpy(ell_use_apn.username, ell_data.apn.username, MAX_GPRS_USER_NAME_LEN);
        strncpy(ell_use_apn.password, ell_data.apn.password, MAX_GPRS_PASSWORD_LEN);
        EllLog("(1) APN:%s, username:%s, password:%s", ell_use_apn.apn, ell_use_apn.username, ell_use_apn.password);
    }
    else
    {
        track_custom_gprs_apn_struct *apn_cust = track_net_get_apn((char *)ell_read_imsi_data());
        if(apn_cust != NULL)
        {
            strncpy(ell_use_apn.apn, apn_cust->APN, MAX_GPRS_APN_LEN);
            strncpy(ell_use_apn.username, apn_cust->UserName, MAX_GPRS_USER_NAME_LEN);
            strncpy(ell_use_apn.password, apn_cust->Passwd, MAX_GPRS_PASSWORD_LEN);
            EllLog("(2) APN:%s, username:%s, password:%s", ell_use_apn.apn, ell_use_apn.username, ell_use_apn.password);
        }
        else
        {
            memset(&ell_use_apn, 0, sizeof(nvram_GPRS_APN_struct));
            EllLog("() error");
        }
    }
}

ell_nvram_data_struct *ell_get_datadisk(void)
{
    return &ell_data;
}

/******************************************************************************
 *  Function    -  ell_update_socket_apn_init
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
void ell_update_socket_apn_init()
{
    static U8 vs_app_id;
    cbm_app_info_struct app_info = {0};
    S8 s;
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    info_req = (mmi_abm_update_account_info_req_struct *) construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
    if(info_req == NULL)
    {
        EllLog("ERROR! 严重错误!");
    }
    info_req->action = MMI_ABM_PROFILE_ADD;
    info_req->account_id = 0x00017e00;
    info_req->bearer_type = CBM_PS; //bearer 的类型为 GPRS
    srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);

    app_info.app_icon_id = 0;
    app_info.app_str_id = 0;
    app_info.app_type = DTCNT_APPTYPE_MRE_NET;
    s = cbm_register_app_id_with_app_info(&app_info, &vs_app_id);
    vs_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, vs_app_id, KAL_FALSE);
    EllLog("APN 设置 ret=%d, xzx_account_id=%d", s, vs_account_id);
}

void ell_update_Socket_prof_query_ind_hdlr(void *info)
{
    mmi_abm_profile_query_ind_struct *ind;
    mmi_abm_profile_query_rsp_struct *rsp  =  NULL;
    //static char *dest_name = {"cmnet"};

    EllLog("");
    ind = (mmi_abm_profile_query_ind_struct*) info;

    rsp  = (mmi_abm_profile_query_rsp_struct  *)construct_local_para(sizeof(mmi_abm_profile_query_rsp_struct), TD_RESET);
    if(rsp != NULL)
    {
        rsp->account_id  = ind->account_id;//account_id;
        /*填入 MSG_ID_MMI_ABM_PROFILE_QUERY_IND 消息中的 account_id*/

        //track_fun_strncpy((char *)rsp->content.ps_account_info.apn, g_data.ps_account_info.apn, MAX_GPRS_APN_LEN);
        strncpy((char *)rsp->content.ps_account_info.apn, ell_use_apn.apn, MAX_GPRS_APN_LEN);
        rsp->content.ps_account_info.apn_length = strlen((char *)rsp->content.ps_account_info.apn);
        strncpy(rsp->content.user_name, ell_use_apn.username, MAX_GPRS_USER_NAME_LEN);
        strncpy(rsp->content.password, ell_use_apn.password, MAX_GPRS_PASSWORD_LEN);
        rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.hcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
        rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;
        rsp->result = KAL_TRUE;

        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_PROFILE_QUERY_RSP, (void *)rsp, MOD_ABM);
    }
    else
    {
        EllLog("ERROR! 严重错误!");
    }
}

void ell_update_Socket_store_bearer_init_ind_hdlr(void *info)
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
    EllLog("");
    ind = (mmi_abm_bearer_init_ind_struct*) info;
    rsp = (mmi_abm_bearer_init_rsp_struct *)construct_local_para(sizeof(mmi_abm_bearer_init_rsp_struct), TD_RESET);
    if(rsp != NULL)
    {
        rsp->ori_acct_id = ind->account_id;
        rsp->rel_acct_id = rsp->ori_acct_id & 0xFFFFFF00;
        EllLog("rel_acct_id=%d", rsp->rel_acct_id);
        rsp->bearer_type = CBM_PS;
        rsp->result = KAL_TRUE;
        rsp->cause = 0;
        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_BEARER_INIT_RSP, (void *)rsp, MOD_ABM);
    }
    else
    {
        EllLog("ERROR! 严重错误!");
    }
}

