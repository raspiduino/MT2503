/***************************************************************************
* File Name    :  gbdef.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  
*                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Author       :  chenbinghui
* Date         :  2009-6-18
* Purpose      :  v5 GB API 对外公布的所有宏定义
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/

#ifndef __GBDEF_H__
#define __GBDEF_H__

/*!
* \addtogroup Output	对外的结构体和枚举定义
*/
/*@{*/

/*!
 * \brief 编译单元内部使用的函数
 */
#define GBLOCAL		static
/*!
 * \brief 全局使用，但不对外公布的函数
 */
#define GBGLOBAL 
/*!
 * \brief 对外公布的函数
 */
#define GBEXPORT 

/*!
 * \brief 输入最大长度
 */
#define GB_INPUT_MAX_LEN		31
#define GB_INPUT_BUFFER_LEN		(GB_INPUT_MAX_LEN + 1)

/*!
 * \brief 候选的最多字符个数
 */
#define GB_CAND_MAX_LEN			31
#define GB_CAND_BUFFER_LEN		(GB_CAND_MAX_LEN + 1)

/*!
 * \brief 部首个数最大值
 */
#define GB_COMPONET_MAX_LEN		5
#define GB_COMPONET_BUFFER_LEN	(GB_COMPONET_MAX_LEN + 1)

/*!
 * \brief 每一个获得候选的最大个数
 */
#define GB_MAX_CANDIDATES			32	  /**@brief 候选项的最大数目 */

/*!
 * \brief 最大的音节个数
 */
#define GB_MAX_SYLLABLES			32

/*!
 * \brief 默认的候选Buffer长度
 */
#define GB_DEFAULT_CAND_BUFFER_LEN	(128 * 2)

/*!
 * \brief 输出候选框的时候最大的行数
 */
#define GB_CAND_MAX_LINE_COUNT		15

/** \brief 最多记录多少个页边界 */
#define GB_BUFFER_BOUND_BUFFER_LEN	64


/*!
 * \brief GBGetDesireOutput中的option函数的定义，只能选择其中一个。
 */
enum GBAlpOutputOption {
	GBA_OUTPUT_NORMAL		= 0		///<输出默认的大小状态的单词
	, GBA_OUTPUT_FCC		= 0x02  ///<输出首字母大写的候选单词
	, GBA_OUTPUT_CAPITAL	= 0x04	///<输出大写的候选单词
	, GBA_OUTPUT_LOWER		= 0x06	///<输出小写的候选单词
	, GBA_OUTPUT_TOGGLE_FCC	= 0x08	///<改变当前输出的首个字母的大小状态
};
/** \brief 默认的中文候选个数, 可以通过\ref GBSetPageOption和\ref GBGetPageOption查看或者重新设置 */
#define DEFAULT_CHN_CAND_COUNT				6

/** \brief 默认的音节候选个数, 可以通过\ref GBSetPageOption和\ref GBGetPageOption查看或者重新设置 */
#define DEFAULT_SYLLABLE_CAND_COUNT			2

/** \brief 默认的Alphabetic候选个数, 可以通过\ref GBSetPageOption和\ref GBGetPageOption查看或者重新设置 */
#define DEFAULT_ALP_CAND_COUNT				1

/** \brief 语言个数的最大值 */
#define GB_LDB_MAX_COUNT					100

/** \brief 默认的\ref GBGetCandidatesCount函数返回的最大值 */
#define GB_CAND_MAX_COUNT					100

/** \brief MDB的最大个数 */
#define GB_MDB_MAX_COUNT					5

/** \brief 词库更新频率 */
#define GB_UDB_UPDATE_FREQ					5

/** \brief GBMDBInit所传入的Buffer的最小值 */
#define GB_MDB_BUFFER_MIN_LEN				(16 * 1024)

/** \brief GBMMI层的切换级别 */
#define GB_MMI_SWITCH_LEVEL		2

#ifndef __GB_CHN_CONFIG_ENUM__
#define __GB_CHN_CONFIG_ENUM__
	/** \brief 引擎配置枚举 */
#ifndef _C166
    enum GBChnConfigEnum {
		GBCFG_FAST_JIANPIN_SYLLABLE = 0x0004,	///<快速简拼功能
        GBCFG_PINYIN_FUZZY_H_F = 0x0008,	///<拼音的h和f的模糊匹配(*)
        GBCFG_PINYIN_FUZZY_N_L = 0x0010,	///<拼音的n和l的模糊匹配(*)
        GBCFG_PINYIN_FUZZY_NG_N = 0x0020,	///<拼音的前鼻音和后鼻音的模糊匹配(*)
        GBCFG_PINYIN_FUZZY_XH_X = 0x0040,	///<拼音的平卷舌的模糊匹配(*)
        GBCFG_PINYIN_FUZZY_K_G = 0x0080,	///<拼音的k和g的模糊匹配(*)
		///关闭词组功能, 在有词组功能的引擎默认打开词组功能，关闭词组功能之后
		///可以重新调用EBEngineConfig(GBCFG_CLOSE_PHRASE, 0)开启词组功能
		///此配置同时自动关闭词语联想功能
		GBCFG_CLOSE_PHRASE = 0x0100,
		///拼音在有完整拼音匹配的情况下,不支持模糊的拼音匹配
		GBCFG_PY_1_MATCH_FUNC = 0x0200,
		///只匹配完整的词语，不会出现词语一半的候选
		GBCFG_ONLY_ENTIRE_PHRASE_CAND = 0x0400,
		///使用进入整句状态
		GBCFG_SYNTAX = 0x0800,
		///找第一页的时候把EBIS的第一个候选作为结果加入到候选
		GBCFG_FIRST_PAGE_ADD_PHRASE = 0x1000,
		///设置第一个候选，在调用EBFindFirstPageC设置，这时候pEBIS里面存在第一个候选的信息
		GBCFG_SET_FIRST_CANDIDATE = 0x2000,
		///设置引擎使用哪个字符集, 
		///option为GBChnCharset中的一个值
		GBCFG_CHARSET_SET = 0x4000,

		///设置分隔符号的显示字符，第二个参数为一个Unicode, 
		///option为一个字符，如'\''
		GBCFG_SET_PHRASE_SPLIT_CHAR = 0x4001,

		///设置笔画通配符符号，第二个参数为一个Unicode
		///option为一个字符，如'#'，不能与GBCFG_SET_PHRASE_SPLIT_CHAR冲突
		GBCFG_SET_STROKE_WILDCARD_CHAR = 0x4002,

		//设置笔划通配符的显示字符，如"？"或"/"等
		GBCFG_SET_STROKE_WILDCHAR_SHOW = 0x4003,

		///设置词语的最大长度限制. 0表示不限制任何词语
		///option为2-10的一个数字
		GBCFG_SET_PHRASE_LEN_LIMIT ,

		//设置词尾匹配最大个数，默认最大个数为1000
		GBCFG_SET_MAX_TAIL_MATCH_COUNT ,
		//设置简拼时词尾匹配最大个数
		GBCFG_SET_JP_MAX_TAIL_MATCH_COUNT = GBCFG_SET_MAX_TAIL_MATCH_COUNT,

		///模糊音r 和 l
		GBCFG_PINYIN_FUZZY_R_L = 0x8000,

		///是否获取默认高频字
		GBCFG_INIT_GET_HIGHEST_FREQ_WORD = 0x00010000,

		///联想的时候不填充高频字，默认填充
		GBCFG_ASSOC_NOT_FILL_HIGHEST_FREQ_WORD = 0x00020000,

		///笔画和韩文输入法下面，输入串超长之后，是否再出来候选
		GBCFG_NOT_ALLOW_USELESS_STROKE = 0x00040000,

		///关闭词语联想功能
		GBCFG_CLOSE_ASSOC_PHRASE = 0x00080000,

		///只返回完整匹配的按键序列的词语候选
		GBCFG_FIND_ONLY_FULL_MATCHING = 0x00100000,

		///是否支持标点符号词语联想
		GBCFG_ASSOCIATE_INTEPCT = 0x00200000,

		///在模糊状态(Amb Pinyin、Bopomofo、Jyutping)是否将输入字符串转换为拼音串
		GBCFG_TRANSLATE_INPUT_STRING = 0x00400000,

		///<配置引擎只输出字的拼音，不输出词语拼音。
		GBCFG_OUT_ZI_SYLLABLE  = 0x00800000,

		///<关闭快捷部首功能。
		GBCFG_CLOSE_COMPONENT = 0x01000000,

		///将转换之后的字符串加入拼音音节列表
		GBCFG_ADD_TRANSLATE_INPUT_STRING_TO_SYLLABLE = 0x02000000,//(1 << 25)

		///联想的时候是否填充高频字
		GBCFG_ASSOCIATE_HIGH_FREQ = 0x04000000,

		//modified by ZhaoKun at 2010-2-23 13:52:52</add>
		//note : 
		///自动简拼
		GBCFG_AUTO_JIANPIN = 0x08000000,
		//modified by ZhaoKun end
		// start add [2011-8-22 Zhaokun]
		// 对精确音节进行拆分
		GBCFG_SPLIT_ACC_SYLLABLE = 0x10000000,
		// 词尾精确匹配
		GBCFG_TAIL_ACC_MATCH = 0x20000000
		// end add [2011-8-22 Zhaokun]
    };
