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
 *  EngineerModeVOIP.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intend for engineer mode VOIP.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "MMI_include.h"

#ifdef __MMI_ENGINEER_MODE__ 

#include "CommonScreens.h"

#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"

#include "EngineerModeCommUI.h"
#include "EngineerModeVOIP.h"

#if defined(__VOIP__)
#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

#include "voip_custom_api.h"
#include "SettingDefs.h"                /* ST_NOTIFYDURATION define */
#include "FileMgr.h"
#include "fmt_struct.h"
#include "mmi2voip_enums.h"
#include "mmi2voip_struct.h"
#include "Asciiprot.h"
#include "GpioSrvGprot.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#if defined(__VOIP__)

typedef struct {

    S32     currP2Pcall;
    S32     currUASRefresher;
    S32     currUACRefresher;
    S32     currRPortSupport;
    U8      reregister_timer[12];
    U8      call_refresh_timer[12];
    U8      refer_sub_timer[12];
    U8      mwi_sub_timer[12];
    U8      mwi_retry_time[6];
    U8      *pEMVOIPP2PCall[2];
    U8      *pEMVOIPUASRefresher[2];
    U8      *pEMVOIPRportSupport[2];
    U8      EMVOIPLocalAddr[42];
    UI_character_type input_buf[VOIP_CUST_STR_LEN*2];     
} em_voip_struct;

em_voip_struct g_em_voip_cntx={0};

#ifdef __MMI_EM_UT_VOIP__
typedef struct 
{
    S32     call_id;
    S32     dialog_id;
    S32     status;
    S8      filename[FMGR_PATH_BUFFER_SIZE];
} em_voip_log_call_status_struct;
#endif /* __MMI_EM_UT_VOIP__ */

typedef struct 
{
    S32     curr_log_activate;
    S32     curr_log_storage;
    S32     curr_log_del_time;
    S32     hili_log_activate;
    S32     hili_log_storage;
    S32     hili_log_del_time;
    S32     delete_all;
    S32     interrupt;
#ifdef __MMI_EM_UT_VOIP__
    em_voip_log_call_status_struct call_status[EM_VOIP_LOG_MAX_CALL];
    U8      *em_voip_log_activate[EM_VOIP_LOG_ACTIVATE_TOTAL];
    S8      filepath[FMGR_PATH_BUFFER_SIZE];
    U8      *em_voip_log_delete[EM_VOIP_LOG_AUTO_DELETE_TOTAL];
    U8      dirpath[EM_VOIP_LOG_MAX_DIR_PATH];
#endif /* __MMI_EM_UT_VOIP__ */
} em_voip_log_struct;

em_voip_log_struct g_em_voip_log_cntx={0};

extern S8 nPrintableStr[];
extern pBOOL IsBackHistory;
#endif /*  __VOIP__ */

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

#define EM_VOIP_LOG
/*-----------------------------------------------------------------------------*/
/*------------------------- Debug info -> FS trace  ---------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __VOIP__
/*****************************************************************************
 * FUNCTION
 *  em_voip_log_init
 * DESCRIPTION
 *  initialize the voip log mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void em_voip_log_init(void)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 voip_log_storage;
    S16 error;
    S32 ret_code;
    FS_HANDLE h_file;


   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize VOIP log setting parameters */
    ReadValue(NVRAM_VOIP_LOG_ACTIVATE, &g_em_voip_log_cntx.curr_log_activate, DS_BYTE, &error);
    if ((g_em_voip_log_cntx.curr_log_activate & 0x000000ff) == 0x000000ff) /* initial value is 0xff */
    {
        g_em_voip_log_cntx.curr_log_activate = 0;
        WriteValue(NVRAM_VOIP_LOG_ACTIVATE, &g_em_voip_log_cntx.curr_log_activate, DS_BYTE, &error);
    }

    ReadValue(NVRAM_VOIP_LOG_STORAGE, &g_em_voip_log_cntx.curr_log_storage, DS_BYTE, &error);
    if ((g_em_voip_log_cntx.curr_log_storage & 0x000000ff) == 0x000000ff) /* initial value is 0xff */
    {
        g_em_voip_log_cntx.curr_log_storage = 0;
        WriteValue(NVRAM_VOIP_LOG_STORAGE, &g_em_voip_log_cntx.curr_log_storage, DS_BYTE, &error);
    }

    ReadValue(NVRAM_VOIP_LOG_DELETE_TIME, &g_em_voip_log_cntx.curr_log_del_time, DS_BYTE, &error);
    if ((g_em_voip_log_cntx.curr_log_del_time & 0x000000ff) == 0x000000ff) /* initial value is 0xff */
    {
        g_em_voip_log_cntx.curr_log_del_time = 0;
        WriteValue(NVRAM_VOIP_LOG_DELETE_TIME, &g_em_voip_log_cntx.curr_log_del_time, DS_BYTE, &error);
    }
 
    memset(g_em_voip_log_cntx.call_status, 0xFF, 
        (sizeof(em_voip_log_call_status_struct) * EM_VOIP_LOG_MAX_CALL));
 
    mmi_fmgr_get_full_storage_inline_list(0, NULL, NULL,NULL);
    mmi_fmgr_get_drive_letter_by_inline_index(
        (U8)g_em_voip_log_cntx.curr_log_storage, (PS8)&voip_log_storage);
    

    kal_wsprintf((kal_wchar*)g_em_voip_log_cntx.dirpath, "%c:\\", (S8) voip_log_storage);
    mmi_ucs2cat((S8*)g_em_voip_log_cntx.dirpath, (const S8*)EM_VOIP_LOG_DIR_PATH);

    /* create the log folder */
    h_file = FS_Open((WCHAR *)g_em_voip_log_cntx.dirpath, FS_OPEN_DIR | FS_READ_ONLY);
    
    if ((h_file == FS_FILE_NOT_FOUND) || (h_file == FS_PATH_NOT_FOUND))
    {
        ret_code = FS_CreateDir((WCHAR *)g_em_voip_log_cntx.dirpath);

        if(ret_code < 0)
        {
            return;
        }
    }
    else
    {
        FS_Close(h_file);
    }    

    /* check and delete outdated logs */
    em_voip_log_check_and_delete();
