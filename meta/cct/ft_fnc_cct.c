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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_cct.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camera calibtration related fuctions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
  //#include "kal_release.h" // danbo mark for build error

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "stack_init.h"
#include "stack_ltlcom.h"
#include "reg_base.h"
#endif
#include "ft_bt_customize.h"
//#ifdef __MTK_TARGET__
//#include <stdio.h>
//#include "app_buff_alloc.h"
//#include "l1_public.h" //<--chliu: for use if L1I_SetAFcData
//#endif /* __MTK_TARGET__ */
#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
//#include "l1_kal.h"
//#include "ft_msg.h"
//#include "ft_msg_common.h"
#endif
#include "ft_msg_common.h"

#if (!defined(__MODEM_COMPONENT__)&&!defined(__MODEM_PRODUCT__))
#include "ft_fnc_cct.h"
#endif

#include "ft_cct_customize.h"
#include "mph_types.h"
#include "fctycomp_config.h"
//#include "nvram.h"
#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "camera_nvram_def.h" 
#include "nvram_user_defs.h"
#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
//#include "l1audio.h"
#include "batparm.h"
#endif
//#include "ft_private.h"
//#include "m12190.h"
 
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
#endif

//#include "l1cal.h"
#include "fat_fs.h"
#include "custom_em.h"
#include "custom_equipment.h"
#include "init.h"

#include "meta_customize.h"
#ifndef MED_NOT_PRESENT
#include "aud_defs.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_utility.h"
#include "med_global.h"
#endif // MED_NOT_PRESENT

#include "gv.h"
#include "tst_def.h"
#include "Usbacm_ft.h"  // danbo add for fix warning  110401
// USB
#define FT_CCT_USB_SYNC_PATTERN			"US"
#define FT_CCT_USB_SYNC_PATTERN_LEN		2
#define FT_CCT_USB_SEND_PATTERN			"SEND"
#define FT_CCT_USB_SEND_PATTERN_LEN		4

#define CAMERA_SUB_SAMPLE_1_1		0x0
#define CAMERA_SUB_SAMPLE_1_2		0x1
#define CAMERA_SUB_SAMPLE_1_4		0x2
#define CAMERA_SUB_SAMPLE_1_8		0x4
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
kal_uint8	ch=0xFF;
kal_char usb_sync_pattern[FT_CCT_USB_SYNC_PATTERN_LEN] = FT_CCT_USB_SYNC_PATTERN;
kal_char usb_send_pattern[FT_CCT_USB_SEND_PATTERN_LEN] = FT_CCT_USB_SEND_PATTERN;
#pragma arm section zidata, rwdata

#ifdef __TH_DEBUG__
//extern void tst_sys_trace(kal_uint8*);
#endif

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
//#include "sccb.h"
#include "image_sensor.h" // <-- you must include this after isp_if.h
#include "lcd_sw_inc.h"
//#include "lcd_if.h"
#include "drv_comm.h"
//#include "visualhisr.h"
//#include "jpeg.h"
#include "med_api.h"
#include "cam_main.h"
//#include "camera_para_v2.h"
extern void L1D_ENABLE_CTIRQ_TimingCheck( kal_bool enabled );
#endif

//#if defined(DRV_IDP_OLD_DESIGN)
//#include "imgdma.h"
//#endif
//#include "aaa_ae_para_v2.h" // for new AeCCT // HAL remove
#if defined(DRV_FEATURE__MM_INTMEM_IF)
#include "mm_intmem.h"
#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)

// for Camera HAL UT
#include "cal_api.h"
#include "cct_comm_def.h"
#include "image_sensor.h"
#include "usb_drv.h"
#include "Lens_comm_def.h" //danbo add for hal af
#include "string.h"
#include "lcd_if.h"
#include "isp_comm_if.h"

//#include "sensor_comm_def.h"
// for Camera HAL UT
//#include "drv_sw_features_display.h"
#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
#include "drv_features_display.h"
#if defined(DRV_DISPLAY_DRIVER_V1)
#include "lcd_if.h"
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
#if defined(DRV_DISPLAY_DRIVER_V2)
#include "lcd_sw_inc.h"
#include "wfc.h"
//#include "gdi_include.h" // TODO: [m] Check include path
//#include "mdi_include.h" // TODO: [m] Check include path
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
#endif
//----------[TH] for 6238r-----------------------------------------
#define JPEG_ENCODE_BUFFER_FULL        0x81 // which was defined in jpeg.h
//-----------------------------------------------------------------------
/*------------------ for build warning ---------------------------*/
#ifndef MED_NOT_PRESENT

extern void aud_mic_mute(kal_bool mute); //HAL remove

//#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217)) // HAL remove
//extern void L1SP_UpdateSpeechPara( kal_uint16 sph_m_para[NUM_MODE_PARAS] );  //NUM_MODE_PARAS = 8
//extern void SPE_LoadSpeechPara( kal_uint16 c_para[NUM_COMMON_PARAS], kal_uint16 m_para[NUM_MODE_PARAS] );  //NUM_COMMON_PARAS = 12, NUM_MODE_PARAS = 8
//#endif
#endif
// for Camera HAL UT
CAL_FEATURE_CTRL_STRUCT CctFeatureCtrl;
// for Camera HAL UT
#define FT_FAT_MAX_PEER_SIZE		2048
#define FT_FAT_MAX_FRAME_SIZE		FT_FAT_MAX_PEER_SIZE/64*56

/*******************************************************************************
*
*  CCT functionality
*
*******************************************************************************/

//#include "jpeg_capture_wrapper.h"

//#include "isp_mshutter_v2.h"

extern kal_uint8	ch;
extern kal_uint32	g_camera_lid[];
extern kal_uint32  g_camera_lid_count;
#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
extern camera_para_struct_copy g_camera_para_table[];
#endif
extern kal_uint32  g_camera_para_table_size;

kal_uint32		g_main_sensor_id = NULL;
kal_uint32		g_sub_sensor_id = NULL;
#if defined(DRV_FEATURE__MM_INTMEM_IF)
kal_uint8 g_memory_pool_on = KAL_FALSE;
#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
extern flashlight_cdt_capture_struct isp_cdt_data;
#define FT_CCT_DISPLAY_BUFFER_SIZE 2 //080704 add for IDP after W08.27
#define FT_CCT_DISPLAY_BUFFER_DUMMY_SIZE (0) //080704 add for IDP after W08.27
kal_uint32 ulFtCctDisplaybifferAddress = 0xffffffff; //080704
kal_uint32 ulFtCctDisplaybifferSize = 0; //080704
kal_uint32 g_GChannelMean = 0;
kal_bool g_b_COQC_MShutter = KAL_FALSE;
kal_bool g_b_image_transfer = KAL_TRUE;
kal_bool g_b_multishot = KAL_FALSE;
kal_uint8 g_cameraType = CAL_CAMERA_SOURCE_MAIN/*CAM_MAIN_CAMERA*/; //HAL
kal_uint8 g_b_set_camera_type_result = FT_CNF_FAIL;
extern void update_nvram_global_to_cct_global(void);
extern void update_cct_global_to_nvram_global(void);
extern kal_uint32 get_lens_prefix_name(kal_char* buf, kal_uint32 buf_size);
extern kal_uint8 Auto_Defect_on_off(kal_bool flag);
kal_int32 ft_cct_isp_hisr_capture_jpeg_result_V2(JPEG_CODEC_STATE_ENUM cause);

 P_CAL_FEATURE_CTRL_STRUCT pCalCCTFeatureParaIn;
 P_CAL_FEATURE_CTRL_STRUCT pCalCCTFeatureParaOut;
 
 CAL_SCENARIO_CTRL_STRUCT CCTCalPreviewScenarioPara;
 CAL_CAMERA_PREVIEW_STRUCT CCTCalPreviewPara;
 CAL_LCD_STRUCT CCTCalLcdPara;
 CAL_ISP_PREVIEW_STRUCT CCTCalIspPreviewPara;
 CAL_MDP_PREVIEW_STRUCT CCTCalMdpPreviewPara;
 
kal_bool g_CctMetaMode = KAL_TRUE;
kal_bool g_CctPreviewModeCapture = KAL_FALSE;
kal_bool g_CctRawDataCapture = KAL_FALSE;

 //old isp_cct_if_v2.c
#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
#define CCT_JPEG_ENC_EXIF_MAX_MEM_SIZE JPEG_ENC_EXIF_MAX_MEM_SIZE
#else
#define CCT_JPEG_ENC_EXIF_MAX_MEM_SIZE 0
#endif

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
 static kal_bool sbCdtBinningMode = KAL_FALSE;
#endif


#define CCT_CAM_MAIN_SENSOR_MIRROR  (0) // 1 : need to mirror
#define CCT_CAM_SUB_SENSOR_MIRROR   (0)

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
#if defined(SENSOR_ROTATE_0)
#define CCT_CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SENSOR_ROTATE_90)
#define CCT_CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SENSOR_ROTATE_180)
#define CCT_CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SENSOR_ROTATE_270)
#define CCT_CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#endif

#if defined(SENSOR_ROTATE_0)
#define CCT_CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SENSOR_ROTATE_90)
#define CCT_CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SENSOR_ROTATE_180)
#define CCT_CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SENSOR_ROTATE_270)
#define CCT_CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#endif
#else
#define CCT_CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#define CCT_CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#endif

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
// CCT state machine global variable
kal_uint8  g_CCT_FirstGrabColor;
SensorInfo g_CCT_MainSensor;
FT_CCT_STATE_MACHINE	g_FT_CCT_StateMachine={

	// is init
	KAL_FALSE,
	FT_CNF_FAIL,

	// memory management
	0, 0,
	0, FT_CCT_INTERNAL_BUF_SIZE,
	0, 0,
	0, 0,
	0, 0,
	0, 0,
	0,CCT_JPEG_ENC_EXIF_MAX_MEM_SIZE,

	// sensor info
	{
		0,
		{
			{ FT_CCT_REG_ISP, 0, 0, 0, 0, 0, FT_CCT_BAYER_PTN_GR, 0, 0 },
			{ FT_CCT_REG_ISP, 0, 0, 0, 0, 0, FT_CCT_BAYER_PTN_GR, 0, 0 },
			{ FT_CCT_REG_ISP, 0, 0, 0, 0, 0, FT_CCT_BAYER_PTN_GR, 0, 0 },
			{ FT_CCT_REG_ISP, 0, 0, 0, 0, 0, FT_CCT_BAYER_PTN_GR, 0, 0 }
		}
	},

	// sensor engineer mode state
	-1, -1, -1, -1, -1,

	// preview state
	NULL,

	// AE state
	KAL_FALSE,

	// WB state
	FT_CCT_WB_RESET,

	// AF state
	KAL_FALSE,
	KAL_TRUE,
	KAL_FALSE,

	// compensation mode state
	FT_CCT_COMP_CAPTURE_NORMAL_SET, // WARNING!! MUST set default mode to capture normal for MT6219 old chip

	// defect table calibration state
	KAL_FALSE,
	KAL_FALSE,

	// strobe calibration state
	KAL_FALSE,
	{ 0, 0 },

	// capture jpeg state
	CAPTURE_JPEG_IDLE,

	// USB data tunnel state
	KAL_FALSE,
	DATA_TUNNEL_RS232,
	USB_TUNNEL_IDLE,
	0,

	// dev tool scene mode
	{ CAM_BANDING_60HZ, KAL_FALSE, CAM_AUTO_DSC },

	KAL_FALSE,//0, 

	// debug
	{0},
	{0}
};
//camera rotate

#if defined(DRV_DISPLAY_DRIVER_V2)
static volatile WFCDevice _cct_lcd_device = WFC_INVALID_HANDLE;
static volatile WFCContext _cct_lcd_context = WFC_INVALID_HANDLE;
static volatile WFCElement _cct_lcd_element = WFC_INVALID_HANDLE;
static volatile kal_uint32 _cct_lcd_width, _cct_lcd_height = 0;
//static volatile gdi_handle _cct_layer_handle;
#define GDI_LAYER_ENABLE_LAYER_0       LCD_LAYER0_ENABLE
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

kal_uint32 ft_cct_read_sensor_id_from_nvram_tag(FT_CCT_SENSOR_TYPE__ENUM sensor_type){
			
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	FT_CCT_SENSOR_TYPE__ENUM CctDataIn_SensorType;		
	SENSOR_INFO_STRUCT CctDataOut_SensorId;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn_SensorType, 0, sizeof(FT_CCT_SENSOR_TYPE__ENUM));
	kal_mem_set(&CctDataOut_SensorId, 0, sizeof(SENSOR_INFO_STRUCT));


	CalCCTInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
	CctDataIn_SensorType = sensor_type;	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn_SensorType;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_SENSOR_ID_TYPE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut_SensorId;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	g_CCT_MainSensor.type = CctDataOut_SensorId.type;
	g_CCT_MainSensor.id = CctDataOut_SensorId.id;

    if(ret==FT_CNF_FAIL)
		return ret;
	else
	return g_CCT_MainSensor.id;		  

}

kal_uint8 ft_cct_detect_sensor_id(void)
{
	kal_uint32 sensor_id = 0xFFFFFFFF;
	g_cameraType = CAM_MAIN_CAMERA;
	//sensor_id = g_main_sensor_id;
	if(0xFFFFFFFF == sensor_id){
		sensor_id = ft_cct_read_sensor_id_from_nvram_tag(CCT_MAIN_SENSOR);
   	}
	
	if(0xFFFFFFFF == sensor_id)
	{
		return FT_CCT_ERR_DETECT_SENSOR_ID_FAIL;
	}
	//set_image_sensor_id(g_cameraType, sensor_id);
	//set_isp_oper_camera_id(g_cameraType);	
	return FT_CNF_OK;
}

kal_uint8  FT_CCT_SendCnf(const FT_CCT_CNF  *cnf, peer_buff_struct *peer_buff) {

	ilm_struct	*ilm_ptr;
	FT_CCT_CNF	*ptrMsg;

	if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_CCT_CNF))) ) {
		return 1;
	}

	// if ptrMsg != NULL
	ptrMsg = (FT_CCT_CNF *)ilm_ptr->local_para_ptr;

	// assign primitive id
	ptrMsg->header.ft_msg_id = FT_CCT_CNF_ID;

	// assign return structure
	ptrMsg->op = cnf->op;
	ptrMsg->status = cnf->status;
	ptrMsg->result = cnf->result;

	// assign peer buffer
	if( NULL != peer_buff ) {
		ilm_ptr->peer_buff_ptr = peer_buff;
	}

	// FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
	FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);

	return 0;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
//begin of FT func inint ft comd
kal_uint8 ft_cct_6238_init_environment(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct *peer_buff_in, peer_buff_struct **peer_buff_ret,  kal_char **pdu_ptr, kal_uint16 *pdu_length)
{

	kal_uint8 ret = FT_CNF_OK;
	
	kal_uint8* p_dev_dual_isp_set_camera_type = NULL;
      g_FT_CCT_StateMachine.debug_last_req = *req;

	// initialize
	*pdu_length = 0;
	*pdu_ptr = NULL;
	*peer_buff_ret = NULL;
	kal_mem_set(cnf, '\0', sizeof(*cnf));

	if( NULL != peer_buff_in ) {
		*pdu_ptr = get_pdu_ptr( peer_buff_in, pdu_length );
	}

	if(!g_FT_CCT_StateMachine.is_init) {
		// disable L1D timing check to avoid In-Target reset assert
		L1D_ENABLE_CTIRQ_TimingCheck(KAL_FALSE);
		// stop RF
		L1TST_Stop();
		// init isp, sensor and firmware
		if(custom_ft_util_check_if_dual_camera_sensor_support())
		{
			if( FT_CCT_DUAL_OP_SET_CAMERA_MAIN_OR_SUB_TYPE == req->op)
			{
				g_b_set_camera_type_result = ft_cct_dual_set_camera_main_or_sub_type(req);
			}
		}
		else if(custom_ft_util_check_if_backup_camera_sensor_support())
		{
			if( FT_CCT_DUAL_OP_SET_CAMERA_MAIN_OR_SUB_TYPE == req->op)
			{
			      p_dev_dual_isp_set_camera_type = (kal_uint8 *)(&req->cmd.dev_dual_isp_set_camera_type);
				*p_dev_dual_isp_set_camera_type = 0; // 0 is CCT_MAIN_SENSOR;
				g_b_set_camera_type_result = ft_cct_dual_set_camera_main_or_sub_type(req);
			}
		}
		else
		{
				#ifdef __TH_DEBUG__
				kal_char tmp[100];
				sprintf((kal_char *)tmp, " !dual && !backup feature");
				//tst_sys_trace((kal_uint8 *)tmp);
				#endif	// __TH_DEBUG__
				g_b_set_camera_type_result = ft_cct_detect_sensor_id();//wait for Ryan HAL
		}
		/* wait for Jason HAL
		if(CAM_YUV_SUPPORT == ft_cct_get_camera_interface_support())
		{
			#ifdef __TH_DEBUG__
			kal_char tmp[100];
			sprintf((kal_char *)tmp, " You can't use YUV sensor to connect with CCT");
			//tst_sys_trace((kal_uint8 *)tmp);
			#endif	// __TH_DEBUG__
			g_b_set_camera_type_result = FT_CCT_ERR_YUV_SENSOR_NOT_SUPPORT;
		}else{
		*/
			ret = ft_cct_init();
			g_FT_CCT_StateMachine.is_init = KAL_TRUE;
		//}
		//==================================================
	}

	//return FT_CNF_OK;
	return ret;

}

kal_uint8 ft_cct_6238_send_back_confirm_message(const FT_CCT_REQ *req,FT_CCT_CNF *cnf, peer_buff_struct* peer_buff_ret)
{
      // YUV sensor not supported in CCT
	if(FT_CCT_ERR_YUV_SENSOR_NOT_SUPPORT == g_b_set_camera_type_result)
	{
		cnf->status = FT_CCT_ERR_YUV_SENSOR_NOT_SUPPORT;
		g_b_set_camera_type_result = FT_CNF_FAIL;
	}
	// send confirm 	
      cnf->header = req->header;
	cnf->op = req->op;
	FT_CCT_SendCnf(cnf, peer_buff_ret);
	// record last cnf for debugging
	g_FT_CCT_StateMachine.debug_last_cnf = *cnf;
	return FT_CNF_OK;
}

#ifdef __USB_COM_PORT_ENABLE__
void  ft_cct_usb_tunnel_send(kal_bool bReset) {

	static kal_uint32	s_max_usb_send_len=0;
	static kal_uint32 	s_total_sent_len=0;
	kal_uint32 	send_len;
	// add 4 bytes SEND pattern in front of buf 
	kal_uint32 	capture_buf_addr=(g_FT_CCT_StateMachine.mem_capture_cur_buf_addr-FT_CCT_USB_SEND_PATTERN_LEN);
	kal_uint32 	capture_buf_size=(g_FT_CCT_StateMachine.mem_capture_cur_buf_size+FT_CCT_USB_SEND_PATTERN_LEN);
	if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support())	
	{
		// get USB max send length 
		if( 0 == s_max_usb_send_len ) {
			s_max_usb_send_len = USB2UART_FT_Get_Max_Len();
			// adjust to 32bits alignment 
			if( 0 != (s_max_usb_send_len%4) ) {
				s_max_usb_send_len = (s_max_usb_send_len/4)*4;
			}
		}

		if(bReset) {
			// reset sent length 
			s_total_sent_len = 0;
			// change to sending state 
			g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_SENDING;
			// fill USB send pattern 
			kal_mem_cpy((kal_uint8 *)capture_buf_addr, usb_send_pattern, FT_CCT_USB_SEND_PATTERN_LEN);
			// reset counter 
			g_FT_CCT_StateMachine.usb_ready_to_write_cnt = 0;
		}

		if( USB_TUNNEL_SENDING != g_FT_CCT_StateMachine.usb_tunnel_state ) {
			return;
		}

		if( s_total_sent_len < capture_buf_size ) {
			// first calculate send length by 32bits WORD mode 
			if( (s_total_sent_len+(s_max_usb_send_len*4)) > capture_buf_size ) {
				send_len = (capture_buf_size-s_total_sent_len);
				if( 0 != (send_len%4) ) {
					// calculate send length by BYTE mode 
					if( (s_total_sent_len+s_max_usb_send_len) > capture_buf_size ) {
						send_len = (capture_buf_size-s_total_sent_len);
					}
					else {
						send_len = s_max_usb_send_len;
					}
					// send by BYTE mode 
					USB2UART_FT_Tx_Byte((kal_uint8 *)(capture_buf_addr+s_total_sent_len), send_len);
					goto update_sent_len;
				}
			}
			else {
				send_len = (s_max_usb_send_len*4);
			}
			// send by 32bits WORD mode 
			USB2UART_FT_Tx_Word((kal_uint32 *)(capture_buf_addr+s_total_sent_len), send_len/4);
	update_sent_len:
			s_total_sent_len += send_len;
		} 

		if( s_total_sent_len == capture_buf_size ) {
			g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_FINISH;
		}
	}
}
#endif
kal_uint8 ft_cct_6238_send_captured_data_by_usb(const FT_CCT_REQ *req,FT_CCT_CNF *cnf)
{
	if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support())
	{
		// start to send captured data via USB_COM 
		if( 1==g_FT_CCT_StateMachine.usb_capture_data_tunnel && 
			(FT_CCT_OP_SINGLE_SHOT_CAPTURE_EX==req->op || FT_CCT_OP_MULTI_SHOT_CAPTURE_EX==req->op) &&
			FT_CNF_OK == cnf->status && g_b_image_transfer == KAL_TRUE
		) {
			ft_cct_usb_tunnel_send(KAL_TRUE);
		}	
		return FT_CNF_OK;
	}else{
             return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	
}

#pragma arm section code ="SECONDARY_ROCODE" // danbo add for Capture assert 110921

kal_uint32 Cct_jpeg_Address=0,Cct_Jpeg_Size=0;

void cct_cam_main_jpeg_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{

    P_CAL_BUFFER_CB_STRUCT jpeg_ptr;
    
    jpeg_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;
	
	Cct_jpeg_Address = jpeg_ptr->ImageBuffAddr;
	Cct_Jpeg_Size = jpeg_ptr->ImageBuffSize;
	
    cam_send_event_ind(CAM_EVT_CAPTURE, (kal_uint8)MED_RES_OK);
}


static MM_ERROR_CODE_ENUM cct_cam_preview_callback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /* mATV should not doing this callback. */
    //ASSERT(0);
    
	cct_cam_main_jpeg_image_callback(pCallbackPara, CallbackParaLen); // danbo add for get JPEG  address and  size

    return MM_ERROR_INVALID_PARAMETER;
}

#pragma arm section code


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~old isp_cct_if function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void init_camera_cct()
{

	// wait for Jason feature coontrol 
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_SCENARIO_PARA_STRUCT CctDataIn;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA;
	
	g_CctMetaMode = KAL_TRUE;
	g_CctPreviewModeCapture = KAL_FALSE;
	CctDataIn.CctMetaMode = g_CctMetaMode;
	CctDataIn.CctPreviewModeCapture = g_CctPreviewModeCapture;
	CctDataIn.CctRawDataCapture = g_CctRawDataCapture;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	//CalCtrl(CAL_FEATURE_CTRL,	pCalCCTFeatureParaIn, NULL, 0, 0);
	CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL);
	
	//CameraSystemMode = CAMERA_SYSTEM_META_MODE;
	CalInit();// in cal_main.c
	CalOpen(cct_cam_preview_callback);

  // LCD 
#if defined(DRV_DISPLAY_DRIVER_V2)
  //_cct_lcd_width = LCD_WIDTH;
  //_cct_lcd_height = LCD_HEIGHT;

	_cct_lcd_width = LCD_HEIGHT;
	_cct_lcd_height = LCD_WIDTH;

#if 0   // Before entering CCT function, GDI is initialized and in use already...
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
#endif  // #if 0
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
	
#if 0 // 080220
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
#if (defined(AF_SUPPORT))// save step for normal search
/* under construction !*/
#endif
#if (!defined(DRV_ISP_6219_SERIES))
/* under construction !*/
#endif	
#else
#endif
}

/* apply global variable to reg */
void cct_apply_camera_autodefect_to_reg(camera_comp_set_num p_set_mode)
{
}

/* read from global variable */
void get_camera_autodefect_set(cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
}

/* write to global variable */
void set_camera_autodefect_set(const cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
}

kal_bool  isp_cct_is_autodefct_count_supported(void) {
	return KAL_FALSE;
}

kal_bool  isp_cct_is_autodefect_supported(void) {
	return KAL_FALSE;
}

kal_uint16  isp_cct_is_cct_af_support(void) {
	// HJ @ 2008-0807
#if (defined(AF_SUPPORT))	
	return KAL_TRUE;
#else	
	return KAL_FALSE;
#endif	
}

/* apply global variable to reg */
void cct_apply_camera_shading_to_reg(camera_comp_set_num p_set_mode)
{
}

/* read from global variable */
void get_camera_shading_set(cct_shading_comp_struct *p_cam_addr,	camera_comp_set_num p_set_mode)
{
}

/* write to global variable */
void set_camera_shading_set(const cct_shading_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode)
{
}

//ft_cct_init
kal_bool  isp_cct_is_shading_supported(void)
{
	return KAL_TRUE;
}

kal_bool cct_defect_table_on_off(kal_bool set_flag)
{
	return KAL_FALSE;
}

kal_uint16  cct_read_autodefct_count(void) {
	return 0xFFFF;
}

kal_uint8 camera_af_lens_offset_cal(AF_OQC_cal_struct *AF_cal_in)
{
#if 0
#if (defined(AF_SUPPORT))
/* under construction !*/
#endif	
#endif       
	return 1;	
}

//FT_CCT_OP_QUERY_ISP_ID
kal_uint32  isp_cct_get_isp_id(void)
{
#if 1//
#if defined(DRV_ISP_6219_SERIES)
	return 0x62198A01;
#elif defined(DRV_ISP_6228_SERIES)
	 // new isp function, assign a new unique id 
	 return 0x62288A00;
#elif (defined(DRV_ISP_6227_SERIES))
	 // different baseband chip but isp functionality is the same, just apply the same id
	 return 0x62278A00;
#elif(defined(DRV_ISP_6229_SERIES)) 
	return 0x62298A00;
#elif(defined(DRV_ISP_MT6236_HW_SUPPORT)) 
	return 0x62368A00;
#elif(defined(DRV_ISP_6238_SERIES)) 
	return 0x62388A00;
#else
	 return 0x00000000;
#endif
#endif
}
void exit_camera_preview_cct(void)
{
// Stop preview
    CAL_SCENARIO_CTRL_STRUCT CCTCalPreviewScenarioPara;
	
    CCTCalPreviewScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
    CCTCalPreviewScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    CCTCalPreviewScenarioPara.ScenarioCtrlParaLen=0;
    CCTCalPreviewScenarioPara.pScenarioCtrlPara=NULL;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CCTCalPreviewScenarioPara, NULL, 0, NULL);

    //CalClose();
    //return KAL_TRUE;
    //the following code depend on Jason's exit_raw_preview_process
/*
#if (defined(ISP_SUPPORT))

	if (isp_operation_state!=ISP_PREVIEW_STATE)
		ASSERT(0);

	stop_isp(ISP_PREVIEW_STATE, CAM_NORMAL_STOP);

//	lcd_display_enable(KAL_FALSE);
#if 1// 080429 after W0816>
	idp_cal_camera_preview_close(idp_camera_key,&isp_preview_config_data);
#else // 080429 after W0816>
	idp_camera_preview_close(idp_camera_key);
#endif // 080429 after W0816

	isp_digital_zoom_flag=KAL_FALSE;

//080428 follow TC's request	config_aaa_exit_preview();
	
	isp_operation_state=ISP_STANDBY_STATE;

	camera_process_stage|=LEAVE_EXIT_CAMERA_PREVIEW;

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   DISABLE_CAMERA_ISP_DONE_INT
   DISABLE_LCD_TRANSFER_COMPLETE_INT
#endif

	return;
#endif
////////////////////////////
*/
}

/*****************************************************************************
 * FUNCTION
 *  cam_capture_still_image_stop
 * DESCRIPTION
 *  This function is to stop camera capture.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void ft_cct_cam_capture_still_image_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalCaptureScenarioPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalCaptureScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
    CalCaptureScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    CalCaptureScenarioPara.ScenarioCtrlParaLen=0;
    CalCaptureScenarioPara.pScenarioCtrlPara=NULL;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, NULL, 0, NULL);
}

//ft_capture_ex

static kal_uint8 ft_cct_convert_capture_format_enum(kal_uint8  format) {
	switch(format) {
	case OUTPUT_RAW_8BITS:
		return (kal_uint8)CAPTRUE_MODE_RAW_8BIT;
	case OUTPUT_YUV:
		return (kal_uint8)CAPTRUE_MODE_YUV;
	case OUTPUT_RGB888:
		return (kal_uint8)CAPTRUE_MODE_RGB888;
	case OUTPUT_RAW_10BITS:
		return (kal_uint8)CAPTRUE_MODE_RAW_10BIT;
	case OUTPUT_EXT_RAW_8BITS:
		return (kal_uint8)CAPTRUE_MODE_EXT_RAW_8BIT;
	case OUTPUT_EXT_RAW_10BITS:
		return (kal_uint8)CAPTRUE_MODE_EXT_RAW_10BIT;
	case OUTPUT_EXT_YUV:
		return (kal_uint8)CAPTRUE_MODE_EXT_YUV;
	case OUTPUT_JPEG:
		return (kal_uint8)CAPTRUE_MODE_JPEG;
	default:
		return format;
	}
}

kal_bool  isp_cct_is_capmode_supported(kal_uint8 mode)
{
    kal_bool ret = KAL_FALSE;
    switch (mode)
	{
   		case CAPTRUE_MODE_RAW_8BIT:		        // RAW, 8Bit, capture to internal ram
           	ret = KAL_FALSE;
            break;            	   		
		case CAPTRUE_MODE_YUV:				    // YUV, capture to internal ram
           	ret = KAL_FALSE;		
            break;            			
		case CAPTRUE_MODE_EXT_RAW_8BIT:         // RAW, 8Bit, capture to external ram  
            	ret = KAL_TRUE;		
            break;            			
		case CAPTRUE_MODE_EXT_YUV:			    // YUV, capture to external ram       
            	ret = KAL_FALSE;
            break;            			            
		case CAPTRUE_MODE_RAW_10BIT:			// RAW, 10Bit, capture to internal ram  
						ret = KAL_FALSE;
            break;           
		case CAPTRUE_MODE_EXT_RAW_10BIT:		// RAW, 10Bit, capture to external ram	
            #if (defined(DRV_ISP_MT6236_HW_SUPPORT))
            	ret = KAL_TRUE;
            #else
            	ret = KAL_FALSE;
            #endif	
            break;            	
		case CAPTRUE_MODE_RGB888:			    // RGB888, capture to internal ram
		case CAPTRUE_MODE_RGB565:			    // RGB565, capture to internal ram
		case CAPTRUE_MODE_EXT_RGB888:		    // RGB888, capture to external ram
		case CAPTRUE_MODE_EXT_RGB565:			// RGB565, capture to external ram
           	ret = KAL_FALSE;
            break;          
        case CAPTRUE_MODE_JPEG:       
            	ret = KAL_TRUE;	
            break;            	        
    }
    return ret;
}

kal_bool IspCdtSetBinningMode(kal_bool EN) //080528
{	
    if(EN)
    	{
			sbCdtBinningMode=KAL_TRUE;		
    	}
	else{
			sbCdtBinningMode=KAL_FALSE;
		}
   	//isp_capture_jpeg_data.binning_mode = sbCdtBinningMode;//080528
	return KAL_TRUE;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ft sub function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//FT_CCT_OP_PREVIEW_LCD_START
const FT_CCT_SENSOR_EX * get_sensor_by_id(const FT_CCT_REG_TYPE  type, const kal_uint32  device_id) {
	kal_uint8	i;
	for(i=0; i<g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor_count; i++) {
#if 1
		if( type==g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].type && device_id==g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].device_id ) {
			return &(g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i]);
		}
#else
/* under construction !*/
#endif
	}
	return NULL;
}