#else
#define GBCFG_FAST_JIANPIN_SYLLABLE	((unsigned long)0x0004)
#define GBCFG_PINYIN_FUZZY_H_F	((unsigned long)0x0008)
#define GBCFG_PINYIN_FUZZY_N_L	((unsigned long)0x0010)
#define GBCFG_PINYIN_FUZZY_NG_N	((unsigned long)0x0020)
#define GBCFG_PINYIN_FUZZY_XH_X	((unsigned long)0x0040)
#define GBCFG_PINYIN_FUZZY_K_G	((unsigned long)0x0080)
#define GBCFG_CLOSE_PHRASE	((unsigned long)0x0100)
#define GBCFG_PY_1_MATCH_FUNC	((unsigned long)0x0200)
#define GBCFG_ONLY_ENTIRE_PHRASE_CAND	((unsigned long)0x0400)
#define GBCFG_SYNTAX	((unsigned long)0x0800)
#define GBCFG_FIRST_PAGE_ADD_PHRASE	((unsigned long)0x1000)
#define GBCFG_SET_FIRST_CANDIDATE	((unsigned long)0x2000)
#define GBCFG_CHARSET_SET	((unsigned long)0x4000)
#define GB_CHARSET_BIGSET   0	
#define GB_CHARSET_GB2312   1
#define GB_CHARSET_BIG5     2
#define GBCFG_SET_PHRASE_SPLIT_CHAR	((unsigned long)0x4001)
#define GBCFG_SET_STROKE_WILDCARD_CHAR	((unsigned long)0x4002)
#define GBCFG_SET_STROKE_WILDCHAR_SHOW	((unsigned long)0x4003)
#define GBCFG_SET_PHRASE_LEN_LIMIT	((unsigned long)0x4004)
#define GBCFG_SET_MAX_TAIL_MATCH_COUNT	((unsigned long)0x4005)
#define GBCFG_SET_JP_MAX_TAIL_MATCH_COUNT	GBCFG_SET_MAX_TAIL_MATCH_COUNT
#define GBCFG_PINYIN_FUZZY_R_L	((unsigned long)0x8000)
#define GBCFG_INIT_GET_HIGHEST_FREQ_WORD	((unsigned long)0x00010000)
#define GBCFG_ASSOC_NOT_FILL_HIGHEST_FREQ_WORD	((unsigned long)0x00020000)
#define GBCFG_NOT_ALLOW_USELESS_STROKE	((unsigned long)0x00040000)
#define GBCFG_CLOSE_ASSOC_PHRASE	((unsigned long)0x00080000)
#define GBCFG_FIND_ONLY_FULL_MATCHING	((unsigned long)0x00100000)
#define GBCFG_ASSOCIATE_INTEPCT	((unsigned long)0x00200000)
#define GBCFG_TRANSLATE_INPUT_STRING	((unsigned long)0x00400000)
#define GBCFG_OUT_ZI_SYLLABLE	((unsigned long)0x00800000)
#define GBCFG_CLOSE_COMPONENT	((unsigned long)0x01000000)
#define GBCFG_ADD_TRANSLATE_INPUT_STRING_TO_SYLLABLE	((unsigned long)0x02000000)
#define GBCFG_ASSOCIATE_HIGH_FREQ	((unsigned long)0x04000000)
#define GBCFG_AUTO_JIANPIN	((unsigned long)0x08000000)
#define GBCFG_SPLIT_ACC_SYLLABLE ((unsigned long)0x10000000)
#define GBCFG_TAIL_ACC_MATCH ((unsigned long)0x20000000)
#endif
#define GBCFG_PINYIN_FUZZY_H    GBCFG_PINYIN_FUZZY_XH_X
#endif

	/** \brief  */
	enum EngineIDEnum
	{
		GB_ENGINE_CHINESE			///<中文输入引擎的设置，对应的设置选项为GBChnConfigEnum
		, GB_ENGINE_ALPHABETIC		///<Alphabetic输入引擎的设置，对应的设置选项为GBAlp_Config
		, GB_ENGINE_SYNTAX			///<整句输入引擎设置，对应的设置选项为GBS_Config
		, GB_ENGINE_FUNCTION		///<功能方面的设置，对应的设置选项为GB_Function_Option
		//added by weizhiping at 2010-7-7 15:32:07
		//note : 增加韩文引擎ID定义		
		, GB_ENGINE_KOREAN			///<韩文引擎ID		
		//added by weizhiping end
		// start add [2011-5-24 haj]
		, GB_ENGINE_MARS			///<火星文引擎ID
		// end add [2011-5-24 haj]
		, GB_ENGINE_COUNT			///<引擎计数
	};

#ifndef __GB_CHN_CHARSET_ENUM__
#define __GB_CHN_CHARSET_ENUM__
	/** \brief 中文字符集 */
	enum GBChnCharset {
		GB_CHARSET_ALL				///<所有的汉字和词语都可以作为候选
		, GB_CHARSET_ONLY_GB2312	///<只有GB2312的汉字和词语可以作为候选
		, GB_CHARSET_ONLY_BIG5		///<只有BIG5的汉字和词语可以作为候选
		///<haj chg 数据生成器定义是这样的：
		///<#define CHARSETDATA_TYPE_GBK	 0x0004			///< 0x4e00 + 20901
		, GB_CHARSET_ONLY_GBK=4		///<只有GBK的汉字和词语可以作为候选
		///<GB18030数据生成器还没有考虑，暂时把GB18030作GBK(GB2312)处理
		, GB_CHARSET_ONLY_GB18030	///<只有GB18030的汉字和词语可以作为候选
	};
#endif

#ifndef __GB_ALP_CONFIG_ENUM__
#define __GB_ALP_CONFIG_ENUM__
#ifndef _C166
enum GBAlp_Config {
	GBALP_AUTO_CORRECTION = 0x0010 //打开自动模糊匹配
	, GBALP_CLOSE_AUTO_COMPLETION = 0x0020 //关闭自动完成功能
	, GBALP_INPUTSTRING_IS_FIRST_CANDIDATE = (1 << 6) ///<在Explicit 模式下面, 输入串作为第一个候选
	, GBALP_QWERTY_OUTPUT_DEFAULT_STRING = (1 << 7) ///<在Qwerty模式下面, 输出一个默认的字符串作为候选
	, GBALP_FIRST_KEY_ASSOC = (1 << 8)	///<Explicit模式和Qwerty下面，第一个按键就开始自动完成功能，
	                                    ///<如果同时打开了GBALP_CLOSE_AUTO_COMPLETION功能，此功能无效
	, GBALP_ASSOC_NO_DERIVE = (1 << 9)			///<是否输出派生词
	//start[2010-4-20 zhj]
	, GBALP_KEEP_ALL_HEADER = (((unsigned long)1) << 10)			///<是否获取不是单词的header
	//end[2010-4-20 zhj]
	//start[2010-4-26 zhj]
	, GBALP_SET_AVOID_PATENT_SYMBOL = (((unsigned long)1) << 11)			///<设置规避专利所使用的符号
	//end[2010-4-26 zhj]
	//start[2010-5-4 zhj]
	, GBALP_CUSTOM_SYMBOL_TABLE = (((unsigned long)1) << 12)	///<是否可以由用户自定义标点符号
	//end[2010-5-4 zhj]
	//start[2010-5-12 zhj]
	, GBALP_SET_EMBEDDED_INTERPUNCTION_KEY = (((unsigned long)1) << 13)	///<设置智能标点符号
	//end[2010-5-12 zhj]
	// Start Add [2011-7-15 haj]
	,GBALP_CLOSE_AVOID_PATENT = (((unsigned long)1) << 14)	///<打开规避专利功能，默认开启	
	// end [2011-7-15 haj]

};
#else
#define GBALP_AUTO_CORRECTION	((unsigned long)0x0010)
#define GBALP_CLOSE_AUTO_COMPLETION	((unsigned long)0x0020)
#define GBALP_INPUTSTRING_IS_FIRST_CANDIDATE	(((unsigned long)1) << 6)
#define GBALP_QWERTY_OUTPUT_DEFAULT_STRING	(((unsigned long)1) << 7)
#define GBALP_FIRST_KEY_ASSOC	(((unsigned long)1) << 8)
#define GBALP_ASSOC_NO_DERIVE	(((unsigned long)1) << 9)
#define GBALP_KEEP_ALL_HEADER	(((unsigned long)1) << 10)
#define GBALP_SET_AVOID_PATENT_SYMBOL	(((unsigned long)1) << 11)
#define GBALP_CUSTOM_SYMBOL_TABLE	(((unsigned long)1) << 12)
#define GBALP_SET_EMBEDDED_INTERPUNCTION_KEY	(((unsigned long)1) << 13)
#define GBALP_CLOSE_AVOID_PATENT	(((unsigned long)1) << 14)
#endif
#endif

