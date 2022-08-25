/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	isp_yuv_if_v2.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP SW Interface about raw camera.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(ISP_SUPPORT))
#include "kal_release.h"
#include "drv_features.h"
//#if (defined(DRV_ISP_6235_SERIES)&&(defined(MT6253E)||defined(MT6253L)))
//#include "isp_if.h"
//#include "typedefs.h"
//#include "sccb_v2.h"
//#include "sensor.h"
//#include "isp_if_hw.h"
//#include "cirq.h"
//#include "img_common_enum.h"

//#include "idp_test.h"

//#include "Sensor_common_interface.h"
#include "Sensor_frame_rate_lut.h"

#if 1//defined(__SENSOR_FRAME_RATE_SUPPORT__)

SENSOR_FRAMERATE_IN_STRUCT SensorFrameRateInputPara;

const SENSOR_FRAME_RATE_ISP_STRUCT IspLutPara[MAX_ISP_HW_LIMITATION_LUT_NO] = ISP_HW_LIMITATION_LUT;

const SENSOR_FRAME_RATE_CHIP_RECORD_STRUCT ChipPreviewLutPara[SENSOR_FRAME_CHIP_LUT_PREVIEW_NO] = SENSOR_FRAME_RATE_CHIP_PREIVEW_LUT;
const SENSOR_FRAME_RATE_CHIP_RECORD_STRUCT ChipCaptureLutPara[SENSOR_FRAME_CHIP_LUT_CAPTURE_NO] = SENSOR_FRAME_RATE_CHIP_CAPTURE_LUT;
const SENSOR_FRAME_RATE_CHIP_RECORD_STRUCT ChipMp4LutPara[SENSOR_FRAME_CHIP_LUT_MP4_NO] = SENSOR_FRAME_RATE_CHIP_MP4_LUT;

//const SENSOR_FRAME_RATE_CHIP_STRUCT ChipLutPara[SENSOR_FRAME_CHIP_LUT_TOTAL_NO] = SENSOR_FRAME_RATE_CHIP_LUT;
SENSOR_FRAME_RATE_CHIP_STRUCT ChipLutPara = SENSOR_FRAME_RATE_CHIP_LUT;
//const SENSOR_FRAME_RATE_MP4_STRUCT Mp4LutPara[MAX_SENSOR_FRAME_MP4_LUT_NO] = SENSOR_FRAME_RATE_MP4_LUT;
SENSOR_FRAME_RATE_OVERALL_STRUCT SensorFrameRateOverallPara =SENSOR_FRAME_RATE_OVERALL_LUT;

SENSOR_FRAME_RATE_ISP_STRUCT IspSensorFrameRateLimitation;

kal_bool LutIspMatch = KAL_FALSE, LutChipMatch = KAL_FALSE,	 LutVideoMatch = KAL_FALSE;

kal_bool SensorCommonIsDataFormatMatch(IMAGE_SENSOR_DATA_OUT_FORMAT_ENUM TableDataFmt ,IMAGE_SENSOR_DATA_OUT_FORMAT_ENUM SensorDataFmt){

    kal_bool IsMatch = KAL_FALSE;
    switch(SensorDataFmt){
        case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST:
        case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST:
        case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST:
        case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST:
            if(TableDataFmt<= IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST){
                IsMatch = KAL_TRUE;
            }
            break;
			
        case IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_VYUY :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_YVYU :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_CbYCrY :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_CrYCbY :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_YCbYCr :
        case IMAGE_SENSOR_DATA_OUT_FORMAT_YCrYCb :
            if(TableDataFmt<= IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG&&TableDataFmt>= IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY){
                IsMatch = KAL_TRUE;
            }

            break;
        case IMAGE_SENSOR_DATA_OUT_FORMAT_RGB565 :
            if(TableDataFmt== IMAGE_SENSOR_DATA_OUT_FORMAT_RGB565){
                IsMatch = KAL_TRUE;
            }

            break;
        default:
            break;			
    }

    return IsMatch;
}



