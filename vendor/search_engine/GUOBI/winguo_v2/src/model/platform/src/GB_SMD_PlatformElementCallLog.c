
#include "MMI_include.h"
#include "Wgui_categories_util.h"
#include "CallLogProt.h"
#include "CallLogSrvGprot.h"
#include "PhbSrvGprot.h"
#include "mmi_rp_app_gb_winguo_def.h"

#include "GB_WG_Common.h"

extern GB_INT GB_SMD_CallLogAddIndexTarget(GB_U32 Index);

// 根据输入串，搜索与其匹配的callLog
GB_INT GB_SMD_Platform_SearchCallLogByString(GB_U16 * key_input)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_clog_get_list_log_ids_req_struct req_data;
	srv_clog_get_list_log_ids_cnf_struct cnf_data;
	srv_clog_log_struct log;
	unsigned short CachType = 0;
	unsigned short index_type = 0;
	unsigned short Index = 0;
	U16 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (!key_input || !*key_input)
	{
		return 0;
	}

	srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
	srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);

	req_data.start_by = SRV_CLOG_BY_ID;
	req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;

	while(1)
	{
		req_data.start_elm = cnf_data.next_start_elm;
		if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
		{
			break;
		}
		for (i = 0; i < cnf_data.log_num; i++)
		{
			srv_clog_get_log_by_id(0, cnf_data.log_ids[i], SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_CID, &log);
			if(!srv_phb_check_number_exist((U16*)log.data.call_log.cid)
				&& mmi_wcsstr(log.data.call_log.cid, key_input))
			{
				Index = cnf_data.log_ids[i];

				GB_SMD_CallLogAddIndexTarget(Index); 
			}
		}
		if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
		{
			break;
		} 
	}
	return 1;
}

static U32 _bit2idx(U32 bit)
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

GB_INT GB_SMD_Platform_GetCallLogIcon(GB_U32 index, GB_PU8 *img_buff_p)
{
	srv_clog_log_struct log;
	srv_clog_log_identity_struct idt;
	srv_clog_get_log_by_id(0, index, SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_CID, &log);
	idt.cate = log.data.call_log.cate;
	idt.sim_id = log.data.call_log.sim_id;
	idt.log_type = log.data.call_log.log_type;
	idt.sub_type = log.data.call_log.sub_type;
#if (MMI_MAX_SIM_NUM >= 4)
	if(_bit2idx(idt.sim_id) == SRV_CLOG_SIM_IDX_SIM4)
	{
		if(idt.log_type == SRV_CLOG_CLT_DIALED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_OUT_SIM4);
		}
		else if (idt.log_type == SRV_CLOG_CLT_MISSED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MISSCALL_SIM4);
		}
		else if (idt.log_type == SRV_CLOG_CLT_RECVED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_IN_SIM4);
		}
	}
#endif
#if (MMI_MAX_SIM_NUM >= 3)
	if(_bit2idx(idt.sim_id) == SRV_CLOG_SIM_IDX_SIM3)
	{
		if(idt.log_type == SRV_CLOG_CLT_DIALED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_OUT_SIM3);
		}
		else if (idt.log_type == SRV_CLOG_CLT_MISSED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MISSCALL_SIM3);
		}
		else if (idt.log_type == SRV_CLOG_CLT_RECVED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_IN_SIM3);
		}
	}
#endif
#if (MMI_MAX_SIM_NUM >= 2)
	if(_bit2idx(idt.sim_id) == SRV_CLOG_SIM_IDX_SIM2)
	{
		if(idt.log_type == SRV_CLOG_CLT_DIALED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_OUT_SIM2);
		}
		else if (idt.log_type == SRV_CLOG_CLT_MISSED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MISSCALL_SIM2);
		}
		else if (idt.log_type == SRV_CLOG_CLT_RECVED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_IN_SIM2);
		}
	}
	if(_bit2idx(idt.sim_id) == SRV_CLOG_SIM_IDX_SIM1)
	{
		if(idt.log_type == SRV_CLOG_CLT_DIALED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_OUT_SIM1);
		}
		else if (idt.log_type == SRV_CLOG_CLT_MISSED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MISSCALL_SIM1);
		}
		else if (idt.log_type == SRV_CLOG_CLT_RECVED)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_IN_SIM1);
		}
	}
#else //(MMI_MAX_SIM_NUM >= 2)
	// 单卡情况
	if(idt.log_type == SRV_CLOG_CLT_DIALED)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_OUT);
	}
	else if (idt.log_type == SRV_CLOG_CLT_MISSED)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MISSCALL);
	}
	else if (idt.log_type == SRV_CLOG_CLT_RECVED)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CALL_IN);
	}
#endif
	return 1;
}

GB_INT GB_SMD_Platform_GetCallLogNumByIndex(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen)
{
	srv_clog_log_struct log;

	if (!pstrBuf || bufLen<=0)
	{
		return 0;
	}
	GB_MEMSET(pstrBuf, 0, bufLen*sizeof(*pstrBuf));
	srv_clog_get_log_by_id(0, id, SRV_CLOG_LOG_FIELD_CID, &log);
	if (log.data.call_log.cid[0])
	{
		GB_MEMCPY(pstrBuf, log.data.call_log.cid, (bufLen-1)*sizeof(*pstrBuf));
		pstrBuf[bufLen-1] = 0;
		return 1;
	}
	return 0;
}

GB_INT GB_SMD_Platform_GetCallLogNote(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen)
{
	GB_INT ret = 0;
	const GB_U16 *pString = GB_NULL;
	srv_clog_log_struct log;
	srv_clog_get_log_by_id(0, id, SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_CID, &log);

	if (!pstrBuf || !bufLen)
	{
		return 0;
	}
	if(log.data.call_log.log_type == SRV_CLOG_CLT_DIALED)
	{
		pString = (const GB_WCHAR*)get_string(STR_GLOBAL_DIALLED_CALLS);
	}
	else if (log.data.call_log.log_type == SRV_CLOG_CLT_MISSED)
	{
		pString = (const GB_WCHAR*)get_string(STR_GLOBAL_MISSED_CALLS);
	}
	else if (log.data.call_log.log_type == SRV_CLOG_CLT_RECVED)
	{
		pString = (const GB_WCHAR*)get_string(STR_GLOBAL_RECEIVED_CALLS);
	}
	if (pString)
	{
		pstrBuf[bufLen-1] = 0;
		gb_wg_wcsncpy(pstrBuf, pString, bufLen-1);
		ret = 1;
	}
	return ret;
}
