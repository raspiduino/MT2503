#ifndef _mcfcommon_h_
#define _mcfcommon_h_
#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

//////////////////////////////////////////////////////////////////////////
/////////////////////////DEBUG开关////////////////////
//////////////////////////////////////////////////////////////////////////
//MCR_TRACE_DEBUG enable the most debug info, and change log into trace. for detect headache bugs.
//MCR_TRACE_DEBUG 1.用trace取代log；2.打开内存模块全部log；3.默认打开全部log通道
//#define MCR_TRACE_DEBUG    
//#define MCR_DEBUG       //enable all debug, include firmlayer ,shell , memory
//#define MFIRM_DEBUG     //enable firmlayer debug 
//#define MSHELL_DEBUG    //enable shell debug 
//#define MCR_MEM_DEBUG   //enable memory debug 
//#define MCR_MEM_MONITOR   //enable memory monitor,it'll print mem info on screen.



#ifdef MCR_TRACE_DEBUG

    #ifndef MCR_DEBUG
        #define MCR_DEBUG
    #endif 

#endif//MCR_TRACE_DEBUG


#ifdef MCR_DEBUG

    #ifndef MFIRM_DEBUG
        #define MFIRM_DEBUG
    #endif

    #ifndef MSHELL_DEBUG
        #define MSHELL_DEBUG
    #endif

    #ifndef MCR_MEM_DEBUG
        #define MCR_MEM_DEBUG //内存调试
        #ifdef MCR_MEM_DEBUG              
            #define ENABLE_QB_MEM_DEBUG //WIN32 模式下使用QQ浏览器的DEBUG模式，该宏应该保持常开        
        #endif        
    #endif

    #ifndef MCR_MEM_MONITOR
        #define MCR_MEM_MONITOR
    #endif    

#endif//MCR_DEBUG

//内存调试
#if defined(MCR_MEM_MONITOR) && !defined(MCR_MEM_DEBUG)
    #define MCR_MEM_DEBUG
#endif

//日志调试
#if defined(MFIRM_DEBUG) || defined(MSHELL_DEBUG)
    #define MCR_LOG_DEBUG
#endif

/****************************************************************************/
#define ALOG_INFO   (1)
#define ALOG_WARN   (2)
#define ALOG_ERROR  (3)
#define ALOG_LEVEL_MAX  (4)

#define  IN
#define  OUT


#ifndef MNULL
#define MFALSE  (0)
#define MTRUE   (1)
#define MNULL   ((void*)0)


typedef unsigned char       MBOOL;
typedef void                MVOID;
typedef char                MCHAR;//
typedef unsigned char       MBYTE;
typedef unsigned short      MWCHAR;
typedef signed short        MSHORT;
typedef unsigned short      MUSHORT;
typedef signed long         MLONG;
typedef unsigned long       MULONG;
typedef signed int          MINT;
typedef unsigned int        MUINT;
typedef unsigned __int64    MU64;
typedef __int64             MS64;
typedef unsigned char       MUINT8;
typedef signed char         MINT8;
typedef unsigned short      MUINT16;
typedef signed short        MINT16;
typedef unsigned long       MUINT32;
typedef signed long         MINT32;
typedef unsigned __int64    MUINT64;
typedef __int64             MINT64;


#endif

#ifndef txmax
#define txmax(a,b)    (((a) > (b)) ? (a) : (b))
#endif

#ifndef txmin
#define txmin(a,b)    (((a) < (b)) ? (a) : (b))
#endif


/* 文件全路径长度 */
#define __MCR_MAX_PATH_LENGTH__		(80)

/* 文件名长度 */
#define __MCR_MAX_FILE_NAME_LENGTH__	(32)

/* trace的缓冲长度 */
#define __MCR_MAX_TRACE_BUF_LENGTH__	(256)

/* IMEI, IMSI最大长度*/
#define __MCR_MAX_IMEI_IMSI_LENGTH__	(20)

/* APN最大长度 */
#define __MCR_MAX_APN_LENGTH__			(20)

/* LC最大长度 */
#define __MCR_MAX_LC_LENGTH__			(20)

/* TerminalType最大长度 */
#define __MCR_MAX_TERMINALTYPE_LENGTH__			(20)

/* 版本号最大长度 */
#define __MCR_MAX_VER_LENGTH__			(16)

/*appid的最大长度*/
#define __MCR_MAX_APPID_LENGTH__            (10)

#define UNUSED_PARAM(x)     (x) =(x)//make compiler happy.



#if defined(WIN32)

#define __MCR_INLINE__		__inline
#if _MSC_VER > 1200
#define __MCR_FUNCTION__	__FUNCTION__" : "
#else
#define __MCR_FUNCTION__	""
#endif // _MSC_VER

#elif defined(__ARMCC_VERSION) // or __CC_ARM

    #if (__ARMCC_VERSION < 200000) // or __CC_ARM
    
        #define __MCR_INLINE__		__inline
        #define __MCR_FUNCTION__	__func__" : "
    
    #else//#if (__ARMCC_VERSION < 200000) // or __CC_ARM
    
        #define __MCR_INLINE__		__inline
        #define __MCR_FUNCTION__	
        
    #endif

