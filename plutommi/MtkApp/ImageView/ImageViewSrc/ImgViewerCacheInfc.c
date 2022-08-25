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
 *  ImgViewerCacheInfc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface layer of image viewer decoder.
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
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#include "ImgViewerCache.h"
#if defined(__MMI_IVF_CACHE__)
#include "DebugInitDef_Int.h"   /* MMI_TRACE */

#define MMI_IVC_INFC_GET_INSTANCE(hdl)    (mmi_ivc_infc_get_instance(hdl))
#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_infc_get_instance
 * DESCRIPTION
 *  This function is used to get IVC instance from handle.
 *
 *  Behavior
 *  1. It will convert IVC handle to instance struct.
 *  2. Check if the instance is a valid instance.
 * PARAMETERS
 *  hdl     [IN]
 * RETURNS
 *  Specific instance struct pointer.
 *****************************************************************************/
static mmi_ivc_instance_struct *mmi_ivc_infc_get_instance(MMI_IVC_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = (mmi_ivc_instance_struct*) hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ins);
    return ins;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_create
 * DESCRIPTION
 *  This function is used to create an instance of IVC.
 *  
 *  Behavior
 *  1. It will check if the bufSize  is large enough for an IVC instance.
 * PARAMETERS
 *  currIdx         [IN]        Current index.
 *  count           [IN]        Image count.
 *  runBufPtr       [IN]        Run buffer for IVC to use.
 *  runBufSize      [IN]        Run buffer size.
 *  eventProc       [IN]        Handler of IVC events.
 *  userData        [?]         User data.
 *  appID(?)                The appID is used to create working folder.(?)
 * RETURNS
 *  MMI_IVC_HANDLE. A hdl returned to caller, MMI_IVC_INVALID_HANDLE if failed
 *****************************************************************************/
extern MMI_IVC_HANDLE mmi_ivc_create(
                        U32 currIdx,
                        U32 count,
                        PU8 runBufPtr,
                        U32 runBufSize,
                        mmi_proc_func eventProc,
                        void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins;
    PU8 cacheRunBufPtr;
    U32 cacheRunBufSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_CREATE, currIdx, count, runBufPtr, runBufSize);

    if (MMI_IVC_INSTANCE_SIZE > runBufSize)
    {
        /* Memory not enough */
        return MMI_IVC_INVALID_HANDLE;
    }

    if (currIdx >= count)
    {
        /* Parameter err */
        return MMI_IVC_INVALID_HANDLE;
    }

    /* Init instance */
    ins = (mmi_ivc_instance_struct*) runBufPtr;
    ins->pattenStart = ins->pattenEnd = MMI_IVC_PATTEN_VALID;
    ins->state = MMI_IVC_STATE_STOPPED;
    ins->currIdx = currIdx;
    ins->count = count;
    ins->eventProc = eventProc;
    ins->userData = userData;

    cacheRunBufPtr = (PU8) (ins + 1);
    cacheRunBufSize = runBufSize - MMI_IVC_INSTANCE_SIZE;
    mmi_ivc_adp_init(ins, cacheRunBufPtr, cacheRunBufSize);

    return (MMI_IVC_HANDLE) ins;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_destory
 * DESCRIPTION
 *  This function is used to destroy a created IVC instance.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 * PARAMETERS
 *  hdl     [IN]        The instance which should be destroyed.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_destory(MMI_IVC_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_DESTORY, hdl);

    if (MMI_IVC_STATE_STOPPED != ins->state)
        mmi_ivc_stop(hdl);
    mmi_ivc_adp_deinit(ins);
    ins->pattenStart = ins->pattenEnd = MMI_IVC_PATTEN_INVALID;
    ins->state = MMI_IVC_STATE_DESTORIED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_start
 * DESCRIPTION
 *  This function is used to start a created IVC instance.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 * PARAMETERS
 *  hdl     [IN]        The instance which should be started.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_start(MMI_IVC_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_START, hdl);

    if (MMI_IVC_STATE_RUNNING == ins->state)
        return;
    mmi_ivc_adp_start(ins);
    ins->state = MMI_IVC_STATE_RUNNING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_stop
 * DESCRIPTION
 *  This function is used to stop a created IVC instance.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 * PARAMETERS
 *  hdl     [IN]        The instance which should be stopped.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_stop(MMI_IVC_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_STOP, hdl);

    mmi_ivc_adp_stop(ins);
    ins->state = MMI_IVC_STATE_STOPPED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_add_memory
 * DESCRIPTION
 *  This function is used to add a piece of data buffer to IVC as specific use.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *  2. It will check if bufSize is large enough
 * PARAMETERS
 *  hdl         [IN]        The handle of specific IVC.
 *  bufPtr      [IN]        Buffer ptr.
 *  bufSize     [IN]        Buffer size.
 * RETURNS
 *  Return count of added cache unit
 *****************************************************************************/
extern S32 mmi_ivc_add_memory(MMI_IVC_HANDLE hdl, PU8 bufPtr, U32 bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_ADD_MEMORY, hdl, bufPtr, bufSize);

    if (MMI_IVC_STATE_STOPPED != ins->state)
        return 0;
    return mmi_ivc_adp_add_memory(ins, bufPtr, bufSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_remove_memory
 * DESCRIPTION
 *  This function is used to remove a piece of data buffer from IVC.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 *  2. It will check if the buffer is used.
 * PARAMETERS
 *  hdl         [IN]        The handle of specific IVC.
 *  bufPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_remove_memory(MMI_IVC_HANDLE hdl, PU8 bufPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_REMOVE_MEMORY, hdl, bufPtr);

    if (MMI_IVC_STATE_STOPPED != ins->state)
        return;
    mmi_ivc_adp_remove_memory(ins, bufPtr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_get_curr_img
 * DESCRIPTION
 *  This function is used to get the cached image from IVC.
 *  It is an asynchronous function, if curr img is not cached, it will dec it and cb.
 *  
 *  Behavior
 *  1. It will check if the specific instance handle is a valid instance.
 * PARAMETERS
 *  hdl         [IN]        The handle of specific IVC.
 *  dstLyr      [IN]        Destination layer handle.
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 mmi_ivc_get_curr_img(MMI_IVC_HANDLE hdl, GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_GET_CURR_IMG, hdl, ins->currIdx, dstLyr);

    return mmi_ivc_adp_get_curr_img(ins, dstLyr);
}


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
 * PARAMETERS
 *  hdl     [IN]        The handle of specific IVC.
 *  idx     [IN]        New curr index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_set_curr_idx(MMI_IVC_HANDLE hdl, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_SET_CURR_IDX, hdl, idx);

    ins->currIdx = idx;
    mmi_ivc_adp_set_curr_idx(ins, idx);
}


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
 * PARAMETERS
 *  hdl         [IN]        The handle of specific IVC.
 *  idx         [IN]        Index of specific image.
 *  dstLyr      [IN]        Destination layer handle.
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 mmi_ivc_query_img(MMI_IVC_HANDLE hdl, S32 idx, GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = MMI_IVC_INFC_GET_INSTANCE(hdl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_INFC_QUERY_IMG, hdl, idx);

    return mmi_ivc_adp_query_img(ins, idx, dstLyr);
}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

#endif /* defined(__MMI_IVF_CACHE__) */ 

