/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * AR1000_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (AR1000)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"

#if (defined(AR1000))


//static kal_int32 freq_rssi_array[2][3]={{0,0,0},{0,0,0}};//for auto search
//static kal_int8 index_count=0; 
///#define force_mono

#define USE_I2C
#define AR1000_DEBUG
#define ext_clk
//#define AR1000_DEBUG_DUMP_LOG       //Option log file
//#define AR1000_timing_cal

#if defined AR1000_DEBUG
static kal_uint8 dbg_cw_readbackM = 0;
static kal_uint8 dbg_cw_readbackL = 0;
static kal_uint16 dbg_cw_readdata;
#endif

#if (defined(MT6205B) || defined(MT6208)) && defined(AR1000_DEBUG_DUMP_LOG)
#error "No file system on MT6205!"
#endif

#define UEBAND			0x0000 // US & Europe BAND 87.5MHz to 108MHz
#define JBAND			0x1000 // Japen BAND 76MHz to 90MHz
#define JWBAND			0x1800 // Japen BAND (wide) 76 MHz to 108MHz

#define SPACE100K		1
#define SPACE200K		0
#define SEEKUP			1
#define SEEKDOWN 		0

/* General propose constant */
#define AR1000_WRITE          	32//192
#define AR1000_READ           	33//193
#define ADDR_STATUS		0x13 // the address of status register
#define MASK_STC 		0x0020  // Seek/Tune/PowerOn complete  D5 in  adress 13H 
#define MASK_SF	 		0x0010  //  Seek Fail D4 in address 13H
#define MASK_READCHAN 0xFF80 // D7~D15 in address 13H
#define SHIFT_READCHAN 7

#define ADDR_RSSI		0x12 
#define MASK_RSSI 		0xFE00
#define SHIFT_RSSI  		9

/// Global variables for current FM status
static kal_int16 _current_frequency = -1;
static kal_bool  _is_fm_on = KAL_FALSE;
//static kal_bool  _is_fm_mute = KAL_FALSE;
//static kal_uint8 _rssi_threshold;
static kal_uint16 Chip_ID = 0;
static kal_uint16 Device_ID = 0;
static kal_uint8 HWSearch_flag = 0;
static kal_uint8 Valid_flag = 0;
static kal_uint16 FreqKHz = 0;
static kal_uint8 RSSI_value = 0;
kal_uint16 FreqSt = 987;

#ifdef AR1000_DEBUG_DUMP_LOG
extern kal_uint32 video_get_current_time(void);
extern kal_uint32 video_get_duration_ms(kal_uint32 t1);
static kal_uint8 _file_name[] = {"D\0:\0\\\0f\0m\0_\0l\0o\0g\0.\0t\0x\0t\0\0\0"};
static kal_uint32 _data_written;
static kal_uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;

static kal_uint8 _channel_name[] = {"D\0:\0\\\0l\0i\0s\0_\0l\0o\0g\0.\0t\0x\0t\0\0\0"};
static kal_uint32 _list_written;
static kal_uint8  _list_str[128];
static FS_HANDLE  _file_list = 0;
#endif



/* Serial communication interfaces */
void  SerialCommInit(void);
void  SerialCommRelease(void);
void  SerialCommCryClkOn(void);
void  SerialCommCryClkOff(void);
void  GPIO_WriteIO(char data,char port);

#if defined USE_I2C
void  SerialCommStart(void);
void  SerialCommStop(void);
kal_uint8 SerialCommTxByte(kal_uint8 data);
void  SerialCommRxByte(kal_uint8 *data, kal_uint8 ack);
#elif defined USE_3_WIRE
kal_uint8 SerialCommTxByte(kal_uint8 cw, kal_uint8 data);
void  SerialCommRxByte(kal_uint8 cw, kal_uint8 *data);
#endif

void FMDrv_Mute(kal_uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);

// enginner mode struct
typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   IF_count_delta,
	   GROUP_TOTAL_NUMS
	} FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_OFF=0,
	   Sblend_ON,  
	   ITEM_TOTAL_NUMS
	} FACTORY_ITEM_INDEX;