#else /*__MMI_EM_UT_VOIP__ */
	  return;
#endif /* !__MMI_EM_UT_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_check_activate_status
 * DESCRIPTION
 *  return the activation status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL em_voip_log_check_activate_status(void)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_em_voip_log_cntx.curr_log_activate > 0) ? MMI_TRUE : MMI_FALSE);
#else
    return MMI_TRUE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_change_id
 * DESCRIPTION
 * change the call id and dialog id
 * PARAMETERS
 *  ori_id       [IN]   original identification
 *  new_id       [IN]   new identification
 * RETURNS
 *  void
 *****************************************************************************/
void em_voip_log_change_id(void* ori_id, void* new_id)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    voip_call_id_struct *voip_ori_id = (voip_call_id_struct *)ori_id;
    voip_call_id_struct *voip_new_id = (voip_call_id_struct *)new_id;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.curr_log_activate > 0)
    {
        /* free the used record */
        for (i = 0; i < EM_VOIP_LOG_MAX_CALL; i++)
        {
            if ((g_em_voip_log_cntx.call_status[i].call_id == voip_ori_id->call_id) &&
               (g_em_voip_log_cntx.call_status[i].dialog_id == voip_ori_id->dialog_id))
            {     
                g_em_voip_log_cntx.call_status[i].call_id = voip_new_id->call_id;
                g_em_voip_log_cntx.call_status[i].dialog_id = voip_new_id->dialog_id;
                break;
            }
        } 
    }

    return;  
#else /* __MMI_EM_UT_VOIP__ */
    return;
#endif /* !__MMI_EM_UT_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_save
 * DESCRIPTION
 * save the log data
 * PARAMETERS
 *  id           [IN]   call identification
 *  buf          [IN]   buffer
 *  buf_len      [IN]   buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void em_voip_log_save(void* id, void *buf, S32 buf_len)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h_file;
    S32 i;
    S32 len = 0;
    S32 ret = 0;
    kal_wchar filename[FMGR_MAX_FILE_LEN];
    voip_call_id_struct *call = (voip_call_id_struct *)id;
    S32 call_id;
    S32 dialog_id;
    S8 log_date[100];
    MYTIME current_time;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.curr_log_activate > 0)
    {
        GetDateTime(&current_time);
                    sprintf(
                        (PS8) log_date,
                        "\n%04d-%02d-%02d %02d:%02d:%02d\n",
                        current_time.nYear,current_time.nMonth, current_time.nDay, 
                        current_time.nHour, current_time.nMin, current_time.nSec);
                    
        if ( call != NULL)
        {
            /* Normal case */
            call_id = (S32)call->call_id;
            dialog_id = (S32)call->dialog_id;
            
            for (i = 0; i < EM_VOIP_LOG_MAX_CALL; i++)
            {
                if ((g_em_voip_log_cntx.call_status[i].call_id == call_id) &&
                   (g_em_voip_log_cntx.call_status[i].dialog_id == dialog_id))
                {     
                    if (g_em_voip_log_cntx.call_status[i].status == FS_NO_ERROR)
                    {
                        break;
                    }
                    else
                    {
                        return;
                    }
                }
            }

            if(i >= EM_VOIP_LOG_MAX_CALL)
            {
                return;
            }

            if (mmi_ucs2cmp((PS8)g_em_voip_log_cntx.call_status[i].filename, (PS8)L"") != 0)
            {  
                h_file = FS_Open((U16*) g_em_voip_log_cntx.call_status[i].filename, FS_READ_WRITE);
                
                if (h_file > 0)
                {
                        
                    FS_Seek(h_file, 0, FS_FILE_END);
                      
                    g_em_voip_log_cntx.call_status[i].status = 
                        FS_Write(h_file, log_date, AsciiStrlen((const S8*)log_date), (UINT *)&len);
                    if(g_em_voip_log_cntx.call_status[i].status == FS_NO_ERROR)
                    {
                        g_em_voip_log_cntx.call_status[i].status = 
                            FS_Write(h_file, buf, buf_len, (UINT *)&len);
                    }
                   
                    FS_Close(h_file);
                }
        
            }
        }
        else
        {
            /* for special case */
            
            /* create the log folder if it is not created during initialization */
            h_file = FS_Open((WCHAR *)g_em_voip_log_cntx.dirpath, FS_OPEN_DIR | FS_READ_ONLY);
            if ((h_file == FS_FILE_NOT_FOUND) || (h_file == FS_PATH_NOT_FOUND))
            {
        
                ret = FS_CreateDir((WCHAR *)g_em_voip_log_cntx.dirpath);
            
                if (ret < 0)
                {
                    DisplayPopup(
                        (PU8) GetString(GetFileSystemErrorString(ret)),
                        IMG_GLOBAL_ERROR,
                        0,
                        1000,
                        ERROR_TONE);
                
                    return;
                }
            }
            else
            {
                FS_Close(h_file);
            }    
            
            memset(filename, 0, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);
            mmi_ucs2cpy((S8*)filename, (S8*)g_em_voip_log_cntx.dirpath);
            mmi_ucs2cat((S8*)filename, (const S8*)EM_VOIP_LOG_TEMP_FILE);
            
            /* check to see if this special file has been created */
            h_file = FS_Open((WCHAR *)filename, FS_READ_WRITE);
            if (h_file < 0)
            {
                /* file does not exist */
                h_file = FS_Open((WCHAR *)filename, FS_CREATE | FS_READ_WRITE);

                if (h_file > 0)
                {
                    ret = FS_Write(h_file, log_date, AsciiStrlen((const S8*)log_date), (UINT *)&len);

                    if (ret == FS_NO_ERROR)
                    {
                        ret = FS_Write(h_file, buf, buf_len, (UINT *)&len);
                    }

                    if (ret < 0)
                    {
                        DisplayPopup(
                        (PU8) GetString(GetFileSystemErrorString(ret)),
                        IMG_GLOBAL_ERROR,
                        0,
                        1000,
                        ERROR_TONE);
                    }

                    FS_Close(h_file);
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(GetFileSystemErrorString(h_file)),
                        IMG_GLOBAL_ERROR,
                        0,
                        1000,
                        ERROR_TONE);
                }
            }
            else
            {
                /* file has already existed */
                if (FS_Seek(h_file, 0, FS_FILE_BEGIN) >= 0)
                {
                    if (FS_Truncate(h_file) == FS_NO_ERROR)
                    {
                        ret = FS_Write(h_file, log_date, AsciiStrlen((const S8*)log_date), (UINT *)&len);
                        if (ret == FS_NO_ERROR)
                        {
                            ret = FS_Write(h_file, buf, buf_len, (UINT *)&len);
                        }

                        if (ret < 0)
                        {
                            DisplayPopup(
                            (PU8) GetString(GetFileSystemErrorString(ret)),
                            IMG_GLOBAL_ERROR,
                            0,
                            1000,
                            ERROR_TONE);
                        }
                    }
                }
                
                FS_Close(h_file);
            }    
            
        }
    }

    return;