#ifndef __GB_SYNTAX_CONFIG_ENUM__
#define __GB_SYNTAX_CONFIG_ENUM__

/** \brief 整句引擎的配置函数*/
enum GBS_Config{ 
	GBS_Config_CompStr = 1	///<使用CompStr, 在pGBIS->pAuxInfo->pCompStr中会输出当前的预测字符串
	, GBS_Config_CompStr_From_Beginning = 2 ///<使用CompStr, 默认的候选从输入串开头查找，此配置
};
#endif


/** \brief GBAPI/GBMMI功能配置 */
#ifndef _C166
enum GB_Function_Option{
	/*GBFO_Display_Key_Sequence  = 1          //(default 0)配置在Alphabetic和中文是否显示按键序列
	, */
	//!配置Alp中Up是否实现数字上屏功能, 打开这个功能的时候,要求客户在Alphabetic状态都要显示按键序列。
	GBFO_Alp_Up_To_Input_Key_Sequence = 1    
	//!配置Up是否实现数字上屏功能, 打开这个功能的时候,要求客户在中文状态都要显示按键序列。
	, GBFO_Chn_Up_To_Input_Key_Sequence = (1 << 1)    
	//change start[2010-4-8 zhj]
	//, GBFO_No_Response_When_Key_No_Cand = (1 << 2) //!<输入过程中按键没有候选的时候，不响应，无候选时自动回退功能
	, GBFO_Chn_No_Response_When_Key_No_Cand = (1 << 2) //!<中文输入过程中按键没有候选的时候，不响应，无候选时自动回退功能
	//change end[2010-4-8 zhj]
	, GBFO_Alp_Add_Space_After_Cand_Confirmed = (1 << 3) ///<alphabetic 选择上屏之后加入一个空格
	/*!在MMI上面支持用户自造词功能，要求OEM用户需要在自造词状态 实现一个候选框 显示两项内容
	1. 用户已经选择的字母
	2. 当前用户已经输入的，但是还没有匹配对应字母的按键序列*/
	, GBFO_Alp_UAW = (1 << 4)      
	, GBFO_OK_Enter_Selected	= (1 << 6)			///<在没有进入候选状态下面，OK键进入选择状态（只针对
	, GBFO_Chn_Syntex_Key_Sequence_Edit = (1 << 7)  ///<整句拼音输入法: 支持按键序列修改
	, GBFO_Chn_Switch_Alp	= (1 << 9)				///<在中文输入法中，是否使用中英切换的功能
	, GBFO_API_Stop_Log = (1 << 10)
	, GBFO_Alp_UAW_Confirm = (1 << 11)				///<在Alphabetic Predictive/HalfQwerty 模式下打开自造词的确认流程
	, GBFO_Multi_Tap_Show_Cand_Wnd = (1 << 12)		///<在MultiTap状态下面仍然打开候选窗口，默认关闭, 此时的候选分页策略与当前语言的一致
	, GBFO_Scroll_Cand_By_Row = (1 << 13)			///<一行一行地对候选进行翻页，默认是一页一页(还不支持)
	, GBFO_Tch_Scr	= (1 << 14)						///<Alp自造词状态下面，支持触摸屏（使用GBCL_ROW_TCH_SCR候选框）
	, GBFO_Alp_Qwerty_Spell	= (1 << 15)				///<Alp自造词状态下面，支持触摸屏（使用GBCL_ROW_TCH_SCR候选框）
	, GBFO_Alp_UAW_Support_Tchscr = (1<<16)			///<Alp自造词状态下面，支持触摸屏（使用GBCL_Row_TchScr候选框）. 
	//start[2010-3-15 zhj]
	/*!GBFO_Chn_All_Num_Can_Continuously_Input还会影响multitap符号引擎，从说明书上看wrapper是属于api层
	的，所以这个配置是可以影响gbmmi层和api层的。如果打开这个配置，在注册标点符号键的时候
	不能让标点符号支持GBIKO_Input_Status_Confirm_Candidate的功能*/
	, GBFO_Chn_All_Num_Can_Continuously_Input = (1<<17)	///<拼音模式下是否可以连续输入任何数字串
	//end[2010-3-15 zhj]
	//start[2010-3-8 zhj]
	, GBFO_Chn_Display_Input_Key_Sequence = (1<<18)	///中文数字键盘拼音输入法输入过程中是否显示数字按键序列
	//end[2010-3-8 zhj]
	//start[2010-3-24 zhj]
	, GBFO_Alp_All_Num_Can_Continuously_Input = (1<<19)	///英文数字键盘智能输入模式下是否能够连续输入数字
	//end[2010-3-24 zhj]
	//start[2010-4-8 zhj]
	, GBFO_Alp_No_Response_When_Key_No_Cand = (1 <<20) ///<英文输入过程中按键没有候选的时候，不响应，无候选时自动回退功能
	//end[2010-4-8 zhj]

	//start[2010-4-26 zhj]
	,GBFO_Alp_Paging_By_Lower = (1<<21)	///<仅使用小写候选进行分页而不用用户期望的候选进行分页
	//end[2010-4-26 zhj]
	
	//start[2010-10-14 zhj]
	,GBFO_Alp_Use_AbbrWordTree_When_Seamless_Switch = (1<<22)	///<无缝切换时第一屏出缩写词表的候选
	//end[2010-10-14 zhj]

	//start[2010-12-28 zhj]
	,GBFO_Alp_Get_Only_Lower = (1<<23)	///<只取小写格式的单字母候选
	,GBFO_Alp_Get_Only_Cap = (1<<24)	///<只取大写格式的单字母候选
	//end[2010-12-28 zhj]
	// start[2011-3-8 haj for Alpha GBCT_Associate]
	, GBFO_Alp_Open_Associat = (1<<25)	///<开启Alpha智能联想功能
	// end[2011-3-8 haj]
	// Start add [2011-5-31 haj]
	, GBFO_Open_Chn_2_Mars = (1<<26)	///<开启中文切换到火星文功能	
	// end [2011-5-31 haj]
	// Start Add [2011-7-22 haj]
	, GBFO_Mars_Char_Random_Cand = (1<<27)	///<火星文引擎随机字获取候选
	, GBFO_Mars_Word_Random_Cand = (1<<28)	///<火星文引擎随机词获取候选
	// end [2011-7-22 haj]
	//start[2010-4-15 zhj]
	//不加这个在TASKING中编译通不过，不知道为什么
	,GBFO_END
	//[2010-4-15 zhj]
};
#else
#define GBFO_Alp_Up_To_Input_Key_Sequence		1    
#define GBFO_Chn_Up_To_Input_Key_Sequence		((unsigned long)1 << 1)    
#define GBFO_Chn_No_Response_When_Key_No_Cand		((unsigned long)1 << 2)
#define GBFO_Alp_Add_Space_After_Cand_Confirmed		((unsigned long)1 << 3)
#define GBFO_Alp_UAW		((unsigned long)1 << 4)      
#define GBFO_OK_Enter_Selected		((unsigned long)1 << 6)
#define GBFO_Chn_Syntex_Key_Sequence_Edit		((unsigned long)1 << 7)
#define GBFO_Chn_Switch_Alp		((unsigned long)1 << 9)
#define GBFO_API_Stop_Log		((unsigned long)1 << 10)
#define GBFO_Alp_UAW_Confirm		((unsigned long)1 << 11)
#define GBFO_Multi_Tap_Show_Cand_Wnd		((unsigned long)1 << 12)
#define GBFO_Scroll_Cand_By_Row		((unsigned long)1 << 13)
#define GBFO_Tch_Scr		((unsigned long)1 << 14)
#define GBFO_Alp_Qwerty_Spell		((unsigned long)1 << 15)
#define GBFO_Alp_UAW_Support_Tchscr		((unsigned long)1<<16)	
#define GBFO_Chn_All_Num_Can_Continuously_Input		((unsigned long)1<<17)	
#define GBFO_Chn_Display_Input_Key_Sequence		((unsigned long)1<<18)	
#define GBFO_Alp_All_Num_Can_Continuously_Input		((unsigned long)1<<19)
#define GBFO_Alp_No_Response_When_Key_No_Cand		((unsigned long)1 <<20) 
//start[2010-4-26 zhj]
#define GBFO_Alp_Paging_By_Lower ((unsigned long)1 <<21) 
//end[2010-4-26 zhj]

