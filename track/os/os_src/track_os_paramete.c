/******************************************************************************
 * track_os_paramete.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        通用头文件
 *
 * modification history
 * --------------------
 * v1.0   2012-07-14,  jwj create this file
 *
 ******************************************************************************/



/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "track_version.h"
#include "track_os_paramete.h"
#include "track_os_log.h"
#include "track_cust.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
//#define ON_OFF(value) (value==0 ? s_OFF : (value==1 ? s_ON : s_Error))

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

#pragma arm section rodata = "TRACK_NVRAM_RODATA"

const nvram_importance_parameter_struct  NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT =
{
    {__DATE__},
    {__TIME__},
#if defined(__SAME_GT02__) && defined(__SYS_VERSION__)
    {"TQ"},
#else
    {0},
#endif /* __SAME_GT02__ */
    {_TRACK_VER_PARAMETER_},
    {KAL_FALSE, "CMNET", "", ""},
    {
#if defined(__NULL_SERVER__)
        /*默认为空*/
        {0},
        1, {0, 0, 0, 0}, 0, 0, 0, 0, 0
#elif defined(__SAME_GT02__) && defined(__SERVER_TUQIANG__)
        /*gpsdev.tracksolid.com*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED},
        1, {202, 70, 2, 53}, 21101, 0, 0, 0, 0
#elif defined(__NT33__)
#if defined (__LANG_ENGLISH__)
        /*gpsdev.tracksolid.com*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xF4, 0xF2, 0xE1, 0xE3, 0xEB, 0xF3, 0xEF, 0xEC, 0xE9, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {49, 213, 12, 232}, 21100, 0, 0, 0
#else
        /*gpsdev.jimicloud.com*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0
#endif /* __LANG_ENGLISH__ */

#elif defined(__NT31__)&& defined(__LANG_ENGLISH__)
        /*gpsdev.tracksolid.com*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xF4, 0xF2, 0xE1, 0xE3, 0xEB, 0xF3, 0xEF, 0xEC, 0xE9, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {49, 213, 12, 232}, 21100, 0, 0, 0

#elif defined (__SERVER_COOACCESS__)&&defined (__SAME_GT02__)
        /*www.cooaccess.net*/
        {0xF7, 0xF7, 0xF7, 0xAE, 0xE3, 0xEF, 0xEF, 0xE1, 0xE3, 0xE3, 0xE5, 0xF3, 0xF3, 0xAE, 0xEE, 0xE5, 0xF4},
        1, {183, 60, 142, 137}, 8821, 0, 0, 0, 0
#elif defined(__ET310__) && defined(__LANG_ENGLISH__)
        /*gpsdev.tracksolid.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xF4, 0xF2, 0xE1, 0xE3, 0xEB, 0xF3, 0xEF, 0xEC, 0xE9, 0xE4, 0xAE, 0xE3, 0xEF, 0xED},
        1, {49, 213, 12, 232}, 21100, 0, 0, 0, 0
#elif defined(__ET310__)
        /*et310.tuqianggps.com:9555*/
        {0xE5, 0xF4, 0xB3, 0xB1, 0xB0, 0xAE, 0xF4, 0xF5, 0xF1, 0xE9, 0xE1, 0xEE, 0xE7, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
        1, {120, 76, 103, 131}, 9555, 0, 0, 0, 0
#elif defined(__EL100__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21104, 0, 0, 0
#elif defined(__NT13V__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0        
#elif defined(__NT17__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0
#elif defined(__NT55__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0
#elif defined(__QB200__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0
#elif defined(__NF2319__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0    
#elif defined (__NF2318__)
#if defined(__EL100_XYT__)
        /*msg.51xytu.com:7071*/
        {0xED, 0xF3, 0xE7, 0xAE, 0xB5, 0xB1, 0xF8, 0xF9, 0xF4, 0xF5, 0xAE, 0xE3, 0xEF, 0xED},
        1, {121, 42, 247, 56}, 7071, 0, 0, 0    
#else
        /*radar.songguo7.com:1024*/
        {0xF2, 0xE1, 0xE4, 0xE1, 0xF2, 0xAE, 0xF3, 0xEF, 0xEE, 0xE7, 0xE7, 0xF5, 0xEF, 0xB7, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {123, 59, 54, 138}, 1024, 0, 0, 0    
#endif
#elif defined(__JM10__)
        /*gpsdev.jimicloud.com:21100*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {112, 74, 143, 157}, 21100, 0, 0, 0  
#else
#error "please define project_null"
#endif
    }, {
#if defined(__LANG_ENGLISH__)&& !defined(__NT36__)&& !defined(__MT200__)&&!defined(__GT740__)
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {116, 204, 8, 57}, 12283, 0, 0, 0
#else
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {116, 204, 8, 57}, 12283, 0, 0, 0
#endif /* __LANG_ENGLISH__ */
    },
    {
        {

            {0XF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xE7 , 0xF0 , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xED , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE1, 0xE7, 0xF0, 0xF3, 0xAE, 0xF4, 0xEF, 0xF0, 0xF3, 0xF4, 0xE1, 0xF2, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
            0, {120, 77, 2, 16}, 12283, 0, 0, 0
        }
    }
#if defined(__SAME_GT02__) && (defined(__GUMI__) || defined(__GUMI_GENERAL__))
    , {
        //gt02.goomegps.net
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        1,
        0,
        0,
    }
#else
    , {
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        0,
        0,
        0
    }
#endif
#if defined(__BACKUP_SERVER__)
    , {0}
#endif/*__BACKUP_SERVER__*/
#ifdef __SAME_GT02__///谷米为默认版本
#if defined( __GUMI__)
    , {1, 1, 0, 1} //version
#elif defined( __GUMI_GENERAL__)
    , {2, 1, 0, 0} //谷米通用版本，不支持SENSOR，不支持国外版功能
#elif defined(__SERVER_TRACKSOLID__) || defined( __SERVER_COOACCESS__)
    , {3, 1, 1, 0} //外贸版本，SENSOR，支持国外版功能
#elif defined( __SERVER_TUQIANG__)
    , {4, 1, 0, 0} //图强版本，支持SENSOR，不支持国外版功能
#endif
#else
    , {0, 0, 0, 0} //version
#endif /* __SAME_GT02__ */

#if defined (__LUYING__)
    , { /*tcpupload.jimicloud.com:20010*/
        {0xF4, 0xE3, 0xF0, 0xF5, 0xF0, 0xEC, 0xEF, 0xE1, 0xE4, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED, 0x80},
        1, {202, 70, 2, 53}, 20010, 0, 0, 0, 0
    }
#endif /* __LUYING__ */
#if defined(__NF2318__)
	,99
	,{"700000001F"}
	,{"G3A650000000371XH"}			////设备ID号
#if defined(__EL100_XYT__)
    ,0x0B                           // 厂商代码
    ,{0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30}  // 识别码
#endif
#endif
};

const nvram_parameter_struct NVRAM_EF_PARAMETER_DEFAULT =
{
    {0},
    {NULL},
#ifdef __LANG_ENGLISH__
    {"http://maps.google.com/maps?q="},                 // URL设置
#else
    {"http://ditu.google.cn/maps?q="},                 // URL设置
#endif /* __LANG_ENGLISH__ */

    10,                                                 // 监听延时，范围：5-18S。默认设置 10S

#if defined(__LANG_ENGLISH__)
    0,                                                  // 1 表示为中文，0 表示为英文，用于地址查询
#else
    1,                                                  // 1 表示为中文，0 表示为英文，用于地址查询
#endif /* __LANG_ENGLISH__ */
    1,                                                  // 1 开启GPRS   0 关闭GPRS
#if defined(__GT300S__)||defined(__SAME_GT02__) || defined(__GT740__)|| defined(__GT370__)|| defined (__GT380__)||defined (__NT33__)
    180,                                                  // 心跳包设置间隔(设置指令为分钟，实际存储为秒)  ACC ON 上传间隔
    180,                                                  // 心跳包设置间隔(设置指令为分钟，实际存储为秒)  ACC OFF 上传间隔
#elif defined(__NF2318__)
	120,												  // 心跳包设置间隔
	120,
#else
    180,                                                  // 心跳包设置间隔
    300,
#endif

    0,                                                  // 来电响铃方式

    3,                                                  // 电话重拨次数

    10,                                                 // 监听延时；0、5～18秒；设置远程监听延时；默认值为：10秒

#if defined(__SPANISH__)
    1,                                                  // 来电呼叫自动返回地址（1 有效， 0 禁用）
#else
    0,                                                  // 来电呼叫自动返回地址（1 有效， 0 禁用）
#endif

#if defined(__SAME_GT02__)
#if defined(__NO_SENSOR__)
    0,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
#else
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
#endif /* __NO_SENSOR__ */
    2,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    600,                                                // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 1, 1}, {1, 20, 2}, {0, 300}, {1, 10, 10, 2, 30}}, // GPS工作模式
    {0, 1, 10, 5, 1, 1800, 180, 2},                     // 震动报警
    {0, 1, 10, 300, 0, 0},                                // 断电报警设置
    {0, 100, 1, 20},                                    // 超速报警设置
    {"666666", "999999", 1, 0, 0, 1, 0},                // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
    {1, 1, 1, 0},                                          // AGPS

#elif defined (__ET310__)
    3,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    60,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 3, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 5, 1, 60, 30, 2},                        // 震动报警
    {1, 1, 10, 1, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#elif defined (__EL100__)
    1,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    600,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 3, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 5, 1, 60, 30, 2},                        // 震动报警
    {1, 0, 5, 300, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#elif defined (__NT13V__)
#if defined (__LANG_ENGLISH__)
    3,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    60,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 2, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 2, 1, 60, 30, 2},                        // 震动报警
    {1, 2, 10, 1, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 3},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#else
    3,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    60,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 2, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 2, 1, 60, 30, 2},                        // 震动报警
    {1, 1, 10, 1, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 3},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */
#elif defined (__NT17__)
#if defined (__LANG_ENGLISH__)
    3,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    60,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 2, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 2, 1, 60, 30, 2},                        // 震动报警
    {1, 2, 10, 1, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 3},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#else
    3,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    60,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 2, 1}, {1, 30, 3}, {0, 300}, {1, 20, 20, 2, 30}}, // GPS工作模式
    {1, 0, 10, 2, 1, 60, 30, 2},                        // 震动报警
    {1, 1, 10, 1, 0},                                   // 断电报警设置
    {0, 50, 0, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 3},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 60, 20, 0},                                     // GPS盲区设置
    {1, 20, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 0, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */

#elif defined (__NT36__)
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    600,                                                 // 延时进入设防时间（秒）
    1,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 1, 1}, {1, 30, 3}, {0, 300}, {1, 10, 10, 2, 30}}, // GPS工作模式
    {0, 2, 10, 5, 1, 1800, 180, 2},                        // 震动报警
    {1, 2, 5, 300, 0},                                   // 断电报警设置
    {0, 100, 1, 20},                                     // 超速报警设置
    {"000000", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 10, 10, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
    {1, 1, 1, 0},                                       // AGPS
#elif defined (__NT55__)
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    180,                                                 // 延时进入设防时间（秒）
    0,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 0, 5, {10, 3, 1}, {1, 20, 2}, {0, 300}, {1, 10, 180, 180, 30}}, // GPS工作模式
    {0, 0, 10, 5, 1, 1800, 180, 2},                        // 震动报警
    {1, 1, 20, 300, 0},                                   // 断电报警设置
    {0, 100, 1, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 10, 10, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
#if defined(__LANG_ENGLISH__)
    {0, 1, 1, 0},                                       // AGPS
#else
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */

#elif defined (__QB200__)
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    180,                                                 // 延时进入设防时间（秒）
    0,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 1, 1}, {1, 20, 2}, {0, 300}, {1, 10, 10, 180, 30}}, // GPS工作模式
    {0, 0, 10, 5, 1, 1800, 1, 2},                        // 震动报警
    {1, 1, 20, 300, 0},                                   // 断电报警设置
    {0, 100, 1, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 10, 10, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
#if defined(__LANG_ENGLISH__)
    {0, 1, 1, 0},                                       // AGPS
#else
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */

#elif defined (__NF2319__)
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    180,                                                 // 延时进入设防时间（秒）
    0,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 1, 1}, {1, 20, 2}, {0, 300}, {1, 10, 10, 180, 30}}, // GPS工作模式
    {0, 0, 10, 5, 1, 1800, 1, 2},                        // 震动报警
    {1, 1, 20, 300, 0},                                   // 断电报警设置
    {0, 100, 1, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 10, 10, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
#if defined(__LANG_ENGLISH__)
    {0, 1, 1, 0},                                       // AGPS
#else
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */
#elif defined (__NF2318__)
	3,													// 0～300分钟，检测到一次震动，开启 GPS 工作的时间
	1,													// 跟随GPS关闭 LED休眠，1为启用，0为禁止
	180,												 // 延时进入设防时间（秒）
	0,													// 断油电功能（1 有效， 0 禁用）
	{1, 10, 60, 1, 5, {10, 3, 1}, {1, 20, 2}, {0, 300}, {1, 15, 15, 180, 30}}, // GPS工作模式
	{1, 0, 10, 3, 1, 120, 1, 2},						 // 震动报警
	{1, 1, 3, 3, 0}, 								  // 断电报警设置
	{0, 100, 1, 5},									 // 超速报警设置
	{"666666", "SUPER", 0, 0, 0, 1, 2}, 				// 权限设置
	{1, 2}, 											// SOS报警设置
	{0, 10, 10, 1}, 									// GPS盲区设置
	{1, 10, 6, 3},										// 静止上报最后位置开关指令
	{0, 1, 300},										// 位移报警
#if defined(__LANG_ENGLISH__)
	{0, 1, 1, 0},										// AGPS
#else
	{1, 1, 1, 0},										// AGPS
#endif /* __LANG_ENGLISH__ */
#elif defined (__JM10__)
    5,                                                  // 0～300分钟，检测到一次震动，开启 GPS 工作的时间
    1,                                                  // 跟随GPS关闭 LED休眠，1为启用，0为禁止
    180,                                                 // 延时进入设防时间（秒）
    0,                                                  // 断油电功能（1 有效， 0 禁用）
    {1, 100, 60, 1, 5, {10, 1, 1}, {1, 20, 2}, {0, 300}, {1, 10, 10, 180, 30}}, // GPS工作模式
    {0, 0, 10, 5, 1, 1800, 1, 2},                        // 震动报警
    {1, 1, 20, 300, 0},                                   // 断电报警设置
    {0, 100, 1, 20},                                     // 超速报警设置
    {"666666", "SUPER", 0, 0, 0, 1, 2},                 // 权限设置
    {1, 2},                                             // SOS报警设置
    {0, 10, 10, 1},                                     // GPS盲区设置
    {1, 10, 6, 3},                                      // 静止上报最后位置开关指令
    {0, 1, 300},                                        // 位移报警
#if defined(__LANG_ENGLISH__)
    {0, 1, 1, 0},                                       // AGPS
#else
    {1, 1, 1, 0},                                       // AGPS
#endif /* __LANG_ENGLISH__ */

#else
#error "please define project_null"
#endif

#if defined(__GT370__)|| defined (__GT380__)
    {1, 0},                                             // 开机报警开关
#else
    {0, 1},                                             // 开机报警开关
#endif

#ifdef __GT300S__
    {0, 30, 30},                                        // 组包个数
#elif defined(__GT370__)|| defined (__GT380__)
    {0, 30, 30},										// 组包个数
#else
    {0, 10, 10},                                        // 组包个数
#endif /* __GT300S__ */
    {0, 0, 1000},                                      // 里程统计
    {0, 1, 60},                                         // 停车超时报警

    {'E', 8, 0, 1},                                     // 时区设置

// 低电报警设置  batalm
#if defined(__SAME_GT02__)
    {0, 1},                                             // 低电报警设置
#elif defined (__NT13V__) || defined (__NT17__)
    #if defined(__LANG_ENGLISH__)
        {1, 1},
    #else
        {1, 0},
    #endif
#elif defined(__ET310__)||defined(__MT200__)||defined(__SPANISH__)||defined(__EL100__)
    {1, 0},
#else
    {1, 1},                                             // 低电报警设置
#endif /* __SAME_GT02__ */

    {1, 0, 240, 20},                                    // 疲劳驾驶提醒
    {
        {0, 2, 1, 0, 3, 0, 0, 0, 0}                     // 电子围栏设置
    },
    {0, 0, 3000, 40, 10},                               // 锁电机参数

#if defined(__GT300S__)
    {1, 2, 60 * 24, 0 , 30, 2, 20},                                      // 终端工作模式
#elif defined(__GT370__)|| defined (__GT380__)
    {1, 1, 60 * 24, 0 , 30, 2, 20},						 // 终端工作模式
#else
    {0, 2, 60 * 24, 0 , 30, 2, 20},                                      // 终端工作模式
#endif

#if (defined(__ET310__)) && defined(__LANG_ENGLISH__)
    {0, 1, 128, 138, 10},                               // 外部电源低电报警
    {1, 0, 125, 130, 10},                               // 外部低电切断保护
#elif defined(__ET310__)
    {0, 0, 128, 138, 10},                               // 外部电源低电报警
    {1, 0, 125, 130, 10},                               // 外部低电切断保护
#elif defined(__NT31__)
    {0, 0, 115, 125, 10},                               // 外部电源低电报警
    {0, 0, 125, 130, 10},                               // 外部低电切断保护
#elif defined(__NT13V__) || defined (__NT17__)
    {0, 0, 128, 138, 10},                               // 外部电源低电报警
    {1, 0, 115, 120, 10},                               // 外部低电切断保护
#else
    {0, 1, 128, 138, 10},                               // 外部电源低电报警
    {0, 1, 125, 130, 10},                               // 外部低电切断保护
#endif
#if defined (__NT33__)
    {0, 6},
#else
    {0, 3},                                             // GPRS 阻塞报警
#endif
    {0, 1, 0},                                          // 门报警
#if defined(__NT55__)
	{0, 1, 7, 0, 0, {0}, 60, 0, 0, 0},					// OBD
#else
    {0, 1, 7, 0, 0, {0}, 60, 0, 0, 0},                  // OBD
#endif
    {126, 128}                                          // ACC外部检测电压

#if defined(__ACC_ALARM__)
    , 1
#else
    , 0                                             // 0 表示为ACC切换无短信通知，1 表示为ACC切换有短信通知
#endif
#if (defined(__ET310__) || defined(__MT200__))

#if  ((defined (__ET310__)) && defined(__LANG_ENGLISH__))
    , 0
#else
    , 80
#endif /* __ET310__ */

#else
    , 0                                             // 电动车限速阀值  车载定位器必须为0
#endif

#if defined (__GT370__)|| defined (__GT380__)
    , {1, 0}                                        // 开机报警开关
    , {0, 0, "0000000000000000"}                    // 换卡报警
#else
    , {0, 0}                                        // 开机报警开关
    , {0, 0, "0000000000000000"}                    // 换卡报警
#endif /* __GW100__ */

    , 0                                             // 限制关机功能,只用于有开关机键的项目

    , 20

    , 0                                             // ADC4补偿值
    , 0                                             // mode3_work_interval;//休眠模式下定时上报间隔
    , 1                                             // mode3_up_counts;//休眠模式下单次工作上报次数
    , {2, 10, 5, 0, 1440, 0, 1, 0, {0}, 0, 2}                   // extchip
    , {"OBDMIFI", "123456"}                         // ap 用户名+密码
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    , {1, 0, "0000000000000000"}                    // smstc 透传
#else
    , {0, 0, "0000000000000000"}                    // smstc 透传
#endif /* __GT300S__ */
//本需要区分有没有OBD模块，因为试产没有OBD，所以暂时区分
    , 0                     // 自动设防模式 X=0  自动设防模式；X=1 手动设防模式

    , {0, 600}                                       //(几米国际)外接电源电压信息上传开关  ADT指令

#if defined (__GT370__)|| defined (__GT380__)
    , {1, 0}                                        //teardown_str //防拆报警
#else
    , {1, 1}                                        //teardown_str //防拆报警
#endif /* __GT370__ */

#ifdef __WIFI__
#if defined(__NT13V__)||defined(__GT740__)||defined(__GT370__)|| defined (__GT380__)         //WIFI设置
    , {1, 10, 0}
#else
    , {0, 10, 10 * 60}
#endif
#else
    , {0, 10, 10 * 60}
#endif /* __WIFI__ */

#if defined(__NT31__) || defined(__ET310__) || defined(__NT36__)|| defined(__NT33__)
    , {1, 60, 60}           //lbson
#else
    , {0, 60, 60}
#endif /* __NT31__ */

#if defined (__NT33__)
    , {0, 0, 30}           //伪基站报警
#else
    , {0, 0, 30}           //伪基站报警
#endif

#if (defined(__ET310__) && defined(__LANG_ENGLISH__))
    , 0                     //飞行模式开关默认开
#else
    , 1                     //飞行模式开关默认开
#endif /* __LANG_ENGLISH__ */
    , {0}                  //在线下载配置参数文件的MD5
#if defined(__SECOND_SET__)
    , 1    // EPO下载开关
#else
    , 0
#endif
    , 2                                             // 5V电源输出状态
#if defined(__ACC_ALARM__)
    , {0, 1, 10, 0}            //ACC报警包检测时间
#endif
#if defined(__GT740__)
    , {0}                 //
    , 0                  //启用新定位包上传开关 默认关
    , 1                 //电量次数计算开关，默认开
    , {0, 20}          //静态补传
#endif

#if defined (__NETWORK_LICENSE__)
, 0
#elif defined (__NT33__)||defined (__NT31__) || defined(__GT740__)
    , 1                 //fake_cell_enable
#else
    , 0                 //fake_cell_enable 防伪基站全部关闭，生产按需打开
#endif
    , 1                 //伪基站信息是否上报AMS
#if defined (__GT370__)|| defined (__GT380__)
    , 1                 //gpsDup gps位置数据上报开关
#else
    , 0                 //gpsDup gps位置数据上报开关
#endif /* __GT370__ */
#if defined (__CUST_BT__) && defined(__NT33__)
    , {0, 2, 2, 0}      //bt
#endif /* __CUST_BT__ */
    , 1  //唤醒GPS 默认0

#if defined (__GT370__)|| defined (__GT380__)
    , {1, 1}    //开盖报警
#endif /* __GT370__ */
    , 0xFF         //临时自动关防伪功能
#if defined(__SPANISH__)
    , 0
#endif
    , {1, 1, 1}
    , {0, 10, 5}
    , 0
#if defined(__DROP_ALM__)//跌倒报警
    , {1, 1}
#endif
    , 0  //通话模式
    , 0
#if defined(__EL100__)
    , {"xinsiwei&concox"}   //密匙
    , 15                                //一键预约时间
    , {0, 3, 15, 5}                 //声音寻车指令
    , {1, 0, 10}
#endif
#if defined(__SMT_BMS__)
       ,{1,300,1200}// 锂电池组信息上报
       ,{1,0,5}//
#endif
#if defined(__NT55__)
    ,{1,3}	//acc 检测方式：1 adc检测外电，2 obd检测,3 sensor检测 ，默认3
#endif

#if defined (__NT13V__)
    ,{0}        //device_sleep_times
#endif /* __NT13V__ */
#if defined (__NF2319__)
    ,{0,75}
#endif /* __NF2319__ */
#if defined(__NF2318__)
	,{3,6,0,0,0,0}//控制器命令存储
	,{0,
	//{"700000001F"},
	99,
	{
	0xc6,0x69,0xa3,0xc2,0x79,0x06,0x18,0xae,0x82,0xdf,0xef,0x07,0x6e,0xa6,0x9f,0x9d,0xa2,0x10,
	0xe5,0x0d,0xe6,0xf0,0x11,0x3d,0xbf,0x7d,0x95,0x3b,0xb1,0x2a,0xab,0x4b,0xa7,0xc4,0xab,0xac,
	0xdd,0x1a,0x23,0xa2,0x01,0x13,0x7f,0x52,0x68,0x54,0xb4,0x28,0xee,0x52,0x41,0x66,0xe1,0x0c,
	0xd3,0xfb,0x2c,0xc9,0x79,0xf1,0x7c,0x6d,0x27,0x1d,0x2a,0x17,0xdc,0x8d,0xe4,0x77,0xd0,0xe3,
	0x1c,0xb3,0x37,0xcb,0x31,0x7b,0x5b,0xea,0xf9,0x1e,0x06,0xb8,0x4e,0x25,0x0f,0xda,0xdd,0xb1,
	0xd8,0xd7,0xac,0xfa,0x1e,0x7c,0xdd,0x51,0x80,0x30,0xa4,0x04,0x15,0x9b,0x10,0x3e,0xba,0x4a,
	0xa6,0x08,0xc7,0x49,0x37,0xcf,0xf1,0x60,0x53,0x72,0x13,0xc7,0xb5,0x36,0xfa,0x7d,0x27,0xdb,
	0x0f,0x55
	},
	{0},
	10,
	30,
	10,
	7,
	60,
	1,
	16,
	25,//磁钢对数
	1,//锁定域名设置范围
	6,//报警间隔
	3,//外电检测过滤时间设置
	300,//震动灵敏度设置， mg
	3,//语音播报出发设置
	10,//轮动检测时间 s
	3,//轮动判断脉冲个数 3
	1800,//半休眠间隔gps工作时间
	"sg-ebike",//蓝牙名称
#if defined(__EL100_XYT__)
    0,//鉴权码长度
    {0,},//鉴权码
#endif
	}
	//,{0,0,0,1,0,2,0,1,0,1}//终端状态
	,{0,0,1,0,0,0,0,1}//终端状态
#endif
	,{1,1}//电池温度采集
	,{1,15,3,0,0,{0x00,0x00,0x0E},{0x00,0x00,0x0F}}//超速报警
	,{0x30,0x00,0x03,0xE8}//语音文件版本
	,18,18,23,25
	,0 //不让bms初始化的开关，0-开  1-关
	,0//语音报警开关 0关 1开
	,0//语音文件总大小
	,{0x65, 0x83, 0x04, 0x14, 0x4f, 0x5a, 0xd2, 0x76, 0xb4, 0xae, 0x15, 0x7b, 0x25, 0x31, 0xf2, 0x2e}//蓝牙密钥//20190717
	,0
	,{"101131004020079090210118180174021123037049242046"}//蓝牙密码
	,{0}//保存新密码
};


