
/*******
版本号设置变更：
应用版本号的更改，修改文件：\track\cust\cust_inc\track_version.h
TRACK_VER_APP_  表示应用版本
TRACK_VER_PARAMETER_  表示参数版本（一般情况不便，只有需要单独出变更参数升级时需要修改）
TRACK_VER_BASE_ 表示基础版本，基础层未变更的情况无需修改，不修改意味着相同的基础版本支持交互升级
原\make\Verno_GXQ60D_MOD_11B.bld 文件不在需要修改。
******/

/*按目前的格式扩展，每个项目宏下面有3个#define关键字，否则就悲剧       --    chengjun  2016-07-15*/

#if defined (__NT17__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NT17_10_A1DE_D23_F1"
#define _TRACK_VER_APP_         "NT17_10_A1DE_D23_V01"

#elif defined (__NT55__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NT55_10_A1DE_D23_F1"
#define _TRACK_VER_APP_         "NT55_10_A1DE_D23_V01"

#elif defined(__EL100__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "EL100_20_A1DE_D23_F1"
#define _TRACK_VER_APP_         "EL100_20_A1DE_D23_V01"
#elif defined(__NT13V__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NT13V_10_A1AE_D23_F1"
#define _TRACK_VER_APP_         "NT13V_10_A1AE_D23_V01"

#elif defined(__QB200__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "QB200_10_A1DE_D23_F1"
#define _TRACK_VER_APP_         "QB200_10_A1DE_D23_V01_TEST"

#elif defined(__NF2319__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NF2319_10_A1AE_D23_F1"
#define _TRACK_VER_APP_         "NF2319_10_A1AE_D23_V01_TEST"
#elif defined (__NF2318__)
#if defined(__EL100_XYT__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NF2318_XYT_20_A1AE_D23_F1"
#define _TRACK_VER_APP_         "NF2318_XYT_20_A1AE_D23_V17"
#else
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "NF2318_20_A1AE_D23_F1"
#define _TRACK_VER_APP_         "NF2318_20_A1AE_D23_V17"
#endif
#elif defined(__JM10__)
#define _TRACK_VER_PARAMETER_   "R0"
#define _TRACK_VER_BASE_        "JM10_10_A1AE_D23_F1"
#define _TRACK_VER_APP_         "JM10_10_A1AE_D23_V01_TEST"

#else
#error "project_null"
#endif

