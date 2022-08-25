/******************************************************************************
 * track_at_sms.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *
 *
 * modification history
 * --------------------
 * v1.0   2012-09-07,  wangqi create this file
 *
 ******************************************************************************/
#include "string.h"

#include "track_at.h"
#include "track_at_sms.h"
#include "track_os_timer.h"

#include "track_cmd.h"


#include "c_RamBuffer.h"
#include "c_vector.h"
#include "track_os_ell.h"
#include "track_cust_key.h"

#include "track_drv_system_interface.h"
#include "track_drv_uart.h"
#include "track_os_paramete.h"

#ifdef __AT_CA__
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/

/*****************************************************************************
*  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static sms_submit_pdu ssp = {0};
static c_vector* vec_sms_send = NULL;
static const int SSP_SIZE = sizeof(sms_submit_pdu);

/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/****************************************************************************
/*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/

static void track_sms_send_at_head(kal_uint16 smslen);
static void track_sms_send_req(void);
void track_sms_clean_all_sms_by_timing();
void track_sms_clean_all_by_id();

/******************************************************************************
        短信驱动层开始PDU处理的支持函数
******************************************************************************/
/******************************************************************************
 * FUNCTION:  - str_from_gsm7str *
 * DESCRIPTION: - 处理7bit字串内的一些特殊字符

1B 3D 21 00 23 02 25 1B 14 26 2A 28 29 11 2B 1B 40 1B 2F 3D 2D 20 1B 28
~     !  @  #  %  ^     &  *  (  )   _     +    |     \  =  -  {

1B 29 3A 22 3E 3F 2E 2F 3B 27 1B 3C 1B 3E 3C 2C
}    :     "  >   ?  .  / ;  '  [   ]     <  ,

 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int str_from_gsm7str(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int index = 0;

    if(nSrcLength == 0)
    {
        return index;
    }

    while(nSrcLength)
    {
        if(*pSrc == 0x1B)
        {
            nSrcLength --;
            pSrc++;
            switch(*(pSrc))
            {
                case 0x0A :
                    ;
                case 0x14:
                    pDst[index ++] = '^';
                    break;
                case 0x28:
                    pDst[index ++] = '{';
                    break;
                case 0x29:
                    pDst[index ++] = '}';
                    break;
                case 0x2F:
                    pDst[index ++] = '\\';
                    break;
                case 0x3C:
                    pDst[index ++] = '[';
                    break;
                case 0x3D:
                    pDst[index ++] = '~';
                    break;
                case 0x3E:
                    pDst[index ++] = ']';
                    break;
                case 0x40:
                    pDst[index ++] = '|';
                    break;
                case 0x65:
                    //pDst[index ++] = ''; break;
                default:
                    break;
            }
        }
        else if(*pSrc == 0x00)
        {
            pDst[index ++] = '@';
        }
        else if(*pSrc == 0x02)
        {
            pDst[index ++] = '$';
        }
        else if(*pSrc == 0x11)
        {
            pDst[index ++] = '_';
        }
        else
        {
            pDst[index ++] = *pSrc;
        }

        pSrc ++;
        nSrcLength--;
    }

    return index;
}
/******************************************************************************
 * FUNCTION:  - str_to_gsm7str *
 * DESCRIPTION: - 处理7bit字串内的一些特殊字符
1B 3D 21 00 23 02 25 1B 14 26 2A 28 29 11 2B 1B 40 1B 2F 3D 2D 20 1B 28 1B 29 3A 22 3E 3F 2E 2F 3B 27 1B 3C 1B 3E 3C 2C
~     !  @  #  %  ^     &  *  (  )   _     +    |     \     =  -  {   }    :     "  >   ?  .  / ;  '  [   ]     <  ,
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int str_to_gsm7str(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int index = 0;

    while(nSrcLength--)
    {
        //nSrcLength --;
        switch(*pSrc)
        {
            case '_':
                pDst[index ++] = 0x11;
                break;
            case '@':
                pDst[index ++] = 0x00;
                break;
            case '$':
                pDst[index ++] = 0x02;
                break;
                //case 0x0A :
                //break;
            case '^':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x14;
                break;
            case  '{':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x28;
                break;
            case '}':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x29;
                break;
            case 0x5C:      /*'\'*/
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x2F;
                break;
            case  '[':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x3C;
                break;
            case '~':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x3D;
                break;
            case ']':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x3E;
                break;
            case '|':
                pDst[index ++] = 0x1b;
                pDst[index ++] = 0x40;
                break;
                //case 0x65:
                //pDst[index ++] = ''; break;
            default:
                pDst[index ++] = *pSrc;
                break;
        }
        pSrc ++;
    }

    return index;
}

/******************************************************************************
 * FUNCTION:  - 7-bit编码 *
 * DESCRIPTION: - 将源串每8个字节分为一组，压缩成7个字节循环该处理过程，
 直至源串被处理完如果分组不到8字节，也能正确处理
 * Input:   pSrc: 源字符串指针
            pDst: 目标编码串指针
            nSrcLength: 源字符串长度
 * Output:
 * Returns:  目标编码串长度
 *
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmEncode7bit(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int nSrc = 0;
    static int nDst = 0;
    int nChar = 0;       // 当前正在处理的组内字符字节的序号，范围是0-7
    unsigned char nLeft = 0;    // 上一字节残余的数据

    nSrc = 0;
    nDst = 0;
    while(nSrc < nSrcLength)
    {
        // 取源字符串的计数值的最低3位
        nChar = nSrc & 7;

        if(nChar == 0)
        {
            // 组内第一个字节，只是保存起来，待处理下一个字节时使用
            nLeft = *pSrc;
        }
        else
        {
            // 组内其它字节，将其右边部分与残余数据相加，得到一个目标编码字节
            *pDst = (*pSrc << (8 - nChar)) | nLeft;

            // 将该字节剩下的左边部分，作为残余数据保存起来
            nLeft = *pSrc >> nChar;
            // 修改目标串的指针和计数值
            pDst++;
            nDst++;

        }
        pSrc++;
        nSrc++;
    }

    return nDst;
}

/******************************************************************************
 * FUNCTION:  - 7-bit解码
 * DESCRIPTION: - 将源数据每7个字节分为一组，解压缩成8个字节
    循环该处理过程，直至源数据被处理完如果分组不到7字节，也能正确处理
 * Input:
 * Output:
 * Returns:
 * modification history
 * ------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmDecode7bit(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
    int nSrc = 0, nByte = 0;
    unsigned char nLeft = 0;
    int nDst = 0;

    while(nSrc < nSrcLength)
    {
        // 将源字节右边部分与残余数据相加，去掉最高位，得到一个目标解码字节
        *pDst = ((*pSrc << nByte) | nLeft) & 0x7f;
        // 将该字节剩下的左边部分，作为残余数据保存起来
        nLeft = *pSrc >> (7 - nByte);

        pDst++;
        nDst++;
        nByte++;

        // 到了一组的最后一个字节
        if(nByte == 7)
        {
            *pDst = nLeft;// 额外得到一个目标解码字节

            pDst++;
            nDst++;

            // 组内字节序号和残余数据初始化
            nByte = 0;
            nLeft = 0;
        }

        pSrc++;
        nSrc++;
    }

    *pDst = 0;
    return nDst;
}

//需要指出的是，7-bit的字符集与ANSI标准字符集不完全一致，在0x20以下也排布了一些
//可打印字符，但英文字母、阿拉伯数字和常用符号的位置两者是一样的。



// UCS2解码
// pSrc: 源编码串指针
// pDst: 目标字符串指针
// nSrcLength: 源编码串长度
// 返回: 目标字符串长度
static int gsmDecodeUcs2(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
    int i = 0 , nDstLength = 0;        // UNICODE宽字符数目
    WCHAR wchar[128] = {0};      // UNICODE串缓冲区

    // 高低字节对调，拼成UNICODE
    for(i = 0; i < nSrcLength / 2; i++)
    {
        wchar[i] = *pSrc++ << 8;// 先高位字节
        wchar[i] |= *pSrc++;// 后低位字节
    }

    // UNICODE串-->字符串
    //nDstLength = WideCharToMultiByte(0/*CP_ACP*/, 0, wchar, nSrcLength/2, pDst, 160, NULL, NULL);
    app_ucs2_wcs_n_to_asc_str(pDst, wchar, nSrcLength / 2);
    pDst[nDstLength] = '\0';

    // 返回目标字符串长度
    return nDstLength;
}

static kal_uint8 gsm2char_1number(const char* pSrc)
{
    static kal_uint8 Dst = 0;
    Dst = 0;
    //Dst = (*pSrc >= '0' && *pSrc <= '9' ? (*pSrc - '0') << 4 : (*pSrc - 'A' + 10) << 4);
    if(*pSrc >= '0' && *pSrc <= '9')
    {
        Dst = (*pSrc - '0') << 4;
    }
    else
    {
        Dst = (*pSrc - 'A' + 10) << 4;
    }

    pSrc++;

    //Dst |= (*pSrc >= '0' && *pSrc <= '9' ? (*pSrc - '0') : (*pSrc - 'A' + 10));
    if(*pSrc >= '0' && *pSrc <= '9')
    {
        Dst |= *pSrc - '0';
    }
    else
    {
        Dst |= *pSrc - 'A' + 10;
    }
    pSrc++;
    return Dst;
}

/******************************************************************************
 * FUNCTION:  - gsmString2Bytes
 * DESCRIPTION: - 可打印字符串转换为字节数据
 * 如："C8329BFD0E01" --> {0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01}
 * Input:   pSrc: 源字符串指针
            pDst: 目标数据指针
            nSrcLength: 源字符串长度
 * Output:
 * Returns: 目标数据长度
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmString2Bytes(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int i = 0;
    LOGD(L_CMD, L_V8, "%d", nSrcLength);
    for(i = 0; i < nSrcLength; i += 2)
    {
        /* 输出高4位*/
        //*pDst = (*pSrc >= '0' && *pSrc <= '9' ? (*pSrc - '0') << 4 : (*pSrc - 'A' + 10) << 4);
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            *pDst = (*pSrc - '0') << 4;
        }
        else
        {
            *pDst = (*pSrc - 'A' + 10) << 4;
        }

        pSrc++;

        /* 输出低4位*/
        //*pDst |= (*pSrc >= '0' && *pSrc <= '9' ? (*pSrc - '0') : (*pSrc - 'A' + 10));
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            *pDst |= *pSrc - '0';
        }
        else
        {
            *pDst |= *pSrc - 'A' + 10;
        }

        pSrc++;
        pDst++;
    }

    return nSrcLength / 2;
}


/******************************************************************************
 * FUNCTION:  - gsmBytes2String
 * DESCRIPTION: - 字节数据转换为可打印字符串
 * 如：{0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01} --> "C8329BFD0E01"
 * Input:   pSrc: 源数据指针
            pDst: 目标字符串指针
            nSrcLength: 源数据长度
 * Output:
 * Returns: 目标字符串长度
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmBytes2String(const unsigned char* pSrc, char* pDst, int nSrcLength, kal_uint16 type)
{
    int i = 0;
    const char tab[] = "0123456789ABCDEF";  // 0x0-0xf的字符查找表
    int DstLen = nSrcLength;

    if(type == SMS_MS_MT)
    {
        memcpy(pDst, pSrc, nSrcLength);
    }
    else
    {
        for(i = 0; i < nSrcLength; i++)
        {
            *pDst++ = tab[*pSrc >> 4];// 输出低4位
            *pDst++ = tab[*pSrc & 0x0f];// 输出高4位
            pSrc++;
        }

        *pDst++ = '\0';// 输出字符串加个结束符
        *pDst = '\0';// 输出字符串加个结束符
        DstLen  = nSrcLength * 2;
    }

    return DstLen;// 返回目标字符串长度
}


/******************************************************************************
 * FUNCTION:  - gsmInvertNumbers
 * DESCRIPTION: - 正常顺序的字符串转换为两两颠倒的字符串，若长度为奇数，补'F'凑成偶数
    如："8613851872468" --> "683158812764F8"
 * Input:   pSrc: 源字符串指针
            pDst: 目标字符串指针
        nSrcLength: 源字符串长度

        type 0时是发送短信号码转为翻转后的数字形式
        type 1时是存储短信号码转为翻转后的字符串形式
 * Output:
 * Returns:
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmInvertNumbers(const char* pSrc, char* pDst, int nSrcLength, kal_uint16 type)
{
    int i = 0, nDstLength = nSrcLength;
    char ch;

    if(type == SMS_MS_MT)
    {

        // 两两颠倒
        for(i = 0; i < nSrcLength; i += 2)
        {
            *pDst = (*pSrc++) - '0';
            *pDst += ((*pSrc++) - '0') << 4;
            //*pDst = *pDst << 4 + ch;
            pDst++;
        }
        nDstLength /= 2;
        // 源串长度是奇数吗？
        if(nSrcLength & 1)
        {
            *(pDst - 1) += 0xF0;//'F';   // 补'F'
            nDstLength++;
        }

        *pDst = '\0';
    }
    else
    {
        // 两两颠倒
        for(i = 0; i < nSrcLength; i += 2)
        {
            ch = *pSrc++;
            *pDst++ = *pSrc++;
            *pDst++ = ch;
        }

        // 源串长度是奇数吗？
        if(nSrcLength & 1)
        {
            *(pDst - 2) = 'F';   // 补'F'
            nDstLength++;
        }

        *pDst = '\0';

    }
    return nDstLength;
}


/******************************************************************************
 * FUNCTION:  - gsmSerializeNumbers
 * DESCRIPTION: - 两两颠倒的字符串转换为正常顺序的字符串
 * 如："683158812764F8" --> "8613851872468"
 * Input:
 * Output:
 * Returns:
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmSerializeNumbers(const char* pSrc, char* pDst, int nSrcLength)
{
    int i , nDstLength;
    char ch;

    nDstLength = nSrcLength;

    // 两两颠倒
    for(i = 0; i < nSrcLength; i += 2)
    {
        ch = *pSrc++;
        *pDst++ = *pSrc++;
        *pDst++ = ch;
    }

    if(*(pDst - 1) == 'F')
    {
        pDst--;
        nDstLength--;
    }

    *pDst = '\0';

    return nDstLength;
}

//以下是PDU全串的编解码模块。为简化编程，有些字段用了固定值。

#if 0
分段以下为PDU解码打包发送接收驱动层处理
#endif

// PDU解码，用于接收、阅读短消息
// pSrc: 源PDU串指针
// pDst: 目标PDU参数指针
// 返回: 用户信息串长度
/*
08 91 683108702505
F0 04
0D 91 685110689058F5
00 08 21909161829323
06 738B94876CFD
*/

