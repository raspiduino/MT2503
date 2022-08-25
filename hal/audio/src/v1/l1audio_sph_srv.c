#include "task_config.h"
#include "syscomp_config.h"
#include "stack_ltlcom.h"


#include "am.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "kal_trace.h"
#include "l1audio_sph_trc.h"
#include "ddload.h"
#include "speech_def.h"

//#define __SPEECH_SW_TRANSC_SUPPORT__
#if defined(__VM_CODEC_SUPPORT__)	
#include "tst_sap.h"


extern kal_bool setCommonPara;
extern uint16 commonPara_0;

void voc_tst_handler(kal_char *string)
{
   commonPara_0 = atoi(string);
   
   if ((commonPara_0 < 0) || (commonPara_0 > 16))
   {
      setCommonPara = KAL_FALSE;
      commonPara_0 = 0;
      kal_trace(TRACE_GROUP_EPL, EPL_PARA_ERROR);
   }
   else
   {
      setCommonPara = KAL_TRUE;
      kal_trace(TRACE_GROUP_EPL, SET_EPL_PARA, commonPara_0);
   }
}

#define NB_FRAME_LEN  160
#define WB_FRAME_LEN  320

#define DDL_TASK_FLAG                 ((volatile uint16*)(DPRAM_CPU_base+0x3F34*2))  
#define DM_AUDIO_DAI_MODE0_SD_CNTR    ((volatile uint16*)(DPRAM_CPU_base+0x50000+0x2F33*2))
#define DM_AUDIO_DAI_MODE0_TAF_COUNT  ((volatile uint16*)(DPRAM_CPU_base+0x50000+0x2F34*2)) 
#define DM_AUDIO_SD_CTRL              ((volatile uint16*)(DPRAM_CPU_base+0x50000+0x32B9*2))
#define DM_PAGE_DACA_BUF 5 

char *codec_type = "NONE";
uint16 case_number = 0;
bool DDLFlag = true;

static struct{
   int32  input_file_hdl;
   int32  output_file_hdl;
   uint32 file_len;
   uint32 frame_len;
   uint32 frame_num;
   uint32 ul_read_count;
   uint32 dl_read_count;
   uint16 speech_mode;
   bool   amr_dtx2_flag;
   bool   wb_flag;
   bool   dtx_setting_flag;
   bool   ul_d2c_flag;
   bool   codec_reset_flag;
   bool   dl_delay_flag;
}transcoding;


void transcoding_msg_handler(uint16 msg_id)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   ilm_struct *ilm = allocate_ilm(MOD_L1AUDIO_SPH_SRV);
	 
   ilm->src_mod_id  = MOD_L1AUDIO_SPH_SRV;  
   ilm->dest_mod_id = MOD_L1AUDIO_SPH_SRV; 
   ilm->sap_id = INVALID_SAP; 
   ilm->msg_id = msg_id;
   ilm->local_para_ptr = NULL;
   ilm->peer_buff_ptr = NULL;
	 
   msg_send_ext_queue(ilm);
#endif   
}

#pragma arm section code="SECONDARY_ROCODE"

void transcodingULHisr(void *param)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint16 message;

   transcoding.ul_d2c_flag = true;

   message = MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_UL_READ_PATTERN;
   transcoding_msg_handler(message);
#endif   
}

void transcodingDLHisr(void *param)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint16 message;

   if(!transcoding.ul_d2c_flag)
      return;
   
   if(transcoding.codec_reset_flag)
   {  
	   *DM_AUDIO_SD_CTRL |= 0x0020;	  
     *DP_SC_FLAGS = 0x0733;
	  transcoding.codec_reset_flag = false;

	  if(transcoding.wb_flag)
      {
         *DSP_AWB_SE_CTRL = 0x1;
         *DSP_AWB_SD_CTRL = 0x1;
      }    

      if(transcoding.dtx_setting_flag)
      {
         *DP_SC_FLAGS |= 0x0004;        
         *DP_AUDIO_PAR |= 0x0080;

		 transcoding.dtx_setting_flag = false;
      }     
   } 

   message = MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_DL_READ_PATTERN;
   transcoding_msg_handler(message);
#endif   
}

#pragma arm section

void VBI_Reset(void)          
{ 
   *SHARE2_M2DI1 = 0x0838; 
   L1Audio_Msg_VBI_RESET(); 
}

void VBI_End(void)
{ 
   *SHARE2_M2DI1 = 0x0839;
   L1Audio_Msg_VBI_END(); 
}

