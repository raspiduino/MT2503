/*-
 * Copyright (c) 1982, 1986, 1991, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)types.h	8.6 (Berkeley) 2/19/95
 * $FreeBSD: src/sys/sys/types.h,v 1.90 2004/06/19 17:58:32 marcel Exp $
 */

#ifndef _IPSEC_TYPES_H_
#define	_IPSEC_TYPES_H_

#include "soc2tcpip_struct.h"

//#if __BSD_VISIBLE
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#ifndef _KERNEL
typedef	unsigned short	ushort;		/* Sys V compatibility */
typedef	unsigned int	uint;		/* Sys V compatibility */
#endif
//#endif

/* !!! include the kal_non_specific_general_types.h */
/*
 * XXX POSIX sized integrals that should appear only in <sys/stdint.h>.
 */
#ifndef _INT8_T_DECLARED
typedef	kal_uint8	int8_t;
#define	_INT8_T_DECLARED
#endif

#ifndef _INT16_T_DECLARED
typedef	kal_int16	int16_t;
#define	_INT16_T_DECLARED
#endif

#ifndef _INT32_T_DECLARED
typedef	kal_int32	int32_t;
#define	_INT32_T_DECLARED
#endif

#ifndef _INT64_T_DECLARED
typedef	kal_int64	int64_t;
#define	_INT64_T_DECLARED
#endif

#ifndef _UINT8_T_DECLARED
typedef	kal_uint8	uint8_t;
#define	_UINT8_T_DECLARED
#endif

#ifndef _UINT16_T_DECLARED
typedef	kal_uint16	uint16_t;
#define	_UINT16_T_DECLARED
#endif

#ifndef _UINT32_T_DECLARED
typedef	kal_uint32	uint32_t;
#define	_UINT32_T_DECLARED
#endif

#ifndef _UINT64_T_DECLARED
typedef	kal_uint64	uint64_t;
#define	_UINT64_T_DECLARED
#endif

#if 0   //// hyzhang
#ifndef _INTPTR_T_DECLARED
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif 

/* there is define in the soc2tcpip_struct.h */
#ifndef _SOC2TCPIP_STRUCT_H
typedef kal_uint8	u_int8_t;	/* unsigned integrals (deprecated) */
typedef kal_uint16	u_int16_t;
typedef kal_uint32	u_int32_t;
#endif

typedef kal_uint64	u_int64_t;

typedef	kal_uint64	u_quad_t;	/* quads (deprecated) */
typedef	kal_int64	quad_t;
typedef	quad_t *	qaddr_t;

typedef	char *		caddr_t;	/* core address */
typedef	const char *	c_caddr_t;	/* core address, pointer to const */
typedef	volatile char *v_caddr_t;	/* core address, pointer to volatile */

#ifndef _PID_T_DECLARED
typedef	kal_int32		pid_t;		/* process id */
#define	_PID_T_DECLARED
#endif

#if 0 //// hyzhang 
#ifndef _CLOCK_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _CLOCKID_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef _DEV_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _FFLAGS_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef _FSBLKCNT_T_DECLARED		/* for statvfs() */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _GID_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _IN_ADDR_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _IN_PORT_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _ID_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _INO_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _KEY_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _LWPID_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _MODE_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _NLINK_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _OFF_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef _RLIM_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef _SIZE_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _SSIZE_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _SUSECONDS_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _TIME_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _TIMER_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef _UID_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef _USECONDS_T_DECLARED
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef _KERNEL
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !_KERNEL */
/* under construction !*/
#endif // hyzhang

/* !!! copy from \kame\kame\libpcap\lbl\gnuc.h*/
#ifndef __P
#if __STDC__
#define __P(protos) protos
#else
#define __P(protos) ()
#endif
#endif

/* inline foo */
#ifdef __GNUC__
#define inline __inline
#else
#define inline
#endif

#endif /* !_IPSEC_TYPES_H_ */
