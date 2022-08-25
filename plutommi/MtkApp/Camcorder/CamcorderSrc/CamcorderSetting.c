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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CamcoSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camcorder Setting Module
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef MMI_CAMCOSETTING_C
#define MMI_CAMCOSETTING_C

#include "MMI_include.h"
#ifdef __MMI_CAMCORDER__

#include "mmi_features_camcorder.h"
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_video.h"

#include "CamcorderResDef.h"
#include "CamcorderSettingHdlr.h"
#include "CamcorderSetting.h"
#ifdef __MMI_CAMCO_FTE__
#include "CamcorderFTEOSD.h"
#else 
#include "CamcorderOSD.h"
#endif 
#include "CamcorderApp.h" 
#include "FileMgrGProt.h"
#include "FileManagerResDef.h"
#include "RestoreGprot.h"
#include "custom_nvram_config.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "cal_comm_def.h"
#include "med_api.h"
#include "kal_public_api.h"
#include "med_struct.h"
#include "DebugInitDef_Int.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "string.h"
#include "mmi_rp_app_camco_def.h"
#include "GlobalResDef.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrResDef.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "mmi_pluto_res_range_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* consol debug */
#define MMI_CAMCO_SETTING_CONSOL_DEBUG
#ifdef MMI_CAMCO_SETTING_CONSOL_DEBUG
#define MMI_CAMCO_DEBUG_PRINT(__str__) mmi_camco_print_unicode_debug_info((CHAR*)__str__);
#else 
#define MMI_CAMCO_DEBUG_PRINT(__str__)
#endif 

#define MMI_CAMCO_SETTING_DUMMY_VALUE   (0xFFFF)

typedef mdi_camera_sensor_general_info mmi_camco_cap_info;
typedef mdi_camera_zoom_info mmi_camco_zoom_info;

#if defined(HORIZONTAL_CAMERA)

#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
MMI_BOOL mmi_camco_capmode_vs_capsize[MMI_CAMCO_CAPMODE_END][MMI_CAMCO_CAPSIZE_END] = 
{
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},    
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE}, //{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1, 1, 1, 0, 0, 0, 0, 0},
   {MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 0, 0, 0, 0, 0, 0, 0},
   {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
   {MMI_FALSE, MMI_FALSE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{0, 0, 1, 0, 0, 0, 0, 0},       
    {MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1, 1, 0, 0, 0, 0, 0, 0}, 
   {MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1, 1, 0, 0, 0, 0, 0, 0}, 
   {MMI_FALSE, MMI_FALSE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{0, 0, 1, 1, 1, 0, 0, 0},
};

#ifdef __FACE_DETECTION_SUPPORT__
MMI_BOOL mmi_camco_facedetect_vs_capsize[MMI_CAMCO_FACEDETECT_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
};
#endif /* __FACE_DETECTION_SUPPORT__ */ 
#else 
MMI_BOOL mmi_camco_capmode_vs_capsize[MMI_CAMCO_CAPMODE_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE},//{1, 1, 1, 1, 1, 1, 0, 0},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_FALSE, MMI_FALSE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 0, 1, 0, 0, 0, 0, 0},      
	{MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1, 1, 0, 0, 0, 0, 0, 0}, 
	{MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1, 1, 0, 0, 0, 0, 0, 0}, 
    {MMI_FALSE, MMI_FALSE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 0, 1, 1, 1, 0, 0, 0},
};

#ifdef __FACE_DETECTION_SUPPORT__
MMI_BOOL mmi_camco_facedetect_vs_capsize[MMI_CAMCO_FACEDETECT_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1, 1},
};
#endif /* __FACE_DETECTION_SUPPORT__ */ 
#endif 
#else /* defined(HORIZONTAL_CAMERA) */ 
#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
MMI_BOOL mmi_camco_capmode_vs_capsize[MMI_CAMCO_CAPMODE_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{1, 1, 0, 0, 0, 0, 0},
    {MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 0, 0, 0, 0, 0, 0}
	{MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_FALSE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{0, 1, 0, 0, 0, 0, 0},   
	{MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1,0, 0, 0, 0, 0, 0, 0}, 
	{MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1,0, 0, 0, 0, 0, 0, 0}, 
    {MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 0, 0, 0, 0, 0, 0}, 
};

#ifdef __FACE_DETECTION_SUPPORT__
MMI_BOOL mmi_camco_facedetect_vs_capsize[MMI_CAMCO_FACEDETECT_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
};
#endif /* __FACE_DETECTION_SUPPORT__ */ 
#else 
MMI_BOOL mmi_camco_capmode_vs_capsize[MMI_CAMCO_CAPMODE_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE},//{1, 1, 1, 1, 1, 0, 0},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_FALSE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 1, 0, 0, 0, 0, 0},    
	{MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1,0, 0, 0, 0, 0, 0, 0}, 
	{MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE}, //{1,0, 0, 0, 0, 0, 0, 0}, 
    {MMI_FALSE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE},//{0, 1, 1, 1, 0, 0, 0},
};

#ifdef __FACE_DETECTION_SUPPORT__
MMI_BOOL mmi_camco_facedetect_vs_capsize[MMI_CAMCO_FACEDETECT_END][MMI_CAMCO_CAPSIZE_END] = 
{
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
    {MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE},//{1, 1, 1, 1, 1, 1, 1},
};
#endif /* __FACE_DETECTION_SUPPORT__ */ 
#endif 
#endif /* defined(HORIZONTAL_CAMERA) */ 
MMI_BOOL mmi_camco_isobinning_vs_capsize[MMI_CAMCO_ISO_END][MMI_CAMCO_CAPSIZE_END];

MMI_BOOL mmi_camco_recsize_vs_codec_vs_qty[MMI_CAMCO_RECSIZE_END][MMI_CAMCO_VISCODEC_END][MMI_CAMCO_VISQTY_END];

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 mmi_camco_setting_cap_dimention_struct cap_dimention[MMI_CAMCO_CAPSIZE_END]=
{
   	{LCD_WIDTH, LCD_HEIGHT},
	#if defined(HORIZONTAL_CAMERA)
	{LCD_HEIGHT,LCD_WIDTH},
   	#endif
   	{640,480},
   	{1280,960},
  	{1600,1200},
   	{2048,1536},
   	{2304,1728},
   	{2592,1944},
};

mmi_camco_setting_cntx_struct g_mmi_camco_setting_cntx;
mmi_camco_setting_cntx_struct *const mmi_camco_setting_p = &g_mmi_camco_setting_cntx;

mmi_camco_setting_scene_sel_cntx_struct g_mmi_camco_setting_scene_sel_cntx;
mmi_camco_setting_scene_sel_cntx_struct *const mmi_camco_setting_scene_sel_p = &g_mmi_camco_setting_scene_sel_cntx;

/***************************************************************************** 
 * Local Function Prototype
 *****************************************************************************/
extern void mmi_camco_update_viscodec_capability(void);
extern void mmi_camco_update_visqty_capability(void);
extern void mmi_camco_update_recsize_capability(void);
static void mmi_camco_default_camev_capability(void);
static void mmi_camco_default_vdoev_capability(void);
static void mmi_camco_default_camzoom_capability(void);
static void mmi_camco_default_vdozoom_capability(void);
static void mmi_camco_setting_gen_camera_mainlist(mmi_camco_setting_mainlist_type_enum type);
static void mmi_camco_setting_apply_current_sensor_capability(
                mmi_camco_setting_cam_enum prev_cam,
                mmi_camco_setting_cam_enum curr_cam);
extern void mmi_camco_update_limit_capability(void);
extern void mmi_camco_update_capsize(void);
extern MMI_BOOL mmi_camco_is_from_external(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_print_unicode_debug_info
 * DESCRIPTION
 *  Print debug info to consol.
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_print_unicode_debug_info(CHAR *str_ptr)
{
#ifndef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ascii_buf[500];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* modis - convert to ascii and print to consol */
    mmi_ucs2_to_asc(ascii_buf, str_ptr);
    printf(ascii_buf);
#else /* __MTK_TARGET__ */ 

#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_target_translate_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_camco_setting_enum mmi_camco_custom_target_translate_to_mmi(recoorder_config_setting_target target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(target == SETTING_CONFIG_SETTING_QTY)
    {
        return MMI_CAMCO_SETTING_VISQTY;        
    }
    else if(target == SETTING_CONFIG_SETTING_CODEC)
    {
        return MMI_CAMCO_SETTING_VISCODEC;        
    }
    else if(target == SETTING_CONFIG_SETTING_RESOLUTION)
    {
        return MMI_CAMCO_SETTING_RECSIZE;        
    }    
    else
    {
        return MMI_CAMCO_SETTING_END;
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_target_translate_from_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
recoorder_config_setting_target mmi_camco_custom_target_translate_from_mmi(mmi_camco_setting_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(target == MMI_CAMCO_SETTING_VISQTY)
    {
        return SETTING_CONFIG_SETTING_QTY;        
    }
    else if(target == MMI_CAMCO_SETTING_VISCODEC)
    {
        return SETTING_CONFIG_SETTING_CODEC;        
    }
    else if(target == MMI_CAMCO_SETTING_RECSIZE)
    {
        return SETTING_CONFIG_SETTING_RESOLUTION;        
    }    
    else
    {
        return SETTING_CONFIG_TARGET_NONE;
    }
}    

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_value_translate_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_camco_custom_value_translate_to_mmi(recoorder_config_setting_value value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(value == SETTING_CONFIG_QTY_FINE)
    {
        return MMI_CAMCO_VISQTY_FINE;        
    }
    else if(value == SETTING_CONFIG_QTY_GOOD)
    {
        return MMI_CAMCO_VISQTY_GOOD;        
    }
    else if(value == SETTING_CONFIG_QTY_NORMAL)
    {
        return MMI_CAMCO_VISQTY_NORMAL;        
    }    
    else if(value == SETTING_CONFIG_QTY_LOW)
    {
        return MMI_CAMCO_VISQTY_LOW;        
    }        
#ifdef MMI_CAMCO_WALLPAPER
	else if(value == SETTING_CONFIG_QTY_LCD)
    {
        return MMI_CAMCO_VISQTY_LCD;        
    } 
#endif
    else if(value == SETTING_CONFIG_CODEC_MP4)
    {
        return MMI_CAMCO_VISCODEC_MP4;        
    }
    else if(value == SETTING_CONFIG_CODEC_3GP)
    {
        return MMI_CAMCO_VISCODEC_3GP;        
    }
    else if(value == SETTING_CONFIG_CODEC_MJPG)
    {
        return MMI_CAMCO_VISCODEC_MJPG;        
    }   
	else if(value == SETTING_CONFIG_CODEC_H264)
    {
        return MMI_CAMCO_VISCODEC_H264;    
    }  
    else if(value == SETTING_CONFIG_RESOLUTION_SQCIF)
    {
        return MMI_CAMCO_RECSIZE_SQCIF;        
    }        
    else if(value == SETTING_CONFIG_RESOLUTION_QQVGA)
    {
        return MMI_CAMCO_RECSIZE_QQVGA;        
    }       
    else if(value == SETTING_CONFIG_RESOLUTION_QCIF)
    {
        return MMI_CAMCO_RECSIZE_QCIF;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_QVGA)
    {
        return MMI_CAMCO_RECSIZE_QVGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_CIF)
    {
        return MMI_CAMCO_RECSIZE_CIF;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_WQVGA)
    {
        return MMI_CAMCO_RECSIZE_WQVGA;        
    }       
    else if(value == SETTING_CONFIG_RESOLUTION_CIF2)
    {
        return MMI_CAMCO_RECSIZE_CIF2;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_HVGA)
    {
        return MMI_CAMCO_RECSIZE_HVGA;        
    }           
    else if(value == SETTING_CONFIG_RESOLUTION_NHD)
    {
        return MMI_CAMCO_RECSIZE_NHD;        
    }        
    else if(value == SETTING_CONFIG_RESOLUTION_VGA)
    {
        return MMI_CAMCO_RECSIZE_VGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_D1)
    {
        return MMI_CAMCO_RECSIZE_D1;        
    }    
    else if(value == SETTING_CONFIG_RESOLUTION_D12)
    {
        return MMI_CAMCO_RECSIZE_D12;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_WVGA)
    {
        return MMI_CAMCO_RECSIZE_WVGA;        
    }      
    else if(value == SETTING_CONFIG_RESOLUTION_SVGA)
    {
        return MMI_CAMCO_RECSIZE_SVGA;        
    }    
    else if(value == SETTING_CONFIG_RESOLUTION_WVGA2)
    {
        return MMI_CAMCO_RECSIZE_WVGA2;        
    }          
    else if(value == SETTING_CONFIG_RESOLUTION_XGA)
    {
        return MMI_CAMCO_RECSIZE_XGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_720P)
    {
        return MMI_CAMCO_RECSIZE_720P;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_4VGA)
    {
        return MMI_CAMCO_RECSIZE_4VGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_SXGA)
    {
        return MMI_CAMCO_RECSIZE_SXGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_16CIF)
    {
        return MMI_CAMCO_RECSIZE_16CIF;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_4SVGA)
    {
        return MMI_CAMCO_RECSIZE_4SVGA;        
    }
    else if(value == SETTING_CONFIG_RESOLUTION_FHD)
    {
        return MMI_CAMCO_RECSIZE_FHD;        
    }    
    else if(value == SETTING_CONFIG_RESOLUTION_4CIF)
    {
        return MMI_CAMCO_RECSIZE_4CIF;        
    } 
    else if(value == SETTING_CONFIG_RESOLUTION_FWVGA)
    {
        return MMI_CAMCO_RECSIZE_FWVGA;        
    } 
#ifdef MMI_CAMCO_WALLPAPER
    else if(value == SETTING_CONFIG_RESOLUTION_WALLPAPER)
    {
        return MMI_CAMCO_RECSIZE_WALLPAPER;        
	}
#endif
    else
    {
        MMI_CAMCO_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_value_translate_from_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
recoorder_config_setting_value mmi_camco_custom_value_translate_from_mmi(U32 value, mmi_camco_setting_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(target == MMI_CAMCO_SETTING_VISQTY)
    {
        if(value == MMI_CAMCO_VISQTY_FINE)
        {
            return SETTING_CONFIG_QTY_FINE;        
        }
        else if(value == MMI_CAMCO_VISQTY_GOOD)
        {
            return SETTING_CONFIG_QTY_GOOD;        
        }
        else if(value == MMI_CAMCO_VISQTY_NORMAL)
        {
            return SETTING_CONFIG_QTY_NORMAL;        
        }    
        else if(value == MMI_CAMCO_VISQTY_LOW)
        {
            return SETTING_CONFIG_QTY_LOW;        
        }           
    #ifdef MMI_CAMCO_WALLPAPER
        else if(value == MMI_CAMCO_VISQTY_LCD)
        {
            return SETTING_CONFIG_QTY_LCD;        
        }  
	#endif
    }
    else if(target == MMI_CAMCO_SETTING_VISCODEC)
    {
        if(value == MMI_CAMCO_VISCODEC_MP4)
        {
            return SETTING_CONFIG_CODEC_MP4;        
        }
        else if(value == MMI_CAMCO_VISCODEC_3GP)
        {
            return SETTING_CONFIG_CODEC_3GP;        
        }
        else if(value == MMI_CAMCO_VISCODEC_MJPG)
        {
            return SETTING_CONFIG_CODEC_MJPG;        
        }      
        else if(value == MMI_CAMCO_VISCODEC_H264)
        {
            return SETTING_CONFIG_CODEC_H264;   
        }    		
    }
    else if(target == MMI_CAMCO_SETTING_RECSIZE)
    {
        if(value == MMI_CAMCO_RECSIZE_SQCIF)
        {
            return SETTING_CONFIG_RESOLUTION_SQCIF;        
        }            
        else if(value == MMI_CAMCO_RECSIZE_QQVGA)
        {
            return SETTING_CONFIG_RESOLUTION_QQVGA;        
        }       
        else if(value == MMI_CAMCO_RECSIZE_QCIF)
        {
            return SETTING_CONFIG_RESOLUTION_QCIF;        
        }
        else if(value == MMI_CAMCO_RECSIZE_QVGA)
        {
            return SETTING_CONFIG_RESOLUTION_QVGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_CIF)
        {
            return SETTING_CONFIG_RESOLUTION_CIF;        
        }
        else if(value == MMI_CAMCO_RECSIZE_WQVGA)
        {
            return SETTING_CONFIG_RESOLUTION_WQVGA;        
        }       
        else if(value == MMI_CAMCO_RECSIZE_CIF2)
        {
            return SETTING_CONFIG_RESOLUTION_CIF2;        
        }
        else if(value == MMI_CAMCO_RECSIZE_HVGA)
        {
            return SETTING_CONFIG_RESOLUTION_HVGA;        
        }           
        else if(value == MMI_CAMCO_RECSIZE_NHD)
        {
            return SETTING_CONFIG_RESOLUTION_NHD;        
        }        
        else if(value == MMI_CAMCO_RECSIZE_VGA)
        {
            return SETTING_CONFIG_RESOLUTION_VGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_D1)
        {
            return SETTING_CONFIG_RESOLUTION_D1;        
        }    
        else if(value == MMI_CAMCO_RECSIZE_D12)
        {
            return SETTING_CONFIG_RESOLUTION_D12;        
        }
        else if(value == MMI_CAMCO_RECSIZE_WVGA)
        {
            return SETTING_CONFIG_RESOLUTION_WVGA;        
        }      
        else if(value == MMI_CAMCO_RECSIZE_SVGA)
        {
            return SETTING_CONFIG_RESOLUTION_SVGA;        
        }    
        else if(value == MMI_CAMCO_RECSIZE_WVGA2)
        {
            return SETTING_CONFIG_RESOLUTION_WVGA2;        
        }          
        else if(value == MMI_CAMCO_RECSIZE_XGA)
        {
            return SETTING_CONFIG_RESOLUTION_XGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_720P)
        {
            return SETTING_CONFIG_RESOLUTION_720P;        
        }
        else if(value == MMI_CAMCO_RECSIZE_4VGA)
        {
            return SETTING_CONFIG_RESOLUTION_4VGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_SXGA)
        {
            return SETTING_CONFIG_RESOLUTION_SXGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_16CIF)
        {
            return SETTING_CONFIG_RESOLUTION_16CIF;        
        }
        else if(value == MMI_CAMCO_RECSIZE_4SVGA)
        {
            return SETTING_CONFIG_RESOLUTION_4SVGA;        
        }
        else if(value == MMI_CAMCO_RECSIZE_FHD)
        {
            return SETTING_CONFIG_RESOLUTION_FHD;        
        }
        else if(value == MMI_CAMCO_RECSIZE_4CIF)
        {
            return SETTING_CONFIG_RESOLUTION_4CIF;        
        } 
        else if(value == MMI_CAMCO_RECSIZE_FWVGA)
        {
            return SETTING_CONFIG_RESOLUTION_FWVGA;        
        } 
		
	#ifdef MMI_CAMCO_WALLPAPER
		else if(value == MMI_CAMCO_RECSIZE_WALLPAPER)
		{
			return SETTING_CONFIG_RESOLUTION_WALLPAPER; 	   
		}
	#endif
          
    }
    else
    {
        ASSERT(0);
		return SETTING_CONFIG_VALUE_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_get_depended_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_custom_get_depended_set(recoorder_config_setting_set* set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_enum key_setting;
    recoorder_config_setting_value key_setting_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    key_setting = mmi_camco_custom_target_translate_to_mmi(recorder_config_get_key());
    key_setting_value = mmi_camco_custom_value_translate_from_mmi(mmi_camco_setting_get_setting_value(key_setting), key_setting);

    recorder_config_get_setting_set(key_setting_value, set);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_get_depended_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
recoorder_config_setting_value mmi_camco_custom_get_depended_setting(recoorder_config_setting_target target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_enum key_setting;
    recoorder_config_setting_value key_setting_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    key_setting = mmi_camco_custom_target_translate_to_mmi(recorder_config_get_key());
    key_setting_value = mmi_camco_custom_value_translate_from_mmi(mmi_camco_setting_get_setting_value(key_setting), key_setting);

    return recorder_config_get_setting(key_setting_value, target);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_set_depended_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_custom_set_depended_setting(recoorder_config_setting_target target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recoorder_config_setting_value depended_setting_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    depended_setting_value = mmi_camco_custom_get_depended_setting(target);
    
    if(target == SETTING_CONFIG_SETTING_QTY)
    {
        mmi_camco_setting_p->visqty.cur_value = mmi_camco_custom_value_translate_to_mmi(depended_setting_value);     
    }
    else if(target == SETTING_CONFIG_SETTING_CODEC)
    {
        mmi_camco_setting_p->viscodec.cur_value = mmi_camco_custom_value_translate_to_mmi(depended_setting_value);    
    }
    else if(target == SETTING_CONFIG_SETTING_RESOLUTION)
    {
        mmi_camco_setting_p->recsize.cur_value = mmi_camco_custom_value_translate_to_mmi(depended_setting_value);    
    }    
    else
    {
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_set_key_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_custom_set_key_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recoorder_config_setting_target key_setting;
    recoorder_config_setting_value key_setting_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_setting = recorder_config_get_key();
    key_setting_value = recorder_config_get_default_key_value();
    
    if(key_setting == SETTING_CONFIG_SETTING_QTY)
    {
        if(mmi_camco_setting_p->visqty.cur_value == 0Xff)
            mmi_camco_setting_p->visqty.cur_value = mmi_camco_custom_value_translate_to_mmi(key_setting_value);     
    }
    else if(key_setting == SETTING_CONFIG_SETTING_CODEC)
    {
        if(mmi_camco_setting_p->viscodec.cur_value == 0Xff)    
            mmi_camco_setting_p->viscodec.cur_value = mmi_camco_custom_value_translate_to_mmi(key_setting_value);    
    }
    else if(key_setting == SETTING_CONFIG_SETTING_RESOLUTION)
    {
        if(mmi_camco_setting_p->recsize.cur_value == 0Xff)    
            mmi_camco_setting_p->recsize.cur_value = mmi_camco_custom_value_translate_to_mmi(key_setting_value);    
    }    
    else
    {
        ASSERT(0);
    }
}     


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_update_depended_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_custom_update_depended_setting(recoorder_config_setting_target target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(target == SETTING_CONFIG_SETTING_QTY)
    {
        mmi_camco_update_visqty(mmi_camco_setting_p->visqty.cur_value);
    }
    else if(target == SETTING_CONFIG_SETTING_CODEC)
    {
		mmi_camco_update_visformat(mmi_camco_setting_p->recsize.cur_value); 
    }
    else if(target == SETTING_CONFIG_SETTING_RESOLUTION)
    {
        mmi_camco_update_vdosize(mmi_camco_setting_p->recsize.cur_value);    
    }    
    else
    {
    }
}  

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_custom_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_custom_update(recoorder_config_setting_target target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recoorder_config_setting_set setting_set;
    U16 i;            

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(recorder_config_is_key(mmi_camco_custom_target_translate_from_mmi((mmi_camco_setting_enum)target)) == KAL_TRUE)
    {

        mmi_camco_custom_get_depended_set(&setting_set);
        for(i=0;i<setting_set.count;i++)
        {
            mmi_camco_custom_set_depended_setting(setting_set.target[i]);
        }
        mmi_camco_setting_store_to_nvram();        
        for(i=0;i<setting_set.count;i++)
        {
            mmi_camco_custom_update_depended_setting(setting_set.target[i]);            
        } 
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_capmode_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_capmode_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 capmode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        capmode = cap_info->support_item[idx];
        switch (capmode)
        {
            case MDI_CAMERA_CAP_MODE_NORMAL:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_NORMAL;
                break;

            case MDI_CAMERA_CAP_MODE_BEST_SHOT:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_BEST_SHOT;
                break;

            case MDI_CAMERA_CAP_MODE_CONT_SHOT:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_CONT_SHOT;
                break;

            case MDI_CAMERA_CAP_MODE_BURST_SHOT:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_BURST_SHOT_SEL;
                break;

            case MDI_CAMERA_CAP_MODE_EV_BRACKETING:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_EV_BRACKET_SEL;
                break;

            case MDI_CAMERA_CAP_MODE_ADD_FRAME:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_ADD_FRAME;
                break;

            case MDI_CAMERA_CAP_MODE_PANORAMA:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_AUTORAMA;
                break;

            case MDI_CAMERA_CAP_MODE_SMILE_SHOT:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_SMILE_SHOT;
                break;

            case MDI_CAMERA_CAP_MODE_HDR:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_HDR_SHOT;
                break;
                
            case MDI_CAMERA_CAP_MODE_ZSD:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_ZSD_SHOT;
                break;
             case MDI_CAMERA_CAP_MODE_ASD:
                cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_ASD_SHOT;
                break;
			case MDI_CAMERA_CAP_MODE_MAV:
				cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_MAV;
				break;
			case MDI_CAMERA_CAP_MODE_3D_IMAGE:
				cap_info->support_item[idx] = MMI_CAMCO_CAPMODE_3D_IMAGE;
				break;
            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_camscenemode_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_camscenemode_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 camscenemode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        camscenemode = cap_info->support_item[idx];
        switch (camscenemode)
        {
            case MDI_CAMERA_SCENE_MODE_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_AUTO;
                break;

            case MDI_CAMERA_SCENE_MODE_PORTRAIT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_PORTRAIT;
                break;

            case MDI_CAMERA_SCENE_MODE_LANDSCAPE:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_LANDSCAPE;
                break;

            case MDI_CAMERA_SCENE_MODE_SPORT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_SPORT;
                break;

            case MDI_CAMERA_SCENE_MODE_NIGHT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_NIGHT;
                break;                
            case MDI_CAMERA_SCENE_MODE_DOCUMENT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_DOCUMENT;
                break;

            case MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE;
                break;
             case MDI_CAMERA_SCENE_MODE_FLOWER:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_FLOWER;
                break;
                
             case MDI_CAMERA_SCENE_MODE_BACKLIGHT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_BACKLIGHT;
                break;
                
             case MDI_CAMERA_SCENE_MODE_BACKLIGHT_PORTRAIT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT;
                break;
                
             case MDI_CAMERA_SCENE_MODE_NIGHT_PORTRAIT:
                cap_info->support_item[idx] = MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT;
                break;
            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}

extern void  mmi_camco_cam_setting_get_setting_dimention(U16 capsize, U16 *width_p, U16 *height_p)
{

    (*width_p) = cap_dimention[capsize].image_width;
    (*height_p)= cap_dimention[capsize].image_height;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_capsize_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_capsize_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 capsize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        capsize = cap_info->support_item[idx];
        switch (capsize)
        {
            case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_WALLPAPER;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_WALLPAPER] = MMI_CAMCO_CAPSIZE_WALLPAPER;
                break;

            case MDI_CAMERA_CAP_SIZE_VGA:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_VGA;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_VGA] = MMI_CAMCO_CAPSIZE_VGA;
                break;

            case MDI_CAMERA_CAP_SIZE_1M:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_1MP;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_1M] = MMI_CAMCO_CAPSIZE_1MP;
                break;

            case MDI_CAMERA_CAP_SIZE_2M:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_2MP;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_2M] = MMI_CAMCO_CAPSIZE_2MP;
                break;

            case MDI_CAMERA_CAP_SIZE_3M:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_3MP;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_3M] = MMI_CAMCO_CAPSIZE_3MP;
                break;

            case MDI_CAMERA_CAP_SIZE_4M:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_4MP;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_4M] = MMI_CAMCO_CAPSIZE_4MP;
                break;

            case MDI_CAMERA_CAP_SIZE_5M:
                cap_info->support_item[idx] = MMI_CAMCO_CAPSIZE_5MP;
                mmi_camco_setting_p->mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_5M] = MMI_CAMCO_CAPSIZE_5MP;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_flash_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_flash_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 flash = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        flash = cap_info->support_item[idx];
        switch (flash)
        {
            case MDI_CAMERA_FLASH_OFF:
                cap_info->support_item[idx] = MMI_CAMCO_FLASH_OFF;
                break;

            case MDI_CAMERA_FLASH_ON:
                cap_info->support_item[idx] = MMI_CAMCO_FLASH_FORCE_ON;
                break;

            case MDI_CAMERA_FLASH_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_FLASH_AUTO;
                break;

            case MDI_CAMERA_FLASH_REDEYE:
                cap_info->support_item[idx] = MMI_CAMCO_FLASH_RED_EYE;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_afrange_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_afrange_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 afrange = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        afrange = cap_info->support_item[idx];
        switch (afrange)
        {
            case MDI_CAMERA_AF_RANGE_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_AFRANGE_AUTO;
                break;

            case MDI_CAMERA_AF_RANGE_MACRO:
                cap_info->support_item[idx] = MMI_CAMCO_AFRANGE_MACRO;
                break;

            case MDI_CAMERA_AF_RANGE_LANDSCAPE:
                cap_info->support_item[idx] = MMI_CAMCO_AFRANGE_INFINTE;
                break;
            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_iso_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_iso_cap(mdi_camera_sensor_iso_binning_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    mmi_camco_iso_enum iso = MMI_CAMCO_ISO_AUTO;
    mmi_camco_setting_cap_enum cap_value;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->IsoBinningInfo[MDI_CAMERA_ISO_AUTO].IsoSupported)
    {
        return MMI_FALSE;
    }

    mmi_camco_setting_p->iso.cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    
    for (idx = 0; idx < MDI_CAMERA_ISO_COUNT; idx++)
    {
        cap_value = MMI_CAMCO_SETTING_CAP_DISABLED;
        
        if (cap_info->IsoBinningInfo[idx].IsoSupported)
        {
            cap_value = MMI_CAMCO_SETTING_CAP_ENABLED;
        }

        switch (idx)
        {
            case MDI_CAMERA_ISO_AUTO:
                iso = MMI_CAMCO_ISO_AUTO;
                break;

            case MDI_CAMERA_ISO_100:
                iso = MMI_CAMCO_ISO_100;
                break;

            case MDI_CAMERA_ISO_200:
                iso = MMI_CAMCO_ISO_200;
                break;

            case MDI_CAMERA_ISO_400:
                iso = MMI_CAMCO_ISO_400;
                break;
            case MDI_CAMERA_ISO_800:
                iso = MMI_CAMCO_ISO_800;
                break;

            case MDI_CAMERA_ISO_1600:
                iso = MMI_CAMCO_ISO_1600;
                break;
            default:
                break;
        }
        
        mmi_camco_setting_p->iso.item_cap[iso] = cap_value;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_wb_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_wb_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 wb = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        wb = cap_info->support_item[idx];
        switch (wb)
        {
            case MDI_CAMERA_WB_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_WB_AUTO;
                break;

            case MDI_CAMERA_WB_DAYLIGHT:
                cap_info->support_item[idx] = MMI_CAMCO_WB_DAYLIGHT;
                break;

            case MDI_CAMERA_WB_TUNGSTEN:
                cap_info->support_item[idx] = MMI_CAMCO_WB_TUNGSTEN;
                break;

            case MDI_CAMERA_WB_FLUORESCENT:
                cap_info->support_item[idx] = MMI_CAMCO_WB_FLUORESCENT;
                break;

            case MDI_CAMERA_WB_CLOUD:
                cap_info->support_item[idx] = MMI_CAMCO_WB_CLOUDY;
                break;

            case MDI_CAMERA_WB_INCANDESCENCE:
                cap_info->support_item[idx] = MMI_CAMCO_WB_INCANDESCENT;
                break;

            case MDI_CAMERA_WB_MANUAL:
                cap_info->support_item[idx] = MMI_CAMCO_WB_AUTO;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_effect_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_effect_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 effect = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        effect = cap_info->support_item[idx];
        switch (effect)
        {
            case MDI_CAMERA_EFFECT_NOMRAL:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_NORMAL;
                break;

            case MDI_CAMERA_EFFECT_LOMO:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_LOMO;
                break;           

            case MDI_CAMERA_EFFECT_COLOR_RED:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_RED_ACCENT;
                break;           

            case MDI_CAMERA_EFFECT_COLOR_BLUE:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_GREEN_ACCENT;
                break;           

            case MDI_CAMERA_EFFECT_COLOR_GREEN:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_YELLOW_ACCENT;
                break;            

            case MDI_CAMERA_EFFECT_COLOR_YELLOW:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_BLUE_ACCENT;
                break;

            case MDI_CAMERA_EFFECT_GRAYSCALE:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_GRAYSCALE;
                break;

            case MDI_CAMERA_EFFECT_SEPIA:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_SEPIA;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_GREEN:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_SEPIA_GREEN;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_BLUE:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_SEPIA_BLUE;
                break;

            case MDI_CAMERA_EFFECT_COLOR_INVERT:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_COLOR_INVERT;
                break;

            case MDI_CAMERA_EFFECT_GRAY_INVERT:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_GRAY_INVERT;
                break;

            case MDI_CAMERA_EFFECT_BLACKBOARD:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_BLACKBOARD;
                break;

            case MDI_CAMERA_EFFECT_WHITEBOARD:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_WHITEBOARD;
                break;

            case MDI_CAMERA_EFFECT_COPPER_CARVING:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_COPPER_CARVING;
                break;

            case MDI_CAMERA_EFFECT_BLUE_CARVING:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_BLUE_CARVING;
                break;

            case MDI_CAMERA_EFFECT_EMBOSSMENT:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_EMBOSSMENT;
                break;

            case MDI_CAMERA_EFFECT_CONTRAST:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_CONTRAST;
                break;

            case MDI_CAMERA_EFFECT_JEAN:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_JEAN;
                break;

            case MDI_CAMERA_EFFECT_SKETCH:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_SKETCH;
                break;

            case MDI_CAMERA_EFFECT_OIL:
                cap_info->support_item[idx] = MMI_CAMCO_EFFECT_OIL;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_aemeter_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_aemeter_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 aemeter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        aemeter = cap_info->support_item[idx];
        switch (aemeter)
        {
            case MDI_CAMERA_AE_METER_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_AEMETER_AUTO;
                break;

            case MDI_CAMERA_AE_METER_SPOT:
                cap_info->support_item[idx] = MMI_CAMCO_AEMETER_SPOT;
                break;

            case MDI_CAMERA_AE_METER_CENTER:
                cap_info->support_item[idx] = MMI_CAMCO_AEMETER_CENTER_WEIGHT;
                break;

            case MDI_CAMERA_AE_METER_AVERAGE:
                cap_info->support_item[idx] = MMI_CAMCO_AEMETER_AVERAGE;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_sharpness_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_sharpness_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 sharpness = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        sharpness = cap_info->support_item[idx];
        switch (sharpness)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = MMI_CAMCO_SHARPNESS_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = MMI_CAMCO_SHARPNESS_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = MMI_CAMCO_SHARPNESS_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_contrast_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_contrast_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 contrast = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        contrast = cap_info->support_item[idx];
        switch (contrast)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = MMI_CAMCO_CONTRAST_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = MMI_CAMCO_CONTRAST_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = MMI_CAMCO_CONTRAST_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_saturation_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_saturation_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 saturation = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        saturation = cap_info->support_item[idx];
        switch (saturation)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = MMI_CAMCO_SATURATION_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = MMI_CAMCO_SATURATION_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = MMI_CAMCO_SATURATION_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_vdoscenemode_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_vdoscenemode_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 vdoscenemode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        vdoscenemode = cap_info->support_item[idx];
        switch (vdoscenemode)
        {
            case MDI_CAMERA_SCENE_MODE_VIDEO_AUTO:
                cap_info->support_item[idx] = MMI_CAMCO_VDOSCENEMODE_AUTO;
                break;

            case MDI_CAMERA_SCENE_MODE_VIDEO_NIGHT:
                cap_info->support_item[idx] = MMI_CAMCO_VDOSCENEMODE_NIGHT;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_afmode_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_afmode_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 afmode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        afmode = cap_info->support_item[idx];
        switch (afmode)
        {
            case MDI_CAMERA_AF_OPERATION_MODE_OFF:
                cap_info->support_item[idx] = MMI_CAMCO_AFMODE_OFF;
                break;

            case MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE:
                cap_info->support_item[idx] = MMI_CAMCO_AFMODE_SINGLE;
                break;

            case MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS:
                cap_info->support_item[idx] = MMI_CAMCO_AFMODE_CONT;
                break;
            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_afzone_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_afzone_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 afzone = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        afzone = cap_info->support_item[idx];
        switch (afzone)
        {
            case MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE:
                cap_info->support_item[idx] = MMI_CAMCO_AFZONE_SINGLE;
                break;

            case MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE:
                cap_info->support_item[idx] = MMI_CAMCO_AFZONE_MULTI;
                break;
                
            case MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS:
                cap_info->support_item[idx] = MMI_CAMCO_AFZONE_CONTINUE;
                break;          
            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_timestamp_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_timestamp_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
	else
	{
		cap_info->item_count = 2;
        cap_info->support_item[0] = MMI_CAMCO_TIMESTAMP_OFF;
        cap_info->support_item[1] = MMI_CAMCO_TIMESTAMP_ON;

		return MMI_TRUE;
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_translate_ev_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_translate_ev_cap(mmi_camco_cap_info *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    U16 ev = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        ev = cap_info->support_item[idx];
        switch (ev)
        {
            case MDI_CAMERA_EV_N4:
                cap_info->support_item[idx] = MMI_CAMCO_EV_N4;
                break;

            case MDI_CAMERA_EV_N3:
                cap_info->support_item[idx] = MMI_CAMCO_EV_N3;
                break;

            case MDI_CAMERA_EV_N2:
                cap_info->support_item[idx] = MMI_CAMCO_EV_N2;
                break;

            case MDI_CAMERA_EV_N1:
                cap_info->support_item[idx] = MMI_CAMCO_EV_N1;
                break;

            case MDI_CAMERA_EV_0:
                cap_info->support_item[idx] = MMI_CAMCO_EV_0;
                break;

            case MDI_CAMERA_EV_P1:
                cap_info->support_item[idx] = MMI_CAMCO_EV_P1;
                break;

            case MDI_CAMERA_EV_P2:
                cap_info->support_item[idx] = MMI_CAMCO_EV_P2;
                break;

            case MDI_CAMERA_EV_P3:
                cap_info->support_item[idx] = MMI_CAMCO_EV_P3;
                break;

            case MDI_CAMERA_EV_P4:
                cap_info->support_item[idx] = MMI_CAMCO_EV_P4;
                break;

            default:
                cap_info->support_item[idx] = MMI_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_query_capbility
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting         [IN]        
 *  cap_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_camco_setting_query_capbility(mmi_camco_setting_enum setting, void *cap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_set_camera_id(mmi_camco_setting_p->active_cam);

    if(mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        switch (setting)
        {
            case MMI_CAMCO_SETTING_CAPMODE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_capmode_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAMSCENEMODE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAMSCENE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_camscenemode_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAPSIZE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPSIZE_WITH_DIMENSION, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_capsize_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_FLASH:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_FLASH, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_flash_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AFRANGE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFRANGE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afrange_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AFZONE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afzone_cap((mmi_camco_cap_info *)cap_info);
               // break;

            case MMI_CAMCO_SETTING_ISO:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_ISO, (void*)cap_info);
                return mmi_camco_setting_translate_iso_cap((mdi_camera_sensor_iso_binning_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_WB:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_WB, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_wb_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_EFFECT:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_EFFECT, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_effect_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AEMETER:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_AEMETER, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_aemeter_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_SHARPNESS:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_SHARPNESS, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_sharpness_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CONTRAST:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_CONTRAST, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_contrast_cap((mmi_camco_cap_info *)cap_info);
               // break;

            case MMI_CAMCO_SETTING_SATURATION:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_SATURATION, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_saturation_cap((mmi_camco_cap_info *)cap_info);
               // break;

            case MMI_CAMCO_SETTING_VDOSCENEMODE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_VIDEOSCENE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_vdoscenemode_cap((mmi_camco_cap_info *)cap_info);
                //break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            case MMI_CAMCO_SETTING_AFMODE:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afmode_cap((mmi_camco_cap_info *)cap_info);
               // break;

            case MMI_CAMCO_SETTING_TIMESTAMP:				
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAP_OVERLAY, (void*)cap_info);
                return mmi_camco_setting_translate_timestamp_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAMEV:
            case MMI_CAMCO_SETTING_VDOEV:
                mdi_camera_query_support_info(MDI_CAMERA_SETTING_EV, (void*)cap_info);
                return mmi_camco_setting_translate_ev_cap((mmi_camco_cap_info *)cap_info);
                //break;

            default:
                MMI_CAMCO_ASSERT(0);
                //break;
        }
    }
    else
    {
        switch (setting)
        {
            case MMI_CAMCO_SETTING_CAPMODE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CAPMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_capmode_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAMSCENEMODE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CAMSCENE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_camscenemode_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAPSIZE:
                mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_CAPSIZE_WITH_DIMENSION, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_capsize_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_FLASH:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_FLASH, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_flash_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AFRANGE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFRANGE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afrange_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AFZONE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afzone_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_ISO:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_ISO, (void*)cap_info);
                return mmi_camco_setting_translate_iso_cap((mdi_camera_sensor_iso_binning_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_WB:
                mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_WB, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_wb_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_EFFECT:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_EFFECT, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_effect_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_AEMETER:
                mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_AEMETER, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_aemeter_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_SHARPNESS:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_SHARPNESS, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_sharpness_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CONTRAST:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CONTRAST, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_contrast_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_SATURATION:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_SATURATION, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_saturation_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_VDOSCENEMODE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_VIDEOSCENE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_vdoscenemode_cap((mmi_camco_cap_info *)cap_info);
                //break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            case MMI_CAMCO_SETTING_AFMODE:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFMODE, (void*)cap_info);
                ASSERT(((mmi_camco_cap_info*)cap_info)->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);
                return mmi_camco_setting_translate_afmode_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_TIMESTAMP:				
                mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_CAP_OVERLAY, (void*)cap_info);
                return mmi_camco_setting_translate_timestamp_cap((mmi_camco_cap_info *)cap_info);
                //break;

            case MMI_CAMCO_SETTING_CAMEV:
            case MMI_CAMCO_SETTING_VDOEV:
                mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_EV, (void*)cap_info);
                return mmi_camco_setting_translate_ev_cap((mmi_camco_cap_info *)cap_info);
               // break;

            default:
                MMI_CAMCO_ASSERT(0);
                //break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_capbility
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting         [IN]        
 *  setting_ptr     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_get_capbility(mmi_camco_setting_enum setting, mmi_camco_setting_struct *setting_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_sensor_general_info cap_info;
	mdi_camera_sensor_capture_resolution_info capsize_info;
    void* info_p;
    
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (setting == MMI_CAMCO_SETTING_ISO)
    {
        info_p = (void*)&mmi_camco_setting_p->iso_binning;
    }
    else if(setting == MMI_CAMCO_SETTING_CAPSIZE)
    {
         info_p = (void*)&capsize_info;

	}
	else
    {
        info_p = (void*)&cap_info;
    }
    
    if (mmi_camco_setting_query_capbility(setting, info_p))
    {
        if(setting == MMI_CAMCO_SETTING_CAPSIZE)
        {
            setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            for (idx = 0; idx < capsize_info.item_count; idx++)
            {
                if (capsize_info.support_item[idx] != MMI_CAMCO_SETTING_DUMMY_VALUE)
                {
                    setting_ptr->item_cap[capsize_info.support_item[idx]] = MMI_CAMCO_SETTING_CAP_ENABLED;
					if((capsize_info.image_size[idx].image_width != 0 ) && (capsize_info.image_size[idx].image_height != 0))
					{
						cap_dimention[capsize_info.support_item[idx]].image_width = capsize_info.image_size[idx].image_width;
	                    cap_dimention[capsize_info.support_item[idx]].image_height = capsize_info.image_size[idx].image_height;

					}
            	}
            }
		}
		else if(setting != MMI_CAMCO_SETTING_ISO)
        {
            setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            for (idx = 0; idx < cap_info.item_count; idx++)
            {
                if (cap_info.support_item[idx] != MMI_CAMCO_SETTING_DUMMY_VALUE)
                {
                    setting_ptr->item_cap[cap_info.support_item[idx]] = MMI_CAMCO_SETTING_CAP_ENABLED;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_iso_binning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_get_iso_binning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_capsize_enum cap_size;
   // mdi_camera_sensor_iso_binning_info iso_info;
    S32 idx;
    S32 i = 0;
    S32 j = 0;
    U16 mdi_capsize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < MMI_CAMCO_ISO_END; idx++)
    {
        if(mmi_camco_setting_p->iso_binning.IsoBinningInfo[idx].BinningEnable)
        { 
            mmi_camco_setting_p->is_iso_binning[idx] = MMI_TRUE;
        }
        else
        {
            mmi_camco_setting_p->is_iso_binning[idx] = MMI_FALSE; 
        }
    }

    for (i = 0; i < MMI_CAMCO_ISO_END; i++)
        for (j = 0; j < MMI_CAMCO_CAPSIZE_END; j++)
        {
            mmi_camco_isobinning_vs_capsize[i][j] = MMI_TRUE;
        }

    for (i = 0; i < MMI_CAMCO_ISO_END; i++)
    {
        if (mmi_camco_setting_p->is_iso_binning[i])
        {
            mdi_capsize = (U16)mmi_camco_setting_p->iso_binning.IsoBinningInfo[i].MaxResolution;
            cap_size = (mmi_camco_capsize_enum)mmi_camco_setting_p->mdi_vs_mmi_capsize[mdi_capsize];
            for (j = cap_size + 1; j < MMI_CAMCO_CAPSIZE_END; j++)
            {
                mmi_camco_isobinning_vs_capsize[i][j] = MMI_FALSE;
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_is_iso_binning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iso     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_is_iso_binning(U16 iso)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(iso < MMI_CAMCO_ISO_END); 
    return mmi_camco_setting_p->iso_binning.IsoBinningInfo[iso].BinningEnable;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_is_facedetect_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_is_facedetect_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->facedetect.cur_value == MMI_CAMCO_FACEDETECT_ON)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->last_camscenemode = MMI_CAMCO_CAMSCENEMODE_END;
    mmi_camco_setting_p->last_vdoscenemode = MMI_CAMCO_VDOSCENEMODE_END;
    mmi_camco_setting_p->cur_main_setting = MMI_CAMCO_SETTING_CAMSWITCHTO;

    mmi_camco_default_camev_capability();
    mmi_camco_default_vdoev_capability();

    // need to keep the last query zoom the same as active app
    if(mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_default_vdozoom_capability();
        mmi_camco_default_camzoom_capability();            
    }
    else
    {
        mmi_camco_default_camzoom_capability();
        mmi_camco_default_vdozoom_capability();    
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_scene_sel_store_to_nvram
 * DESCRIPTION
 *  Store settings to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_scene_sel_store_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_scene_sel_struct nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_data.cam_auto.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].afrange;
    nvram_data.cam_auto.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].iso;
    nvram_data.cam_auto.flash = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].flash;
    nvram_data.cam_auto.sharpness = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].sharpness;
    nvram_data.cam_auto.contrast = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].contrast;
    nvram_data.cam_auto.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].saturation;

    nvram_data.cam_portrait.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].afrange;
    nvram_data.cam_portrait.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].iso;
    nvram_data.cam_portrait.flash = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].flash;
    nvram_data.cam_portrait.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].sharpness;
    nvram_data.cam_portrait.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].contrast;
    nvram_data.cam_portrait.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].saturation;

    nvram_data.cam_landscape.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].afrange;
    nvram_data.cam_landscape.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].iso;
    nvram_data.cam_landscape.flash= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].flash;
    nvram_data.cam_landscape.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].sharpness;
    nvram_data.cam_landscape.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].contrast;
    nvram_data.cam_landscape.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].saturation;
        
    nvram_data.cam_sport.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].afrange;
    nvram_data.cam_sport.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].iso;
    nvram_data.cam_sport.flash = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].flash;
    nvram_data.cam_sport.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].sharpness;
    nvram_data.cam_sport.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].contrast;
    nvram_data.cam_sport.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].saturation;

    nvram_data.cam_night.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].afrange;
    nvram_data.cam_night.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].iso;
    nvram_data.cam_night.flash = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].flash;
    nvram_data.cam_night.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].sharpness;
    nvram_data.cam_night.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].contrast;
    nvram_data.cam_night.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].saturation;

    nvram_data.cam_document.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].afrange;
    nvram_data.cam_document.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].iso;
    nvram_data.cam_document.flash = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].flash;
    nvram_data.cam_document.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].sharpness;
    nvram_data.cam_document.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].contrast;
    nvram_data.cam_document.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].saturation;

    nvram_data.cam_antishake.afrange = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].afrange;
    nvram_data.cam_antishake.iso = mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].iso;
    nvram_data.cam_antishake.flash= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].flash;
    nvram_data.cam_antishake.sharpness= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].sharpness;
    nvram_data.cam_antishake.contrast= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].contrast;
    nvram_data.cam_antishake.saturation= mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].saturation;
 
    nvram_data.vdo_auto.aemeter = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].aemeter;
    nvram_data.vdo_auto.wb = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].wb;
    nvram_data.vdo_auto.afrange = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].afrange;
    nvram_data.vdo_auto.sharpness = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].sharpness;
    nvram_data.vdo_auto.contrast = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].contrast;
    nvram_data.vdo_auto.saturation= mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].saturation;

    nvram_data.vdo_night.aemeter = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].aemeter;
    nvram_data.vdo_night.wb = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].wb;
    nvram_data.vdo_night.afrange = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].afrange;
    nvram_data.vdo_night.sharpness= mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].sharpness;
    nvram_data.vdo_night.contrast = mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].contrast;
    nvram_data.vdo_night.saturation= mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].saturation;
        
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_scene_sel_load_from_nvram
 * DESCRIPTION
 *  Store settings to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_scene_sel_load_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_scene_sel_struct nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].afrange = nvram_data.cam_auto.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].iso = nvram_data.cam_auto.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].flash = nvram_data.cam_auto.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].sharpness = nvram_data.cam_auto.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].contrast = nvram_data.cam_auto.contrast;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].saturation = nvram_data.cam_auto.saturation;

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].afrange = nvram_data.cam_portrait.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].iso = nvram_data.cam_portrait.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].flash = nvram_data.cam_portrait.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].sharpness = nvram_data.cam_portrait.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].contrast = nvram_data.cam_portrait.contrast;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].saturation = nvram_data.cam_portrait.saturation;

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].afrange = nvram_data.cam_landscape.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].iso = nvram_data.cam_landscape.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].flash = nvram_data.cam_landscape.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].sharpness = nvram_data.cam_landscape.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].contrast = nvram_data.cam_landscape.contrast;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].saturation = nvram_data.cam_landscape.saturation;

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].afrange = nvram_data.cam_sport.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].iso = nvram_data.cam_sport.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].flash = nvram_data.cam_sport.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].sharpness = nvram_data.cam_sport.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].contrast = nvram_data.cam_sport.contrast;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_SPORT].saturation = nvram_data.cam_sport.saturation;

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].afrange = nvram_data.cam_night.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].iso = nvram_data.cam_night.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].flash = nvram_data.cam_night.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].sharpness = nvram_data.cam_night.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].contrast = nvram_data.cam_night.contrast; 
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].saturation = nvram_data.cam_night.saturation;

    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].afrange = nvram_data.cam_document.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].iso = nvram_data.cam_document.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].flash = nvram_data.cam_document.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].sharpness = nvram_data.cam_document.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].contrast = nvram_data.cam_document.contrast; 
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].saturation = nvram_data.cam_document.saturation;
    
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].afrange = nvram_data.cam_antishake.afrange;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].iso = nvram_data.cam_antishake.iso;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].flash = nvram_data.cam_antishake.flash;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].sharpness = nvram_data.cam_antishake.sharpness;
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].contrast = nvram_data.cam_antishake.contrast;  
    mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].saturation = nvram_data.cam_antishake.saturation;    

    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].aemeter = nvram_data.vdo_auto.aemeter;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].wb = nvram_data.vdo_auto.wb;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].afrange = nvram_data.vdo_auto.afrange;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].sharpness = nvram_data.vdo_auto.sharpness;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].contrast = nvram_data.vdo_auto.contrast;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].saturation = nvram_data.vdo_auto.saturation;

    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].aemeter = nvram_data.vdo_night.aemeter;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].wb = nvram_data.vdo_night.wb;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].afrange = nvram_data.vdo_night.afrange;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].sharpness = nvram_data.vdo_night.sharpness;
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].contrast = nvram_data.vdo_night.contrast;    
    mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_NIGHT].saturation = nvram_data.vdo_night.saturation;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_store_to_nvram
 * DESCRIPTION
 *  Store settings to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_store_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_struct nvram_data;
    nvram_ef_camco_app_info_struct nvram_camco_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_camco_info.active_app = mmi_camco_setting_p->active_app;
    nvram_camco_info.active_cam = mmi_camco_setting_p->active_cam;

    WriteRecord(
        NVRAM_EF_CAMCO_APP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_camco_info,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        &error);

    nvram_data.capmode = mmi_camco_setting_p->capmode.cur_value;
    nvram_data.camscenemode = mmi_camco_setting_p->camscenemode.cur_value;
    nvram_data.capsize = mmi_camco_setting_p->capsize.cur_value;
    nvram_data.flash = mmi_camco_setting_p->flash.cur_value;
    //nvram_data.highlight = mmi_camco_setting_p->highlight.cur_value;
    nvram_data.afrange = mmi_camco_setting_p->afrange.cur_value;
    nvram_data.facedetect = mmi_camco_setting_p->facedetect.cur_value;
    nvram_data.selftimer = mmi_camco_setting_p->selftimer.cur_value;
    nvram_data.iso = mmi_camco_setting_p->iso.cur_value;
    nvram_data.wb = mmi_camco_setting_p->wb.cur_value;
    nvram_data.effect = mmi_camco_setting_p->effect.cur_value;
    nvram_data.storage = mmi_camco_setting_p->storage.cur_value;
    nvram_data.capqty = mmi_camco_setting_p->capqty.cur_value;
    nvram_data.afzone = mmi_camco_setting_p->afzone.cur_value;
    nvram_data.aemeter = mmi_camco_setting_p->aemeter.cur_value;
    nvram_data.sharpness = mmi_camco_setting_p->sharpness.cur_value;
    nvram_data.contrast = mmi_camco_setting_p->contrast.cur_value;
    nvram_data.saturation = mmi_camco_setting_p->saturation.cur_value;
    nvram_data.timestamp = mmi_camco_setting_p->timestamp.cur_value;
    nvram_data.shuttersound = mmi_camco_setting_p->shuttersound.cur_value;
    nvram_data.banding = mmi_camco_setting_p->banding.cur_value;
    nvram_data.vdoscenemode = mmi_camco_setting_p->vdoscenemode.cur_value;
    nvram_data.recsize = mmi_camco_setting_p->recsize.cur_value;
    nvram_data.sizelimit = mmi_camco_setting_p->sizelimit.cur_value;
    nvram_data.timelimit = mmi_camco_setting_p->timelimit.cur_value;
    nvram_data.limit = mmi_camco_setting_p->limit.cur_value;
    nvram_data.visqty = mmi_camco_setting_p->visqty.cur_value;
    nvram_data.afmode = mmi_camco_setting_p->afmode.cur_value;
    nvram_data.visqty = mmi_camco_setting_p->visqty.cur_value;
    nvram_data.recaud = mmi_camco_setting_p->recaud.cur_value;
    nvram_data.viscodec = mmi_camco_setting_p->viscodec.cur_value;
    nvram_data.restoredefault = mmi_camco_setting_p->restoredefault.cur_value;
	nvram_data.timelaps = mmi_camco_setting_p->timelaps.cur_value;

    nvram_data.last_active_app = mmi_camco_setting_p->active_app;

    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_load_from_nvram
 * DESCRIPTION
 *  Load settings from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_load_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_struct nvram_data;
    nvram_ef_camco_app_info_struct nvram_camco_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_CAMCO_APP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_camco_info,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        &error);

    mmi_camco_setting_p->active_app = (mmi_camco_setting_app_enum)nvram_camco_info.active_app;
    mmi_camco_setting_p->active_cam = (mmi_camco_setting_cam_enum)nvram_camco_info.active_cam;

    if (mmi_camco_setting_p->active_app == 0xff)
    {
        mmi_camco_setting_p->active_app = MMI_CAMCO_SETTING_APP_CAMERA;
    }

    if (mmi_camco_setting_p->active_cam == 0xff)
    {
        mmi_camco_setting_p->active_cam = MMI_CAMCO_SETTING_CAM_MAIN;
    }

    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }

    mmi_camco_setting_p->capmode.cur_value = nvram_data.capmode;
    mmi_camco_setting_p->camscenemode.cur_value = nvram_data.camscenemode;
    mmi_camco_setting_p->capsize.cur_value = nvram_data.capsize;
    mmi_camco_setting_p->flash.cur_value = nvram_data.flash;
    //mmi_camco_setting_p->highlight.cur_value = nvram_data.highlight;
    mmi_camco_setting_p->afrange.cur_value = nvram_data.afrange;
    mmi_camco_setting_p->facedetect.cur_value = nvram_data.facedetect;
    mmi_camco_setting_p->selftimer.cur_value = nvram_data.selftimer;
    mmi_camco_setting_p->iso.cur_value = nvram_data.iso;
    mmi_camco_setting_p->wb.cur_value = nvram_data.wb;
    mmi_camco_setting_p->effect.cur_value = nvram_data.effect;
    mmi_camco_setting_p->storage.cur_value = nvram_data.storage;
    mmi_camco_setting_p->capqty.cur_value = nvram_data.capqty;
    mmi_camco_setting_p->afzone.cur_value = nvram_data.afzone;
    mmi_camco_setting_p->aemeter.cur_value = nvram_data.aemeter;
    mmi_camco_setting_p->sharpness.cur_value = nvram_data.sharpness;
    mmi_camco_setting_p->contrast.cur_value = nvram_data.contrast;
    mmi_camco_setting_p->saturation.cur_value = nvram_data.saturation;
    mmi_camco_setting_p->timestamp.cur_value = nvram_data.timestamp;
    mmi_camco_setting_p->shuttersound.cur_value = nvram_data.shuttersound;
    mmi_camco_setting_p->banding.cur_value = nvram_data.banding;
    mmi_camco_setting_p->vdoscenemode.cur_value = nvram_data.vdoscenemode;
    mmi_camco_setting_p->recsize.cur_value = nvram_data.recsize;
    mmi_camco_setting_p->sizelimit.cur_value = nvram_data.sizelimit;
    mmi_camco_setting_p->timelimit.cur_value = nvram_data.timelimit;
    mmi_camco_setting_p->limit.cur_value = nvram_data.limit;
    mmi_camco_setting_p->visqty.cur_value = nvram_data.visqty;
    mmi_camco_setting_p->afmode.cur_value = nvram_data.afmode;
    mmi_camco_setting_p->visqty.cur_value = nvram_data.visqty;
    mmi_camco_setting_p->recaud.cur_value = nvram_data.recaud;
    mmi_camco_setting_p->viscodec.cur_value = nvram_data.viscodec;
    mmi_camco_setting_p->restoredefault.cur_value = nvram_data.restoredefault;
	mmi_camco_setting_p->timelaps.cur_value = nvram_data.timelaps;

    mmi_camco_setting_p->last_active_app = (mmi_camco_setting_app_enum)nvram_data.last_active_app;

    if (mmi_camco_setting_p->last_active_app == 0xff)
    {
        mmi_camco_setting_p->last_active_app = MMI_CAMCO_SETTING_APP_CAMERA;
    }

    /* save to NVRAM */
    mmi_camco_setting_store_to_nvram();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_store_default_to_nvram
 * DESCRIPTION
 *  Store settings to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_store_default_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_struct nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_data.capmode = mmi_camco_setting_p->capmode.cur_value;
    nvram_data.camscenemode = mmi_camco_setting_p->camscenemode.cur_value;
    nvram_data.capsize = mmi_camco_setting_p->capsize.cur_value;
    nvram_data.flash = mmi_camco_setting_p->flash.cur_value;
    //nvram_data.highlight = mmi_camco_setting_p->highlight.cur_value;
    nvram_data.afrange = mmi_camco_setting_p->afrange.cur_value;
    nvram_data.facedetect = mmi_camco_setting_p->facedetect.cur_value;
    nvram_data.selftimer = mmi_camco_setting_p->selftimer.cur_value;
    nvram_data.iso = mmi_camco_setting_p->iso.cur_value;
    nvram_data.wb = mmi_camco_setting_p->wb.cur_value;
    nvram_data.effect = mmi_camco_setting_p->effect.cur_value;
    nvram_data.storage = mmi_camco_setting_p->storage.cur_value;
    nvram_data.capqty = mmi_camco_setting_p->capqty.cur_value;
    nvram_data.afzone = mmi_camco_setting_p->afzone.cur_value;
    nvram_data.aemeter = mmi_camco_setting_p->aemeter.cur_value;
    nvram_data.sharpness = mmi_camco_setting_p->sharpness.cur_value;
    nvram_data.contrast = mmi_camco_setting_p->contrast.cur_value;
    nvram_data.saturation = mmi_camco_setting_p->saturation.cur_value;
    nvram_data.timestamp = mmi_camco_setting_p->timestamp.cur_value;
    nvram_data.shuttersound = mmi_camco_setting_p->shuttersound.cur_value;
    nvram_data.banding = mmi_camco_setting_p->banding.cur_value;
    nvram_data.vdoscenemode = mmi_camco_setting_p->vdoscenemode.cur_value;
    nvram_data.recsize = mmi_camco_setting_p->recsize.cur_value;
    nvram_data.sizelimit = mmi_camco_setting_p->sizelimit.cur_value;
    nvram_data.timelimit = mmi_camco_setting_p->timelimit.cur_value;
    nvram_data.limit = mmi_camco_setting_p->limit.cur_value;
    nvram_data.visqty = mmi_camco_setting_p->visqty.cur_value;
    nvram_data.afmode = mmi_camco_setting_p->afmode.cur_value;
    nvram_data.visqty = mmi_camco_setting_p->visqty.cur_value;
    nvram_data.recaud = mmi_camco_setting_p->recaud.cur_value;
    nvram_data.viscodec = mmi_camco_setting_p->viscodec.cur_value;
    nvram_data.restoredefault = mmi_camco_setting_p->restoredefault.cur_value;
	nvram_data.timelaps = mmi_camco_setting_p->timelaps.cur_value;

    WriteRecord(
        NVRAM_EF_CAMCO_MAIN_SETTING_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_data,
        NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
        &error);

