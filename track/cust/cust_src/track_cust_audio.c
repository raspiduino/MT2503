/******************************************************************************
 * track_cust_key.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GT300按键处理
 *
 * modification history
 * --------------------
 * v1.0   2013-07-5,  wangqi create this file
 *
 ******************************************************************************/

#if defined(__AUDIO_RC__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_cust_audio.h"
#include "track_drv_system_interface.h"
#include "uem_proc_cmd.h"
#include "med_api.h"
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define AUDIO_SETTING_TOTAL (sizeof(tr_audio_setting)/sizeof(TRACK_AUDIO_SETTING))
//#define K 1024
/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
//static  kal_uint16 *p_rec_buf=NULL;
static  kal_uint32 rec_buf_size=0;
//kal_uint16 Record_Buffer[REC_BUFFER_LEN];//双字节
static U8 play_identifier = 0;

/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/

/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
extern kal_uint8 track_drv_play_voice_by_file(kal_uint8 *file_name,kal_uint8 play_style,kal_uint64 volume,U8 identifier);
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/

/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/

__align(2) static const unsigned char female_mandarin_3_wav[] =
{
0x0,
};

//音频文件移到ell_main 中

#if defined( __SAME_GT02__)
__align(4) static const unsigned char audio_ring_d_wav[] = {0};
#else
__align(4) static const unsigned char audio_ring_d_wav[] = {0};
#endif
__align(2) static const unsigned char bubbles_wav[] =
{
0x0,
};
#if defined (__NF2319__) || defined (__NF2318__)
__align(4) static const unsigned char audio_ring_d1_amr[] = {0};
__align(4) static const unsigned char audio_ring_d2_amr[] = {0};
__align(4) static const unsigned char audio_ring_d3_amr[] = {0};
__align(4) static const unsigned char audio_ring_d4_amr[] = {0};
__align(4) static const unsigned char audio_ring_d5_amr[] = {0};
__align(4) static const unsigned char audio_ring_d6_amr[] = {0};
__align(4) static const unsigned char audio_ring_d7_amr[] = {0};
__align(4) static const unsigned char audio_ring_d8_amr[] = {0};
__align(4) static const unsigned char audio_ring_d9_amr[] = {0};
__align(4) static const unsigned char audio_ring_d10_amr[] = {0};
#if defined (__NF2318__)
__align(4) static const unsigned char audio_ring_d11_amr[] = {0};
__align(4) static const unsigned char audio_ring_d12_amr[] = {0};
__align(4) static const unsigned char audio_ring_d13_amr[] = {0};
__align(4) static const unsigned char audio_ring_d14_amr[] = {0};
#endif
#endif /* __NF2319__ */


const TRACK_AUDIO_ITEM track_audio[] = 
{
    {audio_ring_d_wav, 16102, 13},
    //{audio_ring_d11_amr, 4742, 3},		  
#if defined(__NF2319__)
    {audio_ring_d1_amr, 7686, 3},
    {audio_ring_d2_amr, 2278, 3},
    {audio_ring_d3_amr, 2246, 3},
    {audio_ring_d4_amr, 2886, 3},
    {audio_ring_d5_amr, 3014, 3},
    {audio_ring_d6_amr, 7558, 3},
    {audio_ring_d7_amr, 25318, 3},
    {audio_ring_d8_amr, 2950, 3},
    {audio_ring_d9_amr, 1958, 3},
    {audio_ring_d10_amr, 8966, 3},        
#else defined (__NF2318__)
	{audio_ring_d1_amr, 8742, 3},
	{audio_ring_d2_amr, 4326, 3},
	{audio_ring_d3_amr, 4294, 3},
	{audio_ring_d4_amr, 7462, 3},
	{audio_ring_d5_amr, 8550, 3},
	{audio_ring_d6_amr, 5414, 3},
	{audio_ring_d7_amr, 9222, 3},
	{audio_ring_d8_amr, 2470, 3},
	{audio_ring_d9_amr, 4966, 3},
	{audio_ring_d10_amr, 6054, 3},		  
	{audio_ring_d11_amr, 4742, 3},		  
	{audio_ring_d12_amr, 7014, 3},		  
	{audio_ring_d13_amr, 3718, 3},		  
	{audio_ring_d14_amr, 8070, 3},		  
#endif        
    {bubbles_wav, sizeof(bubbles_wav), 13}
};