/******************************************************************************
 * FUNCTION:  - gsmDecodePdu *
 * DESCRIPTION: - 短信内容解码
 0891683108200075F12410A821251005810689550000219042906145230D41EA8672A44686CD1EF37904
 *          SCA                  PDUTYPE         OA
    1   0-1     0-10                1       1   0-1     0-10
   len  Type    Addr                        len Type    Addr
 * 08   91      683108200075F1      24      10  A8      2125100581068955

   PID  DCS SCTS            UDL     UD
    1    1   7               1  len 1   data
   00   00  219042906145    23  0D      41EA8672A44686CD1EF37904
 * Input:
 * Output:
 * Returns:  *
 * modification history
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int gsmDecodePdu(const char* pSrc, SM_PARAM* pDst)
{
    int nDstLength = 0;          // 目标PDU串长度
    unsigned char tmp = 0;       // 内部用的临时字节变量
    unsigned char bit7smsLen = 0;
    unsigned char buf[SMS_MAX_SIZE]; // 内部用的缓冲区

    /**********SMSC*************/
    tmp = gsm2char_1number(pSrc);    // 取长度
    pSrc += 2; //SCA Type
    //SCA Type = gsm2char_1number(pSrc);
    //pSrc += 2; //
    tmp = tmp * 2;    // SMSC号码串长度
    gsmSerializeNumbers(pSrc, pDst->SCA, tmp);    // 转换SMSC号码到目标PDU串
    pSrc += tmp;
    /********end SMSC**********/

    /**********P_TYPE*************/
    pDst->P_TYPE = gsm2char_1number(pSrc);
    pSrc += 2;
    /********end P_TYPE**********/
    /********OA*********/

    //if(pDst->P_TYPE & 0x80)//小于8?
    {
        pDst->ODAL = gsm2char_1number(pSrc);

        if(pDst->ODAL & 1)
        {
            pDst->ODAL += 1;   // 调整奇偶性
        }
        pSrc += 2;
        tmp = gsm2char_1number(pSrc);

        pSrc += 2;
        if((tmp & 0xf0) == 0x90)
        {
            pDst->TPA[0] = '+';
            gsmSerializeNumbers(pSrc, &pDst->TPA[1], pDst->ODAL);
        }
        else
        {
            gsmSerializeNumbers(pSrc, &pDst->TPA[0], pDst->ODAL);
        }

        pSrc += pDst->ODAL;
    }


    /********end OA**********/
    pDst->TP_PID = gsm2char_1number(pSrc);
    pSrc += 2;
    pDst->TP_DCS = gsm2char_1number(pSrc);
    pSrc += 2;
    gsmSerializeNumbers(pSrc, &pDst->TP_SCTS[0], 14);
    pSrc += 14;
    tmp = gsm2char_1number(pSrc);// 用户信息长度(TP-UDL)
    pSrc += 2;

    LOGD(L_CMD, L_V5, "PID:%d,DCS:%d,SCTS:%s,UDL:%d", pDst->TP_PID, pDst->TP_DCS, pDst->TP_SCTS, tmp);
    memset(buf, 0, sizeof(buf));

    if(pDst->TP_DCS == GSM_7BIT)
    {
        memset(pDst->TP_UD, 0, SMS_MAX_SIZE);
        if(tmp & 7)
        {
            bit7smsLen = (int)tmp * 7 / 4 + 2;
        }
        else
        {
            bit7smsLen = (int)tmp * 7 / 4;
        }
        //nDstLength = gsmString2Bytes(pSrc, buf, tmp & 7 ? (int)tmp * 7 / 4 + 2 : (int)tmp * 7 / 4);nDstLength = gsmString2Bytes(pSrc, buf, tmp & 7 ? (int)tmp * 7 / 4 + 2 : (int)tmp * 7 / 4);
        nDstLength = gsmString2Bytes(pSrc, buf, bit7smsLen);

//LOGD(L_CMD, L_V5, "gsmstringbytes:tmp:%d,nDst:%d", tmp,nDstLength);
//LOGH(L_CMD, L_V8, buf, tmp);
        nDstLength = gsmDecode7bit(buf, pDst->TP_UD, tmp);

//LOGD(L_CMD, L_V5, "decode7bit:tmp:%d,nDst:%d", tmp,nDstLength);
//LOGH(L_CMD, L_V8, pDst->TP_UD, tmp);
        tmp = str_from_gsm7str(pDst->TP_UD, buf, tmp);
        nDstLength = tmp;
//LOGD(L_CMD, L_V5, "gsm7str:last length:%d", tmp);
        memset(pDst->TP_UD, 0, SMS_MAX_SIZE);
        memcpy(pDst->TP_UD, buf, tmp);

    }
    else if(pDst->TP_DCS == GSM_UCS2)
    {
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);
        memcpy(pDst->TP_UD, buf, nDstLength);
        //LOG_UNI(L_CMD,L_V2,pDst->TP_UD,nDstLength);
        LOGH(L_CMD, L_V5, pDst->TP_UD, nDstLength);

    }
    else
    {
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);
        memcpy(pDst->TP_UD, buf, nDstLength);
        LOGD(L_CMD, L_V5, "GSM8:%s", pDst->TP_UD);

    }
    pDst->TP_UDL = nDstLength;

    return nDstLength;
}


#if defined( __GPS_TRACK__)
#include "smsal_l4c_enum.h"
#include "Smsal_l4c_defs.h"
#include "l4c2smsal_struct.h"
#include "l4c_utility.h"
#endif /* __GPS_TRACK__ */
extern kal_bool l4c_sms_exe_post_pdu_req(
    kal_uint8 src_id,
    kal_uint16 reply_index,
    kal_uint16 data_len,
    kal_uint8 source_id,
    kal_uint8 seq_num,
    kal_uint8 mms_mode,
    kal_uint16 length,
    kal_uint8 *pdu);
/******************************************************************************
 * FUNCTION:  - track_l4c_sms_exe_post_pud *
 * DESCRIPTION: - 发短信接口
 * Input:
 * Output:
 * Returns:  *
 * modification history
 * --------------------
 * v1.0  ,20150522,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_l4c_sms_exe_post_pud(kal_uint16 data_len, kal_uint8 type, kal_uint8* data)
{
    LOGH(L_CMD, L_V6, data, data_len);
    l4c_sms_exe_post_pdu_req(
        RMMI_SRC,
        SMSAL_INVALID_INDEX,
        data_len - 1,
        0,
        type,
        0,
        data_len,
        data);
}


/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/

void track_at_sms_check_auto_mode(void)
{
    track_at_vs_send(CHECK_SMS_AUTO);
}

void track_sms_del_one(void)
{
    LOGD(L_CMD, L_V5, "i will del it later");

}

void track_sms_send_CSCA(void)
{
    track_at_vs_send(SMS_CSCA);
}


/*****************************************************************************/
/******************************************************************************
 * FUNCTION:  - track_sms_change_status
 * DESCRIPTION: -
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_sms_change_status(SMS_STATUS_ENUM sstatus)
{
    LOGD(L_CMD, L_V5, "last:%d,status:%d", ssp.sms_status, sstatus);
    ssp.sms_status = sstatus;
}
/******************************************************************************
 * FUNCTION:  - sms_resend
 * DESCRIPTION: - 重新发送短信
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void sms_resend(void)
{
    if(ssp.sms_dir == SMS_SENDER_BOX)
    {
        track_at_vs_send("\x1b\0");
    }
    track_sms_send_at_head(ssp.sms_len);
}
/******************************************************************************
 * FUNCTION:  - sms_check_error_notice_app
 * DESCRIPTION: - 通知应用层
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void
sms_check_error_notice_app(SMS_SEND_RESULT_ENUM result, SMS_STATUS_ENUM sstatus, SMS_DIRECTION sdir, kal_int32 sindex)
{
    sms_send_rsp_struct rpss = {0};

    LOGD(L_CMD, L_V5, "index:%d,status:%d,result:%d", rpss.index, sstatus, rpss.result);

    rpss.index = sindex;
    rpss.status = sstatus;
    rpss.result = result;
    rpss.dir = sdir;
    track_set_vs_at_status(V_A_FREE);
    track_stop_timer(TRACK_SMS_SEND_CHECK_LOCK_TIMER_ID);

    if(SMS_SENDER_BOX == rpss.dir)
    {
        track_sim_sendmsg_rsp(&rpss);
    }
    else
    {
        track_app_sms_rsp(&rpss);
    }
}
/******************************************************************************
 * FUNCTION:  - sms_send_result_notice_app
 * DESCRIPTION: - 通知应用层
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void sms_send_result_notice_app(SMS_SEND_RESULT_ENUM result)
{
    sms_send_rsp_struct rpss = {0};

    rpss.index = ssp.sms_index;
    rpss.status = ssp.sms_status;
    rpss.result = result;
    rpss.dir = ssp.sms_dir;

    memset(&ssp, 0, sizeof(sms_submit_pdu));
    track_sms_change_status(sSTANDBY);
    sms_check_error_notice_app(rpss.result, ssp.sms_status, rpss.dir, rpss.index);

}
/******************************************************************************
 * FUNCTION:  - sms_send_overtime
 * DESCRIPTION: - 发送短信超时
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void sms_send_overtime(void * type)
{
    int stype = (int) type;

    track_set_vs_at_status(V_A_FREE);

    if(stype == sSENDERROR)
    {
        ssp.sms_error_conut++;
    }
    else if(sSENDHEADOVER == stype || sSENDOVERTIME == stype)
    {
        ssp.sms_overtime_count++;
    }
    LOGD(L_CMD, L_V5, "发送超时overtime:%d errortime:%d", ssp.sms_overtime_count, ssp.sms_error_conut);
#if  0
    //测试
    sms_send_result_notice_app(stype);
    track_sms_send_req();
    return;//
#endif /* 0 */
    if(ssp.sms_overtime_count >= SMS_RESEND_LIMIT || ssp.sms_error_conut >= SMS_RESEND_LIMIT)
    {
        sms_send_result_notice_app(stype);
        track_sms_send_req();
    }
    else
    {
        tr_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 1000, sms_resend);
    }
}


/******************************************************************************
 * FUNCTION:  - track_sms_send_ctx
 * DESCRIPTION: - 发送短信内容
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sms_send_ctx(void)
{
    static char * p = &ssp.sms_ctx[0];
    vs_at_cmd_struct vs_sms = {0};

    track_stop_timer(TRACK_SMS_SEND_RSP_TIMER_ID);
    LOGD(L_CMD, L_V5, "发送内容sms_ctx lenght:%d,sms_size:%d,sp_size:%d,type:%d,p=%u",
         ssp.sms_len, ssp.sms_size, ssp.sp_size, ssp.smscodetype, p);

    if(ssp.sms_size)
    {
        if(ssp.sp_size == 0)
        {
            ssp.sp_size = ssp.sms_size;
        }

        if(ssp.sms_dir == SMS_MS_MT)
        {
            track_l4c_sms_exe_post_pud(ssp.sp_size, ssp.smscodetype, ssp.sms_ctx);
            ssp.sms_status = sSEND_WAIT;

            track_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, SMS_RESEND_INTERVAL_TIME, sms_send_overtime, (void*)sSENDOVERTIME);

            return;
        }
        else if(ssp.sms_dir == SMS_SENDER_BOX)
        {

            vs_sms.at_cmd_callback = track_vs_at_sms_at_rsp;
            vs_sms.at_type = AT_CUSTOMER;
            snprintf(vs_sms.at_head, sizeof(vs_sms.at_head), "CMGW:");
        }
        //AT指令最长127
        //track_set_vs_at_status(V_A_FREE);
        if(ssp.sp_size > 120)
        {
            ssp.sp_size -= 120;

            memcpy(vs_sms.at_ctx , p, 120);
            vs_sms.at_length = 120;
            tr_at_vs_ctx(&vs_sms);
            p += 120;
            tr_start_timer(TRACK_SMS_SEND_CTX_TIMER_ID, 200, track_sms_send_ctx);
        }
        else
        {
            memcpy(vs_sms.at_ctx , p, ssp.sp_size);
            vs_sms.at_length = ssp.sp_size;
            tr_at_vs_ctx(&vs_sms);
            p = &ssp.sms_ctx[0];
            ssp.sp_size = 0;
            //track_set_vs_at_status(V_A_FREE);
            ssp.sms_status = sSEND_WAIT;
            track_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, SMS_RESEND_INTERVAL_TIME, sms_send_overtime, (void*)sSENDOVERTIME);
        }
    }
    else
    {
        memset(&ssp, 0, sizeof(sms_submit_pdu));
        p = &ssp.sms_ctx[0];
        track_set_vs_at_status(V_A_FREE);
        track_sms_send_req();
    }

}
/******************************************************************************
 * FUNCTION:  - track_send_ctx
 * DESCRIPTION: - 发送短信内容
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_send_ctx(void)
{
    track_sms_change_status(sSEND_CTX);
    track_sms_send_ctx();
}
/******************************************************************************
 * FUNCTION:  - track_sms_send_at_head
 * DESCRIPTION: - 发送短信AT指令头
 * modification history
8:59:28.216> [3]track_sms_send_req() vector_size:0,at:0,sspLen:48
8:59:35.780>
8:59:35.780> +CMGS: 67
在坐位上测试发送时间为8秒左右
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_sms_send_at_head(kal_uint16 smslen)
{
    vs_at_cmd_struct vs_sms = {0};

    LOGD(L_CMD, L_V5, "进入发送程序smslen:%d,status:%d,dir:%d", smslen, ssp.sms_status, ssp.sms_dir);
    if(smslen <= 0)
    {
        return;
    }

    if(ssp.sms_dir == SMS_MS_MT)
    {
        track_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, SMS_RESEND_INTERVAL_TIME, sms_send_overtime, (void*)sSENDHEADOVER);
        //track_sms_send_ctx();
        track_send_ctx();

    }
    else if(ssp.sms_dir == SMS_SENDER_BOX)
    {
        sprintf(vs_sms.at_ctx, "AT+CMGW=%d,2\r", smslen);
        snprintf(vs_sms.at_head, sizeof(vs_sms.at_head), "CMGW=");


        vs_sms.at_cmd_callback = track_vs_at_sms_at_rsp;
        vs_sms.at_type = AT_CUSTOMER;
        vs_sms.at_length = strlen(vs_sms.at_ctx);

        track_sms_change_status(sSEND_HEAD);
        track_set_vs_at_status(V_A_FREE);
        track_at_vs_send_sms(&vs_sms);
        track_set_vs_at_status(V_A_HOLD);
        track_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 10000, sms_send_overtime, (void*)sSENDHEADOVER);

    }
    else
    {
        LOGD(L_CMD, L_V5, "110 911 112---------------->%d", ssp.sms_dir);
        //ASSERT(0);
        return;
    }

    //超时判断

}


/******************************************************************************
        短信驱动层结束          短信应用层开始
******************************************************************************/
static void track_sms_push_submit(sms_submit_pdu * ssp)
{
    sms_submit_pdu *tem_sms = (sms_submit_pdu*)Ram_Alloc(2, sizeof(sms_submit_pdu));

    if(NULL == vec_sms_send)
    {
        VECTOR_CreateInstance(vec_sms_send);
    }

    if(tem_sms)
    {
        memset(tem_sms, 0, SSP_SIZE);
        memcpy(tem_sms, ssp, SSP_SIZE);
        VECTOR_PushBack(vec_sms_send, tem_sms);
    }
    LOGD(L_CMD, L_V5, "vector_size:%d", VECTOR_Size(vec_sms_send));

}