kal_uint8  ft_cct_set_gamma_bypass(kal_bool enable_flag){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	//kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SET_GAMMA_BYPASS;
	CctDataIn.Enable = enable_flag;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

//FT_CCT_OP_PREVIEW_LCD_START
kal_uint8  ft_cct_preview_on_lcd_enable(const FT_CCT_SENSOR_EX  *sensor, kal_bool enable_flag) {

	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
	//static camera_preview_process_struct	s_preview_para;
	kal_uint16	lcd_width;
	kal_uint16	lcd_height;

	CAL_SCENARIO_CTRL_STRUCT CCTCalPreviewScenarioPara;
 	CAL_CAMERA_PREVIEW_STRUCT CCTCalPreviewPara;
 	CAL_LCD_STRUCT CCTCalLcdPara;
 	CAL_ISP_PREVIEW_STRUCT CCTCalIspPreviewPara;
 	CAL_MDP_PREVIEW_STRUCT CCTCalMdpPreviewPara;
 	//CAL_FD_SD_STRUCT CCTCalFdSdPara; 
 	CAL_POSTPROC_STRUCT  CCTCalPostProcPreviewPara;
 	MM_IMAGE_ROTATE_ENUM CctPreviewRotate = MM_IMAGE_ROTATE_0;
//wait CT imprement function 2010.12.21
	// get lcd width and height 
	//lcd_get_size(MAIN_LCD, &lcd_width, &lcd_height); //HAL
	//lcd_height = 480;
	//lcd_width = 320;
#if defined(DRV_DISPLAY_DRIVER_V1)
	lcd_get_size(MAIN_LCD, &lcd_width, &lcd_height); //HAL
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
#if defined(DRV_DISPLAY_DRIVER_V2)
  if ((0 == _cct_lcd_width) || 
      (0 == _cct_lcd_height))
  {
    ASSERT(0);
  }

  lcd_width = _cct_lcd_width;
  lcd_height = _cct_lcd_height;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

///* HAL 
	// select device 
   
	if( KAL_TRUE == enable_flag ) {
		#if 0 // internal mem will be controlled by ME2
		#if defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
	#endif
		///*//LCD config old, wait for new
		// enable preview 
		// New IDP
		if (g_cameraType == CAL_CAMERA_SOURCE_MAIN)
		{
			CctPreviewRotate = (MM_IMAGE_ROTATE_ENUM)CCT_CAM_MAIN_SENSOR_ROTATE;
            if (CCT_CAM_MAIN_SENSOR_MIRROR)
                CctPreviewRotate += (MM_IMAGE_ROTATE_ENUM)MM_IMAGE_H_MIRROR;
		}
		else if(g_cameraType == CAL_CAMERA_SOURCE_SUB)
		{
			 CctPreviewRotate = (MM_IMAGE_ROTATE_ENUM)CCT_CAM_SUB_SENSOR_ROTATE;
            if (CCT_CAM_SUB_SENSOR_MIRROR)
                CctPreviewRotate += (MM_IMAGE_ROTATE_ENUM)MM_IMAGE_H_MIRROR;
		}
#if defined(DRV_DISPLAY_DRIVER_V2)
    {
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
      #endif
      gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

      gdi_layer_get_layer_element(
        GDI_LAYER_ENABLE_LAYER_0,
        (kal_uint32 *)&_cct_lcd_element,
        (kal_uint32 *)&_cct_lcd_context,
        (kal_uint32 *)&_cct_lcd_device);

      CCTCalLcdPara.WfcDeviceHandle = _cct_lcd_device;
      CCTCalLcdPara.WfcContextHandle = _cct_lcd_context;
      CCTCalLcdPara.WfcElementHandle = _cct_lcd_element;

      wfcActivate(_cct_lcd_device, _cct_lcd_context);
	  /*
      if (WFC_ERROR_NONE != wfcGetError(_cct_lcd_device))
      {
        ASSERT(0);
      }
      */
    }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)
		
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
#endif	

	if(g_FT_CCT_StateMachine.wb_activated_idx == FT_CCT_WB_AUTO)
		{
			ft_cct_6238_awb_enable(KAL_TRUE);
		}
	
	if(g_FT_CCT_StateMachine.ae_enable )
		{
			ft_cct_6238_ae_enable(KAL_TRUE);		
		}

	if(g_FT_CCT_StateMachine.gamma_bypass)
		{
			ft_cct_set_gamma_bypass(KAL_TRUE);
		}
	else
		{
			ft_cct_set_gamma_bypass(KAL_FALSE);
		}
		//*/ HAL preview scenario
		CCTCalMdpPreviewPara.ImageRotAngle=CctPreviewRotate;
    CCTCalMdpPreviewPara.ImageDataFormat=MM_IMAGE_FORMAT_RGB565;//IMG_COLOR_FMT_RGB565;
    CCTCalMdpPreviewPara.DisplayImageWidth=lcd_width;
    CCTCalMdpPreviewPara.DisplayImageHeight=lcd_height;
    CCTCalMdpPreviewPara.FrameBuffAddr1=g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr;
    CCTCalMdpPreviewPara.FrameBuffAddr2=g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr + g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size;
    CCTCalMdpPreviewPara.FrameBuffAddr3=g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr + 2*g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size;//add for Preview timeout
    CCTCalMdpPreviewPara.FrameBuffSize=g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size;
    CCTCalMdpPreviewPara.OverlayEnable = KAL_FALSE;
    //CCTCalMdpPreviewPara.OverlayEnable=isp_data->overlay_frame_mode; //default
    //CCTCalMdpPreviewPara.OverlayPaletteAddr=isp_data->overlay_palette_addr; //default
    //CCTCalMdpPreviewPara.OverlayPaletteSize=isp_data->overlay_palette_size; //default
    //CCTCalMdpPreviewPara.OverlayColorDepth=isp_data->overlay_color_depth; //default
    //CCTCalMdpPreviewPara.OverlayFrameSourceKey=isp_data->overlay_frame_source_key;//default
    //CCTCalMdpPreviewPara.OverlayFrameWidth=isp_data->overlay_frame_width; //default
    //CCTCalMdpPreviewPara.OverlayFrameHeight=isp_data->overlay_frame_height; //default
    //CCTCalMdpPreviewPara.OverlayFrameBuffAddr=isp_data->overlay_frame_buffer_address;//default
    //CalMdpPreviewPara.OverlayPaletteMode=isp_data->//default
    CCTCalMdpPreviewPara.LcdUpdateEnable=KAL_TRUE;

   // CCTCalIspPreviewPara.ContinueCapture=CAL_CAMERA_SINGLE_CAPTURE;//isp_data->; // for YUV only
    CCTCalIspPreviewPara.ZoomStep=0; //default
    //CCTCalIspPreviewPara.TotalZoomStep=40; //default
    //CCTCalIspPreviewPara.MaxZoomFactor=800;//default
    CCTCalIspPreviewPara.ContrastLevel=CAM_CONTRAST_MEDIUM;//1;
    CCTCalIspPreviewPara.BrightnessLevel=0;//isp_data->; // for YUV only
    CCTCalIspPreviewPara.SaturationLevel=CAM_SATURATION_MEDIUM;//1;//default
    CCTCalIspPreviewPara.SharpnessLevel=CAM_SHARPNESS_MEDIUM;//1;//default
    CCTCalIspPreviewPara.WbMode=CAM_WB_AUTO;//0;
    CCTCalIspPreviewPara.EvValue=CAM_EV_ZERO;//4;
    CCTCalIspPreviewPara.BandingFreq=CAM_BANDING_60HZ;
	CCTCalIspPreviewPara.ImageEffect=CAM_EFFECT_ENC_NORMAL;//0;

    CCTCalIspPreviewPara.SceneMode=CAM_AUTO_DSC;//isp_data->dsc_mode;//default
    CCTCalIspPreviewPara.AeMeteringMode=CAM_AE_METER_AUTO;//isp_data->ae_metering_mode;//default
    CCTCalIspPreviewPara.FlashMode=CAM_FLASH_AUTO;//isp_data->flash_mode;//default
    CCTCalIspPreviewPara.AfOperationMode=CAM_AF_SINGLE_ZONE;//isp_data->af_operation_mode;//default
    CCTCalIspPreviewPara.AfRange=CAM_AF_RANGE_AUTO;//isp_data->af_range;//default

    CCTCalIspPreviewPara.HueValue=0;//isp_data->; // for YUV only
    
    //CCTCalFdSdPara.FdEnable=KAL_FALSE;
    CCTCalPostProcPreviewPara.PostProcMode=KAL_FALSE;
    //CalFdSdPara.ExtmemFdStartAddr=isp_data->extmem_fd_start_address;
    //CalFdSdPara.ExtmemFdSize=isp_data->extmem_fd_size;

    CCTCalPreviewPara.ExtmemStartAddress=0; // internal or external:?
    CCTCalPreviewPara.ExtmemSize=0;// internal or external:?
    

		CCTCalPreviewPara.pLcdPara=&CCTCalLcdPara;
    CCTCalPreviewPara.pMdpPara=&CCTCalMdpPreviewPara;
    CCTCalPreviewPara.pIspPara=&CCTCalIspPreviewPara;
    //CCTCalPreviewPara.pFdSdPara=&CCTCalFdSdPara;
    CCTCalPreviewPara.pPostProcPara=&CCTCalPostProcPreviewPara;
    
		CCTCalPreviewScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
    CCTCalPreviewScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_START;
    CCTCalPreviewScenarioPara.ScenarioCtrlParaLen=sizeof(CAL_CAMERA_PREVIEW_STRUCT);
    CCTCalPreviewScenarioPara.pScenarioCtrlPara=&CCTCalPreviewPara;
		//kal_mem_cpy(&isp_preview_config_data, isp_data, sizeof(camera_preview_process_struct));
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CCTCalPreviewScenarioPara, NULL, 0, NULL);

		//camera_preview_cct(&s_preview_para);
	}
	else {
		// disable preview 
		exit_camera_preview_cct();

#if defined(DRV_DISPLAY_DRIVER_V2)
    if ((WFC_INVALID_HANDLE != _cct_lcd_device) && 
        (WFC_INVALID_HANDLE != _cct_lcd_context) )//&& 
        //(NULL != _cct_layer_handle))
    {
      wfcDeactivate(_cct_lcd_device, _cct_lcd_context);
/*
      if (WFC_ERROR_NONE != wfcGetError(_cct_lcd_device))
      {
        ASSERT(0);
      }
*/
      //mdi_util_hw_layer_free(_cct_layer_handle);

      _cct_lcd_device = WFC_INVALID_HANDLE;
      _cct_lcd_context = WFC_INVALID_HANDLE;
      _cct_lcd_element = WFC_INVALID_HANDLE;
      //_cct_layer_handle = NULL;
    }
#endif  // #if defined(DRV_DISPLAY_DRIVER_V2)

#if 0
#if defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
#endif
	}
//*/
	return FT_CNF_OK;
}

void ft_cct_set_final_grab_xy_width_height(kal_int16  *p_grab_left_pos,
									kal_int16  *p_grab_top_pos,
									kal_int16  *p_grab_width,
									kal_int16  *p_grab_height,
									kal_uint8	output_format
) {

	// calculate final grab start position, and final grab width & height 
	if( OUTPUT_RAW_8BITS==output_format || OUTPUT_RAW_10BITS==output_format || 
		OUTPUT_EXT_RAW_8BITS==output_format || OUTPUT_EXT_RAW_10BITS==output_format
	) {
		// RAW (Bayer) 

		//     (x,y)                          
		//       |-----------------------|    
		//       |               |       |    
		//       |      RAW      |       |    
		//       |               |   4   |    
		//       |               |   p   |    
		//       |---------------|       |    
		//       |                       |    
		//       |          2 pixel      |    
		//       |-----------------------|    

		// exposure window is the left-top (x,y), in order to capture the centeral image,   
		// grab (x,y) should add (+2,+1) offset. 
		//*(p_grab_left_pos) += 2;
		//*(p_grab_top_pos) += 1;
		
		// disable the above part to avoid 1st pixel bayer pattern needs to be re-calculated. 
		// just allow RAW has slightly shift with YUV in capture range 

		// Because SET_TG_GRAB_PIXEL will +4 pixels in width when capture image through ISP 
		// For Bayer image output, the data will not pass through ISP, we should -4 pixels  
		// in width for getting the correct shot screen 
//#if defined(MT6238)||defined(MT6239) //
//#if (defined(DRV_ISP_6238_SERIES))	
		(*p_grab_width) -= 0;//4;//4; 
//#else
//		(*p_grab_width) -= 4; 
//#endif
		// Because SET_TG_GRAB_LINE will +2 pixels in height when capture image through ISP 
		// For Bayer image output, the data will not pass through ISP, we should -2 pixels  
		// in height for getting the correct shot screen 
//#if defined(MT6238)|| defined(MT6239) //
		(*p_grab_height) -= 0;//6;//2;
	}
	else {
		// OUTPUT_YUV (YCbCr) 

		//  grab left                         
		//    top|-----------------------|    
		//       |          1 pixel      |    
		//       |    |-------------|    |    
		//       | 2  |             | 2  |    
		//       | p  |    YCbCr    | p  |    
		//       |    |             |    |    
		//       |    |-------------|    |    
		//       |          1 pixel      |    
		//       |-----------------------|    

		// same as normal mode, no need to change 
	}
}


//ft_cct_6238_init_environment
kal_uint8 ft_cct_dual_set_camera_main_or_sub_type(const FT_CCT_REQ *req)
{
#ifdef __TH_DEBUG__
	char tmp[256];
#endif	// __TH_DEBUG__
	kal_uint32 sensor_id = 0xFFFFFFFF;
	FT_CCT_SENSOR_TYPE__ENUM camera_type = (FT_CCT_SENSOR_TYPE__ENUM)(req->cmd.dev_dual_isp_set_camera_type);
	if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support())
	{
		if(req == NULL)
			return FT_CNF_FAIL;
		if(CCT_MAIN_SENSOR == camera_type) 
		{
			g_cameraType = CAL_CAMERA_SOURCE_MAIN /* CAM_MAIN_CAMERA*/; // HAL
			sensor_id = g_main_sensor_id;
			if(NULL == sensor_id){
				sensor_id = 128;
				//wait for Ryan HAL
				sensor_id = ft_cct_read_sensor_id_from_nvram_tag(camera_type);
	       	}
			#ifdef __TH_DEBUG__
			sprintf((kal_char *)tmp, "Set g_cameraType = CAM_MAIN_CAMERA");
			//tst_sys_trace((kal_uint8 *)tmp);
			#endif
		}
		else
		{	
			if(custom_ft_util_check_if_dual_camera_sensor_support())
			{
				g_cameraType = CAL_CAMERA_SOURCE_SUB/*CAM_SUB_CAMERA*/;// HAL
				sensor_id = g_sub_sensor_id;
				if(NULL == sensor_id){
					sensor_id = 128;
				//wait for Ryan HAL
					sensor_id = ft_cct_read_sensor_id_from_nvram_tag(camera_type);
		       	}
				#ifdef __TH_DEBUG__
				sprintf((kal_char *)tmp, "Set g_cameraType = CAM_SUB_CAMERA");
				//tst_sys_trace((kal_uint8 *)tmp);
				#endif	// __TH_DEBUG__	
			}
		}		

		if(0xFFFFFFFF == sensor_id)
		{
			return FT_CCT_DUAL_ERR_DETECT_SENSOR_ID_FAIL;
		}
		//set_image_sensor_id(g_cameraType, sensor_id); //HAL
		//set_isp_oper_camera_id(g_cameraType); //HAL			
		return FT_CNF_OK;
	}
	else
	{	// not support dual or backup sensor
		return FT_CNF_FAIL;
	}
}
/*//HAL wait for Jason
CAMERA_INTERFACE_ENUM ft_cct_get_camera_interface_support(void)
{	
	camera_module_info_func_struct *p_camera_module_info_func;
	camera_module_info_func_config(&p_camera_module_info_func);
	return p_camera_module_info_func->camera_interface_support();
}
*/

void ft_cct_adjust_capture_buf(kal_uint32  *pBufAddr, kal_uint32  *pBufSize) {

	kal_uint32	buf_addr=*pBufAddr;
	kal_uint32	buf_size=*pBufSize;
	kal_uint32	buf_end_addr=(buf_addr+buf_size-1);

	// adjust capture buf address to 4bytes alignment 
	if( 0 != (buf_addr%4) ) {
		buf_addr = (((buf_addr>>2)+1)<<2);
	}

	// the first 4 bytes are reserved for USB SEND pattern 
	buf_addr += FT_CCT_USB_SEND_PATTERN_LEN;

	// adjust buf size to 8bytes alignment, because external buffer will be divided into two buffer for RGB888 capture 
	buf_size = (buf_end_addr-buf_addr+1);
	if( 0 != (buf_size%8) ) {
		buf_size = ((buf_size>>3)<<3);
	}

	*pBufAddr = buf_addr;
	*pBufSize = buf_size;
}

kal_bool cct_backup_bypass_pre_adjust(void)
{
	return KAL_FALSE;
}

kal_bool cct_recover_pre_adjust(void) {
	return KAL_FALSE;
}

//ft_cct_init
// danbo changed 
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
#else
// FT_CCT_OP_AF_ON_OFF: 64 
kal_uint8  ft_cct_af_on_off(kal_bool  bOn){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	
	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_AF_ON_OFF;
	CctDataIn.Enable = bOn;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}  

	g_FT_CCT_StateMachine.af_on_off = bOn;
	  return ret;
}
#endif

// FT_CCT_OP_DEFECT_TABLE_ON_OFF: 65
kal_uint8  ft_cct_defect_table_on_off(kal_bool  bOn) {
	cct_defect_table_on_off(bOn);
	g_FT_CCT_StateMachine.defect_table_on_off = bOn;
	return FT_CNF_OK;
}

//void  get_sensor_group_count(kal_int32* sensor_count_ptr)
kal_uint8  get_sensor_group_count(kal_int32* sensor_count_ptr)
{
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
    kal_int32 CctDataOut;
  
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_SENSOR_GROUP_COUNT; 
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
    CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}  
	
	//&CctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	*sensor_count_ptr = CctDataOut;

	return ret;

}

//void get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr){
kal_uint8 get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_SENSOR_GROUP_INFO_STRUCT CctDataIn, CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SENSOR_GROUP_INFO_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_SENSOR_GROUP_INFO_STRUCT));
  
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_SENSOR_GROUP_INFO;
	CctDataIn.GroupIdx = group_idx;
	CctDataIn.GroupNamePtr = (kal_uint8 *)group_name_ptr;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
    CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}  
	
	//&CctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
    //group_name_ptr = CctDataOut.GroupNamePtr;
	*item_count_ptr = CctDataOut.ItemCount;
	
	return ret;
	

}

//void get_sensor_item_info(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr){
kal_uint8 get_sensor_item_info(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_SENSOR_ITEM_INFO_STRUCT CctDataIn, CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));
  
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_SENSOR_ITEM_INFO; 
	CctDataIn.GroupIdx = group_idx;
	CctDataIn.ItemIdx = item_idx;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
    CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}  
	
	//&CctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
    info_ptr->is_need_restart = CctDataOut.IsNeedRestart;
	info_ptr->is_read_only = CctDataOut.IsReadOnly;
	info_ptr->is_true_false = CctDataOut.IsTrueFalse;
	//info_ptr->item_name_ptr = CctDataOut.ItemNamePtr;
	kal_mem_cpy(&(info_ptr->item_name_ptr), &(CctDataOut.ItemNamePtr), sizeof(info_ptr->item_name_ptr));
	info_ptr->item_value = CctDataOut.ItemValue;
	info_ptr->max = CctDataOut.Max;
	info_ptr->min = CctDataOut.Min;	
	
	return ret;
	
}

kal_bool set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_SENSOR_ITEM_INFO_STRUCT CctDataIn;
  
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SENSOR_ITEM_INFO; 
	CctDataIn.GroupIdx = group_idx;
	CctDataIn.ItemIdx = item_idx;
	CctDataIn.ItemValue = item_value;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	} 

	return (kal_bool)ret;
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// danbo add for cosmos capture assert  110412
#ifdef __MED_IN_ASM__  
extern void* mmi_res_get_asm_pool(void);
//extern U32 mmi_res_get_asm_pool_size(void);
extern unsigned int mmi_res_get_asm_pool_size(void);
kal_uint32 dynamic_switch_cacheable_region(void *vaddr, kal_uint32 len, kal_uint32 cacheable);
#endif
//void ft_cct_init(void) {
kal_uint8 ft_cct_init(void) {
	//kal_char ext_buf_info[100];
	kal_uint16	lcd_width;
	kal_uint16	lcd_height;
	kal_int32	group_count, item_count;
	kal_int8	group_name[128];
	ENG_sensor_info	item_info; //HAL
	kal_uint32	ext_buf_addr, ext_buf_size;
	//static kal_bool sbExtMemAddr = 0; // 080515 check if CS5 fix it? 1; // danbo mark for fix warning  110401

	
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32 *RegOutLen = 0;

#ifdef __MED_IN_ASM__ 
	void* Asm_Address;
    //U32 Asm_Size;
    unsigned int Asm_Size;	
#endif

	//CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrl = {0};
	//IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT ImageSensorInOut = {0};
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrl ;
	IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT ImageSensorInOut ;
	device_info_struct CctAeLutDataOut ;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;

	kal_mem_set(&CCTfeatureCtrl, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&ImageSensorInOut, 0, sizeof(IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT));
	kal_mem_set(&CctAeLutDataOut, 0, sizeof(device_info_struct));
	
	// get lcd width and height 
#if defined(DRV_DISPLAY_DRIVER_V1)
	lcd_get_size(MAIN_LCD, &lcd_width, &lcd_height); //HAL
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
#if defined(DRV_DISPLAY_DRIVER_V2)
  lcd_width = LCD_WIDTH;
  lcd_height = LCD_HEIGHT;
#endif  // #if defined(DRV_DISPLAY_DRIVER_V1)
	g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size = sizeof(kal_uint16)*lcd_width*lcd_height;

	// calculate internal sram size 
#if 0
#if !defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if !defined(DRV_FEATURE__MM_INTMEM_IF)
#endif

#ifdef __MED_IN_ASM__   
	
		//U32* key_pool;
		//key_pool = (U32*)applib_asm_alloc_anonymous(NVRAM_CACHE_VALIDATE_TEMP_BUF_SIZE);
		//applib_asm_free_anonymous(key_pool);
		
		Asm_Address = mmi_res_get_asm_pool();
		Asm_Size = mmi_res_get_asm_pool_size();

		//dynamic_switch_cacheable_region(Asm_Address,Asm_Size,PAGE_NO_CACHE);
		Asm_Size -= Asm_Size%32; // danbo add for assert 110509
		dynamic_switch_cacheable_region((void*)&Asm_Address,(kal_uint32)Asm_Size,0);

		ext_buf_addr = (kal_uint32)Asm_Address;
		ext_buf_size = (kal_uint32)Asm_Size;
		EXT_ASSERT((0x08000000 >= ext_buf_size), ext_buf_addr, ext_buf_size, 0);
#else
	// allocate large external memory buffer 
	#if 1// 080318 failed in current version
	INT_QueryBiggestPool(&ext_buf_size, (void *)&ext_buf_addr);

#ifdef __TH_DEBUG__
	sprintf((kal_char *)group_name, "ext_buf_addr > 0x%x }",ext_buf_addr);
	//tst_sys_trace((kal_uint8 *)group_name);	
#endif

	   #if 0  // danbo mark for fix warning  110401
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
	
	EXT_ASSERT((0x08000000 >= ext_buf_size), ext_buf_addr, ext_buf_size, 0);
	#endif
#endif
	// allocate preview memory and external capture memory 
	
	// HAL FrameBuffAddr1 7 FrameBuffAddr2
	g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr = ext_buf_addr;

       ulFtCctDisplaybifferAddress = g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr + g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size; //080704
       ulFtCctDisplaybifferSize = g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size*(FT_CCT_DISPLAY_BUFFER_SIZE); //080704

	//capture exif buffer
	g_FT_CCT_StateMachine.mem_capture_ext_exif_size = JPEG_ENC_EXIF_MAX_MEM_SIZE;  // MAX_CAM_ENC_EXIF_TOTAL_BUF_SIZE->JPEG_ENC_EXIF_MAX_MEM_SIZE //jim
	g_FT_CCT_StateMachine.mem_capture_ext_exif_addr = ext_buf_addr + g_FT_CCT_StateMachine.mem_capture_ext_exif_size * (1+FT_CCT_DISPLAY_BUFFER_SIZE);

	//capture jpeg or raw buffer
	g_FT_CCT_StateMachine.mem_capture_ext_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_exif_addr+g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size*(1+FT_CCT_DISPLAY_BUFFER_SIZE)+FT_CCT_DISPLAY_BUFFER_DUMMY_SIZE; //080704
	g_FT_CCT_StateMachine.mem_capture_ext_buf_size = ext_buf_size- (g_FT_CCT_StateMachine.mem_capture_ext_exif_size + g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size)*(1+FT_CCT_DISPLAY_BUFFER_SIZE)-FT_CCT_DISPLAY_BUFFER_DUMMY_SIZE; //080704
	// adjust buffer address and length 
#if 0
#if !defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
#endif  // #if !defined(DRV_FEATURE__MM_INTMEM_IF)
#endif
	ft_cct_adjust_capture_buf(&(g_FT_CCT_StateMachine.mem_capture_ext_buf_addr), &(g_FT_CCT_StateMachine.mem_capture_ext_buf_size));

#ifdef __TH_DEBUG__
	sprintf((kal_char *)group_name, "MEM={ LCD_LAYER0_EXT_MEM(%u), ISP_INT_MEM(%u), CAPTURE_INT_MEM(%u), CAPTURE_EXT_MEM(%u) }", g_FT_CCT_StateMachine.mem_lcd_layer0_buf_size, g_FT_CCT_StateMachine.mem_isp_int_buf_size, g_FT_CCT_StateMachine.mem_capture_int_buf_size, g_FT_CCT_StateMachine.mem_capture_ext_buf_size);
	//tst_sys_trace((kal_uint8 *)group_name);
#endif

	// initialize camera module 
	init_camera_cct();
	// load from nvram, but don't apply to ISP, AE&AWB and SENSOR register 
	// because init_camera_cct() will apply
	// HAL wait for ryan 
	//CAL_FEATURE_CCT_OP_LOAD_FROM_NVRAM
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_LOAD_FROM_NVRAM; 
	
	if(CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL) != MM_ERROR_NONE ){ // wait for Ryan
		EXT_ASSERT(KAL_FALSE, 0, 0, 0);
	}

	// initialize camera module 
	//init_camera_cct(g_FT_CCT_StateMachine.mem_lcd_layer0_buf_addr);//LCM triger function, wait for ME2

	// get sensor width and height 
	//image_sensor_func->get_sensor_size(&sensor_width, &sensor_height);//HAL wait for Ryan
	
	// get sensor preview setting 
	/* //HAL wait for Jason
	sensor_config_data.image_mirror=g_CCT_PreviewImageMirror;
	sensor_config_data.frame_rate=0xFF;
	image_sensor_func->sensor_preview_setting(&exposure_window,&sensor_config_data);
	*/
	/* wait for Ryan HAL
	// query each on board sensor
	image_sensor_global_var_init();	// //for CCT use before using g_CCT_MainSensor & g_CCT_FirstGrabColor
	*/

	 CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_QUERY_SENSOR;	
	CCTfeatureCtrl.pCctFeatureParaOut = &ImageSensorInOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrl;
	
//	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara->pCctFeatureParaOut = &(CCTfeatureCtrl.pCctFeatureParaOut);
	//CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara->pCctFeatureParaOut = ImageSensorInOut ;
	 if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, RegOutLen)!=0)
	 {
	   ret = FT_CNF_FAIL;
	 }		 
	 //pImageSensorInOut = CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara->pCctFeatureParaOut;
	//CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara,  (void*)&CalCCTOutPara, 0,0);// wait for HAL structure
	
	//g_CCT_MainSensor.type = CMOS_SENSOR;
	//g_CCT_MainSensor.id = ImageSensorInOut.SensorId;
	//g_FT_CCT_StateMachine.comp_mode = PImageSensorInOut->
	switch(ImageSensorInOut.CaptureDataFormat)
		{
		case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST:
			//g_CCT_FirstGrabColor = 0;
			g_CCT_FirstGrabColor = 1;
			break;
		case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST:
			//g_CCT_FirstGrabColor = 1;
			g_CCT_FirstGrabColor = 2;
			break;
		case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST:
			g_CCT_FirstGrabColor = 3;
			break;
		case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST:
			g_CCT_FirstGrabColor = 4;
			break;
		default:
			g_CCT_FirstGrabColor = 2;
			break;			
		}

	
	switch(g_CCT_MainSensor.type) {
	case CMOS_SENSOR:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].type = FT_CCT_REG_CMOS;
		break;
	case CCD_SENSOR:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].type = FT_CCT_REG_CCD;
		break;
	default:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].type = FT_CCT_REG_CMOS;
		break;
	}
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].device_id = g_CCT_MainSensor.id ;
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].width = sensor_width;
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].height = sensor_height;
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].width = ImageSensorInOut.FullWidth;
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].height = ImageSensorInOut.FullHeight;
	
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_width = exposure_window.exposure_window_width; //wait for ryan HAL
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_height = exposure_window.exposure_window_height;//wait for ryan HAL
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_width = ImageSensorInOut.PreviewWidth; //wait for ryan HAL
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_height = ImageSensorInOut.PreviewHeight;//wait for ryan HAL

	switch(g_CCT_FirstGrabColor) {
	case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].start_pixel_bayer_ptn = FT_CCT_BAYER_PTN_R;
		break;
	case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].start_pixel_bayer_ptn = FT_CCT_BAYER_PTN_GB;
		break;
	case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].start_pixel_bayer_ptn = FT_CCT_BAYER_PTN_B;
		break;
	case IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST:
	default:
		g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].start_pixel_bayer_ptn = FT_CCT_BAYER_PTN_GR;
		break;
	}
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].grab_x_offset = exposure_window.grab_start_x;//wait for ryan HAL
	//g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].grab_y_offset = exposure_window.grab_start_y;//wait for ryan HAL
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].grab_x_offset = 0;//wait for ryan HAL
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].grab_y_offset = 1;//wait for ryan HAL
	g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor_count = 1;
	
	// disable AE & AWB, because init_camera_cct() will enable AE & AWB by default 
	ft_cct_ae_enable(KAL_FALSE);
	ft_cct_6238_ae_enable(KAL_FALSE);

	ft_cct_wb_activate_by_index(FT_CCT_WB_OFF);	
	// disable AF 
	if(isp_cct_is_cct_af_support()) {
		ft_cct_af_on_off(KAL_FALSE);
	}
//#if (!defined(MT6219))
	// disable defect table 
	ft_cct_defect_table_on_off(KAL_FALSE);
//#endif

	// default no sensor is at preview stage now 
	g_FT_CCT_StateMachine.p_preview_sensor = NULL;

	// apply default compensation mode 
	if(isp_cct_is_shading_supported()) {
		cct_apply_camera_shading_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	}
	if(isp_cct_is_autodefect_supported()) {
		cct_apply_camera_autodefect_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	}
//#if (!defined(MT6219))
	// reset defect table calibration state machine 
	//reset_camera_defectpixel(DEFECT_MODE_BOTH); //HAL
	
	// set default scene mode 
	//wait for Ryan HAL  danbo note  need Update.
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
    #endif
	//CAL_FEATURE_CCT_OP_DEV_AE_GET_INFO// not this one
	//get_ae_lut(g_FT_CCT_StateMachine.dev_ae_scene_mode);
//#endif

	// get sensor engineer mode group index and item index 
	ret = get_sensor_group_count(&group_count); //wait for Ryan HAL
	for(; 0<group_count; group_count--) {
		// find CCT group index 
		ret = get_sensor_group_info((kal_uint16)(group_count-1), group_name, &item_count); 
		if(!strcmp("CCT", (kal_char*)group_name)) {
			g_FT_CCT_StateMachine.sensor_eng_group_idx = group_count-1;
			for(; 0<item_count; item_count--) {
				ret = get_sensor_item_info((kal_uint16)(group_count-1), (kal_uint16)(item_count-1), &item_info);
				if(!strcmp("Pregain-R", (kal_char*)item_info.item_name_ptr)) {
					g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_R = item_count-1;
				}
				else if(!strcmp("Pregain-Gr", (kal_char*)item_info.item_name_ptr)) {
					g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gr = item_count-1;
				}
				else if(!strcmp("Pregain-Gb", (kal_char*)item_info.item_name_ptr)) {
					g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gb = item_count-1;
				}
				else if(!strcmp("Pregain-B", (kal_char*)item_info.item_name_ptr)) {
					g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_B = item_count-1;
				}
			}
		}
	}
	
	return ret;
}

//------------------------------------------------------------------------------
//	[TH]  CCT 6238 AE API
//------------------------------------------------------------------------------
// FT_CCT_6238_OP_AE_ENABLE: 97
// FT_CCT_6238_OP_AE_ENABLE: 98
kal_uint8  ft_cct_6238_ae_enable(kal_bool enable){
	kal_uint8	ret = FT_CNF_OK;
	
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	
	// 080421 also need to switch AE flag.
	if(enable) { 
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_ENABLE; 
	}
	else {
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_DISABLE; 
	}
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	g_FT_CCT_StateMachine.ae_enable = enable;

	return ret;
}

kal_uint8 ft_cct_6238_awb_enable(kal_bool enable){
	kal_uint8	ret = FT_CNF_OK;
	
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable)
	{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_AUTO_RUN; 
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		g_FT_CCT_StateMachine.wb_activated_idx = FT_CCT_WB_AUTO;
	}
	else
	{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_AUTO_RUN; 
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		g_FT_CCT_StateMachine.wb_activated_idx = FT_CCT_WB_OFF;	
		
	}
	return ret;
}

// CCT_6238_OP_ISP_ENABLE_BINNING_MODE: 176 , 177
kal_uint8  ft_cct_6238_isp_set_binning_mode(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	// danbo mark wait function update
	// this function finish
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
	#endif
        sbCdtBinningMode=enable;
	  return ret;
}


kal_uint32 ft_cct_6238_cal_g_channel_mean_from_addr(kal_uint32 addr, kal_uint32 size, FT_CCT_BAYER_PATTERN first_pixel_bayer, kal_uint32 width, kal_uint32 height)
{
	kal_bool is_Gr_line = KAL_TRUE;
	kal_uint32 i = 0;
	kal_uint32 j = 0;
	kal_uint32 x =0;
	kal_uint32 y = 0;
	kal_uint32 center_width = 0;
	kal_uint32 center_height = 0;
	kal_uint32 g_channel_sum = 0;
	kal_uint32 g_channel_pixel_count = 0;
	kal_uint32 result = 0;
	kal_uint8* p_addr = NULL;

	if(!custom_ft_util_check_if_camera_mshutter_support()){
		return 0;		/*luminane result = 0*/
	}
	
	switch(first_pixel_bayer)
	{
		case FT_CCT_BAYER_PTN_GR:
			x = 0;
			y = 0;
			break;
		case FT_CCT_BAYER_PTN_R:
			x = 1;
			y = 0;
			break;			
		case FT_CCT_BAYER_PTN_B:
			x = 0;
			y = 1;
			break;
		case FT_CCT_BAYER_PTN_GB:
			x = 1;
			y = 1;
			break;
		default:
			break;
	}

	// 2. get center(1/5) G channel mean
	center_width = width * 0.2;    // div 5
	center_height = height * 0.2;  // div 5
	x += 2*center_width;		   
	y += 2*center_height;
	
	for(j = y ; j < y + center_height; j++)
	{
		if(KAL_TRUE == is_Gr_line)
		{
			i = x;
		}
		else
		{
			i = x + 1;
		}

		for( ; i < x + center_width; i+=2 )
		{	
			if(addr + (j*width) + i > addr + size){
				EXT_ASSERT(KAL_FALSE, 0, 0, 0);
			}					
			p_addr = (kal_uint8 *)(addr + (j*width) + i);
			g_channel_sum += *p_addr;
			g_channel_pixel_count++;
		}
		is_Gr_line = (kal_bool)(!is_Gr_line);
	}	

	result = (g_channel_sum / g_channel_pixel_count);
	if( (g_channel_sum % g_channel_pixel_count) >= (g_channel_pixel_count/2) )
	{
		result+=1;
	}		
	#ifdef __TH_DEBUG__
		sprintf(tmp,"g_channel_sum = %d, g_channel_pixel_count = %d, Lum = %d", g_channel_sum, g_channel_pixel_count, result);
	       //tst_sys_trace(tmp);
	#endif
	return result;
}


kal_uint8 convert_defect_table_err_code(kal_int32 err_code) {
	switch(err_code) {
	case ERR_STATE_UNDER_PROCESSING:
		// two pass calibration scenario, wait for next stage process 
		return FT_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING;
	case ERR_OVER_MAX_SEARCH_NUM:
		// more than max search number defect pixels are found 
		return FT_CCT_ERR_TOO_MANY_DEFECT_PIXEL;
	case ERR_OVER_MAX_DEFECT_NUM:
		// exceed max defect number 
		return FT_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL;
	case ERR_PARA_SIZE_OVER_BLOCK:
		// check max 32 blocks per row 
		return FT_CCT_ERR_INVALID_WIDTH_FACTOR;
	case ERR_PARA_SIZE_OVER_MEM:
		// not enough memory to perform defect table calibration 
		return FT_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM;
	default:
		// unknown fail 
		return FT_CNF_FAIL;
	}
}


void cct_camera_operation_setting(kal_uint8 func_sel, kal_uint16 para)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if ((CAM_AF_KEY == func_sel) && (CAM_AF_RELEASE == para))
	{
		//AF_Recover_Min_Step();
	}
#endif
	//camera_operation_setting(func_sel, para);
}

#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT))) // danbo add for build warning
kal_uint8  ft_cct_af_trigger(void) {
	kal_uint32	timeout;
	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	// trigger AF 
	g_FT_CCT_StateMachine.af_done = KAL_FALSE;
	cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_ONE_TIME);
	// wait til AF is done 
	timeout = 0;
	while( 10000>timeout && !g_FT_CCT_StateMachine.af_done ) {
		timeout += 50;
		kal_sleep_task(50);
	}
	// check result 
	if(g_FT_CCT_StateMachine.af_done) {
		return g_FT_CCT_StateMachine.cnf_return_code;
	}
	else {
		return FT_CCT_ERR_AF_TIMEOUT;
	}
}
#endif

kal_uint8  ft_cct_af_release(void) {

	
	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	// release previous locked focus to hyper focus and reset af lens offset calibration setting 
	cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	#endif
	return FT_CNF_OK;
}

