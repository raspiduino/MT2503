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
*  ntpd_hld.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   NTP Network Event Handler
*
* Author:
* -------
*  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Task Management */
#include "syscomp_config.h"
#include "task_config.h"

#include "app2soc_struct.h"     /* interface with Applications */
#include "soc_api.h"

#include "cbm_api.h"
#include "app2cbm_struct.h"

#include "app_buff_alloc.h"     /* buffer management API */

//#include "mmi_rp_srv_ntp_def.h"
//#include "mmi_frm_events_gprot.h"
//#include "mmi_frm_timer_gprot.h"


#include "ntpd_comm.h"
#include "recvbuff.h"
#include "ntpd_mem.h"

//#include "MMI_trc_Int.h"
//#include "mmi_conn_app_trc.h"
#include "ntpd_trc.h"
#include "custom_ntp_config.h"
#include "stack_msgs.h"
//#define __OPEN_SOURCE__

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
 typedef void (*ntpd_timer_callback_f)(void*);
static void ntpd_start_timer(kal_uint32 delay, ntpd_timer_callback_f callback);
static U8 ntpd_hdlr_soc_notify_ind(void *msg);
static U8 ntpd_hdlr_cbm_bearer_info_ind(void *msg);
static U8 ntpd_hdlr_get_host_by_name_ind(void *msg);
static kal_int8 ntpd_gethostbyname(
            ntpd_context_struct *cntx_p,
            kal_uint16 req_id,
            kal_uint8 *server_name,
            sockaddr_struct *saddr);

static void ntp_transmit_packet(struct server *server);

typedef void (*PsFuncPtr) (void *);

extern void ntpd_clock_filter(struct server * peer, s_fp delay, l_fp * offset,  u_fp dispersion);
extern void ntpd_clock_select(l_fp * offset);

/* Global Varialbe */
ntpd_context_struct ntpd_context;
ntpd_context_struct *ntpd_cntx_p = &ntpd_context;
static event_scheduler * ntpd_timer_id;