static int get_sms_vec_sizes(void)
{
    int vec_sms = 0;
    if(NULL != vec_sms_send)
    {
        vec_sms = VECTOR_Size(vec_sms_send);
    }
    return vec_sms;
}

static void sms_clear_lock(void)
{
    LOGD(L_CMD, L_V5, "回收状态: sms vec size:%d,status:%d,at hold:%d",
         get_sms_vec_sizes(), ssp.sms_status, track_at_is_hold());

    memset(&ssp, 0, sizeof(sms_submit_pdu));
    track_set_vs_at_status(V_A_FREE);
    track_sms_change_status(sSTANDBY);
    if(get_sms_vec_sizes())
    {
        track_at_vs_send("\x1b");
        tr_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 1000, track_sms_send_req);
    }
}
/******************************************************************************
 * FUNCTION:  - track_sms_send_req
 * DESCRIPTION: - 发送短信AT指令头
 * modification history
 * --------------------
 * v1.0  , 30-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_sms_send_req(void)
{
    sms_submit_pdu* tsspdu ;
    LOGD(L_CMD, L_V5, "发送短信前状态确认at:%d", track_at_is_hold());
#if defined (__GT740__)
    if(track_is_in_call() || track_cust_wifi_scan_status())
#else
    if(track_is_in_call())
#endif
    {
        tr_start_timer(TRACK_SMS_SEND_CHECK_TIMER_ID, 5000, track_sms_send_req);
        return;
    }
    tr_start_timer(TRACK_SMS_SEND_CHECK_LOCK_TIMER_ID, SMS_RESEND_INTERVAL_TIME * 3, sms_clear_lock);
    if(track_at_is_hold())
    {
        tr_start_timer(TRACK_SMS_SEND_CHECK_TIMER_ID, 5000, track_sms_send_req);
        return;
    }

    if(NULL == vec_sms_send)
    {
        VECTOR_CreateInstance(vec_sms_send);
    }
    else if(VECTOR_Size(vec_sms_send))
    {
        tsspdu = VECTOR_At(vec_sms_send, 0);
        memset(&ssp, 0, SSP_SIZE);

        if(tsspdu)
        {
            memcpy(&ssp, tsspdu, SSP_SIZE);
            VECTOR_Erase(vec_sms_send, 0, 1);
            Ram_Free(tsspdu);
            tsspdu = NULL;
            track_sms_send_at_head(ssp.sms_len);

        }
        else if(VECTOR_Size(vec_sms_send))
        {
            VECTOR_Erase(vec_sms_send, 0, 1);
            track_os_intoTaskMsgQueue(track_sms_send_req);
        }
    }
    else
    {
        track_stop_timer(TRACK_SMS_SEND_CHECK_LOCK_TIMER_ID);//wangqi
    }
    LOGD(L_CMD, L_V5, "vector_size:%d,at:%d,sspLen:%d", VECTOR_Size(vec_sms_send), track_at_is_hold(), ssp.sms_len);
}

void track_sms_reset(void)
{
    LOGD(L_CMD, L_V5, "sms_status:%d,%d", ssp.sms_status, get_sms_vec_sizes());
    memset(&ssp, 0, SSP_SIZE);
    track_stop_timer(TRACK_SMS_SEND_CHECK_LOCK_TIMER_ID);
    track_stop_timer(TRACK_SMS_SEND_RSP_TIMER_ID);
    track_stop_timer(TRACK_SMS_SEND_CTX_TIMER_ID);
    track_stop_timer(TRACK_SMS_SEND_CHECK_TIMER_ID);
    track_stop_timer(TRACK_OUTBOX_CALLBACK_TIMER_ID);
    if(NULL == vec_sms_send)
    {
        VECTOR_CreateInstance(vec_sms_send);
    }
    while(VECTOR_Size(vec_sms_send))
    {
        sms_submit_pdu* tsspdu;
        tsspdu = VECTOR_At(vec_sms_send, 0);
        if(tsspdu)
        {
            Ram_Free(tsspdu);
            VECTOR_Erase(vec_sms_send, 0, 1);
        }
    }
}

/******************************************************************************
 * FUNCTION:  - track_sms_get_send_status

 * Returns: 1 busy 0 free
 *
 * modification history
 * --------------------
 * v1.0  , 27-03-2013,  wangqi  written
 * --------------------
 ******************************************************************************/
kal_bool track_sms_get_send_status(void)
{
    LOGD(L_CMD, L_V5, "!!sms_status:%d,%d", ssp.sms_status, get_sms_vec_sizes());
    return (ssp.sms_status != sSTANDBY || get_sms_vec_sizes() != 0);
}


/******************************************************************************
 * FUNCTION:  - track_sms_send_rsp
 * DESCRIPTION: -
 *    track_sms_send_rsp
 * Returns: -1 Error 0 OK 1 NEXT 2 返回与发送相等
 * modification history
 * --------------------
 * v1.0  , 25-03-2013,  wangqi  written
 * --------------------
 ******************************************************************************/
kal_bool track_sms_send_rsp(kal_int8 result)
{
    kal_bool operate_ret = KAL_FALSE;

    track_stop_timer(TRACK_SMS_SEND_RSP_TIMER_ID);//发送错误暂时不重发
    LOGD(L_CMD, L_V5, "error:%d,count:%d,status:%d,==ret:%d",
         ssp.sms_error_conut, ssp.sms_overtime_count, ssp.sms_status, result);
    //0,1,2,1
    if(1 == result)
    {
        if(ssp.sms_status == sSEND_HEAD)
        {
            tr_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 100, track_send_ctx);
        }
        else
        {
            LOGD(L_CMD, L_V1, "!!标致位%d", ssp.sms_status);
        }
    }
    else if(0 == result)
    {
        operate_ret = KAL_TRUE;
        if(ssp.sms_status == sSEND_WAIT)
        {
            tr_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 3000, track_sms_send_req);
            sms_send_result_notice_app(sSENDOK);
        }
        else
        {
            LOGD(L_CMD, L_V1, "@@标致位%d", ssp.sms_status);
        }
    }
    else if(2 == result)
    {
        LOGD(L_CMD, L_V1, "====标致位%d", ssp.sms_status);
    }
    else if(-1 == result)
    {
        //track_set_vs_at_status(V_A_FREE);
        if(ssp.sms_status > sSTANDBY)
        {
            track_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 1000, sms_send_overtime, (void*)sSENDERROR);
        }
    }
    {
        extern nvram_realtime_struct G_realtime_data;
        if(G_realtime_data.netLogControl & 64)
        {
            cust_packet_log_data(3, &result, 1);
        }
    }
    return operate_ret;
}


//26:0891683108702505F0040D91685110689058F500082190916182932306738B94876CFD
/*
08 91 683108702505
F0 04
0D 91 685110689058F5
00 08 21909161829323
06 738B94876CFD
*/

/******************************************************************************
 * FUNCTION:  - track_sms_receive
 * DESCRIPTION: - 短信内容接收解码并通知应该层
 * Input:
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sms_receive(int sms_length, char * sms_context)
{
    SM_PARAM *sms_rev_old = NULL;
    track_sms_param *sms_rev = NULL;
    LOGD(L_CMD, L_V5, "%d:%s", sms_length, sms_context);
    LOGH(L_CMD, L_V6, sms_context, sms_length);
    if(sms_length == 0 || sms_context == NULL)
    {
        return;
    }

    sms_rev_old = (SM_PARAM*)Ram_Alloc(2, sizeof(SM_PARAM));
    if(sms_rev_old == NULL)
    {
        LOGD(L_CON, L_V4, "cannt get rambuffer %d", sms_length);
        return;
    }
    memset(sms_rev_old, 0, sizeof(SM_PARAM));

    gsmDecodePdu(sms_context, sms_rev_old);
    if(sms_rev_old->TP_DCS == GSM_UCS2)
    {
        LOGD(L_CMD, L_V5, "%s:%s:%s:%d",
             sms_rev_old->SCA, sms_rev_old->TPA, sms_rev_old->TP_SCTS, sms_rev_old->TP_UDL);
    }
    else
    {
        LOGD(L_CMD, L_V5, "%s:%s:%s:%d,%s",
             sms_rev_old->SCA, sms_rev_old->TPA, sms_rev_old->TP_SCTS, sms_rev_old->TP_UDL, sms_rev_old->TP_UD);
    }
    sms_rev = (track_sms_param*)Ram_Alloc(2, sizeof(track_sms_param) + 280);
    if(sms_rev == NULL)
    {
        LOGD(L_CON, L_V4, "cannt get rambuffer %d", sizeof(track_sms_param) + 280);
        return;
    }
    sms_rev->TP_UD = (char *)sms_rev + sizeof(track_sms_param);

    sms_rev->index =  sms_rev_old->index;
    sms_rev->TP_Unique = sms_rev_old->TP_Unique;
    sms_rev->TP_DCS = sms_rev_old->TP_DCS;
    sms_rev->ODAL =  sms_rev_old->ODAL;
    memcpy(sms_rev->TPA, sms_rev_old->TPA, 31);
    sms_rev->TP_UDL = sms_rev_old->TP_UDL;
    memcpy(sms_rev->TP_UD, sms_rev_old->TP_UD, sms_rev->TP_UDL);

    track_app_receive_sms(sms_rev);
    Ram_Free(sms_rev);
    Ram_Free(sms_rev_old);
}


#if 0
提供接口部分
#endif


/******************************************************************************
 * FUNCTION:  - track_sms_packet
 * DESCRIPTION: -
 * Input:群发时的号码序号  分包的序号 内容 返回包
 * Output:
 * Returns:
 * SCA  PDUTtype    MR  DA      PID DCS VP      UDL UD
   1-12     1       1   2-12    1   1   0,1,7   1   0-140
   AT+CMGS=19
   00 31 00 0D91685110689058F5  00  00  A7      04  D4F29C0E     //7bit Test
   00 31 00 0D91685110689058F5  00  04  A7      04  54455354     //8bit TEST
 1.去加号电话号码/短信中心号码不是偶补F为偶 2.反转 3.加91 4.除以2加长度 1.MSG如果为UIN长除以2
 * modification history
 * --------------------
 * v1.0  , 25-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static kal_uint8 track_sms_packet(sms_ctx_encode_struct * ssms, sms_submit_pdu *_ssp)
{
    kal_uint16 nDstLength = 0, cindex = 0, copylength = 0, max_7bit = 266;
    unsigned char buf[32] = {0};
    extern nvram_importance_parameter_struct G_importance_parameter_data;

    memset(_ssp, 0, sizeof(sms_submit_pdu));
    // SMSC地址信息段

    buf[0] = 0;
    nDstLength = gsmBytes2String(buf, _ssp->sms_ctx, 1, ssms->sms_dir); // 转换2个字节到目标PDU串

    //buf[0] = ssms->tpacket ? 0x71 : 0x31;  // PDUType发送短信相对格式要回执
    
#if defined (__SAME_GT02__)
    if(!G_importance_parameter_data.app_version.support_WM)
    {
        if(ssms->tpacket)
        {
            buf[0] = 0x51;
        }
        else
        {
            buf[0] = 0x11;
        }
    }
    else
    {
        if(ssms->tpacket)
        {
            buf[0] = 0x71;
        }
        else
        {
            buf[0] = 0x31;
        }
    }
#elif defined( __LANG_ENGLISH__)
//PDUType发送短信相对格式不要回执
    if(ssms->tpacket)
    {
        buf[0] = 0x51;
    }
    else
    {
        buf[0] = 0x11;
    }
#else
    if(ssms->tpacket)
    {
        buf[0] = 0x71;
    }
    else
    {
        buf[0] = 0x31;
    }
#endif /* __LANG_ENGLISH__ */

    buf[1] = 0;                             // TP-MR=0

    nDstLength += gsmBytes2String(buf, _ssp->sms_ctx + nDstLength, 2, ssms->sms_dir); //TODO看下是否有问题

    LOGD(L_CMD, L_V6, "number:%s,len:%d,dir:%d",  ssms->encode_number, ssms->inumlen, ssms->sms_dir);

    memcpy(_ssp->sms_ctx + nDstLength, ssms->encode_number, ssms->inumlen); //号码
    nDstLength += ssms->inumlen;

    //PID DCS VP
    buf[0] = 0;          // 协议标识(TP-PID)
    buf[1] = ssms->smscodetype;          // 用户信息编码方式(TP-DCS)
    buf[2] = 0xA7;                  // 有效期(TP-VP)为5分钟
    if(ssms->tpacket > 0)
    {

        if(ssms->smscodetype == GSM_7BIT)
        {
            buf[3] = ssms->sendlen + 8;
            buf[4] = 0x06;//UDHL 分拆标致 后面协议长度 标识 共条 本条
            buf[5] = 0x08;//分拆标致
            buf[6] = 0x04;//后面协议长度
            buf[7] = ssms->tp_index;
            buf[8] = ssms->tpacket + 1; //标识
            buf[9] = ssms->tpacket + 1;
            buf[10] = ssms->curpacket + 1;
            cindex = 11;
        }
        else
        {
            buf[3] = ssms->sendlen + 6;
            buf[4] = 0x05;//UDHL 分拆标致 后面协议长度 标识 共条 本条
            buf[5] = 0x00;//分拆标致
            buf[6] = 0x03;//后面协议长度
            buf[7] = ssms->tp_index;//标识
            buf[8] = ssms->tpacket + 1;
            buf[9] = ssms->curpacket + 1;
            cindex = 10;
        }
    }
    else
    {
        buf[3] = ssms->sendlen;//buf[3]
        cindex = 4;
        copylength = ssms->ictxlen;
    }

    nDstLength += gsmBytes2String(buf, _ssp->sms_ctx + nDstLength, cindex, ssms->sms_dir);


    if(ssms->smscodetype == GSM_7BIT)
    {
        if(ssms->tpacket > 0) //分包分开算长度
        {
            //copylength = (ssms->tpacket == ssms->curpacket ? ssms->ictxlen % 266 : 266);//152 133个8bit字符
            if(ssms->sms_dir == SMS_MS_MT)
            {
                max_7bit = 133;
            }
            if(ssms->tpacket == ssms->curpacket)
            {
                copylength = ssms->ictxlen % max_7bit;
            }
            else
            {
                copylength = max_7bit;
            }
        }
        else
        {
            copylength = ssms->ictxlen;
        }
    }
    else if(ssms->sms_dir == SMS_SENDER_BOX)
    {
        copylength = ssms->sendlen * 2;
    }
    else
    {
        copylength = ssms->sendlen;
    }

    //UDL  UD
    LOGD(L_CMD, L_V5, "copylength:%d,ictxlen=%d", copylength, ssms->ictxlen);

    memcpy(_ssp->sms_ctx + nDstLength, ssms->readptr, copylength); //内容
    ssms->readptr += copylength;

    nDstLength += copylength;
    LOGD(L_CMD, L_V6, "ssms->encode_ctx=%u", ssms->encode_ctx);

    if(ssms->sms_dir == SMS_SENDER_BOX)
    {
        _ssp->sms_ctx[nDstLength] = 0x1a;
        nDstLength += 1;
    }
    LOGD(L_CMD, L_V5, "nDstLength:%d:%s", nDstLength, _ssp->sms_ctx);
    //LOGH(L_CMD, L_V8, pDst, nDstLength + 1);

    /*  --------------------------------------------------*/
    //经过实际验证发现Unicode发送的长度不是汉字个数而是汉字个数*2

    _ssp->sms_len = (nDstLength - 2) / 2; //-2是开头和结尾两个字节不计
    _ssp->sms_error_conut = 0;
    _ssp->sms_overtime_count = 0;
    _ssp->sms_index = ssms->index;
    _ssp->sms_dir = ssms->sms_dir ;
    _ssp->sp_size = 0;
    _ssp->sms_size = nDstLength;
    _ssp->smscodetype = ssms->smscodetype;
    LOGD(L_CMD, L_V5, "encode pdu:%d,sms size:%d", _ssp->sms_len, _ssp->sms_size);

    return 1;
}