kal_uint8 isp_device_af_calibration(kal_uint32 *pos, kal_uint32 *atf_value)
{
#if (defined(AF_SUPPORT))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

kal_uint8 isp_device_set_af_idx(kal_uint8 idx)
{
#if (defined(AF_SUPPORT))
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CCT enum func~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//danbo note  get Struct size
kal_uint8 ft_cct_get_struct_size(CAL_CCT_GET_SIZE_STRUCT *CctStructSize)
{
	kal_uint8	ret = FT_CNF_OK;
	
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlSizeOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInSizePara, CalCCTOutSizePara;
	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	kal_mem_set(&CCTfeatureCtrlSizeOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInSizePara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutSizePara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	// danbo note get Struct Size
	CalCCTInSizePara.FeatureId = CAL_FEATURE_CCT_OP_GET_NVRAM_SIZE;
	CCTfeatureCtrlSizeOut.pCctFeatureParaOut = &CctDataSizeOut;
	CalCCTOutSizePara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlSizeOut; 
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInSizePara, (void*)&CalCCTOutSizePara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}
	memcpy(CctStructSize, &CctDataSizeOut, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	return ret;
	
}

//FT_CCT_OP_REG_READ:0
kal_uint8  ft_cct_reg_read(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) {

    kal_uint32  RegOutLen = 0;// modify
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_REG_RW_STRUCT CctRegDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctRegDataOut, 0, sizeof(CAL_CCT_REG_RW_STRUCT));
  
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_REG_READ; 
    CctRegDataOut.Type = (CAL_CCT_REG_TYPE_ENUM)req->type;
    CctRegDataOut.RegAddr = req->cmd.reg_read.reg_addr ;
    CCTfeatureCtrlOut.pCctFeatureParaOut = &CctRegDataOut;
    CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;// modify
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
  
    if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)// modify
	{
		ret = FT_CNF_FAIL;
	}	   

	cnf->result.reg_read.value_len =  RegOutLen; 
	cnf->result.reg_read.value = CctRegDataOut.RegData;

	return ret;
}

//FT_CCT_OP_REG_WRITE:1
kal_uint8  ft_cct_reg_write(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) {

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_REG_RW_STRUCT CctRegDataIn;
  
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctRegDataIn, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

  	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_REG_WRITE; 
	CctRegDataIn.Type = (CAL_CCT_REG_TYPE_ENUM)req->type;
	CctRegDataIn.RegAddr = req->cmd.reg_write.reg_addr;// jim added
	CctRegDataIn.RegData = req->cmd.reg_write.value; // jim added
	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctRegDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
  
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

//FT_CCT_OP_PREVIEW_LCD_START : 2

kal_uint8 ft_cct_preview_start(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, const FT_CCT_SENSOR_EX** sensor)
{
	if( NULL != (*sensor=get_sensor_by_id(req->type, req->device_id)) ) 
	{
		if( (NULL == g_FT_CCT_StateMachine.p_preview_sensor) || 
	     	    ((*sensor)->device_id != g_FT_CCT_StateMachine.p_preview_sensor->device_id) ||
		    ((*sensor)->type != g_FT_CCT_StateMachine.p_preview_sensor->type) 
		  ) {
			if( FT_CNF_OK == (cnf->status=ft_cct_preview_on_lcd_enable(*sensor, KAL_TRUE)) ) {
				g_FT_CCT_StateMachine.p_preview_sensor = *sensor;				
			}
		}
		else 
		{
			cnf->status = FT_CCT_ERR_PREVIEW_ALREADY_STARTED;
		}
	}
	else 
	{
		cnf->status = FT_CCT_ERR_INVALID_SENSOR_ID;
	}
	return KAL_TRUE;
}

//FT_CCT_OP_PREVIEW_LCD_STOP:3
kal_uint8 ft_cct_preview_stop(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, const FT_CCT_SENSOR_EX** sensor)
{
	if( NULL != (*sensor=get_sensor_by_id(req->type, req->device_id)) ) {
		if( (NULL != g_FT_CCT_StateMachine.p_preview_sensor) && 
			((*sensor)->device_id == g_FT_CCT_StateMachine.p_preview_sensor->device_id) &&
			((*sensor)->type == g_FT_CCT_StateMachine.p_preview_sensor->type) 
		) {
			if( FT_CNF_OK == (cnf->status=ft_cct_preview_on_lcd_enable(*sensor, KAL_FALSE)) ) {
				g_FT_CCT_StateMachine.p_preview_sensor = NULL;
			}
		}
		else {
			cnf->status = FT_CCT_ERR_PREVIEW_ALREADY_STOPPED;
		}
	}
	else {
		cnf->status = FT_CCT_ERR_INVALID_SENSOR_ID;
	}
	return KAL_TRUE;
}

//FT_CCT_OP_QUERY_SENSOR : 6
kal_uint8  ft_cct_query_sensor(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret) {

	kal_uint32	i;
	kal_uint16	pdu_length = 0;
	FT_CCT_ON_BOARD_SENSOR	*p_on_board_sensors = NULL;

	// get peer buf 
	*pp_peer_buff_ret = construct_peer_buff(sizeof(FT_CCT_ON_BOARD_SENSOR), 0, 0, TD_CTRL);

	// query sensor 
	p_on_board_sensors = (FT_CCT_ON_BOARD_SENSOR *)get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
	kal_mem_set(p_on_board_sensors, 0, sizeof(FT_CCT_ON_BOARD_SENSOR));
	p_on_board_sensors->sensor_count = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor_count;
	for(i=0; i<g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor_count; i++) {
		p_on_board_sensors->sensor[i].type		= g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].type;
		p_on_board_sensors->sensor[i].device_id	= g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].device_id;
		p_on_board_sensors->sensor[i].width		= g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].width;
		p_on_board_sensors->sensor[i].height	= g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].height;
		p_on_board_sensors->sensor[i].start_pixel_bayer_ptn = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].start_pixel_bayer_ptn;
		p_on_board_sensors->sensor[i].grab_x_offset = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].grab_x_offset;
		p_on_board_sensors->sensor[i].grab_y_offset = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[i].grab_y_offset;
	}

	return FT_CNF_OK;
}

// FT_CCT_OP_LOAD_FROM_NVRAM: 7
kal_uint8  ft_cct_load_from_nvram(kal_uint8  *p_nvram_cnf_status, kal_bool  apply_to_reg){
	
	 kal_uint8	 ret = FT_CNF_OK;
	 
	 CAL_FEATURE_CTRL_STRUCT CalCCTInPara;	 
	 
	 kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	 
	 CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_LOAD_FROM_NVRAM; 
	 
	 if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	  {
		ret = FT_CNF_FAIL;
	  }

	   return ret;

}


// FT_CCT_OP_SAVE_TO_NVRAM: 8
kal_uint8  ft_cct_save_to_nvram(kal_uint8  *p_nvram_cnf_status){
	
	kal_uint8	ret1 = FT_CNF_OK , ret2 = FT_CNF_OK;
	
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;	
	
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_UPDATE_PARA_FROM_REG; 
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret1 = FT_CNF_FAIL;
	}  
	 
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SAVE_TO_NVRAM; 
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret2 = FT_CNF_FAIL;
	}  
	 
	ret1 |= ret2;	  

	return ret1;
}

//FT_CCT_OP_AE_ENABLE : 9
kal_uint8  ft_cct_ae_enable(kal_bool	enable) {
	kal_uint8	ret = FT_CNF_OK;
	
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	// 080421 also need to switch AE flag.
	if(enable) { 
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_ENABLE; 
	}
	else {
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_DISABLE; 
	}
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	g_FT_CCT_StateMachine.ae_enable = enable;

	return ret;
}

// FT_CCT_OP_AE_SET_EXPOSE_LEVEL: 11
kal_uint8  ft_cct_ae_set_expose_level(const FT_CCT_REQ *req){
	return FT_CNF_OK;
}

// FT_CCT_OP_AE_GET_EXPOSE_LEVEL:   12
// danbo Note this case not use
kal_uint8  ft_cct_ae_get_expose_level(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	//cnf->result.ae_expose.ec_step = ae_get_stepperev();
	//cnf->result.ae_expose.ec_level = ae_get_ev_level();
	//cnf->result.ae_expose.value = ae_get_expovalue();
	
	cnf->result.ae_expose.ec_step = req->cmd.ae_ec_step.step;
	cnf->result.ae_expose.ec_level = 2;;
	cnf->result.ae_expose.value = 110;
	
	return FT_CNF_OK;
}

// FT_CCT_OP_AE_QUERY_EC_STEP_INFO: 13
kal_uint8  ft_cct_ae_query_ec_step_info(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	cnf->result.ae_ec_step.step = req->cmd.ae_ec_step.step;
	cnf->result.ae_ec_step.total_level = 9;// ae_get_totalevlevel();

	return FT_CNF_OK;
}

// FT_CCT_OP_AE_SET_INIT_SHUTTER: 14
kal_uint8 ft_cct_ae_set_init_shutter(kal_uint16 init_shutter){
	return FT_CNF_OK;
}

// FT_CCT_OP_AE_GET_INIT_SHUTTER: 15
// danbo Note this case not use
kal_uint8  ft_cct_ae_get_init_shutter(kal_uint16 *init_shutter){
	return FT_CNF_OK;
}

//FT_CCT_OP_WB_ACTIVATE_BY_INDEX : 16
kal_uint8  ft_cct_wb_activate_by_index(const FT_CCT_WB_SETTING  activate_index) {

	if( FT_CCT_WB_AUTO == activate_index ) {
		// enable AWB 
		ft_cct_6238_awb_enable(KAL_TRUE);//anthony for CDT flash
	}
	else if( FT_CCT_WB_OFF == activate_index ) {
		// disable AWB 
		ft_cct_6238_awb_enable(KAL_FALSE);//anthony for CDT flash
	}
	else if( FT_CCT_WB_RESET == activate_index ) {
		// disable AWB 
		ft_cct_6238_awb_enable(KAL_FALSE);		
	}
	else if( FT_CCT_WB_MANUAL_1<=(kal_int8)activate_index && FT_CCT_WB_MANUAL_5>= activate_index ) {
	}
	else {
		return FT_CCT_ERR_WB_INVALID_INDEX;
	}

	// update current activated index 
	g_FT_CCT_StateMachine.wb_activated_idx = activate_index;

	return FT_CNF_OK;
}

// FT_CCT_OP_WB_SET_BY_INDEX: 17
kal_uint8  ft_cct_wb_set_by_index(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){
	if( FT_CCT_WB_MANUAL_1> (kal_int8)req->cmd.wb_set.index || FT_CCT_WB_MANUAL_5<req->cmd.wb_set.index ) {
		return FT_CCT_ERR_WB_INVALID_INDEX;
		}
		return FT_CNF_OK;
}

// FT_CCT_OP_WB_QUERY_ALL: 18
// danbo Note this case not use
kal_uint8  ft_cct_wb_query_all(FT_CCT_CNF *cnf, peer_buff_struct **peer_buff_ret){ 

	FT_CCT_WHITE_BALANCE_ALL	WB_All;
	kal_uint16	manualWB[5][4];
	kal_uint16	pdu_length = 0;
	kal_char	*pdu_ptr = NULL;
	kal_uint8	i;

	// get peer buf 
	*peer_buff_ret = construct_peer_buff(sizeof(FT_CCT_WHITE_BALANCE_ALL), 0, 0, TD_CTRL);

	// get activated index 
	cnf->result.wb_query_all.activated_index = g_FT_CCT_StateMachine.wb_activated_idx;

	// get all wb setting 
//	  #if(!defined(MT6238)&&!defined(MT6239)) //anthony for ft
#if (!defined(DRV_ISP_6238_SERIES))	
	awb_read_all_manual_gain(manualWB);
#endif
	for(i=0; i<5; i++) {
		WB_All.wb[i].color_temperature = manualWB[i][0];
		WB_All.wb[i].r_gain = manualWB[i][1];
		WB_All.wb[i].g_gain = manualWB[i][2];
		WB_All.wb[i].b_gain = manualWB[i][3];
	}
	pdu_ptr = get_pdu_ptr(*peer_buff_ret, &pdu_length);
	kal_mem_cpy(pdu_ptr, &WB_All, sizeof(FT_CCT_WHITE_BALANCE_ALL));
	
	return FT_CNF_OK;
}

// FT_CCT_OP_AE_SET_MANUAL_SHUTTER: 19
kal_uint8  ft_cct_ae_set_manual_shutter(const FT_CCT_REQ *req){

	kal_uint8	ret1 = FT_CNF_OK,ret2 = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint16 CctDataIn;
	
	CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT CctAeDataIn;
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	
	if(g_FT_CCT_StateMachine.ae_enable) {
		return FT_CCT_ERR_AE_IS_NOT_DISABLED;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_AE_SET_MANUAL_SHUTTER;
	CctDataIn = req->cmd.ae_manual_shutter;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	 ret1 = FT_CNF_FAIL;
	}

	kal_mem_set(&CctAeDataIn, 0, sizeof(CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_SET_VALUE;

	// danbo add for Patch  Capture  Issue  Temporary  Solution
	CctAeDataIn.AeShutterLine = req->cmd.ae_manual_shutter;
	CctAeDataIn.AeSensorGain = 64;
	CctAeDataIn.AeIspGain = 64;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctAeDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret2 = FT_CNF_FAIL;
	}

	ret1 |= ret2;
	
	  return ret1;
	
}

// FT_CCT_OP_AE_GET_MANUAL_SHUTTER: 20
kal_uint8  ft_cct_ae_get_manual_shutter(FT_CCT_CNF *cnf){

	kal_uint8 ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;
	
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint16  CctDataOut;
	
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_AE_GET_MANUAL_SHUTTER;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
        CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.ae_manual_shutter =  CctDataOut;	

	  return ret;

}

// FT_CCT_OP_GET_CAMERA_PARA_BUF: 21
kal_uint8   ft_cct_get_camera_para_buf(peer_buff_struct **peer_buff_ret){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint16	pdu_length = 0;
	kal_uint32  RegOutLen = 0, RegGetOutLen = 0;
	kal_uint8 para_buf [2864]; //1432
	

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 *pCctDataOut;
	pCctDataOut = para_buf;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
  
    if(g_FT_CCT_StateMachine.ae_enable) {
	    return FT_CCT_ERR_AE_IS_NOT_DISABLED;
    }

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	RegGetOutLen = CctDataSizeOut.CameraParaSize;

	// get peer buf 
	*peer_buff_ret = construct_peer_buff(RegGetOutLen, 0, 0, TD_CTRL);

	pCctDataOut = (void *)get_pdu_ptr(*peer_buff_ret, &pdu_length);

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PARA_BUF; 
        CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CCTfeatureCtrlOut.pCctFeatureParaOut = pCctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}  
	//pCctRegDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;

	  return ret;
}

//FT_CCT_OP_MULTI_SHOT_CAPTURE_EX:22
//kal_uint8  ft_cct_capture_ex(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, kal_bool  bMultiShot) {//bMultiShot not used anymore
kal_uint8  ft_cct_capture_ex(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) {//bMultiShot not used anymore

	/*----------------------------------------------------------------*/
       /* Local Variables                                                */
       /*----------------------------------------------------------------*/
      CAL_SCENARIO_CTRL_STRUCT CalCaptureScenarioPara;
      CAL_ISP_STILL_CAPTURE_STRUCT CalIspCapturePara;
      CAL_MDP_STILL_CAPTURE_STRUCT CalMdpCapturePara;
      CAL_CAMERA_STILL_CAPTURE_STRUCT CalCapturePara;
	  CAL_POSTPROC_STRUCT CalPostProcPara;
      CAL_JPEG_ENC_STRUCT CalJpegEncPara;

	camera_capture_cct_struct	capture_para;
	kal_uint8	ret=FT_CNF_OK;
//#if 0
	// static variables 
	static FT_CCT_CNF				s_last_cnf={0};
	//static kal_uint8				s_sub_sample_mode=0;
	static kal_uint8				s_sub_sample_shift_bits=0;
	static kal_uint32				s_capture_buf_addr=0;
	static kal_uint32				s_capture_buf_size=0;
	//static FT_CCT_CAP_BUF_TYPE		s_capture_buf_type=0;
	//static FT_CCT_BAYER_PATTERN		s_cur_bayer_ptn=0, s_base_bayer_ptn=0;
	static const FT_CCT_SENSOR_EX  	*s_sensor=NULL;
	//static camera_capture_jpeg_struct		s_capture_jpeg_para;
	//static camera_capture_mem_struct		s_capture_rgb888_para;

 	MM_IMAGE_ROTATE_ENUM CctCaptureRotate = MM_IMAGE_ROTATE_0; 

	//kal_uint32	timeout;

	//bMultiShot = KAL_FALSE; // for HAL

	// check if strobe calibration mode is enabled 
	if(g_FT_CCT_StateMachine.strobe_cal_enable) {
		//bMultiShot = KAL_FALSE; //danbo mark for fix  Warning 110401
	}

	// check if continue multishot 
	/*
	if(req->cmd.capture_ex.continue_shot) { // lst continue_shot = false (initailize), than continue_shot = true
		if( 0<s_block_num && s_block_idx<s_block_num && s_last_cnf.result.capture_ex.continue_shot ) {
			// continue unfinished part of last capture 
			return FT_CCT_ERR_NOT_IMPLEMENT_YET;
		}
		else {
			return FT_CCT_ERR_AFRESH_CAPTURE_FIRST;
		}
	}
*/
	// check if the previous multishot capture is not finished 
	if(s_last_cnf.result.capture_ex.continue_shot) {
		// restore bayer ptn, preview, AE and AWB 
		ft_cct_suspend_ae_awb_preview_during_capture(KAL_FALSE); //wrap in HAL
	}

	if (g_cameraType == CAL_CAMERA_SOURCE_MAIN)
	{
		CctCaptureRotate = (MM_IMAGE_ROTATE_ENUM)CCT_CAM_MAIN_SENSOR_ROTATE;
		if (CCT_CAM_MAIN_SENSOR_MIRROR)
			CctCaptureRotate += (MM_IMAGE_ROTATE_ENUM)MM_IMAGE_H_MIRROR;
	}
	else if(g_cameraType == CAL_CAMERA_SOURCE_SUB)
	{
		 CctCaptureRotate = (MM_IMAGE_ROTATE_ENUM)CCT_CAM_SUB_SENSOR_ROTATE;
		if (CCT_CAM_SUB_SENSOR_MIRROR)
			CctCaptureRotate += (MM_IMAGE_ROTATE_ENUM)MM_IMAGE_H_MIRROR;
	}

	// new capture command 
	kal_mem_set(&s_last_cnf, 0, sizeof(s_last_cnf));
	//s_sub_sample_mode = 0;
	//s_sub_sample_shift_bits = 0;
	s_capture_buf_addr = 0;
	s_capture_buf_size = 0;
	s_sensor=NULL;

	// select device 
	if( NULL == (s_sensor=get_sensor_by_id(req->type, req->device_id)) ) {
		return FT_CCT_ERR_INVALID_SENSOR_ID;
	}

	// capture in preview off state is not allowed 
	if( NULL == g_FT_CCT_StateMachine.p_preview_sensor ) {
		return FT_CCT_ERR_PREVIEW_MUST_ENABLE;
	}

	// check if capture format is supported 
	if(!isp_cct_is_capmode_supported(ft_cct_convert_capture_format_enum(req->cmd.capture_ex.output_format))) {
		return FT_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT;
	}

//#else
	// set max shot screen by different mode 
	if( FT_CCT_COMP_CAPTURE_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode || FT_CCT_COMP_CAPTURE_LOWLIGHT_SET==g_FT_CCT_StateMachine.comp_mode ) {
		s_last_cnf.result.capture_ex.left_pos = 0;
		s_last_cnf.result.capture_ex.top_pos = 0;
		s_last_cnf.result.capture_ex.width = s_sensor->width;
		s_last_cnf.result.capture_ex.height = s_sensor->height;
	}
	else if( FT_CCT_COMP_PREVIEW_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode || 
		FT_CCT_COMP_PREVIEW_LOWLIGHT_SET==g_FT_CCT_StateMachine.comp_mode ||
		FT_CCT_COMP_CAPTURE_HALF_SET ==g_FT_CCT_StateMachine.comp_mode
		) {
		s_last_cnf.result.capture_ex.left_pos = 0;
		s_last_cnf.result.capture_ex.top_pos = 0;
		s_last_cnf.result.capture_ex.width = s_sensor->preview_width;
		s_last_cnf.result.capture_ex.height = s_sensor->preview_height;
	}
	
	//HAL setting
	if( FT_CCT_COMP_CAPTURE_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode || FT_CCT_COMP_CAPTURE_HALF_SET ==g_FT_CCT_StateMachine.comp_mode)
	{
		//wait for Jason HAL
		CAL_CCT_SCENARIO_PARA_STRUCT CctDataIn ;
		CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
		CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	
		kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA;

		g_CctPreviewModeCapture = KAL_FALSE;
		CctDataIn.CctMetaMode = g_CctMetaMode;
		CctDataIn.CctPreviewModeCapture = g_CctPreviewModeCapture;
		CctDataIn.CctRawDataCapture = g_CctRawDataCapture;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}	
		//CctPreviewModeCapture = KAL_FALSE;
	}
	else if(FT_CCT_COMP_PREVIEW_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode)
	{
		//wait for Jason HAL
		CAL_CCT_SCENARIO_PARA_STRUCT CctDataIn ;
		CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
		CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	
		kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA;
	
		g_CctPreviewModeCapture = KAL_TRUE;
		CctDataIn.CctMetaMode = g_CctMetaMode;
		CctDataIn.CctPreviewModeCapture = g_CctPreviewModeCapture;
		CctDataIn.CctRawDataCapture = g_CctRawDataCapture;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}	
		//CctPreviewModeCapture = KAL_TRUE;
	}
	
	// check if width or height must be multiple of 2 
	if( 0 != (s_last_cnf.result.capture_ex.width%2) ) {
		s_last_cnf.result.capture_ex.width--;
	}
	if( 0 != (s_last_cnf.result.capture_ex.height%2) ) {
		s_last_cnf.result.capture_ex.height--;
	}
//#endif
#if 1
	// check sub sample mode 
	switch(req->cmd.capture_ex.sub_sample) {
	case 8:
		//s_sub_sample_mode = CAMERA_SUB_SAMPLE_1_8;
		s_sub_sample_shift_bits = 3;
		break;
	case 4:
		//s_sub_sample_mode = CAMERA_SUB_SAMPLE_1_4;
		s_sub_sample_shift_bits = 2;
		break;
	case 2:
		//s_sub_sample_mode = CAMERA_SUB_SAMPLE_1_2;
		s_sub_sample_shift_bits = 1;
		break;
	case 1:
	default:
		//s_sub_sample_mode = CAMERA_SUB_SAMPLE_1_1;
		s_sub_sample_shift_bits = 0;
		break;
	}
#endif
    ft_cct_suspend_ae_awb_preview_during_capture(KAL_TRUE); // 6236, wait for HAL
	s_last_cnf.result.capture_ex.sub_sample = req->cmd.capture_ex.sub_sample;

	// arrange output format and capture buffer type and size 
	s_last_cnf.result.capture_ex.output_format = req->cmd.capture_ex.output_format;
	switch(s_last_cnf.result.capture_ex.output_format) {
		/* unsupport format
	case OUTPUT_RAW_8BITS:
	case OUTPUT_RAW_10BITS:
	case OUTPUT_YUV:
		// capture to Internal SRAM 
		// Danny Huang 0506 add for raw data shading table buffer
#if defined(DRV_FEATURE__MM_INTMEM_IF)
    // [6236_mm_intmem] all 96KB SYSRAM used by camera raw capture to internal memory...
#if(defined(DRV_ISP_MT6236_HW_SUPPORT))//Dana for 6236
#if 0
    g_FT_CCT_StateMachine.mem_capture_int_buf_addr = 0x40000000;
    g_FT_CCT_StateMachine.mem_capture_int_buf_size = 0x18000;
#endif     
     #if 0 // HAL remove
    ASSERT(KAL_TRUE == mm_intmem_get(MM_SCEN__MEMORY_POOL, 
                                     MM_INTMEM_SEG__POOL_0, 
                                     &g_FT_CCT_StateMachine.mem_capture_int_buf_addr, 
                                     &g_FT_CCT_StateMachine.mem_capture_int_buf_size));
    g_memory_pool_on = KAL_TRUE;
    #endif
    
    // replace int buf as ext buf
    //g_FT_CCT_StateMachine.mem_capture_int_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr;
    //g_FT_CCT_StateMachine.mem_capture_int_buf_size = g_FT_CCT_StateMachine.mem_capture_ext_buf_size;
#else   // #if defined(MT6236) || defined(MT6236B)
#error "currently undefined!"
#endif  // #if defined(MT6236) || defined(MT6236B)
#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
		//s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_int_buf_addr+(MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE);
		//s_capture_buf_size = g_FT_CCT_StateMachine.mem_capture_int_buf_size-(MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE);
		s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_int_buf_addr+(MAX_ISP_MEM_SIZE);
		s_capture_buf_size = g_FT_CCT_StateMachine.mem_capture_int_buf_size-(MAX_ISP_MEM_SIZE);
		break;
		*/
	case OUTPUT_EXT_RAW_8BITS:
	case OUTPUT_EXT_RAW_10BITS:	
	//case OUTPUT_EXT_YUV:
		// capture to External SRAM 
		//s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr+(MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE);
		//s_capture_buf_size = g_FT_CCT_StateMachine.mem_capture_ext_buf_size-(MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE);
		s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr/*+(MAX_ISP_MEM_SIZE)*/;
		s_capture_buf_size = g_FT_CCT_StateMachine.mem_capture_ext_buf_size/*-(MAX_ISP_MEM_SIZE)*/;
		break;
		
	case OUTPUT_JPEG:
#if 0
#if defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
#endif
		// capture to External SRAM 
		s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr;
		s_capture_buf_size = g_FT_CCT_StateMachine.mem_capture_ext_buf_size;
		// JPEG cannot perform multishot capture, disable it 
		
		//bMultiShot = KAL_FALSE;	//danbo mark for fix  Warning 110401
		
		break;
		/*
	case OUTPUT_RGB888:
//#if (defined(MT6228)||defined(MT6229)||defined(MT6230))
#if 0
		// capture to External SRAM, divide into two equal buffers (dest buffer and imgdma buffer)
		s_capture_buf_addr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr;
		s_capture_buf_size = (g_FT_CCT_StateMachine.mem_capture_ext_buf_size>>1);
		break;
#else
		// non MT6228/MT6229 series ISP not support image clip 
		// cannot perform multishot capture, disable it        
		bMultiShot = KAL_FALSE;
		return FT_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT;
#endif
*/
	default:
		return FT_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT;
	}

	// calculate output buffer width and height 
	if( OUTPUT_RAW_8BITS==s_last_cnf.result.capture_ex.output_format || OUTPUT_EXT_RAW_8BITS==s_last_cnf.result.capture_ex.output_format ) {
		// assign output width and height 
		s_last_cnf.result.capture_ex.output_width = s_last_cnf.result.capture_ex.width;
		s_last_cnf.result.capture_ex.output_height = s_last_cnf.result.capture_ex.height;
		// OUTPUT_RAW_8BITS (Bayer) , each pixel contains 1 byte 
		s_capture_buf_size = (s_last_cnf.result.capture_ex.output_width)*(s_last_cnf.result.capture_ex.output_height);
	}
	else if( OUTPUT_RAW_10BITS==s_last_cnf.result.capture_ex.output_format || OUTPUT_EXT_RAW_10BITS==s_last_cnf.result.capture_ex.output_format ) {
		// assign output width and height 
		s_last_cnf.result.capture_ex.output_width = s_last_cnf.result.capture_ex.width;
		s_last_cnf.result.capture_ex.output_height = s_last_cnf.result.capture_ex.height;
		// OUTPUT_RAW_10BITS (Bayer) , each pixel contains 2 bytes 
		s_capture_buf_size = (s_last_cnf.result.capture_ex.output_width)*(s_last_cnf.result.capture_ex.output_height)*2;
	}
	else {
		// re-arrange to the minimal width and height according to sub sample rate 
		
		if( 0 == (s_last_cnf.result.capture_ex.width>>s_sub_sample_shift_bits) ) {
			s_last_cnf.result.capture_ex.width = (1<<s_sub_sample_shift_bits);
		}
		if( 0 == (s_last_cnf.result.capture_ex.height>>s_sub_sample_shift_bits) ) {
			s_last_cnf.result.capture_ex.height = (1<<s_sub_sample_shift_bits);
		}
		// calculate output width and height according to sub sample rate 
		s_last_cnf.result.capture_ex.output_width = (s_last_cnf.result.capture_ex.width>>s_sub_sample_shift_bits);
		s_last_cnf.result.capture_ex.output_height = (s_last_cnf.result.capture_ex.height>>s_sub_sample_shift_bits);
		
		// calculate capture size 
		s_capture_buf_size = (s_last_cnf.result.capture_ex.output_width)*(s_last_cnf.result.capture_ex.output_height);
		
	}

	//if(!bMultiShot) {
		// JPEG bypass memory check 
		if( OUTPUT_JPEG != req->cmd.capture_ex.output_format ) {
			s_capture_buf_size = (s_last_cnf.result.capture_ex.output_width)*(s_last_cnf.result.capture_ex.output_height);
			// check if memory is enough for single shot capture 
			//if( s_capture_buf_size < capture_size ) {
				// the sensor shot screen is larger than the available capture memory, you should use multi-shot instead 
				//return FT_CCT_ERR_TGT_NO_MEM_FOR_SINGLE_SHOT;
		}
    	g_FT_CCT_StateMachine.mem_capture_ext_buf_size = s_capture_buf_size;
		/*
		s_block_height = s_last_cnf.result.capture_ex.height;
		s_last_block_height = 0;
		s_block_num = 1;
	}
	else {
		// calculate max block height 
		s_block_height = s_capture_buf_size/(capture_size/s_last_cnf.result.capture_ex.output_height);
		// adjust block height to multiple of 2 to prevent changing left-top start pixel's bayer pattern 
		s_block_height = ((s_block_height>>1)<<1);
		if( 0 == s_block_height ) {
			// the available capture memory is too few to capture even one line 
			return FT_CCT_ERR_TGT_NO_MEM_FOR_MULTI_SHOT;
		}
		// For OUTPUT_YUV (YCbCr) or OUTPUT_RGB888 output format, restore to the original height by sub sample rate 
		if( OUTPUT_YUV==s_last_cnf.result.capture_ex.output_format || OUTPUT_RGB888==s_last_cnf.result.capture_ex.output_format ) {
			s_block_height <<= s_sub_sample_shift_bits;
		}
		// calculate num of multi-shot blocks 
		s_block_num = (s_last_cnf.result.capture_ex.height)/s_block_height;
		s_last_block_height = (s_last_cnf.result.capture_ex.height)%s_block_height;
		if( 0 != s_last_block_height ) {
			s_block_num++;
		}
		
	}
*/
	// suspend AE, AWB, preview before capture 
	//ft_cct_suspend_ae_awb_preview_during_capture(KAL_TRUE);//for 6236
/* remove multiple capture for HAL
multishot_capture:

	// calculate grab left_pos 
	capture_para.grab_start_x = (kal_int16)s_last_cnf.result.capture_ex.left_pos;

	// calculate grab_top_pos 
	capture_para.grab_start_y = (kal_int16)(s_last_cnf.result.capture_ex.top_pos + (s_block_idx*s_block_height));

	// calculate grab width 
	capture_para.grab_width = (kal_int16)s_last_cnf.result.capture_ex.width; 

	// calculate grab_height 
	if( (s_block_idx+1)==s_block_num && 0!=s_last_block_height ) {
		// if last block exist 
		capture_para.grab_height = (kal_int16)s_last_block_height;
	}
	else {
		//normal block 
		capture_para.grab_height = (kal_int16)s_block_height;
	}


	// calculate block size by different output format 
	if( OUTPUT_RAW_8BITS==s_last_cnf.result.capture_ex.output_format || OUTPUT_EXT_RAW_8BITS==s_last_cnf.result.capture_ex.output_format ) {
		// OUTPUT_RAW_8BITS (Bayer) , each pixel contains 1 byte 
		//block_size = ((kal_uint16)capture_para.grab_width)*((kal_uint16)capture_para.grab_height);
		block_size = ((kal_uint16)s_last_cnf.result.capture_ex.width)*((kal_uint16) s_last_cnf.result.capture_ex.height);
	}
	else if( OUTPUT_RAW_10BITS==s_last_cnf.result.capture_ex.output_format || OUTPUT_EXT_RAW_10BITS==s_last_cnf.result.capture_ex.output_format ) {
		// OUTPUT_RAW_10BITS (Bayer) , each pixel contains 2 bytes 
		//block_size = ((kal_uint16)capture_para.grab_width)*((kal_uint16)capture_para.grab_height)*2;
		block_size = ((kal_uint16)s_last_cnf.result.capture_ex.width)*((kal_uint16)s_last_cnf.result.capture_ex.height)*2;
	}
	else {
		return FT_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT;
	}

*/
	// modify final grab start position, and final grab width & height by different output format 
	ft_cct_set_final_grab_xy_width_height(&capture_para.grab_start_x, &capture_para.grab_start_y, &capture_para.grab_width, &capture_para.grab_height, s_last_cnf.result.capture_ex.output_format);

	//if( s_block_idx == 0 ) {
		// send back the 1st left-top start pixel pattern 
		s_last_cnf.result.capture_ex.bayer_ptn = s_sensor->start_pixel_bayer_ptn;
	//}

	// check if strobe calibration mode is enabled 
	/*
	if(g_FT_CCT_StateMachine.strobe_cal_enable) {
		// strobe calibration capture 
		capture_para.flash_mode = CAM_FLASH_ON;
		capture_para.curr_lum = g_FT_CCT_StateMachine.strobe_cal_para.curr_lum;
		capture_para.target_lum = g_FT_CCT_StateMachine.strobe_cal_para.target_lum;
	}
	else {
		// normal capture 
		capture_para.flash_mode = CAM_FLASH_OFF;
		capture_para.curr_lum = 0xFFFF;
		capture_para.target_lum = 0xFFFF;
	}
*/
//stop cam first

		//danbo mark
		//ft_cct_cam_capture_still_image_stop();
	
//capture para prepare
		//kal_mem_set(&s_capture_jpeg_para, 0, sizeof(s_capture_jpeg_para));  //reset : 
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
#endif	
		//HAL para
		CalMdpCapturePara.MainImageDataFormat = MM_IMAGE_FORMAT_JPEG;
	    CalMdpCapturePara.MainImageRotAngle = CctCaptureRotate;//MM_IMAGE_ROTATE_270;
		CalMdpCapturePara.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV422;
			
		//CalMdpCapturePara.MainImageWidth = s_last_cnf.result.capture_ex.width;
		//CalMdpCapturePara.MainImageHeight = s_last_cnf.result.capture_ex.height;
		CalMdpCapturePara.MainImageWidth = s_last_cnf.result.capture_ex.output_width ;
		CalMdpCapturePara.MainImageHeight = s_last_cnf.result.capture_ex.output_height;

		s_last_cnf.result.capture_ex.output_width = (s_last_cnf.result.capture_ex.width>>s_sub_sample_shift_bits);
		s_last_cnf.result.capture_ex.output_height = (s_last_cnf.result.capture_ex.height>>s_sub_sample_shift_bits);
		//CalMdpCapturePara.MainImageBuffAddr = g_FT_CCT_StateMachine.mem_capture_ext_buf_addr;
		//CalMdpCapturePara.MainImageBuffSize = g_FT_CCT_StateMachine.mem_capture_ext_buf_size;

		CalMdpCapturePara.MainImageBuffAddr = s_capture_buf_addr;
		CalMdpCapturePara.MainImageBuffSize = s_capture_buf_size;
		CalMdpCapturePara.MainImageWorkingBuffAddr = s_capture_buf_addr;
		CalMdpCapturePara.MainImageWorkingBuffSize = s_capture_buf_size;
		CalMdpCapturePara.OverlayEnable = KAL_FALSE;
		
		//CalMdpCapturePara.OverlayPaletteAddr = cam_context_p->overlay_palette_addr;
		//CalMdpCapturePara.OverlayPaletteSize = cam_context_p->overlay_palette_size;
		//CalMdpCapturePara.OverlayColorDepth = cam_context_p->overlay_color_depth;
		//CalMdpCapturePara.OverlayFrameSourceKey = cam_context_p->overlay_frame_source_key;
		//CalMdpCapturePara.OverlayFrameWidth = cam_context_p->overlay_frame_width;
		//CalMdpCapturePara.OverlayFrameHeight = cam_context_p->overlay_frame_height;
		//CalMdpCapturePara.OverlayFrameBuffAddr = cam_context_p->overlay_frame_buffer_address;
		//CalMdpCapturePara.OverlayPaletteMode = IMG_PALETTE_MODE_8BPP;
		CalMdpCapturePara.QuickViewImageEnable = KAL_FALSE;//cam_context_p->quickview_output;
#if 0 // not support quick view
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		CalMdpCapturePara.ThumbnailImageEnable = KAL_FALSE;