/*****************************************************************************
 * FUNCTION
 *  ntpd_network_init
 * DESCRIPTION
 *  this function is used to register protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_network_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_NETWORK_INIT);
	
    //mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, ntpd_hdlr_soc_notify_ind, KAL_TRUE);
    //mmi_frm_set_protocol_event_handler(MSG_ID_APP_CBM_BEARER_INFO_IND, ntpd_hdlr_cbm_bearer_info_ind, KAL_FALSE);
    //mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, ntpd_hdlr_get_host_by_name_ind, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_network_deinit
 * DESCRIPTION
 *  this function is used to register protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void ntpd_network_deinit(void)
{
	//mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, ntpd_hdlr_soc_notify_ind);
	//mmi_frm_clear_protocol_event_handler(MSG_ID_APP_CBM_BEARER_INFO_IND, ntpd_hdlr_cbm_bearer_info_ind);
	//mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, ntpd_hdlr_get_host_by_name_ind);
}

/*****************************************************************************
 * FUNCTION
 *  ntpd_notify_app
 * DESCRIPTION
 *  this function notifies the application.
 * PARAMETERS
 *  error       [IN]        
 *  ts          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_notify_app(kal_int32 error, l_fp *ts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double dtemp;
    kal_int64 offset = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_NOTIFY_APP);

    if (ts)
    {
        LFPTOD(ts, dtemp);

        offset = (kal_int64) (dtemp * 1e3); /* micro second. */
    }

    for (i = 0; i < ntpd_cntx_p->cb_cnt; i++)
    {
        (ntpd_cntx_p->sync_cb[i]) (error, offset, ntpd_cntx_p->usr_data[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_add_server
 * DESCRIPTION
 *  Add the server into the list.
 * PARAMETERS
 *  serv        [IN]        The server address.
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_add_server(sockaddr_struct *serv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sockaddr_struct *dest;
    struct server *server;
    int i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_ADD_SERVER);

    server = (struct server*)ntpd_malloc(sizeof(*server));
    memset(server, 0, sizeof(*server));
	for(i=0; i<NTP_SHIFT; i++)
	{
	    server->filter_error[i] = PEER_MAXDISP;
	}
    dest = &server->srcadr;
    dest->addr_len = serv->addr_len;

    memcpy(dest->addr, serv->addr, dest->addr_len);
    dest->port = serv->port;
    dest->sock_type = SOC_SOCK_DGRAM;

    server->event_time = ++ntpd_cntx_p->sys_numservers;

    if (ntpd_cntx_p->sys_servers == NULL)
    {
        ntpd_cntx_p->sys_servers = server;
    }
    else
    {
        struct server *sp;

        for (sp = ntpd_cntx_p->sys_servers; sp->next_server != NULL; sp = sp->next_server);

        sp->next_server = server;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_server_send
 * DESCRIPTION
 *  Send packet to the servers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_server_send(void)
{
    struct server *server = ntpd_cntx_p->sys_servers;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ntpd_cntx_p->current_time++;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; server != NULL; server = server->next_server)
    {
        if (server->event_time != 0 && server->event_time <= ntpd_cntx_p->current_time)
        {
            NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SEND);

            ntp_transmit_packet(server);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  clock_adjust
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static int clock_adjust(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	l_fp offset;
	int dostep = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ntpd_clock_select(&offset);
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
#endif /* 0 */ 

    if (dostep)
    {
        /* //?l_step_systime(&server->offset); */
    }
    else
    {
        /* //?l_adj_systime(&server->offset); */
    }

    ntpd_notify_app(ntpd_cntx_p->error, &offset);

    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_find_server
 * DESCRIPTION
 *  Find a server in the list according to its address
 * PARAMETERS
 *  addr        [IN]     the server address.
 * RETURNS
 *  
 *****************************************************************************/
static struct server *ntpd_find_server(sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct server *server;
    struct server *mc_server;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_FIND_SERVER);

    mc_server = NULL;

    if (addr->port != NTP_PORT)
        return 0;

    for (server = ntpd_cntx_p->sys_servers; server != NULL; server = server->next_server)
    {
        if (memcmp(addr->addr, server->srcadr.addr, addr->addr_len) == 0)
            return server;
        /*
         * if (IS_MCAST(&server->srcadr))
         * mc_server = server;
         */
    }

    if (mc_server != NULL)
    {

        struct server *sp;

        if (mc_server->event_time != 0)
        {
            mc_server->event_time = 0;
            ntpd_cntx_p->done_cnt++;
        }

        server = ntpd_malloc(sizeof(*server));
        memset(server, 0, sizeof(*server));

        server->srcadr = *addr;

        server->event_time = ++ntpd_cntx_p->sys_numservers;

        for (sp = ntpd_cntx_p->sys_servers; sp->next_server != NULL; sp = sp->next_server);
        sp->next_server = server;
        ntp_transmit_packet(server);
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_recv_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rbufp       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_recv_proc(struct recvbuf *rbufp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register struct pkt *rpkt;
    register struct server *server;
    register s_fp di;
    l_fp t10, t23, tmp;
    l_fp org;
    l_fp rec;
    l_fp ci;
    int has_mac, auth_ret;
    int is_authentic;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_NOTIFY_APP);

    /* Check if the packet is for us. */     
    if (rbufp->recv_length == LEN_PKT_NOMAC)
        has_mac = 0;
    else if (rbufp->recv_length >= LEN_PKT_NOMAC)
        has_mac = 1;
    else
    {
        return;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 1);

    rpkt = &(rbufp->recv_pkt);
    if (PKT_VERSION(rpkt->li_vn_mode) < NTP_OLDVERSION || PKT_VERSION(rpkt->li_vn_mode) > NTP_VERSION)
    {
        return;
    }

    if ((PKT_MODE(rpkt->li_vn_mode) != MODE_SERVER
         && PKT_MODE(rpkt->li_vn_mode) != MODE_PASSIVE) || rpkt->stratum >= STRATUM_UNSPEC)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 3);
        return;
    }

    /*
     * So far, so good.  See if this is from a server we know.
     */
    server = ntpd_find_server(&(rbufp->recv_srcadr));
    if (server == NULL)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 5);
        return;
    }
    
    server->reach |= 1;

    /*
     * Decode the org timestamp and make sure we're getting a response
     * to our last request.
     */
    NTOHL_FP(&rpkt->org, &org);
    if (!L_ISEQU(&org, &server->xmt))
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 7);
        return;
    }

    /*
     * Check out the authenticity if we're doing that.
     */
    if (!ntpd_cntx_p->auth)
        is_authentic = 1;
    else
    {
        is_authentic = 0;
        auth_ret = authdecrypt(
                    ntpd_cntx_p->sys_authkey,
                    (u_int32*) rpkt,
                    LEN_PKT_NOMAC,
                    (int)(rbufp->recv_length - LEN_PKT_NOMAC));

        if (has_mac && auth_ret && soc_ntohl(rpkt->exten[0]) == ntpd_cntx_p->sys_authkey)
            is_authentic = 1;
    }

    server->trust <<= 1;
    if (!is_authentic)
        server->trust |= 1;

    /*
     * Check for a KoD (rate limiting) response, cease and decist.
     */
    if (LEAP_NOTINSYNC == PKT_LEAP(rpkt->li_vn_mode) &&
        STRATUM_PKT_UNSPEC == rpkt->stratum && !memcmp("RATE", &rpkt->refid, 4))
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 9);

        server->event_time = 0;
        ntpd_cntx_p->done_cnt++;
        return;
    }

    /*
     * Looks good. Record info from the packet.
     */
    server->leap = PKT_LEAP(rpkt->li_vn_mode);
    server->stratum = PKT_TO_STRATUM(rpkt->stratum);
    server->precision = rpkt->precision;
    server->rootdelay = soc_ntohl(rpkt->rootdelay);
    server->rootdisp = soc_ntohl(rpkt->rootdisp);
    server->refid = rpkt->refid;
    NTOHL_FP(&rpkt->reftime, &server->reftime);
    NTOHL_FP(&rpkt->rec, &rec);
    NTOHL_FP(&rpkt->xmt, &server->org);

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_RECV_TIMESTAMP_ORG, org.Ul_i.Xl_i,org.Ul_f.Xl_f);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_RECV_TIMESTAMP_REC, rec.Ul_i.Xl_i,rec.Ul_f.Xl_f);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_RECV_TIMESTAMP_SORG, server->org.Ul_i.Xl_i,server->org.Ul_f.Xl_f);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_RECV_TIMESTAMP_DEST, rbufp->recv_time.Ul_i.Xl_i,rbufp->recv_time.Ul_f.Xl_f);

    /*
     * Make sure the server is at least somewhat sane. If not, try
     * again.
     */
    if (L_ISZERO(&rec) || !L_ISHIS(&server->org, &rec))
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 11);
        server->event_time = ntpd_cntx_p->current_time + ntpd_cntx_p->timeout;
        return;
    }

    /*
     * Calculate the round trip delay (di) and the clock offset (ci).
     * We use the equations (reordered from those in the spec):
     *
     * d = (t2 - t3) - (t1 - t0)
     * c = ((t2 - t3) + (t1 - t0)) / 2
     */
    t10 = server->org;              /* pkt.xmt == t1 */
    L_SUB(&t10, &rbufp->recv_time); /* recv_time == t0 */

    t23 = rec;          /* pkt.rec == t2 */
    L_SUB(&t23, &org);  /* pkt->org == t3 */

    /* now have (t2 - t3) and (t0 - t1).   Calculate (ci) and (di) */
    /*
     * Calculate (ci) = ((t1 - t0) / 2) + ((t2 - t3) / 2)
     * For large offsets this may prevent an overflow on '+'
     */
    ci = t10;
    L_RSHIFT(&ci);
    tmp = t23;
    L_RSHIFT(&tmp);
    L_ADD(&ci, &tmp);

    /*
     * Calculate di in t23 in full precision, then truncate
     * to an s_fp.
     */
    L_SUB(&t23, &t10);
    di = LFPTOFP(&t23);

    di += (FP_SECOND >> (-(int)NTPDATE_PRECISION)) + (FP_SECOND >> (-(int)server->precision)) + NTP_MAXSKW;

    if (di <= 0)
    {   /* value still too raunchy to use? */
        L_CLR(&ci);
        di = 0;
    }
    else
    {
        di = max(di, NTP_MINDIST);
    }

    /*
     * Shift this data in, then schedule another transmit.
     */

    ntpd_clock_filter(server, (s_fp) di, &ci, 0);

    server->event_time = ntpd_cntx_p->current_time; /* send immediately*/

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_RECV_PROC_NO, 20);
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_input
 * DESCRIPTION
 *  receive data asynchronously.
 * PARAMETERS
 *  soc     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ntpd_input(kal_int8 soc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct recvbuf *rb, *rbuf;
    l_fp ts;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_INPUT);

    get_systime(&ts);

    /*
     * Get a buffer and read the frame.  If we
     * haven't got a buffer, or this is ntpd_recv_procd
     * on the wild card socket, just dump the packet.
     */

    rb = get_free_recv_buffer();

    rb->recv_srcadr.addr_len = IP_ADDR_LEN;
    rb->recv_length = soc_recvfrom(soc, (char*)&rb->recv_pkt, sizeof(rb->recv_pkt), 0, &rb->recv_srcadr);
    if (rb->recv_length == -1)
    {
        freerecvbuf(rb);
    }

    /*
     * Got one.  Mark how and when it got here,
     * put it on the full list.
     */
    rb->recv_time = ts;
    add_full_recv_buffer(rb);

    rbuf = get_full_recv_buffer();

    while (rbuf != NULL)
    {
        ntpd_recv_proc(rbuf);
        freerecvbuf(rbuf);
        rbuf = get_full_recv_buffer();
    }

    /* is done */
    if (ntpd_cntx_p->done_cnt >= ntpd_cntx_p->server_num)
    {
        clock_adjust();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_hdlr_soc_notify_ind
 * DESCRIPTION
 *  This is the callback function for SOCKET.
 * PARAMETERS
 *  msg     [OUT]       The message data from SOC.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 ntpd_hdlr_soc_notify_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 sock;

    kal_uint8 event_type;   /* soc_event_enum */    
    kal_bool result;
    app_soc_notify_ind_struct *soc_ind;

    //kal_int8 error_cause;   /* used only when EVENT is close/connect */
    //kal_int32 detail_cause; /* refer to cm_cause_enum if error_cause is SOC_BEARER_FAIL */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    soc_ind = (app_soc_notify_ind_struct*) msg;

    sock = soc_ind->socket_id;
    event_type = soc_ind->event_type;
    result = soc_ind->result;

    //error_cause = soc_ind->error_cause;
    //detail_cause = soc_ind->detail_cause;

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_SOC_NOTIFY_IND, event_type);

    if (ntpd_cntx_p->soc_id != sock)
        return KAL_FALSE;

    switch (event_type)
    {
        case SOC_READ:
            if (result == KAL_TRUE)
            {
                ntpd_input(sock);
            }
            break;

        case SOC_WRITE:
            if (result == KAL_TRUE)
            {
                ntpd_server_send();
            }
            break;

        case SOC_CONNECT:
            if (result == KAL_TRUE)
            {

            }
            else
            {

            }
            break;

        case SOC_CLOSE:
            if (result == KAL_TRUE)
            {

            }
            break;

        default:
            break;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_hdlr_cbm_bearer_info_ind
 * DESCRIPTION
 *  This is the callback function for bearer information.
 * PARAMETERS
 *  msg     [OUT]       The message data from SOC.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 ntpd_hdlr_cbm_bearer_info_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 state;
    //kal_int8 bearer_type;
    app_cbm_bearer_info_ind_struct *bearer_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_ind = (app_cbm_bearer_info_ind_struct*) msg;
    state = bearer_ind->state;
    //bearer_type = bearer_ind->bearer;

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_BEARER_INFO_IND, state);

    switch (state)
    {
        case CBM_ACTIVATING:

            break;

        case CBM_ACTIVATED:
            //ntpd_start_timer(2000, ntpd_timer_proc);
            break;

        case CBM_DEACTIVATING:
            /* no need to notify, because when synchronizing, ppp must open. */
            break;

        case CBM_DEACTIVATED:

            break;

        case CBM_CSD_AUTO_DISC_TIMEOUT:
            /* only occured when CSD connection, NTP uses GPRS always */

            break;

        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_timer_proc
 * DESCRIPTION
 *  Start a timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_timer_proc(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* process the timeout */
    if (ntpd_cntx_p->state == NTPD_S_SYNC)
    {
        ntpd_server_send();

        ntpd_start_timer(1000, ntpd_timer_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_start_timer
 * DESCRIPTION
 *  Start a timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ntpd_start_timer(kal_uint32 delay, ntpd_timer_callback_f callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_START_TIMER);

    evshed_set_event(
            ntpd_timer_id,
            callback,
            NULL,
            delay);
}

/*
 * ntpd_send_packet - send a packet to the specified destination
 */


/*****************************************************************************
 * FUNCTION
 *  ntpd_send_packet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  pkt         [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int ntpd_send_packet(sockaddr_struct *dest, struct pkt *pkt, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cc;
    SOCKET sock = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SEND_PACKET);

    sock = ntpd_cntx_p->soc_id;

    if (sock < 0)
    {
        return SOC_ERROR;
    }

    dest->addr_len = IP_ADDR_LEN;
    cc = soc_sendto(sock, (char*)pkt, len, 0, dest);

    if (SOC_ERROR == cc)
    {
        return SOC_ERROR;
    }

    if (cc > 0)
    {
        ntpd_start_timer(2000, ntpd_timer_proc);
    }

    return cc;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_sync
 * DESCRIPTION
 *  The application requests to synchronize the local time with the indicated server.
 * PARAMETERS
 *  callback        [IN]        Callback funtion.
 *  usr_data        [IN]        The user data.
 * RETURNS
 *  It returns NTPD_SUCCESS on success, otherwise returns value is negative.
 *  The application will ntpd_recv_proc the result in the callback when the
 *  synchronization is done.
 *****************************************************************************/
static kal_int32 ntpd_server_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SYNC);

    //memset(&ntpd_cntx_p->serv_addr, 0, sizeof(sockaddr_struct));

    /* Begin to synchronize with the server */
    ntpd_cntx_p->serv_addr.port = ntpd_cntx_p->port[ntpd_cntx_p->done_cnt];
    ntpd_cntx_p->serv_addr.addr_len = NTPD_ADDR_LEN;
    ret = ntpd_gethostbyname(
            ntpd_cntx_p,
            ++ntpd_cntx_p->dns_req_id,
            ntpd_cntx_p->server[ntpd_cntx_p->done_cnt],
            &(ntpd_cntx_p->serv_addr));

    if (ret == SOC_SUCCESS)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SYNC_NO, 5);
        ntpd_add_server(&(ntpd_cntx_p->serv_addr));
        ntpd_cntx_p->state = NTPD_S_SYNC;
        ntpd_server_send();
    }
    else if (ret == SOC_WOULDBLOCK)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SYNC_NO, 7);
        ntpd_cntx_p->state = NTPD_S_HOST;
    }
    else
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SYNC_NO, 9);
        return NTPD_ERROR;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SERVER_SYNC_NO, 20);
    return NTPD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  ntp_transmit_packet
 * DESCRIPTION
 *  Transmit a packet to the given server.
 * PARAMETERS
 *  server      [IN]        Time server.
 * RETURNS
 *  void
 *****************************************************************************/