#elif defined(__GNUC__)

#define __MCR_INLINE__		inline
#define __MCR_FUNCTION__	__FUNCTION__" : "

#else

#define __MCR_INLINE__
#define __MCR_FUNCTION__

#endif // WIN32



typedef MVOID (*_fFuncPtr)(MVOID);
typedef MVOID (*_fPsExtFuncPtr)(MVOID*, MINT);
typedef MVOID (*_fFuncPtrU32)(MUINT);
typedef MVOID (*_fPsFuncPtr)(MVOID *);
typedef MBYTE (*_fPsIntFuncPtr)(MVOID *);
typedef MVOID (*_fKeyHandlerFuncPtr)(MVOID);
//typedef MVOID (*_fmmi_pen_hdlr)(TMCRPENPOINT pos);
typedef MVOID (*_fPsFuncPtrU16)(MVOID*, MUINT, MUSHORT);



#define MCR_ERR_MAX							(-100)
#define MCR_ERR_TCARD_LOWMEMORY				(-7)
#define MCR_ERR_NO_PERMISSION				(-6)
#define MCR_ERR_CANNT_AFFORD				(-5)
#define MCR_ERR_INVALID_USE					(-4)
#define MCR_ERR_INVALID_PARAMETER			(-3)
#define MCR_ERR_LOW_MEMORY					(-2)
#define MCR_FAIL                            (-1)
#define MCR_SUCCESS                         (0)    

#ifndef __define_audio__
#define __define_audio__

#define MAUD_SUCCESS            MCR_SUCCESS
#define MAUD_FAIL               MCR_FAIL
#define MAUD_NO_PERMISSION      MCR_ERR_NO_PERMISSION
#define MAUD_OPEN_FILE_FAIL     MCR_ERR_MAX + 20
#define MAUD_FINISH             MCR_ERR_MAX + 21
#define MAUD_TERMINATED         MCR_ERR_MAX + 22
#define MAUD_BAD_FORMAT         MCR_ERR_MAX + 23
#define MAUD_BUSY               MCR_ERR_MAX + 24
#define MAUD_DISC_FULL          MCR_ERR_MAX + 25

//[0..5]
#define MAUD_PLAY_ONCE			(0)	//播放一次
#define MAUD_PLAY_FOREVER		(1)	//播放N次
//[6..7]
#define MAUD_NO_SILENT      (1<<6)//ignore silent profile,still play audio
#define MAUD_RESERVED      (1<<7)

//format
#define MAUD_MIDI    17		//MEDIA_SMF
#define MAUD_WAV     13		//MEDIA_WAV
#define MAUD_AMR     3      //MEDIA_AMR


#define MAUD_VOL_MUTE       0
#define MAUD_VOL_LEVEL1     1
#define MAUD_VOL_LEVEL2     2
#define MAUD_VOL_LEVEL3     3
#define MAUD_VOL_LEVEL4     4
#define MAUD_VOL_LEVEL5     5
#define MAUD_VOL_LEVEL6     6
#define MAUD_VOL_LEVEL7     7
#define MAUD_VOL_MAX        0xf//

#define MAUD_SRC_BUFFER     0
#define MAUD_SRC_FILE       1

typedef MVOID (*pfnMcfAudFunc)(MVOID *pUser,MINT result);
typedef MVOID (*pfnAudFunc)(MVOID *pUser,MINT result);

typedef struct _McfAudRecord
{
    MWCHAR *pFilename;
    MINT nFormat;
    MINT nQuality;
    MINT nSizeLmt;
    MINT nTimeLmt;
}McfAudRecord;

#endif//__define_audio__

#ifndef __define_pen__
#define __define_pen__

//pen事件
#define MEVTPEN_DOWN		0x504
#define MEVTPEN_UP          0x506
#define MEVTPEN_MOVE        0x507
#define MEVTPEN_NONE        0xffff

#endif //__define_pen__

#ifndef __define_gdi__
#define __define_gdi__
//颜色
typedef MUINT  MColor;//GDI COLOR

#define  MGDI_SUCCESS		(0)
#define  MGDI_ERROR			(-1)
#define  MGDI_PARAM_ERR		(-2)

//字体大小
#define  MGDI_FONTSIZE_SMALL    (0)//小
#define  MGDI_FONTSIZE_MEDIUM   (1)//中
#define  MGDI_FONTSIZE_LARGE    (2) //大

//字体属性
#define  MGDI_FONTATTR_NORMAL				(1<<1)//正常
#define  MGDI_FONTATTR_BOLD					(1<<2)//粗体
#define  MGDI_FONTATTR_ITALIC				(1<<3)//斜体
#define  MGDI_FONTATTR_UNDERLINE			(1<<4)// 下划线


/* 图像类型 */
#define MGDI_IMG_ERR     (0)
#define MGDI_IMG_BMP     (1)
#define MGDI_IMG_PNG     (2)
#define MGDI_IMG_GIF     (3)
#define MGDI_IMG_JPG     (4)
#define MGDI_IMG_TIF     (5)


