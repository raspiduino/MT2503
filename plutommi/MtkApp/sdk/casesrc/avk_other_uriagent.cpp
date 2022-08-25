
#ifdef __MMI_URI_AGENT__

extern "C"
{
#include "UriAgentSrvGprot.h"
}

extern "C"
{
void dummy_scheme_uri_request_hdlr(srv_uriagent_appid_enum ura_appid, char *url, char *param,
                                                      srv_uriagent_options_enum options,
                                                      srv_uriagent_uri_request_hdlr_cb cb)
{
}

void dummy_prefix_hdlr(srv_uriagent_appid_enum ura_appid, char *url, char *param,
                                                      srv_uriagent_options_enum options,
                                                      srv_uriagent_uri_request_hdlr_cb cb)
{
}

void brwapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid,
                                                  S32 result)
{}

void mmsapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid,
                                                  S32 result)
{}

void smsapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid,
                                                  S32 result)
{}

void unused_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid,
                                                  S32 result)
{}

}

AVK_CASE(AVK_OTHER_URI_001, AVK_OTHER_URI)
{
    AVK_LOG_EX(SRV_URIAGENT_ERR_OK == srv_uriagent_register_hdlr_by_prefix("wtai://wp/er", dummy_prefix_hdlr, MMI_FALSE));
    AVK_LOG_EX(SRV_URIAGENT_ERR_OK == srv_uriagent_register_hdlr_by_scheme("scheme1", dummy_scheme_uri_request_hdlr, MMI_FALSE));
}

AVK_CASE(AVK_OTHER_URI_002, AVK_OTHER_URI)
{
    U32 err_code = 0;
    /* TC-URIAgent-D000: Success to dispatch URI request "scheme:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS, "scheme:ThisIsURL",               SRV_URIAGENT_OPTION_UNSPECIFIED,  NULL);
    /* TC-URIAgent-D001: Success to dispatch URI request "scheme:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS, "scheme:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                smsapp_uri_request_cb);
    /* TC-URIAgent-D002: Success to dispatch URI request "schemeA:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS, "schemeA:ThisIsURL",                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,                NULL);
    /* TC-URIAgent-D003: Success to dispatch URI request "schemeA:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS, "schemeA:ThisIsURL",                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,                mmsapp_uri_request_cb);
    /* TC-URIAgent-D004: Success to dispatch URI request "schemeB:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW, "schemeB:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D005: Success to dispatch URI request "schemeB:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW, "schemeB:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                brwapp_uri_request_cb);
    /* TC-URIAgent-D006: Success to dispatch URI request "scheme:formatThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS, "scheme:formatThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,NULL);
    /* TC-URIAgent-D007: Success to dispatch URI request "scheme:formatThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,  "scheme:formatThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                smsapp_uri_request_cb);
    /* TC-URIAgent-D008: Success to dispatch URI request "scheme:formatAThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,  "scheme:formatAThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D009: Success to dispatch URI request "scheme:formatAThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,  "scheme:formatAThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                mmsapp_uri_request_cb);
    /* TC-URIAgent-D010: Success to dispatch URI request "scheme:formatBThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,  "scheme:formatBThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D011: Success to dispatch URI request "scheme:formatBThisIsURL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,   "scheme:formatBThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                brwapp_uri_request_cb);
    /* TC-URIAgent-D012: Success to dispatch URI request "scheme:formatC This Is URL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   "scheme:formatC This Is URL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D013: Success to dispatch URI request "scheme:formatC This Is URL" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   "scheme:formatC This Is URL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                mmsapp_uri_request_cb);
    /* TC-URIAgent-D014: Success to dispatch URI request "scheme::format This Is URL With Double :" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   "scheme::format This Is URL With Double :",     SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);    
    /* TC-URIAgent-D015: Success to dispatch URI request "scheme::format This Is URL With Double :" from URA to UHA (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   "scheme::format This Is URL With Double :",    SRV_URIAGENT_OPTION_UNSPECIFIED,                smsapp_uri_request_cb);
    /* TC-URIAgent-D100: Fail to dispatch URI request because URL is NULL (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   NULL, SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP, NULL);    
    /* TC-URIAgent-D101: Fail to dispatch URI request beacause URL is NULL (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   NULL,                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,                unused_uri_request_cb);
    /* TC-URIAgent-D102: Fail to dispatch URI request due to unsupported URL "unsupportedscheme:ThisIsURL" (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,   "unsupportedscheme:ThisIsURL", SRV_URIAGENT_OPTION_UNSPECIFIED,NULL);
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,   "unsupportedscheme:ThisIsURL", SRV_URIAGENT_OPTION_UNSPECIFIED,unused_uri_request_cb);
    /* TC-URIAgent-D104: Fail to dispatch URI request due to unsupported URL " scheme:ThisIsURL" (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_EMAIL, " scheme:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D105: Fail to dispatch URI request due to unsupported URL " scheme:ThisIsURL" (callback is not NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_EMAIL, " scheme:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                unused_uri_request_cb);
    /* TC-URIAgent-D200: Success to dispatch URI request "SCHEME:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   "SCHEME:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D201: Success to dispatch URI request "SCHEMEA:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   "SCHEMEA:ThisIsURL",                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,                NULL);
    /* TC-URIAgent-D202: Success to dispatch URI request "schemeb:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,   "schemeb:ThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D203: Success to dispatch URI request "SCHEME:FORMATThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   "SCHEME:FORMATThisIsURL",                SRV_URIAGENT_OPTION_UNSPECIFIED,                NULL);
    /* TC-URIAgent-D204: Success to dispatch URI request "SCHEME:FORMATAThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   "SCHEME:FORMATAThisIsURL",SRV_URIAGENT_OPTION_UNSPECIFIED,  NULL);
    /* TC-URIAgent-D205: Success to dispatch URI request "scheme:formatbThisIsURL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,   "scheme:formatbThisIsURL", SRV_URIAGENT_OPTION_UNSPECIFIED,NULL);
    /* TC-URIAgent-D206: Success to dispatch URI request "SCHEME:formatC This Is URL" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_MMS,   "SCHEME:formatC This Is URL",SRV_URIAGENT_OPTION_UNSPECIFIED,NULL);
    /* TC-URIAgent-D207: Success to dispatch URI request "SCHEME::format This Is URL With Double :" from URA to UHA (callback is NULL) */
    err_code |= srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS,   "SCHEME::format This Is URL With Double :",     SRV_URIAGENT_OPTION_UNSPECIFIED,    NULL);

    AVK_LOG_FUN(srv_uriagent_dispatch_uri_request, SRV_URIAGENT_ERR_OK != err_code);
}

