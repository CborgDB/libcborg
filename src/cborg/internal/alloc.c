/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <stdio.h>

#include "cborg/internal/alloc.h"
#include "cborg/internal/error.h"

int cb_malloc(size_t size, void *retp) {
  void *p;
  *(void **)retp = NULL;
  if ((p = malloc(size)) == NULL) {
    cb_error();
    return -1;
  }
  *(void **)retp = p;
  return 0;
}

int cb_calloc(size_t size, size_t count, void *retp) {
  void *p;
  *(void **)retp = NULL;
  if ((p = calloc(count, size)) == NULL) {
    cb_error();
    return -1;
  }
  *(void **)retp = p;
  return 0;
}

void cb_free(void *p) { free(p); }