/*仅使用在文本的颜色*/
typedef struct
{
	MBYTE		m_nRed;
	MBYTE		m_nGreen;
	MBYTE		m_nBlue;
	MBYTE		m_nAlpha;
}MGdiColor;

typedef  MINT TMCRIMAGE;
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	MINT     m_imageType;//图片类型
	MUINT    m_nWidth;//图片高度
	MUINT    m_nHeight;//图片宽度
	MUINT    m_nImageSize;
	MBYTE*   m_pImageBuffer;
}MImageInfo,*PMImageInfo;

#endif //__define_gdi__

#ifndef __define_time__
#define __define_time__ 
typedef struct 
{
	MUSHORT		m_nYear;
	MBYTE		m_nMonth;
	MBYTE		m_nDay;
	MBYTE		m_nHour;
	MBYTE		m_nMinute;
	MBYTE		m_nSecond;
	MBYTE		m_nWeekday;	// 星期几，0: Sunday, 1: Monday, ...
}MTime_DateTime;

#endif //__define_time__

#ifndef __define_file__
#define __define_file__

typedef MINT MFd; 

//文件属性
#define MFILE_ATTR_NONE                 0x0 //no attribute bits ,normal
#define MFILE_ATTR_READ_ONLY            0x01
#define MFILE_ATTR_HIDDEN               0x02
#define MFILE_ATTR_DIR                  0x10

//文件错误码
#define MFILE_ERR_NOT_FOUND				MCR_ERR_MAX + 1
#define MFILE_ERR_DIR_EXIST				MCR_ERR_MAX + 2
#define MFILE_ERR_BAD_PARAM				MCR_ERR_MAX + 3
#define MFILE_ERR_BAD_FSNAME			MCR_ERR_MAX + 4
#define MFILE_ERR_BAD_DATA				MCR_ERR_MAX + 5
#define MFILE_ERR_LOCKED				MCR_ERR_MAX + 6
#define MFILE_ERR_BUFFER_FULL			MCR_ERR_MAX + 7
#define MFILE_ERR_DISK_FULL				MCR_ERR_MAX + 8
#define MFILE_ERR_NOT_READY				MCR_ERR_MAX + 9
#define MFILE_ERR_ALREADY_EXIST			MCR_ERR_MAX + 10
#define MFILE_ERR_NO_PERMISSION         MCR_ERR_NO_PERMISSION
#define MFILE_SUCCESS                   MCR_SUCCESS
#define MFILE_FAIL                      MCR_FAIL

//open flag
#define MFILE_OPEN_RO	0	//只读
#define MFILE_OPEN_RW	1	//可读写
#define MFILE_OPEN_CW	2	//打开一个空文件读写，如果文件存在内容会清空，不存在就创建该文件

//seek type
#define MFILE_SEEK_SET	0	//开始位置
#define MFILE_SEEK_CUR	1	//当前位置
#define MFILE_SEEK_END	2	//结束位置


//file
typedef struct
{
	MBYTE			m_nAttr;				// 属性
	MTime_DateTime  m_Time;					// 时间
	MUINT			m_nSize;				// 大小
	MWCHAR			m_wszFileFullName[256]; // 全路径名
	MUINT			m_nPos;	                // 考虑去掉？
}MFileInfo;
#endif //__define_file__

#ifndef __define_editor__
#define __define_editor__
//旧式输入法  输入法ENUM
#define MEDITOR_TYPE_CHARACTER			(0)//文字（所有字符）
#define MEDITOR_TYPE_NUMBERS			(1)//仅仅数字	 
#define MEDITOR_TYPE_PASSWORD			(2)//密码模式
#define MEDITOR_TYPE_LETTER				(3)//文字（英文）
#define MEDITOR_TYPE_UNKOWN				(4)


////////////////////////////////////////////
//新式输入法 inputType 输入法
#define MEDITOR_SYMBOLS					0x01
#define MEDITOR_LETTERS					0x02
#define MEDITOR_NUMBERS					0x04
#define MEDITOR_PINYIN					0x08
#define MEDITOR_STROKE					0x10


//显示属性
#define MEDITOR_PROPERTY_PASSWORD	(1)
#define MEDITOR_PROPERTY_NORMAL		(0)
////////////////////////////////////////////

//编辑完成之后的回调
typedef void (*pfnMcfInputCb)(void *pUser,void *pData,int len, int nCode);


//MTK 软键盘输入
#define MEDITOR_MSG_INPUT        (-1)
#define MEDITOR_MSG_UIUPDATE     (-2)
#define MEDITOR_MSG_EXIT         (-3)
#define MEDITOR_TYPE_MTKEDIT     (-4)//for in-screen edit
#define MEDITOR_MSG_CLOSEEDIT    (-5)//当应用发这个类型时，关闭edit
#define MEDITOR_MSG_EDITRANGE    (-6) //应用发给固化层edit的range

typedef struct
{
	MUINT			m_nX;				// 
	MUINT			m_nY;				// 大小
	MUINT			m_nWidth;				// 大小
	MUINT			m_nHeight;				// 大小
}MEditRangeInfo;
#endif// __define_editor__


