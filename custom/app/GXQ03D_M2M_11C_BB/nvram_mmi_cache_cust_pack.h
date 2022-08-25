#ifndef NVRAM_NOT_PRESENT                                             
#ifndef NVRAM_AUTO_GEN                                             
#error "nvram_auto_gen fail!"                                      
#endif                                                             
const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[NVRAM_CACHE_SIZE];		
const kal_uint8 NVRAM_CACHE_SHORT_DEFAULT[NVRAM_CACHE_SIZE];		
const kal_uint8 NVRAM_CACHE_DOUBLE_DEFAULT[NVRAM_CACHE_SIZE];		
#endif                                                             