#else /* __MMI_EM_UT_VOIP__ */
    return;
#endif /* !__MMI_EM_UT_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_call_start
 * DESCRIPTION
 * called when the call is started
 * PARAMETERS
 *  id       [IN]   call identification
 *  mdir     [IN]   message direction
 * RETURNS
 *  void
 ******************************************************************************/
void em_voip_log_call_start( void* id, MMI_BOOL mdir)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h_file;
    MYTIME current_time;
    S8 filename[FMGR_PATH_BUFFER_SIZE];
    S32 i;
    voip_call_id_struct *call = (voip_call_id_struct*)id;
    S32 call_id = (S32)call->call_id;
    S32 dialog_id = (S32)call->dialog_id;
    S32 ret;
    S32 free_slot = -1; /* no free slot */
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.curr_log_activate > 0)
    {
        /* create the log folder if it is not created during initialization */
        h_file = FS_Open((WCHAR *)g_em_voip_log_cntx.dirpath, FS_OPEN_DIR | FS_READ_ONLY);
        if ((h_file == FS_FILE_NOT_FOUND) || (h_file == FS_PATH_NOT_FOUND))
        {
        
            ret = FS_CreateDir((WCHAR *)g_em_voip_log_cntx.dirpath);
            if (ret < 0)
            {
                DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(ret)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    ERROR_TONE);
                
                return;
            }
        }
        else
        {
            FS_Close(h_file);
        }    
    
        for (i = 0; i < EM_VOIP_LOG_MAX_CALL; i++)
        {
            if ((g_em_voip_log_cntx.call_status[i].call_id == call_id) &&
               (g_em_voip_log_cntx.call_status[i].dialog_id == dialog_id))
            {      
                /* we have already started this call */
                MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_VOIP_LOG_TRC_CALL_ACTIVATED, 
                          call_id,dialog_id);
                return;
            }

            if (free_slot < 0)
            {
                if ((g_em_voip_log_cntx.call_status[i].call_id == 0xFFFFFFFF) &&
                   (g_em_voip_log_cntx.call_status[i].dialog_id == 0xFFFFFFFF))
                {    
                    /* found an available record */
                    free_slot = i;
                }
            }
            
        }

        if (free_slot < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_VOIP_LOG_TRC_CALL_OVER_MAX, EM_VOIP_LOG_MAX_CALL);
            return;
        }
       
        /* found an available record */
        g_em_voip_log_cntx.call_status[free_slot].call_id = call_id;
        g_em_voip_log_cntx.call_status[free_slot].dialog_id = dialog_id;
                
        /* generate the log file name based on MDIR + datetime + call_id + dialog_id */
        GetDateTime(&current_time);

        memset(filename, 0, FMGR_PATH_BUFFER_SIZE);
        if (mdir == EM_VOIP_LOG_CALL_OUT)
        {
            kal_wsprintf((kal_wchar*)filename, "MO_%04d%02d%02d%02d%02d%02d_%d%d",
                    current_time.nYear,current_time.nMonth, current_time.nDay, 
                    current_time.nHour, current_time.nMin, current_time.nSec, 
                    call_id, dialog_id);
        }
        else
        {
            kal_wsprintf((kal_wchar*)filename, "MT_%04d%02d%02d%02d%02d%02d_%d%d",
                    current_time.nYear,current_time.nMonth, current_time.nDay, 
                    current_time.nHour, current_time.nMin, current_time.nSec,
                    call_id, dialog_id);
        }

        mmi_ucs2cat((S8*)filename, (S8*)EM_VOIP_LOG_EXT_FILENAME);
        memset(g_em_voip_log_cntx.call_status[free_slot].filename, 0, FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2cpy((S8*)g_em_voip_log_cntx.call_status[free_slot].filename, (const S8*)g_em_voip_log_cntx.dirpath);
        mmi_ucs2cat((S8*)g_em_voip_log_cntx.call_status[free_slot].filename, (S8*)filename);

        /* special file */
        memset(filename, 0, FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2cpy((S8*)filename, (S8*)g_em_voip_log_cntx.dirpath);
        mmi_ucs2cat((S8*)filename, (const S8*)EM_VOIP_LOG_TEMP_FILE);
                
        /* check to see if this special file has been created */
        h_file = FS_Open((WCHAR *)filename, FS_READ_ONLY); 
        if (h_file > 0)
        {
            FS_Close(h_file);
            ret = FS_Rename((WCHAR *)filename, (WCHAR *)g_em_voip_log_cntx.call_status[free_slot].filename);
            if (ret < 0)
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_VOIP_LOG_TRC_CALL_RENAME_FAIL);
            }
        }

        /* check and delete outdated logs */
        em_voip_log_check_and_delete();

        /* check if we can open or create the log file */
        h_file = FS_Open((U16*)g_em_voip_log_cntx.call_status[free_slot].filename, FS_CREATE | FS_READ_WRITE);

        if (h_file > 0)
        {
            FS_Close( h_file );
            
            g_em_voip_log_cntx.call_status[free_slot].status = FS_NO_ERROR;
        }
        else
        {
            /* cannot open or create the log file */
            g_em_voip_log_cntx.call_status[free_slot].status = h_file;
        }
    }

    return;
