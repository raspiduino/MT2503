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
 * aud_recorder_modis.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of MoDIS recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    MoDIS Recorder
 * DESCRIPTION
 *    This module defines related function of MoDIS Recorder.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
/* system includes */
//#include "kal_release.h"
#include "kal_trace.h"
#include "kal_general_types.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"     /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"    /* Task creation */
//#include "app_buff_alloc.h" /* Declaration of buffer management API */
//#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h"     /* Event scheduler */
//#include "stack_timer.h"    /* Stack timer */
    
/* global includes */
//#include "l1audio.h"
    
/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_utility.h"
#include "aud_recorder.h"

#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

#if !defined(__MTK_TARGET__)

/* win32 */
#include <windows.h>
#include "w32_av_types.h"
#include "w32_av_lib.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_RECORDER_MODIS_TRACE(x, y, z)   AUD_RECORDER_MODIS_TRACE(x, y, z, __LINE__)

/* MoDIS Recorder */
typedef struct
{
    med_aud_recorder_t              itf;            /* Recorder interfaces */
    kal_int32                       file_handle;    /* File handle */
    kal_uint8                       state;          /* Recorder state */
    med_aud_recorder_cb_fct         cb_fct;         /* Callback when there is event arisen */
    void*                           cb_param;       /* Callback parameter */
} med_aud_recorder_modis_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_close
 * DESCRIPTION
 *  This function is used to close a MoDIS recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_close(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);
    
    /* Close file handle */
    if (self_p->file_handle >= 0)
    {
        FS_Close(self_p->file_handle);
        self_p->file_handle = -1;
    }

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_open
 * DESCRIPTION
 *  This function is used to open a MoDIS recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  cfg_p           [IN]        Recorder configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_open(med_aud_recorder_t* recorder_p, med_aud_recorder_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;
    kal_uint32                file_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    /* Open a file handle */
    MED_ASSERT(cfg_p->file_name != NULL);
    file_flag = FS_READ_WRITE | FS_OPEN_SHARED | FS_NOBUSY_CHECK_MODE; /* Disable Busy Check Mode For Record */
    
    self_p->file_handle = FS_Open(cfg_p->file_name, file_flag);
    
    if (self_p->file_handle < 0) /* File does not exist */
    {
        /* Create a new file */
        self_p->file_handle = FS_Open(cfg_p->file_name, FS_CREATE | file_flag);
    }

    _AUD_RECORDER_MODIS_TRACE(self_p->file_handle, recorder_p, -1);
    
    if (self_p->file_handle == FS_WRITE_PROTECTION)
    {
        return MED_RES_WRITE_PROTECTION;
    }
    else if (self_p->file_handle < 0)
    {
        return MED_RES_OPEN_FILE_FAIL;
    }
    
    /* Setup private data */
    self_p->state    = AUD_MEDIA_IDLE;
    self_p->cb_fct   = cfg_p->cb_fct;
    self_p->cb_param = cfg_p->cb_param;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_record
 * DESCRIPTION
 *  This function is used to start MoDIS recording.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_record(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    self_p->state = AUD_MEDIA_RECORD;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_stop
 * DESCRIPTION
 *  This function is used to stop MoDIS playback.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_stop(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    self_p->state = AUD_MEDIA_IDLE;

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_pause
 * DESCRIPTION
 *  This function is used to pause MoDIS playback.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_pause(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    self_p->state = AUD_MEDIA_RECORD_PAUSED;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_resume
 * DESCRIPTION
 *  This function is used to resume MoDIS playback.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_resume(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);
    
    self_p->state = AUD_MEDIA_RECORD;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_set
 * DESCRIPTION
 *  This function is used to set parameters to an MoDIS recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  set_type        [IN]        Set command.
 *  data_p          [IN]        The data relative to the command.
 *  date_len        [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_set(med_aud_recorder_t*    recorder_p,
                                         med_aud_recorder_set_t set_type,
                                         void*                  data_p,
                                         kal_uint32             data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;
    kal_int32                 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    _AUD_RECORDER_MODIS_TRACE(set_type, (kal_uint32)data_p, data_len);
    
    switch (set_type)
    {
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_get
 * DESCRIPTION
 *  This function is used to get parameters from an MoDIS recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  get_type        [IN]        Get command.
 *  data_p          [OUT]       The data relative to the command.
 *  data_len        [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_get(med_aud_recorder_t*    recorder_p,
                                         med_aud_recorder_get_t get_type,
                                         void*                  data_p,
                                         kal_uint32             data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;
    kal_int32                 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);

    switch (get_type)
    {
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_RECORDER_MODIS_TRACE(get_type, result, *((kal_uint32*)data_p));
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_destroy
 * DESCRIPTION
 *  This function is used to destroy a MoDIS recorder. Once called, all the 
 *  allocated interfaces of the recorder will be freed.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_modis_destroy(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL);
    self_p = PTHIS(recorder_p, med_aud_recorder_modis_t, itf);
    
    AUD_RECORDER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_recorder_modis_construct
 * DESCRIPTION
 *  This function is used to construct a MoDIS recorder.
 * PARAMETERS
 *  void
 * RETURNS
 *  Recorder handle.
 *****************************************************************************/
med_aud_recorder_t* aud_recorder_modis_construct(void)
{
#if !defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_modis_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_recorder_modis_t*) med_alloc_aud_mem(sizeof(med_aud_recorder_modis_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open     = _aud_recorder_modis_open;
    self_p->itf.close    = _aud_recorder_modis_close;
    self_p->itf.record   = _aud_recorder_modis_record;
    self_p->itf.stop     = _aud_recorder_modis_stop;
    self_p->itf.pause    = _aud_recorder_modis_pause;
    self_p->itf.resume   = _aud_recorder_modis_resume;
    self_p->itf.set      = _aud_recorder_modis_set;
    self_p->itf.get      = _aud_recorder_modis_get;
    self_p->itf.destroy  = _aud_recorder_modis_destroy;

    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ */
}

#endif /* MED_NOT_PRESENT */ 

