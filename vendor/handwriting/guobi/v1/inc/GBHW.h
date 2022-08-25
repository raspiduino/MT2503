#ifndef __GBHW_H__
#define __GBHW_H__

//拉丁语言编码区分(前5种是为了和中文兼容)
#define GBHW_LATIN_RANGE_NUMBER					0x00010000
#define GBHW_LATIN_RANGE_EN_LOWER				0x00020000
#define GBHW_LATIN_RANGE_EN_UPPER				0x00040000
#define GBHW_LATIN_RANGE_ASC_PUNCTUATION		0x00080000
#define GBHW_LATIN_RANGE_CONTROL_CHAR			0x20000000
#define GBHW_LATIN_RANGE_EN_SPACING				0x10000000
#define GBHW_LATIN_RANGE_A		(GBHW_LATIN_RANGE_EN_LOWER | GBHW_LATIN_RANGE_EN_UPPER | GBHW_LATIN_RANGE_EN_SPACING)
#define GBHW_LATIN_RANGE_B						0x00100000
#define GBHW_LATIN_RANGE_C						0x00200000
#define GBHW_LATIN_RANGE_D						0x00400000
#define GBHW_LATIN_RANGE_E						0x00800000
#define GBHW_LATIN_RANGE_F						0x01000000
#define GBHW_LATIN_RANGE_G						0x02000000
#define GBHW_LATIN_RANGE_H						0x04000000
#define GBHW_LATIN_RANGE_I						0x08000000
#define GBHW_LATIN_RANGE_J						0x40000000
#define GBHW_LATIN_RANGE_K						0x80000000

//[中文数据]
//识别范围：数字
#define GBHW_OPT_RANGE_NUMBER				0x1
//识别范围：小写字母
#define GBHW_OPT_RANGE_LOWER_CHAR			0x2
//识别范围：大写字母
#define GBHW_OPT_RANGE_UPPER_CHAR			0x4
//识别范围：半角标点符号
#define GBHW_OPT_RANGE_ASC_PUNCTUATION		0x8
//识别范围：ASCII码，包含数字、小写字母、大写字母和半角标点符号
#define GBHW_OPT_RANGE_ASCII				(GBHW_OPT_RANGE_NUMBER | GBHW_OPT_RANGE_LOWER_CHAR | GBHW_OPT_RANGE_UPPER_CHAR | GBHW_OPT_RANGE_ASC_PUNCTUATION)
//识别范围：GB2312汉字
#define GBHW_OPT_RANGE_GB2312				0x8000 
//识别范围：BIG5汉字
#define GBHW_OPT_RANGE_BIG5					0x200
//识别范围：GBK汉字
#define GBHW_OPT_RANGE_GBK					0x400
//识别范围：中文标点符号
#define GBHW_OPT_RANGE_CHN_PUNCTUATION		0x800
//识别范围：GB18030-2003所规定的汉字
#define GBHW_OPT_RANGE_GB18030				0x1000
//识别范围：空格、回车以及删除等三个控制字符
#define GBHW_OPT_RANGE_CONTROL_CHAR			0x2000

#define GBHW_OPT_RANGE_PUNCTUATION	(GBHW_OPT_RANGE_ASC_PUNCTUATION | GBHW_OPT_RANGE_CHN_PUNCTUATION)

//识别范围：默认识别范围，为GB2312汉字、数字、字母和标点符号。不包括控制符号
#define GBHW_OPT_RANGE_DEFAULT				(GBHW_OPT_RANGE_GB2312 | GBHW_OPT_RANGE_ASCII | GBHW_OPT_RANGE_PUNCTUATION)

/*************************************************两个注意点**********************************************/
//注意：本行以上的各个[识别范围]， 对应的是中文数据。当使用中文数据时，请选择以上的选项来控制输出候选的范围。这时引擎不处理高16位。
//注意：本行以下的各个[识别范围]， 对应的是拉丁数据。当使用拉丁数据时，请选择以下的选项来控制输出候选的范围。这时引擎不处理低16位。

