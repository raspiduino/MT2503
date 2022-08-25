ELFConvert.exe   -iv mre10   -i "QQ2009.vxp"  -o "mre_app_qq2009.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "qq2010.vxp"  -o "mre_app_qq2010.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "QQBrowser.vxp"  -o "mre_app_qqbrowser.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "YahooM800.vxp"  -o "mre_app_yahoo_800.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "YahooM1000.vxp"  -o "mre_app_yahoo_1000.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "OperaMini.vxp"  -o "mre_app_opera.vxp"  -s -c
ELFConvert.exe   -iv mre10   -i "QQsm.vsm"  -o "mre_qq_sm.vsm"  -s -c
dump mre_app_qq2009.vxp >> mre_app_qq2009.txt
dump mre_app_qq2010.vxp >> mre_app_qq2010.txt
dump mre_app_qqbrowser.vxp >> mre_app_qqbrowser.txt
dump mre_app_yahoo_800.vxp >> mre_app_yahoo_800.txt
dump mre_app_yahoo_1000.vxp >> mre_app_yahoo_1000.txt
dump mre_app_opera.vxp >> mre_app_opera.txt
dump mre_qq_sm.vsm >> mre_qq_sm.txt
