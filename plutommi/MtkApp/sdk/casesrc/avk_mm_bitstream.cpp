#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

extern "C"
{
#include "mdi_bitstream.h"
}

#if defined(__BITSTREAM_API_SUPPORT__)

typedef struct
{
	BOOL m_bitstream_record_started;
	FS_HANDLE g_file_handle;
	MDI_HANDLE aud_handle;
} vs_mm_bitstream_context_struct;


vs_mm_bitstream_context_struct g_vs_bitstream_cntx;


static void vs_mm_bistream_record_open_handle_callback(S32 handle, S32 result);
void vs_mm_bitstream_draw_ui(dm_coordinates *coordinate);
void vs_mm_bitstream_record_pass(void);
void vs_mm_bitstream_record_fail(void);

void vs_mm_bitstream_record_pass(void)
{
	//vs_tfw_trace_result(L"vs_mm_bitstream_record", MMI_TRUE, 0, VS_TA_SERVICE_PROFILE);
	//vs_tfw_finish_case_extern(VS_MM_BITSTREAM_RECORD_001, SCR_ID_VS_MM_BITSTREAM);


	mdi_bitstream_record_stop(g_vs_bitstream_cntx.aud_handle);
	mdi_bitstream_record_close(g_vs_bitstream_cntx.aud_handle);

	AVK_LOG_FUN(mdi_bitstream_record_stop,AVK_PASS);
	AVK_LOG_FUN(mdi_bitstream_record_close,AVK_PASS);

	AVK_LOG_FUN(mdi_bitstream_record_get,AVK_PASS);
	AVK_LOG_FUN(mdi_bitstream_record_set,AVK_PASS);
		GoBackHistory();
	AVK_ASYN_DONE();

}
void vs_mm_bitstream_record_fail(void)
{
	//vs_tfw_trace_result(L"vs_mm_bitstream_record", MMI_TRUE, 0, VS_TA_SERVICE_PROFILE);
	//vs_tfw_finish_case_extern(VS_MM_BITSTREAM_RECORD_001, SCR_ID_VS_MM_BITSTREAM);


	mdi_bitstream_record_stop(g_vs_bitstream_cntx.aud_handle);
	mdi_bitstream_record_close(g_vs_bitstream_cntx.aud_handle);

	AVK_LOG_FUN(mdi_bitstream_record_stop,AVK_PASS);
	AVK_LOG_FUN(mdi_bitstream_record_close,AVK_PASS);
		GoBackHistory();
	AVK_ASYN_DONE();

}




static void vs_mm_bistream_record_open_handle_callback(S32 handle, S32 result)
{
	U16 data_buf[1000];
	U16 data_len;
	U16 record_len;
	U32 written = 0;
	S32 ret;
	int letter;



	WCHAR fileBuf[VS_MM_BUFFER_SIZE];
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset(fileBuf, 0, sizeof(fileBuf));

	mmi_wcscat( fileBuf, (U16*) AVK_TEST_FILE_PATH);
	mmi_wcscat( fileBuf, (U16*) L"avk_mm_audio\\");
	mmi_wcscat( fileBuf, (U16*) L"1.amr");

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/


	kal_prompt_trace(MOD_IDLE,"bitstream record cb: handle = %d,result = %d",handle,result);

	/* Get record length */
	data_len = sizeof(U16);
	ret = mdi_bitstream_record_get(g_vs_bitstream_cntx.aud_handle,
		MDI_BITSTREAM_RECORD_GET_LENGTH,
		(void*)&record_len,
		&data_len); /* The value of data_len should be 2 when in/out */
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_get_len ret = %d",ret);

	/* Get record data */
	data_len = 1000;
	ret = mdi_bitstream_record_get(g_vs_bitstream_cntx.aud_handle,
		MDI_BITSTREAM_RECORD_GET_DATA,
		(void*)data_buf,
		&data_len); /* 2bytes per unit. The value of data_len may be less or equal to 1000 */


	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_get_data ret = %d",ret);

	if (g_vs_bitstream_cntx.g_file_handle == -1) //first time open file
	{

		g_vs_bitstream_cntx.g_file_handle = FS_Open(fileBuf,FS_CREATE_ALWAYS | FS_READ_WRITE);
		FS_Seek(g_vs_bitstream_cntx.g_file_handle,0,FS_FILE_END);
		FS_Write(g_vs_bitstream_cntx.g_file_handle,(void*)AMR_HEADER,6,&written);
		FS_Commit(g_vs_bitstream_cntx.g_file_handle);
		FS_Close(g_vs_bitstream_cntx.g_file_handle);

		kal_prompt_trace(MOD_IDLE,"first time write = %d",written);
	}
	else //not the first time
	{
		g_vs_bitstream_cntx.g_file_handle = FS_Open(fileBuf,FS_READ_WRITE);

	}
	if (g_vs_bitstream_cntx.g_file_handle >= 0) //write 
	{
		FS_Seek(g_vs_bitstream_cntx.g_file_handle,0,FS_FILE_END);
		FS_Write(g_vs_bitstream_cntx.g_file_handle,data_buf,2*data_len,&written);
		FS_Commit(g_vs_bitstream_cntx.g_file_handle);
		FS_Close(g_vs_bitstream_cntx.g_file_handle);

		kal_prompt_trace(MOD_IDLE,"non-first time write = %d",written);
	}

}