#ifdef DUAL_CAMERA_SUPPORT
    WriteRecord(
        NVRAM_EF_CAMCO_SUB_SETTING_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_data,
        NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
        &error);
#endif /* DUAL_CAMERA_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_restore_hilite_mod
 * DESCRIPTION
 *  Restore modified setting value after we move hilite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_restore_hilite_mod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retore hilite modify setting to stored value */
    mmi_camco_iso_hilite_restore_hdlr();
    mmi_camco_wb_hilite_restore_hdlr();
    mmi_camco_effect_hilite_restore_hdlr();
    mmi_camco_sharpness_hilite_restore_hdlr();
    mmi_camco_contrast_hilite_restore_hdlr();
    mmi_camco_saturation_hilite_restore_hdlr();
    mmi_camco_highlight_hilite_restore_hdlr();
    mmi_camco_camev_hilite_restore_hdlr();
    mmi_camco_vdoev_hilite_restore_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_misc_selected_hdlr
 * DESCRIPTION
 *  Misc selected handler, we launch SENCODARY mainlist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_misc_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gen misc bar and draw it */
    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SECONDARY);
    mmi_camco_setting_set_mainlist_idx(0);

    mmi_camco_osd_gen_iconlist();
    mmi_camco_osd_gen_setting_menulist();

    mmi_camco_osd_draw_osd();
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
#if (defined(DUAL_CAMERA_SUPPORT) && !defined(__MMI_CAMCO_FTE__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* DUAL_CAMERA_SUPPORT */ 
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_camswitchto_capability
 * DESCRIPTION
 *  default camswitchto capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_camswitchto_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.camswitchto_p = &mmi_camco_setting_p->camswitchto;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
#ifdef __MMI_IMAGE_VIEWER__
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] = MMI_CAMCO_SETTING_CAP_ENABLED;
#else 
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER] = MMI_CAMCO_SETTING_CAP_ENABLED;

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = MMI_CAMCO_SETTING_CAP_ENABLED;
#else 
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#if (defined(DUAL_CAMERA_SUPPORT) && !defined(__MMI_CAMCO_FTE__))
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#else /* DUAL_CAMERA_SUPPORT */ 
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif /* DUAL_CAMERA_SUPPORT */ 
    /* default value */
    setting_ptr->cur_value = MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_camswitchto
 * DESCRIPTION
 *  Initialized camswitchto settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_camswitchto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->camswitchto, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.camswitchto_p = &mmi_camco_setting_p->camswitchto;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SWITCH_TO_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SWITCH_TO;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SWITCH_TO;
    setting_ptr->is_show_radio = MMI_FALSE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] = STR_ID_CAMCO_TO_ALBUMN;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER] = STR_ID_CAMCO_TO_VDOREC;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = STR_ID_CAMCO_TO_SUBLCD;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = STR_ID_CAMCO_TO_MAIN_CAM;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = STR_ID_CAMCO_TO_SUB_CAM;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_external_camswitchto_capability
 * DESCRIPTION
 *  default external camswitchto capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_external_camswitchto_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.camswitchto_p = &mmi_camco_setting_p->camswitchto;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER] = MMI_CAMCO_SETTING_CAP_DISABLED;

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = MMI_CAMCO_SETTING_CAP_ENABLED;
#else 
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#if (defined(DUAL_CAMERA_SUPPORT) && !defined(__MMI_CAMCO_FTE__))
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        /* default value */
        setting_ptr->cur_value = MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        /* default value */
        setting_ptr->cur_value = MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA;
    }
#else /* DUAL_CAMERA_SUPPORT */ 
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif /* DUAL_CAMERA_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_capmode_capability
 * DESCRIPTION
 *  default capmode capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_capmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.capmode_p = &mmi_camco_setting_p->capmode;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CAPMODE, setting_ptr);
#ifndef __MMI_CAMCO_FEATURE_CAM_BESTSHOT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BEST_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BURST_SHOT_SEL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_EV_BRACKET_SEL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_HDR_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ZSD_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 
#ifndef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_MAV] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 
#ifndef __MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_3D_IMAGE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ASD_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif
#ifndef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ADD_FRAME] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#ifndef __SMILE_SHUTTER_SUPPORT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 

#if defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 

#if defined( __MMI_CAMCO_FEATURE_CAM_MAV_MODE__)
    if (!mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_MAV] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_MAV] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 
#if defined( __MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
    if (!mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_3D_IMAGE] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_3D_IMAGE] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 

#ifdef __SMILE_SHUTTER_SUPPORT__
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* __SMILE_SHUTTER_SUPPORT__ */ 
#if defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_ASD_SHOT__)
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ASD_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ASD_SHOT] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 
    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_CAPMODE_NORMAL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_capmode
 * DESCRIPTION
 *  Initialized capmode settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_capmode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->capmode, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.capmode_p = &mmi_camco_setting_p->capmode;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_NORMAL] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BEST_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_CONT_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BURST_SHOT_SEL] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_EV_BRACKET_SEL] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_HDR_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;    
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ADD_FRAME] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ZSD_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_MAV] = MMI_CAMCO_SETTING_CAP_ENABLED;
	setting_ptr->item_cap[MMI_CAMCO_CAPMODE_3D_IMAGE] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ASD_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;

    /* init main str/img id */
#ifdef __MMI_CAMCORDER_SLIM__
    setting_ptr->main_img_id = IMG_ID_CAMCO_CAPMODE_SEL;
#else
    setting_ptr->main_img_id = IMG_ID_CAMCO_CAPMODE;
#endif
    setting_ptr->main_str_id = STR_ID_CAMCO_CAPMODE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_NORMAL] = STR_ID_CAMCO_CAPMODE_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_BEST_SHOT] = STR_ID_CAMCO_CAPMODE_BEST_SHOT;
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_CONT_SHOT] = STR_ID_CAMCO_CAPMODE_CONT_SHOT;
#ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_BURST_SHOT_SEL] = STR_ID_CAMCO_CAPMODE_BURST_SHOT_SEL;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_EV_BRACKET_SEL] = STR_ID_CAMCO_CAPMODE_EV_BRACKET_SEL;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_AUTORAMA] = STR_ID_CAMCO_CAPMODE_AUTORAMA;
#endif 
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_ADD_FRAME] = STR_ID_CAMCO_CAPMODE_ADD_FRAME;
#endif 
#ifdef __SMILE_SHUTTER_SUPPORT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_SMILE_SHOT] = STR_ID_CAMCO_CAPMODE_SMILE_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_HDR_SHOT] = STR_ID_CAMCO_CAPMODE_HDR_SHOT;
#endif 

#ifdef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_ZSD_SHOT] = STR_ID_CAMCO_CAPMODE_ZSD_SHOT;
#endif 

#ifdef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_MAV] = STR_ID_CAMCO_CAPMODE_MAV;
#endif 

#ifdef __MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__
setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_3D_IMAGE] = STR_ID_CAMCO_CAPMODE_3D_IMAGE;
#endif 

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    setting_ptr->item_str_id[MMI_CAMCO_CAPMODE_ASD_SHOT] = STR_ID_CAMCO_CAPMODE_ASD_SHOT;
#endif 
    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_NORMAL] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_BEST_SHOT] = IMG_ID_CAMCO_CAPMODE_BEST_SHOT;
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_CONT_SHOT] = IMG_ID_CAMCO_CAPMODE_CONT_SHOT;
#ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_BURST_SHOT_SEL] = IMG_ID_CAMCO_CAPMODE_BURST_SHOT_SEL;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_EV_BRACKET_SEL] = IMG_ID_CAMCO_CAPMODE_EV_BRACKET_SEL;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_AUTORAMA] = IMG_ID_CAMCO_CAPMODE_AUTORAMA_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_ADD_FRAME] = IMG_ID_CAMCO_CAPMODE_ADD_FRAME;
#endif 
#ifdef __SMILE_SHUTTER_SUPPORT__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_SMILE_SHOT] = IMG_ID_CAMCO_CAPMODE_SMILE_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
    setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_HDR_SHOT] = IMG_ID_CAMCO_CAPMODE_HDR_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
        setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_ASD_SHOT] = IMG_ID_CAMCO_CAPMODE_ASD_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
        setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_ZSD_SHOT] = IMG_ID_CAMCO_CAPMODE_ZSD_SHOT;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
	setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_MAV] = IMG_ID_CAMCO_CAPMODE_MAV;
#endif 
#ifdef __MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__
		setting_ptr->item_img_id[MMI_CAMCO_CAPMODE_3D_IMAGE] = IMG_ID_CAMCO_CAPMODE_3D_IMAGE;
#endif 

    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_NORMAL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BEST_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_CONT_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_BURST_SHOT_SEL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_EV_BRACKET_SEL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#ifdef __SMILE_SHUTTER_SUPPORT__
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_HDR_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ADD_FRAME] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ASD_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ZSD_SHOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
	setting_ptr->item_cap[MMI_CAMCO_CAPMODE_MAV] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
	setting_ptr->item_cap[MMI_CAMCO_CAPMODE_3D_IMAGE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_capmode_capability
 * DESCRIPTION
 *  Update capmode capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_capmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->capmode;

#if defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 

#ifdef __SMILE_SHUTTER_SUPPORT__
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#if defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    if (mmi_camco_setting_p->capmode.cur_value != MMI_CAMCO_CAPMODE_SMILE_SHOT && mmi_camco_setting_p->capmode.cur_value != MMI_CAMCO_CAPMODE_ASD_SHOT
        && mmi_camco_setting_p->camera.facedetect_p->cur_value == MMI_CAMCO_FACEDETECT_ON)
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_DISABLED;
#endif /* defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 
#endif /* __SMILE_SHUTTER_SUPPORT__ */ 

    if (mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_ADD_FRAME)
    {
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        mmi_camco_osd_set_add_frame_enable(MMI_TRUE);
    #endif 
    }
    else if (mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_CONT_SHOT ||
#ifdef __SMILE_SHUTTER_SUPPORT__
             mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_SMILE_SHOT ||
#endif 
             mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_AUTORAMA)
    {
        mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_SELFTIMER);

        if (mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_AUTORAMA)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_FACEDETECT);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_makeup_facedetect_mainlist_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_makeup_facedetect_mainlist_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL is_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_mainlist_setting() == MMI_CAMCO_SETTING_FACEDETECT)
    {
        mmi_camco_setting_gen_camera_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);

        for (i = 0; i < mmi_camco_setting_p->primary_main_count; i++)
        {
            if (mmi_camco_setting_p->mainlist[i] == MMI_CAMCO_SETTING_FACEDETECT)
            {
                is_found = MMI_TRUE;
                break;
            }
        }

        if (is_found)
        {
            mmi_camco_osd_set_iconlist_highlight_idx(i);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_makeup_capture_mode_mainlist_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_makeup_capture_mode_mainlist_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL is_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_mainlist_setting() == MMI_CAMCO_SETTING_CAPMODE)
    {
        mmi_camco_setting_gen_camera_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);

        for (i = 0; i < mmi_camco_setting_p->primary_main_count; i++)
        {
            if (mmi_camco_setting_p->mainlist[i] == MMI_CAMCO_SETTING_CAPMODE)
            {
                is_found = MMI_TRUE;
                break;
            }
        }

        if (is_found)
        {
            mmi_camco_osd_set_iconlist_highlight_idx(i);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_external_capmode_capability
 * DESCRIPTION
 *  set external capmode capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_external_capmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    S16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.capmode_p = &mmi_camco_setting_p->capmode;

    /* set limit capability */
    for (idx = MMI_CAMCO_CAPMODE_NORMAL; idx < MMI_CAMCO_CAPMODE_END; idx++)
    {
        if (setting_ptr->item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if (idx == MMI_CAMCO_CAPMODE_NORMAL || idx == MMI_CAMCO_CAPMODE_ADD_FRAME)
            {
                setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }
            else
            {
                setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
        }
    }

    if (mmi_camco_setting_p->camera.facedetect_p->cur_value == MMI_CAMCO_FACEDETECT_ON)
    {
      if(setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ADD_FRAME] == MMI_CAMCO_SETTING_CAP_ENABLED)
       {
        setting_ptr->item_cap[MMI_CAMCO_CAPMODE_ADD_FRAME] = MMI_CAMCO_SETTING_CAP_DISABLED;
       }
        mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_CAPMODE);
    }
    else
    {
        mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_CAPMODE);
    }
    mmi_camco_makeup_facedetect_mainlist_index();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_last_capmode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  capmode
 * RETURNS
 *  
 *****************************************************************************/
void mmi_camco_set_last_capmode(mmi_camco_capmode_enum capmode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->last_capmode = capmode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_get_last_capmode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_camco_capmode_enum mmi_camco_get_last_capmode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->last_capmode;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_last_FD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  last_FD     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_last_FD(mmi_camco_setting_face_detect_enum last_FD)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->last_FD = last_FD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_get_last_FD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_camco_setting_face_detect_enum mmi_camco_get_last_FD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->last_FD;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_camscenemode_capability
 * DESCRIPTION
 *  default canscebenide capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_camscenemode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.camscenemode_p = &mmi_camco_setting_p->camscenemode;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CAMSCENEMODE, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAMSCENEMODE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAMSCENEMODE));        
    }
    
    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_CAMSCENEMODE_AUTO;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_camscenemode
 * DESCRIPTION
 *  Initialized camscenemode settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_camscenemode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->camscenemode, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.camscenemode_p = &mmi_camco_setting_p->camscenemode;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SCENEMODE_SEL;
    #else    
        setting_ptr->main_img_id = IMG_ID_CAMCO_SCENEMODE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SCENEMODE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;
    
    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_AUTO] = STR_ID_CAMCO_SCENEMODE_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_PORTRAIT] = STR_ID_CAMCO_SCENEMODE_PORTRAIT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE] = STR_ID_CAMCO_SCENEMODE_LANDSCAPE;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_NIGHT] = STR_ID_CAMCO_SCENEMODE_NIGHT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_SPORT] = STR_ID_CAMCO_SCENEMODE_SPORT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_DOCUMENT] = STR_ID_CAMCO_SCENEMODE_DOCUMENT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = STR_ID_CAMCO_SCENEMODE_ANTI_SHAKE;
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT] = STR_ID_CAMCO_SCENEMODE_BACKLIGHT_PORTRAIT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT] = STR_ID_CAMCO_SCENEMODE_NIGHT_PORTRAIT;
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT] = STR_ID_CAMCO_SCENEMODE_BACKLIGHT;
#endif
    setting_ptr->item_str_id[MMI_CAMCO_CAMSCENEMODE_FLOWER] = STR_ID_CAMCO_SCENEMODE_FLOWER;
    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_PORTRAIT] = IMG_ID_CAMCO_SCENEMODE_PORTRAIT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE] = IMG_ID_CAMCO_SCENEMODE_LANDSCAPE;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_NIGHT] = IMG_ID_CAMCO_SCENEMODE_NIGHT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_SPORT] = IMG_ID_CAMCO_SCENEMODE_SPORT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_DOCUMENT] = IMG_ID_CAMCO_SCENEMODE_DOCUMENT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = IMG_ID_CAMCO_SCENEMODE_ANTI_SHAKE;

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT] = IMG_ID_CAMCO_SCENEMODE_BACKLIGHT_PORTRAIT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT] = IMG_ID_CAMCO_SCENEMODE_NIGHT_PORTRAIT;
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT] = IMG_ID_CAMCO_SCENEMODE_BACKLIGHT;
#endif
    setting_ptr->item_img_id[MMI_CAMCO_CAMSCENEMODE_FLOWER] = IMG_ID_CAMCO_SCENEMODE_FLOWER;
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_PORTRAIT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_NIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_SPORT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_DOCUMENT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_FLOWER] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_camscenemode_capability
 * DESCRIPTION
 *  Update camscenemode capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_camscenemode_capability(void)
{
#ifdef __FACE_DETECTION_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *camscenemode_setting_ptr;
    mmi_camco_setting_struct *facedetect_setting_ptr;
    U16 capmode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camscenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
    facedetect_setting_ptr = mmi_camco_setting_p->camera.facedetect_p;
    capmode = mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE);
    
    camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    
    if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON && capmode != MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE] = MMI_CAMCO_SETTING_CAP_DISABLED;
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_NIGHT] = MMI_CAMCO_SETTING_CAP_DISABLED;
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_SPORT] = MMI_CAMCO_SETTING_CAP_DISABLED;
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_DOCUMENT] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
    else if(capmode == MMI_CAMCO_CAPMODE_ASD_SHOT )
    {
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT] = MMI_CAMCO_SETTING_CAP_ENABLED;
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_BACKLIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_ENABLED;
        camscenemode_setting_ptr->item_cap[MMI_CAMCO_CAMSCENEMODE_NIGHT_PORTRAIT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        /* get capability */
        mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CAMSCENEMODE, camscenemode_setting_ptr);
    }
