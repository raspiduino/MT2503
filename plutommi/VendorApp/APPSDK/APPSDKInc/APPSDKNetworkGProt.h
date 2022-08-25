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
 *  SDKNetwork.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access network related functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKNETWORK_H_
#define _SDKNETWORK_H_

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "soc_consts.h"
#include "stack_config.h"
#include "app2soc_struct.h"
#include "cbm_consts.h"
#include "wgui_categories_list.h"
#include "xmlgen_common.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/****************************************************************************
 * soc_api.h
 ****************************************************************************/
#include "soc_api.h"

extern kal_int8 soc_create(kal_uint8         domain,
                           socket_type_enum  type,
                           kal_uint8         protocol,
                           module_type       mod_id,
                           kal_uint32        nwk_account_id);
extern kal_int8 soc_close(kal_int8 s);
extern kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr);
extern kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog);
extern kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr);
extern kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr);
extern kal_int32 soc_sendto(kal_int8	     s,
                            const void       *buf,
                            kal_int32	     len,
                            kal_uint8 	     flags,
                            sockaddr_struct *addr);
extern kal_int32 soc_send(kal_int8	 s,
                          const void *buf,
                          kal_int32  len,
                          kal_uint8	 flags);
extern kal_int32 soc_recvfrom(kal_int8        s,
                              void            *buf,
                              kal_int32       len,
                              kal_uint8       flags,
                              sockaddr_struct *fromaddr);
extern kal_int32 soc_recv(kal_int8  s,
                          void *buf,
                          kal_int32 len,
                          kal_uint8 flags);
extern kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how);
extern kal_int8 soc_setsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);
extern kal_int8 soc_getsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);
/* currently, this function only support non-blocking mode */
extern
kal_int8 soc_gethostbyname(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id);
/* New API for resolving one domain name mapping to multiple IP addresses */
extern
kal_int8 soc_gethostbyname2(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id,
                           kal_uint8       in_entry_num,
                           kal_uint8       *out_entry_num);
/* currently, this function only support non-blocking mode */
extern
kal_int8 soc_gethostbyaddr(kal_bool         is_blocking,
                           module_type      mod_id,
                           kal_int32        request_id,
                           kal_char         *domain_name,
                           kal_uint32       *domain_name_len,
                           const kal_uint8  *addr,
                           kal_uint8	    addr_len,
                           kal_uint8        access_id,
                           kal_uint32       nwk_account_id);
extern
kal_int8 soc_gethostbysrv(module_type         mod_id,
                          kal_int32           request_id,
                          const kal_char      *domain_name,
                          kal_uint8           access_id,
                          kal_uint32          nwk_account_id,
                          soc_dns_srv_struct  *entry,
                          kal_uint8           in_entry_num,
                          kal_uint8           *out_entry_num);
extern
kal_int8 soc_gethostbynaptr(module_type           mod_id,
                            kal_int32             request_id,
                            const kal_char        *domain_name,
                            kal_uint8             access_id,
                            kal_uint32            nwk_account_id,
                            soc_dns_naptr_struct  *entry,
                            kal_uint8             in_entry_num,
                            kal_uint8             *out_entry_num);
extern
kal_int8 soc_abort_dns_query(kal_bool     by_mod_id,
                             module_type  mod_id,
                             kal_bool     by_request_id,
                             kal_uint32   request_id,
                             kal_bool     by_access_id,
                             kal_uint8    access_id,
                             kal_bool     by_nwk_account_id,
                             kal_uint32   nwk_account_id);
extern 
kal_int8 soc_get_account_localip(kal_int8 s, kal_uint8 *local_ip);
extern 
kal_int8 soc_getsockaddr(kal_int8         s, 
                         kal_bool         is_local,
                         sockaddr_struct  *addr);
extern
kal_int8 soc_get_last_error(kal_int8   s,
                            kal_int8   *error, 
                            kal_int32  *detail_cause);
extern
kal_bool soc_ip_check(kal_char   *asci_addr, 
                      kal_uint8  *ip_addr, 
                      kal_bool   *ip_validity);
extern void soc_read_notify(kal_int8 s, kal_bool set);
extern kal_bool soc_ready_for_read(kal_int8 s);
extern kal_bool soc_set_csd_auto_disconnect_timer(kal_uint16 sec);
extern kal_bool soc_get_csd_auto_disconnect_timer(kal_uint16 *sec);
extern kal_uint16 soc_cksum(kal_uint16 *buf, kal_int32 len);