#ifndef __define_timer__
#define __define_timer__
//TIMER 句柄定义
typedef MINT MTmHandle;
//TIMER  回调函数原型
typedef  MVOID (*pfnTimerFuncPtr)(MVOID *pUser); 
#endif// __define_timer__


#ifndef __define_socket__
#define __define_socket__

#define MSOC_SUCCESS           		(0)
#define MSOC_FAIL               	(-1)
#define MSOC_WOULDBLOCK         	(-2)
#define MSOC_INVALID_SOCKET     	(-4)


//socket event type
#define MSOC_EVT_READ       	(0x01)
#define MSOC_EVT_WRITE      	(0x02)
#define MSOC_EVT_CONNECT    	(0x08)
#define MSOC_EVT_CLOSE      	(0x10)
#endif //__define_socket__


#ifndef __define_sms__
#define __define_sms__
#define MENCODE_ASCII   (0)
#define MENCODE_UCS2    (1)

/*add by rico   0-->pop  1-->not pop*/
#define MSMS_OPT_POP        (0)
#define MSMS_OPT_NPOP       (1)  

/*pfnSmsSendCb 
* result =0 --success
* result !=0 --fail
*/
typedef MVOID (*pfnMcfSmsSendCb)(MVOID *pUser,MINT result);
#endif //__define_sms__


#ifndef __define_dtcnt__
#define __define_dtcnt__

#define MAX_NET_INFO_CNT  (6)

typedef struct _MApnInfo
{
	MBYTE nSimId;//
	MBYTE nSimOptr;//sim operator
	MBYTE nBearer;
	MBYTE nApnCount;
	MWCHAR *pName;//should be global buffer
	MWCHAR *pApnName[8];  //element should be global buffer  
	MBYTE apnType[8];
	MBYTE nToSelApn;//whether to display apn selection or not
}MApnInfo;

typedef struct _MNetInfo
{
	MINT nCount;
	MINT nActSimCnt;
	MApnInfo apnInfo[MAX_NET_INFO_CNT];
}MNetInfo;

//apn
#define MAPN_WAP    0
#define MAPN_NET    1
#define MAPN_WIFI   2
#define MAPN_TOTAL  0xf

//bearer
#define MBEARER_CSD     (1<<0)
#define MBEARER_GPRS    (1<<1)    
#define MBEARER_CDMA    (1<<2)
#define MBEARER_EDGE    (1<<3)
#define MBEARER_3G      (1<<4)
#define MBEARER_WIFI    (1<<5)
#define MBEARER_UNKNOWN 0

#define MAPN_NAME_SIZE    32
typedef struct __McfDtcntInfo
{
	MUINT acctId;
	MBYTE simId;// MSIM_xxx
	MBYTE apnType;//MAPN_xxx
	MBYTE opr; //MSIM_OPR_xxx
	MBYTE bearer;// MBEARER_xxx
	MCHAR apnName[MAPN_NAME_SIZE];
}McfDtcntInfo;
#endif //__define_dtcnt__


#ifndef __define_sim__
#define __define_sim__
//sim card
#define MSIM_CARD1       (1<<0)
#define MSIM_CARD2       (1<<1)
#define MSIM_CARD3       (1<<2)
#define MSIM_CARD4       (1<<3)
#define MSIM_VWIFI       (1<<4) //virtual   by puprple fixed wifi problem
#define MSIM_DUALCARD    (MSIM_CARD1|MSIM_CARD2)
#define MSIM_TRICARD     (MSIM_DUALCARD|MSIM_CARD3)
#define MSIM_QUADCARD    (MSIM_TRICARD|MSIM_CARD4)
#define MSIM_NONE        (0)

//sim operator
#define MSIM_OPR_CMCC       (1<<0)/* 中国移动*/
#define MSIM_OPR_UNICOM     (1<<1)/* 中国联通*/
#define MSIM_OPR_TELCOM     (1<<2)/* 中国电信*/
#define MSIM_OPR_WIFI		(1<<3)/* wifi */
#define MSIM_OPR_UNKOWN     (1<<15)/* 未知*/
#define MSIM_OPR_NONE       (0)/*invalid*/

#endif //__define_sim__

#ifndef __define_key__
#define __define_key__