//[拉丁数据]
//识别范围：数字
#define GBHW_OPT_RANGE_LATIN_NUMBER					(GBHW_LATIN_RANGE_NUMBER)
//识别范围：半角标点符号
#define GBHW_OPT_RANGE_LATIN_ASC_PUNCTUATION		(GBHW_LATIN_RANGE_ASC_PUNCTUATION)
//识别范围：空格、回车以及删除等三个控制字符
#define GBHW_OPT_RANGE_LATIN_CONTROL_CHAR			(GBHW_LATIN_RANGE_CONTROL_CHAR)
//识别范围：English	Kurdish		Malagasy	Kinyarwanda		Irish		Zulu	  Zhuang	Oromo	Indonesian
//          英语    库尔德语    马尔加语    基尼亚卢旺达语  爱尔兰语   祖鲁语	  壮语      奥罗莫	印度尼西亚
#define GBHW_OPT_RANGE_A_LANGUAGES					(GBHW_LATIN_RANGE_A)
//识别范围：GBHW_OPT_RANGE_A_LANGUAGES对应语言的小写
#define GBHW_OPT_RANGE_A_LANGUAGES_LOWER			(GBHW_LATIN_RANGE_EN_LOWER)
//识别范围：GBHW_OPT_RANGE_A_LANGUAGES对应语言的大写
#define GBHW_OPT_RANGE_A_LANGUAGES_UPPER			(GBHW_LATIN_RANGE_EN_UPPER)
//识别范围：Portuguese	portuguese_sa	Finnish	Swedish	Tagalog
//          葡萄牙语    葡萄牙语(sa)	芬兰语	瑞典	菲律宾语
#define GBHW_OPT_RANGE_B_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_H)
//识别范围：Vietnamese	Azerbaijiani
//          越南		阿塞拜疆
#define GBHW_OPT_RANGE_C_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J | GBHW_LATIN_RANGE_K)
//识别范围：Croatian	Czech	Polish	Romanian	Serbian		Yoruba
//          克罗地亚	捷克语	波兰语	罗马尼亚	塞尔维亚	约鲁巴
#define GBHW_OPT_RANGE_D_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_I | GBHW_LATIN_RANGE_J)
//识别范围：French	Afrikaans
//			法语	南非语
#define GBHW_OPT_RANGE_E_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_F | \
	                                                 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I)
//识别范围：Hinglish	Bosnian		Uzbek		Catalan		Malaysian
//						波斯尼亚	乌兹别克	加泰罗尼亚	马来西亚
#define GBHW_OPT_RANGE_F_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C)
//识别范围：Danish	Duch	Estonian	German	Spanish	Spanish_sa	Swahili
//			丹麦	杜赫	爱沙尼亚语	德语	西班牙	西班牙(sa)	斯瓦希里
//			Norwegian	Hausa	Basque	Italian	Albanian	Turkmen	Turkish
//			挪威		豪萨	巴斯克	意大利	阿尔巴尼亚	土库曼	土耳其
#define GBHW_OPT_RANGE_G_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
	                                                 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
	                                                 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H)
//识别范围：Hungarian	Latvian
//			匈牙利		拉脱维亚
#define GBHW_OPT_RANGE_H_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
													 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J)
//识别范围：Lithuanian	Slovak		Slovenian
//			立陶宛		斯洛伐克	斯洛文尼亚
#define GBHW_OPT_RANGE_I_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_I | GBHW_LATIN_RANGE_J)
//识别范围：Icelandic
//			冰岛
#define GBHW_OPT_RANGE_J_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
													 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J | GBHW_LATIN_RANGE_K)


//以下6项是为了兼容以前版本，2012年08月16日之后，请不要再使用以下6项
#define GBHW_OPT_FRENCH				GBHW_OPT_RANGE_E_LANGUAGES//0x10000	//法语
#define GBHW_OPT_GERMAN				GBHW_OPT_RANGE_G_LANGUAGES//0x20000	//德语
#define GBHW_OPT_SPANISH			GBHW_OPT_RANGE_G_LANGUAGES//0x30000	//西班牙
#define GBHW_OPT_ITALIAN			GBHW_OPT_RANGE_G_LANGUAGES//0x40000	//意太利
#define GBHW_OPT_TURKISH			GBHW_OPT_RANGE_G_LANGUAGES//0x50000	//土耳其
#define GBHW_OPT_PORTUGUESE			GBHW_OPT_RANGE_B_LANGUAGES//0x60000	//葡萄牙