static kal_uint8 track_sms_test_mode(kal_uint8 option)
{
    static kal_uint8 test_on = 0;
    if(option == 0 || option == 1)
    {
        test_on = option;
    }
    return test_on;
}
/******************************************************************************
 * FUNCTION:  - track_encode_number
 * DESCRIPTION: -对电话号码进行转码
 * Input:
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_encode_number(int inlen, kal_uint8 number_type, char * s_nummber, sms_ctx_encode_struct *sces)
{
    kal_uint8 s_temp_numbuf[8] = {0};

    LOGD(L_CMD, L_V5, "org:leng:%d,number:%d,%s", inlen, number_type, s_nummber);

    if(number_type > 0)
    {
        s_temp_numbuf[1] = number_type;
    }
    else if(s_nummber[0] == '+')
    {
        s_temp_numbuf[1] = 0x91;
        inlen -= 1;
        s_nummber += 1;
    }
    else
    {
        s_temp_numbuf[1] = 0x81;
        if(track_sms_test_mode(0xff))
        {
            char number86[32] = {0};
            s_temp_numbuf[1] = 0x91;
            s_temp_numbuf[0] = (char)inlen + 2;       // 目标地址数字个数(TP-DA地址字符串真实长度)
            sces->inumlen = gsmBytes2String(s_temp_numbuf, sces->encode_number, 2, sces->sms_dir); // 转换4个字节到目标PDU串
            snprintf(number86, 32, "86%s", s_nummber);
            LOGD(L_CMD, L_V5, "inumlen:%d,number:%d,%s", sces->inumlen, number86);
            sces->inumlen += gsmInvertNumbers(number86, sces->encode_number + sces->inumlen, inlen + 2, sces->sms_dir); // 转换TP-DA到目标PDU串

            return;
        }
    }

    s_temp_numbuf[0] = (char)inlen;         // 目标地址数字个数(TP-DA地址字符串真实长度)

    sces->inumlen = gsmBytes2String(s_temp_numbuf, sces->encode_number, 2, sces->sms_dir); // 转换4个字节到目标PDU串

    sces->inumlen += gsmInvertNumbers(s_nummber, sces->encode_number + sces->inumlen, inlen, sces->sms_dir); // 转换TP-DA到目标PDU串

    LOGD(L_CMD, L_V6, "decode:%d:%s", sces->inumlen, sces->encode_number);
    LOGH(L_CMD, L_V6, sces->encode_number, sces->inumlen);
}

/******************************************************************************
 * FUNCTION:  - track_encode_ctx
 * DESCRIPTION: -对短信内容进行转码
 * Input:
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_encode_ctx(int i_slen, char * ctx, sms_ctx_encode_struct *sces)
{
    char sctxbuf[512] = {0};

    LOGD(L_CMD, L_V5, "type:%d,%d,dir:%d,decode:%d", sces->smscodetype, i_slen, sces->sms_dir, sces->ictxlen);

    if(sces->smscodetype == GSM_7BIT)
    {
        sces->ictxlen = gsmEncode7bit(ctx, sctxbuf, i_slen + 1) ; // 转换TP-DA到目标PDU
        //LOGD(L_CMD, L_V6, "Length:%d,7bit len:%d", pSrc->TP_UDL, nLength);
        //LOGH(L_CMD, L_V7, &buf[4], nLength);
        //LOGD(L_CMD, L_V6, "Decode:%d,Context:%s", gsmDecode7bit(&buf[4],  pSrc->TP_UD, nLength), pSrc->TP_UD);
        sces->ictxlen = gsmBytes2String(sctxbuf, sces->encode_ctx, sces->ictxlen, sces->sms_dir);        // 转换该段数据到目标PDU串

    }
    else //if (sces->smscodetype == GSM_UCS2)
    {
        //memcpy(sctxbuf,ctx, islen);    // 转换TP-DA到目标PDU串
        //LOGH(L_CMD, L_V7, pSrc->TP_UD, nLength);
        //LOGD(L_CMD, L_V5, "nDstLength:%d,ctx:%d,sms size:%d", nDstLength, nLength, pDst->sms_size);
        sces->ictxlen = gsmBytes2String(ctx, sces->encode_ctx, i_slen, sces->sms_dir);        // 转换该段数据到目标PDU串

    }
}

/******************************************************************************
 * FUNCTION:  - track_sms_sender
 * DESCRIPTION: -发送短信主入口
 * Input:
 * Output:
 * modification history
 * --------------------
 * v1.0  , 26-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sms_sender(sms_msg_struct * sms_send)
{
    int index = 0, inumlength = 0;
    sms_submit_pdu sspdu = {0};
    kal_uint16 sctxlen = 0;
    static kal_uint8 ssms_index = 0x00;
    static char decode_msg[1024] = {0};
    static sms_ctx_encode_struct encode_msg = {0};
    sms_msg_struct ssms = {0};

    if(sms_send == NULL)
    {
        LOGD(L_CMD, L_V5, "sms_send is NULL");
        return;
    }

    LOGD(L_CMD, L_V5, "number len:%d,MAX:%d,status:%d sim:%d,len:%d,num(%d):%s", sms_send->nocount,
         GROUP_SEND_MAX, ssp.sms_status, track_drv_get_sim_type(), sms_send->ctxlen, sms_send->num_type, sms_send->numbers[index]);

    if(SMS_MAX_SIZE < sms_send->ctxlen)
    {
        sms_check_error_notice_app(sCTXTOOLONG, sSTANDBY, sms_send->smsdir, sms_send->index);
        return;
    }
    /*if(track_drv_get_sim_type() != 1)
    {
        sms_check_error_notice_app(sSIMERROR, sSTANDBY, sms_send->smsdir, sms_send->index);
        return;
    }*/

    if(sms_send->nocount > GROUP_SEND_MAX)
    {
        sms_send->nocount = GROUP_SEND_MAX;
        LOGD(L_CON, L_V3, "too many target %d,%d we can support", sms_send->nocount, GROUP_SEND_MAX);
    }

    memset(decode_msg, 0, sizeof(decode_msg));
    memset(&encode_msg, 0, sizeof(sms_ctx_encode_struct));

    if(sms_send->nocount > 0 && sms_send->ctxlen > 0)
    {
        encode_msg.index = sms_send->index;
        encode_msg.sms_dir = sms_send->smsdir;

        if(SMS_MAX_SIZE < sms_send->ctxlen || sms_send->ctxlen > 450 && sms_send->codetype)
        {
            sms_check_error_notice_app(sCTXTOOLONG, sSTANDBY, sms_send->smsdir, sms_send->index);
            return;
        }

        if(sms_send->codetype)
        {
            sms_send->ctxlen = str_to_gsm7str(sms_send->ctx, decode_msg, sms_send->ctxlen);
            sms_send->ctx = decode_msg;
            LOGD(L_CMD, L_V7, "%u,%u", sms_send->ctx, decode_msg);
            encode_msg.ctxlimit = SMS7BITMAX;
            encode_msg.smscodetype = GSM_7BIT;
        }
        else
        {
            encode_msg.smscodetype = GSM_UCS2;
            encode_msg.ctxlimit = SMSUCS2MAX;
        }

        if(sms_send->ctxlen > encode_msg.ctxlimit)
        {
            if(encode_msg.smscodetype == GSM_7BIT)
            {
                encode_msg.ctxlimit = LONG_SMS_7BIT_MAX;
            }
            else
            {
                encode_msg.ctxlimit = LONG_SMS_UCS2_MAX;
            }
            encode_msg.tpacket = sms_send->ctxlen / encode_msg.ctxlimit;
            sctxlen = sms_send->ctxlen % encode_msg.ctxlimit;
            encode_msg.tp_index = ssms_index++;
        }
        else
        {
            encode_msg.tpacket = 0;
            sctxlen = sms_send->ctxlen;
        }

        LOGD(L_CMD, L_V5, "tp_index:%d,tpacket:%d,len:%d", encode_msg.tp_index, encode_msg.tpacket, sctxlen);

        //解出所有内容BUF

        track_encode_ctx(sms_send->ctxlen, sms_send->ctx, &encode_msg);

        for(index = 0; index < sms_send->nocount; index++)
        {
            inumlength = strlen(sms_send->numbers[index]);
            if(inumlength > 25 || inumlength < 2 && sms_send->smsdir == SMS_MS_MT)
            {
                sms_check_error_notice_app(sNUMBERERROR, sSTANDBY, sms_send->smsdir, sms_send->index);
                LOGD(L_CMD, L_V4, "号码%d Worng :%s" , inumlength, sms_send->numbers[index]);
                LOGH(L_CMD, L_V5, sms_send->numbers[index], 20);
                continue;
            }

            //解出号码BUF
            track_encode_number(inumlength, sms_send->num_type, sms_send->numbers[index], &encode_msg);
            //按包拼接发送
            encode_msg.curpacket = 0;
            encode_msg.readptr = encode_msg.encode_ctx;

            while(encode_msg.curpacket <= encode_msg.tpacket)
            {
                if(encode_msg.curpacket == encode_msg.tpacket)
                {
                    encode_msg.sendlen = sctxlen;
                }
                else
                {
                    encode_msg.sendlen = encode_msg.ctxlimit;
                }

                if(encode_msg.sendlen)
                {
                    track_sms_packet(&encode_msg, &sspdu);
                    track_sms_push_submit(&sspdu);
                }
                encode_msg.curpacket ++;
            }

        }

        if(ssp.sms_status == sSTANDBY && track_is_timer_run(TRACK_SMS_SEND_RSP_TIMER_ID) == KAL_FALSE)
        {
            tr_start_timer(TRACK_SMS_SEND_RSP_TIMER_ID, 1000, track_sms_send_req);
        }
        else
        {
            LOGD(L_CMD, L_V5, "等待!正在发送短信.");
        }

    }

}
#if 0
/************************SIM备份部分代码 **********************************
******************************************************************************/
#endif

typedef enum
{
    GET_FROM_HEAD,
    GET_CUR_SMS,
    GET_NEXT,
    GOT_IT,
    SBAE_MAX
} sender_box_action_enum;


static sms_get_senderbox_handlerPtr sms_get_sb_ptr = NULL;


static int tr_sim_pre_get_f_s_b(sender_box_action_enum action);
static void track_sms_backup_decode(int _index, int udl, const char* sms_ctx);

