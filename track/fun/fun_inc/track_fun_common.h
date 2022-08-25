#ifndef _TRACK_FUN_COMMON_H
#define _TRACK_FUN_COMMON_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_drv.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*
 * 32-bit integer manipulation macros (big endian)
 */
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
{                                                       \
    (n) = ( (unsigned int) (b)[(i)    ] << 24 )             \
        | ( (unsigned int) (b)[(i) + 1] << 16 )             \
        | ( (unsigned int) (b)[(i) + 2] <<  8 )             \
        | ( (unsigned int) (b)[(i) + 3]       );            \
}
#endif

#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
{                                                       \
    (b)[(i)    ] = (unsigned char) ( (n) >> 24 );       \
    (b)[(i) + 1] = (unsigned char) ( (n) >> 16 );       \
    (b)[(i) + 2] = (unsigned char) ( (n) >>  8 );       \
    (b)[(i) + 3] = (unsigned char) ( (n)       );       \
}
#endif

/*
 * 16-bit integer manipulation macros (big endian)
 */
#ifndef GET_UINT16_BE
#define GET_UINT16_BE(n,b,i)                            \
{                                                       \
    (n) = ( (unsigned short) (b)[(i)    ] <<  8 )             \
        | ( (unsigned short) (b)[(i) + 1]       );            \
}
#endif

#ifndef PUT_UINT16_BE
#define PUT_UINT16_BE(n,b,i)                            \
{                                                       \
    (b)[(i)    ] = (unsigned char) ( (n) >>  8 );       \
    (b)[(i) + 1] = (unsigned char) ( (n)       );       \
}
#endif

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Functions Define                     函数声明
******************************************************************************/


extern void track_fun_msg_send(kal_uint16 msg_id, void *req, module_type mod_src, module_type mod_dst);


/******************************************************************************/
/*   字符处理类函数       */
/******************************************************************************/

/******************************************************************************
 *  Function    -  track_fun_str_analyse
 *
 *  Purpose     -  将字符串按特定单个字符进行拆分修改
 *
 *  Description -  str_data    需要进行拆分的字符串(注意经过处理后，源字符串将被改变)
 *                 tar_data    指针数组，拆分后的结果将使用指针逐个指向
 *                 limit       指针数组大小
 *                 startChar   开始字符，例如'*'表示将从str_data字符串中首先查找'*'号，在找到'*'之前忽略任何其它处理
 *                                 该值可以为NULL，则表示拆分将从首个字符开始
 *                 endChars    结束字符，这是一个字符串，拆分时遇到任何一个其中的字符都结束继续拆分
 *                 splitChar   拆分字符，这是判断拆分的唯一标识
 *
 *  example     -
 *
 *  Warning     -  limit 值不能大于 tar_data 实际大小，否则发生越界写操作
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern int track_fun_str_analyse(char *str_data, char **tar_data, int limit, char startChar, char *endChars, char splitChar);


/******************************************************************************
 *  Function    -  track_fun_str_analyse2
 *
 *  Purpose     -  将字符串按特定单个字符进行拆分修改 V2
 *
 *  Description -  str_data    需要进行拆分的字符串(注意经过处理后，源字符串将被改变)
 *                 tar_data    指针数组，拆分后的结果将使用指针逐个指向
 *                 limit       指针数组大小
 *                 startChar   开始字符，例如'*'表示将从str_data字符串中首先查找'*'号，在找到'*'之前忽略任何其它处理
 *                                 该值可以为NULL，则表示拆分将从首个字符开始
 *                 endChars    结束字符，这是一个字符串，拆分时遇到任何一个其中的字符都结束继续拆分
 *                 splitChar   拆分字符串，这是判断拆分的唯一标识(str_analyse拆分这里仅仅是单个字符)
 *
 *  example     -
 *
 *  Warning     -  limit 值不能大于 tar_data 实际大小，否则发生越界写操作
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-09-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern int track_fun_str_analyse2(char *str_data, char **tar_data, int limit, char startChar, char *endChars, char *splitChar);


extern kal_uint8 track_fun_check_ip(const char * str);


/*---------------------------------------------------------------------------------------
 * FUNCTION			track_fun_asciiIP2Hex
 *
 * DESCRIPTION		转换IP地址格式
 *
 * PARAMETERS		void *asciiIP	输入asc码
 *					void *hex	输出十六进制
 *
 * RETURNS
 *
 *---------------------------------------------------------------------------------------*/
extern kal_bool track_fun_asciiIP2Hex(char *asciiIP, kal_uint8 *hex);


/******************************************************************************
 * FUNCTION:  - track_fun_parseInt
 * DESCRIPTION: - 将10进制或者16进制的字符串转换成整形
 * Input: string ,radix 进制10为10进制,16为16进制,不肯定请传0
 * Output:-1为不能正常转换
 * Returns:
  * modification history
 * --------------------
 * v1.0  , 18-06-2012,  WangQi  written
 * --------------------
 ******************************************************************************/
extern int track_fun_parseInt(char * str);

extern kal_uint32 track_fun_parse4(char * str);

extern int track_fun_mem_to_ascii(char *out, int outlimit, void * buff, int size);

extern void track_fun_toUpper(char *buf);


extern void track_fun_make_small_letter(char* buf);


