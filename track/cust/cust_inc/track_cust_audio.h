#if defined(__AUDIO_RC__)
/******************************************************************************
 * track_cust_key.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        GT300音频处理
 * 
 * modification history
 * --------------------
 * v1.0   2013-07-5,  wangqi create this file
 * 
 ******************************************************************************/

#ifndef _TRACK_CUST_AUDIO_H
#define _TRACK_CUST_AUDIO_H

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


/***************************************************************************** 
* Typedef  Enum
*****************************************************************************/

typedef enum
{
    DEVICE_POWER_ON,
    DEVICE_POWER_OFF,
    MT_SMS,
    MT_RING,        //来电响铃
    MT_CONNECT,     //
    MT_MONITOR,     //监听
    MT_DISCONNECT,
    MT_MAX
}action_for_audio_enum;



/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    kal_uint8                   audio_id;
    kal_uint8                   play_style;
    kal_uint64                  volume;
    kal_uint8                   output_path;
    kal_uint16                  identifier;
}track_drv_aud_play_id_struct;

typedef struct 
{
    const unsigned char *AudioNames;
    int                             AudioLength;
    kal_uint8                   AudioType;
} TRACK_AUDIO_ITEM;

typedef struct 
{
    unsigned short                      MaxAudioNumEXT;
    const TRACK_AUDIO_ITEM * Audio_item;
} TRACK_AUDIO_HEADER;


typedef struct 
{
    action_for_audio_enum ActionNames;
    int                             AudioIndex;
    kal_uint8                   AudioRunType;
} TRACK_AUDIO_SETTING;

//30秒AMR文件长度，有点浪费
#define REC_BUFFER_LEN 30*1024

typedef struct 
{
    kal_uint16 Record_Buffer[REC_BUFFER_LEN];//双字节
    kal_uint32 recSize;//byte size
    kal_uint16 time;//录音大概时长
    kal_uint8  packets;
    kal_uint8  revPacket;
}rec_data_struct;

typedef struct
{
	kal_uint8 server_id;
	kal_uint8 audio_id;
	const char *file_path;
}audio_file_path_struct;

/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern void track_cust_audio_play_voice(kal_uint8 index);
extern void track_cust_audio_stop_voice(void);
extern void track_cust_close_record(void);
#endif  /* _TRACK_CUST_AUDIO_H */
#endif /* __AUDIO_RC__ */

