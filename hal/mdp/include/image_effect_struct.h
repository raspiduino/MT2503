#ifndef __IMAGE_EFFECT_STRUCTURE_H__
#define __IMAGE_EFFECT_STRUCTURE_H__

#include "kal_general_types.h"
#include "drv_comm.h"
#include "img_common_enum.h"

#if(!defined(IMGDMA_IBW_OUTPUT_RGB565))
#define IMGDMA_IBW_OUTPUT_RGB565    0x00000000
#endif

#if(!defined(IMGDMA_IBW_OUTPUT_RGB888))
#define IMGDMA_IBW_OUTPUT_RGB888    0x00000040
#endif

typedef enum{
  IBR1_TYPE_RGB565,
  IBR1_TYPE_RGB888
}IMGDMA_DATA_TYPE_ENUM;

typedef enum{
  IBR1_ORDER_BGR888,
  IBR1_ORDER_RGB888
}IMGDMA_DATA_ORDER_ENUM;

typedef struct
{
  /* The following 5 variables are used for legacy_IPP */
  IMGDMA_DATA_TYPE_ENUM data_type; /**< RGB565 or RGB888, used for legacy_IPP */
  IMGDMA_DATA_ORDER_ENUM data_order; /**< BGR888 or RGB888, used for legacy_IPP */
  
  //kal_uint8 src_color_mode; /* IPP_COLOR_RGB565 or IPP_COLOR_RGB888, used for legacy_IPP */
  //kal_uint8 src_color_order; /* BGR888 or RGB888, used for legacy_IPP */
  kal_uint8 dest_color_mode; /**< IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888, used for legacy_IPP */


  img_color_fmt_rgb_enum_t src_color_fmt;
  img_color_fmt_rgb_enum_t dest_color_fmt;
  
  /* source buffer address for image input */
  kal_uint32 source_buffer_address;
  
  /* first destination buffer address for image output */
  kal_uint32 dest1_buffer_address;
  kal_uint32 dest1_buffer_size;
  
  /* second destination buffer address for temporary image */
  kal_uint32 dest2_buffer_address;
  kal_uint32 dest2_buffer_size;
  
  /* image width for image effect processing */
  kal_uint16 image_width;
  
  /* image height for image effect processing */
  kal_uint16 image_height;
  
  /* one of the special effect enum */
  kal_uint8 effect_index;
  
  /* level of adjustment effect */
  kal_uint16 adj_level;
  
  /* call back function for iamge effect */
  void (*image_effect_dec_cb)(kal_uint8 return_code);
} IMAGE_EFFECT_DEC_STRUCT;


#endif //__IMAGE_EFFECT_STRUCTURE_H__
