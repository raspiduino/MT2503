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
 * l1sp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Interface 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_trace.h"
#include "string.h"
#include "reg_base.h"
//#include "ps_trace.h"
#include "custom_equipment.h" /* custom_cfg_audio_ec_range() */
#include "device.h" /* MAX_VOL_LEVEL,  in ps\l4\include */
#include "audcoeff_default.h"

#include "audio_def.h"
#include "speech_def.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "ddload.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "speech_enh_def.h"

#if defined(__VM_CODEC_SUPPORT__) 
#include "l1audio_sph_trc.h"   
#endif

#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h"
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_app.h"
#endif

/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
#if defined(__AUDIO_AT_CMD__)
	SPE_ECNRPARAM_STRUCT_T ecnrparam;
#endif

typedef enum{
	L1SP_NVRAM_VALUES_FLAG_MODE = 0x1,
	L1SP_NVRAM_VALUES_FLAG_IN_FIR = 0x2,
	L1SP_NVRAM_VALUES_FLAG_OUT_FIR = 0x4,
	L1SP_NVRAM_VALUES_FLAG_WB_MODE = 0x8,
	L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR = 0x10,
	L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR = 0x20,
	L1SP_NVRAM_VALUES_FLAG_RECORD_MODE = 0x40,
	L1SP_NVRAM_VALUES_FLAG_RECORD_IN_FIR = 0x80,
	L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM = 0x100,
}L1SP_INTERNAL_NVRAM_VALUES_FLAG; // for NvramValuesFlag


static struct {
   uint16   aud_id;

   uint8    sph_mode;
   uint8    sph_level;
   uint16   sph_c_para[NUM_COMMON_PARAS];
   uint16   sph_m_para[NUM_MODE_PARAS];
   uint16   sph_v_para[NUM_VOL_PARAS];   
#if defined(__DUAL_MIC_SUPPORT__)
   int16    sph_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
   int16    sph_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
#endif    
   uint8    min_ec_level;
   uint8    max_ec_level;
   uint8    mic_volume; 
   uint8    mic_volume_fromMED; 
   uint8    mic_volume_adapted; 
   uint8    sph_dl_vol;
   uint16   spe_app_mask;    //record the usage every application should have . Ex. phonecall should be turned on DMNR. please do not update the mask directly, please use function l1sp_updateSpeFlag() to update
   uint16   spe_usr_mask;   //record the usage use choose . Ex. phonecall should be turned on DMNR, but users can decide whether turn on or not.please do not update the mask directly, please use function l1sp_updateSpeFlag() to update   
   uint8    spe_state;   
   bool     spe_flag;   
   bool     isULMute;
   bool     tch_state; // true: TCH on; false: TCH off
   bool     pcmplayback_flag; // only used in META taste function.
   bool     speech_dmnr_loopback;     
   bool     isVocOn;
   uint8    state;          
   uint8    output_dev;
   bool     bt_on;
   bool     interRAT;
   void (*onHandler)(void *); 
   void (*offHandler)(void *); 

#if defined(__ECALL_SUPPORT__)
   void (*pcm4wayOnHandler)(void *); 
   void (*pcm4wayOffHandler)(void *);
#endif

   //value from nvram 
   uint16   setNvramValuesFlag; //bit 0 for sph_allModePara, bit 1 for sph_allInFirCoeff, bit 2 for sph_allOutFirCoeff, 
                                //bit 3 for sph_allWbModePara, bit 4 for sph_allWbInFirCoeff, bit 5 for sph_allWbOutFirCoeff
                                //bit 6 for recordModePara, bit 7 for recordInFirCoeff
                                //bit 8 for sph_allVolumePara 
   
   uint16 sph_allModePara[NUM_SPH_MODE][NUM_MODE_PARAS];   
   int16 sph_allInFirCoeff[NUM_SPH_INPUT_FIR][NUM_FIR_COEFFS];
   int16 sph_allOutFirCoeff[NUM_SPH_OUTPUT_FIR][NUM_FIR_COEFFS];
   uint16 sph_allVolumePara[3][7][4];
   uint16 sph_selectedOutFirIndex;
   
#if defined(__AMRWB_LINK_SUPPORT__)
   uint16 sph_allWbModePara[NUM_SPH_MODE][NUM_MODE_PARAS];
   int16 sph_allWbInFirCoeff[NUM_SPH_INPUT_FIR][NUM_WB_FIR_COEFFS];
   int16 sph_allWbOutFirCoeff[NUM_SPH_OUTPUT_FIR][NUM_WB_FIR_COEFFS];
#endif //__AMRWB_LINK_SUPPORT__

#if defined(__HD_RECORD__)
   uint16 recordModePara[NUM_RECORD_SPH_MODE][NUM_MODE_PARAS];
   int16  recordInFirCoeff[NUM_RECORD_INPUT_FIR][NUM_WB_FIR_COEFFS];
   uint16 *recordModeFirMappingCh1;
#if defined(__STEREO_RECORD__)
   uint16 *recordModeFirMappingCh2;
#endif 
   uint8  *recordModeDeviceMapping;
#endif //defined(__HD_RECORD__)

   int16 numOfRecordMode;
   int16 numOfRecordInFir;
   
#if defined(__CVSD_CODEC_SUPPORT__) 
   kal_uint8  cordless_path;
#endif
#if defined(__VOICE_CHANGER_SUPPORT__)
   SPH_VOICE_CHANGER_MODE vchg_mode;
#endif
} l1sp;

static kal_bool lineon_flag = KAL_FALSE; 

#if _SPE_FOR_TEST_SIM_
#include "Sim_common_enums.h"
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
const uint16 m_para_for_test_sim[NUM_MAX_MODE_PARAS] = 
{
       96,       221, 16388,  30,   57351,    31,   400,     0, \
     4112,      229,     3,     0,       0,     0,     0,     8192  \
};
#endif
#endif//#if _SPE_FOR_TEST_SIM_

extern void AFE_SetGainFastRamp(kal_bool enable);
extern void SPE_CustomProcess(kal_bool enable, kal_uint16 sph_mode, SPE_Par_Struct *SPE_PAR, kal_uint8 *next_state);
extern void DTMF_MCU_StopAndWait(void);
#if defined(__CVSD_CODEC_SUPPORT__) 
extern void BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH uPath);
#endif
extern void PcmSink_TerminateSound(void);
extern void AFE_TurnOnLoopback(void);
extern void AFE_TurnOffLoopback(void);

#if defined(__BT_SUPPORT__)
bool L1SP_IsBluetoothOn( void )
{
   return (bool)(l1sp.sph_mode==SPH_MODE_BT_CORDLESS || l1sp.sph_mode==SPH_MODE_BT_EARPHONE || 
      l1sp.sph_mode==SPH_MODE_BT_CARKIT || l1sp.sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS);
}
#endif

void L1SP_UpdateSpeechPara( uint16 sph_m_para[NUM_MAX_MODE_PARAS] )
{
   memcpy(l1sp.sph_m_para, sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
}

#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
static kal_uint16 L1SP_GetAudID(void)/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/
{
   kal_uint16 aud_id;
   aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
   return aud_id;
}
static void L1SP_FreeAudID(kal_uint16 aud_id)
{
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
}
#endif

/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
uint8 spe_table[SPH_MODE_UNDEFINED] = {
#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_AEC_NR_DRC__)
    //----------------------------------SPH_MODE_NORMAL----------------------------------------------//
    0,
    //----------------------------------SPH_MODE_EARPHONE--------------------------------------------//
    0,
    //----------------------------------SPH_MODE_LOUDSPK---------------------------------------------//
    0,
    //----------------------------------SPH_MODE_BT_EARPHONE-----------------------------------------//
    0,
    //----------------------------------SPH_MODE_BT_CORDLESS-----------------------------------------//
    0,
    //----------------------------------SPH_MODE_BT_CARKIT-------------------------------------------//
    0,
    //----------------------------------SPH_MODE_AUX1------------------------------------------------//
    0,
    //----------------------------------SPH_MODE_AUX2------------------------------------------------//
    // Used for megaphone
    0,
    //----------------------------------SPH_MODE_LINEIN_VIA_BT_CORDLESS------------------------------//
    0
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    //----------------------------------SPH_MODE_NORMAL----------------------------------------------//
    0
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#if defined(__DUAL_MIC_SUPPORT__)
    + SPE_DMNR_FLAG
#endif  // #if defined(__DUAL_MIC_SUPPORT__)
#endif  // #if defined(AEC_ENABLE)
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_EARPHONE--------------------------------------------//
    0
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#endif
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_LOUDSPK---------------------------------------------//
    0
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#endif
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_BT_EARPHONE-----------------------------------------//
    0
#if defined(AEC_ENABLE) && defined(__BT_SUPPORT__)
    + SPE_AEC_FLAG
#endif
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_BT_CORDLESS-----------------------------------------//
    0
#if defined(BT_DIALER_SPE_FOR_LOUDSPEAKER) || defined(BT_DIALER_SPE_FOR_RECEIVER)
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG
#endif  // #if defined(BT_DIALER_SPE_FOR_LOUDSPEAKER) || defined(BT_DIALER_SPE_FOR_RECEIVER)
    ,
    //----------------------------------SPH_MODE_BT_CARKIT-------------------------------------------//
    0
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#endif
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_AUX1------------------------------------------------//
    0,
    //----------------------------------SPH_MODE_AUX2------------------------------------------------//
    // Used for megaphone
    0
#if defined(AEC_ENABLE)
    + SPE_AEC_FLAG
#endif
#if TDDNC_SUPPORT
    + SPE_TDDNC_FLAG
#endif
    + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG,
    //----------------------------------SPH_MODE_LINEIN_VIA_BT_CORDLESS------------------------------//
    0
#endif
};   

#if __RELOAD_DSP_COEFF__

void L1SP_Reload_DMNR_Para(void)
{
#if defined(__DUAL_MIC_SUPPORT__)

	SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para);
	
#if defined(__AMRWB_LINK_SUPPORT__)
	SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__

#endif //__DUAL_MIC_SUPPORT__
}

void L1SP_Reload_SPE_Para( void )
{
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para);
}
#endif

void L1SP_Init_PCMPlayback(uint8 sph_mode, bool bDigitalGain, uint16 digital_gain)
{
	 unsigned short Speech_Normal_Mode_Para[16] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
   unsigned short Speech_Earphone_Mode_Para[16] = DEFAULT_SPEECH_EARPHONE_MODE_PARA;
   unsigned short Speech_Loudspeaker_Mode_Para[16] = DEFAULT_SPEECH_LOUDSPK_MODE_PARA;
	 
	 switch(sph_mode) {
	 case SPH_MODE_NORMAL:
	     if(bDigitalGain == true) {
	        Speech_Normal_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_NORMAL, Speech_Normal_Mode_Para);
	 		break;
	 case SPH_MODE_EARPHONE:
	     if(bDigitalGain == true) {
	        Speech_Earphone_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_EARPHONE, Speech_Earphone_Mode_Para);
	 	  break;
	 case SPH_MODE_LOUDSPK: 
	     if(bDigitalGain == true) {
	        Speech_Loudspeaker_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_LOUDSPK, Speech_Loudspeaker_Mode_Para);
	 	  break;
	 default:
	 	  break;
	 } 
}

