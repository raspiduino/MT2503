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
 *  ImgViewerCacheAdp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Adapter module of image viewer decoder.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#if defined(__MMI_IVF_CACHE_ADP__)
#include "Unicodexdcl.h"        /* mmi_wcsxxxx */
#include "Math.h"       /* sqrt */
#include "gui.h"        /* gui timer */
#include "mmi_frm_events_gprot.h"       /* MMI_FRM_INIT_EVENT */
#include "FileMgrType.h"        /* FMGR_LIMIT_IMAGE_VIEWER */
#include "FileMgrGProt.h"       /* mmi_fmgr_util_file_limit_check */
#include "DebugInitDef_Int.h"   /* MMI_TRACE */
#include "ImgviewerGprot.h"     /* mmi_imgview_adjust_resize_size */
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"          /* DRM_is_drm_file */
#endif

#define __IVCMODULE__ "Adp"

/* GDI non-blocking decode callback.
   Caution: cause no userData in GDI, so keep current adp pointer in g_ivc_adp_p, this is dangers. */
static mmi_ivc_adp_cntx_struct *g_ivc_adp_p;

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_gdi_dec_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  gdiHdl      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_gdi_dec_cb(GDI_RESULT result, GDI_HANDLE gdiHdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_adp_cntx_struct *adp = g_ivc_adp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_GDI_DEC_CB, result, gdiHdl);
    IVC_PMD_STOP("ade");

    if (NULL != adp && adp->dec.hdl == gdiHdl)
    {
        S32 decRet = MMI_IVC_ERR_GDI_ERR;

        /* Free the cell layer and reset decHdl imediately after decode done */
        adp->dec.hdl = GDI_NULL_HANDLE;
        mmi_ivc_adp_cell_free_layer(adp->dec.cell);

        if (GDI_SUCCEED == result)
        {
        #if defined(__MMI_IVC_DB_DEBUG__)
            WCHAR IDX[4];

            kal_wsprintf(IDX, "%d", (adp->dec.cell->idx + 1));
            mmi_ivc_adp_cell_create_layer(adp->dec.cell);
            gdi_layer_push_and_set_active(adp->dec.cell->imgLyr);
            gui_set_text_color(gui_color(255, 0, 0));
            gui_move_text_cursor(5, 0);
            gui_print_text(IDX);
            gdi_layer_pop_and_restore_active();
            mmi_ivc_adp_cell_free_layer(adp->dec.cell);
        #endif /* defined(__MMI_IVC_DB_DEBUG__) */

            decRet = MMI_IVC_OK;
        }

        if (NULL != adp->dec.cb)
        {
            adp->dec.cb(decRet, adp->dec.userData);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_dec_img
 * DESCRIPTION
 *  Decode image from filepath.
 * PARAMETERS
 *  filepath        [?]     
 *  adp             [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_dec_img(WCHAR *filepath, mmi_ivc_adp_cntx_struct *adp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Caution: create layer here, free layer when decode done and ADP stop. */
    mmi_ivc_adp_cell_create_layer(adp->dec.cell);
    gdi_layer_clear_nb_concurrent(adp->dec.cell->imgLyr, GDI_COLOR_BLACK);

    IVC_PMD_START("afd");
    adp->dec.hdl = gdi_imgdec_nb_draw_resized_file(
        adp->dec.cell->imgLyr,
        0,
        0,
        adp->dec.cell->resizedW,
        adp->dec.cell->resizedH,
        (U8*)filepath,
        mmi_ivc_adp_gdi_dec_cb);
    IVC_PMD_STOP("afd");
    IVC_PMD_START("ade");

    g_ivc_adp_p = adp;

    MMI_IVC_TRACE(
        MMI_IVC_TRACE_GROUP,
        MMI_TRC_IVC_ADP_DEC_IMG,
        adp->dec.cell->idx,
        adp->dec.cell->resizedW,
        adp->dec.cell->resizedH,
        adp->dec.hdl);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_calc_resized_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  orgW            [IN]
 *  orgH            [IN]
 *  resizedW        [OUT]
 *  resizedH        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_calc_resized_size(S32 orgW, S32 orgH, S32 *resizedW, S32 *resizedH)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 expectSize = orgW * orgH * MMI_IVC_BYTES_PER_PIXEL;
    S32 actualSize = MMI_IVC_FULL_SCR_BUF_SIZE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (actualSize < expectSize)
    {
        U32 ratio = (U32) sqrt((actualSize * MMI_IVC_RATIO_MULTIPLE * MMI_IVC_RATIO_MULTIPLE) / expectSize);

        *resizedW = (S32) (ratio * orgW / MMI_IVC_RATIO_MULTIPLE);
        *resizedH = (S32) (ratio * orgH / MMI_IVC_RATIO_MULTIPLE);
    }
    else
    {
        *resizedW = orgW;
        *resizedH = orgH;
    }
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_CALC_RESIZED_SIZE, orgW, orgH, *resizedW, *resizedH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_cell_init_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [?]     
 *  cell            [?]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_ivc_adp_cell_init_info(WCHAR *filepath, mmi_ivc_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* error_str_ptr;
    MMI_BOOL limitRet = MMI_FALSE;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IVC_PMD_START("aci");
    IVC_PMD_START("alc");
    limitRet = (MMI_BOOL) mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) filepath, &error_str_ptr);
    IVC_PMD_STOP("alc");
    if (limitRet == MMI_TRUE)
    {
        WCHAR *filenamePtr;
        GDI_RESULT  ret;

        /* DRM */
    #ifdef __DRM_SUPPORT__
        if (DRM_is_drm_file(NULL, filepath))
        {
            cell->flag |= MMI_IVC_CELL_FLAG_DRM;
        }
    #endif

        /* Size and type */
        ret = IVC_PMD_GDI_GET_DIM((CHAR*) filepath, &cell->orgW, &cell->orgH);
        cell->imgType = IVC_PMD_GDI_GET_TYPE((CHAR*) filepath);
        if ((GDI_SUCCEED == ret && GDI_IMAGE_TYPE_INVALID != cell->imgType) &&
            ((cell->orgW > 0) && (cell->orgH > 0)) &&
            ((cell->orgW <= IV_MAX_IMG_SIZE) && (cell->orgH <= IV_MAX_IMG_SIZE)))
        {
            /* Filename */
            filenamePtr = srv_fmgr_path_get_filename_ptr(filepath);
            if (MMI_IVC_DB_FILENAME_LEN >= mmi_wcslen(filenamePtr))
                mmi_wcscpy(cell->filename, filenamePtr);

            /* Resize */
            mmi_ivc_adp_calc_resized_size(cell->orgW, cell->orgH, &cell->resizedW, &cell->resizedH);
            mmi_imgview_adjust_resize_size(cell->imgType, &cell->resizedW, &cell->resizedH);

            result = MMI_TRUE;
        }
    }
    IVC_PMD_STOP("aci");
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_get_file_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  userData        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_get_file_cyclic(void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = (mmi_ivc_instance_struct*) userData;
    mmi_ivc_event_struct    evt;
    S32                     ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, MMI_IVC_EVENT_GET_FILE);
    evt.data.file.idx = ins->adp.getPath.file.idx;
    evt.data.file.filepath = ins->adp.getPath.file.path;
    ret = mmi_ivc_adp_send_event(ins, &evt);

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_GET_FILE_CYCLIC, ins->adp.getPath.file.idx, ret);

    if (MMI_IVC_LOADING == ret)
        gui_start_timer_ex(MMI_IVC_ADP_GET_PATH_TIMER_DURATION, mmi_ivc_adp_get_file_cyclic, (void*)ins);
    else
    {
        mmi_ivc_adp_cntx_struct *adp = &ins->adp;

        if (MMI_IVC_OK == ret)
        {
            ret = MMI_IVC_ERR_GDI_ERR;
            if (MMI_TRUE == mmi_ivc_adp_cell_init_info(adp->getPath.file.path, adp->dec.cell))
            {
            #if defined(__MMI_IVF_CACHE_DB__)
                if (NULL != adp->dec.preDecCb)
                {
                    adp->dec.preDecCb(adp->getPath.file.path, adp->dec.userData);
                }
            #endif /* defined(__MMI_IVF_CACHE_DB__) */ 
                mmi_ivc_adp_dec_img(adp->getPath.file.path, adp);
                return;
            }
        }
        adp->dec.cb(ret, adp->dec.userData);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_get_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]         
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_get_file(mmi_ivc_instance_struct *ins, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Current get file action may be interrupted by some actions, like set_curr_idx
       When it is interrupted, should stop curr get file timer, or will cause err. */
    gui_cancel_timer((FuncPtr) mmi_ivc_adp_get_file_cyclic);

    ins->adp.getPath.file.idx = idx;

    mmi_ivc_adp_get_file_cyclic((void*)ins);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_get_folder_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  userData        [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_adp_get_folder_cyclic(void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_instance_struct *ins = (mmi_ivc_instance_struct*) userData;
    mmi_ivc_event_struct    evt;
    S32                     ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, MMI_IVC_EVENT_GET_FOLDER);
    evt.data.folder.folderPath = ins->adp.getPath.folder.path;

    ret = mmi_ivc_adp_send_event(ins, &evt);

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_GET_FOLDER_CYCLIC, ret);

    if (MMI_IVC_LOADING == ret)
        gui_start_timer_ex(MMI_IVC_ADP_GET_PATH_TIMER_DURATION, mmi_ivc_adp_get_folder_cyclic, (void*)ins);
    else if (ins->adp.getPath.folder.cb)
    {
        ins->adp.getPath.folder.cb(ins->adp.getPath.folder.path, ins->adp.getPath.folder.userData);
    }
    ins->adp.getPath.folder.cb = NULL;
    ins->adp.getPath.folder.userData = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_cell_cancel_dec
 * DESCRIPTION
 *  Cancel decode curr image.
 * PARAMETERS
 *  ins             [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_cell_cancel_dec(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_adp_cntx_struct *adp = &ins->adp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != adp->dec.cell && GDI_NULL_HANDLE != adp->dec.hdl)
    {
        MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_CANCEL_DEC_IMG, adp->dec.hdl);
        IVC_PMD_STOP("ade");
        IVC_PMD_START("acd");
        gdi_imgdec_nb_stop(adp->dec.hdl);
        IVC_PMD_STOP("acd");
        mmi_ivc_adp_cell_free_layer(adp->dec.cell);
        adp->dec.hdl = GDI_NULL_HANDLE;
        g_ivc_adp_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_cell_dec_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins             [?]         
 *  cell            [?]         
 *  preDecCb        [IN]        
 *  cb              [IN]        
 *  userData        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_cell_dec_cell(
                mmi_ivc_instance_struct *ins,
                mmi_ivc_cell_struct *cell,
                mmi_ivc_preDec_cb preDecCb,
                mmi_ivc_dec_cb cb,
                void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_adp_cntx_struct *adp = &ins->adp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_ADP_CELL_DEC_CELL, cell->idx, cell->flag);

    mmi_ivc_adp_cell_cancel_dec(ins);

    adp->dec.cell = cell;
#if defined(__MMI_IVF_CACHE_DB__)
    adp->dec.preDecCb = preDecCb;
#endif 
    adp->dec.cb = cb;
    adp->dec.userData = userData;

    mmi_ivc_adp_get_file(ins, cell->idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_cell_create_layer_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell        [?]         
 *  file_p      [?]         
 *  line_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_cell_create_layer_ext(mmi_ivc_cell_struct *cell
#if defined(__MMI_IVC_LAYER_DEBUG__)
                                              , char *file_p, long line_p
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IVC_LAYER_DEBUG__)
    WCHAR filename[256];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LAYER_EMPTY_HANDLE != cell->imgLyr)
        return;
    gdi_layer_create_cf_using_outside_memory(
        MMI_IVC_CF,
        0,
        0,
        cell->resizedW,
        cell->resizedH,
        &cell->imgLyr,
        cell->bufPtr,
        MMI_IVC_FULL_SCR_BUF_SIZE);
#if defined(__MMI_IVC_LAYER_DEBUG__)
    kal_wsprintf(filename, "%d-%s-%s-%d-%02X.jpg", cell->idx, file_p, "create", line_p, cell->flag);
    gdi_image_encode_layer_to_jpeg(cell->imgLyr, (CHAR*) filename);
#endif /* defined(__MMI_IVC_LAYER_DEBUG__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_cell_free_layer_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell        [?]         
 *  file_p      [?]         
 *  line_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_cell_free_layer_ext(mmi_ivc_cell_struct *cell
#if defined(__MMI_IVC_LAYER_DEBUG__)
                                            , char *file_p, long line_p
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IVC_LAYER_DEBUG__)
    WCHAR filename[256];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LAYER_EMPTY_HANDLE == cell->imgLyr)
        return;
#if defined(__MMI_IVC_LAYER_DEBUG__)
    kal_wsprintf(filename, "%d-%s-%s-%d-%02X.jpg", cell->idx, file_p, "free", line_p, cell->flag);
    gdi_image_encode_layer_to_jpeg(cell->imgLyr, (CHAR*)filename);
#endif /* defined(__MMI_IVC_LAYER_DEBUG__) */ 
    gdi_layer_free(cell->imgLyr);
    cell->imgLyr = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_get_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins             [IN]
 *  cb              [IN]
 *  userData        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_get_folder(mmi_ivc_instance_struct *ins, mmi_ivc_get_folder_cb cb, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ins->adp.getPath.folder.cb = cb;
    ins->adp.getPath.folder.userData = userData;
    mmi_ivc_adp_get_folder_cyclic((void*)ins);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins             [?]         
 *  runBufPtr       [IN]        
 *  runBufSize      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_init(mmi_ivc_instance_struct *ins, PU8 runBufPtr, U32 runBufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&ins->adp, 0, sizeof(mmi_ivc_adp_cntx_struct));
    MMI_IVC_FILE_IDX_RESET(ins->adp.getPath.file.idx);

    mmi_ivc_mgr_init(ins, runBufPtr, runBufSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_adp_stop(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer((FuncPtr) mmi_ivc_adp_get_file_cyclic);
    mmi_ivc_adp_cell_cancel_dec(ins);
    mmi_ivc_mgr_stop(ins);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_adp_send_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]     
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
extern S32 mmi_ivc_adp_send_event(mmi_ivc_instance_struct *ins, mmi_ivc_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(
        MMI_IVC_TRACE_GROUP,
        MMI_TRC_IVC_ADP_SEND_EVENT,
        evt->evt_id,
        evt->data.decode.idx,
        evt->data.decode.result);

    evt->user_data = ins->userData;
    return ins->eventProc((mmi_event_struct*) evt);
}


#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif


#endif /* defined(__MMI_IVF_CACHE_ADP__) */ 