#endif /* __FACE_DETECTION_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_capsize_capability
 * DESCRIPTION
 *  default capsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_capsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    S16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.capsize_p = &mmi_camco_setting_p->capsize;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CAPSIZE, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAPSIZE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAPSIZE));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        for (idx = MMI_CAMCO_CAPSIZE_END - 1; idx >= 0; idx--)
        {
            if (setting_ptr->item_cap[idx] == MMI_CAMCO_SETTING_CAP_ENABLED)
            {
                setting_ptr->cur_value = idx;
                break;
            }
        }

        if (setting_ptr->cur_value == 0xff)
        {
            MMI_ASSERT(0);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_capsize
 * DESCRIPTION
 *  Initialized capsize settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_capsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->capsize, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.capsize_p = &mmi_camco_setting_p->capsize;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_CAPSIZE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_CAPSIZE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_CAPSIZE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_WALLPAPER] = STR_ID_CAMCO_CAPSIZE_WALLPAPER;
#if defined(HORIZONTAL_CAMERA)
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_HLCD] = STR_ID_CAMCO_CAPSIZE_HLCD;
#endif 
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_VGA] = STR_ID_CAMCO_CAPSIZE_VGA;
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_1MP] = STR_ID_CAMCO_CAPSIZE_1MP;
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_2MP] = STR_ID_CAMCO_CAPSIZE_2MP;
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_3MP] = STR_ID_CAMCO_CAPSIZE_3MP;
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_4MP] = STR_ID_CAMCO_CAPSIZE_4MP;
    setting_ptr->item_str_id[MMI_CAMCO_CAPSIZE_5MP] = STR_ID_CAMCO_CAPSIZE_5MP;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_WALLPAPER] = IMG_ID_CAMCO_CAPSIZE_WALLPAPER;
#if defined(HORIZONTAL_CAMERA)
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_HLCD] = IMG_ID_CAMCO_CAPSIZE_HLCD;
#endif 
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_VGA] = IMG_ID_CAMCO_CAPSIZE_VGA;
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_1MP] = IMG_ID_CAMCO_CAPSIZE_1MP;
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_2MP] = IMG_ID_CAMCO_CAPSIZE_2MP;
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_3MP] = IMG_ID_CAMCO_CAPSIZE_3MP;
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_4MP] = IMG_ID_CAMCO_CAPSIZE_4MP;
    setting_ptr->item_img_id[MMI_CAMCO_CAPSIZE_5MP] = IMG_ID_CAMCO_CAPSIZE_5MP;

    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
#if defined(HORIZONTAL_CAMERA)
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_HLCD] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_HLCD] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }
#endif /* defined(HORIZONTAL_CAMERA) */ 
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_VGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_1MP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_2MP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_3MP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_4MP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CAPSIZE_5MP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_capsize_capability
 * DESCRIPTION
 *  Update capsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_capsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_config_capsize_capability();
}

#if defined( __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__)

/*****************************************************************************
 * FUNCTION
 *	mmi_camco_setting_update_zsd_capsize_capbility
 * DESCRIPTION
 *
 * PARAMETERS
 *		[IN]
 *		[OUT]
 * RETURNS
 *	void
 *****************************************************************************/
extern void mmi_camco_setting_config_zsd_capsize_capbility()
{
	mdi_camera_sensor_general_info cap_info;
	S32 idx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	mdi_camera_query_support_info(MDI_CAMERA_SETTING_ZSD_CAPSIZE, &cap_info);
	mmi_camco_setting_translate_capsize_cap(&cap_info);

	mmi_camco_setting_p->capsize.cap = MMI_CAMCO_SETTING_CAP_ENABLED;
	for(idx = 0; idx < MMI_CAMCO_MAX_SETTING_ITEM_COUNT; idx++)
	{
		if(mmi_camco_setting_p->capsize.item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
	        mmi_camco_setting_p->capsize.item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;

	}

	for (idx = 0; idx < cap_info.item_count; idx++)
	{
		if (cap_info.support_item[idx] != MMI_CAMCO_SETTING_DUMMY_VALUE)
		{
			mmi_camco_setting_p->capsize.item_cap[cap_info.support_item[idx]] = MMI_CAMCO_SETTING_CAP_ENABLED;
		}
	}
#if defined(HORIZONTAL_CAMERA)
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_setting_p->capsize.item_cap[MMI_CAMCO_CAPSIZE_HLCD] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
#endif /* defined(HORIZONTAL_CAMERA) */
	if(mmi_camco_setting_p->capsize.item_cap[mmi_camco_setting_p->capsize.cur_value] == MMI_CAMCO_SETTING_CAP_DISABLED)
	{
		mmi_camco_setting_p->capsize.cur_value = MMI_CAMCO_CAPSIZE_1MP;
		mmi_camco_update_capsize();
	}

}

#endif
#ifdef __FACE_DETECTION_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_config_capsize_capability
 * DESCRIPTION
 *  change capsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_config_capsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    mmi_camco_setting_struct *capmode_setting_ptr;
    mmi_camco_setting_struct *capsize_setting_ptr;
    mmi_camco_setting_struct *facedetect_setting_ptr;
    MMI_BOOL is_capsize_support;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capmode_setting_ptr = &mmi_camco_setting_p->capmode;
    capsize_setting_ptr = &mmi_camco_setting_p->capsize;
    facedetect_setting_ptr = &mmi_camco_setting_p->facedetect;

    for (idx = 0; idx < MMI_CAMCO_CAPSIZE_END; idx++)
    {
        if (capsize_setting_ptr->item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if (!mmi_camco_setting_is_iso_binning(mmi_camco_setting_p->iso.cur_value))
            {
                is_capsize_support =(MMI_BOOL)
                    (mmi_camco_capmode_vs_capsize[capmode_setting_ptr->cur_value][idx] &
                     mmi_camco_facedetect_vs_capsize[facedetect_setting_ptr->cur_value][idx]);
            }

            else
            {
                is_capsize_support =(MMI_BOOL)
                    (mmi_camco_capmode_vs_capsize[capmode_setting_ptr->cur_value][idx] &
                     mmi_camco_isobinning_vs_capsize[mmi_camco_setting_p->iso.cur_value][idx] &
                     mmi_camco_facedetect_vs_capsize[facedetect_setting_ptr->cur_value][idx]);
            }

            if (is_capsize_support)
            {
                capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }
            else
            {
                capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
        }
    }
	#if defined( __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__)
	if(capmode_setting_ptr->cur_value == MMI_CAMCO_CAPMODE_ZSD_SHOT)
	{
		mmi_camco_setting_config_zsd_capsize_capbility();
	}
	#endif
}
#else /* __FACE_DETECTION_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_config_capsize_capability
 * DESCRIPTION
 *  change capsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_config_capsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    mmi_camco_setting_struct *capmode_setting_ptr;
    mmi_camco_setting_struct *capsize_setting_ptr;
    MMI_BOOL is_capsize_support;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capmode_setting_ptr = &mmi_camco_setting_p->capmode;
    capsize_setting_ptr = &mmi_camco_setting_p->capsize;

    for (idx = 0; idx < MMI_CAMCO_CAPSIZE_END; idx++)
    {
        if (capsize_setting_ptr->item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if (!mmi_camco_setting_is_iso_binning(mmi_camco_setting_p->iso.cur_value))
            {
                if (mmi_camco_capmode_vs_capsize[capmode_setting_ptr->cur_value][idx])
                {
                    capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_ENABLED;
                }
                else
                {
                    capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;
                }
            }
            else
            {
                is_capsize_support =
                    (mmi_camco_capmode_vs_capsize[capmode_setting_ptr->cur_value][idx] &
                     mmi_camco_isobinning_vs_capsize[mmi_camco_setting_p->iso.cur_value][idx]);

                if (is_capsize_support)
                {
                    capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_ENABLED;
                }
                else
                {
                    capsize_setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;
                }
            }
        }
    }

	#if defined( __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__)
	if(capmode_setting_ptr->cur_value == MMI_CAMCO_CAPMODE_ZSD_SHOT)
	{
		mmi_camco_setting_config_zsd_capsize_capbility();
	}
	#endif
}
#endif /* __FACE_DETECTION_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_get_flash_type
 * DESCRIPTION
 *  get flash type
 * PARAMETERS
 *  void
 * RETURNS
 *  flash type
 *****************************************************************************/
mmi_camco_setting_flash_type_enum mmi_camco_get_flash_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camera.flash_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_flash_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_flash_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->flash.cap == MMI_CAMCO_SETTING_CAP_ENABLED)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_imageviewer_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_imageviewer_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_camco_setting_p->camswitchto.item_cap[MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN] == MMI_CAMCO_SETTING_CAP_ENABLED) && 
            (mmi_camco_setting_p->camswitchto.cap == MMI_CAMCO_SETTING_CAP_ENABLED))
        return MMI_TRUE;
    else
		return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdoplayer_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdoplayer_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_camco_setting_p->vdoswitchto.item_cap[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] == MMI_CAMCO_SETTING_CAP_ENABLED) && 
            (mmi_camco_setting_p->vdoswitchto.cap == MMI_CAMCO_SETTING_CAP_ENABLED))
        return MMI_TRUE;
	else
		return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_app_switch_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_app_switch_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	flag = 0;
    if(mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
       flag = (mmi_camco_setting_p->camswitchto.item_cap[MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER] == MMI_CAMCO_SETTING_CAP_ENABLED) && 
                (mmi_camco_setting_p->camswitchto.cap == MMI_CAMCO_SETTING_CAP_ENABLED);
    }
    else
    {
        flag = (mmi_camco_setting_p->vdoswitchto.item_cap[MMI_CAMCO_VDOSWITCHTO_CAMERA] == MMI_CAMCO_SETTING_CAP_ENABLED) && 
                (mmi_camco_setting_p->vdoswitchto.cap == MMI_CAMCO_SETTING_CAP_ENABLED);
    
    }
	if(flag)
		return MMI_TRUE;
	else
		return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_selftime_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_selftime_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->selftimer.cap == MMI_CAMCO_SETTING_CAP_ENABLED)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_flash_capability
 * DESCRIPTION
 *  default flash capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_flash_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.flash_p = &mmi_camco_setting_p->flash;

    /* get capability */
#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
    mmi_camco_setting_p->camera.flash_type = MMI_CAMCO_FLASH_TYPE_XENON;
#elif defined(LED_FLASHLIGHT_SUPPORT)
    mmi_camco_setting_p->camera.flash_type = MMI_CAMCO_FLASH_TYPE_LED;
#else 
    mmi_camco_setting_p->camera.flash_type = MMI_CAMCO_FLASH_TYPE_NONE;
#endif 

    if (mmi_camco_setting_p->camera.flash_type != MMI_CAMCO_FLASH_TYPE_NONE)
    {
        mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_FLASH, setting_ptr);

        if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_FLASH)))
        {
            setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
            mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_FLASH));        
        }

    }
    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_FLASH_AUTO;

        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].flash = MMI_CAMCO_FLASH_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].flash = MMI_CAMCO_FLASH_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].flash = MMI_CAMCO_FLASH_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].flash = MMI_CAMCO_FLASH_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].flash = MMI_CAMCO_FLASH_AUTO;

    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].flash = MMI_CAMCO_FLASH_OFF;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].flash = MMI_CAMCO_FLASH_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_flash
 * DESCRIPTION
 *  Initialized flash settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->flash, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.flash_p = &mmi_camco_setting_p->flash;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_FLASH_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_FLASH;
    #endif
    
    setting_ptr->main_str_id = STR_ID_CAMCO_FLASH;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_FLASH_AUTO] = STR_ID_CAMCO_FLASH_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_FLASH_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_FLASH_FORCE_ON] = STR_ID_CAMCO_FLASH_FORCE_ON;
    setting_ptr->item_str_id[MMI_CAMCO_FLASH_RED_EYE] = STR_ID_CAMCO_FLASH_RED_EYE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_FLASH_AUTO] = IMG_ID_CAMCO_FLASH_AUTO;
    setting_ptr->item_img_id[MMI_CAMCO_FLASH_OFF] = IMG_ID_CAMCO_FLASH_OFF;
    setting_ptr->item_img_id[MMI_CAMCO_FLASH_FORCE_ON] = IMG_ID_CAMCO_FLASH_FORCE_ON;
    setting_ptr->item_img_id[MMI_CAMCO_FLASH_RED_EYE] = IMG_ID_CAMCO_FLASH_RED_EYE;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FLASH_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FLASH_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FLASH_FORCE_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FLASH_RED_EYE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_flash_capability
 * DESCRIPTION
 *  Update flash capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_flash_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *flash_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->camera.flash_p->cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        flash_setting_ptr = mmi_camco_setting_p->camera.flash_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        mmi_camco_setting_set_default_capability(MMI_CAMCO_SETTING_FLASH);

        /* store the original setting */
        if (last_scenemode != MMI_CAMCO_CAMSCENEMODE_END &&
            last_scenemode != MMI_CAMCO_CAMSCENEMODE_LANDSCAPE && last_scenemode != MMI_CAMCO_CAMSCENEMODE_SPORT)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].flash =
                flash_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].flash =
                flash_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_NIGHT].flash =
                flash_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].flash =
                flash_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].flash =
                flash_setting_ptr->cur_value;
        }

        if (current_scenemode == MMI_CAMCO_CAMSCENEMODE_LANDSCAPE || current_scenemode == MMI_CAMCO_CAMSCENEMODE_SPORT)
        {
            /* apply the scenemode setting */
            flash_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].flash;
            flash_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }
        else
        {
            /* recover the original setting */
            if (last_scenemode != MMI_CAMCO_CAMSCENEMODE_END)
            {
                flash_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
                flash_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].flash;
            }
        }

        mmi_camco_check_flash_capmode_capability();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_check_flash_capmode_capability
 * DESCRIPTION
 *  Check flash capability for capmode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_check_flash_capmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_NORMAL &&
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_ADD_FRAME
        )
    {
        /* Multi-shot */
        if (mmi_camco_setting_p->camera.flash_type == MMI_CAMCO_FLASH_TYPE_XENON)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_FLASH);
        }
        else if (mmi_camco_setting_p->camera.flash_type == MMI_CAMCO_FLASH_TYPE_LED)
        {
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_EV_BRACKET_SEL || 
            #ifdef __SMILE_SHUTTER_SUPPORT__
                mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_SMILE_SHOT ||
            #endif 
                mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_HDR_SHOT||            
                mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_AUTORAMA)
            {
                mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_FLASH);
            }
            else
            {
                mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_FLASH);
                if (mmi_camco_setting_p->camera.flash_p->cur_value == MMI_CAMCO_FLASH_RED_EYE)
                {
                    mmi_camco_setting_p->camera.flash_p->cur_value = MMI_CAMCO_FLASH_AUTO;
                }
                mmi_camco_setting_set_boundary_capability(
                    MMI_CAMCO_SETTING_FLASH,
                    MMI_CAMCO_FLASH_FORCE_ON,
                    MMI_CAMCO_FLASH_AUTO);
            }
        }
    }
    else
    {
        /* Single shot */
        if (mmi_camco_setting_p->camera.camscenemode_p->cur_value != MMI_CAMCO_CAMSCENEMODE_LANDSCAPE &&
            mmi_camco_setting_p->camera.camscenemode_p->cur_value != MMI_CAMCO_CAMSCENEMODE_SPORT)
        {
            mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_FLASH);
        }

        if (mmi_camco_setting_p->camera.flash_type == MMI_CAMCO_FLASH_TYPE_LED)
        {
            mmi_camco_setting_set_boundary_capability(
                MMI_CAMCO_SETTING_FLASH,
                MMI_CAMCO_FLASH_RED_EYE,
                MMI_CAMCO_FLASH_AUTO);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_highlight_capability
 * DESCRIPTION
 *  default highlight capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_highlight_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.highlight_p = &mmi_camco_setting_p->highlight;

    /* init capability */
#ifdef LED_ONOFF_SUPPORT
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_HIGHLIGHT_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_HIGHLIGHT_ON] = MMI_CAMCO_SETTING_CAP_ENABLED;
#else /* LED_ONOFF_SUPPORT */ 
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_HIGHLIGHT_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_HIGHLIGHT_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif /* LED_ONOFF_SUPPORT */ 

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_HIGHLIGHT)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_HIGHLIGHT));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_HIGHLIGHT_OFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_highlight
 * DESCRIPTION
 *  Initialized highlight settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->highlight, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.highlight_p = &mmi_camco_setting_p->highlight;

    /* shared with video */
    mmi_camco_setting_p->video.highlight_p = &mmi_camco_setting_p->highlight;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_HIGHLIGHT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_HIGHLIGHT;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_HIGHLIGHT;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_HIGHLIGHT_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_HIGHLIGHT_ON] = STR_GLOBAL_ON;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_HIGHLIGHT_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_HIGHLIGHT_ON] = IMG_ID_CAMCO_HIGHLIGHT_ON;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_afrange_capability
 * DESCRIPTION
 *  default afrange capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_afrange_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.afrange_p = &mmi_camco_setting_p->afrange;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_AFRANGE, setting_ptr);
    
    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFRANGE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFRANGE));        
    }


    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_AFRANGE_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].afrange = MMI_CAMCO_AFRANGE_AUTO;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].afrange = MMI_CAMCO_AFRANGE_AUTO;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].afrange = MMI_CAMCO_AFRANGE_AUTO;
    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].afrange = MMI_CAMCO_AFRANGE_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].afrange = MMI_CAMCO_AFRANGE_INFINTE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].afrange = MMI_CAMCO_AFRANGE_INFINTE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].afrange = MMI_CAMCO_AFRANGE_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].afrange = MMI_CAMCO_AFRANGE_MACRO;

    vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].afrange = MMI_CAMCO_AFRANGE_INFINTE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_afrange
 * DESCRIPTION
 *  Initialized afrange settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_afrange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->afrange, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.afrange_p = &mmi_camco_setting_p->afrange;

    /* shared with video */
    mmi_camco_setting_p->video.afrange_p = &mmi_camco_setting_p->afrange;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFRANGE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFRANGE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_AFRANGE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_AFRANGE_AUTO] = STR_ID_CAMCO_AFRANGE_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_AFRANGE_MACRO] = STR_ID_CAMCO_AFRANGE_MACRO;
    setting_ptr->item_str_id[MMI_CAMCO_AFRANGE_INFINTE] = STR_ID_CAMCO_AFRANGE_INFINITE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_AFRANGE_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_AFRANGE_MACRO] = IMG_ID_CAMCO_AFRANGE_MACRO;
    setting_ptr->item_img_id[MMI_CAMCO_AFRANGE_INFINTE] = IMG_ID_CAMCO_AFRANGE_INFINITE;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFRANGE_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFRANGE_MACRO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFRANGE_INFINTE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_afrange_capability
 * DESCRIPTION
 *  Update afrange capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_afrange_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *afrange_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afrange.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        afrange_setting_ptr = mmi_camco_setting_p->camera.afrange_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        /* store the original setting */
        if (last_scenemode == MMI_CAMCO_CAMSCENEMODE_AUTO || last_scenemode == MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].afrange =
                afrange_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].afrange =
                afrange_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_CAMSCENEMODE_AUTO && current_scenemode != MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            /* apply the scenemode setting */
            afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].afrange;
        #if 0
/* under construction !*/
        #endif /* 0 */ 
        }
        else
        {
            /* recover the original setting */
            if (last_scenemode != MMI_CAMCO_CAMSCENEMODE_END)
            {
                afrange_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
                afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].afrange;
            }
        }

    }
    else
    {
        scenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;
        afrange_setting_ptr = mmi_camco_setting_p->video.afrange_p;

        last_scenemode = mmi_camco_setting_p->last_vdoscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        if (last_scenemode == MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].afrange =
                afrange_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].afrange;
        #if 0
/* under construction !*/
        #endif /* 0 */ 
        }
        else
        {
            if (last_scenemode != MMI_CAMCO_VDOSCENEMODE_END)
            {
                afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].afrange;
                afrange_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            }
        }

        if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_AFMODE) == MMI_CAMCO_AFMODE_CONT)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_AFRANGE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_afrange_capability
 * DESCRIPTION
 *  Switch afrange capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_afrange_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *afrange_setting_ptr = &mmi_camco_setting_p->afrange;
    mmi_camco_setting_struct *const camscenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
    mmi_camco_setting_struct *const vdoscenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;

    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afrange.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    afrange_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].afrange
            = afrange_setting_ptr->cur_value;

        current_scenemode = camscenemode_setting_ptr->cur_value;

        afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].afrange;
        if (afrange_setting_ptr->cur_value == 0xff)
        {
            afrange_setting_ptr->cur_value = MMI_CAMCO_AFRANGE_AUTO;
            mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].afrange = afrange_setting_ptr->cur_value;
        }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
    else
    {
        if (mmi_camco_setting_p->facedetect.cur_value == MMI_CAMCO_FACEDETECT_ON)
        {
            mmi_camco_setting_set_boundary_capability(
                MMI_CAMCO_SETTING_AFRANGE,
                MMI_CAMCO_AFRANGE_INFINTE,
                MMI_CAMCO_AFRANGE_AUTO);
        }

        mmi_camco_setting_scene_sel_p->camscenemode[camscenemode_setting_ptr->cur_value].afrange
            = afrange_setting_ptr->cur_value;

        current_scenemode = vdoscenemode_setting_ptr->cur_value;

        afrange_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].afrange;
        if (afrange_setting_ptr->cur_value == 0xff)
        {
            afrange_setting_ptr->cur_value = MMI_CAMCO_AFRANGE_AUTO;
            mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].afrange = afrange_setting_ptr->cur_value;
        }

        if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_AFMODE) == MMI_CAMCO_AFMODE_CONT)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_AFRANGE);
        }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_facedetect_capability
 * DESCRIPTION
 *  default facedetect capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_facedetect_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.facedetect_p = &mmi_camco_setting_p->facedetect;

    /* get capability */
#ifdef __FACE_DETECTION_SUPPORT__
#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
#endif /* DUAL_CAMERA_SUPPORT */ 
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_ON] = MMI_CAMCO_SETTING_CAP_ENABLED;
    #ifdef DUAL_CAMERA_SUPPORT
    }
    else
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }
    #endif /* DUAL_CAMERA_SUPPORT */ 
#endif /* __FACE_DETECTION_SUPPORT__ */ 

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_FACEDETECT)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_FACEDETECT));        
    }


    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_FACEDETECT_OFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_facedetect
 * DESCRIPTION
 *  Initialized face detect settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_facedetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->facedetect, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.facedetect_p = &mmi_camco_setting_p->facedetect;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_FACEDETECT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_FACEDETECT;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_FACE_DETECTION;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_FACEDETECT_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_FACEDETECT_ON] = STR_GLOBAL_ON;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_FACEDETECT_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_FACEDETECT_ON] = IMG_ID_CAMCO_FACEDETECT_ON;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_FACEDETECT_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_facedetect_capability
 * DESCRIPTION
 *  Update facedetect capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_facedetect_capability(void)
{
#ifdef __FACE_DETECTION_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *scenemode_setting_ptr;
    mmi_camco_setting_struct *afrange_setting_ptr;
    mmi_camco_setting_struct *facedetect_setting_ptr;
    mmi_camco_setting_struct *afzone_setting_ptr;
    mmi_camco_setting_struct *capmode_setting_ptr;
    //mmi_camco_setting_struct *wb_setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->facedetect.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        afrange_setting_ptr = mmi_camco_setting_p->camera.afrange_p;
        facedetect_setting_ptr = mmi_camco_setting_p->camera.facedetect_p;
        afzone_setting_ptr = mmi_camco_setting_p->camera.afzone_p;
        capmode_setting_ptr = mmi_camco_setting_p->camera.capmode_p;
        //wb_setting_ptr = mmi_camco_setting_p->camera.wb_p;

        if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON)
        {
            if (scenemode_setting_ptr->cur_value != MMI_CAMCO_CAMSCENEMODE_AUTO &&
                scenemode_setting_ptr->cur_value != MMI_CAMCO_CAMSCENEMODE_PORTRAIT &&
                scenemode_setting_ptr->cur_value != MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
            {
                if (scenemode_setting_ptr->cur_value != 0xff)
                {
                    mmi_camco_setting_p->last_camscenemode =(mmi_camco_camscenemode_enum)scenemode_setting_ptr->cur_value;
                }
                else
                {
                    mmi_camco_setting_p->last_camscenemode = MMI_CAMCO_CAMSCENEMODE_END;
                }
                scenemode_setting_ptr->cur_value = MMI_CAMCO_CAMSCENEMODE_AUTO;

                mmi_camco_setting_update_capability();

                mmi_camco_makeup_facedetect_mainlist_index();
            }
        }

        /* AF zone */
        if (afzone_setting_ptr->cap != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON)
            {
                mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_AFZONE);
            #if (AF_SUPPORT)               
			    if(afzone_setting_ptr->item_cap[MMI_CAMCO_AFZONE_CONTINUE] == MMI_CAMCO_SETTING_CAP_ENABLED)
			    {
                    afzone_setting_ptr->cur_value = MMI_CAMCO_AFZONE_CONTINUE;
			    }
				else
				{
					afzone_setting_ptr->cur_value = MMI_CAMCO_AFZONE_SINGLE;	
				}
            #else
                afzone_setting_ptr->cur_value = MMI_CAMCO_AFZONE_SINGLE;            
            #endif
            }
            else
            {
                mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_AFZONE);              
            }
        }
        /* AF range */
        if (afrange_setting_ptr->cap != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON)
            {
                if (afrange_setting_ptr->cur_value == MMI_CAMCO_AFRANGE_INFINTE)
                {
                    afrange_setting_ptr->cur_value = MMI_CAMCO_AFRANGE_AUTO;
                }
                mmi_camco_setting_set_boundary_capability(
                    MMI_CAMCO_SETTING_AFRANGE,
                    MMI_CAMCO_AFRANGE_MACRO,
                    MMI_CAMCO_AFRANGE_AUTO);
            }
            else
            {
                mmi_camco_setting_set_boundary_capability(
                    MMI_CAMCO_SETTING_AFRANGE,
                    MMI_CAMCO_AFRANGE_INFINTE,
                    MMI_CAMCO_AFRANGE_AUTO);
            }
        }
        /* Capmode */
        if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON)
        {
        #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
            if (capmode_setting_ptr->cur_value == MMI_CAMCO_CAPMODE_ADD_FRAME)
            {
                capmode_setting_ptr->cur_value = MMI_CAMCO_CAPMODE_NORMAL;
                mmi_camco_update_capmode(MMI_CAMCO_CAPMODE_NORMAL);
                mmi_camco_osd_set_add_frame_enable(MMI_FALSE);
            }
        #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
        #ifndef __SMILE_SHUTTER_SUPPORT__
            mmi_camco_setting_set_boundary_capability(
                MMI_CAMCO_SETTING_CAPMODE,
                MMI_CAMCO_CAPMODE_EV_BRACKET_SEL,
                MMI_CAMCO_CAPMODE_NORMAL);
        #else /* __SMILE_SHUTTER_SUPPORT__ */ 
            if(capmode_setting_ptr->cur_value != MMI_CAMCO_CAPMODE_SMILE_SHOT&&capmode_setting_ptr->cur_value != MMI_CAMCO_CAPMODE_ASD_SHOT)
            {
                mmi_camco_setting_set_boundary_capability(
                    MMI_CAMCO_SETTING_CAPMODE,
                    MMI_CAMCO_CAPMODE_SMILE_SHOT,
                    MMI_CAMCO_CAPMODE_NORMAL);
            }else if(mmi_camco_setting_p->last_FD == MMI_CAMCO_FACEDETECT_ON)
        	{
				mmi_camco_setting_set_boundary_capability(
					MMI_CAMCO_SETTING_CAPMODE,
					MMI_CAMCO_CAPMODE_SMILE_SHOT,
					MMI_CAMCO_CAPMODE_NORMAL);

			}                

        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
        }
        else
        {
            mmi_camco_setting_set_boundary_capability(
                MMI_CAMCO_SETTING_CAPMODE,
                MMI_CAMCO_CAPMODE_ADD_FRAME,
                MMI_CAMCO_CAPMODE_NORMAL);
        #if defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
            if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN && !mmi_camco_is_from_external())
            {
                capmode_setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }
            else
            {
                capmode_setting_ptr->item_cap[MMI_CAMCO_CAPMODE_AUTORAMA] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
        #endif /* defined(DUAL_CAMERA_SUPPORT) && defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) */ 
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                capmode_setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }
            else
            {
                capmode_setting_ptr->item_cap[MMI_CAMCO_CAPMODE_SMILE_SHOT] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
        }

        /* Face detection 3.0 has supported WB_TUNGSTEN. */
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
    #endif /* 0 */ 
        if (facedetect_setting_ptr->cur_value == MMI_CAMCO_FACEDETECT_ON)
        {
            mmi_camco_setting_store_to_nvram();
        }

        mmi_camco_config_capsize_capability();
    }
