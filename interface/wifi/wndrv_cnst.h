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
 *  wndrv_cnst.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  WLAN network driver related constant and enum definitions
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _WNDRV_CNST_H
#define _WNDRV_CNST_H

/* --- Temp ---------------------------------------------------------------- */
#define WNDRV_DEBUG_TRACE_BUF       (160)


/* --- IE length definition -------------------------------------------------*/
#define WNDRV_MAX_WPA_IE_LEN        (40)
#define WNDRV_MAX_RSN_IE_LEN        (40)
#define WNDRV_MAX_WAPI_IE_LEN       (40)
#define WNDRV_MAX_ASSOC_IE_LEN      (40)

#define ELEM_HDR_LEN          2
#define WPS_ATTR_HDR_LEN      4
#define VENDOR_OUI_LEN         4

#define WPS_VER_LEN            1
#define WPS_REQ_TYPE_LEN       1
#define WPS_UUID_LEN          16
#define WPS_CFG_METHOD_LEN  2
#define WPS_PRIDEV_TYPE_LEN    8
#define WPS_RFBANDS_LEN        1
#define WPS_ASSOC_STAT_LEN     2
#define WPS_CFG_ERR_LEN     2
#define WPS_DEV_PSWD_ID_LEN    2
#define WPS_AP_SETUP_LOCKED_LEN  1
#define WPS_SETUP_STATE_LEN     1   
#define WPS_SELECT_REG_LEN  1
#define WPS_DEV_PWSD_ID_LEN 2
#define WPS_SELECT_REG_CFG_METHOD_LEN 2
#define WPS_RESP_TYPE_LEN   1
#define WPS_MANUFACTURE_LEN 64
#define WPS_MODEL_NAME_LEN 32
#define WPS_MODEL_NUM_LEN  32
#define WPS_SERIAL_NUM_LEN 32
#define WPS_DEV_NAME_LEN 32

#define WPS_WFA_ATTR_VID_LEN 3
#define WPS_WFA_ATTR_SUB_HDR_LEN 2  /*1 byte ID, 1 byte length*/

#define WPS_WFA_ATTR_SUB_VER_LEN 1
#define WPS_WFA_ATTR_SUB_MACS_LEN 30
#define WPS_WFA_ATTR_SUB_KEY_SHARE_LEN 1
#define WPS_WFA_ATTR_SUB_REQ_ENROLL_LEN    1
#define WPS_WFA_ATTR_SUB_SET_DELAY_TIME_LEN 1

#define ATTR_WFA_VENDOR_ID   0x00372A
#define ATTR_WFA_SUB_VER_ID  0x0
#define ATTR_WFA_SUB_MACS_ID 0x1
#define ATTR_WFA_SUB_KEY_SHARE_ID 0X2
#define ATTR_WFA_SUB_REQ_ENROLL_ID 0x3
#define ATTR_WFA_SUB_SET_DEALY_ID 0x4


#define WPS_PROBE_REQ_ATTRS_LEN    (WPS_ATTR_HDR_LEN + WPS_VER_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_REQ_TYPE_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_UUID_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_CFG_METHOD_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_PRIDEV_TYPE_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_RFBANDS_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_ASSOC_STAT_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_CFG_ERR_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_DEV_PWSD_ID_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_MANUFACTURE_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_MODEL_NAME_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_MODEL_NUM_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_DEV_NAME_LEN + \
                                    WPS_ATTR_HDR_LEN + WPS_WFA_ATTR_VID_LEN + \
                                    WPS_WFA_ATTR_SUB_HDR_LEN + WPS_WFA_ATTR_SUB_VER_LEN)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*reduce the usage of control buffer, avoid fatal error in get_control_buff*/
#define WPS_PROBE_RESP_ATTRS_LEN (WPS_ATTR_HDR_LEN + WPS_SELECT_REG_LEN + \
                                  WPS_ATTR_HDR_LEN + WPS_DEV_PSWD_ID_LEN + \
                                  WPS_ATTR_HDR_LEN + WPS_UUID_LEN)

