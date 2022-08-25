
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
 * JavaAgencyCommand.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define commands 
 *   of Java agency command related routines.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "kal_release.h"
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#include "cache_sw.h"
#endif
#include "JavaAgencyManager.h"
#ifdef __JAVA_MANAGER__

#ifdef __DM_SCOMO_SUPPORT__
#include "DmSrvGprot.h"
extern mmi_java_dmui_scomo_cb(srv_dm_scomo_cmd_enum cmd,srv_dm_scomo_java_cmd_info_struct * scomo_info);
#endif

#include "FileMgrSrvGProt.h"
#include "med_api.h"
#include "rtc_sw.h"
#include "jam_internal.h"
/*************************** Java import external function *******************************/
extern java_context_struct g_java;
extern kal_eventgrpid g_java_event_group_2;
extern kal_bool jam_vm_is_busy(void);
extern kal_int32 jam_mvm_get_vm_state(kal_int32 vm_id);
extern void javaFileGenerator(kal_bool force_remove_all);
extern void mmi_java_global_setting_entry_screen(void);
extern U32 mmi_my_favorite_javabox_waplink_count(void);
//extern S32 utf8_to_ucs2_string(U8 *dest, int dest_size, U8 *src);
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern mmi_ret jam_sg_proc(mmi_event_struct *evt);

static kal_int32 Java_LaunchMidCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_ClearAllCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_JavaBoxCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_InstallMidsCmd(kal_int32 argc, kal_char * argv [ ]);
/*************************** Java Global Command *******************************/
#ifndef __JAVA_MANAGER_SLIM__
static kal_int32 Java_JavaSettingCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_JavaSecurityCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_SelectMidsCmd(kal_int32 argc, kal_char* argv[]);
static kal_int32 Java_DeleteMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_UpdateMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_GetInfoMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_SettingsMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_NetProfileMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_RestoreSettingsMidsCmd(kal_int32 argc, kal_char * argv [ ]);
/************************** Java Auto verification additional tools **********************/
static kal_int32 Java_FileOperatorCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_SnapshotCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_PhoneHangCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_GetFreeSpaceSizeCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_FillDiskDrvCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_DateTimeCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_UploadMMSCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_DminstallMidsCmd(kal_int32 argc, kal_char * argv [ ]);
static kal_int32 Java_DmdeleteMidsCmd(kal_int32 argc, kal_char * argv [ ]);
#endif

/*******************************************************************************/
typedef enum{
    JAVA_CMD_NAME_LAUNCH = 0,
    JAVA_CMD_NAME_JAVABOX,
    JAVA_CMD_NAME_INSTALL,
    JAVA_CMD_NAME_CLEARALLMIDS,   
#ifndef __JAVA_MANAGER_SLIM__
    JAVA_CMD_NAME_JAVASETTINGS,
    JAVA_CMD_NAME_JAVASECURITY,
    JAVA_CMD_NAME_SELECT,
    JAVA_CMD_NAME_DELETE,
    JAVA_CMD_NAME_UPDATE,
    JAVA_CMD_NAME_GETINFO,
    JAVA_CMD_NAME_SETTINGS,
    JAVA_CMD_NAME_NETPROFILE,
    JAVA_CMD_NAME_RESTORE_SETTINGS,
    JAVA_CMD_NAME_SNAPSHOT,
    JAVA_CMD_NAME_FILEEXIST,
    JAVA_CMD_NAME_FILEOPERATOR,
    JAVA_CMD_NAME_PHONEHANG,
    Java_CMD_NAME_FREESPACE,
    Java_CMD_NAME_FILLIN_DRV,
    Java_CMD_NAME_DATETIME,
    Java_CMD_NAME_UPLOADMMS,
    Java_CMD_NAME_DMINSTALL,
    Java_CMD_NAME_DMDELETE 
#endif
}Java_Cmd_Name_ID;

static mmi_java_cmd_struct  builtInCmds[]={
    { "launch",               Java_LaunchMidCmd          },
    { "javabox",              Java_JavaBoxCmd            },
    { "install",              Java_InstallMidsCmd        },
    { "clearall",             Java_ClearAllCmd           }
#ifndef __JAVA_MANAGER_SLIM__
   ,{ "javasettings",         Java_JavaSettingCmd        },
    { "javasecurity",         Java_JavaSecurityCmd       },    
    { "select",               Java_SelectMidsCmd         },  
    { "delete",               Java_DeleteMidsCmd         },
    { "update",               Java_UpdateMidsCmd         },
    { "getinfo",              Java_GetInfoMidsCmd        },
    { "settings",             Java_SettingsMidsCmd       },
    { "netprofile",           Java_NetProfileMidsCmd     },
    { "restoresettings",      Java_RestoreSettingsMidsCmd},
    { "snapshot",             Java_SnapshotCmd           },
    { "fileexist",            Java_FileOperatorCmd       },/*backward fileexist command*/
    { "file",                 Java_FileOperatorCmd       },
    { "phonehang",            Java_PhoneHangCmd          },
    { "freespace",            Java_GetFreeSpaceSizeCmd   },
    { "fill",                 Java_FillDiskDrvCmd        },
    { "datetime",             Java_DateTimeCmd           },
    { "uploadmms",            Java_UploadMMSCmd          },
    { "dminstall",            Java_DminstallMidsCmd      },
    { "dmdelete",             Java_DmdeleteMidsCmd       }
#endif
};
typedef enum {
    /* Below enume value used to description error code field*/
    JAVA_CMD_NO_ERROR = 0,
    JAVA_CMD_ARG_ERROR,
    JAVA_CMD_JAVA_IS_BUSY,
    JAVA_CMD_NO_MEM_ERROR,
    JAVA_CMD_FILE_DIR_ERROR,
    JAVA_CMD_ERROR,
    JAVA_CMD_FILL_IN_FAILED,
    JAVA_CMD_NOT_EXIST,
    JAVA_CMD_IS_NOT_IN_IDLE,
    JAVA_CMD_ENTRY_APP_FAILLED
}Java_cmd_rsp_enum;

static const kal_char* Java_cmd_rsp_string[]={
    "Inject command successfully!",                       /*JAVA_CMD_NO_ERROR = 0,*/
    "Injected ARGS is error!"                   ,         /*JAVA_CMD_ARG_ERROR,*/
    "Java VM engine is busy!"                   ,         /*JAVA_CMD_JAVA_IS_BUSY,*/
    "No enough Memory for cmd!"                 ,         /*JAVA_CMD_NO_MEM_ERROR,*/
    "File dirtecory doesnt exist!"              ,         /*JAVA_CMD_FILE_DIR_ERROR,*/
    "Java cmd executes error"                   ,         /*JAVA_CMD_ERROR*/
    "Fill in Failed!"                           ,    /*JAVA_CMD_FILL_IN_FAILED*/
    "This command doesn't exist, may not insert SIM or FlightMode!",    /*JAVA_CMD_NOT_EXIST*/
    "Idle is not active!"                       ,    /*JAVA_CMD_IS_NOT_IN_IDLE*/
};

#ifdef __MTK_TARGET__
#define STROKE_TIME 4
#define PAUSE_TIME 15
#else
#define STROKE_TIME 2
#define PAUSE_TIME  5
#endif
#define MAX_STROKE_TIME 100
#define MAX_PAUSE_TIME 100

static const kal_char javaTest[]="javaTest";
static const kal_char TestMIDS[]="testMIDS";  
static const kal_char * atJava = "@java";
static const kal_char * tmpFileName = "javaTest.tmp";

void java_cmd_send_rsp(kal_int32 error_code, kal_int32 int_value, const kal_char* string_value)
{
    mmi_l4c_java_cmd_rsp_struct *ptrRsp = NULL;
    ptrRsp = (mmi_l4c_java_cmd_rsp_struct*)construct_local_para(sizeof(mmi_l4c_java_cmd_rsp_struct), TD_CTRL);
    ptrRsp->errorCode = (kal_int32)error_code;
    ptrRsp->intValue = (kal_int32)int_value;
    if(NULL != string_value) strcpy((kal_char*)ptrRsp->stringValue,(const kal_char*)string_value);
    mmi_java_send_message_from_active_mod(MOD_L4C,J2ME_MMI_SAP,MSG_ID_MMI_L4C_JAVA_CMD_RSP,ptrRsp);
}
#define JAVA_CMD_RSP(error_code, value, str_value) java_cmd_send_rsp(error_code, value, str_value)
/*****************************************************************************
 * FUNCTION
 *  JavaFindCmd
 * DESCRIPTION
 *  Find a particular command in Build in command table.
 *  If the command doesn't exist in the table, or if it is an
 *  ambiguous abbreviation, then NULL is returned.  Otherwise
 *  the return value is a pointer to the command.
 * PARAMETERS
 *  const char* FoundCmdName
 * RETURNS
 *  mmi_java_cmd_struct*  
 *****************************************************************************/
static mmi_java_cmd_struct *
Java_FindCmd(kal_char *FoundCmdName)/* Desired command. */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_cmd_struct *pcmd = NULL;
    kal_int32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(NULL == FoundCmdName) return NULL;

    /*
     * First check for an exact match.
     */
    for (idx = 0; idx < sizeof(builtInCmds)/sizeof(mmi_java_cmd_struct);++idx) {
        pcmd = builtInCmds + idx;
        if(0 == app_stricmp(FoundCmdName,pcmd->cmdName))
        return pcmd;
    }
    return NULL;
}
static void 
Java_itoa(kal_int32 i, kal_char *buf,  kal_int32 base)
{
    char *s;
#define LEN    20
    int rem;
    char rev[LEN+1];

    rev[LEN] = 0;
    if (i == 0){
        buf[0] = '0';
        ++buf;
        return;
    }
    s = &rev[LEN];
    while (i){
        rem = i % base;
        if (rem < 10)
            *--s = rem + '0';
        else if (base == 16)
            *--s = "abcdef"[rem - 10];
        i /= base;
    }
    while (*s){
        buf[0] = *s++;
        ++buf;
    }
}

/*****************************************************************************
 * FUNCTION
 *  JavaMakeAgrv
 * DESCRIPTION
 *
 *  Make argv array (*arvp) for tokens in s which are separated by * delimiters.
 *  Return -1 on error or the number of tokens otherwise.
 *  
 *  Must free the mem alloced for arvp and the mem pointed by arvp[0],which stors all arguments.
 * PARAMETERS
 *  const char* FoundCmdName
 *  const char* delimiters
 *  kal_char*** argvp
 * RETURNS
 *  kal_int32  
 *****************************************************************************/
static kal_int32
Java_MakeArgv(const kal_char* str, const kal_char* delimiters, kal_char ***argvp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static  kal_char  FaitourChar[]={5,1,2,3,4};// 1:space 2:tab 3:newline  4:comma 5:no used
    kal_char *tmp= NULL;
    kal_char *snew= NULL;
    kal_char * ptr = NULL;
    kal_char *lasts;
    kal_int32 numtokens = -1;
    kal_int32 idx = 0;   
    kal_bool    flag = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* snew is real start of string after skipping leading delimiters */
    snew = (kal_char*)str + strspn(str, delimiters);
    /*replace all space, tab , newline and comma characters between double quotation marks*/
    for(ptr = snew;(ptr!=NULL) && (*ptr!= '\0'); ptr++){
        if('"' == *ptr && '\\'!=*(ptr-1)){
            *ptr = ' ';
            if( KAL_FALSE == flag)
                flag = KAL_TRUE;
            else
                 flag = KAL_FALSE;
            ptr++;
            continue;
        }
        if(flag){
            switch(*ptr){
                case ' ' :
                    *ptr = FaitourChar[1];
                    break;
                case '\t' :
                    *ptr = FaitourChar[2];
                    break;
                case '\n' :
                    *ptr = FaitourChar[3];
                    break;
                case ',' :
                    *ptr = FaitourChar[4];
                    break;
                default:
                        break;
                        
            }
        }
    }
    if(KAL_TRUE == flag){
        *argvp = NULL;
        return -1;
    }
    /* create space for a copy of snew in t */
    if ((tmp = (kal_char*)OslMalloc(sizeof(kal_char)*(strlen(snew) + 1))) == NULL) { 
        *argvp = NULL;
        numtokens = -1;
        return -1;
    }else{
        /* count the number of tokens in snew */
        strcpy(tmp, snew);
        if (strtok_r(tmp, delimiters,&lasts) == NULL){
            numtokens = 0;
            OslMfree(tmp);
            return 0;
        }else{
            for (numtokens = 1; strtok_r(NULL, delimiters,&lasts) != NULL; numtokens++)
                ;  
            /* create an argument array to contain ptrs to tokens */
            if ((*argvp = (kal_char**)OslMalloc((numtokens + 1)* sizeof(char *))) == NULL) {
                OslMfree(tmp);         
                numtokens = -1;
                return -1;
            }else{
                /* insert pointers to tokens into the array */
                if (numtokens > 0) {
                    strcpy(tmp, snew); 
                    **argvp = strtok_r(tmp, delimiters,&lasts);  
                    for (idx = 1; idx < numtokens + 1; idx++)
                    *((*argvp) + idx) = strtok_r(NULL, delimiters,&lasts);
                }else{           
                    **argvp = NULL; 
                    OslMfree(tmp);
                    return -1;
                }
            }
        }
    }
    /*replace faitour Char*/
    for(idx = 0; idx < numtokens; idx++){
        for(ptr = (*argvp)[idx];(ptr!=NULL) && (*ptr!= '\0'); ptr++){
            switch(*ptr){
                case 1:
                    *ptr = ' ';
                    break;
                case 2:
                    *ptr = '\t';
                    break;
                case 3:
                    *ptr = '\n';
                    break;
                case 4:
                    *ptr = ',';
                    break;
                default:
                    break;
            }
        }
    }
    return numtokens;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_execute_cmd
 * DESCRIPTION
 *
 *  java command entry, mmi module can send cammand string to order java agency.
 *  
 * PARAMETERS
 *  const kal_char*  cmd_str[IN] 
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_java_execute_cmd(const kal_char* cmd_str)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   ret = JAVA_CMD_ERROR;
    kal_int32   argc = 0;
    kal_char** argv = NULL;
    const char * delimiters = " ,\t\n";
    mmi_java_cmd_struct* retcmd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cmd_str!=NULL&&((strlen(cmd_str)) > 0))
    {
        /*  make argv the command string  */
        argc = Java_MakeArgv((const kal_char*)cmd_str,delimiters,&argv);
        /*  Find command in command table  */
        if(argc > 0)
        {
            retcmd = Java_FindCmd(argv[0]);
            if((NULL != retcmd) && (NULL != retcmd->cmdProc))
                ret = retcmd->cmdProc(argc,argv);
            else
                ret = JAVA_CMD_ARG_ERROR;
        }
        if(NULL != argv && 0< argc)
        {
            if(argv[0]) OslMfree(argv[0]);/* free the mem storing all arguments.*/
            OslMfree(argv);
            argv = NULL;
        }
    }
    else
    {
        ret = JAVA_CMD_ARG_ERROR;
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  tst_mmi_java_cmd_req_handler
 * DESCRIPTION
 *
 *  java command entry, used to parse the command string.It carry on a mmi_java_command_req_struct
 *  
 *  
 * PARAMETERS
 *  void*  in 
 * RETURNS
 *  
 *****************************************************************************/
void
tst_mmi_java_cmd_req_handler(ilm_struct *ilm_ptr)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   ret = JAVA_CMD_ERROR;
    tst_mmi_java_cmd_req_struct *pIn = (tst_mmi_java_cmd_req_struct*)ilm_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pIn != NULL);    
    ret = mmi_java_execute_cmd((const kal_char*)pIn->string);
    if(JAVA_CMD_NO_ERROR != ret)
    {
        JAVA_CMD_RSP(ret,0,Java_cmd_rsp_string[ret]);
    }
    return;
}
/*****************************************************************************
 * FUNCTION
 *  Java_URLDecodeToUTF8
 * DESCRIPTION
 *
 * Decode a escaped url encoded by utf-8 to utf-8 string, save into old 
 * character array.
 *  
 * PARAMETERS
 *  kal_char* strurl
 * 
 * RETURNS
 *  kal_int32  The string length of URL after decoding
 *****************************************************************************/