#ifndef GBAPI
#ifdef GBIMPORT
#define GBAPI  __declspec(dllimport)
#else
#define GBAPI	extern
#endif
#endif

#ifdef __cplusplus
extern "C"{
#endif

enum GB_HW_Fail {
	GBHW_OK = 0
		, GBHW_Err_Begin = -1000
		, GBHW_Err_Not_Init
		, GBHW_Err_Init_Null_Data //空数据
		, GBHW_Err_Init_Invalid_Data //数据格式错误
		, GBHW_Err_Recg_Invalid_Result_Len //要求的候选数目有误
		, GBHW_Err_Init_Invalid_Dim //数据中数据的维数超出范围
		, GBHW_Err_Option_Invalid_Speed //GBHWSetOption函数设置GBHW_Index_Set_Speed的时候，param参数超出有效值
		, GBHW_Err_Option_Invalid_Index //GBHWSetOption函数index参数无效
		, GBHW_Err_Winguo_Verify_No_Match//GBHWNew(或GBHWNewFile)函数返回，表示问果验证码错误
		, GBHW_Err_Cluster_Prototypes //GBHWNewFile函数返回，表示数据中样本数目超过定义的最大值
};

enum GB_HW_Option_Index {
	GBHW_Invalid_Index = 0
		/*
		value为0的时候，设置为默认的速度
		value值越大，则速度越慢，准确率越高，
		反之速度越快，准确率越低；
		有效区间为[5, 30]
		这个设置需要在引擎启动之后(GBHWNew)设置，才能生效。
		*/
		, GBHW_Index_Set_Speed 
};

// 识别引擎初始化
// 调用识别引擎前必须调用该函数进行初始化
// 返回0表示成功 
#ifdef _C166
GBAPI int GBHWNew(const void _huge * data,void* param);
#else
GBAPI int GBHWNew(const void * data,void* param);
#endif

//识别引擎主要的函数
//pbTrace (in) 字轨迹，为了节省空间，引擎会修改这个数组的值
//result (out) Unicode 内码输出
//candNum (in)需要的候选个数，最大不能超过MAX_RESULT_COUNT
//option (in)识别参数，GB_OPT中不同值的组合
//prob (out)识别概率输出, 取值范围是(0-1000), 实际值的1000倍。
//返回结果的个数
GBAPI int GBHWRecognize(short* pbTrace, unsigned short * result, int candNum, unsigned long option);
GBAPI int GBHWRecognizeEx(short* pbTrace, unsigned short * result, int candNum, unsigned long option,long *prob);

/*!
 * \brief 设置识别引擎识别参数
 * \param index 范围是GB_HW_Option_Index里面的值
 * \param value 根据index定义不同，详细请参照每一个index的说明
 * \ret 如果index为非法值，则返回GBHW_Err_Option_Invalid_Index 
 *      成功返回GBHW_OK
 *      其他返回值请查看每一个错误值的说明
 */
GBAPI int GBHWSetOption(int index, unsigned long value);


#ifdef GBHW_DATA_FROM_FILE
enum GB_STREAM_FLAG
{
   GB_SEEK_SET,
   GB_SEEK_CUR,
   GB_SEEK_END,
   GB_SEEK_NOMOVE
};

enum GB_STREAM_ERROR
{
   GB_FSEEK_FUNC_NOT_SET,
   GB_FREAD_FUNC_NOT_SET
};

typedef int (*pfGBHWFreadT)(void * ptr,int size,int nmemb,void * stream,int offset,int whence);
int GBHWNewFile(const void * stream,void* param);
void GBHWSetRequireRam(void *buffer,int lth);
void GBHWSetDataSource(void* stream);
void GBHWSetFread(pfGBHWFreadT pf);
int GBHWGetLastError();

#endif

#ifdef __cplusplus
}
#endif

#endif