void L1SP_EnableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = true;
}

void L1SP_DisableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = false;
}

bool L1SP_CheckStrmPcmSPE(void)
{
	 return l1sp.pcmplayback_flag;
}

void l1sp_updateSpeAppMask(uint16 updateFlags, bool enable)
{
	if(enable)
		l1sp.spe_app_mask |= (updateFlags);
	else
		l1sp.spe_app_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_APP_MASK, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateFlags, enable);
	
}

void l1sp_updateSpeUsrMask(uint16 updateFlags, bool enable)
{
	if(enable)
		l1sp.spe_usr_mask |= (updateFlags);
	else
		l1sp.spe_usr_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_USR_MASK, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateFlags, enable);	
}

void SetSpeechEnhancement( bool ec )
{
#if defined(CHIP_BACK_SPH_PHONE_CALL)
    // no speech enhancement at chip back phone call
    return;
#endif
    if (((!AM_IsAmInSpeechState() || !l1sp.spe_flag) && !l1sp.pcmplayback_flag)
        || Media_IsKaraoke())
    {
        return;
    }
    
    ASSERT(l1sp.sph_mode<SPH_MODE_UNDEFINED);
    
    kal_trace( TRACE_INFO, L1SP_APPLY_MODE, (ec) ? 1 : 0, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume);
    
    if (ec)
    {
        uint8 next_state, keep_on_state, on_state, off_state;
        uint8 i;
        
        next_state = spe_table[l1sp.sph_mode];
        if (l1sp.bt_on)
        {   // For BT PLC
            l1sp_updateSpeAppMask(SPH_ENH_MASK_AGC, false);
        }
        
        {
            SPE_Par_Struct spe_par;
            spe_par.mode_par   = l1sp.sph_m_para;
            spe_par.common_par = l1sp.sph_c_para;
            AM_GetFirCoeffs(&spe_par.in_fir, &spe_par.out_fir);
            SPE_CustomProcess(KAL_TRUE,0,0,0);	
        }
        
        // Use "l1sp.spe_app_mask" to control the open / close of speech enhancment
        for (i = 0; i < NUM_OF_SPH_FLAG; i++)
        {
            uint8 tempMaskBit = (1<<i);
            if (((l1sp.spe_app_mask & tempMaskBit) == 0 || (l1sp.spe_usr_mask & tempMaskBit) == 0)
	            && (next_state & tempMaskBit))
            {
                next_state -= tempMaskBit;
            }
        }
        
        keep_on_state = next_state & l1sp.spe_state; 
        on_state = next_state - keep_on_state;
        off_state = l1sp.spe_state - keep_on_state;
        
        kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT, keep_on_state, on_state, off_state);
        
        if (off_state)
        {
            SPE_TurnOffProcess(off_state);
        }
        
        if (next_state)
        {
            kal_trace(TRACE_INFO, L1SP_SPEECH_ENHANCEMENT, next_state, l1sp.sph_m_para[0], l1sp.sph_m_para[1], l1sp.sph_c_para[0], l1sp.sph_c_para[1]);
            
            if (next_state & (SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG))
            {
                SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para);
            }
            
#if defined(__DUAL_MIC_SUPPORT__)
            if (next_state & SPE_DMNR_FLAG)
            {
                SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para);
#if defined(__AMRWB_LINK_SUPPORT__)
                SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__
            }
#endif //__DUAL_MIC_SUPPORT__
            
            if (on_state)
            {
                SPE_TurnOnProcess(on_state);
            }
        }
        
        l1sp.spe_state = next_state;
        SPE_Clear_DLL_Entry(l1sp.spe_state);
    }
    else
    {
        if (l1sp.spe_state)
        {
            SPE_TurnOffProcess(l1sp.spe_state);
            l1sp.spe_state = 0;
            SPE_Clear_DLL_Entry(0);
        }
        
        SPE_CustomProcess(KAL_FALSE,0,0,0);
    }
    
    if (l1sp.spe_app_mask & SPH_ENH_MASK_SIDETONE)
    {
#if defined(AEC_ENABLE)
        if (l1sp.sph_mode == SPH_MODE_LOUDSPK)
#else
        if (l1sp.sph_mode == SPH_MODE_LOUDSPK || (l1sp.sph_mode == SPH_MODE_NORMAL && l1sp.sph_level == MAX_VOL_LEVEL - 1))
#endif
        {
            AFE_SetSidetone(false); // If AEC is turned off or the big volume of DL, it will cause sidetone to generate the howling effect
        }
        else
        {
            AFE_SetSidetone(true);
        }
    }
    
    return;
}

void L1SP_LoadCommonSpeechPara( uint16 c_para[NUM_MAX_COMMON_PARAS] )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif    
   memcpy(l1sp.sph_c_para, c_para, NUM_COMMON_PARAS*sizeof(uint16));
   SetSpeechEnhancement( true );
   
   // Some common parameters are used in non-speech function
   // Force to load common parameter
   SPE_LoadSpeechPara(l1sp.sph_c_para, NULL, NULL);

#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif
}

#if defined(__DUAL_MIC_SUPPORT__)

/**
@deprecated
*/
void L1SP_SetABFPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
   L1SP_SetDMNRPara(DMNR_para);
}

void L1SP_SetDMNRPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
	
	memcpy(&l1sp.sph_dmnr_para, DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
	SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para);
}

#if defined(__AMRWB_LINK_SUPPORT__)
void L1SP_SetWbDMNRPara( kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&l1sp.sph_wb_dmnr_para, WB_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
	SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para);
}

#endif //__AMRWB_LINK_SUPPORT__


#endif //__DUAL_MIC_SUPPORT__

void L1SP_SetDualMicNR( kal_bool enable )
{
	kal_trace( TRACE_INFO, L1SP_ENABLE_DUAL_MIC_NR, enable );
	
#if defined(__DUAL_MIC_SUPPORT__)
   /*
   if(enable)
      l1sp.spe_app_mask |= (SPH_ENH_MASK_DMNR);
   else
      l1sp.spe_app_mask &= ~(SPH_ENH_MASK_DMNR);
      */
   l1sp_updateSpeUsrMask(SPH_ENH_MASK_DMNR, enable);
   if(l1sp.spe_state) { // already turn on speech enhancement 
      SetSpeechEnhancement(KAL_TRUE);
   }

#endif //__DUAL_MIC_SUPPORT__

}

kal_uint8 L1SP_GetSpeechMode( void )
{
    return l1sp.sph_mode;
}

#if defined(__CVSD_CODEC_SUPPORT__) 
static void setBt(uint32 scene, uint32 preScene)
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SET_BT, scene, preScene, l1sp.bt_on);
   ASSERT(scene != SPH_MODE_LINEIN_VIA_BT_CORDLESS); //not available from MT6250 & MT6260
   BT_SCO_Disable_All_APP();
   
   if(l1sp.bt_on || scene == SPH_MODE_BT_CORDLESS || scene == SPH_MODE_BT_EARPHONE || scene == SPH_MODE_BT_CARKIT)
   {
      DTMF_MCU_StopAndWait();
      KT_StopAndWait();
      TONE_StopAndWait();
   }

   if(l1sp.bt_on)
   {
      if(AM_IsBTCordlessMode() || AM_IsBluetoothOn())
      {
         if( preScene == SPH_MODE_BT_CORDLESS) 
         {
            AM_BTCordlessOff();
         } 
         AM_BluetoothOff();
      }
      l1sp.bt_on = false;
   }

   if( scene == SPH_MODE_BT_CORDLESS || scene == SPH_MODE_BT_EARPHONE || scene == SPH_MODE_BT_CARKIT )
   {
      if(l1sp.cordless_path == SPH_CORDLESS_PATH_BT)
      {
         if( scene == SPH_MODE_BT_CORDLESS) 
         {
            extern void BT_SCO_Cordless_ON(kal_uint32 uSampleRate, kal_uint32 uChannelNumber);
            BT_SCO_Cordless_ON(8000, 1);
         }
         else if(AM_IsAudioPlaybackOn() != -1)
         {
#if defined ( __BT_AUDIO_VIA_SCO__ )          	
            extern void BT_SCO_AudioPath_ON(void);
            BT_SCO_AudioPath_ON();
#endif            
         }
         else if(L1SP_IsSpeechOn())
         {
            BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BOTH);
         }
         else if(AM_IsToneOn()|| AM_IsKeyToneOn())
         {
            BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BTUL);
         }
         else if(AM_IsConflictState())
         {
            BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BTDL);
         }
      }
      else //SPH_CORDLESS_PATH_PCM
      {
         if( scene == SPH_MODE_BT_CORDLESS) 
         {
            AM_BluetoothOn(1);
            AM_BTCordlessOn();
         }
         else if(scene==SPH_MODE_BT_EARPHONE || scene==SPH_MODE_BT_CARKIT)
         {
            AM_BluetoothOn(2);
         }
      }
      l1sp.bt_on = true;
   } 
}
#else
static void setBt(uint32 scene, uint32 preScene)
{
#if defined(__BT_SUPPORT__)   
	   // Turn off the BT related function
	   if( preScene == SPH_MODE_BT_CORDLESS ) {
		  AM_BTCordlessOff();
	   }
	//#if defined(__BT_FM_VIA_SCO__)
	   if( preScene == SPH_MODE_LINEIN_VIA_BT_CORDLESS ){
		  AM_PCM8K_RecordOff( true );
	   }
	//#endif
	
	   if((l1sp.bt_on) && (preScene != scene))
		  {
			 AM_BluetoothOff();
			 l1sp.bt_on = false;
		  }
	
	   if( scene == SPH_MODE_BT_CORDLESS || scene == SPH_MODE_BT_EARPHONE || 
		  scene == SPH_MODE_BT_CARKIT || scene == SPH_MODE_LINEIN_VIA_BT_CORDLESS )
	   {
		  if ((scene==SPH_MODE_BT_CORDLESS || scene==SPH_MODE_LINEIN_VIA_BT_CORDLESS)) 
		  {
			 KT_StopAndWait();
			 TONE_StopAndWait();
			 DTMF_MCU_StopAndWait();
			 if (!l1sp.bt_on)
			 {
				AM_BluetoothOn(1);
			 }	 
		  } else {
			 if (!l1sp.bt_on)
			 {
				AM_BluetoothOn(2);
			 }
		  }
		  
		  l1sp.bt_on = true;
		  
		  if (scene == SPH_MODE_BT_CORDLESS) {
			 AM_BTCordlessOn();
		  }
	//#if defined(__BT_FM_VIA_SCO__)
		  if( scene == SPH_MODE_LINEIN_VIA_BT_CORDLESS ){
			 AM_PCM8K_RecordOn(); //Just for turn on related AFE mic, and set am.state to avoid others application execution
		  }
	//#endif
	   } 
#endif 
}
#endif

