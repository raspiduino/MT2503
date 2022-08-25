#ifdef __BT_GATTC_PROFILE__ 

/****************************************************************************
* header files
****************************************************************************/
//#include "mmi_frm_events_gprot.h"
#include "comm_post_event.h"
#include "bcm_GattcSrv.h"
//#include "MMI_conn_app_trc.h" 
//#include "MMI_trc_Int.h"
//#include "mmi_rp_srv_gatt_def.h"
#include "bcmadp.h"
#include "bcm_trc.h"
#include "bluetooth_gap_message.h"
#include "bluetooth_gap_struct.h"
#include "bcm_event_handler.h"


#ifdef __MMI_BLE_LOW_POWER__
#define  GATTC_SET_CONN_INTERVAL_TIME        (1000 * 30)
#define  GATTC_CONN_UPDATE_TIMER_OUT         (1000 * 30)
#define  PROFILE_ID_REMOTE_SRV_CHANGE        (0xFE)
#define  GATTC_BD_ADDR_SIZE                  (6)
#define  MAX_LE_DEVICE                       (4)

static S32 srv_gattc_get_link_context_by_addr(char *bt_addr);
static void srv_gattc_reset_all_link_context(void);
void srv_gattc_conn_param_interval_reset(void);
static void srv_gattc_conn_param_update_req_send(char *bd_addr, CONN_PRIO_ENUM connectionPriority);
void srv_gattc_conn_param_update_req_retry(void* arg);
static U32 srv_gattc_get_conn_updated_profile_num(gattc_conn_prio_struct *conn_info);
static void srv_gattc_conn_update_complete_ind(void *msg);
static S32 srv_gattc_conn_param_is_updating(char *bt_addr);
extern void srv_gattc_conn_param_interval_reset_bcm_adp(void *data);
extern void srv_gattc_conn_param_update_req_retry_bcm_adp(void *data,void *arg);
static gattc_adv_interval_enum g_srv_gattc_curr_adv = GATTC_ADV_INTERVAL_DEFAULT;
static gattc_conn_param_struct conn_para_info[MAX_LE_DEVICE] = {0};
//static CONN_PRIO_ENUM g_srv_gattc_curr_conn_priority[MAX_LE_DEVICE] = {0};
static U8 gattc_bdaddr[GATTC_BD_ADDR_SIZE] = {0};
gattc_conn_param_struct conn_update_param;


