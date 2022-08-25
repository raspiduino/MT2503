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
 *   video_filereader_mem_v2.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *============================================================================
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
 ****************************************************************************/

#ifndef VIDEO_FILEREADER_MEM_V2_H
#define VIDEO_FILEREADER_MEM_V2_H

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
//#include "video_filereader_mem_custom_v2.h"
#include "video_filereader_component_v2.h"

#if defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)

#define FILEREADER_MAX_WIDTH          320//320
#define FILEREADER_MAX_HEIGHT         240//240
#define FILEREADER_BITSTREAM_NUM      3

/***************************************
*
*   Decide the size of bitstream buffer
*
***************************************/

#define FILEREADER_BITSTREAM_BUFF_SIZE (FILEREADER_MAX_WIDTH * FILEREADER_MAX_HEIGHT * FILEREADER_BITSTREAM_NUM * 3 / 2)

/*******************************************************
*
*   Decide the working memory of video decoder component
*
*******************************************************/ 

//#define VIDEO_FILEREADER_FILE_ADAPTATION_SIZE (10752 + )

#define FILEREADER_WORKING_MEM_SIZE (sizeof(VIDEO_FILEREADER_NAL_CTRL_BUFF_T) + sizeof(VIDEO_FILEREADER_FILE_ADAPTATION_STRUCT_T) + \
                                     sizeof(VIDEO_FILEREADER_PARAM_SET_STRUCT_T))
/*******************************************************
*
*   Decide the total external memory needed by
*   decoder component
*
*******************************************************/

#define FILEREADER_EXT_MEM_SIZE (FILEREADER_BITSTREAM_BUFF_SIZE + FILEREADER_WORKING_MEM_SIZE)

#endif /*defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)*/
#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_FILEREADER_MEM_V2_H */