#if 0 // not support thumbnail
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

		CalIspCapturePara.BinningMode = sbCdtBinningMode;
		CalIspCapturePara.MultishotInfo = MULTISHOT_FALSE;
		//CalIspCapturePara.ExpoBracketLevel = cam_context_p->expo_bracket_level;
		CalIspCapturePara.RawCaptureEnable = KAL_TRUE;
		//CalIspCapturePara.RawImageBuffAddr =  g_FT_CCT_StateMachine.mem_capture_ext_buf_addr;
		//CalIspCapturePara.RawImageBuffSize = g_FT_CCT_StateMachine.mem_capture_ext_buf_size;
		CalIspCapturePara.RawImageBuffAddr =  s_capture_buf_addr;
		CalIspCapturePara.RawImageBuffSize = s_capture_buf_size;
		CalIspCapturePara.StillCaptureMode = CAM_STILL_CAPTURE_NORMAL;   

		CalJpegEncPara.JpegEncQuality = (JPEG_ENCODE_QUALITTY_ENUM)JPEG_ENCODE_QUALITY_GOOD;
		//CalJpegEncPara.JpegSamplingFormat = JPEG_SAMPLING_FORMAT_YUV420;
		CalJpegEncPara.JpegSamplingFormat = MM_IMAGE_FORMAT_YUV422;
		CalJpegEncPara.JpegBuffAddr = CalMdpCapturePara.MainImageBuffAddr;
		CalJpegEncPara.JpegBuffSize = CalMdpCapturePara.MainImageBuffSize;
		CalJpegEncPara.pDstFileHandle = NULL;

		CalCapturePara.ExtmemStartAddress = g_FT_CCT_StateMachine.mem_capture_ext_exif_addr;
    	CalCapturePara.ExtmemSize = g_FT_CCT_StateMachine.mem_capture_ext_exif_size;
	// start capture 
	if( OUTPUT_JPEG == s_last_cnf.result.capture_ex.output_format ) {
		// jpeg subsample 
		//capture_para.grab_width = (capture_para.grab_width>>s_sub_sample_shift_bits);
		//capture_para.grab_height = (capture_para.grab_height>>s_sub_sample_shift_bits);
		// setup jpeg capture parameters 
		
		//wait for Jason HAL
		CAL_CCT_SCENARIO_PARA_STRUCT CctDataIn ;
		CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
		CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

		CAL_CCT_CAP_OUTPUT_FORMAT CctRawDataIn;
		kal_bool CctPreviewCaptureFlag = KAL_FALSE;
		
		kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));
		kal_mem_set(&CctRawDataIn, 0, sizeof(CAL_CCT_CAP_OUTPUT_FORMAT));

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA;
	
		//g_CctPreviewModeCapture = KAL_FALSE;
		g_CctRawDataCapture = KAL_FALSE;
		CctDataIn.CctMetaMode = g_CctMetaMode;
		CctDataIn.CctPreviewModeCapture = g_CctPreviewModeCapture;
		CctDataIn.CctRawDataCapture = g_CctRawDataCapture;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}	
		//CctRawDataCapture = KAL_FALSE;

		CalPostProcPara.PostProcMode = 0; // danbo add test

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_RAWBIT;	
		CctRawDataIn = OUTPUT_EXT_RAW_8BITS;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctRawDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_PREVIEW_SIZE;		
		if ( FT_CCT_COMP_PREVIEW_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode )
		{
			CctPreviewCaptureFlag = KAL_TRUE;
		}
		else
		{
			CctPreviewCaptureFlag = KAL_FALSE;
		}
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctPreviewCaptureFlag;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;				
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		CalCapturePara.pMdpPara=&CalMdpCapturePara;
		CalCapturePara.pIspPara=&CalIspCapturePara;
		CalCapturePara.pJpegEncPara=&CalJpegEncPara;
		CalCapturePara.pPostProcPara=&CalPostProcPara;

		CalCaptureScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
		CalCaptureScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_START;
		CalCaptureScenarioPara.ScenarioCtrlParaLen=sizeof(CAL_CAMERA_STILL_CAPTURE_STRUCT);
		CalCaptureScenarioPara.pScenarioCtrlPara=&CalCapturePara;

		CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, (void *) &CalCapturePara, 0, 0);

		#if 0 // HAL yuv sensor build error
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
		//s_capture_jpeg_para.cam_capture_jpeg_cb = ft_cct_isp_hisr_capture_jpeg_result_V2; //HAL wait for Jason
#if 0 // HAL internal unsupport
/* under construction !*/
/* under construction !*/
#endif
#if 0 // HAL yuv sensor build error
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

//#endif
		// start capture 
		g_FT_CCT_StateMachine.capture_jpeg_state = CAPTURE_JPEG_PROCESS;
// 080317		block_size = camera_capture_jpeg_process(&s_capture_jpeg_para);
#ifdef __MTK_TARGET__
        //block_size = camera_capture_jpeg_process_cct(&s_capture_jpeg_para);   //HAL wait for Jason
#endif		
//#if (defined(DRV_ISP_6238_SERIES))
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
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
		#endif
		// stop capture process 
		
		//ft_stop_camera_capture_process(CAM_NORMAL_STOP);

		//cct_cam_capture_callback;
		//cam_send_event_ind(CAM_EVT_CAPTURE, (kal_uint8)MED_RES_OK);

		ft_cct_cam_capture_still_image_stop();
		
		g_FT_CCT_StateMachine.mem_capture_cur_buf_addr = Cct_jpeg_Address;
		g_FT_CCT_StateMachine.mem_capture_cur_buf_size = Cct_Jpeg_Size;
		s_last_cnf.result.capture_ex.capture_size = g_FT_CCT_StateMachine.mem_capture_cur_buf_size;
		
		//block_size = jpeg_capture_wrapper_get_encoded_length(); //HAL see if wrap in CAL (Jason)
//			g_FT_CCT_StateMachine.capture_jpeg_state = CAPTURE_JPEG_IDLE;	


	}
	else {
		// normal capture 
		//capture_para.sub_sample_mode = s_sub_sample_mode;
		//capture_para.isp_debug_buffer = s_capture_buf_addr;
		// convert output format 
		//capture_para.debug_mode = ft_cct_convert_capture_format_enum(s_last_cnf.result.capture_ex.output_format);
		// raw capture 

		//wait for Jason HAL
		CAL_CCT_SCENARIO_PARA_STRUCT CctDataIn , CctDataOut;
		CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
		CAL_FEATURE_CTRL_STRUCT CalCCTInPara,CalCCTOutPara;
		
		CAL_CCT_CAP_OUTPUT_FORMAT CctRawDataIn;
		kal_bool CctPreviewCaptureFlag = KAL_FALSE;
		CAL_CCT_CAPTURE_EX_STRUCT CctGetRawSizeDataOut;
		
		kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
		kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));
		kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_SCENARIO_PARA_STRUCT));
		kal_mem_set(&CctRawDataIn, 0, sizeof(CAL_CCT_CAP_OUTPUT_FORMAT));
		kal_mem_set(&CctGetRawSizeDataOut, 0, sizeof(CAL_CCT_CAPTURE_EX_STRUCT));

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA;
	
		g_CctRawDataCapture = KAL_TRUE;
		CctDataIn.CctMetaMode = g_CctMetaMode;
		CctDataIn.CctPreviewModeCapture = g_CctPreviewModeCapture;
		CctDataIn.CctRawDataCapture = g_CctRawDataCapture;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}	
		//CctRawDataCapture = KAL_TRUE;
		
		CalIspCapturePara.RawCaptureEnable = KAL_TRUE;

		CalPostProcPara.PostProcMode = 0; // danbo add test

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_RAWBIT;	
		CctRawDataIn = OUTPUT_EXT_RAW_8BITS;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctRawDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_PREVIEW_SIZE;		
		if ( FT_CCT_COMP_PREVIEW_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode )
		{
			CctPreviewCaptureFlag = KAL_TRUE;
		}
		else
		{
			CctPreviewCaptureFlag = KAL_FALSE;
		}
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctPreviewCaptureFlag;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;				
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		CalCapturePara.pMdpPara=&CalMdpCapturePara;
		CalCapturePara.pIspPara=&CalIspCapturePara;
		CalCapturePara.pJpegEncPara=&CalJpegEncPara;
		CalCapturePara.pPostProcPara=&CalPostProcPara;

		CalCaptureScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
		CalCaptureScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_START;
		CalCaptureScenarioPara.ScenarioCtrlParaLen=sizeof(CAL_CAMERA_STILL_CAPTURE_STRUCT);
		CalCaptureScenarioPara.pScenarioCtrlPara=&CalCapturePara;

		CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, (void *) &CalCapturePara, 0, 0);

		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_RAW_CAPTURE_SIZE;		

		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctGetRawSizeDataOut;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;				
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		s_last_cnf.result.capture.output_width = CctGetRawSizeDataOut.Width;
		s_last_cnf.result.capture.output_height = CctGetRawSizeDataOut.Height;
		s_last_cnf.result.capture.width = CctGetRawSizeDataOut.Width;
		s_last_cnf.result.capture.height = CctGetRawSizeDataOut.Height;
		s_capture_buf_size = s_last_cnf.result.capture_ex.output_width*s_last_cnf.result.capture_ex.output_height;

		ft_cct_cam_capture_still_image_stop();

		//camera_capture_cct(&capture_para); //HAL
		
		// assign capture size 
		g_FT_CCT_StateMachine.mem_capture_cur_buf_addr = s_capture_buf_addr;
		//g_FT_CCT_StateMachine.mem_capture_cur_buf_size = block_size;
		g_FT_CCT_StateMachine.mem_capture_cur_buf_size = s_capture_buf_size;
		s_last_cnf.result.capture_ex.capture_size = g_FT_CCT_StateMachine.mem_capture_cur_buf_size;
		//s_last_cnf.result.capture.capture_size = g_FT_CCT_StateMachine.mem_capture_cur_buf_size;
	}

	// recover sensor exposure setting
	//recover_sensor_setting();

	// capture/strobe calibration fail 
	if( FT_CNF_OK != ret ) {
		goto finish;
	}
	

	// step to next multishot block 
	//s_block_idx++;

	// check if multishot is finished 
	//if( s_block_idx >= s_block_num ) {
	#if 0 // Mshutter support
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
		//---------------------------------------------------------------------------
		goto finish;
	//}
	/*
	else {
		// indicate pc side continue shot 
		g_b_multishot = KAL_TRUE;
		s_last_cnf.result.capture_ex.continue_shot = KAL_TRUE;
		goto end;
	}
*/
finish:
	// finish, indicate pc side do not continue to shot 
	s_last_cnf.result.capture_ex.continue_shot = KAL_FALSE;
	//s_block_idx = 0;
	//s_block_num = 0;
	if(s_last_cnf.result.capture_ex.output_format == OUTPUT_RAW_8BITS || 
	s_last_cnf.result.capture_ex.output_format == OUTPUT_RAW_10BITS ||
	s_last_cnf.result.capture_ex.output_format == OUTPUT_YUV) 
	{
	#if 0 // HAL remove
	#if defined(DRV_FEATURE__MM_INTMEM_IF)
/* under construction !*/
/* under construction !*/
	#endif  // #if defined(DRV_FEATURE__MM_INTMEM_IF)
	#endif
	}
	// resume AE, AWB, preview before capture 
	ft_cct_suspend_ae_awb_preview_during_capture(KAL_FALSE); //HAL wait for Jason

	ft_cct_6238_isp_set_binning_mode(KAL_FALSE);
//end:
	cnf->result = s_last_cnf.result;
	//#endif
	return ret;
}

// FT_CCT_OP_GET_CAPTURE_BUF: 24
kal_uint8  ft_cct_get_capture_buf(const FT_CCT_REQ *req, FT_CCT_CNF *cnf,peer_buff_struct **peer_buff_ret){

	kal_uint16	pdu_length = 0;
	kal_char	*pdu_ptr = NULL;
	kal_uint32	request_length;

	request_length = req->cmd.get_capture_buf.length;

	// check request offset 
	if( req->cmd.get_capture_buf.offset >= g_FT_CCT_StateMachine.mem_capture_cur_buf_size ) {
		return FT_CNF_FAIL;
     }

	// check request length 
	if( (req->cmd.get_capture_buf.offset+request_length) > g_FT_CCT_StateMachine.mem_capture_cur_buf_size ) {
		request_length = g_FT_CCT_StateMachine.mem_capture_cur_buf_size-req->cmd.get_capture_buf.offset;
	}

	// narrow down length to the max peer buffer size 
	if( FT_FAT_MAX_FRAME_SIZE < request_length ) {
		request_length = FT_FAT_MAX_FRAME_SIZE;
	}
	
	// get peer buf 
	*peer_buff_ret = (peer_buff_struct *)construct_peer_buff((kal_uint16)request_length, 0, 0, TD_CTRL);
	pdu_ptr = get_pdu_ptr(*peer_buff_ret, &pdu_length);
	
	// copy data 
	kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_FT_CCT_StateMachine.mem_capture_cur_buf_addr+req->cmd.get_capture_buf.offset, pdu_length);

	return FT_CNF_OK;
}

// FT_CCT_OP_RESUME_AE_AWB_PREVIEW_FROM_UNFINISHED_CAPTURE: 25
kal_uint8  ft_cct_suspend_ae_awb_preview_during_capture(kal_bool  bSuspend){

	static kal_bool					s_bIsSuspend=KAL_FALSE;
	static const FT_CCT_SENSOR_EX	*s_CurrentPreviewSensor;
	static kal_bool					s_AE_Enabled;
	static FT_CCT_WB_SETTING		s_WB_ActivatedIndex;
	kal_uint8	ret = FT_CNF_OK;
	
	if( !s_bIsSuspend && bSuspend ) {
		
		// save current setting 
		s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;
		s_AE_Enabled = g_FT_CCT_StateMachine.ae_enable;
		s_WB_ActivatedIndex = g_FT_CCT_StateMachine.wb_activated_idx;

		// if AE is enabled, disable it before capture 
		if(g_FT_CCT_StateMachine.ae_enable) {
			ft_cct_ae_enable(KAL_FALSE);
		}
	
		// if AWB is enabled, disable it before capture 
		if( FT_CCT_WB_OFF != g_FT_CCT_StateMachine.wb_activated_idx ) {
			ft_cct_wb_activate_by_index(FT_CCT_WB_OFF);
		}

		// release previous locked focus to hyper focus and reset af lens offset calibration setting 
		if( isp_cct_is_cct_af_support() && KAL_TRUE==g_FT_CCT_StateMachine.af_on_off ) {
			ft_cct_af_release();
		}
	
		// if preview on lcd is enabled, stop it before capture 
		if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
			// trigger AF 
		#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT))) // danbo add for build warning
			if( isp_cct_is_cct_af_support() && KAL_TRUE==g_FT_CCT_StateMachine.af_on_off ) {
				ret = ft_cct_af_trigger();
			}
		#endif
			// disabled preview 
			ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
			g_FT_CCT_StateMachine.p_preview_sensor = NULL;
		}

		// raising suspend flag 
		s_bIsSuspend = KAL_TRUE;
	}
	else if( s_bIsSuspend && !bSuspend ) {
	
		// if preview on lcd was enabled, resume it 
		if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
			g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
			ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
		}

		// release previous locked focus to hyper focus and reset af lens offset calibration setting 
		if( isp_cct_is_cct_af_support() && KAL_TRUE==g_FT_CCT_StateMachine.af_on_off ) {
			ft_cct_af_release();
		}
	
		// if AE was enabled, enable it 
		if(s_AE_Enabled) {
			ft_cct_ae_enable(KAL_TRUE);
		}

		// if AWB was enabled, disable it 
		if( FT_CCT_WB_OFF != s_WB_ActivatedIndex ) {
			ft_cct_wb_activate_by_index(s_WB_ActivatedIndex);
		}
	
		// disable suspend flag 
		s_bIsSuspend = KAL_FALSE;
	}  

	  return ret;
}

// CCT_OP_GET_BANDING_FACTOR: 26
kal_uint8  ft_cct_get_banding_factor(FT_CCT_CNF *cnf){

	//kal_uint8	baseshutter_60hz, baseshutter_50hz;

	cnf->result.get_banding_factor.baseshutter_60hz = 1;//baseshutter_60hz;
	cnf->result.get_banding_factor.baseshutter_50hz = 1;//baseshutter_50hz;

	return FT_CNF_OK;

}

// FT_CCT_OP_GET_SENSOR_PREGAIN: 27
kal_uint8  ft_cct_get_sensor_pregain(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_SENSOR_ITEM_INFO_STRUCT CctDataIn, CctDataOut;
	  
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));
	  
    kal_mem_set(&cnf->result.get_sensor_pregain, 0, sizeof(cnf->result.get_sensor_pregain));

    if( -1 == g_FT_CCT_StateMachine.sensor_eng_group_idx ) {
	    return FT_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST;
    }

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_SENSOR_PREGAIN; 
	CctDataIn.GroupIdx = g_FT_CCT_StateMachine.sensor_eng_group_idx;

	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_R ) {

	  	CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_R;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
		cnf->result.get_sensor_pregain.pregain_r.value = CctDataOut.ItemValue;
		cnf->result.get_sensor_pregain.pregain_r.min = CctDataOut.Min;
		cnf->result.get_sensor_pregain.pregain_r.max = CctDataOut.Max;
		cnf->result.get_sensor_pregain.pregain_r.exist = KAL_TRUE;
		cnf->result.reg_read.value_len = RegOutLen;
	}

	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gr ) {

	  	CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gr;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
		cnf->result.get_sensor_pregain.pregain_gr.value = CctDataOut.ItemValue;
		cnf->result.get_sensor_pregain.pregain_gr.min = CctDataOut.Min;
		cnf->result.get_sensor_pregain.pregain_gr.max = CctDataOut.Max;
		cnf->result.get_sensor_pregain.pregain_gr.exist = KAL_TRUE;
		cnf->result.reg_read.value_len = RegOutLen;
	}

	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gb ) {

	  	CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gb;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
		cnf->result.get_sensor_pregain.pregain_gb.value = CctDataOut.ItemValue;
		cnf->result.get_sensor_pregain.pregain_gb.min = CctDataOut.Min;
		cnf->result.get_sensor_pregain.pregain_gb.max = CctDataOut.Max;
		cnf->result.get_sensor_pregain.pregain_gb.exist = KAL_TRUE;
		cnf->result.reg_read.value_len = RegOutLen;
	}

	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_B ) {

	  	CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_B;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}

		//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
		cnf->result.get_sensor_pregain.pregain_b.value = CctDataOut.ItemValue;
		cnf->result.get_sensor_pregain.pregain_b.min = CctDataOut.Min;
		cnf->result.get_sensor_pregain.pregain_b.max = CctDataOut.Max;
		cnf->result.get_sensor_pregain.pregain_b.exist = KAL_TRUE;		  
		cnf->result.reg_read.value_len = RegOutLen;
	}

	return ret;

}

// FT_CCT_OP_SET_SENSOR_PREGAIN: 28
kal_uint8  ft_cct_set_sensor_pregain(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
        CAL_CCT_SENSOR_ITEM_INFO_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_SENSOR_ITEM_INFO_STRUCT));

	if( -1 == g_FT_CCT_StateMachine.sensor_eng_group_idx ) {
		return FT_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST;
	}

	cnf->result.set_sensor_pregain.pregain_r_result  = KAL_TRUE;
	cnf->result.set_sensor_pregain.pregain_gr_result = KAL_TRUE;
	cnf->result.set_sensor_pregain.pregain_gb_result = KAL_TRUE;
	cnf->result.set_sensor_pregain.pregain_b_result  = KAL_TRUE;

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_SENSOR_PREGAIN; 	
	CctDataIn.GroupIdx = g_FT_CCT_StateMachine.sensor_eng_group_idx;

	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_R ) {		
		CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_R;
		CctDataIn.ItemValue = req->cmd.set_sensor_pregain.pregain_r.value;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		
	}
	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gr ) {
		CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gr;
		CctDataIn.ItemValue = req->cmd.set_sensor_pregain.pregain_gr.value;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		
	}
	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gb ) {
		CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_Gb;
		CctDataIn.ItemValue = req->cmd.set_sensor_pregain.pregain_gb.value;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		
	}
	if( -1 != g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_B ) {
		CctDataIn.ItemIdx = g_FT_CCT_StateMachine.sensor_eng_item_idx_pregain_B;
		CctDataIn.ItemValue = req->cmd.set_sensor_pregain.pregain_b.value;
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
		
		if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		
	}
/*
	if(	!cnf->result.set_sensor_pregain.pregain_r_result ||
		!cnf->result.set_sensor_pregain.pregain_gr_result ||
		!cnf->result.set_sensor_pregain.pregain_gb_result || 
		!cnf->result.set_sensor_pregain.pregain_b_result 
	) {
		return FT_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE;
	}
*/
	
	  if( ret == FT_CNF_FAIL) 
	{
		  return FT_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE;
	}  

	  return ret;
}

// FT_CCT_OP_MAIN_LCD_BACKLIGHT_SETTING: 29
// dabo note wait function
kal_uint8   ft_cct_main_lcd_backlight_setting(const FT_CCT_REQ *req){
	return FT_CNF_OK;
}

// FT_CCT_OP_GET_GAMMA_TABLE: 30
// danbo note this function only use 2X
kal_uint8  ft_cct_get_gamma_table(FT_CCT_CNF *cnf,peer_buff_struct **peer_buff_ret){
	return FT_CNF_OK;
}

// FT_CCT_OP_SET_GAMMA_TABLE: 31
// danbo note this function only use 2X
kal_uint8  ft_cct_set_gamma_table(FT_CCT_GAMMA_TABLE  *gamma_tbl){
	return FT_CNF_OK;
}

//FT_CCT_OP_QUERY_ISP_ID : 32
kal_uint8  ft_cct_query_isp_id(FT_CCT_CNF *cnf) {
	cnf->result.isp_id = isp_cct_get_isp_id();
	return FT_CNF_OK;
}

kal_uint8 Save_File_Get_Camera_Para(nvram_camera_para_struct *PCamera_Para_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PARA;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Para_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_3A(nvram_camera_3a_struct *PCamera_3A_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_3A;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_3A_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Defect1(nvram_camera_defect1_struct *PCamera_Defect1_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT1;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Defect1_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Defect2(nvram_camera_defect2_struct *PCamera_Defect2_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT2;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Defect2_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Shading1(nvram_camera_shading1_struct *PCamera_Shading1_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING1;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Shading1_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Shading2(nvram_camera_shading2_struct *PCamera_Shading2_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING2;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Shading2_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

#if defined(DRV_ISP_PCA_SUPPORT)
kal_uint8 Save_File_Get_Camera_PCA(nvram_camera_pca_struct *PCamera_PCA_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PCA;//CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_PARA
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_PCA_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

#if ( defined(__AUTO_SCENE_DETECT_SUPPORT__) )	  
kal_uint8 Save_File_Get_Camera_PCA2(nvram_camera_pca_struct *PCamera_PCA_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_MAIN;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PCA2;//CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_PARA
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_PCA_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

#endif
#endif

kal_uint8 Save_File_Get_Camera_Sub_Para(nvram_camera_para_struct *PCamera_Sub_Para_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PARA;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_Para_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Sub_3A(nvram_camera_3a_struct *PCamera_Sub_3A_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_3A;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_3A_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Sub_Defect1(nvram_camera_defect1_struct *PCamera_Sub_Defect1_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT1;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_Defect1_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Sub_Defect2(nvram_camera_defect2_struct *PCamera_Sub_Defect2_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT2;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_Defect2_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Sub_Shading1(nvram_camera_shading1_struct *PCamera_Sub_Shading1_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING1;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_Shading1_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

kal_uint8 Save_File_Get_Camera_Sub_Shading2(nvram_camera_shading2_struct *PCamera_Sub_Shading2_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING2;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_Shading2_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

#if defined(DRV_ISP_PCA_SUPPORT)
kal_uint8 Save_File_Get_Camera_Sub_PCA(nvram_camera_pca_struct *PCamera_Sub_PCA_DataOut){
	
	kal_uint8	ret = FT_CNF_OK;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 Camera_DataIn = (kal_uint8)CAL_CCT_SENSOR_SUB;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_CAMERA_PCA;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &Camera_DataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	CCTfeatureCtrlOut.pCctFeatureParaOut = PCamera_Sub_PCA_DataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

#endif

// FT_CCT_OP_GET_CAL_STRUCT_BUF: 33

kal_uint8 g_Camera_Struct_paras_buf[2048];

kal_uint8  ft_cct_get_calibration_struct_buf(kal_uint32	nvram_lid, peer_buff_struct **pp_peer_buff_ret) {

	kal_uint16	pdu_length = 0;
	kal_char	*pdu_ptr = NULL;
	kal_uint8	ret = FT_CNF_OK;

	if(!( custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() ))
	{
		switch(nvram_lid) 
		{
			case NVRAM_EF_CAMERA_PARA1_LID:
			
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_para_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
			
				ret = Save_File_Get_Camera_Para((nvram_camera_para_struct*)g_Camera_Struct_paras_buf );

				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_para_struct));
				break;

			case NVRAM_EF_CAMERA_PARA2_LID:

				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_3a_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 

	            ret = Save_File_Get_Camera_3A((nvram_camera_3a_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_3a_struct)); 	 
				break;

			case NVRAM_EF_CAMERA_DEFECT1_LID:
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect1_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);	
				
				ret = Save_File_Get_Camera_Defect1((nvram_camera_defect1_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect1_struct)); 
				break;

			case NVRAM_EF_CAMERA_DEFECT2_LID:
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect2_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Defect2((nvram_camera_defect2_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect2_struct)); 	
				break;

			case NVRAM_EF_CAMERA_SHADING1_LID:

				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading1_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Shading1((nvram_camera_shading1_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading1_struct)); 	 
				break;

			case NVRAM_EF_CAMERA_SHADING2_LID:

				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading2_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Shading2((nvram_camera_shading2_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading2_struct)); 	 
				break;	
		#if defined(DRV_ISP_PCA_SUPPORT)
			case NVRAM_EF_CAMERA_PCA_LID:

				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_pca_struct), 0, 0, TD_CTRL);

				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);

				ret = Save_File_Get_Camera_PCA((nvram_camera_pca_struct*)g_Camera_Struct_paras_buf );	
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_pca_struct));	 
				break;
		#if ( defined(__AUTO_SCENE_DETECT_SUPPORT__) ) 				
			case NVRAM_EF_CAMERA_PCA2_LID:
			
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_pca_struct), 0, 0, TD_CTRL);
			
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
			
				ret = Save_File_Get_Camera_PCA2((nvram_camera_pca_struct*)g_Camera_Struct_paras_buf );	
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_pca_struct));	 
				break;
		#endif
		#endif
			}
	}
	else	// if( custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
	{
		switch(nvram_lid)
		{
			case NVRAM_EF_CAMERA_PARA1_LID:
			case NVRAM_EF_CAMERA_PARA1_MAIN_LID:
			case NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_para_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
				
				ret = Save_File_Get_Camera_Para((nvram_camera_para_struct*)g_Camera_Struct_paras_buf );
		
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_para_struct));
				break;
		
			case NVRAM_EF_CAMERA_PARA2_LID:
			case NVRAM_EF_CAMERA_PARA2_MAIN_LID:
			case NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_3a_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
		
				ret = Save_File_Get_Camera_3A((nvram_camera_3a_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_3a_struct));	 
				break;
		
			case NVRAM_EF_CAMERA_DEFECT1_LID:
			case NVRAM_EF_CAMERA_DEFECT1_MAIN_LID:
			case NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID:
				
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect1_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);	
				
				ret = Save_File_Get_Camera_Defect1((nvram_camera_defect1_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect1_struct)); 
				break;
		
			case NVRAM_EF_CAMERA_DEFECT2_LID:
			case NVRAM_EF_CAMERA_DEFECT2_MAIN_LID:
			case NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID:
					
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect2_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Defect2((nvram_camera_defect2_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect2_struct));	
				break;
		
			case NVRAM_EF_CAMERA_SHADING1_LID:
			case NVRAM_EF_CAMERA_SHADING1_MAIN_LID:
			case NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading1_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Shading1((nvram_camera_shading1_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading1_struct)); 	 
				break;
		
			case NVRAM_EF_CAMERA_SHADING2_LID:
			case NVRAM_EF_CAMERA_SHADING2_MAIN_LID:
			case NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading2_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Shading2((nvram_camera_shading2_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading2_struct)); 	 
				break;	
				
		#if defined(DRV_ISP_PCA_SUPPORT)
			case NVRAM_EF_CAMERA_PCA_LID:
			case NVRAM_EF_CAMERA_PCA_MAIN_LID:
			case NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_pca_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
		
				ret = Save_File_Get_Camera_PCA((nvram_camera_pca_struct*)g_Camera_Struct_paras_buf );	
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_pca_struct));	 
				break;
		#endif
		
			case NVRAM_EF_CAMERA_PARA1_SUB_LID:
			case NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_para_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
				
				ret = Save_File_Get_Camera_Sub_Para((nvram_camera_para_struct*) g_Camera_Struct_paras_buf);
		
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_para_struct));
				break;
		
			case NVRAM_EF_CAMERA_PARA2_SUB_LID:
			case NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_3a_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
		
				ret = Save_File_Get_Camera_Sub_3A((nvram_camera_3a_struct*) g_Camera_Struct_paras_buf);
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_3a_struct));	 
				break;
		
			case NVRAM_EF_CAMERA_DEFECT1_SUB_LID:
			case NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID:
				
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect1_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);	
				
				ret = Save_File_Get_Camera_Sub_Defect1((nvram_camera_defect1_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect1_struct)); 
				break;
		
			case NVRAM_EF_CAMERA_DEFECT2_SUB_LID:
			case NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID:
					
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_defect2_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Sub_Defect2((nvram_camera_defect2_struct*)g_Camera_Struct_paras_buf );
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_defect2_struct));	
				break;
		
			case NVRAM_EF_CAMERA_SHADING1_SUB_LID:
			case NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading1_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Sub_Shading1((nvram_camera_shading1_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading1_struct)); 	 
				break;
		
			case NVRAM_EF_CAMERA_SHADING2_SUB_LID:
			case NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_shading2_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		 
				
				ret = Save_File_Get_Camera_Sub_Shading2((nvram_camera_shading2_struct*)g_Camera_Struct_paras_buf );
			
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_shading2_struct)); 	 
				break;	
				
		#if defined(DRV_ISP_PCA_SUPPORT)
			case NVRAM_EF_CAMERA_PCA_SUB_LID:
			case NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID:
		
				*pp_peer_buff_ret = construct_peer_buff(sizeof(nvram_camera_pca_struct), 0, 0, TD_CTRL);
		
				pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
		
				ret = Save_File_Get_Camera_Sub_PCA((nvram_camera_pca_struct*)g_Camera_Struct_paras_buf );	
				
				kal_mem_cpy(pdu_ptr, (kal_uint8 *)g_Camera_Struct_paras_buf, sizeof(nvram_camera_pca_struct));	 
				break;
		#endif
			default:
				return FT_CCT_ERR_NOT_IMPLEMENT_YET;
		}
	}
	return ret;
}

// FT_CCT_OP_GET_ENG_SENSOR_PARA: 34
kal_uint8  ft_cct_get_eng_sensor_para(const kal_char *group_id, const kal_char *item_id, FT_CCT_CNF *cnf) {

	kal_int32	group_count, item_count;
	kal_int8	group_name[64];
	ENG_sensor_info		item_info;

	kal_uint8	ret = FT_CNF_OK;

	kal_mem_set(&cnf->result.get_eng_sensor_para, 0, sizeof(cnf->result.get_eng_sensor_para));

	// get sensor engineer mode group index and item index 
	
	ret = get_sensor_group_count(&group_count);
	
	if(ret)
		return ret;
	
	for(; 0<group_count; group_count--) {
		
		ret = get_sensor_group_info((kal_uint16)(group_count-1), group_name, &item_count);

		if(ret) // danbo add for fix warning  110401
			return ret;
		
		if(!strcmp(group_id, (kal_char*)group_name))
		{
			// found group 
			for(; 0<item_count; item_count--) {
				
				ret = get_sensor_item_info((kal_uint16)(group_count-1), (kal_uint16)(item_count-1), &item_info);
	
				if(ret) // danbo add for fix warning  110401
					return ret;
	
				if(!strcmp(item_id, (kal_char*)item_info.item_name_ptr)) 
					{
					// found item 
					cnf->result.get_eng_sensor_para.value = item_info.item_value;
					cnf->result.get_eng_sensor_para.min = item_info.min;
					cnf->result.get_eng_sensor_para.max = item_info.max;
					cnf->result.get_eng_sensor_para.exist = KAL_TRUE;
					return FT_CNF_OK;
				}
			}
			return FT_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST;
		}
	}

	return FT_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST;
}

 // FT_CCT_OP_SET_ENG_SENSOR_PARA: 35
kal_uint8  ft_cct_set_eng_sensor_para(const kal_char *group_id, const kal_char *item_id, const FT_CCT_REQ *req){

 kal_int32	 group_count, item_count;
 kal_int8	 group_name[64];
 ENG_sensor_info	 item_info;

 kal_uint8	 ret = FT_CNF_OK;

 ret = get_sensor_group_count(&group_count);

 if(ret)
	 return ret;
 
 for(; 0<group_count; group_count--) {

	 ret = get_sensor_group_info((kal_uint16)(group_count-1), group_name, &item_count);
	 
	 if(ret) // danbo add for fix warning  110401
		 return ret;
	 
	 if(!strcmp(group_id, (kal_char*)group_name)) 
	 
	 	{
		 for(; 0<item_count; item_count--) {

			 ret = get_sensor_item_info((kal_uint16)(group_count-1), (kal_uint16)(item_count-1), &item_info);

			 if(ret)  // danbo add for fix warning  110401
				 return ret;
			 
			 if(!strcmp(item_id, (kal_char*)item_info.item_name_ptr)) 
			 
			 	{

				 if(!(set_sensor_item_info((kal_uint16)(group_count-1), (kal_uint16)(item_count-1),  req->cmd.set_eng_sensor_para)) )
				 	{
					 return FT_CNF_OK;
				 }
				 return FT_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE;
			 }
		 }
		 return FT_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST;
	 }
 }
 
 return FT_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST;

}

 // FT_CCT_OP_GET_COMPENSATION_MODE: 36
kal_uint8  ft_cct_get_compensation_mode(FT_CCT_CNF *cnf){

	 if( !isp_cct_is_shading_supported() && !isp_cct_is_autodefect_supported() ) {
		 return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	 }
	 cnf->result.get_compensation_mode = g_FT_CCT_StateMachine.comp_mode;	 
	 return FT_CNF_OK;

}
			 
// FT_CCT_OP_SET_COMPENSATION_MODE: 37
kal_uint8  ft_cct_set_compensation_mode(const FT_CCT_REQ *req){

	if( !isp_cct_is_shading_supported() && !isp_cct_is_autodefect_supported() ) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	if( CAMERA_COMP_END <= req->cmd.set_compensation_mode ) {
		return FT_CCT_ERR_INVALID_COMPENSATION_MODE;
	}
	g_FT_CCT_StateMachine.comp_mode = req->cmd.set_compensation_mode;
	cct_apply_camera_shading_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	cct_apply_camera_autodefect_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	return FT_CNF_OK;

}

