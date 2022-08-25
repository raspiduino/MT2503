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
 *   VdoPlyUltraSlimApp.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   low cost video player for 32+32 & 32+16 project.
 *
 * Author:
 * -------
 * -------
 *
 *
 *------------------------------------------------------------------------------
 *============================================================================
 * $Log$
 *
 * 05 24 2011 qiang.zhang
 * removed!
 * .
 *
 * 01 07 2011 qiang.zhang
 * removed!
 * .
 *
 * 12 23 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 21 2010 qiang.zhang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VDOPLY_ULTRA_SLIM_APP_H_H_
#define _VDOPLY_ULTRA_SLIM_APP_H_H_

#include "MMI_features.h"

#ifdef __MMI_ULC_VIDEO_PLAYER__
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gdi_include.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOPLY_BUF_MAX_CHAR_NUMBER           ( (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH )

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_VDOPLY_STATE_EXIT,
    MMI_VDOPLY_STATE_OPENING,
    MMI_VDOPLY_STATE_PLAY,
    MMI_VDOPLY_STATE_PAUSE,
    MMI_VDOPLY_STATE_TOTAL
} mmi_vdoply_state_enum; 


typedef struct
{
    gdi_handle play_wnd_layer_handle; 

    U64 total_time_duration; 
    U64 play_time;

    U16 state;
	U16 flag;
	
	U16 video_id;
    CHAR file_name[VDOPLY_BUF_MAX_CHAR_NUMBER];

	U8 volume;   
} mmi_vdoply_context_struct;

#define MMI_VDOPLY_MASSAGE_TRACE(VAL)					\
		    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOPLY_SLIM_MESSAGE_REPORT, __LINE__, VAL)
#define MMI_VDOPLY_ERROR_TRACE(VAL)					\
	        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOPLY_SLIM_ERROR_REPORT, __LINE__, VAL)

#endif /* __MMI_ULC_VIDEO_PLAYER__*/
#endif /* _VDOPLY_ULTRA_SLIM_APP_H_H_ */