#else /* __MMI_EM_UT_VOIP__ */
    return;
#endif /* !__MMI_EM_UT_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_call_end
 * DESCRIPTION
 * called when the you finish a call
 * PARAMETERS
 *  id       [IN]   call identification
 * RETURNS
 *  void
 ******************************************************************************/
void em_voip_log_call_end( void* id)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    voip_call_id_struct *call = (voip_call_id_struct *)id;
    S32 call_id = (S32)call->call_id;
    S32 dialog_id = (S32)call->dialog_id;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.curr_log_activate > 0)
    {
        /* free the used record */
        for (i = 0; i < EM_VOIP_LOG_MAX_CALL; i++)
        {
            if ((g_em_voip_log_cntx.call_status[i].call_id == call_id) &&
               (g_em_voip_log_cntx.call_status[i].dialog_id == dialog_id))
            {     
                if (g_em_voip_log_cntx.call_status[i].status < 0)
                {
                    DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(g_em_voip_log_cntx.call_status[i].status)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    ERROR_TONE);
                }

                MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_VOIP_LOG_TRC_CALL_CLEAR, call_id,dialog_id);
                memset(&g_em_voip_log_cntx.call_status[i], 0xff, sizeof(em_voip_log_call_status_struct));
                break;
            }
        } 
    }

    return;  
#else /* __MMI_EM_UT_VOIP__ */
    return;