#define WPS_ASSOC_REQ_ATTRS_LEN (WPS_ATTR_HDR_LEN + WPS_VER_LEN + \
                                 WPS_ATTR_HDR_LEN + WPS_REQ_TYPE_LEN + \
                                 WPS_ATTR_HDR_LEN + WPS_WFA_ATTR_VID_LEN + \
                                 WPS_WFA_ATTR_SUB_HDR_LEN + WPS_WFA_ATTR_SUB_VER_LEN)
                                  
#define WPS_ASSOC_RESP_ATTRS_LEN (WPS_ATTR_HDR_LEN + WPS_VER_LEN + \
                                  WPS_ATTR_HDR_LEN + WPS_RESP_TYPE_LEN + \
                                  WPS_ATTR_HDR_LEN + WPS_WFA_ATTR_VID_LEN + \
                                  WPS_WFA_ATTR_SUB_HDR_LEN + WPS_WFA_ATTR_SUB_VER_LEN)


#define ELEM_WPS_PROBE_REQ_IE_LEN  (ELEM_HDR_LEN + VENDOR_OUI_LEN + \
                                    WPS_PROBE_REQ_ATTRS_LEN)


                                    
#define ELEM_WPS_ASSOC_REQ_IE_LEN (ELEM_HDR_LEN + VENDOR_OUI_LEN + \
                                    WPS_ASSOC_REQ_ATTRS_LEN)

#define ELEM_WPS_PROBE_RESP_IE_LEN (ELEM_HDR_LEN + VENDOR_OUI_LEN + \
                                    WPS_PROBE_RESP_ATTRS_LEN) 
                                    
#define ELEM_WPS_ASSOC_RESP_IE_LEN (ELEM_HDR_LEN + VENDOR_OUI_LEN + \
                                    WPS_ASSOC_RESP_ATTRS_LEN)


/*---- statistics indication interval ---------------------------------------*/
#define WNDRV_STATISTICS_INTERVAL   (5000)        /* in milliseconds */

/* --- TX power table Size --------------------------------------------------*/
#define WNDRV_TXPWR_2400M_TABLE_SIZE   (168)
#define WNDRV_TXPWR_5000M_TABLE_SIZE   (272)
#define WNDRV_TXPWR_TABLE_SIZE         (WNDRV_TXPWR_2400M_TABLE_SIZE + WNDRV_TXPWR_5000M_TABLE_SIZE)
#define WNDRV_TXPWR_2400M_TABLE_OFFSET (0x18)
#define WNDRV_TXPWR_5000M_TABLE_OFFSET (0xC0)


/* --- BB & RF Chip Model -------------------------------------------------- */
#define WNDRV_BB_MT5911   (0x00000001)

//20081106 add by saker for define MT5921
#define WNDRV_BB_MT5921   (0x00000002)

//20110509 add by Nelson for define MT5931
#define WNDRV_BB_MT5931   (0x00000003)

#define WNDRV_RF_AL2236   (0x00000001)
#define WNDRV_RF_MAX2827  (0x00000002)
//20081106 add by saker 
#define WNDRV_RF_MT5921   (0x00000003)

//20110509 add by Nelson 
#define WNDRV_RF_MT5931   (0x00000004)

/* --- Free header space in peer buffer ------------------------------------ */
/* src mac addr + dest mac addr + proto type */
#define WNDRV_ETHERNET_MAC_SPACE      (14)

#if defined(__HOTSPOT_SUPPORT__)
#define WNDRV_WLAN_MAC_HEADER_LEN     (24)
#endif /*__HOTSPOT_SUPPORT__*/
/* Reserve more 16 bytes is for linking list node such that the upper layer can
   transmit packets unlimitedly. 
   Be sure sizeof(wndrv_packet_struct) is less than 16 bytes. */