static void changeSpeechMode(uint8 prev_sph_mode, uint8 after_sph_mode, 
	uint16 m_paras[NUM_MAX_MODE_PARAS])
{
   kal_trace( TRACE_INFO, L1SP_CHANGE_ENH_MODE, prev_sph_mode, after_sph_mode, l1sp.sph_mode );
	
   if( prev_sph_mode != after_sph_mode ) { // Allow quick adaptation when change mode		
      SetSpeechEnhancement( false );		
   }
   #ifdef __GAIN_TABLE_SUPPORT__
   else{
      kal_uint16 spe_idx = 0;
      for(spe_idx = 0; spe_idx < NUM_MAX_MODE_PARAS; spe_idx++){
         if(m_paras[spe_idx] != l1sp.sph_m_para[spe_idx]){
            SetSpeechEnhancement( false );
            break;
         }
      }
   }
	#endif /* __GAIN_TABLE_SUPPORT__ */
	
   l1sp.sph_mode = after_sph_mode;

   memcpy(l1sp.sph_m_para, m_paras, NUM_MODE_PARAS*sizeof(uint16));
   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );

   SetSpeechEnhancement( true );
}

void L1SP_SetSpeechMode(uint8 mode, uint16 m_para[NUM_MAX_MODE_PARAS])
{
    uint8 prev_sph_mode = l1sp.sph_mode;
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
    kal_uint16 aud_id = L1SP_GetAudID();
#endif   
#if 0 //defined(CHIP_BACK_SPH_PHONE_CALL)
/* under construction !*/
#endif
#if defined(__ENABLE_AUDIO_DVT__)
    {
        extern kal_bool Always_SetBTmode;
        if (Always_SetBTmode)
        {
            mode = SPH_MODE_BT_EARPHONE;
        }
    }
#endif
#ifdef DSDA_VIA_PCM_INTERFACE
    mode = SPH_MODE_BT_EARPHONE;
#endif
    
    setBt(mode, prev_sph_mode);
    changeSpeechMode(l1sp.sph_mode, mode, m_para);   
    
    // Set SRC control
    if (prev_sph_mode != mode)
    {
#if defined(__BT_SUPPORT__) && !defined(__CVSD_CODEC_SUPPORT__)  
        if (AM_IsBTCordlessMode() || AM_IsSpeechOn())
#else
        if (AM_IsSpeechOn())
#endif
		{
            AM_SetSRCCtrl();
		}
	}
    
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
    L1SP_FreeAudID(aud_id);
#endif
    
    return;
}

static void l1sp_getFirMappingByScene(const uint32 scene, 
	uint8 *devMode, uint8 *enhMode,
	uint8 *inFir, uint8 *outFir)
{
	uint8 tempDevMode = 0xff; 
	uint8 tempEnhMode = 0xff;
	uint8 tempInFir = 0xff; 
	uint8 tempOutFir = 0xff;
	
	switch(scene) {
	case SPH_ENH_AND_FIR_SCENE_NORMAL:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
#if defined(__SMART_PHONE_MODEM__)
		tempOutFir = SPH_FIR_COEFF_NORMAL;
#else		
		tempOutFir = l1sp.sph_selectedOutFirIndex; //using enginerning mode's setting for the FIR index
#endif		
		break;
	case SPH_ENH_AND_FIR_SCENE_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_LOUDSPK:
		tempDevMode = scene;
		tempEnhMode = scene;
		tempInFir = scene;
		tempOutFir = scene;
		break;	
#if defined(__BT_SUPPORT__)		
	case SPH_ENH_AND_FIR_SCENE_BT_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_BT_CORDLESS:
	case SPH_ENH_AND_FIR_SCENE_BT_CARKIT:
		tempDevMode = scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;
#endif
	case SPH_ENH_AND_FIR_SCENE_AUX1:
		tempDevMode = SPH_MODE_AUX1; //scene
		tempEnhMode = SPH_MODE_AUX1; //scene
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_AUX2:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS:
		tempDevMode =  SPH_MODE_LINEIN_VIA_BT_CORDLESS;
		tempEnhMode =  SPH_MODE_LINEIN_VIA_BT_CORDLESS;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;

	//VOIP related
	case SPH_ENH_AND_FIR_SCENE_VOIP_NORMAL:
		tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_VOIP_LOADSPK:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
		
	//CTM related
	case SPH_ENH_AND_FIR_SCENE_CTM_BAUDOT:		
	case SPH_ENH_AND_FIR_SCENE_CTM_DIRECT:
		tempDevMode = l1sp.sph_mode; 
		tempEnhMode = l1sp.sph_mode;
		//use default	
		break;

	//CTM HCO
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_NORMAL: // using Eng Mode's selected_FIR_output_index to decide which is 		
	    tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
#if defined(__SMART_PHONE_MODEM__)
		tempOutFir = SPH_FIR_COEFF_NORMAL;
#else		
		tempOutFir = l1sp.sph_selectedOutFirIndex;
#endif
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_EARPHONE:
	    tempDevMode = SPH_MODE_EARPHONE;
		tempEnhMode = SPH_MODE_EARPHONE;
		tempOutFir = SPH_FIR_COEFF_HEADSET;		
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_LOUDSPK:
	    tempDevMode = SPH_MODE_LOUDSPK;
		tempEnhMode = SPH_MODE_LOUDSPK;
		tempOutFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_BT:
	    tempDevMode = SPH_MODE_BT_EARPHONE;
		tempEnhMode = SPH_MODE_BT_EARPHONE;
		tempOutFir = SPH_FIR_COEFF_BT;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_NORMAL:
	    tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_LOUDSPK:
	    tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;

	//CTM VCO
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_NORMAL:
	    tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_EARPHONE:
	    tempDevMode = SPH_MODE_EARPHONE;
		tempEnhMode = SPH_MODE_EARPHONE;
		tempInFir = SPH_FIR_COEFF_HEADSET;	
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_LOUDSPK:
	    tempDevMode = SPH_MODE_LOUDSPK;
		tempEnhMode = SPH_MODE_LOUDSPK;
		tempInFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_BT:
	    tempDevMode = SPH_MODE_BT_EARPHONE;
		tempEnhMode = SPH_MODE_BT_EARPHONE;
		tempInFir = SPH_FIR_COEFF_BT;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_NORMAL:
	    tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK:
	    tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
		
	default:
#if defined(__HD_RECORD__) && (!defined(__SMART_PHONE_MODEM__)) //Only for feature phone use
				if(scene>SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK && l1sp.numOfRecordMode>0){ 				
					tempEnhMode = (scene-SPH_ENH_AND_FIR_SCENE_INCALL_END)-1; 
					tempDevMode = l1sp.recordModeDeviceMapping[tempEnhMode];
					tempInFir = l1sp.recordModeFirMappingCh1[tempEnhMode];
#if defined(__STEREO_RECORD__)
					tempOutFir = l1sp.recordModeFirMappingCh2[tempEnhMode];
#endif
				} else 
		
#endif //defined(__HD_RECORD__) && (!defined(__SMART_PHONE_MODEM__))
		{
			ASSERT(0);
		}

	}
	
	*devMode = tempDevMode;
	*enhMode = tempEnhMode;
	*inFir = tempInFir;
	*outFir = tempOutFir;
	
}

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. 
*/
void L1SP_SetSpeechEnhanceAndFir(uint32 scene, uint32 updatedCoeff)

{
	uint8 modeIndex = 0;
	uint8 inFirIndex = 0;
	uint8 outFirIndex = 0;
	uint8 devModeIndex = 0; 

	bool isNeedSpeMaskUpdate = (bool)(!AM_IsAmInSpeechState());
	//speech mode
//----------------- original scenario ---------------
#ifdef __SMART_PHONE_MODEM__
	if(scene <SPH_MODE_UNDEFINED)
#else //feature phone
	if(scene <SPH_ENH_AND_FIR_SCENE_INCALL_END)
#endif //__SMART_PHONE_MODEM__
	{ //keeping the original scenario

		l1sp_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outFirIndex);

		//speech mode
#ifdef WB_SPE_SUPPORT 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
			if(l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_MODE)//(l1sp.has_all_wb_sph_m_para)
				L1SP_SetWbSpeechPara(l1sp.sph_allWbModePara[modeIndex]);
		}
#endif 		
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0)
			L1SP_SetSpeechMode(devModeIndex, l1sp.sph_allModePara[modeIndex]);

		// Write NB FIR
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0)
			L1SP_Write_Audio_Coefficients_ByFirIndex(inFirIndex, outFirIndex); 
		//L1SP_Write_Audio_Coefficients(l1sp.sph_allInFirCoeff[inFirIndex], l1sp.sph_allOutFirCoeff[outFirIndex]);

#ifdef WB_SPE_SUPPORT 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			if((l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR)
				&& (l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR)) {
				//(l1sp.has_all_wb_sph_in_FIR_coeffs && l1sp.has_all_wb_sph_out_FIR_coeffs) {
				L1SP_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex],
					l1sp.sph_allWbOutFirCoeff[outFirIndex]);
			}
		}
#endif	
	}

//----------------- recording scenario ---------------
#if defined(__SMART_PHONE_MODEM__) || defined(__HD_RECORD__)
	
#if defined(__SMART_PHONE_MODEM__) //smart phone
	else if (scene>=SPH_MODE_UNDEFINED && scene<= (SPH_MODE_UNDEFINED + l1sp.numOfRecordMode))
#elif defined(__HD_RECORD__) //feature phone
	else if (scene>SPH_ENH_AND_FIR_SCENE_INCALL_END && scene < (SPH_ENH_AND_FIR_SCENE_INCALL_END + l1sp.numOfRecordMode))
#endif
	{

		uint16 emDebugInfo = L1Audio_GetDebugInfo(AMR_REC_DEBUG_INFO);

		//only open uplink nr when recording. (AGC should be on)
		/*
		if(isNeedSpeMaskUpdate) {
			l1sp_updateSpeAppMask(0xff, false);
			l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR, true);
		}
		*/

		//get the mode params		
#if defined(__SMART_PHONE_MODEM__)
		modeIndex = scene - SPH_MODE_UNDEFINED;
		devModeIndex = l1sp.recordModeDeviceMapping[modeIndex]; 
		
		outFirIndex = SPH_FIR_COEFF_NORMAL; //useless in this scenario, just keep safe
		if(l1sp.recordModeFirMappingCh1 == NULL) {
			inFirIndex = SPH_FIR_COEFF_NORMAL;
			//FIXME: should add log
		} else {			
			inFirIndex = l1sp.recordModeFirMapping[modeIndex];
#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__) 
			outFirIndex = l1sp.recordModeFirMappingCh2[modeIndex];
#endif

		}
#else //only for feature phone usage
		l1sp_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outFirIndex);
