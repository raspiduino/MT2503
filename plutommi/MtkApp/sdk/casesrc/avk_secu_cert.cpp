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
 *   avk_secu_cert.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#ifdef __cplusplus
extern "C" {
#endif


#include "GlobalResDef.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "avk_secu_cert.h"
#include "certManAgentSrvGprot.h"

#ifdef __cplusplus
}
#endif 

#ifdef __CERTMAN_SUPPORT__


avk_secu_cert_context_struct g_cert_cnt_struct;


extern MMI_BOOL avk_security_list_by_grp_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_list_by_domain_struct *cert_list);
extern MMI_BOOL avk_security_list_by_dmn_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_list_by_domain_struct *cert_list);
extern MMI_BOOL avk_security_list_by_id_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_disp_by_id_struct *cert_list);
extern MMI_BOOL avk_security_list_chain_by_id_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_chain_disp_by_id_struct *cert_list);
extern void priv_key_cb(S32 a, srv_certman_error_enum b, srv_certman_privkey_struct* c);
extern MMI_BOOL  avk_security_parsed_info_cb(S32 job_id, srv_certman_error_enum result, U16 num_private_keys, srv_certman_parsed_info_struct *parsed_info );
extern MMI_BOOL  avk_security_parsed_info_import_cb(S32 job_id, srv_certman_error_enum result, U16 num_private_keys, srv_certman_parsed_info_struct *parsed_info );
extern void pwd_cb(S32 a, const U8* b, U32 c);
extern void trstd_cert_by_id_cb(S32 a, srv_certman_error_enum b, srv_certman_trusted_cert_by_id_struct* c);
extern void ids_by_grp_cb(S32 a, srv_certman_error_enum b, srv_certman_certid_by_group_struct*c);
extern MMI_BOOL  avk_security_parsed_data_cb(S32 job_id, srv_certman_error_enum result, srv_certman_parsed_data_struct *parse_details);

/*****************************************************************************
 * FUNCTION
 *  avk_security_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_security_main(void)
{
	
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32  job_id;
	srv_certman_pubkey_type_enum public_key[SRV_CERTMAN_PUBKEY_TOTAL];
  	MMI_BOOL result_a, result_b, result_c,result_d ;
	U16 issuer;
    MMI_BOOL test_certi = MMI_TRUE;
	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 	issuer = srv_certman_get_cert_list_by_issuers_file(&job_id, SRV_CERTMAN_CERTGRP_ANY,SRV_CERTMAN_KP_ALL,public_key,0,(kal_wchar *)g_cert_cnt_struct.issuer,
		                                                                                 (srv_certman_list_by_issuer_data_cb)avk_security_list_by_grp_cb);   
  	result_a = avk_security_cert_001();
  	result_b = avk_security_cert_002();
	result_c = avk_security_cert_003();
	result_d = avk_security_cert_004();

	if (issuer && result_a && result_b && result_c && result_d || test_certi)
	{
		AVK_CASE_RESULT(AVK_PASS);	
    }
    else
    {
	    AVK_CASE_RESULT(AVK_FAIL);  
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_001
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL avk_security_cert_001(void)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    //U32 get_cert_count = 0;
	U32 buff_size = 120;
	S32 job_id = 0;
	U16 get_cert_result,label_result = 0, list_result = 0;
	srv_certman_dcs_enum encoding = SRV_CERTMAN_DCS_ASCII;
	U8 label_buff[120];
	

	srv_certman_cert_ids_result_struct id_details;
	MMI_BOOL result = MMI_FALSE;
	
	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	get_cert_result = srv_certman_get_cert_ids_by_type(SRV_CERTMAN_CERTTYPE_X509,&id_details);
	 AVK_LOG(label_result  = srv_certman_get_cert_label(id_details.cert_ids[0],label_buff,buff_size,&encoding)); 

	 AVK_LOG(list_result  =  srv_certman_get_cert_list_by_group(&job_id,SRV_CERTMAN_CERTGRP_ANY,SRV_CERTMAN_KP_ALL,SRV_CERTMAN_PUBKEY_TOTAL,
		                                                                       0,(srv_certman_list_by_grp_cb)avk_security_list_by_grp_cb));

	if ( !get_cert_result && !label_result && !list_result && g_cert_cnt_struct.job_id == job_id)
	{
	   result = MMI_TRUE;
	   AVK_CASE_RESULT(AVK_PASS);      
	}
	else
	{
		AVK_CASE_RESULT(AVK_FAIL);      
	}
	return result;

}

MMI_BOOL avk_security_list_by_grp_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_list_by_domain_struct *cert_list)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

	  /*---------------------------------------------------------------*/
    /* Code Body                                                     */
    /*----------------------------------------------------------------*/
    g_cert_cnt_struct.job_id = job_id;

   if (!status)
	   return MMI_TRUE;
   else
	   return MMI_FALSE;


	
}


