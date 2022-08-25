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
 *   ExternalCMDManager.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Manager for extern command in Offline Resgen system
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include <cstdlib>
#include <iostream>
#include "ResgenLogCAPI.h"

extern "C"{
#include "ExternalCMDManagerCAPI.h"
}


using namespace std;

// External Interface for C sources


#define EXTCMD_TAG        "EXTERNALCMDMANAGER"

#define EXTCMD_LOG_D(format, args...) RES_LOG_D((EXTCMD_TAG), (format) , ##args)
#define EXTCMD_LOG_V(format, args...) RES_LOG_V((EXTCMD_TAG), (format) , ##args)
#define EXTCMD_LOG_W(format, args...) RES_LOG_W((EXTCMD_TAG), (format) , ##args)
#define EXTCMD_LOG_E(format, args...) RES_LOG_E((EXTCMD_TAG), (format) , ##args)


////////////////////////////////////////////////////////
// External Command Manager
////////////////////////////////////////////////////////


class ExternalCMDManager{
public:
    static int execute(string command_str);
    static int execute(const char * command_str);
};

int ExternalCMDManager::execute(string command_str){
    return ExternalCMDManager::execute(command_str.c_str());
}

int ExternalCMDManager::execute(const char * command_str){
    int sys_result = 0;
    try{
        EXTCMD_LOG_V("Start external script:\t%s",command_str);
        EXTCMD_LOG_V("---------------- The following log is generated from %s:",command_str);
        sys_result = std::system(command_str);
        EXTCMD_LOG_V("---------------- The above log is generated from %s:",command_str);
        EXTCMD_LOG_V("Finish external script:\t%s",command_str);
    }catch(...){
        EXTCMD_LOG_E("Received unknown excetion in ExternalCMDManager::execut");
    }
    return sys_result;
}

////////////////////////////////////////////////////////
// C API interface
////////////////////////////////////////////////////////

// This is a temp implemenation of C system command wrapper API
int execute_ext_command(char * command_str)
{
    return ExternalCMDManager::execute(command_str);
}