// FT_CCT_OP_GET_SHADING_PARA: 38
kal_uint8  ft_cct_get_shading_para(FT_CCT_CNF *cnf){

	if(!isp_cct_is_shading_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	// get shading para 
	get_camera_shading_set((cct_shading_comp_struct *)&cnf->result.get_shading_para, (camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	return FT_CNF_OK;

}

// FT_CCT_OP_SET_SHADING_PARA: 39
kal_uint8  ft_cct_set_shading_para(const FT_CCT_REQ *req){

	if(!isp_cct_is_shading_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	// set shading para 
	set_camera_shading_set((const cct_shading_comp_struct *)&req->cmd.set_shading_para, (camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	// apply to reg 
	cct_apply_camera_shading_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	return FT_CNF_OK;

}

// FT_CCT_OP_GET_AUTODEFECT_PARA: 40
kal_uint8  ft_cct_get_autodefect_para(FT_CCT_CNF *cnf){
	// check if isp supports auto-defect compensation 
	if(!isp_cct_is_autodefect_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	// get autodefect para 
	get_camera_autodefect_set((cct_autodefect_comp_struct *)&cnf->result.get_autodefect_para, (camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	return FT_CNF_OK;
}

// FT_CCT_OP_SET_AUTODEFECT_PARA: 41
kal_uint8  ft_cct_set_autodefect_para(const FT_CCT_REQ *req){
	if(!isp_cct_is_autodefect_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	// set shading para 
	set_camera_autodefect_set((const cct_autodefect_comp_struct *)&req->cmd.set_autodefect_para,(camera_comp_set_num) g_FT_CCT_StateMachine.comp_mode);
	// apply to reg 
	cct_apply_camera_autodefect_to_reg((camera_comp_set_num)g_FT_CCT_StateMachine.comp_mode);
	return FT_CNF_OK;
}

// FT_CCT_OP_GET_LAST_COMPENSATION_MODE: 42
kal_uint8  ft_cct_get_last_compensation_mode(FT_CCT_CNF *cnf){
    // danbo note  CAMERA_COMP_END =4 ;
	cnf->result.get_last_compensation_mode = 3;// (CAMERA_COMP_END-1);	
	return FT_CNF_OK;

}

// FT_CCT_OP_GET_AUTODEFECT_COUNT: 43
kal_uint8  ft_cct_get_autodefect_count(FT_CCT_CNF *cnf){
	if(!isp_cct_is_autodefct_count_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	cnf->result.get_autodefect_count = cct_read_autodefct_count();
	return FT_CNF_OK;
}


 //FT_CCT_OP_SET_CAPTURE_DATA_TUNNEL : 44
kal_uint8  ft_cct_set_capture_data_tunnel(const FT_CCT_REQ *req){

	kal_uint32	ret = FT_CNF_OK;

	switch(req->cmd.set_capture_data_tunnel) {
	case DATA_TUNNEL_RS232:
		// RS232 
		//g_FT_CCT_StateMachine.usb_capture_data_tunnel = 0;
		g_FT_CCT_StateMachine.usb_capture_data_tunnel = DATA_TUNNEL_RS232;
		// change to cancel state 
		g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_IDLE;
		break;
	case DATA_TUNNEL_USB_COM:
		// USB_COM 
		if(g_FT_CCT_StateMachine.usb_ready) {
			//g_FT_CCT_StateMachine.usb_capture_data_tunnel = 1;
			g_FT_CCT_StateMachine.usb_capture_data_tunnel = DATA_TUNNEL_USB_COM;
			// change to cancel state 
			g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_IDLE;
		}
		else {
			ret = FT_CCT_ERR_USB_COM_NOT_READY;
		}
		break;
	default:
		ret = FT_CCT_ERR_NOT_IMPLEMENT_YET;
		break;
	}

	//return FT_CNF_OK;
	return ret;
}

// FT_CCT_OP_USB_TUNNEL_CANCEL: 45
kal_uint8  ft_cct_usb_tunnel_cancel(){
#ifdef __USB_COM_PORT_ENABLE__
	if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support())
	{
		//kal_uint8	ch=0xFF;
		if(g_FT_CCT_StateMachine.usb_ready) {
			// change to cancel state 
			g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_CANCEL;
			// stop USB_COM TX DMA 
			USB2UART_FT_Tx_Stop();
			// send extra one byte to flush out PC side driver data 
			USB2UART_FT_Tx_Byte((kal_uint8 *)&ch, 1);
		}
		return FT_CNF_OK;
	}else
	{
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
#else
	return FT_CNF_OK;
#endif
}
 
// FT_CCT_OP_DEFECT_TABLE_VERIFY_BLOCK_FACTOR: 46
kal_uint8  ft_cct_defect_table_verify_block_factor(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_int32	ret = FT_CNF_OK;

	cnf->result.defect_table_cal_para.block_width_factor = req->cmd.defect_table_cal_para.block_width_factor;
	cnf->result.defect_table_cal_para.block_height_factor = req->cmd.defect_table_cal_para.block_height_factor;
	// get boarder length 
	cnf->result.defect_table_cal_para.boarder_len = req->cmd.defect_table_cal_para.boarder_len;

	if( FT_CCT_COMP_PREVIEW_NORMAL_SET==g_FT_CCT_StateMachine.comp_mode || FT_CCT_COMP_PREVIEW_LOWLIGHT_SET==g_FT_CCT_StateMachine.comp_mode ) {
		// get preview mode width and height 
		cnf->result.defect_table_cal_para.image_width = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_width;
		cnf->result.defect_table_cal_para.image_height = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_height;
	}
	else {
		// get capture mode width and height 
		cnf->result.defect_table_cal_para.image_width = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].width;
		cnf->result.defect_table_cal_para.image_height = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].height;
	}

	// calculate max defect table calibration block 
	// danbo note :  camera_defectpixel_verify_block_factor used ?????
	/*
	if( 0 <= (ret=camera_defectpixel_verify_block_factor(g_FT_CCT_StateMachine.mem_capture_ext_buf_size, (defectpixel_para_struct *)&(cnf->result.defect_table_cal_para))) ) {
		return FT_CNF_OK;
	}
       */
	return convert_defect_table_err_code(ret);

}

// FT_CCT_OP_DEFECT_TABLE_CAL: 47
// danbo note : wait check this function not use in hal ??
kal_uint8  ft_cct_defect_table_calibration(const FT_CCT_REQ *req){
	return FT_CNF_OK;
}

// FT_CCT_OP_GET_DEFECT_TABLE: 48
// danbo note : wait check this function not use in hal ??
kal_uint8  ft_cct_get_defect_table(FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret){
		return FT_CNF_OK;
}

// FT_CCT_OP_SET_DEFECT_TABLE: 49
// danbo note : wait check this function not use in hal ??
kal_uint8  ft_cct_set_defect_table(FT_CCT_CNF *cnf, const defectpixel_result_struct  *p_defect_pixel_list){
		return FT_CNF_OK;
}

// FT_CCT_OP_DEV_GET_DSC_INFO: 50
kal_uint8  ft_cct_dev_get_dsc_info(peer_buff_struct **pp_peer_buff_ret){

	kal_uint16	pdu_length = 0;
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	camcorder_info_struct CctDataOut;
	FT_CCT_DEV_DSC_INFO *pdu_ptr = NULL;

	// get peer buf 
	*pp_peer_buff_ret = construct_peer_buff(sizeof(FT_CCT_DEV_DSC_INFO), 0, 0, TD_CTRL);
	pdu_ptr = (FT_CCT_DEV_DSC_INFO *)get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
  
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(camcorder_info_struct));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_CAMCORDER_INFO;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(pdu_ptr->dsc_info), &CctDataOut, sizeof(camcorder_info_struct)); 

#if (!defined(DRV_ISP_6238_SERIES))	
	pdu_ptr->sensor_info.pregain_max = camera_oper_data.pregain_max;
	pdu_ptr->sensor_info.pregain_min = camera_oper_data.pregain_min;
#else
	pdu_ptr->sensor_info.pregain_max = CameraDriverOperParaBuffer.pregain_max;
	pdu_ptr->sensor_info.pregain_min = CameraDriverOperParaBuffer.pregain_min;
#endif
	return ret;
  
}

// FT_CCT_OP_DEV_GET_IRIS_INFO: 51
kal_uint8  ft_cct_dev_get_iris_info(FT_CCT_CNF *cnf){
    //cnf->result.dev_get_iris_info.iris ;
	return FT_CNF_OK;
}

// FT_CCT_OP_DEV_SET_IRIS_INFO: 52
kal_uint8  ft_cct_dev_set_iris_info(const FT_CCT_REQ *req){
	//req->cmd.dev_set_iris_info.iris;
	return FT_CNF_OK;
}

// danbo  add  for  CDT  Tools use Struct  and  Driver Return Struct are not same  110413
void Struct_AE_LUT_To_AE_Get_Info(FT_CCT_DEV_AE_INFO *PGet_AE_Info,IMAGE_SENSOR_AE_LUT_STRUCT *PImage_Ae_LUT)
{
	kal_mem_cpy(&(PGet_AE_Info->device_info.ae),&(PImage_Ae_LUT->pDeviceInfo->ae),sizeof(ae_info_struct));
	kal_mem_cpy(&(PGet_AE_Info->device_info.autoflash),&(PImage_Ae_LUT->pDeviceInfo->autoflash),sizeof(flash_info_struct));
	PGet_AE_Info->ae_table.table_size = PImage_Ae_LUT->pDeviceInfo->ae.lutsize;
	kal_mem_cpy(&(PGet_AE_Info->ae_table.ae_table),*(PImage_Ae_LUT->pAeLut),(PGet_AE_Info->ae_table.table_size)*sizeof(exposure_lut_struct));
	kal_mem_set(&(PGet_AE_Info->ae_table.iris_table), 28, sizeof(kal_uint8)* (PGet_AE_Info->ae_table.table_size));// danbo add set 2.8 iris table  110414
}

// FT_CCT_OP_DEV_AE_GET_INFO: 53
kal_uint8  ft_cct_dev_ae_get_info(peer_buff_struct **peer_buff_ret){

	kal_uint8   ret = FT_CNF_OK;
	kal_uint16  pdu_length = 0;

	FT_CCT_DEV_AE_INFO *pdu_ptr = NULL;
	
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	IMAGE_SENSOR_AE_LUT_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(IMAGE_SENSOR_AE_LUT_STRUCT));

	// get peer buf 
	*peer_buff_ret = construct_peer_buff(sizeof(FT_CCT_DEV_AE_INFO), 0, 0, TD_CTRL);
	pdu_ptr = get_pdu_ptr(*peer_buff_ret, &pdu_length);

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_GET_INFO;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	Struct_AE_LUT_To_AE_Get_Info(pdu_ptr,&CctDataOut);
	return ret;

}

// FT_CCT_OP_DEV_AE_SET_TABLE_IDX: 54
kal_uint8  ft_cct_dev_ae_set_table_index(const FT_CCT_REQ *req){

	 kal_uint8	 ret = FT_CNF_OK;

	 CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	 CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	 CAL_CCT_DEV_AE_TABLE_IDX_INFO CctDataIn;
	 
	 kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	 kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	 kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEV_AE_TABLE_IDX_INFO));
	 
	 CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_SET_TABLE_IDX;
	 CctDataIn.ae_index = req->cmd.dev_ae_set_table_index;
	 CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	 CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	 
	 if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	 {
	  ret = FT_CNF_FAIL;
	 } 
	   return ret;

}

// FT_CCT_OP_DEV_AE_SET_VALUE: 55
kal_uint8  ft_cct_dev_ae_set_value(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_SET_VALUE;
	CctDataIn.AeShutterLine = req->cmd.dev_ae_set_value_para.shutter;
	CctDataIn.AeSensorGain = req->cmd.dev_ae_set_value_para.sensorgain;
	CctDataIn.AeIspGain = req->cmd.dev_ae_set_value_para.ispgain;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	 return ret;
	  
}

// FT_CCT_OP_DEV_AF_GET_TABLE: 56
kal_uint8  ft_cct_dev_af_get_table(peer_buff_struct **peer_buff_ret){

   return FT_CNF_FAIL;
}

// FT_CCT_OP_DEV_AF_CAL: 57
kal_uint8  ft_cct_dev_af_calibration(FT_CCT_CNF *cnf){

	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	if(isp_device_af_calibration(&cnf->result.dev_af_cal_result.pos, &cnf->result.dev_af_cal_result.atf_value)) {
		return FT_CNF_OK;
	}

	return FT_CNF_FAIL;
}

// FT_CCT_OP_DEV_AF_SET_TABLE_IDX: 58
kal_uint8  ft_cct_dev_af_set_table_index(const FT_CCT_REQ *req){

	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	if(isp_device_set_af_idx(req->cmd.dev_af_para.activate_af_table_index)) {
		return FT_CNF_OK;
	}

	return FT_CNF_FAIL;
}

// FT_CCT_OP_DEV_AF_SET_POS: 59
kal_uint8  ft_cct_dev_af_set_pos(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	LENS_COMM_DATA_STRUCT CctDataIn;
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(LENS_COMM_DATA_STRUCT));
	
	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AF_SET_POS;
	CctDataIn.FeatureValue = req->cmd.dev_af_para.set_pos;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}	
	
	  return ret;
}

// FT_CCT_OP_DEV_STROBE_CAL_ENABLE: 60
kal_uint8  ft_cct_dev_strobe_calibration_enable(){
	g_FT_CCT_StateMachine.strobe_cal_enable = KAL_TRUE;
	return FT_CNF_OK;
}

// FT_CCT_OP_DEV_STROBE_CAL_SET_PARA: 61
kal_uint8  ft_cct_dev_strobe_calibration_set_para(const FT_CCT_REQ *req){
	g_FT_CCT_StateMachine.strobe_cal_para = req->cmd.dev_strobe_cal_para;
	return FT_CNF_OK;
}

// FT_CCT_OP_DEV_STROBE_CAL_DISABLE: 62
kal_uint8  ft_cct_dev_strobe_calibration_disable(){
	g_FT_CCT_StateMachine.strobe_cal_enable = KAL_FALSE;
	return FT_CNF_OK;
}

// FT_CCT_OP_ENABLE_USBCOM: 63
kal_uint8  ft_cct_enable_usbcom(void){

	if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support())
	{
		ilm_struct	*ptr_ilm;
		// send enable USBCOM msg to USB task 
		ptr_ilm = FT_ALLOC_OTHER_MSG(0);

		FT_SEND_MSG(MOD_FT, MOD_USB, DRIVER_PS_SAP, MSG_ID_USB_FT_START_REQ, ptr_ilm);
		
		return FT_CNF_OK;
	}
	else
	{
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

}

// FT_CCT_OP_AF_LENS_OFFSET_CAL: 66
kal_uint8  ft_cct_af_lens_offset_cal(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_bool				AE_Enabled;
	FT_CCT_WB_SETTING		WB_ActivatedIndex;

	if(!isp_cct_is_cct_af_support()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	// preview must be enabled to do lens offset calibration 
	if( NULL == g_FT_CCT_StateMachine.p_preview_sensor ) {
		return FT_CCT_ERR_PREVIEW_MUST_ENABLE;
	}

	// backup current AE/AWB setting 
	AE_Enabled = g_FT_CCT_StateMachine.ae_enable;
	WB_ActivatedIndex = g_FT_CCT_StateMachine.wb_activated_idx;

	// release previous locked focus to hyper focus and reset af lens offset calibration setting 
	ft_cct_af_release();

	// if AE is enabled, disable it before calibration 
	if(AE_Enabled) {
		ft_cct_ae_enable(KAL_FALSE);
	}

	// if AWB is enabled, disable it before calibration 
	if( FT_CCT_WB_OFF != WB_ActivatedIndex ) {
		ft_cct_wb_activate_by_index(FT_CCT_WB_OFF);
	}

	// trigger lens offset calibration 
	g_FT_CCT_StateMachine.af_lens_offset_cal = KAL_TRUE;
#if (defined(ISP_SUPPORT)&&(!defined(MT6225))&&(!defined(MT6235))&&(!defined(MT6235B)) && (!defined(MT6253T)) && (!defined(MT6253)) &&(!defined(MT6219)))	
	cnf->result.lens_offset_cal_return_code = camera_af_lens_offset_cal((AF_OQC_cal_struct *)&(req->cmd.lens_offset_cal_para));
#endif
	g_FT_CCT_StateMachine.af_lens_offset_cal = KAL_FALSE;

	// if AE is enabled originally, re-enable it 
	if(AE_Enabled) {
		ft_cct_ae_enable(KAL_TRUE);
	}

	// if AWB is enabled originally, re-enable it 
	if( FT_CCT_WB_OFF != WB_ActivatedIndex ) {
		ft_cct_wb_activate_by_index(WB_ActivatedIndex);
	}

	if( KAL_FALSE == cnf->result.lens_offset_cal_return_code ) {
	return FT_CNF_OK;
}
	else {
		return FT_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL;
	}
}

// FT_CCT_OP_DEFECT_TABLE_BYPASS_BACKUP_SETTING: 67
kal_uint8  ft_cct_defect_table_bypass_and_backup_setting(){
	cct_backup_bypass_pre_adjust();
	return FT_CNF_OK;
}

// FT_CCT_OP_DEFECT_TABLE_RESTORE_SETTING: 68
kal_uint8  ft_cct_defect_table_restore_setting(){
	cct_recover_pre_adjust();
	return FT_CNF_OK;
}

// FT_CCT_OP_AE_GET_PERIOD_PARA: 69
kal_uint8  ft_cct_ae_get_period_para(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_PERIOD_PARA_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_PERIOD_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_AE_GET_PERIOD_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_ae_period_para.AeSettingCalDelayFrame = CctDataOut.AeSettingCalDelayFrame;
	cnf->result.get_ae_period_para.AeSettingShutDelayFrame = CctDataOut.AeSettingShutDelayFrame;
	cnf->result.get_ae_period_para.AeSettingSensorGainDelayFrame = CctDataOut.AeSettingSensorGainDelayFrame;
	cnf->result.get_ae_period_para.AeSettingGainDelayFrame = CctDataOut.AeSettingGainDelayFrame;
	cnf->result.get_ae_period_para.AeAwbCalPeriod = CctDataOut.AeAwbCalPeriod;
	//cnf->result.get_ae_period_para.ae_setting_cal_delay_frame = pCctDataOut.AeSettingCalDelayFrame;
	//cnf->result.get_ae_period_para.ae_setting_shut_delay_frame = pCctDataOut.ae_setting_shut_delay_frame;
	//cnf->result.get_ae_period_para.ae_setting_sensor_gain_delay_frame = pCctDataOut.ae_setting_sensor_gain_delay_frame;
	//cnf->result.get_ae_period_para.ae_setting_gain_delay_frame = pCctDataOut.ae_setting_gain_delay_frame;
	//cnf->result.get_ae_period_para.ae_awb_cal_period = pCctDataOut.ae_awb_cal_period;
	//cnf->result.reg_read.value_len =  RegOutLen;
	return ret;

}

// FT_CCT_OP_AE_SET_PERIOD_PARA: 70
kal_uint8  ft_cct_ae_set_period_para(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	kal_bool				AE_Enabled;
	FT_CCT_WB_SETTING		WB_ActivatedIndex;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_PERIOD_PARA_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_PERIOD_PARA_STRUCT));

	// backup current AE/AWB setting 
	AE_Enabled = g_FT_CCT_StateMachine.ae_enable;
	WB_ActivatedIndex = g_FT_CCT_StateMachine.wb_activated_idx;

	// if AE is enabled, disable it before calibration 
	if(AE_Enabled) {
		ft_cct_ae_enable(KAL_FALSE);
	}

	// if AWB is enabled, disable it before calibration 
	if( FT_CCT_WB_OFF != WB_ActivatedIndex ) {
		ft_cct_wb_activate_by_index(FT_CCT_WB_OFF);
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_AE_SET_PERIOD_PARA;
	CctDataIn.AeSettingCalDelayFrame = req->cmd.set_ae_period_para.AeSettingCalDelayFrame;
	CctDataIn.AeSettingShutDelayFrame = req->cmd.set_ae_period_para.AeSettingShutDelayFrame;
	CctDataIn.AeSettingSensorGainDelayFrame = req->cmd.set_ae_period_para.AeSettingSensorGainDelayFrame;
	CctDataIn.AeSettingGainDelayFrame = req->cmd.set_ae_period_para.AeSettingGainDelayFrame;
	CctDataIn.AeAwbCalPeriod = req->cmd.set_ae_period_para.AeAwbCalPeriod;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	} 	

	// if AE is enabled originally, re-enable it 
	if(AE_Enabled) {
		ft_cct_ae_enable(KAL_TRUE);
	}

	// if AWB is enabled originally, re-enable it 
	if( FT_CCT_WB_OFF != WB_ActivatedIndex ) {
		ft_cct_wb_activate_by_index(WB_ActivatedIndex);
	}
	return ret;
}

// FT_CCT_OP_DEV_AE_BYPASS_FREERUN: 71
kal_uint8  ft_cct_dev_ae_bypass_freerun(const FT_CCT_DEV_AE_BYPASS_FREERUN_PARA  *req, peer_buff_struct **pp_peer_buff_ret){

	FT_CCT_DEV_AE_BYPASS_FREERUN_RESULT *POutResult = NULL;
	kal_uint8	ret = FT_CNF_OK;
	kal_uint16	pdu_length = 0;
	kal_uint32  RegOutLen = 0;
	
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
        CAL_AE_BYPASS_FREERUN_STRUCT CctDataIn;
	CAL_AE_BYPASS_FREERUN_RESULT_STRUCT CctDataOut;
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_AE_BYPASS_FREERUN_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_AE_BYPASS_FREERUN_RESULT_STRUCT));
	
	*pp_peer_buff_ret = construct_peer_buff(sizeof(FT_CCT_DEV_AE_BYPASS_FREERUN_RESULT), 0, 0, TD_CTRL);
	POutResult = (FT_CCT_DEV_AE_BYPASS_FREERUN_RESULT *)get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);
	kal_mem_set(POutResult, 0, sizeof(FT_CCT_DEV_AE_BYPASS_FREERUN_RESULT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_BYPASS_FREERUN;
	CctDataIn.start_idx = req->start_idx;
	CctDataIn.end_idx = req->end_idx;
	CctDataIn.iris_lut = (kal_uint8 *)req->freerun_table.iris_table;
	CctDataIn.lut = (exposure_lut_struct *)req->freerun_table.ae_table;
	CctDataIn.timer_ms = req->timer_ms;
	CctDataOut.resultLum = POutResult->lum_info;
	POutResult->lum_info_size = (CctDataIn.end_idx - CctDataIn.start_idx+1);
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;

	  return ret;
}

// FT_CCT_OP_DEV_AE_SET_SCENE_MODE: 72
kal_uint8  ft_cct_dev_ae_set_scene_mode(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
        AE_LUT_INFO_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(AE_LUT_INFO_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_AE_SET_SCENE_MODE;
	CctDataIn.DscMode = req->cmd.dev_ae_set_scene_mode.DscMode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}  

	g_FT_CCT_StateMachine.dev_ae_scene_mode = req->cmd.dev_ae_set_scene_mode;
	//kal_mem_cpy(&(g_FT_CCT_StateMachine.dev_ae_scene_mode ), &(req->cmd.dev_ae_set_scene_mode), sizeof(ae_lut_info_struct)); 

	return ret;
}

// FT_CCT_OP_GET_GAMMA_TABLE_ON_OFF_FLAG: 73
kal_uint8  ft_cct_get_gamma_table_on_off_flag(FT_CCT_CNF *cnf){

	cnf->result.on_off = (kal_bool)FT_CNF_FAIL;

	return FT_CNF_OK;
}

// FT_CCT_OP_SET_GAMMA_TABLE_ON_OFF_FLAG: 74
kal_uint8  ft_cct_set_gamma_table_on_off_flag(const kal_bool bOnOff){
	return FT_CNF_FAIL;
}

// FT_CCT_OP_GET_GAMMA_ON_OFF_FLAG:75
kal_uint8  ft_cct_get_gamma_on_off_flag(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataOut;
	
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_REG_RW_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_BYPASS_FLAG;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	
	cnf->result.on_off = (kal_bool)!(CctDataOut.Enable);
	
	  return ret;

}

// FT_CCT_OP_SET_GAMMA_ON_OFF_FLAG: 76
kal_uint8  ft_cct_set_gamma_on_off_flag(const kal_bool bOnOff){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SET_GAMMA_BYPASS;
	CctDataIn.Enable = bOnOff;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_GET_ISO_GAIN: 77
kal_uint8  ft_cct_dev_get_iso_gain(FT_CCT_CNF *cnf){
	
	kal_uint8	 ret = FT_CNF_OK;
	 kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_DEV_ISO_GAIN  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_DEV_ISO_GAIN));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_ISO_GAIN;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;	 
	kal_mem_cpy(&(cnf->result.dev_get_iso_gain.gain), &CctDataOut, sizeof(CAL_CCT_DEV_ISO_GAIN)); 

	return ret;
}

// FT_CCT_OP_DEV_SET_ISO_GAIN: 78
kal_uint8  ft_cct_dev_set_iso_gain(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_DEV_ISO_GAIN CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEV_ISO_GAIN));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_ISO_GAIN;
	CctDataIn.gain[0]= req->cmd.dev_set_iso_gain.gain[0];
	CctDataIn.gain[1]= req->cmd.dev_set_iso_gain.gain[1];
	CctDataIn.gain[2]= req->cmd.dev_set_iso_gain.gain[2];
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_RECOVER_ISO_CAPTURE: 79
kal_uint8  ft_cct_dev_recover_iso_capture(){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;	
	
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_RECOVER_ISO_CAPTURE;
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_SET_ISO_CAPTURE: 80
kal_uint8  ft_cct_dev_set_iso_capture(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_ISO_CAPTURE;
	CctDataIn = req->cmd.dev_set_iso_capture.select;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_GET_ISO_VALUE: 81
kal_uint8  ft_cct_dev_get_iso_value(FT_CCT_CNF *cnf){
	
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_DEV_ISO_VALUE CctDataOut ;  

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_DEV_ISO_VALUE));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_ISO_VALUE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.dev_get_iso_value.value), &CctDataOut, sizeof(CAL_CCT_DEV_ISO_VALUE)); 

	return ret;
}

// FT_CCT_OP_DEV_SET_ISO_VALUE: 82
kal_uint8  ft_cct_dev_set_iso_value(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_DEV_ISO_VALUE CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEV_ISO_VALUE));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_ISO_VALUE;
	CctDataIn.value[0]= req->cmd.dev_set_iso_value.value[0];
	CctDataIn.value[1]= req->cmd.dev_set_iso_value.value[1];
	CctDataIn.value[2]= req->cmd.dev_set_iso_value.value[2];
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_FLASHLIGHT_CHARGE: 83
kal_uint8  ft_cct_flashlight_charge(const FT_CCT_REQ *req,FT_CCT_CNF *cnf){

	kal_uint8 ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
        CAL_CDT_FLASHLIGHT_CHARGE_STRUCT CctDataIn; 
	kal_uint32 CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CDT_FLASHLIGHT_CHARGE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_CHARGE;
	CctDataIn.charge_on = req->cmd.dev_flashlight_charge.charge_on;	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.flash_charge_timeout = CctDataOut;
	
	return ret;
 
}

kal_uint32  xenon_flash_ft_test = 0;

// FT_CCT_OP_DEV_FLASHLIGHT_STROBE: 84
kal_uint8  ft_cct_flashlight_strobe(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
        CAL_CDT_FLASHLIGHT_STROBE_STRUCT CctDataIn; 
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CDT_FLASHLIGHT_STROBE_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_STROBE;
	CctDataIn.strobe_width = req->cmd.dev_flashlight_strobe.strobe_width;
	CctDataIn.strobe_height = req->cmd.dev_flashlight_strobe.strobe_height;
	CctDataIn.strobe_duty = req->cmd.dev_flashlight_strobe.strobe_duty;
	CctDataIn.strobe_offset = req->cmd.dev_flashlight_strobe.strobe_offset;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	  xenon_flash_ft_test |= 0x01;

	  return ret;
}

// FT_CCT_OP_DEV_FLASHLIGHT_CONF: 85
// FT_CCT_6238_OP_FLASH_CONFIG: 186
kal_uint8  ft_cct_flashlight_capture(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
        CAL_CDT_FLASHLIGHT_CAPTURE_STRUCT CctDataIn; 
	AE_EXPOSURE_LUT_STRUCT CctDataOut;
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CDT_FLASHLIGHT_CAPTURE_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(AE_EXPOSURE_LUT_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_CONF;
	/*
	CctDataIn.ae_index = req->cmd.dev_flashlight_capture.ae_index;
	CctDataIn.bgain = req->cmd.dev_flashlight_capture.bgain;
	CctDataIn.ggain = req->cmd.dev_flashlight_capture.ggain;
	CctDataIn.is_awb_apply = req->cmd.dev_flashlight_capture.is_awb_apply;
	CctDataIn.linearity_count = req->cmd.dev_flashlight_capture.linearity_count;
	CctDataIn.linearity_duty = req->cmd.dev_flashlight_capture.linearity_duty;
	CctDataIn.max_strobe_duty = req->cmd.dev_flashlight_capture.max_strobe_duty;
	CctDataIn.prestrobe_duty = req->cmd.dev_flashlight_capture.prestrobe_duty;
	CctDataIn.prestrobe_en = req->cmd.dev_flashlight_capture.prestrobe_en;
	CctDataIn.prestrobe_times = req->cmd.dev_flashlight_capture.prestrobe_times;
	CctDataIn.redeye_duty = req->cmd.dev_flashlight_capture.redeye_duty;
	CctDataIn.redeye_en = req->cmd.dev_flashlight_capture.redeye_en;
	CctDataIn.redeye_offset = req->cmd.dev_flashlight_capture.redeye_offset;
	CctDataIn.redeye_wait_frame = req->cmd.dev_flashlight_capture.redeye_wait_frame;
	CctDataIn.rgain = req->cmd.dev_flashlight_capture.rgain;
	CctDataIn.strobe_height = req->cmd.dev_flashlight_capture.strobe_height;
	CctDataIn.strobe_width = req->cmd.dev_flashlight_capture.strobe_width;
	*/
	kal_mem_cpy(&CctDataIn,&(req->cmd.dev_flashlight_capture),sizeof(CAL_CDT_FLASHLIGHT_CAPTURE_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;	
	cnf->result.flash_lut.ispgain = CctDataOut.ispgain;
	cnf->result.flash_lut.sensorgain = CctDataOut.sensorgain;
	cnf->result.flash_lut.shutter = CctDataOut.shutter;
	
	xenon_flash_ft_test |= 0x08;

	  return ret;
}

// FT_CCT_OP_DEV_MODE_SIZE: 86
kal_uint8  ft_cct_dev_mode_size(FT_CCT_CNF *cnf){
	cnf->result.mode_size.width = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].width;
	cnf->result.mode_size.height = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].height;
	cnf->result.mode_size.preview_width = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_width;
	cnf->result.mode_size.preview_height = g_FT_CCT_StateMachine.sensor_onboard_sensors.sensor[0].preview_height;
	return FT_CNF_OK;
}

// FT_CCT_OP_DEV_FLASHLIGHT_TYPE: 87
kal_uint8  ft_cct_dev_flashlight_type(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_TYPE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.flash_type = CctDataOut;
	return ret;
}

// FT_CCT_OP_DEV_GET_ISO_GAIN_CCT: 88
kal_uint8  ft_cct_dev_get_iso_gain_cct(FT_CCT_CNF *cnf){
	
	kal_uint8	 ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_DEV_ISO_GAIN CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_DEV_ISO_GAIN));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_ISO_GAIN;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;	 
	kal_mem_cpy(&(cnf->result.dev_get_iso_gain.gain), &CctDataOut, sizeof(CAL_CCT_DEV_ISO_GAIN)); 

	return ret;
}

// FT_CCT_OP_DEV_SET_ISO_GAIN_CCT: 89
kal_uint8  ft_cct_dev_set_iso_gain_cct(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
        CAL_CCT_DEV_ISO_GAIN CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEV_ISO_GAIN));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_ISO_GAIN;
	CctDataIn.gain[0]= req->cmd.dev_set_iso_gain.gain[0];
	CctDataIn.gain[1]= req->cmd.dev_set_iso_gain.gain[1];
	CctDataIn.gain[2]= req->cmd.dev_set_iso_gain.gain[2];
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_GET_ISO_VALUE_CCT: 90
kal_uint8  ft_cct_dev_get_iso_value_cct(FT_CCT_CNF *cnf){
	
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_DEV_ISO_VALUE  CctDataOut ;  

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_DEV_ISO_VALUE));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_ISO_VALUE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	
	kal_mem_cpy(&(cnf->result.dev_get_iso_value.value), &CctDataOut, sizeof(CAL_CCT_DEV_ISO_VALUE)); 

	return ret;
}

// FT_CCT_OP_DEV_SET_ISO_VALUE_CCT: 91
kal_uint8  ft_cct_dev_set_iso_value_cct(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_DEV_ISO_VALUE CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEV_ISO_VALUE));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_ISO_VALUE;
	CctDataIn.value[0]= req->cmd.dev_set_iso_value.value[0];
	CctDataIn.value[1]= req->cmd.dev_set_iso_value.value[1];
	CctDataIn.value[2]= req->cmd.dev_set_iso_value.value[2];
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_OP_DEV_IF_SUPPORT_ISO: 92
kal_uint8  ft_cct_dev_is_support_iso(){

	  return FT_CNF_OK;
}

// FT_CCT_OP_DEV_GET_FLASH_LEVEL: 93
//danbo wait return function
kal_uint8  ft_cct_get_flash_level(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_FLASH_LEVEL;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.flash_charge_level = CctDataOut;
	return ret;
	
}

// FT_CCT_OP_DEV_SET_FLASH_LEVEL: 94
kal_uint8  ft_cct_set_flash_level(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32 CctDataIn; 
	kal_bool   CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_FLASH_LEVEL;
	CctDataIn = req->cmd.flash_charge_level;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	return ret;
}

// FT_CCT_OP_DEV_SET_FLASH_AE_INDEX: 95
kal_uint8  ft_cct_set_flash_ae_index(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataIn;
	AE_EXPOSURE_LUT_STRUCT  CctDataOut;
  
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(AE_EXPOSURE_LUT_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_SET_FLASH_AE_INDEX;
	CctDataIn = req->cmd.dev_ae_set_table_index;	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	} 
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;		
	cnf->result.flash_lut.ispgain = CctDataOut.ispgain;
	cnf->result.flash_lut.sensorgain = CctDataOut.sensorgain;
	cnf->result.flash_lut.shutter = CctDataOut.shutter;
	  return ret;
}

// FT_CCT_OP_DEV_GET_FLASH_AE_INDEX: 96
kal_uint8  ft_cct_get_flash_ae_index(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;
  
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_DEV_GET_FLASH_AE_INDEX;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	} 
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.ae_index = CctDataOut;
	  return ret;

}

// FT_CCT_6238_OP_AE_SET_SCENE_MODE: 99
kal_uint8  ft_cct_6238_ae_set_scene_mode(kal_uint8 scene_mode){

	kal_uint8	ret = FT_CNF_OK;
	kal_bool current_ae_enable = g_FT_CCT_StateMachine.ae_enable;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	AE_LUT_INFO_STRUCT  CctDataIn;  

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(AE_LUT_INFO_STRUCT));
  
	// AE shoule be enabled this moment
	if(!g_FT_CCT_StateMachine.ae_enable) {
		ft_cct_6238_ae_enable(KAL_TRUE);
	}
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SET_SCENE_MODE;
	CctDataIn.DscMode = scene_mode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}
	
	  // back to the original AE disalbe state
	  if(current_ae_enable !=  g_FT_CCT_StateMachine.ae_enable){
		  ft_cct_6238_ae_enable(current_ae_enable);
	  }
	  return ret;
}

// FT_CCT_6238_OP_AE_SET_METERING_MODE: 100
kal_uint8  ft_cct_6238_ae_set_metering_mode(kal_uint8 mode){

	kal_uint8	ret = FT_CNF_OK;
	kal_bool current_ae_enable = g_FT_CCT_StateMachine.ae_enable;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 CctDataIn;  

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	// AE shoule be enabled this moment
	if(!g_FT_CCT_StateMachine.ae_enable) {
		ft_cct_6238_ae_enable(KAL_TRUE);
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SET_METERING_MODE;
	CctDataIn = mode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}	
	// back to the original AE disalbe state
	if(current_ae_enable !=  g_FT_CCT_StateMachine.ae_enable){
		ft_cct_6238_ae_enable(current_ae_enable);
	}
	return ret;

}