#if defined (__NF2319__)
const TRACK_AUDIO_HEADER custpack_audio =
{
    12,
    &track_audio[0]
};
#elif defined (__NF2318__)
const TRACK_AUDIO_HEADER custpack_audio =
{
    16,
    &track_audio[0]
};
#else
const TRACK_AUDIO_HEADER custpack_audio =
{
    2,
    &track_audio[0]
};
#endif /* __NF2319__ */


static TRACK_AUDIO_SETTING tr_audio_setting[] = 
{
    {DEVICE_POWER_ON , 1        , 2},
    {DEVICE_POWER_OFF, 0        , 2},
    {MT_SMS                   , 0        , 2/*DEVICE_AUDIO_PLAY_ONCE*/},
    {MT_RING                  , 0        , 1},
    {MT_DISCONNECT      , 0XFF  , 1/*DEVICE_AUDIO_PLAY_INFINITE*/}
    
};//此结构体以后可存入NVRAM

static U8 g_alarm_type = 0;

/******************************************************************************
 *  Function    -  track_cust_get_audio_setting
 *
 *  Purpose     -  选择铃音
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   09-10-2013,  Wangqi
 * ----------------------------------------
*******************************************************************************/
static int track_cust_get_audio_setting(kal_uint8 actionType, kal_uint8 witchPart)
{
    int index = 0 ,result = 0XFF;
    
    for(;index < AUDIO_SETTING_TOTAL; index++)
    {
        if(tr_audio_setting[index].ActionNames == actionType)
        {
            if(1 == witchPart)
            {
                result = tr_audio_setting[index].AudioIndex;
            }
            else if(2 == witchPart)
            {
                result =  tr_audio_setting[index].AudioRunType;
            }
        }
    }
    return result;
}
/******************************************************************************
 *  Function    -  track_cust_audio_stop_voice
 *
 *  Purpose     -  停止播放铃音
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   09-10-2013,  Wangqi && Jiangweijun
 * ----------------------------------------
*******************************************************************************/
void track_cust_audio_stop_voice(void)
{
    LOGD(L_APP, L_V5, "");
    track_drv_sys_aud_send_stop_string_req(MOD_MMI);
}

