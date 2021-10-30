/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include "cborg/cbor/item.h"

// Create new item
cbor_item_t *cb_cbor_new_item(size_t size_item_data) {
  cbor_item_t *item = malloc(sizeof(cbor_item_t) + size_item_data);
  _CBOR_NOTNULL(item);
  item->mt = CBOR_MT_UINT;
  item->data = (void *)(item + sizeof(cbor_item_t));
  return item;
}

// Get major type of item
uint8_t cb_cbor_item_get_mt(const cbor_item_t *item) { return item->mt; }

// Get major type of item
void cb_cbor_item_set_mt(cbor_item_t *item, cbor_major_type mt) {
  item->mt = mt;
}

// Delete item
void cb_cbor_delete_item(cbor_item_t **item) {
  free(*item);
  *item = NULL;
}
