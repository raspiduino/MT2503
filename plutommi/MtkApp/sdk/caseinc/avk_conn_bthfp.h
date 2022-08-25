#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#define VS_BTHFP_OPTOIN_SIZE 10

typedef enum 
{
    VS_BTHFP_ITEM_PREPARE,
    VS_BTHFP_ITEM_START,
    VS_BTHFP_ITEM_DO,
    VS_BTHFP_ITEM_ABT,
    VS_BTHFP_ITEM_FINISH,
    VS_BTHFP_ITEM_TEST_ALL
}vs_bthfp_menu_item;

extern void vs_bthfp_entry_scr(void);

extern void vs_bthfp_prepare(void);
extern void vs_bthfp_start(void);
extern void vs_bthfp_do(void);
extern void vs_bthfp_abt(void);
extern void vs_bthfp_finish(void);
extern void vs_bthfp_test_all(void);

#endif /* __MAUI_SDK_TEST__ */