// enginner mode struct
typedef struct{
   void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_vlaid );
   kal_bool bHWsearchStop;
   kal_bool is_preset;
   kal_bool is_searching;
}FMR_data;
extern FMR_data *pstFMR_data;
#if 0
#if defined(ext_clk)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else     
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

//- Modified code start
#if defined(ext_clk)
static kal_uint16 AR1000reg[18]={ // the initial setting of AR1000 register ( base on ARF_V022_080118_MTK)
0xFF7B,  // R0 -- the first writable register 0xFF7F
0x5915,  // R1 0x5B15
0x10B9,  // R2//F4B9 0xF0B9
0x8010,  // R3//8012
0x0780,  // R4
0x28AB,  // R5//28AA 0x28AA
0x6400,  // R6 0x4400
0x1EE7,  // R7
0x7141,  // R8
0x007D,  // R9
0x81C6,  // R10//82CE		//disable wrap by purple
0x4F65,  // R11//4F55 0x4F55
0x970C,  // R12//970C
0xB845,  // R13
0xFC2D,  // R14//FC2D
0x8097,  // R15//8097
0x04A1,  // R16//04A1
0xE2A7  // R17//7F6A 0x7F6A
}; 
#else     
static kal_uint16 AR1000reg[18]={ // the initial setting of AR1000 register ( base on ARF_V022_080118_MTK)
0xFFFB,  // R0 -- the first writable register . 0xFFFF
0x5915,  // R1. 0x5B15
0x10B9,  // R2. 0xF4B9
0x8010,  // R3  
0x0780,  // R4  
0x28AB,  // R5  0x28AA
0x6400,  // R6  0x4400
0x1EE7,  // R7  
0x7141,  // R8  
0x007D,  // R9  
0x81C6,  // R10 		//disable wrap by purple
0x4E65,  // R11. <---  0x4E55
0x970C,  // R12. 
0xB845,  // R13 
0xFC2D,  // R14 
0x8097,  // R15 
0x04A1,  // R16 
0xE2A7  // R17 0xDF6A
}; 
#endif
//- Modified code end