static void ntp_transmit_packet(struct server *server)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    int ret;
    struct pkt xpkt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTP_TRANSMIT_PACKET);

    if (server->filter_nextpt < server->xmtcnt)
    {
        l_fp ts;

        /*
         * Last message to this server timed out.  Shift
         * zeros into the filter.
         */
        L_CLR(&ts);

        ntpd_clock_filter(server, 0, &ts, PEER_MAXDISP);

    }

    if ((int)server->filter_nextpt >= ntpd_cntx_p->samples)
    {
        /*
         * Got all the data we need.  Mark this guy
         * completed and return.
         */
        server->event_time = 0;
        ntpd_cntx_p->done_cnt++;

        if (ntpd_cntx_p->done_cnt >= ntpd_cntx_p->server_num)
        {
            ntpd_cntx_p->state = NTPD_S_INIT;
            clock_adjust();
        }
        else
        {
            /* contact other server */
            ret = ntpd_server_sync();
        }
		
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTP_TRANSMIT_PACKET_NO, 1);

        return;
    }

    /*
     * If we're here, send another message to the server.  Fill in
     * the packet and let 'er rip.
     */
    xpkt.li_vn_mode = PKT_LI_VN_MODE(LEAP_NOTINSYNC, NTP_VERSION, MODE_CLIENT);
    xpkt.stratum = STRATUM_TO_PKT(STRATUM_UNSPEC);
    xpkt.ppoll = NTP_MINPOLL;
    xpkt.precision = NTPDATE_PRECISION;
    xpkt.rootdelay = soc_htonl(NTPDATE_DISTANCE);
    xpkt.rootdisp = soc_htonl(NTPDATE_DISP);
    xpkt.refid = soc_htonl(NTPDATE_REFID);
    L_CLR(&xpkt.reftime);
    L_CLR(&xpkt.org);
    L_CLR(&xpkt.rec);

    /*
     * Determine whether to authenticate or not. If so,
     * fill in the extended part of the packet and do it.
     * If not, just timestamp it and send it away.
     */
    if (ntpd_cntx_p->auth)
    {
        int len;

        /* //?xpkt.exten[0] = htonl(sys_authkey); */
        get_systime(&server->xmt);
        /* //?L_ADDUF(&server->xmt, sys_authdelay); */
        HTONL_FP(&server->xmt, &xpkt.xmt);
        len = authencrypt(ntpd_cntx_p->sys_authkey, (unsigned int*)&xpkt, LEN_PKT_NOMAC);
        ret = ntpd_send_packet(&server->srcadr, &xpkt, (int)(LEN_PKT_NOMAC + len));

    }
    else
    {
        get_systime(&(server->xmt));
        HTONL_FP(&server->xmt, &xpkt.xmt);
        ret = ntpd_send_packet(&server->srcadr, &xpkt, LEN_PKT_NOMAC);
    }

    /*
     * Update the server timeout and transmit count
     */
    if (ret == SOC_WOULDBLOCK)
    {
        server->event_time = ntpd_cntx_p->current_time;
    }
    else
    {
        server->event_time = ntpd_cntx_p->current_time + ntpd_cntx_p->timeout;
    }

    if (ret > 0)
    {
        server->xmtcnt++;
        server->reach <<= 1;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTP_TRANSMIT_PACKET_NO, 20);
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_hdlr_get_host_by_name_ind
 * DESCRIPTION
 *  This is the callback function for gethostbyname.
 * PARAMETERS
 *  msg     [OUT]       The message data from SOC.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 ntpd_hdlr_get_host_by_name_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_get_host_by_name_ind_struct *host_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_GET_HOST_BY_NAME_IND);

    host_ind = (app_soc_get_host_by_name_ind_struct*) msg;

    if ((host_ind == NULL) || (host_ind->result != KAL_TRUE))
    {
        /* error handling */
        ntpd_notify_app(NTPD_ERROR, NULL);
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_GET_HOST_NO, 1);
        return 0;
    }

    if (host_ind->request_id != ntpd_cntx_p->dns_req_id)
    {
        /* error handling */
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_GET_HOST_NO, 3);
        return KAL_FALSE;
    }

    ntpd_cntx_p->serv_addr.addr_len = host_ind->addr_len;
    memcpy(ntpd_cntx_p->serv_addr.addr, host_ind->addr, host_ind->addr_len);

    ntpd_add_server(&(ntpd_cntx_p->serv_addr));
    ntpd_cntx_p->state = NTPD_S_SYNC;

    /* transmit packet */
    ntpd_server_send();

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_HDLR_GET_HOST_NO, 20);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_gethostbyname
 * DESCRIPTION
 *  This function checks whether server_name is in legal dotted decimal format.
 *  Call SOC API to resolve the IP address if not.
 * PARAMETERS
 *  cntx_p          [IN]            Ntpd context
 *  req_id          [IN]            
 *  server_name     [IN]            Server address (domain name or IP)
 *  saddr           [IN/OUT]        Socket address
 *  job_id(?)       [IN]            Distinguish requests from the same source module, use (id * MAX_CONNS + job_id) as unique req id.
 * RETURNS
 *  NTPD_SUCCESS
 * WOULDBLOCK
 *  LOCAL_ERROR_DNS_ERROR
 *  LOCAL_ERROR_INVALID_SERVER_ADDR
 *****************************************************************************/
