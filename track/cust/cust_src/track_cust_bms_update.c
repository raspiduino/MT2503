#if defined(__BMS_UPDATE__)
/******************************************************************************
 * track_cust_bms_update.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *       BMS升级文件
 *
 * modification history
 * --------------------
 * v1.0   2020-02-25,  xiongweiming create this file
 *
 ******************************************************************************/
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_cust_bms_update.h"
#include "Track_os_timer.h"

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
static char http_web[HTTP_MAX_PATH];
static const char *S_request_head = "GET %s HTTP/1.1\r\n" \
                                    "Accept: */*\r\n" \
                                    "Accept-Language: zh-cn\r\n" \
                                    "User-Agent: Molliza/4.0(compatible;MSIE6.0;windows NT 5.0)\r\n" \
                                    "Host: %s\r\n" \
                                    "%s" \
                                    "Connection: close\r\n\r\n";
static nvram_server_addr_struct server_http = {0};	//保存解析后的http服务器
static c_vector* vec_send_http_queue = NULL;
static kal_bool HTTP_Login_Success = KAL_FALSE;
//请求时的变量问题
static int check_header_flag = 0;//这个在打包好请求数据头时就要归零要归 0
static int fileTotalLength = 0;//需下载的文件总大小
static kal_uint32 downLoadedLength = 0;//已经下载数据大小
static FAT_FILE_ST bms_update_file = {0};//BMS升级文件读写
static WCHAR fat_file_name[40];//BMS的文件名称
static kal_uint32 bms_frame = 0;//帧数
static kal_uint8 bms_remainder = 0;//余数
static kal_uint8 is_remainder = 0;//是否有余数，0没有1有
static kal_uint16 frame_count = 0;//发送帧的计数器
static kal_uint8  resend_count = 0;//01,02,03,7F,2A包发送没有回应的重发次数，最大5次
static kal_uint8  update_lose_count = 0;//升级失败次数统计，最多5次
static kal_bool   is_start_update = KAL_FALSE;//没有开始，TRUE:在升级中
/*****************************************************************************
* Local variable           全局变量
*****************************************************************************/

char request[HTTP_MAX_REQUESTHEAD];
int request_len = 0;
char range2[] = "Range: bytes=0-\r\n";

/*
0: 表示指令下发查询版本号
1:    表示升级前查询一次版本号，保存为旧版本号
2: 表示升级是否完成的查询(收到03包后发7F包)
3: 表示平台下发52包查询升级信息
*/
kal_uint8  is_update_7f = 0;

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern nvram_parameter_struct			   G_parameter;


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/

/*****************************************************************************
 *  Global Functions	- Extern	    引用本地函数
*****************************************************************************/
static void HTTP_event(track_soc_Callback_struct *par);