#endif /* !__MMI_EM_UT_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_check_and_delete
 * DESCRIPTION
 *  This function is used to delete outdated logs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_voip_log_check_and_delete( void)
{
#if defined(__MMI_EM_UT_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_date_value = 0;
    U32 curr_date_value = 0;
    S32 outdate = 0;
    S32 i;
    int h = -1; /* save temp. file handle for find */
    FS_DOSDirEntry info;
    kal_wchar filename[FMGR_MAX_FILE_LEN];
    kal_wchar all_file_path[FMGR_MAX_FILE_LEN];
    U8      filepath[FMGR_PATH_BUFFER_SIZE];
    MYTIME curr_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.curr_log_activate > 0)
    {
        /* compute the outdated time */
        switch (g_em_voip_log_cntx.curr_log_del_time)
        {
            case EM_VOIP_LOG_AUTO_DELETE_ALL:
                outdate = 0xFFFFFFFF;
                break;
            case EM_VOIP_LOG_AUTO_DELETE_ONE_DAY:
                outdate = 24*60*60;
                break; 
            case EM_VOIP_LOG_AUTO_DELETE_HALF_MONTH:
                outdate = 15*24*60*60;
                break;    
            case EM_VOIP_LOG_AUTO_DELETE_ONE_MONTH:
                outdate = 31*24*60*60;
                break; 
            default:
                ASSERT(0);
        }
    
    
        mmi_ucs2cpy((S8*)all_file_path, (const S8*)g_em_voip_log_cntx.dirpath);
        mmi_ucs2cat((S8*)all_file_path, (const S8*)(L"*.*"));

        if (outdate != 0xFFFFFFFF)
        {
            GetDateTime(&curr_time);
            if (curr_time.nYear > 1980)
            {
                /* current date */
                curr_date_value = ((curr_time.nYear - 1980)*12*31*24*60*60) +
                                (curr_time.nMonth*31*24*60*60) +
                                (curr_time.nDay*24*60*60) +
                                (curr_time.nHour*60*60) +
                                (curr_time.nMin*60) +
                                (curr_time.nSec >> 1);

                /* outdated time */
                curr_date_value = curr_date_value - outdate;
            }
            else
            {
                return;
            }

            h = FS_FindFirst((WCHAR *)all_file_path, 0, 0, &info, 
                filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

            if (h < 0)
            {
                return;
            } 
            
            do
            {
                /* the date of file */
                file_date_value = (info.DateTime.Year1980*12*31*24*60*60) +
                                (info.DateTime.Month*31*24*60*60) +
                                (info.DateTime.Day*24*60*60) +
                                (info.DateTime.Hour*60*60) +
                                (info.DateTime.Minute*60) +
                                (info.DateTime.Second2);
               
                if (curr_date_value >= file_date_value)
                {
                    /* delete the outdated logs */
                    memset(filepath, 0, FMGR_PATH_BUFFER_SIZE);
                    mmi_ucs2cpy((PS8)filepath, (PS8)g_em_voip_log_cntx.dirpath);
                    mmi_ucs2cat((PS8)filepath, (PS8)filename);
                    FS_Delete((const WCHAR *)filepath);
                }

                memset(filename, 0, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);
            
            } while (FS_FindNext(h, &info, filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH) == FS_NO_ERROR);
            FS_FindClose(h);
        }
        else
        {
            h = FS_FindFirst((WCHAR *)all_file_path, 0, 0, &info, filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

            if (h < 0)
            {
                return;
            } 
            
            do
            {
                memset(filepath, 0, FMGR_PATH_BUFFER_SIZE);
                mmi_ucs2cpy((PS8)filepath, (PS8)g_em_voip_log_cntx.dirpath);
                mmi_ucs2cat((PS8)filepath, (PS8)filename);
                
                for (i = 0; i < EM_VOIP_LOG_MAX_CALL; i++)
                { 
                    if ((g_em_voip_log_cntx.call_status[i].call_id != 0xFFFFFFFF) &&
                        (g_em_voip_log_cntx.call_status[i].dialog_id != 0xFFFFFFFF))
                    {    
                        /* found an available record */
                        if (!mmi_ucs2cmp((const S8 *)g_em_voip_log_cntx.call_status[i].filename,
                            (const S8 *)filepath))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_VOIP_LOG_TRC_CALL_STARTED, 
                                      g_em_voip_log_cntx.call_status[i].call_id, 
                                      g_em_voip_log_cntx.call_status[i].dialog_id);
                            break;
                        }
                    }
                }

                if (i >= EM_VOIP_LOG_MAX_CALL)
                {
                    /* not found in table */
                    FS_Delete((const WCHAR *)filepath);
                    
                }

                memset(filename, 0, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);
            } while (FS_FindNext(h, &info, filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH) == FS_NO_ERROR);

            FS_FindClose(h);
        }
    }
    
    return;
#else /* __MMI_EM_UT_VOIP__ */
    return;
#endif /* !__MMI_EM_UT_VOIP__ */
}
#endif /* __VOIP__ */


#if defined(__MMI_EM_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_VOIP__ */

#if defined(__MMI_EM_UT_VOIP__)

