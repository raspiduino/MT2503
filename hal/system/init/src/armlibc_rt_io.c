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
 *   armlibc_rt_io.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides runtime support for RVCT31 C library stdio functionality
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
  
#if defined(__RVCT__) && defined(__MTK_TARGET__)

#define CLIB_H /* don't include clib.h */
#include "kal_release.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <rt_sys.h>

/*******************************************************************************
tailoring IO subsystem
*******************************************************************************/
const char __stdin_name[] = ":tt:in";
const char __stdout_name[] = ":tt:out";
const char __stderr_name[] = ":tt:err";
FILEHANDLE _sys_open(const char *filename, int mode)
{
    if (strcmp(filename, __stdin_name) == 0) {
        return 0;
    }
    else if (strcmp(filename, __stdout_name) == 0) {
        return 1;
    }
    else if (strcmp(filename, __stderr_name) == 0) {
        return 2;
    }
    return -1;
}
int _sys_close(FILEHANDLE fh)
{
    return 0;
}
int _sys_read(FILEHANDLE fh, unsigned char * buf,
                 unsigned len, int mode)
{
    memset(buf, 0, len);
    return 0;
}
int _sys_write(FILEHANDLE fh, const unsigned char * buf,
                 unsigned len, int mode)
{
    // discard
    return 0;
}
long _sys_flen(FILEHANDLE fh)
{
    return -1;
}
int _sys_seek(FILEHANDLE fh, long pos)
{
    return -1;
}
int _sys_istty(FILEHANDLE fh)
{
    return 1;
}
int _sys_ensure(FILEHANDLE fh)
{
    return 0;
}
int __backspace(FILE *stream)
{
    return EOF;
}

struct __FILE
{
    long __unused;
};
FILE __stdin, __stdout, __stderr;
FILE *__aeabi_stdin = &__stdin, *__aeabi_stdout = &__stdout, *__aeabi_stderr = &__stderr;

#undef  NOTSUPPORT_FUNCTION
#define NOTSUPPORT_FUNCTION

/************ Part I: output to standard output discarded *********************/

int printf(const char * __restrict format, ...)
{
#pragma import(clib_init_io)
    return 0;
}
int _printf(const char * __restrict format, ...)
{
#pragma import(clib_init_io)
    return 0;
}
int __0printf(const char * __restrict format, ...)
{
#pragma import(clib_init_io)
    return 0;
}
int __1printf(const char * __restrict format, ...)
{
#pragma import(clib_init_io)
    return 0;
}

int vprintf(const char * __restrict format, va_list arg)
{
#pragma import(clib_init_io)
    return 0;
}
int _vprintf(const char * __restrict format, va_list arg)
{
#pragma import(clib_init_io)
    return 0;
}
int __0vprintf(const char * __restrict format, va_list arg)
{
#pragma import(clib_init_io)
    return 0;
}
int __1vprintf(const char * __restrict format, va_list arg)
{
#pragma import(clib_init_io)
    return 0;
}

int puts(const char * s)
{
#pragma import(clib_init_io)
    return 0;
}

#undef putchar
int putchar(int c)
{
#pragma import(clib_init_io)
    return 0;
}

/************ Part II: Available functions for WISDOM_MMI *********************/

#ifndef WISDOM_MMI
FILE *fopen(const char * __restrict filename,
            const char * __restrict mode) NOTSUPPORT_FUNCTION
{
    return NULL;
}

FILE *freopen(const char * __restrict filename,
              const char * __restrict mode,
              FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
    return NULL;
}

int fclose(FILE * stream) NOTSUPPORT_FUNCTION
{
    return EOF;
}

int fprintf(FILE * __restrict stream,
            const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
    return EOF;
}

size_t fread(void * __restrict ptr,
             size_t size, size_t nmemb, FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
    return 0;
}

size_t fwrite(const void * __restrict ptr,
              size_t size, size_t nmemb, FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
    return 0;
}

int fputc(int c, FILE * stream) NOTSUPPORT_FUNCTION
{
    return EOF;
}

int fputs(const char * __restrict s, FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
    return EOF;
}

void perror(const char * s)
{
}

#endif
 
/************ Part III: Disabled functions for all projects *******************/

int _fprintf(FILE * __restrict stream,
             const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __0fprintf(FILE * __restrict stream,
             const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __1fprintf(FILE * __restrict stream,
             const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
            
int fflush(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return 0;
}

void setbuf(FILE * __restrict stream,
            char * __restrict buf) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
}

int setvbuf(FILE * __restrict stream,
            char * __restrict buf,
            int mode, size_t size) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int fscanf(FILE * __restrict stream,
           const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int _fscanf(FILE * __restrict stream,
            const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __0fscanf(FILE * __restrict stream,
            const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int scanf(const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int _scanf(const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __0scanf(const char * __restrict format, ...) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int vfscanf(FILE * __restrict stream, const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int _vfscanf(FILE * __restrict stream, const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __0vfscanf(FILE * __restrict stream, const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int vscanf(const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int _vscanf(const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int __0vscanf(const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int vfprintf(FILE * __restrict stream,
             const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
int _vfprintf(FILE * __restrict stream,
              const char * __restrict format, va_list arg) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}
            
int fgetc(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

char *fgets(char * __restrict s, int n,
            FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return NULL;
}

int getc(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

#undef getchar
int getchar(void) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

char *gets(char * s) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return NULL;
}

int putc(int c, FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int ungetc(int c, FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

size_t __fread_bytes_avail(void * __restrict ptr,
                           size_t count, FILE * __restrict stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return 0;
}

int fgetpos(FILE * __restrict stream, fpos_t * __restrict pos) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int fseek(FILE * stream, long int offset, int whence) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int fsetpos(FILE * __restrict stream, const fpos_t * __restrict pos) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

long int ftell(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

void rewind(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
}

void clearerr(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
}

int feof(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int ferror(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

int _fisatty(FILE * stream) NOTSUPPORT_FUNCTION
{
#pragma import(clib_init_io)
    return EOF;
}

/************ Part IV: clib initialze io interface ****************************/

int clib_init_io(void)
{
    return 0;
}

#endif /* __MTK_TARGET__ && __RVCT__ */