#endif

		//speech enhancment mode & device mode setting
		if(emDebugInfo&0x1) { //when debug info parameter2 bit0 = 1, using normal mode parameter
			modeIndex = SPH_MODE_NORMAL;
			devModeIndex = SPH_MODE_NORMAL;
#ifdef WB_SPE_SUPPORT	
        	if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
				L1SP_SetWbSpeechPara(l1sp.sph_allModePara[modeIndex]); //NB mode paramter!!
        	}
#endif
			if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0) {
				L1SP_SetSpeechMode(devModeIndex, l1sp.sph_allModePara[modeIndex]); //Send mode parameter to DSP. 
			}
			
		} else {			
#ifdef WB_SPE_SUPPORT
			if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){			
				L1SP_SetWbSpeechPara(l1sp.recordModePara[modeIndex]); 
			}
#endif //WB_SPE_SUPPORT
			if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0){			
				L1SP_SetSpeechMode(devModeIndex, l1sp.recordModePara[modeIndex]); //Send mode parameter to DSP. 
			}
		}

		// Write NB FIR
		//for recording, DSP only use WB FIR after full solution is provided, 
		//the parameters just keep safe. by using 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0) {
			if(inFirIndex >= NUM_SPH_INPUT_FIR){
				L1SP_Write_Audio_Coefficients_ByFirIndex(0xff, 0xff);
			} else {
				L1SP_Write_Audio_Coefficients_ByFirIndex(inFirIndex, 0xff);
			}			
		}

		// Write WB FIR
#ifdef WB_SPE_SUPPORT
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			int16 *inFirs;
			int16 *outFirs;
			
			if(inFirIndex == 0xff) {
				inFirs = audio_alloc_mem(NUM_WB_FIR_COEFFS*sizeof(int16));
				memset(inFirs, 0, (NUM_WB_FIR_COEFFS)*sizeof(int16));
				inFirs[0] = 0x7fff;
			} else if (inFirIndex >= NUM_SPH_INPUT_FIR) {
				inFirs = l1sp.recordInFirCoeff[(inFirIndex-NUM_SPH_INPUT_FIR)];
			} else {
				inFirs = l1sp.sph_allWbInFirCoeff[inFirIndex];
			}

			if(outFirIndex == 0xff) {
				outFirs = audio_alloc_mem(NUM_WB_FIR_COEFFS*sizeof(int16));
				memset(outFirs, 0, (NUM_WB_FIR_COEFFS)*sizeof(int16));
				outFirs[0] = 0x7fff;
			} else if (outFirIndex >= NUM_SPH_INPUT_FIR) {
				outFirs = l1sp.recordInFirCoeff[(outFirIndex-NUM_SPH_INPUT_FIR)];
			} else {
				outFirs = l1sp.sph_allWbOutFirCoeff[outFirIndex];
			}

			L1SP_Write_WB_Audio_Coefficients(inFirs, outFirs);

			if(inFirIndex == 0xff) {
				audio_free_mem(inFirs);
			}
			if(outFirIndex == 0xff) {
				audio_free_mem(outFirs);
			}
			
			/*
			if(inFirIndex >= NUM_SPH_INPUT_FIR) {
#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)//set the second mic FIR
				if(outFirIndex!=0xff && outFirIndex>= NUM_SPH_INPUT_FIR){ 
					L1SP_Write_WB_Audio_Coefficients(l1sp.recordInFirCoeff[(inFirIndex-NUM_SPH_INPUT_FIR)],
						l1sp.recordInFirCoeff[(outFirIndex-NUM_SPH_INPUT_FIR)]);
				} else { 
					L1SP_Write_WB_Audio_Coefficients(l1sp.recordInFirCoeff[(inFirIndex-NUM_SPH_INPUT_FIR)],
						l1sp.sph_allWbOutFirCoeff[outFirIndex]); 
				}
#else
				L1SP_Write_WB_Audio_Coefficients(l1sp.recordInFirCoeff[(inFirIndex-NUM_SPH_INPUT_FIR)],
					l1sp.sph_allOutFirCoeff[outFirIndex]); //useless in this scenario, just keep safe
#endif
			} else {		
#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)//set the second mic FIR
				if(outFirIndex!=0xff && outFirIndex>= NUM_SPH_INPUT_FIR){ 
					L1SP_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex],
						l1sp.recordInFirCoeff[(outFirIndex-NUM_SPH_INPUT_FIR)]);
				} else { 
					L1SP_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex],
						l1sp.sph_allWbOutFirCoeff[outFirIndex]); 
				}
#else

				L1SP_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex],
					l1sp.sph_allWbOutFirCoeff[outFirIndex]);
#endif

			}
			*/
		}
#endif //WB_SPE_SUPPORT

	}
#endif //__HD_RECORD__ || __SMART_PHONE_MODEM__
//---------------------- undefined cases --------------------
	else { // undefined cases. 
		kal_trace ( TRACE_INFO, L1SP_USELESS_SET, scene, 0, 0);
	}
	
	kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, isNeedSpeMaskUpdate, l1sp.spe_app_mask);
	
}
/**
	@index: [Input] Identify which LID is going to provide
	@buffer: [Output] Buffer with the contain the result
	@len: [Input] Length of the output buffer
*/
void L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, void *buffer, uint16 len)
{
	switch(index)
	{
#if defined(__AMRWB_LINK_SUPPORT__)
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbInFirCoeff, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbOutFirCoeff, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		ASSERT(len == (NUM_SPH_MODE * NUM_MAX_MODE_PARAS));
		memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MAX_MODE_PARAS);
	}
		break;
#endif	
	default:
		ASSERT(0); 
	}
}

#if defined(__HD_RECORD__)
extern const short HD_RECORD_MODE_FIR_MAPPING_CH1[NUM_RECORD_SPH_MODE];
#if defined(__STEREO_RECORD__)
extern const short HD_RECORD_MODE_FIR_MAPPING_CH2[NUM_RECORD_SPH_MODE];
#endif
extern const char HD_RECORD_MODE_DEVICE_MAPPING[NUM_RECORD_SPH_MODE];
#endif
/**
	MED can put all nvram structure to AUD via this function. Audio/Speech driver will parsing the LID by itself. 
	
	@index: [Input] Identify which LID is used to parsing the buffer
	@buffer: [Input] Buffer with the contain from nvram
	@len: [Input] Length of the input buffer
*/
void L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, uint8* buffer, uint16 len)
{
	switch(index)
	{
	case L1SP_NVRAM_INFO_INDEX_UNDEF:		

		break;
	case L1SP_NVRAM_INFO_INDEX_PARAM:
	{
		int16 bufCur=0;

		//NB input FIR
		kal_mem_cpy(l1sp.sph_allInFirCoeff, (buffer + bufCur), (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS));
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_IN_FIR;
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//NB output FIR
        kal_mem_cpy(l1sp.sph_allOutFirCoeff, (buffer + bufCur) , (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS));
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_OUT_FIR;
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//selected FIR
		kal_mem_cpy(&(l1sp.sph_selectedOutFirIndex), (buffer + bufCur), sizeof(kal_uint16));
		bufCur += sizeof(kal_uint16);
		
		//common
		{
		uint16 *data = (uint16 *)(buffer + bufCur);
		L1SP_LoadCommonSpeechPara(data); //common paramter will copy into l1sp.sph_c_para in this function
		bufCur += sizeof(kal_uint16) * 12; //hardcoding size
		}

		//mode parameter
		kal_mem_cpy(l1sp.sph_allModePara, (buffer + bufCur) , (sizeof(kal_uint16)* NUM_SPH_MODE * 16));
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_MODE;
		bufCur += (sizeof(kal_uint16)* NUM_SPH_MODE * 16);

		kal_mem_cpy(l1sp.sph_allVolumePara, (buffer + bufCur), (sizeof(kal_uint16)*3*7*4));
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM;
		
		/*		
	    	kal_uint16 Media_Playback_Maximum_Swing;
    		kal_int16 Melody_FIR_Coeff_Tbl[25];
	    	kal_int16 audio_compensation_coeff[3][45];
		*/
	}
		break;
		
#if defined(__AMRWB_LINK_SUPPORT__)
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		memcpy(l1sp.sph_allWbInFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		memcpy(l1sp.sph_allWbOutFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<5) bit [5]
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MAX_MODE_PARAS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]
	}
		break;
#endif

#if defined(__HD_RECORD__)
	case L1SP_NVRAM_INFO_INDEX_HD_RECORD:
	{
		int16 bufCur=0, secLen;

		//enhancment mode 
		secLen = NUM_RECORD_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16);
		memcpy(l1sp.recordModePara, (buffer + bufCur), secLen);
		bufCur += secLen;
		l1sp.numOfRecordMode = NUM_RECORD_SPH_MODE;
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_RECORD_MODE; // (1<<6) bit [6]

		//input fir
		secLen = NUM_RECORD_INPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16);
		memcpy(l1sp.recordInFirCoeff, (buffer + bufCur), secLen);
		bufCur += secLen;
		l1sp.numOfRecordInFir= NUM_RECORD_INPUT_FIR;
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_RECORD_IN_FIR; // (1<<7) bit [7]

		l1sp.recordModeFirMappingCh1 = ((uint16 *)HD_RECORD_MODE_FIR_MAPPING_CH1);
#if defined(__STEREO_RECORD__)
		l1sp.recordModeFirMappingCh2 = ((uint16 *)HD_RECORD_MODE_FIR_MAPPING_CH2);
#endif
		l1sp_setRecordModeDeviceMapping((uint8 *)HD_RECORD_MODE_DEVICE_MAPPING, NUM_RECORD_SPH_MODE, NUM_RECORD_SPH_MODE);
	}
		break;
#endif //__HD_RECORD__	

	default:
		ASSERT(0); 
	}
		
}



//=============================================================================

int16 l1sp_getNumOfRecordMode(void)
{
	//default return value is 0 if "__HD_RECORD__" and "smart_phone" is not open. 
	return l1sp.numOfRecordMode;
}

#if defined(__HD_RECORD__)
void l1sp_setRecordModeDeviceMapping(uint8 *mappingTable, int16 length, int16 numOfRecordMode)
{
	ASSERT(numOfRecordMode == l1sp.numOfRecordMode);
	ASSERT(length == l1sp.numOfRecordMode);
	
	l1sp.recordModeDeviceMapping = mappingTable;
}

#endif

//=============================================================================

/**
	(related to customer folder)
	@return: number of enhancement mode sets, include speech used(in-call) and HD record used (when compile optin opened)
*/
kal_int16 L1SP_GetNumOfAllEnhancementMode()
{
	//physical number inside the nvram
	return (8 
#if defined(__HD_RECORD__)
		+ NUM_RECORD_SPH_MODE
#endif 
	);
}