#define EM_VOIP_LOG
/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIP
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmVOIPLog, KEY_EVENT_UP);
    SetKeyHandler(EntryEmVOIPLog, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmVOIPLog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmVOIPLog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[32];
    U16 num_items;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_VOIP_LOG_SCR_ID, NULL, EntryEmVOIPLog, NULL);
    gui_buffer = GetCurrGuiBuffer(EM_VOIP_LOG_SCR_ID);

    num_items = GetNumOfChild(EM_VOIP_LOG_MENU_ID);
    GetSequenceStringIds(EM_VOIP_LOG_MENU_ID, item_list);
    SetParentHandler(EM_VOIP_LOG_MENU_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);


    ShowCategory52Screen(
        EM_VOIP_LOG_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_items,
        item_list,
        MMI_EM_INDEX_ICON_LIST,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIPLogSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLogSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmVOIPLogSetting, KEY_EVENT_UP);
    SetKeyHandler(EntryEmVOIPLogSetting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmVOIPLogSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmVOIPLogSetting(void)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    U16 ImageList[EM_VOIP_LOG_INLINE_TOTAL];
    U8  total_drv_num;
    UI_string_type drv_inline_list_p = NULL;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_VOIP_LOG_SETTINGS_SCR_ID, ExitEmVOIPLogSettingScreen, NULL, NULL);
    InitializeCategory57Screen();

    gui_buffer = GetCurrGuiBuffer(EM_VOIP_LOG_SETTINGS_SCR_ID);
    RegisterHighlightHandler(HighlightHdlrVOIPLogInline);

    
    SetInlineItemCaption(&wgui_inline_items[0], (U8*)GetString(STR_GLOBAL_ACTIVATE));
    ImageList[EM_VOIP_LOG_INLINE_ACTIVATE_CAPTION] = IMG_STATUS;

    g_em_voip_log_cntx.em_voip_log_activate[EM_VOIP_LOG_ACTIVATE_OFF] = (U8*)GetString(STR_GLOBAL_OFF);
    g_em_voip_log_cntx.em_voip_log_activate[EM_VOIP_LOG_ACTIVATE_ON] = (U8*)GetString(STR_GLOBAL_ON);
    if (g_em_voip_log_cntx.interrupt <= 0)
    {
        g_em_voip_log_cntx.hili_log_activate = g_em_voip_log_cntx.curr_log_activate;
    }
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[1], 2, 
        (U8**)g_em_voip_log_cntx.em_voip_log_activate, 
        &g_em_voip_log_cntx.hili_log_activate); 
    ImageList[EM_VOIP_LOG_INLINE_ACTIVATE] = 0;
    
    SetInlineItemCaption(&wgui_inline_items[2], (U8*)GetString(STR_GLOBAL_SAVE));
    ImageList[EM_VOIP_LOG_INLINE_SAVE_CAPTION] = IMG_STATUS;
    
    mmi_fmgr_get_full_storage_inline_list(0,(U8 *)&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (g_em_voip_log_cntx.interrupt <= 0)
    {
        g_em_voip_log_cntx.hili_log_storage = g_em_voip_log_cntx.curr_log_storage;
    }
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
    &wgui_inline_items[3], 
    (S32)total_drv_num,
    (U8 **) drv_inline_list_p,
    &g_em_voip_log_cntx.hili_log_storage);    
    ImageList[EM_VOIP_LOG_INLINE_SAVE] = 0;

    SetInlineItemCaption(&wgui_inline_items[4], (U8*)GetString(EM_VOIP_LOG_AUTO_DELETE_TEXT));
    ImageList[EM_VOIP_LOG_INLINE_AUTO_DELETE_CAPTION] = IMG_STATUS;
  
    g_em_voip_log_cntx.em_voip_log_delete[EM_VOIP_LOG_AUTO_DELETE_ALL] = 
        (U8*)GetString(EM_VOIP_LOG_DELETE_ALL_TEXT);
    g_em_voip_log_cntx.em_voip_log_delete[EM_VOIP_LOG_AUTO_DELETE_ONE_DAY] = 
        (U8*)GetString(EM_VOIP_LOG_DELETE_ONE_DAY_TEXT);
    g_em_voip_log_cntx.em_voip_log_delete[EM_VOIP_LOG_AUTO_DELETE_HALF_MONTH] = 
        (U8*)GetString(EM_VOIP_LOG_DELETE_HALF_MONTH_TEXT);
    g_em_voip_log_cntx.em_voip_log_delete[EM_VOIP_LOG_AUTO_DELETE_ONE_MONTH] = 
        (U8*)GetString(EM_VOIP_LOG_DELETE_ONE_MONTH_TEXT);
    if (g_em_voip_log_cntx.interrupt <= 0)
    {
        g_em_voip_log_cntx.hili_log_del_time = g_em_voip_log_cntx.curr_log_del_time;
    }
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
    &wgui_inline_items[5], 4, 
    (U8**)g_em_voip_log_cntx.em_voip_log_delete, 
    &g_em_voip_log_cntx.hili_log_del_time); 
    ImageList[EM_VOIP_LOG_INLINE_AUTO_DELETE] = 0;

    DisableCategory57ScreenDone();
     	
    ShowCategory57Screen(EM_VOIP_LOG_SETTINGS_TEXT, 0, 
                         STR_GLOBAL_OK, 
                         IMG_GLOBAL_OK, 
                         STR_GLOBAL_BACK, 
                         IMG_GLOBAL_BACK,
 	                     EM_VOIP_LOG_INLINE_TOTAL, ImageList, wgui_inline_items, 0, gui_buffer);	

    
    SetCategory57RightSoftkeyFunctions( GoBackHistory, GoBackHistory );  
}


