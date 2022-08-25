
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#include "GB_WG_LACInf.h"
#include "MMI_features.h"
#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "MMIDataType.h"
#include "GB_WG_MTKPlatver.h"
#include "GB_File.h"
#ifdef GB_MTK_10APLAT
#include "Simctrlsrvgprot.h"
#else
#include "Mtpnp_ad_master_common_def.h"
#endif

#ifdef __MMI_ENGINEER_MODE__   

static rr_em_lai_info_struct GB_WG_G_lai_info;
static kal_uint16 GB_WG_G_lac[3];
static kal_uint16 GB_WG_G_Cell_Id[3];
static int GB_WG_G_Cell_Time_Num;
GB_CHAR GB_WG_G_Cell_id[22] = {0};

// 获取状态
//static GB_WG_LACINF_STATE GB_WG_GetInfoState = GB_WG_LACINF_STATE_NONE;
static GB_WG_LACINF_FUNCALLBACK GB_WG_G_pFunCallback = GB_NULL;
static GB_VOID*	pGB_WG_LAC_G_User = GB_NULL;

#define GB_Cell_Time_Num    3

extern void GB_WG_Get_Cell_Msg(void);

GB_CHAR* GB_WG_Get_Cell_id()
{
	if (GB_WG_G_Cell_id[0] == 0)
	{
		return GB_NULL;
	}
	else
	{
		#ifdef __GB_WG_LACINF_DEBUG__
		GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","GB_WG_Get_Cell_id()函数中的：");
		GB_file_write_append_chars("c:\\guobi\\log_winguo.txt",GB_WG_G_Cell_id);
 	    GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
		#endif
		return GB_WG_G_Cell_id;
	}
	
}
/**********************************************************************
* 函数名称： GB_WG_Init_Lac
* 功能描述： 初始化参数
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Init_Lac(void)
{
	GB_MEMSET(GB_WG_G_lac,0,sizeof(GB_WG_G_lac));
	GB_MEMSET(GB_WG_G_Cell_Id,0,sizeof(GB_WG_G_Cell_Id));

	GB_WG_G_Cell_Time_Num = 0;
}

/*********************************************************************
* 函数名称： GB_WG_LAI_Info_Logs_Value
* 功能描述： 将获取到的参数保存
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_LAI_Info_Logs_Value(rr_em_lai_info_struct *rr_em_lai_info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	GB_WG_G_lai_info.mcc[0] = rr_em_lai_info->mcc[0];
	GB_WG_G_lai_info.mcc[1] = rr_em_lai_info->mcc[1];
	GB_WG_G_lai_info.mcc[2] = rr_em_lai_info->mcc[2];
	GB_WG_G_lai_info.mnc[0] = rr_em_lai_info->mnc[0];
	GB_WG_G_lai_info.mnc[1] = rr_em_lai_info->mnc[1];
	GB_WG_G_lai_info.mnc[2] = rr_em_lai_info->mnc[2];
	GB_WG_G_lai_info.lac[0] = rr_em_lai_info->lac[0];
	GB_WG_G_lai_info.lac[1] = rr_em_lai_info->lac[1];
	GB_WG_G_lai_info.cell_id = rr_em_lai_info->cell_id;
	#ifdef __GB_WG_LACINF_DEBUG__
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","GB_WG_LAI_Info_Logs_Value");
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
	//GB_WG_Trace("GB_WG_G_lai_info.cell_id的值为：%d",GB_WG_G_lai_info.cell_id);
	#endif
}

/**********************************************************************
* 函数名称： GB_WG_Info_Process_Log
* 功能描述： 取得消息的参数
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Info_Process_Log(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr)
{
	#ifdef __GB_WG_LACINF_DEBUG__
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","em_info");
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
	#endif
	//GB_WG_Trace("em_info的值为：%d",em_info);
	if (em_info == RR_EM_LAI_INFO)
	{
		rr_em_lai_info_struct *data_ptr;
		kal_uint16 mm_pdu_len;

		#ifdef __GB_WG_LACINF_DEBUG__
		GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","em_info == RR_EM_LAI_INFO");
		GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
		#endif

		/* Get the pdu_ptr where MM peer msg will be stored for transmission */
		data_ptr = (rr_em_lai_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
		GB_WG_LAI_Info_Logs_Value((rr_em_lai_info_struct*) data_ptr);
	}
	free_peer_buff(pdu_buff_ptr);
}