//键值
#define MKEY_BASE (0xE020) /*For Keys*/
#define MKEY_0 (MKEY_BASE+1)
#define MKEY_1 (MKEY_BASE+2)
#define MKEY_2 (MKEY_BASE+3)
#define MKEY_3 (MKEY_BASE+4)
#define MKEY_4 (MKEY_BASE+5)
#define MKEY_5 (MKEY_BASE+6)
#define MKEY_6 (MKEY_BASE+7)
#define MKEY_7 (MKEY_BASE+8)
#define MKEY_8 (MKEY_BASE+9)
#define MKEY_9 (MKEY_BASE+10)
#define MKEY_STAR   (MKEY_BASE+11)
#define MKEY_POUND  (MKEY_BASE+12)
#define MKEY_POWER  (MKEY_BASE+13)
#define MKEY_END     (MKEY_BASE+14)
#define MKEY_SEND    (MKEY_BASE+15)
#define MKEY_CLR     (MKEY_BASE+16)
#define MKEY_UP      (MKEY_BASE+17)
#define MKEY_DOWN    (MKEY_BASE+18)
#define MKEY_LEFT    (MKEY_BASE+19)
#define MKEY_RIGHT   (MKEY_BASE+20)
#define MKEY_SELECT  (MKEY_BASE+21)
#define MKEY_SOFT1   (MKEY_BASE+22)//左软键
#define MKEY_SOFT2   (MKEY_BASE+23)//右软键
#define MKEY_SOFT3   (MKEY_BASE+24)//设备不一定有，慎用
#define MKEY_SOFT4   (MKEY_BASE+25)//设备不一定有，慎用
#define MKEY_SIDEUP		(MKEY_BASE+26)//侧键1
#define MKEY_SIDEDOWN	(MKEY_BASE+27)//侧键2
#define MKEY_FUNCTION3 (MKEY_BASE+28)//设备不一定有，慎用
#define MKEY_FUNCTION4   (MKEY_BASE+29)//设备不一定有，慎用
#define MKEY_MENU        (MKEY_BASE+30)//设备不一定有，慎用
#define MKEY_INFO        (MKEY_BASE+31)//设备不一定有，慎用
#define MKEY_SHIFT       (MKEY_BASE+32)//设备不一定有，慎用
#define MKEY_MESSAGE     (MKEY_BASE+33)//设备不一定有，慎用
#define MKEY_MUTE        (MKEY_BASE+34)//设备不一定有，慎用
#define MKEY_STORE       (MKEY_BASE+35)//设备不一定有，慎用
#define MKEY_RECALL      (MKEY_BASE+36)//设备不一定有，慎用
#define MKEY_PUNC1       (MKEY_BASE+37)//设备不一定有，慎用
#define MKEY_PUNC2       (MKEY_BASE+38)//设备不一定有，慎用
#define MKEY_VOLUME_UP       (MKEY_BASE+39)
#define MKEY_VOLUME_DOWN     (MKEY_BASE+40)
#define MKEY_WEB_ACCESS      (MKEY_BASE+41)//设备不一定有，慎用
#define MKEY_VOICE_MEMO      (MKEY_BASE+42)//设备不一定有，慎用
#define MKEY_SPEAKER         (MKEY_BASE+43)//设备不一定有，慎用
#define MKEY_TAP             (MKEY_BASE+44)// TAP Event
#define MKEY_PTT             (MKEY_BASE+45)//设备不一定有，慎用
#define MKEY_LSHIFT          (MKEY_BASE+46)//left shift 设备不一定有，慎用
#define MKEY_RSHIFT          (MKEY_BASE+47)//right shift 设备不一定有，慎用
#define MKEY_LCTRL           (MKEY_BASE+48)//left ctrl 设备不一定有，慎用
#define MKEY_RCTRL           (MKEY_BASE+49)//right ctrl设备不一定有，慎用
#define MKEY_LALT            (MKEY_BASE+50)//left alt 设备不一定有，慎用
#define MKEY_RALT            (MKEY_BASE+51)//right alt 设备不一定有，慎用
#define MKEY_CAPLK           (MKEY_BASE+52)//cap lock 设备不一定有，慎用
#define MKEY_SCRLK           (MKEY_BASE+53)//scroll lock 设备不一定有，慎用
#define MKEY_NUMLK           (MKEY_BASE+54)//num lock 设备不一定有，慎用
#define MKEY_LNGHANGUL       (MKEY_BASE+55)//设备不一定有，慎用
#define MKEY_LNGJUNJA        (MKEY_BASE+56)//设备不一定有，慎用
#define MKEY_LNGFIN          (MKEY_BASE+57)//设备不一定有，慎用
#define MKEY_LNGHANJA        (MKEY_BASE+58)//设备不一定有，慎用
#define MKEY_PRSCRN          (MKEY_BASE+59)//print screen 设备不一定有，慎用
#define MKEY_BREAK           (MKEY_BASE+60)//break 设备不一定有，慎用
#define MKEY_TXINSERT        (MKEY_BASE+61)//insert 设备不一定有，慎用
#define MKEY_TXDELETE        (MKEY_BASE+62)//delete 设备不一定有，慎用
#define MKEY_TXHOME          (MKEY_BASE+63)//home 设备不一定有，慎用
#define MKEY_TXEND           (MKEY_BASE+64)//end 设备不一定有，慎用
#define MKEY_TXPGUP          (MKEY_BASE+65)//page up 设备不一定有，慎用
#define MKEY_TXPGDOWN        (MKEY_BASE+66)//page down 设备不一定有，慎用
#define MKEY_A 	(MKEY_BASE+67)
#define MKEY_B	(MKEY_BASE+68)
#define MKEY_C	(MKEY_BASE+69)
#define MKEY_D	(MKEY_BASE+71)
#define MKEY_E	(MKEY_BASE+72)
#define MKEY_F	(MKEY_BASE+73)
#define MKEY_G	(MKEY_BASE+74)
#define MKEY_H	(MKEY_BASE+75)
#define MKEY_I	(MKEY_BASE+76)
#define MKEY_J	(MKEY_BASE+77)
#define MKEY_K	(MKEY_BASE+78)
#define MKEY_L	(MKEY_BASE+79)
#define MKEY_M	(MKEY_BASE+80)
#define MKEY_N	(MKEY_BASE+81)
#define MKEY_O	(MKEY_BASE+82)
#define MKEY_P	(MKEY_BASE+83)
#define MKEY_Q	(MKEY_BASE+84)
#define MKEY_R	(MKEY_BASE+85)
#define MKEY_S	(MKEY_BASE+86)
#define MKEY_T	(MKEY_BASE+87)
#define MKEY_U	(MKEY_BASE+88)
#define MKEY_V	(MKEY_BASE+89)
#define MKEY_W	(MKEY_BASE+90)
#define MKEY_X	(MKEY_BASE+91)
#define MKEY_Y	(MKEY_BASE+92)
#define MKEY_Z	(MKEY_BASE+93)
#define MKEY_SPACE	    (MKEY_BASE+94)//space
#define MKEY_TAB	    (MKEY_BASE+95)//tab
#define MKEY_SLASH	    (MKEY_BASE+96)//slash
#define MKEY_BACKSLASH  (MKEY_BASE+97)//back slash
#define MKEY_PERIOD	    (MKEY_BASE+98)//period
#define MKEY_COMMA	    (MKEY_BASE+99)//comma
#define MKEY_SQUOTE      (MKEY_BASE+100)//single quote
#define MKEY_SEMICOLON	(MKEY_BASE+101)//semicolon
#define MKEY_LSBRACKET	(MKEY_BASE+102)//left square bracket
#define MKEY_RSBRACKET	(MKEY_BASE+103)//right square backet
#define MKEY_BACKSPACE	(MKEY_BASE+104)//backspace
#define MKEY_ENTER	    (MKEY_BASE+105)//enter
#define MKEY_SYMBOL	    (MKEY_BASE+106)//symbol
#define MKEY_ESC        (MKEY_BASE+107)//esc
#define MKEY_NONE       (0xffff)