static kal_int32
Java_URLDecodeToUTF8(kal_char *escapedurl) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *dest = escapedurl; 
    kal_char *data = escapedurl; 
    kal_int32 value; 
    kal_int32 c; 
    kal_int32 len;
    extern int isupper(kal_int32);
    extern int tolower(kal_int32);
    extern int isxdigit(kal_int32);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(escapedurl);
    while (len--){ 
        if (*data == '+') { 
            *dest = ' '; 
        }else if (*data == '%' && len >= 2 
            && isxdigit((kal_int32) *(data + 1)) 
            && isxdigit((kal_int32) *(data + 2))){ 
            c = ((unsigned char *)(data+1))[0]; 
            if (isupper(c)) 
                c = tolower(c); 
            value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16; 
            c = ((unsigned char *)(data+1))[1]; 
            if (isupper(c)) 
                c = tolower(c); 
            value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10; 
            *dest = (kal_char)value ; 

            data += 2; 
            len -= 2; 
        } else { 
            *dest = *data; 
        } 
        data++; 
        dest++; 
    }
    *dest = '\0'; 
    return dest - escapedurl; 
}


/****************************************************************************
 * FUNCTION
 *  Java_IsAciiNumeric
 * DESCRIPTION
 *  Check whether the input arg is composed of numer.
 *  [symbol]<digital>
 *
 *  return kal_true If yes, else kal_false
 * PARAMETERS
 * kal_char  *arg
 * RETURNS
 * kal_bool
 *****************************************************************************/
static kal_bool
Java_IsAciiNumeric(const kal_char * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == arg || '\0'== *arg) return KAL_FALSE;
    /*Neg:- Pos:+ Num*/
    if(*arg == '-'||*arg == '+') arg++;
    while(*arg !='\0'){
        if(*arg >='0' && *arg <='9' ){
            arg++;
            ret = KAL_TRUE;
        }else{
            return KAL_FALSE;
        }
    }
    return ret;
}

/****************************************************************************
 * FUNCTION
 *  mmi_l4c_send_at_cmd_req
 * DESCRIPTION
 *  Send the AT command request to L4C by message MSG_ID_TST_INJECT_STRING .
 *  
 * return 0 if no error, else error code
 * PARAMETERS
 * const kal_char  *pInATCmdStr
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
mmi_l4c_send_at_cmd_req(const kal_char  * pInATCmdStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32     len = 0;
    java_l4c_inject_at_cmd_struct *ptrAtCmd=  NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL ==pInATCmdStr){
        return JAVA_CMD_ARG_ERROR;
    }
    len = strlen(pInATCmdStr);
    if((JAVA_COMMAND_AT_MAX_LENGTH<= len)||(0>= len)){
        return JAVA_CMD_ARG_ERROR;
    }
    ptrAtCmd = (java_l4c_inject_at_cmd_struct*) OslConstructDataPtr(sizeof(java_l4c_inject_at_cmd_struct));
    if(NULL == ptrAtCmd){
       return JAVA_CMD_NO_MEM_ERROR;
    }
    /*construct the AT command string */
    strcpy((kal_char*)ptrAtCmd->string, (const kal_char*)pInATCmdStr);
    mmi_java_send_message_from_active_mod(MOD_L4C,J2ME_MMI_SAP,MSG_ID_TST_INJECT_STRING,ptrAtCmd);
    return JAVA_CMD_NO_ERROR;
}

 /****************************************************************************
 * FUNCTION
 *  Java_file_exist
 * DESCRIPTION
 *
 *  determine whether the file_path is a right path.
 *
 *  Return KAL_TRUE ,if yes else KAL_FALSE
 *  
 * PARAMETERS
 * const kal_char  drv
 * const kal_char* filepath 
 * RETURNS
 * kal_int32
 *****************************************************************************/
static 
kal_bool 
Java_file_exist(const kal_wchar* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((ret = FS_Open((const kal_wchar*) file_path, FS_READ_ONLY)) < FS_NO_ERROR){
       return KAL_FALSE;
    }
    FS_Close(ret);
    return KAL_TRUE;
}
 /****************************************************************************
 * FUNCTION
 *  Java_get_filepath_recursive
 * DESCRIPTION
 *  This function is used to get a file path in deep  search first way.
 *    pszUCS2PreFilepath   ---->long file path prefix part.
 *    left_size                    ----> the left size of pszUCS2PreFilepath buffer.
 *    pszUCS2PostFilepath  -----> long file path post part.
 *    recursive_level          -----> config the recursive level.
 *
 *  Return 0 buffer is full or recursive level overflow.
 *  Return 1  search given file successfully.
 *  Return -1 no file found in given folder.
 *  
 * PARAMETERS
 * kal_wchar*  pszUCS2PreFilepath [IN]    
 * kal_int32  left_size  [IN] 
 * kal_wchar*  pszUCS2PostFilepath [IN]    
 * kal_int32  recursive_level  [IN]
 * RETURNS
 * kal_int32
 *****************************************************************************/
 static
 kal_int32 
Java_get_filepath_recursive(kal_wchar* pszUCS2PreFilepath,kal_int32 left_size,kal_wchar* pszUCS2PostFilepath,kal_int32 recursive_level){
     static const kal_wchar dir_dot1[] = {'.', 0};
     static const kal_wchar dir_dot2[] = {'.', '.', 0};
     static const kal_wchar dir_dot3[] = {'.', '\\', 0};
     static const kal_wchar dir_dot4[] = {'.', '.', '\\', 0}; 
     kal_int32 handle;
     kal_int32 bufferSize = 0;
     kal_int32 ret =0;
     kal_wchar * temp_buffer;
     int nameLen = kal_wstrlen(pszUCS2PreFilepath);

     
     FS_DOSDirEntry fileInfo;
     if(pszUCS2PreFilepath[nameLen - 1] != '\\'){
         pszUCS2PreFilepath[nameLen] = '\\';
         pszUCS2PreFilepath[nameLen + 1] = '*';
         pszUCS2PreFilepath[nameLen + 2] = 0;
         temp_buffer = pszUCS2PreFilepath + nameLen+ 3;
         bufferSize = left_size - 3; 
     }else{
         pszUCS2PreFilepath[nameLen] = '*';
         pszUCS2PreFilepath[nameLen + 1] = 0;
         temp_buffer = pszUCS2PreFilepath + nameLen+2;
         bufferSize =  left_size - 2;
     }
     /* the file handler may be used out when recursive level > 10 */
     if(recursive_level > 10|| bufferSize <=0)
        return 0;
     recursive_level ++;
 
     handle = FS_FindFirst(pszUCS2PreFilepath, 0, 0, &fileInfo, temp_buffer,  bufferSize);
     ret = handle;
     while(ret >= FS_NO_ERROR){
         if(fileInfo.Attributes & FS_ATTR_DIR){
            if(kal_wstrcmp(dir_dot1, temp_buffer) != 0 && kal_wstrcmp(dir_dot2, temp_buffer) != 0 &&
                kal_wstrcmp(dir_dot3, temp_buffer) != 0 && kal_wstrcmp(dir_dot4, temp_buffer) != 0){
                kal_int32 len = 0;
                if(pszUCS2PreFilepath[nameLen - 1] != '\\'){
                    pszUCS2PreFilepath[nameLen] = '\\';
                    pszUCS2PreFilepath[nameLen+1] = 0;
                }else{
                    pszUCS2PreFilepath[nameLen] = 0;
                }
                len = kal_wstrlen(temp_buffer);
                if(temp_buffer[len - 1] != '\\'){
                    temp_buffer[len] = '\\';
                    temp_buffer[len + 1] = 0;
                }else{
                    temp_buffer[len] = 0;
                }
                kal_wstrcat(pszUCS2PreFilepath, temp_buffer);
                kal_wstrcat(pszUCS2PreFilepath, pszUCS2PostFilepath);
                if(Java_file_exist((const kal_wchar *) pszUCS2PreFilepath)){
                    return 1;
                }
                pszUCS2PreFilepath[nameLen+len+1] = 0;
                bufferSize = left_size - len;
                ret  = Java_get_filepath_recursive(pszUCS2PreFilepath, bufferSize, pszUCS2PostFilepath, recursive_level);
                if(ret >=0) return ret;
            }
         }else if(kal_wstrcmp((const WCHAR *)temp_buffer,(const WCHAR *)pszUCS2PostFilepath)==0){
             pszUCS2PreFilepath[nameLen] = 0;
             if(pszUCS2PreFilepath[nameLen - 1] != '\\'){
                 pszUCS2PreFilepath[nameLen] = '\\';
                 pszUCS2PreFilepath[nameLen + 1] = 0;
             }
             kal_wstrcat(pszUCS2PreFilepath, temp_buffer);
             return 1;
         }
         pszUCS2PreFilepath[nameLen] = 0;
         bufferSize = left_size;
         temp_buffer = pszUCS2PreFilepath+nameLen+2;
         ret = FS_FindNext(handle, &fileInfo, temp_buffer, bufferSize); 
     }
     FS_FindClose(handle);
     
     return -1;
 }

 /****************************************************************************
 * FUNCTION
 *  java_local_install
 * DESCRIPTION
 *  The local API called by Java_InstallMidsCmd to implement local installation.
 *  drv[0] is the actual driver
 *  Return 0 on no error or error code.
 *  
 * PARAMETERS
 * const kal_int16  drv [IN]    
 * const kal_char* filepath [IN] 
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32 
Java_local_install(const kal_int16 drv,const kal_char* filepath )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define MAX_PATH 256
    kal_char*   fileurlptr = NULL;
    kal_wchar*   ptr = NULL;
    kal_wchar*   postptr = NULL;
    kal_int32   idx = 0;
    kal_wchar* wfilepath;
    kal_int32   size = 0;
    kal_int32   ret = JAVA_CMD_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(0 > drv || NULL == filepath){
        return JAVA_CMD_ARG_ERROR;
    }

    size = 3+strlen(filepath)+1;
    
    if(MAX_PATH < size ) return JAVA_CMD_FILE_DIR_ERROR;

    if (NULL == (fileurlptr = (kal_char *)OslMalloc(size))) {
        return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(fileurlptr,0,size);
    sprintf(fileurlptr,"%c:\\%s",(kal_char)drv,filepath);
    for(idx = 0; *(fileurlptr+idx)!= '\0'; idx++){
        if(fileurlptr[idx]=='/')fileurlptr[idx]='\\';
    }
    /* Try to translate the escaped character into utf-8 encoding*/
    Java_URLDecodeToUTF8((kal_char *) fileurlptr)+1;
    if(NULL == (wfilepath = (kal_wchar*)OslMalloc(MAX_PATH<<1))) {
        OslMfree(fileurlptr);
        return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(wfilepath,0,MAX_PATH<<1);
    //utf8_to_ucs2_string((U8 *)wfilepath, MAX_PATH<<1,(U8 *)fileurlptr);
    mmi_chset_utf8_to_ucs2_string((kal_uint8*)wfilepath,MAX_PATH<<1,(kal_uint8 *)fileurlptr);
    OslMfree(fileurlptr);
    if(NULL!=(ptr = mmi_wcsstr((U16*)wfilepath,(const U16*)L"..."))){
        postptr = ptr+4;
        *ptr = 0;
        size = (mmi_wcslen(ptr+4)+1)<<1;
        if(NULL == (postptr = (kal_wchar*)OslMalloc(size))) {
            OslMfree(fileurlptr);
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(postptr,0,size);
        kal_wstrcpy(postptr,ptr+4);

        if(Java_get_filepath_recursive(wfilepath,MAX_PATH - mmi_wcslen((const U16*)wfilepath)-1,postptr,0) <= 0){
           ret = JAVA_CMD_FILE_DIR_ERROR;
        }else{
           ret = JAVA_CMD_NO_ERROR;
        }
        OslMfree(postptr);        
    }else if(Java_file_exist((const kal_wchar*)wfilepath) == KAL_TRUE){
        mmi_java_local_install_content_routing((U16*)wfilepath);
        ret = JAVA_CMD_NO_ERROR;
    } else{
        ret = JAVA_CMD_FILE_DIR_ERROR;
    }
    
    OslMfree(wfilepath);
    return ret;

}
 /****************************************************************************
 * FUNCTION
 *  Java_InstallMidsCmd
 * DESCRIPTION
 *  The implement of install command.
 *
 *        install <protocol>://url
 *  
 * Local Install
 *
 *        install <protocol>://[<DRV>:/]file_path
 *
 * [Select DRV rule]
 *   1.if  argv[1]="install file://filename", then the SRV_FMGR_PUBLIC_DRV:\javatestcase forder will be searched.   
 *   2.if  argv[1]="install file://DRV: /filepath", then the DRV will be searched.
 *   3.if  argv[1]="install file://filepath", then all DRVs will be searched until the  first match  file be found or all DRVs not  including  the file .
 *Example:
 *   1. file://DodgeBall_Touch.jad   
 *       It will search 
 *           SRV_FMGR_PUBLIC_DRV:\javatestcase\DodgeBall_Touch.jad 
 *   2. file://phone:/Others/DodgeBall_Touch.jad
 *       It will search 
 *           SRV_FMGR_PUBLIC_DRV:\Others\DodgeBall_Touch.jad
 *   3. file://Others/DodgeBall_Touch.jad
 *       It will search 
 *           SRV_FMGR_PUBLIC_DRV:\Others\DodgeBall_Touch.jad        or
 *           SRV_FMGR_CARD_DRV:\Others\DodgeBall_Touch.jad           or
 *           SRV_FMGR_CARD2_DRV:\Others\DodgeBall_Touch.jad
 *
 *  Return 0 on no error or error code.
 *  
 *  
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
kal_int32
Java_InstallMidsCmd(kal_int32 argc, kal_char* argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    kal_int16  drv=0;
    kal_wchar  * pURLaddr = NULL;
    kal_char  * pInStr = NULL;
    kal_char  * filepath = NULL;
    kal_int32 len = 0;
    kal_int32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_INSTALL].cmdName)) ||( 2!= argc)){
        return JAVA_CMD_ARG_ERROR;
    }
    pInStr = argv[1];
    while(*pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
        pInStr++;

    if(strlen(pInStr) == 0)return JAVA_CMD_ARG_ERROR;
      /**
        *Local Install
        *
        *install <protocol>://[<DRV>:/]file_path
        */
    if(0 == app_strnicmp(pInStr,"file://",7)){
        len = strlen(pInStr);
        if(app_strnicmp(pInStr+len-4, ".jad",4)
            && app_strnicmp(pInStr+len-4, ".jar",4)
            && app_strnicmp(pInStr+len-4, ".odf",4)
            && app_strnicmp(pInStr+len-4, ".cer",4)){
            return JAVA_CMD_ARG_ERROR;
        }
        pInStr += 7;
        while(*pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
            pInStr++;
        if(strlen(pInStr) == 0)return JAVA_CMD_ARG_ERROR;
        /**
          * First Rule implements.
          */        
        if((NULL == strchr((const kal_char*)pInStr,'\\') ) && (NULL == strchr((const kal_char*)pInStr,'/'))){
            drv = SRV_FMGR_PUBLIC_DRV;
            if(drv < 0){
                return JAVA_CMD_ARG_ERROR;
            }
            len = (strlen(javaTest)+ strlen(TestMIDS) +strlen(pInStr) +3);
            if ((filepath = (kal_char *)OslMalloc(len)) == NULL) {
                return JAVA_CMD_NO_MEM_ERROR;
            }
            memset(filepath,0,len);
            sprintf(filepath,"%s\\%s\\%s",javaTest,TestMIDS,pInStr);
            ret = Java_local_install(drv,filepath);
            if( JAVA_CMD_NO_ERROR != ret){
                memset(filepath,0,len);
                sprintf(filepath,"%s\\%s",javaTest,pInStr);
                ret = Java_local_install(drv,filepath);
            }
            OslMfree(filepath);
            filepath = NULL;
            return ret;
        
        }
        /**
          *Second Rule implements.
          */
        else if(pInStr[5] == ':'){
            /*user set the DRV = phone:/  */
            if(0 == app_strnicmp(pInStr,"phone:/",7)){
                if((drv =  SRV_FMGR_PUBLIC_DRV)<0){
                    return JAVA_CMD_ARG_ERROR;
                }
            }else if(0 == app_strnicmp(pInStr,"card1:/",7)){
            /* user set the DRV = card1:/   */
                drv =  SRV_FMGR_CARD_DRV;
                if(drv < 0){
                    return JAVA_CMD_ARG_ERROR;
                }
            }else if(0 == app_strnicmp(pInStr,"card2:/",7)){
           /*  user set the DRV = card2:/   */
                drv =  SRV_FMGR_CARD2_DRV;
                if(drv < 0){
                    return JAVA_CMD_ARG_ERROR;
                }
            }else{
            /*no the DRV be set by user*/
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr + 7;
            ret = Java_local_install(drv,filepath);
            return ret;
        }else{
           /** 
             *     
             *Third Rule implements.
             *   No drv is set in input string, so scan all DRV, until a drv is found,  which contains the file,
             *   then we will try to install the file
             */
             
            /*SRV_FMGR_PUBLIC_DRV or SRV_FMGR_CARD_DRV or SRV_FMGR_CARD2_DRV*/
            filepath = pInStr; ret  = JAVA_CMD_ERROR;
            if(((drv = (kal_char)SRV_FMGR_PUBLIC_DRV)>0)  || ((drv = (kal_char)SRV_FMGR_CARD2_DRV)>0)){
                ret = Java_local_install(drv,filepath);
            }
            if((ret != JAVA_CMD_NO_ERROR) && ((drv = (kal_char)SRV_FMGR_CARD_DRV)>0)){
                ret = Java_local_install(drv,filepath);
            }           
            if((ret != JAVA_CMD_NO_ERROR) && ((drv = (kal_char)SRV_FMGR_CARD2_DRV)>0)){
                ret = Java_local_install(drv,filepath);
            }
            return ret;
        }
    }
  /*
     * OTA install
     *        
     * install http://url
     */
    else if((0 == app_strnicmp(pInStr,"https://",8)) || (0 == app_strnicmp(pInStr,"http://",7))){
        if(strlen(pInStr+7)==0||strlen(pInStr+8)==0)return JAVA_CMD_ARG_ERROR;
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pURLaddr = (kal_wchar*)OslMalloc(len<<1))) {
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pURLaddr,0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *)pURLaddr, len<<1,(U8*)pInStr);
#ifdef BROWSER_SUPPORT
        ret = wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)pURLaddr);