//start[2010-10-14 zhj]
#define GBFO_Alp_Use_AbbrWordTree_When_Seamless_Switch ((unsigned long)1<<22)
//end[2010-10-14 zhj]

//start[2010-12-28 zhj]
#define GBFO_Alp_Get_Only_Lower ((unsigned long)1<<23)	///<只取小写格式的单字母候选
#define GBFO_Alp_Get_Only_Cap ((unsigned long)1<<24)	///<只取大写格式的单字母候选
//end[2010-12-28 zhj]
// start[2011-3-8 haj for Alpha GBCT_Associate]
#define GBFO_Alp_Open_Associat ((unsigned long)1<<25)	///<开启Alpha智能联想功能
// end[2011-3-8 haj]
// Start add [2011-5-31 haj]
#define GBFO_Open_Chn_2_Mars   ((unsigned long)1<<26)	///<开启中文切换到火星文功能	
// end [2011-5-31 haj]
// Start Add [2011-7-22 haj]
#define GBFO_Mars_Char_Random_Cand   ((unsigned long)1<<27)	///<火星文引擎随机字获取候选	
#define GBFO_Mars_Word_Random_Cand   ((unsigned long)1<<28)	///<火星文引擎随机词获取候选	
// end [2011-7-22 haj]
#endif

/*!
* \brief 默认的GBMMI功能
*/
#define GBMMI_FUNCTION_OPTION_DEFAULT		\
	(GBFO_Alp_Up_To_Input_Key_Sequence  \
	| GBFO_Chn_Up_To_Input_Key_Sequence \
	| GBFO_Alp_Add_Space_After_Cand_Confirmed \
	| GBFO_Alp_UAW)

//#define GBMMI_NOKIA_FUNCTION (GBFO_No_Response_When_Key_No_Cand)


/*!
* \brief 所有消息的定义，包括Key消息和Event消息两种，
*  Key消息没有参数，Event消息可以带有一个根据不同的消息定义的unsigned long参数
*/
enum GBEventEnum{
	GBEvent_None = 0
	, GBKEY_BACK	= 0x9
	, GBKEY_RETURN	= 0xA
	, GBKEY_SPACE   = 0x20
	, GBKEY_COMMA	= 0x2c
	, GBKEY_PERIOD	= 0x2e

	, GBKEY_0 = '0'
	, GBKEY_1
	, GBKEY_2
	, GBKEY_3
	, GBKEY_4
	, GBKEY_5
	, GBKEY_6
	, GBKEY_7
	, GBKEY_8
	, GBKEY_9

	, GBKEY_A = 'a'
	, GBKEY_B
	, GBKEY_C
	, GBKEY_D
	, GBKEY_E
	, GBKEY_F
	, GBKEY_G
	, GBKEY_H
	, GBKEY_I
	, GBKEY_J
	, GBKEY_K
	, GBKEY_L
	, GBKEY_M
	, GBKEY_N
	, GBKEY_O
	, GBKEY_P
	, GBKEY_Q
	, GBKEY_R
	, GBKEY_S
	, GBKEY_T
	, GBKEY_U
	, GBKEY_V
	, GBKEY_W
	, GBKEY_X
	, GBKEY_Y
	, GBKEY_Z

	, GBKEY_AMB_SPECIAL_A = 0x80	///< 注册标点符号，有输入时在中文模式下面输入分隔符
	, GBKEY_AMB_SPECIAL_B			///< 在Alphabetic改变大小写
	, GBKEY_AMB_SPECIAL_C			///< 无条件上屏编辑框的内容
	, GBKEY_AMB_SPECIAL_D			///< Latin直接进入自造状态进行自造
	, GBKEY_AMB_SPECIAL_E			///< 在中文模式注册无缝切换，
	, GBKEY_AMB_SPECIAL_F			///< 默认不处理，
	, GBKEY_AMB_SPECIAL_G			///< 默认不处理，
	, GBKEY_AMB_SPECIAL_H			///< 默认不处理，

	, GBKEY_OK			  = 0x90
	, GBKEY_LEFT
	, GBKEY_RIGHT
	, GBKEY_UP
	, GBKEY_DOWN

	, GBKEY_NEXT_PAGE_CANDIATE  ///<获得下一页的候选，并且把选择位置定为页的第一个候选, 翻页失败也返回GBOK
	, GBKEY_PREV_PAGE_CANDIATE	///<获得上一页的候选，并且把选择位置定为页的第一个候选, 翻页失败也返回GBOK
	, GBKEY_NEXT_CANDIDATE		///<选择光标往后移一个候选
	, GBKEY_PREV_CANDIDATE		///<选择光标往前移一个候选
	, GBKEY_NEXT_ROW_CANDIDATE  ///<在多行候选的实现中:下一行候选, 翻页失败也返回GBOK
	, GBKEY_PREV_ROW_CANDIDATE	///<在多行候选的实现中:上一行候选, 翻页失败也返回GBOK


	, GBKEY_NEXT_PAGE_SYLLABLE	///<获得下一页的拼音，并且把当前选择的拼音设为页的第一个, 翻页失败也返回GBOK
	, GBKEY_PREV_PAGE_SYLLABLE	///<获得前一页的拼音，并且把当前选择的拼音设为页的第一个, 翻页失败也返回GBOK
	, GBKEY_NEXT_SYLLABLE		///<把当前选择的拼音往后移动一个
	, GBKEY_PREV_SYLLABLE		///<把当前选择的拼音往前移动一个

//	, GBKEY_START_MULTITAP_SYMBOLS		///<根据当前的输入模式，开始Multitap 标点(chn/alp)
//	, GBKEY_START_FULL_SCREEN_SYMBOLS	///<开始全屏标点模式

	, GBEVENT_SELECT_SYLLABLE_PAGED		///<选择当前的页的音节, 参数有效值为0到当前页音节的个数
	, GBEVENT_SELECT_SYLLABLE			///<选择全局的音节, 参数有效值为0到所有音节的总数

	, GBEVENT_SELECT_CANDIDATE			///<选择一个候选，param参数的低16位表示选择的列，高16位表示选择的行。
	, GBEVENT_SET_CANDIDATE_SELECTED	///<设置一个候选作为选择状态，param参数的低16位表示选择的列，高16位表示选择的行。

	, GBEVENT_INPUT_UNICODE				///<输入一个Unicode值
	, GBEVENT_UPDATE_CANDIDATE			///<更新候选，用户在外部使用GBSelectSyllable或者其他方式
										///<改变了引擎的状态，但是没有改变输入模式
	
    //added by weizhiping at 2010-6-21 15:17:24										
	, GBEVENT_SET_INPUT_STRING			///<允许用户通过GBMMI直接设置引擎输入串获取相应候选
	//added by weizhiping end
	, GBEVENT_SET_SYLLABLE_TONE					///<设置音调，范围参见GBChnToneEnum
	// Start Add [2011-7-20 haj]
	, GBEVENT_SELECT_CANDIDATE_BY_INDEX ///<通过index（0-9），选择候选
	// end [2011-7-20 haj]
	//注音事件
	, GBKEY_BPMF_TONE_NULL			//注音音调：缺省匹配所有音調
	, GBKEY_BPMF_TONE_1 = 0x02C9	//注音音调：1声
	, GBKEY_BPMF_TONE_2 = 0x02CA	//注音音调：2声
	, GBKEY_BPMF_TONE_3 = 0x02C7	//注音音调：3声
	, GBKEY_BPMF_TONE_4 = 0x02CB	//注音音调：4声
	, GBKEY_BPMF_TONE_5 = 0x02D9	//注音音调：轻声