#if defined (WIFI_BB_MT5911)
#define WNDRV_PKT_DESCRIPTOR_SIZE     (20) //(sizeof (struct wndrv_pkt_descriptor_struct))
#elif defined (WIFI_BB_MT5921) || defined (MT5931)
#define WNDRV_PKT_DESCRIPTOR_SIZE     (52) //(sizeof (struct wndrv_pkt_descriptor_struct))
#endif
#define PEER_BUF_HDR_SIZE    (8)
#define TX_HDR_SIZE_         (16)
#define WNDRV_RX_PAD   ( ((PEER_BUF_HDR_SIZE + WNDRV_PKT_DESCRIPTOR_SIZE + MBUF_LENGTH + 31)& ~31u) - (PEER_BUF_HDR_SIZE + WNDRV_PKT_DESCRIPTOR_SIZE + MBUF_LENGTH) )
#define WNDRV_AP_RX_PAD   ( ((PEER_BUF_HDR_SIZE + WNDRV_WLAN_MAC_HEADER_LEN + WNDRV_PKT_DESCRIPTOR_SIZE + MBUF_LENGTH + 31)& ~31u) - (PEER_BUF_HDR_SIZE + WNDRV_WLAN_MAC_HEADER_LEN + WNDRV_PKT_DESCRIPTOR_SIZE + MBUF_LENGTH) )
#if defined(__WIFI_SUPPORT__)
#if defined(__HOTSPOT_SUPPORT__)
#if defined(MT5931)
#define WNDRV_FREE_HEADER_SPACE       (WNDRV_PKT_DESCRIPTOR_SIZE + TX_HDR_SIZE_ + WNDRV_WLAN_MAC_HEADER_LEN + (((WNDRV_ETHERNET_MAC_SPACE + 3) >> 2) << 2))
#else
#define WNDRV_FREE_HEADER_SPACE       (WNDRV_PKT_DESCRIPTOR_SIZE + WNDRV_WLAN_MAC_HEADER_LEN + (((WNDRV_ETHERNET_MAC_SPACE + 3) >> 2) << 2))
#endif
#else
#if defined(MT5931)
#define WNDRV_FREE_HEADER_SPACE       (WNDRV_PKT_DESCRIPTOR_SIZE + TX_HDR_SIZE_ + (((WNDRV_ETHERNET_MAC_SPACE + 3) >> 2) << 2))
#else
#define WNDRV_FREE_HEADER_SPACE       (WNDRV_PKT_DESCRIPTOR_SIZE + (((WNDRV_ETHERNET_MAC_SPACE + 3) >> 2) << 2))
#endif
#endif /*__HOTSPOT_SUPPORT__*/
#endif
#define WNDRV_BUFFER_HDLR_CHECK_MARK  (0xaa)

/* --- Different Packet Size Category------------------------------------------- */
#define WNDRV_PACKET_SIZE_COUNT   (6)

/* --- Different Packet Type Category------------------------------------------ */
#define WNDRV_PACKET_TYPE_COUNT   (3)

/* --- Define QoS Queue Size --------------------------------------------------- */
#define  WNDRV_QOS_QUEUE_SIZE      (4)
#define  WNDRV_QUEUE_AC_BK         (0)
#define  WNDRV_QUEUE_AC_BE         (1)
#define  WNDRV_QUEUE_AC_VI         (2)
#define  WNDRV_QUEUE_AC_VO         (3)

/* --- Internal Queue Size and Different Queue Index---------------------------------------- */
#define WNDRV_INT_QUEUE_TYPE          (4)
#define WNDRV_INT_QUEUE_TX_INDEX      (0)
#define WNDRV_INT_QUEUE_RX_INDEX      (1)
#define WNDRV_INT_QUEUE_TIMER_INDEX   (2)
#define WNDRV_INT_QUEUE_FREE_INDEX    (3)
#define WNDRV_FREE_INT_QUEUE_SIZE     (50)



/* --- Different All Rate Count------------------------------------------ */
#define WNDRV_RATE_COUNT           (12)

/* --- SSID Length --------------------------------------------------------- */
#define WNDRV_SSID_MAX_LEN          (32)

/* --- PASSWORD Length --------------------------------------------------------- */
#define WNDRV_PASSWORD_MAX_LEN		(64)

/* --- WEP KEY Length ------------------------------------------------------ */
#define WNDRV_WEP_MAX_LEN           (16)


/* --- TKIP or AES KEY Length ------------------------------------------------------ */
#define WNDRV_KEY_MAX_LEN           (32)


/* --- Max number of PMKID cache ------------------------------------------- */
#define WNDRV_PMKID_CACHE_NUM       (16)  


