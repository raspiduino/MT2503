#ifndef __AP_CSCI_DYMAMIC_H__
#define __AP_CSCI_DYMAMIC_H__

#include <stddef.h>
#include "csci.h"

int csci_alloc(size_t, char*, void**);
int csci_free(void*);
void* csci_addr(char*);
int csci_size(void*);

#endif /* __AP_CSCI_DYMAMIC_H__*/