static kal_bool AR1000_ReadByte(kal_uint8 CW, kal_uint8 *dataM, kal_uint8 *dataL)
{
//	kal_uint8 data1, data2;
   if (CW == 255) {
      *dataM = 0;
      *dataL = 0;
      return KAL_TRUE;
   }
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(AR1000_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word
   SerialCommStart();                /// resend the start sequence
   SerialCommTxByte(AR1000_READ);    /// device ID and R/W bit
   SerialCommRxByte(dataM, 0);        /// read data and send ACK
   SerialCommRxByte(dataL, 1);        /// read data and send ACK
   SerialCommStop();                 /// send the stop sequence
   
#elif defined USE_3_WIRE
   SerialCommRxByte(CW, dataM);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

   return KAL_TRUE;
}

static kal_bool AR1000_WriteByte(kal_uint8 CW, kal_uint16 data)
{
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(AR1000_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word   
   SerialCommTxByte(data>>8);           /// data to be written
   SerialCommTxByte(data&0xFF);           /// data to be written
   SerialCommStop();                 /// send the stop sequence
#elif defined USE_3_WIRE
   SerialCommTxByte(CW, data);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

#if defined AR1000_DEBUG
   AR1000_ReadByte(CW, &dbg_cw_readbackM, &dbg_cw_readbackL);
   dbg_cw_readdata = (kal_uint16)(dbg_cw_readbackM<<8|dbg_cw_readbackL);
#endif
  
   return KAL_TRUE;
}


/***********************************************************************
*  Set radio frequency (internal)
*
*  parameter-->CurFreq:set frequency
*         
***********************************************************************/
static kal_bool AR1000_SetFreq(kal_int32 CurFreq)
{

	kal_uint32 CHAN = 0x0000;
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead, i=0;


#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nAR1000_SetFreq(%d);\n\0", CurFreq);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
  if(pstFMR_data->bHWsearchStop)
  {
    do{
       	AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
       	dataRead = (kal_uint16)(dataM<<8|dataL);
       	if (i++ >= 6000){
   	  return KAL_FALSE;
        }
    }while ((dataRead & MASK_STC)==0);
  }
  i = 0;
   	//- Modified code start
      	AR1000_WriteByte(17, AR1000reg[17]);
      	//- Modified code end
   	
   	_current_frequency = CurFreq;
	CHAN = CurFreq - 690;
	CHAN = CHAN|0x200;//turn on TUNE
	AR1000_ReadByte(2, &dataM, &dataL);
	dataRead = (kal_uint16)(dataM<<8|dataL);
	AR1000_WriteByte(2, (dataRead&0xFC00)|CHAN);
	
	
	do {
         	AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
         	dataRead = (kal_uint16)(dataM<<8|dataL);
         
         	if (i++ >= 6000) {
            		return KAL_FALSE;
         	}
      	   } while ((dataRead & MASK_STC)==0);


   return KAL_TRUE;

}//AR1000_SetFreq

/***********************************************************************
*  Turn on/off tune (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void AR1000_TUNE_ON_OFF(kal_uint8 ON_OFF)
{
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead;
	
	AR1000_ReadByte(2, &dataM, &dataL);
	dataRead = (kal_uint16)(dataM<<8|dataL);
	if (ON_OFF == 1)
		AR1000_WriteByte(2, (dataRead&0xFDFF)|0x200);
	else
		AR1000_WriteByte(2, (dataRead&0xFDFF));
}

/***********************************************************************
*  Seek on/off (internal)
*
*  parameter-->ON_OFF: 1:ON, 0:OFF
*         
***********************************************************************/
void AR1000_SEEK_ON_OFF(kal_uint8 ON_OFF)
{
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead;
	
	AR1000_ReadByte(3, &dataM, &dataL);
	dataRead = (kal_uint16)(dataM<<8|dataL);
	if (ON_OFF == 1)
		AR1000_WriteByte(3, (dataRead&0xBFFF)|0x4000);
	else
		AR1000_WriteByte(3, (dataRead&0xBFFF));
}

/***********************************************************************
*  HiLo side Tune (internal)
*
*  parameter-->Freq: curf:875~1080
*							 band:range87.5~108.0
*         		 space:1:100k, 0:200k
***********************************************************************/
void AR1000_TUNE_HiLo(kal_int32 Freq, kal_int16 band, kal_int8 space)
{
	kal_int8 rssi;
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead;
	
	FMDrv_Mute(1);
      	SerialCommInit();
      
      	AR1000_SEEK_ON_OFF(0);
      	
      	AR1000_ReadByte(3, &dataM, &dataL);
      	dataRead = (kal_uint16)(dataM<<8|dataL);
      	AR1000_WriteByte(3, ((dataRead&0xC7FF)|(space<<13))|band);//set space(100k/200k)and band(875~1080)
        
        //Read Low-Side LO Injection
  	//R11 --> clear  D15,  clear D0/D2,  D3 is the same as default
  	AR1000_ReadByte(11, &dataM, &dataL);
  	dataRead = (kal_uint16)(dataM<<8|dataL);
  	AR1000_WriteByte(11, (dataRead&0x7FFA));
  	if (KAL_FALSE == AR1000_SetFreq(Freq)) 
      	{
         	ASSERT(0);
      	}    
      
       	AR1000_ReadByte(ADDR_RSSI, &dataM, &dataL);
       	dataRead = (kal_uint16)(dataM<<8|dataL);
  	rssi = (dataRead & MASK_RSSI);
  	
  	//Read Hi-Side LO Injection
  	// R11-->set D15, set D0/D2,  D3 is the same as default
  	AR1000_ReadByte(11, &dataM, &dataL);
  	dataRead = (kal_uint16)(dataM<<8|dataL);
  	AR1000_WriteByte(11, (dataRead&0x8005));
  	if (KAL_FALSE == AR1000_SetFreq(Freq)) 
      	{
         	ASSERT(0);
      	}  
      	
      	AR1000_ReadByte(ADDR_RSSI, &dataM, &dataL);
       	dataRead = (kal_uint16)(dataM<<8|dataL);
      	rssi = rssi- (dataRead & MASK_RSSI);  
      	
      	if (rssi < 0) //errata in 0.82
  	{ 	
		// LO
		// R11--> clear D15, set D0/D2, D3 is the same as default
		AR1000_ReadByte(11, &dataM, &dataL);
  		dataRead = (kal_uint16)(dataM<<8|dataL);
  		AR1000_WriteByte(11, (dataRead&0x7FFF)|0x0005);
  	}else{ 
		//HI
		//R11-->  set D15, clear D0/D2, D3 is the same as default
		AR1000_ReadByte(11, &dataM, &dataL);
  		dataRead = (kal_uint16)(dataM<<8|dataL);
  		AR1000_WriteByte(11, (dataRead|0x8000)&0xFFFA);
  	}
  	
  	//fine-tune !!
  	//TUNE to FreqKHz with current setting
  	if (KAL_FALSE == AR1000_SetFreq(Freq)) 
      	{
         	ASSERT(0);
      	}  
	
}

/***********************************************************************
*  Get RSSI Value (internal)
*
*  parameter-->
***********************************************************************/
kal_uint16 AR1000_GetCurRSSI(void)
{
   kal_uint8 TmpRegM, TmpRegL;
   kal_uint16 TmpReg;

   AR1000_ReadByte(ADDR_RSSI, &TmpRegM, &TmpRegL);
   TmpReg = (kal_uint16)(TmpRegM<<8|TmpRegL);
   return ((TmpReg & MASK_RSSI)>>9);
}

/***********************************************************************
*  Get IF_count Value (internal)
*
*  parameter-->
***********************************************************************/
kal_uint16 AR1000_GetCurIF(void)
{
   kal_uint8 TmpRegM, TmpRegL;
   kal_uint16 TmpReg;

   AR1000_ReadByte(ADDR_RSSI, &TmpRegM, &TmpRegL);
   TmpReg = (kal_uint16)(TmpRegM<<8|TmpRegL);
   return (TmpReg & 0x1FF);
}

/***********************************************************************
*  Get Search freq (internal)
*
*  parameter-->
***********************************************************************/
void AR1000_GetSearchFreq(kal_uint16 *pfreq)
{
	*pfreq = (kal_uint16)FreqKHz;
}

kal_uint16 FMDrv_ReadByte(kal_uint8 addr)
{
	kal_uint8 DataM, DataL;
	
	AR1000_ReadByte(addr, &DataM, &DataL);
	return (kal_uint16)(DataM<<8|DataL);
}

kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data)
{
	AR1000_WriteByte(addr, data);
	return 1;
}

void FMDrv_ChipInit(void)
{
//   /// power down the chip
//   kal_int32 i;
//   kal_uint8 tmp_reg;
   SerialCommInit();
   
   //- Modified code start
   AR1000_WriteByte(0, 0xFF7A); //0xFF7E
   //- Modified code end

   SerialCommCryClkOff();
   SerialCommRelease();
//#ifdef USE_AR1000_AMP
//   ExtSwitchInit();
//#endif
}


/***********************************************************************
*  Engineer mode function (API)
*
*  parameter-->group_idx: mono\stereo\RSSI_threshold\IF_count_delta
*              item_idx: sub select index
*              item_value: set parameter value
***********************************************************************/
void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
	kal_uint8 dataM, dataL;
   kal_uint16 dataRead;
	
	SerialCommInit();
	switch (group_idx)
	{
		case mono:
			if(item_value == 1)
  			{
      				AR1000_ReadByte(1, &dataM, &dataL); 
							dataRead = (kal_uint16)(dataM<<8|dataL);
							AR1000_WriteByte(1, (dataRead&0xFFF7)|0x08);

      	}
      	else
      	{
      				AR1000_ReadByte(1, &dataM, &dataL); 
							dataRead = (kal_uint16)(dataM<<8|dataL);
							AR1000_WriteByte(1, (dataRead&0xFFF7));
      	}
   
		break;
		case stereo:
			if(item_value == 0)
			{
				    AR1000_ReadByte(1, &dataM, &dataL); 
						dataRead = (kal_uint16)(dataM<<8|dataL);
						AR1000_WriteByte(1, (dataRead&0xFFF7)|0x08);
			}
			else
			{
				switch (item_idx)
				{
					case Sblend_ON:
//								MT6188_ReadByte(CW(14, 0), &TmpReg1);
//      					TmpReg1&=0x2F;
//      					MT6188_WriteByte(CW(14, 0),TmpReg1|0xD0);
//      					mono_flag = 3;
					break;
					case Sblend_OFF:
//								MT6188_ReadByte(CW(14, 0), &TmpReg1);
//      					TmpReg1&=0x2F;
//      					MT6188_WriteByte(CW(14, 0),TmpReg1|0x90);
//      					mono_flag = 4;
					break;
				}
			}
		break;
		case RSSI_threshold:
			if (item_value == 1)
		        	RSSI_value = 12;
		    	else if (item_value == 2)
		        	RSSI_value = 14;
		    	else if (item_value == 3)
		        	RSSI_value = 16;
		    	else if (item_value == 4)
		        	RSSI_value = 18;
		    	else if (item_value == 5)
		        	RSSI_value = 20;
		    	else if (item_value == 6)
		        	RSSI_value = 22;
		    	else
		    		RSSI_value = 16;//FM_RADIO_INPUT_LEVEL_THRESHOLD;
//					AR1000_ReadByte(3, &dataM, &dataL); 
//					dataRead = (kal_uint16)(dataM<<8|dataL);
//					AR1000_WriteByte(3, (dataRead&0xFF80)|RSSI_value);
		break;
		case IF_count_delta:

		break;
		
	}
	SerialCommRelease();
}