#else
        return JAVA_CMD_ERROR;
#endif          
        if(NULL != pURLaddr){
            OslMfree(pURLaddr);
            pURLaddr = NULL;
        }
        if(0 == ret){
            return JAVA_CMD_NO_ERROR;
        }else{
            return JAVA_CMD_ERROR;
        }
    }
    /*
     * MMS install
     */
    else if(0 == app_strnicmp(argv[1],"mms://",6)){
        return JAVA_CMD_ERROR;
    }
    /*
     * other
     */
    else{
        return JAVA_CMD_ERROR;
    }
}

#ifndef __JAVA_MANAGER_SLIM__
typedef struct  _mids_infor_struct_t
{
    kal_int32  mids_idx;
    kal_uint8  mids_attrib;
}mids_infor_struct;
  
static mids_infor_struct save_mids_infor = {0};
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_cmd_query_req
 * DESCRIPTION
 * Get some information of a mids by index or name, such as the mids index for the name and attribute.
 * However you only set mids_name or mids_idx, and can not be set at the same time.
 *  Send message to java task, and get the MIDlet list back
 * PARAMETERS
 *  mids_name         [IN]        The mids name want to get
 *  mids_index         [IN]        The mids index want to get
 *  extend_mode      [IN]        Send message and sync with java side, get some mids information  from pointer of pointer
 *  ptr             [OUT]       Pointer to the pointer of the list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_send_cmd_query_req(const kal_wchar*  mids_name, const kal_int32  mids_idx, kal_bool extend_mode, java_mmi_cmd_query_rsp_struct **ptrRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_cmd_query_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = OslAllocDataPtr(mmi_java_cmd_query_req_struct);
    msg->mids_index = mids_idx;
    msg->mids_name = (kal_wchar*)mids_name;
    msg->extend_mode = extend_mode;
    msg->confirm_data_ptr = ptrRsp;

    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_CMD_QUERY_REQ,(oslParaType *)msg,NULL);
}
 /****************************************************************************
 * FUNCTION
 *  mmi_java_query_mids_information
 * DESCRIPTION
 *  Find the mids in installed list by name or index. and return available index. However, name and index can not be set at same time
 *  
 * return -1 if not Found, else index
 * PARAMETERS
 * kal_char  *arg
 * RETURNS
 * kal_bool
 *****************************************************************************/
static kal_int32 
mmi_java_query_mids_information(const kal_wchar  * pInMidsName, kal_int32 InMids_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_int32  mids_idx = 0;
     kal_uint32 event_group;
     kal_bool   isFound = KAL_FALSE;
     java_mmi_cmd_query_rsp_struct*  ptrRsp = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((NULL == pInMidsName)&&(0>InMids_idx)){
        return -2;
    }
    if((NULL != pInMidsName) && (0 <= InMids_idx)){
        return -2;
    }
    mmi_java_send_cmd_query_req(pInMidsName, InMids_idx,KAL_TRUE, &ptrRsp);
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_2, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    if(NULL != ptrRsp){
        mids_idx = ptrRsp->mids_idx;
        save_mids_infor.mids_idx = mids_idx;
        save_mids_infor.mids_attrib = ptrRsp->mids_attrib;
        if((ptrRsp->error_code==0)&& (mids_idx>=0)){
            isFound = KAL_TRUE;
    }
        free_local_para((local_para_struct*) ptrRsp);
        ptrRsp = NULL;
    }
    if(isFound)
        return mids_idx;
    else
        return -1;
}
/*==========================================================================================*/
/*                                          Below this line, we implement the command in javabox,                                                                                */
/*==========================================================================================*/

 /*****************************************************************************
 * FUNCTION
  *  Java_JavaSettingCmd
 * DESCRIPTION
  *  The command go to java setting menu.
  *
  *  Return 0 on no error or error code.  
 *  
 * PARAMETERS
  * kal_int32 argc
  * kal_char* argv[]
 * RETURNS
  * kal_int32
 *****************************************************************************/
static kal_int32
 Java_JavaSettingCmd(kal_int32 argc, kal_char* argv[])
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if( 0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_JAVASETTINGS].cmdName) ||1 != argc){
         return JAVA_CMD_ARG_ERROR;
    }
     if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
         return JAVA_CMD_JAVA_IS_BUSY;        
    }
     mmi_java_global_setting_entry_screen();
#endif /*__PLUTO_MMI_PACKAGE__*/ 
    return JAVA_CMD_NO_ERROR;
}
 /*****************************************************************************
 * FUNCTION
  *  Java_JavaSecuiryCmd
 * DESCRIPTION
  *  The command go to java secuiry menu.
  *
  *  Return 0 on no error or error code.  
 *  
 * PARAMETERS
  * kal_int32 argc
  * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
 Java_JavaSecurityCmd(kal_int32 argc, kal_char * argv [ ])
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef OGDR_SECURITY_SETTING
    extern void mmi_java_global_security_entry_screen(void);
#endif
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if( 0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_JAVASECURITY].cmdName) ||1 != argc){
        return JAVA_CMD_ARG_ERROR;
    }
     if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
         return JAVA_CMD_JAVA_IS_BUSY;        
    }

#ifdef OGDR_SECURITY_SETTING
     mmi_java_global_security_entry_screen();
#endif

#endif /* __PLUTO_MMI_PACKAGE__*/ 
    return JAVA_CMD_NO_ERROR;
}


 /****************************************************************************
 * FUNCTION
 *  Java_DeleteMidsCmd
 * DESCRIPTION
 *  The implement of delete command.
 *
 *        delete <mids namel>|<mids index>[<stroke time>] [,<pause time>]
 *        delete <mids name>| <mids index>  [mode = 0]
 * [delete rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculet key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 * 
 * Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *      delete DodgeBall
 *      delete 1
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
Java_DeleteMidsCmd(kal_int32 argc, kal_char* argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__      
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_char  * pATCmdStr = NULL;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_uint8  mids_attrib = 0;
     kal_int32  item_cnt = 0;
     kal_int32  mids_idx = 0;
     kal_int32  key_mode = 0;
     kal_int32  mids_menu_idx = 0;
     kal_wchar  * pInMidsName = NULL;
   /*  const kal_int32 DELETE_MENU_IDX_INSTALLED_BY_DEFAULT =  -1; can not be deleted*/
     const kal_int32 DELETE_MENU_IDX = 4; 
     kal_int32 vm_id = 0;
     #endif
     kal_int32  ret = JAVA_CMD_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__    
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_DELETE].cmdName)|| 2> argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(vm_id)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    } 
    pInStr = argv[1];
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        mids_menu_idx = atoi((const char *)pInStr) ;
        mids_idx = mids_menu_idx -1;
        mids_idx = mmi_java_query_mids_information(NULL, mids_idx);

    }else{
    /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidsName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);
        mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
        mids_menu_idx = mids_idx + 1;
        OslMfree(pInMidsName);
        pInMidsName = NULL;
    }
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EntryScrJavaMenu();
    item_cnt = g_java.total_java_app_mids;

    if(mids_idx<0 || mids_idx >= item_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
   /* mids_attrib = g_java.mids_info[mids_idx].mids_attributes;*/
    mids_attrib = save_mids_infor.mids_attrib;
    if (!(mids_attrib & CAN_BE_REMOVE)){
        return JAVA_CMD_ARG_ERROR;
    }
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    /*construct the AT command string */
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
        i = strlen(pATCmdStr);
        pATCmdStr[i++] = '[';
        if (!(mids_attrib & CAN_BE_UPDATE)){ /* Delete mids installed by local  */
            sprintf((char *) (pATCmdStr + i), "%d",DELETE_MENU_IDX);
            i += 1;  
        }else{/* Delete mids installed by OTA */
            sprintf((char *) (pATCmdStr + i), "%d",DELETE_MENU_IDX+1);
            i += 1;   
        }
        sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;
    }else{
        len = strlen("AT+CKPD=\"1")+mids_menu_idx+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr + 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        for(j = 1; j < mids_menu_idx && i < JAVA_COMMAND_AT_MAX_LENGTH;j++,i++){
            pATCmdStr[i] = 'V';
        }
        pATCmdStr[i++] = '[';
        if (!(mids_attrib & CAN_BE_UPDATE)){ /* Delete mids installed by local */
            for(j = 1; j <DELETE_MENU_IDX ; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }   
        }else{/* Delete mids installed by OTA */
            for(j = 1; j <DELETE_MENU_IDX + 1; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }    
        }
        if(i+7 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
        }else{
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
        }   
    }
    /*send AT command request to l4c */      
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
#endif
    return ret;
}