/* --- MAC Address Length -------------------------------------------------- */
#define WNDRV_MAC_ADDRESS_LEN       (6)


/* --- Number of Scan Results ---------------------------------------------- */
//Temp modified for memory shortage
#define WNDRV_SCAN_RESULTS_NUM    (1)  /* (8) */  
//change for WiFi UE enhancement 16->30
#if defined(__IOT__)
	#define WNDRV_MAX_SCAN_RESULTS_NUM	(16)
#else
	#if defined (__WIFI_SLIM__)
	#define WNDRV_MAX_SCAN_RESULTS_NUM  (8)
	#else
	#define WNDRV_MAX_SCAN_RESULTS_NUM  (30)//(16)
	#endif /* __WIFI_SLIM__ */
#endif

/* --- MAX Number of Desired SSID List ---------------------------------------------- */
#define WNDRV_MAX_SSID_LIST_NUM (7) 

/* --- Number of BSSID List ---------------------------------------------- */
#define WNDRV_BSSID_MAX_NUM (32) // Kinki change for the blacklist

/* --- The Flags of Authentication Indications ----------------------------- */
#define WNDRV_AUTH_REQUEST_REAUTH         (0x01)
#define WNDRV_AUTH_REQUEST_KEY_UPDATE     (0x02)
#define WNDRV_AUTH_REQUEST_PAIRWISE_ERROR (0x06)
#define WNDRV_AUTH_REQUEST_GROUP_ERROR    (0x0E)


/* --- Data Rates ---------------------------------------------------------- */
/* Supported rates in units of 500 kbit/s */
#define WNDRV_RATE_1M       (0x02)   /* 1M   */
#define WNDRV_RATE_2M       (0x04)   /* 2M   */
#define WNDRV_RATE_5_5M     (0x0B)   /* 5.5M */
#define WNDRV_RATE_11M      (0x16)   /* 11M  */
#define WNDRV_RATE_6M       (0x0C)   /* 6M   */
#define WNDRV_RATE_9M       (0x12)   /* 9M   */
#define WNDRV_RATE_12M      (0x18)   /* 12M  */
#define WNDRV_RATE_18M      (0x24)   /* 18M  */
#define WNDRV_RATE_24M      (0x30)   /* 24M  */
#define WNDRV_RATE_36M      (0x48)   /* 36M  */
#define WNDRV_RATE_48M      (0x60)   /* 48M  */
#define WNDRV_RATE_54M      (0x6C)   /* 54M  */


/* --- RSSI Record ---------------------------------------------------------- */
//20081009 add by saker for record RSSI
/* The number of RSSI and link quality records used to calculate their average
   value */
#define WNDRV_MAX_NUM_RSSI_LQ_RECORDS (20)


/* --- Country Code --------------------------------------------------------- */
/* ISO/IEC 3166-1 two-character country codes */
#define WNDRV_COUNTRY_CODE_US  (((kal_uint16) 'U' << 8) | (kal_uint16) 'S')  /* United States */
#define WNDRV_COUNTRY_CODE_CA  (((kal_uint16) 'C' << 8) | (kal_uint16) 'A')  /* Canada */
#define WNDRV_COUNTRY_CODE_EU  (((kal_uint16) 'E' << 8) | (kal_uint16) 'U')  /* ETSI (Europe) */
#define WNDRV_COUNTRY_CODE_ES  (((kal_uint16) 'E' << 8) | (kal_uint16) 'S')  /* Spain */
#define WNDRV_COUNTRY_CODE_FR  (((kal_uint16) 'F' << 8) | (kal_uint16) 'R')  /* France */
#define WNDRV_COUNTRY_CODE_JP  (((kal_uint16) 'J' << 8) | (kal_uint16) 'P')  /* Japan */
                         