/******************************************************************************
 *  Function    -  bms_file_init
 *
 *  Purpose     -  将BMS文件里的数据128个字节为一帧的读取出来
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-05,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 bms_file_init(kal_uint8 *bmsFile)
{
    kal_uint8 fileData[150] = {0};//
    int readsize = 0;
    WCHAR fileName[30] = {0};
    FS_HANDLE ret = 0;
    int fs_seek = 0, fs_read = 0;
    kal_uint32 file_offset = 0;//读取文件的偏移量

    OTA_kal_wsprintf(fileName, "%s", TEMP_FILE_PATH);
    ret = FS_Open(fileName, FS_READ_ONLY);

    if(ret < 0)
    {
        FS_Close(ret);
        LOGD(L_APP, L_V5, "Can not create this file! folder_hd:%d", ret);
        return -1;
    }

    LOGD(L_APP, L_V5, "当前帧数: %d,需要发送的帧数:%d", frame_count, bms_frame);

    if(frame_count == 0)//首帧
    {
        file_offset = 0;
        fs_seek = FS_Seek(ret, file_offset, FS_FILE_BEGIN);
    }
    else if(frame_count < bms_frame)
    {
        file_offset = frame_count * PAGE_SIZE;
        fs_seek = FS_Seek(ret, file_offset, FS_FILE_BEGIN);
    }


    if(fs_seek < 0)
    {
        LOGD(L_APP, L_V5, "ERROR1%d", fs_seek);
        return -2;
    }

    if(frame_count <= bms_frame - 1 && is_remainder == 0)
    {
        //没有余数，每帧都是128个字节
        fs_read = FS_Read(ret, fileData, PAGE_SIZE, &readsize);
        if(fs_read < 0)
        {
            LOGD(L_APP, L_V5, "ERROR2%d", fs_read);
            return -3;
        }
        memcpy(bmsFile, fileData, PAGE_SIZE);
    }
    else if(frame_count < bms_frame - 1)
    {
        //有余数，如有3帧数据，那么只有2帧是128个字节，最后一帧是余数
        fs_read = FS_Read(ret, fileData, PAGE_SIZE, &readsize);
        if(fs_read < 0)
        {
            LOGD(L_APP, L_V5, "ERROR3%d", fs_read);
            return -3;
        }
        memcpy(bmsFile, fileData, PAGE_SIZE);
    }
    else
    {
        //最后一帧是余数
        fs_read = FS_Read(ret, fileData, bms_remainder, &readsize);
        if(fs_read < 0)
        {
            LOGD(L_APP, L_V5, "ERROR4%d", fs_read);
            return -3;
        }
        memcpy(bmsFile, fileData, bms_remainder);
    }

    //LOGD(L_APP, L_V5, "%d", readsize);
    //LOGH(L_APP, L_V5, fileData, PAGE_SIZE);

    FS_Close(ret);
    return readsize;
}

/******************************************************************************
 *  Function    -  track_cust_paket_bms_head
 *
 *  Purpose     -  BMS打包包头和包尾
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_paket_bms_head(U8 cmd, kal_uint8* outData, kal_uint16 len)
{
    kal_uint8 temp[XH_PACKET_HEAD_LEN] = {0};
    kal_uint16 crc = 0;

    if(outData == NULL)
    {
        LOGD(L_APP, L_V5, "传入参数错误");
        return;
    }

    temp[0] = 0x3A;//包头
    temp[1] = 0x16;//包头
    temp[2] = cmd;

    temp[len - 2] = 0x0D; //包尾
    temp[len - 1] = 0x0A; //包尾

    memcpy(outData, temp, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_bms_calc_crc
 *
 *  Purpose     -  计算BMS校验数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint16 track_cust_packet_bms_calc_crc(kal_uint8 * data, kal_uint16 data_len)
{
    kal_uint16 crc;
    kal_uint16 i = 0;

    if(data == NULL || data_len == 0)
    {
        LOGD(L_APP, L_V3, "参数错误!");
        return 0xFF;
    }

    crc = data[i];
    while(++i < data_len)
    {
        crc += data[i];
    }

    return crc;
}

/******************************************************************************
 *  Function    -  track_cust_paket_bms_update_2A
 *
 *  Purpose     -  给BMS发送2A包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_bms_update_2A(void)
{
    kal_uint8 *sendData;
    kal_uint16 crc = 0;
    int size = 9;
    module_type IR_Owner_save = UART_GetOwnerID(uart_port1);

    sendData = (U8*)Ram_Alloc(5, size);

    if(sendData == NULL)
    {
        return;
    }

    memset(sendData, 0, size);

    track_cust_paket_bms_head(0x2A, sendData, size);

    sendData[3] = 0x01;//数据长度
    sendData[4] = 0x00;//数据内容

    //校验数据
    crc = track_cust_packet_bms_calc_crc(&sendData[1], 4);
    sendData[5] = (crc & 0x00FF);
    sendData[6] = (crc & 0xFF00) >> 8;

    //LOGH(L_APP, L_V5, sendData, size);

    UART_PutBytes(uart_port1, sendData, size , IR_Owner_save);//透传给串口1

    Ram_Free(sendData);

}

/******************************************************************************
 *  Function    -  track_cust_paket_bms_update_7F
 *
 *  Purpose     -  给BMS发送7F包
 *
 *  Description -  获取BMS的版本号
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_bms_update_7F(void)
{
    kal_uint8 *sendData;
    kal_uint16 crc = 0;
    int size = 9;
    module_type IR_Owner_save = UART_GetOwnerID(uart_port1);

    sendData = (U8*)Ram_Alloc(5, size);

    if(sendData == NULL)
    {
        return;
    }

    memset(sendData, 0, size);

    track_cust_paket_bms_head(0x7F, sendData, size);

    sendData[3] = 0x01;//数据长度
    sendData[4] = 0x00;//数据内容

    //校验数据
    crc = track_cust_packet_bms_calc_crc(&sendData[1], 4);
    sendData[5] = (crc & 0x00FF);
    sendData[6] = (crc & 0xFF00) >> 8;

    //LOGH(L_APP, L_V5, sendData, size);

    UART_PutBytes(uart_port1, sendData, size , IR_Owner_save);//透传给串口1

    Ram_Free(sendData);

}


/******************************************************************************
 *  Function    -  track_cust_paket_bms_update_01
 *
 *  Purpose     -  给BMS发送01包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_bms_update_01(void)
{
    kal_uint8 *sendData;
    kal_uint16 crc = 0;
    int size = 12;
    module_type IR_Owner_save = UART_GetOwnerID(uart_port1);

    sendData = (U8*)Ram_Alloc(5, size);

    if(sendData == NULL)
    {
        return;
    }

    memset(sendData, 0, size);

    track_cust_paket_bms_head(0x01, sendData, size);

    sendData[3] = 0x04;//数据长度
    sendData[4] = bms_frame && 0x00FF;//PAGE_NUM_L
    sendData[5] = (bms_frame && 0xFF00) >> 8;//PAGE_NUM_H
    sendData[6] = 0x80;//固定128个字节
    sendData[7] = 0x00;//固定128个字节，高位固定就位0了

    //校验数据
    crc = track_cust_packet_bms_calc_crc(&sendData[1], 7);
    sendData[8] = (crc & 0x00FF);
    sendData[9] = (crc & 0xFF00) >> 8;

    //LOGH(L_APP, L_V5, sendData, size);

    UART_PutBytes(uart_port1, sendData, size , IR_Owner_save);//透传给串口1

    Ram_Free(sendData);

}


/******************************************************************************
 *  Function    -  track_cust_paket_bms_update_02
 *
 *  Purpose     -  给BMS发送02包
 *
 *  Description -  给BMS发送更新的文件
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_bms_update_02(void)
{
    kal_uint8 *sendData;
    kal_uint16 crc = 0;
    int size = 0;
    kal_uint8 file_size[150] = 0;//文件的字节数
    module_type IR_Owner_save = UART_GetOwnerID(uart_port1);

    bms_file_init(file_size);

    LOGD(L_APP, L_V5, "frame_count = %d,bms_frame = %d,bms_remainder = %d", frame_count, bms_frame, bms_remainder);

    if(frame_count <= bms_frame - 1 && is_remainder == 0)
    {
        size = 138;
    }
    else if(frame_count < bms_frame - 1)
    {
        size = 138;
    }
    else
    {
        //剩余的字节数
        size = bms_remainder + 10;
    }


    sendData = (U8*)Ram_Alloc(5, size);

    if(sendData == NULL)
    {
        return;
    }

    memset(sendData, 0, size);

    track_cust_paket_bms_head(0x02, sendData, size);

    if(frame_count <= bms_frame - 1 && is_remainder == 0)
    {
        sendData[3] = 0x82;//数据长度128 + 2的数据长度
        sendData[4] = (frame_count & 0x00FF);		//Frame_L
        sendData[5] = (frame_count & 0xFF00) >> 8;//Frame_H
        memcpy(&sendData[6], file_size, 128);
        frame_count++;
    }
    else if(frame_count < bms_frame - 1)
    {
        sendData[3] = 0x82;//数据长度128 + 2的数据长度
        sendData[4] = (frame_count & 0x00FF);		//Frame_L
        sendData[5] = (frame_count & 0xFF00) >> 8;//Frame_H
        memcpy(&sendData[6], file_size, 128);
        frame_count++;
    }
    else
    {
        sendData[3] = bms_remainder + 2;	//剩余多少个字节
        sendData[4] = (frame_count & 0x00FF);		//Frame_L
        sendData[5] = (frame_count & 0xFF00) >> 8;//Frame_H
        memcpy(&sendData[6], file_size, bms_remainder);
        frame_count++;
    }

    //校验数据
    crc = track_cust_packet_bms_calc_crc(&sendData[1], size - 5);
    sendData[size - 4] = (crc & 0x00FF);
    sendData[size - 3] = (crc & 0xFF00) >> 8;

    //LOGH(L_APP, L_V5, sendData, size);

    UART_PutBytes(uart_port1, sendData, size , IR_Owner_save);//透传给串口1

    Ram_Free(sendData);

}


/******************************************************************************
 *  Function    -  track_cust_paket_bms_update_03
 *
 *  Purpose     -  给BMS发送03包
 *
 *  Description -  查询BMS是否接收完升级文件
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-02-25,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_bms_update_03(void)
{
    kal_uint8 *sendData;
    kal_uint16 crc = 0;
    int size = 9;
    module_type IR_Owner_save = UART_GetOwnerID(uart_port1);

    sendData = (U8*)Ram_Alloc(5, size);

    if(sendData == NULL)
    {
        return;
    }

    memset(sendData, 0, size);

    track_cust_paket_bms_head(0x03, sendData, size);

    sendData[3] = 0x01;//数据长度
    sendData[4] = 0x00;//数据内容

    //校验数据
    crc = track_cust_packet_bms_calc_crc(&sendData[1], 4);
    sendData[5] = (crc & 0x00FF);
    sendData[6] = (crc & 0xFF00) >> 8;


    //LOGH(L_APP, L_V5, sendData, size);

    UART_PutBytes(uart_port1, sendData, size , IR_Owner_save);//透传给串口1

    Ram_Free(sendData);

}


/******************************************************************************
 *  Function    -  track_cust_bms_send_update_file
 *
 *  Purpose     -  发送升级文件到BMS
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-10,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_bms_send_update_file(void)
{
    applib_time_struct start_update_time = {0};//升级开始时间
    frame_count = 0;//发送首帧，帧数计数器清零

    //applib_dt_get_rtc_time(&start_update_time);
    track_fun_get_time(&start_update_time, KAL_FALSE, &G_parameter.zone);

    /*年月日*/
    G_parameter.bms_date.bms_start_time.nYear = start_update_time.nYear;
    G_parameter.bms_date.bms_start_time.nMonth = start_update_time.nMonth;
    G_parameter.bms_date.bms_start_time.nDay = start_update_time.nDay;

    /* 时分秒 */
    G_parameter.bms_date.bms_start_time.nHour = start_update_time.nHour;
    G_parameter.bms_date.bms_start_time.nMin = start_update_time.nMin;
    G_parameter.bms_date.bms_start_time.nSec = start_update_time.nSec;

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    LOGD(L_APP, L_V5, "升级开始时间%02d-%02d-%02d-%02d-%02d-%02d", G_parameter.bms_date.bms_start_time.nYear, G_parameter.bms_date.bms_start_time.nMonth,
         G_parameter.bms_date.bms_start_time.nDay, G_parameter.bms_date.bms_start_time.nHour, G_parameter.bms_date.bms_start_time.nMin, G_parameter.bms_date.bms_start_time.nSec);
    bms_file_get_frame_remiander();//初始化需要发送的帧数和余数
    track_cust_paket_bms_update_02();//发送BIN文件给BMS
}