/*****************************************************************************
 * FUNCTION
 *  ExitEmVOIPLogSettingScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmVOIPLogSettingScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 input_buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* to avoid the call interrupt or pop menu */
    if ( IsBackHistory == MMI_FALSE)
    {
        g_em_voip_log_cntx.interrupt = 1;
    }
    else
    {
        g_em_voip_log_cntx.interrupt = 0;
    }
    
    h.scrnID = EM_VOIP_LOG_SETTINGS_SCR_ID;
    h.entryFuncPtr = EntryEmVOIPLogSetting;
    GetCategoryHistory(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightHdlrVOIPLogInline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightHdlrVOIPLogInline(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EmSetVOIPLogInfo, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmSetVOIPLogInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmSetVOIPLogInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  voip_log_storage;
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    EXT_ASSERT( (g_em_voip_log_cntx.hili_log_activate & 0xFFFFFF00) == 0, 
                 g_em_voip_log_cntx.hili_log_activate, 0, 0 );
    
    EXT_ASSERT( (g_em_voip_log_cntx.hili_log_storage & 0xFFFFFF00) == 0, 
                 g_em_voip_log_cntx.hili_log_storage, 0, 0 );
    
    EXT_ASSERT( (g_em_voip_log_cntx.hili_log_del_time & 0xFFFFFF00) == 0, 
                 g_em_voip_log_cntx.hili_log_del_time, 0, 0 );


    if (g_em_voip_log_cntx.hili_log_activate != g_em_voip_log_cntx.curr_log_activate)
    {
        WriteValue(NVRAM_VOIP_LOG_ACTIVATE, 
                  &g_em_voip_log_cntx.hili_log_activate, DS_BYTE, &error);
        g_em_voip_log_cntx.curr_log_activate = g_em_voip_log_cntx.hili_log_activate;
    }

    if (g_em_voip_log_cntx.hili_log_storage != g_em_voip_log_cntx.curr_log_storage)
    {
        WriteValue(NVRAM_VOIP_LOG_STORAGE, 
                  &g_em_voip_log_cntx.hili_log_storage, DS_BYTE, &error);

        g_em_voip_log_cntx.curr_log_storage = g_em_voip_log_cntx.hili_log_storage;
        mmi_fmgr_get_drive_letter_by_inline_index(
                  (U8)g_em_voip_log_cntx.curr_log_storage, (PS8)&voip_log_storage);
        kal_wsprintf((kal_wchar*)g_em_voip_log_cntx.dirpath, "%c:\\", (S8) voip_log_storage);
        mmi_ucs2cat((S8*)g_em_voip_log_cntx.dirpath, (const S8*)EM_VOIP_LOG_DIR_PATH);
    }
    
    if (g_em_voip_log_cntx.hili_log_del_time != g_em_voip_log_cntx.curr_log_del_time)
    {
        WriteValue(NVRAM_VOIP_LOG_DELETE_TIME, 
            &g_em_voip_log_cntx.hili_log_del_time, DS_BYTE, &error);
        g_em_voip_log_cntx.curr_log_del_time = g_em_voip_log_cntx.hili_log_del_time;
    }


    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_VOIP_LOG_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIPLogView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLogView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmVOIPLogOption, KEY_EVENT_UP);
    SetKeyHandler(EntryEmVOIPLogOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmVOIPLogOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmVOIPLogOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
#ifdef __MMI_FILE_MANAGER__
    mmi_fmgr_select_path_and_enter(
        APP_ENGINEERMODE,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) g_em_voip_log_cntx.dirpath,
        EntryEMVOIPLogSelected);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  EntryEMVOIPLogSelected
 * DESCRIPTION
 *  file selected
 * PARAMETERS
 *  path            [IN]        Selected folder path
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEMVOIPLogSelected(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        DeleteUptoScrID(EM_VOIP_LOG_SCR_ID);
        GoBackHistory();
        return;
    }

    if (mmi_ucs2str((S8 *)path, (S8 *)EM_VOIP_LOG_EXT_FILENAME) != NULL)
    {
        memset(g_em_voip_log_cntx.filepath, 0, FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2cpy((PS8) g_em_voip_log_cntx.filepath, (PS8) path);
        /* enter Display Voip Log screen */
        EMVOIPLogDisplayOption();
    }
    else
    {
        /* not supported file type */
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_WARNING,
                     0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
        
        DeleteNScrId(EM_VOIP_LOG_OPTION_SCR_ID);
    }

}


/*****************************************************************************
 * FUNCTION
 *  EMVOIPLogDisplayOption
 * DESCRIPTION
 *  display VOIP log option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMVOIPLogDisplayOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[32];
    U16 num_items;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_VOIP_LOG_OPTION_SCR_ID, NULL, EMVOIPLogDisplayOption, NULL);
    gui_buffer = GetCurrGuiBuffer(EM_VOIP_LOG_OPTION_SCR_ID);

    num_items = GetNumOfChild(EM_VOIP_LOG_OPTION_MENU_ID);
    GetSequenceStringIds(EM_VOIP_LOG_OPTION_MENU_ID, item_list);
    SetParentHandler(EM_VOIP_LOG_OPTION_MENU_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_items,
        item_list,
        MMI_EM_INDEX_ICON_LIST,
        NULL,
        0,
        0,
        gui_buffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIPLogOptionView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLogOptionView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmVOIPLogOptionView, KEY_EVENT_UP);
    SetKeyHandler(EntryEmVOIPLogOptionView, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmVOIPLogOptionView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmVOIPLogOptionView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 readnum;
    S32 ret_code;
    FS_HANDLE fs_handle;
    S8 read_data[MAX_SUB_MENUS][MAX_SUBMENU_CHARACTERS];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_VOIP_LOG_VIEW_SCR_ID, NULL, EntryEmVOIPLogOptionView, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_VOIP_LOG_VIEW_SCR_ID);


    memset(subMenuData, 0, (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE));
    
    fs_handle = FS_Open((U16*) g_em_voip_log_cntx.filepath, FS_READ_ONLY);
    if (fs_handle < 0)
    {
        DisplayPopup(
                     (PU8) GetString(GetFileSystemErrorString(fs_handle)),
                     IMG_GLOBAL_ERROR,
                     0,
                     1000,
                     ERROR_TONE);
        
        DeleteNScrId(EM_VOIP_LOG_OPTION_SCR_ID);
        return;
    }
    
    ret_code = FS_Read(fs_handle, 
                    (void*)read_data,
                    MAX_SUB_MENUS*MAX_SUBMENU_CHARACTERS , 
                    (U32*) & readnum);
    if (ret_code < 0)
    {
        DisplayPopup(
                     (PU8) GetString(GetFileSystemErrorString(ret_code)),
                     IMG_GLOBAL_ERROR,
                     0,
                     1000,
                     ERROR_TONE);
        
        DeleteNScrId(EM_VOIP_LOG_OPTION_SCR_ID);
        return;
    }
    
    mmi_asc_n_to_ucs2((S8*)subMenuData, (S8*)read_data, readnum);
    FS_Close(fs_handle);

    ShowCategory74Screen(
        EM_VOIP_LOG_CONTENT_TEXT,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)subMenuData,
        (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE),
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIPLogOptionDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLogOptionDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_em_voip_log_cntx.delete_all = EM_VOIP_LOG_DELETE;
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(entry_em_voip_log_delete_confirm, KEY_EVENT_UP);
    SetKeyHandler(entry_em_voip_log_delete_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightEmVOIPLogOptionDeleteAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmVOIPLogOptionDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    g_em_voip_log_cntx.delete_all = EM_VOIP_LOG_DELETE_ALL;
    SetLeftSoftkeyFunction(entry_em_voip_log_delete_confirm, KEY_EVENT_UP);
    SetKeyHandler(entry_em_voip_log_delete_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  entry_em_voip_log_delete_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_em_voip_log_delete_confirm(void)
{

     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.delete_all == EM_VOIP_LOG_DELETE_ALL)
    {
 	    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    }
    else
    {

 	    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    }
    
    if (g_em_voip_log_cntx.delete_all == EM_VOIP_LOG_DELETE_ALL)
    {
        SetLeftSoftkeyFunction(em_voip_log_delete_all_file, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(em_voip_log_delete_file, KEY_EVENT_UP);
    }
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_delete_all_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void em_voip_log_delete_all_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    S8 *ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete files */
    ext = mmi_ucs2rchr((const PS8)g_em_voip_log_cntx.filepath, (U16)L'\\');

    if (ext  == NULL)
    {
        DeleteNScrId(EM_VOIP_LOG_OPTION_SCR_ID);
        GoBackHistory();
        return;
    }
    
    ext += 2;
    
    len = mmi_ucs2strlen(ext);
    if (len > 0)
    {
        memset(ext, 0, (len * 2));
        *ext = L'\0';
    }

    mmi_fmgr_util_send_delete_req((PU8) g_em_voip_log_cntx.filepath, 
        FS_DIR_TYPE, em_voip_log_delete_rsp_hdlr);
 
    entry_em_voip_delete_animation();
}