/******************************************************************************
 * FUNCTION:  - sim_read_senderbox_lock
 * DESCRIPTION: -
 *    sim_read_senderbox_lock
 * Returns: 0 解锁 1 上锁  2 查询
 * modification history
 *     60秒超时自动解锁
 * --------------------
 * v1.0  , 07-12-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
kal_uint8 sim_read_senderbox_lock(kal_uint8 arg)
{
    static kal_uint32 tick_over = 0;
    static kal_uint8 rlock = 0;
    kal_uint32 tick = kal_get_systicks();
    if(arg == 0)
    {
        rlock = 0;
        tick = 0;
    }
    else if(arg == 1)
    {
        rlock = 1;
        tick_over = tick + kal_secs_to_ticks(60);
    }
    else if(rlock == 1 && tick_over != 0 && tick > tick_over)
    {
        rlock = 0;
    }
    return rlock;
}

/******************************************************************************
 * FUNCTION:  - gsmDecodePdu *
 * DESCRIPTION: - 短信内容解码
 0891683108200075F12410A821251005810689550000219042906145230D41EA8672A44686CD1EF37904

 *          SCA                  PDUTYPE         OA
    1   0-1     0-10                1       1   0-1     0-10
   len  Type    Addr                        len Type    Addr
 * 08   91      683108200075F1      24      10  A8      2125100581068955

   PID  DCS SCTS            UDL     UD
    1    1   7               1  len 1   data
   00   00  219042906145    23  0D      41EA8672A44686CD1EF37904
---------------------以上为接收到的短信--------------------------
---------------------以下为发件箱的短信--------------------------
 0891683108702505F011FF008100004704C6EA7009
 *          SCA                 PDUTYPE    MR          OA
    1   0-1     0-10            1           1   1   0-1     0-10
   len  Type    Addr                            len Type    Addr
    08  91      683108702505F0  11          FF  00  81

 * PID  VP  DCS UDL     UD
    1    1      len 1   data
    00  00  47  04      C6EA7009
 * --------------------
 * v1.0  , 27-09-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int back_simsms_DecodePdu(const char* pSrc, SM_PARAM* pDst)
{
    int nDstLength;          // 目标PDU串长度
    unsigned char tmp = 0 , tlen = 0;      // 内部用的临时字节变量
    unsigned char bit7smsLen = 0;
    unsigned char buf[SMS_MAX_SIZE]; // 内部用的缓冲区

    /**********SMSC*************/
    tmp = gsm2char_1number(pSrc);    // 取长度
    pSrc += 2; //SCA Type
    if(tmp > 0)
    {
        tmp = tmp * 2;    // SMSC号码串长度
        gsmSerializeNumbers(pSrc, pDst->SCA, tmp);    // 转换SMSC号码到目标PDU串
        pSrc += tmp;
    }
    /********end SMSC**********/
    //0891683108702505F011FF008100004704C6EA7009
    /**********P_TYPE*************/
    pDst->P_TYPE = gsm2char_1number(pSrc);
    pSrc += 2;
    /********end P_TYPE**********/

    pSrc += 2; //MR

    /********DA*********/

    pDst->ODAL = gsm2char_1number(pSrc);

    if(pDst->ODAL > 0)
    {
        if(pDst->ODAL & 1)
        {
            pDst->ODAL += 1;   // 调整奇偶性
        }
        pSrc += 2;
        tmp = gsm2char_1number(pSrc);

        pSrc += 2;
        if((tmp & 0xf0) == 0x90)
        {
            pDst->TPA[0] = '+';
            gsmSerializeNumbers(pSrc, &pDst->TPA[1], pDst->ODAL);
        }
        else
        {
            gsmSerializeNumbers(pSrc, &pDst->TPA[0], pDst->ODAL);
        }

        pSrc += pDst->ODAL;
    }
    else
    {
        pSrc += 4;//0081
    }

    /********end OA**********/
    pDst->TP_PID = gsm2char_1number(pSrc);
    pSrc += 2;
    pDst->TP_DCS = gsm2char_1number(pSrc);
    pSrc += 2;
    //gsmSerializeNumbers(pSrc, &pDst->TP_SCTS[0], 14);
    //pSrc += 14;

    pSrc += 2;//VP

    tmp = gsm2char_1number(pSrc);// 用户信息长度(TP-UDL)
    pSrc += 2;

    LOGD(L_CMD, L_V6, "PID:%d,DCS:%d,,UDL:%d", pDst->TP_PID, pDst->TP_DCS, tmp);
    memset(buf, 0, sizeof(buf));

    /*05 00 03 00 02 02*/
    if(pDst->P_TYPE & 0x40)
    {
        tlen = gsm2char_1number(pSrc);// (TP-UDL)
        tmp -= (tlen + 1);

        pSrc += 2;
        LOGD(L_CMD, L_V5, "is long sms:%d", tmp);

        pSrc += 2;
        tlen = gsm2char_1number(pSrc);// (last length)

        pSrc += 2;
        if(tlen == 4)
        {
            tlen = gsm2char_1number(pSrc);// (TP-unique1)
            pDst->TP_Unique = tlen;
            pSrc += 2;
        }

        tlen = gsm2char_1number(pSrc);// (TP-unique2)

        pSrc += 2;
        pDst->TP_Unique += tlen;
        tlen = gsm2char_1number(pSrc);// (TP-UDL)
        pDst->TP_Max_p = tlen;

        pSrc += 2;
        tlen = gsm2char_1number(pSrc);// (TP_Max_p)
        pDst->TP_Seq_p = tlen;

        pSrc += 2;
        LOGD(L_CMD, L_V5, "TP_index:%d,TP_Max_p=%d,TP_Seq_p=%d", pDst->TP_Unique, pDst->TP_Max_p, pDst->TP_Seq_p);

    }

    if(pDst->TP_DCS == GSM_7BIT)
    {
        memset(pDst->TP_UD, 0, SMS_MAX_SIZE);
        if(tmp & 7)
        {
            bit7smsLen = (int)tmp * 7 / 4 + 2;
        }
        else
        {
            bit7smsLen = (int)tmp * 7 / 4;
        }
        //nDstLength = gsmString2Bytes(pSrc, buf, tmp & 7 ? (int)tmp * 7 / 4 + 2 : (int)tmp * 7 / 4);nDstLength = gsmString2Bytes(pSrc, buf, tmp & 7 ? (int)tmp * 7 / 4 + 2 : (int)tmp * 7 / 4);
        nDstLength = gsmString2Bytes(pSrc, buf, bit7smsLen);
        nDstLength = gsmDecode7bit(buf, pDst->TP_UD, tmp);

        tmp = str_from_gsm7str(pDst->TP_UD, buf, tmp);
        nDstLength = tmp;
        memset(pDst->TP_UD, 0, SMS_MAX_SIZE);
        memcpy(pDst->TP_UD, buf, tmp);

    }
    else if(pDst->TP_DCS == GSM_UCS2)
    {
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);
        memcpy(pDst->TP_UD, buf, nDstLength);
        //LOG_UNI(L_CMD,L_V2,pDst->TP_UD,nDstLength);
        LOGH(L_CMD, L_V6, pDst->TP_UD, nDstLength);

    }
    else
    {
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);
        memcpy(pDst->TP_UD, buf, nDstLength);
        LOGD(L_CMD, L_V5, "GSM8:%s", pDst->TP_UD);

    }
    pDst->TP_UDL = nDstLength;

    return nDstLength;
}
/******************************************************************************
 * FUNCTION:  - track_sim_sms_set_revicer
 * DESCRIPTION: -设置备份短信处理接口

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_sms_set_revicer(sms_get_senderbox_handlerPtr callback)
{
    sms_get_sb_ptr = callback;
    LOGD(L_CMD, L_V5, "%u", callback);
}


#if 1
static c_vector* vec_outbox = NULL;

static void out_sms_push(SM_PARAM * get_out_sms)
{

    if(NULL == vec_outbox)
    {
        VECTOR_CreateInstance(vec_outbox);
    }

    if(get_out_sms)
    {
        VECTOR_PushBack(vec_outbox, get_out_sms);
    }
    else
    {
        LOGD(L_CON, L_V5, "空out sms:");
    }

    LOGD(L_CMD, L_V7, "vector_size:%d", VECTOR_Size(vec_outbox));

}
/******************************************************************************
 * FUNCTION:  - out_sms_fatch
 * DESCRIPTION: -读取短信队列

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void out_sms_fatch(SM_PARAM * get_outsms)
{
    SM_PARAM * vec_sms = NULL;
    if(NULL == vec_outbox)
    {
        VECTOR_CreateInstance(vec_outbox);
    }
    else if(VECTOR_Size(vec_outbox))
    {
        vec_sms = VECTOR_At(vec_outbox, 0);
        if(vec_sms)
        {
            memcpy(get_outsms, vec_sms, sizeof(SM_PARAM));
            VECTOR_Erase(vec_outbox, 0, 1);
            Ram_Free(vec_sms);
            vec_sms = NULL;
        }
        else
        {
            LOGD(L_CON, L_V3, "VECTOR_At == NULL!!!!!ERROR");
            VECTOR_Erase(vec_outbox, 0, 1);
            get_outsms->TP_UDL = 0;
            get_outsms->TP_DCS = 0;
        }

    }
    else
    {
        get_outsms->TP_UDL = 0;
        get_outsms->TP_DCS = 0;
    }
    LOGD(L_CMD, L_V7, "vector_size:%d,at:%d", VECTOR_Size(vec_outbox), get_outsms->TP_UDL);

}

void track_sms_clean_out_vec(void)
{
    LOGD(L_CMD, L_V4, "清%u", vec_outbox);
    if(vec_outbox)
    {
        while(get_vec_out_size())
        {
            SM_PARAM * vec_sms = NULL;
            vec_sms = VECTOR_At(vec_outbox, 0);
            VECTOR_Erase(vec_outbox, 0, 1);
            if(vec_sms)
            {
                Ram_Free(vec_sms);
                vec_sms = NULL;
            }
        }
    }
}

int get_vec_out_size(void)
{
    if(vec_outbox == NULL)
    {
        return 0;
    }
    return VECTOR_Size(vec_outbox);
}

int track_sms_get_out_sms(SM_PARAM * get_outsms)
{
    int vec_out_size =  get_vec_out_size();
    memset(get_outsms, 0, sizeof(SM_PARAM));

    if(vec_out_size)
    {
        out_sms_fatch(get_outsms);
    }
    return vec_out_size;
}
#endif
/******************************************************************************
 * FUNCTION:  - track_sms_backup_decode
 * DESCRIPTION: -备份信息解码

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static void track_sms_backup_decode(int _index, int udl, const char* sms_ctx)
{
    SM_PARAM *sms_get = NULL;
    //static sms_msg_struct ssms = {0};

    LOGD(L_CMD, L_V5, "解%s", sms_ctx);

    if(sms_ctx == NULL)
    {
        return;
    }

    sms_get = (SM_PARAM*)Ram_Alloc(2, sizeof(SM_PARAM));
    memset(sms_get, 0, sizeof(SM_PARAM));

    if(sms_get == NULL)
    {
        LOGD(L_CON, L_V4, "cannt get rambuffer ");
    }
    else if(_index == udl && udl == 0)
    {
        sms_get->TP_UDL = 0;
        sms_get->index = _index;
    }
    else
    {
        back_simsms_DecodePdu(sms_ctx, sms_get);
        sms_get->index = _index;
    }

    LOGD(L_CMD, L_V6, "index:%d,DSC:%d,UDL:%d,%s", sms_get->index, sms_get->TP_DCS, sms_get->TP_UDL, sms_get->TP_UD);


    if(sms_get_sb_ptr)
    {
        out_sms_push(sms_get);
    }
    else
    {
        Ram_Free(sms_get);
        sms_get = NULL;
    }

    LOGD(L_CMD, L_V5, "vec_out_size:%d,%u", get_vec_out_size(), sms_get_sb_ptr);
    //sim_read_senderbox_lock(0);
}
/******************************************************************************
 * FUNCTION:  - track_sim_clean_allsms
 * DESCRIPTION: - 清空所有短信

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * v1.1  , 04-11-2013,  jiangweijun && wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_clean_allsms(void)
{
    char cleanrev[] = "AT+CMGD=0,4\r\n";
    LOGD(L_CMD, L_V5, "");
    track_at_vs_send(cleanrev);
}
/******************************************************************************
 * FUNCTION:  - track_sim_clean_read_sms_reveicebox
 * DESCRIPTION: - 清空收件箱已读短信

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * v1.1  , 04-11-2013,  jiangweijun && wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_clean_read_sms_reveicebox(void)
{
    char cleanrev[] = "AT+CMGD=0,2\r\n";
    LOGD(L_CMD, L_V5, "");
    track_at_vs_send(cleanrev);
}
/******************************************************************************
 * FUNCTION:  - track_sim_read_unreadsms_reveicebox
 * DESCRIPTION: - 读取收件箱未读短信，会将未读短信置为已读短信

 * modification history
 * --------------------
 * v1.0  , 04-11-2013,  jiangweijun && wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_read_unreadsms_reveicebox(void)
{
    char cleanrev[] = "AT+CMGL=0\r\n";
    LOGD(L_CMD, L_V5, "");
    track_at_vs_send(cleanrev);
}
/******************************************************************************
 * FUNCTION:  - track_sim_clean_reveicebox
 * DESCRIPTION: - 清空收件箱短信，将所有未读置为已读然后全部删除

 * modification history
 * --------------------
 * v1.0  , 04-11-2013,  jiangweijun && wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_clean_reveicebox(void)
{
    LOGD(L_CMD, L_V5, "");
    track_sim_read_unreadsms_reveicebox();
    tr_start_timer(TRACK_CUST_CLEAN_SMS_TIMER, 20 * 1000, track_sim_clean_read_sms_reveicebox);//60
}

/******************************************************************************
 * FUNCTION:  - track_sim_clean_senderbox
 * DESCRIPTION: - 清空发件箱

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_clean_senderbox(void)
{
    char clean[] = "AT+CMGD=0,3\r\n";
    LOGD(L_CMD, L_V5, "");
    track_at_vs_send(clean);
}
/******************************************************************************
 * FUNCTION:  - track_sim_del_sms_byid_sb
 * DESCRIPTION: -按编号删除短信

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_del_sms_byid_sb(int index)
{
    char delsms[25] = {0};
    snprintf(delsms, 25, "AT+CMGD=%d\r\n", index);
    LOGD(L_CMD, L_V5, "%s", delsms);

    track_at_vs_send(delsms);
}
/******************************************************************************
 * FUNCTION:  - track_sim_get_sms_from_senderbox
 * DESCRIPTION: - 读取SIM卡草稿箱

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_get_all_senderbox(void)
{
    char getsms[] = "AT+CMGL=2\r\n";
    LOGD(L_CMD, L_V4, "读发件箱");
    track_at_vs_send(getsms);
}
/******************************************************************************
 * FUNCTION:  - track_sim_get_sms_from_senderbox
 * DESCRIPTION: - 读取SIM卡草稿箱

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
kal_uint8 track_sim_get_sms_from_senderbox(void)
{
    LOGD(L_CMD, L_V4, "");
    if(sim_read_senderbox_lock(2) || track_drv_get_sim_type() != 1)
    {
        LOGD(L_CMD, L_V4, "lock");
        return 1;
    }
    else
    {
        sim_read_senderbox_lock(1);
    }

    track_sim_get_all_senderbox();
    return 0;
}


int string_split(char * str, char ch, char *args[], int arglen)
{
    int count = 0;
    args[count] = str;
    while(*str && count < arglen)
    {
        if(*str == ch)
        {
            *str = 0;
            count++;
            args[count] = str + 1;
        }

        str ++;
    }
    return count;
}

/******************************************************************************
 * FUNCTION:  - split_at_cmgr
 * DESCRIPTION: - 分隔读出的短信

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
static int split_at_cmgr(char * ptrcmgl)
{
    char * cptr0d = NULL, *cptr_end = NULL;
    char *args[] = {0, 0, 0, 0};
    int s_type = 0 , sms_udl = 0 , msg_index = 0;

    /*+CMGL: 5, 2,, 145*/
    if(cptr0d = strstr(ptrcmgl, "\r"))
    {
        *cptr0d = 0;

        if((s_type = string_split(ptrcmgl, ',', args, 4)) != 3)
        {
            LOGD(L_CMD, L_V5, "got args error:%d,%s,%s", s_type, args[0], args[1]);
        }
        else if((msg_index = track_fun_parset_int_skip_space(args[0])) < 0)
        {
            LOGD(L_CON, L_V5, "!!oh shit,cmgl index error %d", s_type, sms_udl, args[0]);
        }
        else if((s_type = track_fun_parset_int_skip_space(args[1])) != 2)
        {
            LOGD(L_CMD, L_V5, "is not senderbox sms <---");
        }
        else if((sms_udl = track_fun_parset_int_skip_space(args[3])) < 0)
        {
            LOGD(L_CON, L_V5, "!!oh shit,agrs error type:%d,udl:%d,args0:%s,args2:%s", s_type, sms_udl, args[0], args[2]);
        }
        else
        {
            LOGD(L_CMD, L_V5, "args[0]:%s,args[2]:%s", args[0], args[3]);
            cptr0d += 2;
            cptr_end = strstr(cptr0d, "\r");
            if(cptr_end)
            {
                *cptr_end = 0;
                LOGD(L_CON, L_V7, "bingo:%s", cptr0d);
                track_sms_backup_decode(msg_index, cptr_end - cptr0d, cptr0d);
                return 1;
            }
            else
            {
                LOGD(L_CON, L_V5, "3 oh shit,where is pdu end eof");
            }
        }
    }
    else
    {
        LOGD(L_CON, L_V5, "!!oh shit,where is the \\r\\n?");
    }
    return 0;
}
/******************************************************************************
 * FUNCTION:  - track_sim_get_sms_f_s_b_rsp
 * DESCRIPTION: - 获取发件箱短信AT层返回数据
AT+CMGR=1

+CMGR: 2,, 12
0891683108702505F011FF008100004704C6EA7009

OK
 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_sim_get_sms_f_s_b_rsp(int type, char * cmgl)
{
    char * cptr = NULL, *cptr1 = NULL;
    int s_type = 0 , read_sms = 0, ret = 0;

    LOGD(L_CMD, L_V5, "type:%d,收1:{%s}", type, cmgl);


    if(1 == type)
    {
        cptr = strstr(cmgl, "+CMGL:");
        while(cptr)
        {
            if(++read_sms > SMS_SENDER_BOX_LENGTH)
            {
                break;
            }

            cptr1 = cptr + 6;

            cptr = strstr(cptr1, "+CMGL:"); //先查找下一个CMGL:

            ret = split_at_cmgr(cptr1);

            LOGD(L_CMD, L_V5, "read sms:%d,ret:%d,cmgl:%p,%p", read_sms, ret, cptr1, cptr);
        }

    }

    sim_read_senderbox_lock(0);

    if(0 == type && track_is_timer_run(TRACK_OUTBOX_CALLBACK_TIMER_ID))
    {
        return;
    }

    if(sms_get_sb_ptr)
    {
        tr_start_timer(TRACK_OUTBOX_CALLBACK_TIMER_ID, 3000, sms_get_sb_ptr); /*通知注册函数*/
    }
    else
    {
        LOGD(L_CMD, L_V5, "vec_out_size:%d CallBack is NULL******", get_vec_out_size());
    }
}