/****************************************************************************
 * FUNCTION
 *  Java_SelectMidsCmd
 * DESCRIPTION
 *  The implement of select a special mids command by index or name.
 *
 *        select <mids namel>|<mids index> [<stroke time>] [,<pause time>]
 *        select <mids name>| <mids index>  [mode = 0]
 * [select rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculet key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 * 
 * Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *      select DodgeBall
 *      select  1
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
Java_SelectMidsCmd(kal_int32 argc, kal_char* argv[])
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_char  * pATCmdStr = NULL;
     kal_int32  key_mode = 0;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_int32  item_cnt = 0;
     kal_int32  mids_idx = 0;
     kal_int32  mids_menu_idx = 0;
     kal_wchar  * pInMidsName = NULL;
#endif
     kal_int32  ret = JAVA_CMD_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_SELECT].cmdName)|| 2> argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    }     
    pInStr = argv[1];
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        mids_menu_idx = atoi((const char *)pInStr) ;
        mids_idx = mids_menu_idx -1;
        mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
    }else{
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidsName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

        mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
        
        mids_menu_idx = mids_idx + 1;
        OslMfree(pInMidsName);
    }
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EntryScrJavaMenu();
    item_cnt = g_java.total_java_app_mids;
    if(mids_idx<0 || mids_idx >= item_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    /*construct the AT command string */
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
        i = strlen(pATCmdStr);
        pATCmdStr[i++] = '[';
        sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;
    }else{
        len = strlen("AT+CKPD=\"1")+ item_cnt/2 + 20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        if(mids_menu_idx < item_cnt/2+1){
            for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = 'V';
            }
        }else{
            for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = '^';
            }
        }

        pATCmdStr[i++] = '[';
        if(i+6 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
        }else{
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
        }   
    }
    /*send AT command reqest to l4c */   
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
#endif
    return ret;
}
       
 /****************************************************************************
 * FUNCTION
 *  Java_UpdateMidsCmd
 * DESCRIPTION
 *  The implement of update command. This command is used to update a java game by OTA.
 *
 *       update <mids name>| <mids index>  [<stroke time>] [,<pause time>]
 *       update <mids name>| <mids index>  [mode = 0]
 *  
 * [update rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculate key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     update DodgeBall
 *     update 1
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
Java_UpdateMidsCmd(kal_int32 argc, kal_char* argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef ___PLUTO_MMI_PACKAGE__
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_char  * pATCmdStr = NULL;
     kal_uint8 mids_attrib = 0;
     kal_int32  item_cnt = 0;
     kal_int32  mids_idx = 0;
     kal_int32  mids_menu_idx = 0;
     kal_int32  key_mode = 0;
     kal_wchar  * pInMidsName = NULL;
     const kal_int32 MENU_IDX_UPDATE = 2;
#endif
     kal_int32  ret = JAVA_CMD_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef ___PLUTO_MMI_PACKAGE__
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_UPDATE].cmdName)|| 2> argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    }     
    pInStr = argv[1];
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        mids_menu_idx = atoi((const char *)pInStr) ;
        mids_idx = mids_menu_idx -1;
        mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
    }else{
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidsName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

        mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
        mids_menu_idx = mids_idx + 1;
        OslMfree(pInMidsName);
    }
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EntryScrJavaMenu();
    item_cnt = g_java.total_java_app_mids;
    if(mids_idx<0 || mids_idx >= item_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
    mids_attrib = save_mids_infor.mids_attrib;

    if (!(mids_attrib & CAN_BE_UPDATE)){
        return JAVA_CMD_ARG_ERROR;
    }
    
    /*construct the AT command string */
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+4+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
        i = strlen(pATCmdStr);
        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /* update item is the second, just move down 1 form item 1 */
            sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_UPDATE);
            i +=1;
        }
        sprintf((char *) (pATCmdStr + i), "[[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;
    }else{
        len = strlen("AT+CKPD=\"1")+ item_cnt/2 +20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        if(mids_menu_idx < item_cnt/2+1){
            for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = 'V';
            }
        }else{
            for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = '^';
            }
        }
        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /* update item is the second, just move down 1 form item 1 */
            for(j = 1; j < MENU_IDX_UPDATE; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }  
        }
        if(i+7 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "[[\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
        }else{
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
        }    
    }
    /*send AT command request to l4c */
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
    #endif
    return ret;
}
 /****************************************************************************
 * FUNCTION
 *  Java_GetInfoMidsCmd
 * DESCRIPTION
 *  The implement of GetInfo command. This command is used to get the information of mids.
 *
 *       getinfo <mids name>| <mids index>  [<stroke time>] [,<pause time>]
 *       getinfo <mids name>| <mids index>  [mode = 0]
 *  
 * [getinfo rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculet key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     getinfo DodgeBall
 *     getinfo 1
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
Java_GetInfoMidsCmd(kal_int32 argc, kal_char* argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_char  * pATCmdStr = NULL;
     kal_int32  ret = JAVA_CMD_NO_ERROR;
     kal_uint8 mids_attrib = 0;
     kal_int32  item_cnt = 0;
     kal_int32  mids_idx = 0;
     kal_int32  key_mode = 0;
     kal_int32  mids_menu_idx = 0;
     kal_wchar  * pInMidsName = NULL;
     const kal_int32 MENU_IDX_INFORMATION = 3; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_GETINFO].cmdName) || 2> argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    }     
    pInStr = argv[1];
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        mids_menu_idx = atoi((const char *)pInStr) ;
        mids_idx = mids_menu_idx -1;
        mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
    }else{
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidsName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

        mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
        mids_menu_idx = mids_idx + 1;
        OslMfree(pInMidsName);
    }
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EntryScrJavaMenu();
    item_cnt = g_java.total_java_app_mids;
    if(mids_idx<0 || mids_idx >= item_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
    mids_attrib = save_mids_infor.mids_attrib;
    /*construct the AT command string */
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
        i = strlen(pATCmdStr);
        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /* information item is the fourth, just move down 3 form item 1 */
            sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_INFORMATION+1);
            i +=1;
        } else if (mids_attrib & CAN_BE_REMOVE){ /* information item is the fourth, just move down 3 form item 1 */
            sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_INFORMATION);
            i +=1;
        }else{
            /*can not exist the mids whose attribute is 000.*/
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR;
        }
        sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;
    }else{
        len = strlen("AT+CKPD=\"1")+ item_cnt/2 + 20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        if(mids_menu_idx < item_cnt/2+1){
            for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = 'V';
            }
        }else{
            for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = '^';
            }
        }

        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /* information item is the fourth, just move down 3 form item 1 */
            for(j = 1; j <MENU_IDX_INFORMATION + 1; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }  
        } else { /* information item is the fourth, just move down 3 form item 1 */
            for(j = 1; j <MENU_IDX_INFORMATION; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }  
        }
        if(i+7 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
        }else{
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
         }
    }
    /*send AT command request to l4c */
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
    #endif
    return ret;
}
 /****************************************************************************
 * FUNCTION
 *  Java_SettingMidsCmd
 * DESCRIPTION
 *  The implement of setting command. This command is used to show the mids setting.
 *
 *       setting <mids name>| <mids index>  [<stroke time>] [,<pause time>]
 *       setting <mids name>| <mids index>  [mode = 0]
 *  
 * [Setting rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculet key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     setting DodgeBall
 *     setting 1
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32 
Java_SettingsMidsCmd(kal_int32 argc, kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_int32  key_mode = 0;
     kal_char  * pATCmdStr = NULL;
     kal_int32  ret = JAVA_CMD_NO_ERROR;
     kal_uint8 mids_attrib = 0;
     kal_int32  item_cnt = 0;
     kal_int32  mids_idx = 0;
     kal_int32  mids_menu_idx = 0;
     kal_wchar  * pInMidsName = NULL;
     const kal_int32 MENU_IDX_SETTINGS= 2; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    if(app_stricmp(argv[0],(kal_char *)builtInCmds[JAVA_CMD_NAME_SETTINGS].cmdName)|| 2> argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    }     
    pInStr = argv[1];
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        mids_menu_idx = atoi((const char *)pInStr) ;
        mids_idx = mids_menu_idx -1;
        mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
    }else{
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidsName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

        mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
        mids_menu_idx = mids_idx + 1;
        OslMfree(pInMidsName);
    }
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EntryScrJavaMenu();
    item_cnt = g_java.total_java_app_mids;
    if(mids_idx<0 || mids_idx >= item_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
    mids_attrib = save_mids_infor.mids_attrib;  
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    /*construct the AT command string */
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
        i = strlen(pATCmdStr);
        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /*OTA installed, setting item is the second, just move down 1 form item 2  */
            sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_SETTINGS + 1);
            i += 1;
          }else{   /*local installed or default, setting item is the second, just move down 1 form item 1 */
            sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_SETTINGS);
            i += 1;           
        }
        sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;        
    }else{
        len = strlen("AT+CKPD=\"1")+ item_cnt/2 + 20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        if(mids_menu_idx < item_cnt/2+1){
            for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = 'V';
            }
        }else{
            for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = '^';
            }
        }
        pATCmdStr[i++] = '[';
        if (mids_attrib & CAN_BE_UPDATE){ /*OTA installed, setting item is the second, just move down 1 form item 2  */
            for(j = 1; j <MENU_IDX_SETTINGS + 1; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }           
        }else{   /*local installed, setting item is the second, just move down 1 form item 1 */
            for(j = 1; j <MENU_IDX_SETTINGS; ++j,++i){
                sprintf((char *) (pATCmdStr + i), "v");
            }    
        }
        if(i+6 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
         }else{
            if(NULL != pATCmdStr){
                OslMfree(pATCmdStr);
            }
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
         }    
    }
    /*send AT command request to l4c */
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
    #endif
    return ret;
}
  /****************************************************************************
  * FUNCTION
  *  Java_NetProfileMidsCmd
  * DESCRIPTION
  *  The implement of setting command. This command is used to show the mids setting.
  *
  *       NetProfile <mids name>| <mids index>  [<stroke time>] [,<pause time>]
  *       NetProfile <mids name>| <mids index>  [mode = 0]
  *  
  * [Setting rule]
  *  1.Enter Java box
  *  2.Get the mids menu index 
  *  3.Calculet key pressed sequence to execute the command.
  *  4.Send the AT string to L4C to execute key sequence.
  *
  *  Return 0 on no error or error code.
  *  
  *  Example:
  *      
  *     NetProfile DodgeBall
  *     NetProfile 1
  *
  * PARAMETERS
  * kal_int32  argc
  * kal_char* argv[]
  * RETURNS
  * kal_int32
  *****************************************************************************/
 static kal_int32 
 Java_NetProfileMidsCmd(kal_int32 argc, kal_char * argv [ ])
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
      kal_int32 i,j,len;
      kal_char  * pInStr = NULL;
      kal_int32  stroke_time = STROKE_TIME;
      kal_int32  pause_time  = PAUSE_TIME;
      kal_int32  key_mode = 0;
      kal_char  * pATCmdStr = NULL;
      kal_int32  ret = JAVA_CMD_NO_ERROR;
      kal_uint8 mids_attrib = 0;
      kal_int32  item_cnt = 0;
      kal_int32  mids_idx = 0;
      kal_int32  mids_menu_idx = 0;
      kal_wchar  * pInMidsName = NULL;
      kal_int32 MENU_IDX_NETPROFILE = 4; 
      kal_int32 vm_id = 0;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     #ifdef __PLUTO_MMI_PACKAGE__
     if(app_stricmp(argv[0],(kal_char *)builtInCmds[JAVA_CMD_NAME_NETPROFILE].cmdName)|| 2> argc ||4 < argc){
         return JAVA_CMD_ARG_ERROR;
     }
     if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(vm_id)){
        return JAVA_CMD_JAVA_IS_BUSY;        
     } 
     if (mmi_java_is_no_network_service() || srv_mode_switch_is_network_service_available()){
        return JAVA_CMD_NOT_EXIST;
     }
     pInStr = argv[1];
     if(Java_IsAciiNumeric((const kal_char*)pInStr)){
         mids_menu_idx = atoi((const char *)pInStr) ;
         mids_idx = mids_menu_idx -1;
         mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
     }else{
         /* Try to translate the escaped character into utf-8 encoding*/
         len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
         if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
             return JAVA_CMD_NO_MEM_ERROR;
         }
         memset(pInMidsName, 0,len<<1);
         mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

         mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
         mids_menu_idx = mids_idx + 1;
         OslMfree(pInMidsName);
     }
     g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
     EntryScrJavaMenu();
     item_cnt = g_java.total_java_app_mids;
     if(mids_idx<0 || mids_idx >= item_cnt){
         return JAVA_CMD_ARG_ERROR;
     } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
     mids_attrib = save_mids_infor.mids_attrib;  
     if(argc == 3){
         key_mode = atoi(argv[2]);
     }
	 if (mids_attrib & CAN_BE_UPDATE){ /*since netprofile ine below the update item   */
		 MENU_IDX_NETPROFILE+=1;					   
	 }
	 if(mids_attrib & CAN_BE_REMOVE){	/*since netprofile ine below the delete item */
		 MENU_IDX_NETPROFILE+=1;			 
	 }

     /*construct the AT command string */
     if(key_mode > 0){
         stroke_time =  STROKE_TIME;
         pause_time =  PAUSE_TIME;
         len = strlen("AT+CKPD=\"")+20;
         if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
             return JAVA_CMD_NO_MEM_ERROR;
         }
         memset(pATCmdStr,0,len);
         sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
         i = strlen(pATCmdStr);
         pATCmdStr[i++] = '[';
		 sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_NETPROFILE);
		 i += 1;
         sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
         pATCmdStr[len-1] = 0;
     }else{
         len = strlen("AT+CKPD=\"1")+ item_cnt/2 + 20;
         if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
             return JAVA_CMD_NO_MEM_ERROR;
         }
         memset(pATCmdStr,0,len);
         sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
         i = strlen("AT+CKPD=\"1");
         if(mids_menu_idx < item_cnt/2+1){
             for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                 pATCmdStr[i] = 'V';
             }
         }else{
             for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                 pATCmdStr[i] = '^';
             }
         }
         pATCmdStr[i++] = '[';
		 for(j = 1; j <MENU_IDX_NETPROFILE; ++j,++i){
             sprintf((char *) (pATCmdStr + i), "v");
         }
         if(i+6 < JAVA_COMMAND_AT_MAX_LENGTH){
             if(4 == argc){
                 stroke_time = atoi((const char *)argv[2]);
                 if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                     stroke_time =  STROKE_TIME;
                 }
                 pause_time = atoi((const char *)argv[3]);
                 if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                     pause_time =  PAUSE_TIME;
                 }
             }
             sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
             pATCmdStr[len-1] = 0;
          }else{
             if(NULL != pATCmdStr){
                 OslMfree(pATCmdStr);
             }
             return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
          }    
     }
     /*send AT command request to l4c */
     ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
     OslMfree(pATCmdStr);
     #endif
     return ret;
 }
    /****************************************************************************
    * FUNCTION
    *  Java_RestorNetProfileMidsCmd
    * DESCRIPTION
    *  The implement of restore network profile command. This command is used to restore network profile .
    *
    *       RestoreNetProfile <mids name>| <mids index>  [<stroke time>] [,<pause time>]
    *       RestoreNetProfile <mids name>| <mids index>  [mode = 0]
    *  
    * [Setting rule]
    *  1.Enter Java box
    *  2.Get the mids menu index 
    *  3.Calculet key pressed sequence to execute the command.
    *  4.Send the AT string to L4C to execute key sequence.
    *
    *  Return 0 on no error or error code.
    *  
    *  Example:
    *      
    *     RestoreSettings DodgeBall
    *     RestoreSettings 1
    *
    * PARAMETERS
    * kal_int32  argc
    * kal_char* argv[]
    * RETURNS
    * kal_int32
    *****************************************************************************/
static kal_int32 
Java_RestoreSettingsMidsCmd(kal_int32 argc, kal_char * argv [ ])
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    kal_int32 i,j,len;
    kal_char  * pInStr = NULL;
    kal_int32  stroke_time = STROKE_TIME;
    kal_int32  pause_time  = PAUSE_TIME;
    kal_int32  key_mode = 0;
    kal_char  * pATCmdStr = NULL;
    kal_int32  ret = JAVA_CMD_NO_ERROR;
    kal_uint8 mids_attrib = 0;
    kal_int32  item_cnt = 0;
    kal_int32  mids_idx = 0;
    kal_int32  mids_menu_idx = 0;
    kal_wchar  * pInMidsName = NULL;
    kal_int32 MENU_IDX_RESTORE_SETTINGS = 5; 
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   #ifdef __PLUTO_MMI_PACKAGE__
   if(app_stricmp(argv[0],(kal_char *)builtInCmds[JAVA_CMD_NAME_RESTORE_SETTINGS].cmdName)|| 2> argc ||4 < argc){
       return JAVA_CMD_ARG_ERROR;
   }
   if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
      return JAVA_CMD_JAVA_IS_BUSY;        
   } 
#ifndef OGDR_SECURITY_SETTING
   return JAVA_CMD_NOT_EXIST;
