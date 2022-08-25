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
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.i
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
 * Filename:
 * ---------
 * med_mem.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes media memory configuration.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

//#ifndef MED_NOT_PRESENT

#ifndef _MED_MEM_H
#define _MED_MEM_H

#include "med_global.h" 
#include "med_appmem_config.h"
/* for lcd size */
#include "lcd_Sw_inc.h"
#undef APP_MEM_HEADER_FILE
#undef APP_MEM_CONFIG
#define APP_MEM_HEADER_FILE
#include "app_mem_define.h"

#if 0 /* for pluto memory 2.0 */
#if defined(__J2ME__)
/* under construction !*/
/* under construction !*/
#endif
#endif

#define MED_1_SCENARIO_DEFAULT (MED_MEM_EXT_DEFAULT_SIZE)
#define MED_1_SCENARIO_CAM_CAPTURE (MAX_MED_CAM_CAP_EXT_MEM_SIZE)
#define MED_1_SCENARIO_JPG_DECODE (MAX_MED_JPG_DEC_EXT_MEM_SIZE)
#define MED_1_SCENARIO_PNG_DECODE (MAX_PNG_MAX_EXT_MEM_SIZE)
#define MED_1_SCENARIO_JPG_ENCODE (MAX_MED_JPG_ENC_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_ENCODE (MAX_MED_VID_ENC_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE (MAX_MED_VID_DEC_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_SUBTITLE (MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_QVGA (MAX_MED_VID_DEC_QVGA_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_CIF (MAX_MED_VID_DEC_CIF_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_PREVIEW (MAX_MED_VID_DEC_PREVIEW_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_INFO (MAX_MED_VID_DEC_INFO_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_MP4 (MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_QVGA_MPEG4SP (MAX_MED_VID_DEC_QVGA_MPEG4SP_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_V (MAX_MED_VID_DEC_V_EXT_MEM_SIZE)
#define MED_1_SCENARIO_VID_DECODE_A (MAX_MED_VID_DEC_A_EXT_MEM_SIZE)

#define MED_1_SCENARIO_WEBCAM (MAX_MED_WEBCAM_EXT_MEM_SIZE)
#define MED_1_SCENARIO_MMS_SUPPORT (MAX_MMS_RESIZE_IMAGE_BUF_SIZE)
#define MED_1_SCENARIO_VOIP (MAX_VOIP_EXT_MEM_SIZE)
#define MED_1_SCENARIO_STREAMING (MAX_STREAMING_EXT_MEM_SIZE)
#define MED_1_SCENARIO_STREAMING_QVGA (MAX_STREAMING_QVGA_EXT_MEM_SIZE)
#define MED_1_SCENARIO_STREAMING_CIF  (MAX_STREAMING_CIF_EXT_MEM_SIZE)
#if 0 /* for pluto memory 2.0 */
/* under construction !*/
#endif 
#define MED_1_SCENARIO_3D_GAME (MAX_3D_GAME_EXT_MEM_SIZE)
#define MED_1_SCENARIO_AUD (AUD_EXT_MEM_SIZE)
#define MED_1_SCENARIO_TDMB (MAX_TDMB_EXT_MEM_SIZE)
#define MED_1_SCENARIO_CMMB (MAX_CMMB_EXT_MEM_SIZE)
#define MED_1_SCENARIO_ATV (MAX_ATV_EXT_MEM_SIZE)
#define MED_1_SCENARIO_FS_SORT (MAX_FS_SORT_MEM_SIZE)
#define MED_1_SCENARIO_CAM_PREVIEW (MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)
#define MED_1_SCENARIO_STITCH_PANORAMA (MAX_CAM_PANORAMA_EXT_MEM_SIZE)
#define MED_1_SCENARIO_HDR (MAX_CAM_HDR_EXT_MEM_SIZE)
#define MED_1_SCENARIO_IVEX (MAX_IVEX_MEM_SIZE)