/******

******/

/******************************************************************************
 * FUNCTION:  - l4c_send_2mmi_sms_new_msg_text_lind
 * DESCRIPTION: - 拦截L4C短信

 * modification history
 * --------------------
 * v1.0  , 21-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void l4c_send_2mmi_sms_new_msg_text_lind(kal_uint16 index,
        kal_uint16 dest_port,
        kal_uint16 src_port,
        kal_uint8 mti,
        kal_uint8 display_type,
        kal_uint8 storage_type,
        smsal_concat_struct *concat_info,
        kal_uint16 message_len,
        void *msg_header,
        void *data)
{
#ifndef SMS_FOR_NEPTUNE
    {
        msg_type msg_id = MSG_ID_MMI_L4_CODE_BEGIN;
        void *pp = NULL;

        /*kevin--begin*/
        l4c_number_struct *addr_num1 = NULL;
        l4c_number_struct *addr_num2 = NULL;
        l4_addr_bcd_struct *addr_bcd1 = NULL;
        l4_addr_bcd_struct *addr_bcd2 = NULL;
        /*kevin--end*/

        switch(mti)
        {
            case(SMSAL_MTI_DELIVER):
                {
                    mmi_sms_deliver2_msg_ind_struct *p;
                    smsal_deliver_msg_hdr_struct *msg_p = (smsal_deliver_msg_hdr_struct*)msg_header;

                    msg_id = MSG_ID_MMI_SMS_DELIVER_MSG_IND;/* Set the message id */

                    p = (mmi_sms_deliver2_msg_ind_struct*) construct_local_para(
                        (kal_uint16)(sizeof(mmi_sms_deliver2_msg_ind_struct)), TD_RESET);
                    p->index = index;
                    p->dest_port = dest_port;
                    p->src_port = src_port;
                    p->display_type = display_type;
                    p->storage_type = storage_type;
                    p->mti = mti;
                    p->fo = msg_p->fo;
                    if(msg_p->scts) memcpy(p->scts, msg_p->scts, 7);

                    /*kevin--start*/
                    addr_num1 = &p->sca_number;
                    addr_num2 = &p->oa_number;
                    /*kevin--end*/


                    /* kevin -- start */
                    addr_bcd1 = &msg_p->sca;
                    addr_bcd2 = &msg_p->oa;
                    /* kevin -- end */

                    memcpy(&(p->concat_info), concat_info, sizeof(smsal_concat_struct));

                    p->pid = msg_p->pid;
                    p->dcs = msg_p->dcs;
                    p->ori_dcs = msg_p->ori_dcs;
                    p->no_msg_data = message_len;
                    LOGD(L_CMD, L_V5, "新短信 pid:%d, dcs:%d, ori_dcs:%d, concat_info(ref:%d, total_seg:%d, seg:%d), message_len:%d",
                    p->pid, p->dcs, p->ori_dcs,
                    p->concat_info.ref,
                    p->concat_info.total_seg,
                    p->concat_info.seg,
                    message_len);
                    if(message_len) memcpy(p->msg_data, data, message_len);
                    if(GSM_8BIT == p->dcs)
                    {
                        LOGD(L_CMD, L_V5, "msg_data:%s", p->msg_data);
                    }
                    LOGH(L_CMD, L_V5, p->msg_data , message_len);
                    pp = p;
                    break;
                }
            case(SMSAL_MTI_STATUS_REPORT):
                {
                    mmi_sms_status_report_ind_struct *p;
                    smsal_status_report_msg_hdr_struct *msg_p = (smsal_status_report_msg_hdr_struct*)msg_header;

                    msg_id = MSG_ID_MMI_SMS_STATUS_REPORT_IND;/* Set the message id */

                    p = (mmi_sms_status_report_ind_struct*) construct_local_para(
                        (kal_uint16)(sizeof(mmi_sms_status_report_ind_struct)), TD_RESET);
                    p->fo = msg_p->fo;
                    //p->mr = msg_p->mr;
                    if(msg_p->scts) memcpy(p->scts, msg_p->scts, 7);
                    if(msg_p->dt) memcpy(p->dt  , msg_p->dt, 7);

                    addr_num1 = &p->ra_number;/*kevin*/

                    //memcpy(&(p->ra),&(msg_p->ra),sizeof(l4_addr_bcd_struct));
                    addr_bcd1 = &msg_p->ra;/*kevin*/

                    p->st = msg_p->st;
                    p->pid = msg_p->pid;
                    p->dcs = msg_p->dcs;
                    p->no_msg_data = message_len;
                    LOGD(L_CMD, L_V5, "短信发送反馈message_len:%d", message_len);
                    if(message_len > 0 && message_len < 160) memcpy(p->msg_data, data, message_len);
                    p->mr = msg_p->mr;

                    pp = p;
                    break;
                }
            case(SMSAL_MTI_UNSPECIFIED)://      = 0x03,  /* MMI shall handle this case,
                //* eg, displaying "does not support", or "cannot display", etc */
                {
                    LOGD(L_CON, L_V4, "@@@SMSAL_MTI_UNSPECIFIED @@@");
                }
                break;
            case(SMSAL_MTI_ILLEGAL)://          = 0x04
                {
                    LOGD(L_CON, L_V4, "@@@SMSAL_MTI_ILLEGAL@@@");
                }
                break;


            default:
                ASSERT(0);/*kevin*/
                break;
        }


        /* add l4c_number_struct address modified by kevin -- begin */
        /* address1 */
        if(addr_num1)
        {
            if(addr_bcd1->addr_length > 0)
                addr_num1->type = addr_bcd1->addr_bcd[0];

            /*Brad Begin*/
            if((addr_num1->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
            {
                if(addr_bcd1->addr_length > 1)
                {
                    kal_uint8 temp[41];
                    kal_uint16 out_len;

                    addr_num1->length = smsal_msg_len_in_character(0,
                    (kal_uint16)(addr_bcd1->addr_length - 1),
                    addr_bcd1->addr_bcd[addr_bcd1->addr_length - 1]);

                    smsal_gsm7_unpack((kal_uint8 *) & (addr_bcd1->addr_bcd[1]),
                    (kal_uint8 *)addr_num1->number,
                    addr_num1->length,
                    0);

                    l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, addr_num1->number, (kal_uint16)addr_num1->length, &out_len);
                    kal_mem_cpy(addr_num1->number, temp, out_len);
                    addr_num1->number[out_len] = 0x00;
                    addr_num1->length = out_len;

                }
                else
                {
                    addr_num1->length = 0;
                }

            }
            /*Brad End*/
            else
            {
                if(addr_bcd1->addr_length > 1)
                {
                    addr_num1->length = OTA_convert_to_digit((kal_uint8 *) & (addr_bcd1->addr_bcd[1]),
                    (kal_uint8 *)addr_num1->number);
                }
                else
                {
                    addr_num1->length = 0;
                }
            }
            LOGD(L_CMD, L_V5, "sca length:%d, type:%d, number:%s",
            addr_num1->length, addr_num1->type, addr_num1->number);
        }
        /* address2 */
        if(addr_num2)
        {
            if(addr_bcd2->addr_length > 0)
                addr_num2->type = addr_bcd2->addr_bcd[0];

            /*Brad Begin*/
            if((addr_num2->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
            {
                if(addr_bcd2->addr_length > 1)
                {
                    kal_uint8 temp[41];
                    kal_uint16 out_len;

                    //addr_num2->length = smsal_msg_len_in_character(0,
                    //                       (kal_uint16)(addr_bcd2->addr_length-1),
                    //                       addr_bcd2->addr_bcd[addr_bcd2->addr_length-1]);

                    //smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                    //  	(kal_uint8 *)addr_num2->number,
                    //  	addr_num2->length,
                    //  	0);

                    l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, (kal_uint8 *) & (addr_bcd2->addr_bcd[1]), (kal_uint16)addr_bcd2->addr_length - 1, &out_len);
                    kal_mem_cpy(addr_num2->number, temp, out_len);
                    addr_num2->number[out_len] = 0x00;
                    addr_num2->length = out_len;

                }
                else
                {
                    addr_num2->length = 0;
                }

            }
            /*Brad End*/
            else
            {
                if(addr_bcd2->addr_length > 1)
                {
                    addr_num2->length = OTA_convert_to_digit((kal_uint8 *) & (addr_bcd2->addr_bcd[1]), (kal_uint8 *)addr_num2->number);
                }
                else
                {
                    addr_num2->length = 0;
                }
            }

            LOGD(L_CMD, L_V5, "oa length:%d, type:%d, number:%s",
            addr_num2->length, addr_num2->type, addr_num2->number);
        }


        //l4a_sendmsg_ilm_to_MMI(msg_id, pp);
        if(pp)
        {
            track_l4c_send_msg_track_mmi(msg_id, pp, NULL);
        }
    }
    /* kevin -- end */
#endif

}

