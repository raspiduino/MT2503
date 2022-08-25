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
 *   yuv_encoder_component_v2.c
 *
 * Project:
 * --------
 *  MTK
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
 *
 ****************************************************************************/
#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_SUPPORT_YUV_RECORDING__)

#include "video_types_v2.h"
#include "yuv_encoder_component_v2.h"
#include "video_encoder_component_v2.h"
#include "video_codec_type_v2.h"
#include "fsal.h"
#include "fs_type.h"
#include "fs_func.h"
#include "video_codec_if_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

static YUV_ENCODER_MGR_T _rYUVEncMgr;

/******************************************************************************
*
******************************************************************************/
static void _YUVSwEncYUVEncoded(kal_uint8* pu1Addr)
{
    VideoEncoderReleaseYUV(pu1Addr);
}

/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderInitAdapt(void)
{

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderGetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    switch(eCmd)
    {
    default:
        break;
    }

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderSetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    switch(eCmd)
    {
    default:
        break;
    }

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderDeInitAdapt(void)
{

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}

/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderOpenAdapt(void)
{
    FSAL_Status rOpenStatus;
    kal_wchar   store_name[LENGTH_OF_FILE_PATH] = {'x', ':', '\\', '\\', 'R', 'E', 'C', '9', '9', '.', 'y', 'u', 'v', '\0'};
    //kal_wchar   store_name[LENGTH_OF_FILE_PATH] = L"x:\\REC99.yuv";

    //Initialize store_name to be F:\\REC01.yuv
    store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);


    store_name[8] = _rYUVEncMgr.u4FileCountDigit0 + '0';
    store_name[7] = _rYUVEncMgr.u4FileCountDigit1 + '0';

    //Check if the file already exists
    do{
        rOpenStatus = FSAL_Open(&_rYUVEncMgr.rRecordFile, store_name, FSAL_READ);
        if(FSAL_OPEN_ERROR == rOpenStatus)
        {
            //The file does not exist
            kal_mem_cpy((void*)(_rYUVEncMgr.u2FileName), (void*)(&store_name[0]), sizeof(store_name[0])*LENGTH_OF_FILE_PATH);
            break;
        }
        else if (FSAL_OK == rOpenStatus)
        {
            rOpenStatus = FSAL_Close(&_rYUVEncMgr.rRecordFile);
            if (FSAL_OK != rOpenStatus)
            {
                return VIDEO_ENCODER_CODEC_ERROR_NONE;
            }

            // Maximum 99 files recorded in serial
            if((_rYUVEncMgr.u4FileCountDigit0 == 9)&&(_rYUVEncMgr.u4FileCountDigit1 == 9))
            {
                return VIDEO_ENCODER_CODEC_ERROR_NONE;
            }

            if (_rYUVEncMgr.u4FileCountDigit0 == (10 - 1))
            {
                _rYUVEncMgr.u4FileCountDigit0 = 0;
                _rYUVEncMgr.u4FileCountDigit1++;
                store_name[8] = _rYUVEncMgr.u4FileCountDigit0 + '0';
                store_name[7] = _rYUVEncMgr.u4FileCountDigit1 + '0';
            }
            else
            {
                _rYUVEncMgr.u4FileCountDigit0++;
                store_name[8] = _rYUVEncMgr.u4FileCountDigit0 + '0';
            }
        }
        else
        {
            return VIDEO_ENCODER_CODEC_ERROR_NONE;
        }
    }while (1);


    rOpenStatus = FSAL_Open(&_rYUVEncMgr.rRecordFile, store_name, FSAL_WRITE);
    if (FSAL_OK != rOpenStatus)
    {
        ASSERT(0);
        return VIDEO_ENCODER_CODEC_ERROR;
    }
    FS_Extend(_rYUVEncMgr.rRecordFile.hFile, 480*320*3/2);

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}

/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderCloseAdapt(void)
{
    FSAL_Close(&_rYUVEncMgr.rRecordFile);

    if (KAL_FALSE == _rYUVEncMgr.fgSavedFrame)
    {
        //Delete the file opened if no there's no frames saved
        FS_Delete(_rYUVEncMgr.u2FileName);
    }

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderGenerateHeader(void)
{

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* Encode one unit.
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderEncodeOneFrame(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    FSAL_Status rWriteStatus;

    if (NULL != prBufferHeader)
    {
        rWriteStatus = FSAL_Write(&_rYUVEncMgr.rRecordFile, prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
        if (FSAL_OK != rWriteStatus)
        {
           return VIDEO_ENCODER_CODEC_ERROR_NONE;
        }

        _rYUVEncMgr.u4CodedFrame++;
        _YUVSwEncYUVEncoded( prBufferHeader->pu1Buffer);

        //FS_Extend(_rYUVEncMgr.rRecordFile.hFile, prBufferHeader->u4BuffSize);

        _rYUVEncMgr.fgSavedFrame = KAL_TRUE;
    }

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T YUVEncoderGetNextBitstream(kal_uint8 **ppu1BitstreamAddr,
        VIDEO_ENCODER_PRIVATE_OUTPUT_T *prPrivateOutput)
{
    *ppu1BitstreamAddr = NULL;

    if (_rYUVEncMgr.u4CodedFrame != 0)
    {
        _rYUVEncMgr.u4CodedFrame--;
        prPrivateOutput->fgEndOfFrame = KAL_TRUE;
    }
    else
    {
        prPrivateOutput->fgEndOfFrame = KAL_FALSE;
    }


    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


/******************************************************************************
* xxx
******************************************************************************/
static VIDEO_ENCODER_CODEC_API_T _rYUVEncoderAPI =
{
    YUVEncoderOpenAdapt,
    YUVEncoderInitAdapt,
    YUVEncoderGetParameterAdapt,
    YUVEncoderSetParameterAdapt,
    YUVEncoderGenerateHeader,
    YUVEncoderEncodeOneFrame,
    YUVEncoderDeInitAdapt,
    YUVEncoderCloseAdapt,
    YUVEncoderGetNextBitstream
};


/******************************************************************************
* xxx
******************************************************************************/
VIDEO_ENCODER_CODEC_API_T* GetYUVEncoderHandler(void)
{
    // Initialize data members
    _rYUVEncMgr.u4CodedFrame        =   0;
    _rYUVEncMgr.u4FileCountDigit0   =   1;
    _rYUVEncMgr.u4FileCountDigit1   =   0;
    _rYUVEncMgr.fgSavedFrame        =   KAL_FALSE;

    return &_rYUVEncoderAPI;
}

#endif /*(__VE_SUPPORT_YUV_RECORDING__)*/
#endif /* __VIDEO_ARCHI_V2__*/