	, GBKEY_BPMF_B = 0x3105   
	, GBKEY_BPMF_P    
	, GBKEY_BPMF_M    
	, GBKEY_BPMF_F    
	, GBKEY_BPMF_D    
	, GBKEY_BPMF_T    
	, GBKEY_BPMF_N    
	, GBKEY_BPMF_L    
	, GBKEY_BPMF_G    
	, GBKEY_BPMF_K    
	, GBKEY_BPMF_H    
	, GBKEY_BPMF_J    
	, GBKEY_BPMF_Q    
	, GBKEY_BPMF_X    
	, GBKEY_BPMF_ZH   
	, GBKEY_BPMF_CH   
	, GBKEY_BPMF_SH   
	, GBKEY_BPMF_R    
	, GBKEY_BPMF_Z    
	, GBKEY_BPMF_C    
	, GBKEY_BPMF_S    
	, GBKEY_BPMF_A    
	, GBKEY_BPMF_O    
	, GBKEY_BPMF_E    
	, GBKEY_BPMF_EH   
	, GBKEY_BPMF_AI   
	, GBKEY_BPMF_EI   
	, GBKEY_BPMF_AU   
	, GBKEY_BPMF_OU   
	, GBKEY_BPMF_AN   
	, GBKEY_BPMF_EN   
	, GBKEY_BPMF_ANG  
	, GBKEY_BPMF_ENG  
	, GBKEY_BPMF_ER   
	, GBKEY_BPMF_I    
	, GBKEY_BPMF_U    
	, GBKEY_BPMF_IU 

};
/*!
* \brief GB所有API的返回值定义
*/
enum GBReturnEnum{
	GBOK										///<事件处理成功
	, GBIngore								///<事件被忽略
	, GB_NOT_HANDLED					///<GBMMI没有处理此消息，如果是按键消息，需要OEM继续处理。
	, GB_Failed							///<只针对一些应该返回True和False的消息，表示False.

	, GBR_UAW_CONTINUE					///<继续选择自造词的状态
	, GBR_SELECTED_TIPS					///<选择的候选是提示字符串

	, GB_Message_Start = 0x1000
	, GB_API_NO_MORE_SELECTION			///<在中文的输入里面，已经没有用户的选择。
	, GB_API_UDB_NO_MORE_PHRASE			///<已经没有其他的自造词了
	, GB_API_CAND_BUFFER_FULL			///<候选的存放的Buffer已满
	, GB_API_NOT_MORE_PAGE				///<没有其他页的候选
	, GB_API_GET_LAST_ERROR_NULL_PARAM	///<GBGetLastError函数参数为NULL
	, GB_API_CHN_CONTINUE_SELECTION = GBR_UAW_CONTINUE		///<继续中文自造词
	, GB_API_MARS_CONTINUE_SELECTION = GB_API_CHN_CONTINUE_SELECTION		///<继续火星文自造
	, GB_API_CHN_2_MARS	= GB_API_GET_LAST_ERROR_NULL_PARAM+1           		///<中文切换至火星文
	, GB_API_MARS_FINISH_SELECT                             ///<结束火星文自造
	, GB_API_MARS_OUTPUT_BUFFER_FULL                        ///<中文切换至火星文
	, GB_API_MARS_NO_OPEN                                   ///<火星文配置没有打开
	, GB_API_CHN_SELECT_INTERPUNCTION_CHAR                  ///<中文选择了一个标点符号
	, GB_API_CAND_DESIGNATE_NEWLINE		///<候选被指定另起一行显示
	, GBM_Alp_Message_Start = 0x2000
	, GBM_Chn_Message_Start = 0x3000
	, GBM_MMI_Message_Start = 0x4000
	, GBM_MMI_NO_SUCH_INTER_KEY			///<GBMMIUnregisterInterpunctionKey函数没有找到对应的键值

	, GBW_Warning_Start = 0x5000
	, GBW_ALP_Warning_Start = GBW_Warning_Start
	, GBW_CHN_Warning_Start = 0x6000
	, GBW_MMI_Warning_Start = 0x7000
	, GBW_MMI_STACK_NOTIFY_IS_NULL			///<mSwitchStack中fpNotify为NULL

	, GBE_Error_Start = -0x1000
	, GBE_ALP_Error_Start = GBE_Error_Start
	, GBE_ALP_FAILED                     = GBE_ALP_Error_Start + 1	//!<alp引擎操作失败
	, GBE_ALP_INVALID_INDEX              = GBE_ALP_Error_Start + 100	//!<错误的候选索引
	, GBE_ALP_NOTINIT					 = GBE_ALP_Error_Start + 2 //!<没有调用GBLtStartup()!
	, GBE_ALP_PEBIS_NULL				 = GBE_ALP_Error_Start + 3 //!<pEBIS为空.
	, GBE_ALP_INVALID_INPUT_LEN          = GBE_ALP_Error_Start + 4	//!<输入序列长度错误
	, GBE_ALP_INVALID_DESIRE_LEN         = GBE_ALP_Error_Start + 5	//!<错误的请求
	, GBE_ALP_INVALID_STATUS             = GBE_ALP_Error_Start + 7	//!<错误的状态
	, GBE_ALP_NO_MATCH                   = GBE_ALP_Error_Start + 8 //!<没找到匹配串
	, GBE_ALP_INVALID_INVOKE             = GBE_ALP_Error_Start + 9 //!<非法调用
	, GBE_ALP_NO_WORD                    = GBE_ALP_Error_Start + 10 //!<单词表里面没有任何单词
	, GBE_ALP_INVALID_DESIRE             = GBE_ALP_Error_Start + 12	//!<错误的请求
	, GBE_ALP_INVALID_DESIRE_COUNT       = GBE_ALP_Error_Start + 13	//!<错误的请求
	, GBE_ALP_NO_DATA_FILE               = GBE_ALP_Error_Start + 14	//!<没有数据uwenjian
	, GBE_ALP_INVALID_DATA_FORMAT        = GBE_ALP_Error_Start + 15	//!<错误的数据格式
	, GBE_ALP_FAILED_ALLOC_MEM           = GBE_ALP_Error_Start + 16	//!<分配内存错误
	, GBE_ALP_CORRUPTED_DATA_FILE        = GBE_ALP_Error_Start + 17	//!<数据文件不是词表文件
	, GBE_ALP_MISS_DATA                  = GBE_ALP_Error_Start + 18	//!<缺少数据
	, GBE_ALP_INVALID_CHAR               = GBE_ALP_Error_Start + 19	//!<错误的字符
	, GBE_ALP_WORD_TOO_LONG              = GBE_ALP_Error_Start + 20	//!<单词太长
	, GBE_ALP_NULL_WORD                  = GBE_ALP_Error_Start + 21	//!<词是空的
	, GBE_ALP_SH_NO_SPACE                = GBE_ALP_Error_Start + 22	//!<自造词空间不足
	, GBE_ALP_WORD_EXISTS                = GBE_ALP_Error_Start + 23	//!<自造词已经存在
	, GBE_ALP_INVALID_VALIDCHAR          = GBE_ALP_Error_Start + 24 //!<数据中的字符集有问题
	, GBE_ALP_DATA_MISMATCH              = GBE_ALP_Error_Start + 25 //!<数据与引擎版本不匹配
	//自造词数据错误
	, GBE_ALP_SH_BUFFER_TO_SMALL         = GBE_ALP_Error_Start + 26 //!<调用EBShDataInit的时候, 缓冲区的长度不足
	, GBE_ALP_SH_CORRUPT_DATA            = GBE_ALP_Error_Start + 27 //!<错误的自造词数据
	, GBE_ALP_SH_INVALID_ADDRESS         = GBE_ALP_Error_Start + 28 //!<自造词数据的头地址不能被4整除
	, GBE_ALP_SH_NOT_INIT                = GBE_ALP_Error_Start + 30 //!<自造词和词语调频数据没有初始化
	, GBE_ALP_SH_INVALID_WORD            = GBE_ALP_Error_Start + 32 //!<自造词数据中包涵非法的字母
	, GBE_ALP_SH_SPACE_NOT_ENOUGH        = GBE_ALP_Error_Start + 33 //!<空间不足
	, GBE_ALP_SH_DUPLICATE               = GBE_ALP_Error_Start + 34 //!<已经存在一个完全相同的单词
	, GBE_ALP_SH_PHRASE_INVALID_LENGTH   = GBE_ALP_Error_Start + 35 //!<自造词太长了
	, GBE_ALP_Failed_To_Init //!<引擎初始化失败
	, GBE_ALP_Failed_To_Attach_UDB	//!<UDB附着失败
	, GBE_CHN_Error_Start = -0x2000
	, GBE_CHN_FAILED					 = GBE_CHN_Error_Start + 1 //!<失败
	, GBE_CHN_NOTINIT					 = GBE_CHN_Error_Start + 2 //!<没有调用EBStartup()!
	, GBE_CHN_PEBIS_NULL				 = GBE_CHN_Error_Start + 3 //!<pEBIS为空.
	, GBE_CHN_METHOD_INVALID			 = GBE_CHN_Error_Start + 4 //!<输入法类型错误
	, GBE_CHN_DESIRE_LEN_INVALID		 = GBE_CHN_Error_Start + 5 //!<用户需要的长度错误.
	, GBE_CHN_KEY_INVALID				 = GBE_CHN_Error_Start + 6 //!<调用EBTestKey时的按键不合法
	, GBE_CHN_STATUS_ERROR				 = GBE_CHN_Error_Start + 7 //!<pEBIS->status不正确，不能调用.
	, GBE_CHN_ASSOC_ISN_ERROR			 = GBE_CHN_Error_Start + 8 //!<AssociateISN == GBE_CHN_NULL