#endif /* __FACE_DETECTION_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_selftimer_capability
 * DESCRIPTION
 *  default selftimers capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_selftimer_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.selftimer_p = &mmi_camco_setting_p->selftimer;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SELFTIMER_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SELFTIMER_5_SEC] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SELFTIMER_10_SEC] = MMI_CAMCO_SETTING_CAP_ENABLED;

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SELFTIMER)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SELFTIMER));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_SELFTIMER_OFF;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_selftimer
 * DESCRIPTION
 *  Initialized selftimer settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_selftimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->selftimer, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.selftimer_p = &mmi_camco_setting_p->selftimer;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SELFTIMER_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SELFTIMER;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SELFTIMER;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_SELFTIMER_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_SELFTIMER_5_SEC] = STR_ID_CAMCO_SELFTIMER_5S;
    setting_ptr->item_str_id[MMI_CAMCO_SELFTIMER_10_SEC] = STR_ID_CAMCO_SELFTIMER_10S;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_SELFTIMER_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SELFTIMER_5_SEC] = IMG_ID_CAMCO_SELFTIMER_5S;
    setting_ptr->item_img_id[MMI_CAMCO_SELFTIMER_10_SEC] = IMG_ID_CAMCO_SELFTIMER_10S;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_iso_capability
 * DESCRIPTION
 *  default iso capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_iso_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.iso_p = &mmi_camco_setting_p->iso;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_ISO, setting_ptr);

    if (setting_ptr->item_cap[MMI_CAMCO_ISO_AUTO] == MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    
    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_ISO)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_ISO));        
    }
        
    mmi_camco_setting_get_iso_binning();


    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_ISO_AUTO;

        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].iso = MMI_CAMCO_ISO_AUTO;
    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].iso = MMI_CAMCO_ISO_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].iso = MMI_CAMCO_ISO_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].iso = MMI_CAMCO_ISO_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].iso = MMI_CAMCO_ISO_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].iso = MMI_CAMCO_ISO_AUTO;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].iso = MMI_CAMCO_ISO_AUTO;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_iso
 * DESCRIPTION
 *  Initialized iso settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_iso(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->iso, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.iso_p = &mmi_camco_setting_p->iso;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_ISO_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_ISO;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_ISO;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_ISO_AUTO] = STR_ID_CAMCO_ISO_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_ISO_100] = STR_ID_CAMCO_ISO_100;
    setting_ptr->item_str_id[MMI_CAMCO_ISO_200] = STR_ID_CAMCO_ISO_200;
    setting_ptr->item_str_id[MMI_CAMCO_ISO_400] = STR_ID_CAMCO_ISO_400;
    setting_ptr->item_str_id[MMI_CAMCO_ISO_800] = STR_ID_CAMCO_ISO_800;
    setting_ptr->item_str_id[MMI_CAMCO_ISO_1600] = STR_ID_CAMCO_ISO_1600;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_ISO_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_ISO_100] = IMG_ID_CAMCO_ISO_100;
    setting_ptr->item_img_id[MMI_CAMCO_ISO_200] = IMG_ID_CAMCO_ISO_200;
    setting_ptr->item_img_id[MMI_CAMCO_ISO_400] = IMG_ID_CAMCO_ISO_400;
    setting_ptr->item_img_id[MMI_CAMCO_ISO_800] = IMG_ID_CAMCO_ISO_800;
    setting_ptr->item_img_id[MMI_CAMCO_ISO_1600] = IMG_ID_CAMCO_ISO_1600;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_100] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_200] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_400] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_800] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_ISO_1600] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_iso_capability
 * DESCRIPTION
 *  Update iso capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_iso_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *iso_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->iso.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        iso_setting_ptr = mmi_camco_setting_p->camera.iso_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        /* store the original setting */
        if (last_scenemode == MMI_CAMCO_CAMSCENEMODE_AUTO)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].iso = iso_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_CAMSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            iso_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].iso;
            iso_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;

        }
        else
        {
            if (last_scenemode != MMI_CAMCO_CAMSCENEMODE_END)
            {
                iso_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
                iso_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].iso;
            }
        }

    }

    if (mmi_camco_setting_is_iso_binning(mmi_camco_setting_p->iso.cur_value))
    {
        U16 upperbound_capsize = 0;

        mmi_camco_setting_p->is_current_iso_binning = MMI_TRUE;

        upperbound_capsize = mmi_camco_setting_p->iso_binning.IsoBinningInfo[mmi_camco_setting_p->iso.cur_value].MaxResolution;

        if (mmi_camco_setting_p->capsize.cur_value > mmi_camco_setting_p->mdi_vs_mmi_capsize[upperbound_capsize])
        {
            mmi_camco_setting_p->capsize.cur_value = mmi_camco_setting_p->mdi_vs_mmi_capsize[upperbound_capsize];
            mmi_camco_update_capsize();
        }
    }
    else
    {
        mmi_camco_setting_p->is_current_iso_binning = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_wb_capability
 * DESCRIPTION
 *  default wb capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_wb_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.wb_p = &mmi_camco_setting_p->wb;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_WB, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_WB)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_WB));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_WB_AUTO;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].wb = MMI_CAMCO_WB_AUTO;
        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].wb = MMI_CAMCO_WB_AUTO;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_wb
 * DESCRIPTION
 *  Initialized wb settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_wb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->wb, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.wb_p = &mmi_camco_setting_p->wb;

    /* shared with video */
    mmi_camco_setting_p->video.wb_p = &mmi_camco_setting_p->wb;

    /* init main str/img id */
    
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_WB_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_WB;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_WB;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_WB_AUTO] = STR_ID_CAMCO_WB_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_WB_DAYLIGHT] = STR_ID_CAMCO_WB_DAYLIGHT;
    setting_ptr->item_str_id[MMI_CAMCO_WB_TUNGSTEN] = STR_ID_CAMCO_WB_TUNGSTEN;
    setting_ptr->item_str_id[MMI_CAMCO_WB_FLUORESCENT] = STR_ID_CAMCO_WB_FLUORESCENT;
    setting_ptr->item_str_id[MMI_CAMCO_WB_CLOUDY] = STR_ID_CAMCO_WB_CLOUDY;
    setting_ptr->item_str_id[MMI_CAMCO_WB_INCANDESCENT] = STR_ID_CAMCO_WB_INCANDESCENT;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_WB_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_WB_DAYLIGHT] = IMG_ID_CAMCO_WB_DAYLIGHT;
    setting_ptr->item_img_id[MMI_CAMCO_WB_TUNGSTEN] = IMG_ID_CAMCO_WB_TUNGSTEN;
    setting_ptr->item_img_id[MMI_CAMCO_WB_FLUORESCENT] = IMG_ID_CAMCO_WB_FLUORESCENT;
    setting_ptr->item_img_id[MMI_CAMCO_WB_CLOUDY] = IMG_ID_CAMCO_WB_CLOUDY;
    setting_ptr->item_img_id[MMI_CAMCO_WB_INCANDESCENT] = IMG_ID_CAMCO_WB_INCANDESCENT;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_DAYLIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_TUNGSTEN] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_FLUORESCENT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_CLOUDY] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_WB_INCANDESCENT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

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
#endif /* 0 */ 
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_wb_capability
 * DESCRIPTION
 *  Switch wb capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_wb_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *wb_setting_ptr = &mmi_camco_setting_p->wb;
    mmi_camco_setting_struct *const vdoscenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;

   // static U16 camwb_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->wb.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].wb = wb_setting_ptr->cur_value;

        /* Face detection 3.0 has supported WB_TUNGSTEN. */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
    else
    {
       // camwb_value = wb_setting_ptr->cur_value;
        mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].wb = wb_setting_ptr->cur_value;

        /* Face detection 3.0 has supported WB_TUNGSTEN. */
    #if 0
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        /* apply the scenemode setting */
        if (wb_setting_ptr->item_cap[wb_setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
        {
            wb_setting_ptr->cur_value
                = mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].wb;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_effect_capability
 * DESCRIPTION
 *  default effect capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_effect_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.effect_p = &mmi_camco_setting_p->effect;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_EFFECT, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_EFFECT)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_EFFECT));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_EFFECT_NORMAL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_effect
 * DESCRIPTION
 *  Initialized effect settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->effect, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.effect_p = &mmi_camco_setting_p->effect;

    /* shared with video */
    mmi_camco_setting_p->video.effect_p = &mmi_camco_setting_p->effect;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_EFFECT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_EFFECT;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_EFFECT;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_NORMAL] = STR_GLOBAL_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_LOMO] = STR_ID_CAMCO_EFFECT_LOMO_EFFECT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_RED_ACCENT] = STR_ID_CAMCO_EFFECT_RED_COLOR_ACCENT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_GREEN_ACCENT] = STR_ID_CAMCO_EFFECT_GREEN_COLOR_ACCENT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_BLUE_ACCENT] = STR_ID_CAMCO_EFFECT_BLUE_COLOR_ACCENT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_YELLOW_ACCENT] = STR_ID_CAMCO_EFFECT_YELLOW_COLOR_ACCENT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_GRAYSCALE] = STR_ID_CAMCO_EFFECT_GRAYSCALE;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_SEPIA] = STR_ID_CAMCO_EFFECT_SEPIA;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_SEPIA_GREEN] = STR_ID_CAMCO_EFFECT_SEPIA_GREEN;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_SEPIA_BLUE] = STR_ID_CAMCO_EFFECT_SEPIA_BLUE;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_COLOR_INVERT] = STR_ID_CAMCO_EFFECT_COLOR_INVERT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_GRAY_INVERT] = STR_ID_CAMCO_EFFECT_GRAY_INVERT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_BLACKBOARD] = STR_ID_CAMCO_EFFECT_BLACKBOARD;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_WHITEBOARD] = STR_ID_CAMCO_EFFECT_WHITEBOARD;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_COPPER_CARVING] = STR_ID_CAMCO_EFFECT_COPPER_CARVING;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_BLUE_CARVING] = STR_ID_CAMCO_EFFECT_BLUE_CARVING;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_EMBOSSMENT] = STR_ID_CAMCO_EFFECT_EMBOSSMENT;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_CONTRAST] = STR_ID_CAMCO_EFFECT_CONTRAST;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_JEAN] = STR_ID_CAMCO_EFFECT_JEAN;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_SKETCH] = STR_ID_CAMCO_EFFECT_SKETCH;
    setting_ptr->item_str_id[MMI_CAMCO_EFFECT_OIL] = STR_ID_CAMCO_EFFECT_OIL;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_NORMAL] = 0;
	setting_ptr->item_img_id[MMI_CAMCO_EFFECT_LOMO] = 0;
	setting_ptr->item_img_id[MMI_CAMCO_EFFECT_RED_ACCENT] = 0;
	setting_ptr->item_img_id[MMI_CAMCO_EFFECT_GREEN_ACCENT] = 0;
	setting_ptr->item_img_id[MMI_CAMCO_EFFECT_BLUE_ACCENT] = 0;
	setting_ptr->item_img_id[MMI_CAMCO_EFFECT_YELLOW_ACCENT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_GRAYSCALE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_SEPIA] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_SEPIA_GREEN] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_SEPIA_BLUE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_COLOR_INVERT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_GRAY_INVERT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_BLACKBOARD] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_WHITEBOARD] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_COPPER_CARVING] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_BLUE_CARVING] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_EMBOSSMENT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_CONTRAST] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_JEAN] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_SKETCH] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EFFECT_OIL] = 0;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

    for (idx = 0; idx < MMI_CAMCO_EFFECT_END; idx++)
    {
        setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_effect_capability
 * DESCRIPTION
 *  Update effect capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_effect_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *effect_setting_ptr = &mmi_camco_setting_p->effect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (effect_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    effect_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        if (mmi_camco_setting_p->facedetect.cur_value == MMI_CAMCO_FACEDETECT_ON 
			|| mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_HDR_SHOT 
			|| mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_3D_IMAGE)
        {
            mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_EFFECT, MMI_CAMCO_EFFECT_NORMAL);
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_EFFECT);
        }
        else
        {
            mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_EFFECT);
            if(mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_NORMAL || 
               mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_BURST_SHOT_SEL ||
               mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_CONT_SHOT)
            {
                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_LOMO] == MMI_CAMCO_SETTING_CAP_DISABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_LOMO] = MMI_CAMCO_SETTING_CAP_ENABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_RED_ACCENT] == MMI_CAMCO_SETTING_CAP_DISABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_RED_ACCENT] = MMI_CAMCO_SETTING_CAP_ENABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_BLUE_ACCENT] == MMI_CAMCO_SETTING_CAP_DISABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_BLUE_ACCENT] = MMI_CAMCO_SETTING_CAP_ENABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_GREEN_ACCENT] == MMI_CAMCO_SETTING_CAP_DISABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_GREEN_ACCENT] = MMI_CAMCO_SETTING_CAP_ENABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_YELLOW_ACCENT] == MMI_CAMCO_SETTING_CAP_DISABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_YELLOW_ACCENT] = MMI_CAMCO_SETTING_CAP_ENABLED;
                
            }
            else
            {
            
                if(mmi_camco_setting_p->effect.cur_value == MMI_CAMCO_EFFECT_LOMO ||
                   mmi_camco_setting_p->effect.cur_value == MMI_CAMCO_EFFECT_RED_ACCENT||
                   mmi_camco_setting_p->effect.cur_value == MMI_CAMCO_EFFECT_BLUE_ACCENT||
                   mmi_camco_setting_p->effect.cur_value == MMI_CAMCO_EFFECT_GREEN_ACCENT||
                   mmi_camco_setting_p->effect.cur_value == MMI_CAMCO_EFFECT_YELLOW_ACCENT)

                   mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_EFFECT, MMI_CAMCO_EFFECT_NORMAL);

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_LOMO] == MMI_CAMCO_SETTING_CAP_ENABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_LOMO] = MMI_CAMCO_SETTING_CAP_DISABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_RED_ACCENT] == MMI_CAMCO_SETTING_CAP_ENABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_RED_ACCENT] = MMI_CAMCO_SETTING_CAP_DISABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_BLUE_ACCENT] == MMI_CAMCO_SETTING_CAP_ENABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_BLUE_ACCENT] = MMI_CAMCO_SETTING_CAP_DISABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_GREEN_ACCENT] == MMI_CAMCO_SETTING_CAP_ENABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_GREEN_ACCENT] = MMI_CAMCO_SETTING_CAP_DISABLED;

                if(mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_YELLOW_ACCENT] == MMI_CAMCO_SETTING_CAP_ENABLED)
                    mmi_camco_setting_p->effect.item_cap[MMI_CAMCO_EFFECT_YELLOW_ACCENT] = MMI_CAMCO_SETTING_CAP_DISABLED;


            }
        }
    }
    else
    {
        mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_EFFECT);
    }
    mmi_camco_setting_update_imgadjust_capability();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_effect_capability
 * DESCRIPTION
 *  Switch effect capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_effect_capability(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_camco_setting_struct *setting_ptr;
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *effect_setting_ptr = &mmi_camco_setting_p->effect;
    U16 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (effect_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    effect_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
	setting_ptr = &mmi_camco_setting_p->effect;
    for (idx = 0; idx < MMI_CAMCO_EFFECT_END; idx++)
    {
        setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }
	mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_EFFECT, setting_ptr);

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
    #ifdef __FACE_DETECTION_SUPPORT__
        if (mmi_camco_setting_p->facedetect.cur_value == MMI_CAMCO_FACEDETECT_ON || mmi_camco_setting_p->capmode.cur_value == MMI_CAMCO_CAPMODE_HDR_SHOT)
        {
            mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_EFFECT, MMI_CAMCO_EFFECT_NORMAL);
			mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_EFFECT);
            mmi_camco_setting_update_imgadjust_capability();
        }
        else
	#endif
        {
            mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_EFFECT);

        }
    }
    else
    {
        mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_EFFECT);

	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_storage_capability
 * DESCRIPTION
 *  default storage capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_storage_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    U8 drv_num;
    U16 drv_enum;
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;
    mdi_video_rec_spec_struct spec_entry_struct;
    U32 i;
    U16 count;    
    MMI_BOOL isPhoneSupport = MMI_FALSE, isCardSupport = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_num = srv_fmgr_drivelist_count(drvlist);
            
    setting_ptr = mmi_camco_setting_p->camera.storage_p = &mmi_camco_setting_p->storage;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
	for(idx = 0;idx < MMI_CAMCO_MAX_SETTING_ITEM_COUNT; idx++)
	{
		setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;
	}
    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        drv_enum = srv_fmgr_drv_get_type(drv);        

        setting_ptr->item_cap[drv_enum] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
#ifdef __FS_CARD_SUPPORT__
    setting_ptr->item_cap[SRV_FMGR_DRV_CARD_TYPE] = MMI_CAMCO_SETTING_CAP_ENABLED;
#ifdef __PLUTO_MMI_PACKAGE__
    setting_ptr->item_str_id[SRV_FMGR_DRV_CARD_TYPE] = STR_FMGR_REM_DEVICE;
#endif
    setting_ptr->item_img_id[SRV_FMGR_DRV_CARD_TYPE] = IMG_ID_CAMCO_STORAGE_MEMORY_CARD;
#endif /* __FS_CARD_SUPPORT__ */ 
    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        for (idx = 0; idx < SRV_FMGR_DRV_TOTAL; idx++)
        {
            if (setting_ptr->item_cap[idx] == MMI_CAMCO_SETTING_CAP_ENABLED)
            {
                setting_ptr->cur_value = idx;
                break;
            }
        }

        if (idx == SRV_FMGR_DRV_TOTAL)
        {
            setting_ptr->cur_value = 0;
        }
    }

    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        switch (spec_entry_struct.storage)
        {
            case MDI_VIDEO_REC_STORAGE_PHONE:             
                isPhoneSupport = MMI_TRUE;  
                break;         
                
            case MDI_VIDEO_REC_STORAGE_SD:             
                isCardSupport = MMI_TRUE;    
                break;           
                
            case MDI_VIDEO_REC_STORAGE_ALL: 
                isPhoneSupport = MMI_TRUE;                  
                isCardSupport = MMI_TRUE;    
                break;                               
        }
    }    

    if(!isPhoneSupport)
    {
        setting_ptr->item_cap[SRV_FMGR_DRV_PHONE_TYPE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        setting_ptr->item_cap[SRV_FMGR_DRV_PHONE_2_TYPE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;              
    }

    if(!isCardSupport)
    {
        setting_ptr->item_cap[SRV_FMGR_DRV_CARD_TYPE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        setting_ptr->item_cap[SRV_FMGR_DRV_CARD_2_TYPE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;            
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_storage
 * DESCRIPTION
 *  Initialized storage settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    U8 drv_num;
    U16 drv_enum;
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_num = srv_fmgr_drivelist_count(drvlist);

    memset((void*)&mmi_camco_setting_p->storage, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.storage_p = &mmi_camco_setting_p->storage;

    /* shared with video */
    mmi_camco_setting_p->video.storage_p = &mmi_camco_setting_p->storage;

    /* init main str/img id */
    
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_STORAGE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_STORAGE;
    #endif
    
    setting_ptr->main_str_id = STR_GLOBAL_STORAGE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    for (idx = 0; idx < SRV_FMGR_DRV_TOTAL; idx++)
    {
        setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }

    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        drv_enum = srv_fmgr_drv_get_type(drv);       

        setting_ptr->item_str_id[drv_enum] = srv_fmgr_drv_get_string((U8)drv);

        if (drv_enum == SRV_FMGR_DRV_PHONE_TYPE || drv_enum == SRV_FMGR_DRV_PHONE_2_TYPE)
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_PHONE;
        }
        else if (drv_enum == SRV_FMGR_DRV_CARD_TYPE)
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_MEMORY_CARD;
        }
        else
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_OTG;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_storage_capability
 * DESCRIPTION
 *  Update storage capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_storage_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_update_storage(mmi_camco_setting_p->storage.cur_value);

    if(!mmi_camco_is_drive_avaiable() && mmi_camco_setting_p->storage.cur_value == SRV_FMGR_DRV_CARD_TYPE)
    {
        mmi_camco_switch_non_avaiable_storage(MMI_TRUE);
    }
    else
    {
        mmi_camco_switch_non_avaiable_storage(MMI_FALSE);    
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_check_storage_capability
 * DESCRIPTION
 *  default storage capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_check_storage_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    U8 drv_num;
    U8 drv_enum;
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_num = srv_fmgr_drivelist_count(drvlist);

    setting_ptr = mmi_camco_setting_p->camera.storage_p;

    for (idx = 0; idx < SRV_FMGR_DRV_TOTAL; idx++)
    {
        setting_ptr->item_cap[idx] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    }

    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        drv_enum = srv_fmgr_drv_get_type(drv);       

        setting_ptr->item_str_id[drv_enum] = srv_fmgr_drv_get_string((U8)drv);

        if (drv_enum == SRV_FMGR_DRV_PHONE_TYPE || drv_enum == SRV_FMGR_DRV_PHONE_2_TYPE)
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_PHONE;
        }
        else if (drv_enum == SRV_FMGR_DRV_CARD_TYPE)
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_MEMORY_CARD;
        }
        else
        {
            setting_ptr->item_img_id[drv_enum] = IMG_ID_CAMCO_STORAGE_OTG;
        }
    }
    mmi_camco_default_storage_capability();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_capqty_capability
 * DESCRIPTION
 *  default capqty capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_capqty_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.capqty_p = &mmi_camco_setting_p->capqty;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPQTY_FINE] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPQTY_GOOD] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPQTY_NORMAL] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_CAPQTY_LOW] = MMI_CAMCO_SETTING_CAP_DISABLED;    

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAPQTY)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CAPQTY));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_CAPQTY_FINE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_capqty
 * DESCRIPTION
 *  Initialized capqty settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_capqty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->capqty, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.capqty_p = &mmi_camco_setting_p->capqty;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_CAPQTY_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_CAPQTY;    
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_CAPQTY;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CAPQTY_FINE] = STR_ID_CAMCO_CAPQTY_FINE;
    setting_ptr->item_str_id[MMI_CAMCO_CAPQTY_GOOD] = STR_ID_CAMCO_CAPQTY_GOOD;
    setting_ptr->item_str_id[MMI_CAMCO_CAPQTY_NORMAL] = STR_ID_CAMCO_CAPQTY_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_CAPQTY_LOW] = STR_ID_CAMCO_CAPQTY_LOW;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CAPQTY_FINE] = IMG_ID_CAMCO_CAPQTY_FINE;
    setting_ptr->item_img_id[MMI_CAMCO_CAPQTY_GOOD] = IMG_ID_CAMCO_CAPQTY_GOOD;
    setting_ptr->item_img_id[MMI_CAMCO_CAPQTY_NORMAL] = IMG_ID_CAMCO_CAPQTY_NORMAL;
    setting_ptr->item_img_id[MMI_CAMCO_CAPQTY_LOW] = IMG_ID_CAMCO_CAPQTY_LOW;    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_afzone_capability
 * DESCRIPTION
 *  default afzone capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_afzone_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.afzone_p = &mmi_camco_setting_p->afzone;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_AFZONE, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFZONE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFZONE));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_AFZONE_SINGLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_afzone
 * DESCRIPTION
 *  Initialized afzone settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_afzone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->afzone, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.afzone_p = &mmi_camco_setting_p->afzone;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFZONE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFZONE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_AFZONE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_AFZONE_SINGLE] = STR_ID_CAMCO_AFZONE_SINGLE;
    setting_ptr->item_str_id[MMI_CAMCO_AFZONE_MULTI] = STR_ID_CAMCO_AFZONE_MULTI;
    setting_ptr->item_str_id[MMI_CAMCO_AFZONE_CONTINUE] = STR_ID_CAMCO_AFZONE_CONTINUE;       

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_AFZONE_SINGLE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_AFZONE_MULTI] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_AFZONE_CONTINUE] = 0;    

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFZONE_SINGLE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFZONE_MULTI] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFZONE_CONTINUE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_aemeter_capability
 * DESCRIPTION
 *  default aemeter capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_aemeter_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.aemeter_p = &mmi_camco_setting_p->aemeter;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_AEMETER, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AEMETER)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AEMETER));        
    }


    /* if setting is un-intied or driver not enabled reset to default */
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_AEMETER_AUTO;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].aemeter = MMI_CAMCO_AEMETER_AUTO;
        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].aemeter = MMI_CAMCO_AEMETER_AUTO;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_aemeter
 * DESCRIPTION
 *  Initialized aemeter settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_aemeter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->aemeter, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.aemeter_p = &mmi_camco_setting_p->aemeter;

    /* shared with video */
    mmi_camco_setting_p->video.aemeter_p = &mmi_camco_setting_p->aemeter;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
    setting_ptr->main_img_id = IMG_ID_CAMCO_AEMETER_SEL;
    #else
    setting_ptr->main_img_id = IMG_ID_CAMCO_AEMETER;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_AEMETER;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_AEMETER_AUTO] = STR_ID_CAMCO_AEMETER_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_AEMETER_SPOT] = STR_ID_CAMCO_AEMETER_SPOT;
    setting_ptr->item_str_id[MMI_CAMCO_AEMETER_CENTER_WEIGHT] = STR_ID_CAMCO_AEMETER_CENTER_WEIGHT;
    setting_ptr->item_str_id[MMI_CAMCO_AEMETER_AVERAGE] = STR_ID_CAMCO_AEMETER_AVERAGE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_AEMETER_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_AEMETER_SPOT] = IMG_ID_CAMCO_AEMETER_SPOT;
    setting_ptr->item_img_id[MMI_CAMCO_AEMETER_CENTER_WEIGHT] = IMG_ID_CAMCO_AEMETER_CENTER_WEIGHT;
    setting_ptr->item_img_id[MMI_CAMCO_AEMETER_AVERAGE] = IMG_ID_CAMCO_AEMETER_AVERAGE;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AEMETER_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AEMETER_SPOT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AEMETER_CENTER_WEIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AEMETER_AVERAGE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_sharpness_capability
 * DESCRIPTION
 *  default sharpness capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_sharpness_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.sharpness_p = &mmi_camco_setting_p->sharpness;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_SHARPNESS, setting_ptr);
    
    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SHARPNESS)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SHARPNESS));        
    }   

    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_SHARPNESS_NORMAL;

        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].sharpness = MMI_CAMCO_SHARPNESS_NORMAL;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].sharpness = MMI_CAMCO_SHARPNESS_NORMAL;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].sharpness = MMI_CAMCO_SHARPNESS_NORMAL;
    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].sharpness = MMI_CAMCO_SHARPNESS_REDUCE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].sharpness = MMI_CAMCO_SHARPNESS_ENHANCE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].sharpness = MMI_CAMCO_SHARPNESS_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].sharpness = MMI_CAMCO_SHARPNESS_REDUCE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].sharpness = MMI_CAMCO_SHARPNESS_ENHANCE;

    vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].sharpness = MMI_CAMCO_SHARPNESS_REDUCE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_sharpness
 * DESCRIPTION
 *  Initialized sharpness settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_sharpness(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->sharpness, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.sharpness_p = &mmi_camco_setting_p->sharpness;

    /* shared with video */
    mmi_camco_setting_p->video.sharpness_p = &mmi_camco_setting_p->sharpness;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SHARPNESS_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SHARPNESS;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SHARPNESS;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_SHARPNESS_ENHANCE] = STR_ID_CAMCO_ENHANCE;
    setting_ptr->item_str_id[MMI_CAMCO_SHARPNESS_NORMAL] = STR_GLOBAL_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_SHARPNESS_REDUCE] = STR_ID_CAMCO_REDUCE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_SHARPNESS_ENHANCE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SHARPNESS_NORMAL] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SHARPNESS_REDUCE] = 0;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SHARPNESS_ENHANCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SHARPNESS_NORMAL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SHARPNESS_REDUCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_sharpness_capability
 * DESCRIPTION
 *  Update sharpness capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_sharpness_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *sharpness_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->sharpness.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        sharpness_setting_ptr = mmi_camco_setting_p->camera.sharpness_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        /* store the original setting */
        if (last_scenemode == MMI_CAMCO_CAMSCENEMODE_AUTO || last_scenemode == MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].sharpness =
                sharpness_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].sharpness =
                sharpness_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_CAMSCENEMODE_AUTO && current_scenemode != MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            /* apply the scenemode setting */
            sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].sharpness;
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }
        else
        {
            /* recover the original setting */
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].sharpness;
        }
    }
    else
    {
        scenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;
        sharpness_setting_ptr = mmi_camco_setting_p->video.sharpness_p;

        last_scenemode = mmi_camco_setting_p->last_vdoscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        /* store the original setting */
        if (last_scenemode == MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].sharpness =
                sharpness_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].sharpness;
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }
        else
        {
            /* recover the original setting */
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].sharpness;
        }
    }

    if (sharpness_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_sharpness_capability
 * DESCRIPTION
 *  Switch sharpness capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_sharpness_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *sharpness_setting_ptr = &mmi_camco_setting_p->sharpness;
    mmi_camco_setting_struct *const camscenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
    mmi_camco_setting_struct *const vdoscenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;

    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->sharpness.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].sharpness
            = sharpness_setting_ptr->cur_value;

        current_scenemode = camscenemode_setting_ptr->cur_value;

        sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].sharpness;
        if (sharpness_setting_ptr->cur_value == 0xff)
        {
            sharpness_setting_ptr->cur_value = MMI_CAMCO_SHARPNESS_NORMAL;
            mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].sharpness = sharpness_setting_ptr->cur_value;
        }

        if (current_scenemode >= MMI_CAMCO_CAMSCENEMODE_PORTRAIT
            && current_scenemode <= MMI_CAMCO_CAMSCENEMODE_DOCUMENT)
        {
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }
    else
    {
        mmi_camco_setting_scene_sel_p->camscenemode[camscenemode_setting_ptr->cur_value].sharpness
            = sharpness_setting_ptr->cur_value;

        current_scenemode = vdoscenemode_setting_ptr->cur_value;

        sharpness_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].sharpness;
        if (sharpness_setting_ptr->cur_value == 0xff)
        {
            sharpness_setting_ptr->cur_value = MMI_CAMCO_SHARPNESS_NORMAL;
            mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].sharpness = sharpness_setting_ptr->cur_value;
        }

        if (current_scenemode == MMI_CAMCO_VDOSCENEMODE_NIGHT)
        {
            sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }

    if (sharpness_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        sharpness_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_contrast_capability
 * DESCRIPTION
 *  default contrast capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_contrast_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    setting_ptr = mmi_camco_setting_p->camera.contrast_p = &mmi_camco_setting_p->contrast;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CONTRAST, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CONTRAST)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_CONTRAST));        
    }   

    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_CONTRAST_NORMAL;

        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].contrast = MMI_CAMCO_CONTRAST_NORMAL;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].contrast = MMI_CAMCO_CONTRAST_NORMAL;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].contrast = MMI_CAMCO_CONTRAST_NORMAL;
    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].contrast = MMI_CAMCO_CONTRAST_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].contrast = MMI_CAMCO_CONTRAST_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].contrast = MMI_CAMCO_CONTRAST_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].contrast = MMI_CAMCO_CONTRAST_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].contrast = MMI_CAMCO_CONTRAST_ENHANCE;

    vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].contrast = MMI_CAMCO_CONTRAST_NORMAL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_contrast
 * DESCRIPTION
 *  Initialized contrast settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_contrast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->contrast, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.contrast_p = &mmi_camco_setting_p->contrast;

    /* shared with video */
    mmi_camco_setting_p->video.contrast_p = &mmi_camco_setting_p->contrast;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_CONTRAST_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_CONTRAST;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_CONTRAST;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_CONTRAST_ENHANCE] = STR_ID_CAMCO_ENHANCE;
    setting_ptr->item_str_id[MMI_CAMCO_CONTRAST_NORMAL] = STR_GLOBAL_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_CONTRAST_REDUCE] = STR_ID_CAMCO_REDUCE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_CONTRAST_ENHANCE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CONTRAST_NORMAL] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_CONTRAST_REDUCE] = 0;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CONTRAST_ENHANCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CONTRAST_NORMAL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_CONTRAST_REDUCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_contrast_capability
 * DESCRIPTION
 *  Update contrast capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_contrast_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *contrast_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->contrast.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        contrast_setting_ptr = mmi_camco_setting_p->camera.contrast_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        if (last_scenemode == MMI_CAMCO_CAMSCENEMODE_AUTO || last_scenemode == MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].contrast =
                contrast_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].contrast =
                contrast_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_CAMSCENEMODE_AUTO && current_scenemode != MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
            contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].contrast;
        }
        else
        {
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].contrast;
        }
    }
    else
    {
        scenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;
        contrast_setting_ptr = mmi_camco_setting_p->video.contrast_p;

        last_scenemode = mmi_camco_setting_p->last_vdoscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        if (last_scenemode == MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].contrast =
                contrast_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].contrast;
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }
        else
        {
            contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].contrast;
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
        }
    }

    if (contrast_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_contrast_capability
 * DESCRIPTION
 *  Switch contrast capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_contrast_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *contrast_setting_ptr = &mmi_camco_setting_p->contrast;
    mmi_camco_setting_struct *const camscenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
    mmi_camco_setting_struct *const vdoscenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;

    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->contrast.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].contrast
            = contrast_setting_ptr->cur_value;

        current_scenemode = camscenemode_setting_ptr->cur_value;

        contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].contrast;
        if (contrast_setting_ptr->cur_value == 0xff)
        {
            contrast_setting_ptr->cur_value = MMI_CAMCO_CONTRAST_NORMAL;
            mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].contrast = contrast_setting_ptr->cur_value;
        }

        if (current_scenemode >= MMI_CAMCO_CAMSCENEMODE_PORTRAIT
            && current_scenemode <= MMI_CAMCO_CAMSCENEMODE_DOCUMENT)
        {
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }
    else
    {
        mmi_camco_setting_scene_sel_p->camscenemode[camscenemode_setting_ptr->cur_value].contrast
            = contrast_setting_ptr->cur_value;

        current_scenemode = vdoscenemode_setting_ptr->cur_value;

        contrast_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].contrast;
        if (contrast_setting_ptr->cur_value == 0xff)
        {
            contrast_setting_ptr->cur_value = MMI_CAMCO_CONTRAST_NORMAL;
            mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].contrast = contrast_setting_ptr->cur_value;
        }

        if (current_scenemode == MMI_CAMCO_VDOSCENEMODE_NIGHT)
        {
            contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }

    if (contrast_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        contrast_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_saturation_capability
 * DESCRIPTION
 *  default contrast capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_saturation_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mmi_camco_setting_cam_scene_sel_struct *cam_scene_sel_p;
    mmi_camco_setting_vdo_scene_sel_struct *vdo_scene_sel_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.saturation_p = &mmi_camco_setting_p->saturation;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_SATURATION, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SATURATION)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_SATURATION));        
    }    

    /* if setting is un-intied or driver not enabled reset to default */
    cam_scene_sel_p = mmi_camco_setting_scene_sel_p->camscenemode;
    vdo_scene_sel_p = mmi_camco_setting_scene_sel_p->vdoscenemode;

    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_SATURATION_NORMAL;

        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_AUTO].saturation = MMI_CAMCO_SATURATION_NORMAL;
        cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].saturation = MMI_CAMCO_SATURATION_NORMAL;

        vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_AUTO].saturation = MMI_CAMCO_SATURATION_NORMAL;
    }
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_PORTRAIT].saturation = MMI_CAMCO_SATURATION_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_LANDSCAPE].saturation = MMI_CAMCO_SATURATION_ENHANCE;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_SPORT].saturation = MMI_CAMCO_SATURATION_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_NIGHT].saturation = MMI_CAMCO_SATURATION_NORMAL;
    cam_scene_sel_p[MMI_CAMCO_CAMSCENEMODE_DOCUMENT].saturation = MMI_CAMCO_SATURATION_NORMAL;

    vdo_scene_sel_p[MMI_CAMCO_VDOSCENEMODE_NIGHT].saturation = MMI_CAMCO_SATURATION_NORMAL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_saturation
 * DESCRIPTION
 *  Initialized saturation settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_saturation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->saturation, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.saturation_p = &mmi_camco_setting_p->saturation;

    /* shared with video */
    mmi_camco_setting_p->video.saturation_p = &mmi_camco_setting_p->saturation;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SATURATION_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SATURATION; 
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SATURATION;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_SATURATION_ENHANCE] = STR_ID_CAMCO_ENHANCE;
    setting_ptr->item_str_id[MMI_CAMCO_SATURATION_NORMAL] = STR_GLOBAL_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_SATURATION_REDUCE] = STR_ID_CAMCO_REDUCE;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_SATURATION_ENHANCE] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SATURATION_NORMAL] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SATURATION_REDUCE] = 0;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SATURATION_ENHANCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SATURATION_NORMAL] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_SATURATION_REDUCE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_saturation_capability
 * DESCRIPTION
 *  Update contrast capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_saturation_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *saturation_setting_ptr;
    mmi_camco_setting_struct *scenemode_setting_ptr;
    U16 last_scenemode;
    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->saturation.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        scenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
        saturation_setting_ptr = mmi_camco_setting_p->camera.saturation_p;

        last_scenemode = mmi_camco_setting_p->last_camscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        if (last_scenemode == MMI_CAMCO_CAMSCENEMODE_AUTO || last_scenemode == MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_AUTO].saturation =
                saturation_setting_ptr->cur_value;
            mmi_camco_setting_scene_sel_p->camscenemode[MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE].saturation =
                saturation_setting_ptr->cur_value;

        }

        if (current_scenemode != MMI_CAMCO_CAMSCENEMODE_AUTO && current_scenemode != MMI_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
            saturation_setting_ptr->cur_value =
                mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].saturation;
        }
        else
        {
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
            saturation_setting_ptr->cur_value =
                mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].saturation;
        }
    }
    else
    {
        scenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;
        saturation_setting_ptr = mmi_camco_setting_p->video.saturation_p;

        last_scenemode = mmi_camco_setting_p->last_vdoscenemode;
        current_scenemode = scenemode_setting_ptr->cur_value;

        if (last_scenemode == MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            mmi_camco_setting_scene_sel_p->vdoscenemode[MMI_CAMCO_VDOSCENEMODE_AUTO].saturation =
                saturation_setting_ptr->cur_value;
        }

        if (current_scenemode != MMI_CAMCO_VDOSCENEMODE_AUTO)
        {
            saturation_setting_ptr->cur_value =
                mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].saturation;
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }
        else
        {
            saturation_setting_ptr->cur_value =
                mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].saturation;
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
        }
    }

    if (saturation_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_saturation_capability
 * DESCRIPTION
 *  Switch saturation capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_saturation_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;
    mmi_camco_setting_struct *saturation_setting_ptr = &mmi_camco_setting_p->saturation;
    mmi_camco_setting_struct *const camscenemode_setting_ptr = mmi_camco_setting_p->camera.camscenemode_p;
    mmi_camco_setting_struct *const vdoscenemode_setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p;

    U16 current_scenemode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->saturation.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[vdoscenemode_setting_ptr->cur_value].saturation
            = saturation_setting_ptr->cur_value;

        current_scenemode = camscenemode_setting_ptr->cur_value;

        saturation_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].saturation;
        if (saturation_setting_ptr->cur_value == 0xff)
        {
            saturation_setting_ptr->cur_value = MMI_CAMCO_SATURATION_NORMAL;
            mmi_camco_setting_scene_sel_p->camscenemode[current_scenemode].saturation
                = saturation_setting_ptr->cur_value;
        }

        if (current_scenemode >= MMI_CAMCO_CAMSCENEMODE_PORTRAIT
            && current_scenemode <= MMI_CAMCO_CAMSCENEMODE_DOCUMENT)
        {
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }
    else
    {
        mmi_camco_setting_scene_sel_p->camscenemode[camscenemode_setting_ptr->cur_value].saturation
            = saturation_setting_ptr->cur_value;

        current_scenemode = vdoscenemode_setting_ptr->cur_value;

        saturation_setting_ptr->cur_value = mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].saturation;
        if (saturation_setting_ptr->cur_value == 0xff)
        {
            saturation_setting_ptr->cur_value = MMI_CAMCO_SATURATION_NORMAL;
            mmi_camco_setting_scene_sel_p->vdoscenemode[current_scenemode].saturation
                = saturation_setting_ptr->cur_value;
        }

        if (current_scenemode == MMI_CAMCO_VDOSCENEMODE_NIGHT)
        {
            saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        }

    }

    if (saturation_setting_ptr->cap == MMI_CAMCO_SETTING_CAP_ENABLED &&
        mmi_camco_setting_p->effect.cur_value != MMI_CAMCO_EFFECT_NORMAL)
    {
        saturation_setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_timestamp_capability
 * DESCRIPTION
 *  default contrast capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_timestamp_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.timestamp_p = &mmi_camco_setting_p->timestamp;

#if defined(__MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__) 
    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_TIMESTAMP, setting_ptr);   

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_TIMESTAMP)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_TIMESTAMP));        
    }

    /* if setting is un-intied or driver not enabled reset to  */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_TIMESTAMP_OFF;
    }
#else /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_TIMESTAMP_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_TIMESTAMP_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

    setting_ptr->cur_value = MMI_CAMCO_TIMESTAMP_OFF;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_timestamp
 * DESCRIPTION
 *  Initialized timestamp settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_timestamp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->timestamp, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.timestamp_p = &mmi_camco_setting_p->timestamp;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_TIMESTAMP_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_TIMESTAMP;   
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_TIMESTAMP;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_TIMESTAMP_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_TIMESTAMP_ON] = STR_GLOBAL_ON;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_TIMESTAMP_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_TIMESTAMP_ON] = IMG_ID_CAMCO_TIMESTAMP_ON;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_TIMESTAMP_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_TIMESTAMP_ON] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_timestamp_capability
 * DESCRIPTION
 *  Update timestamp capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_timestamp_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *timestamp_setting_ptr;
    mmi_camco_capmode_enum capmode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timestamp_setting_ptr = &mmi_camco_setting_p->timestamp;
    capmode = (mmi_camco_capmode_enum)mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE);

#if defined(__MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__) 
    if (timestamp_setting_ptr->cur_value == MMI_CAMCO_TIMESTAMP_ON &&
        capmode != MMI_CAMCO_CAPMODE_ADD_FRAME && capmode != MMI_CAMCO_CAPMODE_AUTORAMA)
    {
        mmi_camco_osd_set_time_stamp_enable(MMI_TRUE);
    }
    else
    {
        if (capmode == MMI_CAMCO_CAPMODE_ADD_FRAME || capmode == MMI_CAMCO_CAPMODE_AUTORAMA)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_TIMESTAMP);
        }
        else
        {
            mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_TIMESTAMP);
        }
        mmi_camco_osd_set_time_stamp_enable(MMI_FALSE);
    }
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_shuttersound_capability
 * DESCRIPTION
 *  default shuttersound capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_shuttersound_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.shuttersound_p = &mmi_camco_setting_p->shuttersound;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SHUTTERSOUND_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SHUTTERSOUND_SOUND_1] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SHUTTERSOUND_SOUND_2] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SHUTTERSOUND_SOUND_3] = MMI_CAMCO_SETTING_CAP_ENABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_SHUTTERSOUND_SOUND_1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_shuttersound
 * DESCRIPTION
 *  Initialized shuttersound settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_shuttersound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->shuttersound, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.shuttersound_p = &mmi_camco_setting_p->shuttersound;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SHUTTERSOUND_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SHUTTERSOUND;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SHUTTERSOUND;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_SHUTTERSOUND_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_SHUTTERSOUND_SOUND_1] = STR_ID_CAMCO_SHUTTERSOUND_SOUND_1;
    setting_ptr->item_str_id[MMI_CAMCO_SHUTTERSOUND_SOUND_2] = STR_ID_CAMCO_SHUTTERSOUND_SOUND_2;
    setting_ptr->item_str_id[MMI_CAMCO_SHUTTERSOUND_SOUND_3] = STR_ID_CAMCO_SHUTTERSOUND_SOUND_3;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_SHUTTERSOUND_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SHUTTERSOUND_SOUND_1] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SHUTTERSOUND_SOUND_2] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SHUTTERSOUND_SOUND_3] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_banding_capability
 * DESCRIPTION
 *  default banding capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_banding_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.banding_p = &mmi_camco_setting_p->banding;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_BANDING_50HZ] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_BANDING_60HZ] = MMI_CAMCO_SETTING_CAP_ENABLED;

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_BANDING)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_BANDING));        
    }   

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_BANDING_60HZ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_banding
 * DESCRIPTION
 *  Initialized banding settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_banding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->banding, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.banding_p = &mmi_camco_setting_p->banding;

    /* shared with video */
    mmi_camco_setting_p->video.banding_p = &mmi_camco_setting_p->banding;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_BANDING_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_BANDING;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_BANDING;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_BANDING_50HZ] = STR_ID_CAMCO_BANDING_50HZ;
    setting_ptr->item_str_id[MMI_CAMCO_BANDING_60HZ] = STR_ID_CAMCO_BANDING_60HZ;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_BANDING_50HZ] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_BANDING_60HZ] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_vdoswitchto_capability
 * DESCRIPTION
 *  default vdoswitchto capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_vdoswitchto_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.vdoswitchto_p = &mmi_camco_setting_p->vdoswitchto;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
#ifdef __MMI_VIDEO_PLAYER__
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] = MMI_CAMCO_SETTING_CAP_ENABLED;
#else 
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif 
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;

#if (defined(DUAL_CAMERA_SUPPORT) && !defined(__MMI_CAMCO_FTE__))
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
    }
