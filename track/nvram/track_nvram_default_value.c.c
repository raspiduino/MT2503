
#include "kal_general_types.h"
#include "nvram_data_items.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"

#include "track_nvram_struct.c"

#include "track_version.h"

/*


特别注意-----  如果需要对终端做FOTA升级，特别要留意本文件的NVRAM默认参数，升级前、后两个版本的该文件必须一致
包括函数和变量名字都不可以修改


MagicNing 2014-03-29
*/

//#pragma arm section rodata = "TRACK_NVRAM_RODATA"

const nvram_gps_backup_data_param_struct NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT[] =
{
    {
        1,
        1
    }
};



const nvram_check_ota_struct NVRAM_EF_CHECK_OTA_DEFAULT[] =
{
    {
        0,
        0,
        0,
        {0},
        {0},
        {"dev.jimicloud.com"},
        12283,
        {0},
        0,
        0,
        50,
        10
    }
};



//const kal_uint8 tmptmp_gsadasda_tmp[12288] = {0};

//#pragma arm section rodata

