/***************************************************
* McrSocket.c
* socket interface implement
* by arlo,2010.09.19

****************************************************/

#ifdef __MCAREV31__
#ifndef _TENCENT_MCARE_ADP_
#define _TENCENT_MCARE_ADP_
#endif
#include "MAdpConfig.h"
#include "McfPlatform.h"
#include "McfSocket.h"
#include "McfSocketAdp.h"
#include "McfMemory.h"
#include "McfSim.h"
#include "McfDtcnt.h"

#include "McfTrace.h"

#define MCF_SOC_MAX_COUNT (15)


extern MVOID McfSocket_ProtocolEventHandler(_fPsFuncPtr socHandler,_fPsFuncPtr dnsHandler);


typedef struct 
{
	MINT slotType;//0--not used,1--SOC,2--DNS
	MSocHandle socHd;//if it's DNS,request id used as socHd
	MVOID *pUser;
	MVOID *notifyHandler;
	//MVOID *pData;//
	MUSHORT port;
	MINT requestId;
}MSocket;

typedef struct 
{
	MSocket *pSocList;
	MINT socListCount;
}AppMSocket;

static AppMSocket *gAppMSocList;
#define SOC_CNTX()  ((AppMSocket*)gAppMSocList)
#define SOC_LIST()  (SOC_CNTX()->pSocList)

#ifdef MCR_MEM_DEBUG
extern MVOID* MKernPool_MallocDebug(MUINT nMemSize, MCHAR *pFileName, MINT nLineNo);
extern MVOID MKernPool_FreeDebug(MVOID* pMem, MCHAR *pFileName, MINT nLineNo);
#define MKernPool_Malloc(nSize)     MKernPool_MallocDebug(nSize,__FILE__,__LINE__)
#define MKernPool_Free(pBuffer)     MKernPool_FreeDebug(pBuffer,__FILE__,__LINE__)
#else
extern MVOID* MKernPool_Malloc(MUINT nMemSize);
extern MVOID MKernPool_Free(MVOID* pMem);
#endif

#define MSOC_CALLOC(size)   MKernPool_Malloc(size)
#define MSOC_FREE(ptr)      MKernPool_Free(ptr)

#define __GetSocSlot() __LookupSlot(MCF_SOC_SLOT_NOTUSED,0)
#define __LookupSocSlot(socHd)  __LookupSlot(MCF_SOC_SLOT_SOC,socHd)
#define __LookupDnsSlot(requestId)  __LookupSlot(MCF_SOC_SLOT_DNS,requestId)



/*__SocConvertError ,convert error code from plat to mcr
*@error --[in] plat error code
*#mcf error code
*/
MINT __SocConvertError(MINT error)
{
	if(error == MADP_SOC_WOULDBLOCK)
	{
		return MSOC_WOULDBLOCK;
	}
	else if(error == MADP_SOC_INVALID_SOCK)
	{
		return MSOC_INVALID_SOCKET;
	}
	else if(error == MADP_SOC_SUCCESS)
	{
		return MSOC_SUCCESS;
	}
	else if(error > 0)
	{
		return error;
	}
	else
	{
		return MSOC_FAIL;
	}
}

/*__SocConvertPlatEvtVal ,convert mcr soc event to plat
*@evtVal --[in] plat soc event
*#mcf soc event 
*/
MBYTE  __SocConvertPlatEvtVal(MBYTE evtVal)
{
	MBYTE val=0;

	if(evtVal & MADP_SOC_READ)
	{
		val |= MSOC_EVT_READ;
	}
	if(evtVal & MADP_SOC_WRITE)
	{
		val |= MSOC_EVT_WRITE;
	}
	if(evtVal & MADP_SOC_CONNECT)
	{
		val |= MSOC_EVT_CONNECT;
	}
	if(evtVal & MADP_SOC_CLOSE)
	{
		val |= MSOC_EVT_CLOSE;
	}

	return val;
}

static MVOID __ResetSocSlot(MSocket *pSoc)
{
	MCFSOC_TRACE(__MCR_FUNCTION__" Entry, pSoc = 0x%x", pSoc);

	if(pSoc)
	{
		memset(pSoc,0,sizeof(MSocket));
	}

	MCFSOC_TRACE(__MCR_FUNCTION__" Leave");
}

