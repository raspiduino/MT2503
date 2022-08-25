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
 * custom_config_account.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to configure data account.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__
#ifdef __TCPIP__

#include "custom_config_account.h"
#include "custom_data_account.h"

#include "kal_general_types.h"
#include "soc2tcpip_struct.h"
#include "if.h"

#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

extern void arp_input(int tcpip_sap_id, mbuf *m);
extern void arprequest(kal_uint8 profile_id, kal_uint32 target_ip, const kal_uint8 *target_mac);
extern kal_bool arpresolve(kal_uint8 profile_id, mbuf *m, kal_uint32 dest_addr,
    kal_uint8 *desten, int socket_id, u_char tos);

extern kal_int8 arplookup(kal_uint32 nexthop, kal_bool create, /*enum*/ arp_dir dir);
extern void send_arp(struct arpsnd *snd);
extern void get_arp_hw_addr(kal_int8 id, kal_uint8 *tcpip_hw_addr);
extern void pwr_saving_off(kal_uint8 s);
extern void pwr_saving_on(kal_uint8 s);
extern void arp_freehold(kal_int8 socket_id);

extern kal_int8 arp_rtrequest(/*enum*/ arpt_op req, kal_uint32 ip_addr,
                    /*enum*/ arp_dir dir, kal_bool perm);

////////////////nat
#ifdef __HOTSPOT_SUPPORT__
extern void init_tcpip_nat(void);
extern kal_bool nat_ip_packet_input(struct mbuf *m, kal_int8 tcpip_sap_id);
extern void nat_ip_packet_output(struct mbuf *m, kal_int8 tcpip_sap_id);
extern kal_uint32  nat_gprs_ip_addr;
extern kal_uint32   nat_local_gprs_addr;
extern kal_uint8   nat_out_context_id;
extern kal_int8   nat_out_profile_id;
extern kal_uint32  nat_wifi_ip_addr_netmask;
extern kal_uint32  nat_wifi_ip_addr;
extern kal_uint16  local_tcpip_port_used[];
extern kal_uint32  nat_send_data_flag;
extern kal_uint32  nat_send_data_wifi_flag;
extern kal_int8   nat_in_profile_id;
#endif

#endif



void tcpip_wifi_arp_input(cbm_bearer_enum bearer_id, mbuf *m)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    arp_input(bearer_id, m);
#else
    return;
#endif
}

void tcpip_wifi_arprequest(kal_uint8 profile_id, kal_uint32 target_ip, const kal_uint8 *target_mac)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    
        arprequest(profile_id, target_ip, target_mac);
#else
        return;
#endif
}

kal_bool tcpip_wifi_arpresolve(kal_uint8 profile_id, mbuf *m, kal_uint32 dest_addr,
    kal_uint8 *desten, int socket_id, u_char tos)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    arpresolve(profile_id, m, dest_addr,desten, socket_id, tos);
#else
    return 0;
#endif
}

kal_int8 tcpip_wifi_arplookup(kal_uint32 nexthop, kal_bool create, /*enum*/ arp_dir dir)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    return arplookup(nexthop, create, dir);
#else
    return 0;
#endif


}

void tcpip_wifi_get_arp_hw_addr(kal_int8 id, kal_uint8 *tcpip_hw_addr)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    get_arp_hw_addr(id, tcpip_hw_addr);
#else
    return;
#endif    
}

void tcpip_wifi_send_arp(struct arpsnd *snd)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    
        send_arp(snd);
#else
        return;
#endif    

}


void tcpip_wif_set_arp_conflict_mac(kal_int32 value)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    set_arp_conflict_mac(value);
#else
    return;
#endif    

}

void tcpip_wif_set_arp_last_conflict_time(kal_int32 value)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__

    set_arp_last_conflict_time(value);
#else
    return;
#endif   

}

void tcpip_wifi_pwr_saving_off(kal_uint8 s)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    
        pwr_saving_off(s);
#else
        return;
#endif   

}

void tcpip_wifi_pwr_saving_on(kal_uint8 s)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
        
            pwr_saving_on(s);
#else
            return;
#endif  

}

void tcpip_wifi_arp_freehold(kal_int8 socket_id)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
        
            arp_freehold(socket_id);
#else
            return;
#endif   

}