void track_cust_monitor_set_speaket(kal_uint8 mute)
{
    LOGD(L_APP, L_V5, "mute:%d", mute);
#if defined(__GT300S__)||defined(__NT36__) || defined(__NF2318__)
//为了不影响其它项目，如果其它项目也要禁用Speaker可去掉这个宏
    if(mute == 1)
    {
        track_drv_sys_l4cuem_set_audio_mode(2);//可用切换到普通模式 
        L1SP_MuteSpeaker(KAL_TRUE);
    }
    else if(mute == 0)
    {
        L1SP_MuteSpeaker(KAL_FALSE);
    }
#endif
}
/******************************************************************************
 *  Function    -  track_cust_audio_play_voice
 *
 *  Purpose     -  处理铃音和震动主入口
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   09-10-2013,  Wangqi && Jiangweijun
 * ----------------------------------------
*******************************************************************************/
void track_cust_audio_play_voice(action_for_audio_enum actionType)
{
    aud_play_string_struct play_string = {0};
    kal_uint8 index = track_cust_get_audio_setting(actionType, 1);
    kal_uint8 playType = track_cust_get_audio_setting(actionType, 2);
    kal_uint8 call_mode = track_status_audio_mode(0xFF);
    
    LOGD(L_APP, L_V5, "actionType:%d, audioIndex:%d,plyaType:%d,callmode:%d,%d", actionType, index, playType,G_parameter.callmode,call_mode);

    if(actionType > MT_MAX )
    {
        LOGS( "Exception Action type or  AUDIO_PLAY beyond :%d,%d", actionType, playType);
        return;
    }
    
    if(actionType == MT_DISCONNECT || actionType == MT_CONNECT || actionType == MT_MONITOR)
    {
        track_cust_audio_stop_voice();
        track_cust_ring_Vibration((void*)0);
        
        if(actionType == MT_CONNECT)
        {
            track_cust_Vibration_100ms();
        }
        
#if defined(__NT36__)
        if (actionType == MT_MONITOR)
        {
            track_cust_monitor_set_speaket(1);
        }        
        else if(call_mode != 0)
        {
            track_drv_sys_l4cuem_set_audio_mode(0);//可用切换到普通模式            
        }

        if(actionType == MT_DISCONNECT)
        {
            track_cust_monitor_set_speaket(0);
            //track_drv_sys_audio_set_volume(2/*VOL_TYPE_MIC*/,3/*GAIN_NOR_MIC_VOL3*/);
        }
#endif
        return;
    }
    
    if(G_parameter.callmode >= 1 && actionType >= MT_SMS)
    {
        if(actionType == MT_RING)
        {
            track_cust_vib_interval(20, 1000, 2000);
            track_cust_ring_Vibration((void*)1);
        }
        else 
        {
            ControlVibration();
        }
        
        if(G_parameter.callmode == 1)
        {
            return;
        }
    }
    
    if(index >= custpack_audio.MaxAudioNumEXT || playType > 3/*DEVICE_AUDIO_PLAY_DESCENDO*/)
    {
        LOGS("==%d Voice Index Beyond %d!==",index, custpack_audio.MaxAudioNumEXT);
        return;
    }

    play_string.src_id = MOD_MMI;
#if defined (__NF2319__) || defined (__NF2318__)
    play_string.data_p = OTA_ell_play_voice(1);//(kal_uint8 *)custpack_audio.Audio_item[index].AudioNames;
#else
    play_string.data_p = OTA_ell_play_voice();//(kal_uint8 *)custpack_audio.Audio_item[index].AudioNames;
#endif /* __NF2319__ */
    play_string.len =custpack_audio.Audio_item[index].AudioLength;
    play_string.format = custpack_audio.Audio_item[index].AudioType;/*MED_TYPE_WAV*/
    
    if(actionType <= MT_SMS)
    {
        play_string.play_style = 2;/*DEVICE_AUDIO_PLAY_ONCE*/
    }
    else
    {
        play_string.play_style = playType;
    }
    
    play_string.volume = 5;
    play_string.output_path = 6;/*AUDIO_DEVICE_SPEAKER_BOTH*/
    play_string.identifier = 1;
    /* set both start_offset and end_offset to 0 for backward compatible */
    play_string.start_offset = 0;    /* 0 : file begining */
    play_string.end_offset = play_string.len;      /* 0 or file data len-1: file end */
    play_string.blocking = TRUE;

    LOGD(L_APP, L_V5, "len:%d,format:%d", play_string.len, play_string.format);

    track_drv_sys_aud_send_play_string_req((void *)&play_string);
}



/*录音存FAT验证补丁       --    chengjun  2016-12-24*/
//#define  DEBUG_RECORD_FILE_ON   1
#if defined(__LUYING__)
static rec_data_struct rec_data = {0};
static int folder_hd;
#endif
#if defined (DEBUG_RECORD_FILE_ON)
kal_uint8 track_record_init_file(void)
{
   kal_wchar filename[40];
   kal_wsprintf(filename, "\\rec_test.amr");
   folder_hd = FS_Open(filename, FS_READ_WRITE | FS_CREATE);
   if(folder_hd < 0)
   {
        folder_hd = 0;
         LOGD(L_DRV, L_V5,"Can not create this file! folder_hd:%d", folder_hd);
   }
   LOGD(L_DRV, L_V5,"create file sucesse! folder_hd:%d", folder_hd);
   return (folder_hd == 0 ? 0 : 1);
}
#endif /* DEBUG_RECORD_FILE_ON */


#if defined (__LUYING__)
void track_check_record(void)
{
    if(G_realtime_data.record_cnt > G_realtime_data.record_file + 1)
    {
        G_realtime_data.record_file = G_realtime_data.record_file + 1;
        track_cust_record(g_alarm_type, 1, RECORD_INTERVAL);
    }
    else if(G_realtime_data.record_last_time && G_realtime_data.record_last_time < RECORD_INTERVAL)
    {
        track_cust_record(g_alarm_type, 1, G_realtime_data.record_last_time);
        G_realtime_data.record_last_time = 0;
    }
    else
    {
        G_realtime_data.record_cnt = 0;
        G_realtime_data.record_file = 0;
        G_realtime_data.record_up = 0;
        G_realtime_data.record_last_time = 0;
    }
}