static MSocket *__LookupSlot(MINT slotType,MSocHandle socHd)
{
	MSocket *pSoc;
	AppMSocket *pAppMSoc;
	MINT idx=0;

	pAppMSoc = SOC_CNTX();

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,slotType:%d,socHd:%d",slotType,socHd); 
	MCFSOC_TRACE(__MCR_FUNCTION__" Entry,slotType:%d,socHd:%d, pAppMSoc = 0x%x", slotType, socHd, pAppMSoc); 

	if(pAppMSoc == MNULL)
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" Error : MSoc Context Struct NULL!!"); 
		MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" Error : MSoc Context Struct NULL!!"); 
		return MNULL;
	}

	pSoc = SOC_LIST();
	MCFSOC_TRACE(__MCR_FUNCTION__" pSoc = 0x%x", pSoc); 

	//print all soc
	while(idx < MCF_SOC_MAX_COUNT)
	{
		if(pSoc)
		{
			MCFSOC_TRACE(__MCR_FUNCTION__" pSoc = 0x%x, id = %d, socHd = %d, ", pSoc, idx, pSoc->socHd, pSoc->slotType); 
		}
		idx++;
		pSoc++;
	}

	idx = 0;
	pSoc = SOC_LIST();

	while(idx < MCF_SOC_MAX_COUNT)
	{
		if(pSoc)
		{
			MCFSOC_TRACE(__MCR_FUNCTION__" idx = %d, pSoc = 0x%x, socHd = %d", idx, pSoc, pSoc->socHd); 
			if(pSoc->slotType == slotType && pSoc->socHd == socHd) 
			{
				MCFSOC_TRACE(__MCR_FUNCTION__" ===========Look Up pSoc = 0x%x, id = %d, socHd = %d=========", pSoc, idx, pSoc->socHd);

				if(pSoc->slotType == MCF_SOC_SLOT_NOTUSED)
				{
					__ResetSocSlot(pSoc);
				}

				return pSoc;
			}
		}
		idx++;
		pSoc++;
	}

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave"); 

	return MNULL;
}

static MVOID __GetHostByNameCb(MVOID *pUser,const MCHAR* pDomainName,MINT *pAddr, MINT ipCount)
{//This is for MSoc_ConnectByName only....
	MINT ipAddr;
	MSocket *pConnSoc = (MSocket*)pUser;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,pUser:0x%x",pUser); 
	MCFSOC_TRACE(__MCR_FUNCTION__" pUser = 0x%x, pDomainName = %s, pAddr = 0x%x, ipCount = %d", pUser,  pDomainName, pAddr, ipCount); 

	if(pConnSoc == MNULL || pConnSoc->slotType== MCF_SOC_SLOT_NOTUSED) return ;

	// Eric: 复位requestID，避免解析成功依然会取消一次
	pConnSoc->requestId=0;

	if( ipCount>0)
	{
		ipAddr = *pAddr;//get the first ip address
		MCFSOC_TRACE(__MCR_FUNCTION__" McfSoc_Connect Ready"); 

		McfSoc_Connect(pConnSoc->socHd,ipAddr,pConnSoc->port);  

	}
	else
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" pConnSoc->notifyHandler = 0x%x, pConnSoc->pUser = 0x%x", pConnSoc->notifyHandler, pConnSoc->pUser); 
		if(pConnSoc->notifyHandler)
		{
			((pfnMcfSocNotify)(pConnSoc->notifyHandler))(pConnSoc->pUser,MSOC_EVT_CONNECT, MFALSE);
		}
	}

	MCFSOC_TRACE(__MCR_FUNCTION__" Leave"); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave"); 
}

