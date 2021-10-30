/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_ITEM_H
#define _CBORG_CBOR_ITEM_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "cborg/cbor/types.h"

#define _CBOR_NOTNULL(cbor_item)                                               \
  do {                                                                         \
    if (cbor_item == NULL) {                                                   \
      return NULL;                                                             \
    }                                                                          \
  } while (0)

// Create new item
cbor_item_t *cb_cbor_new_item();

// Get major type of item
uint8_t cb_cbor_item_get_mt(const cbor_item_t *item);

// Get major type of item
void cb_cbor_item_set_mt(cbor_item_t *item, cbor_major_type mt);

// Delete item
void cb_cbor_delete_item(cbor_item_t **item);

#endif
