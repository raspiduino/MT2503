/*******************************************************************************************
 *
 * Filename:
 * Author :
 * Date :
 * Comment:
 *
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "ell_update.h"
#include "app_md5.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
const static U16 crctab16[] =
{
    0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
    0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
    0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
    0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
    0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
    0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
    0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
    0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
    0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
    0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
    0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
    0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
    0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
    0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
    0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
    0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
    0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
    0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
    0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
    0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
    0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
    0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
    0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
    0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
    0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
    0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
    0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
    0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
    0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
    0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
    0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
    0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
/******************************************************************************
 *  Function    -  ell_GetCrc16
 *
 *  Purpose     -  计算给定长度数据的16位CRC
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
U16 ell_GetCrc16(const U8* pData, int nLength)
{
    U16 fcs = 0xffff;    // 初始化
    U8 tmp;
    while(nLength > 0)
    {
        fcs = (fcs >> 8) ^ crctab16[(fcs ^ *pData) & 0xff];
        nLength--;
        pData++;
    }
    return ~fcs;
}

/******************************************************************************
 *  Function    -  IsDataCrc16
 *
 *  Purpose     -  判断 CRC-ITU16 校验结果
 *
 *  Description -  数据的最后两位为CRC值
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool ell_IsDataCrc16(const U8* pData, int nLength)
{
    U16 fcs, crc;
    fcs = ell_GetCrc16(pData, nLength - 2);
    crc = *(pData + nLength - 2);
    crc <<= 8;
    crc |= *(pData + nLength - 1);
    return (crc == fcs);
}

kal_bool ell_IsDataCrc16ext(const U8* pData, int nLength, U16 crc)
{
    U16 fcs;
    fcs = ell_GetCrc16(pData, nLength);
    return (crc == fcs);
}

kal_bool ell_IsDataMd5ext(const U8* pData, int nLength, U8 *md5)
{
    applib_md5_ctx md5_ctx;
    U8 hash_result[16] = {0};

    applib_md5_init(&md5_ctx);
    applib_md5_update(&md5_ctx, (U8 *)pData, nLength);
    applib_md5_final(hash_result, &md5_ctx);
    if(!memcmp(hash_result, md5, 16))
    {
        return KAL_TRUE;/*相等*/
        EllHex(hash_result, 16);
    }
    EllHex(hash_result, 16);
    EllHex(md5, 16);
    return KAL_FALSE;
}

void ell_GetDataMd5(const U8* pData, int nLength, U8 *md5)
{
    applib_md5_ctx md5_ctx;

    applib_md5_init(&md5_ctx);
    applib_md5_update(&md5_ctx, (U8 *)pData, nLength);
    applib_md5_final(md5, &md5_ctx);
}

char *ell_get_base_version2(void)
{
    static kal_bool first = KAL_TRUE;
    static char tmp[100] = {0}, *src_ver, *ver, *p;
    if(first)
    {
        src_ver = (char*)release_verno();
        p = strstr(src_ver, "_F");
        ver = src_ver;
        if(p)
        {
            p = strstr(p + 1, "_");
            if(p)
            {
                int len = p-src_ver;
                if(len > 99) len = 99;
                memcpy(tmp, src_ver, len);
            }
            else
            {
                strncpy(tmp, src_ver, 99);
            }
        }
        else
        {
            strncpy(tmp, src_ver, 99);
        }
    }
    return tmp;
}
#if 0

static int ell_String2Bytes(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int i = 0;
    EllLog("%d", nSrcLength);
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
#endif /* 0 */

void ell_DataToHex(char *ptr, void * buff, int size)
{
    char *ptr1;
    int i = 0, j;
    ptr1 = (char*)buff;

    if(size <= 0)
    {
        return;
    }
    while(i < size)
    {
        sprintf(ptr, "%0.2X", *ptr1);
        ptr += 2;
        ptr1++;
        i++;
    }
}

static char * ell_trim(char * str)
{
    int len = strlen(str);
    int i = 0;
    if(len > 0)
    {
        int j = 1;
        //统计字符串前端空格数
        while(*(str + i) == ' ' || *(str + i) == '\t')
        {
            i++;
        }
        //统计字符串后端空格数
        while(*(str + len - j) == ' ' || *(str + len - j) == '\t' || *(str + len - j) == '\r' || *(str + len - j) == '\n')
        {
            j++;
        }
        //重新计算修剪后的字符串数
        if(len - j + 1 >= 0) str[len - j + 1]  = '\0';
    }
    return str + i;
}

static void ell_server_addr_analyze(char *src, ell_data_parameter_struct *data)
{
    char *p = src;
    char *line_start = src, *line_end, *total_end, *spacer;
    if(src == NULL) return;
    total_end = src + strlen(src);
    do
    {
        line_end = strchr(line_start, '\n');
        if(line_end == NULL) line_end = total_end;
        // ---------
        *line_end = 0;
        spacer = strchr(line_start, '=');
        if(spacer != NULL)
        {
            *spacer = 0;
            line_start = ell_trim(line_start);
            if(!strcmp(line_start, "LOG"))
            {
                int t;
                line_start = ell_trim(spacer + 1);
                t = atoi(line_start);
                data->log = t;
            }
            else if(!strcmp(line_start, "RECOUNT"))
            {
                int t;
                line_start = ell_trim(spacer + 1);
                t = atoi(line_start);
                data->recount= t;
            }
            else if(!strcmp(line_start, "SERVER"))
            {
                data->server = ell_trim(spacer + 1);
            }
            else if(!strcmp(line_start, "PORT"))
            {
                int t;
                line_start = ell_trim(spacer + 1);
                t = atoi(line_start);
                data->port = t;
            }
        }
        // ---------
        line_start = line_end + 1;
    }
    while(line_start != NULL && line_start < total_end);
}

S8 ell_check_is_IPaddress(char *data, U8 *ip)
{
    int j = 0, x = 0;
    char *ips[4] = {0}, *ipstr;
    char ipstr2[16] = {0};
    if(strlen(data) > 15)
    {
        EllLog("%d|%s|", strlen(data), data);
        return -1;
    }
    ips[x++] = data;
    strcpy(ipstr2, data);
    ipstr = ipstr2;
    while(*ipstr != '\0')
    {
        if(*ipstr < '0' || *ipstr > '9')
        {
            if(*ipstr == '.')
            {
                j++;
                *ipstr = 0;
                if(j > 3) return -2;
                ips[x++] = ipstr + 1;
            }
            else
            {
                return -3;
            }
        }
        ipstr++;
    }
    if(j != 3) return -4;
    for(j = 0; j < 4; j++)
    {
        x = atoi(ips[j]);
        if(x > 255 || x < 0) return -5;
        ip[j] = x;
    }
    return 0;
}

ell_data_parameter_struct *ell_get_data_parameter(void)
{
    static ell_data_parameter_struct ell_data_parameter = {0};
    static U8 first = 0;
    if(first == 0)
    {
        static char buf[150] = {0};
        S32 ret;
        first = 1;
        ret = ell_get_data_from_file("test.ini", buf, 150);
        if(ret > 0) ell_server_addr_analyze(buf, &ell_data_parameter);
    }
    return &ell_data_parameter;
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

void ell_sys_assert_reset(void)
{
    EXT_ASSERT(0, 0, 0, 0);
}

S32 ell_get_data_from_file(char *file_path, U8 *data, U32 len)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    U32 filelen, readsize;
    int fs_result;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        //EllLog("FS_Open %d", fp);
        return fp;
    }
    FS_GetFileSize(fp, &filelen);
    if(filelen > len)
    {
        FS_Close(fp);
        EllLog("filelen:%d, len:%d", filelen, len);
        return -4;
    }
    len = filelen;
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        EllLog("FS_Seek %d", fs_result);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Read(fp, data, 50000, &readsize);
        }
        else
        {
            fs_result = FS_Read(fp, data, len, &readsize);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            EllLog("fs_result:%d, %d, %d", fs_result, readsize, len);
            return fs_result;
        }
        len -= readsize;
        data += readsize;
    }
    FS_Close(fp);
    return filelen;
}