void transcoding_write_speech_parameters( sc_flags, sc_mode, sd_mode )
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   *DP_SC_MODE  = sd_mode | (sc_mode << 8);
   *DP_SC_VAD   = (sc_mode>2)? 1:0;
   *DP_SC_FLAGS = sc_flags;
#endif   
}

extern const uint16 DSP_PCM_DELAY_TABLE_SUBCH0[13][2];
extern const uint16 DSP_PCM_MARGIN_TABLE[];

void transcoding_write_speech_delay( uint16 speech_mode )
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint16 n = (uint16)L1D_GetT2();
   if(n >= 13)
      n -= 13;

   *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH0[n][0];
   *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH0[n][1];
   *DP_MARGIN_PCM_W  = DSP_PCM_MARGIN_TABLE[speech_mode];
   //*DP_MARGIN_VBIPCM_W  = DSP_PCM_MARGIN_TABLE[speech_mode];
#endif   
}

void transcoding_stop(void)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   DSP_DACA_CTRL = 0x0000;
   *DP_AUDIO_PAR = 0x0;
	
   if(transcoding.wb_flag)
   {  
      *DSP_AWB_SE_CTRL = 0x0;      
      *DSP_AWB_SD_CTRL = 0x0;
      *DDL_TASK_FLAG = *DDL_TASK_FLAG &(~(0x60)); 
   }

   VBI_End();
   AFE_TurnOff8K();

   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_UL);
   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_DL);

   FS_Close(transcoding.input_file_hdl);
   FS_Close(transcoding.output_file_hdl);
#endif   
}

void transcoding_start(void)
{

#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   //if(transcoding.wb_flag && DDLFlag)
   //{
   //   DSP_DynamicDownload(DDID_AWB);
	 // DDLFlag = false;

   am.DL_UL_path = SPH_BOTH_PATH;   
   AFE_TurnOn8K();
   
   transcoding_write_speech_parameters( 0x0633, transcoding.speech_mode, transcoding.speech_mode );
   transcoding_write_speech_delay( transcoding.speech_mode );
   
   if(transcoding.amr_dtx2_flag)
      *DP_SC_VAD = 0x0;
    
   *E_CTRL_HO = 0x0100;   
   //*DSP_SPEECH_DEBUG_MODE |= 0x0008;            
   *DP_SC_FLAGS |= 0x100;
   *DSP_AGC_CTRL = 0x0000;   
   *E_CTRL_HRFR = 0x0000;   
   *E_CTRL_AMREFR = 0x0000;   
   *DP_AUDIO_PAR = 0x8000;
   *DM_AUDIO_DAI_MODE0_SD_CNTR = 0x00;
   
   if(transcoding.wb_flag)
   {  
      DSP_DACA_CTRL = 0x0011;
            
      *DP_AUDIO_PAR |= 0x0008;	    
	    *DSP_AWB_SE_CTRL = 0x1;      
      *DSP_AWB_SD_CTRL = 0x1;
      transcoding.frame_len = WB_FRAME_LEN;
   }
   else
   {      
      DSP_DACA_CTRL = 0x0111;
      
	  transcoding.frame_len = NB_FRAME_LEN;
   }

   transcoding.frame_num = transcoding.file_len/(transcoding.frame_len*2);

   VBI_Reset();

   L1Audio_HookHisrHandler( DP_D2C_DACA_REQ_UL, transcodingULHisr, 0 );
   L1Audio_HookHisrHandler( DP_D2C_DACA_REQ_DL, transcodingDLHisr, 0 );
   
#endif   
}

void transcoding_ul_process(viod)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint32 read_len;
   volatile uint16 *addr;
   uint16 buf[320];
   uint16 i;
            
   if(transcoding.ul_read_count >= transcoding.file_len)
      return;
   
   if(FS_Read(transcoding.input_file_hdl, buf, transcoding.frame_len*2, &read_len) < 0)
   {
      kal_trace(TRACE_GROUP_TRANSCODING, READ_FILE_FAIL);
      ASSERT(0);
   }
   transcoding.ul_read_count += read_len;   
   
   addr = DSP2_DM_ADDR(DM_PAGE_DACA_BUF, DSP_DACA_PTR_UL);
   for(i = 0; i < transcoding.frame_len; i++)
      *addr++ = buf[i];
#endif      
}