#ifndef GEN_FOR_PC
extern kal_int8 soc_select(kal_uint8  ndesc,
                           soc_fd_set     *in,
                           soc_fd_set     *out,
                           soc_fd_set     *ex,
                           soc_timeval_struct *tv);
#endif

/****************************************************************************
 * wps_struct.h & wps_sap.h
 ****************************************************************************/
#ifdef __cplusplus
 typedef enum appsdk_nw_sap_enum
{
    #include "wap_sap.h"  
    MSG_ID_WAP_CODE_CHECK_POINT,
}appsdk_nw_sap_enum;
#endif

#include "wps_struct.h"

extern kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf);


/****************************************************************************
 * cbm_api.h
 ****************************************************************************/

extern kal_int8 cbm_register_app_id(kal_uint8 *app_id);
extern kal_bool cbm_deregister_app_id(kal_uint8 app_id);
extern kal_uint32 cbm_encode_data_account_id(kal_uint32 acct_id, cbm_sim_id_enum sim_id, 
                                      kal_uint8 app_id, kal_bool always_ask);
extern kal_uint32 cbm_set_app_id(kal_uint32 acct_id, kal_uint8 app_id);
extern kal_bool cbm_decode_data_account_id(kal_uint32 acct_id, 
                                           cbm_sim_id_enum *sim_id, 
                                           kal_uint8 *app_id, 
                                           kal_bool *always_ask, 
                                           kal_uint32* ori_acct_id);
extern kal_bool cbm_is_always_ask_account(kal_uint32 acct_id);
extern cbm_sim_id_enum cbm_get_sim_id(kal_uint32 acct_id);
extern kal_uint8 cbm_get_app_id(kal_uint32 acct_id);
extern kal_uint8 cbm_get_original_account(kal_uint32 acct_id);

/****************************************************************************
 * DataAccountGProt.h
 ****************************************************************************/
#include "DataAccountGProt.h"
#include "DataAccountCuiGprot.h"

/* Create select CUI, data account CUI will support multi-instance */
extern mmi_id cui_dtcnt_select_create(mmi_id parent_gid);
/* Initialize CUI */
extern void cui_dtcnt_select_set_param(mmi_id cui_gid, cui_dtcnt_select_run_struct *p_args);
/* Execute CUI*/
extern void cui_dtcnt_select_run(mmi_id cui_gid);
/* Close CUI */
extern void cui_dtcnt_select_close(mmi_id cui_gid);

extern MMI_BOOL mmi_dtcnt_get_full_account_name(U32 acct_id, S8 *dest, U8 len, mmi_dtcnt_get_acct_name_type_enum type);
extern MMI_BOOL mmi_dtcnt_ready_check(FuncPtr ready_callback, MMI_BOOL with_scr_lock);

/****************************************************************************
 * xml_def.h
 ****************************************************************************/
#include "xml_def.h"

extern kal_int32 xml_new_parser(XML_PARSER_STRUCT *parser);
extern void xml_close_parser(XML_PARSER_STRUCT *parser);
extern void xml_register_doctype_handler(
                XML_PARSER_STRUCT *parser,
                XML_start_doctype_hdlr start_hdlr,
                XML_end_doctype_hdlr end_hdlr);
extern void xml_register_element_handler(
                XML_PARSER_STRUCT *parser,
                XML_start_elem_hdlr start_hdlr,
                XML_end_elem_hdlr end_hdlr);
extern void xml_register_data_handler(XML_PARSER_STRUCT *parser, XML_data_hdlr data_hdlr);
extern kal_int32 xml_parse(XML_PARSER_STRUCT *parser, kal_wchar *file_name);
extern kal_int32 xml_parse_buffer(XML_PARSER_STRUCT *parser, const kal_char *xmltext, kal_int32 length);
extern void xml_stop_parse(XML_PARSER_STRUCT *parser);
extern kal_char *xml_get_err_string(XML_PARSER_STRUCT *parser);
extern void xml_configure_memory(
                XML_PARSER_STRUCT *parser,
                XML_malloc_buffer_ptr get_ptr,
                XML_free_buffer_ptr free_ptr);


/****************************************************************************
 * xmlgen.h
 ****************************************************************************/
#ifdef  __XML_SUPPORT__
#include "xmlgen.h"