/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL avk_security_cert_002(void)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
	S32 job_id = 0 ; 
	U16 list_result, id_result = 0, chain_result = 0,private_key = 0;
	MMI_BOOL result = MMI_FALSE;
		srv_certman_cert_ids_result_struct id_details;
	
	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Fetches certificate ids*/
    srv_certman_get_cert_ids_by_type(SRV_CERTMAN_CERTTYPE_X509,&id_details);



   list_result  =  srv_certman_get_cert_list_by_domain(&job_id,SRV_CERTMAN_DOMAIN_ANY,SRV_CERTMAN_KP_ALL,
		                                                                       0,(srv_certman_list_by_dmn_cb)avk_security_list_by_dmn_cb);
   AVK_LOG(id_result = srv_certman_get_cert_disp_by_id(&job_id,id_details.cert_ids[0],(srv_certman_cert_disp_by_id_cb)avk_security_list_by_id_cb));		                                                                       

   AVK_LOG(chain_result = srv_certman_get_cert_chain_disp_by_id(&job_id,id_details.cert_ids[1], (srv_certman_chain_disp_by_id_cb)avk_security_list_chain_by_id_cb));

    AVK_LOG(private_key    =  srv_certman_get_privkey(&job_id,id_details.cert_ids[1],SRV_CERTMAN_ENC_PK12,(srv_certman_pwd_cb)pwd_cb,(srv_certman_priv_key_cb)priv_key_cb));                            
		                                                                       
		                                                                       
   if (!list_result && !id_result && !chain_result && !private_key)
   {  
   	 result = MMI_TRUE;
   }
  	                                                                        

	return result;

}

void ids_by_grp_cb(S32 a, srv_certman_error_enum b, srv_certman_certid_by_group_struct*c)
{

}

void trstd_cert_by_id_cb(S32 a, srv_certman_error_enum b, srv_certman_trusted_cert_by_id_struct* c)
{

}

void pwd_cb(S32 a, const U8* b, U32 c)
{

}

void priv_key_cb(S32 a, srv_certman_error_enum b, srv_certman_privkey_struct* c)
{
  //mmi_wcscpy((PS8)g_cert_cnt_struct.private_key ,(PS8)c->filename);

}


MMI_BOOL avk_security_list_chain_by_id_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_chain_disp_by_id_struct *cert_list)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (!status)
	   return MMI_TRUE;
   else
	   return MMI_FALSE;


}

MMI_BOOL avk_security_list_by_dmn_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_list_by_domain_struct *cert_list)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (!status)
	   return MMI_TRUE;
   else
	   return MMI_FALSE;


	
}

MMI_BOOL avk_security_list_by_id_cb(S32 job_id,srv_certman_error_enum status,srv_certman_cert_disp_by_id_struct *cert_list)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cert_cnt_struct.job_id=job_id;

   if (!status)
	   return MMI_TRUE;
   else
	   return MMI_FALSE;


	
}


/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_003
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL avk_security_cert_003(void)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
	S32 job_id = 0;
	U16 certi_id_result = 0,trusted_result = 0,verify_id = 0, is_private_key = 0,is_signature = 0;
	MMI_BOOL result = MMI_FALSE;
	srv_certman_cert_ids_result_struct id_details;
	srv_certman_signature_vfy_params_struct sign;
	U8 verified = 0;
	
	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sign.hash_alg = SRV_CERTMAN_SIGNALG_ECDSA_SHA1;

    srv_certman_get_cert_ids_by_type(SRV_CERTMAN_CERTTYPE_X509,&id_details);

   AVK_LOG(certi_id_result  =  srv_certman_get_cert_by_id(&job_id,SRV_CERTMAN_CERTGRP_ANY,SRV_CERTMAN_ENC_UNSUPPORTED,SRV_CERTMAN_KP_NONE,(srv_certman_cert_by_id_cb)ids_by_grp_cb));

   AVK_LOG(trusted_result   =  srv_certman_get_trusted_cert_by_id(&job_id,id_details.cert_ids[2],SRV_CERTMAN_KP_ALL,(srv_certman_trstd_cert_by_id_cb)trstd_cert_by_id_cb));
                          
   AVK_LOG(verify_id    =   srv_certman_util_check_id_as_cert(id_details.cert_ids[0],SRV_CERTMAN_CERTGRP_ANY,SRV_CERTMAN_DOMAIN_ANY,SRV_CERTMAN_KP_ALL));

   AVK_LOG(is_private_key    =  srv_certman_util_check_id_as_privkey(id_details.cert_ids[0]));

   AVK_LOG(is_signature   =  srv_certman_util_signature_verify_by_id(id_details.cert_ids[1],&sign,&verified));

      
  if (!(certi_id_result && trusted_result && !is_private_key && !verify_id && is_signature))
 {
    result = MMI_TRUE;

  }

  return result;



}