//=============================================================================

/**
	user: maybe META
	(related to customer folder)
	For example, if you want to query wb input fir numbers, please invoke L1SP_GetNumOfAllFir(1,0) to get the result.
	
	@isWideBand: 0 is narrow band (8k), >0 is wide band(16k)
	@isOutputFir: 0 is for input FIR, >0 is for output FIR 
	@return: number of FIR sets. includes speech used(in-call), recording used (when compile option opened)
*/
kal_int16 L1SP_GetNumOfAllFir(kal_uint8 isWideBand, kal_uint8 isOutputFir)
{
	if(isWideBand == 0) { //NB
		if(isOutputFir)
			return NUM_SPH_OUTPUT_FIR;
		else
			return NUM_SPH_INPUT_FIR;
	}else{ //WB
		if(isOutputFir) {
			return NUM_SPH_OUTPUT_FIR;
		} else {
			return (NUM_SPH_INPUT_FIR
#if defined(__HD_RECORD__)
					+ NUM_RECORD_INPUT_FIR
#endif 
			);
		}

	}
}


//=============================================================================

#if defined(__HD_RECORD__)
extern const short HD_RECORD_MODE_CATEGORY[NUM_RECORD_SPH_MODE];
#endif

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "1 * @return" should be equal, because category is a 1D array.
	@categoryResult: [Output] An array indicate which tab(category) the enhancement belongs to. 
	  0 for "in-call", 1 for "voice-record", 2 for "vedio-record". For example: categoryResult[0] = 0, categoryResult[1] = 0 ....	  
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution

*/
int16 L1SP_GetAllEnhancementModeCategory(int16 inputBufLength, int16 *categoryResult)

{
	int16 i;
	int16 result1[8];
	int16 numofEnhMode = L1SP_GetNumOfAllEnhancementMode();
	
	//error handling when buffer size is too small
	if(inputBufLength < (numofEnhMode*1)){
		return -1;
	}
	
	for(i=0; i<8; i++) {
		result1[i] = 0;
	}
		
	memcpy(categoryResult, result1, 8 * sizeof(int16));

#if defined(__HD_RECORD__)
	if(NUM_RECORD_SPH_MODE > 0)
		memcpy(&categoryResult[8], HD_RECORD_MODE_CATEGORY, NUM_RECORD_SPH_MODE*sizeof(kal_int16));
#endif

	return numofEnhMode;
}

//=============================================================================

#define QUOTE(x) #x
#define SPEECH_MODE_NAME_NORMAL QUOTE(Normal Mode)
#define SPEECH_MODE_NAME_EARPHONE QUOTE(Earphone Mode)
#define SPEECH_MODE_NAME_LOUDSPK QUOTE(Loud Speaker Mode)
#define SPEECH_MODE_NAME_BT_EARPHONE QUOTE(BlueTooth Earphone Mode)
#define SPEECH_MODE_NAME_BT_CORDLESS QUOTE(BuleTooth Cordless Mode)
#define SPEECH_MODE_NAME_BT_CARKIT QUOTE(BT Carkit Mode)
#define SPEECH_MODE_NAME_AUX1 QUOTE(AUX1 Mode)
#define SPEECH_MODE_NAME_AUX2 QUOTE(AUX2 Mode)

#if defined(__HD_RECORD__)
extern const char HD_RECORD_MODE_NAMES[NUM_RECORD_SPH_MODE][LEN_OF_ENHANCEMENT_MODE_NAME];
#endif //__HD_RECORD__
/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_MODE_NAME" should be equal. 	
	@nameResult: [Output] An array of names for different enhancement modes
	  (for every record, the max length is LEN_OF_ENHANCEMENT_MODE_NAME, i.e. 30) 
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution
*/
int16 L1SP_GetAllEnhancementModeName(int16 inputBufLength, char *nameResult)

{
	int16 totalModeNum; 
	
	char result[(8
#if defined(__HD_RECORD__)
		+NUM_RECORD_SPH_MODE
#endif //__HD_RECORD__
		)][LEN_OF_ENHANCEMENT_MODE_NAME];

	totalModeNum = L1SP_GetNumOfAllEnhancementMode();
	
	//erro handling when result buffer size is too small
	if(inputBufLength < (totalModeNum*LEN_OF_ENHANCEMENT_MODE_NAME)){
		return -1;
	}

	//normal process
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_NORMAL;
		memcpy(result[0], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_EARPHONE;
		memcpy(result[1], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_LOUDSPK;
		memcpy(result[2], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_EARPHONE;
		memcpy(result[3], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_CORDLESS;
		memcpy(result[4], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_CARKIT;
		memcpy(result[5], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_AUX1;
		memcpy(result[6], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_AUX2;
		memcpy(result[7], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}

#if defined(__HD_RECORD__)
	if(NUM_RECORD_SPH_MODE > 0)
		memcpy(result[8], HD_RECORD_MODE_NAMES, NUM_RECORD_SPH_MODE*LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
#endif

	memcpy(nameResult, result, totalModeNum*LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	
	
	return totalModeNum;
}

//=============================================================================
#ifdef __HD_RECORD__
extern const char HD_RECORD_MODE_CATEGORY_NAME[NUM_RECORD_SPH_MODE_CATEGORY][LEN_OF_ENHANCEMENT_CATEGORY_NAME];
#endif

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_CATEGORY_NAME" should be equal. 	
	@categoryName: [Output] An array indicate each tab's name. For example, 
	                        tab 0 is named "in-call"; tab 1 is named "voice-record"; Tab 2 is named "video-record"
	                        The max length of name is LEN_OF_ENHANCEMENT_CATEGORY_NAME, i.e. 20. 
	@return: number of enhancement categories, when <= 0, it means some error occur when function execution

*/
int16 L1SP_GetAllEnhancementCategoryName(int16 inputBufLength, char *categoryName)
{
	char result[(1
#if defined(__HD_RECORD__)		
		+NUM_RECORD_SPH_MODE_CATEGORY
#endif //__HD_RECORD__
		)][LEN_OF_ENHANCEMENT_CATEGORY_NAME];

	int16 catgNum = L1SP_GetNumOfAllEnhancementCategory();
	
	//error handling when result buffer is too small
	if(inputBufLength < (catgNum*LEN_OF_ENHANCEMENT_CATEGORY_NAME)){
		return -1;
	}
	
	{
		char temp[LEN_OF_ENHANCEMENT_CATEGORY_NAME] = "In-call";
		memcpy(result[0], temp, LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));
	}

#if defined(__HD_RECORD__)
	memcpy(result[1], HD_RECORD_MODE_CATEGORY_NAME, NUM_RECORD_SPH_MODE_CATEGORY*LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));
#endif

	memcpy(categoryName, result, catgNum*LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));	

	return catgNum;
}

//=============================================================================

/**
	user: should be META only
	(realted to customer folder)
	
	@return: number of all enhancement category
*/
int16 L1SP_GetNumOfAllEnhancementCategory(void)
{
	return ( 1 
#if defined(__HD_RECORD__)
		+ NUM_RECORD_SPH_MODE_CATEGORY
#endif  //__HD_RECORD__
		);
}

//=============================================================================

/**
	user: should be META only
	(realted to customer folder)
		
	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * 1" should be equal, because number of param is a 1D array. 	
	@paramNumOfCatg: [Output] An array indicate the number of enhancement mode parameters in each tab's (i.e. category). 
	  For example, category 0 has 32 parameters in each mode; category 1 has 16 parameters in each mode
	@return:  number of enhancement categories, when <= 0, it means some error occur when function execution
	
*/
int16 L1SP_GetNumOfAllEnhancementCategoryParam(int16 inputBufLength, int16 *paramNumOfCatg)
{
	int16 i;
	int16 totalResultNum = L1SP_GetNumOfAllEnhancementCategory();

	//error handling
	if(inputBufLength < (totalResultNum*1)){
		return -1;
	}

	//others
#ifdef __AMRWB_LINK_SUPPORT__
	paramNumOfCatg[0] = NUM_MODE_PARAS*2;
#else //NB only
	paramNumOfCatg[0] = NUM_MODE_PARAS;
#endif //__AMRWB_LINK_SUPPORT__

	for(i=1; i< totalResultNum; i++) {
		paramNumOfCatg[i] = NUM_MODE_PARAS;
	}

	return totalResultNum;
	

}


void L1SP_SetOutputDevice( uint8 device )
{
   l1sp.output_dev = device;
   AFE_SetOutputDevice( L1SP_SPEECH, device );   
}

uint8 L1SP_GetOutputDevice(void)
{
   return l1sp.output_dev;
}

void L1SP_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   l1sp.sph_dl_vol = volume1;
   AFE_SetOutputVolume( L1SP_SPEECH, volume1, digital_gain_index );   
}

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetOutputGainControl( uint32 gain )
{
   //l1sp.sph_dl_vol = volume1;//Need take care here
   AFE_SetOutputGainControl( L1SP_SPEECH, gain );
}
#endif

#if defined(__AUDIO_AT_CMD__)

void L1SP_SetECOn(kal_bool ec_on ){
		
		bool IsSpeechOn=AM_IsAmInSpeechState();
		if(!IsSpeechOn){
			ecnrparam.EC_On=ec_on;
		}
		kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_EC ,IsSpeechOn, ecnrparam.EC_On);
}
void L1SP_SetNROn(kal_bool ul_nr_on,kal_bool dl_nr_on  ){
		
		bool IsSpeechOn=AM_IsAmInSpeechState();
		if(!IsSpeechOn){
			ecnrparam.UL_NR_On=ul_nr_on;
			ecnrparam.DL_NR_On=dl_nr_on;
		}
		kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_NR ,IsSpeechOn, ecnrparam.DL_NR_On, ecnrparam.UL_NR_On);

}


void L1SP_GetECNRStatus(SPE_ECNRPARAM_STRUCT_T *ecnrcfg){

		ecnrcfg->EC_On=ecnrparam.EC_On;
		ecnrcfg->DL_NR_On=ecnrparam.DL_NR_On;
		ecnrcfg->UL_NR_On=ecnrparam.UL_NR_On;
		kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_GetECNR ,ecnrparam.EC_On,ecnrparam.DL_NR_On,ecnrparam.UL_NR_On);
		
}

#endif


void L1SP_SetSpeechVolumeLevel( kal_uint8 level, kal_uint16 v_para[NUM_MAX_VOL_PARAS] )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   if( level<MAX_VOL_LEVEL ) {
      l1sp.sph_level = level;
      memcpy(l1sp.sph_v_para, v_para, NUM_VOL_PARAS*sizeof(uint16));
      kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
      SetSpeechEnhancement( true );
   }
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif   
}

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex)
{
	L1SP_SetSpeechVolumeLevel(level, l1sp.sph_allVolumePara[v_paraIndex][level]);
}