#define MED_2_SCENARIO_WEBCAM_W_FS_WORT (MAX_MED_WEBCAM_EXT_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)
#define MED_2_SCENARIO_JPG_ENCODE_W_AUD_TDMB (MAX_MED_JPG_ENC_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_2_SCENARIO_STREAMING_W_AUD_TDMB (MAX_STREAMING_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_2_SCENARIO_MMS_SUPPORT_W_AUD_TDMB (MAX_MMS_RESIZE_IMAGE_BUF_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_2_SCENARIO_TDMB_W_AUD (MAX_TDMB_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE)
#define MED_2_SCENARIO_CMMB_W_AUD (MAX_CMMB_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE)
#define MED_2_SCENARIO_ATV_W_AUD (MAX_ATV_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE)
#define MED_2_SCENARIO_WEBCAM_W_TDMB (MAX_MED_WEBCAM_EXT_MEM_SIZE + MTV_BG_RECORD_MEM_SIZE)
#define MED_2_SCENARIO_STREAMING_W_AUD_W_PANO (MAX_STREAMING_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE+CAM_BG_STITCH_EXT_MEM_SIZE)
#define MED_2_SCENARIO_IVEX_W_IMG_DECODE (MAX_IVEX_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE)
#define MED_2_SCENARIO_STITCH_PANORAMA_W_IMG_DECODE (MAX_CAM_PANORAMA_EXT_MEM_SIZE+MAX_MED_JPG_DEC_EXT_MEM_SIZE)
#define MED_2_SCENARIO_MRE_W_AUD_W_IMG_DECODE_W_FS_SORT (MAX_MRE_EXT_MEM_SIZE+MAX_FS_SORT_MEM_SIZE+MAX_MED_JPG_DEC_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE)
#define MED_2_SCENARIO_GADGET_W_VID_DECODE (GADGET_FULL_SCREEN_MEM_SIZE+MAX_MED_VID_DEC_EXT_MEM_SIZE)
#define MED_2_SCENARIO_CAM_CAPTURE_W_BG_PANO (MAX_MED_CAM_CAP_EXT_MEM_SIZE + CAM_BG_STITCH_EXT_MEM_SIZE)

#define MED_3_SCENARIO_IMG_DECODE_W_AUD_TDMB_FS_SORT (MAX_MED_JPG_DEC_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)
#define MED_3_SCENARIO_IMG_DECODE_W_VOIP_W_AUD_TDMB_FS_SORT (MAX_MED_JPG_DEC_EXT_MEM_SIZE+MAX_VOIP_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)
#define MED_3_SCENARIO_CAM_CAPTURE_W_IMG_DECODE_W_TDMB (MAX_CAM_FILE_BUFFER_LEN+MAX_MED_JPG_DEC_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#if defined(LOW_COST_SUPPORT)
#define MED_3_SCENARIO_VDO_DECODE_W_SNAPSHOT_W_AUD_TDMB_FS_SORT (MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE+ 0 +AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)
#else
#define MED_3_SCENARIO_VDO_DECODE_W_SNAPSHOT_W_AUD_TDMB_FS_SORT (MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE+ MAX_MED_JPG_ENC_EXT_MEM_SIZE +AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)
#endif

#define MED_3_SCENARIO_VDO_DECODE_W_IMG_DECODE_W_AUD_TDMB_FS_SORT (MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE+ MAX_MED_JPG_DEC_EXT_MEM_SIZE +AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)

#define MED_3_SCENARIO_VDO_ENCODE_W_FS_SORT_W_AUD_TDMB  (MAX_MED_VID_ENC_EXT_MEM_SIZE + MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_3_SCENARIO_W_FS_SORT_W_AUD_TDMB  (MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#if 0 /* for pluto memory 2.0 */
/* under construction !*/
#endif
#define MED_3_SCENARIO_STREAMING_W_IMG_DECODE_W_FS_SORT_AUD_TDMB  (MAX_STREAMING_EXT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE + MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_3_SCENARIO_MMS_SUPPORT_W_FS_SORT_W_AUD_TDMB  (MAX_MMS_RESIZE_IMAGE_BUF_SIZE + MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_3_SCENARIO_IVEX_W_IMG_DECODE_W_FS_SORT_AUD_TDMB (MAX_IVEX_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE + MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)
#define MED_3_SCENARIO_CAM_CAPTURE_W_FS_SORT_W_AUD (MAX_MED_CAM_CAP_EXT_MEM_SIZE + MAX_FS_SORT_MEM_SIZE + AUD_EXT_MEM_SIZE)

