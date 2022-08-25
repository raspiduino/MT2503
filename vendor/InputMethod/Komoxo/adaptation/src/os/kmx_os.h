
#ifndef KMX_OS_H
#define KMX_OS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

/****************************************************************************

Basic data types.

****************************************************************************/

/*{{ basic_types {{*/

#ifndef TRUE
    #define TRUE            1
#endif

#ifndef FALSE
    #define FALSE           0
#endif

#ifndef NULL
    #define NULL            0
#endif

typedef int             KMXSTATUS;
typedef unsigned int    KMXPARAM;
typedef unsigned short  KMXWCHAR;



#define KMX_STATUS_OK                        0
#define KMX_STATUS_ERROR                     1
#define KMX_STATUS_NOT_INITIALIZED           2
#define KMX_STATUS_INVALID_PARAMETER         3
#define KMX_STATUS_OUT_OF_MEMORY             4
#define KMX_STATUS_NOT_SUPPORTED             5
#define KMX_STATUS_EXIT_APP                  6
#define KMX_STATUS_NOT_HANDLED               7
#define KMX_STATUS_TIME_OUT                  8
#define KMX_STATUS_BUFFER_FULL               9
#define KMX_STATUS_FILE_NOT_FOUND            10
#define KMX_STATUS_MISSING_IMPORT            11
#define KMX_STATUS_CONNECTION_END            12
#define KMX_STATUS_NO_UPDATE_AVALIABLE       13     



#define KMX_EVENT_CHANNEL_RESPONSE   40
/* param1: TTSTATUS status
 * param2: Not used, must be 0
 */

#define KMX_EVENT_HTTP_RESPONSE      41
/* param1: const TT_OS_HTTP_RESPONSE* response
 * param2: Not used, must be 0
 */

/****************************************************************************

Network interface.

****************************************************************************/

/*{{ os_network {{*/

#define KMX_HTTP_METHOD_GET      0
#define KMX_HTTP_METHOD_POST     1

typedef struct
{
    unsigned int                id;
    int                         method;
    char*                       url;
    char*                       header;
    char*                       post_data;
} KMX_OS_HTTP_REQUEST;

#define KMX_HTTP_FLAG_STATUS     0x01
#define KMX_HTTP_FLAG_HEADER     0x02
#define KMX_HTTP_FLAG_CONTENT    0x04

typedef struct
{
    unsigned int                id;
    KMXSTATUS                   status;
    int                         flags;
    int                         http_status;
    const char*                 header;
    unsigned int                header_length;
    const char*                 content;
    unsigned int                content_length;
} KMX_OS_HTTP_RESPONSE;

KMXSTATUS kmx_os_net_open_channel(void);
void kmx_os_net_close_channel(void);

KMXSTATUS kmx_os_net_send_http_request(KMX_OS_HTTP_REQUEST* request);
void kmx_os_net_cancel_http_request(unsigned int id);

typedef KMXSTATUS (*KMX_NET_RESPONSE_HANDLER)(int event, KMXPARAM param1, KMXPARAM param2);
void kmx_os_net_set_response_handler(KMX_NET_RESPONSE_HANDLER handler);

/*}} os_network }}*/


/****************************************************************************

File system interface.

****************************************************************************/

/*{{ os_file_system {{*/

typedef int KMX_FILE_HANDLE;

#define KMX_OPEN_CREATE      0
#define KMX_OPEN_READ        1
#define KMX_OPEN_READ_WRITE  2

#define KMX_SEEK_CUR         0
#define KMX_SEEK_END         1
#define KMX_SEEK_SET         2

KMXSTATUS kmx_os_fs_create_dir(const KMXWCHAR* dir);

KMXSTATUS kmx_os_fs_open(
    const KMXWCHAR*     file_name,
    int                 mode,
    KMX_FILE_HANDLE*    handle);

void kmx_os_fs_close(KMX_FILE_HANDLE handle);

KMXSTATUS kmx_os_fs_seek(
    KMX_FILE_HANDLE     handle,
    int                 offset,
    int                 origin);

KMXSTATUS kmx_os_fs_read(
    KMX_FILE_HANDLE     handle,
    void*               buffer,
    unsigned int        size,
    unsigned int*       read_size);

KMXSTATUS kmx_os_fs_write(
    KMX_FILE_HANDLE     handle,
    const void*         buffer,
    unsigned int        size,
    unsigned int*       written_size);

/*}} os_file_system }}*/

#ifdef __cplusplus
}
#endif

#endif /* KMX_OS_H */