void L1SP_SetInputSource( uint8 src )
{
   AFE_SetInputSource( src );
}

uint8 L1SP_GetInputSource( void )
{
   return AFE_GetInputSource();
}

void sub_SetMicrophoneVolume( uint8 mic_volume )
{
   if( mic_volume == 0 )// special case when mic_volume = 0, mute microphone
      AFE_MuteMicrophone( KAL_TRUE );
   else if( !l1sp.isULMute )
      AFE_MuteMicrophone( KAL_FALSE );

   l1sp.mic_volume = mic_volume;
   AFE_SetMicrophoneVolume( mic_volume );
   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, mic_volume );    
   
   SetSpeechEnhancement( true );
}

void L1SP_SetMicrophoneVolume( uint8 mic_volume )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif
   /* For the sake of integration, 
      In 8k record, driver will decrease 10dB Microphone Volume, and Speech Enhancement in DSP will compensate it. 
      In 16k record, we has no wideband-speech-enhancement, we cannot decrease Mic-Vol when 16k record 
      Please check Media_Record and L1SP_SetMicrophoneVolume
      */   

   if( mic_volume == 0 )// special case when mic_volume = 0, mute microphone
      AFE_MuteMicrophone( KAL_TRUE );
   else if( !l1sp.isULMute )
      AFE_MuteMicrophone( KAL_FALSE );

   kal_trace( TRACE_INFO, L1SP_SET_MIC_VOL, mic_volume, l1sp.sph_m_para[4]);	
   l1sp.mic_volume_fromMED = mic_volume;

   {
      if(mic_volume > 40)
         mic_volume -= 40;//down 10 dB
      else
         mic_volume = 0;
   }
   l1sp.mic_volume_adapted = mic_volume;
   kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_VOL, l1sp.mic_volume_adapted);	

   
   //l1sp.mic_volume = mic_volume;
#ifndef WB_SPE_SUPPORT 
   if(AM_RECORD_16K == AM_GetRecordFormat()){   	
      sub_SetMicrophoneVolume( l1sp.mic_volume_fromMED );   //WB recording doesn't decrease by 10dB      
   }else{  
      sub_SetMicrophoneVolume( l1sp.mic_volume_adapted );   //NB recording decrease by 10dB
   }
#else
	 sub_SetMicrophoneVolume( l1sp.mic_volume_adapted );   //always decrease by 10dB
#endif  
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif
}

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetMicGainControl( uint32 mic_gain )
{
   //kal_trace( TRACE_INFO, L1SP_SET_MIC_VOL, mic_volume, l1sp.sph_m_para[4]);
   kal_uint32 mic_volume = mic_gain >> 26;
   kal_trace( TRACE_INFO, L1SP_SET_MIC_GAIN_CONTROL, mic_gain);
   //if( (l1sp.sph_m_para[4] & 0x2000) )
   {
      if(mic_volume >= 10)
         mic_volume -= 10;//down 10 dB
      else
         mic_volume = 0;
   }
   mic_gain = (mic_gain & 0x03FFFFFF) | (mic_volume << 26);
   //kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_VOL, mic_volume);	
   kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_GAIN_CONTROL, mic_gain);

   AFE_SetMicGainControl( mic_gain );
}
#endif

uint8 L1SP_GetMicrophoneVolume( void )
{
   return l1sp.mic_volume_fromMED;
}

void L1SP_SetSidetoneVolume( uint8 sidetone )
{
   AFE_SetSidetoneVolume( sidetone );
}

uint8 L1SP_GetSidetoneVolume( void )
{
   return AFE_GetSidetoneVolume();
}

void L1SP_MuteMicrophone( bool mute )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   //AFE_MuteMicrophone( mute ); // do not use AFE_MuteMicrophone for speech enhancement
   AM_MuteULSpeech( mute );
   l1sp.isULMute = mute;
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif   
}

void L1SP_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_SPEECH, mute );
}

bool L1SP_IsMicrophoneMuted( void )
{
   bool ret;
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(MTK_SLEEP_ENABLE) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   ret = AM_IsULSpeechMuted();
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(MTK_SLEEP_ENABLE) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif 
   return ret;
}

extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern void vt_SP3G_Callback( kal_uint8 event, void *data );

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
void L1SP_3G_Request(void)
{  
   if(l1sp.state ==  L1SP_STATE_3G_SPEECH_ON)
   {
      CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
      return;
   }
}
#endif

void L1SP_SetState(uint8 state)
{
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   if( ( l1sp.state == L1SP_STATE_3G_SPEECH_ON && state == L1SP_STATE_2G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_2G_SPEECH_ON && state == L1SP_STATE_3G_SPEECH_ON ) )
      l1sp.interRAT = true;
#endif
   l1sp.state = state; 
   L1Audio_Msg_Speech_State(L1Audio_Speech_State(state));
}

uint8 L1SP_GetState( void )
{
   return l1sp.state; 
}

#if _SPE_FOR_TEST_SIM_
//====================================================================
//l1spDspAdaptVol run under hisr
kal_uint16 pre_Sig_Energy;
kal_uint16 frame_index=0;

#define IDLE_NOISE_ADAPT_THRESHOLD 8

static void l1spDspAdaptVol(void *data)
{
   kal_uint8 vol_get;
   kal_int16 vol_get_temp;
   kal_int8 digiGainIdx_get;
   
   kal_uint16 PGA_max;//=(PFA_parameter & 0x003E)>>1;
   kal_uint16 PGA_decay;
   kal_uint16 PGA_parameter;//=L1Audio_GetDebugInfo(1);
   kal_uint16 PGA_stick_flag;//Dr.Nien wants to test digital or audio part genrating noise
   kal_uint16 PGA_threshold;
   kal_uint8 gpre_volume;
   
   PGA_parameter=L1Audio_GetDebugInfo(1);
   PGA_max=(PGA_parameter & 0x003E)>>1;
   PGA_decay=(PGA_parameter & 0x00C0)>>6;
   PGA_stick_flag=(PGA_parameter &0x0100)>>8;
   PGA_threshold=(PGA_parameter &0x0E00)>>9;
   PGA_threshold+=4;
   PGA_threshold=0x1<<PGA_threshold;
   AFE_GetOutputVolume( L1SP_SPEECH, &vol_get, &digiGainIdx_get );
   gpre_volume = vol_get;   
   frame_index++;
   if(frame_index>2000)
      frame_index=200;
   if( l1sp.sph_dl_vol<vol_get ) //protection
      vol_get=l1sp.sph_dl_vol;

   if( PGA_parameter & 0x0001 ){
#if defined(MT6253) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
      if( AM_IsKeyToneOn() || AM_IsToneOn()
#ifdef BGSND_ENABLE
          || AM_IsBgsndOn()
#endif
      ){
         //kal_prompt_trace(MOD_L1SP,"restore gain");
         AFE_SetOutputVolume( L1SP_SPEECH, l1sp.sph_dl_vol, 0 );
      }else
#endif
      if(((PGA_stick_flag==0)&& (pre_Sig_Energy<16) && (*DP2_ADAPT_VOL < IDLE_NOISE_ADAPT_THRESHOLD))||((PGA_stick_flag==1)&&(frame_index%200>=100))){ 
         if ( (l1sp.sph_dl_vol-vol_get) >= PGA_max*16 )  // avoid special case vol = 0 will mute
            vol_get_temp = l1sp.sph_dl_vol-PGA_max*16;
         else
            vol_get_temp = vol_get - (PGA_decay+1)*16;
         if(vol_get_temp<1)
            vol_get_temp=1;
         vol_get=(kal_uint8)vol_get_temp;
         kal_dev_trace( TRACE_INFO, L1SP_DEC_SPK_VOL, vol_get, *DP2_ADAPT_VOL );
		 //if(vol_get!=gpre_volume)
			 AFE_SetOutputVolume( L1SP_SPEECH, vol_get, 0 );
      }
      else if(((PGA_stick_flag==0)&&(*DP2_ADAPT_VOL > PGA_threshold)) || ((PGA_stick_flag==1)&&(frame_index%200<100))){
         kal_dev_trace( TRACE_INFO, L1SP_INC_SPK_VOL, vol_get, *DP2_ADAPT_VOL );
         //if(l1sp.sph_dl_vol!=gpre_volume)
	         AFE_SetOutputVolume( L1SP_SPEECH, l1sp.sph_dl_vol, 0 );
      }
   }
   pre_Sig_Energy=*DP2_ADAPT_VOL;
}
#endif

kal_bool L1SP_IsSpeechOn( void )
{
    return (AM_IsSpeechOn());
}

void L1SP_Speech_On( uint8 RAT_Mode )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   kal_uint32 voc_pattern = TVCI_CREATE_FILE;
   kal_uint32 *voc_ptr = &voc_pattern;

   if( AM_IsSpeechOn() )
      return;

#if defined(__CVSD_CODEC_SUPPORT__) 
    {
        kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
        if (uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT)
        {
            BT_SCO_Disable_All_APP();
        }
    }
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   Media_SpkVibration_Enable(KAL_FALSE);
#endif
   PcmSink_TerminateSound();

#if _SPE_FOR_TEST_SIM_
#ifdef __GEMINI__
   if( is_test_sim( SIM1 ) || is_test_sim( SIM2 ))
#else 
   if( is_test_sim() )
#endif 
   {
      if( ( L1Audio_GetDebugInfo(1) & 0x1000 ) == 0 ){//use test SIM parameter
         extern void L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info );
         L1Audio_SetDebugInfoN(1, 2569);
         l1sp.sph_m_para[8] = (l1sp.sph_m_para[8] & 0xCFFF) | (m_para_for_test_sim[8] & 0x3000);
         l1sp.sph_m_para[9] = (l1sp.sph_m_para[9] & 0xEFFF) | (m_para_for_test_sim[9] & 0x1000);
      }
   }
#endif //#if _SPE_FOR_TEST_SIM_
   
   TONE_StopAndWait();
   KT_StopAndWait();
   DTMF_MCU_StopAndWait(); 
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   l1sp_updateSpeAppMask(0xff, true);

   AFE_SetDigitalGain(L1SP_SPEECH, 100);


   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */
#if defined(CHIP_BACK_SPH_PHONE_CALL)
    // no dynamic download for chip back speech phone call
#else
#if defined(AEC_ENABLE)
   DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif
#endif

   SPE_SetSBSD( false ); //When true, SpeechDSP will do ErroreConceilment for speech frame quality.But Modem have SAIC which focus on the same purpose, drivers always turns off this function.

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      //In Dual mode, allow 2G/3G capability at initialization stage  for InterRAT HO
      //if 3G324M, there is no InterRAT
      sp3g_speech_init( RAT_3G_MODE );

   if( SP3G_Rab_State() && RAT_Mode != RAT_3G324M_MODE ){
      RAT_Mode = RAT_3G_MODE;
   }else if ( l1sp.tch_state )
      RAT_Mode = RAT_2G_MODE;
   l1sp.interRAT = false;