const nvram_phone_number_struct NVRAM_EF_PHONE_NUMBER_DEFAULT =
{
    {0},
    {0},

    {1, 1, 1}
	//,{0}	//存储需要下载的语音列表
	//,0 //需要下载的原因总条数
};

const nvram_ef_logd_struct NVRAM_EF_LOGD_DEFAULT =
{
    /*save paramter for log wangqi*/
    {0}, //kal_uint8          logd_mdoule[L_MAX];
    //{L_CON,L_DRV,L_SOC,L_CMD,L_OS,L_APP,L_SYS,}//请注意参数个数与L_MAX对应
    0,        //kal_uint16          log_sw;
    LOG_AUTO,    //log_target          logd_target;
    ""
};

const nvram_realtime_struct NVRAM_EF_REALTIME_DEFAULT =
{
    {0},                    // 电子围栏 当前是出于围栏内(1)还是围栏外(2)
    0,                      // 低电报警发送标记
    0,                      // 外部电源低电报警发送标记
    0,                      // 外部电源断开发送标记
    0,                      // 位移报警 标记
    0,                      // 位移报警
    0,                      // 位移报警
    0,                      // 在线网络上报日志控制
    0,                      // 20分钟重启连续计数
    0,                      // 设防状态  1 撤防，2 预设防，3 设防

    0,                      //ledsw  按键状态 0 关    1 开

    0,                      // 油电状态
    0,                      // 断油电指令来源
    2,                      // 用于记录ACC状态，防止开机后的状态与上次关机前一致
    0,                      // 低电关机报警发送标记
    0,                      // 省电模式(0:正常模式;1:省电模式)
    1,                      // 是否发送阻塞报警短信(0不发送，1发送)
    0,                      // L4C_RAC_LIMITED_SERVICE 重启计数
    2,                      // 盲区报警状态0，为进，1为出，2为初始值。

    0,                      // 自动设防模式 X=0  自动设防模式；X=1 手动设防模式，默认X=1

    1,                       // 定位数据上传开关  0 关闭  1 打开
#if !defined(__NF2318__)
    {0},
#endif
    1,                       // 外部电压6v之下报警后设置为1, 6v之上为0
    0,                       //换卡报警标志位
    500,
#if defined (__LUYING__)
	0,      //音频数量
    60,     //时长
    {{0}, {0}, {0}, {0}, {0}}, //音频文件
#endif
    0,                       // 休眠模式开启工作倒计时
    {0},
    0,
    0,
#if defined(__MECH_SENSOR__)
    1,
    700,
#else
    1,
    1000,
#endif
#if defined(__GT740__)
    0,
    20,//追踪模式时间
    0,
#endif
    0,
    1,//自动上传参数
    1, //ams 保存LOG开关
    0,    //710上传LOG开关
    0,     //定位包协议次数
    0    // 联网重启标记
#if defined (__BAT_TEMP_TO_AMS__)
    , {0}
    , 0
#endif /* __BAT_TEMP_TO_AMS__ */
    , 0//是否不停上传断电报警标志位
#if defined(__CUST_FAKECELL__)
    ,{0}//伪基站信息记录
#endif
    , 0 //主基站ID
    , 0 // 重启标志
    , 0
    , 0
    , 0
    , 0                                //锁状态

#if defined (__LUYING__)
    , 0     //record_file
    , 0
    , 0     //recard_time
    , {0}   //录音上传的流水号
    , 0
#endif /* __LUYING__ */
#if defined(__NF2318__)
	,0
	,0
	,0
	,0//电池锁异常告警
	,{0}//http下载参数临时存储
	,0//已经对比完版本信息 有固件更新 00000001 有语音更新 00000010  
	,0//固件升级标识
	//,0//电机状态 0  不锁 1 锁
	,0//后轮锁状态0 不锁 1锁
	,2//电池锁状态 0 不锁 1 锁
	,0,0,0,0
	,0 //当前休眠状态 0 无休眠 15半休眠  16 全休眠
	,0//http连接计数
	,{0}//http日期
	,{0}	//存储需要下载的语音列表
	,0 //需要下载的原因总条数
	,{0}//临时存储语音版本号
	,0//临时存放本次下载语音的总大小
	,{0}//bms 状态报警#endif	
	,0//ACC异常报警
	,{0}//控制器报警
	//--------------20191010
	,0
	,0
#endif
};