void transcoding_dl_process(void)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint16 message;
   uint32 read_len;
   volatile uint16 *addr;
   uint16 buf[320];
   uint16 i;
   uint16 *HB_Header_Ptr;
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   
   if(transcoding.dl_read_count >= transcoding.file_len)
      return;
   
   if(transcoding.dl_delay_flag)
   {
      transcoding.dl_delay_flag = false;
      *DM_AUDIO_DAI_MODE0_SD_CNTR = 0x2;
      *DM_AUDIO_DAI_MODE0_TAF_COUNT = 0x1;
	  return;
   }
   
   if((*DM_AUDIO_DAI_MODE0_SD_CNTR)<4)
   	  *DM_AUDIO_DAI_MODE0_SD_CNTR = *DM_AUDIO_DAI_MODE0_SD_CNTR +1;
   
   
   addr = DSP2_DM_ADDR(DM_PAGE_DACA_BUF, DSP_DACA_PTR_DL); 
   
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_TRANSCODING_OUTPUT, &module_id, 0x2))
   {
      for(i = 0; i < transcoding.frame_len; i++)
         buf[i] = *addr++;
      kal_buffer_trace(TRACE_GROUP_TRANSCODING, DECODER_OUTPUT_DATA, 320, (const kal_uint8*)buf);
   }
   
   if(FS_Read(transcoding.output_file_hdl, buf, transcoding.frame_len*2, &read_len) < 0)
   {
      kal_trace(TRACE_GROUP_TRANSCODING, READ_FILE_FAIL);
      ASSERT(0);
   }

   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_TRANSCODING_OUTPUT, &module_id, 0x2))  
      kal_buffer_trace(TRACE_GROUP_TRANSCODING, PATTERN_OUTPUT_DATA, 320, (const kal_uint8*)buf);   	

   transcoding.dl_read_count += read_len;   
   kal_trace(TRACE_GROUP_TRANSCODING, TRANSCODING_FRAME_NUMBER, transcoding.dl_read_count/(transcoding.frame_len*2));
		   
   addr = DSP2_DM_ADDR(DM_PAGE_DACA_BUF, DSP_DACA_PTR_DL);
   for(i = 0; i < transcoding.frame_len; i++)
   {
      if(*addr++ != buf[i])
      {
         transcoding_stop();
		 kal_wap_trace(MOD_L1AUDIO_SPH_SRV, TRACE_GROUP_TRANSCODING, "%s case %d FAIL. This case has %d frames.", codec_type, case_number, transcoding.frame_num);
         message = MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_CONTINUE;
         transcoding_msg_handler(message);

         return;
	  }
   }
   
   if(transcoding.dl_read_count >= transcoding.file_len)
   {  
	  transcoding_stop();
	  kal_wap_trace(MOD_L1AUDIO_SPH_SRV, TRACE_GROUP_TRANSCODING, "%s case %d PASS. This case has %d frames.", codec_type, case_number, transcoding.frame_num);
      message = MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_CONTINUE;
      transcoding_msg_handler(message);
   }
#endif   
}

void transcoding_init(viod)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   uint16 input_file_name[] = { 'D', ':', '\\', 'i', 'n', 'p', 'u', 't', '.', 'd', 'a', 't', 0x00 };
   uint16 output_file_name[] = { 'D', ':', '\\', 'o', 'u', 't', 'p', 'u', 't', '.', 'd', 'a', 't', 0x00 };
	 	      
   if((transcoding.input_file_hdl = FS_Open((const kal_wchar*)input_file_name, FS_READ_ONLY)) < 0 ||
	  (transcoding.output_file_hdl = FS_Open((const kal_wchar*)output_file_name, FS_READ_ONLY)) < 0)
   {
      kal_trace(TRACE_GROUP_TRANSCODING, OPEN_FILE_FAIL);
      ASSERT(0);
   }	
   FS_GetFileSize(transcoding.output_file_hdl, &transcoding.file_len);
	
   transcoding.ul_read_count = 0;
   transcoding.dl_read_count = 0;
   transcoding.ul_d2c_flag = false;
   transcoding.codec_reset_flag = true;
   transcoding.dl_delay_flag = true;
   transcoding.dtx_setting_flag = false;
   transcoding.wb_flag = false;
   transcoding.amr_dtx2_flag = false;
   kal_wap_trace(MOD_L1AUDIO_SPH_SRV, TRACE_GROUP_TRANSCODING, "SW Transcoding Init Done");
#endif   
}

void get_codec_type_and_case_number(char *codec_type_new)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   if(strcmp(codec_type, codec_type_new)!=0)
   {
      codec_type = codec_type_new;
      case_number = 1;
   }
   else
      case_number += 1;