#endif

#if _SPE_FOR_TEST_SIM_
   L1Audio_HookHisrHandler( DP_D2C_ADAPT_VOL, l1spDspAdaptVol, 0 );
#endif

   AM_SpeechOn(RAT_Mode);
      
   SetSpeechEnhancement( true );

   switch(RAT_Mode)
   {
      case RAT_2G_MODE:
         L1SP_SetState(L1SP_STATE_2G_SPEECH_ON);     
         break;
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
      case RAT_3G_MODE: 
         L1SP_SetState(L1SP_STATE_3G_SPEECH_ON);
         CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
         break;
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
      default: 
         ASSERT(false);
   }
   if(l1sp.onHandler != NULL)
      l1sp.onHandler( (void *)l1sp.state );

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOnHandler != NULL)
      l1sp.pcm4wayOnHandler( (void *)0);
#endif

#ifndef __L1_STANDALONE__ // avoid link error
#if defined(__VM_CODEC_SUPPORT__)
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VOC, &module_id, 0x2))
   {
      l1sp.isVocOn = true;
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptr, 4);
      vmRecord(NULL, 0, true); // type is to match MEDIA_FORMAT_GSM_FR
   }
   else
   {
      l1sp.isVocOn = false;
   }
#endif
#endif

#if defined(__CVSD_CODEC_SUPPORT__)
    {
        kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
        if (   (uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT)
            && l1sp.cordless_path == SPH_CORDLESS_PATH_BT)
        {
            BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BOTH);
        }
    }
#endif

}


void L1SP_Afe_On( kal_uint32 afe_mode )
{
   if( AM_IsAfeOn() )
      return;   
   TONE_StopAndWait();
   KT_StopAndWait();
   PcmSink_TerminateSound();
   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */
            
   AM_AfeOn(afe_mode);   
}

void L1SP_Afe_Off( void )
{
   if( !AM_IsAfeOn() )
      return;   
   AM_AfeOff();  
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );       
}

void L1SP_Register_Service(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.onHandler = onHandler;   
   l1sp.offHandler = offHandler;
}

void L1SP_UnRegister_Service( void )
{
   l1sp.onHandler = NULL;   
   l1sp.offHandler = NULL;
}

#if defined(__ECALL_SUPPORT__)
void L1SP_Register_Pcm4WayService(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.pcm4wayOnHandler = onHandler; 
   l1sp.pcm4wayOffHandler = offHandler;
}

void L1SP_UnRegister_Pcm4Way_Service( void )
{
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
}
#endif

void L1SP_Speech_Off( void )
{
   kal_uint32 uCurrentSpMode;

#ifndef __L1_STANDALONE__ // avoid link error
#if defined(__VM_CODEC_SUPPORT__)
	if(l1sp.isVocOn)
   {
      kal_uint32 voc_pattern = TVCI_CLOSE_FILE;
      kal_uint32 *voc_ptr = &voc_pattern;
      
      vmStop(NULL);
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptr, 4);
      l1sp.isVocOn = false;
   }
#endif
#endif

   if( !AM_IsSpeechOn() )
      return;

#if defined(__CVSD_CODEC_SUPPORT__) 
   uCurrentSpMode = L1SP_GetSpeechMode();
   if( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT )
   {
      BT_SCO_Disable_All_APP();
   }
#endif

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOffHandler != NULL)
      l1sp.pcm4wayOffHandler( (void *)0 );
#endif

   if(l1sp.offHandler != NULL)
      l1sp.offHandler( (void *)l1sp.state );
   SetSpeechEnhancement( false );

   AM_SpeechOff();

#if _SPE_FOR_TEST_SIM_
   L1Audio_UnhookHisrHandler( DP_D2C_ADAPT_VOL );
#endif

#if defined( __UMTS_RAT__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
   L1SP_SetState( L1SP_STATE_IDLE );

   SPE_SetSBSD( false );

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif
   
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );
}

void L1SP_Set_DAI_Mode( uint8 mode )
{
	//this feature is phased out
  //AM_SetDAIMode( mode );
}

void L1SP_SetAfeLoopback( bool enable )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
   if( enable )
      AFE_TurnOnLoopback();
   else
      AFE_TurnOffLoopback();
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif      
}
/*for MIC2 loopback*/
void L1SP_SetAfeLoopback2( bool enable )
{
   if( enable ){
      #if defined(MT6256)
      l1sp_updateSpeAppMask(SPH_ENH_MASK_AGC, false);
      SetSpeechEnhancement(KAL_TRUE);
      AFE_TurnOnLoopback2();
      #else
      AFE_TurnOnLoopback();
      #endif
   }
   else{
      AFE_TurnOffLoopback();
   }
}


void L1SP_PCMIFLoopbackEn( kal_bool enable)
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif  
#if defined(MT6261) || defined(MT2501) || defined(MT2502)    
   AFE_PCMIFLoopbackEn(enable);
#endif
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif      
}


kal_bool L1SP_GetAfeLoopbackStatus( void )
{
   return AFE_GetLoopbackStatus();
}

void L1SP_SetFIR( bool enable )
{
   if( enable ){
      AFE_TurnOnFIR( L1SP_SPEECH );
      AFE_TurnOnFIR( L1SP_VOICE );
   }else{
      AFE_TurnOffFIR( L1SP_SPEECH );
      AFE_TurnOffFIR( L1SP_VOICE );
   }
}

void L1SP_Write_Audio_Coefficients( const int16 in_coeff[45], const int16 out_coeff[45] )
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   AM_WriteFirCoeffs( in_coeff, out_coeff );
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif   
}


void L1SP_Write_Audio_Coefficients_ByFirIndex( const uint8 inFirIndex, 
	const uint8 outOrIn2FirIndex)
{

	int16 *inCoeff; //[NUM_FIR_COEFFS];
	int16 *outOrIn2Coeff; //[NUM_FIR_COEFFS];

	inCoeff = audio_alloc_mem(NUM_FIR_COEFFS*sizeof(int16));
	outOrIn2Coeff = audio_alloc_mem(NUM_FIR_COEFFS*sizeof(int16));
		
	if(inFirIndex == 0xff) {
		inCoeff[0] = 0x7fff;
		memset(&inCoeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(inCoeff, l1sp.sph_allInFirCoeff[inFirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	if(outOrIn2FirIndex == 0xff) {
		outOrIn2Coeff[0] = 0x7fff;
		memset(&outOrIn2Coeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(outOrIn2Coeff, l1sp.sph_allOutFirCoeff[outOrIn2FirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	L1SP_Write_Audio_Coefficients( inCoeff, outOrIn2Coeff );

	audio_free_mem((void **)(&inCoeff));
	audio_free_mem((void **)(&outOrIn2Coeff));
	
}

void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      l1sp.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      l1sp.spe_flag = false;
   }      
}

void L1SP_LoadSpeechPara( void ) 
{
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para);   
#if (defined(__CENTRALIZED_SLEEP_MANAGER__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)))
   L1SP_FreeAudID(aud_id);
#endif      
}

void L1SP_Init( void )
{
	//kal_prompt_trace(MOD_L1SP,"L1SP_INIT_ecnr");

#if defined(__AUDIO_AT_CMD__)
	//kal_prompt_trace(MOD_L1SP,"L1SP_INIT_ecnr2");
    ecnrparam.EC_On = KAL_TRUE;
	ecnrparam.UL_NR_On = KAL_TRUE;
	ecnrparam.DL_NR_On = KAL_TRUE;
	//ecnrparam.IsSpeechOn=false;
#endif

#if defined(CHIP_BACK_SPH_PHONE_CALL)
    // default set to normal mode for chip back phone call scenario
   l1sp.sph_mode = SPH_MODE_NORMAL;
#else
   l1sp.sph_mode = SPH_MODE_UNDEFINED;
#endif
#ifndef __L1_STANDALONE__
   custom_cfg_audio_ec_range( &l1sp.min_ec_level, &l1sp.max_ec_level );
#else
   l1sp.min_ec_level = 1;
   l1sp.max_ec_level = 6;
#endif
   memset(&l1sp.sph_c_para, 0, NUM_COMMON_PARAS*sizeof(uint16));
   memset(&l1sp.sph_m_para, 0, NUM_MODE_PARAS*sizeof(uint16));
   memset(&l1sp.sph_v_para, 0, NUM_VOL_PARAS*sizeof(uint16));
   
#if defined(__DUAL_MIC_SUPPORT__)
   memset(&l1sp.sph_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));
#ifdef __AMRWB_LINK_SUPPORT__   
   memset(&l1sp.sph_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
#endif
#endif 

   l1sp.mic_volume = AFE_GetMicrophoneVolume(); // get initial value

#if defined(__BT_SUPPORT__)   
   l1sp.bt_on = false;
#endif

#if defined( __UMTS_RAT__ )
/* under construction !*/
/* under construction !*/
#endif

   SPE_Init();
   l1sp.spe_flag = true;
   l1sp.isULMute = false;
   l1sp.spe_state = 0;
   
   //default set the DMNR on
   l1sp.spe_app_mask = 0xffff;
   l1sp.spe_usr_mask = 0xffff;
   
   l1sp.sph_dl_vol = 128;
   l1sp.pcmplayback_flag = KAL_FALSE;
   l1sp.speech_dmnr_loopback = KAL_FALSE; 
   
   l1sp.onHandler = NULL;
   l1sp.offHandler = NULL;
#if defined(__ECALL_SUPPORT__)
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
#endif
   l1sp.output_dev = 0;
   L1SP_SetState(L1SP_STATE_IDLE);


   l1sp.setNvramValuesFlag = 0;
   memset(l1sp.sph_allModePara, 0, NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(l1sp.sph_allInFirCoeff, 0, NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allOutFirCoeff, 0, NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allVolumePara, 0, 3*7*4*sizeof(uint16));
   
   l1sp.sph_selectedOutFirIndex = 0;
#if defined(__HD_RECORD__)
   memset(l1sp.recordModePara, 0, NUM_RECORD_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(l1sp.recordInFirCoeff, 0, NUM_RECORD_INPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16));
   l1sp.recordModeFirMappingCh1 = NULL;
#if defined(__STEREO_RECORD__)   
   l1sp.recordModeFirMappingCh2 = NULL;
#endif //__STEREO_RECORD__
   l1sp.recordModeDeviceMapping = NULL;
#endif //__HD_RECORD__
   l1sp.numOfRecordMode = 0;
   l1sp.numOfRecordInFir = 0;
      
#if defined(__CVSD_CODEC_SUPPORT__) 
   l1sp.cordless_path = SPH_CORDLESS_PATH_BT;
#endif
}
kal_bool L1SP_TCH_State( void )
{
   return l1sp.tch_state;
}

// run under l1 LISR context
void L1SP_TCH_Notify( bool bOn )
{
#if defined( __UMTS_RAT__ )
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
}

void L1SP_SpeechLoopBackEnable(kal_bool fgEnable)
{
#if defined(MT6235) || defined(MT6235B) || defined(MT6236) || defined(MT6536B) || defined(MT6268) || defined(MT6253) || defined(MT6256) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)

    #define LOOP_BACK_ON    (kal_uint16)(0x1 << 6)
    
    if (fgEnable)
    {
        *DSP_SPEECH_DEBUG_MODE = *DSP_SPEECH_DEBUG_MODE | LOOP_BACK_ON;
    }
    else
    {
        *DSP_SPEECH_DEBUG_MODE = *DSP_SPEECH_DEBUG_MODE & ~LOOP_BACK_ON;
    }

    //kal_prompt_trace(MOD_L1SP,"DSP_SPEECH_DEBUG_MODE[%08x]    = (%04x) \r\n", DSP_SPEECH_DEBUG_MODE, *DSP_SPEECH_DEBUG_MODE);
#else
    (void)fgEnable;
#endif    
}

void L1SP_SetCordLessPath( kal_uint8 uPath )
{
#if defined(__CVSD_CODEC_SUPPORT__) 
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SET_CORDLESS_PATH, l1sp.cordless_path, uPath);
   ASSERT(uPath < SPH_CORDLESS_PATH_UNDEFINED);
   l1sp.cordless_path = uPath;
#endif
}

void LINEIN_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_LINEIN, device );
}

void LINEIN_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   AFE_SetOutputVolume( L1SP_LINEIN, volume1, digital_gain_index );
}

void LINEIN_Open()
{
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();
   if (!lineon_flag){
      ktLock();
      AFE_TurnOnSpeaker(L1SP_LINEIN);
      lineon_flag = KAL_TRUE;
   }
}

void LINEIN_Close()
{
   if(lineon_flag){
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
      AFE_SetGainFastRamp(KAL_TRUE);    
#endif

      AFE_TurnOffSpeaker(L1SP_LINEIN);

#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
      kal_sleep_task(3);
      AFE_SetGainFastRamp(KAL_FALSE);    
#endif

      ktUnlock();
      lineon_flag = KAL_FALSE;
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif
}

void LINEIN_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_LINEIN, mute );
}

#if defined(__GAIN_TABLE_SUPPORT__)
void LINEIN_SetOutputGainControl( kal_uint32 gain ){
   AFE_SetOutputGainControl( L1SP_LINEIN, gain );
}

void LINEIN_SetOutputGainControlDualPath( kal_uint32 ext_amp_gain ){
   AFE_SetOutputGainControlDualPath( L1SP_LINEIN, ext_amp_gain );
}
#endif

#if defined(__DUAL_MIC_SUPPORT__)
#include "pcm4way.h"

#define FRAME_BUF_NO (32)
#define NB_FRAME_SIZE   (160)
static uint16 PCM_UL_BUF[FRAME_BUF_NO][NB_FRAME_SIZE];
static uint16 PCM_DL_BUF[FRAME_BUF_NO][NB_FRAME_SIZE];
static uint32 DELAY = 12;
static uint32 UL_tmp_w, UL_tmp_r;
static uint32 DL_tmp_w, DL_tmp_r;

void AcousticLoopback_PCM4WAY_HisrHdl()
{
   {
      if( (UL_tmp_w - UL_tmp_r) < FRAME_BUF_NO ){        
         PCM4WAY_GetFromMic((uint16*)PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)]);
         kal_brief_trace(TRACE_INFO, L1SP_DMNR_LOOPBACK_FROM_MIC, 
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][0],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][1],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][2],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][3]);         
         UL_tmp_w++;            
      }else{
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_SKIP_MIC); 
      }

      if( (UL_tmp_w - UL_tmp_r) >= DELAY ){
         PCM4WAY_PutToSE(PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)]);   
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_TO_SE, 
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][0],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][1],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][2],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][3]);               
         UL_tmp_r++;
      }else{
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FILL_SE); 
         PCM4WAY_FillSE(0);
      }
   }

   {
      if( (DL_tmp_w - DL_tmp_r) < FRAME_BUF_NO ){        
         PCM4WAY_GetFromSD((uint16*)PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)]);
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FROM_SD, 
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][0],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][1],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][2],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][3]);
         DL_tmp_w++;            
      }else{
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_SKIP_SD); 
      }

      if( (DL_tmp_w - DL_tmp_r) >= DELAY ){
         PCM4WAY_PutToSpk(PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)]);  
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_TO_SPK, 
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][0],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][1],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][2],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][3]);         
         DL_tmp_r++;          
      }else{
         kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FILL_SPK); 
         PCM4WAY_FillSpk(0);
      }
   }
   kal_brief_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_UL_DL_INDEX, UL_tmp_w, UL_tmp_r, DL_tmp_w, DL_tmp_r);
}