//事件
#define MEVTKEY_PRESS        0x100
#define MEVTKEY_RELEASE      0x102
#define MEVTKEY_LONGPRESS    0x103
#define MEVTKEY_REPEAT       0x104
#define MEVTKEY_NONE         0xffff

#endif //__define_key__

#ifndef __define_idle__
#define __define_idle__
//Idle 图标ID
#define MIDLE_ICON_MCARE			(1)
#define MIDLE_ICON_QQ_ONLINE		(2)
#define MIDLE_ICON_QQ_OFFLINE		(3)
#define MIDLE_ICON_QQ_AWAYLINE		(4)
#define MIDLE_ICON_QQ_INVISBLE		(5)
#define MIDLE_ICON_QQ_HAVEMSG		(6)
#define MIDLE_ICON_CONTACT		    (7)
#define MIDLE_ICON_TOTAL			(8)


//图标状态
#define MIDLE_ICON_SHOW				(0)
#define MIDLE_ICON_HIDE				(1)
#define MIDLE_ICON_BLINK			(2)
#define MIDLE_ICON_NONE				(3)


#endif //__define_idle__


#ifndef __define_phonebook__
#define __define_phonebook__
//phonebook storage
#define MPHB_ST_SIM1    (1<<0)
#define MPHB_ST_SIM2    (1<<1)
#define MPHB_ST_SIM3    (1<<2)
#define MPHB_ST_SIM4    (1<<3)
#define MPHB_ST_PHONE   (1<<8)
#define MPHB_ST_ALL     (MPHB_ST_SIM1|MPHB_ST_SIM2|MPHB_ST_SIM3|MPHB_ST_SIM4|MPHB_ST_PHONE)
#define MPHB_ST_NONE    (0)

#define MPHB_NAME_LENGTH           30 //character len
#define MPHB_NUMBER_LENGTH         40//
#define MPHB_NAMEPINYIN_LENGTH     15 //character len
#define MPHB_EMAIL_LENGTH          60
#define MPHB_URL_LENGTH            128
#define MPHB_BDAY_LENGTH            12
#define MPHB_TITLE_LENGTH           20
#define MPHB_COMPANY_LENGTH         20
#define MPHB_URL_LENGTH             128
#define MPHB_ADDRESS_LENGTH         25
#define MPHB_NOTE_LENGTH            30
#define MPHB_IMPS_LENGTH            61
#define MPHB_POC_LENGTH             62

#define MPHB_SUCCESS        (0)
#define MPHB_ERROR          (-1)
#define MPHB_WAIT           (-2)
#define MPHB_NOT_FOUND      (-3)
#define MPHB_STORAGE_FULL   (-4)
#define MPHB_BUSY           (-5)
#define MPHB_NO_PERMISSION  (MCR_ERR_NO_PERMISSION)

#define MPHB_SYNC   0
#define MPHB_ASYNC  1