/*---------------------------------------------------------------------------------------
 * FUNCTION			track_fun_string2U16
 *
 * DESCRIPTION		字符转16位输出
 *
 * PARAMETERS		void *string	待转字符串
 *
 * RETURNS			U16			转换结果(16位)
 *
 *---------------------------------------------------------------------------------------*/
extern kal_uint16 track_fun_string2U16(void *string);


/******************************************************************************
 *  Function    -  track_fun_interval_range_manage
 *
 *  Purpose     -  将指令中的数值转化为数字
 *
 *  Description - [min,max]
 *
 * modification history
 * ----------------------------------------
 *
 * ----------------------------------------
 ******************************************************************************/
extern kal_uint16 track_fun_interval_range_manage(char *data_str, U16 min, U16  max);


/******************************************************************************
 *  Function    -  track_fun_Get_GPS_Coordinate
 *
 *  Purpose     -  将输入的坐标转化成数字
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
extern kal_bool track_fun_Get_GPS_Coordinate(char* coordinate, double* data);

/******************************************************************************
 *  Function    -  track_fun_check_str_is_number
 *
 *  Purpose     -  检测字符串是不是全是数字组成
 *
 *  Description -  flag == 1 允许字符串中包含'+'或'-'
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 24-12-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_uint8 track_fun_check_str_is_number(kal_uint8 flag, const char *str);

/******************************************************************************
 *  Function    -  track_fun_atoi
 *
 *  Purpose     -  扩展atoi函数
 *
 *  Description -  当字符串存在非有效字符时返回 -99
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-12-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_int32 track_fun_atoi(const char *str);

/******************************************************************************
 *  Function    -  track_fun_atof
 *
 *  Purpose     -  扩展atof函数
 *
 *  Description -  当字符串存在非有效字符时返回 -99
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-12-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern float track_fun_atof(const char *str);

/*---------------------------------------------------------------------------------------
* FUNCTION			track_fun_check_data_is_port
*
* DESCRIPTION		判断是否为端口号
*
* PARAMETERS		void *data	asc码端口号
*
* RETURNS			BOOL
*
*---------------------------------------------------------------------------------------*/
extern kal_bool track_fun_check_data_is_port(void *data);

extern kal_uint8 track_fun_check_phone_number(char *number);

/******************************************************************************
 *  Function    -  track_fun_abs_degrees
 *
 *  Purpose     -  计算两个方向的角度值，最大不超过180度
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 17-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern float track_fun_abs_degrees(float a, float b);

extern kal_uint32 track_fun_convert_phone_number_to_int(char *ascii_number);

/******************************************************************************
 *  Function    -  track_fun_UTF16_B_and_L_swap
 *
 *  Purpose     -  交换UTF16大端小段，高位低位互调
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 13-12-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern void track_fun_UTF16_B_and_L_swap(kal_uint8 *pOutBuffer, kal_uint8 *pInBuffer, kal_int32 nBuffsize);

extern char *track_fun_hextimestep_view(U8 *data);

extern int track_fun_stringtime_to_hex(char *src, U8 *dec);

/******************************************************************************/
/*   影响系统类函数       */
/******************************************************************************/

/******************************************************************************
 *  Function    -  track_fun_update_time_to_system
 *
 *  Purpose     -  更新系统时间
 *
 *  Description -  GPS 优先与服务器下发的时间
 *
 *             app: 1 GPS   ,2 服务器
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-09-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_uint8 track_fun_update_time_to_system(kal_uint8 app, applib_time_struct *utcTime);

/******************************************************************************
 *  Function    -  track_fun_FS_GetDiskInfo
 *
 *  Purpose     -  获得FAT剩余空间大小
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 12-06-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern U32 track_fun_FS_GetDiskInfo(void);

/******************************************************************************
 *  Function    -  track_fun_SystemTime_Sync_FromStrTime
 *
 *  Purpose     -  将字符串格式表示时间的解析出来同步进系统
 *
 *  Description -  字符串格式必须如："2012-9-11 14:36:44"
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-09-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_int8 track_fun_SystemTime_Sync_FromStrTime(nvram_gps_time_zone_struct *ReferenceValue, char *data);

extern void track_fun_reverse_16(kal_uint8 *dec, kal_uint16 src);

extern void track_fun_reverse_32(kal_uint8 *dec, kal_uint32 src);

extern kal_uint8 *track_fun_strWchr(const kal_uint8 *wchr, kal_uint8 *data, int len);

extern void track_fun_view_UTF16BE_string(kal_uint8 *src_buff, kal_int32 src_len);

extern kal_int32 track_fun_UTF16BE_to_GB2312(kal_uint8 *src_buff, kal_int32 src_len, char *dest_buff, kal_int32 dest_size);

/******************************************************************************
 *  Function    -  track_fun_trim
 *
 *  Purpose     -  删除字符串头尾多余空格
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 02-12-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern char *track_fun_trim(char *str);

/******************************************************************************
 *  Function    -  track_fun_trim2
 *
 *  Purpose     -  删除字符串头尾的空格，制表符，换行符
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 26-05-2016,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern char *track_fun_trim2(char *str);


extern kal_uint32 track_fun_del_string(char *str, char *sub);
extern kal_uint8* track_fun_stringtohex(kal_uint8 * buf, kal_uint16 len);
#endif  /* _TRACK_FUN_COMMON_H */