void ABF_SetAcousticLoopback( kal_bool loopback )
{
   if(loopback){
      if(ABF_GetAcousticLoopbackStatus()){
         kal_brief_trace( TRACE_INFO,  L1SP_DMNR_LOOPBACK_ILLEGAL_OPEN);
         return;
      }
   	
      UL_tmp_w = UL_tmp_r = DL_tmp_w = DL_tmp_r = 0;
      {
         int32 I;
         for( I = 0; FRAME_BUF_NO > I; I++ ){
            memset(PCM_UL_BUF, 0, sizeof(uint16)*NB_FRAME_SIZE);
            memset(PCM_DL_BUF, 0, sizeof(uint16)*NB_FRAME_SIZE);
         }         
      }
      //L1SP_EnableDLSpeechEnhancement(false);  
      L1SP_Speech_On(RAT_2G_MODE);
      L1SP_SpeechLoopBackEnable(KAL_TRUE);
      PCM4WAY_Start(AcousticLoopback_PCM4WAY_HisrHdl, 0);
      l1sp.speech_dmnr_loopback = KAL_TRUE;
   } else {
      if(!ABF_GetAcousticLoopbackStatus()){
         kal_brief_trace( TRACE_INFO,  L1SP_DMNR_LOOPBACK_ILLEGAL_CLOSE);
         return;
      }

      PCM4WAY_Stop(0);
      L1SP_SpeechLoopBackEnable(KAL_FALSE);
     
      L1SP_Speech_Off();
      //L1SP_EnableDLSpeechEnhancement(true);      
      l1sp.speech_dmnr_loopback = KAL_FALSE;
   }
}
kal_bool ABF_GetAcousticLoopbackStatus( void )
{
   return l1sp.speech_dmnr_loopback;
}
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define MIC_MAX_VALUE_FOR_INTENSITY 5000
#else   // chip compile option
#define MIC_MAX_VALUE_FOR_INTENSITY 12000
#endif  // chip compile option
#define MIC_MIN_VALUE_FOR_INTENSITY 0

void L1SP_GetIntensityExtremeValues(kal_uint32 *p_intensity_max_value, kal_uint32 *p_intensity_min_value)
{
    *p_intensity_max_value = MIC_MAX_VALUE_FOR_INTENSITY;
    *p_intensity_min_value = MIC_MIN_VALUE_FOR_INTENSITY;
    
    return;
}

#ifndef BOUNDED
#define BOUNDED(in,up,lo) ((in) > (up) ? (up) : (in) < (lo) ? (lo) : (in))
#endif

kal_uint32 L1SP_GetFrameIntensity(kal_uint32 channel)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {
        kal_uint16 record_intensity = *DSP_PCM_FRM_PEAK_UL;
        record_intensity = BOUNDED(record_intensity, MIC_MAX_VALUE_FOR_INTENSITY, MIC_MIN_VALUE_FOR_INTENSITY);
        return record_intensity;
    }
#else   // chip compile option
#if defined(WAV_CODEC)   
    {   //Now, we only use the FIRST_MIC, which is defined into 0
        kal_uint32 record_intensity = pcmGetFrameIntensity();
        record_intensity = BOUNDED(record_intensity, MIC_MAX_VALUE_FOR_INTENSITY, MIC_MIN_VALUE_FOR_INTENSITY);
        return record_intensity;
    }
#else
   return 0;
#endif   
#endif  // chip compile option
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackOn (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )      
   AcousticLoopbackOn();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackOff (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )         
   AcousticLoopbackOff();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackSpeechMode(kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackSpeechMode(u1Mode);
#endif       
}

/* Just for Factory Usage */
kal_bool L1SP_AcousticLoopbackStatus(void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   return AcousticLoopbackStatus();
#else
    return KAL_FALSE;
#endif       
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackBypassMode(kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackBypassMode(u1Mode);
#endif    
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackLength (kal_uint32 u4Length)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackLength(u4Length);
#endif   
}

void L1SP_MutePCMOuputPort ( kal_bool fMute )
{
#if defined(MT6252)
   #define PCM_MUTE    (kal_uint16)(0x1 << 15)
	kal_brief_trace( TRACE_INFO, L1SP_Mute_PCM_Ouput_Port, fMute );
   if(fMute)
   {
      *DSP_AUDIO_CTRL2 = *DSP_AUDIO_CTRL2 | PCM_MUTE;
   }
   else
   {
      *DSP_AUDIO_CTRL2 = *DSP_AUDIO_CTRL2 & ~PCM_MUTE;
   }
#endif
}


#if defined( __VOICE_CHANGER_SUPPORT__ )
extern kal_bool SPE_GetCustomProcessState(void);

kal_bool L1SP_SetVoiceChangerMode(SPH_VOICE_CHANGER_MODE mode)
{
    kal_bool process_on = SPE_GetCustomProcessState();
    kal_trace( TRACE_GROUP_AUD_SPE_CSUT, SPEECH_VCH_SET_MODE, l1sp.vchg_mode, mode, process_on,AM_IsSpeechOn());  
    if( mode== SPH_VC_NORMAL && process_on)
    {
    	 l1sp.vchg_mode = mode;
    	 SPE_CustomProcess(KAL_FALSE,0,0,0);
    	 
    }
    else if(process_on && (l1sp.vchg_mode!=mode))
    {
    	 SPE_CustomProcess(KAL_FALSE,0,0,0);
    	 l1sp.vchg_mode = mode;
    	 SPE_CustomProcess(KAL_TRUE,0,0,0);	
    }
    else if(AM_IsSpeechOn() && !process_on)
    {
    	 l1sp.vchg_mode = mode;	
    	 SPE_CustomProcess(KAL_TRUE,0,0,0);    	 
    }
    else
    {
    	 l1sp.vchg_mode = mode;	
    }	
    return KAL_TRUE;
}

SPH_VOICE_CHANGER_MODE L1SP_GetVoiceChangerMode(void)
{
    return l1sp.vchg_mode;
}
#endif