/*MSoc_Create,create a TCP stream socket
*@pUser --[in] user of MSoc
*@notifyHandler --[in] callback func of MSoc
*#socket handle
*/
MSocHandle McfSoc_Create(MVOID *pUser,pfnMcfSocNotify notifyHandler)
{
	MSocket *pSoc;
	MSocHandle socHd = MSOC_INVALID_SOCKET;
	MUSHORT modId;
	MUINT accountId;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry"); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 

	pSoc =__GetSocSlot();
	MCFSOC_TRACE(__MCR_FUNCTION__" ========Create pSoc = 0x%x ==========", pSoc); 

	if(pSoc)
	{
		MBYTE val;

		modId = (MUSHORT)McfGetNetModId();
		accountId = McfDtcnt_GetDataAcctInfo()->acctId;

		MCFSOC_TRACE(__MCR_FUNCTION__" modId = %d, accountId = %d", modId, accountId); 

		//MCFSOC_TRACE(__MCR_FUNCTION__" ============Soc_create, AppId = %d =============", ((Applet *)APPM_GET_APPLET())->m_nAppId); 
		socHd = soc_create(MADP_PF_INET,MADP_SOC_STREAM,0,modId,accountId);

		//
		if(socHd < 0){
			return MSOC_INVALID_SOCKET;
		}

		MCFSOC_TRACE(__MCR_FUNCTION__" ============Soc_create socHd = %d", socHd); 
		val =1;
		if(soc_setsockopt(socHd,MADP_SOC_NBIO,&val,sizeof(MBYTE))<0)//None block mode
		{
			soc_close(socHd);
			return MSOC_INVALID_SOCKET;
		}

		val =MADP_SOC_READ|MADP_SOC_WRITE|MADP_SOC_CONNECT|MADP_SOC_CLOSE;
		if(soc_setsockopt(socHd,MADP_SOC_ASYNC ,&val,sizeof(MBYTE))<0)//Asynchronize notify
		{
			soc_close(socHd);
			return MSOC_INVALID_SOCKET;
		}

		if(socHd >= 0)
		{//create socket ok
			pSoc->slotType = MCF_SOC_SLOT_SOC;
			pSoc->socHd = socHd;
			pSoc->pUser = pUser;
			pSoc->notifyHandler =(MVOID*) notifyHandler;

			MCFSOC_TRACE(__MCR_FUNCTION__" ============Soc_create pSoc->notifyHandler = 0x%x============", pSoc->notifyHandler); 
		}
	}

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave,socHd=%d",socHd); 
	MCFSOC_TRACE(__MCR_FUNCTION__" Leave, socHd = %d", socHd); 

	return socHd;
}

MINT McfSoc_Close(MSocHandle socHd)
{
	MINT ret =MSOC_FAIL;
	MSocket *pSoc;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,socHd:%d",socHd); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry, socHd = %d", socHd); 

	// Eric: 做个保护
	if(socHd < 0){
		return MSOC_FAIL;
	}

	ret = soc_close(socHd);
	MCFSOC_TRACE(__MCR_FUNCTION__" soc_close ret = %d", ret); 

	pSoc =__LookupSocSlot(socHd);
	MCFSOC_TRACE(__MCR_FUNCTION__" pSoc = 0x%x", pSoc); 

	if(pSoc)
	{
		// Eric: 如果调用域名链接方式，还需要取消域名解析
		if(pSoc->requestId!=0){
			McfSoc_CancelGetHostByName(pSoc->requestId);    
		}

		MCFSOC_TRACE(__MCR_FUNCTION__" __ResetSocSlot"); 
		__ResetSocSlot(pSoc);
	}

	ret = __SocConvertError(ret);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave,ret:%d",ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__" leave,ret:%d",ret); 

	return ret;
}

/*MSoc_Connect
*@socHd --[in] socket handle
*@addr --[in] ip address as integer ,eg: 10.0.0.6 should as 0x060000a
*@port --[in] port number
#error code
*/
MINT  McfSoc_Connect(MSocHandle socHd,const MINT addr,MUSHORT port)
{//connet by ip address
	MINT ret;
	//MadpSocAddr sockaddr;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,socHd:%d,addr:0x%x,port:%d",socHd,addr,port); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry,socHd:%d,addr:0x%x,port:%d",socHd,addr,port); 

	ret = McfSocConnect(socHd,addr,port);
	ret = __SocConvertError(ret);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave,ret:%d",ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__" leave,ret:%d",ret); 

	return ret;
}