/*add for low power*/
//#ifdef __MMI_BLE_LOW_POWER__
/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_interval_cnf
 * DESCRIPTION
 *  This function is to handle adv interval setting confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gattc_set_adv_interval_cnf(void *msg)
{
    bt_gattc_set_adv_param_cnf_struct *cnf = (bt_gattc_set_adv_param_cnf_struct *)msg;

    if (!cnf)
    {
        return;
    }

    if (cnf->result != 0)
    {
        g_srv_gattc_curr_adv = GATTC_ADV_INTERVAL_DEFAULT;
		//kal_prompt_trace(MOD_BT, "[GATTCSRV]srv_gattc_set_adv_interval_cnf() result = %d !\n", cnf->result);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_SET_ADV_CNF, cnf->result);
    } 
	SetProtocolEventHandler(NULL, MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_interval
 * DESCRIPTION
 *  send advertise interval to client
 * PARAMETERS
 *  profile_id              [IN]        
 *  adv_interval          [IN]   
 *          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_set_adv_interval(U32 profile_id, gattc_adv_interval_enum adv_interval)
{

    bt_gattc_set_adv_param_req_struct *req;

#if defined (__BLE_DEBUG_LOG__)		    
//-------------------------------------------------------------
		    {
		    //验证补丁添加的代码  chengjun  2017-05-18
		    char testLog[128] = {0};
		    sprintf(testLog, "srv_gattc_set_adv_interval %d,%d\r\n",profile_id,adv_interval);
		    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
		    }
    		//-------------------------------------------------------------
#endif   
    
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_SET_ADV_REQ, profile_id, g_srv_gattc_curr_adv, adv_interval);
	
	if (g_srv_gattc_curr_adv == adv_interval) 
	{
		return;
	}
	g_srv_gattc_curr_adv = adv_interval;

    req = (bt_gattc_set_adv_param_req_struct*)construct_local_para(sizeof(bt_gattc_set_adv_param_req_struct), TD_CTRL);    
	
	switch (adv_interval)
	{
	   case GATTC_ADV_INTERVAL_FAST_CONN:
	   {
		   req->min_interval = 0xC0;/*192 * 0.625 ms = 120ms*/
		   req->max_interval = 0xC0;/*192 * 1.25 ms = 120ms*/
		   break;

	   }
		   
	   case GATTC_ADV_INTERVAL_REDUCE_POWER:
	   {
#if defined(__NF2318__)
		req->min_interval = 0x0140;/*320* 0.625 ms = 200ms*/
		req->max_interval = 0x0140;/*320* 0.625 ms = 200ms*/
#else
		   req->min_interval = 0x0320;/*800* 0.625 ms = 500ms*/
		   req->max_interval = 0x07D0;/*2000* 0.625 ms = 1250ms*/
#endif
		   break;
	   }			   
	   default:
	   {

		   req->min_interval = 0x0320;/*800* 0.625 ms = 500ms*/
		   req->max_interval = 0x07D0;/*2000* 0.625 ms = 1250ms*/

	   }
		   break;
	}

    req->MaskBit = 0x03;
	SetProtocolEventHandler(srv_gattc_set_adv_interval_cnf, MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF);
	
    gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SET_ADV_PARAM_REQ, (void*)req);  
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_conn_priority
 * DESCRIPTION
 *  This function is to get the interval mode of one link
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static CONN_PRIO_ENUM srv_gattc_get_conn_priority(gattc_conn_prio_struct *conninfo)
{
	U32 i;
	U32 high_num = 0, balance_num = 0, low_num = 0;

	for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
	{
		if (0 != conninfo->high_speed[i])
		{
		    high_num ++;
		}
		if (0 != conninfo->balance[i])
		{
			balance_num ++;
		}
		if (0 != conninfo->low_power[i])
		{
			low_num++;
		}
	}
	if (high_num != 0)
	{
		return CONNECTION_PRIORITY_HIGH_SPEED;
	}
	else if (balance_num != 0)
	{
		return CONNECTION_PRIORITY_BALANCE;
	}
	else if (low_num != 0)
	{
		return CONNECTION_PRIORITY_LOW_POWER;
	}

	return CONNECTION_PRIORITY_DEFAULT;	
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_conn_priority
 * DESCRIPTION
 *  This function is to set the interval mode of one link
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gattc_set_conn_priority(gattc_conn_prio_struct *conn_info, U32 app_id, CONN_PRIO_ENUM conn_priority)
{
	U32 i,j,index = 0;

	switch(conn_priority)
	{
		case CONNECTION_PRIORITY_HIGH_SPEED:
		{
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
			    index ++;
			    if (app_id == conn_info->high_speed[i])
			    {
					conn_info->high_speed[i] = app_id;
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_HIGH, i);
					break;
				}
			}
			if (index == GATT_SRV_MAX_PROFILE_NUM)
			{
				for(j = 0; j < GATT_SRV_MAX_PROFILE_NUM; j++)
				{
					if (0 == conn_info->high_speed[j])
					{
						conn_info->high_speed[j] = app_id;
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_HIGH_FIRST, j);
						break;
					}
				}
			}
			
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
				if (app_id == conn_info->balance[i])
				{
					conn_info->balance[i] = 0;
				}
				if (app_id == conn_info->low_power[i])
				{
					conn_info->low_power[i] = 0;
				}
				
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_BUFFER_RESET);
			}
		}
			break;
			
		case CONNECTION_PRIORITY_BALANCE:
		{
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
			    index ++;
			    if (app_id == conn_info->balance[i])
			    {
					conn_info->balance[i] = app_id;
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_BALANCE, i);
					break;
				}
			}
			if (index == GATT_SRV_MAX_PROFILE_NUM)
			{
				for(j = 0; j < GATT_SRV_MAX_PROFILE_NUM; j++)
				{
					if (0 == conn_info->balance[j])
					{
						conn_info->balance[j] = app_id;
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_BALANCE_FIRST, j);
						break;
					}
				}

			}
			
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
				if (app_id == conn_info->high_speed[i])
				{
					conn_info->high_speed[i] = 0;
				}
				if (app_id == conn_info->low_power[i])
				{
					conn_info->low_power[i] = 0;
				}
				
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_BUFFER_RESET);
			}
		}
			break;
		case CONNECTION_PRIORITY_LOW_POWER:
		case CONNECTION_PRIORITY_DEFAULT:
		{
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
			    index ++;
			    if (app_id == conn_info->low_power[i])
			    {
					conn_info->low_power[i] = app_id;
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_LOW, i);
					break;
				}
			}
			if (index == GATT_SRV_MAX_PROFILE_NUM)
			{
				for(j = 0; j < GATT_SRV_MAX_PROFILE_NUM; j++)
				{
					if (0 == conn_info->low_power[j])
					{
						conn_info->low_power[j] = app_id;
						
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_PROFILE_EXIST_IN_LOW_FIRST, j);
						break;
					}
				}

			}
			for(i = 0; i < GATT_SRV_MAX_PROFILE_NUM; i++)
			{
				if (app_id == conn_info->high_speed[i])
				{
					conn_info->high_speed[i] = 0;
				}
				if (app_id == conn_info->balance[i])
				{
					conn_info->balance[i] = 0;
				}
				
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_BUFFER_RESET);
			}
		}
			break;
			
		default:
			break;
	}
		
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update_cnf
 * DESCRIPTION
 *  This function is to handle conn interval update confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_conn_param_update_cnf(void *msg)
{
    bt_gattc_conn_param_update_cnf_struct *cnf = (bt_gattc_conn_param_update_cnf_struct *)msg;

    if (!cnf)
    {
        return;
    }

    if (cnf->result != 0)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_SET_CONN_CNF, cnf->result);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_update_complete_ind
 * DESCRIPTION
 *  This function is to handle conn interval update complete message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gattc_conn_update_complete_ind(void *msg)
{
    bt_le_connect_update_complete_struct *cnf = (bt_le_connect_update_complete_struct *)msg;
	
	StopTimer(GATTC_CONN_UPDATE_TIMER_OUT_ID);

    if (!cnf)
    {
        return;
    }

    if (cnf->status == 0)
    {
		CONN_PRIO_ENUM priority_req;
    	S32 link_index = srv_gattc_get_link_context_by_addr((char *)cnf->bdaddr);
		if (cnf->interval == 0x0010)
		{
			conn_para_info[link_index].conn_info.curr_priority = CONNECTION_PRIORITY_HIGH_SPEED;
		}
		else if ((cnf->interval >= 0x0010) && (cnf->interval <= 0x0020))
		{
			conn_para_info[link_index].conn_info.curr_priority = CONNECTION_PRIORITY_BALANCE;
		}
		else if ((cnf->interval >= 0x0120) && (cnf->interval <= 0x0130))
		{
			conn_para_info[link_index].conn_info.curr_priority = CONNECTION_PRIORITY_LOW_POWER;
		
		}
		else
		{
			conn_para_info[link_index].conn_info.curr_priority = CONNECTION_PRIORITY_DEFAULT;
		}
		conn_para_info[link_index].is_confirmed = TRUE;
		priority_req = srv_gattc_get_conn_priority(&conn_para_info[link_index].conn_info);
		if (conn_para_info[link_index].conn_info.curr_priority != priority_req)
		{
			conn_para_info[link_index].is_confirmed = FALSE;
			srv_gattc_conn_param_update_req_send(cnf->bdaddr, priority_req);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_UPDATE, link_index,
				996, 
				priority_req, 
				conn_para_info[link_index].conn_info.curr_priority);

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
		#endif
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_SET_CONN_CNF, cnf->status);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_conn_updated_profile_num
 * DESCRIPTION
 *  This function is to get the whole profiles numble of one link
 * PARAMETERS
 *  conn_info     [IN]  link info structure
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_gattc_get_conn_updated_profile_num(gattc_conn_prio_struct *conn_info)
{
	U32 j;
	U32 high_num = 0, balance_num = 0, low_num = 0;
	
	for(j = 0; j < GATT_SRV_MAX_PROFILE_NUM; j++)
	{
		if (0 != conn_info->high_speed[j])
		{
			high_num++;
		}
		if (0 != conn_info->balance[j])
		{
			balance_num++;
		}
		if (0 != conn_info->low_power[j])
		{
			low_num++;
		}
	}
	return (high_num + balance_num + low_num);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_RESET_ALL_LINKS, high_num, balance_num, low_num);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_reset_all_link_context
 * DESCRIPTION
 *  This function is to reset the info structure of connection link
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gattc_reset_all_link_context(void)
{
	U32 i,j;
	U32 high_num = 0, balance_num = 0, low_num = 0;
	
	for(i = 0; i < MAX_LE_DEVICE; i++)
	{
		for(j = 0; j < GATT_SRV_MAX_PROFILE_NUM; j++)
		{
			if (0 != conn_para_info[i].conn_info.high_speed[j])
			{
				high_num++;
			}
			if (0 != conn_para_info[i].conn_info.balance[j])
			{
				balance_num++;
			}
			if (0 != conn_para_info[i].conn_info.low_power[j])
			{
				low_num++;
			}
		}
		if (high_num + balance_num + low_num == 0)
		{
			memset(&conn_para_info[i],0x00, sizeof(gattc_conn_param_struct));
		}
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_RESET_ALL_LINKS, high_num, balance_num, low_num);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_link_context_by_addr
 * DESCRIPTION
 *  This function is to get one link by bt adress
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_gattc_conn_param_is_updating(char *bt_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (!bt_addr)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_NULL);
		return -2;// -2 means error code
	}
	
	for(i = 0; i < MAX_LE_DEVICE; i++)
	{
		if (memcmp(bt_addr, conn_para_info[i].bd_addr, BD_ADDR_SIZE) == 0)
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_EXISTED, i);
			return i;
		}
	}
	return -1;// -1 means error code
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_link_context_by_addr
 * DESCRIPTION
 *  This function is to get one link by bt adress
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_gattc_get_link_context_by_addr(char *bt_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i, j;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (!bt_addr)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_NULL);
		return -2;// 100 means error code
	}
	
	for(i = 0; i < MAX_LE_DEVICE; i++)
	{
		if (memcmp(bt_addr, conn_para_info[i].bd_addr, BD_ADDR_SIZE) == 0)
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_EXISTED, i);
			return i;
		}
	}

    for(j = 0; j < MAX_LE_DEVICE; j++)
	{
	    U8 base_addr[BD_ADDR_SIZE] = {0};
		if (memcmp(base_addr, conn_para_info[j].bd_addr, BD_ADDR_SIZE) == 0)
		{
			memcpy(conn_para_info[j].bd_addr, bt_addr, BD_ADDR_SIZE);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_FIRST_EXIST, j);
			return j;
		}
	}
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_SPACE_FULL);
	return -1;//error code 2
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update_req_retry
 * DESCRIPTION
 *  retry to send connection interval to client when last one fail
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_conn_param_update_req_retry(void* arg)
{
	CONN_PRIO_ENUM priority_req;
	gattc_conn_param_struct *update_info = (gattc_conn_param_struct *)arg;
	S32 link_index = srv_gattc_get_link_context_by_addr((char *)update_info->bd_addr);

	StopTimer(GATTC_CONN_UPDATE_TIMER_OUT_ID);
	priority_req = srv_gattc_get_conn_priority(&conn_para_info[link_index].conn_info);
	if (conn_para_info[link_index].conn_info.curr_priority != priority_req)
	{
		conn_para_info[link_index].is_confirmed = FALSE;
		srv_gattc_conn_param_update_req_send(update_info->bd_addr, priority_req);

		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_UPDATE, link_index,
			999, 
			priority_req, 
			conn_para_info[link_index].conn_info.curr_priority);

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
	#endif
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update_req_send
 * DESCRIPTION
 *  send connection interval to client
 * PARAMETERS
 *  bd_addr              [IN]   remote device's address           
 *  connectionPriority   [IN]  if need high transfer speed, please pass CONNECTION_PRIORITY_HIGH_SPEED; 
 *              if need Low power, please pass CONNECTION_PRIORITY_LOW_POWER;default:CONNECTION_PRIORITY_LOW_POWER
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gattc_conn_param_update_req_send(char *bd_addr, CONN_PRIO_ENUM connectionPriority)
{
    bt_gattc_conn_param_update_req_struct *req;
	S32 link_index;
	
    req = (bt_gattc_conn_param_update_req_struct*)
                construct_local_para(sizeof(bt_gattc_conn_param_update_req_struct), TD_CTRL);   

    if (req)
    {
	    memcpy(req->bd_addr, bd_addr, BD_ADDR_SIZE);
        req->timeout = 0x0258; /*600 * 10 ms*/
        req->MaskBit = 0x0F;

		switch (connectionPriority)
		{
			case CONNECTION_PRIORITY_HIGH_SPEED:
			{
				req->min_interval = 0x0010;/*16 * 1.25 ms*/
		        req->max_interval = 0x0010;/*16 * 1.25 ms*/
				req->latency = 0;
			}
				break;
			case CONNECTION_PRIORITY_BALANCE:
			{
				req->min_interval = 0x0010;/*16* 1.25 ms*/
				req->max_interval = 0x0020;/*32* 1.25 ms*/
				req->latency = 0;
			}
				break;
			case CONNECTION_PRIORITY_LOW_POWER:
			{
				req->min_interval = 0x0120;/*288* 1.25 ms*/
				req->max_interval = 0x0130;/*304 * 1.25 ms*/
				req->latency = 4;
			}
				break;
			default:
			{
				req->min_interval = 0x0120;/*288* 1.25 ms*/
				req->max_interval = 0x0130;/*304 * 1.25 ms*/

				req->latency = 4;
			}
				break;
		}
		
		link_index = srv_gattc_get_link_context_by_addr(bd_addr);
		//memset(&conn_update_param, 0x00, sizeof(gattc_conn_param_struct));
		//memcpy(&conn_update_param.bd_addr, bd_addr, sizeof(bd_addr));
		
		SetProtocolEventHandler(srv_gattc_conn_param_update_cnf, MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF);
		SetProtocolEventHandler(srv_gattc_conn_update_complete_ind, MSG_ID_BT_LE_CONNECT_UPDATE_COMPLETE_IND);
		gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_REQ, (void*)req);
		StartTimerEx(GATTC_CONN_UPDATE_TIMER_OUT_ID, 
			GATTC_CONN_UPDATE_TIMER_OUT, 
			srv_gattc_conn_param_update_req_retry, 
			(void *)&conn_para_info[link_index]);

		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_UPDATE, link_index,
			998, 
			connectionPriority, 
			conn_para_info[link_index].conn_info.curr_priority);

	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update
 * DESCRIPTION
 *  send connection interval to client
 * PARAMETERS
 *  profile_id              [IN]  please see gattprofilesrvdeclaration.c    
 *  bd_addr              [IN]   remote device's address           
 *  connectionPriority   [IN]  if need high transfer speed, please pass CONNECTION_PRIORITY_HIGH_SPEED; 
 *              if need Low power, please pass CONNECTION_PRIORITY_LOW_POWER;default:CONNECTION_PRIORITY_LOW_POWER
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_conn_param_update(U32 profile_id, char *bd_addr, CONN_PRIO_ENUM connectionPriority)
{
    bt_gattc_conn_param_update_req_struct *req;
	S32 link_index = 0;

	if (!bd_addr)
    {
        return;
    }

#if defined (__BLE_DEBUG_LOG__)	
		    //-------------------------------------------------------------
		    {
		    //验证补丁添加的代码  chengjun  2017-05-18
		    char testLog[128] = {0};
		    sprintf(testLog, "srv_gattc_conn_param_update %d,%d\r\n",profile_id,connectionPriority);
		    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
		    }
    		//-------------------------------------------------------------
#endif
    
	srv_gattc_reset_all_link_context();

	link_index = srv_gattc_get_link_context_by_addr(bd_addr);
	if (link_index < MAX_LE_DEVICE)
	{
		CONN_PRIO_ENUM priority_req;
		U32 profile_num = 0;
		srv_gattc_set_conn_priority(&conn_para_info[link_index].conn_info, profile_id, connectionPriority);
		priority_req = srv_gattc_get_conn_priority(&conn_para_info[link_index].conn_info);
		conn_para_info[link_index].set_times++;
		//profile_num = srv_gattc_get_conn_updated_profile_num(&conn_para_info[link_index].conn_info);

		if ((conn_para_info[link_index].conn_info.curr_priority != priority_req) && 
			((conn_para_info[link_index].set_times == 1) || (conn_para_info[link_index].is_confirmed)))
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_UPDATE, link_index,
				profile_id, 
				priority_req, 
				conn_para_info[link_index].conn_info.curr_priority);
			
			conn_para_info[link_index].is_confirmed = FALSE;
			srv_gattc_conn_param_update_req_send(bd_addr, priority_req);
		}	
	}
	else
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_UPDATE_ERROR);
		return;
	}
}

