#if defined(__BMS_UPDATE__)
/****************************************************************************
***file author: xiongweiming
***creat date:2020-03-03
***introduction:
****************http 下载协议头文件
****************
****************************************************************************/

#include "track_cust.h"
#include "c_vector.h"

#define HTTP_MAX_PATH 			260     //HTTP 最大地址长度
#define DEF_HTTP_PORT			80		//HTTP 的端口号
#define HTTP_MAX_REQUESTHEAD    1024
#define TEMP_FILE_PATH			"BMSTRACK.BIN"//零时的BIN文件
#define PAGE_SIZE 				128		 //固定的一页数据字节数
#define XH_PACKET_HEAD_LEN      150

//#define FRAME_L					255		

typedef struct
{
    int         iDrvLetter;
    WCHAR       wfile_name[64];
    FS_HANDLE   wfile_hd;
    kal_uint32  writen_size;
#if !defined (__REMOVE_LOG_TO_FILE__)
    c_string*   string;
#endif /* __REMOVE_LOG_TO_FILE__ */
} FAT_FILE_ST;

void track_cust_packet_conn_http(kal_uint8 * data, kal_uint16 len);
void bms_file_get_frame_remiander(void);
#endif