MM_ERROR_CODE_ENUM SensorCommonGetFrameRate(SENSOR_FRAMERATE_IN_STRUCT *InPara, SENSOR_FRAMERATE_OUT_STRUCT *OutPara)
{
	kal_uint16 i=0;
	kal_uint16 ChipLutMaxNo=0;
	kal_bool CrzTwoPassEnable;
	//kal_uint16 LutIndex[2] = {0,0};
	MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
	PSENSOR_FRAME_RATE_CHIP_SUB_STRUCT pSensorFrameRateChipSub = NULL;

    LutIspMatch = KAL_FALSE; 
    LutChipMatch = KAL_FALSE;
    LutVideoMatch = KAL_FALSE;
#if !(defined(MT6253E)||defined(MT6253L)) // currently only apply on MT6253EL
	//return MM_ERROR_SENSOR_FRAME_RATE_LUT_NOT_SUPPORT;
#endif
	//set default value
	memcpy(&OutPara->IspHwLimitation,&SensorFrameRateOverallPara.pIspLutPara[0].IspLimitPara, sizeof(SENSOR_FRAME_RATE_ISP_LIMIT_PARA_STRUCT));

	if(InPara->Scenario == CAL_SCENARIO_CAMERA_PREVIEW)
	{
		pSensorFrameRateChipSub = &SensorFrameRateOverallPara.pChipLutPara->pPreviewChipLUT[0];
		ChipLutMaxNo = SENSOR_FRAME_CHIP_LUT_PREVIEW_NO;
	}else if(InPara->Scenario == CAL_SCENARIO_CAMERA_STILL_CAPTURE)
	{
		pSensorFrameRateChipSub = &SensorFrameRateOverallPara.pChipLutPara->pCaptureChipLUT[0];
		ChipLutMaxNo = SENSOR_FRAME_CHIP_LUT_CAPTURE_NO;
	}else if(InPara->Scenario == CAL_SCENARIO_VIDEO)
	{
		pSensorFrameRateChipSub = &SensorFrameRateOverallPara.pChipLutPara->pVideoChipLUT[0];
		ChipLutMaxNo = SENSOR_FRAME_CHIP_LUT_MP4_NO;
	}else
	{
		ASSERT(0);
	}
	OutPara->OtfCriticalDzFactor = (pSensorFrameRateChipSub+i)->MaxDzFactor;
	OutPara->MaxSensorFrameRate = (pSensorFrameRateChipSub+i)->MaxSensorFrameRate;
	CrzTwoPassEnable = (pSensorFrameRateChipSub+i)->CrzTwoPassEnable;

	//dbg_print("1.OutPara  DZ (%d) FrameRate(%d)  Crz2Pass (%d)\r\n",
		//OutPara->OtfCriticalDzFactor ,	OutPara->MaxSensorFrameRate , CrzTwoPassEnable);
	for(i=0; i<MAX_ISP_HW_LIMITATION_LUT_NO ; i++ )
	{
		
	
		if((SensorFrameRateOverallPara.pIspLutPara[i].CameraIf == InPara->CameraIf) &&
            //(SensorFrameRateOverallPara.pIspLutPara[i].DataFormat == InPara->DataFormat)&&
			((SensorFrameRateOverallPara.pIspLutPara[i].SourceWidth >= (InPara->SourceWidth)) &&
			 (SensorFrameRateOverallPara.pIspLutPara[i].SourceHeight >= (InPara->SourceHeight)))&&
			(((SensorFrameRateOverallPara.pIspLutPara[i].SourceWidth*15)>>4 <= InPara->SourceWidth ) &&
			 ((SensorFrameRateOverallPara.pIspLutPara[i].SourceHeight*15)>>4 <= InPara->SourceHeight ))
		){
                if(KAL_TRUE == SensorCommonIsDataFormatMatch(SensorFrameRateOverallPara.pIspLutPara[i].DataFormat,InPara->DataFormat))
                {
			LutIspMatch = KAL_TRUE;
			memcpy(&OutPara->IspHwLimitation,&SensorFrameRateOverallPara.pIspLutPara[i].IspLimitPara, sizeof(SENSOR_FRAME_RATE_ISP_LIMIT_PARA_STRUCT));
			break;
                }
		}

	}


	for(i=0; i<ChipLutMaxNo ; i++ )
	{
		if(((pSensorFrameRateChipSub+i)->CameraIf == InPara->CameraIf) &&
			//((pSensorFrameRateChipSub+i)->DataFormat == InPara->DataFormat)&&
			(((pSensorFrameRateChipSub+i)->SourceWidth >= (InPara->SourceWidth)) &&
			((pSensorFrameRateChipSub+i)->SourceHeight >= (InPara->SourceHeight)))&&
			((((pSensorFrameRateChipSub+i)->SourceWidth*15)>>4 <= InPara->SourceWidth ) &&
			 (((pSensorFrameRateChipSub+i)->SourceHeight*15)>>4 <= InPara->SourceHeight ))
		){

                if(KAL_TRUE == SensorCommonIsDataFormatMatch((pSensorFrameRateChipSub+i)->DataFormat ,InPara->DataFormat))
                {

			LutChipMatch = KAL_TRUE;
			OutPara->OtfCriticalDzFactor =(pSensorFrameRateChipSub+i)->OtfCriticalDzFactor ;
			if(InPara->NighhtMode)
				OutPara->MaxSensorFrameRate=(pSensorFrameRateChipSub+i)->NightModeFrameRate ;
			else
				OutPara->MaxSensorFrameRate=(pSensorFrameRateChipSub+i)->MaxSensorFrameRate ;


			CrzTwoPassEnable = (pSensorFrameRateChipSub+i)->CrzTwoPassEnable ;
			break;
                }
		}
	}

	//dbg_print("2.OutPara  DZ (%d) FrameRate(%d)  Crz2Pass (%d)\r\n",
		//OutPara->OtfCriticalDzFactor ,	OutPara->MaxSensorFrameRate , CrzTwoPassEnable);


	if(InPara->Scenario == CAL_SCENARIO_VIDEO){// should also reference ME1 Video frame rate table
		if(OutPara->MaxSensorFrameRate> (InPara->EncodeFramRate*(CrzTwoPassEnable+1)))
			OutPara->MaxSensorFrameRate = (InPara->EncodeFramRate*(CrzTwoPassEnable+1));
	}
	//dbg_print("3.LutIspMatch  (%d) LutChipMatch(%d)  LutVideoMatch (%d) [%d,%d,%d]\r\n",
		//LutIspMatch,LutChipMatch,LutVideoMatch,LutIndex[0],LutIndex[1],LutIndex[2]);

	if(/*(LutIspMatch==KAL_FALSE)||*/(LutChipMatch==KAL_FALSE))
	{
		ret =  MM_ERROR_SENSOR_FRAME_RATE_LUT_NOT_MATCH;
		//ASSERT(0);
	}
	return ret;

}

#if 0
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


#endif/*__SENSOR_FRAME_RATE_SUPPORT__*/


//#endif /* MT6235 */
#endif /* ISP_SUPPORT */

