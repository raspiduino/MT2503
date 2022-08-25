#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>


<APP id = "APP_PACKAGE_CONCURRENT">

  <APPCONCURRENT concurrent_w_order="APP_OPERA, APP_VDOPLY"/>
  <APPCONCURRENT concurrent_w_order="APP_OPERA, APP_MEDPLY"/>
  <APPCONCURRENT concurrent_w_order="APP_OPERA, APP_MEDPLY, APP_VENUS_SCREEN_LOCK_KEY"/>
  <APPCONCURRENT concurrent_w_order="APP_OPERA, APP_VDOPLY, APP_VENUS_SCREEN_LOCK_KEY"/>

#if (defined(__OP01__) && defined(__J2ME__))
  <APPCONCURRENT concurrent ="APP_JAVA, APP_OPERA"/>
#endif
</APP>      