/******************************************************************************
 *  Function    -  track_cust_bms_send_7F_packet
 *
 *  Purpose     -  重发07包机制
 *
 *  Description -   重发5次，如果都没有回复，那么升级失败，需要重新升级
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-10,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_bms_send_7F_packet(void)
{
    LOGD(L_APP, L_V5, "发送7F包的次数:%d", resend_count);

    track_cust_paket_bms_update_7F();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_7F_TIMER_ID) && resend_count < 5)
    {
        resend_count++;
        tr_start_timer(TRACK_CUST_BMS_SEND_7F_TIMER_ID, 5000, track_cust_bms_send_7F_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
        resend_count = 0;//次数重新置为0
        is_update_7f = 0;
		is_start_update = KAL_FALSE;
        track_stop_timer(TRACK_CUST_BMS_SEND_7F_TIMER_ID);
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_send_01_packet
 *
 *  Purpose     -  发送01包
 *
 *  Description -   做重发机制，默认5次
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-10,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_send_01_packet(void)
{
    LOGD(L_APP, L_V5, "发送01包的次数:%d", resend_count);
    track_cust_paket_bms_update_01();

    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_01_TIMER_ID) && resend_count < 5)
    {
        resend_count++;
        tr_start_timer(TRACK_CUST_BMS_SEND_01_TIMER_ID, 2000, track_cust_bms_send_01_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
		is_start_update = KAL_FALSE;
        resend_count = 0;//次数重新置为0
        track_stop_timer(TRACK_CUST_BMS_SEND_01_TIMER_ID);
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_send_2A_packet
 *
 *  Purpose     -  发送2A包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-10,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_send_2A_packet(void)
{

	if(G_realtime_data.http_server.isdownload == 1)
	{
		LOGD(L_APP, L_V5, "升级文件下载失败");
		is_start_update = KAL_FALSE;
		track_cust_paket_bms_update_51(0x03);
		return;
	}
	
    LOGD(L_APP, L_V5, "发送2A包的次数:%d", resend_count);

    track_cust_paket_bms_update_2A();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_2A_TIMER_ID) && resend_count < 5)
    {
        resend_count++;
        tr_start_timer(TRACK_CUST_BMS_SEND_2A_TIMER_ID, 5000, track_cust_bms_send_2A_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
		is_start_update = KAL_FALSE;
        resend_count = 0;//次数重新置为0
        track_stop_timer(TRACK_CUST_BMS_SEND_2A_TIMER_ID);
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_resend_2A_packet
 *
 *  Purpose     -  为了区分是因为传输02包没有回应时重新发送2A包
 *
 *  Description -   文件失败次数和升级失败次数是叠加的
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_resend_2A_packet(void)
{
    update_lose_count++;
    LOGD(L_APP, L_V5, "发送2A包的次数:%d,发送文件失败次数:%d", resend_count, update_lose_count);

    track_cust_paket_bms_update_2A();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_2A_TIMER_ID) && resend_count < 5)
    {
        resend_count++;
        tr_start_timer(TRACK_CUST_BMS_SEND_2A_TIMER_ID, 5000, track_cust_bms_send_2A_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
        resend_count = 0;//次数重新置为0
        update_lose_count = 0;//次数重新置为0
        is_start_update = KAL_FALSE;
        track_stop_timer(TRACK_CUST_BMS_SEND_2A_TIMER_ID);
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_send_03_packet
 *
 *  Purpose     -  发送03包
 *
 *  Description -  要做重发机制，最多5次，多了为升级失败
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_send_03_packet(void)
{
    LOGD(L_APP, L_V5, "发送03包的次数:%d", resend_count);

    track_cust_paket_bms_update_03();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_03_TIMER_ID) && resend_count < 5)
    {
        resend_count++;
        tr_start_timer(TRACK_CUST_BMS_SEND_03_TIMER_ID, 2000, track_cust_bms_send_03_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
		is_start_update = KAL_FALSE;
        resend_count = 0;//次数重新置为0
        track_stop_timer(TRACK_CUST_BMS_SEND_03_TIMER_ID);
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}


/******************************************************************************
 *  Function    -  track_cust_bms_send_02_first_packet
 *
 *  Purpose     -  发送02包
 *
 *  Description -  如果BMS没有相应02包的报文，那么说明升级失败，
 *				需要从2A包重新开始(客户提示)
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_send_02_first_packet(void)
{
    track_cust_bms_send_update_file();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID) && update_lose_count < 5)
    {
        tr_start_timer(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID, 2000, track_cust_bms_resend_2A_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
        track_stop_timer(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID);
		is_start_update = KAL_FALSE;
        update_lose_count = 0;//失败清0
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);

    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_send_02_packet
 *
 *  Purpose     -  发送剩余的02帧到BMS
 *
 *  Description -   与第一帧区分只是为了不频繁写NVRAM保存升级时间
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-11,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_bms_send_02_packet(void)
{
    track_cust_paket_bms_update_02();
    if(!track_is_timer_run(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID) && update_lose_count < 5)
    {
        LOGD(L_APP, L_V5, "发送文件失败次数:%d", update_lose_count);
        tr_start_timer(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID, 2000, track_cust_bms_resend_2A_packet);
    }
    else
    {
        LOGD(L_APP, L_V5, "升级失败!!");
        track_stop_timer(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID);
		is_start_update = KAL_FALSE;
        update_lose_count = 0;//失败清0
        G_parameter.bms_date.bms_update_result = 0;//升级失败
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_paket_bms_update_51(0x00);
    }
}

/******************************************************************************
 *  Function    -  track_cust_bms_data_analyze
 *
 *  Purpose     -  解析BMS传过来的数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-09,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_bms_data_analyze(kal_uint8 *data, kal_uint8 cmd, kal_uint16 len)
{
    applib_time_struct finish_update_time = {0};//升级完成时间

    LOGH2(L_APP, L_V5, "", data, len);

    switch(cmd)
    {
        case 0x2A:
            resend_count = 0;//有回应，置零
            track_stop_timer(TRACK_CUST_BMS_SEND_2A_TIMER_ID);
            if(data[5] == 0x00)//在APP中运行，需要切换到IAP模式下
            {
                LOGD(L_APP, L_V5, "在APP模式下");
                is_update_7f = 1;
                track_cust_bms_send_7F_packet();//查询当前的版本号
            }
            else if(data[5] == 0x01)//在IAP中运行，发送02包的首帧给BMS
            {
                LOGD(L_APP, L_V5, "发送首帧文件到BMS");
                track_cust_bms_send_02_first_packet();
            }
            break;

        case 0x01:
			LOGD(L_APP, L_V5, "切换到IAP模式");
            resend_count = 0;//有回应，置零
            track_stop_timer(TRACK_CUST_BMS_SEND_01_TIMER_ID);
            track_cust_bms_send_2A_packet();//清除FLASH
            break;

        case 0x02:
            track_stop_timer(TRACK_CUST_BMS_SEND_02_LOSE_TIMER_ID);
            if(frame_count < bms_frame)
            {
                LOGD(L_APP, L_V5, "发送BIN文件到BMS");
                track_cust_bms_send_02_packet();
            }
            else
            {
                LOGD(L_APP, L_V5, "发完升级文件,检查BMS是否升级成功");
                track_cust_bms_send_03_packet();
            }
            break;

        case 0x03:
            resend_count = 0;//有回应，置零
            track_stop_timer(TRACK_CUST_BMS_SEND_03_TIMER_ID);
            if(data[4] == 0x00)
            {
                LOGD(L_APP, L_V5, "发送7F包验证是否升级成功!");
                is_update_7f = 2;
                track_cust_bms_send_7F_packet();
            }
            else
            {
                LOGD(L_APP, L_V5, "升级失败,重新升级次数:%d", update_lose_count);
                if(update_lose_count <= 5)
                {
                    update_lose_count++;
                    track_cust_bms_send_2A_packet();
                }
                else
                {
                    update_lose_count = 0;//失败清0
                    G_parameter.bms_date.bms_update_result = 0;//升级失败
                    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                    track_cust_paket_bms_update_51(0x00);
                }
            }
            break;

        case 0x7F:
            if(is_update_7f == 1)
            {
                LOGD(L_APP, L_V5, "升级前查询版本号，保存为旧版本号");
                is_update_7f = 0;
                resend_count = 0;//查询成功清零
                G_parameter.bms_date.bmsVersion = data[5];//此时的版本号保存为旧版本号
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            }
            else
            {
                LOGD(L_APP, L_V5, "升级成功");
                is_update_7f = 0;
				is_start_update = KAL_FALSE;
                update_lose_count = 0;//升级成功清零
                resend_count = 0;//升级成功清零
                //applib_dt_get_rtc_time(&finish_update_time);
				track_fun_get_time(&finish_update_time, KAL_FALSE, &G_parameter.zone);

                /*年月日*/
                G_parameter.bms_date.bms_finish_time.nYear = finish_update_time.nYear;
                G_parameter.bms_date.bms_finish_time.nMonth = finish_update_time.nMonth;
                G_parameter.bms_date.bms_finish_time.nDay = finish_update_time.nDay;

                /* 时分秒 */
				G_parameter.bms_date.bms_finish_time.nHour =finish_update_time.nHour; 
				G_parameter.bms_date.bms_finish_time.nMin = finish_update_time.nMin;
				G_parameter.bms_date.bms_finish_time.nSec = finish_update_time.nSec;

                LOGD(L_APP, L_V5, "升级结束时间%02d-%02d-%02d-%02d-%02d-%02d", G_parameter.bms_date.bms_finish_time.nYear, G_parameter.bms_date.bms_finish_time.nMonth,
                     G_parameter.bms_date.bms_finish_time.nDay, G_parameter.bms_date.bms_finish_time.nHour, G_parameter.bms_date.bms_finish_time.nMin, G_parameter.bms_date.bms_finish_time.nSec);
                G_parameter.bms_date.bms_update_result = 1;//升级成功
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                track_cust_paket_bms_update_51(0x01);
            }
            break;

        default:
            break;
    }
}

