/* --------------------------------------------------------
  Copyright (c) 2006 汉王科技股份有限公司
  
  File：       HWAPI.h

  关键字：阿拉伯文 Unicode编码 LittleEndian
------------------------------------------------------------ */

#ifndef __HWAPI_ARABIC
#define __HWAPI_ARABIC

#define HANWANG_DEMO  	//Release 版本
//#define HANWANG_DICINTEGRATION 		//字典集成
#if !defined(HANWANG_LITTLEENDIAN)
#define HANWANG_LITTLEENDIAN	1	//littleendian
#endif
/* ------------------识别范围设置---------------------- */

#define ALC_ARABIC_BASIC				0x0020	// 28个基本阿拉伯字符
#define ALC_ARABIC_EXTEND				0x0040	// 扩展阿拉伯字符
#define ALC_ARABIC_NUMERIC				0x0080	// 阿拉伯文数字
#define	ALC_ARABIC_SYMBOLS				0x0200  // 阿拉伯文标点符号


/*typedef struct tagTHWPoint
{
	short x; // 笔迹 X 坐标
	short y; // 笔迹 Y 坐标
} THWPoint;*/

/* ------------识别属性定义------------------ */
typedef struct tagTHWAttributeArabic
{
	int				iCandidateNum;	// 用户需要的候选字个数
	unsigned long	dwRange;		// 识别范围设置		
	unsigned char*	pRam;			// 运算空间，大小为 HWRERAMSIZE，要求起始地址4字节对齐
	unsigned char*	pRom;			//识别数据库起始地址，要求4字节对齐
}THWAttributeArabic;

#ifdef __cplusplus
extern "C" {
#endif

/*
功能：笔迹识别
参数说明：
	pTrace：笔迹数据，其格式为(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,
	        (STROKEENDMARK,0),(STROKEENDMARK,STROKEENDMARK)，
			其中(STROKEENDMARK,0)为笔画结束标志，
			(STROKEENDMARK,STROKEENDMARK)为字结束标志。
	pAttr：识别属性。
	pResult：识别结果存放区。大小为 2*MAXCANDNUM。	
返回值：
	= 0:拒识
	> 0:候选字个数
*/
int HWRecognizeArabic( const THWPoint* pTrace, const THWAttributeArabic* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