#endif
   if (mmi_java_is_no_network_service() ||srv_mode_switch_is_network_service_available()){
        MENU_IDX_RESTORE_SETTINGS -= 1;
   }

   pInStr = argv[1];
   if(Java_IsAciiNumeric((const kal_char*)pInStr)){
       mids_menu_idx = atoi((const char *)pInStr) ;
       mids_idx = mids_menu_idx -1;
       mids_idx = mmi_java_query_mids_information(NULL, mids_idx);
   }else{
       /* Try to translate the escaped character into utf-8 encoding*/
       len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
       if(NULL == (pInMidsName = (kal_wchar*)OslMalloc(len<<1))){
           return JAVA_CMD_NO_MEM_ERROR;
       }
       memset(pInMidsName, 0,len<<1);
       mmi_chset_utf8_to_ucs2_string((U8 *) pInMidsName,len<<1, (U8 *) pInStr);

       mids_idx = mmi_java_query_mids_information(pInMidsName,-1);
       mids_menu_idx = mids_idx + 1;
       OslMfree(pInMidsName);
   }
   g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
   EntryScrJavaMenu();
   item_cnt = g_java.total_java_app_mids;
   if(mids_idx<0 || mids_idx >= item_cnt){
       return JAVA_CMD_ARG_ERROR;
   } 
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
   mids_attrib = save_mids_infor.mids_attrib; 
   if (mids_attrib & CAN_BE_UPDATE){ /*since netprofile ine below the update item   */
       MENU_IDX_RESTORE_SETTINGS+=1;					   
   }
   if(mids_attrib & CAN_BE_REMOVE){	/*since netprofile ine below the delete item */
	   MENU_IDX_RESTORE_SETTINGS+=1;			 
   }
   if(argc == 3){
       key_mode = atoi(argv[2]);
   }
   /*construct the AT command string */
   if(key_mode > 0){
       stroke_time =  STROKE_TIME;
       pause_time =  PAUSE_TIME;
       len = strlen("AT+CKPD=\"")+20;
       if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
           return JAVA_CMD_NO_MEM_ERROR;
       }
       memset(pATCmdStr,0,len);
       sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",mids_menu_idx);
       i = strlen(pATCmdStr);
       pATCmdStr[i++] = '[';
		   sprintf((char *) (pATCmdStr + i), "%d",MENU_IDX_RESTORE_SETTINGS);
       i += 1; 
       sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
       pATCmdStr[len-1] = 0;
   }else{
       len = strlen("AT+CKPD=\"1")+ item_cnt/2 + 20;
       if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
           return JAVA_CMD_NO_MEM_ERROR;
       }
       memset(pATCmdStr,0,len);
       sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"1");
       i = strlen("AT+CKPD=\"1");
       if(mids_menu_idx < item_cnt/2+1){
           for(j = 0; j < mids_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
               pATCmdStr[i] = 'V';
           }
       }else{
           for(j = 0; (j < item_cnt-mids_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
               pATCmdStr[i] = '^';
           }
       }
       pATCmdStr[i++] = '[';
	   for(j = 1; j <MENU_IDX_RESTORE_SETTINGS; ++j,++i){
           sprintf((char *) (pATCmdStr + i), "v");
       } 
       if(i+6 < JAVA_COMMAND_AT_MAX_LENGTH){
           if(4 == argc){
               stroke_time = atoi((const char *)argv[2]);
               if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                   stroke_time =  STROKE_TIME;
               }
               pause_time = atoi((const char *)argv[3]);
               if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                   pause_time =  PAUSE_TIME;
               }
           }
           sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
           pATCmdStr[len-1] = 0;
        }else{
           if(NULL != pATCmdStr){
               OslMfree(pATCmdStr);
           }
           return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
        }    
   }
   /*send AT command request to l4c */
   ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
   OslMfree(pATCmdStr);
   #endif
   return ret;
}

/*==========================================================================================*/
/*                                          Below this line, we implement java auto verification additional tool commands                                                 */
/*==========================================================================================*/


/****************************************************************************
 * FUNCTION
 *  Java_SnapshotCmd
 * DESCRIPTION
 *  The implement of snapshot command. This command is used to capture current screen and flush to PhoneDisk.
 *
 *       snapshot  [save folder] [prefix]
 *      
 *  
 * [snapshot rule]
 *  1.Check args and create saving forder. 
 *  2.Get the current blt layers.
 *  3.Flatten all layers gotten to a new layer.
 *  4.Encode the layer to JPEG and save to file.
 *
 *  Return 1 on no error or error code.
 *  
 *  Example:
 *      
 *     snapshot 
 *     snapshot save_folder 
 *     snapshot save_folder prefix
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32 
Java_SnapshotCmd(kal_int32 argc, kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define LAYER_BUFFER_SIZE    (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)+64)
    #define PATH_LEN 120
    #define FOLDER_LEN 40
    #define MIN_MEM_LIMIT 40960
    static const kal_char javaImage[]="javaImage";
    static kal_char ImageSaveForder[PATH_LEN] = "default";
    static kal_uint32 ImageIdx;
    kal_char * filepathname;
    kal_wchar wfilepath[PATH_LEN<<1];
    GDI_RESULT retgdi;
    gdi_handle handle[4]={0};
    gdi_handle destlayerhandle = 0;
    kal_int32  len,idx;
    FS_DiskInfo DiskInfo;
    kal_uint32  free_space =0;
    kal_bool loop;
    kal_int16 *gdi_layer_buf = NULL;
    kal_int16  drv;
    kal_uint32 *invalidPtr;
    kal_uint32 whoMalloc = 0;/* 0:jvm_malloc; 1:jam_memlist_malloc; 2:media_get_ext_buffer */
    //extern void * jam_listmem_malloc(kal_int32 size);    
    //extern void jam_listmem_free(void *);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_SNAPSHOT].cmdName)|| 1> argc ||3 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if((2 <= argc)&& app_strnicmp(argv[1],ImageSaveForder,FOLDER_LEN)){
        len = strlen(argv[1]);
        len = len > FOLDER_LEN -1 ?FOLDER_LEN -1:len;
        strncpy(ImageSaveForder,argv[1],len);
        ImageSaveForder[len]='\0';
    }
    /* create the save folder */
    drv = SRV_FMGR_PUBLIC_DRV;
    if ((filepathname = (kal_char *)OslMalloc(PATH_LEN)) == NULL) {
           return JAVA_CMD_NO_MEM_ERROR;
    }
    kal_mem_set(filepathname,0,PATH_LEN);
    sprintf(filepathname,"%c:\\",(kal_char)drv);

    memset(wfilepath,0,PATH_LEN<<1);
    mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepathname);
    if (FS_GetDiskInfo((const WCHAR *)wfilepath, &DiskInfo, FS_DI_FREE_SPACE|FS_DI_BASIC_INFO) >= FS_NO_ERROR){
        free_space = DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
    }
    if (MIN_MEM_LIMIT > free_space){
       drv = SRV_FMGR_CARD_DRV;
       kal_mem_set(filepathname,0,PATH_LEN);
       sprintf(filepathname,"%c:\\",(kal_char)drv);
       if (FS_GetDiskInfo((const WCHAR *)wfilepath, &DiskInfo, FS_DI_FREE_SPACE|FS_DI_BASIC_INFO) >= FS_NO_ERROR){
        free_space = DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
        if(MIN_MEM_LIMIT > free_space){ 
            OslMfree(filepathname);
            return JAVA_CMD_NO_MEM_ERROR;
        }
       }
       
    }
    /*check javaTest exists?*/
    kal_mem_set(filepathname,0,PATH_LEN);
    sprintf(filepathname,"%c:\\%s",(kal_char)drv,javaTest);
    memset(wfilepath,0,PATH_LEN<<1);
    mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepathname);
    if (KAL_TRUE != Java_file_exist((const kal_wchar *) wfilepath)){
        if(0>FS_CreateDir((WCHAR *)wfilepath)){
            OslMfree(filepathname);
            return JAVA_CMD_FILE_DIR_ERROR;
        }
    } 
    /*check javaTest\javaImage exists?*/
    kal_mem_set(filepathname,0,PATH_LEN);
    sprintf(filepathname,"%c:\\%s\\%s",(kal_char)drv,javaTest,javaImage);
    memset(wfilepath,0,PATH_LEN<<1);
    mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepathname);

    if (KAL_TRUE != Java_file_exist((const kal_wchar *) wfilepath)){
        if(0>FS_CreateDir((WCHAR *)wfilepath)){
            OslMfree(filepathname);
            return JAVA_CMD_FILE_DIR_ERROR;
        }
        ImageIdx = 0;
    } 
    /*check javaTest\javaImage\saveimageforder exists?*/
    kal_mem_set(filepathname,0,PATH_LEN);
    sprintf(filepathname,"%c:\\%s\\%s\\%s",(kal_char)drv,javaTest,javaImage,ImageSaveForder);
    memset(wfilepath,0,PATH_LEN<<1);
    mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepathname);
    if (KAL_TRUE != Java_file_exist((const kal_wchar *) wfilepath)){
        if(0>FS_CreateDir((WCHAR *)wfilepath)){
            OslMfree(filepathname);
            return JAVA_CMD_FILE_DIR_ERROR;
        }
        ImageIdx = 0;
    }
    whoMalloc = 0;
    gdi_layer_buf = jvm_malloc(LAYER_BUFFER_SIZE);
    if(NULL == gdi_layer_buf){
        whoMalloc = 1;
        //gdi_layer_buf = (kal_int16 *)jam_listmem_malloc(LAYER_BUFFER_SIZE);
        if(NULL == gdi_layer_buf){
            whoMalloc = 2;
            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
               // media_get_ext_buffer_cacheable(MOD_MMI, (void **)&(gdi_layer_buf), LAYER_BUFFER_SIZE);
            #else /* defined(__ARM9_DCACHEABLE__) */ 
             //   media_get_ext_buffer(MOD_MMI, (void **)&(gdi_layer_buf),LAYER_BUFFER_SIZE);
            #endif /* defined(__ARM9_DCACHEABLE__) */
            if(NULL == gdi_layer_buf){
                OslMfree(filepathname);
                return JAVA_CMD_NO_MEM_ERROR;
            }
        }

    }
    invalidPtr  =  (kal_uint32 *)gdi_layer_buf; 
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) 
{
    kal_int32 remain_bits;
    kal_int32 buffer_32len;
    remain_bits =  ((kal_int32) invalidPtr & (0x1f));
    invalidPtr = (kal_uint32*) ((kal_int32) invalidPtr & (~0x1f));
    buffer_32len= LAYER_BUFFER_SIZE >> 5;
    if ((kal_uint32*)gdi_layer_buf  != invalidPtr){
        buffer_32len += 2;
    }else{
        buffer_32len++;
    }              
    //dynamic_switch_cacheable_region((void *)&invalidPtr, (buffer_32len<<5), PAGE_NO_CACHE);            
    invalidPtr = (kal_uint32 *)((kal_int32)invalidPtr | remain_bits);
}
#endif //__ARM9_DCACHEABLE__    


    /*flatten the current layers to destion layer*/
    if(GDI_LAYER_SUCCEED != gdi_layer_create_using_outside_memory(
        0, 0, UI_device_width, UI_device_height,
        &destlayerhandle, (PU8) invalidPtr, LAYER_BUFFER_SIZE)){
        OslMfree(filepathname);
        jvm_free(gdi_layer_buf);
        return JAVA_CMD_NO_MEM_ERROR;
    }
    retgdi = gdi_layer_get_blt_layer(&handle[0],&handle[1], &handle[2], &handle[3]);
    gdi_layer_push_and_set_active(destlayerhandle);
    for(idx =0; idx <4;idx++){
        if(handle[idx]>0){
            retgdi = gdi_layer_flatten(destlayerhandle,handle[idx],0,0);
            if (GDI_SUCCEED != retgdi){
               return JAVA_CMD_ERROR;
            }
        }
    }    
    gdi_layer_pop_and_restore_active();
    /*Create picture name like " phondisk:\javaTest\javaImage\<prefix><ImageIdx>.jpg" */
    do{
        #define IMAGE_PREFIX_LEN 40
        #define IMAGE_NAME_LEN 50
        #define IMAGE_INDEX_LEN 6
        static kal_char Prefix[IMAGE_PREFIX_LEN];
        kal_char ImageName[IMAGE_NAME_LEN]={0};
        kal_char temp[IMAGE_INDEX_LEN]={0};
        kal_int32 prefixlen=0;
        kal_int32 name_idx = 0;
        kal_mem_set(ImageName,0,IMAGE_NAME_LEN);
        loop = KAL_FALSE;
        /*Save prefix of file*/
        if(3 == argc && NULL != argv[2]){
           prefixlen = strlen(argv[2]);
           if(prefixlen > IMAGE_PREFIX_LEN-1){
                prefixlen = IMAGE_PREFIX_LEN-1;
           }
           if(app_strnicmp((kal_char *) Prefix, (kal_char *)argv[2] , prefixlen)){
                strncpy(Prefix,(const kal_char*)argv[2],prefixlen);
                Prefix[prefixlen] = '\0';
                ImageIdx = 0;
           }
        }
        prefixlen = strlen(Prefix);
        if(prefixlen > 0){
            strncpy(ImageName,(const kal_char*)Prefix,prefixlen);
            ImageName[prefixlen] = '\0';
            name_idx = prefixlen;
        }else{
            name_idx = 0;
        }
        
        Java_itoa(ImageIdx,temp,10);
        len = strlen(temp);
        for(idx = 0; idx <IMAGE_INDEX_LEN - len-1;++idx)ImageName[name_idx+idx] = '0';

        strcat(ImageName,temp);
        kal_mem_set(filepathname,0,PATH_LEN);
#ifdef __MTK_TARGET__
        sprintf(filepathname,"%c:\\%s\\%s\\%s\\%s.jpg",(kal_char)drv,javaTest,javaImage,ImageSaveForder,ImageName);
#else
        sprintf(filepathname,"%c:\\%s\\%s\\%s\\%s.bmp",(kal_char)drv,javaTest,javaImage,ImageSaveForder,ImageName);
#endif
        memset(wfilepath,0,PATH_LEN<<1);
        mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepathname);
        /*we dont want to check whether file exists and if there is a same name file existed on phone disk,then overwite it */
        //if(KAL_TRUE == Java_file_exist(wfilepath)){
        if(++ImageIdx >= 99999){
            ImageIdx = 0;
        }
        //    loop = KAL_TRUE;
        //}
    }while(loop);
    OslMfree(filepathname);
    /*Save the dest layer to file*/
#ifdef __MTK_TARGET__
    retgdi = gdi_layer_save_jpeg_file (destlayerhandle,(CHAR *)wfilepath);
#else
    retgdi = gdi_layer_save_bmp_file (destlayerhandle,(CHAR *)wfilepath);
#endif
    gdi_layer_free(destlayerhandle);
    switch(whoMalloc){
        case 0:
            jvm_free(gdi_layer_buf);
            break;
        case 1:
            //jam_listmem_free((void*)gdi_layer_buf);
            break;
        case 2:
            media_free_ext_buffer(MOD_MMI,(void**)&gdi_layer_buf);
            break;
        default: 
            return  JAVA_CMD_ERROR;            
    }
    
    if (GDI_SUCCEED != retgdi){
        return JAVA_CMD_ERROR;
    }
    return JAVA_CMD_NO_ERROR;
}