// FT_CCT_6238_OP_AE_GET_CURRENT_EXPO_INFO: 101
kal_uint8  ft_cct_6238_ae_get_current_expo_info(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
	ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_CURRENT_EXPO_INFO;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;

	kal_mem_cpy(&(cnf->result.get_6238_ae_current_expo_info_cnf), &CctDataOut, sizeof(CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT)); 

	// if original preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
	g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}  

	return ret;
}

// FT_CCT_6238_OP_AE_APPLY_EXPO_INFO: 102
kal_uint8 ft_cct_6238_ae_apply_expo_info(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	kal_bool current_ae_enable = g_FT_CCT_StateMachine.ae_enable;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT CctDataIn ; 

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT));

	// disable AE
	if( g_FT_CCT_StateMachine.ae_enable ) {
		ft_cct_6238_ae_enable(KAL_FALSE);
	}

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_APPLY_EXPO_INFO;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_ae_expo_info_eq), sizeof(CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	// back to the original AE disalbe state
	if(current_ae_enable !=  g_FT_CCT_StateMachine.ae_enable){
		ft_cct_6238_ae_enable(current_ae_enable);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_SELECT_BAND: 103
kal_uint8  ft_cct_6238_ae_select_band(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	kal_bool current_ae_enable = g_FT_CCT_StateMachine.ae_enable;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 CctDataIn = (req->cmd.dev_6238_ae_select_band);

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	// should enable AE
	if(!g_FT_CCT_StateMachine.ae_enable) {
		ft_cct_6238_ae_enable(KAL_TRUE);		
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SELECT_BAND;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}	

	// back to the original AE disalbe state
	if(current_ae_enable !=  g_FT_CCT_StateMachine.ae_enable){
		ft_cct_6238_ae_enable(current_ae_enable);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_GET_AUTO_EXPO_PARA: 104
kal_uint8  ft_cct_6238_ae_get_auto_expo_para(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_EXPO_SETTING_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_EXPO_SETTING_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_AUTO_EXPO_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_auto_expo_para), &CctDataOut, sizeof(CAL_CCT_AE_EXPO_SETTING_STRUCT));
	return ret;

}

// FT_CCT_6238_OP_AE_GET_ISO_VALUE_GAIN: 105
kal_uint8  ft_cct_6238_ae_get_iso_value_gain(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_ISO_LUT_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_ISO_LUT_STRUCT));
  
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_ISO_VALUE_GAIN;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	} 
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_iso_value_gain), &CctDataOut, sizeof(CAL_CCT_AE_ISO_LUT_STRUCT));
	
	  return ret;

}

// FT_CCT_6238_OP_AE_GET_GAMMA_PARA: 106
kal_uint8  ft_cct_6238_ae_get_gamma_para(FT_CCT_CNF *cnf){

	/*
	aeGammaSettingStruct* gammaPara = (aeGammaSettingStruct *)&(cnf->result.get_6238_ae_gamma_para);

	aeCctGetGammaPara(gammaPara);
	*/

	return FT_CCT_ERR_NOT_IMPLEMENT_YET;

}

// FT_CCT_6238_OP_AE_GET_GAMMA_TABLE: 107
kal_uint8  ft_cct_6238_ae_get_gamma_table(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_GAMMA_TABLE_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_GAMMA_TABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_TABLE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_gamma_table), &CctDataOut, sizeof(CAL_CCT_AE_GAMMA_TABLE_STRUCT));

	return ret;

}

// FT_CCT_6238_OP_AE_GET_FLARE_PARA: 108
kal_uint8  ft_cct_6238_ae_get_flare_para(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_FLARE_SETTING_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_REG_RW_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_FLARE_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_flare_para), &CctDataOut, sizeof(CAL_CCT_AE_FLARE_SETTING_STRUCT));

	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_AUTO_EXPO_PARA: 109
kal_uint8  ft_cct_6238_ae_update_auto_expo_para(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_EXPO_SETTING_STRUCT CctDataIn ;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_EXPO_SETTING_STRUCT));

	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}	

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_AUTO_EXPO_PARA;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_ae_auto_expo_para), sizeof(CAL_CCT_AE_EXPO_SETTING_STRUCT));
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	ret = FT_CNF_FAIL;
	}

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_ISO_VALUE_GAIN: 110
kal_uint8  ft_cct_6238_ae_update_iso_value_gain(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_ISO_LUT_STRUCT CctDataIn ;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_ISO_LUT_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_ISO_VALUE_GAIN;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_ae_iso_value_gain), sizeof(CAL_CCT_AE_ISO_LUT_STRUCT));
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	  ret = FT_CNF_FAIL;
	}
	
	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARA: 111
kal_uint8  ft_cct_6238_ae_update_gamma_para(const FT_CCT_REQ *req){

  return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_AE_UPDATE_FLARE_PARA: 112
kal_uint8  ft_cct_6238_ae_update_flare_para(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_FLARE_SETTING_STRUCT CctDataIn ;
	
	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_FLARE_SETTING_STRUCT));
	
	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_FLARE_PARA;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_ae_flare_para), sizeof(CAL_CCT_AE_FLARE_SETTING_STRUCT));
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}	

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}
	return ret;
}

// FT_CCT_6238_OP_AE_GET_HISTOGRAM: 113
kal_uint8  ft_cct_6238_ae_get_flare_histogram( FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}	

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_HISTOGRAM;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_flare_histogram), &CctDataOut, sizeof(CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT));

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}
	return ret;
	
}

// FT_CCT_6238_OP_AE_GET_METERING_RESULT: 114
kal_uint8  ft_cct_6238_ae_get_metering_result( FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT CctDataOut;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    
	//aeCctCurrentMeteringResultStruct* meteringResult = (aeCctCurrentMeteringResultStruct *)&(cnf->result.get_6238_ae_metering_result);

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT));	

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_RESULT;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_metering_result), &CctDataOut, sizeof(CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT));

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}
	return ret;	

}

// FT_CCT_6238_OP_AE_GET_METERING_MODE_SETTING: 115
kal_uint8  ft_cct_6238_ae_get_metering_mode_setting(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_METERING_SETTING_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_METERING_SETTING_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_MODE_SETTING;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_ae_metering_mode_setting), &CctDataOut, sizeof(CAL_CCT_AE_METERING_SETTING_STRUCT));

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_METERING_MODE_SETTING: 116
kal_uint8  ft_cct_6238_ae_update_metering_mode_setting( const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AE_METERING_SETTING_STRUCT  CctDataIn ;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_METERING_SETTING_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_METERING_MODE_SETTING;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_ae_metering_mode_setting), sizeof(CAL_CCT_AE_METERING_SETTING_STRUCT));
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}
	return ret;

}

// FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM: 117
kal_uint8  ft_cct_6238_ae_get_window_histogram(FT_CCT_CNF *cnf){

	return FT_CCT_ERR_NOT_IMPLEMENT_YET;

}

// FT_CCT_6238_OP_AE_GET_SMOOTH_MODE_SETTING: 118
kal_uint8  ft_cct_6238_ae_get_smooth_mode_setting( const FT_CCT_REQ *req,  FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;
	
	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 CctDataIn ;
	kal_uint8* pCctDataOut ;
	kal_uint8 ae_setting_buffer [40]; //20
	pCctDataOut = ae_setting_buffer;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	
	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
    //RegGetOutLen = CctDataSizeOut.AeSmoothModeStructSize;

	//kal_mem_set(pCctDataOut, 0, RegGetOutLen);
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_SMOOTH_MODE_SETTING;
        CctDataIn = req->cmd.dev_6238_ae_scene_mode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = pCctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	
	kal_mem_cpy(&(cnf->result.get_6238_ae_smooth_mode_setting), pCctDataOut, RegOutLen);

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}
	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_SMOOTH_MODE_SETTING: 119
kal_uint8  ft_cct_6238_ae_update_smooth_mode_setting(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegGetOutLen = 0;

	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;  

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 *pCctDataIn;
	kal_uint8 ae_setting_buffer [40]; //20
	pCctDataIn = ae_setting_buffer;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
        RegGetOutLen = CctDataSizeOut.AeSmoothModeStructSize;
 
	kal_mem_cpy(pCctDataIn, &(req->cmd.dev_6238_ae_smooth_mode_setting), RegGetOutLen);

	//kal_mem_set(pCctDataIn, 0, RegGetOutLen);
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_SMOOTH_MODE_SETTING;
	CCTfeatureCtrlIn.pCctFeatureParaIn = pCctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	// if original preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}  

	return ret;

}

// FT_CCT_6238_OP_AE_ENABLE_PREVIEW_LOG: 120 ,121
kal_uint8  ft_cct_6238_ae_enable_preview_log(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_ENABLE_PREVIEW_LOG; 		
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_DISABLE_PREVIEW_LOG;
	}

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AE_GET_PREVIEW_EXPO_INFO: 122
kal_uint8  ft_cct_6238_ae_get_preview_expo_info(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT));
	
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_PREVIEW_EXPO_INFO;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	
	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
	 ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	//cnf->result.reg_read.value_len =  RegOutLen;

	kal_mem_cpy(&(cnf->result.get_6238_ae_preview_expo_info), &CctDataOut, sizeof(CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT));

	  return ret;

}

// FT_CCT_6238_OP_AWB_ENABLE_PREF_GAIN: 123 , 124
kal_uint8  ft_cct_6238_awb_enable_pref_gain(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_PREF_GAIN; 		
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_PREF_GAIN;
	}

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

// FT_CCT_6238_OP_AWB_ENABLE_FAST_CONVERGE: 125 , 126
kal_uint8  ft_cct_6238_awb_enable_fast_converge(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_FAST_CONVERGE; 		
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_FAST_CONVERGE;
	}

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}  

	return ret;

}

// FT_CCT_6238_OP_AWB_ENABLE_AUTO_RUN: 127 , 128
kal_uint8  ft_cct_6238_awb_enable_auto_run(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_AUTO_RUN; 		
		g_FT_CCT_StateMachine.wb_activated_idx = FT_CCT_WB_AUTO;
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_AUTO_RUN;
		g_FT_CCT_StateMachine.wb_activated_idx = FT_CCT_WB_OFF;
	}

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}  

	return ret;

}

// FT_CCT_6238_OP_AWB_ENABLE_SMALL_BOX: 129 , 130
kal_uint8  ft_cct_6238_awb_enable_small_box(const FT_CCT_REQ *req, kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	kal_uint32  CctDataIn;	

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CctDataIn = req->cmd.dev_6238_awb_small_box_light_source;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_SMALL_BOX; 		
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_SMALL_BOX;
	}	

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}  

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY: 131
kal_uint8  ft_cct_6238_awb_get_window_whit_point_count_array(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AWB_WHITE_COUNT_STRUCT CctDataOut ;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AWB_WHITE_COUNT_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_window_whit_point), &CctDataOut, sizeof(CAL_CCT_AWB_WHITE_COUNT_STRUCT));

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_LIGHT_MODE: 132
kal_uint8  ft_cct_6238_awb_get_light_mode(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));	
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_LIGHT_MODE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_awb_light_mode = CctDataOut;

	return ret;
}

// FT_CCT_6238_OP_AWB_GET_GAIN: 133
kal_uint8  ft_cct_6238_awb_get_gain(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AWB_GAIN_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AWB_GAIN_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_GAIN;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_gain), &CctDataOut, sizeof(CAL_CCT_AWB_GAIN_STRUCT)); 

	return ret;
}

// FT_CCT_6238_OP_AWB_SET_GAIN: 134
kal_uint8  ft_cct_6238_awb_set_gain(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AWB_GAIN_STRUCT CctDataIn;  

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AWB_GAIN_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_SET_GAIN;
	CctDataIn.awbRgain = req->cmd.dev_6238_awb_set_gain.awbRgain;
	CctDataIn.awbGgain = req->cmd.dev_6238_awb_set_gain.awbGgain;
	CctDataIn.awbBgain = req->cmd.dev_6238_awb_set_gain.awbBgain;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

// FT_CCT_6238_OP_AWB_SET_PREF_FACTOR: 135
kal_uint8  ft_cct_6238_awb_set_pref_factor(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AWB_PREF_FACTOR_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AWB_PREF_FACTOR_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_SET_PREF_FACTOR;
	kal_mem_cpy(&CctDataIn, &req->cmd.dev_6238_awb_set_pref_factor, sizeof(CAL_CCT_AWB_PREF_FACTOR_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_PREF_FACTOR: 136
kal_uint8  ft_cct_6238_awb_get_pref_factor(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AWB_PREF_FACTOR_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AWB_PREF_FACTOR_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_PREF_FACTOR;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_pref_factor), &CctDataOut, sizeof(CAL_CCT_AWB_PREF_FACTOR_STRUCT));
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;

}

// FT_CCT_6238_OP_AWB_ENABLE_DYNAMIC_CCM: 137 , 138
kal_uint8  ft_cct_6238_awb_enable_dynamic_ccm(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;
	
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_DYNAMIC_CCM; 		
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_DYNAMIC_CCM;
	}

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	  return ret;

}

// FT_CCT_6238_OP_AWB_GET_CURRENT_CCM: 139
kal_uint8  ft_cct_6238_awb_get_current_ccm(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_CCM_STRUCT  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_CCM_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_CURRENT_CCM;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_current_ccm), &CctDataOut, sizeof(CAL_CCT_CCM_STRUCT));
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_AWB_ENABLE_FLASH_SYNC: 140 , 141
kal_uint8   ft_cct_6238_awb_enable_flash_sync(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_FLASH_SYNC;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_FLASH_SYNC;
	}

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

// FT_CCT_6238_OP_AWB_APPLY_CAMERA_PARA2: 142
kal_uint8   ft_cct_6238_awb_apply_camera_para2_to_reg(){

	kal_uint8 ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_APPLY_CAMERA_PARA2;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AWB_UPDATE_CAMERA_PARA2: 143
kal_uint8   ft_cct_6238_awb_update_camera_para2_from_req(){

	kal_uint8 ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CAMERA_PARA2;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AWB_GET_NVRAM_CCM: 144
kal_uint8   ft_cct_6238_awb_get_nvram_ccm(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_CCM_LIGHTMODE_STRUCT CctDataIn, CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_CCM_LIGHTMODE_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_CCM_LIGHTMODE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_NVRAM_CCM;
	CctDataIn.CCMLightMode = (CCM_MODE_ENUM)req->cmd.dev_6238_awb_light_source_mode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy((CAL_CCT_CCM_STRUCT *)&(cnf->result.get_6238_awb_nvram_ccm), &(CctDataOut.CCM), sizeof(CAL_CCT_CCM_STRUCT) );

	return ret;

}

// FT_CCT_6238_OP_AWB_SET_NVRAM_CCM: 145
kal_uint8   ft_cct_6238_awb_set_nvram_ccm(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_CCM_LIGHTMODE_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_CCM_LIGHTMODE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_SET_NVRAM_CCM;
	CctDataIn.CCMLightMode = (CCM_MODE_ENUM)req->cmd.dev_6238_awb_nvram_ccm.lightSourceMode;
	kal_mem_cpy(&(CctDataIn.CCM), (CAL_CCT_CCM_STRUCT *)&(req->cmd.dev_6238_awb_nvram_ccm.nvram_ccm), sizeof(CAL_CCT_CCM_STRUCT) );
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}	

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_AWB_PARA: 146
kal_uint8   ft_cct_6238_awb_get_awb_para(FT_CCT_CNF *cnf){

	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_AWB_GET_CCM_PARA: 147
kal_uint8   ft_cct_6238_awb_get_ccm_para(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0 ;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	//void *pCctDataOut;
	kal_uint8 ccm_buffer [56]; //28
	kal_uint8 *pCctDataOut = ccm_buffer ;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	//RegOutGetLen = CctDataSizeOut.CcmParaSize;

	//kal_mem_set(pCctDataOut, 0, RegOutGetLen); 
	//pCctDataOut = (void *) new(RegOutGetLen);
	//pCctDataOut = (void *) malloc (RegOutGetLen);
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_CCM_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = pCctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_cmm_para), pCctDataOut, RegOutLen );
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;

}

// FT_CCT_6238_OP_AWB_UPDATE_AWB_PARA: 148
kal_uint8  ft_cct_6238_awb_update_awb_para( const FT_CCT_REQ *req){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_AWB_UPDATE_CCM_PARA: 149
kal_uint8  ft_cct_6238_awb_update_ccm_para( const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;
	kal_uint32 RegGetOutLen = 0;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 *pCctDataIn;
	kal_uint8 ccm_buffer [56]; //28
	pCctDataIn= ccm_buffer ;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

 	ret = ft_cct_get_struct_size(&CctDataSizeOut);
        RegGetOutLen = CctDataSizeOut.CcmParaSize;

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CCM_PARA;
	kal_mem_cpy(pCctDataIn, &(req->cmd.dev_6238_awb_cmm_para), RegGetOutLen); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = pCctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AWB_GET_AWB_STATUS: 150
kal_uint8  ft_cct_6238_awb_get_awb_status(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AWB_STATUS_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AWB_STATUS_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_AWB_STATUS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_awb_status), &CctDataOut, sizeof(CAL_CCT_AWB_STATUS_STRUCT)); 

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_CCM_STATUS: 151
kal_uint8  ft_cct_6238_awb_get_ccm_status(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_CCM_STATUS_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_CCM_STATUS_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_CCM_STATUS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_awb_cmm_status), &(CctDataOut.DynamicCcmEn), RegOutLen );

	return ret;

}

// FT_CCT_6238_OP_AWB_UPDATE_AWB_STATUS: 152
kal_uint8  ft_cct_6238_awb_update_awb_status( const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_AWB_STATUS_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AWB_STATUS_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_AWB_STATUS;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_awb_awb_status), sizeof(CAL_CCT_AWB_STATUS_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AWB_UPDATE_CCM_STATUS: 153
kal_uint8  ft_cct_6238_awb_update_ccm_status( const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_CCM_STATUS_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_CCM_STATUS_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CCM_STATUS;
	CctDataIn.DynamicCcmEn = req->cmd.dev_6238_awb_ccm_status.DynamicCcmEn;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	return ret;
}

// FT_CCT_6238_OP_AWB_SET_CURRENT_CCM: 154
kal_uint8  ft_cct_6238_awb_set_current_ccm( const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_CCM_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_SET_CURRENT_CCM;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_awb_current_ccm), sizeof(CAL_CCT_CCM_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

//danbo note: This  function To change CCT  Shading Para Struct  To  ISP Shading Para Struct
// CCT  Tools Shading Para Struct Item Use  Uint 8, Uint 16 and  Uint 32.
//But  ISP Shading Para Struct Item all use Uint 32

void Struct_Item_Unit_To_Unit32(cct_shading_comp_struct *PISP_ShadingComp,cct_shading_comp_tool_struct *PSet_Shading_Para){

	PISP_ShadingComp->SDBLK_TRIG = (kal_uint32)(PSet_Shading_Para->SDBLK_TRIG);
	PISP_ShadingComp->SHADING_EN = (kal_uint32)(PSet_Shading_Para->SHADING_EN );
	PISP_ShadingComp->SHADINGBLK_XOFFSET = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_XOFFSET);
	PISP_ShadingComp->SHADINGBLK_YOFFSET = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_YOFFSET);
	PISP_ShadingComp->SHADINGBLK_XNUM = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_XNUM);
	PISP_ShadingComp->SHADINGBLK_YNUM = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_YNUM );
	PISP_ShadingComp->SHADINGBLK_WIDTH = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_WIDTH );
	PISP_ShadingComp->SHADINGBLK_HEIGHT = (kal_uint32)(PSet_Shading_Para->SHADINGBLK_HEIGHT );
	PISP_ShadingComp->SHADING_RADDR = (PSet_Shading_Para->SHADING_RADDR);
	PISP_ShadingComp->SD_LWIDTH = (kal_uint32)(PSet_Shading_Para->SD_LWIDTH );
	PISP_ShadingComp->SD_LHEIGHT = (kal_uint32)(PSet_Shading_Para->SD_LHEIGHT );
	PISP_ShadingComp->SDBLK_RATIO00 = (kal_uint32)(PSet_Shading_Para->SDBLK_RATIO00 );
	PISP_ShadingComp->SDBLK_RATIO01 = (kal_uint32)(PSet_Shading_Para->SDBLK_RATIO01 );
	PISP_ShadingComp->SDBLK_RATIO10 = (kal_uint32)(PSet_Shading_Para->SDBLK_RATIO10 );
	PISP_ShadingComp->SDBLK_RATIO11 = (kal_uint32)(PSet_Shading_Para->SDBLK_RATIO11 );
	PISP_ShadingComp->SD_TABLE_SIZE = (PSet_Shading_Para->SD_TABLE_SIZE );
	
}


// FT_CCT_6238_OP_ISP_SET_SHADING_PARA: 155
kal_uint8  ft_cct_6238_isp_set_shading_para( const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_SHADING_COMP_STRUCT CctDataIn;
	cct_shading_comp_struct ISP_ShadingComp;
	cct_shading_comp_tool_struct CCT_ShadingComp;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	//kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_REG_RW_STRUCT));
	kal_mem_set(&ISP_ShadingComp, 0, sizeof(cct_shading_comp_struct));
	kal_mem_set(&CCT_ShadingComp, 0, sizeof(cct_shading_comp_tool_struct));

	// check if isp supports shading compensation 
	if(!isp_cct_is_shading_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_PARA;
	CctDataIn.SHADING_MODE = (kal_uint8)g_FT_CCT_StateMachine.comp_mode;
	
	kal_mem_cpy(&(CCT_ShadingComp), (cct_shading_comp_struct *)&req->cmd.set_shading_para, sizeof(cct_shading_comp_struct) );

	//CCT_ShadingComp.SHADING_RADDR = 0X4000FE00;
	
	Struct_Item_Unit_To_Unit32(&(ISP_ShadingComp),&(CCT_ShadingComp));	
	
	CctDataIn.pShadingComp = &ISP_ShadingComp;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}


//danbo note: This  function To change ISP Shading Para Struct To CCT  Shading Para Struct 
//ISP Shading Para Struct Item all use Uint 32
//But  CCT  Tools Shading Para Struct Item Use  Uint 8, Uint 16 and  Uint 32.

#define    UNIT32_TO_UNIT8      0xFF
#define    UNIT32_TO_UNIT16      0xFFFF

void Struct_Item_Unit32_To_Unit(cct_shading_comp_tool_struct *PGet_Shading_Para,cct_shading_comp_struct *PISP_ShadingComp){
	PGet_Shading_Para->SDBLK_TRIG = (kal_uint8)(PISP_ShadingComp->SDBLK_TRIG & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADING_EN = (kal_uint8)(PISP_ShadingComp->SHADING_EN & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADINGBLK_XOFFSET = (kal_uint8)(PISP_ShadingComp->SHADINGBLK_XOFFSET & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADINGBLK_YOFFSET = (kal_uint8)(PISP_ShadingComp->SHADINGBLK_YOFFSET & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADINGBLK_XNUM = (kal_uint8)(PISP_ShadingComp->SHADINGBLK_XNUM & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADINGBLK_YNUM = (kal_uint8)(PISP_ShadingComp->SHADINGBLK_YNUM & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SHADINGBLK_WIDTH = (kal_uint16)(PISP_ShadingComp->SHADINGBLK_WIDTH & UNIT32_TO_UNIT16);
	PGet_Shading_Para->SHADINGBLK_HEIGHT = (kal_uint16)(PISP_ShadingComp->SHADINGBLK_HEIGHT & UNIT32_TO_UNIT16);
	PGet_Shading_Para->SHADING_RADDR = (PISP_ShadingComp->SHADING_RADDR);
	PGet_Shading_Para->SD_LWIDTH = (kal_uint16)(PISP_ShadingComp->SD_LWIDTH & UNIT32_TO_UNIT16);
	PGet_Shading_Para->SD_LHEIGHT = (kal_uint16)(PISP_ShadingComp->SD_LHEIGHT & UNIT32_TO_UNIT16);
	PGet_Shading_Para->SDBLK_RATIO00 = (kal_uint8)(PISP_ShadingComp->SDBLK_RATIO00 & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SDBLK_RATIO01 = (kal_uint8)(PISP_ShadingComp->SDBLK_RATIO01 & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SDBLK_RATIO10 = (kal_uint8)(PISP_ShadingComp->SDBLK_RATIO10 & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SDBLK_RATIO11 = (kal_uint8)(PISP_ShadingComp->SDBLK_RATIO11 & UNIT32_TO_UNIT8);
	PGet_Shading_Para->SD_TABLE_SIZE =  (PISP_ShadingComp->SD_TABLE_SIZE );
	
}

// FT_CCT_6238_OP_ISP_GET_SHADING_PARA: 156
kal_uint8  ft_cct_6238_isp_get_shading_para(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 CctDataIn;
	CAL_CCT_SHADING_COMP_STRUCT CctDataOut;
	cct_shading_comp_struct Shading_Com;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	//kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_SHADING_COMP_STRUCT));
	kal_mem_set(&Shading_Com, 0, sizeof(cct_shading_comp_struct));


	if(!isp_cct_is_shading_supported()) {
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_PARA;
	CctDataIn = (kal_uint8 )g_FT_CCT_StateMachine.comp_mode;
	CctDataOut.SHADING_MODE = CctDataIn;
	CctDataOut.pShadingComp = &Shading_Com;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	
	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	//kal_mem_cpy(&(cnf->result.get_shading_para), &(Get_Shading_Para), sizeof(cct_shading_comp_tool_struct) );
	Struct_Item_Unit32_To_Unit(&(cnf->result.get_shading_para),(CctDataOut.pShadingComp));
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;

}

// FT_CCT_6238_OP_ISP_ENABLE_DYNAMIC_BYPASS_MODE: 157 , 158
kal_uint8  ft_cct_6238_isp_enable_dynamic_bypass_mode(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_ENABLE_DYNAMIC_BYPASS_MODE;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_DISABLE_DYNAMIC_BYPASS_MODE;
	}

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;

}

// FT_CCT_6238_OP_ISP_GET_TUNING_PARA: 159
kal_uint8  ft_cct_6238_isp_get_tuning_para(FT_CCT_CNF *cnf){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;

}

// FT_CCT_6238_OP_ISP_SET_TUNING_PARA: 160
kal_uint8  ft_cct_6238_isp_set_tuning_para(const FT_CCT_REQ *req){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_ISP_GET_PARTIAL_SHADING_TABLE: 161
kal_uint8  ft_cct_6238_isp_get_partial_shading_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_ISP_SET_PARTIAL_SHADING_TABLE: 162
kal_uint8  ft_cct_6238_isp_set_partial_shading_table(const FT_CCT_REQ *req){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_ISP_SET_SHADING_ON_OFF: 163
kal_uint8  ft_cct_6238_isp_set_shading_on_off(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_MODULE_CTRL_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_MODULE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_ON_OFF;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)req->cmd.dev_6238_isp_shading_status.mode;
	CctDataIn.Enable = req->cmd.dev_6238_isp_shading_status.m_switch;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_SHADING_ON_OFF: 164
kal_uint8  ft_cct_6238_isp_get_shading_on_off(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) {
	
	kal_uint8	ret = FT_CNF_OK;
	 kal_uint32 RegOutLen = 0;

	ispShadingStatusMsg *ptrMessage = (ispShadingStatusMsg *)&(req->cmd.dev_6238_isp_shading_status);

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_MODULE_CTRL_STRUCT CctDataIn, CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_MODULE_CTRL_STRUCT));
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_MODULE_CTRL_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_ON_OFF;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)ptrMessage->mode;    
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	//cnf->result.reg_read.value_len =	RegOutLen;
	cnf->result.get_6238_isp_shading_status.m_switch = CctDataOut.Enable;
 
	return ret;
}

// FT_CCT_6238_OP_AE_GET_SCENE_MODE: 165
kal_uint8  ft_cct_6238_ae_get_scene_mode(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_SCENE_MODE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_ae_scene_mode = CctDataOut;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_AE_GET_METERING_MODE: 166
kal_uint8  ft_cct_6238_ae_get_metering_mode(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_MODE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_ae_metering_mode = CctDataOut;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_AE_GET_BAND: 167
kal_uint8  ft_cct_6238_ae_get_band(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_BAND;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_ae_band = CctDataOut;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_AE_SET_GAMMA_BYPASS: 168
kal_uint8  ft_cct_6238_ae_set_gamma_bypass(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	//kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	if(req->cmd.dev_6238_ae_gamma_bypass)
	{
		g_FT_CCT_StateMachine.gamma_bypass = KAL_TRUE;		
	}
	else
	{
		g_FT_CCT_StateMachine.gamma_bypass = KAL_FALSE; 	
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_SET_GAMMA_BYPASS;
	CctDataIn.Enable = (kal_bool)req->cmd.dev_6238_ae_gamma_bypass;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AE_GET_GAMMA_BYPASS_FLAG: 169
kal_uint8  ft_cct_6238_ae_get_gamma_bypass_flag(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_BYPASS_FLAG;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6283_ae_gamma_bypass_flag = CctDataOut.Enable;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_ISP_SET_TUNING_INDEX: 170
kal_uint8  ft_cct_6238_isp_set_tuning_index(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;
	CAL_ISP_CATEGORY_ENUM i;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_ISP_TUNING_SET CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_ISP_TUNING_SET));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_TUNING_INDEX;
	for(i = ISP_CATEGORY_NR1; i < ISP_CATEGORY_AUTO_SHADING; i ++)
	{		 
                CctDataIn.index = i;
		CctDataIn.value = req->cmd.dev_6238_isp_tuning_setting_index_value.value[i];
		CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
		CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

		if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}
		else
		{
			ret = FT_CNF_OK;
		}
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_TUNING_INDEX: 171
kal_uint8  ft_cct_6238_isp_get_tuning_index(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;
	CAL_ISP_CATEGORY_ENUM i;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_ISP_TUNING_SET CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_ISP_TUNING_SET));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_TUNING_INDEX;
	for(i = ISP_CATEGORY_NR1; i < ISP_CATEGORY_AUTO_SHADING; i ++)
	{
		//danbo note this function use out para transfer in para
		CctDataOut.index = i;
		CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
		CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
		CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
		if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
		{
			ret = FT_CNF_FAIL;
		}  
		//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
		cnf->result.get_6238_isp_tuning_setting_index_value.value[i] = CctDataOut.value;
		//cnf->result.reg_read.value_len =  RegOutLen;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_AE_TOTAL_GAIN: 172
kal_uint8  ft_cct_6238_isp_get_ae_total_gain(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_AE_TOTAL_GAIN;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_isp_ae_total_gain = CctDataOut;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF: 173
kal_uint8  ft_cct_6238_isp_get_dynamic_bypass_mode_on_off(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_isp_dynamic_bypass_mode_on_off = CctDataOut.Enable;
	//cnf->result.reg_read.value_len =  RegOutLen;

	return ret;
}

// FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_PRESTROBE: 174
kal_uint8  ft_cct_6238_isp_flash_linearity_prestrobe(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8   CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	//isp_cdt_data = req->cmd.dev_6238_isp_flashlight_cdt_capture;

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_LINEARITY_PRESTROBE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	return ret;
}

// FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULT: 175
kal_uint8  ft_cct_6238_isp_flash_linearity_result(FT_CCT_CNF *cnf){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_ISP_GET_BINNING_MODE: 178
kal_uint8  ft_cct_6238_isp_get_binning_mode(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	
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
  #endif
  	cnf->result.get_6238_isp_binning_mode = sbCdtBinningMode;
	  return ret;
}

// FT_CCT_6238_OP_ISP_FLASHLIGHT_SET_AE_PARA_2: 179
kal_uint8  ft_cct_6238_isp_flashlight_set_ae_para_2(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CDT_FLASH_AE_PARA_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CDT_FLASH_AE_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_SET_AE_PARA;
	kal_mem_cpy(&CctDataIn, &(req->cmd.dev_6238_isp_flashlight_set_ae_para), sizeof(CAL_CDT_FLASH_AE_PARA_STRUCT)); 
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AF_GET_PARA: 180
kal_uint8  ft_cct_6238_af_get_para(FT_CCT_CNF *cnf){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_AF_SET_PARA: 181
kal_uint8  ft_cct_6238_af_set_para(const FT_CCT_REQ *req){
	return FT_CCT_ERR_NOT_IMPLEMENT_YET;
}

// FT_CCT_6238_OP_ISP_FLASHLIGHT_GET_AE_PARA_2: 182
kal_uint8  ft_cct_6238_isp_flashlight_get_ae_para_2(FT_CCT_CNF *cnf){
	
	kal_uint8   ret = FT_CNF_OK;
        kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CDT_FLASH_AE_PARA_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CDT_FLASH_AE_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_GET_AE_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,	(void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_isp_flashlight_cdt_capture),(CctDataOut.FlashAeCdtPara), sizeof(FLASH_AE_CDT_PARA_STRUCT));
	return ret;
}

// FT_CCT_6238_OP_ISP_GET_CAMCORDER_INFO: 183
kal_uint8  ft_cct_6238_isp_get_camcorder_info(FT_CCT_CNF *cnf){
	 
	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	camcorder_info_struct CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(camcorder_info_struct));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_CAMCORDER_INFO;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_isp_dev_camcorder_info), &CctDataOut, sizeof(camcorder_info_struct)); 
	return ret;
}

// FT_CCT_6238_OP_ISP_BYPASS_SHADING_MODE_ENABLE: 184 , 185
// danbo note this function not use ? wait return function ?
kal_uint8  ft_cct_isp_bypass_shading_mode(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_BYPASS_SHADING_MODE_ENABLE;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_BYPASS_SHADING_MODE_DISABLE;
	}

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_FLASH_DURATION_LUT: 187
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
kal_uint8  ft_cct_6238_flash_duration_lut(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CDT_XENON_DURATION  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CDT_XENON_DURATION));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_FLASH_DURATION_LUT;
	CctDataIn.pLutTriggerTime = (kal_uint16*)&(req->cmd.dev_6238_flash_duration_lut.lut_trigger_time);
	CctDataIn.pLutResultTime = (kal_uint16 *)&(req->cmd.dev_6238_flash_duration_lut.lut_result_time);
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}
#endif

// FT_CCT_6238_ISP_DEFECT_TABLE_ON: 188 ,189
kal_uint8  ft_cct_6238_isp_defect_table_enable(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_MODULE_CTRL_STRUCT  CctDataIn;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));	

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_ISP_DEFECT_TABLE_ON;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_ISP_DEFECT_TABLE_OFF;
	}

	CctDataIn.Enable = enable;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_SET_SHUTTER_MODE: 190
// danbo note Mshutter is not use 
kal_uint8  ft_cct_6238_set_shutter_mode(const FT_CCT_REQ *req){
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
#endif
	return FT_CNF_OK;
}
 
// FT_CCT_6238_OP_SET_SHUTTER_TARGET_TIME: 191
// danbo note Mshutter is not use 
kal_uint8  ft_cct_6238_set_shutter_target_time(const FT_CCT_REQ *req){
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
#endif
	return FT_CNF_OK;
}

// FT_CCT_6238_OP_SET_SHUTTER_DELAY_TIME: 192
// danbo note Mshutter is not use 
kal_uint8  ft_cct_6238_set_shutter_delay_time(const FT_CCT_REQ *req){
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
#endif
	return FT_CNF_OK;
}

// FT_CCT_6238_OP_GET_SHUTTER_G_CHANNEL_MEAN: 193
kal_uint8  ft_cct_6238_get_capture_center_g_channel_mean(FT_CCT_CNF *cnf){
	
   kal_uint8   ret = FT_CNF_OK;

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
#endif
	 return ret;
}

// FT_CCT_6238_OP_GET_SHUTTER_TARGET_TIME: 194
kal_uint8  ft_cct_6238_get_shutter_target_time(FT_CCT_CNF *cnf){

        kal_uint8   ret = FT_CNF_OK;
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
#endif
	return ret;
}

// FT_CCT_6238_OP_GET_SHUTTER_DELAY_TIME: 195
kal_uint8  ft_cct_6238_get_shutter_delay_time(FT_CCT_CNF *cnf){
			
	kal_uint8   ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

#if 1 
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_DELAY_TIME;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_shutter_delay_time = CctDataOut;
#endif
	return ret;
}

// FT_CCT_6238_OP_GET_SHUTTER_MODE: 196
kal_uint8  ft_cct_6238_get_shutter_mode(FT_CCT_CNF *cnf){
			
	kal_uint8   ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

#if 1  
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint32  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_MODE;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	//cnf->result.get_6238_shutter_mode = *pCctDataOut;
	//cnf->result.reg_read.value_len =  RegOutLen;
#endif
	return ret;
}

// FT_CCT_6238_OP_SET_SHUTTER_CALIBRATION_ENABLE: 197 , 198
kal_uint8  ft_cct_6238_COQC_shutter_calibration_enable(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;
	
	if(!custom_ft_util_check_if_camera_mshutter_support()){
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	g_b_COQC_MShutter = enable;
	  return ret;
}

// FT_CCT_6238_OP_GET_PREVIEW_TARGET_LINES: 199
kal_uint8  ft_cct_6238_ge_shuttert_preview_target_lines(const FT_CCT_REQ *req, FT_CCT_CNF *cnf){
	
	//kal_uint32 target_time = req->cmd.dev_6238_shutter_target_time_for_preview_target_lines;
	if(!custom_ft_util_check_if_camera_mshutter_support()){
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
//	cnf->result.get_6238_shutter_target_lines = mshutter_cct_get_preview_target_lines(target_time); 
	return FT_CNF_OK;
}

// FT_CCT_6238_OP_ENABLE_IMAGE_TRANSFER: 200 , 201
kal_uint8  ft_cct_6238_enable_transfer_image(kal_bool enable){
	if(!custom_ft_util_check_if_camera_mshutter_support()){
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}
	
	g_b_image_transfer = enable;
	return FT_CNF_OK;
}

// FT_CCT_6238_OP_ISP_ENABLE_AUTO_DEFECT: 202 , 203
kal_uint8  ft_cct_6238_enable_auto_defect(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_ENABLE_AUTO_DEFECT;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_DISABLE_AUTO_DEFECT;
	}

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_ISP_GET_DEFECT_TABLE: 204
//danbo note this function need update. 101128
kal_uint8  ft_cct_6238_isp_get_defect_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret){
		
	kal_uint8   ret = FT_CNF_OK;

	kal_uint16  pdu_length = 0;
	kal_char	 *pdu_ptr = NULL;

#if 1
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_DEFECT_TBL  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_DEFECT_TBL));

	*pp_peer_buff_ret = construct_peer_buff(sizeof(CAL_CCT_DEFECT_TBL), 0, 0, TD_CTRL);
	pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);		
	if(NULL == *pp_peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_GET_DEFECT_TBL;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(((CAL_CCT_DEFECT_TBL*)pdu_ptr), &CctDataOut, sizeof(CAL_CCT_DEFECT_TBL));
#endif
	return ret;
}

// FT_CCT_6238_ISP_SET_DEFECT_TABLE: 205
kal_uint8  ft_cct_6238_isp_set_defect_table(const FT_CCT_REQ *req,  ispTable *p_defect_table){
				
	kal_uint8   ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_DEFECT_PARA  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_DEFECT_PARA));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_OP_SET_CAMERA_DEFECT;
	CctDataIn.Mode = req->cmd.dev_6238_isp_defect_para.mode;
	CctDataIn.Length = req->cmd.dev_6238_isp_defect_para.length;
	CctDataIn.Offset = req->cmd.dev_6238_isp_defect_para.offset;
	//pCctDataIn->Data = p_defect_table->data;
	kal_mem_cpy((CctDataIn.Data), (p_defect_table->data), sizeof(ispTable));
	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_ISP_GET_SHADING_TABLE: 206
kal_uint8  ft_cct_6238_isp_get_shading_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret){
				
	kal_uint8   ret = FT_CNF_OK;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_TABLE_SET_STRUCT  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_TABLE_SET_STRUCT));

	cnf->result.get_6238_isp_shading_table_para.mode = req->cmd.dev_6238_isp_shading_para.mode;
	cnf->result.get_6238_isp_shading_table_para.offset = req->cmd.dev_6238_isp_shading_para.offset;
	cnf->result.get_6238_isp_shading_table_para.length = req->cmd.dev_6238_isp_shading_para.length;

	*pp_peer_buff_ret = construct_peer_buff(sizeof(ispTable), 0, 0, TD_CTRL);
	if(NULL == *pp_peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_ISP_GET_SHADING_TABLE;
	CctDataIn.Length = req->cmd.dev_6238_isp_shading_para.length;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)req->cmd.dev_6238_isp_shading_para.mode;
	CctDataIn.Offset = req->cmd.dev_6238_isp_shading_para.offset;
	CctDataIn.pBuffer = ((ispTable*)pdu_ptr)->data;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_ISP_SET_SHADING_TABLE: 207
kal_uint8  ft_cct_6238_isp_set_shading_table(const FT_CCT_REQ *req, ispTable *p_shading_table){
			   
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_TABLE_SET_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_TABLE_SET_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_ISP_SET_SHADING_TABLE;
	CctDataIn.Length = req->cmd.dev_6238_isp_shading_para.length;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)req->cmd.dev_6238_isp_shading_para.mode;
	CctDataIn.Offset = req->cmd.dev_6238_isp_shading_para.offset;
	CctDataIn.pBuffer = p_shading_table->data;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_TUNING_PARAS: 208
kal_uint8  ft_cct_6238_get_isp_tuning_para(peer_buff_struct **peer_buff_ret){

	kal_uint8	ret = FT_CNF_OK;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn,CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_COMP_SET_ENUM CctDataIn;
	CCT_ISP_TUNING_CMD CctDataOut;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_COMP_SET_ENUM));
	kal_mem_set(&CctDataOut, 0, sizeof(CCT_ISP_TUNING_CMD));

	*peer_buff_ret = construct_peer_buff(sizeof(CCT_ISP_TUNING_CMD), 0, 0, TD_CTRL);
	if(NULL == *peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*peer_buff_ret, &pdu_length);	


	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_TUNING_PARAS;
	CctDataIn = (CAL_CCT_COMP_SET_ENUM)g_FT_CCT_StateMachine.comp_mode;	
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(((CCT_ISP_TUNING_CMD*)pdu_ptr), &CctDataOut, sizeof(CCT_ISP_TUNING_CMD));

	return ret;

}

// FT_CCT_6238_OP_ISP_SET_TUNING_PARAS: 209
kal_uint8  ft_cct_6238_set_isp_tuning_para(CCT_ISP_TUNING_CMD *tuning_cmd){
			   
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_ISP_TUNING_CMD  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_ISP_TUNING_CMD));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_TUNING_PARAS;
	CctDataIn.tuning_cmd = tuning_cmd;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_AE_GET_GAMMA_PARAS: 210
kal_uint8  ft_cct_6238_ae_get_gamma_paras(peer_buff_struct **peer_buff_ret){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint16 pdu_length = 0;

	kal_char *pdu_ptr = NULL;
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_GAMMA_SETTING_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT));

	*peer_buff_ret = construct_peer_buff(sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT), 0, 0, TD_CTRL);
	if(NULL == *peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	//CctDataOut = (CAL_CCT_AE_GAMMA_SETTING_STRUCT )get_pdu_ptr(*peer_buff_ret, &pdu_length);
	pdu_ptr = get_pdu_ptr(*peer_buff_ret, &pdu_length);
	//kal_mem_cpy(&CctDataOut, (CAL_CCT_AE_GAMMA_SETTING_STRUCT *)pdu_ptr, sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_PARAS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(((CAL_CCT_AE_GAMMA_SETTING_STRUCT*)pdu_ptr),&CctDataOut, sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT));
	return ret;

}

// FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARAS: 211
kal_uint8  ft_cct_6238_ae_update_gamma_paras(aeGammaSettingStruct* p_gamma_setting){

	kal_uint8	ret = FT_CNF_OK;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_GAMMA_SETTING_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_UPDATE_GAMMA_PARAS;
	//&CctDataIn = (CAL_CCT_AE_GAMMA_SETTING_STRUCT *)p_gamma_setting;
	kal_mem_cpy(&CctDataIn, p_gamma_setting, sizeof(CAL_CCT_AE_GAMMA_SETTING_STRUCT));
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	return ret;

}

// FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM_DATA: 212
kal_uint8  ft_cct_6238_ae_get_window_histogram_data(peer_buff_struct **p_peer_buf_ret){

	kal_uint8	ret = FT_CNF_OK;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;
	const FT_CCT_SENSOR_EX *s_CurrentPreviewSensor = g_FT_CCT_StateMachine.p_preview_sensor;    

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT));

	//preview should be disabled before calling function and should be enabled after then
	if( NULL != g_FT_CCT_StateMachine.p_preview_sensor ) {
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_FALSE);
		g_FT_CCT_StateMachine.p_preview_sensor = NULL;
	}

	*p_peer_buf_ret = construct_peer_buff(sizeof(CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT), 0, 0, TD_CTRL);
	pdu_ptr = get_pdu_ptr(*p_peer_buf_ret, &pdu_length);

	//&CctDataOut = ((CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT*)pdu_ptr);		
	//kal_mem_cpy(&CctDataOut, pdu_ptr, sizeof(CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AE_GET_WINDOW_HISTOGRAM_DATA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(((CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT*)pdu_ptr),&CctDataOut, sizeof(CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT));

	// if preview on lcd was enabled, resume it 
	if( NULL!=s_CurrentPreviewSensor && NULL==g_FT_CCT_StateMachine.p_preview_sensor ) {
		g_FT_CCT_StateMachine.p_preview_sensor = s_CurrentPreviewSensor;
		ft_cct_preview_on_lcd_enable(g_FT_CCT_StateMachine.p_preview_sensor, KAL_TRUE);
	}

	return ret;

}