kal_bool FMDrv_IsChipValid( void )
{
	/// anything to do?
	return KAL_TRUE;
}



/// level ranges from 0 to 12
void FMDrv_SetVolumeLevel(kal_uint8 level)
{
  #ifdef AR1000_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetVolumeLevel(%d);\n\0", level);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
//   AR1000_SetVolumeLevel(level);
}

void FMDrv_Mute(kal_uint8 mute)
{
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead;
  #ifdef AR1000_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_Mute(%d);\n\0", mute);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

	SerialCommInit();
	AR1000_ReadByte(1,&dataM, &dataL);
	dataRead = (kal_uint16)(dataM<<8|dataL);
	if (mute == 1)
		AR1000_WriteByte(1, (dataRead&0xFFFD)|0x02);
	else
		AR1000_WriteByte(1, (dataRead&0xFFFD));      
      
      
      SerialCommRelease();
   
}


/*************************************************************
*  Radio power on Reset
*
*************************************************************/
void FMDrv_PowerOnReset(void)
{
   kal_uint8 fail_count=0;
   kal_uint16 dataRead;
   kal_int16 i;
   kal_uint8 dataM, dataL;
   

#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOnReset();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

#ifdef AR1000_DEBUG_DUMP_LOG
    _file_list = FS_Open((const WCHAR *)_channel_name, FS_CREATE);
   kal_sprintf((void*)_list_str, "\nchannel list;\n\0");
   FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
#endif   
   
   SerialCommInit();
   SerialCommCryClkOn();

    AR1000_ReadByte(0x1C, &dataM, &dataL);
    Chip_ID = (kal_uint16)((dataM<<8)|dataL);
    
    AR1000_ReadByte(0x1B, &dataM, &dataL);
    Device_ID = (kal_uint16)((dataM<<8)|dataL);
/// Power On
   
   //- Modified code start
   AR1000_WriteByte(0, 0xFF7A); //0xFF7E
   //- Modified code end
   
   if (RSSI_value != 0)
   	AR1000reg[3] = ((AR1000reg[3]&0xFF80)|RSSI_value);
   	 	
   for (i=1; i<18; i++)
   {
   	AR1000_WriteByte(i, AR1000reg[i]);
   }
   AR1000_WriteByte(0, AR1000reg[0]);
   
   do {
         AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
         dataRead = (kal_uint16)(dataM<<8|dataL);
         
         if (fail_count++ == 4000) {
            ASSERT(0);
         }
      } while ((dataRead & MASK_STC)==0);
   
   
   
   
   SerialCommRelease();
   _is_fm_on = KAL_TRUE;
   _current_frequency = -1;
//   _rssi_threshold = FM_RADIO_INPUT_LEVEL_THRESHOLD;
//   if(RSSI_offset != 0)
//    	_rssi_threshold = 6+RSSI_offset;    
//    	_rssi_threshold = 10+RSSI_offset;
   
#ifdef AR1000_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n Chip_ID = %d \n\0", duration_t, Chip_ID);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

}