#pragma arm section rodata

nvram_drv_importance_backup_struct   importance_backup = {0};

nvram_parameter_struct* OTA_NVRAM_EF_PARAMETER_DEFAULT = (nvram_parameter_struct*)&NVRAM_EF_PARAMETER_DEFAULT;
nvram_importance_parameter_struct* OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT  = (nvram_importance_parameter_struct*)&NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT;
nvram_phone_number_struct* OTA_NVRAM_EF_PHONE_NUMBER_DEFAULT = (nvram_phone_number_struct*)&NVRAM_EF_PHONE_NUMBER_DEFAULT ;
nvram_ef_logd_struct* OTA_NVRAM_EF_LOGD_DEFAULT = (nvram_ef_logd_struct*)&NVRAM_EF_LOGD_DEFAULT;
nvram_realtime_struct* OTA_NVRAM_EF_REALTIME_DEFAULT = (nvram_realtime_struct*)&NVRAM_EF_REALTIME_DEFAULT;

extern void track_cust_paket_9404_handle(void);

void track_os_importance_backup_write(void)
{
    static char *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
    kal_uint32 len = 2000, l = 0;
	
    kal_uint32 value1 = 0 ,value2 = 0;
    //LOGD(L_APP, L_V5, "");
#ifdef __SAME_GT02__
    kal_uint8 chip_rid[16];
    kal_uint16 CRC, CRC_IN = 0;
    memcpy(chip_rid, track_drv_get_chip_id(), 16);
    CRC = GetCrc16(chip_rid, 16);
#endif /* __SAME_GT02__ */

    memset(&importance_backup, 0x00, sizeof(importance_backup));
	//新增加域名端口号判断，如果突变，不去写了
	if(G_importance_parameter_data.server.conecttype == 255 || G_importance_parameter_data.server.server_port == 65535 ||  G_importance_parameter_data.server.soc_type == 255)
	{
    	LOGD(L_APP, L_V5, "error,%d,%d,%d", G_importance_parameter_data.server.conecttype,G_importance_parameter_data.server.server_port,G_importance_parameter_data.server.soc_type);
		return;
	}
	if(G_parameter.ste_param.rcv == 0 || G_parameter.ste_param.rcv == 255 || G_parameter.ste_param.rcv != 99)
	{
	    LOGD(L_APP, L_V5, "error1,%d", G_parameter.ste_param.rcv);
		return;
	}
	if(G_importance_parameter_data.rcv == 0 || G_importance_parameter_data.rcv == 255 || G_importance_parameter_data.rcv != 99)
	{
	    LOGD(L_APP, L_V5, "error2,%d", G_importance_parameter_data.rcv);
		return;
	}
    l += OTA_snprintf(importance_backup.data + l, len - l, "ASETAPN,%s\r\n", (G_importance_parameter_data.apn.custom_apn_valid ? s_OFF : s_ON));
    if(G_importance_parameter_data.apn.custom_apn_valid)
    {
        extern nvram_GPRS_APN_struct *track_socket_get_use_apn(void);
        nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
        l += OTA_snprintf(importance_backup.data + l, len - l, "APN,%s,%s,%s\r\n", use_apn->apn, use_apn->username, use_apn->password);
    }
#ifdef __SAME_GT02__
    l += OTA_snprintf(importance_backup.data + l, len - l, "SYS_VERSION,%d,%d\r\n", G_importance_parameter_data.app_version.version, CRC);
#endif /* __SAME_GT02__ */

#if defined(__BACKUP_SERVER__)
    {
        if(G_importance_parameter_data.bserver.conecttype == 0)
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "BSERVER,0,%d.%d.%d.%d,%d,%d\r\n",
                              G_importance_parameter_data.bserver.server_ip[0], G_importance_parameter_data.bserver.server_ip[1],
                              G_importance_parameter_data.bserver.server_ip[2], G_importance_parameter_data.bserver.server_ip[3],
                              G_importance_parameter_data.bserver.server_port, G_importance_parameter_data.bserver.soc_type);
        }
        else
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "BSERVER,%d,%s,%d,%d\r\n",
                              G_importance_parameter_data.bserver.conecttype,
                              track_domain_decode(G_importance_parameter_data.bserver.url),
                              G_importance_parameter_data.bserver.server_port,
                              G_importance_parameter_data.bserver.soc_type);
        }
    }
