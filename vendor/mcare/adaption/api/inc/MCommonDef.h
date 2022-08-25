#ifndef _mcommon_h
#define _mcommon_h

/*app evt basic 
*create 应用程序入口函数ModEntry执行完，平台会立即向应用发送该消息
*destroy 应用程序主动调用MApp_DestroyApp方法或者平台强制杀死应用时发送该消息.  
*active只有前台应用才能收到，发生在应用程序刚加载时以及从挂起状态恢复到运行状态时
*inactive只有前台应用才能收到，发生在应用程序从运行状态进入挂起状态时，由外部事件触发；
*get focus仅有具有后台处理能力的程序才会收到该消息，在应用程序从后台切换成前台
*lose focus仅有具有后台处理能力的程序才会收到该消息，
 在应用程序主动或者被动从前台切换至后台时发送给应用，
 应用需要在该消息处理里尽量释放内存等资源给平台；
 被动切换发生在：本程序调起其它程序、alm、msg消息到来的情形下其它程序要求获取前台时
*/
#define MEVT_APP_CREATE           0x0   
#define MEVT_APP_DESTROY          0x1   
#define MEVT_APP_ACTIVE           0x2   
#define MEVT_APP_INACTIVE         0x3   
#define MEVT_APP_GET_FOCUS        0x6   
#define MEVT_APP_LOSE_FOCUS       0x7
#define MEVT_APP_ROTATE			  0x8
#define MEVT_APP_BGRSRV		      0x9//

//system event
#define MEVT_SMS         (20)
#define MEVT_MMS         (21)
#define MEVT_BT          (22)//bluetooth
#define MEVT_EMAIL       (23)
#define MEVT_CALL        (24)//param[ongoing/end]
#define MEVT_ROTATE      (25)//param[angle 0/90/180/270]
#define MEVT_CLAM        (26)//clam/slide open or close, param[open/close]
#define MEVT_MSF_QQ      (27)
#define MEVT_EXTERNAL    (49)

//custom define [100-150]
#define MEVT_APP_SEND_MSG					(0x64)
#define MEVT_APP_BRW_NOTIFY					(0x65)
#define MEVT_APP_DOWNFINISH_NOTIFY			(0x66)//download app success,notify mcare to reload tmc!!!!

// Key Events
#define MEVT_KEY_PRESS            0x100 // App keydown - wShortData = KEYCODE, dwParam = Bitflags for modifier keys
#define MEVT_KEY_RELEASE          0x102 // App keyRelease - wShortData = KEYCODE, dwParam = Bitflags for modifier keys
#define MEVT_KEY_HELD             0x103 // Key held - wShortData = KEYCODE, dwParam = Bitflags for modifier keys

// Pen Events...
#define MEVT_PEN_DOWN             0x504 // dwParam = position: signed x in upper 16 bits, y in lower
#define MEVT_PEN_UP               0x506 // dwParam = position: signed x in upper 16 bits, y in lower
#define MEVT_PEN_MOVE			  0x507 //


//event param.
//for get focus
#define MGET_FOCUS_NORMAL       (0)
#define MGET_FOCUS_BGAPP        (1)


#define MEVT_NONE       (0xffff)

#define MEvent_HI(dwParm)         ((MUSHORT)(((MUINT)(dwParm) >> 16) & 0x0000ffff))
#define MEvent_LO(dwParm)         ((MUSHORT)((MUINT)(dwParm) &  0x0000ffff))

#define MEvent_GET_X(dwParm)      MEvent_HI(dwParm)
#define MEvent_GET_Y(dwParm)      MEvent_LO(dwParm)

typedef enum
{
	EMCF_ENTRY_PAR_TYPE_NORMAL = 0x0,
	EMCF_ENTRY_PAR_TYPE_STARTAPP	=1,
	EMCF_ENTRY_PAR_TYPE_BGRUN	=2,//running as dameon program
	EMCF_ENTRY_PAR_TYPE_MAX
}EMcfEntryParamType;//

typedef struct
{
    MINT    m_nParamType;
    MUINT   m_nSrcAppId;
	MUINT   m_nDstAppID;
	MUINT   m_nCapLen;
	MCHAR*  m_pszCap;
	MUINT   m_nBufLen;	
	MVOID*  m_pBuf;	
}SMCareEntryParams;

typedef enum
{
    ECONTENTTYPE_COMMON = 0,
    ECONTENTTYPE_TMC,
    ECONTENTTYPE_TMZ,
    ECONTENTTYPE_ZIP
}EContentType;

typedef MINT E_EventType;
typedef MINT (*_fEventHandler)(E_EventType eEvtType, MINT nParam, MVOID *pParam);//消息处理函数的返回值0代表处理成功 <0 碰到问题了 -2内存不足 -3 代表处理不了该消息 -4代表不想处理 

typedef MUINT APPID;


//relocation info
#define RELOC_MAGIC       0x00ddccdd
#define RELOC_HEAD_FILEDS   (5)// each size is sizeof(MUINT)

#if defined(WIN32) //debug only
//模拟器上是否释放动态代码的DLL
#define SIMULATOR_FREE_SHELL_DLL    (1)//(0),(1)
#define SIMULATOR_FREE_APP_DLL      (1)//(0),(1)
#endif


#ifdef MSHELL_DEBUG
#define MSHELL_DEBUG_ENABLE
#endif

#define USE_HTTPDOWN

#define _MCR_VERIFY_TMC_FILE_

//type define for dosome1/dosome2
#define DOSO_CODEBUF_MEM    (0)
#define DOSO_ENDKEY_BACK     (1)//goback or return idle
#define DOSO_SOCREAD_INTERVAL    (2)//QYCommSocket,whether to read socket data continuously or not
#define DOSO_INST_BGPROP (3)//has app can background
#define DOSO_MULTIBG_SUPPORT (4)
#define DOSO_APP_NO_BG_SUPPORT (5)
#define DOSO_SINGLE_INST (6) 	
#define DOSO_MAX        (0xffff)

#endif