static kal_int8 ntpd_gethostbyname(
            ntpd_context_struct *cntx_p,
            kal_uint16 req_id,
            kal_uint8 *server_name,
            sockaddr_struct *saddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_ip_valid;
    kal_int8 ret = NTPD_SUCCESS;
    kal_int8 soc_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_GETHOSTBYNAME);

    ret = soc_ip_check((kal_char*) server_name, saddr->addr, &is_ip_valid);
    if (ret == KAL_FALSE)
    {

        /*
         * For soc_ip_check() return KAL_FALSE, the queried remote address
         * * is a domain name
         */

        /* server name is not an IP address */
        soc_cause = soc_gethostbyname(
                        KAL_FALSE,                          /* is blocking */
                        MOD_NTPD,                            /* mod_id */
                        cntx_p->dns_req_id,                 /* request_id */
                        (kal_char *)server_name,                        /* domain_name */
                        saddr->addr,                        /* addr */
                        (kal_uint8*) & (saddr->addr_len),   /* addr_len */
                        0,                                  /* access_id */
                        cntx_p->account_id);                /* nwk_account_id */

        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_GETHOSTBYNAME_NO, soc_cause);

        if (soc_cause == SOC_WOULDBLOCK)
        {
            ret = SOC_WOULDBLOCK;
        }
        else if (soc_cause < 0)
        {
            /* //kal_trace(TRACE_ERROR, ERROR_NTPD_DNS_GETADDR, soc_cause); */
        }
    }
    else if (is_ip_valid == KAL_FALSE)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_GETHOSTBYNAME_NO, 9);
        ret = SOC_ERROR;
    }
    else
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_GETHOSTBYNAME_NO, 10);
        /* valid IP address */
        saddr->addr_len = 4;
        ret = SOC_SUCCESS;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_GETHOSTBYNAME_NO, 20);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_create_socket
 * DESCRIPTION
 *  create the socket.
 * PARAMETERS
 *  net_id      [IN]        Profile id
 * RETURNS
 *  Return socket id on success, otherwise -1.
 *****************************************************************************/
static int ntpd_create_socket(unsigned int net_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 sd, ret;
    kal_uint8 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_CREATE_SOCKET);

    sd = soc_create(SOC_PF_INET, SOC_SOCK_DGRAM, 0, MOD_NTPD, net_id);

    if (sd < 0)
    {
        return sd;
    }

    val = SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE;
    ret = soc_setsockopt(sd, SOC_ASYNC, &val, sizeof(val));
    if (ret < 0)
    {
        return -1;
    }

    val = KAL_TRUE;
    ret = soc_setsockopt(sd, SOC_NBIO, &val, sizeof(val));
    if (ret < 0)
    {
        return -1;
    }

    /* soc_activate_account(sd); */

    return sd;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_socket_bind
 * DESCRIPTION
 *  create socket and bind the port.
 * PARAMETERS
 *  port        [IN]        Local port.
 * RETURNS
 *  return the socket id on success, otherwise -1.
 *****************************************************************************/
static int ntpd_socket_bind(kal_uint16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 soc_id;
    sockaddr_struct saddr;
    kal_int8 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SOCKET_BIND);

    soc_id = ntpd_create_socket(ntpd_cntx_p->account_id);

    /* //kal_trace(TRACE_FUNC, FUNC_NTPD_SOCKET_BIND, soc_id); */

    if (soc_id < 0)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SOCKET_BIND_NO, soc_id);
        return soc_id;
    }

    /* ret = setsockopt(soc_id, SO_REUSEPORT, &oneopt, sizeof(oneopt)); */
    if (ret < 0)
    {
        return ret;
    }

    memset(&saddr, 0, sizeof(saddr));
    saddr.addr_len = NTPD_ADDR_LEN;
    saddr.port = port;

    ret = soc_bind(soc_id, &saddr);

    if (ret < 0)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SOCKET_BIND_NO, 31);
        return ret;
    }

    return soc_id;
}


static void ntpd_sys_server_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct server *sp, *next_server = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sp = ntpd_cntx_p->sys_servers; sp != NULL; sp = next_server)
    {
        next_server = sp->next_server;
        ntpd_free(sp);
    }

    ntpd_cntx_p->sys_servers = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_open
 * DESCRIPTION
 *  The application requests to start NTP and provide some parameters
 *  including server, port, sample number and profile id etc.
 * PARAMETERS
 *  config      [IN]        Configuration Parameters.
 * RETURNS
 *  It returns NTPD_SUCCESS on success, otherwise returns value is negative.
 *****************************************************************************/
