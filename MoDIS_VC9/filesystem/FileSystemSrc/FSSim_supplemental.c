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
 *  FSSim_supplemental.c
 *
 * Project:
 * --------
 *  FSSIM
 *
 * Description:
 * ------------
 *  This file implements supplemental functions of File System Simulation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define UNICODE

#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "kal_release.h"

#include "fat_fs.h"

#include "FSSim_def.h"

/*************************************************************************/
/*    Definitions of global data                                         */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_create_mutex                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to create a mutex.                         */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      Pointer to mutex                                                 */
/*                                                                       */
/*************************************************************************/
void *fssim_create_mutex()
{
    static char         next_mutex_name[]   = "FS_N";
    static unsigned int fssim_mutex_counter = 0;
    const char          hex_digits[]        = "0123456789ABCDEF";
    FSSIM_MUTEX_T      *mutex;

    next_mutex_name[ strlen(next_mutex_name) - 1 ] = hex_digits[fssim_mutex_counter++];
    fssim_mutex_counter = fssim_mutex_counter % strlen(hex_digits);

    mutex=malloc(sizeof(FSSIM_MUTEX_T));

    mutex->rtf_sem=kal_create_mutex(next_mutex_name);
    mutex->rtf_sem_owner=-1;
    mutex->rtf_lock_count=0;
            
    return (void *) mutex;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_take_mutex                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to take a mutex.                           */
/*                                                                       */
/* INPUTS                                                                */
/*      mutex  -  poitner to mutex                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
void fssim_take_mutex(void *mutex)
{
    DWORD         current_task;
    FSSIM_MUTEX_T *m = (FSSIM_MUTEX_T*)mutex;

    if (kal_query_systemInit() == KAL_TRUE)
        return;

    current_task = GetCurrentThreadId();

    if (m->rtf_sem_owner == current_task)   {
        m->rtf_lock_count++;
        return;
    }
    
    kal_take_mutex(m->rtf_sem);
    m->rtf_sem_owner=current_task;
    m->rtf_lock_count=1;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_give_mutex                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to give a mutex.                           */
/*                                                                       */
/* INPUTS                                                                */
/*      mutex  -  poitner to mutex                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
void fssim_give_mutex(void *mutex)
{
    DWORD current_task;
    FSSIM_MUTEX_T *m = (FSSIM_MUTEX_T*)mutex;


    if (kal_query_systemInit() == KAL_TRUE)
        return;
    
    current_task = GetCurrentThreadId();

    m->rtf_lock_count--;

    if (m->rtf_lock_count==0)   {
        m->rtf_sem_owner=-1;
        kal_give_mutex(m->rtf_sem);
    }
}

/**
 * @brief this function returns task name string pointer
 *
 * @param curr_task_ptr
 *    Task ID
 * @return
 *    NULL: No task name could be retrieved. System may be in initialization stage.
 *    A task name string pointer
 */
extern void* kal_get_task_name_ptr(void* curr_task_ptr);

void *fssim_get_task_name_ptr(void* curr_task_ptr)
{
   return kal_get_task_name_ptr(curr_task_ptr);
}

/**
 * @brief this function prints current used file table slots
 */
void fssim_dbg_print_file_table(void)
{
   const char  UNKNOWN_TASK_NAME[] = "UND";
   const TCHAR UNKNOWN_FILE_NAME[] = L"NULL";
   int i;
   char *task_name;
   TCHAR* file_name;

   // print file table

   printf("=======================================\n");
   printf("        File System File Table\n");
   printf("=======================================\n\n");

   for (i = 1; i <= FSSIM_MAX_FILE; i++)
   {
      if (fssim_file[i].state == STATE_INUSE)
      {
         task_name = (char*)fssim_get_task_name_ptr(fssim_file[i].taskid);
         file_name = fssim_file[i].filename;

         if (task_name == NULL)
            task_name = (char*)UNKNOWN_TASK_NAME;

         if (*file_name == 0)
            file_name = (TCHAR*)UNKNOWN_FILE_NAME;

         printf("File table[%d] - <%s> ", i, task_name);
         wprintf(L"%s\n", file_name);
      }
   }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_get_task_self_id                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to current task's ID                       */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      Task id                                                          */
/*                                                                       */
/*************************************************************************/
void *fssim_get_task_self_id()
{
    return kal_get_task_self_id();
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_print_str                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to print a string                          */
/*                                                                       */
/* INPUTS                                                                */
/*      str  -  poitner to string                                        */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
void fssim_print_str(const TCHAR *str)
{
    unsigned int i;
    char *pch;

    ASSERT(str != NULL);

    for (i = 0; i < wcslen(str); i++) {

        pch = (char *)&(str[i]);

        fssim_printf(("%c", *pch));
    }

    fssim_printf(("\n"));
}

#undef UNICODE