//phb filed mask
#define MPHB_FILED_NAME                 (1<<0)
#define MPHB_FILED_NUMBER               (1<<1)
#define MPHB_FILED_HOMENUM              (1<<2)
#define MPHB_FILED_OFFICENUM            (1<<3)
#define MPHB_FILED_FAXNUM               (1<<4)
#define MPHB_FILED_COMPANYNAME          (1<<5)
#define MPHB_FILED_EMAIL                (1<<6)
#define MPHB_FILED_EMAIL2               (1<<7)
#define MPHB_FILED_BIRTH                (1<<8)
#define MPHB_FILED_TITLE                (1<<9)
#define MPHB_FILED_URL                  (1<<10)
#define MPHB_FILED_ADR_POBOX            (1<<11)
#define MPHB_FILED_ADR_EXT              (1<<12)
#define MPHB_FILED_ADR_STREET           (1<<13)
#define MPHB_FILED_ADR_CITY             (1<<14)
#define MPHB_FILED_ADR_STATE            (1<<15)
#define MPHB_FILED_ADR_POSTCODE         (1<<16)
#define MPHB_FILED_ADR_COUNTRY          (1<<17)
#define MPHB_FILED_NOTE                 (1<<18)


typedef MVOID (*pfnPhbNotifyCb)(MVOID *pUser, MINT nResult, MINT nId, MINT nStorage);

typedef struct
{
    MUSHORT    index;//group index
    MUSHORT name[MPHB_NAME_LENGTH+1];
} McfPhbGroup;

typedef struct
{
    MINT       id;
    MINT        storage;          
    MUSHORT    name[MPHB_NAME_LENGTH+1];
    MUSHORT    number[MPHB_NUMBER_LENGTH+1];
    MUSHORT    homeNumber[MPHB_NUMBER_LENGTH+1];
    MUSHORT    officeNumber[MPHB_NUMBER_LENGTH+1];
    MUSHORT    faxNumber[MPHB_NUMBER_LENGTH+1];
    MUSHORT    companyName[MPHB_NAME_LENGTH+1];
    MUSHORT    emailAddr[MPHB_EMAIL_LENGTH + 1];
    MUSHORT    emailAddr2[MPHB_EMAIL_LENGTH + 1];
    MUSHORT     birthYear;
    MBYTE       birthMon;
    MBYTE       birthDay;
    MUSHORT title[MPHB_TITLE_LENGTH + 1];                    /* contact title field(UCS2) */
    MUSHORT url[MPHB_URL_LENGTH + 1];                        /* contact url field(UCS2) */
    MUSHORT adrPobox[MPHB_ADDRESS_LENGTH + 1];              /* contact address-pobox field(UCS2) */
    MUSHORT adrExtension[MPHB_ADDRESS_LENGTH + 1];          /* contact address-extention field(UCS2) */
    MUSHORT adrStreet[MPHB_ADDRESS_LENGTH + 1];             /* contact address-street field(UCS2) */
    MUSHORT adrCity[MPHB_ADDRESS_LENGTH + 1];               /* contact address-city field(UCS2) */
    MUSHORT adrState[MPHB_ADDRESS_LENGTH + 1];              /* contact address-state field(UCS2) */
    MUSHORT adrPostalCode[MPHB_ADDRESS_LENGTH + 1];        /* contact address-state field(UCS2) */
    MUSHORT adrCountry[MPHB_ADDRESS_LENGTH + 1];            /* contact address-postal code field(UCS2) */
    MUSHORT note[MPHB_NOTE_LENGTH + 1];                      /* contact note field(UCS2) */
    McfPhbGroup       groupInfo;//not support now@Aug 24,2011,arlo      
}McfPhbEntry;

typedef struct
{
    MUINT mask;//contact fileds supported on phone
    MBYTE maxNameLen;//max name length allowed on phone
    MBYTE maxNumLen; //max number length allowed on phone
    MBYTE reserved1; //reserved,not used now.
    MBYTE reserved2;
}McfPhbProp;

typedef MVOID (*pfnForeachEntryCb)(McfPhbEntry *pEntry);

#endif//__define_phonebook__

#ifndef __define_rotate__
#define __define_rotate__
#define MSCREEN_ROTATE_0     (0)
#define MSCREEN_ROTATE_90    (1)
#define MSCREEN_ROTATE_180   (2)
#define MSCREEN_ROTATE_270   (3)
#endif//__define_rotate__


#ifndef __define_sys__
#define __define_sys__
#define MSYS_EXIT_NONE       (0)
#define MSYS_EXIT_MCARE      (1<<0)
#define MSYS_EXIT_GOBACK     (1<<1)
#define MSYS_EXIT_IDLE		 (1<<2)
#define MSYS_EXIT_OUTHDL	 (1<<3)//outside handle

#define MSYS_DELAY_EXIT     (1)
#define MSYS_DELAY_BACK     (2)