#define WNDRV_COUNTRY_CODE_AT  (((kal_uint16) 'A' << 8) | (kal_uint16) 'T')  /* Austria */
#define WNDRV_COUNTRY_CODE_BE  (((kal_uint16) 'B' << 8) | (kal_uint16) 'E')  /* Belgium */
#define WNDRV_COUNTRY_CODE_DK  (((kal_uint16) 'D' << 8) | (kal_uint16) 'K')  /* Denmark */
#define WNDRV_COUNTRY_CODE_FI  (((kal_uint16) 'F' << 8) | (kal_uint16) 'I')  /* Finland */
#define WNDRV_COUNTRY_CODE_DE  (((kal_uint16) 'D' << 8) | (kal_uint16) 'E')  /* Germany */
#define WNDRV_COUNTRY_CODE_GR  (((kal_uint16) 'G' << 8) | (kal_uint16) 'R')  /* Greece */
#define WNDRV_COUNTRY_CODE_IS  (((kal_uint16) 'I' << 8) | (kal_uint16) 'S')  /* Iceland */
#define WNDRV_COUNTRY_CODE_IE  (((kal_uint16) 'I' << 8) | (kal_uint16) 'E')  /* Ireland */
#define WNDRV_COUNTRY_CODE_IT  (((kal_uint16) 'I' << 8) | (kal_uint16) 'T')  /* Italy */
#define WNDRV_COUNTRY_CODE_LI  (((kal_uint16) 'L' << 8) | (kal_uint16) 'I')  /* Liechtenstein */
#define WNDRV_COUNTRY_CODE_LU  (((kal_uint16) 'L' << 8) | (kal_uint16) 'U')  /* Luxembourg */
#define WNDRV_COUNTRY_CODE_NL  (((kal_uint16) 'N' << 8) | (kal_uint16) 'L')  /* Netherlands */
#define WNDRV_COUNTRY_CODE_NO  (((kal_uint16) 'N' << 8) | (kal_uint16) 'O')  /* Norway */
#define WNDRV_COUNTRY_CODE_PT  (((kal_uint16) 'P' << 8) | (kal_uint16) 'T')  /* Portugal */
#define WNDRV_COUNTRY_CODE_SE  (((kal_uint16) 'S' << 8) | (kal_uint16) 'E')  /* Sweden */
#define WNDRV_COUNTRY_CODE_CH  (((kal_uint16) 'C' << 8) | (kal_uint16) 'H')  /* Switzerland */
#define WNDRV_COUNTRY_CODE_GB  (((kal_uint16) 'G' << 8) | (kal_uint16) 'B')  /* United Kingdom */
                         
#define WNDRV_COUNTRY_CODE_AU  (((kal_uint16) 'A' << 8) | (kal_uint16) 'U')  /* Australia */
#define WNDRV_COUNTRY_CODE_CN  (((kal_uint16) 'C' << 8) | (kal_uint16) 'N')  /* China */
#define WNDRV_COUNTRY_CODE_IL  (((kal_uint16) 'I' << 8) | (kal_uint16) 'L')  /* Israel */
#define WNDRV_COUNTRY_CODE_JO  (((kal_uint16) 'J' << 8) | (kal_uint16) 'O')  /* Jordan */
#define WNDRV_COUNTRY_CODE_KR  (((kal_uint16) 'K' << 8) | (kal_uint16) 'R')  /* Korea */
#define WNDRV_COUNTRY_CODE_SG  (((kal_uint16) 'S' << 8) | (kal_uint16) 'G')  /* Singapore */
#define WNDRV_COUNTRY_CODE_TW  (((kal_uint16) 'T' << 8) | (kal_uint16) 'W')  /* Taiwan */
#define WNDRV_COUNTRY_CODE_TH  (((kal_uint16) 'T' << 8) | (kal_uint16) 'H')  /* Thailand */


/***** DMA ******/
// 20081020 saker modify for ARM9 DCACHE DEV
#define CPU_CACHE_LINE_SIZE 32
#define CPU_CACHE_LINE_SIZE_MASK 0x0000001F
#define SWITCH_TO_NONCACHEABLE 0
#define SWITCH_TO_CACHEABLE 1
#if defined(MT6276_S00) || defined(MT6253E)
	#define DMA_THRESHOLD 2048
#else
	#if defined(MT5931)
		#if defined (__WIFI_EHPI_16BIT__) && defined (MT6255)
			#define DMA_THRESHOLD 128
		#else
			#define DMA_THRESHOLD 128
		#endif
	#else
		#define DMA_THRESHOLD 128
	#endif
#endif

#endif /* _WNDRV_CNST_H */
