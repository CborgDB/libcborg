/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <string.h>

#include "cborg/cbor/int.h"
#include "cborg/cbor/item.h"

void _cbor_int_init(cbor_int_t *i, cbor_int_width width, void *pValue);

// New int
cbor_item_t *cb_cbor_new_int8() {
  cbor_item_t *item = cb_cbor_new_item(sizeof(cbor_int_t) + sizeof(uint8_t));
  _cbor_int_init(item->data, CBOR_INT_8,
                 (char *)item->data + sizeof(cbor_int_t));
  return item;
}

cbor_item_t *cb_cbor_new_int16() {
  cbor_item_t *item = cb_cbor_new_item(sizeof(cbor_int_t) + sizeof(uint16_t));
  _cbor_int_init(item->data, CBOR_INT_16,
                 (char *)item->data + sizeof(cbor_int_t));
  return item;
}

cbor_item_t *cb_cbor_new_int32() {
  cbor_item_t *item = cb_cbor_new_item(sizeof(cbor_int_t) + sizeof(uint32_t));
  _cbor_int_init(item->data, CBOR_INT_32,
                 (char *)item->data + sizeof(cbor_int_t));
  return item;
}

cbor_item_t *cb_cbor_new_int64() {
  cbor_item_t *item = cb_cbor_new_item(sizeof(cbor_int_t) + sizeof(uint64_t));
  _cbor_int_init(item->data, CBOR_INT_64,
                 (char *)item->data + sizeof(cbor_int_t));
  return item;
}

void cb_cbor_delete_int(cbor_item_t **item) { cb_cbor_delete_item(item); }

void cb_cbor_mark_uint(cbor_item_t *item) { item->mt = CBOR_MT_UINT; }

void cb_cbor_mark_negint(cbor_item_t *item) { item->mt = CBOR_MT_NEGINT; }

cbor_int_width cb_cbor_int_get_width(const cbor_item_t *item) {
  return ((cbor_int_t *)item->data)->width;
}

// Build
cbor_item_t *cb_cbor_build_uint8(uint8_t value) {
  cbor_item_t *item = cb_cbor_new_int8();
  cb_cbor_set_uint8(item, value);
  return item;
}

cbor_item_t *cb_cbor_build_uint16(uint16_t value) {
  cbor_item_t *item = cb_cbor_new_int16();
  cb_cbor_set_uint16(item, value);
  return item;
}

cbor_item_t *cb_cbor_build_uint32(uint32_t value) {
  cbor_item_t *item = cb_cbor_new_int32();
  cb_cbor_set_uint32(item, value);
  return item;
}

cbor_item_t *cb_cbor_build_uint64(uint64_t value) {
  cbor_item_t *item = cb_cbor_new_int64();
  cb_cbor_set_uint64(item, value);
  return item;
}

// Mutator
void cb_cbor_set_uint8(cbor_item_t *item, uint8_t value) {
  *(uint8_t *)(((cbor_int_t *)item->data)->value) = value;
}

void cb_cbor_set_uint16(cbor_item_t *item, uint16_t value) {
  *(uint16_t *)(((cbor_int_t *)item->data)->value) = value;
}

void cb_cbor_set_uint32(cbor_item_t *item, uint32_t value) {
  *(uint32_t *)(((cbor_int_t *)item->data)->value) = value;
}

void cb_cbor_set_uint64(cbor_item_t *item, uint64_t value) {
  *(uint64_t *)(((cbor_int_t *)item->data)->value) = value;
}

// Accessor
uint8_t cb_cbor_get_uint8(const cbor_item_t *item) {
  return *(uint8_t *)(((cbor_int_t *)item->data)->value);
}

uint16_t cb_cbor_get_uint16(const cbor_item_t *item) {
  return *(uint16_t *)(((cbor_int_t *)item->data)->value);
}

uint32_t cb_cbor_get_uint32(const cbor_item_t *item) {
  return *(uint32_t *)(((cbor_int_t *)item->data)->value);
}

uint64_t cb_cbor_get_uint64(const cbor_item_t *item) {
  return *(uint64_t *)(((cbor_int_t *)item->data)->value);
}

uint64_t cb_cbor_get_uint(const cbor_item_t *item) {
  cbor_int_t *i = (cbor_int_t *)item->data;
  switch (i->width) {
  case CBOR_INT_8:
    return cb_cbor_get_uint8(item);
    break;
  case CBOR_INT_16:
    return cb_cbor_get_uint16(item);
    break;
  case CBOR_INT_32:
    return cb_cbor_get_uint32(item);
    break;
  case CBOR_INT_64:
    return cb_cbor_get_uint64(item);
    break;
  }
}

// Comparator
bool cb_cbor_int_eq(const cbor_item_t *a, const cbor_item_t *b) {
  cbor_int_t *ai = (cbor_int_t *)a->data;
  cbor_int_t *bi = (cbor_int_t *)b->data;
  return (a->mt == b->mt) && (ai->width == bi->width) &&
         memcmp(ai->value, bi->value, ai->width) == 0;
}

bool cb_cbor_int_ne(const cbor_item_t *a, const cbor_item_t *b) {
  return !cb_cbor_int_eq(a, b);
}

bool cb_cbor_int_lt(const cbor_item_t *a, const cbor_item_t *b) {
  if (a->mt == CBOR_MT_UINT && b->mt == CBOR_MT_UINT) {
    return cb_cbor_get_uint(a) < cb_cbor_get_uint(b);
  } else if (a->mt == CBOR_MT_NEGINT && b->mt == CBOR_MT_NEGINT) {
    return cb_cbor_get_uint(a) > cb_cbor_get_uint(b);
  } else {
    return a->mt > b->mt;
  }
}

bool cb_cbor_int_gt(const cbor_item_t *a, const cbor_item_t *b) {
  return !cb_cbor_int_lt(a, b) && !cb_cbor_int_eq(a, b);
}

bool cb_cbor_int_le(const cbor_item_t *a, const cbor_item_t *b) {
  return cb_cbor_int_lt(a, b) || cb_cbor_int_eq(a, b);
}

bool cb_cbor_int_ge(const cbor_item_t *a, const cbor_item_t *b) {
  return cb_cbor_int_gt(a, b) || cb_cbor_int_eq(a, b);
}

// internal
void _cbor_int_init(cbor_int_t *i, cbor_int_width width, void *pValue) {
  i->width = width;
  i->value = pValue;
}