/*MSoc_ConnectByName
*@socHd --[in] socket handle
*@pName --[in] remote host name
*@port --[in] port number
*#error code
*/
MINT McfSoc_ConnectByName(MSocHandle socHd,const MCHAR* pName,MUSHORT port)
{
	MSocket *pSoc =__LookupSocSlot(socHd);
	MINT addr,addrLen;
	MINT ret= MSOC_FAIL;

	// Eric: 保存requestId 用于后面取消域名解析
	MINT requestId;

	if(pName==MNULL)
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" entry,pName NULL");
		MCFAPI_SOCKET_PRINT(ALOG_ERROR,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,pName NULL");
		return MSOC_FAIL;
	}

	MCFSOC_TRACE(__MCR_FUNCTION__" entry,socHd:%d,pName:%s,port:%d,pSoc:0x%x",socHd,pName,port,pSoc); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,socHd:%d,pName:%s,port:%d,pSoc:0x%x",socHd,pName,port,pSoc); 

	if(pSoc)
	{ 
		addrLen =sizeof(MINT);
		// Eric: 保存requestId 用于后面释放
		ret =McfSoc_GetHostByName(pSoc,pName,(MCHAR*)&addr,&addrLen,__GetHostByNameCb,&requestId);

		MCFSOC_TRACE(__MCR_FUNCTION__" McfSoc_GetHostByName ret = %d", ret); 

		if(ret ==MSOC_SUCCESS)
		{//not wouldblock,get ip immediately
			MCFSOC_TRACE(__MCR_FUNCTION__"  MCF_SOC_SUCCESS"); 
			ret = McfSoc_Connect(socHd,addr,port);
		}
		else if(ret ==MSOC_WOULDBLOCK)
		{
			MCFSOC_TRACE(__MCR_FUNCTION__"  MCF_SOC_WOULDBLOCK"); 
			// Eric: 去掉pData 避免不多次分配释放
			//pSoc->pData = (MVOID*)MSOC_CALLOC(sizeof(MINT));
			//if(pSoc->pData) 
			//{
			//*((MINT*)(pSoc->pData)) =port;
			//}
			pSoc->port=port;
			pSoc->requestId=requestId;

		}
	}

	ret = __SocConvertError(ret);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave,ret:%d",ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__"  leave,ret:%d",ret); 

	return ret; 
}

MINT McfSoc_Send(MSocHandle socHd, MBYTE *pBuf,MINT len)
{//
	MINT ret=MSOC_FAIL;
	if (pBuf==MNULL)
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" entry,pBuf NULL"); 
		MCFAPI_SOCKET_PRINT(ALOG_ERROR,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,pBuf NULL"); 
		return MSOC_FAIL;
	}

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,socHd:%d,pBuf:0x%x,len:%d",socHd,pBuf,len); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry,socHd:%d,pBuf:0x%x,len:%d",socHd,pBuf,len); 

	ret =soc_send(socHd,pBuf,len,0);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" before convert,ret:%d",ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__" before convert,ret:%d",ret); 

	ret = __SocConvertError(ret);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave, after convert ret:%d",ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__" leave, after convert ret:%d",ret); 

	return ret;
}
MINT McfSoc_Recv(MSocHandle socHd,MBYTE *pBuf,MINT len)
{
	MINT ret =MSOC_FAIL;

	if (pBuf==MNULL)
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" entry pBuf NULL"); 
		MCFAPI_SOCKET_PRINT(ALOG_ERROR,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry pBuf NULL"); 
		return MSOC_FAIL;
	}

	MCFSOC_TRACE(__MCR_FUNCTION__" entry,socHd:%d,pBuf:0x%x,len:%d",socHd,pBuf,len); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,socHd:%d,pBuf:0x%x,len:%d",socHd,pBuf,len); 

	ret = soc_recv(socHd,pBuf,len,0);

	MCFSOC_TRACE(__MCR_FUNCTION__" ============McfSoc_Recv socHd = %d, ret:%d =========",socHd, ret); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" before convert,ret:%d",ret); 

	ret = __SocConvertError(ret);

	MCFSOC_TRACE(__MCR_FUNCTION__" leave, after convert ret:%d",ret); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave, after convert ret:%d",ret); 

	return ret;
}

