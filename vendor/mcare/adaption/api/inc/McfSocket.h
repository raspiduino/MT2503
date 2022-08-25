/***************************************************
* McrSocket.h
* socket macro ,struct,enum ,constant definition for MCARE usage
* by arlo,2010.09.19
****************************************************/

#ifndef _mcfsocket_h_
#define _mcfsocket_h_

#include "McfCommon.h"

#ifdef _cplusplus
extern "C "{
#endif

#define MCF_SOC_MAX_A_ENTRY (5)

//msoc type ,dns or socket
#define MCF_SOC_SLOT_NOTUSED (0)
#define MCF_SOC_SLOT_SOC (1)
#define MCF_SOC_SLOT_DNS (2)



typedef struct
{
	MBYTE				m_nRefCount;
	MUSHORT			m_nMsgLen;
}McfLocalParam; /* header */


typedef MINT MSocHandle;

typedef MVOID (*pfnMcfSocHandler)(MVOID*);
typedef MVOID (*pfnMcfDnsNotify)(MVOID *pUser,const MCHAR* pDomainName,MINT *pAddr, MINT ipCount);
typedef MVOID (*pfnMcfSocNotify)(MVOID *pUser, MINT socEvtType, MINT result);//socEvtType --EMSocEvtType

MSocHandle McfSoc_Create(MVOID *pUser,pfnMcfSocNotify notifyHandler);

MINT McfSoc_Close(MSocHandle socHd);
MINT McfSoc_Connect(MSocHandle socHd,const MINT addr,MUSHORT port);
MINT McfSoc_ConnectByName(MSocHandle socHd,const MCHAR* pName,MUSHORT port);
MINT McfSoc_Send(MSocHandle socHd, MBYTE *pBuf,MINT len);
MINT McfSoc_Recv(MSocHandle socHd,MBYTE *pBuf,MINT len);
MINT McfSoc_GetHostByName(MVOID *pUser,const MCHAR*  pName,MCHAR *pAddr,MINT *pAddrLen,pfnMcfDnsNotify hostNotifyHandler,MINT *pReqId);
MINT McfSoc_CancelGetHostByName(MINT requestId);

MINT  McfSoc_CloseAll(MVOID);

MINT McfHandleSocNotify(MVOID *pInfo);
MINT McfHandleDnsNotify(MVOID *pInfo);

MVOID *McfSocketInit(MVOID);
MVOID McfSocketDeinit(MVOID);

MBOOL McfSoc_IpCheck(MCHAR* asci_addr, MBYTE* ip_addr);
MUINT McfSoc_ntohl(MUINT x);
MUSHORT McfSoc_ntohs(MUSHORT x);
MUINT  McfSoc_htonl(MUINT x);
MUSHORT McfSoc_htons(MUSHORT x);




#ifdef _cplusplus
}
#endif
#endif