kal_int32 ntpd_open(struct ntpd_config_struct *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_OPEN);

    if (config == NULL)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_OPEN_NO, 1);
        return NTPD_ERROR;
    }

    if (ntpd_cntx_p->state != NTPD_S_IDLE)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_OPEN_NO, 3);
        return NTPD_SUCCESS;
    }

    ntpd_network_init();
    ntpd_create_mem_pool(); /* create the memory */

    memset(ntpd_cntx_p, 0, sizeof(ntpd_context));

    memcpy(ntpd_cntx_p->server, config->server, NTPD_SERVER_NUM * NTPD_MAX_NAME_LEN);
    memcpy(ntpd_cntx_p->keyid, config->keyid, NTPD_KEYID_LEN);

    memcpy(ntpd_cntx_p->port, config->port, sizeof(kal_uint16)*NTPD_SERVER_NUM);
    ntpd_cntx_p->server_num = config->server_num;
    ntpd_cntx_p->account_id = config->account_id;
    ntpd_cntx_p->samples = config->samples;
    ntpd_cntx_p->timeout = config->timeout;
    ntpd_cntx_p->auth = config->auth;

    ntpd_cntx_p->dns_req_id = 1357;

    /* Init the buffer */
    init_recvbuff(NTPD_SERVER_NUM + 2);

    /* bind the socket */
#ifdef __MTK_TARGET__	
    ntpd_cntx_p->soc_id = ntpd_socket_bind(ntpd_cntx_p->port[0]);
#else
    ntpd_cntx_p->soc_id = ntpd_socket_bind(ntpd_cntx_p->port[0] + 1037);
#endif

    ntpd_cntx_p->state = NTPD_S_INIT;

    if (ntpd_cntx_p->soc_id < 0)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_OPEN_NO, 5);
        return NTPD_ERROR;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_OPEN_NO, 20);
    return NTPD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_sync
 * DESCRIPTION
 *  The application requests to synchronize the local time with the indicated server.
 * PARAMETERS
 *  callback        [IN]        Callback funtion.
 *  usr_data        [IN]        The user data.
 * RETURNS
 *  It returns NTPD_SUCCESS on success, otherwise returns value is negative.
 *  The application will ntpd_recv_proc the result in the callback when the
 *  synchronization is done.
 *****************************************************************************/
kal_int32 ntpd_sync(ntpd_sync_cb callback, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;
    kal_uint16 i = ntpd_cntx_p->cb_cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC);

    if (callback == NULL)
    {
        return NTPD_ERROR;
    }

    if ((ntpd_cntx_p->state == NTPD_S_IDLE) || (ntpd_cntx_p->cb_cnt >= NTPD_MAX_CALLBACK))
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_NO, 3);
        return NTPD_ERROR;
    }

    ntpd_cntx_p->sync_cb[i] = callback;
    ntpd_cntx_p->usr_data[i] = usr_data;
    ntpd_cntx_p->cb_cnt++;

    /* Begin to synchronize with the server */
    ntpd_cntx_p->serv_addr.port = ntpd_cntx_p->port[ntpd_cntx_p->done_cnt];
    ntpd_cntx_p->serv_addr.addr_len = NTPD_ADDR_LEN;
    ret = ntpd_gethostbyname(
            ntpd_cntx_p,
            ++ntpd_cntx_p->dns_req_id,
            ntpd_cntx_p->server[ntpd_cntx_p->done_cnt],
            &(ntpd_cntx_p->serv_addr));

    if (ret == SOC_SUCCESS)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_NO, 5);
        ntpd_add_server(&(ntpd_cntx_p->serv_addr));
        ntpd_cntx_p->state = NTPD_S_SYNC;
        ntpd_server_send();
    }
    else if (ret == SOC_WOULDBLOCK)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_NO, 7);
        ntpd_cntx_p->state = NTPD_S_HOST;
    }
    else
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_NO, 9);
        return NTPD_ERROR;
    }

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_NO, 20);
    return NTPD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_sync_abort
 * DESCRIPTION
 *  The application requests to abort the synchronization.
 * PARAMETERS
 *  void
 * RETURNS
 *  It returns NTPD_SUCCESS on success, otherwise returns value is negative.
 *****************************************************************************/
kal_int32 ntpd_sync_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_SYNC_ABORT);

    ntpd_cntx_p->state = NTPD_S_INIT;

    return NTPD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_close
 * DESCRIPTION
 *  Release the resource if the application doesn't want to synchronize the local time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ntpd_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, FUNC_NTPD_CLOSE);

    if (ntpd_cntx_p->state == NTPD_S_IDLE)
    {
        return;
    }

    /* Release the buffer */
    uninit_recvbuff();

    if (ntpd_cntx_p->soc_id >= 0)
    {
        soc_close(ntpd_cntx_p->soc_id);
    }

    ntpd_network_deinit();
    ntpd_sys_server_free();

    ntpd_cntx_p->state = NTPD_S_IDLE;
}

/*****************************************************************************
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ntpd_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  offset          [IN]        
 *  usr_data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ntpd_sync_callback(kal_int32 result, kal_int64 offset, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ntpd_close();
}


/*****************************************************************************
 * FUNCTION
 *  ntpd_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ntpd_test_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ntpd_config_struct config;
    kal_uint8 app_id = 0;
    U32 acc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_register_app_id(&app_id);

    memset(&config, 0, sizeof(config));

    //strcpy(config.server[0], "172.27.4.10");
#ifdef __MTK_TARGET__    
    strcpy((char *)config.server[0], "203.117.180.36");
#else
    //strcpy(config.server[0], "172.27.50.10");
    strcpy((char *)config.server[0], "64.236.96.53");
#endif
    
    //
    /* strcpy(config.server[0], "www.baidu.com"); */
    //strcpy(config.server[0], "172.27.4.12");
    config.port[0] = 123;
    config.server_num = 1;

#ifdef __MTK_TARGET__
    //srv_dtcnt_get_acc_id_by_apn("cmnet", &acc_id);
    acc_id = CBM_WIFI_ACCT_ID;
#else
    acc_id = CBM_WIFI_ACCT_ID;
#endif
    config.account_id = cbm_encode_data_account_id(acc_id, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);
    config.samples = 4;
    config.timeout = 16;
    config.auth = 0;

    ntpd_open(&config);

    ntpd_sync((ntpd_sync_cb) ntpd_sync_callback, NULL);
}


#define CLOCK_PHI (1.0/86400)
#define NTP_FILTER (1.0/2)
#define NTPSELECT  (3.0/4)
#define MAX_SERVER (4)
#define MINCLOCK   (1)


/************************************************
*offset-distance:-1; offset:0; offset+distance:1
*************************************************/
typedef struct endpoint_mtk
{
    int value;
    int type;
}ntpd_endpoint_struct;

typedef struct candidate
{
    double distance;
    struct server * peer_ptr;
}ntpd_candidate_struct;



