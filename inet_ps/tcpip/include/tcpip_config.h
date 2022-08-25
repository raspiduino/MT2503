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
 * tcpip_config.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Global config file for TCPIP.
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
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TCPIP_CONFIG_H_
#define _TCPIP_CONFIG_H_

#ifdef __MTK_TARGET__

/* Define to 1 to support selective ACK */
#define TCPSACK_SUPPORT 1
/* #undef TCPSACK_SUPPORT */

/* Define to 1 to enable ARP support */
#ifdef __WIFI_SUPPORT__
#define _ARP_ 1
#else /* !__WIFI_SUPPORT__ */
/* #undef _ARP_ */
#endif /* !__WIFI_SUPPORT__ */

/* Define to 1 to log ARP history */



/* Define to 1 to accept inject message */



/* Define to 1 to enable ARP unit test code */
/* #undef ARP_UT */

/* Define to 1 to log history of TCP RTO */
/* #undef TCP_LOG_RTO */

/* Define to 1 to log history of TCP advertised window */
/* #undef TCP_LOG_SND_WND */

/* Define to 1 to enable Path MTU discovery */
#define PMTU_DISCOVERY 1

#define TCPIP_LOG_TPDU 1

//#define FLC_VERSION 0
#ifdef __FLC2__ /* FLC2 */
#define FLC_VERSION 2
#else /* FLC1 */
#define FLC_VERSION 1
#endif /* FLC1 */
//#define FLC_VERSION 2

/* Define to 1 to enable raw ip */
#ifdef __TCPIP_RAW_SOCKET_SUPPORT__
#define RIP_SUPPORT
#endif

/* Define to 1 to enable IPSEC */
#define IPSEC_ESP       1
#define INET            1
#define _KERNEL         1
//#define IPSEC_DEBUG_TRACE   1

/* Added by Huiyong */
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#define TCPIP_CUST_SOC_NUM  0            /* specail socket */
#define TCPIP_CUST_BUF_SIZE 0
#define TCPIP_SIGNAL_BUF    (6 * 1024)

#endif /* __MTK_3G_MRAT_ARCH__ */

#endif /* __MTK_TARGET__ */

#endif /* !_TCPIP_CONFIG_H_ */


