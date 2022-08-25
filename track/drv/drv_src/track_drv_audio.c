#if 1//defined(__MED_AUD_FS_ACCESS__)
/******************************************************************************
 * track_drv_audio.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        MP3ÎÄ¼þ²¥·Å
 *
 * modification history
 * --------------------
 * v1.0   2018-04-30,  Liujw create this file
 *
 ******************************************************************************/
#include "track_drv_audio.h"
#if 0
#define MDI_AUD_PTH_EX(x) (x)
/* Exclude 1st(16-level) and 2nd(Mute) bit to get actual volume level*/
#define MDI_AUD_VOL_GET_EX_LEVEL(x)     ((x) & 0x3F)
/* Is 16 Level*/
#define MDI_AUD_VOL_IS_EX_LEVEL(x)      ((x) & 0x80)
/* Is Level 0 is mute */
#define MDI_AUD_VOL_IS_MUTE_LEVEL(x)    ((x) & 0x40)
#define MDI_DEVICE_SPEAKER2             (4)

/* Volume control */
#define CRESCENDO_TIMER_TIMEOUT    (1000)
#define CRESCENDO_VOLUME_MIN       (0)
#define CRESCENDO_VOLUME_MAX       (6)
#endif

#define AVK_TEST_FILE_PATH avk_framework_testfile_path
/* Tone, Keypad sound to play on audio device. */
#if 0
#define MDI_DEVICE_SPEAKER              (0)
/* Microphone sound to send on audio device. */
#define MDI_DEVICE_MICROPHONE           (1)
/* Earphone, carkit */
#define MDI_DEVICE_SPEAKER2             (4)
/* Loudspeaker for free sound */
#define MDI_DEVICE_LOUDSPEAKER          (5)
/* Output from earphone and loud speaker */
#define MDI_DEVICE_SPEAKER_BOTH         (6)
/* Used to be OR bitwise with above audio output devices */
#define MDI_DEVICE_BT_HEADSET           (8)

#define MDI_MAX_VOLUME_LEVEL 7
#endif
static U8 identifier;
/* Volume control */
//static kal_uint8 g_crescendo_volume = CRESCENDO_VOLUME_MIN;  /* Current crescendo volume */
//static kal_uint8 g_crescendo_bound = CRESCENDO_VOLUME_MAX;   /* Upper bound of crescendo volume */

void vs_mm_audio_misc_get_file_path(CHAR* path, CHAR* file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //    S8 fileBuf[VS_MM_BUFFER_SIZE];
    kal_wchar wszAudio[] = {0x0041, 0x0075, 0x0064, 0x0069, 0x006F, 0x005C, 0x0000};  /* default folder = Audio */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //    memset(fileBuf, 0, VS_MM_BUFFER_SIZE);
    memset(path, 0, VS_MM_BUFFER_SIZE);

    //mmi_wcscat((U16*) path, (U16*) AVK_TEST_FILE_PATH);
    kal_wstrcat((U16*) path, (U16*) L"Z:\\");
    kal_wstrcat((U16*) path, (U16*) file);
}

kal_uint8 track_drv_play_voice_by_file(kal_uint8 *file_name,kal_uint8 play_style,kal_uint64 volume,U8 identifier)
{
	kal_int32 result = 0;
	U8 identifierTemp = 0;
	aud_play_file_struct file_param;
	U16 file_name_temp[60] = {0};
	
	U16 file_path_name[100] = {0};
	identifierTemp = getplayidentifier();
	LOGD(L_APP,L_V5,"identifier:%d,%s", identifierTemp,file_name);
	
	OTA_mbstowcs(file_name_temp, file_name, 60);
	vs_mm_audio_misc_get_file_path((CHAR*)file_path_name,(CHAR*)file_name_temp);//audio.mp3 opendoor.amr
	file_param.src_id = MOD_MMI;
	file_param.file_name_p = (kal_wchar*)file_path_name;
    file_param.play_style = play_style;
    file_param.volume = volume;
    file_param.output_path = 6;
    file_param.identifier = (U16) identifierTemp; 
    file_param.start_offset = 0;
    file_param.end_offset = 0;
    file_param.cache_p = NULL;
	if ((result = OTA_media_aud_play_file(MOD_MMI, &file_param)) == 0)//MED_RES_OK =0
	{
		LOGD(L_DRV, L_V1, "result:%d",result);
	}
	else
	{
		LOGD(L_DRV, L_V1, "audio play not ok !result1:%d",result);
	}
}

void track_play_mp3_voice_test()
{
	static int done = 0;
	kal_int32 result = 0;
	U8 identifier = 2;
	aud_play_file_struct file_param;
	//S8 file_path_name[100] = {0};
	
	U16 file_path_name[100] = {0};
	if(done == 0)
	{
	  // GPIO_WriteIO(1, 41);
	   done = 1;
	}
	vs_mm_audio_misc_get_file_path((CHAR*)file_path_name,(CHAR*)L"Z:\\opendoor.amr");//audio.mp3 opendoor.amr
	file_param.src_id = MOD_MMI;
	file_param.file_name_p = (kal_wchar*)file_path_name;
    file_param.play_style = DEVICE_AUDIO_PLAY_ONCE;
    file_param.volume = 6;//MDI_MAX_VOLUME_LEVEL;
    file_param.output_path = 6;
    file_param.identifier = (U16) identifier; 
    file_param.start_offset = 0;
    file_param.end_offset = 0;
    file_param.cache_p = NULL;
	if ((result = OTA_media_aud_play_file(MOD_MMI, &file_param)) == 0)//MED_RES_OK = 0
	{
		LOGD(L_DRV, L_V1, "result:%d",result);
	}
}

#endif/*__MED_AUD_FS_ACCESS__*/