// FT_CCT_6238_OP_AWB_GET_AWB_PARAS: 213
kal_uint8  ft_cct_6238_awb_get_awb_paras(peer_buff_struct **peer_buf_ret){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0, RegGetOutLen = 0;

	kal_uint16 pdu_length = 0;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_char *pCctDataOut = NULL;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	RegGetOutLen = CctDataSizeOut.AwbNvramSize;

	*peer_buf_ret = construct_peer_buff( RegGetOutLen, 0, 0, TD_CTRL);
	pCctDataOut = (kal_char *)get_pdu_ptr(*peer_buf_ret, &pdu_length);// jim test
	if(NULL == *peer_buf_ret)
	{
		return FT_CNF_FAIL;
	}

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_GET_AWB_PARAS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = pCctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//kal_mem_cpy(pdu_ptr,pCctDataOut, RegOutLen);// jim test

	return ret;
}

// FT_CCT_6238_OP_AWB_UPDATE_AWB_PARAS: 214
// danbo note  this function need update
#if 1
kal_uint8  ft_cct_6238_awb_update_awb_paras(void* p_awb_para){
			   
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 awb_paras_buf [464];//232
	kal_uint8 *pCctDataIn= awb_paras_buf;
	
	//void *pCctDataIn = p_awb_para;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	//RegGetOutLen = CctDataSizeOut.AwbNvramSize;

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_AWB_PARAS;
	//kal_mem_cpy(pCctDataIn, p_awb_para, RegGetOutLen);
	pCctDataIn = p_awb_para;;
	CCTfeatureCtrlIn.pCctFeatureParaIn = pCctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}
#endif

// FT_CCT_6238_OP_AF_GET_PARAS: 215
kal_uint8  ft_cct_6238_af_get_paras(peer_buff_struct **peer_buf_ret){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32 RegOutLen = 0, RegGetOutLen=0;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8 af_paras_buf [932]; //466
	kal_uint8 *pCctDataOut = af_paras_buf;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	RegGetOutLen = CctDataSizeOut.AfNvramSize;

	*peer_buf_ret = construct_peer_buff( RegGetOutLen, 0, 0, TD_CTRL);

	if(NULL == *peer_buf_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*peer_buf_ret, &pdu_length);  

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AF_GET_PARAS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = pCctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	//kal_mem_cpy(&CctDataOut, &(cnf->result.get_6238_ae_preview_expo_info), sizeof(CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT));
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(pdu_ptr,pCctDataOut, RegOutLen);

	return ret;
}

// FT_CCT_6238_OP_AF_SET_PARAS: 216
#if 1 
kal_uint8  ft_cct_6238_af_set_paras (void* pdu){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegGetOutLen = 0;

	CAL_CCT_GET_SIZE_STRUCT CctDataSizeOut;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8 af_paras_buf [932]; // 466
	kal_uint8 *pCctDataIn = af_paras_buf;

	kal_mem_set(&CctDataSizeOut, 0, sizeof(CAL_CCT_GET_SIZE_STRUCT));

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));

	if(!isp_cct_is_cct_af_support())
	{
		return FT_CCT_ERR_NOT_IMPLEMENT_YET;
	}

	if(NULL == pdu)
	{
		return FT_CNF_FAIL;
	}

	ret = ft_cct_get_struct_size(&CctDataSizeOut);
	RegGetOutLen = CctDataSizeOut.AfNvramSize;

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_AF_SET_PARAS;
	kal_mem_cpy(pCctDataIn, pdu, RegGetOutLen);
	//pCctDataIn = pdu;
	CCTfeatureCtrlIn.pCctFeatureParaIn = pCctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	
	return ret;
}
#endif


// CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULTS: 217
kal_uint8  ft_cct_6238_isp_flash_linearity_results(peer_buff_struct **peer_buf_ret){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	flashlight_linearity_ae_result_struct CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(flashlight_linearity_ae_result_struct));

	*peer_buf_ret = construct_peer_buff(sizeof(flashlight_linearity_ae_result_struct), 0, 0, TD_CTRL);
	if(NULL == *peer_buf_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*peer_buf_ret, &pdu_length);	

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_LINEARITY_RESULTS;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(((flashlight_linearity_ae_result_struct*)pdu_ptr),&CctDataOut, RegOutLen);
	return ret;
}

// FT_CCT_DUAL_OP_GET_CAMRA_PARA_TABLE: 219
kal_uint8  ft_cct_dual_get_camera_para_table(peer_buff_struct **peer_buf_ret){

	#ifdef __TH_DEBUG__
	char tmp[256];
#endif
	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;
	kal_uint32 valid_camera_type = 0;
	kal_uint32 index =0;

	if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support())
	{
#ifdef __TH_DEBUG__
		sprintf((kal_char *)tmp, "Call ft_cct_dual_get_camera_para_table() ");
		//tst_sys_trace((kal_uint8 *)tmp);
#endif
	  
		*peer_buf_ret = construct_peer_buff(sizeof(camera_para_table_struct), 0,0, TD_CTRL);
		if(*peer_buf_ret == NULL)
		{
			EXT_ASSERT(KAL_FALSE, 0, 0, 0);
			return FT_CNF_FAIL;
		}
		pdu_ptr = get_pdu_ptr(*peer_buf_ret, &pdu_length);
		if(pdu_ptr == NULL)
		{
			EXT_ASSERT(KAL_FALSE, 0, 0, 0);
			return FT_CNF_FAIL;
		}

		kal_mem_set(pdu_ptr, 0, sizeof(camera_para_table_struct));	
		//valid_camera_type = get_valid_camera_type();					// valid_camera_type = enum VALID_CAMERA_TYPE	
		index = g_cameraType * FT_CCT_6238_CAMERA_LID_NUM;	//      for each sensor, there are six CAMERA LID, Notice: + 1 <== 1 first is for default
		if(index + 6 > g_camera_para_table_size)
		{
#ifdef __TH_DEBUG__
		sprintf((kal_char *)tmp, "index >= g_camera_para_table_size, index = %d, valid_camera_type = %d", index, valid_camera_type);
		//tst_sys_trace((kal_uint8 *)tmp);
#endif
			EXT_ASSERT(KAL_FALSE, index, g_camera_para_table_size, valid_camera_type);
			return FT_CNF_FAIL;
		}
		
		kal_mem_cpy(pdu_ptr, &g_camera_para_table[index], sizeof(camera_para_table_struct));	
		return FT_CNF_OK;
	}
	else
	{
		return FT_CNF_FAIL;
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
#endif	
	  //return ret;
}

// FT_CCT_DUAL_OP_GET_VALID_CAMERA_TYPE: 220
kal_uint8  ft_cct_dual_get_valid_camera_type(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
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
#endif
	  return ret;
}

// FT_CCT_DUAL_OP_GET_SENSOR_PREFIX_NAME: 221
kal_uint32  ft_cct_dual_get_sensor_prefix_name(FT_CCT_CNF *cnf){
	
	kal_uint8	ret = FT_CNF_OK;
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
#endif
	  return ret;
}

// FT_CCT_DUAL_OP_GET_LENS_PREFIX_NAME: 222
kal_uint32  ft_cct_dual_get_lens_prefix_name(FT_CCT_CNF *cnf){
	
	kal_uint8	ret = FT_CNF_OK;
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
#endif
	  return ret;
}

// FT_CCT_6238_OP_ISP_GET_SHADING_TABLE_V3: 223
kal_uint8  ft_cct_6238_isp_get_shading_table_V3(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret){
			   
	kal_uint8	ret = FT_CNF_OK;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	ispShadingParaV3 *request = (ispShadingParaV3 *)(&req->cmd.dev_6238_isp_shading_para);
	ispShadingParaV3 *result = (ispShadingParaV3 *)(&cnf->result.get_6238_isp_shading_table_para);

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_TABLE_SET_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_TABLE_SET_STRUCT));

	result->mode = request->mode;
	result->offset = request->offset;
	result->length = request->length;
	result->color_temperature = request->color_temperature;

	*pp_peer_buff_ret = construct_peer_buff(sizeof(ispTable), 0, 0, TD_CTRL);
	if(NULL == *pp_peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_TABLE_V3;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)req->cmd.dev_6238_isp_shading_para_v3.mode;
	CctDataIn.ColorTemp = req->cmd.dev_6238_isp_shading_para_v3.color_temperature;
	CctDataIn.Offset = req->cmd.dev_6238_isp_shading_para_v3.offset;
	CctDataIn.Length = req->cmd.dev_6238_isp_shading_para_v3.length;
	CctDataIn.pBuffer = ((ispTable*)pdu_ptr)->data;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_SET_SHADING_TABLE_V3: 224
kal_uint8  ft_cct_6238_isp_set_shading_table_V3(const FT_CCT_REQ *req, ispTable *p_shading_table){
			   
	kal_uint8	ret = FT_CNF_OK;
	
	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_TABLE_SET_STRUCT  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_TABLE_SET_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_TABLE_V3;
	CctDataIn.Mode = (CAMERA_TUNING_SET_ENUM)req->cmd.dev_6238_isp_shading_para_v3.mode;
	CctDataIn.ColorTemp = req->cmd.dev_6238_isp_shading_para_v3.color_temperature;
	CctDataIn.Offset = req->cmd.dev_6238_isp_shading_para_v3.offset;
	CctDataIn.Length = req->cmd.dev_6238_isp_shading_para_v3.length;
	CctDataIn.pBuffer = p_shading_table->data;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_CHECK_DYNAMIC_LSC_SUPPORT: 225
kal_uint8  ft_cct_6238_check_if_dynamic_LSC_support(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;
	kal_uint32  RegOutLen = 0;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_FUNCTION_ENABLE_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_FUNCTION_ENABLE_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_CHECK_DYNAMIC_LSC_SUPPORT;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CCTfeatureCtrlOut.pRealCctFeatureParaOutLen = &RegOutLen;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_is_supported = CctDataOut.Enable;

	return ret;

}

// FT_CCT_6238_OP_ENABLE_AWB_CT: 226 , 227
kal_uint8  ft_cct_6238_enable_awb_cct_ct(kal_bool enable){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_MODULE_CTRL_STRUCT  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_TABLE_SET_STRUCT));

	if(enable){
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ENABLE_AWB_CT;   
	}
	else{
		CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_DISABLE_AWB_CT;
	}

	CctDataIn.Enable = enable;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL, (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_SET_LIGHT_SOURCE: 228
kal_uint8  ft_cct_6238_set_awb_cct_light_source(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_LIGHT_SOURCE_SET_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_LIGHT_SOURCE_SET_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_SET_LIGHT_SOURCE;
	CctDataIn.LightSource = req->cmd.dev_6238_awb_cct_light_source;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_SET_PCA_TABLE: 229
kal_uint8  ft_cct_6238_isp_set_pca_table(const FT_CCT_REQ *req, ispPCATable *p_pca_table){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_PCA_TBL_PARA_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_PCA_TBL_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_TABLE;
	CctDataIn.Channel = req->cmd.dev_6238_isp_PCA_tbl_para.channel;
	CctDataIn.ColorTemperature = req->cmd.dev_6238_isp_PCA_tbl_para.color_temperature;
	CctDataIn.Length = req->cmd.dev_6238_isp_PCA_tbl_para.length;
	CctDataIn.Offset = req->cmd.dev_6238_isp_PCA_tbl_para.offset;
	CctDataIn.pBuffer = p_pca_table->data;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_PCA_TABLE: 230
kal_uint8  ft_cct_6238_isp_get_pca_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret){
			   
	kal_uint8	ret = FT_CNF_OK;

	kal_uint16 pdu_length = 0;
	kal_char *pdu_ptr = NULL;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_PCA_TBL_PARA_STRUCT  CctDataIn;

	ispPCATblPara *result = (ispPCATblPara *)(&cnf->result.get_6238_isp_PCA_tbl_para);

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_PCA_TBL_PARA_STRUCT));

	*pp_peer_buff_ret = construct_peer_buff(sizeof(ispPCATable), 0, 0, TD_CTRL);
	if(NULL == *pp_peer_buff_ret)
	{
		return FT_CNF_FAIL;
	}
	pdu_ptr = get_pdu_ptr(*pp_peer_buff_ret, &pdu_length);

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_TABLE;
	CctDataIn.Channel = req->cmd.dev_6238_isp_PCA_tbl_para.channel;
	CctDataIn.ColorTemperature = req->cmd.dev_6238_isp_PCA_tbl_para.color_temperature;
	CctDataIn.Length = req->cmd.dev_6238_isp_PCA_tbl_para.length;
	CctDataIn.Offset = req->cmd.dev_6238_isp_PCA_tbl_para.offset;
	CctDataIn.pBuffer = ((ispPCATable*)pdu_ptr)->data;

	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}
	//kal_mem_cpy(pdu_ptr, (kal_uint8 *)PCA_Table_buf, sizeof(ispPCATable));	 
	result->offset = req->cmd.dev_6238_isp_PCA_tbl_para.offset;
	result->length = req->cmd.dev_6238_isp_PCA_tbl_para.length;
	result->channel = req->cmd.dev_6238_isp_PCA_tbl_para.channel;
	result->color_temperature = req->cmd.dev_6238_isp_PCA_tbl_para.color_temperature;

	return ret;
}

