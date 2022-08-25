#ifndef _mcftrace_h_
#define _mcftrace_h_

#include "MAdpConfig.h"

#include "McfCommon.h"

#define LOG_FILE_PATH	L"mcarelog\\log.txt" //mcare所在存储卡根目录下
#define LOG_DIR_NAME	L"mcarelog"
#define LOG_FILE_NAME	L"log.txt"
#define LOG_STR_Slash	L"\\"

#ifdef MCR_TRACE_DEBUG
#define USE_TRACE  (1) // (0) or (1)
#else
#define USE_TRACE  (0) // (0) or (1)
#endif


MVOID McfTrace_TraceFormatA(const MCHAR *format, ...);//平台trace实现，支持ANSI 字符串数据输入,如 MTrace_TraceFormatA("%s","log me");
MVOID McfTrace_TraceFormat(const MWCHAR* format, ...);//平台trace实现，支持UCS2字符串数据输入 如 MTrace_TraceFormat("%s",L"log me");
MVOID McfTrace_LogFormatA(const MCHAR *format, ...);//log记录到文件，ANSI
MVOID McfTrace_LogFormat(const MWCHAR* format, ...);//log记录到文件，UCS2
MVOID McfTrace_AssertFail(MCHAR* pExpr, MCHAR* pFileName, MINT nLine);

MVOID McfTraceInit(MVOID);
MVOID McfTraceDeinit(MVOID);


/*****************************************************************************
*通道log的通道(channel)
*****************************************************************************/
typedef enum 
{
	MLOG_NONE = 0,
	MLOG_SDKMEMORY,// 1
	MLOG_SDKFILE,// 2
	MLOG_SDKAPP,// 3
	MLOG_SDKGDI,//4
	MLOG_SDKAUDIO,//5
	MLOG_SDKSOCKET,//6
	MLOG_SDKSMS,//7
	MLOG_SDKTELEPHONE,//8
	MLOG_SDKPHONEBOOK,//9
	MLOG_SDKMISC,//10
	MLOG_SDKLOG,//11
	MLOG_SDKINPUT,//12
	MLOG_SDKUNZIP,//13
	MLOG_MGRKERN,//14
	MLOG_MGRNET,//15
	MLOG_MGRTMC,//16
	MLOG_MGRUI,//17
	MLOG_APPLICATION  ,//扩展，应用使用//18
	MLOG_FIRMFLOW,//扩展，应用使用//19
	MLOG_FIRMHTTP,//固化层http协议//20
	MLOG_CHANNEL_MAX
}TraceChannelEnum;


#define MLOG_INFO   ALOG_INFO
#define MLOG_WARN   ALOG_WARN
#define MLOG_ERROR  ALOG_ERROR
#define MLOG_LEVEL_MAX  ALOG_LEVEL_MAX


#define TRACE_CHANNEL_NUM					MLOG_CHANNEL_MAX
#define TRACE_MAX_LOG_LENGTH				256
#define TRACE_MAX_NAME_LENGTH				15
#define ATRACE_MAX_CHANNEL_INFO_STR_LENGTH  (32)


typedef struct  
{
	MBOOL m_bIsInitialized;    
	MCHAR m_ChannelControl[TRACE_CHANNEL_NUM];
	MCHAR m_ChannelLevel[TRACE_CHANNEL_NUM];
	MCHAR m_pTmpBuf[TRACE_MAX_LOG_LENGTH];
}MTrace;


#define TRACE8		McfTrace_TraceFormatA
#define LOG8		McfTrace_LogFormatA
#define McfTrace_LogPrintA McfLog_PrintMethod

#ifdef __MCARE_SEPERATE_NET_TASK__
#define MCF_TRACE_MOD   MOD_MCARE
#else
#define MCF_TRACE_MOD   MOD_SMS
#endif

#if (USE_TRACE == 1)
#define MTRACEANDLOG8(_x_)	TRACE8 _x_
#else
#define MTRACEANDLOG8(_x_)	\
{							\
	TRACE8 _x_;				\
	LOG8 _x_;				\
}
#endif

