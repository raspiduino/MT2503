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

/*******************************************************************************
 * Filename:
 * ---------
 * mpl_clipper.h
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * This file defines Media Porting Layer interface of video clipper.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 02 2011 tofar.huang
 * removed!
 * .
 *
 * 11 22 2011 tofar.huang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MPL_CLIPPER_H
#define _MPL_CLIPPER_H

#include "mpl_common.h" // the common defition for MPL

/*****************************************************************************
 * DESCRIPTION
 *  Parameters of clipper interface 
 *****************************************************************************/
typedef enum 
{
    MPL_CLIPPER_PARAM_CURR_PROGRESS,        // [kal_uint32 *] To GET current progress percentage
    MPL_CLIPPER_PARAM_TOTAL_COUNT
}mpl_clipper_param_enum;


/*****************************************************************************
 * DESCRIPTION
 *  Clipper event type 
 *****************************************************************************/
typedef enum
{
    MPL_CLIPPER_EVENT_OPEN,     // open event callback
    MPL_CLIPPER_EVENT_START,    // start event callback
    MPL_CLIPPER_EVENT_STOP,     // stop event callback
    MPL_CLIPPER_EVENT_CLOSE,    // close event callback
    MPL_CLIPPER_EVENT_SAVE      // save event callback
} mpl_clipper_event_t;


/*****************************************************************************
 * DESCRIPTION
 *  Structure of open request
 *****************************************************************************/
typedef struct
{
    // Path information
    kal_wchar *pau2SrcPath;
    kal_wchar *pau2DstPath;
    kal_wchar *pau2WorkingPath;

    // time information
    kal_uint32 u4StartTime;
    kal_uint32 u4EndTime;
}mpl_clipper_open_t;


/*****************************************************************************
 * DESCRIPTION
 *  get_default request
 *****************************************************************************/
typedef enum
{
    MPL_CLIPPER_OPEN_PARAM
}mpl_clipper_param_type_enum;



/*****************************************************************************
 * DESCRIPTION
 *  Callback functions of open and play are defined here.
 *****************************************************************************/
typedef struct mpl_clipper_client_t mpl_clipper_client_t;
struct mpl_clipper_client_t
{
    // Memory allcator and free api.
    void* (*mem_alloc_func)(mpl_clipper_client_t *prClient, kal_uint32 u4Size, med_mem_type_enum eType, char* pau1File, long u4Line);
    void (*mem_free_func)(mpl_clipper_client_t *prClient, void** p, med_mem_type_enum eType, char* pau1File, long u4Line);

    // On event, when an opeartion is an async call, this must be called after the operation are finished.
    void (*on_event)(mpl_clipper_client_t *prClient, mpl_clipper_event_t eEvent, media_error_t eResult); 
};

/*****************************************************************************
 * DESCRIPTION
 *  This defines the interfaces which should be implemented to support basic functions of video clippper. 
 *****************************************************************************/
typedef struct mpl_clipper_t mpl_clipper_t;
struct mpl_clipper_t
{
    media_error_t (*open)(mpl_clipper_t* prItf, mpl_clipper_open_t* prOpenStruct); 
    media_error_t (*start)(mpl_clipper_t* prItf); 
    media_error_t (*cancel)(mpl_clipper_t* prItf); 
    media_error_t (*close)(mpl_clipper_t* prItf);
    media_error_t (*get_param)(mpl_clipper_t* prItf, mpl_clipper_param_enum eParam, void *pValue);   
    media_error_t (*set_param)(mpl_clipper_t* prItf, mpl_clipper_param_enum eParam, void *pValue);   
    void (*destroy)(mpl_clipper_t* prItf); 
    media_error_t (*get_default)(mpl_clipper_t *prItf, mpl_clipper_param_type_enum eParamType,
                                 void* prParam, kal_int32 u4Size);
};

extern mpl_clipper_t* construct_media_clipper(mpl_clipper_client_t* prClient);
extern void video_clipper_main(ilm_struct *prIlm);

#endif