#endif
/*
    if(0)//(G_importance_parameter_data.dserver.server_type)
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "DSERVER,0,%d.%d.%d.%d,%d,%d\r\n",
                              G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1],
                              G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3],
                              G_importance_parameter_data.dserver.server_port, G_importance_parameter_data.dserver.soc_type);
        }
        else
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "DSERVER,%d,%s,%d,%d\r\n",
                              G_importance_parameter_data.dserver.conecttype,
                              track_domain_decode(G_importance_parameter_data.dserver.url),
                              G_importance_parameter_data.dserver.server_port,
                              G_importance_parameter_data.dserver.soc_type);
        }
    }
    else
    {
    */
        if(G_importance_parameter_data.server.conecttype == 0)
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER,0,%d.%d.%d.%d,%d,%d\r\n",
                              G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                              G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                              G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type);
        }
        else
        {
            l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER,%d,%s,%d,%d\r\n",
                              G_importance_parameter_data.server.conecttype,
                              track_domain_decode(G_importance_parameter_data.server.url),
                              G_importance_parameter_data.server.server_port,
                              G_importance_parameter_data.server.soc_type);
        }
    //}
    if(G_importance_parameter_data.server2.conecttype == 0)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER2,0,%d.%d.%d.%d,%d,%d\r\n",
                          G_importance_parameter_data.server2.server_ip[0], G_importance_parameter_data.server2.server_ip[1],
                          G_importance_parameter_data.server2.server_ip[2], G_importance_parameter_data.server2.server_ip[3],
                          G_importance_parameter_data.server2.server_port, G_importance_parameter_data.server2.soc_type);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER2,%d,%s,%d,%d\r\n",
                          G_importance_parameter_data.server2.conecttype,
                          track_domain_decode(G_importance_parameter_data.server2.url),
                          G_importance_parameter_data.server2.server_port,
                          G_importance_parameter_data.server2.soc_type);
    }
    /*
    l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER,0,%d.%d.%d.%d,%d,%d\r\n",
            G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
            G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
            G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type);

    l += OTA_snprintf(importance_backup.data + l, len - l, "SERVER2,0,%d.%d.%d.%d,%d,%d\r\n",
            G_importance_parameter_data.server2.server_ip[0], G_importance_parameter_data.server2.server_ip[1],
            G_importance_parameter_data.server2.server_ip[2], G_importance_parameter_data.server2.server_ip[3],
            G_importance_parameter_data.server2.server_port, G_importance_parameter_data.server2.soc_type);
    */

