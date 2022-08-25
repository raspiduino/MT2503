/****************************************************************************
***file author: Liujw
***creat date:2018-05-29
***introduction:
****************http 下载文件处理
****************
2019-4-14 Liujw 将文件存储文件大小从256-512 文件存储格式：语音ID[3byte]+,[1byte]+文件名[10byte]+#[1byte]=15byte
2019-7-19 Liujw 将文件存储文件大小从512改为2K
2019-9-4  Liujw 将文件存储格式修改为：语音ID[3byte]+语音格式[1byte][1:amr,2:mp3]+分隔符#[0x23]
****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"

#define AUDIO_FILE_PATH "AUDIO_FILE1"
static 	FS_HANDLE fh = NULL;
static int audioFileLength = 0;
static kal_uint32 del_f_length = 0;
extern void track_nvram_write();
extern audio_amplifier(void* param);
//---------------------
extern kal_uint8 track_get_voice_volume(void);
static int AUDIO_file_exist(char *file_path);

int AUDIO_file_init(U8 operate, kal_uint8 *audioData, int len)
{
    int fileLength = 0;
    kal_uint8 fileData[2048] = {0};//256-512
    WCHAR fileName[30] = {0};
    static kal_uint8 done = 0;
    int fs_seek = 0, fs_write = 0, fs_read = 0;
    int operateLength = 0;
    if(done == 0)
    {
        OTA_kal_wsprintf(fileName, "%s", AUDIO_FILE_PATH);
        fh = FS_Open(fileName, FS_CREATE | FS_READ_WRITE);
        if(fh < 0)
        {
            LOGD(L_APP, L_V1, "ERROR%d", fh);
            return -1;
        }
        done = 1;
    }
    fs_seek = FS_Seek(fh, 0, FS_FILE_BEGIN);
    if(fs_seek < 0)
    {
        LOGD(L_APP, L_V1, "ERROR1%d", fs_seek);
        return -2;
    }
    if(operate == 0)
    {
        FS_GetFileSize(fh, &fileLength);
        fs_read = FS_Read(fh, (void*)fileData, fileLength, &operateLength);

        LOGD(L_APP, L_V1, "%d-%d", fs_read, operateLength);
        if(fs_read < 0)
        {
            LOGD(L_APP, L_V1, "ERROR2%d", fs_read);
            return -3;
        }
        if(operateLength > 0)
        {
            if(operateLength > 2048)
            {
                operateLength = 2048;
            }
            memcpy(audioData, fileData, operateLength);
            LOGH(L_APP, L_V5, fileData, operateLength);
        }
    }
    else if(operate == 1)
    {
        fs_write = FS_Write(fh, (void*)audioData, len, &operateLength);
        LOGD(L_APP, L_V1, "%d-%d", fs_write, operateLength);
        if(fs_write < 0)
        {
            LOGD(L_APP, L_V1, "ERROR3%d", fs_write);
            return -4;
        }
        FS_Commit(fh);
    }
    else if(operate == 2)
    {
        FS_Close(fh);
        done = 0;
    }
    return operateLength;

}
//一条语音数据最长是15个字节，其实完全可以只存储ID就行了，语音文件名就是%X%X%X出来的，但是后面跟的是amr还是mp3就不知道了
void AUDIO_file_memory(kal_uint8 *voiceID, char *fileName)//语音文件下载完成之后，才去记录文件名，所以OK了
{
    kal_uint8 fileData[2048] = {0};
    int datalength = 0;
    char audioFile[20] = {0};
    int fileLength = 0;
	
    audioFile[0] = voiceID[0];
    audioFile[1] = voiceID[1];
    audioFile[2] = voiceID[2];
    if(strstr(fileName, ".amr"))
    {
        audioFile[3] = 1;
    }
    else if(strstr(fileName, ".mp3"))
    {
        audioFile[3] = 2;
    }
    else
    {
        LOGD(L_APP, L_V5, "格式有问题");
        return;
    }
    audioFile[4] = 0x23;
    fileLength = 5;
    LOGH(L_APP, L_V5, audioFile, fileLength);
	
    audioFileLength = 0;
    audioFileLength = AUDIO_file_init(0, fileData, 0);
    LOGD(L_APP, L_V5, "无数据%d", audioFileLength);
	
    if(audioFileLength > 0)
    {
        LOGH(L_APP, L_V5, fileData, audioFileLength);
    }
    if((audioFileLength + fileLength) > 2048)
    {
        LOGD(L_APP, L_V1, "语音数据已满!", audioFileLength);
        return;
    }
    memcpy(&fileData[audioFileLength], audioFile, fileLength);
    audioFileLength += fileLength;
	
    datalength = AUDIO_file_init(1, fileData, audioFileLength);

    LOGD(L_APP, L_V5, "%d", datalength);

}
//00 04 4D [01] 23  00 04 4E [01] 23  00 04 4E [02] 23     23为结束符#  01是amr  02是mp3
int AUDIO_id_macth(kal_uint8 *audioID)
{
    kal_uint8 fileData[2048] = {0};
    int dataLength = 0, i = 0;
    int finder = 0;
    //测试  return 0;
    audioFileLength = 0;
    audioFileLength = AUDIO_file_init(0, fileData, 0);
    if(audioFileLength > 0)
    {
        for(i = 0; i < audioFileLength; i++)
        {
            if(fileData[i] == 0x23 && (((i + 1) % 5) == 0) && fileData[i-4] == audioID[0] && fileData[i-3] == audioID[1] && fileData[i-2] == audioID[2])
            {
                finder = 1;
                break;
            }
        }
    }
    return finder;

}
U8 AUDIO_file_play(kal_uint8 *audioID)
{
    kal_uint8 fileData[2048] = {0};
    int dataLength = 0, i = 0, j = 0;
    char audioFile[20] = {0};
    int finder = 0;
    U8 voiceType = 0;
    static U8 music_identifier = 0;
	
    audioFileLength = 0;
    audioFileLength = AUDIO_file_init(0, fileData, 0);
    if(audioFileLength < 1)
    {
        LOGD(L_APP, L_V1, "audio file is not exist!");
        return 1;
    }
    while(i < audioFileLength)
    {
        if(fileData[i] == 0x23 && (((i + 1) % 5) == 0) && fileData[i-4] == audioID[0] && fileData[i-3] == audioID[1] && fileData[i-2] == audioID[2])
        {
            finder = 1;
            voiceType = fileData[i-1];//语音类型
            break;
        }
        i++;
    }
    if(finder == 0)
    {
        LOGD(L_APP, L_V1, "没有找到匹配的语音ID");
        //return 1;
        return 9;
    }
    if(voiceType == 1)
    {
        dataLength = snprintf(audioFile, 20, "%X%X%X.amr", audioID[0], audioID[1], audioID[2]);
    }
    else if(voiceType == 2)
    {
        dataLength = snprintf(audioFile, 20, "%X%X%X.mp3", audioID[0], audioID[1], audioID[2]);
    }
    LOGH(L_APP, L_V5, audioFile, dataLength);
    finder = AUDIO_file_exist(audioFile);
    if(finder < 0)
    {
        LOGD(L_APP, L_V1, "没有找到匹配的语音ID-1");
        //return 1;
        return 9;
    }
    music_identifier ++;
    if(music_identifier >= 254) music_identifier = 0;
    audio_amplifier((void*)1);
    track_drv_play_voice_by_file(audioFile, DEVICE_AUDIO_PLAY_ONCE, track_get_voice_volume(), music_identifier);
    return 0;
}
static U8 fileDelete(kal_uint8 *data, int audioLen)
{
    int i = 0, j = 0;
    U8 finder = 0;
    WCHAR fileName[40] = {0};
    char fileNameTemp[20] = {0};
    FS_HANDLE fp = NULL;
    voice_list_struct voice_list = {0};
    kal_uint32 f_length = 0;
    int voiceNameLen = 0;

    memcpy(&voice_list, &G_realtime_data.voice_list, sizeof(voice_list_struct));
    LOGH(L_APP, L_V5, data, audioLen);
    for(j = 0; j < G_realtime_data.voice_max; j++)
    {
        if(data[0] == voice_list.void_id[j].voice_id[0] && data[1] == voice_list.void_id[j].voice_id[1] && data[2] == voice_list.void_id[j].voice_id[2])
        {
            finder = 1;
            break;
        }
    }
    LOGD(L_APP, L_V5, "finder:%d", finder);

    if(!finder)
    {
        if(data[3] == 1)
        {
            voiceNameLen = snprintf(fileNameTemp, 20, "%X%X%X.amr", data[0], data[1], data[2]);
        }
        else if(data[3] == 2)
        {
            voiceNameLen = snprintf(fileNameTemp, 20, "%X%X%X.mp3", data[0], data[1], data[2]);
        }
        OTA_kal_wsprintf(fileName, "%s", fileNameTemp);
		LOGD(L_APP, L_V5,"%s",fileNameTemp);
        FS_Delete(fileName);
    }
    return finder;
}
/******************************************************************************
 *  Function    -  AUDIO_file_delete
 *
 *  Purpose     -  语音文件对比删除函数
 *
 *  Description -  分列表更新删除和恢复出厂删除
 *
 *  0-恢复出厂删除        1-对比删除
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-07-23,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void AUDIO_file_delete(U8 par)
{
    kal_uint8 singleVoiceTemp[5] = {0};
    int result1 = 0;
    WCHAR fileName[30] = {0};
    kal_uint8 fileData[2048] = {0};
    int i = 0, j = 0;
    int audioLen = 0;
    char audioData[20] = {0};
    kal_uint8 fileDataTemp[2048] = {0};
    int audioFileLengthTemp = 0;
    voice_list_struct voice_list = {0};
	
    audioFileLength = 0;
    audioFileLength = AUDIO_file_init(0, fileData, 0);
    AUDIO_file_init(2, NULL, 0);
    LOGD(L_APP, L_V5, "%d", audioFileLength);
    if(audioFileLength <= 0) return;

    for(i = 0; i < audioFileLength; i++)
    {
        if(fileData[i] == 0x23 && (((i + 1) % 5) == 0))
        {
            memcpy(singleVoiceTemp, &fileData[i-4], 5);
            audioLen = 5;
            LOGH(L_APP, L_V5, singleVoiceTemp, audioLen);
            if(fileDelete(singleVoiceTemp, audioLen))
            {
                if((audioFileLengthTemp + 5) > 2048)
                {
                    LOGD(L_APP, L_V5, "Error!,%d", audioFileLengthTemp);
                    break;
                }
                memcpy(&fileDataTemp[audioFileLengthTemp], singleVoiceTemp, 5);
                audioFileLengthTemp += 5;

                LOGD(L_APP, L_V5, "%d", audioFileLengthTemp);
                LOGH(L_APP, L_V7, fileDataTemp, audioFileLengthTemp);
            }
            j = i + 1;
        }
    }
    OTA_kal_wsprintf(fileName, "%s", AUDIO_FILE_PATH);
    result1 = FS_Delete(fileName);
    LOGD(L_APP, L_V5, "%d", result1);
    AUDIO_file_init(1, fileDataTemp, audioFileLengthTemp);
}
void track_file_test(U8 arg)
{
    ;
#if 0
    FS_HANDLE fs = NULL;
    char voicepatch[30] = "test.mp3";
    char voicepatch1[30] = "test1.mp3";
    WCHAR pathTemp[60];
    if(arg == 0)
        OTA_kal_wsprintf(pathTemp, "Z:\\%s", voicepatch);
    else
        OTA_kal_wsprintf(pathTemp, "Z:\\%s", voicepatch1);
    fs = FS_Open(pathTemp, FS_READ_ONLY);
    if(fs < 0)
    {
        LOGD(L_APP, L_V1, "查无此语音文件.%d", fs);
    }
    else
    {
        LOGD(L_APP, L_V1, "文件存在:%d", fs);
        FS_Close(fs);
        audio_amplifier((void*)1);
        track_drv_play_voice_by_file(voicepatch, 2, /*G_parameter.ste_param.volume*/6, 1);
    }