#endif      
}

void transcoding_tst_handler(kal_char *string)
{
#if defined(__SPEECH_SW_TRANSC_SUPPORT__)
   transcoding_init();

   if(strcmp(string, "FR_NODTX")==0)
   {
      transcoding.speech_mode = 0x0;
	  get_codec_type_and_case_number("FR_NODTX");  
	  transcoding_start();
   }
   else if(strcmp(string, "FR_DTX")==0)
   {
	  transcoding.speech_mode = 0x0;
	  transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("FR_DTX");
	  transcoding_start();
   }
   else if(strcmp(string, "HR_NODTX")==0)
   {
      transcoding.speech_mode = 0x1;
	  get_codec_type_and_case_number("HR_NODTX");	  
	  transcoding_start();
   }
   else if(strcmp(string, "HR_DTX")==0)
   {
      transcoding.speech_mode = 0x1;
	  transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("HR_DTX");
	  transcoding_start();
   }
   else if(strcmp(string, "EFR_NODTX")==0)
   {
      transcoding.speech_mode = 0x2;
	  get_codec_type_and_case_number("EFR_NODTX");	  
	  transcoding_start();
   }
   else if(strcmp(string, "EFR_DTX")==0)
   {
      transcoding.speech_mode = 0x2;	  
	  transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("EFR_DTX");
	  transcoding_start();
   }
   else if(strcmp(string, "AMR122_NODTX")==0)
   {
      transcoding.speech_mode = 0x3;
	  get_codec_type_and_case_number("AMR122_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR122_DTX1")==0)
   {
      transcoding.speech_mode = 0x3;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR122_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR122_DTX2")==0)
   {
      transcoding.speech_mode = 0x3;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR122_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR102_NODTX")==0)
   {
      transcoding.speech_mode = 0x4;
	  get_codec_type_and_case_number("AMR102_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR102_DTX1")==0)
   {
      transcoding.speech_mode = 0x4;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR102_DTX1");
	  transcoding_start();
   }
   else if(strcmp(string, "AMR102_DTX2")==0)
   {
      transcoding.speech_mode = 0x4;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR102_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR795_NODTX")==0)
   {
      transcoding.speech_mode = 0x5;
	  get_codec_type_and_case_number("AMR795_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR795_DTX1")==0)
   {
      transcoding.speech_mode = 0x5;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR795_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR795_DTX2")==0)
   {
      transcoding.speech_mode = 0x5;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR795_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR74_NODTX")==0)
   {
      transcoding.speech_mode = 0x6;
	  get_codec_type_and_case_number("AMR74_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR74_DTX1")==0)
   {
      transcoding.speech_mode = 0x6;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR74_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR74_DTX2")==0)
   {
      transcoding.speech_mode = 0x6;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR74_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR67_NODTX")==0)
   {
      transcoding.speech_mode = 0x7;
	  get_codec_type_and_case_number("AMR67_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR67_DTX1")==0)
   {
      transcoding.speech_mode = 0x7;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR67_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR67_DTX2")==0)
   {
      transcoding.speech_mode = 0x7;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR67_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR59_NODTX")==0)
   {
      transcoding.speech_mode = 0x8;
	  get_codec_type_and_case_number("AMR59_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR59_DTX1")==0)
   {
      transcoding.speech_mode = 0x8;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR59_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR59_DTX2")==0)
   {
      transcoding.speech_mode = 0x8;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR59_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR515_NODTX")==0)
   {
      transcoding.speech_mode = 0x9;
	  get_codec_type_and_case_number("AMR515_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR515_DTX1")==0)
   {
      transcoding.speech_mode = 0x9;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR515_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR515_DTX2")==0)
   {
      transcoding.speech_mode = 0x9;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR515_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AMR475_NODTX")==0)
   {
      transcoding.speech_mode = 0xA;
	  get_codec_type_and_case_number("AMR475_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AMR475_DTX1")==0)
   {
      transcoding.speech_mode = 0xA;
      transcoding.dtx_setting_flag = true;
	  get_codec_type_and_case_number("AMR475_DTX1");
      transcoding_start();
   }
   else if(strcmp(string, "AMR475_DTX2")==0)
   {
      transcoding.speech_mode = 0xA;
      transcoding.dtx_setting_flag = true;
      transcoding.amr_dtx2_flag = true;
	  get_codec_type_and_case_number("AMR475_DTX2");
      transcoding_start();
   }
   else if(strcmp(string, "AWB660_NODTX")==0)
   {
      transcoding.speech_mode = 0x20;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB660_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB660_DTX")==0)
   {
      transcoding.speech_mode = 0x20;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB660_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB885_NODTX")==0)
   {
      transcoding.speech_mode = 0x21;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB885_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB885_DTX")==0)
   {
      transcoding.speech_mode = 0x21;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB885_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1265_NODTX")==0)
   {
      transcoding.speech_mode = 0x22;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1265_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1265_DTX")==0)
   {
      transcoding.speech_mode = 0x22;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1265_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1425_NODTX")==0)
   {
      transcoding.speech_mode = 0x23;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1425_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1425_DTX")==0)
   {
      transcoding.speech_mode = 0x23;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1425_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1585_NODTX")==0)
   {
      transcoding.speech_mode = 0x24;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1585_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1585_DTX")==0)
   {
      transcoding.speech_mode = 0x24;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1585_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1825_NODTX")==0)
   {
      transcoding.speech_mode = 0x25;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1825_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1825_DTX")==0)
   {
      transcoding.speech_mode = 0x25;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1825_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1985_NODTX")==0)
   {
      transcoding.speech_mode = 0x26;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1985_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB1985_DTX")==0)
   {
      transcoding.speech_mode = 0x26;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB1985_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB2305_NODTX")==0)
   {
      transcoding.speech_mode = 0x27;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB2305_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB2305_DTX")==0)
   {
      transcoding.speech_mode = 0x27;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB2305_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB2385_NODTX")==0)
   {
      transcoding.speech_mode = 0x28;      
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB2385_NODTX");
      transcoding_start();
   }
   else if(strcmp(string, "AWB2385_DTX")==0)
   {
      transcoding.speech_mode = 0x28;
      transcoding.dtx_setting_flag = true;
	  transcoding.wb_flag = true;
	  get_codec_type_and_case_number("AWB2385_DTX");
      transcoding_start();
   }
   else if(strcmp(string, "END")==0)
   {
      codec_type = "NONE";
	  case_number = 0;
      FS_Close(transcoding.input_file_hdl);
      FS_Close(transcoding.output_file_hdl);
   }
   else if(strcmp(string, "Turn_On_8K")==0)
   {
      am.DL_UL_path = SPH_BOTH_PATH; 
      AFE_TurnOn8K();      
      kal_wap_trace(MOD_L1AUDIO_SPH_SRV, TRACE_GROUP_TRANSCODING, "Turn on 8K Done");
   }
#endif   
}


void l1audio_sph_srv_tst_handler(ilm_struct *ilm_ptr)
{
   tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

   ASSERT(tst_inject != NULL);

   switch (tst_inject->index)
   {
      case 1:
      {
	     voc_tst_handler(tst_inject->string);
         break;
      }
	  case 2:
	  {
         transcoding_tst_handler(tst_inject->string);
	  }
      default:
         break;
   }
}

void l1audio_sph_srv_main(ilm_struct *ilm_ptr)
{
   if(ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
      l1audio_sph_srv_tst_handler(ilm_ptr);
   else if (ilm_ptr->msg_id == MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_UL_READ_PATTERN)
   	  transcoding_ul_process();
   else if (ilm_ptr->msg_id == MSG_ID_L1AUDIO_SPH_SRV_TRANSCODING_DL_READ_PATTERN)
      transcoding_dl_process();
} 

void l1audio_sph_srv_task_main(task_entry_struct *task_entry_ptr)
{
   ilm_struct current_ilm;
   kal_uint32 my_index;

   kal_get_my_task_index(&my_index);

   while(1)
   {
      receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

      l1audio_sph_srv_main((void *)&current_ilm);

      free_ilm(&current_ilm);
   }
}
kal_bool l1audio_sph_srv_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

kal_bool l1audio_sph_srv_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}
#endif

kal_bool l1audio_sph_srv_create(comptask_handler_struct **handle)
{
#if defined(__VM_CODEC_SUPPORT__)	
   static const comptask_handler_struct l1audio_sph_srv_handler_info =
   {
      l1audio_sph_srv_task_main,   /* task entry function */
      NULL,                        /* task initialization function */
      NULL,                        /* task configuration function */
      l1audio_sph_srv_task_reset,  /* task reset handler */
      l1audio_sph_srv_task_end,    /* task termination handler */
   };
   *handle = (comptask_handler_struct *)&l1audio_sph_srv_handler_info;
   return KAL_TRUE;
#else   
   return KAL_FALSE;
#endif   
}