/*********************************************************
* FUNCTION
* ntpd_syn_distance
* DESCRIPTION
*  Calculate synchronize distance.
* PARAMETERS
*  peer          [IN]                point to peer context       
* RETURNS
*  synchronize distance
*********************************************************/
double ntpd_syn_distance(struct server * peer)
{
    double distance = 0.0;
    l_fp current_time;
    
    /*local var for format convert*/
    l_fp temp_l_fp_fir;
    l_fp temp_l_fp_sec;
    double temp_double_fir = 0.0;
    double temp_double_sec = 0.0;
    memset(&temp_l_fp_fir, 0, sizeof(temp_l_fp_fir));
    memset(&temp_l_fp_sec, 0, sizeof(temp_l_fp_sec));

    get_systime(&current_time);

    UFPTOLFP(peer->dispersion, &temp_l_fp_fir);
    UFPTOLFP(peer->rootdisp, &temp_l_fp_sec);
    LFPTOD(&temp_l_fp_fir, temp_double_fir);
    LFPTOD(&temp_l_fp_sec, temp_double_sec);

    distance = temp_double_fir - temp_double_sec;

    UFPTOLFP(peer->delay, &temp_l_fp_fir);
    UFPTOLFP(peer->rootdelay, &temp_l_fp_sec);
    LFPTOD(&temp_l_fp_fir, temp_double_fir);
    LFPTOD(&temp_l_fp_sec, temp_double_sec);   

    distance += fabs(temp_double_fir - temp_double_sec)/2;
    
    LFPTOD(&current_time, temp_double_fir);
    LFPTOD(&peer->updtime, temp_double_sec);

    distance += CLOCK_PHI * (temp_double_fir - temp_double_sec);

    /*to-do, check MAX-MIN*/
    if(distance >= MAXDISTANCE)
    {
        distance = MAXDISTANCE;
    }
    return distance;
}

/***************************************************
* FUNCTION
*  ntpd_clock_filter
* DESCRIPTION
*  Add incoming clock sample to filter register and find the best sample.
* PARAMETERS
*  peer          [IN]                point to peer context
*  offset        [IN]                sample offset       
*  delay         [IN]                sample delay
*  dispersion   [IN]                sample dispersion
* RETURNS
*  void
****************************************************/
void ntpd_clock_filter(struct server * peer, s_fp delay, l_fp * offset,  u_fp dispersion)
{
    int      current_index = 0;
    double	 synch_dst[NTP_SHIFT];		
	int	     sample_order[NTP_SHIFT];
    u_fp   compensation_disp = 0;
    int      i = 0, j = 0, temp = 0;
    l_fp      current_time;
    int      available_sample = 0;
    double      temp_dst = 0.0;
    double      filter_dispersion = 0.0;
    double      diff_offset = 0.0;

    /*local var for format convert*/
    double temp_double_fir = 0.0;
    double temp_double_sec = 0.0;

    
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_ENTER_CLOCK_FILTER, peer->refid, peer->filter_nextpt);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_CLOCK_FILTER_OFFSET, offset->Ul_i.Xl_i,offset->Ul_f.Xl_f);
    
    /*add new sample into filter register and modify the index*/
    current_index = peer->filter_nextpt;
    peer->filter_offset[current_index] = * offset;
	peer->filter_delay[current_index] = delay;
	peer->filter_error[current_index] = dispersion;
    peer->filter_soffset[current_index] = LFPTOFP(offset);
	//current_index = (current_index + 1) % NTP_SHIFT;
	//peer->filter_nextpt = current_index;
    peer->filter_nextpt = current_index+1;

    /*adjust old sample, calculate the synchronize distance*/
    get_systime(&current_time);
    LFPTOD(&current_time, temp_double_fir);
    LFPTOD(&peer->updtime, temp_double_sec);
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
    compensation_disp = DTOUFP( CLOCK_PHI * (temp_double_fir - temp_double_sec) );
    peer->updtime = current_time;
    
	for (i = NTP_SHIFT - 1; i >= 0; i--) 
	{
	  current_index = (current_index + 1) % NTP_SHIFT;
		if (i != 0)
    {
            peer->filter_error[current_index] += compensation_disp;
    }      			
		if (peer->filter_error[current_index] >= PEER_MAXDISP) 
    { 
			peer->filter_error[current_index] = PEER_MAXDISP;
			synch_dst[i] = FPTOD(PEER_MAXDISP);
		}
        else 
        {
			synch_dst[i] = FPTOD(peer->filter_delay[current_index])/2 + FPTOD(peer->filter_error[current_index]);
      available_sample++;
            //kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G9_NTPD,"[NTPD-PS] synch_dst[i] = [%f]",synch_dst[i]);
		}
		sample_order[i] = current_index;
		
	}

    if(available_sample <= 0)
    {
        peer->dispersion = PEER_MAXDISP;
    }

    /*sort the sample by synchronize distance*/
    for(i = 0; i < NTP_SHIFT; i++)
    {
        for(j = 0; j < NTP_SHIFT-i-1; j++)
        {
            if(synch_dst[j] > synch_dst[j+1])
            {
                temp_dst = synch_dst[j];
                synch_dst[j] = synch_dst[j+1];
                synch_dst[j+1] = temp_dst;
                
                temp = sample_order[j];
                sample_order[j] = sample_order[j+1];
                sample_order[j+1] = temp;
            }
        }
    }

    /*calculate filter dispersion*/
    for(i = NTP_SHIFT-1; i >= 0; i--)
    {
        if(i < available_sample)
        {
            diff_offset = fabs(FPTOD(peer->filter_soffset[sample_order[i]]) - FPTOD(peer->filter_soffset[sample_order[0]]));
            if(diff_offset > FPTOD(PEER_MAXDISP) )
            {
                diff_offset = FPTOD(PEER_MAXDISP);
            }
        }
        else
        {
            diff_offset = FPTOD(PEER_MAXDISP);
        }

        filter_dispersion = NTP_FILTER * (filter_dispersion + diff_offset);
    }

    /*update peer context*/
    peer->offset = peer->filter_offset[sample_order[0]];
    peer->delay = peer->filter_delay[sample_order[0]];
    peer->dispersion = peer->filter_error[sample_order[0]] + DTOUFP(filter_dispersion);
    //kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G9_NTPD,"[NTPD-PS] peer->dispersion = [%u]",peer->dispersion);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_PEER_DISPERSION,peer->dispersion);
    if(peer->dispersion > PEER_MAXDISP)
    {
        peer->dispersion = PEER_MAXDISP;
    }
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_CLOCK_FILTER_OFFSET, peer->offset.Ul_i.Xl_i,peer->offset.Ul_f.Xl_f);
    
}
int ntpd_clock_intersection_selection(int * top, int * bottom)
{
    struct server * temp_svr_list = ntpd_cntx_p->sys_servers;
    int num_of_survivor = 0;
    ntpd_endpoint_struct endpoint_vector[3 * NTPD_SERVER_NUM];
    ntpd_endpoint_struct temp_endpoint;
    int endpoint_index = 0;
    double sync_distance = 0;
    int i = 0;
    int j = 0;
    int clk = 0;
    int end = 0;
    double offset = 0;

    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_ENTER_CLOCK_INTERSECTION);
    for( ; temp_svr_list != NULL; temp_svr_list = temp_svr_list->next_server)
    {
        //kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G9_NTPD,"[NTPD-PS] reach is [%u]",temp_svr_list->reach);
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_REACH_NUM,temp_svr_list->reach);
        if( (temp_svr_list->reach != 0) && (temp_svr_list->dispersion < PEER_MAXDISP) )
        {
            LFPTOD(&temp_svr_list->offset ,offset);
            num_of_survivor++;
            sync_distance = ntpd_syn_distance(temp_svr_list);
            endpoint_vector[endpoint_index].value = offset - sync_distance;
            endpoint_vector[endpoint_index].type = -1;
            endpoint_index++;
            endpoint_vector[endpoint_index].value = offset;
            endpoint_vector[endpoint_index].type = 0;
            endpoint_index++; 
            endpoint_vector[endpoint_index].value = offset + sync_distance;
            endpoint_vector[endpoint_index].type = 1;
            endpoint_index++;
        }
    }

    if(num_of_survivor <= 0)
    {
        ntpd_cntx_p->error = NTPD_UNREACH;
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_CLOCK_INTERSECTION_NO_SERVER);
        return -1;
    }

    for(i = 0; i < endpoint_index; i++)
    {
        for(j = 0; j < endpoint_index-i-1; j++)
        {
            if( (endpoint_vector[j].value > endpoint_vector[j+1].value) ||
                ( (endpoint_vector[j].value == endpoint_vector[j+1].value) 
                && (endpoint_vector[j].type > endpoint_vector[j+1].type) ) )
            {
                temp_endpoint = endpoint_vector[j];
                endpoint_vector[j] = endpoint_vector[j+1];
                endpoint_vector[j+1] = temp_endpoint;
            }
        }

    }

    *bottom = endpoint_vector[0].value;
    *top = endpoint_vector[endpoint_index-1].value;
    
    for(i = 0; i < num_of_survivor/2; i++)
    {
    
        for(j = 0; j < endpoint_index; j++) 
        {
            end -= endpoint_vector[j].type;
            *bottom = endpoint_vector[j].value;
            if(end >= num_of_survivor-i)
            {
                break;
            }
            if(endpoint_vector[j].type == 0)
            {
                clk++;
            }
        }

        end = 0;

        for(j = endpoint_index-1; j >= 0; j--)
        {
            end += endpoint_vector[j].type;
            *top = endpoint_vector[j].value;
            if(end >= num_of_survivor-i)
            {
                break;
            }
            if(endpoint_vector[j].type == 0)
            {
                clk++;
            }
        }

        if(clk <= i)
        {
            break;
        }
    }
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_CLOCK_INTERSECTION_BOUNDARY,*bottom,*top);
    return 0;
}


