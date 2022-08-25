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
 *  xmlgen_test.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  xml generator test file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __XML_SUPPORT__

#include "kal_release.h"        /* Basic data type */
#include "fat_fs.h"
#include "app_buff_alloc.h"

#include "xmlgen.h"
#include "xmlgen_def.h"

#ifdef TEST_XMLGEN
void test_xmlgen(void)
{
    
    XG_HANDLE  hd;
    xg_attr_struct attrlist[2];
    char *data = NULL, *dtd=NULL;
    kal_wchar resultname[128];
    int  ret, len, driver;

    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    kal_wsprintf((kal_uint16*)resultname, "%c:\\xmlsample.txt",driver);    

    hd = xml_new_generator((kal_char*)resultname, 0);
    xml_generate_xmldecl(hd, 0, XML_ENCODING_UTF8);
    xml_generate_doctypedecl(hd, "bookshop", XG_DOCTYPE_SYSTEM, "bookshop.dtd");
    dtd = "<!ELEMENT greeting (#PCDATA)>";
    len = strlen(dtd);
//    xml_generate_doctypedecl_ex(hd, "bookshop", dtd, len);
  
    ret = xml_generate_stag(hd, "bookshop", NULL, 0);  /*  to generate:  <bookshop> */
 
    /* to generate: <book1>this is a book of computer</book1> */

    data = "test data";
    
    ret = xml_generate_inline_element(hd, "book1", data, strlen(data)); 
    

    ret = xml_generate_stag(hd, "contact", NULL, 0);
    
    /* to generate: <address street="Xi Dan Street"/> */
    attrlist[0].attrname = "street";
    attrlist[0].attrvalue = "Xi Dan Street";
    attrlist[1].attrname = "code";
    attrlist[1].attrvalue = "100022";
    ret = xml_generate_empty_element(hd, "address", attrlist, 2);
  
    /* to generate: <email>[![CDATA[bookshop@sohu.com]]></email> */
    ret = xml_generate_stag(hd, "email", NULL, 0);
    data = " bookshop@sohu.com";
    ret = xml_generate_cdata(hd, data, strlen(data));
   
    ret = xml_generate_etag(hd, "email");

    ret = xml_generate_stag(hd, "msn", NULL, 0);
    data = "iamlixia@hotmail.com";
    ret = xml_generate_data(hd, data, strlen(data));
    ret = xml_generate_etag(hd, "msn");
  
    /* to generate: </contact> */
    ret = xml_generate_etag(hd, "contact");
    
    /* to generate: </sample> */
    ret = xml_generate_etag(hd, "bookshop");
  
    xml_close_generator(hd);
}
#endif /* TEST_WBXMLP */
#endif /* #ifdef __XML_SUPPORT__ */


