/*
 *  ntp_types.h - defines how int32 and u_int32 are treated.
 *  For 64 bit systems like the DEC Alpha, they have to be defined
 *  as int and u_int.
 *  For 32 bit systems, define them as long and u_long
 */
#ifndef NTP_TYPES_H
#define NTP_TYPES_H

/*
 * Basic system type definitions, taken from the BSD file sys/types.h.
 */
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

/*
 * The new type to be used in all
 * instances which refer to sockets.
 */
typedef int SOCKET;

#define SIZEOF_INT   4
#define SIZEOF_CHARP 4
#define SIZEOF_LONG  4
#define SIZEOF_SHORT 2

/*
 * used to quiet compiler warnings
 */
#ifndef UNUSED_ARG
#define UNUSED_ARG(arg) ((void)(arg))
#endif 

/*
 * COUNTOF(array) - size of array in elements
 */
#define COUNTOF(arr) (sizeof(arr) / sizeof((arr)[0]))


#if (SIZEOF_INT == 4)
# ifndef int32
#  define int32 int
# endif
# ifndef u_int32
#  define u_int32 unsigned int
# endif
#else /* (SIZEOF_INT == 4) */ /* not sizeof(int) == 4 */
# if (SIZEOF_LONG == 4)
#  ifndef int32
#   define int32 long
#  endif
#  ifndef u_int32
#   define u_int32 unsigned long
#  endif
# else /* not sizeof(long) == 4 */
#  include "Bletch: what's 32 bits on this machine?"
# endif /* not sizeof(long) == 4 */
#endif /* (SIZEOF_INT == 4) */ /* not sizeof(int) == 4 */

typedef u_char ntp_u_int8_t;
typedef u_short ntp_u_int16_t;
typedef u_int32 ntp_u_int32_t;

typedef struct ntp_uint64_t
{
    u_int32 val[2];
} ntp_uint64_t;

typedef unsigned short associd_t;   /* association ID */
typedef u_int32 keyid_t;            /* cryptographic key ID */
typedef u_int32 tstamp_t;           /* NTP seconds timestamp */


#endif /* NTP_TYPES_H */ 