	, GBE_CHN_INVALID_CHAR             = GBE_CHN_Error_Start + 9 //!<非法的字符
	, GBE_CHN_INVALID_TONE             = GBE_CHN_Error_Start + 10 //!<非法的音调
	, GBE_CHN_INVALID_INPUT_LEN        = GBE_CHN_Error_Start + 11 //!<输入串的长度过长
	, GBE_CHN_FIRST_IS_WILDCARD        = GBE_CHN_Error_Start + 12 //!<第一个输入的字符是通配符
	, GBE_CHN_NO_MATCH_WORD            = GBE_CHN_Error_Start + 13 //!<没有匹配的字
	, GBE_CHN_NO_MATCH_COMPONENT       = GBE_CHN_Error_Start + 14 //!<没有匹配的部首
	, GBE_CHN_INVALID_SYLLABLE         = GBE_CHN_Error_Start + 15 //!<非法的音节
	, GBE_CHN_INVALID_SYLLABLE_INDEX   = GBE_CHN_Error_Start + 16 //!<非法的音节下标
	, GBE_CHN_INPUT_STRING_NULL        = GBE_CHN_Error_Start + 17 //!<输入串为空
	, GBE_CHN_DATA_FILE_NOT_FOUND      = GBE_CHN_Error_Start + 18 //!<找不到数据文件
	, GBE_CHN_INVALID_DATA_FORMAT      = GBE_CHN_Error_Start + 19 //!<非法的数据格式
	, GBE_CHN_FAILED_TO_ALLOC_MEMORY   = GBE_CHN_Error_Start + 20 //!<内存分配失败
	, GBE_CHN_MISS_DATA                = GBE_CHN_Error_Start + 21 //!<缺少数据
	, GBE_CHN_STROKE_LEN_MISMATCH      = GBE_CHN_Error_Start + 22 //!<引擎的笔画数与数据的笔画数不一样
	, GBE_CHN_INVALID_SYLLLABLES_COUNT = GBE_CHN_Error_Start + 23	//!<音节个数错误
	, GBE_CHN_SH_BUFFER_TO_SMALL       = GBE_CHN_Error_Start + 24 //!<调用EBShDataInit的时候, 缓冲区的长度不足
	, GBE_CHN_SH_CORRUPT_DATA          = GBE_CHN_Error_Start + 25 //!<错误的自造词数据
	, GBE_CHN_SH_INVALID_ADDRESS       = GBE_CHN_Error_Start + 26 //!<自造词数据的头地址不能被4整除
	, GBE_CHN_SH_NOT_ENOUGH_SPACE      = GBE_CHN_Error_Start + 28	//!<自造词空间不足
	, GBE_CHN_SH_NOT_INIT              = GBE_CHN_Error_Start + 30 //!<自造词和词语调频数据没有初始化
	, GBE_CHN_SH_INVALID_WORD          = GBE_CHN_Error_Start + 32 //!<自造词数据中包涵非法的字母
	, GBE_CHN_SH_SPACE_NOT_ENOUGH      = GBE_CHN_Error_Start + 33 //!<空间不足
	, GBE_CHN_SH_DUPLICATE             = GBE_CHN_Error_Start + 34 //!<数据已经存在一个完全相同的单词
	, GBE_CHN_SH_PHRASE_INVALID_LENGTH = GBE_CHN_Error_Start + 35 //!<自造词太长了，超过了10个汉字
	, GBE_CHN_TO_INPUT_PHRASE          = GBE_CHN_Error_Start + 36 //!<词语输入

	, GBE_CHN_DIALECT_DATA_MISSMATCH	= GBE_CHN_Error_Start + 37 //方言数据与引擎主数据不匹配
	, GBE_CHN_INVALID_SYLLABLE_TABLE	= GBE_CHN_Error_Start + 38	//错误的拼音表数据，主要多拼音方式的引擎里面使用

	, GBE_CHN_ERR_CLOSE_PHRASE_FUNC		= GBE_CHN_Error_Start + 39 //!<词组功能已经关闭, 在EBFindFirstPageC里面返回，
	, GBE_CHN_NEED_EXTRA_PACK4_DATA		= GBE_CHN_Error_Start + 40 //!<引擎的结构体大小是强制4整除，但是数据中的结构体大小没有Pack到4整除。	
	, GBE_CHN_NEED_NO_EXTRA_PACK4_DATA	= GBE_CHN_Error_Start + 41 //!<引擎的结构体大小并不是强制4整除，但是数据中的结构体大小已经Pack到4整除。		
	, GBE_CHN_INPUTSTRUCT_IS_NULL		= GBE_CHN_Error_Start + 42 //!<没有中文引擎交互数据！
	, GBE_CHN_F_NO_SPACE				= GBE_CHN_Error_Start + 100 ///<MDB功能：RAM Buffer用完
	, GBE_CHN_TOO_MANY_MDB_FILE			= GBE_CHN_Error_Start + 101 ///<MDB个数超过了GB_MDB_MAX_COUNT

	//start[2010-10-20 zhj]
	, GBE_CHN_DUPLICATE_FILE	= GBE_CHN_Error_Start +102	///<细胞词库重复
	, GBE_CHN_NO_FILE_DATA_BUFFER	= GBE_CHN_Error_Start +103	///<细胞词库EBFileDataInit没有传入缓冲区信息，不能使用GBFT_DATA_IN_FILE
	, GBE_CHN_CPU_TYPE_FAILED	= GBE_CHN_Error_Start +104	///<PC 数据不该被使用到非PC 引擎
	, GBE_CHN_INDEX_MORE_MAX_MUL_PRON  = GBE_CHN_Error_Start +105	///<PC 音节反查序号大于多一字个数
	//end[2010-10-20 zhj]
	, GBE_CHN_TEST_IS_MAX_COUNT      = GBE_CHN_Error_Start + 1000 //!<测试版，测试次数已经超过最大规定次数
	, GBE_CHN_FAILED_TO_INIT			///<Chinese Module failed to initialize.
	, GBE_CHN_FAILED_TO_ATTACH_UDB		///<Chinese Module failed to attach UDB.

	, GBE_MMI_Error_Start = -0x3000		
	, GBE_MMI_NOT_INIT					///<invoke MMI function before Invoke GBMMIHandlerInit();
	, GBE_MMI_INITED                    ///< GBMMI已初始化      
	, GBE_MMI_TOO_MANY_MULTITAP_KEY ///<当前输入模式下面已经设置了太多的MultiTap按键
	, GBE_MMI_INPUT_STRING_FULL			///<当前的输入已满
	, GBE_MMI_INVALID_CAND_LIST_TYPE	///<当前的状态下不能使用这个输入模式
	, GBE_MMI_NO_SUCH_CAND				///<没有对应的候选
	, GBE_MMI_ENGINE_STATUS_ERR			///<引擎状态有误
	, GBE_MMI_SWITCH_STACK_FULL			///<切换的堆栈已满
	, GBE_MMI_INVALID_STACK_INDEX		///<错误的无缝切换堆栈索引
	, GBE_MMI_INVALID_EVENT				///<非法的消息类型
	, GBE_MMI_INVALID_SEL_INDEX			///<候选选择下标有误
	, GBE_MMI_INVALID_CAND_LIST			///<设定的候选框类型无效
	, GBE_MMI_UNSUPPORT					///<引擎没有GBMMI模块
	, GBE_MMI_NOT_SWITCH_LANG_STATUS	///<当前并没有处于无缝切换状态，add by zhj
	//start[2010-7-28 zhj]
	, GBE_MMI_IGNORE_EVENT				///<如果标点符号键被设置成输入过程中不能触发进入标点符号状态,则忽略这个按键事件
	, GBE_MMI_WRONG_STATUS				///<GBMMI处于错误的状态
	, GBE_MMI_NOT_ASSOCIATE_STATUS_NO_ASSOCIATE_CANDIDATE	///<不是联想状态无法获取联想候选
	//end[2010-7-28 zhj]
	, GBE_MMI_SYMBOL_KEY_ALREADY_CONSUMED		///<符号按键已经被处理
	// Start add [2011-4-25 haj]
	,GBE_MMI_NOT_SET_QWERTY_MAP_ARRAY   ///>没有设置Qwerty键盘映射数组
	,GBE_MMI_CONVERT_QWERTY_MAP_FAIL    ///>转换Qwerty键盘映射失败
	// end [2011-4-25 haj]



