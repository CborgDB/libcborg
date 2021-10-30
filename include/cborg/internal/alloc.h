/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_INTERNAL_ALLOC_H
#define _CBORG_INTERNAL_ALLOC_H

#include <stdlib.h>

int cb_malloc(size_t size, void *retp);

int cb_calloc(size_t size, size_t count, void *p);

void cb_free(void *p);

#endif