/*****************************************************************
*  Radio power off
*
*****************************************************************/
void FMDrv_PowerOffProc(void)
{
//   kal_int16 i;
//   kal_uint8 tmp_reg;
   
#ifdef AR1000_DEBUG_DUMP_LOG
   if (_file_handle == 0)
      ASSERT(0);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOffProc();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   FS_Close(_file_handle);
   _file_handle = 0;
#endif   

#ifdef AR1000_DEBUG_DUMP_LOG
   if (_file_list == 0)
      ASSERT(0);
   kal_sprintf((void*)_list_str, "\nFMDrv_PowerOffProc();\n\0");
   FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
   FS_Close(_file_list);
   _file_list = 0;
#endif   
   
   
#ifdef USE_AR1000_AMP
   SwitchExtFMPath(0);
#endif

   SerialCommInit();
   
   //- Modified code start
   AR1000_WriteByte(0, 0xFF7A); //0xFF7E
   //- Modified code end
   
   SerialCommCryClkOff();
   SerialCommRelease();
   _is_fm_on = KAL_FALSE;
   _current_frequency = -1;
   
}


/*********************************************************************
*  Radio set frquency
*
*  parameter-->curf:setting frequency value
                    input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)
*********************************************************************/
void FMDrv_SetFreq( kal_int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	kal_uint8 dataM, dataL, PowerOn=0;
	kal_uint16 dataRead;
//   if (_current_frequency != curf) {
//      kal_int16 HiLo;
//      kal_int32 curFreq = (kal_int32)curf * FM_TUNER_GRID;
      
#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetFreq(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif
   pstFMR_data->is_searching = 0;
power_on_again:
      if (_is_fm_on != KAL_TRUE)
      {
         PowerOn = 1;
        FMDrv_PowerOnReset();
      }  
      FMDrv_Mute(1);
      SerialCommInit();
      
      AR1000_TUNE_ON_OFF(0);
      AR1000_SEEK_ON_OFF(0);
      
      AR1000_ReadByte(3, &dataM, &dataL);
      dataRead = (kal_uint16)(dataM<<8|dataL);
      AR1000_WriteByte(3, (dataRead&0xC7FF)|0x2000);//set space(100k/200k)and band(875~1080)
  
      if (KAL_FALSE == AR1000_SetFreq(curf)) 
      {
         if(PowerOn != KAL_TRUE)
         {
         	_is_fm_on = KAL_FALSE;
		goto power_on_again;
         }
	  else
         ASSERT(0);
      }     
//      AR1000_TUNE_HiLo(curf, 0, 1);
      SerialCommRelease();
      FMDrv_Mute(0);

#ifdef USE_AR1000_AMP
   SwitchExtFMPath(1);
#endif

#ifdef AR1000_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

}