void srv_gattc_conn_param_interval_reset(void)
{
	StopTimer(GATTC_SET_CONN_INTERVAL_TIMER_ID);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_INTERVAL_RESET_OK);
	srv_gattc_conn_param_update(PROFILE_ID_REMOTE_SRV_CHANGE, (char *)gattc_bdaddr, CONNECTION_PRIORITY_LOW_POWER); 
}

//#endif /* __MMI_BLE_LOW_POWER__*/
/*add for low power end*/



/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_param_cnf
 * DESCRIPTION
 *  This function is to handle adv interval setting confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gatt_set_adv_param_cnf(void *msg)
{
    //bcm_gatt_set_adv_param_cnf_struct *bcm_cnf;
    bt_gattc_set_adv_param_cnf_struct *cnf = (bt_gattc_set_adv_param_cnf_struct *)msg;

    if (!cnf)
    {
        return;
    }

    if (cnf->result != 0)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_SET_ADV_CNF, cnf->result);
    } 
	
	SetProtocolEventHandler(NULL, MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatt_set_adv_param
 * DESCRIPTION
 *  send advertise interval to client
 * PARAMETERS
 *  profile_id              [IN]        
 *  adv_interval          [IN]   
 *          
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatt_set_adv_param_req(U16 min_interval, U16 max_interval)
{

    bt_gattc_set_adv_param_req_struct *req;

#if defined (__BLE_DEBUG_LOG__)	
		    //-------------------------------------------------------------
		    {
		    //验证补丁添加的代码  chengjun  2017-05-18
		    char testLog[128] = {0};
		    sprintf(testLog, "srv_gatt_set_adv_param_req %d,%d\r\n",min_interval,max_interval);
		    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
		    }
    		//-------------------------------------------------------------
#endif
            
    req = (bt_gattc_set_adv_param_req_struct*)construct_local_para(sizeof(bt_gattc_set_adv_param_req_struct), TD_CTRL);    

    req->min_interval = min_interval;/*192 * 0.625 ms = 120ms*/
    req->max_interval = max_interval;/*192 * 1.25 ms = 120ms*/
	
    req->MaskBit = 0x03;
	SetProtocolEventHandler(srv_gatt_set_adv_param_cnf, MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF);
    gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SET_ADV_PARAM_REQ, (void*)req);  
}