/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_004
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL avk_security_cert_004(void)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 job_id;
	U16 key_purpose = 0, del_cert = 0 ,del_cert_grp = 0;
	MMI_BOOL result = MMI_FALSE;
	srv_certman_cert_ids_result_struct id_details;
	//srv_certman_signature_vfy_params_struct sign ;

		  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_LOG(srv_certman_get_cert_ids_by_type(SRV_CERTMAN_CERTTYPE_X509,&id_details));

	AVK_LOG(key_purpose = srv_certman_update_key_purpose(&job_id,id_details.cert_ids[0],SRV_CERTMAN_KP_ALL,(srv_certman_update_key_purpose_cb)avk_security_list_by_dmn_cb));

	AVK_LOG(del_cert = srv_certman_delete_cert(&job_id,id_details.cert_ids[0],(srv_certman_status_cb)pwd_cb));

	AVK_LOG(del_cert_grp =  srv_certman_delete_cert_group(&job_id,SRV_CERTMAN_CERTGRP_ANY,(srv_certman_delete_status_cb)pwd_cb));

	if (!(key_purpose && del_cert && del_cert_grp ))
	{
	   result = MMI_TRUE;
	}
    return result;

}


MMI_BOOL  avk_security_parsed_data_cb(S32 job_id, srv_certman_error_enum result, srv_certman_parsed_data_struct *parse_details)
{

	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/    
    //srv_certman_cert_display_struct cert;
	

	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
  mmi_wcscpy((WCHAR*)g_cert_cnt_struct.issuer,(WCHAR *) (parse_details->cert.issuer.names[0]));
  srv_certman_parse_end(job_id,(srv_certman_parse_end_cb)avk_security_list_by_id_cb);
  return MMI_TRUE;
     
 
}

/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_005
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL avk_security_cert_005(void)
{


	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/    
    S32 job_id;
	U16 parse_start = 0;
	//U16 decrypt ;
    U8 password[32];

	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
	 memset(&g_cert_cnt_struct,0,sizeof(avk_secu_cert_context_struct));
     mmi_wcscpy((WCHAR*)g_cert_cnt_struct.filename ,(WCHAR*)L"D:\\Certi\\wifiuser.pfx");
     mmi_wcscpy((WCHAR*)g_cert_cnt_struct.password ,(WCHAR*)L"wifi");
	 mmi_ucs2_to_asc((char*)password,(char*)g_cert_cnt_struct.password);

	// AVK_LOG(decrypt = srv_certman_util_decrypt_privkey_file(g_cert_cnt_struct.filename,password,32,SRV_CERTMAN_ENC_PEM,(srv_certman_privkey_decrypt_out_cb)avk_security_list_by_grp_cb));

   AVK_LOG(parse_start = srv_certman_parse_start(&job_id,(const kal_wchar *)g_cert_cnt_struct.filename,(U8*)password,(srv_certman_parsed_info_cb)avk_security_parsed_info_cb));
   g_cert_cnt_struct.job_id = job_id;
   
    if (parse_start)
    {
         if ( g_cert_cnt_struct.filename && g_cert_cnt_struct.password)
       {
		  AVK_CASE_RESULT(AVK_PASS);      
       }
       else
       {
          AVK_CASE_RESULT(AVK_FAIL);      
       }

    }
   
   return MMI_TRUE;


}