/*****************************************************************************
 * FUNCTION
 *  em_voip_log_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_voip_log_delete_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete files */
    mmi_fmgr_util_send_delete_req((PU8) g_em_voip_log_cntx.filepath, 
        FS_FILE_TYPE, em_voip_log_delete_rsp_hdlr);
   
    entry_em_voip_delete_animation();
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_log_delete_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void em_voip_log_delete_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_delete_rsp_strcut *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_off();
    SetDelScrnIDCallbackHandler (EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID, (HistoryDelCBPtr)NULL);	

    msg_p = (mmi_fmt_delete_rsp_strcut*) info;

    if (msg_p->result >= FS_NO_ERROR)
    {
       
        /* success */
        if (mmi_em_is_in_call() == TRUE && GetExitScrnID() != EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID)
        {
            DeleteScreenIfPresent(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, SUCCESS_TONE);
            DeleteScreenIfPresent(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID);
        }
    }
    else
    {
        /* fail */
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) g_em_voip_log_cntx.filepath);

        if (mmi_em_is_in_call() == TRUE && GetExitScrnID() != EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID)
        {
           DeleteScreenIfPresent(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(msg_p->result)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                ERROR_TONE);
            DeleteScreenIfPresent(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID);
        }
    }

    g_em_voip_log_cntx.delete_all = EM_VOIP_LOG_DELETE_NONE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_delete_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_em_voip_delete_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_on(0);

    EntryNewScreen(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID, exit_em_voip_delete_animation, NULL, NULL);

    ShowCategory66Screen(
        STR_GLOBAL_DELETE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* can only delete the screen when the deletetion resp is received */
    if (!IsScreenPresent(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID))
    {
        if (g_em_voip_log_cntx.delete_all == EM_VOIP_LOG_DELETE_ALL)
        {
            DeleteUptoScrID(EM_VOIP_LOG_SCR_ID);
        }
        else
        {
            DeleteNScrId(EM_VOIP_LOG_OPTION_SCR_ID);
        }
    }

    SetDelScrnIDCallbackHandler(EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID, 
        (HistoryDelCBPtr) em_voip_delete_animation_callback);
}


/*****************************************************************************
 * FUNCTION
 *  exit_em_voip_delete_animation
 * DESCRIPTION
 *  processing the interrupt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_em_voip_delete_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history curr_history;
    S16 num_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_em_is_in_call() == FALSE)
    {
        /* pop up interrupt => add to history */
        curr_history.scrnID = EM_VOIP_LOG_DELETE_ANIMATION_SCR_ID;
        curr_history.entryFuncPtr = entry_em_voip_delete_animation;
        mmi_ucs2cpy((S8*) curr_history.inputBuffer, (S8*) & num_history);
        GetCategoryHistory(curr_history.guiBuffer);
        AddHistory(curr_history);
    }
    else
    {
        /* interrupt by Call => abort XDelete */
        if (g_em_voip_log_cntx.delete_all == EM_VOIP_LOG_DELETE_ALL)
        {
            FS_Abort(FS_ABORT_XDELETE);       
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  em_voip_delete_animation_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 em_voip_delete_animation_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_voip_log_cntx.delete_all == EM_VOIP_LOG_DELETE_NONE)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
#endif   /*  #if defined(__MMI_EM_UT_VOIP__) */


#endif /* __MMI_ENGINEER_MODE__ */