/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetSigLvl( kal_int16 curf )
{
   kal_uint16 rssi;
   
#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetSigLvl(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
   
   if (curf != _current_frequency)
   	FMDrv_SetFreq( curf );
   SerialCommInit();
   rssi = AR1000_GetCurRSSI();
   SerialCommRelease();
   
#ifdef AR1000_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   RSSI returned: %d.\n\0", duration_t, rssi);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   return rssi;
}


/**********************************************************************
*  Get really IF count in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetIF( kal_int16 curf)
{
   kal_uint16 IF;

#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetIF(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   if (curf != _current_frequency)
      FMDrv_SetFreq( curf );
   SerialCommInit();
   IF = AR1000_GetCurIF();
   SerialCommRelease();

#ifdef AR1000_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   IF returned: %d.\n\0", duration_t, IF );
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return IF;
}

/***********************************************************************
*  FMDrv_Get_stereo_mono
*
*  parameter-->
* RETURNS
*  0:mono 1:stereo
***********************************************************************/
kal_uint8 FMDrv_Get_stereo_mono(void)
{
   return 0;
}

/**********************************************************************
*  Radio valid station,used in HW auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: start frequency
               is_step_up:1-->forward, 0-->backward
               space:search step,0:200KHz, 1:100KHz
**********************************************************************/
void FMDrv_HWSearch(kal_int16 freq, kal_bool is_step_up, kal_int16 space, kal_bool is_preset)
{
   kal_int32 targetFreq;
   kal_uint8 dataM, dataL, UpDown_flag=0;
   kal_uint16 dataRead;
   kal_uint8 _step;
   
//   kal_int8 pt;
    
//kal_uint32 save_irq_mask;
   
#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_ValidStop(%d, %d, %d);\n\0", freq, signalvl, is_step_up);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
			
				if (is_step_up)
					UpDown_flag = 1;
				HWSearch_flag = 0;
				Valid_flag = 0;
				FreqSt = freq;
//calculate starting frequency
			 if (!is_preset)
			{	// this is not a auto_scan function !
				targetFreq = (kal_int32)(freq);
			}else{
			 if( space )
			 {// 100K
				_step = 1;
			 }else{
			  //200K
				_step = 2;
			 }
			 if(is_step_up)
			 {// up
				targetFreq = (kal_int32)(freq-_step);
			}else{
			  //down
				targetFreq = (kal_int32)(freq+_step);
				if( targetFreq > 1080 )	targetFreq = 1080;
			}
			}
    		FMDrv_Mute(1);
    		SerialCommInit();

	//- Modified code start  
      	if (KAL_FALSE == AR1000_SetFreq(targetFreq)) 
      	{
      	   ASSERT(0);
      	}     
      
    		AR1000_TUNE_ON_OFF(0);
    		AR1000_SEEK_ON_OFF(0);
    	
//    		AR1000_ReadByte(3, &dataM, &dataL);
//      	dataRead = (kal_uint16)(dataM<<8|dataL);
//      	AR1000_WriteByte(3, (dataRead&0xC7FF)|0x2000);//set space(100k/200k)and band(875~1080)
      	
//      	if (KAL_FALSE == AR1000_SetFreq(targetFreq)) 
//      	{
//      	   ASSERT(0);
//      	}     

    		AR1000_ReadByte(3, &dataM, &dataL);
      	dataRead = (kal_uint16)(dataM<<8|dataL);
      	AR1000_WriteByte(3, (dataRead&0x47FF)|(UpDown_flag<<15)|(space<<13));//set space(100k/200k)and band(875~1080)and up/down

	// Setting before seek      
	AR1000_ReadByte(17, &dataM, &dataL);
	dataM = (dataM & 0xC3) | 0x20;
	dataL =(dataL &  0xFF) | 0x00;
      	dataRead = (kal_uint16)(dataM<<8|dataL);
      	AR1000_WriteByte(17, dataRead);
      
	if (!is_preset)
  	{	// this is not a auto_scan function !
		AR1000_WriteByte(10, AR1000reg[10]|0x0008); //enable wrap , if it is not auto scan function
    }else{
		AR1000_WriteByte(10, AR1000reg[10]&0xFFF7); //disable wrap , if it is auto scan function
	}	
    		AR1000_SEEK_ON_OFF(1);
//    		AR1000_ReadByte(3, &dataM, &dataL);
//      	dataRead = (kal_uint16)(dataM<<8|dataL);
//      	AR1000_WriteByte(3, (dataRead&0x47FF)|(UpDown_flag<<15)|(space<<13));//set space(100k/200k)and band(875~1080)and up/down
   	//- Modified code end
//   return 1;
}

