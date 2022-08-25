/* --------------------------------------------------------
  Copyright (c) 2010 汉王科技股份有限公司
  
  File：       HWAPI.h

  Author：John Lee  
  		lzh@hanwang.com.cn

  关键字：
		GB2312 , BIG5
------------------------------------------------------------ */

#ifndef __HWAPI_H_S
#define __HWAPI_H_S
	
//#define  HANWANG_INTEGRATED_DICT  0  //commented as prom of E_THWAttribute got undefined      
/* ------------------识别范围设置---------------------- */
#define ALC_SC_COMMON		0x00000001		/* 简体一级字 */
#define ALC_SC_RARE			0x00000002		/* 简体二级字 */
#define ALC_SC_RADICAL		0x00000080		/* 偏旁部首，只适用于简体版 */
#define ALC_NUMERIC			0x00000100		/* 数字 0-9 ) */
#define ALC_UCALPHA			0x00000200		/* 大写字母( A-Z ) */
#define ALC_LCALPHA			0x00000400		/* 小写字母 ( a-z ) */

#define ALC_PUNC_COMMON		0x00000800		/* 常用标点 
												0021 !     0022 "     201C “     201D ”  
												002C ,     003A :     003B ;     003F ?     
                                                3001 、    3002 。 */
#define ALC_PUNC_RARE		0x00001000		/* 扩展标点 
												0027 '    0028  (    0029 )    2014 —    
												2026 …     3008 〈   3009 〉   300A 《   
												300B 》   */
#define ALC_SYM_COMMON		0x00002000		/* 常用符号 
												0023 #    0024 $     0025 %      0026 &    
												002A *    002B +     002D -      002E  .    
												002F /    003C <     003D =      003E >   
												0040 @    FFE1 ￡    FFE5 ￥     20AC �     */
#define ALC_SYM_RARE		0x00004000		/* 扩展符号
												005B  [   005C \   005D  ]     005E  ^      
                                                005F  _   0060 `   007B  {     007C  |      
                                                007D  }   007E ~   */
#define	ALC_GESTURE			0x00008000		/* 控制手势
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Table 0x0009	*/
#define ALC_CS_CURSIVE      0x00010000      /* 行草字 */


/* -----------------常用组合----------------------------- */
#define CHARSET_CNDEFAULT		(ALC_SC_COMMON | ALC_SC_RARE)//缺省简体中文识别
#define CHARSET_SYMPUNC			(ALC_PUNC_COMMON | ALC_PUNC_RARE)//符号标点
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)//英文识别

/* ----------------定义手势编码值-------------------------- */
#define CODE_BACKSPACE			0x0008	//回删
#define CODE_TAB					0x0009	//Tab
#define CODE_RETURN				0x000D	//回车
#define CODE_SPACE				0x0020	//空格

/* ---------------常量定义---------------------------- */
#define MAXCANDNUM				10			// 可输出的最大侯选字个数
#define HWRERAMSIZE				(10*1024)	// 引擎需要的临时运算空间大小

/* ------------笔迹结构定义------------------- */
#define STROKEENDMARK			(-1)		// 定义笔画结束标记值

typedef struct tagTHWPoint
{
	short x; // 笔迹 X 坐标
	short y; // 笔迹 Y 坐标
} THWPoint;

typedef struct tagTHWAttribute
{
 	int				iCandidateNum;	// 用户需要的候选字个数 number of candidate
	unsigned long		dwRange;		// 识别范围设置		recognize range
	unsigned char*	pRam;			// 运算空间，大小为 HWRERAMSIZE，要求起始地址4字节对齐, ram needed, align by four bytes
	unsigned char*	pRom;	
} THWAttribute;

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
	 -1:参数错误
	= 0:拒识
	> 0:候选字个数
*/
int HWRecognize( const THWPoint* pTrace, const THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