/**********************************************************************
* 函数名称： GB_WG_Start_Send_Req_Cell_Id
* 功能描述： 发送消息获取基站信息
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Start_Send_Req_Cell_Id (void)
{
	MYQUEUE Message;
	mmi_em_update_req_struct *em_start_req;
	U8 i=0;
	

	Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
	em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

	for (i=0;i<EM_INFO_REQ_NUM;i++)
	{
		em_start_req->info_request[i] = EM_NC;
	}

	em_start_req->info_request[RR_EM_LAI_INFO]=EM_ON;

	Message.oslDataPtr = (oslParaType*) em_start_req;
	Message.oslPeerBuffPtr = NULL;
	Message.oslSrcId = MOD_MMI;
	#ifdef __MMI_DUAL_SIM_MASTER__
	#ifdef GB_MTK_10APLAT
/* under construction !*/
	#else
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	{
		Message.oslDestId = MOD_L4C;
	}
	OslMsgSendExtQueue(&Message);

}

/**********************************************************************
* 函数名称： GB_WG_Get_Cell_Id
* 功能描述： 消息回调函数获得基站信息
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Get_Cell_Id(void *info)
{
	mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;

	kal_uint16 lac,cell_id;
	U8 i;
	char get_data[17]={0};
	char get_data1[17]={0};

	GB_WG_Info_Process_Log(msg->em_info, msg->info);
	ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);

	lac = GB_WG_G_lai_info.lac[0];
	lac = (lac<<8) + GB_WG_G_lai_info.lac[1];
	cell_id = GB_WG_G_lai_info.cell_id;
	if(cell_id==0||lac==0)
	{
		//GB_WG_SetLacState(GB_WG_LACINF_STATE_FAILURE);

		// 返回结果
		if (GB_WG_G_pFunCallback != GB_NULL)
		{
			GB_WG_G_pFunCallback(GB_WG_LACINF_STATE_FAILURE,GB_NULL,pGB_WG_LAC_G_User);
		}

		return;
	}

	for(i=0;i<3;i++)
	{
		if( GB_WG_G_lac[i] == 0 && GB_WG_G_Cell_Id[i] == 0 ) 
		{
			if(i==0)
			{
				GB_WG_G_lac[i] = lac;
				GB_WG_G_Cell_Id[i] = cell_id;
			}
			else if(i==1&&(GB_WG_G_lac[0] != lac||GB_WG_G_Cell_Id[0] != cell_id))
			{
				GB_WG_G_lac[i] = lac;
				GB_WG_G_Cell_Id[i] = cell_id;
			}
			else if((GB_WG_G_lac[0] != lac||GB_WG_G_Cell_Id[0] != cell_id)&&(GB_WG_G_lac[1] != lac||GB_WG_G_Cell_Id[1] != cell_id))
			{
				GB_WG_G_lac[i] = lac;
				GB_WG_G_Cell_Id[i] = cell_id;
			}
			
			break;
		}
	}

// 	if(GB_WG_G_Cell_Time_Num<(GB_Cell_Time_Num - 1))
// 	{
// 		// 这里会不会一直在请求呢
// 		GB_WG_Get_Cell_Msg();
// 	}
//	else
	{
		for(i=0;i<3;i++)/////判断获取到的cell id 的个数
		{
			if( GB_WG_G_lac[i] == 0 || GB_WG_G_Cell_Id[i] == 0 ) 
				break;
		}
		if(i<3)/////当获得的cell id个数小于3时
		{
			for(;i<3;i++)
			{
				GB_WG_G_lac[i] = GB_WG_G_lac[i-1];
				GB_WG_G_Cell_Id[i] = GB_WG_G_Cell_Id[i-1];
			}

			// 设置成功的标志位
			//GB_WG_SetLacState(GB_WG_LACINF_STATE_SUCCESS);
			// 返回结果
			if (GB_WG_G_pFunCallback != GB_NULL)
			{
				GB_WG_G_pFunCallback(GB_WG_LACINF_STATE_SUCCESS,GB_WG_Get_Cell_id(),pGB_WG_LAC_G_User);
			}
		}
		else
		{
			// 意味着失败？
			//GB_WG_SetLacState(GB_WG_LACINF_STATE_FAILURE);
			// 返回结果
			if (GB_WG_G_pFunCallback != GB_NULL)
			{
				GB_WG_G_pFunCallback(GB_WG_LACINF_STATE_FAILURE,GB_WG_Get_Cell_id(),pGB_WG_LAC_G_User);
		}
		}
	}
}

/**********************************************************************
* 函数名称： GB_WG_Check_Cell_Id
* 功能描述： 消息回调函数获得基站信息和存储的信息对比
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Check_Cell_Id(void *info)
{
	mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;

	kal_uint16 lac,cell_id;
	U8 i;
	char get_data[17]={0};
	char get_data1[17]={0};
	char get_data2[17]={0};
	char data[22]={0};

	GB_WG_Info_Process_Log(msg->em_info, msg->info);
	#if (defined(__MMI_DUAL_SIM_MASTER__) && !defined(GB_MTK_10APLAT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);

	lac = GB_WG_G_lai_info.lac[0];
	lac = (lac<<8) + GB_WG_G_lai_info.lac[1];
	cell_id = GB_WG_G_lai_info.cell_id;
	#ifdef __GB_WG_LACINF_DEBUG__
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","cell_id");
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
	#endif
    //GB_WG_Trace("cell的值为：%d",cell_id);
	if(cell_id==0||lac==0)
	{
		//GB_WG_SetLacState(GB_WG_LACINF_STATE_FAILURE);
		
		// 返回结果
		if (GB_WG_G_pFunCallback != GB_NULL)
		{
			GB_WG_G_pFunCallback(GB_WG_LACINF_STATE_FAILURE,GB_NULL,pGB_WG_LAC_G_User);
		}

		return;
	}

	memset(get_data, 0, sizeof(get_data));
	memset(get_data1, 0, sizeof(get_data1));
	memset(get_data2, 0, sizeof(get_data2));

	sprintf(get_data, "%d", GB_WG_G_lai_info.mcc[0]);
	sprintf(get_data1, "%d", GB_WG_G_lai_info.mcc[1]);
	sprintf(get_data2, "%d", GB_WG_G_lai_info.mcc[2]);

	strncat(data, get_data,sizeof(get_data));
	strncat(data,get_data1,sizeof(get_data1));
	strncat(data,get_data2,sizeof(get_data2));/////获得mcc信息
	strcat(data,"-");

	memset(get_data, 0, sizeof(get_data));
	memset(get_data1, 0, sizeof(get_data1));
	memset(get_data2, 0, sizeof(get_data2));
	sprintf(get_data, "%d", GB_WG_G_lai_info.mnc[0]);
	sprintf(get_data1, "%d", GB_WG_G_lai_info.mnc[1]);
	sprintf(get_data2, "%d", GB_WG_G_lai_info.mnc[2]);

	strncat(data,get_data,sizeof(get_data));
	strncat(data,get_data1,sizeof(get_data1));
	strncat(data,get_data2,sizeof(get_data2));////加上 mnc 信息
	strcat(data,"-");

	memset(get_data, 0, sizeof(get_data));
	memset(get_data1, 0, sizeof(get_data1));
	memset(get_data2, 0, sizeof(get_data2));
	sprintf(get_data, "%d", lac);
	sprintf(get_data1, "%d", cell_id);
	sprintf(get_data2, "%d", GB_WG_G_lai_info.nc_info_index);

	strncat(data,get_data1,sizeof(get_data));///加上lac 信息
	strcat(data,"-");
	strncat(data,get_data,sizeof(get_data1));///加上cell_id 信息

	strncpy(GB_WG_G_Cell_id, data, sizeof(data));
	#ifdef __GB_WG_LACINF_DEBUG__
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt",GB_WG_G_Cell_id);
	GB_file_write_append_chars("c:\\guobi\\log_winguo.txt","\r\n");
	#endif
    //GB_WG_Trace("GB_WG_G_Cell_id的值为：%s",GB_WG_G_Cell_id);
	memset(get_data, 0, sizeof(get_data));
	memset(get_data1, 0, sizeof(get_data1));
	memset(get_data2, 0, sizeof(get_data2));
	
/**********************************************************************
	在这里我们上传数据时只要把get_data 上传就可以了

***********************************************************************/

	for(i=0;i<3;i++)
	{
		if( GB_WG_G_lac[i] == lac && GB_WG_G_Cell_Id[i] == cell_id ) 
			break;
	}

	if(i >= 3)
	{
		GB_WG_G_lac[0] = GB_WG_G_lac[1];
		GB_WG_G_lac[1] = GB_WG_G_lac[2];
		GB_WG_G_Cell_Id[0] = GB_WG_G_Cell_Id[1];
		GB_WG_G_Cell_Id[1] = GB_WG_G_Cell_Id[2];
		GB_WG_G_lac[2] = lac; 
		GB_WG_G_Cell_Id[2] = cell_id;
	}
	
	//GB_WG_SetLacState(GB_WG_LACINF_STATE_SUCCESS);
	
	// 返回结果
	if (GB_WG_G_pFunCallback != GB_NULL)
	{
		GB_WG_G_pFunCallback(GB_WG_LACINF_STATE_SUCCESS,GB_WG_G_Cell_id,pGB_WG_LAC_G_User);
	}
}