#define MED_4_SCENARIO_FS_SORT_W_AUD_W_IMG_DECODE (MAX_FS_SORT_MEM_SIZE + AUD_EXT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE )
#ifdef __MMI_VUI_MEDIAWALL__
#define MED_4_SCENARIO_VRT_ENGINE_W_IVEX_W_IMG_DECODE_W_AUD_FS_SORT (MAX_VRT_EXT_MEM_SIZE + MAX_IVEX_MEM_SIZE + MAX_FS_SORT_MEM_SIZE + AUD_EXT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE)
#endif

/* Audio memory */
/* Put VRSD, VRSI, TTS in MED memory pool because they are with large memory size and could not run in the background */
#define MED_AUD_SCENARIO_VRSD      (AUD_MED_VRSD_EXT_MEM_SIZE)
#define MED_AUD_SCENARIO_VRSI      (AUD_MED_VRSI_EXT_MEM_SIZE)
#define MED_AUD_SCENARIO_TTS       (AUD_MED_TTS_EXT_MEM_SIZE)
/* Put the others in AUD memory pool */
#define MED_AUD_SCENARIO_SPEECH    (MAX_AUD_MEM_SIZE_SPEECH)
#define MED_AUD_SCENARIO_CTM       (MAX_AUD_MEM_SIZE_CTM)
#define MED_AUD_SCENARIO_BKSND     (MAX_AUD_MEM_SIZE_BKSND)
#define MED_AUD_SCENARIO_MMA       (MAX_AUD_MEM_SIZE_MMA)
#define MED_AUD_SCENARIO_WAV       (MAX_AUD_MEM_SIZE_WAV)
#define MED_AUD_SCENARIO_MP3       (MAX_AUD_MEM_SIZE_MP3)
#define MED_AUD_SCENARIO_MP4       (MAX_AUD_MEM_SIZE_MP4)
#define MED_AUD_SCENARIO_AAC       (MAX_AUD_MEM_SIZE_AAC)
#define MED_AUD_SCENARIO_AMR       (MAX_AUD_MEM_SIZE_AMR)
#define MED_AUD_SCENARIO_AWB       (MAX_AUD_MEM_SIZE_AWB)
#define MED_AUD_SCENARIO_APE       (MAX_AUD_MEM_SIZE_APE)
#define MED_AUD_SCENARIO_VORBIS    (MAX_AUD_MEM_SIZE_VORBIS)
#define MED_AUD_SCENARIO_FLAC      (MAX_AUD_MEM_SIZE_FLAC)
#define MED_AUD_SCENARIO_SBC_DEC   (MAX_AUD_MEM_SIZE_SBC_DEC)
#define MED_AUD_SCENARIO_I2S_REC   (MAX_AUD_MEM_SIZE_I2S_REC)
#define MED_AUD_SCENARIO_AMR_REC   (MAX_AUD_MEM_SIZE_AMR_REC)
#define MED_AUD_SCENARIO_VORBIS_REC (MAX_AUD_MEM_SIZE_VORBIS_REC)
#define MED_AUD_SCENARIO_MIDI_FILE (MAX_AUD_MEM_SIZE_MIDI_FILE)
#define MED_AUD_SCENARIO_IMY_DATA  (MAX_AUD_MEM_SIZE_IMY_DATA)
#define MED_AUD_SCENARIO_MIDI_DATA (MAX_AUD_MEM_SIZE_MIDI_DATA)
#define MED_AUD_SCENARIO_VM        (MAX_AUD_MEM_SIZE_VM)

