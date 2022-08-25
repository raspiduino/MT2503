#ifndef _mcfmisc_h_
#define _mcfmisc_h_

#include "McfCommon.h"
#include "McfTime.h"


typedef struct
{
    MBYTE ref_count; //LOCAL_PARA_HDR
    MUSHORT msg_len;
    
    MUINT nAppId;
    MINT nEvtId;
    MVOID *pData;
    MINT nSize;//data size
}McfAppMsg;



//extern QQINT _vsnwprintf_MCR(QQWCHAR *buf, QQUINT cnt, const QQWCHAR *fmt, va_list args);
//#define McfVsnwprintf _vsnwprintf_MCR


/*
参数：
simId --[in] 标识SIM，双卡手机会有2个IMEI ，EMcrSimCard
pImei --[out] 保存IMEI的buffer
len --[in] buffer的长度
返回值：
说明：
获取对应simId的IMEI号
*/
MVOID McfMisc_GetImei(MINT simId,MCHAR *pImei,MINT len);

/*
参数：
simId --[in] 标识SIM，EMcrSimCard
pImei --[out] 保存IMSI的buffer
len --[in] buffer的长度
返回值：
说明：
获取对应simId的IMSI号
*/
MVOID McfMisc_GetImsi(MINT simId,MCHAR *pImsi,MINT len);



MVOID McfMisc_GetCurLangCode(MCHAR *pLangCode,MINT nSize);

MINT McfMisc_SetBacklight(MINT nInterval,MINT nLevel);

MVOID McfMisc_GetSimImsi(MINT simId, MCHAR * pImsi, MINT nSize);

MINT McfMisc_GetCharPinyin(MUSHORT ucs2Char, MCHAR* pPinyin, MINT nSize);

MINT McfPhb_AddEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnAddCb);
MINT McfPhb_UpdateEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnUpdateCb);
MINT McfPhb_DelEntry(MVOID *pUser, MINT nId,MINT nStorage,pfnPhbNotifyCb fnDelCb);
MINT McfPhb_GetEntry(McfPhbEntry *pEntry);
MINT McfPhb_QueryStatus(MINT nStorage, MUSHORT *pTotalCount,MUSHORT *pUsedCount);
MINT McfPhb_QueryProperty(McfPhbProp *pProp);
MINT McfPhb_CancelOperation(MVOID *pUser,pfnPhbNotifyCb func);

MINT McfPhb_FindFirst(MINT nStorage,McfPhbEntry *pEntry);
MINT McfPhb_FindNext(MINT nPhbHandle,McfPhbEntry *pEntry);
MINT McfPhb_FindClose(MINT nPhbHandle);



MINT McfCam_Open(MVOID *pUser,MINT nCamId,MINT nMode,pfnCamNotify fnCamNotify);
MINT McfCam_Close(MINT nCamId,MINT nMode);
MINT McfCam_StartPreview(McfCamParam *pParam);
MINT McfCam_StopPreview(MVOID);
MINT McfCam_CaptureToFile(MWCHAR *pFilepath,MINT *pImgFmt);
MINT McfCam_CaptureToMem(MBYTE **ppBuffer, MUINT *pSize,MINT *pImgFmt);
MINT McfCam_QueryProperty(McfCamProp *pProp);//


/*************************************************
* McfMisc_RequestCellInfo
* @fnRequestCb --[in]callback function for request
* #return MTRUE --request ok
        MFALE --request fail
*/
MINT McfMisc_RequestCellInfo(MINT nSimId, MVOID *pUser, pfnCellInfoFunc fnRequestCb);
MVOID McfMisc_CancelCellInfo(MVOID * pUser, pfnCellInfoFunc fnRequestCb);
MINT McfMisc_DeliverMessage(MINT nAppId,MINT nEvtId,MVOID *pData,MINT nSize);

#endif
