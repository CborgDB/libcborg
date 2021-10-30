/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include "cborg/cbor/string.h"

cbor_item_t *cb_cbor_new_string() { return NULL; }

cbor_item_t *cb_cbor_delete_string() { return NULL; }

char *cb_cbor_get_string(cbor_item_t *item) {
  return ((cbor_string_t *)(item->data))->chunks;
}

// Comparator
bool cb_cbor_string_eq(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}

bool cb_cbor_string_ne(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}

bool cb_cbor_string_lt(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}

bool cb_cbor_string_gt(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}

bool cb_cbor_string_le(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}

bool cb_cbor_string_ge(const cbor_item_t *a, const cbor_item_t *b) {
  return false;
}
