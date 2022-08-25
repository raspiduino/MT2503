/****************************************************************************
***file author: Liujw
***creat date:2018-05-09
***introduction:
****************http 下载协议头文件
****************
****************************************************************************/

#include "track_cust.h"
#include "c_vector.h"

#define HTTP_MAX_PATH 260
#define HTTP_MAX_REQUESTHEAD 1024
#define DEF_HTTP_PORT 80
#define SINGLE_DATA_LEN 800//2048
#define __HTTP_TEST__
#define TEMP_FILE_PATH		"TEMPTRACK.BIN"

typedef struct
{
    kal_uint8   buffer[MAX_SND_BUFFER_SIZE];
    int         status; /* 状态:  0 等待中  ;   1 正在发送 */
    int         len;
    kal_uint32  no;
    kal_uint8   packet_type;              // 数据包类型
    kal_uint8   lock;                     // 正在发送数据时避免进行删除
} vec_gprs_socket_send_struct;

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

extern void HTTP_server_connect(void);
extern void HTTP_server_reconnect(void * arg);
 
extern int  HTTP_file_init(kal_uint8 op);
extern int HTTP_file_write(kal_uint8 *data, int len, int offset);
extern void track_audio_file_checking(void* arg);
extern void AUDIO_file_memory(kal_uint8 *voiceID, char *fileName);
extern void setVoicefileTiming(kal_uint8 *voice_id);