/******************************************************************************
 *  Function    -  track_cust_receive_update_bms_date
 *
 *  Purpose     -  BMS发过来的数据进行过滤
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-05,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_receive_update_bms_date(kal_uint8* datas, kal_uint16 len)
{
    kal_uint8 i = 0, j = 0;
    kal_uint8 cmd = 0, addid = 0, cmdlen = 0;

    if(datas[0] != 0x3A || len <= 0 || datas[1] != 0x16)
    {
        LOGD(L_APP, L_V5, "包内容错误!!");
        return;
    }

    if(datas[i] == 0x3A)
    {
        addid = datas[i + 1];
        cmd = datas[i + 2];
        cmdlen = datas[i + 3];
    }

    LOGD(L_APP, L_V5, "cmd:%02X,addid:%x,cmdlen:%x", cmd, addid, cmdlen);
    j = cmdlen + 3;
    j += 2;

    if(datas[j + 1] == 0x0D && datas[j + 2] == 0x0A)
    {
        i += 4;
        track_cust_bms_data_analyze(datas, cmd, len);
    }
}

/******************************************************************************
 *  Function    -  bms_file_get_frame_remiander
 *
 *  Purpose     -  返回文件的帧数和余数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-04,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void bms_file_get_frame_remiander(void)
{
    kal_uint32 frame_num = 0;//帧数
    kal_uint8 remainder = 0;//余数

    frame_num = G_realtime_data.http_server.load_length / PAGE_SIZE;

    if(frame_num < 0)
    {
        LOGD(L_APP, L_V5, "升级文件错误!!!");
        return;
    }

    if(frame_num * PAGE_SIZE != G_realtime_data.http_server.load_length)
    {
        remainder = G_realtime_data.http_server.load_length % PAGE_SIZE;//求余数
        frame_num = frame_num + 1;//有余数需要多增加一帧
        bms_frame = frame_num;//帧数
        bms_remainder = remainder;//余数
        is_remainder = 1;
    }
    else
    {
        bms_frame = frame_num;//帧数
        remainder = 0;
        bms_remainder = remainder;//余数
        is_remainder = 0;
    }

    LOGD(L_APP, L_V5, "该文件的帧数:%d,余数为:%d , 是否有余数:%d", bms_frame, bms_remainder, is_remainder);
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
        //OTA_kal_wsprintf(bms_update_file.wfile_name, "%s", "unlock.mp3");
        //memset(fat_file_name, 0, 128);
        OTA_kal_wsprintf(bms_update_file.wfile_name, "%s", fat_file_name);
        bms_update_file.wfile_hd = FS_Open(fat_file_name , FS_CREATE | FS_READ_WRITE);
        ret = bms_update_file.wfile_hd;
        if(bms_update_file.wfile_hd < 0)
        {
            LOGD(L_DRV, L_V1, "ERROR %d", bms_update_file.wfile_hd);
        }
    }
    if(op == 1)//close
    {
        ret = FS_Close(bms_update_file.wfile_hd);
        first = 0;
    }
    else if(op == 2)
    {
        ret = FS_Close(bms_update_file.wfile_hd);
        LOGD(L_DRV, L_V1, "ret %d", ret);
        ret = FS_Delete(fat_file_name);
    }
    LOGD(L_DRV, L_V1, "ret %d", ret);

    return ret;

}

/******************************************************************************
 *  Function    -  HTTP_web
 *
 *  Purpose     -  将URL放到变量http_web里面
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-01,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void HTTP_web(char *web, kal_uint16 len)
{
    memset(http_web, 0, HTTP_MAX_PATH);
    memcpy(http_web, web, len);
    http_web[len] = '\0';
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


/******************************************************************************
 *  Function    -  package_request
 *
 *  Purpose     -  标准的HTTP数据请求打包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-01,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
int package_request(char *request, const char *web, const char *filepath, char *range)
{
    int n = sprintf(request, S_request_head, filepath, web, range);
    request[n] = '\0';
    return n;
}

/******************************************************************************
 *  Function    -  parse_url
 *
 *  Purpose     -  解析URL，分辨解析出：域名，端口，文件路径和文件名
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-01,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
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


    if(!strncmp(url, "http://", 7))
    {
        web_start = 7;
    }
    else if(!strncmp(url, "https://", 8))
    {
        web_start = 8;
    }

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

    LOGD(L_APP, L_V5, "web_len %d", web_len);

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

#if 0
    if(G_realtime_data.httpdowncount >= fileDownLoadCountMax)
    {
        LOGD(L_APP, L_V4, "达到最大次数。%d", G_realtime_data.httpdowncount);
        return;
    }
#endif

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
    HTTP_server_disconnect();
}

void HTTP_continue_loading_error()
{
    HTTP_stop_connect();
    //isContinueLoading = 0;
    G_realtime_data.http_server.file_length = 0;
    G_realtime_data.http_server.load_length = 0;
    HTTP_file_init(2);
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

        G_realtime_data.http_server.isdownload = 0;

        if(stamp == 1)
        {
            OTA_kal_wsprintf(newFileName, "%s", FOTA_FILE_PATH);
            ret = OTA_FS_Rename(fat_file_name, newFileName);
            if(ret == 0)//FS_NO_ERROR:0
            {
                //G_realtime_data.fota_update = 1;//标识固件升级
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
                IsWrite = 1;
            }
            else
            {
                ret = FS_Delete(fat_file_name);
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
        single_len = track_fun_atoi(l_p + 1);
    }

    if(r_p == NULL)
    {
        fileTotalLength = single_len;
    }

#if 0
    if(isContinueLoading && HTTP_continue_loading_check(single_len, fileTotalLength) < 0)
    {
        LOGD(L_APP, L_V1, "error!!!断点续传数据验证失败，总大小计算出错!");
        HTTP_continue_loading_error();
        return -1;
    }
#endif

    LOGD(L_APP, L_V5, "文件下载开始！本次数据长度：%d,数据总大小:%d,range:%d", single_len , fileTotalLength, range);
    setFotaFileTiming(0);
    G_realtime_data.http_server.file_length = fileTotalLength;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    return range;
}

int HTTP_file_write(kal_uint8 *data, int len, int offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    fs_seek = FS_Seek(bms_update_file.wfile_hd, offset, 0);
    if(fs_seek < 0)
    {
        LOGD(L_DRV, L_V1, "fs_seek error %d", fs_seek);
        return -1;
    }

    fs_write = FS_Write(bms_update_file.wfile_hd, (void*)data, len, &file_operate_size);
    if(fs_write < 0)
    {
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -2;
    }
    FS_Commit(bms_update_file.wfile_hd);
    return file_operate_size;
}


/******************************************************************************
 *  Function    -  HTTP_data_recv
 *
 *  Purpose     -  对接收的数据包进行拆分
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-03,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
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
        if(buf[i] == 0x48 && buf[i + 1] == 0x54 && buf[i + 2] == 0x54 && buf[i + 3] == 0x50)
        {
            check_header_flag  = 1;
            //continue;
        }

        if(check_header_flag == 1 && buf[i] == 0x0D && buf[i + 1] == 0x0A && buf[i + 2] == 0x0D && buf[i + 3] == 0x0A)
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

    ret = HTTP_file_write(&buf[finder], _packetLength, _totalLength);
    _bufferLength = 0;
    _totalLength += _packetLength;

    //G_importance_parameter_data.http_server.load_length = _totalLength;
    downLoadedLength = _totalLength;
    LOGD(L_APP, L_V5, "check_header_flag:%d,本次长度:%d,累计长度:%d,header_check:%d;总长度:%d,ret=%d,packet_len:%d", check_header_flag, _bufferLength, _totalLength, _headerCheck, fileTotalLength, ret, _packetLength);
    if(_totalLength == fileTotalLength)
    {
        FS_GetFileSize(bms_update_file.wfile_hd, &ota_size);
        //下面这条日志放在fota数据下载完后并修改名字完后，二期软件在优化
        check_header_flag = 0;
        _totalLength = 0;
        _bufferLength = 0;
        downLoadedLength = 0;
        Ram_Free(buf);
        buf = NULL;
        HTTP_file_init(1);
        G_realtime_data.http_server.load_length = ota_size;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        LOGD(L_APP, L_V5, "file_true_len:%d", ota_size);

        if(ota_size != fileTotalLength)
        {
            setFotaFileTiming(2);
        }
        else
        {
            setFotaFileTiming(1);//一期90台使用定时器，二期直接修改名称
        }

        memset(fat_file_name, 0, 40);
        fileTotalLength = 0;
        //isContinueLoading = 0;
        HTTP_server_disconnect();
        LOGD(5, 5, "文件下载完成！！！");
    }

}


static void HTTP_packet_login(void *par)
{
    Socket_write_req(2, request, strlen(request), 0, 0, 0, 1);
}


static void HTTP_event(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;

    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                HTTP_Login_Success = KAL_TRUE;
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
                    tr_start_timer(TRACK_CUST_NET_HTTP_CONN_TIMEOUT_TIMER_ID, 1000, HTTP_server_connect);
                }
                else
                {
                    HTTP_stop_connect();
                }
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


/******************************************************************************
 *  Function    -  track_cust_packet_conn_http
 *
 *  Purpose     -  去连接HTTP服务器
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-03,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_conn_http(kal_uint8 * data, kal_uint16 len)
{
    kal_uint8 HTTP_LINK[500] = {0};
    int webLength = 0;
    char web[HTTP_MAX_PATH + 1];
    int port;
    char remote_path[HTTP_MAX_PATH + 1];
    char remote_file[HTTP_MAX_PATH + 1];
    kal_uint8 *finder = NULL;

    LOGH(L_APP, L_V5, data, len);

	//标志BMS升级流程开始
	is_start_update = KAL_TRUE;

    webLength = len - 3;

    if(len > 259)
    {
        LOGD(L_APP, L_V1, "error0，link addr259[%d]!", len);
        return;
    }

    memcpy(HTTP_LINK, &data[1], webLength);
    memset(&G_realtime_data.http_server, 0, sizeof(nvram_http_server_struct));
    HTTP_web(HTTP_LINK, webLength);
    G_realtime_data.http_server.isdownload = 1;//文件未下载完成
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

    LOGD(L_APP, L_V5, "向HTTP服务器请求升级数据");

    parse_url(http_web, web, &port, remote_path, remote_file);

    LOGD(L_APP, L_V5, "%d,%s,%s,%s", port, web, remote_path, remote_file);

    if(strstr(remote_file, ".BIN") || strstr(remote_file, ".bin"))
    {
        OTA_kal_wsprintf(fat_file_name, "%s", TEMP_FILE_PATH);
    }
    else
    {
        LOGD(L_APP, L_V1, "error!文件格式错误！返回,%s", remote_file);
        return;
    }

    memset(request, 0, HTTP_MAX_REQUESTHEAD);

    fileTotalLength = 0;
    check_header_flag = 0;
    request_len = package_request(request, web, remote_path, range2);

    LOGD(L_APP, L_V5, "%d,%s", request_len, request);
    //这里将域名和端口进行重新解析
    finder = strchr(web, ':');
    HTTP_file_init(3);

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

/******************************************************************************
 *  Function    -  track_cust_update_bms_start
 * 
 *  Purpose     -  开始升级BMS入口
 * 
 *  Description -  当已经开始升级的时候，在收到升级指令不相应
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-12,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_update_bms_start(kal_uint8 * bin_data, kal_uint16 bin_len)
{
    if(is_start_update == KAL_TRUE)
    {
		LOGD(L_APP, L_V5, "已经开始升级，请勿一直发升级指令!");
		return;
	}

    track_cust_packet_conn_http(bin_data, bin_len);
	//等待BIN文件的下载，40秒以后开始升级
	tr_start_timer(TRACK_CUST_BMS_START_UPDATE_TIMER_ID, 40 * 1000, track_cust_bms_send_2A_packet);
}
#endif