	, GBE_API_Error_Start = -0x4000		
	, GBE_API_ALREADY_INIT				///<已经初始化之后，又调用\ref GBInitialize，请调用\ref GBTerminate
	, GBE_API_MMI_BUFFER_NOT_ENOUGH		///<\ref tagGBInputStruct ::mmi_private_buffer空间不足
	, GBE_API_ENGINE_BUFFER_NOT_ENOUGH		///<\ref tagGBInputStruct ::engine_private_buffer空间不足
	//	, GBE_API_OUTPUT_INFO_IS_NULL		///<\ref tagGBInputStruct ::pOutputInfo为空
	, GBE_API_INVALID_PARAM				///<函数的参数至少包含一个无效参数
	, GBE_API_GBIS_IS_NULL				///<函数的参数pGBIS为NULL
	, GBE_API_MISS_LDB					///<在\ref GBSetCurLanguage函数里面，不存在对应语言的LDB
	, GBE_API_MISS_MAIN_LBD				///<在\ref GBSetCurLanguage函数里面，中文SubLang没有对应的语言数据
	, GBE_API_ALP_DONT_SUPPORT_SUB_LANG ///<Alphabetic引擎不支持Sub Language
	, GBE_API_UNSUPPORT_INPUT_MODE		///<不支持的输入模式
	, GBE_API_UNSUPPORT_CHINESE			///<此版本不支持中文输入
	, GBE_API_INVALID_INPUT_MODE		///<当前的语言输入模式不匹配，如在Alphabetic状态设置了拼音输入模式
	, GBE_API_INVALID_KOREAN_INPUT_MODE ///<设置韩语输入模式的时候，不为GBIM_Korean
	, GBE_API_INVALID_SYLLABLE_PO		///<Syllable候选分页选项无效
	, GBE_API_INVALID_CHN_PO			///<中文候选分页选项无效
	, GBE_API_INVALID_ALP_PO			///<Alphabetic候选分页选项无效
	, GBE_API_INVALID_GET_STR_WIDTH_FP	///<\ref GBSetPageOption传入的fpGetWStringWidth有误，使用字符串获取宽度的时候返回0或者负值
	, GBE_API_SYLLABLE_NOT_EXISTS		///<当前状态不存在音节
	, GBE_API_INVALID_SYLLABLE_INDEX	///<当前音节下标不在有效范围内
	, GBE_API_NOT_CHINESE				///<当前的功能是中文语言的功能，但是当前的语言不是中文
	, GBE_API_CAND_NOT_FOUND			///<候选没有找到
	, GBE_API_LANG_DIDNOT_SUPPORT_API	///<当前的语言不支持此API
	, GBE_API_UNSUPPORT_ALP				///<此版本不支持Alphabetic输入
	, GBE_API_AUX_INFO_IS_NULL			///<\ref tagGBInputStruct ::pAuxInfo 为空
	, GBE_API_PREV_NOT_EXISTS			///<不存在上一页
	, GBE_API_NEXT_NOT_EXISTS			///<不存在下一页
	, GBE_API_GET_STRING_WIDTH_ERROR	///<获取字符串长度函数返回负值
	, GBE_API_FAILED_TO_GET_CAND		///<获取候选失败
	, GBE_API_INVALID_ENGINE_STATUS		///<引擎状态不正确
	, GBE_API_INVALID_CAND_INDEX		///<获取当前的候选下标的函数返回值有误
	, GBE_API_NO_SUCH_CAND				///<没有对应的候选
	, GBE_API_ALP_NOT_SUPPORT			///<Alphabetic不支持此功能
	, GBE_API_CHN_NOT_SUPPORT			///<中文不支持此功能
	, GBE_API_NEED_TO_CALL_FIRST_PAGE	///<调用GBGetACand函数之前，需要首先成功调用GBFirstPage
	, GBE_API_CHN_SELECT_FAILED			///<调用EBHelperSelect或者EBHelperSelectEx失败
	, GBE_API_COMPONENTS_NOT_EXISTS		///<当前状态不存在部首
	, GBE_API_INVALID_LANGUAGE			///<无效的语言
	, GBE_API_NULL_FUNCTION_POINTER		///<空函数指针
	, GBE_API_NO_PAGE_INVOLVE			///<没有调用GBGet***PageCandiate函数
	, GBE_API_NO_MATCH_CAND				///<没有找到对应的候选
	, GBE_API_INVALID_MDB				///<无效的MDB数据
	, GBE_API_MDB_READ_AFTER_EOF		///<MDB功能：读入的位置已经超出文件结尾
	, GBE_API_MDB_BUFFER_NOT_ENOUPH		///<\ref GBMDBInit所传入的空间不足最小长度
	, GBE_API_MDB_INVALID_ID			///<MDB的ID无效
	, GBE_API_MDB_INVALID_READ_FP		///<GBMDBAttachFile函数提供的fpRead回调函数无效
	, GBE_API_To_Many_UDB				///<UDB的个数超出了限制，seen function GBUDBAttach
	, GBE_API_INVALID_UDB_ID			///<无效的UDB ID
	, GBE_API_LANG_UDB_EXISTS			///<该语言的UDB已经存在
	, GBE_API_UNSUPPORT_LANGUAGE		///<不支持该语言
	, GBE_API_INVALID_SYNATX_DATA		///<整句数据无效
	, GBE_API_SYNTAX_SELECT_FAILED		///<整句引擎GBSyntaxSelectCandidate2调用失败
	, GBE_API_SYNTAX_UDB_ATTACH_FAILED	///<GBSyntaxAttachUDB失败
	, GBE_API_UNSUPPORT_SYNTAX			///<不支持整句引擎
	, GBE_API_TOO_MANY_MDB				///<MDB太多
	, GBE_API_SYNTAX_CHANGE_INPUT_FAILED ///<GBSyntaxAttachUDB失败
	, GBE_API_INPUT_STRING_TO_LONG		///<输入串长度太长
	, GBE_API_NEED_FILE_MDB				///<需要GBMDBAttachFile对应的MDB
	, GBE_API_UPSCREEN_STRING_FULL		///<上屏Buffer已满
	, GBE_API_UPSCREEN_STRING_POINT_NULL///上屏指针为空
	, GBE_API_NO_ENGINE					///<没有任何一个引擎有效
	// start [2011-4-22 Zhaokun]
	//, GBE_API_WRONG_STRING_IN_WRONG_STATUS	///<当前状态下使用当前输入串对引擎无效，add by zhj
	, GBE_API_INPUT_STRING_IS_NULL		///<输入串为NULL
	// end [2011-4-22 Zhaokun]
	, GBE_API_MDB_INVALID_SEEK_FP		///<GBMDBAttachFile函数提供的fpSeek回调函数无效
	, GBE_API_THIS_INPUT_MODE_NOT_TONE		///<当前输入模式没有音调