/******************************************************************************
 *  Function    -  track_sms_long_sms_overtime
 *
 *  Purpose     -  长短信未能完整接收的超时函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_sms_long_sms_overtime(void)
{
    LOGD(L_CMD, L_V5, "长短信未能完整接收");
}

/******************************************************************************
 *  Function    -  track_sms_status_deliver_lind
 *
 *  Purpose     -  短信内容上报处理函数
 *
 *  Description -  //index:1, mti:0, dcs:0, number(129,5):66855,
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_sms_status_deliver_lind(void * msg)
{
    track_sms_param *sms_rev = NULL;
    smsal_concat_struct *concat_info;
    kal_uint8 long_sms_head = 6;

    mmi_sms_deliver2_msg_ind_struct *ptr = (mmi_sms_deliver2_msg_ind_struct *) msg;

    LOGD(L_CMD, L_V5, "index:%d, mti:%d, dcs:%d, number(%d,%d):%s, (ref:%d, seg/total:%d/%d)",
         ptr->index, ptr->mti, ptr->dcs,  ptr->oa_number.type, ptr->oa_number.length, ptr->oa_number.number,
         ptr->concat_info.ref, ptr->concat_info.seg, ptr->concat_info.total_seg);
    if(GSM_7BIT == ptr->dcs)
    {
        LOGD(L_CMD, L_V5, "UD:%s", ptr->msg_data);
    }


    if(ptr->concat_info.total_seg > 1)
    {
        static mmi_sms_delivers_struct sms_long = {0};
        if(ptr->concat_info.total_seg > 16 || ptr->concat_info.seg > 16)
        {
            LOGD(L_CMD, L_V1, "ERROR: Maybe this message is too long !! %d,%d", ptr->concat_info.seg, ptr->concat_info.total_seg);
            return;
        }
        if(ptr->concat_info.seg > ptr->concat_info.total_seg)
        {
            LOGD(L_CMD, L_V1, "ERROR: Bad Boy!!seg:%d, total_seg:%d", ptr->concat_info.seg , ptr->concat_info.total_seg);
            return;
        }
        if(sms_long.count > 0 && ptr->concat_info.ref != sms_long.concat_info.ref)
        {
            LOGD(L_CMD, L_V1, "ERROR: count:%d, ref:%d,%d", sms_long.count, ptr->concat_info.ref , sms_long.concat_info.ref);
        }
        if(sms_long.count > 0 && ptr->concat_info.total_seg != sms_long.concat_info.total_seg)
        {
            LOGD(L_CMD, L_V1, "ERROR: count:%d, total_seg:%d,%d", sms_long.count, ptr->concat_info.total_seg , sms_long.concat_info.total_seg);
            return;
        }
        if(sms_long.count == 0 || ptr->concat_info.ref != sms_long.concat_info.ref)
        {
            int i;
            for(i = 0; i < 16; i++)
            {
                if(sms_long.pdata[i] != NULL)
                {
                    Ram_Free(sms_long.pdata[i]);
                }
            }
            memset(&sms_long, 0, sizeof(mmi_sms_delivers_struct));
            sms_long.fo = ptr->fo;
            memcpy(sms_long.scts, ptr->scts, 7);
            memcpy(&sms_long.sca_number, &ptr->sca_number, sizeof(l4c_number_struct));
            memcpy(&sms_long.oa_number, &ptr->oa_number, sizeof(l4c_number_struct));
            sms_long.pid = ptr->pid;
            sms_long.dcs = ptr->dcs;
            sms_long.ori_dcs = ptr->ori_dcs;
            sms_long.index = ptr->index;
            sms_long.dest_port = ptr->dest_port;
            sms_long.src_port = ptr->src_port;
            sms_long.display_type = ptr->display_type;
            sms_long.storage_type = ptr->storage_type;
            memcpy(&sms_long.concat_info, &ptr->concat_info, sizeof(smsal_concat_struct));
            //sms_submit_pdu *tem_sms = (sms_submit_pdu*)Ram_Alloc(2, sizeof(sms_submit_pdu));
        }
        if(sms_long.count < ptr->concat_info.total_seg)
        {
            LOGD(L_CMD, L_V6, "add sms vec %d", sms_long.count);
            sms_long.count++;
            if(GSM_7BIT == ptr->dcs)
            {
                sms_long.pdata[ptr->concat_info.seg - 1] = (kal_uint8 *)Ram_Alloc(2, 320);
                if(sms_long.pdata[ptr->concat_info.seg - 1] == NULL)
                {
                    return;
                }
                l4c_ConvertGSM7BitDefaultEncodingToAscii(
                    sms_long.pdata[ptr->concat_info.seg - 1],
                    ptr->msg_data, ptr->no_msg_data,
                    &sms_long.data_len[ptr->concat_info.seg - 1]);
                if(320 < sms_long.data_len[ptr->concat_info.seg - 1])
                {
                    track_cust_restart(60, 0);
                }
            }
            else
            {
                sms_long.pdata[ptr->concat_info.seg - 1] = (kal_uint8 *)Ram_Alloc(2, ptr->no_msg_data);
                if(sms_long.pdata[ptr->concat_info.seg - 1] == NULL)
                {
                    return;
                }
                memcpy(sms_long.pdata[ptr->concat_info.seg - 1], ptr->msg_data, ptr->no_msg_data);
                sms_long.data_len[ptr->concat_info.seg - 1] = ptr->no_msg_data;
            }
        }
        if(sms_long.count >= ptr->concat_info.total_seg)
        {
            int sumsize, i;
            kal_uint8 head_len;
            sms_rev = (track_sms_param*)Ram_Alloc(2, sizeof(track_sms_param) + ptr->concat_info.total_seg * 150);
            if(sms_rev == NULL)
            {
                LOGD(L_CON, L_V4, "cannt get rambuffer %d", sizeof(track_sms_param) + ptr->concat_info.total_seg * 150);
                track_cust_restart(62, 0);
                return;
            }
            sms_rev->TP_UD = (char *)sms_rev + sizeof(track_sms_param);
            for(i = 0; i < 16; i++)
            {
                if(ptr->concat_info.total_seg * 150 < sms_rev->TP_UDL + sms_long.data_len[i])
                {
                    LOGD(L_CMD, L_V1, "ERROR: %d", sms_rev->TP_UDL + sms_long.data_len[i]);
                    track_cust_restart(61, 0);
                    return;
                }
                if(sms_long.pdata[i] != NULL)
                {
                    head_len = sms_long.pdata[i][0] + 1;
                    memcpy(&sms_rev->TP_UD[sms_rev->TP_UDL], &sms_long.pdata[i][head_len], sms_long.data_len[i] - head_len);
                    sms_rev->TP_UDL += sms_long.data_len[i] - head_len;
                    Ram_Free(sms_long.pdata[i]);
                }
            }
            sms_rev->index =  ptr->index;
            sms_rev->TP_DCS = ptr->dcs;
            /*if(GSM_7BIT == ptr->dcs)
            {
                sms_rev.TP_DCS = GSM_8BIT;
            }*/
            sms_rev->P_TYPE = ptr->oa_number.type;
            sms_rev->ODAL =  ptr->oa_number.length;
            memcpy(&sms_rev->TPA[0], ptr->oa_number.number, 31);
            sms_rev->TP_Unique = ptr->concat_info.ref;
            track_app_receive_sms(sms_rev);
            Ram_Free(sms_rev);
            memset(&sms_long, 0, sizeof(mmi_sms_delivers_struct));
            tr_stop_timer(TRACK_SMS_WAIT_LONG_SMS_TIME_ID);
        }
        else
        {
            LOGD(L_CMD, L_V6, "wait next sms: %d,%d", sms_long.count, ptr->concat_info.total_seg);
            tr_start_timer(TRACK_SMS_WAIT_LONG_SMS_TIME_ID, 20 * 1000, track_sms_long_sms_overtime);
        }
    }
    else
    {
        sms_rev = (track_sms_param*)Ram_Alloc(2, sizeof(track_sms_param) + 280);
        if(sms_rev == NULL)
        {
            LOGD(L_CON, L_V4, "cannt get rambuffer %d", sizeof(track_sms_param) + 280);
            return;
        }
        sms_rev->TP_UD = (char *)sms_rev + sizeof(track_sms_param);
        sms_rev->index =  ptr->index;
        sms_rev->P_TYPE = ptr->oa_number.type;
        sms_rev->ODAL =  ptr->oa_number.length;
        memcpy(&sms_rev->TPA[0], ptr->oa_number.number, 31);
        sms_rev->TP_Unique = ptr->concat_info.ref;
        sms_rev->TP_DCS = ptr->dcs;
        LOGH(L_CMD, L_V6, ptr->msg_data, ptr->no_msg_data);
        if(GSM_7BIT == ptr->dcs)
        {
            l4c_ConvertGSM7BitDefaultEncodingToAscii(
                sms_rev->TP_UD,
                ptr->msg_data, ptr->no_msg_data,
                &sms_rev->TP_UDL);
        }
        else
        {
            sms_rev->TP_UDL = ptr->no_msg_data;
            memcpy(sms_rev->TP_UD, ptr->msg_data, sms_rev->TP_UDL);
        }
        LOGH(L_CMD, L_V6, sms_rev->TP_UD, sms_rev->TP_UDL);
        track_app_receive_sms(sms_rev);
        Ram_Free(sms_rev);
    }
    //track_sim_clean_allsms();  // ? 有存SIM卡?
    {
        track_sim_del_sms_byid_sb(ptr->index + 1);
		//track_os_intoTaskMsgQueue(track_sim_read_unreadsms_reveicebox);//每次来短信，都处理一次标记已读短信
		tr_start_timer(TRACK_CUST_UNREAD_SMS_CHECK_ONE_TIMER_ID, 2000, track_sms_clean_all_by_id);
    }
}

/******************************************************************************
 *  Function    -  track_sms_status_report_lind
 *
 *  Purpose     -  短信状态回执
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 23-08-2013,  wangqi  written ps_cause_enum
 * ----------------------------------------
*******************************************************************************/
void track_sms_status_report_lind(void * msg)
{
    mmi_sms_status_report_ind_struct *ptr = (mmi_sms_status_report_ind_struct *) msg;

    LOGH(L_CMD, L_V5, ptr->scts, 7);
    LOGH(L_CMD, L_V5, ptr->msg_data, ptr->no_msg_data);

    LOGD(L_CMD, L_V5, "fo:%d, mr:%d, st:%d, dcs:%d, pid:%d,length:%d",
         ptr->fo, ptr->mr, ptr->st, ptr->dcs, ptr->pid, ptr->no_msg_data);

    //track_sms_send_rsp(0);

}

/******************************************************************************
 *  Function    -  track_sms_mem_full_lind
 *
 *  Purpose     -  短信箱满的信息状态处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 04-11-2013,  jiangweijun && wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_sms_mem_full_lind(void * msg)
{
    mmi_sms_mem_full_ind_struct *ptr = (mmi_sms_mem_full_ind_struct *)msg;
    LOGD(L_CMD, L_V5, "%d", ptr->type);
    if(0 == ptr->type)//短信已满清空已读的同时，延时全清
    {
        //track_sim_clean_allsms();//清空所有短信，IMEI备份的短信也将被删除
        track_sim_clean_reveicebox();
		tr_start_timer(TRACK_CUST_UNREAD_SMS_CHECK_TWO_TIMER_ID, 2*60*1000, track_sms_clean_all_sms_by_timing);
    }
}

void track_sms_clean_all_sms_by_timing()
{
	//3小时清理一次
    LOGD(L_CMD, L_V5, "");
	track_sim_clean_allsms();
	tr_start_timer(TRACK_CUST_UNREAD_SMS_CHECK_TWO_TIMER_ID, 180*60*1000, track_sms_clean_all_sms_by_timing);
}
void track_sms_clean_all_by_id()
{
    LOGD(L_CMD, L_V5, "");

	track_sim_read_unreadsms_reveicebox();
	if(!track_is_timer_run(TRACK_CUST_UNREAD_SMS_CHECK_THREE_TIMER_ID))
	{
		tr_start_timer(TRACK_CUST_UNREAD_SMS_CHECK_THREE_TIMER_ID, 2*1000, track_sim_clean_read_sms_reveicebox);
	}
}
/************************测试代码 ********************************
******************************************************************/

#if 0
void track_l4c_sms_exe_post_pdu_req3(void)
{
    //char* pdu = "0031000B815110689058F50000A7289B5E083012943614930A958AAC36C0CDABD7026F509B944EE4FBB95EBBD386B7F1F158";
    kal_uint8 pdu[] =
    {
        0x00, 0x31, 0x00, 0x0B, 0x81, 0x51, 0x10, 0x68, 0x90, 0x58, 0xF5, 0x00, 0x00, 0xA7, 0x28, 0x9B, 0x5E, 0x08, 0x30, 0x12
        , 0x94, 0x36, 0x14, 0x93, 0x0A, 0x95, 0x8A, 0xAC, 0x36, 0xC0, 0xCD, 0xAB, 0xD7, 0x02, 0x6F, 0x50, 0x9B, 0x94, 0x4E, 0xE4
        , 0xFB, 0xB9, 0x5E, 0xBB, 0xD3, 0x86, 0xB7, 0xF1, 0xF1, 0x58
    };
    LOGD(L_CMD, L_V6, "sizeof:%d", sizeof(pdu));
    LOGH(L_CMD, L_V6, pdu, 50);

    l4c_sms_exe_post_pdu_req(
        RMMI_SRC,
        SMSAL_INVALID_INDEX,
        49,
        0,
        0,
        0,
        50,
        (kal_uint8*)&pdu);
}
void track_l4c_sms_exe_post_pdu_req2(void)
{
    //char* pdu = "0031000B815110689058F50000A7289B5E083012943614930A958AAC36C0CDABD7026F509B944EE4FBB95EBBD386B7F1F158";
    kal_uint8 pdu[] =
    {
        0x00, 0x31, 0x00, 0x0B, 0x81, 0x51, 0x10, 0x68, 0x90, 0x58, 0xF5, 0x00, 0x00, 0xA7, 0x28, 0x9B, 0x5E, 0x08, 0x30, 0x12
        , 0x94, 0x36, 0x14, 0x93, 0x0A, 0x95, 0x8A, 0xAC, 0x36, 0xC0, 0xCD, 0xAB, 0xD7, 0x02, 0x6F, 0x50, 0x9B, 0x94, 0x4E, 0xE4
        , 0xFB, 0xB9, 0x5E, 0xBB, 0xD3, 0x86, 0xB7, 0xF1, 0xF1, 0x58
    };
    LOGD(L_CMD, L_V6, "sizeof:%d", sizeof(pdu));
    LOGH(L_CMD, L_V6, pdu, 50);

    l4c_sms_exe_post_pdu_req(
        RMMI_SRC,
        SMSAL_INVALID_INDEX,
        50,
        0,
        0,
        0,
        51,
        (kal_uint8*)&pdu);
}

kal_bool l4a_sms_exe_post_msg_req(
    kal_uint8 src_id,
    kal_uint8 profile,
    kal_uint16 reply_index,
    l4c_number_struct dest,
    kal_uint16 para,
    l4c_number_struct sc_addr,
    kal_uint8 vp,
    smsal_pid_enum pid,
    kal_uint8 udhi,
    smsal_dcs_enum dcs,
    kal_uint16 length,
    kal_uint8 *msg,
    kal_uint8 seq_num,
    kal_uint8 mms_mode,
    kal_uint8 source_id,
    kal_uint8 tp_srr,
    kal_uint8 tp_rp)
{
    return l4c_sms_exe_post_msg_req(source_id, profile, reply_index, dest, para, sc_addr, vp,
                                    pid, udhi, dcs, length, msg, seq_num, mms_mode, tp_srr, tp_rp);
}


extern kal_uint8 not_reset(kal_uint8 reset);
extern void L1SP_Speech_Off(void);
extern kal_uint16 USB_PutBytes(kal_uint8 * out_context, kal_uint16 length);

char * test_sms_number(char* num)
{
    static char number[32] = {0};
    if(NULL != num)
    {
        snprintf(number, 31, "%s", num);
    }
    if(0 == strlen(number))
    {
        snprintf(number, 31, "15018609855");
    }
    LOGD(L_CMD, L_V5, "SMS TEST number:%s", number);
    return &number[0];
}

char * test_sms_number1(char* num)
{
    static char number[32] = {0};
    if(NULL != num)
    {
        snprintf(number, 31, "%s", num);
    }
    if(0 == strlen(number))
    {
        snprintf(number, 31, "17090209856");
    }
    LOGD(L_CMD, L_V5, "SMS TEST number:%s", number);
    return &number[0];
}

char * test_sms_number2(char* num)
{
    static char number[32] = {0};
    if(NULL != num)
    {
        snprintf(number, 31, "%s", num);
    }
    if(0 == strlen(number))
    {
        snprintf(number, 31, "15013981461");
    }
    LOGD(L_CMD, L_V5, "SMS TEST number:%s", number);
    return &number[0];
}

