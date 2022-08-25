
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
 * mbuf.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of mbuf.c
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
#ifdef __MTK_TARGET__

#ifndef _MBUF_H_
#define _MBUF_H_

//#include "tcpip_config.h"
#include "app_ltlcom.h"
#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
#endif
/* auto add by kw_check begin*/
#include "soc2tcpip_struct.h"
/* auto add by kw_check end */
/* mbuf pkthdr flags, also in m_flags */
#define M_SOC_ID    0x00FF  /* MAX_SOCKET_NUM * 2 must be smaller than 255 */
#define M_TPDU      0x0100
#define M_FRAG      0x0200
#define M_SMALL     0x0800  /* buffer size use MTU/2 */
#define M_SPDU_HS   0x0400
#define M_SPDU_DL   0x1000

#define NOT_SPDU -1

#define POOL_FRAG_SIZE 750
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

extern mbuf *pbuf_to_mbuf_udp_ul(peer_buff_struct *peer_buff_ptr, int socket_id);
extern mbuf *pbuf_to_mbuf_ul(peer_buff_struct *peer_buff_ptr, int socket_id);
extern mbuf *pbuf_to_mbuf_dl(peer_buff_struct *peer_buff_ptr);

extern void m_free_dl(int tcpip_sap_id, mbuf *m);   /* free buffer for down link */
extern void m_free_ul(int tcpip_sap_id, mbuf *m, int socket_id);    /* free buffer for up link */
extern void m_adj(struct mbuf *mp, int req_len);

#ifdef __IPSEC__

#define MBUF_HDR_SIZE(m)    ((m)->sockaddr.addr_len)
#define MBUF_TAIL_SIZE(m)   ((m)->sockaddr.port)

#define MBUF_HDR_SIZE_DEC(m, len)    ((m)->sockaddr.addr_len -= len)
#define MBUF_TAIL_SIZE_DEC(m, len)   ((m)->sockaddr.port -= len)


/*
 * Redefinition of mbuf m_flags
 */
#define	M_AUTHIPHDR	0x1000
#define	M_DECRYPTED	0x2000
#define	M_AUTHIPDGM	0x8000


extern void m_copydata(const struct mbuf *m, int off, int len, caddr_t cp);
extern void m_copyback(struct mbuf *m0, int off, int len, const char *cp);
extern void m_cat(struct mbuf *m, struct mbuf *n);
extern int mbuf_get_len(struct mbuf *mbuf);

/* Macro define */
#define bcopy(src, dst, len)    kal_mem_cpy(dst, src, len)
#define ovbcopy(src, dst, len)  ipsec_mem_mov(dst, src, len)
#define bzero(dst, len)         kal_mem_set(dst, 0, len)
#define bcmp(src, dst, len)     kal_mem_cmp(dst, src, len)

extern void *ipsec_malloc(unsigned int size);
extern void ipsec_free(void *p);
extern void *ipsec_mem_mov(void *dst_void, const void *src_void, int length);

#endif  /* __IPSEC__ */

#endif /* !_MBUF_H_ */

#endif /* __MTK_TARGET__ */

