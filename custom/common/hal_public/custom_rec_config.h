#include "kal_release.h"

#ifndef __CAMERA_RECORDER_CUSTOM_CONFIG__
#define __CAMERA_RECORDER_CUSTOM_CONFIG__

// the number mean how long (in sec) dors the recorder sample a frame
#define RECORDER_TIME_LAPSE_SAMPLE_PERIOD    (1)

#if defined(MT6253) ||defined(MT6252)||defined(MT6253DV)||defined(MT6253D) || defined(MT6252H) || defined(MT6253D)||defined(MT6235)||defined(MT6236)||defined(MT6255)
#define __RECORDER_CUSTOM_CONFIG__
#endif
#define IS_KEY KAL_TRUE;

#define MAX_CUSTOM_REC_CONFIG_TBL_SETTING_NUM    10
#define MAX_CUSTOM_REC_CONFIG_TBL_CONFIG_NUM     20


#define SETTING_SET_START(idx) \
    i = ##idx##; j = 0;
#define SETTING_SET_END(idx) \
    i++;
#define SETTING_SET_ELEMENT(s,v) \
    custom_rec_config_table[i][j] = SETTING_CONFIG_##s##_##v##; \
    custom_rec_config_setting_table[SETTING_CONFIG_SETTING_##s##].type = SETTING_CONFIG_TYPE_DEPENDED; \
    custom_rec_config_setting_table[SETTING_CONFIG_SETTING_##s##].index = j; \
    if(i == 0)     custom_rec_config_table_real_col_num++; \
    if(j == 0)     custom_rec_config_table_real_row_num++; \
    if(i != 0)     ASSERT(j < custom_rec_config_table_real_col_num); \
    if(j == 0)     ASSERT(custom_rec_config_table_real_row_num < MAX_CUSTOM_REC_CONFIG_TBL_CONFIG_NUM); \
    j++;         
    
#define SETTING_SET_KEY_ELEMENT(s,v,k) \
    custom_rec_config_table[i][j] = SETTING_CONFIG_##s##_##v##; \
    ASSERT(custom_rec_config_table_key_col == -1 || custom_rec_config_table_key_col == j); \
    custom_rec_config_table_key_col = j; \
    custom_rec_config_setting_table[SETTING_CONFIG_SETTING_##s##].type = SETTING_CONFIG_TYPE_KEY; \
    custom_rec_config_setting_table[SETTING_CONFIG_SETTING_##s##].index = j; \
    custom_rec_config_table_free_style = KAL_FALSE; \
    if(i == 0)     custom_rec_config_table_real_col_num++; \
    if(j == 0)     custom_rec_config_table_real_row_num++; \
    if(i != 0)     ASSERT(j < custom_rec_config_table_real_col_num); \
    if(j == 0)     ASSERT(custom_rec_config_table_real_row_num < MAX_CUSTOM_REC_CONFIG_TBL_CONFIG_NUM); \
    j++;      


typedef enum
{

  SETTING_CONFIG_QTY_FINE,
  SETTING_CONFIG_QTY_GOOD,
  SETTING_CONFIG_QTY_NORMAL,    
  SETTING_CONFIG_QTY_LOW,  
  SETTING_CONFIG_QTY_LCD,    
  
  SETTING_CONFIG_CODEC_MP4,
  SETTING_CONFIG_CODEC_3GP,
  SETTING_CONFIG_CODEC_MJPG,    
  SETTING_CONFIG_CODEC_H264,      
  
  SETTING_CONFIG_RESOLUTION_SQCIF,
  SETTING_CONFIG_RESOLUTION_QQVGA,       
  SETTING_CONFIG_RESOLUTION_QCIF,
  SETTING_CONFIG_RESOLUTION_QVGA,
  SETTING_CONFIG_RESOLUTION_CIF,
  SETTING_CONFIG_RESOLUTION_WQVGA,       
  SETTING_CONFIG_RESOLUTION_CIF2, 
  SETTING_CONFIG_RESOLUTION_HVGA,           
  SETTING_CONFIG_RESOLUTION_NHD,        
  SETTING_CONFIG_RESOLUTION_VGA,
  SETTING_CONFIG_RESOLUTION_4CIF,  
  SETTING_CONFIG_RESOLUTION_D1,    
  SETTING_CONFIG_RESOLUTION_D12,       
  SETTING_CONFIG_RESOLUTION_WVGA,      
  SETTING_CONFIG_RESOLUTION_SVGA,    
  SETTING_CONFIG_RESOLUTION_WVGA2,  
  SETTING_CONFIG_RESOLUTION_FWVGA,    
  SETTING_CONFIG_RESOLUTION_XGA,
  SETTING_CONFIG_RESOLUTION_720P,
  SETTING_CONFIG_RESOLUTION_4VGA,
  SETTING_CONFIG_RESOLUTION_SXGA,
  SETTING_CONFIG_RESOLUTION_16CIF,
  SETTING_CONFIG_RESOLUTION_4SVGA,
  SETTING_CONFIG_RESOLUTION_FHD, 
  SETTING_CONFIG_RESOLUTION_WALLPAPER, 

  SETTING_CONFIG_STORAGE_PHONE,  
  SETTING_CONFIG_STORAGE_CARD,  

  /* add new seeting before this */
  SETTING_CONFIG_VALUE,
    
  SETTING_CONFIG_VALUE_END  
  
} recoorder_config_setting_value;  

typedef enum
{
  SETTING_CONFIG_SETTING_QTY,
  SETTING_CONFIG_SETTING_CODEC,
  SETTING_CONFIG_SETTING_RESOLUTION,
  SETTING_CONFIG_SETTING_STORAGE,  

    
  /*add new setting before this */    
  SETTING_CONFIG_TARGET_END,
    
  SETTING_CONFIG_TARGET_NONE    
  
} recoorder_config_setting_target;   
 
typedef enum
{
  SETTING_CONFIG_TYPE_KEY,
  SETTING_CONFIG_TYPE_DEPENDED,
  SETTING_CONFIG_TYPE_VALUE,           
  
  SETTING_CONFIG_TYPE_END
  
} recoorder_config_setting_type;  

typedef struct
{
    recoorder_config_setting_type type;
    kal_int32 index;        
}recoorder_config_setting_table_element;

typedef struct
{
  recoorder_config_setting_target target[MAX_CUSTOM_REC_CONFIG_TBL_SETTING_NUM];    
  recoorder_config_setting_value value[MAX_CUSTOM_REC_CONFIG_TBL_CONFIG_NUM];
  kal_uint32 count;
  
} recoorder_config_setting_set;  
 
static recoorder_config_setting_value custom_rec_config_table[MAX_CUSTOM_REC_CONFIG_TBL_CONFIG_NUM][MAX_CUSTOM_REC_CONFIG_TBL_SETTING_NUM];
static kal_uint32 custom_rec_config_table_real_col_num = 0;
static kal_uint32 custom_rec_config_table_real_row_num = 0;
static kal_int32 custom_rec_config_table_key_col = -1;
static kal_bool custom_rec_config_table_free_style = KAL_TRUE;
static recoorder_config_setting_table_element custom_rec_config_setting_table[SETTING_CONFIG_TARGET_END];

#ifdef __cplusplus
extern "C"
{
#endif
extern void custom_rec_init_table(void);
extern void custom_rec_set_table(void);
extern kal_bool recorder_config_has_dependency(void);
extern kal_bool recorder_config_is_depended(recoorder_config_setting_target target);
extern kal_bool recorder_config_is_key(recoorder_config_setting_target target);
extern recoorder_config_setting_target recorder_config_get_key(void);
extern recoorder_config_setting_value recorder_config_get_default_key_value(void);
extern void recorder_config_get_setting_set(recoorder_config_setting_value key_value, recoorder_config_setting_set* set);
extern recoorder_config_setting_value recorder_config_get_setting(recoorder_config_setting_value key_value, recoorder_config_setting_target target);

#ifdef __cplusplus
}
#endif

#endif