#else /* DUAL_CAMERA_SUPPORT */ 
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif /* DUAL_CAMERA_SUPPORT */ 

    /* default value */
    setting_ptr->cur_value = MMI_CAMCO_VDOSWITCHTO_CAMERA;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_vdoswitchto
 * DESCRIPTION
 *  Initialized vdoswitchto settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_vdoswitchto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->vdoswitchto, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.vdoswitchto_p = &mmi_camco_setting_p->vdoswitchto;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SWITCH_TO_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SWITCH_TO;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SWITCH_TO;
    setting_ptr->is_show_radio = MMI_FALSE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] = STR_ID_CAMCO_TO_VDOPLY;
    setting_ptr->item_str_id[MMI_CAMCO_VDOSWITCHTO_CAMERA] = STR_ID_CAMCO_TO_CAMERA;
    setting_ptr->item_str_id[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = STR_ID_CAMCO_TO_MAIN_CAM;
    setting_ptr->item_str_id[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = STR_ID_CAMCO_TO_SUB_CAM;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VDOSWITCHTO_CAMERA] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_external_vdoswitchto_capability
 * DESCRIPTION
 *  default external vdoswitchto capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_external_vdoswitchto_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.vdoswitchto_p = &mmi_camco_setting_p->vdoswitchto;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;

#if (defined(DUAL_CAMERA_SUPPORT) && !defined(__MMI_CAMCO_FTE__))
    if (mmi_camco_setting_p->active_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        /* default value */
        setting_ptr->cur_value = MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA;
    }
    else
    {
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_ENABLED;
        setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DISABLED;
        /* default value */
        setting_ptr->cur_value = MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA;
    }
#else /* DUAL_CAMERA_SUPPORT */ 
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
#endif /* DUAL_CAMERA_SUPPORT */ 

}



/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_tiemlaps
 * DESCRIPTION
 *  Initialized timelaps settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_timelaps(void)
{
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->timelaps, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.timelaps_p= &mmi_camco_setting_p->timelaps;

    /* init main str/img id */
    setting_ptr->main_img_id = IMG_ID_CAMCO_TIME_LAPSE_SEL;

    setting_ptr->main_str_id = STR_ID_CAMCO_TIME_LAPSE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_TIMELAPS_ON] = STR_GLOBAL_ON;/*using  gloable*/
    setting_ptr->item_str_id[MMI_CAMCO_TIMELAPS_OFF] = STR_GLOBAL_OFF;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_TIMELAPS_ON] = IMG_ID_CAMCO_TIME_LAPSE_ON;
    setting_ptr->item_img_id[MMI_CAMCO_TIMELAPS_OFF] = 0;

	setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_tiemlaps
 * DESCRIPTION
 *  default  timelaps capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_timelaps_capablility(void)
{
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.timelaps_p= &mmi_camco_setting_p->timelaps;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELAPS_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELAPS_ON] = MMI_CAMCO_SETTING_CAP_ENABLED;
	
    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_TIMELAPS_OFF;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_time_laps_capability
 * DESCRIPTION
 *  Update update timelaps capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_update_timelaps_capability(void)
{
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_camco_update_limit_capability();
	mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_RECAUD);
    if (mmi_camco_setting_p->recaud.cap == MMI_CAMCO_SETTING_CAP_ENABLED)
    {
	    if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_OFF)
	    {
		    mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_RECAUD, MMI_CAMCO_RECAUD_ON);
		  
	    }
	    else
	    {
	
		    mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_RECAUD, MMI_CAMCO_RECAUD_OFF);	
			mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_RECAUD);
	
	    }
    }
#endif

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_external_visqty_capability
 * DESCRIPTION
 *  default external visqty capability. for qty/size/codec is binding project
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_external_visqty_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recoorder_config_setting_set setting_set;
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_setting_p->visqty.cur_value != MMI_CAMCO_VISQTY_LOW)
    {
        mmi_camco_setting_p->visqty.cur_value = MMI_CAMCO_VISQTY_LOW;       
		if(recorder_config_has_dependency())
		{
            mmi_camco_custom_get_depended_set(&setting_set);
            for(i=0;i<setting_set.count;i++)
            {
                mmi_camco_custom_set_depended_setting(setting_set.target[i]);
            }
            mmi_camco_setting_store_to_nvram();        
            for(i=0;i<setting_set.count;i++)
            {
                mmi_camco_custom_update_depended_setting(setting_set.target[i]);            
			}
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_vdoscenemode_capability
 * DESCRIPTION
 *  default vdoscenemode capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_vdoscenemode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p = &mmi_camco_setting_p->vdoscenemode;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_VDOSCENEMODE, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VDOSCENEMODE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VDOSCENEMODE));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_VDOSCENEMODE_AUTO;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_vdoscenemode
 * DESCRIPTION
 *  Initialized vdoscenemode settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_vdoscenemode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->vdoscenemode, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.vdoscenemode_p = &mmi_camco_setting_p->vdoscenemode;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
    setting_ptr->main_img_id = IMG_ID_CAMCO_SCENEMODE_SEL;
    #else
    setting_ptr->main_img_id = IMG_ID_CAMCO_SCENEMODE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_SCENEMODE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_VDOSCENEMODE_AUTO] = STR_ID_CAMCO_SCENEMODE_AUTO;
    setting_ptr->item_str_id[MMI_CAMCO_VDOSCENEMODE_NIGHT] = STR_ID_CAMCO_SCENEMODE_NIGHT;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_VDOSCENEMODE_AUTO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VDOSCENEMODE_NIGHT] = IMG_ID_CAMCO_SCENEMODE_NIGHT;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VDOSCENEMODE_AUTO] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VDOSCENEMODE_NIGHT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_recsize_capability
 * DESCRIPTION
 *  default recsize capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_recsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    //S16 idx = 0;
    mdi_video_rec_spec_struct spec_entry_struct;    
    U32 i;
    U16 count;
    U32 p = 0, q = 0, r = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.recsize_p = &mmi_camco_setting_p->recsize;

    memset(mmi_camco_recsize_vs_codec_vs_qty, 0, sizeof(MMI_BOOL)*MMI_CAMCO_RECSIZE_END*MMI_CAMCO_VISCODEC_END*MMI_CAMCO_VISQTY_END);
    
    /* get capability */
    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        switch (spec_entry_struct.video_size)
        {

            case MDI_VIDEO_REC_RESOLUTION_128x96:             // SQCIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SQCIF] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_SQCIF;
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_160x120:            // QQVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QQVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_QQVGA;                
                break;            
                
            case MDI_VIDEO_REC_RESOLUTION_176x144:            // QCIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QCIF] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_QCIF;                      
                break;            
                
            case MDI_VIDEO_REC_RESOLUTION_352x288:            // CIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_CIF] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_CIF;                      
                break;   
                
            case MDI_VIDEO_REC_RESOLUTION_400x240:            // WQVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WQVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_WQVGA;                      
                break;            
            
            case MDI_VIDEO_REC_RESOLUTION_432x240:            // CIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_CIF2] = MMI_CAMCO_SETTING_CAP_ENABLED; 
                p = MMI_CAMCO_RECSIZE_CIF2;                      
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_480x320:            // HVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_HVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_HVGA;                      
                break;   
                
            case MDI_VIDEO_REC_RESOLUTION_640x368:            // NHD
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_NHD] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_NHD;                      
                break; 
                
            case MDI_VIDEO_REC_RESOLUTION_640x480:            // VGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_VGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_VGA;                      
                break; 
                
            case MDI_VIDEO_REC_RESOLUTION_720x480:            // D1
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_D1] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_D1;                      
                break;       
                
            case MDI_VIDEO_REC_RESOLUTION_720x576:            // D1
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_D12] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_D12;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_800x480:            // WVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_WVGA;                      
                break;   

            case MDI_VIDEO_REC_RESOLUTION_800x608:            // SVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_SVGA;                      
                break;   
                
            case MDI_VIDEO_REC_RESOLUTION_848x480:            // WVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WVGA2] = MMI_CAMCO_SETTING_CAP_ENABLED;   
                p = MMI_CAMCO_RECSIZE_WVGA2;                      
                break;                         
                
            case MDI_VIDEO_REC_RESOLUTION_1024x768:           // XGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_XGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_XGA;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_1280x720:           // 720P
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_720P] = MMI_CAMCO_SETTING_CAP_ENABLED;  
                p = MMI_CAMCO_RECSIZE_720P;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_1280x960:           // 4VGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4VGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_4VGA;                      
                break;   
                
            case MDI_VIDEO_REC_RESOLUTION_1280x1024:          // SXGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SXGA] = MMI_CAMCO_SETTING_CAP_ENABLED;      
                p = MMI_CAMCO_RECSIZE_SXGA;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_1408x1152:          // 16CIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_16CIF] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_16CIF;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_1600x1200:          // 4SVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4SVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_4SVGA;                      
                break;  
                
            case MDI_VIDEO_REC_RESOLUTION_1920x1088:          // FHD
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_FHD] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_FHD;                      
                break;    
            case MDI_VIDEO_REC_RESOLUTION_704x576:          //4CIF
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4CIF] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_4CIF;                      
                break; 

            case MDI_VIDEO_REC_RESOLUTION_864x480:          // FWVGA
                setting_ptr->item_cap[MMI_CAMCO_RECSIZE_FWVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
                p = MMI_CAMCO_RECSIZE_FWVGA;                      
                break; 
		#ifdef MMI_CAMCO_WALLPAPER
			case MDI_VIDEO_REC_RESOLUTION_240x400:
	            setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER; 
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_240x400;
                break; 
			case MDI_VIDEO_REC_RESOLUTION_320x480:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_320x480;
				break; 
			case MDI_VIDEO_REC_RESOLUTION_96x128:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_96x128;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_120x160:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_120x160;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_288x352:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_288x352;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_176x208:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_176x208;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_144x176:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_144x176;
				break; 

			case MDI_VIDEO_REC_RESOLUTION_240x432:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_240x432;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_480x640:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_480x640;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_480x720:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_480x720;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_480x800:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_480x800;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_480x848:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_480x848;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_576x720:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_576x720;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_608x800:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_608x800;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_768x1024:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_768x1024;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_720x1280:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_720x1280;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_960x1280:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_960x1280;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_1024x1280:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_1024x1280;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_1152x1408:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_1152x1408;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_1200x1600:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_1200x1600;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_1088x1920:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_1088x1920;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_576x704:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_576x704;
				break; 
				
			case MDI_VIDEO_REC_RESOLUTION_480x864:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_480x864;
				break; 
			case MDI_VIDEO_REC_RESOLUTION_320x240:
				if(LCD_WIDTH == 320 && LCD_HEIGHT == 240)
				{
					setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
					mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_320x240;
				}
				    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
					p = MMI_CAMCO_RECSIZE_QVGA;	
				break; 
			case MDI_VIDEO_REC_RESOLUTION_240x320:
				setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_ENABLED;
				p = MMI_CAMCO_RECSIZE_WALLPAPER;	
				mmi_camco_setting_p->video.wp_rec_size = MDI_VIDEO_REC_RESOLUTION_240x320;
				break; 
		#else
			case MDI_VIDEO_REC_RESOLUTION_320x240:
					setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QVGA] = MMI_CAMCO_SETTING_CAP_ENABLED;
					p = MMI_CAMCO_RECSIZE_QVGA;
					break; 
		#endif
        }       
        switch (spec_entry_struct.video_format)
        {
            case MDI_VIDEO_VIDEO_FORMAT_3GP:
                q = MMI_CAMCO_VISCODEC_3GP;             
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MP4:
                q = MMI_CAMCO_VISCODEC_MP4;
                break;    
            case MDI_VIDEO_VIDEO_FORMAT_MJPEG:
                q = MMI_CAMCO_VISCODEC_MJPG;
                break;                
            case MDI_VIDEO_VIDEO_FORMAT_H264:
                q = MMI_CAMCO_VISCODEC_H264;
                break;     				
        }  
        switch (spec_entry_struct.quality)
        {
            case MDI_VIDEO_REC_QTY_LOW:             
                r = MMI_CAMCO_VISQTY_LOW;
                break;           
            case MDI_VIDEO_REC_QTY_NORMAL:             
                r = MMI_CAMCO_VISQTY_NORMAL;
                break;           
            case MDI_VIDEO_REC_QTY_FINE:             
                r = MMI_CAMCO_VISQTY_FINE;
                break;           
            case MDI_VIDEO_REC_QTY_HIGH:             
                r = MMI_CAMCO_VISQTY_GOOD;
                break;                  
        }        
        mmi_camco_recsize_vs_codec_vs_qty[p][q][r] = MMI_TRUE;
     #ifdef MMI_CAMCO_WALLPAPER
		if(LCD_WIDTH == 320 && LCD_HEIGHT == 240 && mmi_camco_recsize_vs_codec_vs_qty[MMI_CAMCO_RECSIZE_QVGA][q][r] == MMI_TRUE)
		{
			mmi_camco_recsize_vs_codec_vs_qty[MMI_CAMCO_RECSIZE_WALLPAPER][q][r] = MMI_TRUE;

		}
    #endif
		if(setting_ptr->cur_value == 0xff)
		{
			if(i==0 && !mmi_camco_is_from_external())
			{
	            mmi_camco_setting_p->recsize.cur_value = p;
			    mmi_camco_setting_p->viscodec.cur_value = q;
			    mmi_camco_setting_p->visqty.cur_value = r;
			}
			else
			{
	            mmi_camco_setting_p->recsize.cur_value = p;
			    mmi_camco_setting_p->viscodec.cur_value = q;
			    mmi_camco_setting_p->visqty.cur_value = r;
			}
		}
    }
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_RECSIZE)))
    {
    #ifdef MMI_CAMCO_WALLPAPER
		if( mmi_camco_setting_p->recsize.item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] ==  MMI_CAMCO_SETTING_CAP_ENABLED )
		{
			mmi_camco_setting_p->visqty.item_cap[MMI_CAMCO_VISQTY_LCD] = MMI_CAMCO_SETTING_CAP_ENABLED;
    	}
    #endif
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_RECSIZE));        
    }

    /* if setting is un-intied or driver not enabled reset to default */
    /*if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        for (idx = MMI_CAMCO_RECSIZE_END - 1; idx >= 0; idx--)
        {
            if (setting_ptr->item_cap[idx] == MMI_CAMCO_SETTING_CAP_ENABLED)
            {
                setting_ptr->cur_value = idx;
                break;
            }
        }

        if (setting_ptr->cur_value == 0xff)
        {
            MMI_ASSERT(0);
        }

    }
#ifdef __MMI_OP02_LEMEI__   
    if(mmi_camco_is_from_external())
    {
        mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_RECSIZE, MMI_CAMCO_RECSIZE_QCIF);
        mmi_camco_update_vdosize(MMI_CAMCO_RECSIZE_QCIF);
        mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_RECSIZE);     
    }
#endif */   
}

extern U16 mmi_camco_setting_get_wallpaper_size(void)
{
	return mmi_camco_setting_p->video.wp_rec_size;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_recsize
 * DESCRIPTION
 *  Initialized recsize settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_recsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->recsize, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.recsize_p = &mmi_camco_setting_p->recsize;
	mmi_camco_setting_p->video.wp_rec_size = 0;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_RECSIZE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_RECSIZE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_RECSIZE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_SQCIF] = STR_ID_CAMCO_RECSIZE_SQCIF;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_QQVGA] = STR_ID_CAMCO_RECSIZE_QQVGA;		
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_QCIF] = STR_ID_CAMCO_RECSIZE_QCIF;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_QVGA] = STR_ID_CAMCO_RECSIZE_QVGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_CIF] = STR_ID_CAMCO_RECSIZE_CIF;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_WQVGA] = STR_ID_CAMCO_RECSIZE_WQVGA;       
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_CIF2] = STR_ID_CAMCO_RECSIZE_CIF2; 
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_HVGA] = STR_ID_CAMCO_RECSIZE_HVGA;           
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_NHD] = STR_ID_CAMCO_RECSIZE_NHD;        
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_VGA] = STR_ID_CAMCO_RECSIZE_VGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_D1] = STR_ID_CAMCO_RECSIZE_D1;    
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_D12] = STR_ID_CAMCO_RECSIZE_D12;       
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_WVGA] = STR_ID_CAMCO_RECSIZE_WVGA;      
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_SVGA] = STR_ID_CAMCO_RECSIZE_SVGA;    
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_WVGA2] = STR_ID_CAMCO_RECSIZE_WVGA2;          
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_XGA] = STR_ID_CAMCO_RECSIZE_XGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_720P] = STR_ID_CAMCO_RECSIZE_720P;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_4VGA] = STR_ID_CAMCO_RECSIZE_4VGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_SXGA] = STR_ID_CAMCO_RECSIZE_SXGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_16CIF] = STR_ID_CAMCO_RECSIZE_16CIF;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_4SVGA] = STR_ID_CAMCO_RECSIZE_4SVGA;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_FHD] = STR_ID_CAMCO_RECSIZE_FHD;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_4CIF] = STR_ID_CAMCO_RECSIZE_4CIF;
    setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_FWVGA] = STR_ID_CAMCO_RECSIZE_FWVGA;
#ifdef MMI_CAMCO_WALLPAPER
	setting_ptr->item_str_id[MMI_CAMCO_RECSIZE_WALLPAPER] = STR_ID_CAMCO_RECSIZE_WALLPAPER;
#endif
    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_SQCIF] = IMG_ID_CAMCO_RECSIZE_SQCIF;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_QQVGA] = IMG_ID_CAMCO_RECSIZE_QQVGA;		
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_QCIF] = IMG_ID_CAMCO_RECSIZE_QCIF;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_QVGA] = IMG_ID_CAMCO_RECSIZE_QVGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_CIF] = IMG_ID_CAMCO_RECSIZE_CIF;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_WQVGA] = IMG_ID_CAMCO_RECSIZE_WQVGA;       
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_CIF2] = IMG_ID_CAMCO_RECSIZE_CIF2; 
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_HVGA] = IMG_ID_CAMCO_RECSIZE_HVGA;           
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_NHD] = IMG_ID_CAMCO_RECSIZE_nHD;        
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_VGA] = IMG_ID_CAMCO_RECSIZE_VGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_D1] = IMG_ID_CAMCO_RECSIZE_D1;    
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_D12] = IMG_ID_CAMCO_RECSIZE_D12;       
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_WVGA] = IMG_ID_CAMCO_RECSIZE_WVGA;      
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_SVGA] = IMG_ID_CAMCO_RECSIZE_SVGA;    
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_WVGA2] = IMG_ID_CAMCO_RECSIZE_WVGA2;          
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_XGA] = IMG_ID_CAMCO_RECSIZE_XGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_720P] = IMG_ID_CAMCO_RECSIZE_720P;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_4VGA] = IMG_ID_CAMCO_RECSIZE_4VGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_SXGA] = IMG_ID_CAMCO_RECSIZE_SXGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_16CIF] = IMG_ID_CAMCO_RECSIZE_16CIF;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_4SVGA] = IMG_ID_CAMCO_RECSIZE_4SVGA;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_FHD] = IMG_ID_CAMCO_RECSIZE_FHD;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_4CIF] = IMG_ID_CAMCO_RECSIZE_4CIF;
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_FWVGA] = IMG_ID_CAMCO_RECSIZE_FWVGA;
#ifdef MMI_CAMCO_WALLPAPER
    setting_ptr->item_img_id[MMI_CAMCO_RECSIZE_WALLPAPER] = IMG_ID_CAMCO_RECSIZE_WALLPAPER;
#endif
    /* init capability */
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SQCIF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QQVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;		
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QCIF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_QVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_CIF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WQVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;       
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_CIF2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT; 
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_HVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;           
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_NHD] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;        
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_VGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_D1] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;    
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_D12] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;       
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;      
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;    
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WVGA2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;          
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_XGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_720P] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4VGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_SXGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_16CIF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4SVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_FHD] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT; 
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_4CIF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_FWVGA] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT; 
#ifdef MMI_CAMCO_WALLPAPER
    setting_ptr->item_cap[MMI_CAMCO_RECSIZE_WALLPAPER] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT; 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_recsize_capability
 * DESCRIPTION
 *  Update recsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_update_recsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_update_limit_capability();

    if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][g_mmi_camco_setting_cntx.visqty.cur_value] || g_mmi_camco_setting_cntx.viscodec.cur_value == 0xFF)
    {
        S32 idx;
		if(mmi_camco_is_from_external())
	    {
			for (idx = 0; idx < MMI_CAMCO_RECSIZE_END; idx++)
			{
				if (mmi_camco_recsize_vs_codec_vs_qty[idx][mmi_camco_setting_p->viscodec.cur_value][mmi_camco_setting_p->visqty.cur_value])
				{
					mmi_camco_setting_p->recsize.cur_value = idx;
					break;
				}
			}

		}
		else
	    {
			for (idx = MMI_CAMCO_RECSIZE_END - 1; idx >= 0; idx--)
			{
				if (mmi_camco_recsize_vs_codec_vs_qty[idx][mmi_camco_setting_p->viscodec.cur_value][mmi_camco_setting_p->visqty.cur_value])
				{
					mmi_camco_setting_p->recsize.cur_value = idx;
					break;
				}
			}
        }
    }

    for(i = 0; i<MMI_CAMCO_RECSIZE_END; i++)
    {
        if(mmi_camco_setting_p->recsize.item_cap[i] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(!mmi_camco_recsize_vs_codec_vs_qty[i][mmi_camco_setting_p->viscodec.cur_value][mmi_camco_setting_p->visqty.cur_value])
            {
                mmi_camco_setting_p->recsize.item_cap[i] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
            else
            {
                mmi_camco_setting_p->recsize.item_cap[i] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_sizelimit_capability
 * DESCRIPTION
 *  default sizelimit capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_sizelimit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.sizelimit_p = &mmi_camco_setting_p->sizelimit;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_SIZELIMIT_NO_LIMIT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SIZELIMIT_95K] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SIZELIMIT_195K] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_SIZELIMIT_295K] = MMI_CAMCO_SETTING_CAP_ENABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_SIZELIMIT_NO_LIMIT;
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_sizelimit_capability
 * DESCRIPTION
 *  update sizelimit capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_sizelimit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_RECSIZE) > MMI_CAMCO_RECSIZE_CIF)
	{
		mmi_camco_setting_set_boundary_capability(
			MMI_CAMCO_SETTING_LIMIT,
			MMI_CAMCO_LIMIT_TIME_60S,
			MMI_CAMCO_LIMIT_NO_LIMIT);
	
		if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_TIME_60S)
		{
			mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_LIMIT, MMI_CAMCO_LIMIT_NO_LIMIT);
		}
	}
	else
	{
		mmi_camco_setting_set_boundary_capability(
			MMI_CAMCO_SETTING_LIMIT,
			MMI_CAMCO_LIMIT_SIZE_295K,
			MMI_CAMCO_LIMIT_NO_LIMIT);
	}


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_sizelimit
 * DESCRIPTION
 *  Initialized sizelimit settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_sizelimit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->sizelimit, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.sizelimit_p = &mmi_camco_setting_p->sizelimit;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_SIZELIMIT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_SIZELIMIT;
    #endif
    
    setting_ptr->main_str_id = STR_ID_CAMCO_SIZELIMIT;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_SIZELIMIT_NO_LIMIT] = STR_ID_CAMCO_SIZELIMIT_NO_LIMIT;
    setting_ptr->item_str_id[MMI_CAMCO_SIZELIMIT_95K] = STR_ID_CAMCO_SIZELIMIT_95K;
    setting_ptr->item_str_id[MMI_CAMCO_SIZELIMIT_195K] = STR_ID_CAMCO_SIZELIMIT_195K;
    setting_ptr->item_str_id[MMI_CAMCO_SIZELIMIT_295K] = STR_ID_CAMCO_SIZELIMIT_295K;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_SIZELIMIT_NO_LIMIT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_SIZELIMIT_95K] = IMG_ID_CAMCO_SIZELIMIT_95K;
    setting_ptr->item_img_id[MMI_CAMCO_SIZELIMIT_195K] = IMG_ID_CAMCO_SIZELIMIT_195K;
    setting_ptr->item_img_id[MMI_CAMCO_SIZELIMIT_295K] = IMG_ID_CAMCO_SIZELIMIT_295K;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_timelimit_capability
 * DESCRIPTION
 *  default timelimit capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_timelimit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.timelimit_p = &mmi_camco_setting_p->timelimit;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_NO_LIMIT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_15S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_30S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_60S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_5MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_10MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_TIMELIMIT_NO_LIMIT;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_timelimit_capability
 * DESCRIPTION
 *  update timelimit capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_update_timelimit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.timelimit_p = &mmi_camco_setting_p->timelimit;

	if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_OFF)
	{
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_15S] = MMI_CAMCO_SETTING_CAP_ENABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_30S] = MMI_CAMCO_SETTING_CAP_ENABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_60S] = MMI_CAMCO_SETTING_CAP_ENABLED;
	    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_5MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_10MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;

	}
	else
	{
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_15S] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_30S] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_60S] = MMI_CAMCO_SETTING_CAP_DISABLED;
	    setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_5MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;
		setting_ptr->item_cap[MMI_CAMCO_TIMELIMIT_10MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;

	}
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_TIMELIMIT_NO_LIMIT;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_timelimit
 * DESCRIPTION
 *  Initialized timelimit settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_timelimit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->timelimit, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.timelimit_p = &mmi_camco_setting_p->timelimit;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_TIMELIMIT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_TIMELIMIT;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_TIMELIMIT;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_NO_LIMIT] = STR_ID_CAMCO_TIMELIMIT_NO_LIMIT;
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_15S] = STR_ID_CAMCO_TIMELIMIT_15S;
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_30S] = STR_ID_CAMCO_TIMELIMIT_30S;
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_60S] = STR_ID_CAMCO_TIMELIMIT_60S;
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_5MIN] = STR_ID_CAMCO_LIMIT_TIME_5MIN;
    setting_ptr->item_str_id[MMI_CAMCO_TIMELIMIT_10MIN] = STR_ID_CAMCO_LIMIT_TIME_10MIN;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_NO_LIMIT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_15S] = IMG_ID_CAMCO_TIMELIMIT_15S;
    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_30S] = IMG_ID_CAMCO_TIMELIMIT_30S;
    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_60S] = IMG_ID_CAMCO_TIMELIMIT_60S;

    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_5MIN] = IMG_ID_CAMCO_LIMIT_TIME_5MIN;
    setting_ptr->item_img_id[MMI_CAMCO_TIMELIMIT_10MIN] = IMG_ID_CAMCO_LIMIT_TIME_10MIN;
}

extern void mmi_camco_update_limit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.limit_p = &mmi_camco_setting_p->limit;
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__

	if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_ON)
	{

        setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_15S] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_30S] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_60S] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_95K] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_195K] = MMI_CAMCO_SETTING_CAP_DISABLED;						
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_295K] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_5MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_10MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;

	}
	else
#endif
	{
		    setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_5MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;
		setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_10MIN] = MMI_CAMCO_SETTING_CAP_DISABLED;
		if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_RECSIZE) > MMI_CAMCO_RECSIZE_CIF)
		{
			mmi_camco_setting_set_boundary_capability(
				MMI_CAMCO_SETTING_LIMIT,
				MMI_CAMCO_LIMIT_TIME_60S,
				MMI_CAMCO_LIMIT_NO_LIMIT);
		
			if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_TIME_60S)
			{
				mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_LIMIT, MMI_CAMCO_LIMIT_NO_LIMIT);
			}
		}
		else
		{
			mmi_camco_setting_set_boundary_capability(
				MMI_CAMCO_SETTING_LIMIT,
				MMI_CAMCO_LIMIT_SIZE_295K,
				MMI_CAMCO_LIMIT_NO_LIMIT);
		}
		
	}
	
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_TIMELIMIT_NO_LIMIT;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_limit_capability
 * DESCRIPTION
 *  default limit capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_limit_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.limit_p = &mmi_camco_setting_p->limit;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_NO_LIMIT] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_15S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_30S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_60S] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_95K] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_195K] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_SIZE_295K] = MMI_CAMCO_SETTING_CAP_ENABLED;
	setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_5MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_LIMIT_TIME_10MIN] = MMI_CAMCO_SETTING_CAP_ENABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_LIMIT_NO_LIMIT;
    }
    
#ifdef __MMI_OP02_LEMEI__ 
    if(mmi_camco_is_from_external())
    {
        mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_LIMIT, MMI_CAMCO_LIMIT_TIME_30S);        
        mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_LIMIT);        
    }
#endif        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_limit
 * DESCRIPTION
 *  Initialized limit settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->limit, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.limit_p = &mmi_camco_setting_p->limit;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_LIMIT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_LIMIT;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_LIMIT;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_NO_LIMIT] = STR_ID_CAMCO_LIMIT_NO_LIMIT;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_TIME_15S] = STR_ID_CAMCO_LIMIT_TIME_15S;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_TIME_30S] = STR_ID_CAMCO_LIMIT_TIME_30S;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_TIME_60S] = STR_ID_CAMCO_LIMIT_TIME_60S;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_SIZE_95K] = STR_ID_CAMCO_LIMIT_SIZE_95K;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_SIZE_195K] = STR_ID_CAMCO_LIMIT_SIZE_195K;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_SIZE_295K] = STR_ID_CAMCO_LIMIT_SIZE_295K;
	setting_ptr->item_str_id[MMI_CAMCO_LIMIT_TIME_5MIN] = STR_ID_CAMCO_LIMIT_TIME_5MIN;
    setting_ptr->item_str_id[MMI_CAMCO_LIMIT_TIME_10MIN] = STR_ID_CAMCO_LIMIT_TIME_10MIN;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_NO_LIMIT] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_TIME_15S] = IMG_ID_CAMCO_LIMIT_TIME_15S;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_TIME_30S] = IMG_ID_CAMCO_LIMIT_TIME_30S;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_TIME_60S] = IMG_ID_CAMCO_LIMIT_TIME_60S;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_SIZE_95K] = IMG_ID_CAMCO_LIMIT_SIZE_95K;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_SIZE_195K] = IMG_ID_CAMCO_LIMIT_SIZE_195K;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_SIZE_295K] = IMG_ID_CAMCO_LIMIT_SIZE_295K;
	setting_ptr->item_img_id[MMI_CAMCO_LIMIT_TIME_5MIN] = IMG_ID_CAMCO_LIMIT_TIME_5MIN;
    setting_ptr->item_img_id[MMI_CAMCO_LIMIT_TIME_10MIN] = IMG_ID_CAMCO_LIMIT_TIME_10MIN;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_visqty_capability
 * DESCRIPTION
 *  default visqty capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_visqty_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mdi_video_rec_spec_struct spec_entry_struct;
    U32 i;
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.visqty_p = &mmi_camco_setting_p->visqty;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;

    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        switch (spec_entry_struct.quality)
        {
            case MDI_VIDEO_REC_QTY_LOW:             
                setting_ptr->item_cap[MMI_CAMCO_VISQTY_LOW] = MMI_CAMCO_SETTING_CAP_ENABLED;             
                break;           
            case MDI_VIDEO_REC_QTY_NORMAL:             
                setting_ptr->item_cap[MMI_CAMCO_VISQTY_NORMAL] = MMI_CAMCO_SETTING_CAP_ENABLED;           
                break;           
            case MDI_VIDEO_REC_QTY_FINE:             
                setting_ptr->item_cap[MMI_CAMCO_VISQTY_FINE] = MMI_CAMCO_SETTING_CAP_ENABLED;            
                break;           
            case MDI_VIDEO_REC_QTY_HIGH:             
                setting_ptr->item_cap[MMI_CAMCO_VISQTY_GOOD] = MMI_CAMCO_SETTING_CAP_ENABLED;          
                break;                  
        }
    }

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VISQTY)))
    {   
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VISQTY));        
    }


    /* if setting is un-intied or driver not enabled reset to default */
    /*if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_VISQTY_FINE;
    }*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_visqty
 * DESCRIPTION
 *  Initialized visqty settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_visqty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->visqty, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.visqty_p = &mmi_camco_setting_p->visqty;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_VISQTY_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_VISQTY;    
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_VISQTY;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_VISQTY_FINE] = STR_ID_CAMCO_VISQTY_FINE;
    setting_ptr->item_str_id[MMI_CAMCO_VISQTY_GOOD] = STR_ID_CAMCO_VISQTY_GOOD;
    setting_ptr->item_str_id[MMI_CAMCO_VISQTY_NORMAL] = STR_ID_CAMCO_VISQTY_NORMAL;
    setting_ptr->item_str_id[MMI_CAMCO_VISQTY_LOW] = STR_ID_CAMCO_VISQTY_LOW;
#ifdef MMI_CAMCO_WALLPAPER
	setting_ptr->item_str_id[MMI_CAMCO_VISQTY_LCD] = STR_ID_CAMCO_RECSIZE_WALLPAPER;
#endif
    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_VISQTY_FINE] = IMG_ID_CAMCO_VISQTY_FINE;
    setting_ptr->item_img_id[MMI_CAMCO_VISQTY_GOOD] = IMG_ID_CAMCO_VISQTY_GOOD;
    setting_ptr->item_img_id[MMI_CAMCO_VISQTY_NORMAL] = IMG_ID_CAMCO_VISQTY_NORMAL;
    setting_ptr->item_img_id[MMI_CAMCO_VISQTY_LOW] = IMG_ID_CAMCO_VISQTY_LOW;
	
#ifdef MMI_CAMCO_WALLPAPER
	setting_ptr->item_img_id[MMI_CAMCO_VISQTY_LCD] = IMG_ID_CAMCO_VISQTY_WALLPAPER;
#endif
    setting_ptr->item_cap[MMI_CAMCO_VISQTY_FINE] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_VISQTY_GOOD] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_VISQTY_NORMAL] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_VISQTY_LOW] = MMI_CAMCO_SETTING_CAP_DISABLED;
	
#ifdef MMI_CAMCO_WALLPAPER
	setting_ptr->item_cap[MMI_CAMCO_VISQTY_LCD] = MMI_CAMCO_SETTING_CAP_DISABLED;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_afmode_capability
 * DESCRIPTION
 *  default afmode capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_afmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.afmode_p = &mmi_camco_setting_p->afmode;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_AFMODE, setting_ptr);

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFMODE)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_AFMODE));        
    } 

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_AFMODE_OFF;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_afmode
 * DESCRIPTION
 *  Initialized afmode settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_afmode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->afmode, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.afmode_p = &mmi_camco_setting_p->afmode;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFMODE_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_AFMODE;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_AFMODE;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_AFMODE_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_AFMODE_SINGLE] = STR_ID_CAMCO_AFMODE_SINGLE;
    setting_ptr->item_str_id[MMI_CAMCO_AFMODE_CONT] = STR_ID_CAMCO_AFMODE_CONT;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_AFMODE_OFF] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_AFMODE_SINGLE] = IMG_ID_CAMCO_AFMODE_SINGLE;
    setting_ptr->item_img_id[MMI_CAMCO_AFMODE_CONT] = IMG_ID_CAMCO_AFMODE_CONT;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFMODE_OFF] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFMODE_SINGLE] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_AFMODE_CONT] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_afmode_capability
 * DESCRIPTION
 *  Update afmode capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_update_afmode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afmode.cap == MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        return;
    }

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_VIDEO)
    {
        if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_AFMODE) == MMI_CAMCO_AFMODE_CONT)
        {
            mmi_camco_setting_hide_capability(MMI_CAMCO_SETTING_AFRANGE);
        }
        else
        {
            mmi_camco_setting_unhide_capability(MMI_CAMCO_SETTING_AFRANGE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_recaud_capability
 * DESCRIPTION
 *  default recaud capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_recaud_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.recaud_p = &mmi_camco_setting_p->recaud;

    /* init capability */

    /* current MED only can rec mjpg video with sound */
//#ifdef MJPG_ENCODE
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
//#else 
    //setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
