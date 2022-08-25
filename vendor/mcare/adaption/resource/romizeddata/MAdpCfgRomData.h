#ifndef _madpcfgromdata_h_
#define _madpcfgromdata_h_

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#include "McfCommon.h"
#include "MCommonDef.h"

typedef struct _RomAppCfg
{
    MUINT nAppId;
    MINT nType;
    MBYTE*pData;
    MUINT nSize;
    MCHAR *pVersion;
}SRomAppCfg;


#define APP_NAME_MAX_LENGTH (20)
#define APP_LOAD_URL_MAX_LENGTH (128)
#define APP_TYPE_NORMAL   (0x01)//普通型应用
#define APP_TYPE_LINK     (0x02)//链接型应用


typedef struct SDefaultAppInfo 
{
    MBYTE   m_nAppType;//type
    MUINT   m_nAppID;//id
    MWCHAR  m_wszAppName[APP_NAME_MAX_LENGTH];//app name (unicode ucs2)
    MCHAR   m_szURL[APP_LOAD_URL_MAX_LENGTH];/*url ,this is a link type app ,so URL means the destnation URL ,
                                               if it is a normal app it means the download url*/
}SDefaultAppInfo;

#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif //