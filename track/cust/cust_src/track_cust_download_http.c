/****************************************************************************
***file author: Liujw
***creat date:2018-05-09
***introduction:
****************http 下载协议
****************2019-7-1 没有使用断点续传
****************************************************************************/
#include "track_cust_download_http.h"
#define fileDownLoadCountMax 15
static int fileTotalLength = 0;//需下载的文件总大小
static U8 isContinueLoading = 0;//是否是断点续传
static kal_uint32 downLoadedLength = 0;//已经下载数据大小
extern void HTTP_server_request();
extern void HTTP_continue_loading_error();
static c_vector* vec_send_http_queue = NULL;
static kal_bool HTTP_Login_Success = KAL_FALSE;
static nvram_server_addr_struct server_http = {0};	//保存解析后的http服务器
static FAT_FILE_ST radio_file = {0};//语音文件读写
//以下是存储文件
static  WCHAR       fat_file_name[40];
static char http_web[HTTP_MAX_PATH];
static char audioFileName[30];
//请求时的变量问题
static int check_header_flag = 0;//这个在打包好请求数据头时就要归零要归 0

//CONNECTION:Keep-Alive [close]请求完成后断开
//RANGE:1000
//Range: bytes=10-：第10个字节及最后个字节的数据
//Range: bytes=40-100：第40个字节到第100个字节之间的数据.
//注意，这个表示[start,end]，即是包含请求头的start及end字节的，所以，下一个请求，应该是上一个请求的[end+1, nextEnd]
#if 0
static const char *S_request_head = "GET %s HTTP/1.1\r\n" \
                                    "Accept: */*\r\n" \
                                    "Range: bytes=0-50\r\n"\
                                    "Accept-Language: zh-cn\r\n" \
                                    "User-Agent: Molliza/4.0(compatible;MSIE6.0;windows NT 5.0)\r\n" \
                                    "Host: %s\r\n" \
                                    "Connection: close\r\n\r\n";
#endif
static const char *S_request_head = "GET %s HTTP/1.1\r\n" \
                                    "Accept: */*\r\n" \
                                    "Accept-Language: zh-cn\r\n" \
                                    "User-Agent: Molliza/4.0(compatible;MSIE6.0;windows NT 5.0)\r\n" \
                                    "Host: %s\r\n" \
                                    "%s" \
                                    "Connection: close\r\n\r\n";
//"Range: bytes=%d-%d\r\n"
char range1[] = "Range: bytes=%d-\r\n";
char range2[] = "Range: bytes=0-\r\n";
char request[HTTP_MAX_REQUESTHEAD];
int request_len = 0;
static U8 isDownLoadFile = 0;//文件正在现在标识 1 有音频文件下载  2 有固件升级

static void HTTP_server_disconnect(void);


/******************************************************************************
 *  Function    -  package_request
 * 
 *  Purpose     -  请求字符串拼接
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-01-19,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
int package_request(char *request, const char *web, const char *filepath, char *range)
{
    int n = sprintf(request, S_request_head, filepath, web, range);
    request[n] = '\0';
    return n;
}


static char * r_strchr(const char *p, int len, char ch)
{
    int last_pos = -1;
    int i = 0;
    while(*(p + i) != '\0')
    {
        if(*(p + i) == ch)last_pos = i;
        if(++i >= len)break;
    }
    return last_pos >= 0 ? (char*)(p + last_pos) : NULL;
}
static void domain_slip(char* url, kal_uint8 isport)
{
    kal_uint8 temp[3] = {"80"};
    kal_uint8 len = 0;
    char *port;//buf[128] = {0};
    kal_uint8 IP[4], dnsLen = 0;
    kal_bool flag = KAL_FALSE;
    kal_uint16 portInt = 0;
    nvram_server_addr_struct server = {0};
    char domain[TRACK_MAX_URL_SIZE] = {0};
    do
    {
        if(isport != 0)
        {
            if((port = strchr(url, ':')) == NULL) break;
            *port++ = '\0';
            LOGD(L_APP, L_V5, "Server:%s:%s", url, port);
        }
        else
        {
            port = temp;
        }
        dnsLen = strlen(url);
        if(dnsLen > 99) break;
        if(track_fun_asciiIP2Hex(url, IP) == KAL_FALSE) memset(IP, 0, 4);

        if(track_fun_check_data_is_port(port) == KAL_FALSE || (portInt = track_fun_parseInt(port)) <= 0) break;
        flag = KAL_TRUE;
    }
    while(0);
    if(flag)
    {
        if(IP[0] == 0 && IP[3] == 0)
        {
            server_http.conecttype = 1;
            memset((void *)server_http.url, 0, sizeof(server_http.url));//以前当设置为url时发送的信息会有2个端口号这里改正
            //memcpy((void *)&G_importance_parameter_data.server.url, (void *)parameter, dnsLen);
            memcpy(domain, (void *)url, dnsLen);
            track_domain_encode(domain, server_http.url);
        }
        else
        {
            server_http.conecttype = 0;
            memcpy(server_http.server_ip, IP, 4);
        }
        server_http.soc_type = 0;
        server_http.server_port = portInt;
    }
}
static void parse_url(const char *url, char *web, int *port, char *filepath, char *filename)
{
    int web_len = 0;
    int web_start = 0;
    int file_len = 0;
    int file_start = 0;
    int path_len = 0;
    int path_start = 0;
    char *pa = NULL;
    char *pb = NULL;
    if(!strncmp(url, "http://", 7)) web_start = 7;
    else if(!strncmp(url, "https://", 8)) web_start = 8;

    pa = strchr(url + web_start, '/');
    pb = strchr(url + web_start, ':');

    /* 获取web */
    if(pa)
    {
        web_len = (int)(pa - (url + web_start));
    }
    else
    {
        if(pb) web_len = pb - (url + web_start);
        else web_len = strlen(url + web_start);
    }
    //if(web_len == 0)
    {
        LOGD(L_APP, L_V5, "web_len %d", web_len);
    }
    memcpy(web, url + web_start, web_len);
    web[web_len] = '\0';

    /* 获取filename */
    if(pb)
    {
        //pa = r_strchr(url + web_start, (int)(pb - (url + web_start)), '/');
        pa = r_strchr(url + web_start, (strlen(url) - web_start), '/');
        LOGD(L_APP, L_V5, "pb:%d,pa:%d,%d,%d", pb, pa, (url + web_start), url);
        file_len = strlen(pa + 1);
        file_start = (int)(pa + 1 - url);
        *port = atoi(pb + 1);
        LOGD(L_APP, L_V5, "1-%d,%d,%d", file_len, file_start, port);
    }
    else
    {
        pa = r_strchr(url + web_start, strlen(url + web_start), '/');
        //LOGD(L_APP, L_V5, "pa == NULL");
        file_len = strlen(pa + 1);
        file_start = (int)(pa + 1 - url);
        *port = DEF_HTTP_PORT;
        LOGD(L_APP, L_V5, "2-%d,%d,%d", file_len, file_start, port);
    }
    LOGD(L_APP, L_V5, "file_len:%d", file_len);
    memcpy(filename, url + file_start, file_len);
    filename[file_len] = '\0';

    /* 获取filepath */
    path_start = web_start + web_len;
    path_len = file_start - path_start + file_len;
    memcpy(filepath, url + web_start + web_len, file_start - path_start + file_len);
    filepath[path_len] = '\0';
}
void setFotaFileTiming(U8 stamp)
{
    static kal_uint32 _beginTime = 0;
    kal_uint32 _endTime = 0;
    U8 IsWrite = 0;
    //U8 _fileUpdate = 0;
    if(stamp == 0)
    {
        _beginTime += kal_get_systicks();
        LOGD(L_APP, L_V5, "FOTA文件下载开始!");
    }
    else
    {
        kal_int32 ret = 0;
        WCHAR newFileName[40] = {0};
        nvram_check_ota_struct g_otacheck = {0};
        _endTime = kal_get_systicks();
        LOGD(L_APP, L_V5, "%d,FOTA文件下载全部完成，耗时:%d秒", stamp, kal_ticks_to_secs(_endTime - _beginTime));
        _beginTime = 0;
        _endTime = 0;

        G_realtime_data.file_update_style &= 2;
        G_realtime_data.http_server.isdownload = 0;
        G_realtime_data.http_server.filestyle = 0;

        if(stamp == 1)
        {
            OTA_kal_wsprintf(newFileName, "%s", FOTA_FILE_PATH);
            ret = OTA_FS_Rename(fat_file_name, newFileName);
            if(ret == 0)//FS_NO_ERROR:0
            {
                /*
                                Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                                g_otacheck.unconditional = 97;
                                Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                */
                G_realtime_data.fota_update = 1;//标识固件升级
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
                IsWrite = 1;
                if(G_parameter.ste_status.lease == 0)
                {
                    track_cust_restart(99, 5);
                }
            }
            else
            {
                ret = FS_Delete(fat_file_name);
                if(G_parameter.ste_status.lease == 0)
                {
                    track_cust_restart(98, 5);
                }
                LOGD(L_APP, L_V5, "重命名文件出错");
            }
        }
        else
        {
            ret = FS_Delete(fat_file_name);
        }
        LOGD(L_APP, L_V5, "ret:%d", ret);

        if(IsWrite == 0)
        {
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }

    }
}

static int track_cust_http_response_header(kal_uint8 *data, int len)
{
    U8 range = 0;//标识是否是断点续传
    int single_len = 0;
    char *r_p = NULL, *end = NULL;
    char *l_p = NULL;
    char *content_range[] = {"Content-Range:"};//断点续传标识
    char *content_length[] = {"Content-Length"};//单包长度

    LOGD(L_APP, L_V7, "%s", data);
    if(len > 700)
        LOGD(L_APP, L_V7, "%s", (data + 700));
    r_p = strstr(data, "Content-Range:");
    if(r_p != NULL)
    {
        r_p = strchr(r_p, '/');
        end = strstr(r_p, "\r\n");
        strncpy(end, "\0", 1);
        fileTotalLength = track_fun_atoi(r_p + 1);
        //进来这里，表明要断点续传，加入标志位
        range = 1;
    }
    l_p = strstr(data, "Content-Length:");
    if(l_p != NULL)
    {
        l_p = strchr(l_p, ':');
        end = strstr(l_p, "\r\n");
        strncpy(end, "\0", 1);
        single_len = track_fun_atoi(l_p + 2);
    }
    if(r_p == NULL)
    {
        fileTotalLength = single_len;
    }
    if(isContinueLoading && HTTP_continue_loading_check(single_len, fileTotalLength) < 0)
    {
        LOGD(L_APP, L_V1, "error!!!断点续传数据验证失败，总大小计算出错!");
        HTTP_continue_loading_error();
        return -1;
    }
    LOGD(L_APP, L_V5, "文件下载开始！本次数据长度：%d,数据总大小:%d,range:%d", single_len , fileTotalLength, range);
    if(G_realtime_data.http_server.filestyle == 2) setFotaFileTiming(0);
    G_realtime_data.http_server.file_length = fileTotalLength;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    return range;
}
//const char test_url1[1024] = {"http://jsfx.downg.com//201805/PSLHardCodedString.rar"};
//const char test_url2[1024] = {"https://dzs.qisuu.la/36/36895/吹神.txt"};
//const char test_url3[1024] = {"http://120.234.223.168:7815//123/audio.mp3"};
//const char test_url4[1024] = {"http://120.234.223.168:7815/audio.mp3"};
//const char test_url5[1024] = {"http://120.234.223.168:7815/testhttp.txt"};
#if 0
void track_cust_http_data_request()//(kal_uint16 page)
{
    int port;
    //int request_len = 0;
    char web[HTTP_MAX_PATH+1];
    char remote_path[HTTP_MAX_PATH+1];
    char remote_file[HTTP_MAX_PATH+1];
    char header_range[50];
    int n = 0;
    //page 从0 开始
    kal_int32 start_b = 0, end_b = 0;

    LOGD(L_APP, L_V5, "total_pages:%d,page:%d", down_pages + 1, curr_page + 1);
    start_b = curr_page * SINGLE_DATA_LEN;
    if(curr_page == down_pages)
    {
        LOGD(L_APP, L_V5, "最后一包: %d", curr_page);
        end_b = (curr_page * SINGLE_DATA_LEN) + last_page - 1;
    }
    else
    {
        end_b = (curr_page + 1) * SINGLE_DATA_LEN - 1;
    }
    LOGD(L_APP, L_V5, "此次请求开始字符start_b:%d,结束字符end_b:%d，共:%d", start_b, end_b, (end_b - start_b));
    parse_url(test_url3, web, &port, remote_path, remote_file);
    n = sprintf(header_range, range1, start_b, end_b);
    header_range[n] = '\0';
    request_len = package_request(request, web, remote_path, header_range);
    Socket_write_req(2, request, strlen(request), 0, 0, 0, 1);
}
#endif
static int file_postfix(char *filename)
{
    U8 file[40];
    int postfix = 0;
    int audioNameLen = 0;
    U8 _audioName[20] = {0};

    if(G_realtime_data.http_server.filestyle == 1)
    {
        /*用语音ID来作为语音文件名,是否OK*/
        if(strstr(filename, ".MP3") || strstr(filename, ".mp3"))
        {
            sprintf(_audioName, "%X%X%X.mp3", G_realtime_data.http_server.voice_Id[0], G_realtime_data.http_server.voice_Id[1], G_realtime_data.http_server.voice_Id[2]);
        }
        else if(strstr(filename, ".amr"))
        {
            sprintf(_audioName, "%X%X%X.amr", G_realtime_data.http_server.voice_Id[0], G_realtime_data.http_server.voice_Id[1], G_realtime_data.http_server.voice_Id[2]);
        }
        else
        {
            return 0;
        }

        memset(filename, 0, HTTP_MAX_PATH + 1);
        sprintf(filename, "%s", _audioName);
        LOGD(L_APP, L_V1, "audioname:%s,%s", filename, _audioName);
        OTA_kal_wsprintf(fat_file_name, "%s", filename);
        postfix = 1;
    }
    else if(G_realtime_data.http_server.filestyle == 2)//(strstr(filename, ".BIN"))
    {
        OTA_kal_wsprintf(fat_file_name, "%s", TEMP_FILE_PATH);
        postfix = 2;
    }
    else
    {
        LOGD(L_APP, L_V1, "Warning!!!!!!!!!!!!!,There is not a right file style ,Please check it !!!");
        return 0;
    }
    return postfix;
}
void track_cust_test_http(char *filename, kal_uint8 voice_id)
{
    int web_len = 0;
    kal_uint8 *finder = NULL;
    int port;
    //int request_len = 0;
    char web[HTTP_MAX_PATH+1];
    char remote_path[HTTP_MAX_PATH+1];
    char remote_file[HTTP_MAX_PATH+1];
    char url_tmp[512] = {"http://61.143.127.62:7815/"}; //120.234.223.168
    char range_temp[HTTP_MAX_PATH+1];

    if(filename != NULL)
    {
        if(voice_id != 99)
        {
            G_realtime_data.http_server.voice_Id[2] = voice_id;
        }
        strcat(url_tmp, filename);
        web_len = strlen(url_tmp);
        if(web_len > 99)
        {
            LOGD(L_APP, L_V5, "路径超长!!!,web_len:%d", web_len);
            return;
        }
        memcpy(http_web, url_tmp, web_len);

        parse_url(url_tmp, web, &port, remote_path, remote_file);
    }
    else
    {
        parse_url(http_web, web, &port, remote_path, remote_file);
    }
    LOGD(L_APP, L_V5, "%d,%s,%s,%s", port, web, remote_path, remote_file);
    if(!file_postfix(remote_file))
    {
        if((G_realtime_data.http_server.filestyle == 1))//临时处理目前文件格式不对或者链接不对的问题
        {
            G_realtime_data.http_server.isdownload = 0;
            setVoicefileTiming(G_realtime_data.http_server.voice_Id);
            G_realtime_data.http_server.filestyle = 0;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        LOGD(L_APP, L_V1, "error!文件格式错误！返回,%s", remote_file);
        return;
    }
    memset(request, 0, HTTP_MAX_REQUESTHEAD);
    if(G_realtime_data.http_server.load_length > 0 && G_realtime_data.http_server.isdownload == 1)//判断为断点续传
    {
        //没做断点续传，不可能进来
        LOGD(L_APP, L_V1, "警告警告警告，这里不可能进来的,%d", G_realtime_data.http_server.load_length);
        isContinueLoading = 1;
        sprintf(range_temp, range1, G_realtime_data.http_server.load_length);
        request_len = package_request(request, web, remote_path, range_temp);
        return;//没有断点续传，先返回，以免出错 2019-7-3
    }
    else
    {
        if(G_realtime_data.http_server.filestyle == 1)
        {
            memset(audioFileName, 0, 30);
            memcpy(audioFileName, remote_file, strlen(remote_file));
            //AUDIO_file_memory(G_realtime_data.http_server.voice_Id,remote_file);
        }
        fileTotalLength = 0;
        check_header_flag = 0;
        request_len = package_request(request, web, remote_path, range2);
    }
    LOGD(L_APP, L_V5, "VOICEID:%d,%d,%s", voice_id , request_len, request);

    HTTP_file_init(3);
    //这里将域名和端口进行重新解析
    finder = strchr(web, ':');
    if(finder != NULL)
    {
        domain_slip(web, 1);
    }
    else
    {
        domain_slip(web, 0);
    }
    if(server_http.conecttype == 1)
    {
        LOGD(5, 5, "DOMAIN=%s:%d", track_domain_decode(server_http.url), server_http.server_port);
    }
    else if(server_http.conecttype == 0)
    {
        LOGD(5, 5, "DOMAIN=%d.%d.%d.%d:%d",
             server_http.server_ip[0],
             server_http.server_ip[1],
             server_http.server_ip[2],
             server_http.server_ip[3],
             server_http.server_port);
    }
    G_realtime_data.http_server.isdownload = 1;
    HTTP_server_connect();
}
U8 getVoicefileTiming(kal_uint8* voice_id)
{
    int i = 0;
    kal_uint8 voice_temp[4];
    U8 finder = 0;
    for(i = 0; i < G_realtime_data.voice_max; i++)
    {
        memset(voice_temp, 0, 4);
        if(G_realtime_data.voice_list.void_id[i].isload == 0)
        {
            voice_temp[0] = G_realtime_data.voice_list.void_id[i].isload;
            memcpy(&voice_temp[1], G_realtime_data.voice_list.void_id[i].voice_id, 3);
            finder = 1;
            break;
        }
    }
    if(finder == 1)
    {
        //if(AUDIO_id(&voice_temp[1])) return 0;
        memcpy(voice_id, voice_temp, 4);
    }
    LOGH(5, 5, voice_id, 4);
    return finder;
}
void setVoicefileTiming(kal_uint8 *voice_id)
{
    kal_bool finder = KAL_FALSE;
    int i = 0, len = 0;
    kal_uint8 voice_temp[4];
    len = G_realtime_data.voice_max * 4;
    for(i = 0; i < G_realtime_data.voice_max; i++)
    {
        memset(voice_temp, 0, 4);
        memcpy(&voice_temp[1], G_realtime_data.voice_list.void_id[i].voice_id, 3);
        LOGD(5, 6, "%02X%02X%02X-%02X%02X%02X", voice_temp[1], voice_temp[2], voice_temp[3], voice_id[0], voice_id[1], voice_id[2]);
        if(voice_temp[1] == voice_id[0] && voice_temp[2] == voice_id[1] && voice_temp[3] == voice_id[2])
        {
            G_realtime_data.voice_list.void_id[i].isload = 1;
            LOGD(5, 5, "isload 1");
            finder = KAL_TRUE;
            break;
        }
    }
    if(finder)
    {
        finder = KAL_FALSE;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    track_audio_file_checking((void*)1);
}

void track_cust_isDownLoadFile()
{
    LOGD(L_DRV, L_V1, "%d", isDownLoadFile);
    isDownLoadFile = 0;
}
U8 track_getIsDownLoadFile()
{
    LOGD(L_DRV, L_V1, "%d", isDownLoadFile);
    return isDownLoadFile;
}
/******************************************************************************
 *  Function    -  HTTP_data_recv
 *
 *  Purpose     -  对接收的数据包进行拆分处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-05-2018,  Liujw  written
 * ----------------------------------------
*******************************************************************************/
static void HTTP_data_recv(kal_uint8 *data, int len)
{
    U32 ota_size = 0;
    int ret = 0;
    int i = 0, _headerCheck = 99, finder = 0, _packetLength = 0;
    static kal_uint32 _totalLength = 0;
    static kal_uint8 *buf = NULL;
    static int _bufferLength = 0;
    kal_uint32 _voicesizecheck = 0;
    U32 FATDiskSpace = 0;
    //static int flag = 0;//这个要归 0

    if(buf == NULL)
    {
        buf = (U8*)Ram_Alloc(5, 4096);
        if(buf == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
            return;
        }
    }

    //LOGH(5, 7, data, len);
    if(_bufferLength < 0) _bufferLength = 0;
    if(_bufferLength + len >= 4096)
    {
        LOGD(L_APP, L_V4, "%d,%d 接收数据异常", len, _bufferLength);
        _bufferLength = 0;
        return;
    }
    memcpy(&buf[_bufferLength], data, len);
    _bufferLength += len;

    _packetLength = _bufferLength;
    for(i = 0; (i < _bufferLength && check_header_flag < 2); i++)
    {
        if(buf[i] == 0x48 && buf[i+1] == 0x54 && buf[i+2] == 0x54 && buf[i+3] == 0x50)
        {
            check_header_flag  = 1;
            //continue;
        }
        if(check_header_flag == 1 && buf[i] == 0x0D && buf[i+1] == 0x0A && buf[i+2] == 0x0D && buf[i+3] == 0x0A)
        {
            if(check_header_flag == 1)
            {
                check_header_flag = 2;
                finder = i + 4;
            }
        }
        if(check_header_flag == 2)
        {
            //check_header_flag = 0;
            _headerCheck = track_cust_http_response_header(buf, i + 4);
            //total_length = len - i - 1;
            _packetLength = _bufferLength - i - 4;
            i += 4;
            ///收到头文件，说明重新下载，就清掉累计的数据
            _totalLength = 0;
            downLoadedLength = 0;
            //判断内存是否超过最大 要留800K 800*1024 = 819200
            if(G_realtime_data.http_server.filestyle == 1)//MP3的文件需要计算
            {
                FATDiskSpace = track_fun_FS_GetDiskInfo();
                LOGD(L_APP, L_V1, "%d,%d,%d", _voicesizecheck, FATDiskSpace, fileTotalLength);
                if(FATDiskSpace <= 0) return;
                if((FATDiskSpace - fileTotalLength) <= 819200)
                {
                    //语音文件已经超过最大下载量,关闭http连接，不接收数据
                    LOGD(L_APP, L_V1, "Error! over load voice file,%d,%d", _voicesizecheck, FATDiskSpace);
                    HTTP_server_disconnect();
                    track_audio_file_checking((void*) 2);
                    check_header_flag = 0;
                    return;
                }
            }
            break;
        }
    }
    LOGD(L_APP, L_V1, "_headerCheck=%d,%d,%d", _headerCheck, _totalLength, downLoadedLength);
    if(check_header_flag != 2)
    {
        LOGD(L_APP, L_V1, "没有找到header字符串！返回");
        check_header_flag = 0;
        return;
    }
    LOGD(L_APP, L_V5, "起始:%d,长度:%d", i, _packetLength);
    if(_headerCheck < 0)
    {
        LOGD(L_APP, L_V1, "ERROR!!! header_check= -1,断点续传检查出错，无法进行续传下载!");
        check_header_flag = 0;
        _bufferLength = 0;
        return;
    }
    else if(_headerCheck == 1)
    {
        //没有断点续传，这里都无用的，去掉 2019-7-3
        ;// _totalLength = downLoadedLength;//G_importance_parameter_data.http_server.load_length;
    }
    else if(_headerCheck == 0)
    {
    }

    if(finder == _bufferLength)
    {
        LOGD(L_APP, L_V1, "接收HEADER数据包，不写文件!");
        _bufferLength = 0;
        return;
    }
    if((G_realtime_data.http_server.filestyle == 2 && G_parameter.ste_status.lease == 0) || G_realtime_data.http_server.filestyle == 1)
    {
        if(G_realtime_data.http_server.filestyle == 2)
        {
            isDownLoadFile = 2;
        }
        else if(G_realtime_data.http_server.filestyle == 1)
        {
            isDownLoadFile = 1;
        }
        tr_start_timer(TRACK_CUST_HTTP_IS_DOWNLOAD_FILE_TIMER_ID, 30 * 1000, track_cust_isDownLoadFile);
    }
    ret = HTTP_file_write(&buf[finder], _packetLength, _totalLength);
    _bufferLength = 0;
    _totalLength += _packetLength;

    //G_importance_parameter_data.http_server.load_length = _totalLength;
    downLoadedLength = _totalLength;
    LOGD(L_APP, L_V5, "check_header_flag:%d,本次长度:%d,累计长度:%d,header_check:%d;总长度:%d,ret=%d,packet_len:%d", check_header_flag, _bufferLength, _totalLength, _headerCheck, fileTotalLength, ret, _packetLength);
    if(_totalLength == fileTotalLength)
    {
        FS_GetFileSize(radio_file.wfile_hd, &ota_size);
        //下面这条日志放在fota数据下载完后并修改名字完后，二期软件在优化
        check_header_flag = 0;
        _totalLength = 0;
        _bufferLength = 0;
        downLoadedLength = 0;
        Ram_Free(buf);
        buf = NULL;
        HTTP_file_init(1);
        LOGD(L_APP, L_V5, "file_true_len:%d", ota_size);
        if(G_realtime_data.httpdowncount < fileDownLoadCountMax)
        {
            G_realtime_data.httpdowncount = 0;
        }
        if(G_realtime_data.http_server.filestyle == 2)
        {
            if(ota_size != fileTotalLength || (fileTotalLength < 307200 || fileTotalLength > 365000))//409600//366586
            {
                setFotaFileTiming(2);
            }
            else
            {
                setFotaFileTiming(1);//一期90台使用定时器，二期直接修改名称
            }
        }
        memset(fat_file_name, 0, 40);
        if(G_realtime_data.http_server.filestyle == 1)
        {
            if(strlen(audioFileName) != 0)
            {
                AUDIO_file_memory(G_realtime_data.http_server.voice_Id, audioFileName);
                memset(audioFileName, 0, 30);
            }
            //G_realtime_data.temp_voicesize += fileTotalLength;//累加本次下载的文件数据数据
            G_realtime_data.http_server.isdownload = 0;
            G_realtime_data.http_server.filestyle = 0;
            setVoicefileTiming(G_realtime_data.http_server.voice_Id);
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        fileTotalLength = 0;
        isContinueLoading = 0;
        LOGD(5, 5, "文件下载完成！！！");
    }

}


static void HTTP_packet_login(void *par)
{
    //int request_len = 0;

    Socket_write_req(2, request, strlen(request), 0, 0, 0, 1);
    if(G_realtime_data.httpdowncount < 15)
    {
        G_realtime_data.httpdowncount += 1;
    }
    LOGD(L_APP, L_V5, "httpdowncount:%d", G_realtime_data.httpdowncount);

    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}

static void HTTP_server_disconnect(void)
{
    LOGD(L_APP, L_V5, "");
    socket_disconnect(2);
}

void HTTP_stop_connect(void)
{
    LOGD(L_APP, L_V5, "");

    tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID);
    tr_stop_timer(TRACK_HTTP_TIMEOUT_10min_TEIMER_ID);
    track_stop_timer(TRACK_CUST_NET_HTTP_LOGIN_TIMEOUT_TIMER_ID);
    track_stop_timer(TRACK_CUST_NET_HTTP_LOGIN_RESEND_TIMER_ID);
    track_stop_timer(TRACK_CUST_NET_HTTP_STOP_CONN_TIMER_ID);
    HTTP_server_disconnect();
}

static void HTTP_event(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;

    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                HTTP_Login_Success = KAL_FALSE;
                re_conn = 0;
                tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID);
                LOGD(L_APP, L_V5, "HTTP 服务器连接完成");
                track_os_intoTaskMsgQueueExt(HTTP_packet_login, NULL);
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                if(!track_is_timer_run(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID))
                {
                    tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 5000, HTTP_server_connect);
                }
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                LOGD(L_APP, L_V5, "HTTP 链接关闭,isdownload:%d", G_realtime_data.http_server.isdownload);
                HTTP_Login_Success = KAL_FALSE;

                if(G_realtime_data.http_server.isdownload == 1)
                {
                    tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 1000, HTTP_server_request);
                }
                else HTTP_stop_connect();

                break;
            }
        case SOC_RECV_DATA:
            {
                HTTP_data_recv(par->recvBuff, par->recvBuffLen);
                break;
            }
        case SOC_SEND_DATA:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "ERROR!!! id=%d", par->errorid);
                }
                else
                {
                    LOGD(L_APP, L_V5, "向HTTP服务器请求数据!!! id=%d", par->errorid);
                }
                break;
            }
        case SOC_RECV_HOST_BY_NAME:
            {
                if(par->errorid != 0)
                {
                    static kal_uint8 count = 0;
                    LOGD(L_APP, L_V1, "ERROR id=%d", par->errorid);
                    if(count < 10 && par->errorid == -14)
                    {
                        count++;
                        socket_disconnect(2);
                        tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 3000, HTTP_server_connect);//4
                    }
                    else
                    {
                        tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 30000, HTTP_server_connect);//1
                    }
                }
                else
                {
                    sockaddr_struct ip_addr = {0};
                    kal_int8 ret;
                    ip_addr.port = server_http.server_port;
                    LOGD(L_APP, L_V5, "hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         ip_addr.port);
                    ip_addr.addr_len = 4;
                    memcpy(ip_addr.addr, par->ip_from_hostname, 4);
                    ret = Socket_conn_req(2, &ip_addr, HTTP_event, 0);
                    LOGD(L_DRV, L_V1, "ret=%d", ret);
                }
                break;
            }
    }
}

static void HTTP_data_send(void *par)
{
    vec_gprs_socket_send_struct *buf = NULL;
    kal_uint32 tt = (U32)par;
    //kal_int8 ret = 0;//Socket_get_status(2);
    kal_int8 ret = Socket_get_write_status(2);
    int size;
    LOGD(L_APP, L_V5, "");
    if(HTTP_Login_Success == KAL_FALSE)
    {
        LOGD(L_APP, L_V5, "Login_Information_Success:%d", HTTP_Login_Success);
        return;
    }
    if(ret && HTTP_Login_Success)
    {
        LOGD(L_APP, L_V5, "Error : %d, Login_Information_Success:%d", ret, HTTP_Login_Success);
        //正在写,不能并发
        track_start_timer(TRACK_CUST_NET_HTTP_RESEND_TIMER_ID, 5000, HTTP_data_send, 0);
        return;
    }
    if(NULL == vec_send_http_queue)
    {
        VECTOR_CreateInstance(vec_send_http_queue);
    }
    if(tt == 1)
    {
        size = VECTOR_Size(vec_send_http_queue);
        if(size <= 0)
        {
            LOGD(L_APP, L_V5, "Warning: 1 size=0");
            return;
        }
        VECTOR_Erase2(vec_send_http_queue, 0, 1, KAL_FALSE);
    }

    size = VECTOR_Size(vec_send_http_queue);
    if(size <= 0)
    {
        LOGD(L_APP, L_V5, "Warning: 2 size=0");
        return;
    }
    buf = VECTOR_At(vec_send_http_queue, 0);
    if(!buf)
    {
        LOGD(L_APP, L_V5, "Error : VECTOR_At is NULL");
        return;
    }
    buf->lock = 1;
    Socket_write_req(2, buf->buffer, buf->len, 0, buf->packet_type, buf->no, 1);
    track_start_timer(TRACK_CUST_NET_HTTP_RESEND_TIMER_ID, 30000, HTTP_data_send, 0);
}
#if 0//2019-7-23 Liujw close
int HTTP_get_queue(void)
{
    if(NULL == vec_send_http_queue)
    {
        VECTOR_CreateInstance(vec_send_http_queue);
    }
    return VECTOR_Size(vec_send_http_queue);
}
void HTTP_server_queue_send_reg(kal_uint8* data, int len, kal_uint8 packet_type, kal_uint32 no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    vec_gprs_socket_send_struct* buf;
    int v_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_SOC, L_V5,  "data_len=%d, packet_type=%X", len, (U8)packet_type);

#if defined (__NETWORK_LICENSE__)
    return;
#endif /* __NETWORK_LICENSE__ */
    if(NULL == vec_send_http_queue)
    {
        VECTOR_CreateInstance(vec_send_http_queue);
    }
    if(len > MAX_SND_BUFFER_SIZE || len <= 0)
    {
        LOGD(L_SOC, L_V5,  "数据长度超出范围");
        return;
    }
    else
    {
        v_size = VECTOR_Size(vec_send_http_queue);
        if(v_size >= 100)
        {
            LOGD(L_SOC, L_V1, "内存报警队列数值已经满%d条，删除早期数据，保留最新数据!!!", v_size);
            VECTOR_Erase2(vec_send_http_queue, 0, 50, KAL_TRUE);
        }
        buf = (vec_gprs_socket_send_struct*)Ram_Alloc(3, sizeof(vec_gprs_socket_send_struct));
        if(buf)
        {
            buf->status = 0;
            memcpy(buf->buffer , data , len);
            buf->len = len;
            buf->no = no;
            buf->packet_type = packet_type;
            VECTOR_PushBack(vec_send_http_queue, buf);
        }
        else
        {
            LOGD(L_SOC, L_V1, "Ram_Alloc 申请临时内存空间失败!!!");
            track_cust_restart(22, 0);
        }
        track_os_intoTaskMsgQueueExt(HTTP_data_send, (void*)0);
    }
}
#endif

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void HTTP_server_connect(void)
{
    sockaddr_struct ip_addr = {0};
    kal_int8 ret;
    kal_uint16 crc;
    char *domain;

    LOGD(L_APP, L_V5, "HTTP联网请求");

#if defined (__NETWORK_LICENSE__)
    return;
    //禁止GPRS链接后台
#endif /* __NETWORK_LICENSE__ */
    if(NULL == vec_send_http_queue)
    {
        VECTOR_CreateInstance(vec_send_http_queue);
    }
    if(G_realtime_data.http_server.isdownload == 0)
    {
        LOGD(L_APP, L_V4, "没有数据需要更新，无需请求http服务器!");
        return;
    }
    if(G_realtime_data.httpdowncount >= fileDownLoadCountMax)
    {
        LOGD(L_APP, L_V4, "达到最大次数。%d", G_realtime_data.httpdowncount);
        return;
    }
    if(track_cust_status_sim() != 1)
    {
        if(track_is_testmode())
        {
            return;
        }
        LOGD(L_APP, L_V4, "SIM卡检测有误!");
        track_cust_get_sim_status();
        tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMER_ID, 5000, HTTP_server_connect);
        return;
    }

    if(!G_parameter.gprson)
    {
        LOGD(L_APP, L_V5, " 不联网");
        //return;
    }
    tr_stop_timer(TRACK_CUST_NET_HTTP_HEARTBEAT_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_HTTP_HEARTBEAT_OVERTIME_TIMER_ID);
    if(track_is_timer_run(TRACK_CUST_NET_HTTP_CONN_TIMER_ID) || track_is_timer_run(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID))
    {
        tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID);
    }

    domain = track_domain_decode(server_http.url);
    if(server_http.conecttype == 1 && strlen(domain) > 0)
    {
        LOGD(L_APP, L_V5, "domain:%s", domain);
        Socket_gethostbyname(domain, HTTP_event);
    }
    else
    {
        ip_addr.addr[0] = server_http.server_ip[0]; //112
        ip_addr.addr[1] = server_http.server_ip[1];//91
        ip_addr.addr[2] = server_http.server_ip[2];//114
        ip_addr.addr[3] = server_http.server_ip[3];//235
        ip_addr.port = (unsigned short)server_http.server_port;//8442 9080 10008
        ip_addr.addr_len = 4;
        LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
             server_http.server_ip[0],
             server_http.server_ip[1],
             server_http.server_ip[2],
             server_http.server_ip[3],
             server_http.server_port);
        //Login_Information_Success = KAL_FALSE;
        ret = Socket_conn_req(2, &ip_addr, HTTP_event, 0);
        LOGD(L_APP, L_V5, "ret=%d", ret);
        if(ret < 0)
        {
            tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMER_ID, 5000, HTTP_server_connect);
        }
    }
    tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 30000, HTTP_server_connect);
}

void HTTP_server_queue_init(void)
{
    if(NULL == vec_send_http_queue)
    {
        VECTOR_CreateInstance(vec_send_http_queue);
    }
}
void HTTP_server_reconnect(void *arg)
{
    kal_uint32  value = (kal_uint32)arg;
    track_soc_connstatus_enum conStatus = Socket_get_conn_status(2);
    LOGD(L_APP, L_V5, "value=%d,%d", value, conStatus);

    // 连接超时
    if(value > 4)
    {
        if(conStatus <= SOC_CONN_FAILURE)
        {
            HTTP_server_connect();
            track_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 30000, HTTP_server_reconnect, (void*)3);
        }
        else HTTP_server_disconnect();
    }
    else if(value == 3)
    {
        if(conStatus != SOC_CONN_SUCCESSFUL)
        {
            HTTP_server_connect();
            track_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 30000, HTTP_server_reconnect, (void*)4);
        }
    }
    else if(value == 4)
    {
        // 强制连接
        tr_stop_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID);
        HTTP_server_connect();
    }
}
kal_bool HTTP_server_login_status(void)
{
    return HTTP_Login_Success;
}

int HTTP_file_write(kal_uint8 *data, int len, int offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    fs_seek = FS_Seek(radio_file.wfile_hd, offset, 0);
    if(fs_seek < 0)
    {
        LOGD(L_DRV, L_V1, "fs_seek error %d", fs_seek);
        return -1;
    }

    fs_write = FS_Write(radio_file.wfile_hd, (void*)data, len, &file_operate_size);
    if(fs_write < 0)
    {
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -2;
    }
    FS_Commit(radio_file.wfile_hd);
    return file_operate_size;
}
static int HTTP_file_read(void* data, int length, int  Offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    LOGD(L_DRV, L_V5, "");

    fs_seek = FS_Seek(radio_file.wfile_hd, Offset, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V5, "FS_Seek %d", fs_seek);
        return -2;
    }

    fs_write = FS_Read(radio_file.wfile_hd, (void *)data, length , &file_operate_size);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(fs_write);
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -3;
    }
    FS_Commit(radio_file.wfile_hd);
    return file_operate_size;
}

int HTTP_file_init(kal_uint8 op)
{
    int ret = 0;
    kal_uint32   file_operate_size;
    static U8 first = 0;
    if(op == 9)
    {
        first = 0;
        return 0;
    }
    if(op == 10)
    {
        return first;
    }
    if(first == 0)
    {
        first = 1;
        //OTA_kal_wsprintf(fat_file_name, "%s", "unlock.mp3");
        //OTA_kal_wsprintf(radio_file.wfile_name, "%s", "unlock.mp3");
        //memset(fat_file_name, 0, 128);
        OTA_kal_wsprintf(radio_file.wfile_name, "%s", fat_file_name);
        radio_file.wfile_hd = FS_Open(fat_file_name , FS_CREATE | FS_READ_WRITE);
        ret = radio_file.wfile_hd;
        if(radio_file.wfile_hd < 0)
        {
            LOGD(L_DRV, L_V1, "ERROR %d", radio_file.wfile_hd);
        }
    }
    if(op == 1)//close
    {
        ret = FS_Close(radio_file.wfile_hd);
        first = 0;
    }
    else if(op == 2)
    {
        ret = FS_Close(radio_file.wfile_hd);
        LOGD(L_DRV, L_V1, "ret %d", ret);
        ret = FS_Delete(fat_file_name);
    }
    LOGD(L_DRV, L_V1, "ret %d", ret);

    return ret;

}
//--1.18版本要解决一个问题，如果只获取到了版本号，没有获取到语音列表，走到这里就不会去下载了,
//2019-7-8 问题已解决
void track_audio_file_checking(void* arg)
{
    kal_uint8 audio_temp[4] = {0};
    U8 result = 0;
    U8 _fileUpdate = 0;
    U8 _par = (U8)arg;
    U32 voiceID = 0;
    U8 tempVoiceVer[3] = {0};
    //u32 _tempVoiceId = 0;

    result = getVoicefileTiming(audio_temp);
    LOGH(5, 5, audio_temp, 4);
    if(result && _par == 1)
    {
        //这里检测语音ID是否已经存在
        //track_cust_N07_paket_0F(&audio_temp[1], 0x00, 3);好像协议已经改了30
        track_cust_N07_paket_0F(&audio_temp[1], 0x30, 3);
        track_start_timer(TRACK_HTTP_AUDIO_FILE_REQUEST_OVERTIME_TIMER_ID, 10 * 1000, track_audio_file_checking, (void*)1);
    }
    else
    {
        LOGD(L_APP, L_V5, "没有新的语音数据需要更新 %d,%d,%d,%d", G_realtime_data.file_update_style, G_parameter.voicefilesize, G_realtime_data.temp_voicesize, _par);
        LOGD(L_APP, L_V5, "0x%02X-0x%02X-0x%02X-0x%02X", G_realtime_data.voice_version_tmp[0], G_realtime_data.voice_version_tmp[1], G_realtime_data.voice_version_tmp[2], G_realtime_data.voice_version_tmp[3]);
        //存储语音总大小,这里只牵扯到语音编号的问题
        if(_par == 2)
        {
            memcpy(tempVoiceVer, G_realtime_data.http_server.voice_Id, 3);
            voiceID = ((tempVoiceVer[0] & 0x0000FF) << 16) | ((tempVoiceVer[1] & 0x0000FF) << 8) | tempVoiceVer[2];
            //_tempVoiceId = (G_parameter.voice_ver[1] & 0x0000FF) << 16 | (G_parameter.voice_ver[2] & 0x0000FF) << 8 | G_parameter.voice_ver[3];
            LOGD(L_APP, L_V5, "over load storage,%d", voiceID);
            if(voiceID > 1000)
            {
                voiceID -= 1;
                G_realtime_data.voice_version_tmp[1] = (voiceID & 0xFF0000);
                G_realtime_data.voice_version_tmp[2] = (voiceID & 0x00FF00);
                G_realtime_data.voice_version_tmp[3] = (voiceID & 0x0000FF);
            }
            else
            {
                voiceID = 1000;
                G_realtime_data.voice_version_tmp[1] = (voiceID & 0xFF0000);
                G_realtime_data.voice_version_tmp[2] = (voiceID & 0x00FF00);
                G_realtime_data.voice_version_tmp[3] = (voiceID & 0x0000FF);
            }
            fileTotalLength = 0;
            G_realtime_data.http_server.isdownload = 0;
        }
        G_realtime_data.http_server.filestyle = 0;
#if 0
        if((G_parameter.voicefilesize + G_realtime_data.temp_voicesize) < VOICE_FILES_SIZE)
        {
            G_parameter.voicefilesize += G_realtime_data.temp_voicesize;
        }
        else
        {
            G_realtime_data.temp_voicesize = 0;
        }
#endif
        if(G_realtime_data.voice_version_tmp[0] == 0x30 || _par == 2)
        {
            if(G_parameter.voice_ver[1] != G_realtime_data.voice_version_tmp[1] || G_parameter.voice_ver[2] != G_realtime_data.voice_version_tmp[2] || G_parameter.voice_ver[3] != G_realtime_data.voice_version_tmp[3])
            {
                LOGD(L_APP, L_V5, "storage version");
                memset(G_parameter.voice_ver, 0, 4);
                memcpy(G_parameter.voice_ver, G_realtime_data.voice_version_tmp, 4);
                //保存需要下载语音ID号
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            }
        }

        G_realtime_data.file_update_style &= 1;
        G_realtime_data.fota_update = 1;//标识固件升级
        memset(G_realtime_data.voice_version_tmp, 0, 4);
        //下载列表清零
        G_realtime_data.voice_max = 0;
        memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

        track_soc_gprs_reconnect((void*)21);
    }


}
int HTTP_continue_loading_check(int contentLength, int fileLength)
{
    if(G_realtime_data.http_server.file_length != fileLength)
    {
        LOGD(L_DRV, L_V1, "error 1断点续传检查出错 %d,%d", fileLength, G_realtime_data.http_server.file_length);
        return -1;
    }
    else if((G_realtime_data.http_server.file_length - G_realtime_data.http_server.load_length) != contentLength)
    {
        LOGD(L_DRV, L_V1, "error 2断点续传检查出错 %d,%d,%d", contentLength, G_realtime_data.http_server.file_length, G_realtime_data.http_server.load_length);
        return -2;
    }
    return 0;
}
void HTTP_continue_loading_error()
{
    HTTP_stop_connect();
    isContinueLoading = 0;
    G_realtime_data.http_server.file_length = 0;
    G_realtime_data.http_server.load_length = 0;
    HTTP_file_init(2);
}
void HTTP_server_request()
{
    LOGD(L_APP, L_V5, "");

    track_cust_test_http(NULL, 99);
}
void HTTP_abnormal_restart_roll_back()
{
    U8 isWrite = 0;
    LOGD(L_DRV, L_V1, "%d", G_realtime_data.file_update_style);
    //固件下载简单粗暴，直接删除标志位，等待下次推送
    if((G_realtime_data.file_update_style & 1) == 1) //(G_realtime_data.http_server.isdownload == 1 && G_realtime_data.http_server.filestyle == 2)// && G_importance_parameter_data.http_server.load_length)
    {
        LOGD(L_DRV, L_V1, "1");
        G_realtime_data.file_update_style = 0;
        if(HTTP_file_init(10) == 1)
        {
            HTTP_file_init(1);
        }
        OTA_kal_wsprintf(fat_file_name, "%s", TEMP_FILE_PATH);//干掉临时的bin文件
        FS_Delete(fat_file_name);
        memset(fat_file_name, 0, 40);
        HTTP_file_init(9);
        memset(&G_realtime_data.http_server, 0, sizeof(nvram_http_server_struct));
        isWrite = 1;
    }
    else if((G_realtime_data.file_update_style & 2) == 2)
    {
        //语音下载的问题在于是否已经获取到语音列表
        LOGD(L_DRV, L_V1, "2");
        if(G_realtime_data.voice_version_tmp[0] == 0 && G_realtime_data.voice_version_tmp[1] == 0 && G_realtime_data.voice_version_tmp[2] == 0 && G_realtime_data.voice_version_tmp[3] == 0) //没有获取到语音列表或者不需要下载
        {
        	tr_stop_timer(TRACK_CUST_VOICE_8F_TIMER_ID);
			tr_stop_timer(TRACK_CUST_VOICE_GET_LIST_TIMER_ID);
            G_realtime_data.file_update_style = 0;//还没有获取到语音列表，清掉语音下载标志位，重新获取
            isWrite = 1;
        }
        else//获取到了语音列表，已经准备下载
        {
            if(G_realtime_data.http_server.filestyle != 0)
            {
                G_realtime_data.http_server.filestyle = 0;
                isWrite = 1;
            }
            if(HTTP_file_init(10) == 1)
            {
                HTTP_file_init(1);
            }
            HTTP_file_init(9);
            track_audio_file_checking((void*)1);
        }
    }
    if(isWrite == 1)
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

}
void HTTP_web(char *web, kal_uint16 len)
{
    memset(http_web, 0, HTTP_MAX_PATH);
    memcpy(http_web, web, len);
    http_web[len] = '\0';
}

S32 rewrite_file(kal_uint8 *data, int len, int offset, int op)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;
    static int first = 0;
    WCHAR fileName[60];
    static FS_HANDLE fp = NULL;
    if(first == 0)
    {
        OTA_kal_wsprintf(fileName, FOTA_FILE_PATH);
        fp = FS_Open(fileName, FS_CREATE | FS_READ_WRITE);
        if(fp < 0)
        {
            return fp;
        }
        first = 1;
    }

    if(op == 1)
    {
        fs_seek = FS_Seek(fp, offset, 0);
        if(fs_seek < 0)
        {
            LOGD(L_DRV, L_V1, "fs_seek error %d", fs_seek);
            return -1;
        }
        fs_write = FS_Write(fp, (void*)data, len, &file_operate_size);
        if(fs_write < 0)
        {
            LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
            return -2;
        }
        FS_Commit(fp);
        return file_operate_size;
    }
    else if(op == 0)
    {
        FS_Close(fp);
        first = 0;
    }
    else if(op == 3)
    {
        FS_Delete(fileName);
        first = 0;
    }
    return file_operate_size;
}
void track_http_download_manager()
{
    //时间对比
    applib_time_struct tmpDate = {0};
    applib_dt_get_rtc_time(&tmpDate);
    if(tmpDate.nYear > 0)
    {
        tmpDate.nYear = tmpDate.nYear % 100;
    }
    if(G_realtime_data.httpdowndate[0] != tmpDate.nYear || G_realtime_data.httpdowndate[1] != tmpDate.nMonth || G_realtime_data.httpdowndate[2] != tmpDate.nDay)
    {
        LOGD(L_APP, L_V1, "return to zero!!!!");
        G_realtime_data.httpdowndate[0] = tmpDate.nYear;
        G_realtime_data.httpdowndate[1] = tmpDate.nMonth;
        G_realtime_data.httpdowndate[2] = tmpDate.nDay;
        G_realtime_data.httpdowncount = 0;//次数清零

        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    LOGD(L_APP, L_V5, "次数:%d,时间:%02d-%02d-%02d %02d:%02d:%02d,时间1:%02d-%02d-%02d", G_realtime_data.httpdowncount, tmpDate.nYear, tmpDate.nMonth
         , tmpDate.nDay, tmpDate.nHour, tmpDate.nMin, tmpDate.nSec, G_realtime_data.httpdowndate[0], G_realtime_data.httpdowndate[1], G_realtime_data.httpdowndate[2]);
}
