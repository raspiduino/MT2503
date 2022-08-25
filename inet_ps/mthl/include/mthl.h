
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"      
#include "syscomp_config.h"
#include "task_config.h"  
//#include "mmi_frm_history_gprot.h"
//#include "mmi_rp_srv_mms_def.h"
#include "fs_func.h"
#include "common_nvram_editor_data_item.h "
#include "cbm_api.h"
#include "Mmi2abm_struct.h"
#include "Mmi_l3_enums.h"
#include "Abm_main.h"
#include "Abm_util.h"
#include "mthl_struct.h"

#if defined (__WIFI_SUPPORT__) && defined (__WIFI_TCPIP_AT_SUPPORT__) 
#include "DtcntSrvIprot.h"
#endif


typedef struct
{
    kal_uint32              account_id;
	kal_uint32              nwk_acct_id;
    pdp_addr_type_enum      pdp_type;        /*pdp_type_enum*/
    kal_uint8               apn_length;
    kal_uint8               apn [ MAX_APN_LEN ];
    kal_uint16              proxy_port;       
    kal_uint8               proxy_addr[ MAX_PDP_ADDR_LEN ];
	kal_uint8               proxy_flags;
	custom_dtcnt_prof_auth_struct Auth_info;       /* authentication info */
	pdp_bear_op_enum                 bear_op;
    kal_uint32              user_data;
}mthl_create_pdp_param_save_struct;


void mthl_send_msg_to_abm(kal_uint16 msg_id, void *req, int mod_dst);