kal_int8 tcpip_wifi_arp_rtrequest(/*enum*/ arpt_op req, kal_uint32 ip_addr,
                    /*enum*/ arp_dir dir, kal_bool perm)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
            
                return arp_rtrequest(req, ip_addr, dir, perm);
#else
                return 0;
#endif   

}

////////////////nat

void tcpip_wifi_init_tcpip_nat(void)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__

    init_tcpip_nat();
#endif    
#else
    return;
#endif    
}

kal_bool tcpip_wifi_nat_ip_packet_input(struct mbuf *m, kal_int8 tcpip_sap_id)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_ip_packet_input(m, tcpip_sap_id);
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

void tcpip_wifi_nat_ip_packet_output(struct mbuf *m, kal_int8 tcpip_sap_id)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_ip_packet_output(m, tcpip_sap_id);
#else
    return;
#endif 
#else
    return;
#endif 

}


kal_uint32  tcpip_wifi_get_nat_gprs_ip_addr()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_gprs_ip_addr;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

kal_uint32*  tcpip_wifi_get_nat_gprs_ip_addr_p()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return &nat_gprs_ip_addr;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

void tcpip_wifi_set_nat_gprs_ip_addr(kal_uint32 nat_gprs_ip_addr_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_gprs_ip_addr = nat_gprs_ip_addr_t;
#endif    
#else
    return;
#endif 

}

void tcpip_wifi_set_nat_local_gprs_addr(kal_uint32 nat_local_gprs_addr_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_local_gprs_addr = nat_local_gprs_addr_t;
#else
    return;
#endif 
#else
    return;
#endif 

}


kal_uint32  tcpip_wifi_get_nat_out_context_id()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_out_context_id;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

void tcpip_wifi_set_nat_out_context_id(kal_uint32 nat_out_context_id_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_out_context_id = nat_out_context_id_t;
#else
    return;
#endif 
#else
    return;
#endif 

}

kal_int8  tcpip_wifi_get_nat_out_profile_id()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_out_profile_id;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

void tcpip_wifi_set_nat_out_profile_id(kal_uint32 nat_out_profile_id_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_out_profile_id = nat_out_profile_id_t;
#else
    return;
#endif 
#else
    return;
#endif 

}

kal_uint32  tcpip_wifi_get_nat_wifi_ip_addr_netmask()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_wifi_ip_addr_netmask;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

kal_uint32*  tcpip_wifi_get_nat_wifi_ip_addr_netmask_p()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return &nat_wifi_ip_addr_netmask;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

void tcpip_wifi_set_nat_wifi_ip_addr_netmask(kal_uint32 nat_wifi_ip_addr_netmask_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_wifi_ip_addr_netmask = nat_wifi_ip_addr_netmask_t;
#endif    
#else
    return;
#endif 

}


kal_uint32  tcpip_wifi_get_nat_wifi_ip_addr()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_wifi_ip_addr;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}

kal_uint32*  tcpip_wifi_get_nat_wifi_ip_addr_p()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return &nat_wifi_ip_addr;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}



void tcpip_wifi_set_nat_wifi_ip_addr(kal_uint32 nat_wifi_ip_addr_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_wifi_ip_addr = nat_wifi_ip_addr_t;
#endif    
#else
    return;
#endif 

}


kal_uint16*  tcpip_wifi_get_local_tcpip_port_used()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return local_tcpip_port_used;
#endif    
#else
    return 0;
#endif 

}

void tcpip_wifi_set_nat_send_data_flag(kal_uint32 nat_send_data_flag_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_send_data_flag = nat_send_data_flag_t;
#endif    
#else
    return;
#endif 

}

void tcpip_wifi_set_nat_send_data_wifi_flag(kal_uint32 nat_send_data_wifi_flag_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_send_data_wifi_flag = nat_send_data_wifi_flag_t;
#endif    
#else
    return;
#endif 

}

kal_int8  tcpip_wifi_get_nat_in_profile_id()
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    return nat_in_profile_id;
#else
    return 0;
#endif 
#else
    return 0;
#endif 

}


void tcpip_wifi_set_nat_in_profile_id(kal_int8 nat_in_profile_id_t)
{
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
#ifdef __HOTSPOT_SUPPORT__
    nat_in_profile_id = nat_in_profile_id_t;
#endif    
#else
    return;
#endif 

}


#endif /* __TCPIP__ */ 
#endif/*#__MTK_TARGET__*/