#if defined(__GT740__)
    if(G_parameter.extchip.mode == 3)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "MODE,3,%d,%0.2d:%0.2d\r\n", G_parameter.extchip.mode3_par1, G_parameter.extchip.mode3_par2 / 60, G_parameter.extchip.mode3_par2 % 60);
    }
    else if(G_parameter.extchip.mode == 4)
    {
        char m_buf[100] = {0};
        U8 vle = G_parameter.extchip.mode4_par1, i = 0;
        for(; i < vle; i++)
        {
            if(0 == i)
            {
                snprintf(m_buf + strlen(m_buf), 99, "%0.2d:%0.2d", G_parameter.extchip.mode4_par2[i] / 60, G_parameter.extchip.mode4_par2[i] % 60);
            }
            else
            {
                snprintf(m_buf + strlen(m_buf), 99, ",%0.2d:%0.2d", G_parameter.extchip.mode4_par2[i] / 60, G_parameter.extchip.mode4_par2[i] % 60);
            }
        }
        l += OTA_snprintf(importance_backup.data + l, len - l, "MODE,4,%d,%s\r\n", vle, m_buf);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "MODE,2,%d:%d,%d\r\n", G_parameter.extchip.mode2_par1 / 60, G_parameter.extchip.mode2_par1 % 60, G_parameter.extchip.mode2_par2 / 60);
    }
    l += OTA_snprintf(importance_backup.data + l, len - l, "TRACKTIME,%d\r\n", G_realtime_data.tracking_time);
    l += OTA_snprintf(importance_backup.data + l, len - l, "GPSWAKE,%s\r\n",   ON_OFF(G_parameter.gpswake));
