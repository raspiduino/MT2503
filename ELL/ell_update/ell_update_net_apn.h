#ifndef _ELL_UPDATE_NET_APN_H
#define _ELL_UPDATE_NET_APN_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "cbm_consts.h"
#include "ps_public_enum.h"
#include "cbm_api.h"
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/
typedef enum
{
    MMI_ABM_PROFILE_ADD,
    MMI_ABM_PROFILE_MODIFY,
    MMI_ABM_PROFILE_DEL,
    MMI_ABM_PROFILE_ACT_TOTAL
} mmi_abm_profile_update_act_enum;

typedef enum
{
    MMI_ABM_BEARER_STATE_INIT,
    MMI_ABM_BEARER_STATE_REINIT,
    MMI_ABM_BEARER_STATE_TOTAL
} mmi_abm_bearer_state_enum;

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_uint8                         ref_count;
    kal_uint16                        msg_len;
    kal_uint32                        account_id;
    mmi_abm_bearer_state_enum         state;
} mmi_abm_bearer_init_ind_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          ori_acct_id;
    kal_uint32          rel_acct_id;
    kal_bool            result;
    cbm_bearer_enum     bearer_type;
    kal_int32           cause;
} mmi_abm_bearer_init_rsp_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          account_id;
} mmi_abm_profile_query_ind_struct;

typedef struct
{
    kal_uint8 addr_str[23];
    kal_uint8 csd_ur;
    kal_uint8 csd_type;
    kal_uint8 csd_module;
} csd_account_info_struct;

typedef struct
{
    kal_uint8 apn[MAX_GPRS_APN_LEN];
    kal_uint8 apn_length;
    kal_uint8 dcomp_algo; // Fixed value: SND_NO_DCOMP
    kal_uint8 hcomp_algo; // Fixed value: SND_NO_PCOMP
    kal_uint8 pdp_type; // Fixed value: IPV4_ADDR_TYPE 0x21 for IPv4
    kal_uint8 pdp_addr_len; // Fixed value: NULL_PDP_ADDR_LEN = 0x01, if use fixed IP address, this should be IPV4_ADDR_LEN = 0x04
    kal_uint8 pdp_addr_val[MAX_GPRS_IP_ADDR]; // should be all 0
} ps_account_info_struct;

typedef struct
{
    kal_uint8 authentication_type;
    kal_uint8 user_name[MAX_GPRS_USER_NAME_LEN];
    kal_uint8 password[MAX_GPRS_PASSWORD_LEN];
    kal_uint8 dns[MAX_GPRS_IP_ADDR];
    kal_uint8 sec_dns[MAX_GPRS_IP_ADDR];
    ps_account_info_struct ps_account_info;
    csd_account_info_struct csd_account_info;
} mmi_abm_account_info_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  account_id;
    mmi_abm_account_info_struct content;
    kal_bool                    result;
} mmi_abm_profile_query_rsp_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32          account_id;
    mmi_abm_profile_update_act_enum action;
    cbm_bearer_enum     bearer_type;
} mmi_abm_update_account_info_req_struct;

typedef struct
{
    kal_uint8  bearer_type; /* GPRS or CSD */
    kal_uint8  sim_id;
    kal_uint8  call_id;
    kal_uint8  context_id;
    kal_uint8  query_number;
} mmi_abm_dialup_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint64 recv_data_size;    
    kal_uint64 send_data_size;
    kal_uint64 conn_duration_in_secs;
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dailup_info;
    cbm_bearer_state_enum  status;
    cbm_bearer_enum bearer_type;
    kal_uint8  connect_type;
} mmi_abm_bearer_info_ind_struct;

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/



#endif  /* _ELL_UPDATE_NET_APN_H */