kal_uint8 FMDrv_HWSpolling(kal_uint16 *curf, kal_uint8 *is_valid)
{
	kal_uint8 dataM, dataL;
	kal_uint16 dataRead;

   	AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
        dataRead = (kal_uint16)(dataM<<8|dataL);
   	HWSearch_flag = dataRead & MASK_STC; // check STC flag 
  	while( HWSearch_flag == 0)
  	{
		// maybe you can delay for a while
		// delay ( 100 ms )
		if(pstFMR_data->bHWsearchStop == 1)
  		{
  			*curf = FreqSt;
  			*is_valid = 0;
			AR1000_SEEK_ON_OFF(0);
  			return 0;
  		}
		AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
         	dataRead = (kal_uint16)(dataM<<8|dataL);
		HWSearch_flag = dataRead & MASK_STC; // check STC flag 
		if(!HWSearch_flag)
			kal_sleep_task(5);
		Valid_flag = 1;
  	}
 	FreqKHz = 690 + ((dataRead & MASK_READCHAN )>> SHIFT_READCHAN );			
	if (pstFMR_data->is_preset)
  	{
   		if (FreqKHz == 1080)
  		{
  			HWSearch_flag = 1;
  			Valid_flag = 0;
  		}
  	}
	if((dataRead & MASK_SF)!=0)
	{
      	 HWSearch_flag = 1;
      	 Valid_flag = 0;
	}			

      	//- Modified code start
      	// Restore setting after seek
      	AR1000_WriteByte(17, AR1000reg[17]);
      	//- Modified code end
      		   
  			FMDrv_Mute(0);
   			SerialCommRelease();

	if (HWSearch_flag != 0)
	{
		AR1000_GetSearchFreq(curf); 
		AR1000_SEEK_ON_OFF(0);
		if (Valid_flag == 1)
			*is_valid = 1;
		else
			*is_valid = 0;
		return 1;
	}
	else
		return 0;
}
/**********************************************************************
*  Radio valid station,used in auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: frequency
               signalv1:signal level range is 0 ~ 15 
               is_step_up:return value(Reserved)
**********************************************************************/
kal_uint8 FMDrv_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up)
{
   kal_int32 targetFreq;
   kal_uint8 dataM, dataL;
   kal_uint16 dataRead, i=0;
   
//   kal_int8 pt;
    
//kal_uint32 save_irq_mask;
   
#ifdef AR1000_DEBUG_DUMP_LOG
   kal_uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_ValidStop(%d, %d, %d);\n\0", freq, signalvl, is_step_up);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   

	targetFreq = (kal_int32)freq;
	
    	FMDrv_Mute(1);
    	SerialCommInit();
      
    	AR1000_TUNE_ON_OFF(0);
    	AR1000_SEEK_ON_OFF(0);
    	
    	AR1000_ReadByte(3, &dataM, &dataL);
      	dataRead = (kal_uint16)(dataM<<8|dataL);
      	AR1000_WriteByte(3, (dataRead&0xC7FF)|0x2000);//set space(100k/200k)and band(875~1080)
      	
      	if (KAL_FALSE == AR1000_SetFreq(targetFreq)) 
      	{
      	   ASSERT(0);
      	}     
      
    	AR1000_SEEK_ON_OFF(1);
    	AR1000_ReadByte(3, &dataM, &dataL);
      	dataRead = (kal_uint16)(dataM<<8|dataL);
      	AR1000_WriteByte(3, (dataRead&0x47FF)|(is_step_up<<15)|0x2000);//set space(100k/200k)and band(875~1080)
   
   	do {
         	AR1000_ReadByte(ADDR_STATUS, &dataM, &dataL);
         	dataRead = (kal_uint16)(dataM<<8|dataL);
         
         	if (i++ >= 4000) {
            		return 0;
         	}
      	   } while ((dataRead & MASK_STC)==0);
      	   
      	 if((dataRead & MASK_SF)!=0)
      	 	return 0;
      	 	
      	 
  	FMDrv_Mute(0);


   SerialCommRelease();

   return 1;
}


#endif // defined(AR1000A1)