void vs_mm_bitstream_draw_ui(dm_coordinates *coordinate)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	UI_UNUSED_PARAMETER(coordinate);
	gui_set_text_color(gui_color(128, 0, 255));
	gui_move_text_cursor(5, 40);
	gui_print_text((UI_string_type) L"please speak");
	gui_set_text_color(gui_color(0, 0, 0));
	gui_set_text_border_color(gui_color(255, 255, 255));
	gui_move_text_cursor(5, 70);
	gui_print_bordered_text((UI_string_type) L"store file in phone");
	gui_move_text_cursor(5, 100);
	gui_print_bordered_text((UI_string_type) L"file name 1.amr"); 
	gui_move_text_cursor(5, 130);
	gui_print_bordered_text((UI_string_type) L"softkey to stop");

}
#endif



void vs_mm_bitstream_record(void)
{	
#if defined(__BITSTREAM_API_SUPPORT__)


	mdi_bitstream_record_cfg_struct bitstream_record_cfg_struct;
	S32 ret;

	mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_BITSTREAM_AUDIO_RECORD, NULL, vs_mm_bitstream_record, MMI_FRM_FULL_SCRN);
	ShowCategory227Screen(
		0,
		0,
		STR_GLOBAL_YES,
		0,
		STR_GLOBAL_NO,
		0,
		vs_mm_bitstream_draw_ui,
		NULL);

	SetLeftSoftkeyFunction(vs_mm_bitstream_record_pass, KEY_EVENT_UP);
	SetRightSoftkeyFunction(vs_mm_bitstream_record_fail, KEY_EVENT_UP);

	g_vs_bitstream_cntx.m_bitstream_record_started = FALSE;
	g_vs_bitstream_cntx.g_file_handle = -1;


	bitstream_record_cfg_struct.codec_type = MDI_BITSTREAM_CODEC_TYPE_AMR;
	bitstream_record_cfg_struct.quality = MDI_BITSTREAM_RECORD_QUALITY_LOW;
	ret = mdi_bitstream_record_open(&g_vs_bitstream_cntx.aud_handle,&bitstream_record_cfg_struct,vs_mm_bistream_record_open_handle_callback);
	AVK_LOG_FUN(mdi_bitstream_record_open,AVK_PASS);

	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_open ret = %d",ret);
	if (ret !=MDI_RES_BITSTREAM_SUCCEED)
	{
		return;
	}
	else
	{
		ret = mdi_bitstream_record_start(g_vs_bitstream_cntx.aud_handle);
		AVK_LOG_FUN(mdi_bitstream_record_start,AVK_PASS);

		kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_start ret = %d",ret);
		if (MDI_RES_BITSTREAM_SUCCEED != ret)
		{
			mdi_bitstream_record_close(g_vs_bitstream_cntx.aud_handle);
			
			AVK_LOG_FUN(mdi_bitstream_record_close,AVK_PASS);
			return;
		}
		else
		{
			g_vs_bitstream_cntx.m_bitstream_record_started = TRUE;
		}
	}

#else
AVK_LOG_FUN_UNSUPPORTED(mdi_bitstream_record_open);
AVK_ASYN_DONE();

#endif

}

AVK_ADD_ITEM(AVK_BITSM_ITEM_001,L"Bistream Record 001",AVK_MM_BITSTREAM);


AVK_MANUAL_CASE(AVK_BITSM_MANUAL1,AVK_BITSM_ITEM_001)
{    
	vs_mm_bitstream_record();

}

#endif