	//remove start[2010-7-28 zhj]
	//搬到上面去，这是GBMMI的错误，不是GBAPI的错误
	////start[2010-4-12 zhj]
	//,GBE_API_IGNORE_EVENT				///<如果标点符号键被设置成输入过程中不能触发进入标点符号状态,则忽略这个按键事件
	////end[2010-4-12 zhj]
	//remove end[2010-7-28 zhj]
	// Start add [2011-6-16 haj]
	, GBE_API_VERIFY_WINGUO_FAILE		///<验证Winguo失败	
	// end [2011-6-16 haj]
	, GBE_API_NOT_LOAD_CHN_DATA			///<没有加载中文数据
	, GBE_API_NO_INIT					///<没有初始化
	//start[2010-7-19 zhj]
	,GBE_KOREAN_Error_Start=-0x5000
	, GBE_KOREAN_FAILED                     = GBE_KOREAN_Error_Start + 1
	, GBE_KOREAN_INVALID_INDEX              = GBE_KOREAN_Error_Start + 100
	, GBE_KOREAN_NOTINIT					 = GBE_KOREAN_Error_Start + 2 //!<没有调用EBStartup()!
	, GBE_KOREAN_PEBIS_NULL				 = GBE_KOREAN_Error_Start + 3 //!<pEBIS为空.
	, GBE_KOREAN_INVALID_INPUT_LEN          = GBE_KOREAN_Error_Start + 4 //

	, GBE_KOREAN_NO_MATCH                   = GBE_KOREAN_Error_Start + 8 //!<没找到匹配串
	, GBE_KOREAN_INVALID_INVOKE             = GBE_KOREAN_Error_Start + 9 //!<非法调用
	, GBE_KOREAN_NO_DATA_FILE               = GBE_KOREAN_Error_Start + 14
	, GBE_KOREAN_INVALID_DATA_FORMAT        = GBE_KOREAN_Error_Start + 15
	, GBE_KOREAN_INVALID_CHAR               = GBE_KOREAN_Error_Start + 19
	, GBE_KOREAN_WORD_TOO_LONG              = GBE_KOREAN_Error_Start + 20
	, GBE_KOREAN_NULL_WORD                  = GBE_KOREAN_Error_Start + 21
	, GBE_KOREANP_INVALID_VALIDCHAR          = GBE_KOREAN_Error_Start + 24 //!<数据中的字符集有问题
	, GBE_KOREAN_DATA_MISMATCH              = GBE_KOREAN_Error_Start + 25 //!<数据与引擎版本不匹配
	//end[2010-7-19 zhj]

	// start add [2011-5-24 haj]
	, GBE_Mars_Error_Start = -0x6000
	// end add [2011-5-24 haj]
};

#define CHN_ENGINE_TO_API_ERR(err)		(GBE_CHN_Error_Start - (err))
#define ALP_ENGINE_TO_API_ERR(err)		(GBE_ALP_Error_Start - (err))
//start[2010-7-19 zhj]
#define KOREAN_ENGINE_TO_API_ERR(err)		(GBE_KOREAN_Error_Start - (err))
//end[2010-7-19 zhj]
// start add [2011-5-24 haj]
#define MARS_ENGINE_TO_API_ERR(err)		(GBE_Mars_Error_Start - (err))
// end  [2011-5-24 haj]

/** \brief 输入结构体的Flag (input) */
enum GBInputStructFlag
{
	GBIS_INPUT_STRING_UPDATED = (1 << 0)		///<输入串已经更新
	, GBIS_SYLLABLE_INDEX_UPDATED = (1 << 1)	///<音标已经更新，引擎内部使用
	, GBIS_SELECTED_CANDIDATE = (1 << 2)		///<选择了候选
	//Change by ZhaoKun at 2011/1/12 9:29:54 [Start]
	, GBIS_SYLLABLE_TONE_UPDATED = (1 << 3)		///<更新了音调
	//Change by ZhaoKun at 2011/1/12 9:29:54 [End]
};

/** \brief GBMMIRegisterMultiTapSymbols 函数能够最多设置多少个Key */
#define GB_MAX_MULTI_TAP_SYMBOLS	4

/** \brief 候选框类型 */
enum GBCandListType
{
	GBCL_INVALID
	, GBCL_ROW_KEYBD			///<分行的候选（键盘）, 适用于Chn和Alp
	, GBCL_ROW_TCH_SCR			///<分行的候选（触摸屏）, 适用于Chn和Alp
	, GBCL_SINGLE_CAND			///<单个候选(候选框不显示)，仅适用于Alp
	, GBCL_ROW_MULTITAP			///<带候选框的MultiTap候选，可以设置行数, 只适用于标点符号
	, GBCL_MULTITAP				///<MultiTap候选(候选框不显示)，
	//start[2010-3-9 zhj]
	, GBCL_ROW_MULTITAP_WITH_TIMER	///用来显示multitap候选的候选框，带定时器			
	//end[2010-3-9 zhj]
};

/** \brief 用于设置候选行数的Enum */
enum GBCandStatusEnum 
{
	GBCS_INPUT						///<输入状态, 包括了输入状态, 中文自造词, Alphabetic自造词等状态
	, GBCS_ASSOCIATE				///<联想状态
};

/** \brief Alphabetic普通的候选列表 */
#define GBCL_ALP_NORMAL(cl)		((cl) == GBCL_ROW_KEYBD || (cl) == GBCL_ROW_TCH_SCR \
	|| (cl) == GBCL_SINGLE_CAND)
/** \brief 中文普通的候选列表*/
#define GBCL_CHN_NORMAL(cl)		((cl) == GBCL_ROW_KEYBD || (cl) == GBCL_ROW_TCH_SCR)

/** \brief GBHRESULT返回值的意义 */
enum GBHandleResultEnum 
{
	GB_CONSUMED = 0				///<这个键已经被引擎处理，外部无需处理
	, GB_NOT_CONSUMED = GB_NOT_HANDLED				///<这个键引擎没有处理，需要外部处理
	//start[2010-4-12 zhj]
	,GB_IGNORE						///<这个键引擎没有处理，也不需要外部处理
	//end[2010-4-12 zhj]
};
/*@}*/

/** \brief 输入法状态 */
enum GBInputModeStatusEnum
{
	GBIMS_INITIAL				///<初始化
	, GBIMS_INPUT				///<输入状态
	, GBIMS_CHN_UAW				///<中文自造词选择过程中
	, GBIMS_ALP_UAW_NO_MORE_CAND///<没有其他候选的时候按下翻
	, GBIMS_ALP_UAW_BEGIN		///<Alphabetic开始自造词
	, GBIMS_ALP_UAW				///<Alphabetic自造词过程中
	, GBIMS_ALP_UAW_Confirm		///<自造词结束，用户确认加入，这个状态可以关闭
	, GBIMS_ASSOCIATE			///<联想状态，如果对应的语言没有联想功能，
	////则词语输入之后自动变为GBIMS_INITIAL
	, GBIMS_SELECTED			///<选择候选状态
	//	, GBIMS_Interpunction		///<输入标点符号状态
	, GBIMS_MULTITAP_INTERPUNCTION	///<MultiTap标点符号模式
	//	, GBIMS_Full_Scr_Symbol		///<全屏标点符号状态
	//start[2010-3-15 zhj]
	//配合GBFO_Chn_All_Num_Can_Continuously_Input所做的改动
	, GBIMS_MULTITAP_INTERPUNCTION_BEGIN	///<准备开始标点符号模式
	//end[2010-3-15 zhj]
	, GBIMS_STATUS_COUNT		///<输入法状态个数
};

#ifndef __GB_CHN_TONE_ENUM__
#define __GB_CHN_TONE_ENUM__
enum GBChnToneEnum{
	GB_CHN_TONE_NULL = 0
	,GB_CHN_TONE_1 = 1	//音调: 
	,GB_CHN_TONE_2		//音调: 
	,GB_CHN_TONE_3		//音调: 
	,GB_CHN_TONE_4		//音调: 
	,GB_CHN_TONE_5		//音调: 轻
	,GB_CHN_TONE_6		//音调: 用于粤音
};
#endif

#ifndef __GB_WORDS_SPELL_CORRECTION_MATCH_TYPE__
#define __GB_WORDS_SPELL_CORRECTION_MATCH_TYPE__
enum GB_WORDS_SPELL_CORRECTION_MATCH_TYPE
{
	GB_WSC_ALL_MATCH = 0					//全部匹配
	,GB_WSC_COMPLETE_MATCH = (1<<0)			//完全匹配 //1
	,GB_WSC_WRONG_PRESS = (1<<1)			//错按	//2
	,GB_WSC_MORE_PRESS = (1<<2)				//多按	//4
	,GB_WSC_LESS_PRESS = (1<<3)				//少按	//8
	,GB_WSC_COMPLETE_MATCH_ASSOC = (1<<4)	//完全匹配的预测	//16
	,GB_WSC_WRONG_PRESS_ASSOC = (1<<5)		//错按预测		//32
	,GB_WSC_MORE_PRESS_ASSOC = (1<<6)		//多按预测		//64
	,GB_WSC_LESS_PRESS_ASSOC = (1<<7)		//少按预测		//128
};
#endif


#endif
