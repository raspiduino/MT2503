/* AVK by Jianhua Zhao*/
#include "MMI_features.h"

#ifdef __MMI_USB_SUPPORT__

extern "C"
{
#include "mmi_cb_mgr_gprot.h"
#include "MMIDataType.h"
#include "USBSrvGprot.h"
#include "USBSrvIprot.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "mmi_rp_app_usbsrv_def.h"
}

static void avk_device_usb_manual_pass(void)
{
    AVK_LOG(MMI_TRUE);
}

static void avk_device_usb_manual_fail(void)
{
    AVK_LOG(MMI_FALSE);
}

/* Auto cases*/
AVK_ADD_ITEM(AVK_DEVICE_USB_AUTO, L"USB auto case", AVK_DEVICE_USB);

AVK_CASE(AVK_DEVICE_USB_CASE_AUTO, AVK_DEVICE_USB_AUTO)
{
    AVK_LOG(srv_usb_check_path_exported((WCHAR*)L"Z:\\test") == MMI_TRUE);
}

/* Manual cases*/
//AVK_ADD_ITEM(AVK_DEVICE_USB_MANUAL, L"USB manual cases", AVK_DEVICE_USB);

AVK_ADD_ITEM_SPECIAL(AVK_DEVICE_USB_SPEC1, L"srv_usb_is_connected", AVK_DEVICE_USB);
AVK_SPECIAL_CASE(AVK_DEVICE_USB_SPEC1_CASE, AVK_DEVICE_USB_SPEC1)
{
    WCHAR *str;
    
    if (srv_usb_is_connected())
    {
        str = (WCHAR*)L"If USB cable is connected, this case pass";
    }
    else
    {
        str = (WCHAR*)L"If USB cable is not connected, this case pass";
    }
    AVK_MANU_SHOW_TIPS(str, NULL);
}

static void avk_device_usb_manal_002_tips_lsk(void)
{
    WCHAR *str;
    
    if (srv_usb_is_in_mass_storage_mode())
    {
        str = (WCHAR*)L"If in Mass storage mode now, this case pass";
    }
    else
    {
        str = (WCHAR*)L"If not in Mass storage mode now, this case pass";
    }
    AVK_MANU_SHOW_TIPS(str, NULL);
}

AVK_ADD_ITEM_SPECIAL(AVK_DEVICE_USB_SPEC2, L"srv_usb_is_in_mass_storage_mode", AVK_DEVICE_USB);
AVK_SPECIAL_CASE(AVK_DEVICE_USB_SPEC2_CASE, AVK_DEVICE_USB_SPEC2)
{
    AVK_MANU_SHOW_TIPS(L"Please insert USB and enter Mass storage", 
        avk_device_usb_manal_002_tips_lsk);
}

static void avk_device_usb_manal_003_tips_lsk(void)
{
    WCHAR *str;
    
    if (srv_usb_is_in_mass_storage_mode_ext())
    {
        str = (WCHAR*)L"If in Mass storage mode now, this case pass";
    }
    else
    {
        str = (WCHAR*)L"If not in Mass storage mode now, this case pass";
    }
    AVK_MANU_SHOW_TIPS(str, NULL);
}

AVK_ADD_ITEM_SPECIAL(AVK_DEVICE_USB_SPEC3, L"srv_usb_is_in_mass_storage_mode_ext", AVK_DEVICE_USB);
AVK_SPECIAL_CASE(AVK_DEVICE_USB_SPEC3_CASE, AVK_DEVICE_USB_SPEC3)
{
    AVK_MANU_SHOW_TIPS(L"Please insert USB and enter Mass storage", 
        avk_device_usb_manal_003_tips_lsk);
}


static U8 ms_unblock;

static void avk_device_usb_manal_004_contiue_lsk(void)
{
    kal_prompt_trace(MOD_MMI, "[AVK USB]avk_device_usb_manal_004_contiue_lsk" );
    ms_unblock = 1;
    srv_usb_unblock_event(EVT_ID_USB_ENTER_MS_MODE);
}

static mmi_ret avk_device_usb_ms_cb (mmi_event_struct *param)
{
    kal_prompt_trace(MOD_MMI, "[AVK USB]avk_device_usb_ms_cb" );
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_frm_group_close(GRP_ID_USB_MMI);
#else
	mmi_frm_group_close(VAPP_USBMMI);
#endif
    srv_usb_block_event(EVT_ID_USB_ENTER_MS_MODE);
    AVK_MANU_SHOW_TIPS(L"If not enter Mass storage mode yet, srv_usb_block_event case pass.\r\n After press Ok, if enter Mass storage mode successfully, srv_usb_unblock_event case pass", 
        avk_device_usb_manal_004_contiue_lsk);

    return MMI_RET_OK;
}

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
#endif

static mmi_ret avk_device_usb_config_rsp_cb (mmi_event_struct *param)
{
    srv_usb_config_result_struct *rsp = (srv_usb_config_result_struct*)param->user_data;

    kal_prompt_trace(MOD_MMI, "[AVK USB]avk_device_usb_config_rsp_cb, mode=%d", rsp->mode);
    
    if (rsp->mode == DEVUSB_CFG_ACTION_MASS_STORAGE)
    {
        //StartTimer(USB_AVK_CASE_TIMER, 100, avk_device_usb_config_rsp_timer_hdlr);
    }

    return MMI_RET_OK;
}

static void avk_device_usb_manal_004_tips_lsk(void)
{
    kal_prompt_trace(MOD_MMI, "[AVK USB]avk_device_usb_manal_004_tips_lsk" );
}

AVK_ADD_ITEM_SPECIAL(AVK_DEVICE_USB_SPEC4, L"srv_usb_block_event&srv_usb_unblock_event", AVK_DEVICE_USB);
AVK_SPECIAL_CASE(AVK_DEVICE_USB_SPEC4_CASE, AVK_DEVICE_USB_SPEC4)
{
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, avk_device_usb_ms_cb, NULL);
    mmi_frm_cb_reg_event(EVT_ID_USB_MMI_NOTIFY, avk_device_usb_config_rsp_cb, NULL);
    ms_unblock = 0;
    AVK_MANU_SHOW_TIPS(L"Please press Ok, then re-insert USB and select Mass storage to do this test", 
        avk_device_usb_manal_004_tips_lsk);
}


#endif

