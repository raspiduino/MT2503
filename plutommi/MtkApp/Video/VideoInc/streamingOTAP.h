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
 *   StreamingOTAP.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   RTSP OTAP for video streaming profiles, internal used structure and function.
 *
 * Author:
 * -------
 * -------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 * $Log$
 *
 * 04 20 2012 qiang.zhang
 * removed!
 * .
 *
 * 12 09 2011 qiang.zhang
 * removed!
 * .
 *
 * 07 28 2011 qiang.zhang
 * removed!
 * .
 *
 * 05 26 2011 qiang.zhang
 * removed!
 * .
 *
 * 04 13 2011 qiang.zhang
 * removed!
 * .
 *
 * 03 01 2011 qiang.zhang
 * removed!
 * .
 *
 * 12 14 2010 qiang.zhang
 * removed!
 * .
 *
 * 11 17 2010 qiang.zhang
 * removed!
 * .
 *
 * 11 04 2010 qiang.zhang
 * removed!
 * .
 *
 ****************************************************************************/
#ifndef __STREAMING_OTAP_H__
#define __STREAMING_OTAP_H__
//#include "MMI_include.h"

#include "MMI_features.h"
#ifdef __MMI_STREAMING_OTAP__
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"

#include "common_nvram_editor_data_item.h"
#include "DataAccountGProt.h"
//#include "CentralConfigAgentGProt.h"

#if defined(__MMI_VIDEO_PLAYER__) && !defined(__MMI_MEDIA_PLAYER__)
#include "vdoplyGProt.h"
#include "mmi_rp_app_vdoply_def.h"
#endif 

#if !defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_MEDIA_PLAYER__)
#include "MediaPlayerGProt.h"
#include "mmi_rp_app_medply_def.h"

extern void mmi_medply_store_profile(U8 index,nvram_ef_medply_settings_profile_struct *prof_p);
extern void mmi_medply_load_profile(U8 index, nvram_ef_medply_settings_profile_struct *prof_p);
extern void mmi_medply_del_all_app_screen(void);
#endif 

#define STREAMING_PROFILE_USED              MMI_TRUE
#define STREAMING_PROFILE_EMPTY             MMI_FALSE

#define INVALID_STREAMING_PROFILE_INDEX     MAX_STREAMING_PROFILE_NUM
#define STREAMING_DATA_ACCOUNT_TYPE         (DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI)

#define STREAMING_PROXY_IP_COUNT            (4)
#define DEFAULT_MIN_UDP_PORT            (6000)
#define DEFAULT_MAX_UDP_PORT            (65535)
#define UDP_PORT_DELTA                  (3)
#define STREAMING_PROFILE_PORT_LEN      (6)

#if defined(__MMI_VIDEO_PLAYER__) && !defined(__MMI_MEDIA_PLAYER__)

#define MAX_STREAMING_PROFILE_NAME_SIZE VIDEO_MAX_PROFILE_NAME_BUF_SIZE
#define MAX_STREAMING_PROFILE_NUM       NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL
#define MENU_ID_STREAMING_OTA           MENU_ID_VDOPLY_APP
#define MAX_STREAMING_PROXY_ADDR_BUF_SIZE VIDEO_MAX_PROXY_ADDR_BUF_SIZE

#define mmi_media_get_active_profile()      mmi_vdoply_get_active_profile()
#define mmi_media_set_active_profile(a)             mmi_vdoply_set_active_profile((U8)(a))
#define mmi_media_is_profile_in_use(a)              mmi_vdoply_is_profile_in_use((U8)(a))
#define mmi_media_del_all_app_screen()              mmi_vdoply_del_all_app_screen()
#define mmi_media_load_profile(a, b)                mmi_vdoply_load_profile((U8)(a), (nvram_ef_video_network_profile_struct *)(b))
#define mmi_media_store_profile(a, b)               mmi_vdoply_store_profile((U8)(a), (nvram_ef_video_network_profile_struct *)(b))
#define mmi_media_get_cbm_app_id()                  (mmi_vdoply_get_cbm_app_id())
#define mmi_media_get_string_id_and_icon_id(a,b)    mmi_vdoply_get_string_id_and_icon_id((U16*)(a),(U16*)(b))
typedef nvram_ef_video_network_profile_struct streaming_profile_nvram_struct;
#endif /* defined(__MMI_VIDEO_PLAYER__) && !defined(__MMI_MEDIA_PLAYER__) */ 

#if !defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_MEDIA_PLAYER__)

#define MAX_STREAMING_PROFILE_NAME_SIZE MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE
#define MAX_STREAMING_PROFILE_NUM       NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL
#define MENU_ID_STREAMING_OTA           MENU_ID_MEDPLY_MAIN
#define MAX_STREAMING_PROXY_ADDR_BUF_SIZE MMI_MEDPLY_MAX_PROXY_ADDR_BUF_SIZE

#define mmi_media_get_active_profile()      mmi_medply_get_active_profile()
#define mmi_media_set_active_profile(a)             mmi_medply_set_active_profile((U8)(a))
#define mmi_media_is_profile_in_use(a)              mmi_medply_is_profile_in_use((U8)(a))
#define mmi_media_del_all_app_screen()              mmi_medply_del_all_app_screen()
#define mmi_media_load_profile(a, b)                mmi_medply_load_profile((U8)(a), (nvram_ef_medply_settings_profile_struct *)(b))
#define mmi_media_store_profile(a, b)               mmi_medply_store_profile((U8)(a), (nvram_ef_medply_settings_profile_struct *)(b))
#define mmi_media_get_cbm_app_id()                  (mmi_medply_get_cbm_app_id())
#define mmi_media_get_string_id_and_icon_id(a,b)    mmi_medply_get_string_id_and_icon_id((U16*)(a),(U16*)(b))
typedef nvram_ef_medply_settings_profile_struct streaming_profile_nvram_struct;
#endif /* !defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_MEDIA_PLAYER__) */ 

/**********************************************************************************/
/*Streaming DM                                                                                                                                                       */
/**********************************************************************************/
#ifdef SYNCML_DM_SUPPORT
#define MMI_STREAMING_DM_UDP_PORT_DELTA     (5)
#define MMI_STREAMING_PROFILE_IP_LEN        (16)
#endif

#define MMI_STREAM_OTAP_MASSAGE_TRACE(VAL)					\
		    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_STREAMING_OTAP_MESSAGE_REPORT, __LINE__, VAL)
#define MMI_STREAM_OTAP_ERROR_TRACE(VAL)					\
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_STREAMING_OTAP_ERROR_REPORT, __LINE__, VAL)
#endif /* __MMI_STREAMING_OTAP__ */ 
#endif /* __STREAMING_OTAP_H__ */ 