AVK_CASE(AVK_OTHER_URI_003, AVK_OTHER_URI)
{

    //  srv_uriagent_has_registered_hdlr   
    U32 retVal = 0;
    U32 retVal1 = 0;
    U32 retVal2 = 0;
    U32 retVal3 = 0;


    /* TC-URIAgent-C000: Check if any handler is registered to process this URI request: URL is "scheme:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:ThisIsURL");
    /* TC-URIAgent-C001: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With Space " */
    retVal |= srv_uriagent_has_registered_hdlr("scheme: This Is URL With Space ");
    /* TC-URIAgent-C002: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With : And Space" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme: This Is URL With : And Space");
    /* TC-URIAgent-C003: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With ^_^" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme: This Is URL With ^_^");
    /* TC-URIAgent-C004: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With %" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme: This Is URL With %");
    /* TC-URIAgent-C005: Check if any handler is registered to process this URI request: URL is "scheme::This Is URL With Double :" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme::This Is URL With Double :");
    /* TC-URIAgent-C006: Check if any handler is registered to process this URI request: URL is "schemeA:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeA:ThisIsURL");
    /* TC-URIAgent-C007: Check if any handler is registered to process this URI request: URL is "schemeB:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeB:ThisIsURL");
    /* TC-URIAgent-C008: Check if any handler is registered to process this URI request: URL is "scheme:formatThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:formatThisIsURL");
    /* TC-URIAgent-C009: Check if any handler is registered to process this URI request: URL is "scheme:formatAThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:formatAThisIsURL");
    /* TC-URIAgent-C010: Check if any handler is registered to process this URI request: URL is "scheme:formatBThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:formatBThisIsURL");
    /* TC-URIAgent-C011: Check if any handler is registered to process this URI request: URL is "scheme:formatCThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:formatCThisIsURL");
    /* TC-URIAgent-C100: Check if any handler is registered to process this URI request: URL is "schemeC:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeC:ThisIsURL");
    /* TC-URIAgent-C101: Check if any handler is registered to process this URI request: URL is "schemeAB:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeAB:ThisIsURL");
    /* TC-URIAgent-C102: Check if any handler is registered to process this URI request: URL is "schemeBB:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeBB:ThisIsURL");
    /* TC-URIAgent-C103: Check if any handler is registered to process this URI request: URL is "unsupportedscheme:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("unsupportedscheme:ThisIsURL");
    /* TC-URIAgent-C104: Check if any handler is registered to process this URI request: URL is "schemeThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("schemeThisIsURL");
    /* TC-URIAgent-C105: Check if any handler is registered to process this URI request: URL is " " */
    retVal |= srv_uriagent_has_registered_hdlr(" ");
    /* TC-URIAgent-C106: Check if any handler is registered to process this URI request: URL is NULL */
    retVal |= srv_uriagent_has_registered_hdlr(NULL);
    /* TC-URIAgent-C200: Check if any handler is registered to process this URI request: URL is "SCHEME:ThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("SCHEME:ThisIsURL");
    /* TC-URIAgent-C201: Check if any handler is registered to process this URI request: URL is "sChEmE: This Is URL With Space " */
    retVal |= srv_uriagent_has_registered_hdlr("sChEmE: This Is URL With Space ");
    /* TC-URIAgent-C202: Check if any handler is registered to process this URI request: URL is "SCHEME:FORMATThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("SCHEME:FORMATThisIsURL");
    /* TC-URIAgent-C203: Check if any handler is registered to process this URI request: URL is "scheme:FORMATAThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:FORMATAThisIsURL");
    /* TC-URIAgent-C204: Check if any handler is registered to process this URI request: URL is "scheme:formatbThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("scheme:formatbThisIsURL");
    /* TC-URIAgent-C205: Check if any handler is registered to process this URI request: URL is "SCHEME:formatCThisIsURL" */
    retVal |= srv_uriagent_has_registered_hdlr("SCHEME:formatCThisIsURL");


    // set scheme and prefix
    retVal1 |= srv_uriagent_register_hdlr_by_scheme("scheme99", dummy_scheme_uri_request_hdlr, MMI_FALSE);
    retVal1 |= srv_uriagent_register_hdlr_by_scheme("scheme88", dummy_scheme_uri_request_hdlr, MMI_FALSE);
    retVal1 |= srv_uriagent_register_hdlr_by_scheme("scheme77", dummy_scheme_uri_request_hdlr, MMI_FALSE);
    retVal1 |= srv_uriagent_register_hdlr_by_prefix("wtai://wp/cm", dummy_prefix_hdlr, MMI_FALSE);
    retVal1 |= srv_uriagent_register_hdlr_by_prefix("wtai://wp/ds", dummy_prefix_hdlr, MMI_FALSE);
    retVal1 |= srv_uriagent_register_hdlr_by_prefix("wtai://wp/pa", dummy_prefix_hdlr, MMI_FALSE);

    retVal2 |= srv_uriagent_has_registered_hdlr("scheme77:1234567");
    retVal2 |= srv_uriagent_has_registered_hdlr("scheme88:1234567");
    retVal2 |= srv_uriagent_has_registered_hdlr("scheme99:1234567");
    
    retVal3 |= srv_uriagent_has_registered_hdlr("wtai://wp/cm");
    retVal3 |= srv_uriagent_has_registered_hdlr("wtai://wp/ds");
    retVal3 |= srv_uriagent_has_registered_hdlr("wtai://wp/pa");

    AVK_LOG_FUN(srv_uriagent_has_registered_hdlr, 
                    (MMI_FALSE == retVal) &&( SRV_URIAGENT_ERR_OK == retVal1) && ( MMI_FALSE != retVal2 ) &&(MMI_FALSE != retVal3));

}

AVK_CASE(AVK_OTHER_URI_004, AVK_OTHER_URI)
{
    AVK_LOG_EX(srv_uriagent_get_num_of_registered_schemes()>0);
    AVK_LOG_EX(srv_uriagent_get_num_of_registered_prefixes()>0);
    AVK_LOG_EX(NULL != srv_uriagent_get_registered_scheme_by_index(0));
    AVK_LOG_EX(NULL != srv_uriagent_get_registered_prefix_by_index(0));
}

#endif /*__MMI_URI_AGENT__*/