MINT McfSoc_GetHostByName(MVOID *pUser,const MCHAR*  pName,MCHAR *pAddr,
						  MINT *pAddrLen,pfnMcfDnsNotify hostNotifyHandler,MINT *pReqId)
{//
	MSocket *pSoc;
	MUINT accountId;
	MUSHORT modId;
	MINT ret=MSOC_FAIL,requestId,len;

	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry"); 

	if(pName ==MNULL) 
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" entry,pName NULL"); 
		MCFAPI_SOCKET_PRINT(ALOG_ERROR,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry,pName NULL"); 
		return MSOC_FAIL;
	}
	pSoc =__GetSocSlot();
	if(pSoc)
	{
		modId = (MUSHORT)McfGetNetModId();
		accountId = McfDtcnt_GetDataAcctInfo()->acctId;

		requestId=McfTime_GetSysTimeMs();//generate a request id

		MCFSOC_TRACE(__MCR_FUNCTION__" requestId = %d, accountId = %d", requestId); 
		MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" requestId = %d", requestId); 
		MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" accountId = %d", accountId); 

		ret =soc_gethostbyname(MFALSE,modId,requestId,pName,(MBYTE*)pAddr,(MBYTE*)pAddrLen,0,accountId);
		if(ret ==MADP_SOC_WOULDBLOCK)
		{
			pSoc->slotType = MCF_SOC_SLOT_DNS;//identify as DNS soc slot
			pSoc->socHd = requestId;//
			pSoc->pUser = pUser;
			pSoc->notifyHandler =(MVOID*) hostNotifyHandler;
		}
		if(pReqId)
		{
			*pReqId = requestId;
		}
	}

	ret = __SocConvertError(ret);

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave ret : %d", ret); 
	MCFSOC_TRACE(__MCR_FUNCTION__" leave ret : %d", ret); 

	return ret;
} 

MINT McfSoc_CancelGetHostByName(MINT requestId)
{
	MUSHORT modId;
	MINT ret;
	MSocket *pSoc;

	modId = (MUSHORT)McfGetNetModId();
	ret = soc_abort_dns_query(MTRUE, modId, MTRUE, requestId, MFALSE, 0, MFALSE,0);

	pSoc =__LookupDnsSlot(requestId);
	if(pSoc)
	{
		__ResetSocSlot(pSoc);
	}

	ret = __SocConvertError(ret);
	return ret;
}


MINT  McfSoc_CloseAll(MVOID)
{
	MSocket *pSoc;
	AppMSocket *pAppMSoc;
	MINT idx=0;

	pAppMSoc = SOC_CNTX();

	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry"); 
	if(pAppMSoc == MNULL)
	{
		MCFSOC_TRACE(__MCR_FUNCTION__" Error : MSoc Context Struct NULL!!"); 
		MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" Error : MSoc Context Struct NULL!!"); 
		return MSOC_FAIL;
	}

	pSoc = SOC_LIST();
	while(idx < MCF_SOC_MAX_COUNT)
	{
		if(pSoc)
		{
			if(pSoc->slotType==MCF_SOC_SLOT_SOC) 
			{
				soc_close(pSoc->socHd);

				// Eric: 此时回调不确定上层逻辑是否还存在，回调的意义也不大，故取消回调
				//if(pSoc->notifyHandler)
				//{
				//	((pfnMcfSocNotify)(pSoc->notifyHandler))(pSoc->pUser,MCF_SOC_EVT_CLOSE,MTRUE);
				//}
			}
			else if(pSoc->slotType ==MCF_SOC_SLOT_DNS)
			{
				soc_abort_dns_query(MFALSE, 0,MTRUE, pSoc->socHd, MFALSE, 0,MFALSE,0);
			}
			__ResetSocSlot(pSoc);//free soc data
		}
		idx++;
		pSoc++;
	}

	MCFSOC_TRACE(__MCR_FUNCTION__" leave"); 
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave"); 

	return MSOC_SUCCESS;
}


//[Internal use]
MVOID __McfHandleSocNotify(MINT socHd,MINT evtType,MINT result)
{
	MSocket *pSoc= MNULL;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry"); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 

	pSoc = __LookupSlot(MCF_SOC_SLOT_SOC,socHd);
	MCFSOC_TRACE(__MCR_FUNCTION__" pSoc = 0x%x, socket id = %d", pSoc, socHd); 
	if(pSoc)
	{
		MVOID *pUser;
		MVOID *notifyHandler;

		MCFSOC_TRACE(__MCR_FUNCTION__" pSoc->notifyHandler = 0x%x", pSoc->notifyHandler); 
		evtType = __SocConvertPlatEvtVal(evtType);

		pUser=pSoc->pUser;
		notifyHandler=pSoc->notifyHandler;

		//event close,free soc slot from list
		if(evtType == MSOC_EVT_CLOSE)
		{
			MCFSOC_TRACE(__MCR_FUNCTION__" MCF_SOC_EVT_CLOSE, __ResetSocSlot"); 
			// Eric: 此时不会处于域名解析，也不用考虑soc_close
			__ResetSocSlot( pSoc);
		}       

		MCFSOC_TRACE(__MCR_FUNCTION__" pSoc->pUser = 0x%x, evtType = %d, result = %d", pSoc->pUser, evtType, result);  
		if(notifyHandler!=0){
			((pfnMcfSocNotify)(notifyHandler))(pUser,evtType,result); 
		} 
	}

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave"); 
	MCFSOC_TRACE(__MCR_FUNCTION__" leave"); 
}