/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_update_complete_ind
 * DESCRIPTION
 *  This function is to handle conn interval update complete message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gatt_conn_update_complete_ind(void *msg)
{
    bt_le_connect_update_complete_struct *cnf = (bt_le_connect_update_complete_struct *)msg;
	

    if (!cnf)
    {
        return;
    }

    if (cnf->status != 0)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATT_CONN_UPDATE_IND, cnf->status);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_conn_param_update_cnf
 * DESCRIPTION
 *  This function is to handle conn interval update confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_gatt_conn_param_update_cnf(void *msg)
{
    bt_gattc_conn_param_update_cnf_struct *cnf = (bt_gattc_conn_param_update_cnf_struct *)msg;

    if (!cnf)
    {
        return;
    }

    if (cnf->result != 0)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATT_CONN_UPDATE_CNF, cnf->result);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatt_conn_param_update_req
 * DESCRIPTION
 *  send connection interval to client
 * PARAMETERS
 *  bd_addr              [IN]   remote device's address           
 *  connectionPriority   [IN]  if need high transfer speed, please pass CONNECTION_PRIORITY_HIGH_SPEED; 
 *              if need Low power, please pass CONNECTION_PRIORITY_LOW_POWER;default:CONNECTION_PRIORITY_LOW_POWER
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatt_conn_param_update_req(char *bd_addr, U16 min_interval, U16 max_interval, U16 timeout, U16 latency)
{
    bt_gattc_conn_param_update_req_struct *req;
	
    req = (bt_gattc_conn_param_update_req_struct*)
                construct_local_para(sizeof(bt_gattc_conn_param_update_req_struct), TD_CTRL);   

#if defined (__BLE_DEBUG_LOG__)	
		    //-------------------------------------------------------------
		    {
		    //验证补丁添加的代码  chengjun  2017-05-18
		    char testLog[128] = {0};
		    sprintf(testLog, "srv_gatt_conn_param_update_req %d,%d\r\n",min_interval,max_interval);
		    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
		    }
    		//-------------------------------------------------------------
#endif
   		
    if (req)
    {
	    memcpy(req->bd_addr, bd_addr, BD_ADDR_SIZE);
        req->timeout = timeout;
		req->min_interval = min_interval;
		req->max_interval = max_interval;
		req->latency = latency;
		
        req->MaskBit = 0x0F;
		SetProtocolEventHandler(srv_gatt_conn_param_update_cnf, MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF);
		SetProtocolEventHandler(srv_gatt_conn_update_complete_ind, MSG_ID_BT_LE_CONNECT_UPDATE_COMPLETE_IND);
		gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_REQ, (void*)req);
	}
}

#endif

