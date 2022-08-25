/******************************************************************************
 * track_os_log.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        提供输出日志接口
 *
 * modification history
 * --------------------
 * v1.0   2012-07-21,  WangQi create this file
 *
 ******************************************************************************/

#ifndef _TRACK_LOG_H
#define _TRACK_LOG_H

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/


/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
/*
 * general definitions
 */

typedef enum
{
    L_CON = 0,     //1开机信息等，很少打印的
    L_DRV = 1,     //driver
    L_SOC = 2,     // network
    L_CMD = 3,     // at sms call factory
    L_OS  = 4,     //
    L_APP = 5,     //
    L_SYS = 6,     //
    L_FUN = 7,     //
    L_UART = 8,    //用于串口外设调试
    L_TEST= 9,     //smt测试模式下
    L_MCU,
    L_GPS = 11,    // network
    L_OBD = 12,    // network
    L_BMS = 13,
    L_MAX
} enum_LOG_MODULE;

typedef enum
{
    L_V1 = 1,
    L_V2 = 2,
    L_V3 = 3,
    L_V4 = 4,
    L_V5 = 5,
    L_V6 = 6,
    L_V7 = 7,
    L_V8 = 8,
    L_V9 = 9,
    L_VMAX
} enum_LOG_LEVEL;

#define gAT_PORT 0
#define gTST_PORT 4


/******************************************************************************
 *  Function    -  LOGH
 *  Purpose     -  打印出一段内存空间十六进制的值
 *  Description -  
 * modification history
 * ----------------------------------------
 * v1.0  , 13-07-2010,    written
 * ----------------------------------------
 ******************************************************************************/
extern void LOGHH(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *text, void * buff, int size);

/******************************************************************************
 * FUNCTION:  LOGS *
 * DESCRIPTION: -  *直接输出
 * Input:  *
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 08-08-2012,   wangqi written
 * --------------------
 ******************************************************************************/
extern void LOGS(const char *fmt, ...);

extern void LOGT(const char *fmt, ...);

/******************************************************************************
 * FUNCTION:  - LOGB * 
 * DESCRIPTION: -  将字符按二进制输出 * 
 * Input: 
 * Output: 
 * Returns: 
 * 
 * modification history
 * --------------------
 * v1.0  , 15-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
extern void LOGB(enum_LOG_MODULE module,enum_LOG_LEVEL grade,const void * buff, int size);

extern void LOGDD(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *fmt, ...);

/* 无自动添加函数名 */
#define LOGC(module, grade, fmt, args...) LOGDD(module, grade, "", fmt, ##args)

/* 有自动添加函数名 */
#define LOGD(module, grade, fmt, args...) LOGDD(module, grade, __func__, fmt, ##args)

#if defined (__REMOVE_LOG_TO_FILE__)
#define LOGD2(module, grade, fmt, args...) LOGDD(module, grade, __func__, fmt, ##args)
#else
#define LOGD2(module, grade, fmt, args...) LOGDD2(module, grade, __func__, fmt, ##args)
#endif

#define LOGH(module, grade, buff, size) LOGHH(module, grade, __func__, NULL, buff, size) 

#define LOGH2(module, grade, text, buff, size) LOGHH(module, grade, __func__, text, buff, size) 

#endif  /* _TRACK_LOG_H */
//--#--define nvram_trace(...)    kal_brief_trace(__VA_ARGS__)