MVOID McfLog_PrintMethod(MCHAR level, MCHAR channel, const MCHAR *pFormat, ...);


//API LOG控制
#ifdef MFIRM_DEBUG
//#define MCR_DEBUG_PORTING_APIAUDIO
//#define MCR_DEBUG_PORTING_APISOCKET
//#define MCR_DEBUG_PORTING_APIMEMORY
//#define MCR_DEBUG_PORTING_APIGDI
//#define MCR_DEBUG_PORTING_APIFILE
//#define MCR_DEBUG_PORTING_APIMISC
//#define MCR_DEBUG_PORTING_APISMS
//#define MCR_DEBUG_PORTING_TIMER
#define MCR_DEBUG_PORTING_APISOCKET
#define MCR_DEBUG_PORTING_APIMEMORY
#define MCR_DEBUG_LOGIC_FLOW
#define MCR_DEBUG_LOGIC_HTTP
#endif

//AUDIO
#ifdef MCR_DEBUG_PORTING_APIAUDIO
#define MCFAPI_AUDIO_PRINT   McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_AUDIO_PRINT
#else
#define MCFAPI_AUDIO_PRINT(...)
#endif
#endif

//SOCKET
#ifdef MCR_DEBUG_PORTING_APISOCKET
#define MCFAPI_SOCKET_PRINT   McfLog_Print
#define MCFSOC_TRACE    McfTrace_TraceFormatA
#else
#ifdef WIN32
#define MCFAPI_SOCKET_PRINT
#define MCFSOC_TRACE    
#else
#define MCFAPI_SOCKET_PRINT(...)
#define MCFSOC_TRACE(...)
#endif
#endif

//MEMORY
#ifdef MCR_DEBUG_PORTING_APIMEMORY
#define MCFAPI_MEMORY_PRINT   McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_MEMORY_PRINT
#else
#define MCFAPI_MEMORY_PRINT(...)
#endif
#endif

//GDI
#ifdef MCR_DEBUG_PORTING_APIGDI
#define MCFAPI_GDI_PRINT   McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_GDI_PRINT
#else
#define MCFAPI_GDI_PRINT(...)
#endif
#endif

//FILE
#ifdef MCR_DEBUG_PORTING_APIFILE
#define MCFAPI_FILE_PRINT   McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_FILE_PRINT
#else
#define MCFAPI_FILE_PRINT(...)
#endif
#endif

//MISC
#ifdef MCR_DEBUG_PORTING_APIMISC
#define MCFAPI_MISC_PRINT   McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_MISC_PRINT
#else
#define MCFAPI_MISC_PRINT(...)
#endif
#endif

//SMS
#ifdef MCR_DEBUG_PORTING_APISMS
#define MCFAPI_SMS_PRINT	McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_SMS_PRINT
#else
#define MCFAPI_SMS_PRINT(...)
#endif
#endif

//TIMER
#ifdef MCR_DEBUG_PORTING_TIMER
#define MCFAPI_TIMER_PRINT		McfTrace_LogPrintA
#else
#ifdef WIN32
#define MCFAPI_TIMER_PRINT
#else
#define MCFAPI_TIMER_PRINT(...)
#endif
#endif


//LOGIC
#ifdef MCR_DEBUG_LOGIC_FLOW
#define MCFLOGIC_FLOW_PRINT		McfLog_PrintMethod
#else
#ifdef WIN32
#define MCFLOGIC_FLOW_PRINT     
#else
#define MCFLOGIC_FLOW_PRINT(...)     
#endif
#endif

#if 0  //by purple
/* under construction !*/
#ifdef MCR_DEBUG_LOGIC_HTTP
/* under construction !*/
#else
#ifdef WIN32
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif

//#define MCFAPI_PRINT   McfTrace_LogPrintA //McfCmn_LogPrint

#ifdef MCR_LOG_DEBUG
#define McfLog_Print	McfLog_PrintMethod
#else
#ifdef WIN32
#define McfLog_Print
#else
#define McfLog_Print(...)
#endif
#endif


#endif