#define MCR_TCSTORE_DIR_NAME    L"tcstorev31"
#define MCR_STORE_DIR_NAME      L"storev31"
#define MCR_DOWN_DIR_NAME       L"mcare_dl"
#define MCR_KERN_LAYER_NAME     L"10000000.tmc"
#define MCR_KERN_LAYER_ZIP_NAME     L"10000000.tmz"
#define MCR_KERN_DLL_NAME       L"10000000.dll"
#define MCR_MODIS_ROOT          L"..\\..\\WIN32FS\\DRIVE_E"
#define MCR_KERN_LAYER_APPID    (10000000)
#define MCR_BRW_DL_FOLDER_NAME  L"QQDownload"

#endif//__define_sys__

#ifndef __define_mem__
#define __define_mem__
#define MMEM_MAIN				(0)
#define MMEM_KERN				(1)
#define MMEM_APP				(2)
#define MMEM_NONE               (0xff)
#endif

#ifndef __define_unzip__
#define __define_unzip__

#define Unzip_DCoder_Success_CallAgain		(0)
#define Unzip_DCoder_Success_Ok				(1)
#define Unzip_DCoder_Success_StreamEnd		(2)
#define Unzip_DCoder_Fail_Data				(3)
#define Unzip_DCoder_Fail_Memory			(4)

#define Unzip_DMode_Deflate					(0)
#define Unzip_DMode_GZip					(1)

#endif//__define_unzip__




/*================键盘触屏类型================*/
#ifndef __define_keytouch__
#define __define_keytouch__

//下述键盘类型宏定义用来上报后台终端属性
#define MKEYTYPE_NO_KEYPAD				(1)
#define MKEYTYPE_NORMAL_KEYPAD			(2)
#define MKEYTYPE_QWERTY_KEYPAD			(3)

//下述屏幕类型宏定义用来上报后台终端属性
#define MTOUCHSCREEN_NO					(1)
#define MTOUCHSCREEN_YES				(2)

#endif//__define_keytouch__



/*================UI================*/
#ifndef __define_uistyle__
#define __define_uistyle__

#define UI_THEME_BLUE			(0)
#define UI_THEME_PINK			(1)
#define UI_THEME_BROWN			(2)
#define UI_THEME_GREEN          (3)
#define UI_THEME_BLACK          (5)

#define UI_THEME_MAX            (6)//for max mark


#endif//__define_uistyle__

#ifndef __define_backlight__
#define __define_backlight__

//interval time
#define MBKL_TIME_DEFAULT        (0)
#define MBKL_TIME_PERMANENT      (0xffff)

//brightness level
#define MBKL_LEVEL_DEFAULT      (0)
#define MBKL_LEVEL_1      (1)
#define MBKL_LEVEL_2      (2)
#define MBKL_LEVEL_3      (3)
#define MBKL_LEVEL_4      (4)
#define MBKL_LEVEL_5      (5)
#define MBKL_LEVEL_6      (6)
#define MBKL_LEVEL_7      (7)
#define MBKL_LEVEL_8      (8)
#define MBKL_LEVEL_9      (9)
#define MBKL_LEVEL_10     (10)
#define MBKL_LEVEL_MAX     (MBKL_LEVEL_10)
#endif


#ifndef __define_camera__
#define __define_camera__

//camera id
#define MCAM_ID_FRONT  0
#define MCAM_ID_BACK   1

//camera ret code
#define MCAM_SUCCESS    0
#define MCAM_ERROR      -1
#define MCAM_BUSY       -2
#define MCAM_NO_DISK    -3
#define MCAM_DISK_FULL  -4

//camera status
#define MCAM_STATUS_IDLE            0
#define MCAM_STATUS_PREVIEW         1
#define MCAM_STATUS_CAPTURE         2

//camera open-mode
#define MCAM_MODE_LOCAL  0//launch local camera application directly
#define MCAM_MODE_USER   1//launch camera to preview,under user's control

typedef struct 
{
    //preview parameters
    MSHORT nPreviewX;//offset x of preview window
    MSHORT nPreviewY;//offset y of preview window
    MSHORT nPreviewWidth;
    MSHORT nPreviewHeight;
    MUINT nFlag;
    
    //capture parameters    
    MUSHORT nImgWidth;//image width to capture
    MUSHORT nImgHeight;//image height to capture
    MBYTE nImgQuality; //image quality(high/mid/low)
    MBYTE nImgFmt;//image format(maybe jpg/gif/bmp...)
    MBYTE nColorFmt;//color format(maybe rgb/yuv/...)
    MBYTE nReserved;
}McfCamParam;

typedef struct
{
    MUINT nFlag;//support image format, ...
}McfCamProp;


typedef MVOID (*pfnCamNotify)(MVOID *pUser,MINT nStatus,MINT nParam,MVOID *pParam);

#endif

#ifndef __define_cellinfo__
#define __define_cellinfo__
typedef struct
{			
	MUINT16	cellId;
	MUINT8	mcc[3];
	MUINT8	mnc[3];
	MUINT8	lac[2];
	MUINT	reserved;
} McfCellInfo;

typedef MVOID (*pfnCellInfoFunc)(MVOID *pUser, McfCellInfo *pCellInfo);

#endif


#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif//#ifndef MCRCOMMON_H
