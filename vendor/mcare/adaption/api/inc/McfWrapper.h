#ifndef _wrapper_inc_h_
#define _wrapper_inc_h_

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#if defined( _TENCENT_MCARE_ADP_ ) 
//#include "platform_inc.h"
#endif

#include "McfAudio.h"
#include "McfBrowser.h"
#include "McfChset.h"
#include "McfCommon.h"
#include "McfDtcnt.h"
#include "McfEditor.h"
#include "McfFs.h"
#include "McfGdi.h"
#include "McfGZip.h"
#include "McfIdle.h"
#include "McfKey.h"
#include "McfMemory.h"
#include "McfMisc.h"
#include "McfPen.h"
#include "McfSim.h"
#include "McfSms.h"
#include "McfSocket.h"
#include "McfStdLib.h"
#include "McfSys.h"
#include "McfTelephone.h"
#include "McfTime.h"
#include "McfTimer.h"
#include "McfTrace.h"
#include "McfUcs2.h"
#include "McfUsb.h"
#include "McfVibrate.h"
#include "McfIdle.h"

#if ((MCR_MTK_VER ==MTK_VER_1144) && (defined  (__COSMOS_MMI_PACKAGE__))) //by rico 1144
#define NICK_NAME_LEN 25
typedef struct  
{	
	U32    dwUid;						//发送者号码
	U32    dwCode;						//群Code  如果是群消息 这个字段有效
	U32    dwTime;						//发送时间
	U8    cType;						//消息类型
	U8    cFlag;						//发送者属性
	U16   wsName[NICK_NAME_LEN];		//昵称
	U16   wsMsgLen;
	U16*  pwsMsg;						//消息内容  
}stReadMsg;
//MMisc_DeliverMessage(10010000,MEVT_APP_SEND_MSG,msg,sizeof(stReadMsg));
//end
#endif

#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif 