#endif


    //l += OTA_snprintf(importance_backup.data + l, len - l, "EURL,%s\r\n", G_parameter.url);

    l += OTA_snprintf(importance_backup.data + l, len - l, "LANG,%d\r\n", G_parameter.lang);

    /*需要重点测试*/
//   l += OTA_snprintf(importance_backup.data + l, len - l, "IMEI,1,%s\r\n", (char *)track_drv_get_imei(0));

    l += OTA_snprintf(importance_backup.data + l, len - l, "AGPS,%s\r\n", ON_OFF(G_parameter.agps.sw));

    if(G_importance_parameter_data.server.lock)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "LOCKIP\r\n");
    }
#if defined(__NF2318__)
	l += OTA_snprintf(importance_backup.data + l, len - l, "DEVICESN,%s\r\n",G_importance_parameter_data.SequenceNumber);
	l += OTA_snprintf(importance_backup.data + l, len - l, "LEASE,%d\r\n",G_parameter.ste_status.lease);
	l += OTA_snprintf(importance_backup.data + l, len - l, "MELIAGE,%d,%d\r\n",G_parameter.ele_data.oncemileage,G_parameter.ele_data.totalmileage);
	l += OTA_snprintf(importance_backup.data + l, len - l, "ENCODETYPE,%d\r\n",G_parameter.ste_status.encode_type);