/******************************************************************************
 *  Function    -  track_epo_write_file
 *
 *  Purpose     -  写入EPO文件
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
int ell_data_write_to_file(char *file_path, U8 *data, U32 len)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    U32 writelen;
    int fs_result, ret;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_WRITE | FS_CREATE);
    if(fp < 0)
    {
        EllLog("FS_Open %d", fs_result);
        return fp;
    }
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        EllLog("FS_Seek %d", fs_result);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Write(fp, data, 50000, &writelen);
        }
        else
        {
            fs_result = FS_Write(fp, data, len, &writelen);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            EllLog("fs_result:%d, %d, %d", fs_result, len, writelen);
            ret = FS_Delete(FilePath);
            EllLog("2 FS_Delete=%d", ret);
            return fs_result;
        }
        FS_Commit(fp);
        len -= writelen;
        if(len > 0)
        {
            data += writelen;
        }
    }
    FS_GetFileSize(fp, &writelen);
    EllLog("%s文件写入FAT, 大小:%d", file_path, writelen);//"EPO文件写入FAT大小:%d"
    FS_Close(fp);
    return 0;
}

U8 *ell_get_imei(U8 par)
{
    static kal_bool first = KAL_TRUE;
    static U8       imei_hex[8] = {0};
    static char     imei_str[17] = {0};
    if(first)
    {
        U8 i, j;
        nvram_ef_imei_imeisv_struct imei_data = {0};
        
        nvram_external_read_data(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
        imei_str[0] = '0';
        for(i = 0, j = 1; i < 8; i++)
        {
            imei_str[j++] = (imei_data.imei[i] & 0x0F) + 0x30;
            imei_str[j++] = ((imei_data.imei[i] >> 4) & 0x0F) + 0x30;
        }
        imei_str[16] = 0; //最后一位0  舍弃
        EllLog("IMEI=%s", &imei_str[1]);

        for(i = 0, j = 0; i < 16;)
        {
            imei_hex[j++] = (((imei_str[i] - 0x30) & 0x0F) << 4) | ((imei_str[i + 1] - 0x30) & 0x0F);
            i += 2;
        }
        first = KAL_FALSE;
    }
    if(par == 1)
        return imei_hex;
    else
        return (U8*)&imei_str[1];
}

char *ell_read_imsi_data(void)
{
    static kal_uint8 imsi_str[16] = {0};
    kal_uint8 imsi_data[10] = {0};
    kal_uint8 str[17] = {0};
    kal_uint8 i, j;

    l4csmu_get_imsi(imsi_data);

    /*imsi_data 全0 表示没插SIM 卡*/

    for(i = 0, j = 0; i < 8; i++)
    {
        str[j++] = (imsi_data[i] & 0x0F) + 0x30;
        str[j++] = ((imsi_data[i] >> 4) & 0x0F) + 0x30;
    }
    str[j] = 0;
    memset(imsi_str, 0x00, sizeof(imsi_str));
    snprintf(imsi_str, 16, "%s", &str[1]);   //首位9 不知道是什么

    EllLog("IMSI:%s", imsi_str);
    return imsi_str;
}

char *ell_domain_decode(kal_uint8 *data)
{
    static kal_uint8 buf[TRACK_MAX_URL_SIZE] = {0};
    kal_uint8 tmp[TRACK_MAX_URL_SIZE] = {0};
    int i, len;
    len = strlen(data);
    if(len >= TRACK_MAX_URL_SIZE)
    {
        EllLog("URL encode error!");
        return NULL;
    }
    memcpy(tmp, data, TRACK_MAX_URL_SIZE);
    for(i=0; i<len; i++)
    {
        tmp[i] -= 128;
    }
    if(memcmp(tmp, buf, TRACK_MAX_URL_SIZE))
    {
        memcpy(buf, tmp, TRACK_MAX_URL_SIZE);
    }
    return (char *)buf;
}

