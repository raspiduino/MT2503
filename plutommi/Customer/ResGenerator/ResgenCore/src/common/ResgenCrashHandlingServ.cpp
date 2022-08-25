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
 * ResgenDataType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resgen crash exception handling service
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

#include <stdio.h>
#include <iostream>
#include "ResgenCrashHandlingServ.h"
#include "ResgenLogCAPI.h"

#define EXPSERV_TAG        "RESGENCRASHHANDLINGSERV"

#define EXPSERV_LOG_D(format, args...) RES_LOG_D((EXPSERV_TAG), (format) , ##args)
#define EXPSERV_LOG_V(format, args...) RES_LOG_V((EXPSERV_TAG), (format) , ##args)
#define EXPSERV_LOG_W(format, args...) RES_LOG_W((EXPSERV_TAG), (format) , ##args)
#define EXPSERV_LOG_E(format, args...) RES_LOG_E((EXPSERV_TAG), (format) , ##args)

using namespace std;

/////////////////////////////////////////////////
// Static member definition
/////////////////////////////////////////////////
ResgenCrashHandlingService* ResgenCrashHandlingService::objInstance = NULL;

/////////////////////////////////////////////////
// Member function implementation
/////////////////////////////////////////////////

ResgenCrashHandlingService::ResgenCrashHandlingService(){
    isStart = 0;
    EXPSERV_LOG_V("Create ResgenCrashHandlingService");
    // Disable the system critical error dialog message box.
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
}
ResgenCrashHandlingService::~ResgenCrashHandlingService(){
    if(this->isStart){
        this->stop();
    }
}

ResgenCrashHandlingService * ResgenCrashHandlingService::getInstance(){
    if(objInstance == NULL){
        objInstance = new ResgenCrashHandlingService();
    }
    return objInstance;
}

LONG ResgenCrashHandlingService::ResgenCrashHandlerWrapper(EXCEPTION_POINTERS *pExcept)
{	
    return (ResgenCrashHandlingService::getInstance())->ResgenCrashHandler(pExcept);
}

LONG ResgenCrashHandlingService::ResgenCrashHandler(EXCEPTION_POINTERS *pExcept)
{	
    static int re_entry = 0;

    // Prevent exception re-entry during this handler
    if(re_entry != 0)
    {
        fflush(stdout);
        fflush(stderr);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    re_entry ++;

    // Log the error messge in file
    EXPSERV_LOG_E("** Received windows exception, ExceptionCode = 0x%08x,  ExceptionAddress = 0x%08x",	pExcept->ExceptionRecord->ExceptionCode, pExcept->ExceptionRecord->ExceptionAddress);
    EXPSERV_LOG_V("** Please check the following files for detailed debug information\n\t\t - plutommi/Customer/ResGenerator/mtk_resgenerator.map\n\t\t - plutommi/Customer/ResGenerator/debug/obj/mtk_resgenerator_core/*.cod");

    // Display the error messge in the console 
    fprintf(stderr, "** Exception 0x%08x at 0x%08x\n",	pExcept->ExceptionRecord->ExceptionCode, pExcept->ExceptionRecord->ExceptionAddress);
    fprintf(stderr, "** Please check the following files for detailed debug information\n\t - plutommi/Customer/ResGenerator/mtk_resgenerator.map\n\t - plutommi/Customer/ResGenerator/debug/obj/mtk_resgenerator_core/*.cod\n");
    fflush(stderr);
    // Dump register data
    EXPSERV_LOG_V("======================Registers======================");        
    EXPSERV_LOG_V("esp : 0x%08x\tebp : 0x%08x", pExcept->ContextRecord->Esp,pExcept->ContextRecord->Ebp);
    EXPSERV_LOG_V("eax : 0x%08x\tebx : 0x%08x\tecx : 0x%08x\tedx : 0x%08x", pExcept->ContextRecord->Eax,pExcept->ContextRecord->Ebx,pExcept->ContextRecord->Ecx,pExcept->ContextRecord->Edx);
    EXPSERV_LOG_V("=====================================================");
    // Show registers in console
    fprintf(stderr, "** Registers: \n");
    fprintf(stderr,"esp : 0x%08x\tebp : 0x%08x\n", pExcept->ContextRecord->Esp,pExcept->ContextRecord->Ebp);
    fprintf(stderr,"eax : 0x%08x\tebx : 0x%08x\necx : 0x%08x\tedx : 0x%08x\n", pExcept->ContextRecord->Eax,pExcept->ContextRecord->Ebx,pExcept->ContextRecord->Ecx,pExcept->ContextRecord->Edx);
    fflush(stderr);

    // Dump stack data
    if(pExcept->ContextRecord && pExcept->ContextRecord->Esp)
    {
        int i = 1024*5;
        DWORD *ptr = (DWORD*)pExcept->ContextRecord->Esp;

        fprintf(stdout, "** Stack address = 0x%08x\nStack dump:(%d bytes)", pExcept->ContextRecord->Esp, i);

        i = i/sizeof(DWORD);
        while(i>0)
        {
            if (i%4 == 0)
            {
                fprintf(stdout, "\n%08X:  ", ptr);
            }
            fprintf(stdout, "0x%08X,", *ptr);
            i--;
            ptr++;
        }
        fflush(stdout);
    }
    
    re_entry --;

    return EXCEPTION_EXECUTE_HANDLER;
}


void ResgenCrashHandlingService::start(){
    if(this->isStart != 1){
        this->isStart = 1;
        previousCrashExceptionHandler = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ResgenCrashHandlerWrapper); 
    }
}
void ResgenCrashHandlingService::stop(){
    if(this->isStart){
        SetUnhandledExceptionFilter(previousCrashExceptionHandler);
        this->isStart = 0;
    }
}