#endif

    l += OTA_snprintf(importance_backup.data + l, len - l, "ASETGMT,%s\r\n", ON_OFF(G_parameter.zone.timezone_auto));
    if(G_parameter.zone.timezone_auto == 0 && (G_parameter.zone.zone == 'E' || G_parameter.zone.zone=='W'))
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "GMT,%c,%d,%d\r\n", G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min);
    }

    //l += OTA_snprintf(importance_backup.data + l, len - l, "CENTER,A,%s\r\n", G_parameter.centerNumber);

    //l += OTA_snprintf(importance_backup.data + l, len - l, "SOS,A,%s,%s,%s\r\n", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
    //l += OTA_snprintf(importance_backup.data + l, len - l, "SOSALM,%s,%d\r\n", ON_OFF(G_parameter.sos_alarm.sw), G_parameter.sos_alarm.alarm_type);
    //l += OTA_snprintf(importance_backup.data + l, len - l, "ALMREP,%d,%d,%d\r\n", G_phone_number.almrep[0], G_phone_number.almrep[1], G_phone_number.almrep[2]);

    l += OTA_snprintf(importance_backup.data + l, len - l, "PERMIT,%d\r\n", G_parameter.Permission.Permit);

    /*需要重点测试*/
#if !defined(__NF2318__)
    l += OTA_snprintf(importance_backup.data + l, len - l, "PWDSW\r\n", ON_OFF(G_parameter.Permission.password_sw));
    if(G_parameter.Permission.password_sw)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "PASSWORD,%s\r\n", G_parameter.Permission.password);
    }
    if(G_parameter.speed_limit_alarm.sw)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SPEED,%s,%d,%d,%d\r\n",
                          ON_OFF(G_parameter.speed_limit_alarm.sw), G_parameter.speed_limit_alarm.delay_time,
                          G_parameter.speed_limit_alarm.threshold, G_parameter.speed_limit_alarm.alarm_type);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SPEED,%s\r\n",
                          ON_OFF(G_parameter.speed_limit_alarm.sw));
    }
#endif
    if(G_parameter.power_fails_alarm.sw)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "POWERALM,%s,%d,%d,%d,%d\r\n",
                          ON_OFF(G_parameter.power_fails_alarm.sw),
                          G_parameter.power_fails_alarm.alarm_type,
                          G_parameter.power_fails_alarm.delay_time_off,
                          G_parameter.power_fails_alarm.delay_time_on,
                          G_parameter.power_fails_alarm.delay_time_acc_on_to_off);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "POWERALM,%s\r\n",
                          ON_OFF(G_parameter.power_fails_alarm.sw));
    }
    if(G_parameter.low_power_alarm.sw)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "BATALM,%s,%d\r\n", ON_OFF(G_parameter.low_power_alarm.sw), G_parameter.low_power_alarm.alarm_type);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "BATALM,%s\r\n", ON_OFF(G_parameter.low_power_alarm.sw));
    }
    if(G_parameter.vibrates_alarm.sw)
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SENALM,%s,%d\r\n", ON_OFF(G_parameter.vibrates_alarm.sw), G_parameter.vibrates_alarm.alarm_type);
    }
    else
    {
        l += OTA_snprintf(importance_backup.data + l, len - l, "SENALM,%s\r\n", ON_OFF(G_parameter.vibrates_alarm.sw));
    }
#if defined(__NT36__)||defined(__MT200__)
    l += OTA_snprintf(importance_backup.data + l, len - l, "SENSOR,%d,%d,%d\r\n",
                      G_parameter.vibrates_alarm.detection_time, G_parameter.vibrates_alarm.alarm_delay_time,
                      G_parameter.vibrates_alarm.alarm_interval / 60);
#else
    l += OTA_snprintf(importance_backup.data + l, len - l, "SENSOR2,%d,%d,%d\r\n",
                      G_parameter.vibrates_alarm.detection_time, G_parameter.vibrates_alarm.alarm_delay_time,
                      G_parameter.vibrates_alarm.alarm_interval);
#endif

    l += OTA_snprintf(importance_backup.data + l, len - l, "GPRSON,%d\r\n", G_parameter.gprson);

    l += OTA_snprintf(importance_backup.data + l, len - l, "LINK,%d\r\n", G_parameter.gprs_obstruction_alarm.link);

    /*需要重点测试*/
    l += OTA_snprintf(importance_backup.data + l, len - l, "HBT,S%d,S%d\r\n", G_parameter.hbt_acc_on, G_parameter.hbt_acc_off);
    l += OTA_snprintf(importance_backup.data + l, len - l, "ADC_BC,B,%d\r\n", G_parameter.adc4_offset);
    l += OTA_snprintf(importance_backup.data + l, len - l, "DEFMODE,%d\r\n", G_realtime_data.defense_mode);
#if defined(__OBD__)
	l += OTA_snprintf(importance_backup.data + l, len - l, "OBDCMD,%s\r\n", ON_OFF(G_parameter.obd.sw));
#endif

    /*
    l += OTA_snprintf(importance_backup.data + l, len - l, "REPORT\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );
    l += OTA_snprintf(importance_backup.data + l, len - l, "\r\n", );*/



#if defined(__GT300S__)
    if(G_parameter.work_mode.mode == 2)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%d",  G_parameter.work_mode.mode, G_parameter.gps_work.Fti.interval_acc_on);
    }
    else  if(G_parameter.work_mode.mode == 1)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%d", G_parameter.work_mode.mode, G_parameter.work_mode.mode1_timer);

    }
    else if(G_parameter.work_mode.mode == 3)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%0.2d:%0.2d,%d",  G_parameter.work_mode.mode,
                G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);
    }
#elif defined(__GT370__)|| defined (__GT380__)
    if(G_parameter.work_mode.mode == 2)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%d,%d",  G_parameter.work_mode.mode, G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
    }
    else  if(G_parameter.work_mode.mode == 1)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%d,%d", G_parameter.work_mode.mode, G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);

    }
    else if(G_parameter.work_mode.mode == 3)
    {
        sprintf(importance_backup.data + l, "MODE,%d,%0.2d:%0.2d,%d",  G_parameter.work_mode.mode,
                G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,	G_parameter.work_mode.mode3_timer / 60);
    }