int ntpd_clock_clustering_selection(int top, int bottom, l_fp * offset)
{
    struct server * temp_svr_list = ntpd_cntx_p->sys_servers ;
    int count = 0;
    double sync_distance = 0;
    double dist = 0;
    ntpd_candidate_struct candidate_vector[NTPD_SERVER_NUM];
    ntpd_candidate_struct temp_candidate;
    int i = 0;
    int j = 0;
    double max_select_disp = 0;
    int select_disp_index = 0;
    double min_disp = MAXDISPERSE;
    double select_disp = 0;
    double dispersion = 0;
    double offset_sum = 0;
    double dis_sum = 0;

    /*local var for format convert*/
    l_fp temp_l_fp;
    double temp_double_fir = 0.0;
    double temp_double_sec = 0.0;
    
    
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_ENTER_CLOCK_CLUSTER_SELECT);
    for( ; temp_svr_list != NULL; temp_svr_list = temp_svr_list->next_server)
    {
        LFPTOD(&temp_svr_list->offset ,temp_double_fir);
        if(temp_double_fir >= bottom && temp_double_fir <= top && temp_svr_list->reach !=0 )
        {
            sync_distance = ntpd_syn_distance(temp_svr_list);
            dist = sync_distance * MAXDISPERSE + temp_svr_list->stratum;
            candidate_vector[count].distance = dist;
            candidate_vector[count].peer_ptr = temp_svr_list;
            count++;
        }
    }

    if(count == 0)
    {
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_CLOCK_CLUSTER_SELECT_NO_SERVER);
        if(ntpd_cntx_p->ntpd_sys_peer != NULL)
        {
            *offset = ntpd_cntx_p->ntpd_sys_peer->offset;
        }
        else
        {
            *offset = ntpd_cntx_p->sys_servers->offset;
        }
        return -1;
    }

    for(i = 0; i< count; i++)
    {
        for(j = 0; j < count-i-1; j++)
        {
            if(candidate_vector[j].distance > candidate_vector[j+1].distance)
            {
                temp_candidate = candidate_vector[j];
                candidate_vector[j] = candidate_vector[j+1];
                candidate_vector[j+1] = temp_candidate;
            }
        }
    }

    while(1)
    {
        max_select_disp = 0;
        min_disp = MAXDISPERSE;
        
        for(i = 0; i < count; i++)
        {
            select_disp = 0;
            LFPTOD(&candidate_vector[i].peer_ptr->offset, temp_double_fir);
            for(j = count-1; j >= 0; j--)
            {
               LFPTOD(&candidate_vector[j].peer_ptr->offset, temp_double_sec);
               select_disp = NTPSELECT * (select_disp + 
                fabs(temp_double_fir - temp_double_sec) ); 
            }
            if(select_disp > max_select_disp)
            {
                max_select_disp = select_disp;
                select_disp_index = i;
            }

            UFPTOLFP(candidate_vector[i].peer_ptr->dispersion, &temp_l_fp);
            LFPTOD(&temp_l_fp, temp_double_fir);
            dispersion = temp_double_fir;
            get_systime(&temp_l_fp);
            LFPTOD(&temp_l_fp, temp_double_fir);
            LFPTOD(&candidate_vector[i].peer_ptr->reftime, temp_double_sec);
            
            dispersion += CLOCK_PHI * (temp_double_fir - temp_double_sec);
            if(dispersion < min_disp)
            {
                min_disp = dispersion;
            }
        }

        if(max_select_disp <= min_disp || count <= MINCLOCK)
        {
            break;
        }
        if(ntpd_cntx_p->ntpd_sys_peer == candidate_vector[select_disp_index].peer_ptr)
        {
            ntpd_cntx_p->ntpd_sys_peer = NULL;
        }

        for(i = select_disp_index; i < count-1; i++)
        {
            candidate_vector[i] = candidate_vector[i+1];
        }
        count--;
    }
    if(ntpd_cntx_p->ntpd_sys_peer != candidate_vector[0].peer_ptr)
    {
        if(ntpd_cntx_p->ntpd_sys_peer == NULL)
        {
            ntpd_cntx_p->ntpd_sys_peer = candidate_vector[0].peer_ptr;
            //NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_SELECT_SYNC_SERVER, ntpd_cntx_p->ntpd_sys_peer->refid);
        }
        else if(ntpd_cntx_p->ntpd_sys_peer->stratum < candidate_vector[0].peer_ptr->stratum)
        {
            ntpd_cntx_p->ntpd_sys_peer = candidate_vector[0].peer_ptr;
            //NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_SELECT_SYNC_SERVER, ntpd_cntx_p->ntpd_sys_peer->refid);
        }
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_SELECT_SYNC_SERVER, ntpd_cntx_p->ntpd_sys_peer->refid);
    }

    for(i = 0; i < count; i++)
    {
        LFPTOD(&candidate_vector[i].peer_ptr->offset, temp_double_fir);
        offset_sum += (temp_double_fir) / 
            (ntpd_syn_distance(candidate_vector[i].peer_ptr));
        dis_sum += 1 /  ntpd_syn_distance(candidate_vector[i].peer_ptr);
        
    }
    //*offset = offset_sum / dis_sum;
    DTOLFP(offset_sum / dis_sum, offset);
    return 0;
}