/**********************************************************************
* 函数名称： GB_WG_Back_Req_Cell_Id
* 功能描述： 发送消息后返回是否成功的返回函数
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Back_Req_Cell_Id(void)
{

}


/**********************************************************************
* 函数名称： GB_WG_Check_Cell_Msg
* 功能描述： 发送消息检查基站信息
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
void GB_WG_Check_Cell_Msg(void)
{
	#ifdef __MMI_DUAL_SIM_MASTER__
	#ifndef GB_MTK_10APLAT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#endif
	{
		ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);
		SetProtocolEventHandler(GB_WG_Back_Req_Cell_Id, MSG_ID_MMI_EM_UPDATE_RSP);
		SetProtocolEventHandler(GB_WG_Check_Cell_Id, MSG_ID_MMI_EM_STATUS_IND);
	}
	GB_WG_Start_Send_Req_Cell_Id();
}


/**********************************************************************
* 函数名称： GB_WG_Get_Cell_Msg
* 功能描述： 发送消息获得基站信息
* 输入参数： 
* 输出参数： 无
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                        20100519                       创建
***********************************************************************/
GB_VOID GB_WG_Get_Cell_Msg(GB_VOID)
{
	ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);
	SetProtocolEventHandler(GB_WG_Back_Req_Cell_Id, MSG_ID_MMI_EM_UPDATE_RSP);
	SetProtocolEventHandler(GB_WG_Get_Cell_Id, MSG_ID_MMI_EM_STATUS_IND);
	GB_WG_Start_Send_Req_Cell_Id();
	//GB_WG_G_Cell_Time_Num++;
}

// GB_WG_LACINF_STATE GB_WG_GetLacState(GB_VOID)
// {
// 	return GB_WG_GetInfoState;
// }
// 
// GB_VOID GB_WG_SetLacState(GB_WG_LACINF_STATE state)
// {
// 	// 判断一个范围
// 	if (state >= GB_WG_LACINF_STATE_NONE && 
// 		state <= GB_WG_LACINF_STATE_END)
// 	{
// 		GB_WG_GetInfoState = state;
// 	}
// }

GB_VOID GB_WG_Get_Cell(GB_WG_LACINF_FUNCALLBACK pLacFunCallback,GB_VOID* pUser)
{
	GB_WG_G_pFunCallback = pLacFunCallback;
	pGB_WG_LAC_G_User = pUser;

	// 清空再获取
	GB_WG_Init_Lac();

	//GB_WG_Get_Cell_Msg();
	GB_WG_Check_Cell_Msg();
}

#endif
#endif /* #ifdef __MMI_GB_WINGUO__ */