extern XG_HANDLE xml_new_generator(kal_char* dest, kal_uint32 length);
extern kal_int32 xml_close_generator(XG_HANDLE hd);
extern kal_int32 xml_generate_xmldecl(XG_HANDLE hd, const kal_char *verstr, XML_ENCODING_TYPE_ENUM encode);
extern kal_int32 xml_generate_doctypedecl(XG_HANDLE hd, const kal_char* name, xg_doctype_mark_enum mark, const kal_char* externalid);
extern kal_int32 xml_generate_doctypedecl_ex(XG_HANDLE hd, const kal_char* name, kal_char* dtd, kal_uint32 len_dtd);
extern kal_int32 xml_generate_stag(XG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr);
extern kal_int32 xml_generate_data(XG_HANDLE hd, kal_char* data, kal_uint32 datalen);
extern kal_int32 xml_generate_cdata(XG_HANDLE hd, kal_char* cdata, kal_uint32 datalen);
extern kal_int32 xml_generate_etag(XG_HANDLE hd, const kal_char* el);
extern kal_int32 xml_generate_inline_element(XG_HANDLE hd, const kal_char* el, kal_char* data, kal_uint32 datalen);
extern kal_int32 xml_generate_empty_element(XG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr);
#endif  /* __XML_SUPPORT__ */

/****************************************************************************
 * Wbxmlp.h
 ****************************************************************************/
#ifdef  __WBXML_SUPPORT__
#include "Wbxmlp.h"

/* API for parsing */
extern WP_HANDLE wbxml_new_parser(void);
extern void wbxml_close_parser(WP_HANDLE handle);
extern kal_int32 wbxml_parse(WP_HANDLE handle, kal_char* src, kal_int32 length);
extern void wbxml_stop_parser(WP_HANDLE handle);
extern kal_char *wbxml_get_error_tag(WP_HANDLE handle);

/* API for registering callback functions */
extern void wbxml_register_header_handler(WP_HANDLE handle,  wbxml_header_hdlr header_hdlr);
extern void wbxml_register_data_handler(WP_HANDLE handle, wbxml_data_hdlr data_hdlr);
extern void wbxml_register_element_handler(WP_HANDLE handle,
                               wbxml_stag_hdlr stag_hdlr, wbxml_end_elem_hdlr end_hdlr);
extern void wbxml_register_get_name_handler(WP_HANDLE  handle,
                            wbxml_get_tagname_by_token get_tagname_by_token,
                            wbxml_get_attrname_by_token get_attrname_by_token);
extern void wbxml_configure_memory(WP_HANDLE  handle,
            wbxml_malloc_buffer_ptr get_buffer,  wbxml_free_buffer_ptr free_buffer);

/* API for getting extension data*/
extern kal_char *wbxml_get_ext_0(const kal_char* data, kal_uint32 *len);
extern kal_char *wbxml_get_ext_1(const kal_char* data, kal_uint32 *len);
extern kal_char *wbxml_get_ext_2(const kal_char* data, kal_uint32 *len);
#endif  /* __WBXML_SUPPORT__ */

/****************************************************************************
 * Wbxmlgen.h
 ****************************************************************************/
#ifdef  __WBXML_SUPPORT__
#include "Wbxmlgen.h"

extern WG_HANDLE wbxml_new_generator(kal_char* dest, kal_uint32 length);
extern kal_int32 wbxml_close_generator(WG_HANDLE hd);
extern void wbxml_register_get_token_handler(WG_HANDLE  handle, wbxml_get_token_by_tagname get_token_by_tagname, 
        wbxml_get_token_by_attrname get_token_by_attrname, wbxml_get_token_by_attrvalue get_token_by_attrvalue);
extern kal_int32 wbxml_generate_header(WG_HANDLE hd, kal_uint8 mainver, kal_uint8 subver, const kal_char* publicid, wbxml_charset_type_enum charset);
extern kal_int32 wbxml_generate_stag(WG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr, kal_bool iscontent);
extern kal_int32 wbxml_generate_data(WG_HANDLE hd, kal_char* data, kal_uint32 datalen, wbxml_data_type_enum data_type);
extern kal_int32 wbxml_generate_empty_element(WG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr);
extern kal_int32 wbxml_generate_inline_element(WG_HANDLE hd, const kal_char* el, kal_char* data, kal_uint32 datalen, kal_uint8 datatype);
extern kal_int32 wbxml_generate_etag(WG_HANDLE hd, const kal_char* el);
#endif  /* __WBXML_SUPPORT__ */

#endif /* _SDKNETWORK_H_ */ 