// FT_CCT_6238_OP_ISP_SET_PCA_PARA: 231
kal_uint8  ft_cct_set_pca_para(const FT_CCT_REQ *req){

	kal_uint8 ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	CAL_CCT_PCA_PARA_STRUCT CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_PCA_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_PARA;
	CctDataIn.pca_en = req->cmd.dev_6238_isp_PCA_para.pca_en;
	CctDataIn.chroma_lo = req->cmd.dev_6238_isp_PCA_para.chroma_lo;
	CctDataIn.chroma_md = req->cmd.dev_6238_isp_PCA_para.chroma_md;
	CctDataIn.chroma_hi = req->cmd.dev_6238_isp_PCA_para.chroma_hi;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_ISP_GET_PCA_PARA: 232
kal_uint8  ft_cct_get_pca_para(FT_CCT_CNF *cnf){
			   
	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	CAL_CCT_PCA_PARA_STRUCT CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	kal_mem_set(&CctDataOut, 0, sizeof(CAL_CCT_PCA_PARA_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_PARA;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	kal_mem_cpy(&(cnf->result.get_6238_isp_PCA_para), &CctDataOut, sizeof(CAL_CCT_PCA_PARA_STRUCT));
	return ret;
}

// FT_CCT_6238_OP_CHECK_PCA_SUPPORT: 233
kal_uint8  ft_cct_6238_check_if_PCA_support(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_CHECK_PCA_SUPPORT;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_PCA_is_supported = (kal_bool)CctDataOut;

	return ret;
}
 
// FT_CCT_6238_OP_SET_CCM_MODE: 234
kal_uint8  ft_cct_6238_set_ccm_mode(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	kal_uint8  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_SET_CCM_MODE;
	CctDataIn = (kal_uint8)req->cmd.dev_6238_ccm_mode;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
}

// FT_CCT_6238_OP_GET_CCM_MODE: 235
kal_uint8  ft_cct_6238_get_ccm_mode(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	 CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	 CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	 CCM_MODE_ENUM CctDataOut;
	
	 kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	 kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	 kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 
	 kal_mem_set(&CctDataOut, 0, sizeof(CCM_MODE_ENUM));
	
	 CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_GET_CCM_MODE;
	 CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	 CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;
	
	 if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	 {
	  ret = FT_CNF_FAIL;
	 }
	
	// pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_ccm_mode = CctDataOut;
	//kal_mem_cpy(&(cnf->result.get_6238_ccm_mode), &CctDataOut, RegOutLen );	

	  return ret;
}

// ft_cct_6238_check_if_ASD_PCA_support: 236
kal_uint8  ft_cct_6238_check_if_ASD_PCA_support(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	kal_uint8  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_CHECK_PCA2_SUPPORT;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.get_6238_PCA_is_supported = (kal_bool)CctDataOut;

	return ret;
} 

// ft_cct_isp_set_PCA_TABLE_IDX: 237
kal_uint8  ft_cct_isp_set_PCA_TABLE_IDX(const FT_CCT_REQ *req){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlIn;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara;
	PCA_TABLE_ENUM  CctDataIn;

	kal_mem_set(&CCTfeatureCtrlIn, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CctDataIn, 0, sizeof(CAL_CCT_REG_RW_STRUCT));

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_TABLE_IDX;
	CctDataIn = req->cmd.dev_isp_PCA_Index;
	CCTfeatureCtrlIn.pCctFeatureParaIn = &CctDataIn;
	CalCCTInPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlIn;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, NULL, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	return ret;
} 

// ft_cct_isp_get_PCA_TABLE_IDX: 238
kal_uint8  ft_cct_isp_get_PCA_TABLE_IDX(FT_CCT_CNF *cnf){

	kal_uint8	ret = FT_CNF_OK;

	CAL_CCT_FEATURE_CTRL_STRUCT CCTfeatureCtrlOut;
	CAL_FEATURE_CTRL_STRUCT CalCCTInPara, CalCCTOutPara;
	PCA_TABLE_ENUM  CctDataOut;

	kal_mem_set(&CCTfeatureCtrlOut, 0, sizeof(CAL_CCT_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTInPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT));
	kal_mem_set(&CalCCTOutPara, 0, sizeof(CAL_FEATURE_CTRL_STRUCT)); 

	CalCCTInPara.FeatureId = CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_TABLE_IDX;
	CCTfeatureCtrlOut.pCctFeatureParaOut = &CctDataOut;
	CalCCTOutPara.FeatureInfo.FeatureStructured.pCctInOutPara = &CCTfeatureCtrlOut;

	if (CalCtrl(CAL_FEATURE_CTRL,  (void*)&CalCCTInPara, (void*)&CalCCTOutPara, 0, NULL)!=0)
	{
		ret = FT_CNF_FAIL;
	}

	//pCctDataOut = CCTfeatureCtrlOut.pCctFeatureParaOut;
	cnf->result.dev_isp_PCA_Index = CctDataOut;

	return ret;
} 


//begin of FT_CCT_Operation
extern kal_uint8 g_b_set_camera_type_result;

void FT_CCT_Operation(const FT_CCT_REQ *req, peer_buff_struct *peer_buff_in) {
	kal_uint16	pdu_length;
	kal_char	*pdu_ptr;
	peer_buff_struct *peer_buff_ret;
	FT_CCT_CNF	cnf;
	const FT_CCT_SENSOR_EX	*sensor;
	// kal_bool	bMultiShotFlag = KAL_FALSE; //HAL //danbo Mark  for fix  Warning 110401
	//p_dev_dual_isp_set_camera_type

      ft_cct_6238_init_environment(req, &cnf, peer_buff_in, &peer_buff_ret, &pdu_ptr, &pdu_length);


	switch(req->op) {
		case FT_CCT_OP_REG_READ:
			cnf.status = ft_cct_reg_read(req, &cnf);
			break;
		case FT_CCT_OP_REG_WRITE:
			cnf.status = ft_cct_reg_write(req, &cnf);
			break;
		case FT_CCT_OP_PREVIEW_LCD_START:
			ft_cct_preview_start(req, &cnf, &sensor);
			break;
		case FT_CCT_OP_PREVIEW_LCD_STOP:
			ft_cct_preview_stop(req, &cnf, &sensor);
			break;
		case FT_CCT_OP_SINGLE_SHOT_CAPTURE:
			// old capture method is obsolete
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			break;
		case FT_CCT_OP_MULTI_SHOT_CAPTURE:
			// old capture method is obsolete
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			break;
		case FT_CCT_OP_QUERY_SENSOR:
			cnf.status = ft_cct_query_sensor(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_OP_LOAD_FROM_NVRAM:
			cnf.status = ft_cct_load_from_nvram(&(cnf.result.nvram.status), KAL_TRUE);
			break;
		case FT_CCT_OP_SAVE_TO_NVRAM:
			cnf.status = ft_cct_save_to_nvram(&(cnf.result.nvram.status));
			break;
		case FT_CCT_OP_AE_ENABLE:
			cnf.status = ft_cct_ae_enable(KAL_TRUE);
			break;
		case FT_CCT_OP_AE_DISABLE:
			cnf.status = ft_cct_ae_enable(KAL_FALSE);
			break;

		// danbo Note this case not use
		case FT_CCT_OP_AE_SET_EXPOSE_LEVEL:
			cnf.status = ft_cct_ae_set_expose_level(req);
			break;

		// danbo Note this case not use
		case FT_CCT_OP_AE_GET_EXPOSE_LEVEL:
			cnf.status = ft_cct_ae_get_expose_level(req, &cnf);
			break;
			
		// danbo Note this case  not use  Get ev
		case FT_CCT_OP_AE_QUERY_EC_STEP_INFO:
			cnf.status = ft_cct_ae_query_ec_step_info(req, &cnf);
			break;

		// danbo Note this case  not  use  Init_Shutter
		case FT_CCT_OP_AE_SET_INIT_SHUTTER:
			cnf.status = ft_cct_ae_set_init_shutter(req->cmd.ae_init_shutter);
			break;

		// danbo Note this case not use
		case FT_CCT_OP_AE_GET_INIT_SHUTTER:
			cnf.status = ft_cct_ae_get_init_shutter(&(cnf.result.ae_init_shutter));
			break;
		
		case FT_CCT_OP_WB_ACTIVATE_BY_INDEX:
			cnf.status = ft_cct_wb_activate_by_index(req->cmd.wb_activate.index);
			break;
		case FT_CCT_OP_WB_SET_BY_INDEX:
			cnf.status = ft_cct_wb_set_by_index(req, &cnf);
			break;

		// danbo Note this case not use
		case FT_CCT_OP_WB_QUERY_ALL:
			cnf.status = ft_cct_wb_query_all(&cnf, &peer_buff_ret);
			break;
			
		case FT_CCT_OP_AE_SET_MANUAL_SHUTTER:
			cnf.status = ft_cct_ae_set_manual_shutter(req);
			break;
		case FT_CCT_OP_AE_GET_MANUAL_SHUTTER:
			cnf.status = ft_cct_ae_get_manual_shutter(&cnf);
			break;
		case FT_CCT_OP_GET_CAMERA_PARA_BUF:
			cnf.status = ft_cct_get_camera_para_buf(&peer_buff_ret);
			break;
		case FT_CCT_OP_SINGLE_SHOT_CAPTURE_EX:
			//bMultiShotFlag = KAL_FALSE; //danbo Mark  for fix  Warning 110401
		case FT_CCT_OP_MULTI_SHOT_CAPTURE_EX:
			//cnf.status = ft_cct_capture_ex(req, &cnf, bMultiShotFlag);
			cnf.status = ft_cct_capture_ex(req, &cnf);//danbo Change  for fix  Warning 110401
			break;
		case FT_CCT_OP_GET_CAPTURE_BUF:
			cnf.status = ft_cct_get_capture_buf(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_OP_RESUME_AE_AWB_PREVIEW_FROM_UNFINISHED_CAPTURE:
			cnf.status = ft_cct_suspend_ae_awb_preview_during_capture(KAL_FALSE);
			if(req->cmd.resume_preview.no_confirm) {
				// skip return confirm
				return;
			}
			break;
		case FT_CCT_OP_GET_BANDING_FACTOR:
			cnf.status = ft_cct_get_banding_factor(&cnf);
			break;
		case FT_CCT_OP_GET_SENSOR_PREGAIN:
			cnf.status = ft_cct_get_sensor_pregain(&cnf);
			break;
		case FT_CCT_OP_SET_SENSOR_PREGAIN:
			cnf.status = ft_cct_set_sensor_pregain(req, &cnf);
			break;
		case FT_CCT_OP_MAIN_LCD_BACKLIGHT_SETTING:
			cnf.status = ft_cct_main_lcd_backlight_setting(req);
			break;
		case FT_CCT_OP_GET_GAMMA_TABLE:
			cnf.status = ft_cct_get_gamma_table(&cnf, &peer_buff_ret);
			break;
		case FT_CCT_OP_SET_GAMMA_TABLE:
			cnf.status = ft_cct_set_gamma_table((FT_CCT_GAMMA_TABLE *)pdu_ptr);
			break;
		case FT_CCT_OP_QUERY_ISP_ID:
			cnf.status = ft_cct_query_isp_id(&cnf);
			break;

		// danbo note Check if only use 2X
		case FT_CCT_OP_GET_CAL_STRUCT_BUF:
			cnf.status = ft_cct_get_calibration_struct_buf(req->cmd.cal_nvram_lid, &peer_buff_ret);
			break;
			
		case FT_CCT_OP_GET_ENG_SENSOR_PARA:
			cnf.status = ft_cct_get_eng_sensor_para(((FT_CCT_SENSOR_ENG_KEY *)pdu_ptr)->group_name, ((FT_CCT_SENSOR_ENG_KEY *)pdu_ptr)->item_name, &cnf);
			break;
		case FT_CCT_OP_SET_ENG_SENSOR_PARA:
			cnf.status = ft_cct_set_eng_sensor_para(((FT_CCT_SENSOR_ENG_KEY *)pdu_ptr)->group_name, ((FT_CCT_SENSOR_ENG_KEY *)pdu_ptr)->item_name, req);
			break;
		case FT_CCT_OP_GET_COMPENSATION_MODE:
			cnf.status = ft_cct_get_compensation_mode(&cnf);
			break;
		case FT_CCT_OP_SET_COMPENSATION_MODE:
			cnf.status = ft_cct_set_compensation_mode(req);
			break;
		case FT_CCT_OP_GET_SHADING_PARA:
			cnf.status = ft_cct_get_shading_para(&cnf);
			break;
		case FT_CCT_OP_SET_SHADING_PARA:
			cnf.status = ft_cct_set_shading_para(req);
			break;
		case FT_CCT_OP_GET_AUTODEFECT_PARA:
			cnf.status = ft_cct_get_autodefect_para(&cnf);
			break;
		case FT_CCT_OP_SET_AUTODEFECT_PARA:
			cnf.status = ft_cct_set_autodefect_para(req);
			break;
		case FT_CCT_OP_GET_LAST_COMPENSATION_MODE:
			cnf.status = ft_cct_get_last_compensation_mode(&cnf);
			break;
		case FT_CCT_OP_GET_AUTODEFECT_COUNT:
			cnf.status = ft_cct_get_autodefect_count(&cnf);
			break;
		case FT_CCT_OP_SET_CAPTURE_DATA_TUNNEL:
			cnf.status = ft_cct_set_capture_data_tunnel(req);
			break;
		case FT_CCT_OP_USB_TUNNEL_CANCEL:
			cnf.status = ft_cct_usb_tunnel_cancel();
			break;
//#if (!defined(MT6219))
		case FT_CCT_OP_DEFECT_TABLE_VERIFY_BLOCK_FACTOR:
			cnf.status = ft_cct_defect_table_verify_block_factor(req, &cnf);
			break;
		case FT_CCT_OP_DEFECT_TABLE_CAL:
			cnf.status = ft_cct_defect_table_calibration(req);
			break;
		case FT_CCT_OP_GET_DEFECT_TABLE:
			cnf.status = ft_cct_get_defect_table(&cnf, &peer_buff_ret);
			break;
		case FT_CCT_OP_SET_DEFECT_TABLE:
			cnf.status = ft_cct_set_defect_table(&cnf, (defectpixel_result_struct *)pdu_ptr);
			break;
		case FT_CCT_OP_DEV_GET_DSC_INFO:// 2x func
			cnf.status = ft_cct_dev_get_dsc_info(&peer_buff_ret);
			break;
		case FT_CCT_OP_DEV_GET_IRIS_INFO:
			cnf.status = ft_cct_dev_get_iris_info(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_IRIS_INFO:
			cnf.status = ft_cct_dev_set_iris_info(req);
			break;
		case FT_CCT_OP_DEV_GET_ISO_GAIN:
			cnf.status = ft_cct_dev_get_iso_gain(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_ISO_GAIN:
			cnf.status = ft_cct_dev_set_iso_gain(req);
			break;
		case FT_CCT_OP_DEV_GET_ISO_VALUE:
			cnf.status = ft_cct_dev_get_iso_value(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_ISO_VALUE:
			cnf.status = ft_cct_dev_set_iso_value(req);
			break;
		case FT_CCT_OP_DEV_GET_ISO_GAIN_CCT:
			cnf.status = ft_cct_dev_get_iso_gain_cct(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_ISO_GAIN_CCT:
			cnf.status = ft_cct_dev_set_iso_gain_cct(req);
			break;
		case FT_CCT_OP_DEV_GET_ISO_VALUE_CCT:
			cnf.status = ft_cct_dev_get_iso_value_cct(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_ISO_VALUE_CCT:
			cnf.status = ft_cct_dev_set_iso_value_cct(req);
			break;
		case FT_CCT_OP_DEV_IF_SUPPORT_ISO:
			cnf.status = ft_cct_dev_is_support_iso();
			break;
		case FT_CCT_OP_DEV_RECOVER_ISO_CAPTURE:
			cnf.status = ft_cct_dev_recover_iso_capture();
			break;
		case FT_CCT_OP_DEV_SET_ISO_CAPTURE:
			cnf.status = ft_cct_dev_set_iso_capture(req);
			break;
		case FT_CCT_OP_DEV_AE_GET_INFO:
			cnf.status = ft_cct_dev_ae_get_info(&peer_buff_ret);
			break;
		case FT_CCT_OP_DEV_AE_SET_TABLE_IDX:
			cnf.status = ft_cct_dev_ae_set_table_index(req);
			break;
		case FT_CCT_OP_DEV_AE_SET_VALUE:
			cnf.status = ft_cct_dev_ae_set_value(req);
			break;
		case FT_CCT_OP_DEV_AF_GET_TABLE:
			cnf.status = ft_cct_dev_af_get_table(&peer_buff_ret);
			break;
		case FT_CCT_OP_DEV_AF_CAL:
			cnf.status = ft_cct_dev_af_calibration(&cnf);
			break;
		case FT_CCT_OP_DEV_AF_SET_TABLE_IDX:
			cnf.status = ft_cct_dev_af_set_table_index(req);
			break;
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
		case FT_CCT_OP_DEV_AF_SET_POS:
			cnf.status = ft_cct_dev_af_set_pos(req);
			break;
#endif
		case FT_CCT_OP_DEV_STROBE_CAL_ENABLE:
			cnf.status = ft_cct_dev_strobe_calibration_enable();
			break;
		case FT_CCT_OP_DEV_STROBE_CAL_SET_PARA:
			cnf.status = ft_cct_dev_strobe_calibration_set_para(req);
			break;
		case FT_CCT_OP_DEV_STROBE_CAL_DISABLE:
			cnf.status = ft_cct_dev_strobe_calibration_disable();
			break;
		case FT_CCT_OP_DEFECT_TABLE_ON_OFF:
			cnf.status = ft_cct_defect_table_on_off(req->cmd.on_off);
			break;
		case FT_CCT_OP_DEFECT_TABLE_BYPASS_BACKUP_SETTING:
			cnf.status = ft_cct_defect_table_bypass_and_backup_setting();
			break;
		case FT_CCT_OP_DEFECT_TABLE_RESTORE_SETTING:
			cnf.status = ft_cct_defect_table_restore_setting();
			break;
		case FT_CCT_OP_AE_GET_PERIOD_PARA:
			cnf.status = ft_cct_ae_get_period_para(&cnf);
			break;
		case FT_CCT_OP_AE_SET_PERIOD_PARA:
			cnf.status = ft_cct_ae_set_period_para(req);
			break;
		case FT_CCT_OP_DEV_AE_BYPASS_FREERUN:
			cnf.status = ft_cct_dev_ae_bypass_freerun((FT_CCT_DEV_AE_BYPASS_FREERUN_PARA *)pdu_ptr, &peer_buff_ret);
			break;
		case FT_CCT_OP_DEV_AE_SET_SCENE_MODE:
			cnf.status = ft_cct_dev_ae_set_scene_mode(req);
			break;
//#endif
		case FT_CCT_OP_ENABLE_USBCOM:
			cnf.status = ft_cct_enable_usbcom();
			break;
	#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
		case FT_CCT_OP_AF_ON_OFF:
			cnf.status = ft_cct_af_on_off(req->cmd.on_off);
			break;
	#endif
		case FT_CCT_OP_AF_LENS_OFFSET_CAL:
			cnf.status = ft_cct_af_lens_offset_cal(req, &cnf);
			break;
		case FT_CCT_OP_GET_GAMMA_TABLE_ON_OFF_FLAG:
			cnf.status = ft_cct_get_gamma_table_on_off_flag(&cnf);
			break;
		case FT_CCT_OP_SET_GAMMA_TABLE_ON_OFF_FLAG:
			cnf.status = ft_cct_set_gamma_table_on_off_flag(req->cmd.on_off);
			break;
		case FT_CCT_OP_GET_GAMMA_ON_OFF_FLAG:
			cnf.status = ft_cct_get_gamma_on_off_flag(&cnf);
			break;
		case FT_CCT_OP_SET_GAMMA_ON_OFF_FLAG:
			cnf.status = ft_cct_set_gamma_on_off_flag(req->cmd.on_off);
			break;
//#if (!defined(MT6219))
		case FT_CCT_OP_DEV_FLASHLIGHT_CHARGE:
			cnf.status = ft_cct_flashlight_charge(req,&cnf);
			break;
		case FT_CCT_OP_DEV_FLASHLIGHT_STROBE:
	    	cnf.status = ft_cct_flashlight_strobe(req);
	    	break;
	    case FT_CCT_OP_DEV_FLASHLIGHT_CONF:
			cnf.status = ft_cct_flashlight_capture(req,&cnf);
			break;
		case FT_CCT_OP_DEV_MODE_SIZE:
			cnf.status = ft_cct_dev_mode_size(&cnf);
			break;
		case FT_CCT_OP_DEV_FLASHLIGHT_TYPE:
			cnf.status = ft_cct_dev_flashlight_type(&cnf);
			break;
		case FT_CCT_OP_DEV_GET_FLASH_LEVEL:
			cnf.status = ft_cct_get_flash_level(&cnf);
			break;
		case FT_CCT_OP_DEV_SET_FLASH_LEVEL:
			cnf.status = ft_cct_set_flash_level(req);
			break;
		case FT_CCT_OP_DEV_SET_FLASH_AE_INDEX:
			cnf.status = ft_cct_set_flash_ae_index(req,&cnf);
			break;
		case FT_CCT_OP_DEV_GET_FLASH_AE_INDEX:
			cnf.status = ft_cct_get_flash_ae_index(&cnf);
			break;
//#endif
		// ----------------[TH] for CCT 6238 AE---------------------------------
		case FT_CCT_6238_OP_AE_ENABLE:
			cnf.status = ft_cct_6238_ae_enable(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AE_DISABLE:
			cnf.status = ft_cct_6238_ae_enable(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AE_SET_SCENE_MODE:
			cnf.status = ft_cct_6238_ae_set_scene_mode(req->cmd.dev_6238_ae_scene_mode);
			break;
		case FT_CCT_6238_OP_AE_SET_METERING_MODE:
			cnf.status = ft_cct_6238_ae_set_metering_mode(req->cmd.dev_6238_ae_metering_mode);
			break;
		case FT_CCT_6238_OP_AE_GET_CURRENT_EXPO_INFO:
			cnf.status = ft_cct_6238_ae_get_current_expo_info(&cnf);
			break;
		case FT_CCT_6238_OP_AE_APPLY_EXPO_INFO:
			cnf.status = ft_cct_6238_ae_apply_expo_info(req);
			break;
		case FT_CCT_6238_OP_AE_SELECT_BAND:
			cnf.status = ft_cct_6238_ae_select_band(req);
			break;
		case FT_CCT_6238_OP_AE_GET_AUTO_EXPO_PARA:
			cnf.status = ft_cct_6238_ae_get_auto_expo_para(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_ISO_VALUE_GAIN:
			cnf.status = ft_cct_6238_ae_get_iso_value_gain(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_GAMMA_PARA:
			cnf.status = ft_cct_6238_ae_get_gamma_para(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_GAMMA_TABLE:
			cnf.status = ft_cct_6238_ae_get_gamma_table(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_FLARE_PARA:
			cnf.status = ft_cct_6238_ae_get_flare_para(&cnf);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_AUTO_EXPO_PARA:
			cnf.status = ft_cct_6238_ae_update_auto_expo_para(req);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_ISO_VALUE_GAIN:
			cnf.status = ft_cct_6238_ae_update_iso_value_gain(req);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARA:
			cnf.status = ft_cct_6238_ae_update_gamma_para(req);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_FLARE_PARA:
			cnf.status = ft_cct_6238_ae_update_flare_para(req);
			break;
		case FT_CCT_6238_OP_AE_GET_HISTOGRAM:
			cnf.status = ft_cct_6238_ae_get_flare_histogram(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_METERING_RESULT:
			cnf.status = ft_cct_6238_ae_get_metering_result(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_METERING_MODE_SETTING:
			cnf.status = ft_cct_6238_ae_get_metering_mode_setting(&cnf);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_METERING_MODE_SETTING:
			cnf.status = ft_cct_6238_ae_update_metering_mode_setting( req);
			break;
		case FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM:
			cnf.status = ft_cct_6238_ae_get_window_histogram(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_SMOOTH_MODE_SETTING:
			cnf.status = ft_cct_6238_ae_get_smooth_mode_setting(req, &cnf);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_SMOOTH_MODE_SETTING:
			cnf.status = ft_cct_6238_ae_update_smooth_mode_setting(req);
			break;
		case FT_CCT_6238_OP_AE_ENABLE_PREVIEW_LOG:
			cnf.status = ft_cct_6238_ae_enable_preview_log(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AE_DISABLE_PREVIEW_LOG:
			cnf.status = ft_cct_6238_ae_enable_preview_log(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AE_GET_PREVIEW_EXPO_INFO:
			cnf.status = ft_cct_6238_ae_get_preview_expo_info(&cnf);
			break;
		// ---------------- for CCT 6238 AWB---------------------------------
		case FT_CCT_6238_OP_AWB_ENABLE_PREF_GAIN:
			cnf.status = ft_cct_6238_awb_enable_pref_gain(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_PREF_GAIN:
			cnf.status = ft_cct_6238_awb_enable_pref_gain(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_ENABLE_FAST_CONVERGE:
			cnf.status = ft_cct_6238_awb_enable_fast_converge(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_FAST_CONVERGE:
			cnf.status = ft_cct_6238_awb_enable_fast_converge(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_ENABLE_AUTO_RUN:
			cnf.status = ft_cct_6238_awb_enable_auto_run(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_AUTO_RUN:
			cnf.status = ft_cct_6238_awb_enable_auto_run(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_ENABLE_SMALL_BOX:
			cnf.status = ft_cct_6238_awb_enable_small_box(req,KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_SMALL_BOX:
			cnf.status = ft_cct_6238_awb_enable_small_box(req,KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY:
			cnf.status = ft_cct_6238_awb_get_window_whit_point_count_array(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_GET_LIGHT_MODE:
			cnf.status = ft_cct_6238_awb_get_light_mode(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_GET_GAIN:
			cnf.status = ft_cct_6238_awb_get_gain(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_SET_GAIN:
			cnf.status = ft_cct_6238_awb_set_gain( req);
			break;
		case FT_CCT_6238_OP_AWB_SET_PREF_FACTOR:
			cnf.status = ft_cct_6238_awb_set_pref_factor( req);
			break;
		case FT_CCT_6238_OP_AWB_GET_PREF_FACTOR:
			cnf.status = ft_cct_6238_awb_get_pref_factor(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_ENABLE_DYNAMIC_CCM:
			cnf.status = ft_cct_6238_awb_enable_dynamic_ccm(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_DYNAMIC_CCM:
			cnf.status = ft_cct_6238_awb_enable_dynamic_ccm(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_GET_CURRENT_CCM:
			cnf.status = ft_cct_6238_awb_get_current_ccm(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_ENABLE_FLASH_SYNC:
			cnf.status = ft_cct_6238_awb_enable_flash_sync(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_AWB_DISABLE_FLASH_SYNC:
			cnf.status = ft_cct_6238_awb_enable_flash_sync(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_AWB_APPLY_CAMERA_PARA2:
			cnf.status = ft_cct_6238_awb_apply_camera_para2_to_reg();
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_CAMERA_PARA2:
			cnf.status = ft_cct_6238_awb_update_camera_para2_from_req();
			break;
		case FT_CCT_6238_OP_AWB_GET_NVRAM_CCM:
			cnf.status = ft_cct_6238_awb_get_nvram_ccm( req,&cnf);
			break;
		case FT_CCT_6238_OP_AWB_SET_NVRAM_CCM:
			cnf.status = ft_cct_6238_awb_set_nvram_ccm( req);
			break;
		case FT_CCT_6238_OP_AWB_GET_AWB_PARA:
			cnf.status = ft_cct_6238_awb_get_awb_para(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_GET_CCM_PARA:
			cnf.status = ft_cct_6238_awb_get_ccm_para(&cnf);
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_AWB_PARA:
			cnf.status = ft_cct_6238_awb_update_awb_para( req);
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_CCM_PARA:
			cnf.status = ft_cct_6238_awb_update_ccm_para( req);
			break;
		case FT_CCT_6238_OP_AWB_GET_AWB_STATUS:
			cnf.status = ft_cct_6238_awb_get_awb_status( &cnf);
			break;
		case FT_CCT_6238_OP_AWB_GET_CCM_STATUS:
			cnf.status = ft_cct_6238_awb_get_ccm_status( &cnf);
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_AWB_STATUS:
			cnf.status = ft_cct_6238_awb_update_awb_status( req);
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_CCM_STATUS:
			cnf.status = ft_cct_6238_awb_update_ccm_status( req);
			break;
		case FT_CCT_6238_OP_AWB_SET_CURRENT_CCM:
			cnf.status = ft_cct_6238_awb_set_current_ccm(req);
			break;
		// ---------------- for CCT 6238 ISP---------------------------------
		case FT_CCT_6238_OP_ISP_SET_SHADING_PARA:
			cnf.status = ft_cct_6238_isp_set_shading_para(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_SHADING_PARA:
			cnf.status = ft_cct_6238_isp_get_shading_para(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_ENABLE_DYNAMIC_BYPASS_MODE:
			cnf.status = ft_cct_6238_isp_enable_dynamic_bypass_mode(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_ISP_DISABLE_DYNAMIC_BYPASS_MODE:
			cnf.status = ft_cct_6238_isp_enable_dynamic_bypass_mode(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_ISP_GET_TUNING_PARA:
			cnf.status = ft_cct_6238_isp_get_tuning_para(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_SET_TUNING_PARA:
			cnf.status = ft_cct_6238_isp_set_tuning_para(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_PARTIAL_SHADING_TABLE:
			cnf.status = ft_cct_6238_isp_get_partial_shading_table(req,&cnf);
			break;
		case FT_CCT_6238_OP_ISP_SET_PARTIAL_SHADING_TABLE:
			cnf.status = ft_cct_6238_isp_set_partial_shading_table(req);
			break;
		case FT_CCT_6238_OP_ISP_SET_SHADING_ON_OFF:
			cnf.status = ft_cct_6238_isp_set_shading_on_off(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_SHADING_ON_OFF:
			cnf.status = ft_cct_6238_isp_get_shading_on_off(req, &cnf);
			break;
		//-----------------------------------------------------------------
		case FT_CCT_6238_OP_AE_GET_SCENE_MODE:
			cnf.status = ft_cct_6238_ae_get_scene_mode(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_METERING_MODE:
			cnf.status = ft_cct_6238_ae_get_metering_mode(&cnf);
			break;
		case FT_CCT_6238_OP_AE_GET_BAND:
			cnf.status = ft_cct_6238_ae_get_band(&cnf);
			break;
		case FT_CCT_6238_OP_AE_SET_GAMMA_BYPASS:
			cnf.status = ft_cct_6238_ae_set_gamma_bypass(req);
			break;
		case FT_CCT_6238_OP_AE_GET_GAMMA_BYPASS_FLAG:
			cnf.status = ft_cct_6238_ae_get_gamma_bypass_flag(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_SET_TUNING_INDEX:
			cnf.status = ft_cct_6238_isp_set_tuning_index(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_TUNING_INDEX:
			cnf.status = ft_cct_6238_isp_get_tuning_index(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_GET_AE_TOTAL_GAIN:
			cnf.status = ft_cct_6238_isp_get_ae_total_gain(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF:
			cnf.status = ft_cct_6238_isp_get_dynamic_bypass_mode_on_off(&cnf);
			break;
		//---------------CDT 6238 Flash--------------------------------
		case FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_PRESTROBE:
			cnf.status = ft_cct_6238_isp_flash_linearity_prestrobe(req);
			break;
		case FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULT:
			cnf.status = ft_cct_6238_isp_flash_linearity_result(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_ENABLE_BINNING_MODE:
			cnf.status = ft_cct_6238_isp_set_binning_mode(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_ISP_DISABLE_BINNING_MODE:
			cnf.status = ft_cct_6238_isp_set_binning_mode(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_ISP_GET_BINNING_MODE:
			cnf.status = ft_cct_6238_isp_get_binning_mode(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_FLASHLIGHT_SET_AE_PARA_2:
			cnf.status = ft_cct_6238_isp_flashlight_set_ae_para_2(req);
			break;
		case FT_CCT_6238_OP_AF_GET_PARA:
			cnf.status = ft_cct_6238_af_get_para(&cnf);
			break;
		case FT_CCT_6238_OP_AF_SET_PARA:
			cnf.status = ft_cct_6238_af_set_para(req);
			break;
		case FT_CCT_6238_OP_ISP_FLASHLIGHT_GET_AE_PARA_2:
			cnf.status = ft_cct_6238_isp_flashlight_get_ae_para_2(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_GET_CAMCORDER_INFO:
			cnf.status = ft_cct_6238_isp_get_camcorder_info(&cnf);
			break;
		case FT_CCT_6238_OP_ISP_BYPASS_SHADING_MODE_ENABLE:
			cnf.status = ft_cct_isp_bypass_shading_mode(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_ISP_BYPASS_SHADING_MODE_DISABLE:
			cnf.status = ft_cct_isp_bypass_shading_mode(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_FLASH_CONFIG:
			cnf.status = ft_cct_flashlight_capture(req,&cnf);
			break;
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
		case FT_CCT_6238_FLASH_DURATION_LUT:
			cnf.status = ft_cct_6238_flash_duration_lut(req);
			break;
#endif
		case FT_CCT_6238_ISP_DEFECT_TABLE_ON:
			cnf.status = ft_cct_6238_isp_defect_table_enable(KAL_TRUE);
			break;
		case FT_CCT_6238_ISP_DEFECT_TABLE_OFF:
			cnf.status = ft_cct_6238_isp_defect_table_enable(KAL_FALSE);
			break;
		case FT_CCT_6238_ISP_GET_DEFECT_TABLE:
			cnf.status = ft_cct_6238_isp_get_defect_table(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_6238_ISP_SET_DEFECT_TABLE:
			cnf.status = ft_cct_6238_isp_set_defect_table(req, ((ispTable*)pdu_ptr));
			break;
		case FT_CCT_6238_ISP_GET_SHADING_TABLE:
			cnf.status = ft_cct_6238_isp_get_shading_table(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_6238_ISP_SET_SHADING_TABLE:
			cnf.status = ft_cct_6238_isp_set_shading_table(req, ((ispTable*)pdu_ptr));
			break;
		case FT_CCT_6238_OP_ISP_GET_TUNING_PARAS:
			cnf.status = ft_cct_6238_get_isp_tuning_para(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_ISP_SET_TUNING_PARAS:
			cnf.status = ft_cct_6238_set_isp_tuning_para(((CCT_ISP_TUNING_CMD*)pdu_ptr));
			break;
		case FT_CCT_6238_OP_AE_GET_GAMMA_PARAS:
			cnf.status = ft_cct_6238_ae_get_gamma_paras(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARAS:
			cnf.status = ft_cct_6238_ae_update_gamma_paras(((aeGammaSettingStruct*)pdu_ptr));
			break;
		case FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM_DATA:
			cnf.status =ft_cct_6238_ae_get_window_histogram_data(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_AWB_GET_AWB_PARAS:
			cnf.status = ft_cct_6238_awb_get_awb_paras(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_AWB_UPDATE_AWB_PARAS:
			cnf.status = ft_cct_6238_awb_update_awb_paras(pdu_ptr);
			break;
		case FT_CCT_6238_OP_AF_GET_PARAS:
			cnf.status = ft_cct_6238_af_get_paras(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_AF_SET_PARAS:
			cnf.status = ft_cct_6238_af_set_paras(pdu_ptr);
			break;
		case FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULTS:
			cnf.status = ft_cct_6238_isp_flash_linearity_results(&peer_buff_ret);
			break;
		case FT_CCT_6238_OP_SET_SHUTTER_MODE:
			cnf.status = ft_cct_6238_set_shutter_mode(req);
			break;
		case FT_CCT_6238_OP_SET_SHUTTER_TARGET_TIME:
			cnf.status = ft_cct_6238_set_shutter_target_time(req);
			break;
	      case FT_CCT_6238_OP_SET_SHUTTER_DELAY_TIME:
		  	cnf.status = ft_cct_6238_set_shutter_delay_time(req);
		  	break;
		case FT_CCT_6238_OP_GET_SHUTTER_G_CHANNEL_MEAN:
			cnf.status = ft_cct_6238_get_capture_center_g_channel_mean(&cnf);
			break;
		case FT_CCT_6238_OP_GET_SHUTTER_TARGET_TIME:
			cnf.status = ft_cct_6238_get_shutter_target_time(&cnf);
			break;
		case FT_CCT_6238_OP_GET_SHUTTER_DELAY_TIME:
			cnf.status = ft_cct_6238_get_shutter_delay_time(&cnf);
			break;
		case FT_CCT_6238_OP_GET_SHUTTER_MODE:
			cnf.status = ft_cct_6238_get_shutter_mode(&cnf);
			break;
		case FT_CCT_6238_OP_SET_SHUTTER_CALIBRATION_ENABLE:
			cnf.status = ft_cct_6238_COQC_shutter_calibration_enable(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_SET_SHUTTER_CALIBRATION_DISABLE:
			cnf.status = ft_cct_6238_COQC_shutter_calibration_enable(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_GET_PREVIEW_TARGET_LINES:
			cnf.status = ft_cct_6238_ge_shuttert_preview_target_lines(req,&cnf);
			break;
		case FT_CCT_6238_OP_ENABLE_IMAGE_TRANSFER:
			cnf.status = ft_cct_6238_enable_transfer_image(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_DISABLE_IMAGE_TRANSFER:
			cnf.status = ft_cct_6238_enable_transfer_image(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_ISP_ENABLE_AUTO_DEFECT:
			cnf.status = ft_cct_6238_enable_auto_defect(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_ISP_DISABLE_AUTO_DEFECT:
			cnf.status = ft_cct_6238_enable_auto_defect(KAL_FALSE);
			break;
		//-----------------------------------------------------------------
		case FT_CCT_DUAL_OP_SET_CAMERA_MAIN_OR_SUB_TYPE:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
			{
				cnf.status = g_b_set_camera_type_result;
			}
			break;
		case FT_CCT_DUAL_OP_GET_CAMRA_PARA_TABLE:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
			{
				cnf.status = ft_cct_dual_get_camera_para_table(&peer_buff_ret);
			}
			break;
		case FT_CCT_DUAL_OP_GET_VALID_CAMERA_TYPE:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
			{
				cnf.status = ft_cct_dual_get_valid_camera_type(&cnf);
			}
			break;
		case FT_CCT_DUAL_OP_GET_SENSOR_PREFIX_NAME:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
			{
				cnf.status = ft_cct_dual_get_sensor_prefix_name(&cnf);
			}
			break;
		case FT_CCT_DUAL_OP_GET_LENS_PREFIX_NAME:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			if(custom_ft_util_check_if_dual_camera_sensor_support() || custom_ft_util_check_if_backup_camera_sensor_support() )
			{
				cnf.status = ft_cct_dual_get_lens_prefix_name(&cnf);
			}
			break;
		case FT_CCT_6238_OP_CHECK_DYNAMIC_LSC_SUPPORT:
			cnf.status = ft_cct_6238_check_if_dynamic_LSC_support(&cnf);
			break;
		case FT_CCT_6238_OP_ENABLE_AWB_CT:
			cnf.status = ft_cct_6238_enable_awb_cct_ct(KAL_TRUE);
			break;
		case FT_CCT_6238_OP_DISABLE_AWB_CT:
			cnf.status = ft_cct_6238_enable_awb_cct_ct(KAL_FALSE);
			break;
		case FT_CCT_6238_OP_SET_LIGHT_SOURCE:
			cnf.status = ft_cct_6238_set_awb_cct_light_source(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_SHADING_TABLE_V3:
			cnf.status = ft_cct_6238_isp_get_shading_table_V3(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_6238_OP_ISP_SET_SHADING_TABLE_V3:
			cnf.status = ft_cct_6238_isp_set_shading_table_V3(req, ((ispTable*)pdu_ptr));
			break;
		case FT_CCT_6238_OP_ISP_SET_PCA_TABLE:
			cnf.status = ft_cct_6238_isp_set_pca_table(req, ((ispPCATable*)pdu_ptr));
			break;
		case FT_CCT_6238_OP_ISP_GET_PCA_TABLE:
			cnf.status = ft_cct_6238_isp_get_pca_table(req, &cnf, &peer_buff_ret);
			break;
		case FT_CCT_6238_OP_ISP_SET_PCA_PARA:
			cnf.status = ft_cct_set_pca_para(req);
			break;
		case FT_CCT_6238_OP_ISP_GET_PCA_PARA:
			cnf.status = ft_cct_get_pca_para(&cnf);
			break;
		case FT_CCT_6238_OP_CHECK_PCA_SUPPORT:
			cnf.status = ft_cct_6238_check_if_PCA_support(&cnf);
			break;
		case FT_CCT_6238_OP_SET_CCM_MODE:
			cnf.status = ft_cct_6238_set_ccm_mode(req);
			break;
		case FT_CCT_6238_OP_GET_CCM_MODE:
			cnf.status = ft_cct_6238_get_ccm_mode(&cnf);
			break;
		case FT_CCT_OP_CHECK_ASD_PCA_SUPPORT:
			cnf.status = ft_cct_6238_check_if_ASD_PCA_support(&cnf);
			break;
		case FT_CCT_OP_ISP_SET_PCA_TABLE_IDX:
			cnf.status = ft_cct_isp_set_PCA_TABLE_IDX(req);
			break;
		case FT_CCT_OP_ISP_GET_PCA_TABLE_IDX:
			cnf.status = ft_cct_isp_get_PCA_TABLE_IDX(&cnf);
			break;
		default:
			cnf.status = FT_CCT_ERR_NOT_IMPLEMENT_YET;
			break;
	}


       ft_cct_6238_send_back_confirm_message(req, &cnf, peer_buff_ret);
	ft_cct_6238_send_captured_data_by_usb(req, &cnf);

}

kal_bool  isp_cct_is_gamma_table_supported(void) {
	return KAL_FALSE;
}

kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code)//,FT_UTILITY_COMMAND_CNF  *cnf)
{

	kal_uint8	ret = FT_CNF_FAIL;//FT_CNF_OK;

    if( FT_CCT_OP_END > query_op_code ) 
    {
            switch(query_op_code) {
                case FT_CCT_OP_SINGLE_SHOT_CAPTURE:
                case FT_CCT_OP_MULTI_SHOT_CAPTURE:
                    // not support
                    ret = FT_CNF_FAIL;
                    break;
                case FT_CCT_OP_SET_CAPTURE_DATA_TUNNEL:
                case FT_CCT_OP_USB_TUNNEL_CANCEL:
                case FT_CCT_OP_ENABLE_USBCOM:
                    if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support()){
                        ret = FT_CNF_OK;
                    }else{
                        ret = FT_CNF_FAIL;
                    }
                    break;
                case FT_CCT_OP_GET_GAMMA_TABLE:
                case FT_CCT_OP_SET_GAMMA_TABLE:
                case FT_CCT_OP_GET_GAMMA_TABLE_ON_OFF_FLAG:
                case FT_CCT_OP_SET_GAMMA_TABLE_ON_OFF_FLAG:
                    // check if isp supports gamma table
                    if(isp_cct_is_gamma_table_supported()) {
                        ret = FT_CNF_OK;
                    } 
                    break;
                case FT_CCT_OP_GET_COMPENSATION_MODE:
                case FT_CCT_OP_SET_COMPENSATION_MODE:
                    // check if isp supports shading and auto-defect compensation
                    if( isp_cct_is_shading_supported() || isp_cct_is_autodefect_supported() ) {
                        ret = FT_CNF_OK;
                    }
                    break;
                case FT_CCT_OP_GET_SHADING_PARA:
                case FT_CCT_OP_SET_SHADING_PARA:
                    // check if isp supports shading compensation
                    if(isp_cct_is_shading_supported()) {
                        ret = FT_CNF_OK;
                    }
                    break;
                case FT_CCT_OP_GET_AUTODEFECT_PARA:
                case FT_CCT_OP_SET_AUTODEFECT_PARA:
                    // check if isp supports auto-defect compensation
                    if(isp_cct_is_autodefect_supported()) {
                        ret = FT_CNF_OK;
                    }
                    break;
                case FT_CCT_OP_GET_AUTODEFECT_COUNT:
                    // check if isp supports auto-defect count
                    if(isp_cct_is_autodefct_count_supported()) {
                        ret = FT_CNF_OK;
                    }
                    break;
                case FT_CCT_OP_DEFECT_TABLE_VERIFY_BLOCK_FACTOR:
                case FT_CCT_OP_DEFECT_TABLE_CAL:
                case FT_CCT_OP_GET_DEFECT_TABLE:
                case FT_CCT_OP_SET_DEFECT_TABLE:
                case FT_CCT_OP_DEV_GET_DSC_INFO:
                case FT_CCT_OP_DEV_GET_IRIS_INFO:
                case FT_CCT_OP_DEV_SET_IRIS_INFO:
                case FT_CCT_OP_DEV_AE_GET_INFO:
                case FT_CCT_OP_DEV_AE_SET_TABLE_IDX:
                case FT_CCT_OP_DEV_AE_SET_VALUE:
                case FT_CCT_OP_DEV_STROBE_CAL_ENABLE:
                case FT_CCT_OP_DEV_STROBE_CAL_SET_PARA:
                case FT_CCT_OP_DEV_STROBE_CAL_DISABLE:
                case FT_CCT_OP_DEFECT_TABLE_ON_OFF:
                case FT_CCT_OP_DEFECT_TABLE_BYPASS_BACKUP_SETTING:
                case FT_CCT_OP_DEFECT_TABLE_RESTORE_SETTING:
                case FT_CCT_OP_DEV_AE_BYPASS_FREERUN:
                case FT_CCT_OP_AE_GET_PERIOD_PARA:
                case FT_CCT_OP_AE_SET_PERIOD_PARA:
                case FT_CCT_OP_DEV_AE_SET_SCENE_MODE:
#if (!defined(MT6219))
                    ret = FT_CNF_OK;
#endif
                    break;
                case FT_CCT_OP_DEV_AF_GET_TABLE:
                case FT_CCT_OP_DEV_AF_CAL:
                case FT_CCT_OP_DEV_AF_SET_TABLE_IDX:
                case FT_CCT_OP_DEV_AF_SET_POS:
                case FT_CCT_OP_AF_ON_OFF:
                case FT_CCT_OP_AF_LENS_OFFSET_CAL:
                    if(isp_cct_is_cct_af_support()) {
                        ret = FT_CNF_OK;
                    }
                    break;
                default:
                    ret = FT_CNF_OK;
                    break;
            }
        }
        //return FT_CNF_FAIL;
        return  ret;
}

void ft_cct_proc_ae_awb(void) {
#if defined(RAW_MAIN_CAMERA)	
	//ae_awb_main();
#endif
}

void ft_cct_usb_communication(ilm_struct* ptrMsg)
{
    //return;
#ifdef __USB_COM_PORT_ENABLE__
    if(KAL_TRUE == custom_ft_util_check_if_usb_enable_support())	
	{
		switch(ptrMsg->msg_id) {
		case MSG_ID_USB_FT_IND:
			// stop USB_COM TX DMA 
			USB2UART_FT_Tx_Stop();
	   		// USB_COM is ready 
	   		g_FT_CCT_StateMachine.usb_ready = KAL_TRUE;
	   		break;
		case MSG_ID_USB_FT_RX_DATA_IND:
		{
			kal_uint8	tmp_buf[16];
			kal_uint16	read_len;
			// read data via USB_COM 
			read_len = USB2UART_FT_Rx_Byte((kal_uint8 *)tmp_buf, (kal_uint16)sizeof(tmp_buf));
			if( FT_CCT_USB_SYNC_PATTERN_LEN <= read_len ) {
				if(!strncmp((kal_char*)tmp_buf, usb_sync_pattern, FT_CCT_USB_SYNC_PATTERN_LEN)) {
					// send back sync pattern 
					USB2UART_FT_Tx_Byte((kal_uint8 *)usb_sync_pattern, (kal_uint16)FT_CCT_USB_SYNC_PATTERN_LEN);
				}
			}
	   		break;
		}
		case MSG_ID_USB_FT_TX_DONE_IND:
			// if the last packet was sent 
			if( USB_TUNNEL_FINISH == g_FT_CCT_StateMachine.usb_tunnel_state ) {
				// send extra one byte to flush out PC side driver data 
				//kal_uint8	ch=0xFF;
				USB2UART_FT_Tx_Byte((kal_uint8*)&ch, (kal_uint16)1);
				g_FT_CCT_StateMachine.usb_tunnel_state = USB_TUNNEL_IDLE;
			}
			else if( USB_TUNNEL_SENDING == g_FT_CCT_StateMachine.usb_tunnel_state ) {
				// continue to send unfinish data to USB_COM 
				g_FT_CCT_StateMachine.usb_ready_to_write_cnt++;
				ft_cct_usb_tunnel_send(KAL_FALSE);
			}
	   		break;
	   	default:
	   		break;
   		}
   }

#else
   return;
#endif
}

#else

void FT_CCT_Operation(const FT_CCT_REQ *req, peer_buff_struct *peer_buff_in)
{
    EXT_ASSERT(KAL_FALSE, 0, 0, 0);
    return;
}

kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code)
{
    return FT_CNF_FAIL;
}

void ft_cct_proc_ae_awb(void)
{
	return;
}

void ft_cct_usb_communication(ilm_struct* ptrMsg)
{
    return;
}
#endif