#endif
}
static int AUDIO_file_exist(char *file_path)
{
    FS_HANDLE fh = NULL;
    WCHAR file_path_tmp[60];

    OTA_kal_wsprintf(file_path_tmp, "Z:\\%s", file_path);
    fh = FS_Open(file_path_tmp, FS_READ_ONLY);
    if(fh < 0)
    {
        LOGD(L_APP, L_V1, "查无此语音文件.%d", fh);
        return fh;
    }
    else
    {
        LOGD(L_APP, L_V1, "文件存在:%d", fh);
        FS_Close(fh);
        return 1;
    }
    return -1;

}
#if 0
kal_uint32 AUDIO_get_total_size()
{
    FS_HANDLE fp = NULL;
    kal_uint32 f_size = 0;
    kal_uint32 f_id_len = 0;
    kal_uint32 voicefilesize = 0;
    kal_uint8 fileData[2048] = {0};
    int i = 0, j = 0;
    int audioLen = 0;
    kal_uint8 audioData[20] = {0};
    WCHAR fileName[40] = {0};
    char fileNameTemp[20] = {0};

    f_id_len = AUDIO_file_init(0, fileData, 0);
    if(f_id_len <= 0) return 0;

    for(i = 0; i < f_id_len; i++)
    {
        if(fileData[i] == 0x23)
        {
            audioLen = i - j + 1;
            memcpy(audioData, &fileData[j], audioLen);
            LOGH(L_APP, L_V5, audioData, audioLen);

            memcpy(fileNameTemp, &audioData[4], audioLen - 5);
            fileNameTemp[audioLen-5] = '\0';
            OTA_kal_wsprintf(fileName, "%s", fileNameTemp);
            fp = FS_Open(fileName, FS_READ_ONLY);
            if(fp > 0)
            {
                FS_GetFileSize(fp, &f_size);
                if(f_size > 0)
                {
                    voicefilesize += f_size;
                }
                LOGD(L_APP, L_V5, "%d,%d,%s", f_size, voicefilesize, fileNameTemp);
                FS_Close(fp);
            }
            j = i + 1;
        }
    }
    return voicefilesize;
}
#endif