/* MED Internal */
#define MED_INT_SCENARIO_DEFAULT MED_MEM_INT_DEFAULT_SIZE
#define MED_INT_SCENARIO_AMR_REC MAX_DEDI_AMR_REC_BUFFER
#define MED_INT_SCENARIO_CAM_PRE MAX_MED_CAM_PREVIEW_INT_MEM_SIZE
/* MED DEFAULT SIZE is multiple of 4 */
#define MED_MEM_INT_DEFAULT_SIZE     (4)
#define MED_MEM_EXT_DEFAULT_SIZE     (4)
#define MED_MEM_ALIGN_TO_4(_x)  (((_x) + 3) & ~3) 

#define MED_INT_MEM_SIZE_CONFIG(size)    \
	(MED_MEM_ALIGN_TO_4(size) + MEM_OVERHEAD)
#define MED_AUD_MEM_SIZE_CONFIG(size)    \
    (MED_MEM_ALIGN_TO_4(size) + MEM_AUD_OVERHEAD)
#define MED_MEM_SIZE_CONFIG(size)    \
	(MED_MEM_ALIGN_TO_4(size) + MEM_EXT_OVERHEAD)
#define MED_MEM_CONC2_SIZE(size1, size2)    \
    (MED_MEM_ALIGN_TO_4(size1) + MED_MEM_ALIGN_TO_4(size2) + MEM_EXT_OVERHEAD)
#define MED_MEM_CONC3_SIZE(size1, size2, size3)    \
    (MED_MEM_ALIGN_TO_4(size1) + MED_MEM_ALIGN_TO_4(size2) + MED_MEM_ALIGN_TO_4(size3) + MEM_EXT_OVERHEAD)
#define MED_MEM_CONC4_SIZE(size1, size2, size3, size4)    \
    (MED_MEM_ALIGN_TO_4(size1) + MED_MEM_ALIGN_TO_4(size2) + MED_MEM_ALIGN_TO_4(size3) + MED_MEM_ALIGN_TO_4(size4) + MEM_EXT_OVERHEAD)
#define MED_MEM_CONC5_SIZE(size1, size2, size3, size4, size5)    \
        (MED_MEM_ALIGN_TO_4(size1) + MED_MEM_ALIGN_TO_4(size2) + MED_MEM_ALIGN_TO_4(size3) + MED_MEM_ALIGN_TO_4(size4) + MED_MEM_ALIGN_TO_4(size5) + MEM_EXT_OVERHEAD)

#undef MEM_CONFIG_APP_ONLY
#undef MEM_CONFIG_MED_EXT
#undef MEM_CONFIG_SCREEN_BASE
#undef MEM_CONFIG_APP_TOTAL
#undef APP_MEM_HEADER_FILE
#undef APP_MEM_CONFIG
	
#define APP_MEM_CONFIG
#define MEM_CONFIG_APP_ONLY(app_name, size)  
#define MEM_CONFIG_MED_EXT(app_name, size) \
	       kal_uint8 MED_EXT_##app_name##_BUFFER[size];