void test_sms(void * mm)
{
    int m = (int)mm;

    char yi[512] = {0};
    static int nna = 0;

    //12520 15018609855 AT^GT_CM=LOG#
    char* yx_sms = "0891683108702505F0240D91685110689058F500005150039015212305C8329BFD06\0";
    char* en_sms = "0891683108200075F12410A821251005810689550000219042013501230E41EA8672A44686CD1EF3791C01\0";
    char* zh_sms = "0891683108702505F00405816658F500082190024181902306738B94876CFD\0";
    char* e_sms = "0891683108200075F12010A821251005810689550000210122512310233FE8329BFD06D1D1E939283D0785417076785C06DDC373D038CC6697C9207498CDA6BFEF6E108B8E2E83D061383C5D9ED3417076785E068500";
    char *lsms = "0891683108200075F12410A821251005810689550000219042013501239A31D98C56B3DD7039584C36A3D56C375C0E1693CD6835DB0D9783C564335ACD76C3E56031D98C56B3DD7039584C36A3D56C375C0E1693CD6835DB0D9783C564335ACD76C3E56031D98C56B3DD7039584C36A3D56C375C0E1693CD6835DB0D9783C564335ACD76C3E56031D98C56B3DD7039584C36A3D56C375C0E1693CD6835DB0D9783C564331A";
    char *tests = "0891683110304105F0240D91683118684003F0000851502241618423045F804E8B\0";

    char unicode_sms[] = {0x73, 0x8B, 0x94, 0x87, 0x6c, 0xFD};
    char dw[] =
    {
        0x4F, 0x4D, 0x7F, 0x6E, 0x00, 0x3A, 0x5E, 0x7F, 0x4E, 0x1C, 0x77, 0x01, 0x00, 0x2E, 0x60, 0xE0,
        0x5D, 0xDE, 0x5E, 0x02, 0x00, 0x2E, 0x60, 0xE0, 0x57, 0xCE, 0x53, 0x3A, 0x4E, 0x91, 0x5C, 0x71,
        0x89, 0x7F, 0x8D, 0xEF, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C, 0x00, 0x41, 0x00, 0x54,
        0x00, 0x4D, 0x7E, 0xA6, 0x00, 0x31, 0x00, 0x38, 0x7C, 0x73, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D,
        0x88, 0x4C, 0x6C, 0x5F, 0x53, 0x17, 0x65, 0x2F, 0x88, 0x4C, 0x7E, 0xA6, 0x00, 0x31, 0x00, 0x39,
        0x7C, 0x73, 0x00, 0x2E
    };

    char dw2[] =
    {
        0x4F, 0x4D, 0x7F, 0x6E, 0x00, 0x3A, 0x5E, 0x7F, 0x4E, 0x1C, 0x77, 0x01, 0x00, 0x2E, 0x60, 0xE0,
        0x5D, 0xDE, 0x5E, 0x02, 0x00, 0x2E, 0x60, 0xE0, 0x57, 0xCE, 0x53, 0x3A, 0x4E, 0x91, 0x5C, 0x71,
        0x89, 0x7F, 0x8D, 0xEF, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C, 0x00, 0x41, 0x00, 0x54,
        0x00, 0x4D, 0x7E, 0xA6, 0x00, 0x31, 0x00, 0x38, 0x7C, 0x73, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D,
        0x88, 0x4C, 0x6C, 0x5F, 0x53, 0x17, 0x65, 0x2F, 0x88, 0x4C, 0x7E, 0xA6, 0x00, 0x31, 0x00, 0x39,
        0x7C, 0x73, 0x00, 0x2E, 0x4F, 0x4D, 0x7F, 0x6E, 0x00, 0x3A, 0x5E, 0x7F, 0x4E, 0x1C, 0x77, 0x01,
        0x00, 0x2E, 0x60, 0xE0, 0x5D, 0xDE, 0x5E, 0x02, 0x00, 0x2E, 0x60, 0xE0, 0x57, 0xCE, 0x53, 0x3A,
        0x4E, 0x91, 0x5C, 0x71, 0x89, 0x7F, 0x8D, 0xEF, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C,
        0x00, 0x41, 0x00, 0x54, 0x00, 0x4D, 0x7E, 0xA6, 0x00, 0x31, 0x00, 0x38, 0x7C, 0x73, 0x00, 0x2E,
        0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C, 0x6C, 0x5F, 0x53, 0x17, 0x65, 0x2F, 0x88, 0x4C, 0x7E, 0xA6,
        0x00, 0x31, 0x00, 0x39, 0x7C, 0x73, 0x00, 0x2E
    };
    char reset[] = {0x97, 0x07, 0x52, 0xA8, 0x62, 0xA5, 0x8B, 0x66, 0xFF, 0x01, 0x5E, 0x7F, 0x4E, 0x1C, 0x77, 0x01,
                    0x00, 0x2E, 0x60, 0xE0, 0x5D, 0xDE, 0x5E, 0x02, 0x00, 0x2E, 0x60, 0xE0, 0x57, 0xCE, 0x53, 0x3A,
                    0x4E, 0x91, 0x5C, 0x71, 0x89, 0x7F, 0x8D, 0xEF, 0x00, 0x2E, 0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C,
                    0x00, 0x41, 0x00, 0x54, 0x00, 0x4D, 0x7E, 0xA6, 0x00, 0x32, 0x00, 0x37, 0x7C, 0x73, 0x00, 0x2E,
                    0x79, 0xBB, 0x4E, 0x2D, 0x88, 0x4C, 0x6C, 0x5F, 0x53, 0x17, 0x65, 0x2F, 0x88, 0x4C, 0x7E, 0xA6,
                    0x00, 0x32, 0x00, 0x37, 0x7C, 0x73, 0x00, 0x2E, 0x00, 0x31, 0x00, 0x35, 0x00, 0x3A, 0x00, 0x32,
                    0x00, 0x31
                   };
    char ssw[] = {0x00, 0x33, 0x00, 0x34, 0x00, 0x35};
    char ssw1[] = {0x4E, 0x7E , 0x57, 0x64 , 0x67 , 0x09 , 0x5E , 0x8F , 0x5B , 0x87 , 0x5B , 0x99 , 0x65 , 0xE0 , 0x75
                   , 0x86 , 0x66 , 0x1F , 0x8F , 0xB0 , 0x5B , 0xC6 , 0x5E , 0x03 , 0x65 , 0x97 , 0x67 , 0xC4 , 0x63 , 0x07 , 0x82 , 0x2A
                  };
    char org[] = {0x89, 0x7F , 0x74 , 0xDC , 0x59 , 0x27 , 0x89 , 0x7F , 0x74 , 0xDC , 0x62 , 0x11 , 0x66 , 0x2F , 0x59 , 0x27 , 0x89 ,
                  0x7F , 0x74 , 0xDC , 0xFF , 0x0C , 0x00 , 0x6F , 0x00 , 0x72 , 0x00 , 0x61 , 0x00 , 0x6E , 0x00 , 0x67 , 0x00 , 0x65 , 0x00 ,
                  0x2C , 0x00 , 0x6F , 0x00 , 0x72 , 0x00 , 0x61 , 0x00 , 0x67 , 0x00 , 0x6E , 0x00 , 0x65 , 0x00 , 0x2C , 0x00 , 0x69 ,
                  0x00 , 0x61 , 0x00 , 0x6D , 0x00 , 0x2C , 0x00 , 0x6F , 0x00 , 0x72 , 0x00 , 0x61 , 0x00 , 0x6E , 0x00 , 0x67 , 0x00 , 0x65
                 };
    //66415 王钇泽
    //char * phone_no[] = {"15018609855\0", "66855\0", "66461\0", "13790761907\0", "15018609855\0", "66855\0"};
    //char * phone_NU[] = { "12345678900\0"};
    // char * yixi = "13818604300";
    char * YIXIC = "HOLLE THIS IS TEST SMS ~!@#$%^&*()_+|\\=-`{}:\">?./;'[]<,";
    char * ctx = "~!@#$%^&*()_+|\\=-`{}:\">?./;'[]<,";

    char rCtx[64] = {0} , sCtx[320] = {0};
    char *tmp = "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    char * abc = "00310000810000A720A9D3D426D3D9A6CE2953C95C3A994A66D3A97C3293CDE951D97C6E5E";

    sms_msg_struct ssms = {0};
    if(m == 0)
    {
        track_sms_receive(sizeof(en_sms), en_sms);
    }
    else if(m == 1)
    {
        track_sms_receive(sizeof(lsms), lsms);
    }
    else if(m == 2)
    {
        track_sms_receive(sizeof(zh_sms), zh_sms);
    }
    else if(m == 3)
    {
        track_sms_receive(sizeof(tests), tests);
    }
    else if(m == 4)
    {
        track_sms_receive(sizeof(yx_sms), yx_sms);
    }
    else if(m == 5)
    {
        track_drv_sleep_enable(SLEEP_DRV_MOD, TRUE);
    }
    else if(m == 6)
    {
        track_drv_sleep_enable(SLEEP_DRV_MOD, FALSE);
    }
    else if(m == 7)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = 70;
        ssms.ctx = tmp;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
        LOGD(L_CMD, L_V5, "======================");
    }
    else if(m == 8)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(dw);
        ssms.nocount = 1;
        ssms.ctx = dw;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
        LOGD(L_CMD, L_V5, "======================");
    }
    /*1-5收短信解码   10-19是发送7bit测试 20-30是群发 个位5以上为长短信*/
    else if(m == 10)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = strlen(ctx);
        ssms.ctx = ctx;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 11)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = 160;
        ssms.ctx = tmp;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 12)
    {
        //track_l4c_sms_exe_post_pdu_req2();
        track_l4c_sms_exe_post_pdu_req3();
    }
    else if(m == 13)
    {
        track_l4c_sms_exe_post_pdu_req2();
    }
    else if(m == 14)
    {
    }

    else if(m == 15)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = strlen(tmp);
        ssms.ctx = tmp;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 20)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = strlen(ctx);
        ssms.ctx = ctx;
        ssms.nocount = 2;
        ssms.numbers[0] = test_sms_number(NULL);
        ssms.numbers[1] = test_sms_number1(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 25)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = strlen(tmp);
        ssms.ctx = tmp;
        ssms.nocount = 3;
        ssms.numbers[0] = test_sms_number(NULL);
        ssms.numbers[1] = test_sms_number1(NULL);
        ssms.numbers[2] = test_sms_number2(NULL);
        track_sms_sender(&ssms);
    }

    else if(m == 30)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(dw);
        ssms.ctx = dw;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 35)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(dw2);
        ssms.ctx = dw2;
        ssms.nocount = 1;
        ssms.numbers[0] = test_sms_number(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 40)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(dw);
        ssms.ctx = dw;
        ssms.nocount = 2;
        ssms.numbers[0] = test_sms_number(NULL);
        ssms.numbers[1] = test_sms_number1(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 45)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(dw2);
        ssms.ctx = dw2;
        ssms.nocount = 2;
        ssms.numbers[0] = test_sms_number(NULL);
        ssms.numbers[1] = test_sms_number1(NULL);
        track_sms_sender(&ssms);
    }
    else if(m == 46)
    {
        int index = 0;
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_FALSE;
        ssms.ctxlen = sizeof(reset);
        ssms.ctx = reset;
        ssms.nocount = 3;
        ssms.numbers[0] = test_sms_number(NULL);
        ssms.numbers[1] = test_sms_number1(NULL);
        ssms.numbers[2] = test_sms_number2(NULL);

        track_sms_sender(&ssms);
    }
    else if(m == 50)
    {
        memset(&ssms, 0, sizeof(sms_msg_struct));
        ssms.codetype = KAL_TRUE;
        ssms.ctxlen = 152;
        ssms.ctx = tmp;
        ssms.nocount = 1;
        ssms.smsdir = SMS_SENDER_BOX;
        ssms.numbers[0] = "";
        track_sms_sender(&ssms);
    }

    /*****************************************************************************/
    else if(m == 60)
    {
        track_is_in_call();
    }
    else if(m == 61)
    {
        track_make_call(test_sms_number(NULL));
    }
    else if(m == 62)
    {
        track_make_call(test_sms_number(NULL));
    }
    else if(m == 63)
    {
        track_make_call(test_sms_number(NULL));
    }/*****************************************************************************/
    else if(m == 80)
    {
        track_sim_get_sms_from_senderbox();
    }
    else if(m == 81)
    {
        track_sim_clean_senderbox();
    }
    else if(m == 82)
    {
        track_sim_clean_allsms();
    }
    else if(m == 83)
    {
        track_sms_backup_decode(20, 36, abc);
        sms_get_sb_ptr;
    }
    else if(m == 84)
    {
        track_sim_clean_reveicebox();
    }
    else if(90 <= m && m < 100)
    {
        sim_test(m);
    }
    else if(m == 100)
    {
        track_set_vs_at_status(V_A_FREE);
    }
    else if(m == 101)
    {
        track_set_vs_at_status(V_A_HOLD);
    }
    else if(m == 102)
    {
        LOGS("at lock is :%d", track_get_vs_at_status());
    }
    else if(120 <= m && m < 126)
    {
        track_cust_set_gps_mode(m - 120);
    }
    else if(m == 158)
    {
        uem_poweron_timer_start(5000);
    }
    else if(m == 159)
    {
        l4cuem_power_reset(0);
    }
    else if(m == 184)
    {
        LOGS("\r\n track_drv_sys_power_off_req\r\n");
        track_drv_sys_power_off_req();
    }
    else if(160 <= m && m < 180)
    {
#if defined(__AUDIO_RC__)
        track_cust_test_voice(m);
#endif /* __AUDIO_RC__ */
    }
#if defined( __WDT_USE_I2C__)
    else if(m == 180)
    {
        WDT_SerialCommRelease();
        WDT_SystemOFF_Init();
    }
    else if(m == 181)
    {
        Watch_dog_Charging_Enable();
    }
    else if(m == 182)
    {
        WDT_Worng_Data_Test(1, 0xa0a0);
    }
    else if(m == 183)
    {
        track_drv_watdog_close(0);
    }
    else if(m == 185)
    {
        track_drv_watdog_close(1);
    }
#endif /* __WDT_USE_I2C__ */
    else if(m == 186)
    {
        if(track_is_timer_run(WATCH_DOG_TIMER_ID))
        {
            track_stop_timer(WATCH_DOG_TIMER_ID);
        }
    }
    else if(m == 187)
    {
        not_reset(1);
    }
    else if(m == 188)
    {
        GPIO_WriteIO(0, 18);
    }

    else if(m == 198)
    {
        if(track_is_timer_run(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID))
        {
            track_stop_timer(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID);
        }
    }
    else if(m == 199)
    {
        L1SP_Speech_Off();
    }
    else if(m == 200)
    {
        AFE_TurnOffSpeaker(L1SP_SPEECH);
    }
    else if(m == 201)
    {
        L1SP_MuteSpeaker(KAL_TRUE);
    }
    else if(m == 202)
    {
        L1SP_MuteSpeaker(KAL_FALSE);
    }
    else if(m == 203)
    {
        AFE_SetRefresh();
    }
    else if(m == 205)
    {
        track_sms_test_mode(1);
    }
    else if(m == 206)
    {
        track_sms_test_mode(0);
    }
    else if(m == 207)
    {
        USB_PutBytes(en_sms, strlen(en_sms));
    }
    else if(m == 208)
    {
        track_drv_sleep_enable(SLEEP_MOD_ALL, KAL_TRUE);
    }
    else if(m == 209)
    {
        track_drv_sleep_enable(SLEEP_MOD_ALL, KAL_FALSE);
    }
    else if(220 == m)
    {
        G_realtime_data.work3_countdowm = 0;
        track_cust_mode3_work_check(99);
    }
    else if(221 == m)
    {
        track_cust_sim_restart((void*)1);
    }
    else if(222 == m)
    {
        track_cust_get_sim_status();
    }
    else if(223 == m)
    {
        track_cust_entry_sleep();
    }
    else if(225 == m)
    {
        ell_update_delete_file();
    }
    else if(226 == m)
    {
        kal_uint16 reset_value = *(volatile kal_uint16 *)(0xA0700A14);
        //关闭BATON_HT_EN-0
        LOGS("BATON_HT_EN is:(0xA0700A14:%x,%x)", reset_value, *(volatile kal_uint16 *)(0xA0700A14));
    }
    else if(226 == m)
    {
        kal_uint16 reset_value = *(volatile kal_uint16 *)(0xA0700A14);
        *(volatile kal_uint16 *)(0xA0700A14) = (reset_value  & 0xFEFF);
        //关闭BATON_HT_EN-0
        LOGS("BATON_HT_EN is:(0xA0700A14:%x,%x)", reset_value, *(volatile kal_uint16 *)(0xA0700A14));
    }
    else if(227 == m)
    {
        track_drv_led_vcama(KAL_TRUE);
    }
    else if(228 == m)
    {
        track_drv_led_vcama(KAL_FALSE);
    }
}
#endif /* 0 */

#endif