MVOID __McfHandleDnsNotify(MINT requestId,MBOOL result,MINT*pIpEntrys,MINT entryCnt)
{
	MSocket *pSoc = MNULL;

	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" entry"); 
	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 


	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, "request id:%d, result :%d",requestId,result); 
	pSoc = __LookupSlot(MCF_SOC_SLOT_DNS,requestId);
	if(pSoc && pSoc->notifyHandler)
	{
		//invoke notify callback
		MCFSOC_TRACE(__MCR_FUNCTION__" pfnMcfDnsNotify before, pSoc = 0x%x, pSoc->notifyHandler = 0x%x", pSoc, pSoc->notifyHandler); 

		MCFSOC_TRACE( __MCR_FUNCTION__" request_id = %d", requestId); 
		MCFSOC_TRACE( __MCR_FUNCTION__" result = %d",result); 

		// Eric: 去掉pData 避免多次分配释放 
		//((pfnMcfDnsNotify)(pSoc->notifyHandler))(pSoc->pUser,(const MCHAR*)pSoc->pData,(MINT*)ipEntry,pNotify->num_entry);
		((pfnMcfDnsNotify)(pSoc->notifyHandler))(pSoc->pUser,0,(MINT*)pIpEntrys,entryCnt);


		MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" pfnMcfDnsNotify"); 
		MCFSOC_TRACE(__MCR_FUNCTION__" pfnMcfDnsNotify"); 
	}

	__ResetSocSlot(pSoc);
	MCFAPI_SOCKET_PRINT(ALOG_INFO,MLOG_SDKSOCKET, __MCR_FUNCTION__" leave"); 
	MCFSOC_TRACE(__MCR_FUNCTION__" Leave"); 
}

/*McfSocIpCheck, check IPv4 address
*@asci_addr --[in] eg: "121.14.94.24"
*@ip_addr --[out] eg: ip_addr[0]=121,ip_addr[1]=14,ip_addr[2]=94,ip_addr[3]=24
#return
TRUE  -- ok
FALSE -- error
*/
MBOOL McfSoc_IpCheck(MCHAR* asci_addr, MBYTE* ip_addr)
{
#if 1
	kal_bool valid=MFALSE;
	soc_ip_check((kal_char *) asci_addr, (kal_uint8 *) ip_addr, (kal_bool *) &valid);//
	return valid;
#else//if no func soc_ip_check,use the following
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
}



MUINT McfSoc_ntohl(MUINT  x)
{
	return ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |
		(((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24));
}

MUSHORT McfSoc_ntohs(MUSHORT x)
{
	return ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8));
}

MUINT  McfSoc_htonl(MUINT  x)
{
	return McfSoc_ntohl(x);
}

MUSHORT McfSoc_htons(MUSHORT x)
{
	return McfSoc_ntohs(x);
}



MVOID *McfSocketInit(MVOID)
{
	MINT allocSize;

	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 

	if(gAppMSocList)
	{//has been inited
		return gAppMSocList;
	}
	allocSize = sizeof(AppMSocket)+ MCF_SOC_MAX_COUNT * sizeof(MSocket);
	gAppMSocList = MSOC_CALLOC(allocSize);

	if(gAppMSocList)
	{
		gAppMSocList->pSocList = (MSocket*)(gAppMSocList+1);
		gAppMSocList->socListCount = MCF_SOC_MAX_COUNT;
	}

	McfSocket_ProtocolEventHandler(McfHandleSocNotify,McfHandleDnsNotify);

	MCFSOC_TRACE(__MCR_FUNCTION__" leave"); 
	return gAppMSocList;
}

MVOID  McfSocketDeinit(MVOID)
{
	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 
	McfSoc_CloseAll();
	MSOC_FREE(SOC_CNTX());
	gAppMSocList = MNULL;
	McfSocket_ProtocolEventHandler(MNULL,MNULL);

	MCFSOC_TRACE(__MCR_FUNCTION__" leave"); 
}

#endif