void ntpd_clock_select(l_fp * offset)
{
    int top = 0;
    int bottom = 0;
    int intersection_result = 0;
    
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD, NTPD_ENTER_CLOCK_SLECT);
    intersection_result = ntpd_clock_intersection_selection(&top, &bottom);
    if(intersection_result == -1)
    {
        if(ntpd_cntx_p->ntpd_sys_peer != NULL)
        {
            *offset = ntpd_cntx_p->ntpd_sys_peer->offset;
        }
        else
        {
            *offset = ntpd_cntx_p->sys_servers->offset;
        }
        NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_CLOCK_SELECT_OFFSET,offset->Ul_i.Xl_i,offset->Ul_f.Xl_f);
        return;
    }
    ntpd_clock_clustering_selection(top, bottom, offset);
    NTPD_TRACE(MMI_CONN_TRC_G9_NTPD,NTPD_CLOCK_SELECT_OFFSET,offset->Ul_i.Xl_i,offset->Ul_f.Xl_f);
    
}

void ntpd_sync_time_ext(ntpd_sync_cb callback, kal_uint32 account_id, void *usr_data)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	ilm_struct *ilm_ptr = NULL;
	ntpd_open_param * ind_p;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
    ind_p = (ntpd_open_param*) construct_local_para( sizeof(ntpd_open_param), TD_CTRL);

	ind_p->usr_data = usr_data;
	ind_p->callback = callback;
	ind_p->account_id = account_id;
	
	ilm_ptr = allocate_ilm(stack_get_active_module_id());
	ilm_ptr->src_mod_id = stack_get_active_module_id();
	ilm_ptr->dest_mod_id = MOD_NTPD;
	ilm_ptr->sap_id = 0;

	ilm_ptr->msg_id = (msg_type) MSG_ID_NTPD_SYNC_TIME;
	ilm_ptr->local_para_ptr = (local_para_struct*)ind_p;
	ilm_ptr->peer_buff_ptr = NULL;
	
	msg_send_ext_queue(ilm_ptr);
}

void ntpd_sync_time_close()
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	ilm_struct *ilm_ptr = NULL;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	ilm_ptr = allocate_ilm(stack_get_active_module_id());
	ilm_ptr->src_mod_id = stack_get_active_module_id();
	ilm_ptr->dest_mod_id = MOD_NTPD;
	ilm_ptr->sap_id = 0;
	
	ilm_ptr->msg_id = (msg_type) MSG_ID_NTPD_SYNC_CLOSE;
	ilm_ptr->local_para_ptr = NULL;
	ilm_ptr->peer_buff_ptr = NULL;
	
	msg_send_ext_queue(ilm_ptr);

}

static void ntpd_sync_time_int(void *local_param)
{
	ntpd_open_param * ind_p = (ntpd_open_param *) local_param;
	struct ntpd_config_struct config;
	kal_int32 i;
    static kal_uint8 app_id = 0;
    static U32 acc_id = 0;
    cbm_app_info_struct info;                        

    memset(&config, 0, sizeof(config));

	for (i = 0; i < NTPD_SERVER_NUM && i < NTP_SERVER_NUM; ++i)
	{
		strncpy(config.server[i], g_ntp_servers[i], NTPD_MAX_NAME_LEN);
	}

    for (i = 0; i < NTPD_SERVER_NUM; ++i)
    {
        config.port[i] = NTP_PROTOCAL_PORT;
    }

	if (app_id == 0)
	{
		memset(&info,0,sizeof(info));
		info.app_str_id = 0;
		info.app_icon_id = 0;
		info.app_type = DTCNT_APPTYPE_NTP;
		acc_id = ind_p->account_id;
		cbm_register_app_id_with_app_info(&info, &app_id);
		acc_id = cbm_encode_data_account_id(acc_id, 0, app_id, KAL_FALSE);
	}
	else
	{
		acc_id = cbm_encode_data_account_id(ind_p->account_id, 0, app_id, KAL_FALSE);
	}
	
	config.account_id = acc_id;
    config.server_num   = (U16)NTPD_SERVER_NUM;
    config.samples      = NTP_SAMPLES_NUM;
    config.timeout      = NTP_TIME_OUT_SECONDS;
    config.auth         = 0;

	

	ntpd_open(&config);
	ntpd_sync(ind_p->callback, ind_p->usr_data);
}

static void ntpd_main(ilm_struct *current_ilm)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(current_ilm != NULL);
	
	if (current_ilm != NULL)
	{
		switch (current_ilm->msg_id) 
		{
			case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
				ntpd_hdlr_get_host_by_name_ind((void*) current_ilm->local_para_ptr);
				break;
			case MSG_ID_APP_SOC_NOTIFY_IND:
				ntpd_hdlr_soc_notify_ind((void*) current_ilm->local_para_ptr);
				break;
			case MSG_ID_TIMER_EXPIRY:
				evshed_timer_handler(ntpd_timer_id);
				break;
			case MSG_ID_NTPD_SYNC_TIME:
				ntpd_sync_time_int(current_ilm->local_para_ptr);
				break;
			case MSG_ID_NTPD_SYNC_CLOSE:
				ntpd_close();
				break;
			 default:
				 break;
		}
	}			 
}


/*****************************************************************************
  * FUNCTION
  *  ftpsrv_main 
  * DESCRIPTION
  * PARAMETERS
  * RETURNS
  *****************************************************************************/
 static void ntpd_task_main(task_entry_struct *task_entry_ptr)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	
	 ilm_struct current_ilm;
	 kal_uint32 ntpd_index;
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/

	 kal_get_my_task_index(&ntpd_index);
	  
	 while ( 1 ) 
	 {	 
		 receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
		 stack_set_active_module_id(ntpd_index, current_ilm.dest_mod_id);
		 ntpd_main(&current_ilm);
		 free_ilm(&current_ilm);
	 } 
 }
 
/*****************************************************************************
* FUNCTION
*  ftpsrv_init 
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static kal_bool ntpd_init(task_indx_type task_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
    ntpd_timer_id = evshed_create("ntpd_protocol_timer", MOD_NTPD, 0, 0);
	return KAL_TRUE;	   
}


/*****************************************************************************
* FUNCTION
*  ftpsrv_deinit
* DESCRIPTION
* RETURNS
*****************************************************************************/
kal_bool ntpd_deinit(task_indx_type task_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/

	return KAL_TRUE;
}	 


/*****************************************************************************
* FUNCTION
*  ftpsrv_reset
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
kal_bool ntpd_reset(task_indx_type task_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	return KAL_TRUE;
}	

/*****************************************************************************
 * FUNCTION
 *  ftpsrv_create 
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool ntpd_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static comptask_handler_struct ntpd_handler_info = 
    {
        ntpd_task_main,         /* task entry function */
        ntpd_init,         /* task initialization function */
        NULL,
        ntpd_reset,        /* task reset handler */
        ntpd_deinit,       /* task termination handler */
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = &ntpd_handler_info;
    return KAL_TRUE;
}