/****************************************************************************
 * FUNCTION
 *  Java_FileOperatorCmd
 * DESCRIPTION
 *  The implement of fileExist  command. This command is used to query whether the given file exists.
 *
 *       fileExist <file_path_name>
 *      
 *  
 * [getVM rule]
 *  1.Check whether exist drv in file_path_name. 
 *  2.If there is a drv,then check the file whether exists.
 *  3.Otherwise, query all drv.
 *  4.If file exist the send 1 to l4c by MSG_ID_MMI_L4C_JAVA_CMD_RSP
 *  5.If file exist the send 0 to l4c by MSG_ID_MMI_L4C_JAVA_CMD_RSP
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *
 *     fileExist other/dodgeball.jad 
 *     fileExist phone://other/dodgeball.jar 
 *     fileExist card1://other/dodgeball.jar 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/

static kal_int32 
Java_FileOperatorCmd(kal_int32 argc, kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    kal_int16  drv=0;
    kal_char  * filepath = NULL;
    kal_char  * filefullpath = NULL;
    kal_char  * pInStr = NULL;
    kal_wchar  * wfilepath = NULL;
    kal_int32 len = 0;
    kal_int32 idx = 0;
    kal_int32 ret = 0;
    kal_int32 opcode = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_FILEEXIST].cmdName))
        &&(0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_FILEOPERATOR].cmdName))
        ||( 2>argc || 3<argc)){
        return JAVA_CMD_ARG_ERROR;
    }
    if(2 == argc){
        pInStr = argv[1];
    }else if(3 == argc){
        if(0 == app_stricmp(argv[1],(kal_char*)"-e")){
            opcode = 0;
        }else if(0 == app_stricmp(argv[1],(kal_char*)"-d")){
            opcode = 1;
        }else{
           return JAVA_CMD_ARG_ERROR;
        }
        pInStr = argv[2];
    }
    while(*pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
        pInStr++;
    len = strlen(pInStr);
    if(':' == pInStr[5] || ':' == pInStr[6] || ':' == pInStr[7]){
       /*user set the DRV = phone:/  */
        if(0 == app_strnicmp(pInStr,"phone:/",7)){
            if((drv =  SRV_FMGR_PUBLIC_DRV)<0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"card1:/",7)){
         /* user set the DRV = card1:/   */
            drv =  SRV_FMGR_CARD_DRV;
            if(drv < 0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"card2:/",7)){
        /*  user set the DRV = card2:/   */
            drv =  SRV_FMGR_CARD2_DRV;
            if(drv < 0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"system:/",8)){
            /* user set the DRV = system:/   */
               drv =  SRV_FMGR_SYSTEM_DRV;
               if(drv < 0){
                   return JAVA_CMD_ARG_ERROR;
               }
               filepath = pInStr+8;

        }else if(0 == app_strnicmp(pInStr,"private:/",9)){
            /* user set the DRV = private:/   */
               drv =  SRV_FMGR_PRIVATE_DRV;
               if(drv < 0){
                   return JAVA_CMD_ARG_ERROR;
               }
               filepath = pInStr+9;

        }else{
        /*no the DRV be set by user*/
                return JAVA_CMD_ARG_ERROR;
        }
        /* File check or delete*/
        {
            len = strlen(filepath)+4;
            filefullpath = (kal_char*)OslMalloc(len);
            if(NULL == filefullpath){
                return JAVA_CMD_NO_MEM_ERROR;

            }
            memset(filefullpath,0,len);
            sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
            for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
                if(filefullpath[idx]=='/')filefullpath[idx]='\\';
            }
            len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
            wfilepath = (kal_wchar*)OslMalloc(len<<1);
            if(NULL == wfilepath){
                OslMfree(filefullpath);
                return JAVA_CMD_NO_MEM_ERROR;
            }
            memset(wfilepath,0,len<<1);
            mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
                if(1==opcode){
                    FS_Delete((const WCHAR*)wfilepath); 
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File deleted!");
                }else{
                if(Java_file_exist((const kal_wchar *) wfilepath)){
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,1,"File exist!");
                }else{                
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File No exist!");/* the file doesn't exist on any driver*/
                }
            }
        }
    } else{
   
    /** 
           *     
           *Second Rule implements.
           *   No drv is set in input string, so scan all DRV, until a drv is found,  which contains the file,
           *   then we will try to install the file
           */
     /*SRV_FMGR_PUBLIC_DRV or SRV_FMGR_CARD_DRV or SRV_FMGR_CARD2_DRV*/
        ret  = JAVA_CMD_ERROR; filepath = pInStr;
        if(((drv = (kal_char)SRV_FMGR_PUBLIC_DRV)>0)  || ((drv = (kal_char)SRV_FMGR_CARD2_DRV)>0)){
            len = strlen(pInStr)+4;
            filefullpath = (kal_char*)OslMalloc(len);
            if(NULL == filefullpath){
                return JAVA_CMD_NO_MEM_ERROR;

            }
            memset(filefullpath,0,len);
            sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
            for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
                if(filefullpath[idx]=='/')filefullpath[idx]='\\';
            }
            len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
            wfilepath = (kal_wchar*)OslMalloc(len<<1);
            if(NULL == wfilepath){
                OslMfree(filefullpath);
                return JAVA_CMD_NO_MEM_ERROR;
            }
            memset(wfilepath,0,len<<1);
            mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
                if(1==opcode){
                    FS_Delete((const WCHAR*)wfilepath); 
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File deleted!");
                }else{
                if(Java_file_exist((const kal_wchar *) wfilepath)){
                JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,1,"File exist!");
                }else{
                ret = JAVA_CMD_ERROR;
                }
            }
        }
        if((ret != JAVA_CMD_NO_ERROR) && ((drv = (kal_char)SRV_FMGR_CARD_DRV)>0)){
            sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
            for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
                if(filefullpath[idx]=='/')filefullpath[idx]='\\';
            }
            len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
            memset(wfilepath,0,len<<1);
            mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
                if(1==opcode){
                    FS_Delete((const WCHAR*)wfilepath); 
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File deleted!");
                }else{
                if(Java_file_exist((const kal_wchar *) wfilepath)){
                JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,1,"File exist!");
                }else{
                ret = JAVA_CMD_ERROR;
                }
            }
        }           
        if((ret != JAVA_CMD_NO_ERROR) && ((drv = (kal_char)SRV_FMGR_CARD2_DRV)>0)){
            sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
            for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
                if(filefullpath[idx]=='/')filefullpath[idx]='\\';
            }
            len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
            memset(wfilepath,0,len<<1);
            mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
                if(1==opcode){
                    FS_Delete((const WCHAR*)wfilepath); 
                    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File deleted!");
                }else{
                if(Java_file_exist((const kal_wchar *) wfilepath)){
                JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,1,"File exist!");
                }else{
                ret = JAVA_CMD_ERROR;
                }
            }
        }

        if(JAVA_CMD_ERROR == ret){
            JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"File no exist!");/* the file doesn't exist on any driver*/
        }
           
    }
    if(NULL != filefullpath){
        OslMfree(filefullpath);
        filefullpath = NULL;
    }
    if(NULL != wfilepath){
        OslMfree(wfilepath);
        wfilepath = NULL;
    }
    return JAVA_CMD_NO_ERROR;
}
/****************************************************************************
 * FUNCTION
 *  Java_PhoneHangCmd
 * DESCRIPTION
 *  The implement of phone hang command. This command is used to check whether the phone or j2me task hangs.
 *
 *       phonehang
 *      
 *  
 * [getVM rule]
 *  1.Check args. 
 *  2.Get the Type of swver.
 *  3.send the result to l4c by MSG_ID_MMI_L4C_JAVA_CMD_RSP
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     phonehang 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/

static kal_int32 
Java_PhoneHangCmd(kal_int32 argc, kal_char * argv [ ])
{
    if((1 != argc)||app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_PHONEHANG].cmdName)) {
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    } 
    mmi_java_query_mids_information(NULL, 0);
    memset(&save_mids_infor,0,sizeof(mids_infor_struct));
    return JAVA_CMD_NO_ERROR;
}

/****************************************************************************
 * FUNCTION
 *  Java_PhoneHangCmd
 * DESCRIPTION
 *  The implement of phone hang command. This command is used to check whether the phone or j2me task hangs.
 *
 *       freespace <path>
 *      
 *  
 * [freespace rule]
 *  1.Check args. 
 *  2.Get the Type of swver.
 *  3.send the result to l4c by MSG_ID_MMI_L4C_JAVA_CMD_RSP
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     phonehang 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/

static kal_int32 
Java_GetFreeSpaceSizeCmd(kal_int32 argc, kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 errorCode = JAVA_CMD_NO_ERROR;
    kal_int16 drv[2] = {0};
    kal_int32  free_space = -1;
    FS_DiskInfo DiskInfo;
    kal_wchar* wfilepath = NULL;
    kal_int32  len = 0;
    kal_int32  idx = 0;
    kal_char * filepath = NULL;
    kal_char * pInStr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((2 != argc)||app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_FREESPACE].cmdName)) {
        return JAVA_CMD_ARG_ERROR;
    }
    if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"phone",5)){
        drv[0] = SRV_FMGR_PUBLIC_DRV;drv[1] = 0;
        pInStr= argv[1]+5;
    }else if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"card1",5)){
        drv[0] = SRV_FMGR_CARD_DRV;drv[1] = 0;
        pInStr= argv[1]+5;
    }else if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"card2",5)){
        drv[0] = SRV_FMGR_CARD2_DRV;drv[1] = 0;
        pInStr= argv[1]+5;
    }else if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"system",6)){
        drv[0] = SRV_FMGR_SYSTEM_DRV;drv[1] = 0;
        pInStr= argv[1]+6;
    }else if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"private",7)){
        drv[0] = SRV_FMGR_PRIVATE_DRV;drv[1] = 0;
        pInStr= argv[1]+7;
    }else{
    /*this drv doesnt exist*/
        return  JAVA_CMD_FILE_DIR_ERROR;
    }
    while(*pInStr == ':'|| *pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
        pInStr++;
    len =sizeof(pInStr)+5;
    if(NULL == (filepath = (kal_char*)OslMalloc(len))) {
        return JAVA_CMD_NO_MEM_ERROR;
    }    
    memset(filepath,0,len);
    sprintf((char *) filepath,"%c:\\%s",drv[0],pInStr);
    
    for(idx = 0; *(filepath+idx)!= '\0'; idx++){
        if(filepath[idx]=='/')filepath[idx]='\\';
    }
    len =len <<1;
    if(NULL == (wfilepath = (kal_wchar*)OslMalloc(len))) {
        OslMfree(filepath);
        return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(wfilepath,0,len);
    mmi_asc_to_ucs2((CHAR *)wfilepath, (CHAR *) filepath);
    OslMfree(filepath);
    if (FS_GetDiskInfo((const WCHAR *)wfilepath, &DiskInfo, FS_DI_FREE_SPACE|FS_DI_BASIC_INFO) >= FS_NO_ERROR){
        free_space = DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
        OslMfree(wfilepath);
    }else{
        OslMfree(wfilepath);
        return JAVA_CMD_FILE_DIR_ERROR;
    }
    JAVA_CMD_RSP(errorCode,free_space,"Byte size of free space!");
    return JAVA_CMD_NO_ERROR;
}
/****************************************************************************
 * FUNCTION
 *  Java_FillDiskDrvCmd
 * DESCRIPTION
 *  The implement of fill command, this is a consumed time command. 
 *  This command is used to fill in given disk.
 *  
 *       fill <mode> <drv> <left_size(KB)>|<Folder_prefix> 
 *      
 *  
 *[Rule]
 *
 *  Return 0 on no error or error code.
 *  
 *[NOTICE]
 * .
 *  Example:
 *      
 *     fill in  path  1024
 *     fill out path
 *     fill in  path  Folder_prefix num
 *     fill out path  Folder_prefix   
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32 
Java_FillDiskDrvCmd(kal_int32 argc, kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo DiskInfo;
    kal_int16  drv[2] = {0};
    kal_int32   mode = -1;
    kal_int32   kilo_size = 0;
    kal_uint32  filesize = 0;
    kal_uint32  left_size = 0;
    kal_uint32  offset = 0;
    kal_uint32  free_space = 0;
    kal_wchar   wpath[250] = {0};
    FS_HANDLE   filehandler = -1;
    kal_uint32  fillin_size = 0; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_FILLIN_DRV].cmdName)|| 5 < argc|| 3 > argc){
        return JAVA_CMD_ARG_ERROR;
    }
     /* parse arg[1] */
    if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"in",2)){
        mode = 0;
    }else if(0 == app_strnicmp((kal_char * )argv[1],(kal_char *)"out",3)){
        mode = 1;
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    /* parse arg[2] to get driver */
    if(0 == app_strnicmp((kal_char * )argv[2],(kal_char *)"phone",5)){
        drv[0] = SRV_FMGR_PUBLIC_DRV;drv[1] = 0;
    }else if(0 == app_strnicmp((kal_char * )argv[2],(kal_char *)"card1",5)){
        drv[0] = SRV_FMGR_CARD_DRV;drv[1] = 0;
    }else if(0 == app_strnicmp((kal_char * )argv[2],(kal_char *)"card2",5)){
        drv[0] = SRV_FMGR_CARD2_DRV;drv[1] = 0;
    }else if(0 == app_strnicmp((kal_char * )argv[2],(kal_char *)"system",6)){
        drv[0] = SRV_FMGR_SYSTEM_DRV;drv[1] = 0;
    }else if(0 == app_strnicmp((kal_char * )argv[2],(kal_char *)"private",7)){
        drv[0] = SRV_FMGR_PRIVATE_DRV;drv[1] = 0;
    }else{
    /*this drv doesnt exist*/
        return  JAVA_CMD_FILE_DIR_ERROR;
    }

    /* parse arg[3] to get left size */
    if(argc == 4){
        if(Java_IsAciiNumeric(argv[3])){
            kilo_size = atoi(argv[3]);
            if(kilo_size < 0){
                return JAVA_CMD_FILL_IN_FAILED;
            }
            left_size =  kilo_size * 1024;
        }else{
            left_size = 0;
        }
    }
    kal_wsprintf(wpath,"%c:\\%s\\%s\0",drv[0],atJava,tmpFileName);
    if(0 == mode){
        /*fill in temp file in @java*/
        kal_int32 ret = 0; 
        if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){ 
            if((filehandler = FS_Open((U16*) (wpath), FS_READ_WRITE)) < 0){
                return JAVA_CMD_FILE_DIR_ERROR;
            }
            ret = FS_GetFileSize(filehandler, &filesize);
            offset = filesize;
        }else{
            kal_wsprintf(wpath,"%c:\\%s\0",drv[0],atJava);
            /* check D:\@java folder */
            ret = FS_Open(wpath, FS_OPEN_DIR | FS_READ_ONLY);
            if (ret < FS_NO_ERROR){
                if (ret == FS_FAT_ALLOC_ERROR){
                    return JAVA_CMD_FILE_DIR_ERROR;
                }            
                ret = FS_CreateDir(wpath);
                if (FS_NO_ERROR > ret){
                    return JAVA_CMD_FILE_DIR_ERROR;
                }else{
                    FS_SetAttributes(wpath, FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM);
                    ret = -1;
                }
            }else{
                FS_Close(ret);
                ret = -1;
            }
            kal_wsprintf(wpath,"%c:\\%s\\%s\0",drv[0],atJava,tmpFileName);
            if((filehandler = FS_Open((U16*) (wpath),  FS_CREATE_ALWAYS | FS_READ_WRITE)) < 0){
                return JAVA_CMD_FILE_DIR_ERROR;
            } 
            offset = 0;
        }
        if (FS_GetDiskInfo((const WCHAR *)wpath, &DiskInfo, FS_DI_FREE_SPACE|FS_DI_BASIC_INFO) >= FS_NO_ERROR){
            free_space = DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
        }else{
            FS_Delete((const WCHAR*)wpath);
            return JAVA_CMD_FILE_DIR_ERROR;
        }
        if(free_space < left_size){
            offset =offset - (left_size- free_space);
            if (offset >0 && FS_Seek(filehandler, offset, FS_FILE_BEGIN) >= 0){
                if (FS_Truncate(filehandler) >= FS_NO_ERROR){
                    FS_Delete((const WCHAR*)wpath);
                    return JAVA_CMD_FILE_DIR_ERROR;
                }
                ret = JAVA_CMD_NO_ERROR;
            }else{
                ret = JAVA_CMD_ERROR;
            }
            FS_Close(filehandler);    
            return ret;
        }
        fillin_size = free_space - left_size;
        FS_Seek(filehandler, fillin_size, FS_FILE_BEGIN);
        FS_Close(filehandler);
    }else if(1 == mode){
        FS_Delete((const WCHAR*)wpath);
    }else{
        return JAVA_CMD_ERROR;/* no reason happen*/
    }  
    return JAVA_CMD_NO_ERROR;
}
/****************************************************************************
 * FUNCTION
 *  Java_GetUTCTime
 * DESCRIPTION
 *  The function is use to get current utc time. 
 *  
 *   
 *[NOTICE]
 *
 * PARAMETERS
 * applib_time_struct*  utcCurrTime
 *
 * RETURNS
 * void
 *****************************************************************************/ 