//#endif 
    setting_ptr->item_cap[MMI_CAMCO_RECAUD_OFF] = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_RECAUD_ON] = MMI_CAMCO_SETTING_CAP_ENABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    if (setting_ptr->cur_value == 0xff ||
        setting_ptr->item_cap[setting_ptr->cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        setting_ptr->cur_value = MMI_CAMCO_RECAUD_ON;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_recaud
 * DESCRIPTION
 *  Initialized recaud settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_recaud(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->recaud, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.recaud_p = &mmi_camco_setting_p->recaud;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_RECAUD_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_RECAUD;   
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_RECAUD;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_RECAUD_OFF] = STR_GLOBAL_OFF;
    setting_ptr->item_str_id[MMI_CAMCO_RECAUD_ON] = STR_ID_CAMCO_RECAUD_ON;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_RECAUD_OFF] = IMG_ID_CAMCO_RECAUD_OFF;
    setting_ptr->item_img_id[MMI_CAMCO_RECAUD_ON] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_viscodec_capability
 * DESCRIPTION
 *  default viscodec capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_viscodec_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;
    mdi_video_rec_spec_struct spec_entry_struct;
    U32 i;
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.viscodec_p = &mmi_camco_setting_p->viscodec;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_VISCODEC_MP4] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VISCODEC_3GP] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_VISCODEC_MJPG] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;   
    setting_ptr->item_cap[MMI_CAMCO_VISCODEC_H264] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;       

    /* get capability */
    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        switch (spec_entry_struct.video_format)
        {
            case MDI_VIDEO_VIDEO_FORMAT_3GP:
                setting_ptr->item_cap[MMI_CAMCO_VISCODEC_3GP] = MMI_CAMCO_SETTING_CAP_ENABLED;             
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MP4:
                setting_ptr->item_cap[MMI_CAMCO_VISCODEC_MP4] = MMI_CAMCO_SETTING_CAP_ENABLED;            
                break;    
            case MDI_VIDEO_VIDEO_FORMAT_MJPEG:
                setting_ptr->item_cap[MMI_CAMCO_VISCODEC_MJPG] = MMI_CAMCO_SETTING_CAP_ENABLED;  
                break;                   
            case MDI_VIDEO_VIDEO_FORMAT_H264:
                setting_ptr->item_cap[MMI_CAMCO_VISCODEC_H264] = MMI_CAMCO_SETTING_CAP_ENABLED;                       
                break;                
        }
    }

    if(recorder_config_is_depended(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VISCODEC)))
    {
        setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DISABLED;
        mmi_camco_custom_set_depended_setting(mmi_camco_custom_target_translate_from_mmi(MMI_CAMCO_SETTING_VISCODEC));        
    }
   /* else
    {
        if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][g_mmi_camco_setting_cntx.visqty.cur_value] || g_mmi_camco_setting_cntx.viscodec.cur_value == 0xFF)
        {
            S32 idx;
            
            for (idx = MMI_CAMCO_VISCODEC_END - 1; idx >= 0; idx--)
            {
                if (mmi_camco_recsize_vs_codec_vs_qty[mmi_camco_setting_p->recsize.cur_value][idx][mmi_camco_setting_p->visqty.cur_value])
                {
                    mmi_camco_setting_p->viscodec.cur_value = idx;
                    break;
                }
            }
        }
    }
    
    for(i = 0; i<MMI_CAMCO_VISCODEC_END; i++)
    {
        if(mmi_camco_setting_p->viscodec.item_cap[i] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(!mmi_camco_recsize_vs_codec_vs_qty[mmi_camco_setting_p->recsize.cur_value][i][mmi_camco_setting_p->visqty.cur_value])
            {
                mmi_camco_setting_p->viscodec.item_cap[i] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
            else
            {
                mmi_camco_setting_p->viscodec.item_cap[i] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }            
        }
    }*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_viscodec
 * DESCRIPTION
 *  Initialized viscodec settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_viscodec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->viscodec, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->video.viscodec_p = &mmi_camco_setting_p->viscodec;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_VISCODEC_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_VISCODEC;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_VISCODEC;
    setting_ptr->is_show_radio = MMI_TRUE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_VISCODEC_MP4] = STR_ID_CAMCO_VISCODEC_MP4;
    setting_ptr->item_str_id[MMI_CAMCO_VISCODEC_3GP] = STR_ID_CAMCO_VISCODEC_3GP;
    setting_ptr->item_str_id[MMI_CAMCO_VISCODEC_MJPG] = STR_ID_CAMCO_VISCODEC_MJPG;        
    setting_ptr->item_str_id[MMI_CAMCO_VISCODEC_H264] = STR_ID_CAMCO_VISCODEC_H264;    

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_VISCODEC_MP4] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VISCODEC_3GP] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_VISCODEC_MJPG] = 0;        
    setting_ptr->item_img_id[MMI_CAMCO_VISCODEC_H264] = 0;        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_viscodec_capability
 * DESCRIPTION
 *  Update viscodec capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_update_viscodec_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
    if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][g_mmi_camco_setting_cntx.visqty.cur_value] || g_mmi_camco_setting_cntx.viscodec.cur_value == 0xFF)
    {
        S32 idx;
			
        for (idx = MMI_CAMCO_VISCODEC_END - 1; idx >= 0; idx--)
        {
            if (mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][idx][mmi_camco_setting_p->visqty.cur_value])
	        {
				mmi_camco_setting_p->viscodec.cur_value = idx;
				break;
			}
		}
	}
	
	for( i = 0; i<MMI_CAMCO_VISCODEC_END; i++)
	{
		if(mmi_camco_setting_p->viscodec.item_cap[i] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
		{
			if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][i][mmi_camco_setting_p->visqty.cur_value])
			{
				mmi_camco_setting_p->viscodec.item_cap[i] = MMI_CAMCO_SETTING_CAP_DISABLED;
			}
			else
			{
				mmi_camco_setting_p->viscodec.item_cap[i] = MMI_CAMCO_SETTING_CAP_ENABLED;
			}			 
		}
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_viscodec_capability
 * DESCRIPTION
 *  Update viscodec capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_viscodec_cap_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 idx1;
	S32 idx2;
	S32 idx3;
	S32 curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;
	S32 curr_recsize = mmi_camco_setting_p->recsize.cur_value;
	S32 curr_visqty = mmi_camco_setting_p->visqty.cur_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#ifdef MMI_CAMCO_WALLPAPER
    if(mmi_camco_setting_p->visqty.cur_value == MMI_CAMCO_VISQTY_LCD)
		return;
#endif
	for (idx1 = MMI_CAMCO_VISCODEC_END ; idx1 >= 0; idx1--)
	{
   
		if(mmi_camco_setting_p->viscodec.item_cap[curr_viscodec] == MMI_CAMCO_SETTING_CAP_ENABLED )
		{
			curr_recsize = mmi_camco_setting_p->recsize.cur_value;
			for (idx2 = MMI_CAMCO_RECSIZE_END; idx2 >= 0; idx2--)
			{

				if(mmi_camco_setting_p->recsize.item_cap[curr_recsize] == MMI_CAMCO_SETTING_CAP_ENABLED )

				{
					curr_visqty = mmi_camco_setting_p->visqty.cur_value;

					for(idx3 = MMI_CAMCO_VISQTY_END; idx3 >= 0; idx3--)
					{
						if(mmi_camco_setting_p->visqty.item_cap[curr_visqty]== MMI_CAMCO_SETTING_CAP_ENABLED )
						{
                        
							if (mmi_camco_recsize_vs_codec_vs_qty[curr_recsize][curr_viscodec][curr_visqty])
							{
								mmi_camco_setting_p->viscodec.cur_value = curr_viscodec;
								mmi_camco_setting_p->recsize.cur_value = curr_recsize;
								mmi_camco_setting_p->visqty.cur_value = curr_visqty;
								return;
							}
						}
						curr_visqty = idx3-1;
					}
			  
				}
				curr_recsize = idx2 -1;

			}
		}
   
		curr_viscodec = idx1-1;

	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_codecsize_cap_value
 * DESCRIPTION
 *  Update codecsize capability value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_codecsize_cap_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 idx1;
	S32 idx2;
	S32 idx3;
	S32 curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;
	S32 curr_recsize = mmi_camco_setting_p->recsize.cur_value;
	S32 curr_visqty = mmi_camco_setting_p->visqty.cur_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#ifdef MMI_CAMCO_WALLPAPER
	if(mmi_camco_setting_p->visqty.cur_value == MMI_CAMCO_VISQTY_LCD)
		return;
#endif
	if(mmi_camco_is_from_external())
    {
	    for (idx1 = 0 ; idx1 <= MMI_CAMCO_RECSIZE_END; idx1++)
        {
   
             if(mmi_camco_setting_p->recsize.item_cap[curr_recsize] == MMI_CAMCO_SETTING_CAP_ENABLED )
	        {
		        curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;
		        for (idx2 = MMI_CAMCO_VISCODEC_END; idx2 >= 0; idx2--)
		        {

			        if(mmi_camco_setting_p->viscodec.item_cap[curr_viscodec] == MMI_CAMCO_SETTING_CAP_ENABLED )

			        {
						curr_visqty = mmi_camco_setting_p->visqty.cur_value;

			            for(idx3 = MMI_CAMCO_VISQTY_END; idx3 >= 0; idx3--)
			            {
					        if(mmi_camco_setting_p->visqty.item_cap[curr_visqty]== MMI_CAMCO_SETTING_CAP_ENABLED )
					        {

						        if (mmi_camco_recsize_vs_codec_vs_qty[curr_recsize][curr_viscodec][curr_visqty])
						        {
							        mmi_camco_setting_p->viscodec.cur_value = curr_viscodec;
								    mmi_camco_setting_p->recsize.cur_value = curr_recsize;
								    mmi_camco_setting_p->visqty.cur_value = curr_visqty;
							        return;
						        }
					        }
					        curr_visqty = idx3-1;
			            }
			  
			        }
			         curr_viscodec = idx2-1;

		        }
	        }
   
            curr_recsize = idx1;

        }
    }
	else
    {
        for (idx1 = MMI_CAMCO_RECSIZE_END ; idx1 >= 0; idx1--)
  
        {
             if(mmi_camco_setting_p->recsize.item_cap[curr_recsize] == MMI_CAMCO_SETTING_CAP_ENABLED )
	        {
		        curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;
		        for (idx2 = MMI_CAMCO_VISCODEC_END; idx2 >= 0; idx2--)
		        {

			        if(mmi_camco_setting_p->viscodec.item_cap[curr_viscodec] == MMI_CAMCO_SETTING_CAP_ENABLED )

			        {
						curr_visqty = mmi_camco_setting_p->visqty.cur_value;

			            for(idx3 = MMI_CAMCO_VISQTY_END; idx3 >= 0; idx3--)
			            {
					        if(mmi_camco_setting_p->visqty.item_cap[curr_visqty]== MMI_CAMCO_SETTING_CAP_ENABLED )
					        {

						        if (mmi_camco_recsize_vs_codec_vs_qty[curr_recsize][curr_viscodec][curr_visqty] == MMI_TRUE)
						        {
							        mmi_camco_setting_p->viscodec.cur_value = curr_viscodec;
								    mmi_camco_setting_p->recsize.cur_value = curr_recsize;
								    mmi_camco_setting_p->visqty.cur_value = curr_visqty;
							        return;
						        }
					        }
					        curr_visqty = idx3-1;
			            }
			  
			        }
			        curr_viscodec = idx2-1;

		        }
	        }
   
            curr_recsize = idx1-1;

        }
  }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_visqty_cap_value
 * DESCRIPTION
 *  Update visqty cap value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_update_visqty_cap_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 idx1;
	S32 idx2;
	S32 idx3;
	S32 curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;
	S32 curr_recsize = mmi_camco_setting_p->recsize.cur_value;
	S32 curr_visqty = mmi_camco_setting_p->visqty.cur_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#ifdef MMI_CAMCO_WALLPAPER
    if(mmi_camco_setting_p->visqty.cur_value == MMI_CAMCO_VISQTY_LCD)
		return;
#endif
	for (idx1 = MMI_CAMCO_VISQTY_END ; idx1 >= 0; idx1--)
	{
	   
	   if(mmi_camco_setting_p->visqty.item_cap[curr_visqty] == MMI_CAMCO_SETTING_CAP_ENABLED )
		{

			curr_viscodec = mmi_camco_setting_p->viscodec.cur_value;

			for (idx2 = MMI_CAMCO_VISCODEC_END; idx2 >= 0; idx2--)
			{
	
				if(mmi_camco_setting_p->viscodec.item_cap[curr_viscodec] == MMI_CAMCO_SETTING_CAP_ENABLED )
	
				{
					curr_recsize = mmi_camco_setting_p->recsize.cur_value;
					for(idx3 = MMI_CAMCO_RECSIZE_END; idx3 >= 0; idx3--)
					{
						if(mmi_camco_setting_p->recsize.item_cap[curr_recsize]== MMI_CAMCO_SETTING_CAP_ENABLED )
						{
	
							if (mmi_camco_recsize_vs_codec_vs_qty[curr_recsize][curr_viscodec][curr_visqty] == MMI_TRUE)
							   {

   							        mmi_camco_setting_p->viscodec.cur_value = curr_viscodec;
								    mmi_camco_setting_p->recsize.cur_value = curr_recsize;
								    mmi_camco_setting_p->visqty.cur_value = curr_visqty;
									return;
							   }
						}	
						curr_recsize  = idx3 - 1;	
					}
				  
				}
				curr_viscodec  = idx2 - 1;
			}
		}
		curr_visqty = idx1 - 1;
	
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_get_last_viscodec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_camco_viscodec_enum mmi_camco_get_last_viscodec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->last_viscodec;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_last_viscodec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  viscodec        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_set_last_viscodec(mmi_camco_viscodec_enum viscodec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_misc_capability
 * DESCRIPTION
 *  default misc capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_misc_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->video.misc_p = &mmi_camco_setting_p->misc;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_misc
 * DESCRIPTION
 *  Initialized misc settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_misc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->misc, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.misc_p = &mmi_camco_setting_p->misc;

    /* shared with video */
    mmi_camco_setting_p->video.misc_p = &mmi_camco_setting_p->misc;

    /* init main str/img id */
    
    #ifdef __MMI_CAMCORDER_SLIM__
       setting_ptr->main_img_id = IMG_ID_CAMCO_MISC_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_MISC;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_MISC;
    setting_ptr->is_show_radio = MMI_FALSE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_restoredefault_capability
 * DESCRIPTION
 *  default recaud capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_restoredefault_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = mmi_camco_setting_p->camera.restoredefault_p = &mmi_camco_setting_p->restoredefault;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    setting_ptr->item_cap[MMI_CAMCO_RESTOREDEFAULT_NO] = MMI_CAMCO_SETTING_CAP_DISABLED;
    setting_ptr->item_cap[MMI_CAMCO_RESTOREDEFAULT_YES] = MMI_CAMCO_SETTING_CAP_DISABLED;

    /* if setting is un-intied or driver not enabled reset to default */
    setting_ptr->cur_value = MMI_CAMCO_RESTOREDEFAULT_YES;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_restoredefault
 * DESCRIPTION
 *  Initialized misc settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_restoredefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&mmi_camco_setting_p->restoredefault, 0, sizeof(mmi_camco_setting_struct));
    setting_ptr = mmi_camco_setting_p->camera.restoredefault_p = &mmi_camco_setting_p->restoredefault;

    /* shared with video */
    mmi_camco_setting_p->video.restoredefault_p = &mmi_camco_setting_p->restoredefault;

    /* init main str/img id */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_DEFAULT_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_DEFAULT;  
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_DEFAULT;
    setting_ptr->is_show_radio = MMI_FALSE;
    setting_ptr->is_hilite_mod = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_RESTOREDEFAULT_NO] = STR_GLOBAL_NO;
    setting_ptr->item_str_id[MMI_CAMCO_RESTOREDEFAULT_YES] = STR_GLOBAL_YES;

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_RESTOREDEFAULT_NO] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_RESTOREDEFAULT_YES] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_camev_capability
 * DESCRIPTION
 *  default camev capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_camev_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->camev;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P4] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P3] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P1] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_0] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N1] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N3] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N4] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_CAMEV, setting_ptr);

    /* default value */
    setting_ptr->cur_value = MMI_CAMCO_EV_0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_camev
 * DESCRIPTION
 *  Initialized camev settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_camev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->camev;

    /* not used */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_EV_SETTING_SEL;
    #else
        setting_ptr->main_img_id = IMG_ID_CAMCO_EV_SETTING;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_EV;
    setting_ptr->is_show_radio = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_EV_P4] = STR_ID_CAMCO_EVP4;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P3] = STR_ID_CAMCO_EVP3;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P2] = STR_ID_CAMCO_EVP2;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P1] = STR_ID_CAMCO_EVP1;
    setting_ptr->item_str_id[MMI_CAMCO_EV_0] = STR_ID_CAMCO_EVZ0;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N1] = STR_ID_CAMCO_EVN1;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N2] = STR_ID_CAMCO_EVN2;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N3] = STR_ID_CAMCO_EVN3;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N4] = STR_ID_CAMCO_EVN4;    

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_EV_P4] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P3] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P2] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P1] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_0] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N1] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N2] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N3] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N4] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_vdoev_capability
 * DESCRIPTION
 *  default vdoev capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_vdoev_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->vdoev;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P4] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P3] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_P1] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_0] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N1] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N2] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N3] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
    setting_ptr->item_cap[MMI_CAMCO_EV_N4] = MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;

    /* get capability */
    mmi_camco_setting_get_capbility(MMI_CAMCO_SETTING_VDOEV, setting_ptr);

    /* default value */
    setting_ptr->cur_value = MMI_CAMCO_EV_0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_init_vdoev
 * DESCRIPTION
 *  Initialized vdoev settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_init_vdoev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *setting_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->vdoev;

    /* not used */
    #ifdef __MMI_CAMCORDER_SLIM__
        setting_ptr->main_img_id = IMG_ID_CAMCO_EV_SETTING_SEL;
    #else    
        setting_ptr->main_img_id = IMG_ID_CAMCO_EV_SETTING;
    #endif
    setting_ptr->main_str_id = STR_ID_CAMCO_EV;
    setting_ptr->is_show_radio = MMI_FALSE;

    /* init item str id */
    setting_ptr->item_str_id[MMI_CAMCO_EV_P4] = STR_ID_CAMCO_EVP4;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P3] = STR_ID_CAMCO_EVP3;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P2] = STR_ID_CAMCO_EVP2;
    setting_ptr->item_str_id[MMI_CAMCO_EV_P1] = STR_ID_CAMCO_EVP1;
    setting_ptr->item_str_id[MMI_CAMCO_EV_0] = STR_ID_CAMCO_EVZ0;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N1] = STR_ID_CAMCO_EVN1;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N2] = STR_ID_CAMCO_EVN2;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N3] = STR_ID_CAMCO_EVN3;
    setting_ptr->item_str_id[MMI_CAMCO_EV_N4] = STR_ID_CAMCO_EVN4;       

    /* init item img id */
    setting_ptr->item_img_id[MMI_CAMCO_EV_P4] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P3] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P2] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_P1] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_0] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N1] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N2] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N3] = 0;
    setting_ptr->item_img_id[MMI_CAMCO_EV_N4] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_switch_ev_capability
 * DESCRIPTION
 *  Switch ev capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_switch_ev_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_camco_setting_app_enum switchto_app = mmi_camco_setting_p->active_app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (switchto_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_p->camev.cur_value = mmi_camco_setting_p->vdoev.cur_value;
    }
    else
    {
        mmi_camco_setting_p->vdoev.cur_value = mmi_camco_setting_p->camev.cur_value;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_camzoom_capability
 * DESCRIPTION
 *  default camzoom capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_camzoom_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_zoom_struct *setting_ptr;
    mmi_camco_zoom_info zoom_info;
    U16 image_width, image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->camzoom;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    mmi_camco_set_camera_id(mmi_camco_setting_p->active_cam);
 
    if(mmi_camco_setting_p->capsize.cur_value == 0xff)
        mmi_camco_default_capsize_capability(); 

    mmi_camco_get_cmd_capsize(&image_width, &image_height);
    mdi_camera_update_para_image_size(image_width, image_height);    
    mdi_camera_query_zoom_info(&zoom_info);

    setting_ptr->max_value = zoom_info.max_zoom_factor;
    setting_ptr->min_value = 100;
    
    /* default value */
    setting_ptr->cur_value = setting_ptr->min_value;
    setting_ptr->max_step = zoom_info.zoom_steps;
    setting_ptr->min_step = 0; 
    setting_ptr->cur_step = setting_ptr->min_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camzoom_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  zoom_max                [OUT]       
 *  zoom_min                [OUT]       
 *  zoom_step               [OUT]       
 *  zoom_level_count        [OUT]       
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_camzoom_info(U16 *zoom_max, U16 *zoom_min, U16 *zoom_step, U16 *zoom_level_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*zoom_min) = mmi_camco_setting_p->camzoom.min_step;
    (*zoom_max) = mmi_camco_setting_p->camzoom.max_step;
    (*zoom_step) = 1;
    (*zoom_level_count) = (*zoom_max) - (*zoom_min) + 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_default_vdozoom_capability
 * DESCRIPTION
 *  default vdozoom capability.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_default_vdozoom_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_zoom_struct *setting_ptr;
    mmi_camco_zoom_info zoom_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_ptr = &mmi_camco_setting_p->vdozoom;

    /* init capability */
    setting_ptr->cap = MMI_CAMCO_SETTING_CAP_ENABLED;
    mmi_camco_set_camera_id(mmi_camco_setting_p->active_cam);

    mdi_video_rec_query_zoom_info(&zoom_info);

    /* default value */
    setting_ptr->min_value = 100;
    setting_ptr->max_value = zoom_info.max_zoom_factor;
    setting_ptr->cur_value = setting_ptr->min_value;
    setting_ptr->max_step = zoom_info.zoom_steps;
    setting_ptr->min_step = 0; 
    setting_ptr->cur_step = setting_ptr->min_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdozoom_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  zoom_max                [OUT]       
 *  zoom_min                [OUT]       
 *  zoom_step               [OUT]       
 *  zoom_level_count        [OUT]       
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_vdozoom_info(U16 *zoom_max, U16 *zoom_min, U16 *zoom_step, U16 *zoom_level_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*zoom_min) = mmi_camco_setting_p->vdozoom.min_step;
    (*zoom_max) = mmi_camco_setting_p->vdozoom.max_step;
    (*zoom_step) = 1;
    (*zoom_level_count) = (*zoom_max) - (*zoom_min) + 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_max_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 mmi_camco_setting_get_max_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_step;
    /*----------------------------------------------------------------*/
    /* Macro                                                          */
    /*----------------------------------------------------------------*/	
	max_step = 0;
	
    if (MMI_CAMCO_SETTING_APP_CAMERA == mmi_camco_setting_p->active_app)
    {
        max_step = mmi_camco_setting_p->camzoom.max_step;
    }
    else if (MMI_CAMCO_SETTING_APP_VIDEO == mmi_camco_setting_p->active_app)
    {
        max_step = mmi_camco_setting_p->vdozoom.max_step;
    }  
	return max_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_camera_mainlist
 * DESCRIPTION
 *  Generate camera's mainlist
 * PARAMETERS
 *  type        [IN]        PRIMARY or SECONDARY type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_gen_camera_mainlist(mmi_camco_setting_mainlist_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Macro                                                          */
    /*----------------------------------------------------------------*/
#define ADD_TO_CAMERA_MAIN_LIST_MACRO(__X__,__x__)                                      \
    if (mmi_camco_setting_p->camera.##__x__##_p->cap == MMI_CAMCO_SETTING_CAP_ENABLED)  \
    {                                                                                   \
        mmi_camco_setting_p->mainlist[i] = MMI_CAMCO_SETTING_##__X__##;                 \
        mmi_camco_setting_p->mainlist_data_ptr[i] = &mmi_camco_setting_p->##__x__##;    \
        mmi_camco_setting_p->##__x__##.is_hilite_mod = MMI_FALSE;                       \
        i++;                                                                            \
    }
#define ADD_TO_CAMERA_MAIN_EV_MACRO(__X__,__x__)                                      \
    if (mmi_camco_setting_p->##__x__##.cap == MMI_CAMCO_SETTING_CAP_ENABLED)  \
    {                                                                                   \
        mmi_camco_setting_p->mainlist[i] = MMI_CAMCO_SETTING_##__X__##;                 \
        mmi_camco_setting_p->mainlist_data_ptr[i] = &mmi_camco_setting_p->##__x__##;    \
        mmi_camco_setting_p->##__x__##.is_hilite_mod = MMI_FALSE;                       \
        i++;                                                                            \
    }    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init */
    for (i = 0; i < MMI_CAMCO_SETTING_END; i++)
    {
        mmi_camco_setting_p->mainlist[i] =(mmi_camco_setting_enum) MMI_CAMCO_SETTING_NULL;
    }

    mmi_camco_setting_p->mainlist_type = type;

    if (MMI_CAMCO_SETTING_MAINLIST_PRIMARY == mmi_camco_setting_p->mainlist_type)
    {
        MMI_CAMCO_DEBUG_PRINT(L"###### GEN [CAMERA] main list ######\n");

        /* setup main list */
        i = 0;
        ADD_TO_CAMERA_MAIN_EV_MACRO(CAMEV, camev);        
    #ifndef __MMI_CAMCO_FTE__        
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAMSWITCHTO, camswitchto);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAPMODE, capmode);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAMSCENEMODE, camscenemode);
    #endif 
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAPSIZE, capsize);
    #ifndef __MMI_CAMCO_FTE__
        ADD_TO_CAMERA_MAIN_LIST_MACRO(FLASH, flash);
    #endif 
        ADD_TO_CAMERA_MAIN_LIST_MACRO(HIGHLIGHT, highlight);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(AFRANGE, afrange);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(FACEDETECT, facedetect);
    #ifndef __MMI_CAMCO_FTE__
        ADD_TO_CAMERA_MAIN_LIST_MACRO(SELFTIMER, selftimer);
    #else /* __MMI_CAMCO_FTE__ */ 
    #ifndef MMI_CAMCO_SUPPORT_FLASH
        if(mmi_camco_setting_flash_is_enable())
             ADD_TO_CAMERA_MAIN_LIST_MACRO(SELFTIMER, selftimer);     
    #else   
         ADD_TO_CAMERA_MAIN_LIST_MACRO(SELFTIMER, selftimer);       
    #endif            
    #endif /* __MMI_CAMCO_FTE__ */ 
        ADD_TO_CAMERA_MAIN_LIST_MACRO(ISO, iso);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(WB, wb);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(EFFECT, effect);
    #ifndef __MMI_CAMCO_FTE__
        ADD_TO_CAMERA_MAIN_LIST_MACRO(MISC, misc);
    #endif 

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_SECONDARY == mmi_camco_setting_p->mainlist_type)
    {
        MMI_CAMCO_DEBUG_PRINT(L"###### GEN [CAMERA] misc list ######\n");

        /* setup misc list */
        i = 0;
        ADD_TO_CAMERA_MAIN_LIST_MACRO(STORAGE, storage);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAPQTY, capqty);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(AFZONE, afzone);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(AEMETER, aemeter);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(SHARPNESS, sharpness);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CONTRAST, contrast);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(SATURATION, saturation);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(TIMESTAMP, timestamp);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(SHUTTERSOUND, shuttersound);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(BANDING, banding);
        ADD_TO_CAMERA_MAIN_LIST_MACRO(RESTOREDEFAULT, restoredefault);

        mmi_camco_setting_p->cur_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_SCN_ONLY == mmi_camco_setting_p->mainlist_type)
    {
        i = 0;
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAMSCENEMODE, camscenemode);

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_FLASH_ONLY == mmi_camco_setting_p->mainlist_type)
    {
        i = 0;
        ADD_TO_CAMERA_MAIN_LIST_MACRO(FLASH, flash);

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_TIMER_ONLY == mmi_camco_setting_p->mainlist_type)
    {
        i = 0;
        ADD_TO_CAMERA_MAIN_LIST_MACRO(SELFTIMER, selftimer);

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_CAPMODE_ONLY == mmi_camco_setting_p->mainlist_type)
    {
        i = 0;
        ADD_TO_CAMERA_MAIN_LIST_MACRO(CAPMODE, capmode);

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }    
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_camera_itemlist
 * DESCRIPTION
 *  Generate camera's itemlist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_gen_camera_itemlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(__X__,__x__)                                                     \
    case MMI_CAMCO_SETTING_##__X__##:                                                                       \
    {                                                                                                       \
        i = 0;                                                                                              \
        for (j = 0; j < MMI_CAMCO_##__X__##_END; j++)                                                       \
        {                                                                                                   \
            if (mmi_camco_setting_p->camera.##__x__##_p->item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)      \
            {                                                                                               \
                mmi_camco_setting_p->itemlist[i] = j;                                                       \
                if (mmi_camco_setting_p->camera.##__x__##_p->cur_value == j)                                \
                {                                                                                           \
                    mmi_camco_setting_p->cur_item_idx = i;                                                  \
                }                                                                                           \
                i++;                                                                                        \
            }                                                                                               \
        }                                                                                                   \
        mmi_camco_setting_p->cur_item_count = i;                                                            \
        break;                                                                                              \
    }

    /*
     *   [Example]
     *   ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAPSIZE,capsize);
     *
     *   case MMI_CAMCO_SETTING_CAPSIZE 
     *   {                                        
     *       i = 0;                               
     *
     *       // for each setting items
     *       for (j = 0; j < MMI_CAMCO_CAPSIZE_END; j++)   
     *       {                        
     *           if (mmi_camco_setting_p->camera.capsize_p->item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)         
     *           { 
     *               // if this item is enabled, we will add it to itemlist; 
     *               mmi_camco_setting_p->itemlist[i++] = j;     
     *
     *               // if this item is current value, we highlight this 
     *               if (mmi_camco_setting_p->camera.capsize_p->cur_value == j)  
     *               {
     *                   mmi_camco_setting_p->cur_item_idx = i; 
     *               }   
     *
     *               i++;                           
     *           } 
     *       }  
     *       mmi_camco_setting_p->cur_item_count = i; 
     *       break;  
     *   }
     */