/******************************************************************************
 *  Function    -  track_record_callback
 *  Purpose     -  录音回调函数
 *  Description -
 *  
 *  modification history
 * ----------------------------------------
 * v1.0   20140927,  Wangqi
 * ----------------------------------------
*******************************************************************************/
void track_record_callback(Media_Event event)
{
    kal_uint16 *pwBuf;
    kal_uint32 buf_len, ret, wSize, curSize;
    LOGD(L_APP, L_V5,"event:%d", event);
    switch (event)
    {
    case MEDIA_TERMINATED:
        LOGD(L_APP, L_V5,"[DVT] record end");
        break;
    case MEDIA_DATA_NOTIFICATION:
        OTA_Media_GetReadBuffer(&pwBuf, &buf_len);
        OTA_Media_ReadDataDone(buf_len);

        curSize = rec_data.recSize + buf_len*2;
        if(curSize < REC_BUFFER_LEN)
        {
            rec_data.recSize = curSize;
        }
        
        LOGH(L_APP, L_V8, pwBuf, sizeof(int16) * buf_len);
        LOGD(L_APP, L_V5,"[DVT] record len = %d, %d, %d, %d, g_alarm_type:%d", 
            rec_data.packets, rec_data.revPacket, buf_len, rec_data.recSize, g_alarm_type);
        if(rec_data.revPacket++ > rec_data.packets)
        {
            int l = rec_data.recSize, b = 0;
            U8 *p;
            U16 crc = GetCrc16(p, l);

            p = (U8 *)rec_data.Record_Buffer;

            track_cust_record(g_alarm_type, 0, 0);
            
            LOGD(L_APP, L_V5,"rec_data:%x,apn:%x,%x",&rec_data.Record_Buffer[REC_BUFFER_LEN], track_socket_get_use_apn(), G_importance_parameter_data.apn.apn);
            
            if(track_is_testmode())
            {
                break;
            }


            /*连续压栈没问题吗?       --    chengjun  2017-09-01*/
            while(l > 0)
            {
                if(l > 1000)
                {
                    track_cust_paket_8D(g_alarm_type, rec_data.recSize, 0, (U8*)&crc, b, 1000, p + b);
                    l -= 1000;
                    b += 1000;
                }
                else
                {
                    track_cust_paket_8D(g_alarm_type, rec_data.recSize, 0, (U8*)&crc, b, l, p + b);
                    l = 0;
                    b += l;
                }
            }

        track_os_intoTaskMsgQueue(track_check_record);
                            
        }
        break;
    default:
        break;
    }
        
} 


/*1=正在录音，0=录音结束，其他是读取状态       --    chengjun  2017-09-27*/
kal_uint8 track_cust_is_recording(kal_uint8 option)
{
    static kal_uint8 going = 0;
    if(0 == option || 1 == option)
    {
        going = option;
    }
    LOGD(L_APP, L_V5,"== %d %d==", going, option);
    return going;
}

/******************************************************************************
 *  Function    -  track_cust_record
 *  Purpose     -  录音主入口
 *  Description -
 *  type:1开启 0关闭
 *  time:录音时长 单位秒 
 *  
 *  modification history
 * ----------------------------------------
 * v1.0   20140927,  Wangqi
 * ----------------------------------------
*******************************************************************************/
int track_cust_record(U8 alarm_type, kal_uint8 type, kal_uint16 time)
{
    int close_ret = 0;
    kal_uint32 ret, wSize;
    kal_uint8 isGoing = track_cust_is_recording(0xff);

    g_alarm_type = alarm_type;
    LOGD(L_APP, L_V5,"isGoing:%d, type:%d, g_alarm_type:%d", isGoing,type, g_alarm_type);

    if(isGoing && type == 1)
    {
        LOGD(L_APP, L_V5,"==[DVT] is recording ==");
        return 0;
    }
    
    if(1 == type)
    {
#if defined(DEBUG_RECORD_FILE_ON)
        if(track_record_init_file() == 0)
        {
            LOGD(L_APP, L_V5,"==[DVT] track_cust_record init 创建文件失败==");
            //return -1;
        }
#endif
        memset(&rec_data, 0, sizeof(rec_data_struct));
        track_cust_is_recording(1);

        rec_data.Record_Buffer[0] = 0x2123;//低位在前生成文件为23 21 41 4d 52 0a
        rec_data.Record_Buffer[1] = 0x4d41;
        rec_data.Record_Buffer[2] = 0x0a52;
        rec_data.recSize = 6;

        if(time > 128) 
        {
            time = 128;
        }
        if(time == 0)
        {
            time = 10;
        }
        rec_data.time = time;
        rec_data.packets = time * 2 - time/3;
        rec_data.revPacket = 0;
        LOGD(L_APP, L_V5,"==[DVT] track_cust_record init == %d,%d,%d",rec_data.time, rec_data.packets, rec_data.revPacket);
        OTA_Media_SetBuffer((kal_uint16 *)&rec_data.Record_Buffer[3], REC_BUFFER_LEN - 3);

        OTA_Media_SetRBThreshold(200);
        OTA_Media_Record(3/*MEDIA_FORMAT_AMR*/, track_record_callback, NULL); 
        tr_start_timer(TRACK_CUST_RECODE_OFF_TIMER_ID, (time+2)*1000, track_cust_close_record);
    }
    else if(0 == type)
    {
        LOGD(L_APP, L_V5,"==[DVT] track_cust_record colse ==");
        if(track_is_timer_run(TRACK_CUST_RECODE_OFF_TIMER_ID))
        {
            track_stop_timer(TRACK_CUST_RECODE_OFF_TIMER_ID);
        }
        OTA_Media_Stop();//stop record audio
        //OTA_LOGH(L_DRV, L_V5, rec_data.Record_Buffer, rec_data.recSize);
        
#if defined(DEBUG_RECORD_FILE_ON)
        if(folder_hd)
        {
            ret = FS_Write(folder_hd, (void *)rec_data.Record_Buffer, rec_data.recSize , &wSize);
            FS_Commit(folder_hd);
            close_ret = FS_Close(folder_hd);

            LOGD(L_DRV, L_V5,"==[DVT] %d colse ret:%d %d %d==", ret, close_ret,rec_data.recSize, wSize);
        }
#endif

        track_cust_is_recording(0);
        
    }
    return 1;
}


