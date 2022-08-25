#ifndef __CSCI_H__
#define __CSCI_H__

#define CSCI_DEFINE_ARR(type,name,size) \
			type name[size] __attribute__((section("csci_static_"#name), zero_init));
			
#define CSCI_DEFINE_VAR(type,name) \
			type name __attribute__((section("csci_static_"#name), zero_init));
			
#define CSCI_EXTERN_ARR(type,name) \
			extern type name[];
			
#define CSCI_EXTERN_VAR(type,name) \
			extern type name;


#define CSCI_ERR_NOT_INITIALIZED    (-1)
#define CSCI_ERR_INVALID_SIZE       (-2)
#define CSCI_ERR_INVALID_ADDR       (-3)
#define CSCI_ERR_INVALID_KEY        (-4)
#define CSCI_ERR_DUP_KEY            (-5)
#define CSCI_ERR_NO_SPACE           (-6)


#endif