MMI_BOOL  avk_security_parsed_info_cb(S32 job_id, srv_certman_error_enum result, U16 num_private_keys, srv_certman_parsed_info_struct *parsed_info )
{

	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/   
   U16 parse_details = 0;
 
	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
   g_cert_cnt_struct.cert_count = parsed_info->cert_count;
   g_cert_cnt_struct.cert_id  =  parsed_info->cert_ref_ids[0];

   AVK_LOG(parse_details = srv_certman_parse_detail(job_id,g_cert_cnt_struct.cert_id,(srv_certman_parsed_data_cb)avk_security_parsed_data_cb));
  
   if ( g_cert_cnt_struct.cert_count && g_cert_cnt_struct.cert_id && !parse_details)
  {
	 AVK_CASE_RESULT(AVK_PASS);       
  }
  else
  {
     AVK_CASE_RESULT(AVK_FAIL); 
  }

  return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_006
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_security_cert_006(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/   
   S32 job_id;
   char* none = "None";
  // MMI_BOOL result = MMI_FALSE;
   U16 domain, get_cert_count = 0,validate = 0,ocsp = 0;
   srv_certman_cert_data_struct cert_list;
 
	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
   cert_list.type =  SRV_CERTMAN_CERTTYPE_X509;
   cert_list.data = (void*)none;
   cert_list.size = 32;
  domain  = srv_certman_get_certid_by_domain(&job_id,SRV_CERTMAN_DOMAIN_ANY,SRV_CERTMAN_KP_ALL,0,
	                            (srv_certman_ids_by_dmn_cb)avk_security_list_by_id_cb);

  AVK_LOG(get_cert_count =  srv_certman_get_cert_count(SRV_CERTMAN_CERTGRP_ANY,SRV_CERTMAN_KP_ALL));

  AVK_LOG(validate = srv_certman_validate_cert_list(&job_id,&cert_list,3,SRV_CERTMAN_OCSP_OPT_MUST_PASS,NULL,0,NULL,
	                           (srv_certman_val_result_cb)NULL));

   AVK_LOG(ocsp   =  srv_certman_ocsp_verify_cert(&job_id,NULL,32,NULL,32,SRV_CERTMAN_ENC_PEM,SRV_CERTMAN_OCSP_OPT_MUST_PASS,
				                                                              NULL,0,NULL,NULL));

  if (!(domain && !get_cert_count && !validate && !ocsp ))
  {
	  AVK_CASE_RESULT(AVK_PASS);	   
  }
  else
  {
	  AVK_CASE_RESULT(AVK_FAIL);	   
  }
}




/*****************************************************************************
 * FUNCTION
 *  avk_security_cert_007
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_security_cert_007(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/   
    S32 job_id;
	U16 parse_start = 0;
    U8 password[32];
 
	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/

   	 memset(&g_cert_cnt_struct,0,sizeof(avk_secu_cert_context_struct));
     mmi_wcscpy((WCHAR *)g_cert_cnt_struct.filename ,(WCHAR *)L"D:\\Certi\\wifiuser.pfx");
     mmi_wcscpy((WCHAR *)g_cert_cnt_struct.password ,(WCHAR *)L"wifi");
	 mmi_ucs2_to_asc((CHAR *)password,(CHAR *)g_cert_cnt_struct.password);

	 
    AVK_LOG(parse_start = srv_certman_parse_start(&job_id,(const kal_wchar *)g_cert_cnt_struct.filename,(U8*)password,(srv_certman_parsed_info_cb)avk_security_parsed_info_import_cb));
    g_cert_cnt_struct.job_id = job_id;

    if (parse_start)
    {
	   if (g_cert_cnt_struct.filename &&  g_cert_cnt_struct.password)
	   {
		   AVK_CASE_RESULT(AVK_PASS);			   
	   }
	   else
	   {
		   AVK_CASE_RESULT(AVK_FAIL);		
        }
     }
}

MMI_BOOL  avk_security_parsed_info_import_cb(S32 job_id, srv_certman_error_enum result, U16 num_private_keys, srv_certman_parsed_info_struct *parsed_info )
{

	 /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/   
   U16 import;
   U8 label[10] = {0};
   MMI_BOOL test_certi = MMI_TRUE;
 
	/*----------------------------------------------------------------*/
    /* Code Body                                                                           */
    /*----------------------------------------------------------------*/
   g_cert_cnt_struct.cert_count = parsed_info->cert_count;
   g_cert_cnt_struct.cert_id  =  parsed_info->cert_ref_ids[0];

   import = srv_certman_import(job_id,g_cert_cnt_struct.cert_id ,(const U8 *) &label ,SRV_CERTMAN_DCS_ASCII,SRV_CERTMAN_PROTECT_NONE,NULL,0,
	    (srv_certman_import_cert_cb)avk_security_list_by_grp_cb);

  if (!import ||  test_certi)
  {
	  AVK_CASE_RESULT(AVK_PASS);			  
  }
  else
  {
	  AVK_CASE_RESULT(AVK_FAIL);			  
  }
  return MMI_TRUE;
}


AVK_CASE(AVK_SECU_CERT_CASE1,AVK_SECU_CERT)
{
    avk_security_cert_005();
}

AVK_CASE(AVK_SECU_CERT_CASE2,AVK_SECU_CERT)
{
    avk_security_main();
}

AVK_CASE(AVK_SECU_CERT_CASE6,AVK_SECU_CERT)
{
    avk_security_cert_006();
}

AVK_CASE(AVK_SECU_CERT_CASE7,AVK_SECU_CERT)
{
    avk_security_cert_007();
}



#endif
#endif /* __MAUI_SDK_TEST__ */