void track_cust_close_record(void)
{
    LOGD(L_DRV, L_V5,"录音结束");
    track_cust_record(0, 0, 0);
}

#endif /* __LUYING__ */

/******************************************************************************
 *  Function    -  track_cust_infinite_ring_stop_voice
 * 
 *  Purpose     -  关闭循环响铃
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-05-22,  ZengPing  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_infinite_ring_stop_voice(void)
{
    LOGD(L_APP, L_V5, "");
	tr_stop_timer(TRACK_CUST_INFINITE_RING_TIMER_ID);
    track_drv_sys_aud_send_stop_string_req(MOD_MMI);
}

/******************************************************************************
 *  Function    -  track_cust_play_amr_infinite_ring
 *
 *  Purpose     -  循环响铃声
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-05-22,  ZengPing  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_play_amr_infinite_ring(kal_uint16 ring_index)
{
	kal_uint16 time = 0;
    aud_play_string_struct play_string = {0};
    //kal_uint8 index = track_cust_get_audio_setting(3, 1);
    kal_uint16 index  = ring_index - 1;
    kal_uint8 playType = track_cust_get_audio_setting(3, 2);
    //LOGD(L_APP, L_V5, "");

    play_string.src_id = MOD_MMI;
#if defined (__NF2319__)||defined (__NF2318__)
    play_string.data_p = OTA_ell_play_voice(1);;//track_cust_play_voice(ring_index);//(kal_uint8 *)custpack_audio.Audio_item[index].AudioNames;

#else
    play_string.data_p = OTA_ell_play_voice();;//track_cust_play_voice(ring_index);//(kal_uint8 *)custpack_audio.Audio_item[index].AudioNames;
#endif /* __NF2319__ */
	play_identifier ++;
	if(play_identifier >= 254) play_identifier = 1;

    play_string.len = custpack_audio.Audio_item[0].AudioLength;
    LOGD(L_APP, L_V5, "len = %d", play_string.len);
    play_string.format = custpack_audio.Audio_item[0].AudioType;/*MED_TYPE_WAV*/
    play_string.play_style = DEVICE_AUDIO_PLAY_INFINITE;//DEVICE_AUDIO_PLAY_ONCE
    play_string.volume = 5;

    //play_string.output_path = 5;//AUDIO_DEVICE_LOUDSPEAKER
    play_string.output_path = 6;/*AUDIO_DEVICE_SPEAKER_BOTH*/
    play_string.identifier = play_identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    play_string.start_offset = 0;    /* 0 : file begining */
    play_string.end_offset = play_string.len;      /* 0 or file data len-1: file end */
    play_string.blocking = TRUE;

    LOGD(L_APP, L_V5, ", audioIndex:%d,plyaType:%d,play_style:%d", index, playType, play_string.play_style);
    track_drv_sys_aud_send_play_string_req((void *)&play_string);

    time = play_string.len/2;//从大小转换时间，大概是这个值
    //LOGD(L_APP, L_V5, "@1  time = %d", time);
	track_start_timer(TRACK_CUST_INFINITE_RING_TIMER_ID, time, track_cust_play_amr_infinite_ring,(void *)ring_index);	
}
#if defined (__NF2319__) || defined (__NF2318__) 
void track_cust_play_amr_ring(kal_uint16 index, kal_uint16 volume)
{
    aud_play_string_struct play_string = {0};
    kal_uint8 playType = track_cust_get_audio_setting(3, 2);
    kal_uint16 len = 0;

    play_string.src_id = MOD_MMI;
    play_string.data_p = OTA_ell_play_voice(index + 1);//(kal_uint8 *)custpack_audio.Audio_item[index].AudioNames;
    if(len > 0)
    {
		play_string.len =  len;
    }
    else
    {
        play_string.len = custpack_audio.Audio_item[index].AudioLength;
    }
	play_identifier ++;
	if(play_identifier >= 254) play_identifier = 1;
    LOGD(L_APP, L_V5, "play_identifier:%d",play_identifier);
    play_string.format = custpack_audio.Audio_item[index].AudioType;/*MED_TYPE_WAV*/
    play_string.play_style = 2;
    play_string.volume = volume;
    play_string.output_path = 6;/*AUDIO_DEVICE_SPEAKER_BOTH*/
    play_string.identifier = play_identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    play_string.start_offset = 0;    /* 0 : file begining */
    play_string.end_offset = play_string.len;      /* 0 or file data len-1: file end */
    play_string.blocking = TRUE;

    LOGD(L_APP, L_V5, ", audioIndex:%d,plyaType:%d,play_style:%d", index, playType, play_string.play_style);
    track_drv_sys_aud_send_play_string_req((void *)&play_string);
}