#endif /* __GT300S__ */
#if defined(__NF2318__)
	//l += OTA_snprintf(importance_backup.data + l, len - l, "DEVICESN,%s\r\n",G_importance_parameter_data.SequenceNumber);
	//l += OTA_snprintf(importance_backup.data + l, len - l, "LEASE,%d\r\n",G_parameter.ste_status.lease);
	//l += OTA_snprintf(importance_backup.data + l, len - l, "MELIAGE,%d,%d\r\n",G_parameter.ele_data.oncemileage,G_parameter.ele_data.totalmileage);
	//l += OTA_snprintf(importance_backup.data + l, len - l, "ENCODETYPE,%d\r\n",G_parameter.ste_status.encode_type);
	
	l += OTA_snprintf(importance_backup.data + l, len - l, "ADVTYPE,%d\r\n",G_parameter.ste_status.btadvtype);
	l += OTA_snprintf(importance_backup.data + l, len - l, "DISARM,%d\r\n",G_realtime_data.defences_status);
	l += OTA_snprintf(importance_backup.data + l, len - l, "AVB,%d,%d,%d\r\n",G_parameter.voice_ver[1],G_parameter.voice_ver[2],G_parameter.voice_ver[3]);
	l += OTA_snprintf(importance_backup.data + l, len - l, "DIAMETER,%d\r\n",G_parameter.ste_param.diameter);
	l += OTA_snprintf(importance_backup.data + l, len - l, "ALNICONUM,%d\r\n",G_parameter.ste_param.alnicounum);
	l += OTA_snprintf(importance_backup.data + l, len - l, "VIBL,%d\r\n",G_parameter.ste_param.viblmg);
	l += OTA_snprintf(importance_backup.data + l, len - l, "BLEKG,%d\r\n",G_parameter.ste_param.btsw);
	l += OTA_snprintf(importance_backup.data + l, len - l, "FREQ,%d\r\n",G_parameter.gps_work.Fti.interval_acc_on);
	//新的保存的参数吧，2019.02.23
	l += OTA_snprintf(importance_backup.data + l, len - l, "SLEEPT,%d\r\n",G_parameter.ste_param.sleept);
	l += OTA_snprintf(importance_backup.data + l, len - l, "DFTLOCKVOICEPLAYT,%d\r\n",G_parameter.ste_param.dftlockvoiceplayt);
	l += OTA_snprintf(importance_backup.data + l, len - l, "MAXECUSPEED,%d\r\n",G_parameter.ele_data.turn_limit);
	l += OTA_snprintf(importance_backup.data + l, len - l, "ALARMFREQ,%d\r\n",G_parameter.ste_param.alarmreq);
	l += OTA_snprintf(importance_backup.data + l, len - l, "DFTTIMEOUT,%d\r\n",G_parameter.ste_param.dfttimeout);
	l += OTA_snprintf(importance_backup.data + l, len - l, "OSDTIMEINTERVAL,%d\r\n",G_parameter.osd.osdtimeinterval);
	l += OTA_snprintf(importance_backup.data + l, len - l, "OSDTIMEMAX,%d\r\n",G_parameter.osd.osdtimemax);

	
	l += OTA_snprintf(importance_backup.data + l, len - l, "OSDSPEED,%d\r\n",G_parameter.osd.osdspeed);
	l += OTA_snprintf(importance_backup.data + l, len - l, "BWOT,%d\r\n",(G_parameter.bwtopen*100));
	l += OTA_snprintf(importance_backup.data + l, len - l, "BWCT,%d\r\n",(G_parameter.bwtclose*100));
	l += OTA_snprintf(importance_backup.data + l, len - l, "ELEOT,%d\r\n",(G_parameter.eletopen*100));
	l += OTA_snprintf(importance_backup.data + l, len - l, "ELECT,%d\r\n",(G_parameter.eletclose*100));
	
	value1 = ((G_parameter.osd.osdvoiceid[0]&0x0000FF)<<16) |((G_parameter.osd.osdvoiceid[1]&0x0000FF)<<8) | G_parameter.osd.osdvoiceid[2];
	value2 = ((G_parameter.osd.osdringid[0]&0x0000FF)<<16) |((G_parameter.osd.osdringid[1]&0x0000FF)<<8) | G_parameter.osd.osdringid[2];
	l += OTA_snprintf(importance_backup.data + l, len - l, "OSDRING,%d:%d\r\n",value1,value2);
	
	l += OTA_snprintf(importance_backup.data + l, len - l, "OSDSWITCH,%d\r\n",G_parameter.osd.osdswitch);
	l += OTA_snprintf(importance_backup.data + l, len - l, "VIBLVOICESW,%s\r\n",ON_OFF(G_parameter.viblvoicesw));
	
	//l += OTA_snprintf(importance_backup.data + l, len - l, "VOICESIZE,%d\r\n",G_parameter.voicefilesize);
	
	l += OTA_snprintf(importance_backup.data + l, len - l, "BTNAME,%s\r\n",G_parameter.ste_param.bt_name);
		//________蓝牙密码
	l += OTA_snprintf(importance_backup.data + l, len - l, "BTPASSWD,%s\r\n",G_parameter.encode_token_s);
	l += OTA_snprintf(importance_backup.data + l, len - l, "NEWBTPSWD,%s\r\n",G_parameter.new_encode_token_s);
	l += OTA_snprintf(importance_backup.data + l, len - l, "NEWBTPSTA,%d\r\n",G_parameter.bt_token_mark);
	//l += OTA_snprintf(importance_backup.data + l, len - l, "RREASON,%d\r\n",G_realtime_data.fota_update);
	//----------------------20191010
	l += OTA_snprintf(importance_backup.data + l, len - l,"LESOFF,%d,%d\r\n",G_realtime_data.lesea_off_to_sta,G_realtime_data.lesea_off_to_volume_sta);
	
#endif
    //LOGD(L_DRV, L_V5, "result=%d,strlen(data)=%d ,%s", len, strlen(importance_backup.data), importance_backup.data);
    l = strlen(importance_backup.data);
    LOGD(L_DRV, L_V5, "result=%d,strlen(data)=%d, stringCRC:%0.4X,\r\n%s", len, l, GetCrc16(importance_backup.data, l), importance_backup.data);
    Track_nvram_write(DISK1_BACKUP_LID, 1, (void *)&importance_backup, NVRAM_EF_DRV__IMP_BACKUP_SIZE);
}

void track_os_importance_backup_read(void)
{
    int l;
    LOGD(L_APP, L_V5, "");

    memset(&importance_backup, 0x00, sizeof(importance_backup));
    Track_nvram_read(DISK1_BACKUP_LID, 1, (void *)&importance_backup, NVRAM_EF_DRV__IMP_BACKUP_SIZE);
    l = strlen(importance_backup.data);
    LOGD(L_DRV, L_V7, "strlen(data)=%d, stringCRC:%0.4X,\r\n%s", l, GetCrc16(importance_backup.data, l), importance_backup.data);
    track_cmd_params_recv(importance_backup.data, CM_PARAM_CMD);
}