void 
Java_GetCurrentUTCTime(applib_time_struct *utcCurrTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // t_rtc sys_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_mem_set(&sys_time, 0, sizeof(t_rtc));  
    /*get current system RTC time */
  /*  RTC_GetTime((t_rtc*) & sys_time);
    utcCurrTime->nYear  = sys_time.rtc_year + 2000;  
    utcCurrTime->nMonth = sys_time.rtc_mon;   
    utcCurrTime->nDay  = sys_time.rtc_day;
    utcCurrTime->nHour =sys_time.rtc_hour;
    utcCurrTime->nMin  = sys_time.rtc_min;
    utcCurrTime->nSec  =sys_time.rtc_sec;*/
}
/****************************************************************************
 * FUNCTION
 *  Java_DateTimeCmd
 * DESCRIPTION
 *  The implement of Date command. 
 *  This command is used to set a virtual time for vm.
 *  
 *       DateTime    
 *       DateTime  reset
 *       DateTime <Date>|<Time>
 *  
 *[Rule]
 *
 *  Return 6 on no error or error code.
 *  
 *[NOTICE]
 *
 *  Example:
 *      
 *       DateTime
 *       DateTime 2008/10/30 
 *       DateTime 19:30:00
 *       DateTime 2008/10/30 19:30:10
 *       DateTime reset
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/ 
static kal_int32 
Java_DateTimeCmd(kal_int32 argc,kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define  MAX_DATE_TIME_LEN 30
    
    kal_char * preptr = NULL;
    kal_char * postptr = NULL;
    kal_char  strdatetime[MAX_DATE_TIME_LEN]={0};
    applib_time_struct utcSystime;
    static applib_time_struct utcJavaManagerDate;
    static applib_time_struct utclastSystemDate;
    extern void mmi_dt_set_rtc_dt(MYTIME*);
    extern kal_uint32 applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving);
    extern kal_uint8 applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_DATETIME].cmdName)|| 1 > argc ||4 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    if(argc == 1){
        Java_GetCurrentUTCTime(&utcSystime);
        memset(strdatetime,0,MAX_DATE_TIME_LEN);
        sprintf(strdatetime,"%d/%d/%d,%d:%d:%d",utcSystime.nYear,utcSystime.nMonth,utcSystime.nDay,utcSystime.nHour,utcSystime.nMin,utcSystime.nSec);
        strdatetime[MAX_DATE_TIME_LEN-1] = 0;
        JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,strdatetime);
        return JAVA_CMD_NO_ERROR;
    }
    /*Parse argv[2]*/
    if(strlen(argv[1]) >= MAX_DATE_TIME_LEN)
        return JAVA_CMD_ARG_ERROR;
    memset(strdatetime,0,MAX_DATE_TIME_LEN);
    strcpy(strdatetime,argv[1]);
    if(argc ==2){
        if(app_stricmp(argv[1],"reset")==0){
            Java_GetCurrentUTCTime(&utcSystime);
#ifdef __MTK_TARGET__
{
    kal_uint32 u32System = applib_dt_mytime_2_utc_sec((applib_time_struct *)&utcSystime, KAL_TRUE);
    kal_uint32 u32lastSystem = applib_dt_mytime_2_utc_sec((applib_time_struct *)&utclastSystemDate, KAL_TRUE);
    kal_uint32 u32JavaManager = applib_dt_mytime_2_utc_sec((applib_time_struct *)&utcJavaManagerDate, KAL_TRUE);
    u32System = u32lastSystem+u32System-u32JavaManager;            
    applib_dt_utc_sec_2_mytime(u32System, (applib_time_struct *)&utcSystime, KAL_TRUE);
}
#endif

            mmi_dt_set_rtc_dt((MYTIME*)&utcSystime);
            memset(&utclastSystemDate,0,sizeof(utclastSystemDate));
            memset(&utcJavaManagerDate,0,sizeof(utcJavaManagerDate));
            return JAVA_CMD_NO_ERROR;
        }
        if(strchr(strdatetime,'/'))
            goto  PARSE_DATE;
        if(strchr(strdatetime,':'))
            goto  PARSE_TIME;
    }

PARSE_DATE:
    /*Parse Year */
    preptr = strtok_r((kal_char *) strdatetime,(const kal_char *)"/ " ,(kal_char ** )&postptr);
    if(NULL!= preptr){
        kal_int32 intTmp =0;
        if(2000 > (intTmp = atoi(preptr))) 
            return JAVA_CMD_ARG_ERROR;        
        utcJavaManagerDate.nYear = intTmp;
        /*Parse Month */
        preptr = strtok_r(NULL,(const kal_char *)"/" ,(kal_char ** )&postptr);
        if(NULL!=preptr){
            if((intTmp= atoi(preptr)) < 1 || intTmp > 12)
                return JAVA_CMD_ARG_ERROR;
            utcJavaManagerDate.nMonth = intTmp;
            /*Parse Day of month */
            preptr = strtok_r(NULL,(const kal_char *)"/" ,(kal_char ** )&postptr);
            if(NULL!= preptr){
                if((intTmp = atoi(preptr)) < 1 || intTmp > 31) 
                    return JAVA_CMD_ARG_ERROR;
                utcJavaManagerDate.nDay = intTmp;
            }else{
                return JAVA_CMD_ARG_ERROR;
            }
        }else{
            return JAVA_CMD_ARG_ERROR;
        }
        if(argc == 2) goto SUCCESS;
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    if(argc ==3){
        if(strlen(argv[2]) >= MAX_DATE_TIME_LEN)
            return JAVA_CMD_ARG_ERROR;
        memset(strdatetime,0,MAX_DATE_TIME_LEN);
        strcpy(strdatetime,argv[2]);
    }else{
        return JAVA_CMD_ARG_ERROR;
    }

PARSE_TIME:
    preptr = strtok_r((kal_char *) strdatetime,(const kal_char *)": " ,(kal_char ** )&postptr);
    if(NULL!=preptr){
        kal_int32 intTmp =0;
        /*Parse Hour*/
        if((intTmp = atoi(preptr))<0 ||intTmp > 23) 
            return JAVA_CMD_ARG_ERROR;
        utcJavaManagerDate.nHour = intTmp;
        /*Parse Minute*/
        preptr = strtok_r(NULL,(const kal_char *)":" ,(kal_char ** )&postptr);
        if(NULL!= preptr){
            if((intTmp = atoi(preptr)) < 0 || intTmp > 59) 
                return JAVA_CMD_ARG_ERROR;
            utcJavaManagerDate.nMin = intTmp;
            /*Parse Second*/
            preptr = strtok_r(NULL,(const kal_char *)":" ,(kal_char ** )&postptr);
            if(NULL!= preptr){
                if((intTmp = atoi(preptr)) < 0 || intTmp > 59) 
                    return JAVA_CMD_ARG_ERROR;
                utcJavaManagerDate.nSec = intTmp;
            }else{
                utcJavaManagerDate.nSec = 0;
            }
        }else{
            return JAVA_CMD_ARG_ERROR;
        }        
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    
SUCCESS:
    /* set java manager date and time*/    
    Java_GetCurrentUTCTime(&utclastSystemDate);
    mmi_dt_set_rtc_dt((MYTIME*)&utcJavaManagerDate);
    return JAVA_CMD_NO_ERROR;
}

/****************************************************************************
 * FUNCTION
 *  Java_UploadMMSCmd
 * DESCRIPTION
 *  The implement of uploadmms  command. 
 *  This command is used to upload a .mms file into mms folder.
 *  
 *  
 *[Rule]
 *
 *  Return 6 on no error or error code.
 *  
 *[NOTICE]
 * This command can be used while neigther VM is running nor backgroud Runing.
 * Otherwise, The invocation may cause broken down phone.
 *  Example:
 *      
 *     uploadmms filepath 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	filePath[100];
} mmi_java_upload_mms_req_ind_struct;
static kal_int32 
Java_UploadMMSCmd(kal_int32 argc,kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16  drv= 0;
    kal_int32  len = 0;
    kal_int32  idx = 0;
    kal_char* pInStr = NULL;
    kal_char* filepath = NULL;
    kal_char* filefullpath = NULL;
    kal_wchar* wfilepath = NULL;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_UPLOADMMS].cmdName)|| 2 != argc){
        return JAVA_CMD_ARG_ERROR;
    }
    pInStr = argv[1];
    while(*pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
    	 pInStr++;
    len = strlen(pInStr);
    if(len<5||len>=100) return JAVA_CMD_ARG_ERROR;

    /*user set the DRV = phone:/  */
    if(0 == app_strnicmp(pInStr,"phone:/",7)){
        if((drv =	SRV_FMGR_PUBLIC_DRV)<0){
            return JAVA_CMD_ARG_ERROR;
        }
        filepath = pInStr+7;
    }else if(0 == app_strnicmp(pInStr,"card1:/",7)){
      /* user set the DRV = card1:/   */
        drv =   SRV_FMGR_CARD_DRV;
        if(drv < 0){
        	 return JAVA_CMD_ARG_ERROR;
        }
        filepath = pInStr+7;
    }else if(0 == app_strnicmp(pInStr,"card2:/",7)){
        /*  user set the DRV = card2:/   */
        drv =	SRV_FMGR_CARD2_DRV;
        if(drv < 0){
           return JAVA_CMD_ARG_ERROR;
        }
        filepath = pInStr+7;
    }else{
    /*no the DRV be set by user*/
        return JAVA_CMD_ARG_ERROR;
    }

    len = strlen(filepath)+4;
    filefullpath = (kal_char*)OslMalloc(len);
    if(NULL == filefullpath){
         return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(filefullpath,0,len);
    sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
    for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
       if(filefullpath[idx]=='/')filefullpath[idx]='\\';
    }
    len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
    wfilepath = (kal_wchar*)OslMalloc(len<<1);
    if(NULL == wfilepath){
       OslMfree(filefullpath);
       return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(wfilepath,0,len<<1);
    mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
    OslMfree(filefullpath);
#if defined(MMS_SUPPORT)	
    {
        MYQUEUE msg;
        mmi_java_upload_mms_req_ind_struct *ptrinds = NULL;
        ptrinds = (mmi_java_upload_mms_req_ind_struct*) OslConstructDataPtr(sizeof(mmi_java_upload_mms_req_ind_struct));

        app_ucs2_strcpy((kal_int8*)ptrinds->filePath,(const kal_int8*)wfilepath);
        OslMfree(wfilepath);
        msg.oslSrcId = MOD_MMI;
        msg.oslDestId = MOD_MMI;
        msg.oslMsgId = MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND;
        msg.oslDataPtr = (oslParaType*) ptrinds;
        msg.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&msg);
    }
#endif
    return JAVA_CMD_NO_ERROR;
}


/****************************************************************************
 * FUNCTION
 *  Java_ClearAllMIDSCmd
 * DESCRIPTION
 *  The implement of clearAll  command. 
 *  This command is used to clear all mids installed on phone by user or clear all tmp file.
 *  
 *       dminstall 
 *      
 *  
 *[Rule]
 *
 *  Return 6 on no error or error code.
 *  
 *[NOTICE]
 * This command can be used while neigther VM is running nor backgroud Runing.
 * Otherwise, The invocation may cause broken down phone.
 *  Example:
 *      
 *     dminstall 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/ 
static kal_int32 
Java_DminstallMidsCmd(kal_int32 argc,kal_char * argv [ ])
{
#ifdef __DM_SCOMO_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16  drv=0;
    kal_char  * filepath = NULL;
    kal_char  * filefullpath = NULL;
    kal_char  * pInStr = NULL;
    kal_wchar  * wfilepath = NULL;
    kal_int32  mode = 0;
    kal_int32  len = 0;
    kal_int32  idx = 0;
    srv_dm_scomo_java_cmd_info_struct * scomo_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_DMINSTALL].cmdName)
        || 4 != argc
        || argv[1]==NULL||strlen(argv[1])==0
        || argv[2]==NULL||strlen(argv[2])==0
        || argv[3]==NULL||strlen(argv[3])==0 ){
        return JAVA_CMD_ARG_ERROR;
    }
    if(Java_IsAciiNumeric((const kal_char*)argv[1])){
        mode = atoi((const char *)argv[1]);
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    pInStr = argv[2];
    while(*pInStr == ' '||*pInStr == '\\' || *pInStr == '/' || *pInStr == '\t'||*pInStr == '\n')
        pInStr++;
    len = strlen(pInStr);
    if(':' == pInStr[5] || ':' == pInStr[6] || ':' == pInStr[7]){
       /*user set the DRV = phone:/  */
        if(0 == app_strnicmp(pInStr,"phone:/",7)){
            if((drv =  SRV_FMGR_PUBLIC_DRV)<0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"card1:/",7)){
         /* user set the DRV = card1:/   */
            drv =  SRV_FMGR_CARD_DRV;
            if(drv < 0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"card2:/",7)){
        /*  user set the DRV = card2:/   */
            drv =  SRV_FMGR_CARD2_DRV;
            if(drv < 0){
                return JAVA_CMD_ARG_ERROR;
            }
            filepath = pInStr+7;
        }else if(0 == app_strnicmp(pInStr,"system:/",8)){
            /* user set the DRV = system:/   */
               drv =  SRV_FMGR_SYSTEM_DRV;
               if(drv < 0){
                   return JAVA_CMD_ARG_ERROR;
               }
               filepath = pInStr+8;

        }else if(0 == app_strnicmp(pInStr,"private:/",9)){
            /* user set the DRV = private:/   */
               drv =  SRV_FMGR_PRIVATE_DRV;
               if(drv < 0){
                   return JAVA_CMD_ARG_ERROR;
               }
               filepath = pInStr+9;

        }else{
        /*no the DRV be set by user*/
                return JAVA_CMD_ARG_ERROR;
        }
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    /* File check or delete*/

    len = strlen(filepath)+4;
    filefullpath = (kal_char*)OslMalloc(len);
    if(NULL == filefullpath){
        return JAVA_CMD_NO_MEM_ERROR;

    }
    memset(filefullpath,0,len);
    sprintf(filefullpath,"%c:\\%s",(kal_char)(drv),filepath);
    for(idx = 0; *(filefullpath+idx)!= '\0'; idx++){
        if(filefullpath[idx]=='/')filefullpath[idx]='\\';
    }
    len = Java_URLDecodeToUTF8((kal_char *) filefullpath)+1;
    wfilepath = (kal_wchar*)OslMalloc(len<<1);
    if(NULL == wfilepath){
        OslMfree(filefullpath);
        return JAVA_CMD_NO_MEM_ERROR;
    }
    memset(wfilepath,0,len<<1);
    mmi_chset_utf8_to_ucs2_string((U8 *)wfilepath,len<<1,(U8 *)(filefullpath));
    OslMfree(filefullpath);

    
    scomo_info =(srv_dm_scomo_java_cmd_info_struct*) OslMalloc(sizeof(srv_dm_scomo_java_cmd_info_struct));
    memset(scomo_info,0,sizeof(srv_dm_scomo_java_cmd_info_struct));
    if(mode==0){        
        scomo_info->display_mode =SRV_DM_SCOMO_DISPLAY_MODE_DEFAULT;
    }else if(mode == 1){
        scomo_info->display_mode = SRV_DM_SCOMO_DISPLAY_MODE_CONFIRM;
    }else if(mode == 2){
        scomo_info->display_mode = SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND;
    }else{
        OslMfree(scomo_info);
        return JAVA_CMD_ARG_ERROR;
    }    
    if(Java_file_exist((const kal_wchar *) wfilepath)==KAL_FALSE)
    {
        return JAVA_CMD_ARG_ERROR;
    }
    memcpy(scomo_info->pkg_install_path,wfilepath,len <<1);
    memcpy(scomo_info->pkg_network_url,argv[3],strlen(argv[3]));
    mmi_java_dmui_scomo_cb(SRV_DM_SCOMO_CMD_INSTALL, scomo_info);
    OslMfree(wfilepath);
    OslMfree(scomo_info);
    return JAVA_CMD_NO_ERROR;