#endif /* __GB100__ */
#if defined(__NF2318__)
#if 0
static audio_file_path_struct audio_table[]=
{
	{0x0A,0,"pedalpower.mp3"},//脚踩来电 0x0A
	{0x0B,1,"parknotfree.mp3"},//服务器外停车收费提醒 0x0B
	{0x0C,2,"outservice.mp3"},//即将骑出服务区 0x0C
	{0x0D,3,"outservicecutele.mp3"},//服务区外断电 0x0D
	{0x01,4,"unlock.mp3"},//开锁成功 0x01
	{0x02,5,"powerlow.mp3"},//电量不足 0x02
	{0x03,6,"noparkarea.mp3"},//前方没有指定停车点了 0x03
	{0x04,7,"alarm.mp3"},//偷车报警 0x04
	{0x05,8,"findcar.mp3"},//寻车提示 0x05
	{0x06,9,"lock.mp3"},//锁车成功 0x06
	{0x07,10,"notservicearea.mp3"},//限行区域提示 0x07
	{0x09,11,"pedallate.mp3"},//稍后脚踩才能来电 0x09
	//{0x22,0,"111"},
	{0x0E,13,"1002.amr"},//广告1
	{0x0F,14,"1001.mp3"},//广告2
};
#endif
void track_drv_check_audio_file(kal_uint8 server_id,kal_uint8* file_name)
{
	int size = 0;
	kal_bool finder = KAL_FALSE;
	int i = 0;
	#if 0
	size = sizeof(audio_table)/sizeof(audio_file_path_struct);
	for(i = 0;i<size;i++)
	{
		LOGD(L_APP, L_V9, "0x%02X,0x%02X|%s",audio_table[i].server_id,server_id,audio_table[i].file_path);
		if(audio_table[i].server_id == server_id)
		{
			finder = KAL_TRUE;
			sprintf(file_name, "%s",audio_table[i].file_path);
			break;
		}
	}
	if(!finder)
	{
		LOGD(L_APP, L_V5, "error,do not found audio file id");
	}
	else
	{
		LOGD(L_APP, L_V5, "%s",file_name);
	}
	#endif
}
kal_uint8 track_cust_play_voice_by_mp3(kal_uint8 play_id,kal_uint8 volume)
{
	U8 file[30]; 
	static U8 music_identifier = 0;
	if(music_identifier >= 3)
		music_identifier = 0;
	else
		music_identifier ++;
	track_drv_check_audio_file(play_id,file);
	LOGD(L_APP, L_V5, "%s",file);
	track_drv_play_voice_by_file(file, DEVICE_AUDIO_PLAY_ONCE, volume, music_identifier);
}
#endif
U8 track_cust_play_identifier()
{
	LOGD(L_APP, L_V5,"play_identifier:%d",play_identifier);
	return play_identifier;
}
void track_cust_set_identifier()
{
	play_identifier = 0;
}
U8 getplayidentifier()
{
	play_identifier ++;
	if(play_identifier >= 254) play_identifier = 1;	
	return play_identifier;
}

