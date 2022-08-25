#ifndef _DECRYPTION_H_
#define _DECRYPTION_H_

/* portable character for multichar character set */
typedef char                    kal_char;
/* portable wide character for unicode character set */
typedef unsigned short          kal_wchar;

/* portable 8-bit unsigned integer */
typedef unsigned char           kal_uint8;
/* portable 8-bit signed integer */
typedef signed char             kal_int8;
/* portable 16-bit unsigned integer */
typedef unsigned short int      kal_uint16;
/* portable 16-bit signed integer */
typedef signed short int        kal_int16;
/* portable 32-bit unsigned integer */
typedef unsigned int            kal_uint32;
/* portable 32-bit signed integer */
typedef signed int              kal_int32;

typedef enum 
{
    /* FALSE value */
    KAL_FALSE,
    /* TRUE value */
    KAL_TRUE
} kal_bool;

/******************************************************************************
 *  Function    -  track_fun_decryption
 *
 *  Purpose     -  EPO解密函数
 *
 *  Description -  参数
 *                 dec  ----  解密后的目标Buffer(长度定义大于带解密的长度)
 *                 src  ----  待解密的数据Buffer
 *                 szie ----  带解密的数据长度
 *  Return
 *        >0   解密成功，值等于解密后的文件大小
 *        -1   解密失败，文件未被加密
 *        -2   解密失败，校验出错
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2013
 * ----------------------------------------
*******************************************************************************/
extern kal_int32 track_fun_decryption(kal_uint8 *dec, kal_uint8 *src, int size);
#endif
