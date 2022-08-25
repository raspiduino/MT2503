no_loadfile = ["hwkb_fullscreen_top1.xml", "hwkb_halfscreen_top.xml","hwkb_halfscreen_bottom.xml",
               "hwkb_fullscreen_top2.xml","hwkb_fullscreen_top1.xml","hwkb_fullscreen_land_revise.xml",
               "hwkb_fullscreen_bottom.xml","hwkb_fullscreen.xml", "skb_popup_phn_key1.xml",
               "skb_popup_phn_key1.xml", "skb_popup_phn_key2.xml", "skb_popup_phn_key3.xml",
               "skb_popup_phn_key4.xml", "skb_popup_phn_key5.xml", "skb_popup_phn_key6.xml",
               "skb_popup_phn_key7.xml", "skb_popup_phn_key8.xml", "skb_popup_phn_key9.xml",
               "skb_qwerty_land_doublehw.xml", "skb_qwerty_land_fullhw.xml"]

#hw will use skb_phn_template               
matrixPrefix = ["skb_phn"]  

#skb_popup_*.xml will use skb_qwerty_template
qwertyPrefix = ["skb_qwerty", "skb_special_alpha_"]
miniKeyboardMapping = {"pl-PL":"polish", "lv-LV":"lv", "lt-LT":"lt", "km-IN":"khmer", "ig-NG":"igbo", 
                       "ha-HA":"hausa", "ca-CA":"ca", "ar-SA":"ar", "uk-UA":"uk", "ta-IN":"ru",
                       "sr-SR":"ru", "ru-RU":"ru", "mo-MD":"ru", "bg-BG":"ru", "my-ZA":"za"} #lv->latvian, lt->lithuanian, ca->catalan, ar->arabic

handwritingPrefix = ["hwkb_"] 

dialerSearchPrefix = ["skb_template_dialer", "skb_dialer"]

#handwriting need skb_phn_symbol(foreign and chinese) when no vk
matrixSymbolPrefix = ["skb_phn_symbol"]

#when only support hw, no need to gen stroke 
strokeSymbolPrefix = "skb_stroke" 

#if support matrix and qwerty, no need to parse skb_phn_123sym_*.xml
symbol123Prefix = "skb_phn_123sym" 