#define ADD_TO_CAMERA_ITEM_EV_CASE_MACRO(__X__,__Y__,__x__)                                                     \
    case MMI_CAMCO_SETTING_##__X__##:                                                                       \
    {                                                                                                       \
        i = 0;                                                                                              \
        for (j = 0; j < MMI_CAMCO_##__Y__##_END; j++)                                                       \
        {                                                                                                   \
            if (mmi_camco_setting_p->##__x__##.item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)      \
            {                                                                                               \
                mmi_camco_setting_p->itemlist[i] = j;                                                       \
                if (mmi_camco_setting_p->##__x__##.cur_value == j)                                \
                {                                                                                           \
                    mmi_camco_setting_p->cur_item_idx = i;                                                  \
                }                                                                                           \
                i++;                                                                                        \
            }                                                                                               \
        }                                                                                                   \
        mmi_camco_setting_p->cur_item_count = i;                                                            \
        break;                                                                                              \
    }

    /* init */
    for (i = 0; i < MMI_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        mmi_camco_setting_p->itemlist[i] = MMI_CAMCO_SETTING_NULL;
    }

    mmi_camco_setting_p->cur_item_setting = 0;
    mmi_camco_setting_p->cur_item_idx = 0;
    mmi_camco_setting_p->cur_item_count = 0;

    /* set item list */
    switch (mmi_camco_setting_p->cur_main_setting)
    {
            /* primary */
            ADD_TO_CAMERA_ITEM_EV_CASE_MACRO(CAMEV, EV, camev);        
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAMSWITCHTO, camswitchto);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAPMODE, capmode);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAMSCENEMODE, camscenemode);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAPSIZE, capsize);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(FLASH, flash);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(HIGHLIGHT, highlight);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(AFRANGE, afrange);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(FACEDETECT, facedetect);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(SELFTIMER, selftimer);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(ISO, iso);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(WB, wb);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(EFFECT, effect);
    #ifndef __MMI_CAMCO_FTE__
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(MISC, misc);
    #endif 

            /* misc */
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(STORAGE, storage);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CAPQTY, capqty);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(AFZONE, afzone);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(AEMETER, aemeter);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(SHARPNESS, sharpness);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(CONTRAST, contrast);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(SATURATION, saturation);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(TIMESTAMP, timestamp);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(SHUTTERSOUND, shuttersound);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(BANDING, banding);
            ADD_TO_CAMERA_ITEM_LIST_CASE_MACRO(RESTOREDEFAULT, restoredefault);

        default:
            MMI_ASSERT(0);
    }

    mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_video_mainlist
 * DESCRIPTION
 *  Generate video's mainlist
 * PARAMETERS
 *  type        [IN]        PRIMARY or SECONDARY type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_gen_video_mainlist(mmi_camco_setting_mainlist_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Macro                                                          */
    /*----------------------------------------------------------------*/
#define ADD_TO_VIDEO_MAIN_LIST_MACRO(__X__,__x__)                                      \
    if (mmi_camco_setting_p->video.##__x__##_p->cap == MMI_CAMCO_SETTING_CAP_ENABLED)  \
    {                                                                                  \
        mmi_camco_setting_p->mainlist[i] = MMI_CAMCO_SETTING_##__X__##;                \
        mmi_camco_setting_p->mainlist_data_ptr[i] = &mmi_camco_setting_p->##__x__##;   \
        mmi_camco_setting_p->##__x__##.is_hilite_mod = MMI_FALSE;                      \
        i++;                                                                           \
    }
#define ADD_TO_VIDEO_MAIN_EV_MACRO(__X__,__x__)                                      \
    if (mmi_camco_setting_p->##__x__##.cap == MMI_CAMCO_SETTING_CAP_ENABLED)  \
    {                                                                                  \
        mmi_camco_setting_p->mainlist[i] = MMI_CAMCO_SETTING_##__X__##;                \
        mmi_camco_setting_p->mainlist_data_ptr[i] = &mmi_camco_setting_p->##__x__##;   \
        mmi_camco_setting_p->##__x__##.is_hilite_mod = MMI_FALSE;                      \
        i++;                                                                           \
    }    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init */
    for (i = 0; i < MMI_CAMCO_SETTING_END; i++)
    {
        mmi_camco_setting_p->mainlist[i] = (mmi_camco_setting_enum)MMI_CAMCO_SETTING_NULL;
    }

    mmi_camco_setting_p->mainlist_type = type;

    if (MMI_CAMCO_SETTING_MAINLIST_PRIMARY == mmi_camco_setting_p->mainlist_type)
    {
        MMI_CAMCO_DEBUG_PRINT(L"###### GEN [VIDEO] main list ######\n");

        /* setup main list */
        i = 0;
        ADD_TO_VIDEO_MAIN_EV_MACRO(VDOEV, vdoev);
    #ifndef __MMI_CAMCO_FTE__    
        ADD_TO_VIDEO_MAIN_LIST_MACRO(VDOSWITCHTO, vdoswitchto);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(VDOSCENEMODE, vdoscenemode);
    #endif 
        ADD_TO_VIDEO_MAIN_LIST_MACRO(RECSIZE, recsize);
	    ADD_TO_VIDEO_MAIN_LIST_MACRO(TIMELAPS, timelaps);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(HIGHLIGHT, highlight);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(AFRANGE, afrange);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(WB, wb);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(EFFECT, effect);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(SIZELIMIT, sizelimit);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(TIMELIMIT, timelimit);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(LIMIT, limit);
    #ifndef __MMI_CAMCO_FTE__        
        ADD_TO_VIDEO_MAIN_LIST_MACRO(MISC, misc);
    #endif /* __MMI_CAMCO_FTE__ */ 

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;

    }
    else if (MMI_CAMCO_SETTING_MAINLIST_SECONDARY == mmi_camco_setting_p->mainlist_type)
    {
        MMI_CAMCO_DEBUG_PRINT(L"###### GEN [VIDEO] misc list ######\n");

        /* setup misc list */
        i = 0;
        ADD_TO_VIDEO_MAIN_LIST_MACRO(STORAGE, storage);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(VISQTY, visqty);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(VISCODEC, viscodec);        
        ADD_TO_VIDEO_MAIN_LIST_MACRO(AFMODE, afmode);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(SHARPNESS, sharpness);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(CONTRAST, contrast);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(SATURATION, saturation);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(RECAUD, recaud);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(BANDING, banding);
        ADD_TO_VIDEO_MAIN_LIST_MACRO(RESTOREDEFAULT, restoredefault);

        mmi_camco_setting_p->cur_main_count = i;
    }
    else if (MMI_CAMCO_SETTING_MAINLIST_SCN_ONLY == mmi_camco_setting_p->mainlist_type)
    {
        i = 0;
        ADD_TO_VIDEO_MAIN_LIST_MACRO(VDOSCENEMODE, vdoscenemode);

        mmi_camco_setting_p->cur_main_count = i;
        mmi_camco_setting_p->primary_main_count = i;
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_video_itemlist
 * DESCRIPTION
 *  Generate video's itemlist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_gen_video_itemlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(__X__,__x__)                                                      \
    case MMI_CAMCO_SETTING_##__X__##:                                                                       \
    {                                                                                                       \
        i = 0;                                                                                              \
        for (j = 0; j < MMI_CAMCO_##__X__##_END; j++)                                                       \
        {                                                                                                   \
            if (mmi_camco_setting_p->video.##__x__##_p->item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)       \
            {                                                                                               \
                mmi_camco_setting_p->itemlist[i] = j;                                                       \
                if (mmi_camco_setting_p->video.##__x__##_p->cur_value == j)                                 \
                {                                                                                           \
                    mmi_camco_setting_p->cur_item_idx = i;                                                  \
                }                                                                                           \
                i++;                                                                                        \
            }                                                                                               \
        }                                                                                                   \
        mmi_camco_setting_p->cur_item_count = i;                                                            \
        break;                                                                                              \
    }

    /*
     *   [Example]
     *   ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(RECSIZE,recsize);
     *
     *   case MMI_CAMCO_SETTING_RECSIZE 
     *   {                                        
     *       i = 0;                               
     *
     *       // for each setting items
     *       for (j = 0; j < MMI_CAMCO_RECSIZE_END; j++)   
     *       {                        
     *           if (mmi_camco_setting_p->video.recsize_p->item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)         
     *           { 
     *               // if this item is enabled, we will add it to itemlist; 
     *               mmi_camco_setting_p->itemlist[i++] = j;     
     *
     *               // if this item is current value, we highlight this 
     *               if (mmi_camco_setting_p->video.recsize_p->cur_value == j)  
     *               {
     *                   mmi_camco_setting_p->cur_item_idx = i; 
     *               }   
     *
     *               i++;                           
     *           } 
     *      }  
     *      mmi_camco_setting_p->cur_item_count = i;  
     *      break;  
     *   }
     */
#define ADD_TO_VIDEO_ITEM_EV_CASE_MACRO(__X__,__Y__,__x__)                                                      \
    case MMI_CAMCO_SETTING_##__X__##:                                                                       \
    {                                                                                                       \
        i = 0;                                                                                              \
        for (j = 0; j < MMI_CAMCO_##__Y__##_END; j++)                                                       \
        {                                                                                                   \
            if (mmi_camco_setting_p->##__x__##.item_cap[j] == MMI_CAMCO_SETTING_CAP_ENABLED)       \
            {                                                                                               \
                mmi_camco_setting_p->itemlist[i] = j;                                                       \
                if (mmi_camco_setting_p->##__x__##.cur_value == j)                                 \
                {                                                                                           \
                    mmi_camco_setting_p->cur_item_idx = i;                                                  \
                }                                                                                           \
                i++;                                                                                        \
            }                                                                                               \
        }                                                                                                   \
        mmi_camco_setting_p->cur_item_count = i;                                                            \
        break;                                                                                              \
    }
    /* init */
    for (i = 0; i < MMI_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        mmi_camco_setting_p->itemlist[i] = MMI_CAMCO_SETTING_NULL;
    }

    mmi_camco_setting_p->cur_item_setting = 0;
    mmi_camco_setting_p->cur_item_idx = 0;
    mmi_camco_setting_p->cur_item_count = 0;

    /* set item list */
    switch (mmi_camco_setting_p->cur_main_setting)
    {
            ADD_TO_VIDEO_ITEM_EV_CASE_MACRO(VDOEV, EV, vdoev);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(RECSIZE, recsize);
			ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(TIMELAPS, timelaps);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(HIGHLIGHT, highlight);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(AFRANGE, afrange);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(WB, wb);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(EFFECT, effect);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(SIZELIMIT, sizelimit);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(TIMELIMIT, timelimit);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(LIMIT, limit);
    #ifndef __MMI_CAMCO_FTE__
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(MISC, misc);
    #endif 

            /* misc */
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(STORAGE, storage);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(VISQTY, visqty);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(AFMODE, afmode);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(AEMETER, aemeter);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(SHARPNESS, sharpness);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(CONTRAST, contrast);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(SATURATION, saturation);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(RECAUD, recaud);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(VISCODEC, viscodec);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(BANDING, banding);
            ADD_TO_VIDEO_ITEM_LIST_CASE_MACRO(RESTOREDEFAULT, restoredefault);

        default:
            MMI_ASSERT(0);
    }

    mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_itemlist
 * DESCRIPTION
 *  Generate itemlist, will dispatch to gen camera / video's item list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_gen_itemlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CAMCO_SETTING_APP_CAMERA == mmi_camco_setting_p->active_app)
    {
        mmi_camco_setting_gen_camera_itemlist();
    }
    else if (MMI_CAMCO_SETTING_APP_VIDEO == mmi_camco_setting_p->active_app)
    {
        mmi_camco_setting_gen_video_itemlist();
    }
    else
    {
        /* invalid app type */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_item_selected_hdlr
 * DESCRIPTION
 *  Dispatch to each settings selected handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_item_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ITEM_SELECTED_CASE_MACRO(__X__,__x__)   \
    case MMI_CAMCO_SETTING_##__X__:             \
    {                                           \
        mmi_camco_##__x__##_selected_hdlr();    \
        break;                                  \
    }

    switch (mmi_camco_setting_p->cur_main_setting)
    {
            ITEM_SELECTED_CASE_MACRO(CAMEV, camev);        
            ITEM_SELECTED_CASE_MACRO(VDOEV, vdoev);                
            ITEM_SELECTED_CASE_MACRO(CAMSWITCHTO, camswitchto);
            ITEM_SELECTED_CASE_MACRO(CAPMODE, capmode);
            ITEM_SELECTED_CASE_MACRO(CAMSCENEMODE, camscenemode);
            ITEM_SELECTED_CASE_MACRO(CAPSIZE, capsize);
            ITEM_SELECTED_CASE_MACRO(FLASH, flash);
            ITEM_SELECTED_CASE_MACRO(HIGHLIGHT, highlight);
            ITEM_SELECTED_CASE_MACRO(AFRANGE, afrange);
            ITEM_SELECTED_CASE_MACRO(FACEDETECT, facedetect);
            ITEM_SELECTED_CASE_MACRO(SELFTIMER, selftimer);
            ITEM_SELECTED_CASE_MACRO(ISO, iso);
            ITEM_SELECTED_CASE_MACRO(WB, wb);
            ITEM_SELECTED_CASE_MACRO(EFFECT, effect);
            ITEM_SELECTED_CASE_MACRO(STORAGE, storage);
            ITEM_SELECTED_CASE_MACRO(CAPQTY, capqty);
            ITEM_SELECTED_CASE_MACRO(AFZONE, afzone);
            ITEM_SELECTED_CASE_MACRO(AEMETER, aemeter);
            ITEM_SELECTED_CASE_MACRO(SHARPNESS, sharpness);
            ITEM_SELECTED_CASE_MACRO(CONTRAST, contrast);
            ITEM_SELECTED_CASE_MACRO(SATURATION, saturation);
            ITEM_SELECTED_CASE_MACRO(TIMESTAMP, timestamp);
            ITEM_SELECTED_CASE_MACRO(SHUTTERSOUND, shuttersound);
            ITEM_SELECTED_CASE_MACRO(BANDING, banding);
            ITEM_SELECTED_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
            ITEM_SELECTED_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            ITEM_SELECTED_CASE_MACRO(RECSIZE, recsize);
            ITEM_SELECTED_CASE_MACRO(SIZELIMIT, sizelimit);
            ITEM_SELECTED_CASE_MACRO(TIMELIMIT, timelimit);
            ITEM_SELECTED_CASE_MACRO(LIMIT, limit);
            ITEM_SELECTED_CASE_MACRO(VISQTY, visqty);
            ITEM_SELECTED_CASE_MACRO(AFMODE, afmode);
            ITEM_SELECTED_CASE_MACRO(RECAUD, recaud);
            ITEM_SELECTED_CASE_MACRO(VISCODEC, viscodec);
			ITEM_SELECTED_CASE_MACRO(TIMELAPS, timelaps);
    #ifndef __MMI_CAMCO_FTE__
            ITEM_SELECTED_CASE_MACRO(MISC, misc);
    #endif 
            ITEM_SELECTED_CASE_MACRO(RESTOREDEFAULT, restoredefault);
        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_item_hilite_hdlr
 * DESCRIPTION
 *  Dispatch to each settings hilite handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_item_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);
#define ITEM_HILITE_CASE_MACRO(__X__,__x__)     \
    case MMI_CAMCO_SETTING_##__X__##:           \
    {                                           \
        mmi_camco_##__x__##_hilite_hdlr();      \
        break;                                  \
    }

    switch (mmi_camco_setting_p->cur_main_setting)
    {
            ITEM_HILITE_CASE_MACRO(HIGHLIGHT, highlight);
            ITEM_HILITE_CASE_MACRO(ISO, iso);
            ITEM_HILITE_CASE_MACRO(WB, wb);
            ITEM_HILITE_CASE_MACRO(EFFECT, effect);
            ITEM_HILITE_CASE_MACRO(SHARPNESS, sharpness);
            ITEM_HILITE_CASE_MACRO(CONTRAST, contrast);
            ITEM_HILITE_CASE_MACRO(SATURATION, saturation);
            ITEM_HILITE_CASE_MACRO(SHUTTERSOUND, shuttersound);
            ITEM_HILITE_CASE_MACRO(CAMEV, camev);        
            ITEM_HILITE_CASE_MACRO(VDOEV, vdoev);                
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_default_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_default_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*set key and dependency setting */
    if(recorder_config_has_dependency())
    {
        recoorder_config_setting_set setting_set;
        U16 i;            
        //recoorder_config_setting_target target;

        mmi_camco_custom_set_key_setting();

        mmi_camco_custom_get_depended_set(&setting_set);
        for(i=0;i<setting_set.count;i++)
        {
            mmi_camco_custom_set_depended_setting(setting_set.target[i]);
        }
        mmi_camco_setting_store_to_nvram();        
        for(i=0;i<setting_set.count;i++)
        {
            mmi_camco_custom_update_depended_setting(setting_set.target[i]);            
        } 
    }
    
    mmi_camco_default_capmode_capability();
    mmi_camco_default_camswitchto_capability();
    mmi_camco_default_camscenemode_capability();
    mmi_camco_default_capsize_capability();
    mmi_camco_setting_set_default();
    mmi_camco_default_flash_capability();
    mmi_camco_default_highlight_capability();
    mmi_camco_default_afrange_capability();
    mmi_camco_default_facedetect_capability();
    mmi_camco_default_afzone_capability();
    mmi_camco_default_selftimer_capability();
    mmi_camco_default_iso_capability();
    mmi_camco_default_wb_capability();
    mmi_camco_default_effect_capability();
    mmi_camco_default_storage_capability();
    mmi_camco_default_capqty_capability();
    mmi_camco_default_sharpness_capability();
    mmi_camco_default_contrast_capability();
    mmi_camco_default_saturation_capability();
    mmi_camco_default_timestamp_capability();
    mmi_camco_default_shuttersound_capability();
    mmi_camco_default_banding_capability();
    mmi_camco_default_restoredefault_capability();
    mmi_camco_default_vdoswitchto_capability();
	mmi_camco_default_timelaps_capablility();
    mmi_camco_default_vdoscenemode_capability();
    mmi_camco_default_aemeter_capability();
    mmi_camco_default_recsize_capability();
    mmi_camco_default_sizelimit_capability();
    mmi_camco_default_timelimit_capability();
    mmi_camco_default_limit_capability();
    mmi_camco_default_visqty_capability();
    mmi_camco_default_afmode_capability();
    mmi_camco_default_recaud_capability();
    mmi_camco_default_viscodec_capability();
    mmi_camco_default_misc_capability();

    mmi_camco_setting_store_to_nvram();

    if (!mmi_camco_is_from_external() &&
        (mmi_camco_setting_get_last_active_app() == mmi_camco_setting_get_active_app()))
    {
        mmi_camco_setting_update_capability();
        mmi_camco_update_facedetect_capability();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_init
 * DESCRIPTION
 *  Init setting module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_scene_sel_load_from_nvram();

    mmi_camco_init_capmode();
    mmi_camco_init_camswitchto();
    mmi_camco_init_camscenemode();
    mmi_camco_init_capsize();
    mmi_camco_init_flash();
    mmi_camco_init_highlight();
    mmi_camco_init_afrange();
    mmi_camco_init_facedetect();
    mmi_camco_init_selftimer();
    mmi_camco_init_iso();
    mmi_camco_init_wb();
    mmi_camco_init_effect();
    mmi_camco_init_storage();
    mmi_camco_init_capqty();
    mmi_camco_init_afzone();
    mmi_camco_init_aemeter();
    mmi_camco_init_sharpness();
    mmi_camco_init_contrast();
    mmi_camco_init_saturation();
    mmi_camco_init_timestamp();
    mmi_camco_init_shuttersound();
    mmi_camco_init_banding();
    mmi_camco_init_restoredefault();
    mmi_camco_init_vdoswitchto();
	mmi_camco_init_timelaps();
    mmi_camco_init_vdoscenemode();
    mmi_camco_init_recsize();
    mmi_camco_init_sizelimit();
    mmi_camco_init_timelimit();
    mmi_camco_init_limit();
    mmi_camco_init_visqty();
    mmi_camco_init_afmode();
    mmi_camco_init_recaud();
    mmi_camco_init_viscodec();
    mmi_camco_init_misc();
    mmi_camco_init_camev();
    mmi_camco_init_vdoev();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_update_imgadjust_capability
 * DESCRIPTION
 *  Update settings capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_update_imgadjust_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->last_camscenemode = MMI_CAMCO_CAMSCENEMODE_END;
    mmi_camco_setting_p->last_vdoscenemode = MMI_CAMCO_VDOSCENEMODE_END;

    mmi_camco_update_sharpness_capability();
    mmi_camco_update_contrast_capability();
    mmi_camco_update_saturation_capability();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_update_capability
 * DESCRIPTION
 *  Update settings capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_update_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_update_flash_capability();
    mmi_camco_update_afrange_capability();
    mmi_camco_update_iso_capability();
    mmi_camco_update_sharpness_capability();
    mmi_camco_update_contrast_capability();
    mmi_camco_update_saturation_capability();
    mmi_camco_update_effect_capability();

    mmi_camco_update_capsize_capability();
    mmi_camco_update_capmode_capability();
    mmi_camco_update_limit_capability();
    mmi_camco_update_timestamp_capability();
    mmi_camco_update_afmode_capability();
    mmi_camco_update_camscenemode_capability();
    mmi_camco_setting_scene_sel_store_to_nvram();
	mmi_camco_update_timelaps_capability();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_switch_capability
 * DESCRIPTION
 *  Switch settings capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_switch_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_switch_afrange_capability();
    mmi_camco_switch_sharpness_capability();
    mmi_camco_switch_contrast_capability();
    mmi_camco_switch_saturation_capability();
    mmi_camco_switch_ev_capability();
    mmi_camco_switch_effect_capability();
    mmi_camco_switch_wb_capability();

    mmi_camco_setting_scene_sel_store_to_nvram();
    mmi_camco_setting_store_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_apply_current_scenemode_capability
 * DESCRIPTION
 *  Apply the current sensor scenemode setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_apply_current_scenemode_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scene = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        cur_scene = mmi_camco_setting_p->camera.camscenemode_p->cur_value;
        mmi_camco_setting_p->camera.afrange_p->cur_value =
            mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].afrange;
        mmi_camco_setting_p->camera.iso_p->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].iso;
        mmi_camco_setting_p->camera.flash_p->cur_value = mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].flash;
        mmi_camco_setting_p->camera.sharpness_p->cur_value =
            mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].sharpness;
        mmi_camco_setting_p->camera.contrast_p->cur_value =
            mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].contrast;
        mmi_camco_setting_p->camera.saturation_p->cur_value =
            mmi_camco_setting_scene_sel_p->camscenemode[cur_scene].saturation;
    }
    else if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_VIDEO)
    {
        cur_scene = mmi_camco_setting_p->video.vdoscenemode_p->cur_value;
        mmi_camco_setting_p->video.afrange_p->cur_value =
            mmi_camco_setting_scene_sel_p->vdoscenemode[cur_scene].afrange;
        mmi_camco_setting_p->video.sharpness_p->cur_value =
            mmi_camco_setting_scene_sel_p->vdoscenemode[cur_scene].sharpness;
        mmi_camco_setting_p->video.contrast_p->cur_value =
            mmi_camco_setting_scene_sel_p->vdoscenemode[cur_scene].contrast;
        mmi_camco_setting_p->video.saturation_p->cur_value =
            mmi_camco_setting_scene_sel_p->vdoscenemode[cur_scene].saturation;
    }

    mmi_camco_setting_update_capability();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_apply_current_sensor_capability
 * DESCRIPTION
 *  Apply the current sensor setting to another
 * PARAMETERS
 *  prev_cam        [IN]        
 *  curr_cam        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_setting_apply_current_sensor_capability(
                mmi_camco_setting_cam_enum prev_cam,
                mmi_camco_setting_cam_enum curr_cam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#ifdef DUAL_CAMERA_SUPPORT
	nvram_ef_camco_setting_struct nvram_data;
    S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DUAL_CAMERA_SUPPORT
    if (curr_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }
    else if (curr_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
    nvram_data.storage = mmi_camco_setting_p->storage.cur_value;
#ifdef __MMI_CAMCO_DUAL_CAMERA_APPLY_EACHOTHER__
    nvram_data.wb = mmi_camco_setting_p->wb.cur_value;
    nvram_data.effect = mmi_camco_setting_p->effect.cur_value;
    nvram_data.timestamp = mmi_camco_setting_p->timestamp.cur_value;
    nvram_data.banding = mmi_camco_setting_p->banding.cur_value;
    nvram_data.shuttersound = mmi_camco_setting_p->shuttersound.cur_value;
    nvram_data.capqty = mmi_camco_setting_p->capqty.cur_value;
    nvram_data.facedetect = mmi_camco_setting_p->facedetect.cur_value;

    nvram_data.limit = mmi_camco_setting_p->limit.cur_value;
    nvram_data.visqty = mmi_camco_setting_p->visqty.cur_value;
    nvram_data.viscodec = mmi_camco_setting_p->viscodec.cur_value;
#endif /* __MMI_CAMCO_DUAL_CAMERA_APPLY_EACHOTHER__ */ 
    if (curr_cam == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }
    else if (curr_cam == MMI_CAMCO_SETTING_CAM_SUB)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_gen_mainlist
 * DESCRIPTION
 *  Generate mainlist.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_gen_mainlist(mmi_camco_setting_mainlist_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CAMCO_SETTING_APP_CAMERA == mmi_camco_setting_p->active_app)
    {
        mmi_camco_setting_gen_camera_mainlist(type);
    }
    else if (MMI_CAMCO_SETTING_APP_VIDEO == mmi_camco_setting_p->active_app)
    {
        mmi_camco_setting_gen_video_mainlist(type);
    }
    else
    {
        /* invalid app type */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_type
 * DESCRIPTION
 *  Get main list type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUE
 *  MMI_CAMCO_SETTING_MAINLIST_PRIMARY
 *  MMI_CAMCO_SETTING_MAINLIST_SECONDARY
 *****************************************************************************/
mmi_camco_setting_mainlist_type_enum mmi_camco_setting_get_mainlist_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->mainlist_type != MMI_CAMCO_SETTING_MAINLIST_PRIMARY &&
        mmi_camco_setting_p->mainlist_type != MMI_CAMCO_SETTING_MAINLIST_SECONDARY)
    {
        mmi_camco_setting_p->mainlist_type = mmi_camco_setting_p->previous_full_mainlist_type;
        return mmi_camco_setting_p->previous_full_mainlist_type;
    }
    else
        return mmi_camco_setting_p->mainlist_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_mainlist_type
 * DESCRIPTION
 *  Set main list type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_mainlist_type(mmi_camco_setting_mainlist_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->mainlist_type = type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_active_cam
 * DESCRIPTION
 *  Get current active cam type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUE
 *  MMI_CAMCO_SETTING_APP_CAMERA
 *  MMI_CAMCO_SETTING_APP_VIDEO
 *****************************************************************************/
mmi_camco_setting_cam_enum mmi_camco_setting_get_active_cam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->active_cam;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_active_cam
 * DESCRIPTION
 *  Get current active cam type
 * PARAMETERS
 *  cam     [IN]        
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_active_cam(mmi_camco_setting_cam_enum cam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_app_info_struct nvram_camco_info;
    mmi_camco_setting_cam_enum prev_cam = mmi_camco_setting_p->active_cam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_CAMCO_SET_ACTIVE_CAM, cam);

    /* Before change cam id, store the relative setting to NVRAM */
    mmi_camco_setting_store_to_nvram();
    mmi_camco_setting_scene_sel_store_to_nvram();

    mmi_camco_setting_p->active_cam = cam;

    nvram_camco_info.active_app = mmi_camco_setting_p->active_app;
    nvram_camco_info.active_cam = mmi_camco_setting_p->active_cam;

    WriteRecord(
        NVRAM_EF_CAMCO_APP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_camco_info,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        &error);

    if (prev_cam != mmi_camco_setting_p->active_cam)
    {
        mmi_camco_setting_apply_current_sensor_capability(prev_cam, mmi_camco_setting_p->active_cam);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_last_active_app
 * DESCRIPTION
 *  Get current last active app type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUE
 *  MMI_CAMCO_SETTING_APP_CAMERA
 *  MMI_CAMCO_SETTING_APP_VIDEO
 *****************************************************************************/
mmi_camco_setting_app_enum mmi_camco_setting_get_last_active_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->last_active_app;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_active_app
 * DESCRIPTION
 *  Get current active app type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUE
 *  MMI_CAMCO_SETTING_APP_CAMERA
 *  MMI_CAMCO_SETTING_APP_VIDEO
 *****************************************************************************/
mmi_camco_setting_app_enum mmi_camco_setting_get_active_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->active_app;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_active_app
 * DESCRIPTION
 *  Set current active app type
 * PARAMETERS
 *  app     [IN]        App type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_active_app(mmi_camco_setting_app_enum app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->active_app != app)
    {
        mmi_camco_setting_p->active_app = app;
        mmi_camco_setting_store_to_nvram();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_idx_by_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  
 * RETURN VALUE
 *  
 *****************************************************************************/
U8 mmi_camco_setting_get_mainlist_idx_by_setting(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_camco_setting_p->cur_main_count; i++)
    {
        if (mmi_camco_setting_p->mainlist[i] == setting)
           break; 
    }
	return i;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_mainlist_idx_ex
 * DESCRIPTION
 *  Set mainlist's idx. Move current setting to this idx
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  Return true if it is a valid index, otherwise reture false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_set_mainlist_idx_ex(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(__X__,__x__)                                 \
    case MMI_CAMCO_SETTING_##__X__##:                                                       \
    {                                                                                       \
        mmi_camco_setting_p->cur_main_data_ptr = mmi_camco_setting_p->camera.##__x__##_p;   \
        break;                                                                              \
    }

#define SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(__X__,__x__)                                  \
    case MMI_CAMCO_SETTING_##__X__##:                                                       \
    {                                                                                       \
        mmi_camco_setting_p->cur_main_data_ptr = mmi_camco_setting_p->video.##__x__##_p;    \
        break;                                                                              \
    }

    while (1)
    {
        if (mmi_camco_setting_p->mainlist[idx] == setting)
            break;
        idx++;
    }

    if (idx < mmi_camco_setting_p->cur_main_count)
    {
        /* it is a valid index */
        mmi_camco_setting_p->cur_main_setting = mmi_camco_setting_p->mainlist[idx];
        mmi_camco_setting_p->cur_main_idx = idx;

        switch (mmi_camco_setting_p->cur_main_setting)
        {
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAMSWITCHTO, camswitchto);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPMODE, capmode);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAMSCENEMODE, camscenemode);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPSIZE, capsize);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(FLASH, flash);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(HIGHLIGHT, highlight);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AFRANGE, afrange);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(FACEDETECT, facedetect);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SELFTIMER, selftimer);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(ISO, iso);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(WB, wb);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(EFFECT, effect);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(STORAGE, storage);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPQTY, capqty);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AFZONE, afzone);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AEMETER, aemeter);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SHARPNESS, sharpness);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CONTRAST, contrast);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SATURATION, saturation);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(TIMESTAMP, timestamp);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SHUTTERSOUND, shuttersound);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(BANDING, banding);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(RESTOREDEFAULT, restoredefault);
                /* SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(MISC,misc); */

                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(RECSIZE, recsize);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(SIZELIMIT, sizelimit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(TIMELIMIT, timelimit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(LIMIT, limit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VISQTY, visqty);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(AFMODE, afmode);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(RECAUD, recaud);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VISCODEC, viscodec);
				SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(TIMELAPS, timelaps);
        }

        mmi_camco_setting_gen_itemlist();
        return MMI_TRUE;

    }
    else
    {
        /* wrong index */
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_mainlist_idx
 * DESCRIPTION
 *  Set mainlist's idx. Move current setting to this idx
 * PARAMETERS
 *  idx     [IN]        Idx
 * RETURNS
 *  Return true if it is a valid index, otherwise reture false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_set_mainlist_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(__X__,__x__)                                 \
    case MMI_CAMCO_SETTING_##__X__##:                                                       \
    {                                                                                       \
        mmi_camco_setting_p->cur_main_data_ptr = mmi_camco_setting_p->camera.##__x__##_p;   \
        break;                                                                              \
    }

#define SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(__X__,__x__)                                  \
    case MMI_CAMCO_SETTING_##__X__##:                                                       \
    {                                                                                       \
        mmi_camco_setting_p->cur_main_data_ptr = mmi_camco_setting_p->video.##__x__##_p;    \
        break;                                                                              \
    }

    if (idx < mmi_camco_setting_p->cur_main_count)
    {
        /* it is a valid index */
        mmi_camco_setting_p->cur_main_setting = mmi_camco_setting_p->mainlist[idx];
        mmi_camco_setting_p->cur_main_idx = idx;

        switch (mmi_camco_setting_p->cur_main_setting)
        {
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAMSWITCHTO, camswitchto);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPMODE, capmode);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAMSCENEMODE, camscenemode);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPSIZE, capsize);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(FLASH, flash);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(HIGHLIGHT, highlight);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AFRANGE, afrange);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(FACEDETECT, facedetect);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SELFTIMER, selftimer);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(ISO, iso);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(WB, wb);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(EFFECT, effect);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(STORAGE, storage);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CAPQTY, capqty);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AFZONE, afzone);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(AEMETER, aemeter);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SHARPNESS, sharpness);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(CONTRAST, contrast);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SATURATION, saturation);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(TIMESTAMP, timestamp);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(SHUTTERSOUND, shuttersound);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(BANDING, banding);
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(RESTOREDEFAULT, restoredefault);
        #ifndef __MMI_CAMCO_FTE__
                SET_CAMERA_SETTING_DATA_PTR_CASE_MACRO(MISC, misc);
        #endif 
                case MMI_CAMCO_SETTING_CAMEV:                                           
                {                                                                           
                    mmi_camco_setting_p->cur_main_data_ptr = &mmi_camco_setting_p->camev;   
                    break;                                                                  
                }
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(RECSIZE, recsize);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(SIZELIMIT, sizelimit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(TIMELIMIT, timelimit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(LIMIT, limit);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VISQTY, visqty);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(AFMODE, afmode);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(RECAUD, recaud);
                SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(VISCODEC, viscodec);
				SET_VIDEO_SETTING_DATA_PTR_CASE_MACRO(TIMELAPS, timelaps);
                case MMI_CAMCO_SETTING_VDOEV:                                           
                {                                                                           
                    mmi_camco_setting_p->cur_main_data_ptr = &mmi_camco_setting_p->vdoev;   
                    break;                                                                  
                }
        }

        mmi_camco_setting_gen_itemlist();
        return MMI_TRUE;

    }
    else
    {
        /* wrong index */
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_count
 * DESCRIPTION
 *  Get mainlist count.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mainlist count
 *****************************************************************************/
U16 mmi_camco_setting_get_mainlist_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_main_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_idx
 * DESCRIPTION
 *  Get mainlist current highlight idx.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mainlist idx
 *****************************************************************************/
U16 mmi_camco_setting_get_mainlist_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_main_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_setting
 * DESCRIPTION
 *  Get mainlist current setting enum.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mainlist idx
 *****************************************************************************/
U16 mmi_camco_setting_get_mainlist_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_main_setting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_mainlist_primary_count
 * DESCRIPTION
 *  Get mainlist primary setting count.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mainlist idx
 *****************************************************************************/
U16 mmi_camco_setting_get_mainlist_primary_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->primary_main_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_mainlist_move_next
 * DESCRIPTION
 *  Move mainlist's index to next.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true if can move next, otherwise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_mainlist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->cur_main_idx < mmi_camco_setting_p->cur_main_count - 1)
    {
        mmi_camco_setting_set_mainlist_idx(++mmi_camco_setting_p->cur_main_idx);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_mainlist_move_prev
 * DESCRIPTION
 *  Move mainlist's index to previous.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true if can move previous, otherwise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_mainlist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->cur_main_idx > 0)
    {
        mmi_camco_setting_set_mainlist_idx(--mmi_camco_setting_p->cur_main_idx);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_main_resource
 * DESCRIPTION
 *  Get mainlist's resource (img, str) via index.
 * PARAMETERS
 *  idx                 [IN]        Index
 *  str_id_ptr          [OUT]       Str ID pointer
 *  img_id_ptr          [OUT]       Img ID pointer
 *  cur_str_id_ptr      [OUT]       
 *  cur_img_id_ptr      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_main_resource(
        U16 idx,
        MMI_ID_TYPE *str_id_ptr,
        MMI_ID_TYPE *img_id_ptr,
        MMI_ID_TYPE *cur_str_id_ptr,
        MMI_ID_TYPE *cur_img_id_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *str_id_ptr = mmi_camco_setting_p->mainlist_data_ptr[idx]->main_str_id;
    *img_id_ptr = mmi_camco_setting_p->mainlist_data_ptr[idx]->main_img_id;

    if (cur_str_id_ptr)
        *cur_str_id_ptr =
            mmi_camco_setting_p->mainlist_data_ptr[idx]->item_str_id[mmi_camco_setting_p->mainlist_data_ptr[idx]->
                                                                     cur_value];
    if (cur_img_id_ptr)
        *cur_img_id_ptr =
            mmi_camco_setting_p->mainlist_data_ptr[idx]->item_img_id[mmi_camco_setting_p->mainlist_data_ptr[idx]->
                                                                     cur_value];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_cur_main_title
 * DESCRIPTION
 *  Get mainlist current selection's title
 * PARAMETERS
 *  str_id_ptr      [OUT]       Str ID pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_cur_main_title(MMI_ID_TYPE *str_id_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *str_id_ptr = mmi_camco_setting_p->cur_main_data_ptr->main_str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_is_main_show_radio
 * DESCRIPTION
 *  Is current main item show radio or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means it will show radio, other wise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_is_main_show_radio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_main_data_ptr->is_show_radio;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_itemlist_count
 * DESCRIPTION
 *  Get itemlist count
 * PARAMETERS
 *  void
 * RETURNS
 *  Itemlist count
 *****************************************************************************/
U16 mmi_camco_setting_get_itemlist_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_item_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_itemlist_idx
 * DESCRIPTION
 *  Get current itemlist index.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current item idx
 *****************************************************************************/
U16 mmi_camco_setting_get_itemlist_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->cur_item_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_itemlist_value
 * DESCRIPTION
 *  Get current itemlist index.
 * PARAMETERS
 *  idx     [IN]        [U16]
 * RETURNS
 *  Current item idx
 *****************************************************************************/
U16 mmi_camco_setting_get_itemlist_value(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->itemlist[idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_itemlist_move_next
 * DESCRIPTION
 *  Move itemlist's index selection to next
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means it can move next, otherwise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_itemlist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->cur_item_idx < mmi_camco_setting_p->cur_item_count - 1)
    {
        mmi_camco_setting_p->cur_item_idx++;
        mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
        return MMI_TRUE;
    }
    else
    {
        mmi_camco_setting_p->cur_item_idx = 0;
        mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_itemlist_move_prev
 * DESCRIPTION
 *  Move itemlist's index selection to prev
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means it can move prev, otherwise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_itemlist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->cur_item_idx > 0)
    {
        mmi_camco_setting_p->cur_item_idx--;
        mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
        return MMI_TRUE;

    }
    else
    {
        mmi_camco_setting_p->cur_item_idx = mmi_camco_setting_p->cur_item_count - 1;
        mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_itemlist_idx
 * DESCRIPTION
 *  Set itemlist index.
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  Return true means the idx is valid, otherwise return false.
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_set_itemlist_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < mmi_camco_setting_p->cur_item_count)
    {
        mmi_camco_setting_p->cur_item_idx = idx;
        mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_item_resource
 * DESCRIPTION
 *  Get item's resource
 * PARAMETERS
 *  setting_value       [IN]        Setting index
 *  str_id_ptr          [OUT]       Str ID pointer
 *  img_id_ptr          [OUT]       Img ID pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_item_resource(U16 setting_value, MMI_ID_TYPE *str_id_ptr, MMI_ID_TYPE *img_id_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *str_id_ptr = mmi_camco_setting_p->cur_main_data_ptr->item_str_id[setting_value];
    *img_id_ptr = mmi_camco_setting_p->cur_main_data_ptr->item_img_id[setting_value];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_change_capsize_setting_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  capsize     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_change_capsize_setting_value(mmi_camco_capsize_enum capsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->capsize.cur_value = capsize;
    mmi_camco_setting_store_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_current_setting_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_setting_set_current_setting_value(mmi_camco_setting_enum setting, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_CURRENT_VALUE_CASE_MACRO(__X__,__x__)   \
        case MMI_CAMCO_SETTING_##__X__##:                   \
         mmi_camco_setting_p->##__x__##.cur_value = value;  \
            break;

    switch (setting)
    {
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAPSIZE, capsize);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(RECSIZE, recsize);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(STORAGE, storage);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(LIMIT, limit);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(WB, wb);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(HIGHLIGHT, highlight);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAMSCENEMODE, camscenemode);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAMEV, camev);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(FACEDETECT, facedetect);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CONTRAST, contrast);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SHARPNESS, sharpness);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SATURATION, saturation);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(AFZONE, afzone);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SHUTTERSOUND, shuttersound);
			SET_SETTING_CURRENT_VALUE_CASE_MACRO(TIMELAPS, timelaps);
			SET_SETTING_CURRENT_VALUE_CASE_MACRO(RECAUD, recaud);

        default:
            MMI_ASSERT(0);
            break;
    }

    mmi_camco_setting_store_to_nvram();

}
extern void mmi_camco_setting_set_current_value(mmi_camco_setting_enum setting, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_CURRENT_VALUE_CASE_MACRO(__X__,__x__)   \
        case MMI_CAMCO_SETTING_##__X__##:                   \
         mmi_camco_setting_p->##__x__##.cur_value = value;  \
            break;

    switch (setting)
    {
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAPSIZE, capsize);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(RECSIZE, recsize);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(STORAGE, storage);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(LIMIT, limit);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(WB, wb);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(HIGHLIGHT, highlight);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAMSCENEMODE, camscenemode);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CAMEV, camev);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(FACEDETECT, facedetect);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(CONTRAST, contrast);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SHARPNESS, sharpness);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SATURATION, saturation);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(AFZONE, afzone);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(SHUTTERSOUND, shuttersound);			
            SET_SETTING_CURRENT_VALUE_CASE_MACRO(ISO, iso);	
			SET_SETTING_CURRENT_VALUE_CASE_MACRO(TIMELAPS, timelaps);
        default:
            MMI_ASSERT(0);
            break;
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_cam_id_set_setting_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cam_id      [IN]        
 *  setting     [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_cam_id_set_setting_value(
        mmi_camco_setting_cam_enum cam_id,
        mmi_camco_setting_enum setting,
        U16 value)
{
#ifdef DUAL_CAMERA_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_struct nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_id == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }

    else if (cam_id == MMI_CAMCO_SETTING_CAM_SUB)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
    else
    {
        MMI_ASSERT(0);
    }

#define SET_SETTING_CAMID_VALUE_CASE_MACRO(__X__,__x__)   \
        case MMI_CAMCO_SETTING_##__X__##:                 \
         nvram_data.##__x__## = value;                    \
            break;

    switch (setting)
    {
            SET_SETTING_CAMID_VALUE_CASE_MACRO(CAPSIZE, capsize);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(RECSIZE, recsize);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(STORAGE, storage);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(LIMIT, limit);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(WB, wb);
            SET_SETTING_CAMID_VALUE_CASE_MACRO(HIGHLIGHT, highlight);

        default:
            MMI_ASSERT(0);
            break;
    }

    if (cam_id == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }
    else if (cam_id == MMI_CAMCO_SETTING_CAM_SUB)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }

#endif /* DUAL_CAMERA_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_check_and_set_capsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_check_and_set_capsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->capsize.item_cap[mmi_camco_setting_p->capsize.cur_value] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        U8 i;

        for (i = 0; i < MMI_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
        {
            if (mmi_camco_setting_p->capsize.item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)
            {
                mmi_camco_setting_p->capsize.cur_value = i;
                mmi_camco_update_capsize();
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_boundary_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting         [IN]        
 *  upperbound      [IN]        
 *  lowerbound      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_setting_set_boundary_capability(mmi_camco_setting_enum setting, U16 upperbound, U16 lowerbound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(__X__,__x__)                                                  \
        case MMI_CAMCO_SETTING_##__X__##:                                                                   \
      {                                                                                                     \
         for (idx = 0; idx < MMI_CAMCO_##__X__##_END; idx++)                                                \
            {                                                                                               \
            if ((idx >= lowerbound) && (idx <= upperbound))                                                 \
            {                                                                                               \
               if (mmi_camco_setting_p->##__x__##.item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)   \
               {                                                                                            \
                  mmi_camco_setting_p->##__x__##.item_cap[idx] = MMI_CAMCO_SETTING_CAP_ENABLED;             \
               }                                                                                            \
            }                                                                                               \
            else                                                                                            \
            {                                                                                               \
               if (mmi_camco_setting_p->##__x__##.item_cap[idx] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)   \
               {                                                                                            \
                  mmi_camco_setting_p->##__x__##.item_cap[idx] = MMI_CAMCO_SETTING_CAP_DISABLED;            \
               }                                                                                            \
            }                                                                                               \
         }                                                                                                  \
      }                                                                                                     \
      break;

    switch (setting)
    {
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(CAPSIZE, capsize);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(RECSIZE, recsize);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(LIMIT, limit);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(FLASH, flash);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(CAMSWITCHTO, camswitchto);
            SET_SETTING_BOUNDARY_VALUE_CASE_MACRO(VDOSWITCHTO, vdoswitchto);

        default:
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_default_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_setting_set_default_capability(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_DEFAULT_VALUE_CASE_MACRO(__X__,__x__)   \
        case MMI_CAMCO_SETTING_##__X__##:                   \
            mmi_camco_default_##__x__##_capability();       \
            break;

    switch (setting)
    {
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(CAPSIZE, capsize);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(RECSIZE, recsize);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(TIMESTAMP, timestamp);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(CAMZOOM, camzoom);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(VDOZOOM, vdozoom);
            SET_SETTING_DEFAULT_VALUE_CASE_MACRO(FLASH, flash);

        default:
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_hide_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_hide_capability(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_HIDE_CASE_MACRO(__X__,__x__)                                    \
        case MMI_CAMCO_SETTING_##__X__##:                                           \
            if (mmi_camco_setting_p->##__x__##.cap == MMI_CAMCO_SETTING_CAP_ENABLED)\
            {                                                                       \
                mmi_camco_setting_p->##__x__##.cap = MMI_CAMCO_SETTING_CAP_DISABLED;\
            }                                                                       \
            break;

    switch (setting)
    {
            SET_SETTING_HIDE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_HIDE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_HIDE_CASE_MACRO(TIMESTAMP, timestamp);
            SET_SETTING_HIDE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_HIDE_CASE_MACRO(FLASH, flash);
            SET_SETTING_HIDE_CASE_MACRO(CAMSWITCHTO, camswitchto);
            SET_SETTING_HIDE_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
            SET_SETTING_HIDE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_HIDE_CASE_MACRO(AFZONE, afzone);
            SET_SETTING_HIDE_CASE_MACRO(FACEDETECT, facedetect);
            SET_SETTING_HIDE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_HIDE_CASE_MACRO(LIMIT, limit);
            SET_SETTING_HIDE_CASE_MACRO(CAPSIZE, capsize);            
            SET_SETTING_HIDE_CASE_MACRO(RECSIZE, recsize);    
            SET_SETTING_HIDE_CASE_MACRO(CAMSCENEMODE, camscenemode); 
            SET_SETTING_HIDE_CASE_MACRO(WB, wb); 
            SET_SETTING_HIDE_CASE_MACRO(CAMEV, camev); 
            SET_SETTING_HIDE_CASE_MACRO(CONTRAST, contrast); 
            SET_SETTING_HIDE_CASE_MACRO(SHARPNESS, sharpness); 
            SET_SETTING_HIDE_CASE_MACRO(SATURATION, saturation); 
            SET_SETTING_HIDE_CASE_MACRO(ISO, iso); 			
			SET_SETTING_HIDE_CASE_MACRO(SHUTTERSOUND, shuttersound); 
			SET_SETTING_HIDE_CASE_MACRO(CAPQTY, capqty); 
			SET_SETTING_HIDE_CASE_MACRO(TIMELAPS, timelaps); 
			SET_SETTING_HIDE_CASE_MACRO(RECAUD, recaud); 
        default:
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_is_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_is_hide(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_IS_HIDE_CASE_MACRO(__X__,__x__)                                  \
        case MMI_CAMCO_SETTING_##__X__##:                                            \
            if (!mmi_camco_setting_p->##__x__##.cap == MMI_CAMCO_SETTING_CAP_ENABLED)\
            {                                                                        \
                return MMI_TRUE;                                                     \
            }                                                                        \
            break;

    switch (setting)
    {
            SET_SETTING_IS_HIDE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_IS_HIDE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_IS_HIDE_CASE_MACRO(TIMESTAMP, timestamp);
            SET_SETTING_IS_HIDE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_IS_HIDE_CASE_MACRO(FLASH, flash);
            SET_SETTING_IS_HIDE_CASE_MACRO(CAMSWITCHTO, camswitchto);
            SET_SETTING_IS_HIDE_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
            SET_SETTING_IS_HIDE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_IS_HIDE_CASE_MACRO(AFZONE, afzone);
            SET_SETTING_IS_HIDE_CASE_MACRO(FACEDETECT, facedetect);
            SET_SETTING_IS_HIDE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_IS_HIDE_CASE_MACRO(ISO, iso);

        default:
            return MMI_FALSE;
            //break;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_unhide_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_unhide_capability(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_UNHIDE_CASE_MACRO(__X__,__x__)                                   \
        case MMI_CAMCO_SETTING_##__X__##:                                            \
            if (mmi_camco_setting_p->##__x__##.cap == MMI_CAMCO_SETTING_CAP_DISABLED)\
            {                                                                        \
                mmi_camco_setting_p->##__x__##.cap = MMI_CAMCO_SETTING_CAP_ENABLED;  \
            }                                                                        \
            break;

    switch (setting)
    {
            SET_SETTING_UNHIDE_CASE_MACRO(CAPMODE, capmode);
            SET_SETTING_UNHIDE_CASE_MACRO(VISCODEC, viscodec);
            SET_SETTING_UNHIDE_CASE_MACRO(TIMESTAMP, timestamp);
            SET_SETTING_UNHIDE_CASE_MACRO(SELFTIMER, selftimer);
            SET_SETTING_UNHIDE_CASE_MACRO(FLASH, flash);
            SET_SETTING_UNHIDE_CASE_MACRO(CAMSWITCHTO, camswitchto);
            SET_SETTING_UNHIDE_CASE_MACRO(VDOSWITCHTO, vdoswitchto);
            SET_SETTING_UNHIDE_CASE_MACRO(AFRANGE, afrange);
            SET_SETTING_UNHIDE_CASE_MACRO(AFZONE, afzone);
            SET_SETTING_UNHIDE_CASE_MACRO(FACEDETECT, facedetect);
            SET_SETTING_UNHIDE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_UNHIDE_CASE_MACRO(CAMSCENEMODE, camscenemode);
            SET_SETTING_UNHIDE_CASE_MACRO(WB,wb);
            SET_SETTING_UNHIDE_CASE_MACRO(CAMEV, camev);
            SET_SETTING_UNHIDE_CASE_MACRO(CONTRAST, contrast);
            SET_SETTING_UNHIDE_CASE_MACRO(SHARPNESS, sharpness);
            SET_SETTING_UNHIDE_CASE_MACRO(SATURATION, saturation);
            SET_SETTING_UNHIDE_CASE_MACRO(ISO, iso); 
			SET_SETTING_UNHIDE_CASE_MACRO(SHUTTERSOUND, shuttersound); 
			SET_SETTING_UNHIDE_CASE_MACRO(CAPQTY, capqty); 
			SET_SETTING_UNHIDE_CASE_MACRO(RECAUD, recaud); 

        default:
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_itemlist_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 *  item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_camco_setting_get_itemlist_capability(mmi_camco_setting_enum setting, U16 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_ITEM_CAP_CASE_MACRO(__X__,__x__,IDX)                \
        case MMI_CAMCO_SETTING_##__X__##:                       \
            return mmi_camco_setting_p->##__x__##.item_cap[IDX];\
            //break;

    switch (setting)
    {
            GET_ITEM_CAP_CASE_MACRO(RECSIZE, recsize, item);

        default:
            MMI_CAMCO_ASSERT(0);
            //break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_setting_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_camco_setting_get_setting_capability(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_SETTING_CAP_CASE_MACRO(__X__,__x__)       \
        case MMI_CAMCO_SETTING_##__X__##:             \
            return mmi_camco_setting_p->##__x__##.cap;\
           // break;

    switch (setting)
    {
            GET_SETTING_CAP_CASE_MACRO(CAPMODE, capmode);
            GET_SETTING_CAP_CASE_MACRO(CAMSCENEMODE, camscenemode);
            GET_SETTING_CAP_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_CAP_CASE_MACRO(FLASH, flash);
            GET_SETTING_CAP_CASE_MACRO(HIGHLIGHT, highlight);
            GET_SETTING_CAP_CASE_MACRO(AFRANGE, afrange);
            GET_SETTING_CAP_CASE_MACRO(FACEDETECT, facedetect);
            GET_SETTING_CAP_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_CAP_CASE_MACRO(ISO, iso);
            GET_SETTING_CAP_CASE_MACRO(WB, wb);
            GET_SETTING_CAP_CASE_MACRO(EFFECT, effect);
            GET_SETTING_CAP_CASE_MACRO(STORAGE, storage);
            GET_SETTING_CAP_CASE_MACRO(CAPQTY, capqty);
            GET_SETTING_CAP_CASE_MACRO(AFZONE, afzone);
            GET_SETTING_CAP_CASE_MACRO(AEMETER, aemeter);
            GET_SETTING_CAP_CASE_MACRO(SHARPNESS, sharpness);
            GET_SETTING_CAP_CASE_MACRO(CONTRAST, contrast);
            GET_SETTING_CAP_CASE_MACRO(SATURATION, saturation);
            GET_SETTING_CAP_CASE_MACRO(TIMESTAMP, timestamp);
            GET_SETTING_CAP_CASE_MACRO(SHUTTERSOUND, shuttersound);
            GET_SETTING_CAP_CASE_MACRO(BANDING, banding);

            GET_SETTING_CAP_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            GET_SETTING_CAP_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_CAP_CASE_MACRO(SIZELIMIT, sizelimit);
            GET_SETTING_CAP_CASE_MACRO(TIMELIMIT, timelimit);
            GET_SETTING_CAP_CASE_MACRO(LIMIT, limit);
            GET_SETTING_CAP_CASE_MACRO(VISQTY, visqty);
            GET_SETTING_CAP_CASE_MACRO(AFMODE, afmode);
            GET_SETTING_CAP_CASE_MACRO(RECAUD, recaud);
            GET_SETTING_CAP_CASE_MACRO(VISCODEC, viscodec);
			GET_SETTING_CAP_CASE_MACRO(TIMELAPS, timelaps);

        default:
            MMI_CAMCO_ASSERT(0);
            //break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_str_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting     [IN]        
 *  idx         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID_TYPE mmi_camco_setting_get_str_idx(mmi_camco_setting_enum setting, U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_SETTING_STR_IDX_CASE_MACRO(__X__,__x__)                                             \
    case MMI_CAMCO_SETTING_##__X__##:                                                           \
    {                                                                                           \
        for(i=0; i< MMI_CAMCO_##__X__##_END;i++)                                                \
        {                                                                                       \
            if(mmi_camco_setting_p->##__x__##.item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)     \
            {                                                                                   \
                if(j == idx)                                                                    \
                    return mmi_camco_setting_p->##__x__##.item_str_id[i];                       \
                else                                                                            \
                    j++;                                                                        \
            }                                                                                   \
        }                                                                                       \
        break;                                                                                  \
    }

    j = 0;
    switch (setting)
    {

            GET_SETTING_STR_IDX_CASE_MACRO(CAPMODE, capmode);
            GET_SETTING_STR_IDX_CASE_MACRO(CAMSCENEMODE, camscenemode);
            GET_SETTING_STR_IDX_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_STR_IDX_CASE_MACRO(FLASH, flash);
            GET_SETTING_STR_IDX_CASE_MACRO(HIGHLIGHT, highlight);
            GET_SETTING_STR_IDX_CASE_MACRO(AFRANGE, afrange);
            GET_SETTING_STR_IDX_CASE_MACRO(FACEDETECT, facedetect);
            GET_SETTING_STR_IDX_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_STR_IDX_CASE_MACRO(ISO, iso);
            GET_SETTING_STR_IDX_CASE_MACRO(WB, wb);
            GET_SETTING_STR_IDX_CASE_MACRO(EFFECT, effect);
            GET_SETTING_STR_IDX_CASE_MACRO(STORAGE, storage);
            GET_SETTING_STR_IDX_CASE_MACRO(CAPQTY, capqty);
            GET_SETTING_STR_IDX_CASE_MACRO(AFZONE, afzone);
            GET_SETTING_STR_IDX_CASE_MACRO(AEMETER, aemeter);
            GET_SETTING_STR_IDX_CASE_MACRO(SHARPNESS, sharpness);
            GET_SETTING_STR_IDX_CASE_MACRO(CONTRAST, contrast);
            GET_SETTING_STR_IDX_CASE_MACRO(SATURATION, saturation);
            GET_SETTING_STR_IDX_CASE_MACRO(TIMESTAMP, timestamp);
            GET_SETTING_STR_IDX_CASE_MACRO(SHUTTERSOUND, shuttersound);
            GET_SETTING_STR_IDX_CASE_MACRO(BANDING, banding);

            GET_SETTING_STR_IDX_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            GET_SETTING_STR_IDX_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_STR_IDX_CASE_MACRO(SIZELIMIT, sizelimit);
            GET_SETTING_STR_IDX_CASE_MACRO(TIMELIMIT, timelimit);
            GET_SETTING_STR_IDX_CASE_MACRO(LIMIT, limit);
            GET_SETTING_STR_IDX_CASE_MACRO(VISQTY, visqty);
            GET_SETTING_STR_IDX_CASE_MACRO(AFMODE, afmode);
            GET_SETTING_STR_IDX_CASE_MACRO(RECAUD, recaud);
            GET_SETTING_STR_IDX_CASE_MACRO(VISCODEC, viscodec);
			GET_SETTING_STR_IDX_CASE_MACRO(TIMELAPS, timelaps);
        default:
            MMI_CAMCO_ASSERT(0);
            //return;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_setting_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting             [IN]        
 *  setting_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_setting_info(mmi_camco_setting_enum setting, mmi_camco_setting_struct **setting_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_SETTING_INFO_CASE_MACRO(__X__,__x__)                   \
            case MMI_CAMCO_SETTING_##__X__:                        \
                (*setting_info) = &mmi_camco_setting_p->##__x__;   \
                break;

    switch (setting)
    {

            GET_SETTING_INFO_CASE_MACRO(CAPMODE, capmode);
            GET_SETTING_INFO_CASE_MACRO(CAMSCENEMODE, camscenemode);
            GET_SETTING_INFO_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_INFO_CASE_MACRO(FLASH, flash);
            GET_SETTING_INFO_CASE_MACRO(HIGHLIGHT, highlight);
            GET_SETTING_INFO_CASE_MACRO(AFRANGE, afrange);
            GET_SETTING_INFO_CASE_MACRO(FACEDETECT, facedetect);
            GET_SETTING_INFO_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_INFO_CASE_MACRO(ISO, iso);
            GET_SETTING_INFO_CASE_MACRO(WB, wb);
            GET_SETTING_INFO_CASE_MACRO(EFFECT, effect);
            GET_SETTING_INFO_CASE_MACRO(STORAGE, storage);
            GET_SETTING_INFO_CASE_MACRO(CAPQTY, capqty);
            GET_SETTING_INFO_CASE_MACRO(AFZONE, afzone);
            GET_SETTING_INFO_CASE_MACRO(AEMETER, aemeter);
            GET_SETTING_INFO_CASE_MACRO(SHARPNESS, sharpness);
            GET_SETTING_INFO_CASE_MACRO(CONTRAST, contrast);
            GET_SETTING_INFO_CASE_MACRO(SATURATION, saturation);
            GET_SETTING_INFO_CASE_MACRO(TIMESTAMP, timestamp);
            GET_SETTING_INFO_CASE_MACRO(SHUTTERSOUND, shuttersound);
            GET_SETTING_INFO_CASE_MACRO(BANDING, banding);

            GET_SETTING_INFO_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            GET_SETTING_INFO_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_INFO_CASE_MACRO(SIZELIMIT, sizelimit);
            GET_SETTING_INFO_CASE_MACRO(TIMELIMIT, timelimit);
            GET_SETTING_INFO_CASE_MACRO(LIMIT, limit);
            GET_SETTING_INFO_CASE_MACRO(VISQTY, visqty);
            GET_SETTING_INFO_CASE_MACRO(AFMODE, afmode);
            GET_SETTING_INFO_CASE_MACRO(RECAUD, recaud);
            GET_SETTING_INFO_CASE_MACRO(VISCODEC, viscodec);
			GET_SETTING_INFO_CASE_MACRO(TIMELAPS, timelaps);
        default:
            MMI_ASSERT(0);
            return;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_setting_value
 * DESCRIPTION
 *  Get setting value.
 * PARAMETERS
 *  setting     [IN]        Setting type
 * RETURNS
 *  Will return current setting value based on the pass in setting type
 *****************************************************************************/
extern U16 mmi_camco_setting_get_setting_value(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_SETTING_VALUE_CASE_MACRO(__X__,__x__)               \
        case MMI_CAMCO_SETTING_##__X__##:                       \
            return mmi_camco_setting_p->##__x__##.cur_value;    \

#define GET_SETTING_HILITE_VALUE_CASE_MACRO(__X__,__x__)                \
        case MMI_CAMCO_SETTING_##__X__##:                               \
            if (mmi_camco_setting_p->##__x__##.is_hilite_mod)           \
                return mmi_camco_setting_p->cur_item_setting;           \
            else                                                        \
                return mmi_camco_setting_p->##__x__##.cur_value;        \

    switch (setting)
    {
            GET_SETTING_VALUE_CASE_MACRO(CAPMODE, capmode);
            GET_SETTING_VALUE_CASE_MACRO(CAMSCENEMODE, camscenemode);
            GET_SETTING_VALUE_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_VALUE_CASE_MACRO(FLASH, flash);
            GET_SETTING_VALUE_CASE_MACRO(HIGHLIGHT, highlight);
            GET_SETTING_VALUE_CASE_MACRO(AFRANGE, afrange);
            GET_SETTING_VALUE_CASE_MACRO(FACEDETECT, facedetect);
            GET_SETTING_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_VALUE_CASE_MACRO(ISO, iso);
            GET_SETTING_HILITE_VALUE_CASE_MACRO(WB, wb);
            GET_SETTING_HILITE_VALUE_CASE_MACRO(EFFECT, effect);
            GET_SETTING_VALUE_CASE_MACRO(STORAGE, storage);
            GET_SETTING_VALUE_CASE_MACRO(CAPQTY, capqty);
            GET_SETTING_VALUE_CASE_MACRO(AFZONE, afzone);
            GET_SETTING_VALUE_CASE_MACRO(AEMETER, aemeter);
            GET_SETTING_HILITE_VALUE_CASE_MACRO(SHARPNESS, sharpness);
            GET_SETTING_HILITE_VALUE_CASE_MACRO(CONTRAST, contrast);
            GET_SETTING_HILITE_VALUE_CASE_MACRO(SATURATION, saturation);
            GET_SETTING_VALUE_CASE_MACRO(TIMESTAMP, timestamp);
            GET_SETTING_VALUE_CASE_MACRO(SHUTTERSOUND, shuttersound);
            GET_SETTING_VALUE_CASE_MACRO(BANDING, banding);

            GET_SETTING_VALUE_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            GET_SETTING_VALUE_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_VALUE_CASE_MACRO(SIZELIMIT, sizelimit);
            GET_SETTING_VALUE_CASE_MACRO(TIMELIMIT, timelimit);
            GET_SETTING_VALUE_CASE_MACRO(LIMIT, limit);
            GET_SETTING_VALUE_CASE_MACRO(VISQTY, visqty);
            GET_SETTING_VALUE_CASE_MACRO(AFMODE, afmode);
            GET_SETTING_VALUE_CASE_MACRO(RECAUD, recaud);
            GET_SETTING_VALUE_CASE_MACRO(VISCODEC, viscodec);
			GET_SETTING_VALUE_CASE_MACRO(TIMELAPS, timelaps);
        default:
            MMI_CAMCO_ASSERT(0);
           // return 0;

    }

}
#ifdef DUAL_CAMERA_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_cam_id_get_setting_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cam_id      [IN]        
 *  setting     [IN]        
 * RETURNS
 *  value       [OUT]
 *****************************************************************************/
extern U16 mmi_camco_setting_cam_id_get_setting_value(mmi_camco_setting_cam_enum cam_id, mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_camco_setting_struct nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_id == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
            &error);
    }

    else if (cam_id == MMI_CAMCO_SETTING_CAM_SUB)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
            &error);
    }
    else
    {
        MMI_ASSERT(0);
    }

#define GET_SETTING_CAMID_VALUE_CASE_MACRO(__X__,__x__)   \
        case MMI_CAMCO_SETTING_##__X__##:                 \
         return nvram_data.##__x__##;                     \
            //break;

    switch (setting)
    {
            GET_SETTING_CAMID_VALUE_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(CAPMODE, capmode);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(VISCODEC, viscodec);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(STORAGE, storage);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(LIMIT, limit);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(EFFECT, effect);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(WB, wb);
            GET_SETTING_CAMID_VALUE_CASE_MACRO(HIGHLIGHT, highlight);

        default:
            MMI_CAMCO_ASSERT(0);
            //break;
    }
}
#endif /* DUAL_CAMERA_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_setting_icon
 * DESCRIPTION
 *  Get setting icon.
 * PARAMETERS
 *  setting     [IN]        Setting type
 * RETURNS
 *  Will return current setting's icon (if availabe) based on the pass in
 *  setting type
 *****************************************************************************/
MMI_ID_TYPE mmi_camco_setting_get_setting_icon(mmi_camco_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define GET_SETTING_ICON_CASE_MACRO(__X__,__x__)                                                                \
        case MMI_CAMCO_SETTING_##__X__##:                                                                       \
            if (mmi_camco_setting_p->##__x__##.item_cap[mmi_camco_setting_p->##__x__##.cur_value]               \
                == MMI_CAMCO_SETTING_CAP_ENABLED)                                                               \
            {                                                                                                   \
                return mmi_camco_setting_p->##__x__##.item_img_id[mmi_camco_setting_p->##__x__##.cur_value];    \
            }                                                                                                   \
         else                                                                                                   \
         {                                                                                                      \
            return 0;                                                                                           \
         }

     if(MMI_CAMCO_SETTING_CAMSCENEMODE == setting && mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
     {  

       if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAMSCENEMODE)== MMI_CAMCO_CAMSCENEMODE_AUTO)
       {
           return IMG_ID_CAMCO_SCENEMODE_AUTO;

       }
       else
       {
         return mmi_camco_setting_p->camscenemode.item_img_id[mmi_camco_setting_p->camscenemode.cur_value];    
       }
     }

    switch (setting)
    {
            GET_SETTING_ICON_CASE_MACRO(CAPMODE, capmode);         
            GET_SETTING_ICON_CASE_MACRO(CAMSCENEMODE, camscenemode); 
            GET_SETTING_ICON_CASE_MACRO(CAPSIZE, capsize);
            GET_SETTING_ICON_CASE_MACRO(FLASH, flash);
            GET_SETTING_ICON_CASE_MACRO(HIGHLIGHT, highlight);
            GET_SETTING_ICON_CASE_MACRO(AFRANGE, afrange);
            GET_SETTING_ICON_CASE_MACRO(FACEDETECT, facedetect);
            GET_SETTING_ICON_CASE_MACRO(SELFTIMER, selftimer);
            GET_SETTING_ICON_CASE_MACRO(ISO, iso);
            GET_SETTING_ICON_CASE_MACRO(WB, wb);
            GET_SETTING_ICON_CASE_MACRO(EFFECT, effect);
            GET_SETTING_ICON_CASE_MACRO(STORAGE, storage);
            GET_SETTING_ICON_CASE_MACRO(CAPQTY, capqty);
            GET_SETTING_ICON_CASE_MACRO(AFZONE, afzone);
            GET_SETTING_ICON_CASE_MACRO(AEMETER, aemeter);
            GET_SETTING_ICON_CASE_MACRO(SHARPNESS, sharpness);
            GET_SETTING_ICON_CASE_MACRO(CONTRAST, contrast);
            GET_SETTING_ICON_CASE_MACRO(SATURATION, saturation);
            GET_SETTING_ICON_CASE_MACRO(TIMESTAMP, timestamp);
            GET_SETTING_ICON_CASE_MACRO(SHUTTERSOUND, shuttersound);
            GET_SETTING_ICON_CASE_MACRO(BANDING, banding);
            GET_SETTING_ICON_CASE_MACRO(RESTOREDEFAULT, restoredefault);

            GET_SETTING_ICON_CASE_MACRO(VDOSCENEMODE, vdoscenemode);
            GET_SETTING_ICON_CASE_MACRO(RECSIZE, recsize);
            GET_SETTING_ICON_CASE_MACRO(SIZELIMIT, sizelimit);
            GET_SETTING_ICON_CASE_MACRO(TIMELIMIT, timelimit);
            GET_SETTING_ICON_CASE_MACRO(LIMIT, limit);
            GET_SETTING_ICON_CASE_MACRO(VISQTY, visqty);
            GET_SETTING_ICON_CASE_MACRO(AFMODE, afmode);
            GET_SETTING_ICON_CASE_MACRO(RECAUD, recaud);
            GET_SETTING_ICON_CASE_MACRO(VISCODEC, viscodec);
			GET_SETTING_ICON_CASE_MACRO(TIMELAPS, timelaps);
        default:
            MMI_ASSERT(0);
            return 0;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camev_can_inc
 * DESCRIPTION
 *  Camear EV can increase or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can increase, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camev_can_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *ev_p = &mmi_camco_setting_p->camev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ev_p->cur_value >= MMI_CAMCO_EV_END - 1)
    {
        /* already last one */
        return MMI_FALSE;
    }
    else if (ev_p->item_cap[ev_p->cur_value + 1] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        /* next one cap not enabled */
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camev_can_dec
 * DESCRIPTION
 *  Camear EV can decrease or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can decreases, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camev_can_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *ev_p = &mmi_camco_setting_p->camev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ev_p->cur_value == 0)
    {
        /* already first one */
        return MMI_FALSE;
    }
    else if (ev_p->item_cap[ev_p->cur_value - 1] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        /* prev cap not enabled */
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camev_inc
 * DESCRIPTION
 *  Camear EV increase.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can increase, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camev_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = mmi_camco_setting_p->camev.cur_value;
    if (MMI_CAMCO_EV_END - 1 <= value)
    {
        /* already last one */
        return MMI_FALSE;
    }

    value++;

    if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->camev.item_cap[value])
    {
        mmi_camco_setting_p->camev.cur_value = value;
        return MMI_TRUE;
    }
    else
    {
        /* not support */
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camev_dec
 * DESCRIPTION
 *  Camear EV decrease.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can decrease, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camev_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = mmi_camco_setting_p->camev.cur_value;
    if (0 == value)
    {
        /* already first one */
        return MMI_FALSE;
    }

    value--;

    if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->camev.item_cap[value])
    {
        mmi_camco_setting_p->camev.cur_value = value;
        return MMI_TRUE;
    }
    else
    {
        /* not support */
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camev_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ev_max              [OUT]       
 *  ev_min              [OUT]       
 *  ev_step             [OUT]       
 *  ev_level_count      [OUT]       
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_camev_info(U16 *ev_max, U16 *ev_min, U16 *ev_step, U16 *ev_level_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*ev_max) = (*ev_min) = 0;

    for (i = MMI_CAMCO_EV_END - 1; i >= 0; i--)
    {
        if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->camev.item_cap[i])
        {
            (*ev_max) = i;
            break;
        }
    }

    for (i = 0; i <= (*ev_max); i++)
    {
        if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->camev.item_cap[i])
        {
            (*ev_min) = i;
            break;
        }
    }

    (*ev_step) = 1;

    (*ev_level_count) = (*ev_max) - (*ev_min) + 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_camev_value
 * DESCRIPTION
 *  Set current camera EV value.
 * PARAMETERS
 *  ev      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_camev_value(U16 ev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->camev.cur_value = ev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camev_value
 * DESCRIPTION
 *  Get current camera EV value.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera EV value
 *****************************************************************************/
U16 mmi_camco_setting_get_camev_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camev.cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camev_img
 * DESCRIPTION
 *  Get current EV's image
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera EV image
 *****************************************************************************/
MMI_ID_TYPE mmi_camco_setting_get_camev_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camev.item_img_id[mmi_camco_setting_p->camev.cur_value];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdoev_can_inc
 * DESCRIPTION
 *  Video EV can increase or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can increase, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdoev_can_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *ev_p = &mmi_camco_setting_p->vdoev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ev_p->cur_value >= MMI_CAMCO_EV_END - 1)
    {
        /* already last one */
        return MMI_FALSE;
    }
    else if (ev_p->item_cap[ev_p->cur_value + 1] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        /* next cap not enabled */
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdoev_can_dec
 * DESCRIPTION
 *  Video EV can decrease or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can decrease, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdoev_can_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_struct *ev_p = &mmi_camco_setting_p->vdoev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ev_p->cur_value == 0)
    {
        /* already first one */
        return MMI_FALSE;
    }
    else if (ev_p->item_cap[ev_p->cur_value - 1] != MMI_CAMCO_SETTING_CAP_ENABLED)
    {
        /* prev cap not enabled */
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdoev_inc
 * DESCRIPTION
 *  Video EV increase.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can increase, otherwise return false
 * RETURN VALUE LIST
 *  MMI_TRUE        success
 *  MMI_FALSE       failure
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdoev_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = mmi_camco_setting_p->vdoev.cur_value;
    if (MMI_CAMCO_EV_END - 1 <= value)
    {
        /* already last one */
        return MMI_FALSE;
    }

    value++;

    if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->vdoev.item_cap[value])
    {
        mmi_camco_setting_p->vdoev.cur_value = value;
        return MMI_TRUE;
    }
    else
    {
        /* not support */
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdoev_dec
 * DESCRIPTION
 *  Video EV decrease.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means ev can decrease, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdoev_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = mmi_camco_setting_p->vdoev.cur_value;
    if (0 == value)
    {
        /* already first one */
        return MMI_FALSE;
    }

    value--;

    if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->vdoev.item_cap[value])
    {
        mmi_camco_setting_p->vdoev.cur_value = value;
        return MMI_TRUE;
    }
    else
    {
        /* not support */
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdoev_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ev_max              [OUT]       
 *  ev_min              [OUT]       
 *  ev_step             [OUT]       
 *  ev_level_count      [OUT]       
 * RETURNS
 *  void
 * RETURN VALUE
 *  void
 *****************************************************************************/
void mmi_camco_setting_get_vdoev_info(U16 *ev_max, U16 *ev_min, U16 *ev_step, U16 *ev_level_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*ev_max) = (*ev_min) = 0;

    for (i = MMI_CAMCO_EV_END - 1; i >= 0; i--)
    {
        if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->vdoev.item_cap[i])
        {
            (*ev_max) = i;
            break;
        }
    }

    for (i = 0; i <= (*ev_max); i++)
    {
        if (MMI_CAMCO_SETTING_CAP_ENABLED == mmi_camco_setting_p->vdoev.item_cap[i])
        {
            (*ev_min) = i;
            break;
        }
    }

    (*ev_step) = 1;

    (*ev_level_count) = (*ev_max) - (*ev_min) + 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_vdoev_value
 * DESCRIPTION
 *  Set current vidoe EV value.
 * PARAMETERS
 *  ev      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_vdoev_value(U16 ev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->vdoev.cur_value = ev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdoev_value
 * DESCRIPTION
 *  Get current video EV value.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current video EV value
 *****************************************************************************/
U16 mmi_camco_setting_get_vdoev_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdoev.cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdoev_img
 * DESCRIPTION
 *  Get current EV's image
 * PARAMETERS
 *  void
 * RETURNS
 *  Current video EV image
 *****************************************************************************/
MMI_ID_TYPE mmi_camco_setting_get_vdoev_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdoev.item_img_id[mmi_camco_setting_p->vdoev.cur_value];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camzoom_value
 * DESCRIPTION
 *  Get current zoom's value
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera zoom value
 *****************************************************************************/
U16 mmi_camco_setting_get_camzoom_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camzoom.cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camzoom_step
 * DESCRIPTION
 *  Get current zoom's value
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera zoom value
 *****************************************************************************/
U16 mmi_camco_setting_get_camzoom_step(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camzoom.cur_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_zoom_max_value
 * DESCRIPTION
 *  Get current zoom's value
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera zoom value
 *****************************************************************************/ 
S32 mmi_camco_setting_get_zoom_max_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CAMCO_SETTING_APP_CAMERA == mmi_camco_setting_p->active_app)
    {
        max_value =  mmi_camco_setting_p->camzoom.max_value;
    }
    else if (MMI_CAMCO_SETTING_APP_VIDEO == mmi_camco_setting_p->active_app)
    {
        max_value =  mmi_camco_setting_p->vdozoom.max_value;
    }    
	return max_value;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_is_highlight_on
 * DESCRIPTION
 *  Check if highlight is on
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE/MMI_FALSE  [OUT]
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_is_highlight_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->highlight.cur_value == MMI_CAMCO_HIGHLIGHT_ON)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_camzoom_value
 * DESCRIPTION
 *  Set current zoom's value
 * PARAMETERS
 *  value       [IN]        Zoom value
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_camzoom_value(U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(value <= mmi_camco_setting_p->camzoom.max_value && value >= mmi_camco_setting_p->camzoom.min_value);

    mmi_camco_setting_p->camzoom.cur_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_camzoom_step
 * DESCRIPTION
 *  Set current zoom's step
 * PARAMETERS
 *  step        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_camzoom_step(U16 step)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->camzoom.cur_step = step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camzoom_maxstep
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  maxzoom value   [OUT]
 *****************************************************************************/
U16 mmi_camco_setting_get_camzoom_maxstep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camzoom.max_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_camzoom_minstep
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  maxzoom value   [OUT]
 *****************************************************************************/
U16 mmi_camco_setting_get_camzoom_minstep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->camzoom.min_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camzoom_can_zoom_in
 * DESCRIPTION
 *  Camera can zoom in or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means can zoom in, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camzoom_can_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
	if((mmi_camco_setting_p->capmode.cur_value== MMI_CAMCO_CAPMODE_MAV) ||
		(mmi_camco_setting_p->capmode.cur_value== MMI_CAMCO_CAPMODE_3D_IMAGE))
	{
		return MMI_FALSE;
	}
	#endif
    if (mmi_camco_setting_p->camzoom.cur_value < mmi_camco_setting_p->camzoom.max_value)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_camzoom_can_zoom_out
 * DESCRIPTION
 *  Camera can zoom out or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means can zoom out, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_camzoom_can_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->camzoom.cur_value > mmi_camco_setting_p->camzoom.min_value)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdozoom_value
 * DESCRIPTION
 *  Get current zoom's value
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera zoom value
 *****************************************************************************/
U16 mmi_camco_setting_get_vdozoom_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdozoom.cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdozoom_step
 * DESCRIPTION
 *  Get current zoom's value
 * PARAMETERS
 *  void
 * RETURNS
 *  Current camera zoom value
 *****************************************************************************/
U16 mmi_camco_setting_get_vdozoom_step(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdozoom.cur_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdozoom_maxstep
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  maxzoom value   [OUT]
 *****************************************************************************/
U16 mmi_camco_setting_get_vdozoom_maxstep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdozoom.max_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_vdozoom_minstep
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  maxzoom value   [OUT]
 *****************************************************************************/
U16 mmi_camco_setting_get_vdozoom_minstep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_setting_p->vdozoom.min_step;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_vdozoom_value
 * DESCRIPTION
 *  Set current zoom's value
 * PARAMETERS
 *  value       [IN]        Zoom value
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_vdozoom_value(U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(value <= mmi_camco_setting_p->vdozoom.max_value && value >= mmi_camco_setting_p->vdozoom.min_value);

    mmi_camco_setting_p->vdozoom.cur_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_vdozoom_step
 * DESCRIPTION
 *  Set current zoom's step
 * PARAMETERS
 *  step        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_vdozoom_step(U16 step)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->vdozoom.cur_step = step;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_camscene_mode
 * DESCRIPTION
 *  Set current scene mode
 * PARAMETERS
 *  step        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_camscene_mode(U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->camscenemode.cur_value= value;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdozoom_can_zoom_in
 * DESCRIPTION
 *  Video can zoom in or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means can zoom in, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdozoom_can_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->vdozoom.cur_value < mmi_camco_setting_p->vdozoom.max_value)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_vdozoom_can_zoom_out
 * DESCRIPTION
 *  Video can zoom out or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return true means can zoom out, otherwise return false
 * RETURN VALUE
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_camco_setting_vdozoom_can_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->vdozoom.cur_value > mmi_camco_setting_p->vdozoom.min_value)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_banding
 * DESCRIPTION
 *  This is for webcam cam setting
 * PARAMETERS
 *  void
 * RETURNS
 *  banding value
 *****************************************************************************/
U16 mmi_camco_setting_get_banding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->banding.cur_value == 0xff ||
        mmi_camco_setting_p->banding.cur_value == MMI_CAMCO_BANDING_60HZ)
    {
        value = MDI_CAMERA_BANDING_60HZ;
    }
    else
    {
        value = MDI_CAMERA_BANDING_50HZ;
    }

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_cur_item_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        Index value
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_cur_item_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->cur_item_idx = idx;
    mmi_camco_setting_p->cur_item_setting = mmi_camco_setting_p->itemlist[mmi_camco_setting_p->cur_item_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_restore_default
 * DESCRIPTION
 *  This is for webcam cam setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 0, NVRAM_EF_CAMCO_MAIN_SETTING_LID, 1, NVRAM_EF_CAMCO_MAIN_SETTING_TOTAL);
#ifdef DUAL_CAMERA_SUPPORT    
    mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 0, NVRAM_EF_CAMCO_SUB_SETTING_LID, 1, NVRAM_EF_CAMCO_SUB_SETTING_TOTAL);
#endif

    mmi_camco_setting_p->capmode.cur_value = MMI_CAMCO_CAPMODE_NORMAL;
    mmi_camco_setting_p->camscenemode.cur_value = MMI_CAMCO_CAMSCENEMODE_AUTO;
    mmi_camco_setting_p->capsize.cur_value = 0xff;
    mmi_camco_setting_p->flash.cur_value = MMI_CAMCO_FLASH_AUTO;
    mmi_camco_setting_p->highlight.cur_value = MMI_CAMCO_HIGHLIGHT_OFF;
    mmi_camco_setting_p->afrange.cur_value = 0xff;
    mmi_camco_setting_p->facedetect.cur_value = MMI_CAMCO_FACEDETECT_OFF;
    mmi_camco_setting_p->selftimer.cur_value = MMI_CAMCO_SELFTIMER_OFF;
    mmi_camco_setting_p->iso.cur_value = MMI_CAMCO_ISO_AUTO;
    mmi_camco_setting_p->wb.cur_value = MMI_CAMCO_WB_AUTO;
    mmi_camco_setting_p->effect.cur_value = MMI_CAMCO_EFFECT_NORMAL;
    mmi_camco_setting_p->storage.cur_value = 0xff;
    mmi_camco_setting_p->capqty.cur_value = MMI_CAMCO_CAPQTY_FINE;
    mmi_camco_setting_p->afzone.cur_value = MMI_CAMCO_AFZONE_SINGLE;
    mmi_camco_setting_p->aemeter.cur_value = MMI_CAMCO_AEMETER_AUTO;
    mmi_camco_setting_p->sharpness.cur_value = 0xff;
    mmi_camco_setting_p->contrast.cur_value = 0xff;
    mmi_camco_setting_p->saturation.cur_value = 0xff;
    mmi_camco_setting_p->timestamp.cur_value = MMI_CAMCO_TIMESTAMP_OFF;
    mmi_camco_setting_p->shuttersound.cur_value = MMI_CAMCO_SHUTTERSOUND_SOUND_1;
    mmi_camco_setting_p->banding.cur_value = MMI_CAMCO_BANDING_60HZ;
    mmi_camco_setting_p->vdoscenemode.cur_value = MMI_CAMCO_VDOSCENEMODE_AUTO;
    mmi_camco_setting_p->recsize.cur_value = 0xff;
    mmi_camco_setting_p->sizelimit.cur_value = MMI_CAMCO_SIZELIMIT_NO_LIMIT;
    mmi_camco_setting_p->timelimit.cur_value = MMI_CAMCO_TIMELIMIT_NO_LIMIT;
    mmi_camco_setting_p->limit.cur_value = MMI_CAMCO_LIMIT_NO_LIMIT;
    mmi_camco_setting_p->visqty.cur_value = MMI_CAMCO_VISQTY_FINE;
    mmi_camco_setting_p->afmode.cur_value = MMI_CAMCO_AFMODE_OFF;
    mmi_camco_setting_p->recaud.cur_value = MMI_CAMCO_RECAUD_ON;
    mmi_camco_setting_p->viscodec.cur_value = MMI_CAMCO_VISCODEC_MP4;
    mmi_camco_setting_p->camev.cur_value = MMI_CAMCO_EV_0;
    mmi_camco_setting_p->vdoev.cur_value = MMI_CAMCO_EV_0;
    mmi_camco_setting_p->restoredefault.cur_value = MMI_CAMCO_RESTOREDEFAULT_YES;
	mmi_camco_setting_p->timelaps.cur_value = MMI_CAMCO_TIMESTAMP_OFF;

    mmi_camco_setting_p->camzoom.cur_value = mmi_camco_setting_p->camzoom.min_value;
    mmi_camco_setting_p->camzoom.cur_step = 0;

    mmi_camco_setting_p->vdozoom.cur_value = mmi_camco_setting_p->vdozoom.min_value;
    mmi_camco_setting_p->vdozoom.cur_step = 0;

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_set_time_stamp_enable(MMI_FALSE);
#endif 
    mmi_camco_setting_store_default_to_nvram();

    mmi_camco_osd_set_default();
    //mmi_camco_setting_set_default();
    mmi_camco_setting_default_capability();
    if (mmi_camco_is_from_external())
    {
        mmi_camco_setting_update_capability();
        mmi_camco_update_facedetect_capability();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_set_current_setting_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting         [IN]        
 *  is_hilite       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_setting_set_current_setting_hilite(mmi_camco_setting_enum setting, MMI_BOOL is_hilite)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define SET_SETTING_CURRENT_HILITE_CASE_MACRO(__X__,__x__)        \
        case MMI_CAMCO_SETTING_##__X__##:                         \
         mmi_camco_setting_p->##__x__##.is_hilite_mod = is_hilite;\
            break;

    switch (setting)
    {
            SET_SETTING_CURRENT_HILITE_CASE_MACRO(EFFECT, effect);
            SET_SETTING_CURRENT_HILITE_CASE_MACRO(WB, wb);
            SET_SETTING_CURRENT_HILITE_CASE_MACRO(SHARPNESS, sharpness);
            SET_SETTING_CURRENT_HILITE_CASE_MACRO(CONTRAST, contrast);
            SET_SETTING_CURRENT_HILITE_CASE_MACRO(SATURATION, saturation);

        default:
            MMI_ASSERT(0);
            break;
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_update_visqty_capability
 * DESCRIPTION
 *  Update recsize capability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_update_visqty_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][g_mmi_camco_setting_cntx.visqty.cur_value] || g_mmi_camco_setting_cntx.viscodec.cur_value == 0xFF)
    {
        S32 idx;
        
        for (idx = MMI_CAMCO_VISQTY_END - 1; idx >= 0; idx--)
        {
            if (mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][idx])
            {
                mmi_camco_setting_p->visqty.cur_value = idx;
                break;
            }
        }
    }

    for(i = 0; i< MMI_CAMCO_VISQTY_END; i++)
    {
        if(mmi_camco_setting_p->visqty.item_cap[i] != MMI_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(!mmi_camco_recsize_vs_codec_vs_qty[g_mmi_camco_setting_cntx.recsize.cur_value][g_mmi_camco_setting_cntx.viscodec.cur_value][i])
            {
                mmi_camco_setting_p->visqty.item_cap[i] = MMI_CAMCO_SETTING_CAP_DISABLED;
            }
            else
            {
                mmi_camco_setting_p->visqty.item_cap[i] = MMI_CAMCO_SETTING_CAP_ENABLED;
            }            
        }
    }
}
#endif /* __MMI_CAMCORDER__ */ 

#endif /* MMI_CAMCOSETTING_C */ 