/************************测试代码 ********************************
******************************************************************/

#if 0
void track_cust_test_voice(int m)
{
    track_drv_aud_play_id_struct play_voice = {0};
    aud_play_string_struct play_string = {0};
    static kal_uint8 indentifier = 0;
    if(m == 160)
    {
        l4cuem_speech_set_mode_req(KAL_TRUE, 2);
    }
    else if(m == 161)
    {

        l4cuem_speech_set_mode_req(KAL_FALSE, 2);
    }
    else if(m == 162)
    {
        l4cuem_speech_set_mode_req(KAL_TRUE, 0);
    }
    else if(m == 163)
    {
        //处于免提状态执行此功能后无音，执行162后恢复
        l4cuem_speech_set_mode_req(KAL_FALSE, 0);
    }
    else if(m == 164)
    {
        //LOGD(L_CON, L_V5, "",mdi_audio_get_audio_mode());
        ;
    }
    else if(m == 165)
    {
        track_drv_sys_l4cuem_set_audio_mode(0);//可用切换到手持
    }
    else if(m == 166)
    {
        track_drv_sys_l4cuem_set_audio_mode(2);//可用切换到免提
    }
    else if(m == 176)
    {
        track_drv_sys_l4cuem_set_audio_mode(1);//可用切换到免提
    }
    else if(m == 167)
    {
        l4cuem_audio_get_volume_req(MOD_MMI, 0);
    }
    else if(m == 168)
    {
        l4cuem_audio_get_volume_req(MOD_MMI, 4);
    }
    else if(m == 169)
    {
        l4cuem_audio_get_volume_req(MOD_MMI, 2);
    }
    else if(m == 170)
    {
        track_drv_sys_audio_set_volume(4, 1);
    }
    else if(m == 171)
    {
        track_drv_sys_audio_set_volume(4, 6);
    }
    else if(m == 172)
    {
        LOGD(L_CMD, L_V5, "indentifier:%d", indentifier);
        play_voice.audio_id = indentifier;
        play_voice.play_style = 1;/*DEVICE_AUDIO_PLAY_INFINITE*/
        play_voice.volume = 5;
        play_voice.output_path = 6;/*AUDIO_DEVICE_SPEAKER_BOTH*/
        play_voice.identifier = indentifier;
        track_drv_sys_aud_send_play_id_req((void*)&play_voice);//按键声音
        indentifier++;

        //INCOMING_CALL_TONE
    }
    else if(m == 173)
    {
        tr_audio_setting[MT_RING].AudioIndex = 0;
        track_cust_audio_play_voice(3);

    }
    else if(m == 174)
    {
        tr_audio_setting[MT_RING].AudioIndex = 0;
        track_cust_audio_play_voice(3);
    }
    else if(m == 175)
    {
        play_string.src_id = MOD_MMI;
        play_string.data_p = (kal_uint8*)&female_mandarin_3_wav[0];
        play_string.len = sizeof(female_mandarin_3_wav);
        play_string.format = 13;
        play_string.play_style = 1;/*DEVICE_AUDIO_PLAY_INFINITE*/
        play_string.volume = 5;
        play_string.output_path = 6;/*AUDIO_DEVICE_SPEAKER_BOTH*/
        play_string.identifier = indentifier;
        /* set both start_offset and end_offset to 0 for backward compatible */
        play_string.start_offset = 0;    /* 0 : file begining */
        play_string.end_offset = play_string.len;      /* 0 or file data len-1: file end */
        play_string.blocking = TRUE;

        LOGD(L_CMD, L_V5, "indentifier:%d,len:%d", indentifier, play_string.len);

        track_drv_sys_aud_send_play_string_req((void *)&play_string);
    }

}
#endif
#endif