/****************************************************************************
* function define
****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gattc_handle_register_cnf
 * DESCRIPTION
 *  This function is to handle gattc register confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_register_cnf(void *msg)
{
    bt_gattc_register_cnf_struct *cnf = (bt_gattc_register_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->register_client_cb)
    {
        callback->register_client_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            (bt_uuid_struct *)cnf->user_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_deregister_cnf
 * DESCRIPTION
 *  This function is to handle gattc deregister confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_deregister_cnf(void *msg)
{
    bt_gattc_deregister_cnf_struct *cnf = (bt_gattc_deregister_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->deregister_client_cb)
    {
        callback->deregister_client_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_scan_result_ind
 * DESCRIPTION
 *  This function is to handle gattc scan result message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_scan_result_ind(void *msg)
{
    bt_gattc_scan_result_ind_struct *ind = (bt_gattc_scan_result_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->scan_result_cb)
    {
        callback->scan_result_cb(ind->reg_ctx, (BD_ADDR *)ind->bd_addr, ind->rssi, ind->eir_len, ind->eir);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_connect_cnf
 * DESCRIPTION
 *  This function is to handle gattc connect confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_connect_cnf(void *msg)
{
    bt_gattc_connect_cnf_struct *cnf = (bt_gattc_connect_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx;    
    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->connection_cb)
    {
        if (cnf->result == 0)
        {
            callback->connection_cb(&conn, TRUE, (BD_ADDR *)cnf->bd_addr);
        }
        else if (cnf->result != 2)
        {
            callback->connection_cb(&conn, FALSE, (BD_ADDR *)cnf->bd_addr);
        }
    }    
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gattc_conn;
        
        gattc_conn.conn = &conn;
        gattc_conn.bd_addr = (BD_ADDR *)cnf->bd_addr;
        if (cnf->result == 0)
        {
            gattc_conn.connected = TRUE;
        }
        else if (cnf->result != 2)
        {
            gattc_conn.connected = FALSE;
        }
        else
        {
            return;
        }
        
		gattc_conn.is_ind = ((cnf->LocalRole == BCR_MASTER) ? FALSE : TRUE);
        callback->connection_ext_cb(&gattc_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_connected_ind
 * DESCRIPTION
 *  This function is to handle gattc connected indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_connected_ind(void *msg)
{
    bt_gattc_connected_ind_struct *ind = (bt_gattc_connected_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;    

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    conn.reg_ctx = ind->reg_ctx;
    conn.conn_ctx = ind->conn_ctx;  
    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->connection_cb)
    {
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_state msg;

        if (ind->LocalRole != 0xFF) //exclude the case that not link change state.
        {
            memset(&msg, 0, sizeof(msg));
            memcpy(msg.dev_addr.addr, ind->bd_addr, sizeof(ind->bd_addr));
            msg.is_conn = TRUE;
            msg.is_ind = ((ind->LocalRole == BCR_MASTER) ? FALSE : TRUE);
            msg.result = ((ind->result == 0) ? TRUE : FALSE);
            gatt_conn_state_handle(msg);
        }
#endif
        callback->connection_cb(&conn, (ind->result == 0) ? TRUE : FALSE, (BD_ADDR *)ind->bd_addr);
    }   

#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gattc_conn;

        gattc_conn.conn = &conn;
        gattc_conn.bd_addr = (BD_ADDR *)ind->bd_addr;
        gattc_conn.connected = (ind->result == 0) ? TRUE : FALSE;
        gattc_conn.is_ind = ((ind->LocalRole == BCR_MASTER) ? FALSE : TRUE);
        callback->connection_ext_cb(&gattc_conn);
    }   
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_disconnect_cnf
 * DESCRIPTION
 *  This function is to handle gattc disconnect confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_disconnect_cnf(void *msg)
{
    bt_gattc_disconnect_cnf_struct *cnf = (bt_gattc_disconnect_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;       

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx; 
    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->connection_cb && (cnf->result != 2))
    {
        callback->connection_cb(&conn, FALSE, (BD_ADDR *)cnf->bd_addr);
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gattc_conn;
        
        gattc_conn.conn = &conn;
        gattc_conn.bd_addr = (BD_ADDR *)cnf->bd_addr;
        if (cnf->result != 2)
        {
            gattc_conn.connected = FALSE;
        }
        else
        {
            return;
        }
        gattc_conn.is_ind = FALSE;
        callback->connection_ext_cb(&gattc_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_disconnected_ind
 * DESCRIPTION
 *  This function is to handle gattc disconnected indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_disconnected_ind(void *msg)
{
    bt_gattc_disconnected_ind_struct *ind = (bt_gattc_disconnected_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;        
#ifdef __MMI_BLE_LOW_POWER__
	S32 link_num = -1;
#endif
    if (!ind || !ind->app_ctx)
    {
        return;
    }

    conn.reg_ctx = ind->reg_ctx;
    conn.conn_ctx = ind->conn_ctx;
    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->connection_cb)
    {
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_state msg;

        if (ind->result != 0xFF)
        {
            memset(&msg, 0, sizeof(msg));
            memcpy(msg.dev_addr.addr, ind->bd_addr, sizeof(ind->bd_addr));
            msg.is_conn = FALSE;
            msg.is_ind = (DISC_BY_LOCAL_HOST(ind->result) ? FALSE : TRUE);
            msg.result = TRUE;
            msg.reason = ind->result;
            msg.LastInd = ind->LastInd; //20150331
            gatt_conn_state_handle(msg);
        }
#endif
        callback->connection_cb(&conn, FALSE, (BD_ADDR *)ind->bd_addr);
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gattc_conn;
        
        gattc_conn.conn = &conn;
        gattc_conn.bd_addr = (BD_ADDR *)ind->bd_addr;
        gattc_conn.connected = FALSE;
        gattc_conn.is_ind = (DISC_BY_LOCAL_HOST(ind->result) ? FALSE : TRUE);
        callback->connection_ext_cb(&gattc_conn);
    }
#endif  
#ifdef __MMI_BLE_LOW_POWER__
	link_num = srv_gattc_conn_param_is_updating(ind->bd_addr);
	if ((0 <= link_num) && (3 >= link_num))
	{
		memset(&conn_para_info[link_num],0x00, sizeof(gattc_conn_param_struct));
	}
#endif

}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_listen_cnf
 * DESCRIPTION
 *  This function is to handle gattc listen confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_listen_cnf(void *msg)
{
    bt_gattc_listen_cnf_struct *cnf = (bt_gattc_listen_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->listen_cb)
    {
        callback->listen_cb(cnf->reg_ctx, (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_set_adv_data_cnf
 * DESCRIPTION
 *  This function is to handle gattc set adv data confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_set_adv_data_cnf(void *msg)
{
    bt_gattc_set_adv_data_cnf_struct *cnf = (bt_gattc_set_adv_data_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->set_adv_data_cb)
    {
        callback->set_adv_data_cb(cnf->reg_ctx, (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}
/*****************************************************************************
 * FUNCTION
 *  gattc_handle_search_service_result_ind
 * DESCRIPTION
 *  This function is to handle gattc search service result indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_search_service_result_ind(void *msg)
{
    bt_gattc_search_service_result_ind_struct *ind = (bt_gattc_search_service_result_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;       

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    conn.reg_ctx = ind->reg_ctx;
    conn.conn_ctx = ind->conn_ctx;
    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->search_result_cb)
    {
        callback->search_result_cb(&conn, &ind->uuid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_search_service_cnf
 * DESCRIPTION
 *  This function is to handle gattc search service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_search_service_cnf(void *msg)
{
    bt_gattc_search_service_cnf_struct *cnf = (bt_gattc_search_service_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx;
    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->search_complete_cb)
    {
        callback->search_complete_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_get_incl_service_cnf
 * DESCRIPTION
 *  This function is to handle gattc get included service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_get_incl_service_cnf(void *msg)
{
    bt_gattc_get_incl_service_cnf_struct *cnf = (bt_gattc_get_incl_service_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx;
    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->get_included_service_cb)
    {
        callback->get_included_service_cb(&conn,
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED,
            &cnf->svc_uuid, &cnf->incl_svc_uuid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_get_char_cnf
 * DESCRIPTION
 *  This function is to handle gattc get characteristic confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_get_char_cnf(void *msg)
{
    bt_gattc_get_char_cnf_struct *cnf = (bt_gattc_get_char_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_char_struct char_info;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->get_characteristic_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx;  
        char_info.svc_uuid = &cnf->svc_uuid;
        char_info.char_uuid = &cnf->char_uuid;
        callback->get_characteristic_cb(&conn,
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED,
            &char_info, cnf->properties);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_get_descr_cnf
 * DESCRIPTION
 *  This function is to handle gattc get descriptor confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_get_descr_cnf(void *msg)
{
    bt_gattc_get_descr_cnf_struct *cnf = (bt_gattc_get_descr_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_descr_struct descr_info;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->get_descriptor_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx; 
        descr_info.svc_uuid = &cnf->svc_uuid;
        descr_info.char_uuid = &cnf->char_uuid;
        descr_info.descr_uuid = &cnf->descr_uuid;
        callback->get_descriptor_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, &descr_info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_read_char_cnf
 * DESCRIPTION
 *  This function is to handle gattc read characteristic confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_read_char_cnf(void *msg)
{
    bt_gattc_read_char_cnf_struct *cnf = (bt_gattc_read_char_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_char_struct char_info;    
    ATT_VALUE value;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->read_characteristic_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx;   
        char_info.svc_uuid = &cnf->svc_uuid;
        char_info.char_uuid = &cnf->char_uuid;
        value.len = (cnf->value.len > ATT_MAX_VALUE_LEN) ? ATT_MAX_VALUE_LEN : cnf->value.len;
        if (value.len)
        {
            memcpy(value.value, cnf->value.value, value.len);
        }
        callback->read_characteristic_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, &char_info, &value);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_write_char_cnf
 * DESCRIPTION
 *  This function is to handle gattc write characteristic confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_write_char_cnf(void *msg)
{
    bt_gattc_write_char_cnf_struct *cnf = (bt_gattc_write_char_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_char_struct char_info;        

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->write_characteristic_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx;    
        char_info.svc_uuid = &cnf->svc_uuid;
        char_info.char_uuid = &cnf->char_uuid;        
        callback->write_characteristic_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, &char_info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_read_descr_cnf
 * DESCRIPTION
 *  This function is to handle gattc read descriptor confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_read_descr_cnf(void *msg)
{
    bt_gattc_read_descr_cnf_struct *cnf = (bt_gattc_read_descr_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_descr_struct descr_info;
    ATT_VALUE value;    

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->read_descriptor_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx;   
        descr_info.svc_uuid = &cnf->svc_uuid;
        descr_info.char_uuid = &cnf->char_uuid;
        descr_info.descr_uuid = &cnf->descr_uuid;  
        value.len = (cnf->value.len > ATT_MAX_VALUE_LEN) ? ATT_MAX_VALUE_LEN : cnf->value.len;
        if (value.len)
        {
            memcpy(value.value, cnf->value.value, value.len);     
        }   
        callback->read_descriptor_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, &descr_info, &value);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_write_descr_cnf
 * DESCRIPTION
 *  This function is to handle gattc write descriptor confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_write_descr_cnf(void *msg)
{
    bt_gattc_write_descr_cnf_struct *cnf = (bt_gattc_write_descr_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_descr_struct descr_info;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->write_descriptor_cb)
    {
        conn.reg_ctx = cnf->reg_ctx;
        conn.conn_ctx = cnf->conn_ctx;  
        descr_info.svc_uuid = &cnf->svc_uuid;
        descr_info.char_uuid = &cnf->char_uuid;
        descr_info.descr_uuid = &cnf->descr_uuid;         
        callback->write_descriptor_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, &descr_info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_exec_write_cnf
 * DESCRIPTION
 *  This function is to handle gattc execute write confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_exec_write_cnf(void *msg)
{
    bt_gattc_exec_write_cnf_struct *cnf = (bt_gattc_exec_write_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx;
    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->execute_write_cb)
    {
        callback->execute_write_cb(&conn, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_reg_notification_cnf
 * DESCRIPTION
 *  This function is to handle gattc register for notification confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_reg_notification_cnf(void *msg)
{
    bt_gattc_register_notification_cnf_struct *cnf = (bt_gattc_register_notification_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gattc_char_struct char_info;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->register_for_notification_cb)
    {
        char_info.svc_uuid = &cnf->svc_uuid;
        char_info.char_uuid = &cnf->char_uuid;
        callback->register_for_notification_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED,
            (BD_ADDR *)cnf->bd_addr, &char_info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_dereg_notification_cnf
 * DESCRIPTION
 *  This function is to handle gattc deregister for notification confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_dereg_notification_cnf(void *msg)
{
    bt_gattc_deregister_notification_cnf_struct *cnf = (bt_gattc_deregister_notification_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gattc_char_struct char_info;       

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->register_for_notification_cb)
    {
        char_info.svc_uuid = &cnf->svc_uuid;
        char_info.char_uuid = &cnf->char_uuid;    
        callback->register_for_notification_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED,
            (BD_ADDR *)cnf->bd_addr, &char_info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_read_rssi_cnf
 * DESCRIPTION
 *  This function is to handle gattc read rssi confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_read_rssi_cnf(void *msg)
{
    bt_gattc_read_rssi_cnf_struct *cnf = (bt_gattc_read_rssi_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->read_remote_rssi_cb)
    {
        callback->read_remote_rssi_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            (BD_ADDR *)cnf->bd_addr, cnf->rssi);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_get_device_type_cnf
 * DESCRIPTION
 *  This function is to handle gattc get device type confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_get_device_type_cnf(void *msg)
{
    bt_gattc_get_device_type_cnf_struct *cnf = (bt_gattc_get_device_type_cnf_struct *)msg;
    gattc_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)cnf->app_ctx;
    if (callback->get_device_type_cb)
    {
        callback->get_device_type_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            (BD_ADDR *)cnf->bd_addr, cnf->dev_type);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_notification_ind
 * DESCRIPTION
 *  This function is to handle gattc noification indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_notification_ind(void *msg)
{
    bt_gattc_notification_ind_struct *ind = (bt_gattc_notification_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
    gattc_char_struct char_info;  
    ATT_VALUE value;

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->notify_cb)
    {
        conn.reg_ctx = ind->reg_ctx;
        conn.conn_ctx = ind->conn_ctx;
        char_info.svc_uuid = &ind->svc_uuid;
        char_info.char_uuid = &ind->char_uuid;  
        value.len = (ind->value.len > ATT_MAX_VALUE_LEN) ? ATT_MAX_VALUE_LEN : ind->value.len;
        if (value.len)
        {
            memcpy(value.value, ind->value.value, value.len);  
        }      
        callback->notify_cb(&conn, (BD_ADDR *)ind->bd_addr, &char_info, &value, ind->is_notify);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_start_research_service_ind
 * DESCRIPTION
 *  This function is to handle gattc start service change indication message
 * PARAMETERS
 *  msg     [IN]: bt_gattc_research_service_ind_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_start_research_service_ind(void *msg)
{
#ifdef __MMI_BLE_LOW_POWER__
    bt_gattc_start_research_service_ind_struct *ind = (bt_gattc_start_research_service_ind_struct *)msg;
	if (!((char *)ind->bd_addr))
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_ADDR_NULL);
		return;
	}
	memset(gattc_bdaddr, 0x00, GATTC_BD_ADDR_SIZE);
	memcpy((char *)gattc_bdaddr, (char *)ind->bd_addr, GATTC_BD_ADDR_SIZE);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_CONN_INTERVAL_REQ, gattc_bdaddr[0],
		gattc_bdaddr[1],gattc_bdaddr[2],gattc_bdaddr[3],gattc_bdaddr[4],gattc_bdaddr[5]);
	
	StopTimer(GATTC_SET_CONN_INTERVAL_TIMER_ID);
	srv_gattc_conn_param_update(PROFILE_ID_REMOTE_SRV_CHANGE, (char *)ind->bd_addr, CONNECTION_PRIORITY_BALANCE); 
	StartTimer(GATTC_SET_CONN_INTERVAL_TIMER_ID, GATTC_SET_CONN_INTERVAL_TIME, srv_gattc_conn_param_interval_reset);
#endif
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTC_START_RESEARCH);
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_research_service_ind
 * DESCRIPTION
 *  This function is to handle gattc service change indication message
 * PARAMETERS
 *  msg     [IN]: bt_gattc_research_service_ind_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_research_service_ind(void *msg)
{
    bt_gattc_research_service_ind_struct *ind = (bt_gattc_research_service_ind_struct *)msg;
    gattc_callback_struct *callback = NULL;
    gatt_conn_struct conn;
        
    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gattc_callback_struct *)ind->app_ctx;
    if (callback->research_service_cb)
    {        
        conn.reg_ctx = ind->reg_ctx;
        conn.conn_ctx = ind->conn_ctx;
        callback->research_service_cb(&conn, (ind->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, (BD_ADDR *)ind->bd_addr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gattc_handle_update_connected_info
 * DESCRIPTION
 *  This function is to handle gattc update connected name message
 * PARAMETERS
 *  msg     [IN]: bt_gattc_connected_info_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gattc_handle_update_connected_info(void *msg)
{
    bt_gattc_connected_info_struct *info = (bt_gattc_connected_info_struct *)msg;
        
    if (!info || !info->app_ctx)
    {
        return;
    }
    
#ifdef MMI_SRV_CONN_STATE_IND
    gatt_update_remote_device_name(info->dev_name, (BD_ADDR *)info->bd_addr);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_init(void)
{
    SetProtocolEventHandler(gattc_handle_register_cnf, MSG_ID_BT_GATTC_REGISTER_CNF);
    SetProtocolEventHandler(gattc_handle_deregister_cnf, MSG_ID_BT_GATTC_DEREGISTER_CNF);    
    SetProtocolEventHandler(gattc_handle_scan_result_ind, MSG_ID_BT_GATTC_SCAN_RESULT_IND);
    SetProtocolEventHandler(gattc_handle_connect_cnf, MSG_ID_BT_GATTC_CONNECT_CNF);
    SetProtocolEventHandler(gattc_handle_connected_ind, MSG_ID_BT_GATTC_CONNECTED_IND);
    SetProtocolEventHandler(gattc_handle_disconnect_cnf, MSG_ID_BT_GATTC_DISCONNECT_CNF);
    SetProtocolEventHandler(gattc_handle_disconnected_ind, MSG_ID_BT_GATTC_DISCONNECTED_IND);
    SetProtocolEventHandler(gattc_handle_listen_cnf, MSG_ID_BT_GATTC_LISTEN_CNF);
    SetProtocolEventHandler(gattc_handle_set_adv_data_cnf, MSG_ID_BT_GATTC_SET_ADV_DATA_CNF);    
    SetProtocolEventHandler(gattc_handle_search_service_result_ind, MSG_ID_BT_GATTC_SEARCH_SERVICE_RESULT_IND);
    SetProtocolEventHandler(gattc_handle_search_service_cnf, MSG_ID_BT_GATTC_SEARCH_SERVICE_CNF);
    SetProtocolEventHandler(gattc_handle_get_incl_service_cnf, MSG_ID_BT_GATTC_GET_INCL_SERVICE_CNF);
    SetProtocolEventHandler(gattc_handle_get_char_cnf, MSG_ID_BT_GATTC_GET_CHAR_CNF);
    SetProtocolEventHandler(gattc_handle_get_descr_cnf, MSG_ID_BT_GATTC_GET_DESCR_CNF);
    SetProtocolEventHandler(gattc_handle_read_char_cnf, MSG_ID_BT_GATTC_READ_CHAR_CNF);
    SetProtocolEventHandler(gattc_handle_write_char_cnf, MSG_ID_BT_GATTC_WRITE_CHAR_CNF);
    SetProtocolEventHandler(gattc_handle_read_descr_cnf, MSG_ID_BT_GATTC_READ_DESCR_CNF);
    SetProtocolEventHandler(gattc_handle_write_descr_cnf, MSG_ID_BT_GATTC_WRITE_DESCR_CNF);
    SetProtocolEventHandler(gattc_handle_exec_write_cnf, MSG_ID_BT_GATTC_EXEC_WRITE_CNF);
    SetProtocolEventHandler(gattc_handle_reg_notification_cnf, MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_CNF);
    SetProtocolEventHandler(gattc_handle_dereg_notification_cnf, MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_CNF);
    SetProtocolEventHandler(gattc_handle_read_rssi_cnf, MSG_ID_BT_GATTC_READ_RSSI_CNF);
    SetProtocolEventHandler(gattc_handle_get_device_type_cnf, MSG_ID_BT_GATTC_GET_DEVICE_TYPE_CNF);
    SetProtocolEventHandler(gattc_handle_notification_ind, MSG_ID_BT_GATTC_NOTIFICATION_IND);    
    SetProtocolEventHandler(gattc_handle_start_research_service_ind, MSG_ID_BT_GATTC_START_RESEARCH_SERVICE_IND);    
    SetProtocolEventHandler(gattc_handle_research_service_ind, MSG_ID_BT_GATTC_RESEARCH_SERVICE_IND);    
    SetProtocolEventHandler(gattc_handle_update_connected_info, MSG_ID_BT_GATTC_UPDATE_CONNECTED_INFO);    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_register
 * DESCRIPTION
 *  Registers a GATT client application with the stack
 * PARAMETERS
 *  app_uuid [IN]
 *  callback [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_register(bt_uuid_struct *app_uuid, gattc_callback_struct *callback)
{
    bt_gattc_register_req_struct *req = NULL;

    if (!app_uuid)
    {
        return;
    }
    req = (bt_gattc_register_req_struct*)
            construct_local_para(sizeof(bt_gattc_register_req_struct), TD_CTRL);    
    if (req)
    {
        req->app_ctx = callback;
        memcpy(req->user_id, app_uuid->uu, sizeof(app_uuid->uu));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_REGISTER_REQ, (void*)req);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_deregister
 * DESCRIPTION
 *  Unregister a client application from the stack
 * PARAMETERS
 *  reg_ctx [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_deregister(void *reg_ctx)
{
    bt_gattc_deregister_req_struct *req = (bt_gattc_deregister_req_struct*)
            construct_local_para(sizeof(bt_gattc_deregister_req_struct), TD_CTRL);
    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_DEREGISTER_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_scan
 * DESCRIPTION
 *  Start or stop LE device scanning
 * PARAMETERS
 *  reg_ctx [IN]
 *  start   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_scan(void *reg_ctx, BOOL start)
{
    if (start)
    {
        bt_gattc_scan_req_struct *req = (bt_gattc_scan_req_struct*)
                    construct_local_para(sizeof(bt_gattc_scan_req_struct), TD_CTRL);
        if (req)
        {
            req->reg_ctx = reg_ctx;
            gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SCAN_REQ, (void*)req);
        }        
    }
    else
    {
        bt_gattc_scan_cancel_req_struct *req = (bt_gattc_scan_cancel_req_struct*)
                    construct_local_para(sizeof(bt_gattc_scan_cancel_req_struct), TD_CTRL);
        if (req)
        {
            req->reg_ctx = reg_ctx;
            gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SCAN_CANCEL_REQ, (void*)req);
        }          
    }   
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_connect
 * DESCRIPTION
 *  Create a connection to a remote LE or dual-mode device
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 *  direct  [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_connect(void *reg_ctx, BD_ADDR *bd_addr, BOOL direct)
{
    bt_gattc_connect_req_struct *req = NULL;
    
    if (!bd_addr)
    {
        return;
    }
    req = (bt_gattc_connect_req_struct*)
        construct_local_para(sizeof(bt_gattc_connect_req_struct), TD_CTRL);
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->direct = direct;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_CONNECT_REQ, (void*)req);
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_clear_state(bd_addr);
#endif
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_disconnect
 * DESCRIPTION
 *  Disconnect a remote device or cancel a pending connection
 * PARAMETERS
 *  conn    [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr)
{
    bt_gattc_disconnect_req_struct *req = NULL;

    if (!conn || !bd_addr)
    {
        return;
    }
    req = (bt_gattc_disconnect_req_struct*)
            construct_local_para(sizeof(bt_gattc_disconnect_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_DISCONNECT_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_listen
 * DESCRIPTION
 *  Start or stop a listen for connection
 * PARAMETERS
 *  reg_ctx [IN]
 *  start   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_listen(void *reg_ctx, BOOL start)
{
    bt_gattc_listen_req_struct *req = NULL;

    req = (bt_gattc_listen_req_struct*)
            construct_local_para(sizeof(bt_gattc_listen_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->start = start;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_LISTEN_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_set_adv_data
 * DESCRIPTION
 *  Set advertise data
 * PARAMETERS
 *  reg_ctx           [IN]
 *  set_scan_rsp      [IN]
 *  include_name      [IN]
 *  include_txpower   [IN]
 *  min_interval      [IN]
 *  max_interval      [IN]
 *  appearance        [IN]
 *  manufacturer_len  [IN]
 *  manufacturer_data [IN]
 *  service_data_len  [IN]
 *  service_data      [IN]
 *  service_uuid_len  [IN]
 *  service_uuid      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_set_adv_data(void *reg_ctx, BOOL set_scan_rsp, BOOL include_name, BOOL include_txpower, 
                                U16 min_interval, U16 max_interval, U16 appearance,
                                U16 manufacturer_len, char *manufacturer_data,
                                U16 service_data_len, char *service_data,
                                U16 service_uuid_len, char *service_uuid)
{
    bt_gattc_set_adv_data_req_struct *req = NULL;

    req = (bt_gattc_set_adv_data_req_struct*)
            construct_local_para(sizeof(bt_gattc_set_adv_data_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->set_scan_rsp = set_scan_rsp;
        req->include_name = include_name;
        req->include_txpower = include_txpower;
        req->min_interval = min_interval;
        req->max_interval = max_interval;
        req->appearance = appearance;
        req->manufacturer_len = (manufacturer_len > 512) ? 512 : manufacturer_len;  
        req->service_data_len = (service_data_len > 512) ? 512 : service_data_len;    
        req->service_uuid_len = (service_uuid_len > 512) ? 512 : service_uuid_len;    
        if (manufacturer_data)
        {
            memcpy(req->manufacturer_data, manufacturer_data, req->manufacturer_len);
        }
        if (service_data)
        {
            memcpy(req->service_data, service_data, req->service_data_len);
        }
        if (service_uuid)
        {
            memcpy(req->service_uuid, service_uuid, req->service_uuid_len);
        }        
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SET_ADV_DATA_REQ, (void*)req);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_refresh
 * DESCRIPTION
 *  Clear the attribute cache for a given device
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_refresh(void *reg_ctx, BD_ADDR *bd_addr)
{
    bt_gattc_refresh_req_struct *req = NULL;

    if (!bd_addr)
    {
        return;
    }
    req = (bt_gattc_refresh_req_struct*)
            construct_local_para(sizeof(bt_gattc_refresh_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_REFRESH_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_search_service
 * DESCRIPTION
 *  Enumerate all GATT services on a connected device.
 *  Optionally, the results can be filtered for a given UUID.
 * PARAMETERS
 *  conn        [IN]
 *  filter_uuid [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_search_service(gatt_conn_struct *conn, bt_uuid_struct *filter_uuid)
{
    bt_gattc_search_service_req_struct *req = NULL;
    
    if (!conn)
    {
        return;
    }    
    req = (bt_gattc_search_service_req_struct*)
                construct_local_para(sizeof(bt_gattc_search_service_req_struct), TD_CTRL);
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;
        req->uuid.inst = 0;
        if (filter_uuid)
        {
            req->uuid.uuid.len = 16;        
            memcpy(&req->uuid.uuid.uuid, filter_uuid->uu, sizeof(bt_uuid_struct));
        }
        else
        {
            req->uuid.uuid.len = 0;
        }
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_SEARCH_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_included_service
 * DESCRIPTION
 *  Enumerate included services for a given service.
 *  Set start_incl_srvc_id to NULL to get the first included service.
 * PARAMETERS
 *  conn                [IN]
 *  svc_uuid            [IN]
 *  start_incl_svc_uuid [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_get_included_service(gatt_conn_struct *conn, 
                                    GATT_SVC_UUID *svc_uuid, 
                                    GATT_SVC_UUID *start_incl_svc_uuid)
{
    bt_gattc_get_incl_service_req_struct *req = NULL;

    if (!conn || !svc_uuid)
    {
        return;
    }
    req = (bt_gattc_get_incl_service_req_struct*)
            construct_local_para(sizeof(bt_gattc_get_incl_service_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;    
        memcpy(&req->svc_uuid, svc_uuid, sizeof(GATT_SVC_UUID));
        if (start_incl_svc_uuid)
        {
            memcpy(&req->incl_svc_uuid, start_incl_svc_uuid, sizeof(GATT_SVC_UUID));  
        }
        else
        {
            req->incl_svc_uuid.uuid.uuid.len = 0;
        }
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_GET_INCL_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_characteristic
 * DESCRIPTION
 *  Enumerate characteristics for a given service.
 *  Set start_char_uuid to NULL to get the first characteristic.
 * PARAMETERS
 *  conn            [IN]
 *  svc_uuid        [IN]
 *  start_char_uuid [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_get_characteristic(gatt_conn_struct *conn, 
                                  GATT_SVC_UUID *svc_uuid, 
                                  ATT_UUID *start_char_uuid)
{
    bt_gattc_get_char_req_struct *req = NULL;

    if (!conn || !svc_uuid)
    {
        return;
    }
    req = (bt_gattc_get_char_req_struct*)
            construct_local_para(sizeof(bt_gattc_get_char_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;    
        memcpy(&req->svc_uuid, svc_uuid, sizeof(GATT_SVC_UUID));
        if (start_char_uuid)
        {
            memcpy(&req->char_uuid, start_char_uuid, sizeof(ATT_UUID)); 
        }
        else
        {
            req->char_uuid.uuid.len = 0;
        }
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_GET_CHAR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_descriptor
 * DESCRIPTION
 *  Enumerate descriptors for a given characteristic.
 *  Set start_descr_id to NULL to get the first descriptor.
 * PARAMETERS
 *  conn             [IN]
 *  char_info        [IN] 
 *  start_descr_uuid [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_get_descriptor(gatt_conn_struct *conn, 
                              gattc_char_struct *char_info, 
                              ATT_UUID *start_descr_uuid)
{
    bt_gattc_get_descr_req_struct *req = NULL;

    if (!conn || !char_info)
    {
        return;
    }
    req = (bt_gattc_get_descr_req_struct*)
            construct_local_para(sizeof(bt_gattc_get_descr_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;    
        memcpy(&req->svc_uuid, char_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, char_info->char_uuid, sizeof(ATT_UUID)); 
        if (start_descr_uuid)
        {
            memcpy(&req->descr_uuid, start_descr_uuid, sizeof(ATT_UUID));  
        }
        else
        {
            req->descr_uuid.uuid.len = 0;
        }
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_GET_DESCR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_read_characteristic
 * DESCRIPTION
 *  Read a characteristic on a remote device 
 * PARAMETERS
 *  conn      [IN]
 *  char_info [IN]
 *  auth_req  [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_read_characteristic(gatt_conn_struct *conn, gattc_char_struct *char_info, GATTC_AUTH_REQ auth_req)
{
    bt_gattc_read_char_req_struct *req = NULL;

    if (!conn || !char_info)
    {
        return;
    }
    req = (bt_gattc_read_char_req_struct*)
            construct_local_para(sizeof(bt_gattc_read_char_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;   
        req->auth_req = auth_req;
        memcpy(&req->svc_uuid, char_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, char_info->char_uuid, sizeof(ATT_UUID)); 
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_READ_CHAR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_write_characteristic
 * DESCRIPTION
 *  Write a remote characteristic 
 * PARAMETERS
 *  conn       [IN]
 *  char_info  [IN]
 *  value      [IN]
 *  write_type [IN]  
 *  auth_req   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_write_characteristic(gatt_conn_struct *conn, 
                                    gattc_char_struct *char_info, 
                                    ATT_VALUE *value,
                                    GATTC_WRITE_TYPE write_type,                                    
                                    GATTC_AUTH_REQ auth_req)
{
    bt_gattc_write_char_req_struct *req = NULL;

    if (!conn || !char_info || !value)
    {
        return;
    }
    req = (bt_gattc_write_char_req_struct*)
            construct_local_para(sizeof(bt_gattc_write_char_req_struct) - sizeof(ATT_VALUE) + sizeof(value->len) + value->len, TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx; 
        req->write_type = write_type;
        req->auth_req = auth_req;
        req->value.len = value->len;
        memcpy(&req->svc_uuid, char_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, char_info->char_uuid, sizeof(ATT_UUID)); 
        if (value->len)
        {
            memcpy(req->value.value, value->value, value->len); 
        }        
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_WRITE_CHAR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_read_descriptor
 * DESCRIPTION
 *  Read the descriptor for a given characteristic  
 * PARAMETERS
 *  conn       [IN]
 *  descr_info [IN] 
 *  auth_req   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_read_descriptor(gatt_conn_struct *conn, gattc_descr_struct *descr_info, GATTC_AUTH_REQ auth_req)
{
    bt_gattc_read_descr_req_struct *req = NULL;

    if (!conn || !descr_info)
    {
        return;
    }
    req = (bt_gattc_read_descr_req_struct*)
            construct_local_para(sizeof(bt_gattc_read_descr_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx; 
        req->auth_req = auth_req;
        memcpy(&req->svc_uuid, descr_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, descr_info->char_uuid, sizeof(ATT_UUID)); 
        memcpy(&req->descr_uuid, descr_info->descr_uuid, sizeof(ATT_UUID));  
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_READ_DESCR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_write_descriptor
 * DESCRIPTION
 *  Write a remote descriptor for a given characteristic 
 * PARAMETERS
 *  conn       [IN]
 *  descr_info [IN]
 *  value      [IN]
 *  write_type [IN]  
 *  auth_req   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_write_descriptor(gatt_conn_struct *conn, 
                                gattc_descr_struct *descr_info, 
                                ATT_VALUE *value,
                                GATTC_WRITE_TYPE write_type,                                
                                GATTC_AUTH_REQ auth_req)
{
    bt_gattc_write_descr_req_struct *req = NULL;
    
    if (!conn || !descr_info || !value)
    {
        return;
    }
    req = (bt_gattc_write_descr_req_struct*)
            construct_local_para(sizeof(bt_gattc_write_descr_req_struct) - sizeof(ATT_VALUE) + sizeof(value->len) + value->len, TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx; 
        req->write_type = write_type;        
        req->auth_req = auth_req;
        req->value.len = value->len;        
        memcpy(&req->svc_uuid, descr_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, descr_info->char_uuid, sizeof(ATT_UUID)); 
        memcpy(&req->descr_uuid, descr_info->descr_uuid, sizeof(ATT_UUID)); 
        if (value->len)
        {
            memcpy(req->value.value, value->value, value->len); 
        }          
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_WRITE_DESCR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_execute_write
 * DESCRIPTION
 *  Execute a prepared write operation
 * PARAMETERS
 *  conn   [IN]
 *  exeute [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_execute_write(gatt_conn_struct *conn, U8 exeute)
{
    bt_gattc_exec_write_req_struct *req = NULL;
    
    if (!conn)
    {
        return;
    }
    req = (bt_gattc_exec_write_req_struct*)
            construct_local_para(sizeof(bt_gattc_exec_write_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx; 
        req->exeute = exeute;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_EXEC_WRITE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_register_for_notification
 * DESCRIPTION
 *  Register to receive notifications or indications for a given
 *  characteristic
 * PARAMETERS
 *  reg_ctx   [IN]
 *  bd_addr   [IN]
 *  char_info [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_register_for_notification(void *reg_ctx, BD_ADDR *bd_addr, gattc_char_struct *char_info)
{
    bt_gattc_register_notification_req_struct *req = NULL;

    if (!bd_addr || !char_info)
    {
        return;
    }
    req = (bt_gattc_register_notification_req_struct*)
            construct_local_para(sizeof(bt_gattc_register_notification_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));        
        memcpy(&req->svc_uuid, char_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, char_info->char_uuid, sizeof(ATT_UUID)); 
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_deregister_for_notification
 * DESCRIPTION
 *  Deregister a previous request for notifications/indications
 * PARAMETERS
 *  reg_ctx   [IN]
 *  bd_addr   [IN]
 *  char_info [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_deregister_for_notification(void *reg_ctx, BD_ADDR *bd_addr, gattc_char_struct *char_info)
{
    bt_gattc_deregister_notification_req_struct *req = NULL;
    
    if (!bd_addr || !char_info)
    {
        return;
    }    
    req = (bt_gattc_deregister_notification_req_struct*)
                construct_local_para(sizeof(bt_gattc_deregister_notification_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));        
        memcpy(&req->svc_uuid, char_info->svc_uuid, sizeof(GATT_SVC_UUID));
        memcpy(&req->char_uuid, char_info->char_uuid, sizeof(ATT_UUID)); 
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_read_remote_rssi
 * DESCRIPTION
 *  Request RSSI for a given remote device
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_read_remote_rssi(void *reg_ctx, BD_ADDR *bd_addr)
{
    bt_gattc_read_rssi_req_struct *req = NULL;
    
    if (!bd_addr)
    {
        return;
    }    
    req = (bt_gattc_read_rssi_req_struct*)
                construct_local_para(sizeof(bt_gattc_read_rssi_req_struct), TD_CTRL);     
    if (req)
    {       
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));   
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_READ_RSSI_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gattc_get_device_type
 * DESCRIPTION
 *  Determine the type of the remote device (LE, BR/EDR, Dual-mode)
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gattc_get_device_type(void *reg_ctx, BD_ADDR *bd_addr)
{
    bt_gattc_get_device_type_req_struct *req = NULL;
    
    if (!bd_addr)
    {
        return;
    }    
    req = (bt_gattc_get_device_type_req_struct*)
                construct_local_para(sizeof(bt_gattc_get_device_type_req_struct), TD_CTRL);     
    if (req)
    {       
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));   
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTC_GET_DEVICE_TYPE_REQ, (void*)req);
    }    
}


#endif