#else
        return JAVA_CMD_NO_ERROR;
#endif

}
static kal_int32 
Java_DmdeleteMidsCmd(kal_int32 argc,kal_char * argv [ ])
{
#ifdef __DM_SCOMO_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  mode = 0;
    srv_dm_scomo_java_cmd_info_struct * scomo_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[Java_CMD_NAME_DMDELETE].cmdName)
        || 3 != argc
        || argv[1]==NULL||strlen(argv[1])==0
        || argv[2]==NULL||strlen(argv[2])==0){
        return JAVA_CMD_ARG_ERROR;
    }
    if(Java_IsAciiNumeric((const kal_char*)argv[1])){
        mode = atoi((const char *)argv[1]);
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    scomo_info =(srv_dm_scomo_java_cmd_info_struct*) OslMalloc(sizeof(srv_dm_scomo_java_cmd_info_struct));
    memset(scomo_info,0,sizeof(srv_dm_scomo_java_cmd_info_struct));
    
    if(mode==0){        
        scomo_info->display_mode =SRV_DM_SCOMO_DISPLAY_MODE_DEFAULT;
    }else if(mode == 1){
        scomo_info->display_mode = SRV_DM_SCOMO_DISPLAY_MODE_CONFIRM;
    }else if(mode == 2){
        scomo_info->display_mode = SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND;
    }else{
        OslMfree(scomo_info);
        return JAVA_CMD_ARG_ERROR;
    }    
    memcpy(scomo_info->app_software_id,argv[2],strlen(argv[2]));
    mmi_java_dmui_scomo_cb(SRV_DM_SCOMO_CMD_REMOVE, scomo_info);
    OslMfree(scomo_info);
    return JAVA_CMD_NO_ERROR;
#else
    return JAVA_CMD_NO_ERROR;
#endif
}


#endif

/****************************************************************************
 * FUNCTION
 *  Java_ClearAllMIDSCmd
 * DESCRIPTION
 *  The implement of clearAll  command. 
 *  This command is used to clear all mids installed on phone by user or clear all tmp file.
 *  
 *       clearAll
 *      
 *  
 *[Rule]
 *
 *  Return 6 on no error or error code.
 *  
 *[NOTICE]
 * This command can be used while neigther VM is running nor backgroud Runing.
 * Otherwise, The invocation may cause broken down phone.
 *  Example:
 *      
 *     clearAll 
 *
 * PARAMETERS
 * kal_int32  argc
 * kal_char* argv[]
 * RETURNS
 * kal_int32
 *****************************************************************************/ 
static kal_int32 
Java_ClearAllCmd(kal_int32 argc,kal_char * argv [ ])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16  drv[2] = {0};
    kal_wchar  wpath[30]={0};
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_CLEARALLMIDS].cmdName)|| 1 > argc||2 < argc){
        return JAVA_CMD_ARG_ERROR;
    }
    drv[0] = SRV_FMGR_PUBLIC_DRV;drv[1] = 0;
    kal_wsprintf(wpath,"%c:\\%s\\%s\0",drv,atJava,tmpFileName);
    if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){
        FS_Delete((const WCHAR*)wpath);
    }
    wpath[0] = SRV_FMGR_CARD_DRV;
    if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){
        FS_Delete((const WCHAR*)wpath);
    }
    wpath[0] = SRV_FMGR_CARD2_DRV;
    if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){    
        FS_Delete((const WCHAR*)wpath);   
    }
    wpath[0] = SRV_FMGR_SYSTEM_DRV;
    if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){
        FS_Delete((const WCHAR*)wpath); 
    }
    
    wpath[0] = SRV_FMGR_PRIVATE_DRV;
    if(KAL_TRUE == (Java_file_exist((const kal_wchar *) wpath))){
        FS_Delete((const WCHAR*)wpath); 
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(vm_id)){
        return JAVA_CMD_JAVA_IS_BUSY;        
    }

#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
    javaFileGenerator(KAL_TRUE);
#else
    return JAVA_CMD_ERROR;
#endif
#ifdef __JBLENDIA__
    {    
        extern void kjava_reset_game_list(void);
        kjava_reset_game_list();
    }
#endif
    JAVA_CMD_RSP(JAVA_CMD_NO_ERROR,0,"Clear All mids successfully!");
    return JAVA_CMD_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
  *  Java_JavaBoxCmd
 * DESCRIPTION
  *  The command go to java box.
  *
  *  Return 0 on no error or error code.  
 *  
 * PARAMETERS
  * kal_int32 argc
  * kal_char* argv[]
 * RETURNS
  * kal_int32
 *****************************************************************************/
 static kal_int32
 Java_JavaBoxCmd(kal_int32 argc, kal_char* argv[])
{
#ifdef __PLUTO_MMI_PACKAGE__
     if( 0 != app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_JAVABOX].cmdName) ||1 != argc){
         return JAVA_CMD_ARG_ERROR;
        }
     g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
     EntryScrJavaMenu();
#endif
     return JAVA_CMD_NO_ERROR;
}


extern void jam_mids_getlist_exit_free(void);
 /****************************************************************************
 * FUNCTION
 *  Java_LaunchMidCmd
 * DESCRIPTION
 *  The implement of launch command.
 *
 *       launch <mids name>| <mids index>  [<stroke time>] [,<pause time>]
 *       launch <mids name>| <mids index>  [mode = 0]
 *  
 * [Rule]
 *  1.Enter Java box
 *  2.Get the mids menu index 
 *  3.Calculet key pressed sequence to execute the command.
 *  4.Send the AT string to L4C to execute key sequence.
 *
 *  Return 0 on no error or error code.
 *  
 *  Example:
 *      
 *     launch DodgeBall
 *     launch 1
 *[NOTICE]
 * This command must be used after select command.
 *[PARAMETERS]
 * kal_int32  argc
 * kal_char* argv[]
 *[RETURNS]
 * kal_int32
 *****************************************************************************/
static kal_int32
Java_LaunchMidCmd(kal_int32 argc, kal_char* argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_int32 i,j,len;
     kal_char  * pInStr = NULL;
     kal_int32  stroke_time = STROKE_TIME;
     kal_int32  pause_time  = PAUSE_TIME;
     kal_char  * pATCmdStr = NULL;
     kal_int32  ret = JAVA_CMD_NO_ERROR;
     kal_int32  key_mode = 0;
     kal_int32 launch_mode = 0;
     kal_int32  mids_idx = 0;
     kal_int32  midlet_cnt = 0;
     kal_int32  midlet_idx = 0;
     kal_int32  midlet_menu_idx = 0;
     kal_wchar  * pMidletName = NULL;
     kal_wchar  * pInMidletName = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(app_stricmp(argv[0],(kal_char*)builtInCmds[JAVA_CMD_NAME_LAUNCH].cmdName)|| 2> argc ||5 < argc)
    {
        return JAVA_CMD_ARG_ERROR;
    }
    if(KAL_TRUE == jam_vm_is_busy()||JVM_TERMINATE_STATE != jam_mvm_get_vm_state(0))
    {
        return JAVA_CMD_JAVA_IS_BUSY;        
    }     
    if(argc == 4&&Java_IsAciiNumeric((const char*)argv[argc-1]))
    {
        launch_mode =  atoi(argv[argc-1]);
    }else{
        return JAVA_CMD_ARG_ERROR;
    }
    if(launch_mode != 0)
    {
        mmi_java_mid_start_req_struct *msg;
        if(Java_IsAciiNumeric((const char*)argv[1]))
        {
            mids_idx = atoi((const char *)argv[1]) ;
        }else{
            return JAVA_CMD_ARG_ERROR;
        }
        if(Java_IsAciiNumeric((const char*)argv[2]))
        {
            midlet_idx = atoi((const char *)argv[2]);
        }
        else
        {
            return JAVA_CMD_ARG_ERROR;
    }
        if(!mmi_idle_is_active())
        {
            return JAVA_CMD_IS_NOT_IN_IDLE;
        }
        mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);
        if(g_java.total_java_app_mids < mids_idx || mids_idx< 1)
        {
            jam_mids_getlist_exit_free();
            return JAVA_CMD_ARG_ERROR;
        }
        if(mmi_java_get_mid_list_in_mids(mids_idx)==KAL_FALSE)
        {
            jam_mids_getlist_exit_free();
            return JAVA_CMD_JAVA_IS_BUSY;
        }
        if(midlet_idx < 1||midlet_idx>g_java.total_java_app_mid)
        {
            jam_mids_getlist_exit_free();
            return JAVA_CMD_ARG_ERROR;
        }
        jam_call_back_functions.jam_free_list();
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_JAVA_APP, jam_sg_proc, NULL);
        mmi_frm_group_enter(GRP_ID_JAVA_APP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_scrn_enter(GRP_ID_JAVA_APP,SCR_JAVA_DUMMY,NULL,NULL,MMI_FRM_FULL_SCRN);  
        msg = (mmi_java_mid_start_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_start_req_struct));
        msg->mids_id = mids_idx;
        msg->mid_id = midlet_idx;
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MID_START_REQ, msg);
        return JAVA_CMD_NO_ERROR;
    }
    else
    {
    /**
        * Processing the argv[1]
        */
    pInStr = argv[1];
    mids_idx = g_java.mids_index - g_java.mids_info_start;
    midlet_cnt = g_java.mids_info[mids_idx].mid_count;
    if(Java_IsAciiNumeric((const kal_char*)pInStr)){
        midlet_idx = atoi((const char *)pInStr) ;
        midlet_menu_idx = midlet_idx;
    }else{
        /* Try to translate the escaped character into utf-8 encoding*/
        len = Java_URLDecodeToUTF8((kal_char *) pInStr)+1;
        if(NULL == (pInMidletName = (kal_wchar*)OslMalloc(len<<1))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pInMidletName, 0,len<<1);
        mmi_chset_utf8_to_ucs2_string((U8 *) pInMidletName,len<<1, (U8 *) pInStr);
       
        for(midlet_idx = 0; midlet_idx < midlet_cnt;midlet_idx++){
            pMidletName = (kal_wchar  *)g_java.mid_info[midlet_idx].mid_name;
            if(0 == mmi_ucs2icmp((const CHAR *) pInMidletName, (const CHAR *) pMidletName)){
               break;
            }
        }
        midlet_menu_idx = midlet_idx + 1;
        OslMfree(pInMidletName);
    }
    if(midlet_idx<0 || midlet_idx >= midlet_cnt){
        return JAVA_CMD_ARG_ERROR;
    } 
    if(1 == midlet_cnt){
        return JAVA_CMD_NO_ERROR;
    }
   /**
       *Send AT command REQ to L4C 
       */
    if(argc == 3){
        key_mode = atoi(argv[2]);
    }
    /*construct the AT command string */
    if(key_mode > 0){
        stroke_time =  STROKE_TIME;
        pause_time =  PAUSE_TIME;
        len = strlen("AT+CKPD=\"")+20;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        memset(pATCmdStr,0,len);
        sprintf((char *) (pATCmdStr+ 0), "AT+CKPD=\"%d",midlet_menu_idx);
        i = strlen(pATCmdStr);
        sprintf((char *) (pATCmdStr + i), "[\",%d,%d",stroke_time,pause_time);
        pATCmdStr[len-1] = 0;
    }else{
        len = strlen("AT+CKPD=\"1")+midlet_menu_idx+4+10;
        if(NULL == (pATCmdStr = (kal_char*)OslMalloc(len))){
            return JAVA_CMD_NO_MEM_ERROR;
        }
        sprintf((char *) (pATCmdStr + 0), "AT+CKPD=\"1");
        i = strlen("AT+CKPD=\"1");
        if(midlet_menu_idx < midlet_cnt/2+1){
            for(j = 0; j < midlet_menu_idx-1 && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = 'V';
            }
        }else{
            for(j = 0; (j < midlet_cnt-midlet_menu_idx+1) && i < JAVA_COMMAND_AT_MAX_LENGTH;++j,++i){
                pATCmdStr[i] = '^';
            }
        }
        pATCmdStr[i++] = '[';
        if(i+7 < JAVA_COMMAND_AT_MAX_LENGTH){
            if(4 == argc){
                stroke_time = atoi((const char *)argv[2]);
                if( STROKE_TIME > stroke_time || MAX_STROKE_TIME < stroke_time){
                    stroke_time =  STROKE_TIME;
                }
                pause_time = atoi((const char *)argv[3]);
                if( PAUSE_TIME > pause_time || MAX_PAUSE_TIME < pause_time){
                    pause_time =  PAUSE_TIME;
                }
            }
            sprintf((char *) (pATCmdStr + i), "\",%d,%d",stroke_time,pause_time);
            pATCmdStr[len-1] = 0;
        }else{
            OslMfree(pATCmdStr);
            return JAVA_CMD_ERROR; /* This should not happen for ever!since we cannot construct a AT command string whose length is larger than 128*/
        }   
    }
    /*send AT command request to l4c */   
    ret = mmi_l4c_send_at_cmd_req(pATCmdStr);
    OslMfree(pATCmdStr);
    }
    return ret;
}
#endif
