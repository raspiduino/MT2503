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
 *  ImgViewerCacheGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image viewer decoder interfaces for application to reference.
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
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#if !defined(_IMG_VIEWER_DEC_GPROT_H_)
/* DOM-NOT_FOR_SDK-BEGIN */
#define _IMG_VIEWER_DEC_GPROT_H_
/* DOM-NOT_FOR_SDK-END */

#include "ImgviewerConfig.h"
#if defined(__MMI_IVF_CACHE__)

/*******************************************************************************
* Macro Define
*******************************************************************************/
/*
 * IVC run buffer size.
 */
#define MMI_IVC_RUN_BUF_SIZE          (2*1024)  /* cntx + l1 nodes */

/*
 * Return values for IVC APIs.
 */
/* Successfule. */
#define MMI_IVC_OK                    (0)
/* Decoding, the image is not decode done. */
#define MMI_IVC_DECODING              (-56001)
/* App should return this if MMI_IVC_EVENT_GET_FILE result is loading. */
#define MMI_IVC_LOADING               (-56002)
/* If image is not been cached, then query img and gat max size will return faile. */
#define MMI_IVC_FAILE                 (-56003)
/* Error. */
#define MMI_IVC_ERR                   (-56004)

/*
 * Should not have bellow errors.
 */
/* The IVC handle is invalide. */
#define MMI_IVC_ERR_INVALID_HANDLE    (-56101)
/* The memory is not large enough. */
#define MMI_IVC_ERR_NOT_ENOUGH_MEM    (-56102)
/* Parameter is invalid. */
#define MMI_IVC_ERR_PARAM_ERR         (-56103)

/*
 * Invalid handle.
 */
#define MMI_IVC_INVALID_HANDLE        ((U32)NULL)

/*******************************************************************************
* Type Define
*******************************************************************************/

/*
 * Callback events.
 */
typedef enum
{
    /* Get app folder path. */
    MMI_IVC_EVENT_GET_FOLDER,

    /* Get specific filename. */
    MMI_IVC_EVENT_GET_FILE,

    /* Return decode result. */
    MMI_IVC_EVENT_DECODE
} mmi_ivc_event_enum;

/*
 * Parameter structure of callback event.
 */
typedef struct
{
    /* Event id, see mmi_ivc_event_enum. */
    U16 evt_id;

    /* Event structure size */
    U16 size;

    /* User data pointer */
    void *user_data;

    /* Parameters union */
    union
    {
        /* Parameters of MMI_IVC_EVENT_GET_FOLDER. */
        struct
        {
            /* Buffer for folder path. */
            WCHAR *folderPath;
        } folder;

        /* Parameters of MMI_IVC_EVENT_GET_FILE. */
        struct
        {
            /* Index of image. */
            U32 idx;

            /* Buffer for filename. */
            WCHAR *filepath;
        } file;

        /* Parameters of MMI_IVC_EVENT_DECODE. */
        struct
        {
            /* Index of image. */
            U32 idx;

            /* Result of decoding. */
            S32 result;
        } decode;
    } data;
} mmi_ivc_event_struct;

/*
 * IVC handle type
 */
typedef U32 MMI_IVC_HANDLE;

/*******************************************************************************
* Extern APIs
*******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_create
 * DESCRIPTION
 *  This function is used to create an instance of IVC.
 *
 *  Behavior
 *  1. It will check if the bufSize  is large enough for an IVC instance.
 *
 * PARAMETERS
 *  currIdx    :    [IN]    Current index.
 *  count      :    [IN]    Image count.
 *  runBufPtr  :    [IN]    Run buffer for IVC to use.
 *  runBufSize :    [IN]    Run buffer size.
 *  eventProc  :    [IN]    Handler of IVC events.
 *  userData   :    [IN]    User data.
 * RETURNS
 *  MMI_IVC_HANDLE. A hdl returned to caller, MMI_IVC_INVALID_HANDLE if failed
 *****************************************************************************/
extern MMI_IVC_HANDLE mmi_ivc_create(
                        U32 currIdx,
                        U32 count,
                        PU8 runBufPtr,
                        U32 runBufSize,
                        mmi_proc_func eventProc,
                        void *userData);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_destory
 * DESCRIPTION
 *  This function is used to destroy a created IVC instance.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The instance which should be destroyed.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_destory(MMI_IVC_HANDLE hdl);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_start
 * DESCRIPTION
 *  This function is used to start a created IVC instance.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The instance which should be started.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_start(MMI_IVC_HANDLE hdl);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_destory
 * DESCRIPTION
 *  This function is used to stop a created IVC instance.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The instance which should be stopped.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_stop(MMI_IVC_HANDLE hdl);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_add_memory
 * DESCRIPTION
 *  This function is used to add a piece of data buffer to IVC as specific use.
 *  APP should add memory before mmi_ivc_start.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *  2. It will check if bufSize is large enough
 *
 * PARAMETERS
 *  hdl     :   [IN]    The handle of specific IVC.
 *  type    :   [IN]    Which type of memory is adding.
 *  bufPtr  :   [IN]    Buffer ptr.
 *  bufSize :   [IN]    Buffer size.
 * RETURNS
 *  Return count of added cache unit
 *****************************************************************************/
extern S32 mmi_ivc_add_memory(MMI_IVC_HANDLE hdl, PU8 bufPtr, U32 bufSize);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_remove_memory
 * DESCRIPTION
 *  This function is used to remove a piece of data buffer from IVC.
 *  APP should remove memory after mmi_ivc_stop.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *  2. It will check if the buffer is used.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The handle of specific IVC.
 *  type    :   [IN]    Which type of memory is adding.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_remove_memory(MMI_IVC_HANDLE hdl, PU8 bufPtr);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_get_curr_img
 * DESCRIPTION
 *  This function is used to get the cached image from IVC.
 *  It is an asynchronous function, if curr img is not cached, it will dec it and cb.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The handle of specific IVC.
 *  dstLyr  :   [IN]    Destination layer handle.
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 mmi_ivc_get_curr_img(MMI_IVC_HANDLE hdl, GDI_HANDLE dstLyr);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_set_curr_idx
 * DESCRIPTION
 *  This function is used to set the current index to IVC.
 *  And it get the large cache index and L1 caches to start decode new images.
 *  It is a synchronous function.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The handle of specific IVC.
 *  idx     :   [IN]    New curr index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_set_curr_idx(MMI_IVC_HANDLE hdl, S32 idx);

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_query_img
 * DESCRIPTION
 *  This function is used to get the cached image from IVC.
 *  And it will draw the image to fit the dstLyr.
 *  It is a synchronous function, if curr img is not cached, it will not dec it and cb.
 *
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *
 * PARAMETERS
 *  hdl     :   [IN]    The handle of specific IVC.
 *  idx     :   [IN]    Index of specific image.
 *  dstLyr  :   [IN]    Destination layer handle.
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 mmi_ivc_query_img(MMI_IVC_HANDLE hdl, S32 idx, GDI_HANDLE dstLyr);
#endif /* defined(__MMI_IVF_CACHE__) */ 
#endif /* !defined(_IMG_VIEWER_DEC_GPROT_H_) */ 

