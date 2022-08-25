/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  GPS_DL_api.h
*
* Project:
* --------
*  GPS Download Library.
*
* Description:
* ------------
*  Exported C interface APIs for GPS Download Library.
*
* Author:
* -------
 * -------
*
*******************************************************************************/
#ifndef _GPS_DL_API_H_
#define _GPS_DL_API_H_

//#define __GPS_FW_UPDATE_SUPPORT__


#define MAX_GPS_IMAGE_NUM 16

#define	MAX_FILENAME_LENGTH		256
#define	MAX_DA_IMAGE_LENGTH		0x5000


#define GPS_FW_DEFAULT_FILE_NAME L"Z:\\@fota_iot\\gps_image.bin"
#define GPS_FW_DOWNLOAD_OK 0
#define GPS_FW_DOWNLOAD_FILE_OPEN_ERR -1
#define GPS_FW_DOWNLOAD_FILE_GTE_FILE_SIZE_ERR -2
#define GPS_FW_DOWNLOAD_FILE_READ_ERR -3
#define GPS_FW_DOWNLOAD_UPLOAD_ERR -4  

typedef int (*CALLBACK_DOWNLOAD_PROGRESS_INIT)(void *usr_arg);
typedef int (*CALLBACK_DOWNLOAD_PROGRESS)(unsigned char finished_percentage,
										   unsigned int finished_bytes,
										   unsigned int total_bytes, void *usr_arg);

typedef int (*CALLBACK_CONN_BROM_WRITE_BUF_INIT)(void *usr_arg);
typedef int (*CALLBACK_CONN_BROM_WRITE_BUF)(unsigned char finished_percentage,
                                           unsigned int sent_bytes,
                                           unsigned int total_bytes, void *usr_arg);

typedef struct{
    char                    m_path[MAX_FILENAME_LENGTH];
    const unsigned char     *m_image;
    unsigned int            m_size;
}GPS_DA;

typedef struct{
    char                    m_path[MAX_FILENAME_LENGTH];
    const unsigned char     *m_image;
    unsigned int            m_size;
}GPS_Image;

typedef struct{
    unsigned int    m_num;
    GPS_Image       m_image_list[MAX_GPS_IMAGE_NUM];
}GPS_Image_List;

typedef struct{
   unsigned int      m_packet_length;
   unsigned char     m_num_of_unchanged_data_blocks;
   const unsigned char     *m_buf;
   unsigned int      m_len;   
   unsigned int      m_begin_addr; 
   unsigned int      m_end_addr;
}ROM_HANDLE_T;

typedef struct{
    int                                 m_bEnableLog;
    int *                               m_p_bootstop;
    CALLBACK_CONN_BROM_WRITE_BUF_INIT   m_cb_download_conn_da_init;
    void *                              m_cb_download_conn_da_init_arg;
    CALLBACK_CONN_BROM_WRITE_BUF        m_cb_download_conn_da;
    void *                              m_cb_download_conn_da_arg;
}GPS_DA_Arg;

typedef struct{
    CALLBACK_DOWNLOAD_PROGRESS_INIT     m_cb_download_conn_init;
    void *                              m_cb_download_conn_init_arg;
    CALLBACK_DOWNLOAD_PROGRESS          m_cb_download_conn;
    void *                              m_cb_download_conn_arg;
    CALLBACK_CONN_BROM_WRITE_BUF_INIT   m_cb_download_conn_da_init;
    void *                              m_cb_download_conn_da_init_arg;
    CALLBACK_CONN_BROM_WRITE_BUF        m_cb_download_conn_da;
    void *                              m_cb_download_conn_da_arg;
    int                                 m_bEnableLog;
    int *                               m_p_bootstop;
}GPS_Download_Arg;


int GPS_DL();

#endif
