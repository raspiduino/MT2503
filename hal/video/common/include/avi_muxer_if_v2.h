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
 *   avi_muxer_if_v2.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 ****************************************************************************/
#include "drv_features_video.h"

#ifndef __AVI_MUXER_IF_V2_H__
#define __AVI_MUXER_IF_V2_H__

#include "sw_video_encode_custom.h"
#include "cache_sw.h"
#include "video_muxer_if_v2.h"
#include "hal_custom_video_if.h"

#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUPPORT_AVI_MUXER__)
    #if defined(MT6250) || defined(MT6260) || defined(MT6261)
        //#define _SUPPORT_BIG_FRAME_SIZE_ONLY_
    #endif

    #if !defined(ENABLE_AVI_MUXER_CUSTOM_SETTING)
        #if defined(MT6252) || defined(MT6252H)
            #define _AVI_ONE_DATA_BUFF_SIZE         (64*1024)
            #define _AVI_DATA_BUFF_NUM              (3)
        #elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T)
            #define _AVI_ONE_DATA_BUFF_SIZE         (64*1024)
            #define _AVI_DATA_BUFF_NUM              (5)
        #elif defined(MT6236) || defined (MT6236B)
            #define _AVI_ONE_DATA_BUFF_SIZE         (128*1024)
            #define _AVI_DATA_BUFF_NUM              (10)
        #elif defined(MT6256)
            #define _AVI_ONE_DATA_BUFF_SIZE         (128*1024)
            #define _AVI_DATA_BUFF_NUM              (4)
        #elif defined(MT6250) || defined(MT6260) || defined(MT6261)
            #if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
                #define _AVI_ONE_DATA_BUFF_SIZE         (64*1024)
                #define _AVI_DATA_BUFF_NUM              (1)
            #else
                #define _MIN_AVI_DATA_BUFF_NUM              (2)

                #ifdef __VE_MED_VIDEO_ULC__
                    #define _AVI_ONE_DATA_BUFF_SIZE         (32 * 1024)
                #elif defined(__VE_MJPEG_ENC_SW_SLIM__)
                    #define _AVI_ONE_DATA_BUFF_SIZE         (64 * 1024)
                #else
                    #define _AVI_ONE_DATA_BUFF_SIZE         (32 * 1024)
                #endif

                #define _MAX_MJPG_SIZE                   (MJPEG_ENC_MAX_WIDTH * MJPEG_ENC_MAX_HEIGHT * 33 / 32)
                #define _AVI_DATA_BUFF_NUM               (((_MAX_MJPG_SIZE + _AVI_ONE_DATA_BUFF_SIZE - 1) / _AVI_ONE_DATA_BUFF_SIZE))
                #if (_AVI_DATA_BUFF_NUM < _MIN_AVI_DATA_BUFF_NUM)
                    #undef _AVI_DATA_BUFF_NUM
                    #define _AVI_DATA_BUFF_NUM (_MIN_AVI_DATA_BUFF_NUM)
                #endif
            #endif
        #else
            #define _AVI_ONE_DATA_BUFF_SIZE         (64*1024)
            #define _AVI_DATA_BUFF_NUM              (5)
        #endif

        #if defined(MT6250) || defined(MT6260) || defined(MT6261)
            #if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
                #define _AVI_ONE_IDX_BUFF_SIZE      (32*1024)
                #define _AVI_IDX_BUFF_NUM           (1)
            #else
                #define _AVI_ONE_IDX_BUFF_SIZE      (32*1024)
                #define _AVI_IDX_BUFF_NUM           (2)
            #endif
        #else
            #define _AVI_ONE_IDX_BUFF_SIZE      (4*1024)
            #define _AVI_IDX_BUFF_NUM           (2)
        #endif
    #else
        #define _AVI_MIN_BUFFER_NUM         (2)
        #define _AVI_ONE_DATA_BUFF_SIZE     (CUSTOM_AVI_ONE_DATA_BUFF_SIZE)
        #define _AVI_DATA_BUFF_NUM          (CUSTOM_AVI_DATA_BUFF_EXTRA_NUM + _AVI_MIN_BUFFER_NUM)
        #define _AVI_ONE_IDX_BUFF_SIZE      (CUSTOM_AVI_ONE_IDX_BUFF_SIZE)
        #define _AVI_IDX_BUFF_NUM           (CUSTOM_AVI_IDX_BUFF_EXTRA_NUM + _AVI_MIN_BUFFER_NUM)
        #if ((_AVI_ONE_DATA_BUFF_SIZE % 32768) != 0)
            #error "CUSTOM_AVI_ONE_DATA_BUFF_SIZE is recommended to be some multiple of 32KB"
        #endif
    #endif

    #define _AVI_MAX_BUFFER_NUM  (16)
    #if (_AVI_DATA_BUFF_NUM > _AVI_MAX_BUFFER_NUM)
        #error "_AVI_DATA_BUFF_NUM cannot exceed _AVI_MAX_BUFFER_NUM(16)"
    #endif
    #if (_AVI_IDX_BUFF_NUM > _AVI_MAX_BUFFER_NUM)
        #error "_AVI_IDX_BUFF_NUM cannot exceed _AVI_MAX_BUFFER_NUM(16)"
    #endif

    #define _AVI_BUFFER_CTRL_SIZE  (_AVI_MAX_BUFFER_NUM * 3 * 4 + 16)

    #define _MAX_FILE_NAME_N_PATH   (261)
    #define _SIZE_OF_KAL_WCHAR      (2)
    #define _AVI_FILE_PATH_SIZE     (_MAX_FILE_NAME_N_PATH*_SIZE_OF_KAL_WCHAR)
    #define _AVI_WORKING_PATH_SIZE  (_MAX_FILE_NAME_N_PATH*_SIZE_OF_KAL_WCHAR)
    #define _AVI_ADM_OVERHEAD       (512)

    #define AVI_MUXER_TOTAL_EXT_MEM_SIZE       ((_AVI_ONE_DATA_BUFF_SIZE + CPU_CACHE_LINE_SIZE)*_AVI_DATA_BUFF_NUM + \
                                                (_AVI_ONE_IDX_BUFF_SIZE + CPU_CACHE_LINE_SIZE)*_AVI_IDX_BUFF_NUM + \
                                                _AVI_FILE_PATH_SIZE + CPU_CACHE_LINE_SIZE + \
                                                _AVI_WORKING_PATH_SIZE + CPU_CACHE_LINE_SIZE +\
                                                _AVI_BUFFER_CTRL_SIZE*2 +\
                                                _AVI_FILE_PATH_SIZE + CPU_CACHE_LINE_SIZE   +\
                                                _AVI_WORKING_PATH_SIZE + CPU_CACHE_LINE_SIZE    +\
                                                _AVI_ADM_OVERHEAD)

    #define AVI_MUXER_TOTAL_MERGE_FILE_EXT_MEM_SIZE (_AVI_FILE_PATH_SIZE + CPU_CACHE_LINE_SIZE + \
                                                            _AVI_WORKING_PATH_SIZE + CPU_CACHE_LINE_SIZE +\
                                                            _AVI_BUFFER_CTRL_SIZE*2 +\
                                                            _AVI_FILE_PATH_SIZE + CPU_CACHE_LINE_SIZE   +\
                                                            _AVI_WORKING_PATH_SIZE + CPU_CACHE_LINE_SIZE    +\
                                                            _AVI_ADM_OVERHEAD)
#else
    #define AVI_MUXER_TOTAL_EXT_MEM_SIZE       (0)
    #define AVI_MUXER_TOTAL_MERGE_FILE_EXT_MEM_SIZE (0)
#endif

MUXER_ADAPT_API_T* AVIMuxerGetHandle(void);


#endif // __AVI_MUXER_IF_V2_H__