#define MEM_CONFIG_SCREEN_BASE(app_name, size) 
#define MEM_CONFIG_APP_TOTAL(app_name, size) 
typedef union
{
	#include "app_mem_define.h" 

    /* each single cases */	
    //kal_uint8 MED_EXT_CAM_CAPTURE[MED_MEM_SIZE_CONFIG(MAX_MED_CAM_CAP_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_JPG_ENCODE[MED_MEM_SIZE_CONFIG(MAX_MED_JPG_ENC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_IMG_DECODE[MED_MEM_SIZE_CONFIG(MAX_MED_JPG_DEC_EXT_MEM_SIZE)]; 
    kal_uint8 MED_EXT_VID_ENCODE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_ENC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VID_DECODE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_DEC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VID_DECODE_SUBTITLE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_WEBCAM[MED_MEM_SIZE_CONFIG(MAX_MED_WEBCAM_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_MMS_SUPPORT[MED_MEM_SIZE_CONFIG(MAX_MMS_RESIZE_IMAGE_BUF_SIZE)];
    kal_uint8 MED_EXT_VOIP[MED_MEM_SIZE_CONFIG(MAX_VOIP_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_STREAMING[MED_MEM_SIZE_CONFIG(MAX_STREAMING_EXT_MEM_SIZE)]; 
	#if 0 /* for pluto memory 2.0 */
/* under construction !*/
	#endif
    kal_uint8 MED_EXT_3D_GAME[MED_MEM_SIZE_CONFIG(MAX_3D_GAME_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_AUD[MED_MEM_SIZE_CONFIG(AUD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_TDMB[MED_MEM_SIZE_CONFIG(MAX_TDMB_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_CMMB[MED_MEM_SIZE_CONFIG(MAX_CMMB_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_ATV[MED_MEM_SIZE_CONFIG(MAX_ATV_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_CAM_PREVIEW[MED_MEM_SIZE_CONFIG(MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_CAM_PANORAMA[MED_MEM_SIZE_CONFIG(MAX_CAM_PANORAMA_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_CAM_HDR[MED_MEM_SIZE_CONFIG(MAX_CAM_HDR_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_IVEX[MED_MEM_SIZE_CONFIG(MAX_IVEX_MEM_SIZE)];
    kal_uint8 MED_EXT_VRSD[MED_MEM_SIZE_CONFIG(AUD_MED_VRSD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VRSI[MED_MEM_SIZE_CONFIG(AUD_MED_VRSI_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_TTS[MED_MEM_SIZE_CONFIG(AUD_MED_TTS_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_VRT[MED_MEM_SIZE_CONFIG(MAX_VRT_EXT_MEM_SIZE)];

    /* 2 scenarios concurrent cases */
    //kal_uint8 MED_EXT_GADGET_W_VID_DECODE[MED_MEM_CONC2_SIZE(GADGET_FULL_SCREEN_MEM_SIZE ,MAX_MED_VID_DEC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_WEBCAM_W_FS_SORT[MED_MEM_CONC2_SIZE(MAX_MED_WEBCAM_EXT_MEM_SIZE,MAX_FS_SORT_MEM_SIZE)];
    kal_uint8 MED_EXT_JPG_ENCODE_W_AUD_TDMB[MED_MEM_CONC2_SIZE(MAX_MED_JPG_ENC_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_STREAMING_W_AUD_TDMB[MED_MEM_CONC2_SIZE(MAX_STREAMING_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_MMS_SUPPORT_W_AUD_TDMB[MED_MEM_CONC2_SIZE(MAX_MMS_RESIZE_IMAGE_BUF_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_TDMB_W_AUD[MED_MEM_CONC2_SIZE(MAX_TDMB_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_CMMB_W_AUD[MED_MEM_CONC2_SIZE(MAX_CMMB_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_ATV_W_AUD[MED_MEM_CONC2_SIZE(MAX_ATV_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_WEBCAM_W_TDMB[MED_MEM_CONC2_SIZE(MAX_MED_WEBCAM_EXT_MEM_SIZE,MTV_BG_RECORD_MEM_SIZE)];
    
    kal_uint8 MED_EXT_PANORAMA_W_JPG_DECODE[MED_MEM_CONC2_SIZE(MAX_CAM_PANORAMA_EXT_MEM_SIZE,MAX_MED_JPG_DEC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_STREAMING_W_AUD_W_PANO[MED_MEM_CONC2_SIZE(MAX_STREAMING_EXT_MEM_SIZE+AUD_EXT_MEM_SIZE,CAM_BG_STITCH_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_IVEX_W_JPG_DECODE[MED_MEM_CONC2_SIZE(MAX_IVEX_MEM_SIZE,MAX_MED_JPG_DEC_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_MRE_W_AUD_W_JPG_DECODE_W_FS_SORT[MED_MEM_CONC2_SIZE(MAX_MRE_EXT_MEM_SIZE, MAX_FS_SORT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE + AUD_EXT_MEM_SIZE)];
    //kal_uint8 MED_EXT_CAM_CAPTURE_W_BG_PANO[MED_MEM_CONC2_SIZE(MAX_MED_CAM_CAP_EXT_MEM_SIZE,CAM_BG_STITCH_EXT_MEM_SIZE)];
#if 0 /* for pluto memory 2.0 */
/* under construction !*/
/* under construction !*/
    #ifdef J2ME_SUPPORT_BACKGROUND
/* under construction !*/
    #endif
#endif    

    /* 3 scenarios concurrent cases */
    kal_uint8 MED_EXT_JPG_DECODE_W_AUD_TDMB_FS_SORT[MED_MEM_CONC3_SIZE(MAX_MED_JPG_DEC_EXT_MEM_SIZE, AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE, MAX_FS_SORT_MEM_SIZE)];
    kal_uint8 MED_EXT_JPG_DECODE_W_VOIP_W_AUD_TDMB_FS_SORT[MED_MEM_CONC3_SIZE(MAX_MED_JPG_DEC_EXT_MEM_SIZE,MAX_VOIP_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)];
    #if defined(LOW_COST_SUPPORT)
    kal_uint8 MED_EXT_VDO_DECODE_W_SNAPSHOT_W_AUD_TDMB_FS_SORT[MED_MEM_CONC3_SIZE(MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE,0,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)];
    #else
    kal_uint8 MED_EXT_VDO_DECODE_W_SNAPSHOT_W_AUD_TDMB_FS_SORT[MED_MEM_CONC3_SIZE(MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE,MAX_MED_JPG_ENC_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)];
    #endif
    #if !defined(__MP4_DEC_SW_SUPPORT__) && !defined(__H264_DEC_SW_SUPPORT__)
    kal_uint8 MED_EXT_VDO_DECODE_W_JPG_DECODE_W_AUD_TDMB_FS_SORT[MED_MEM_CONC3_SIZE(MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE,MAX_MED_JPG_DEC_EXT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE+MAX_FS_SORT_MEM_SIZE)];
    #endif
    //kal_uint8 MED_EXT_CAM_CAPTURE_W_JPG_DECODE_W_TDMB[MED_MEM_CONC3_SIZE(MAX_CAM_FILE_BUFFER_LEN,MAX_MED_JPG_DEC_EXT_MEM_SIZE,MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_VDO_ENCODE_W_FS_SORT_W_AUD_TDMB[MED_MEM_CONC3_SIZE(MAX_MED_VID_ENC_EXT_MEM_SIZE,MAX_FS_SORT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_FS_SORT_W_AUD_W_TDMB[MED_MEM_CONC3_SIZE(MAX_FS_SORT_MEM_SIZE, AUD_EXT_MEM_SIZE, MTV_BG_RECORD_MEM_SIZE)];
#if 0 /* for pluto memory 2.0 */
/* under construction !*/
#endif
    kal_uint8 MED_EXT_STREAMING_W_JPG_DECODE_W_FS_SORT_AUD_TDMB[MED_MEM_CONC3_SIZE(MAX_STREAMING_EXT_MEM_SIZE,MAX_MED_JPG_DEC_EXT_MEM_SIZE,MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    kal_uint8 MED_EXT_MMS_SUPPORT_W_FS_SORT_W_AUD_TDMB[MED_MEM_CONC3_SIZE(MAX_MMS_RESIZE_IMAGE_BUF_SIZE ,MAX_FS_SORT_MEM_SIZE,AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    //kal_uint8 MED_EXT_IVEX_W_JPG_DECODE_W_FS_SORT_AUD_TDMB[MED_MEM_CONC3_SIZE(MAX_IVEX_MEM_SIZE,MAX_MED_JPG_DEC_EXT_MEM_SIZE,MAX_FS_SORT_MEM_SIZE+AUD_EXT_MEM_SIZE+MTV_BG_RECORD_MEM_SIZE)];
    //kal_uint8 MED_EXT_CAM_CAPTURE_W_FS_SORT_W_AUD[MED_MEM_CONC3_SIZE(MAX_MED_CAM_CAP_EXT_MEM_SIZE,MAX_FS_SORT_MEM_SIZE,AUD_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_FS_SORT_W_AUD_W_JPG_DECODE[MED_MEM_CONC3_SIZE(MAX_FS_SORT_MEM_SIZE ,AUD_EXT_MEM_SIZE ,MAX_MED_JPG_DEC_EXT_MEM_SIZE )];
    
    #if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined(__MED_IN_ASM__)   
    #if (defined(STREAM_SUPPORT) && defined(__MMI_MEDIA_PLAYER__))
    kal_uint8 MED_EXT_VRT_W_VIDEO_LIVE_WALLPAPER[MED_MEM_CONC5_SIZE(MAX_VRT_EXT_MEM_SIZE ,MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE, MAX_MED_VIDEO_LIVE_WALLPAPER_EXT_MEM_SIZE, MAXOF(MED_STREAMING_BASE_MEM, MED_AUD_PLY_BASE_MEM), GADGET_IDLE_SCREEN_MEM_SIZE)];
    #else
    kal_uint8 MED_EXT_VRT_W_VIDEO_LIVE_WALLPAPER[MED_MEM_CONC4_SIZE(MAX_VRT_EXT_MEM_SIZE ,MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE, MAX_MED_VIDEO_LIVE_WALLPAPER_EXT_MEM_SIZE, GADGET_IDLE_SCREEN_MEM_SIZE)];
    #endif
    #endif

    #ifdef __MMI_VUI_MEDIAWALL__
    //kal_uint8 MED_EXT_VRT_W_IVEX_W_FS_SORT_W_AUD_W_JPG_DECODE[MED_MEM_CONC4_SIZE(MAX_VRT_EXT_MEM_SIZE, MAX_IVEX_MEM_SIZE ,MAX_FS_SORT_MEM_SIZE, AUD_EXT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE )];
    #endif
    //kal_uint8 MED_EXT_MEDIACACHE_W_IVEX_W_FS_SORT_W_AUD_W_JPG_DECODE[MED_MEM_CONC4_SIZE(MAX_MED_MEDIACACHE_IES_EXT_MEM_SIZE, MAX_IVEX_MEM_SIZE ,MAX_FS_SORT_MEM_SIZE, AUD_EXT_MEM_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE )];
} med_ext_mem_config_union;

typedef union
{
    /* default size */
    kal_uint8 MED_DUFAULT_EXT_SIZE[MED_MEM_EXT_DEFAULT_SIZE];
#if !defined(__MED_IN_ASM__)
    kal_uint8 MED_EXT_MEMORY[sizeof(med_ext_mem_config_union)];
#else
    kal_uint8 MED_EXT_MEDIA_LARGE_POOL[4];
#endif /* __MED_IN_ASM__ */
} med_ext_mem_union;

#define MED_EXT_MEM_SIZE sizeof(med_ext_mem_union)
#define MED_EXT_MEM_PLUTO_SIZE sizeof(med_ext_mem_config_union)


#if defined(__MED_IN_ASM__)
typedef union
{
    kal_uint8 MED_EXT_CAM_CAPTURE[MED_MEM_SIZE_CONFIG(MAX_MED_CAM_CAP_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VID_ENCODE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_ENC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VID_DECODE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_DEC_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_VID_DECODE_SUBTITLE[MED_MEM_SIZE_CONFIG(MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_CAM_PREVIEW[MED_MEM_SIZE_CONFIG(MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_CAM_PANORAMA[MED_MEM_SIZE_CONFIG(MAX_CAM_PANORAMA_EXT_MEM_SIZE)];
    kal_uint8 MED_EXT_CAM_HDR[MED_MEM_SIZE_CONFIG(MAX_CAM_HDR_EXT_MEM_SIZE)];
    
} med_ext_mem_ext_union;

#define MED_EXT_MEM_EXT_SIZE sizeof(med_ext_mem_ext_union)
#endif


typedef union
{
    kal_uint8 MED_DUFAULT_INT_SIZE[MED_INT_MEM_SIZE_CONFIG(MED_MEM_INT_DEFAULT_SIZE)];
    kal_uint8 MED_INT_CAM_PREVIEW[MED_INT_MEM_SIZE_CONFIG(MAX_MED_CAM_PREVIEW_INT_MEM_SIZE)];
    kal_uint8 MED_INT_DEDI_AMR_REC_BUFFER[MED_INT_MEM_SIZE_CONFIG(MAX_DEDI_AMR_REC_BUFFER)];
} med_int_mem_union;

#define MED_INT_MEM_SIZE sizeof(med_int_mem_union)

typedef union
{
    kal_uint8 MED_AUD_SPEECH[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_SPEECH)];
    kal_uint8 MED_AUD_CTM[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_CTM)];
    kal_uint8 MED_AUD_BKSND[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_BKSND)];
    kal_uint8 MED_AUD_MMA[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_MMA)];
    kal_uint8 MED_AUD_WAV[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_WAV)];
    kal_uint8 MED_AUD_MP3[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_MP3)];
    kal_uint8 MED_AUD_MP4[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_MP4)];
    kal_uint8 MED_AUD_AAC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_AAC)];
    kal_uint8 MED_AUD_AMR[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_AMR)];
    kal_uint8 MED_AUD_AWB[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_AWB)];
    kal_uint8 MED_AUD_APE[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_APE)];
    kal_uint8 MED_AUD_VORBIS[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_VORBIS)];
    kal_uint8 MED_AUD_FLAC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_FLAC)];
    kal_uint8 MED_AUD_SBC_DEC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_SBC_DEC)];
    kal_uint8 MED_AUD_I2S_REC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_I2S_REC)];
    kal_uint8 MED_AUD_AMR_REC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_AMR_REC)];
    kal_uint8 MED_AUD_VORBIS_REC[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_VORBIS_REC)];
    kal_uint8 MED_AUD_MIDI_FILE[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_MIDI_FILE)];
    kal_uint8 MED_AUD_IMY_DATA[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_IMY_DATA)];
    kal_uint8 MED_AUD_MIDI_DATA[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_MIDI_DATA)];
    kal_uint8 MED_AUD_VM[MED_AUD_MEM_SIZE_CONFIG(MAX_AUD_MEM_SIZE_VM)];
} med_aud_mem_union;

typedef union
{
    kal_uint8 MED_AUD_INFO_MP4[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_MP4)];
    kal_uint8 MED_AUD_INFO_AAC[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_AAC)];
    kal_uint8 MED_AUD_INFO_AMR[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_AMR)];
    kal_uint8 MED_AUD_INFO_DAF[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_DAF)];
    kal_uint8 MED_AUD_INFO_WMA[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_WMA)];
    kal_uint8 MED_AUD_INFO_AU[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_AU)];
    kal_uint8 MED_AUD_INFO_AIFF[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_AIFF)];
    kal_uint8 MED_AUD_INFO_WAV[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_WAV)];
    kal_uint8 MED_AUD_INFO_APE[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_APE)];
    kal_uint8 MED_AUD_INFO_VORBIS[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_VORBIS)];
    kal_uint8 MED_AUD_INFO_FLAC[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_FLAC)];    
} med_aud_info_union;


#define MED_AUD_MEM_SIZE sizeof(med_aud_mem_union) + sizeof(med_aud_info_union)

#ifdef __VIDEO_STANDALONE_MEMORY__
typedef union
{
    kal_uint8 MED_VID_DSP[MED_MEM_SIZE_CONFIG(MED_VID_MEM_SIZE)];
}med_vid_mem_union;

#define MED_VID_MEM_SIZE sizeof(med_vid_mem_union)
#endif /* __VIDEO_STANDALONE_MEMORY__ */

#endif
