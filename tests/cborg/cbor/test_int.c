/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "cborg/cbor/int.h"

void test_cbor_new_int8() {
  cbor_item_t *item = cb_cbor_new_int8();
  assert(item != NULL);
  assert(item->mt == CBOR_MT_UINT);

  cbor_int_t *i = (cbor_int_t *)item->data;
  assert(i->width == CBOR_INT_8);

  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_new_int16() {
  cbor_item_t *item = cb_cbor_new_int16();
  assert(item != NULL);
  assert(item->mt == CBOR_MT_UINT);

  cbor_int_t *i = (cbor_int_t *)item->data;
  assert(i->width == CBOR_INT_16);

  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_new_int32() {
  cbor_item_t *item = cb_cbor_new_int32();
  assert(item != NULL);
  assert(item->mt == CBOR_MT_UINT);

  cbor_int_t *i = (cbor_int_t *)item->data;
  assert(i->width == CBOR_INT_32);

  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_new_int64() {
  cbor_item_t *item = cb_cbor_new_int64();
  assert(item != NULL);
  assert(item->mt == CBOR_MT_UINT);

  cbor_int_t *i = (cbor_int_t *)item->data;
  assert(i->width == CBOR_INT_64);

  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_delete_int() {
  cbor_item_t *item = cb_cbor_new_int64();
  assert(item != NULL);
  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_mark_uint() {
  cbor_item_t *item = cb_cbor_new_int64();
  assert(item != NULL);
  assert(item->mt== CBOR_MT_UINT);
  cb_cbor_mark_negint(item);
  assert(item->mt== CBOR_MT_NEGINT);
  cb_cbor_mark_uint(item);
  assert(item->mt== CBOR_MT_UINT);
  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_mark_negint() {
  cbor_item_t *item = cb_cbor_new_int64();
  assert(item != NULL);
  assert(item->mt== CBOR_MT_UINT);
  cb_cbor_mark_negint(item);
  assert(item->mt== CBOR_MT_NEGINT);
  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

void test_cbor_build_uint8() {
  cbor_item_t *item = cb_cbor_build_uint8(5);
  assert(cb_cbor_get_uint8(item) == 5);
  cb_cbor_delete_int(&item);

  cbor_item_t *item2 = cb_cbor_build_uint8(100);
  assert(cb_cbor_get_uint8(item2) == 100);
  cb_cbor_delete_int(&item2);
}

void test_cbor_build_uint16() {
  cbor_item_t *item = cb_cbor_build_uint16(1000);
  assert(cb_cbor_get_uint16(item) == 1000);
  cb_cbor_delete_int(&item);
}

void test_cbor_build_uint32() {
  cbor_item_t *item = cb_cbor_build_uint32(1048576);
  assert(cb_cbor_get_uint32(item) == 1048576);
  cb_cbor_delete_int(&item);

}

void test_cbor_build_uint64() {
  cbor_item_t *item = cb_cbor_build_uint64(8589934592);
  assert(cb_cbor_get_uint64(item) == 8589934592);
  cb_cbor_delete_int(&item);
}

void test_cbor_set_uint8() {
  cbor_item_t *item = cb_cbor_new_int64();
  assert(item != NULL);
  assert(item->mt== CBOR_MT_UINT);
  cb_cbor_set_uint8(item, 150);
  assert(cb_cbor_get_uint8(item) == 150);
  cb_cbor_set_uint8(item, 99);
  assert(cb_cbor_get_uint8(item) == 99);
  cb_cbor_delete_int(&item);
  assert(item == NULL);
}

// TODO
void test_cbor_set_uint16() {}

// TODO
void test_cbor_set_uint32() {}

// TODO
void test_cbor_set_uint64() {}

// TODO
void test_cbor_get_uint8() {}

// TODO
void test_cbor_get_uint16() {}

// TODO
void test_cbor_get_uint32() {}

// TODO
void test_cbor_get_uint64() {}

void test_cbor_int_eq() {
  // test eq
  cbor_item_t *a = cb_cbor_build_uint8(16);
  cbor_item_t *b = cb_cbor_build_uint8(16);
  assert(cb_cbor_int_eq(a,b));
  cb_cbor_delete_int(&a);
  cb_cbor_delete_int(&b);

  // test type not eq
  cbor_item_t *c = cb_cbor_build_uint8(16);
  cbor_item_t *d = cb_cbor_build_uint16(16);
  assert(!cb_cbor_int_eq(c,d));
  cb_cbor_delete_int(&c);
  cb_cbor_delete_int(&d);

  // test eq on same value but not major type
  cbor_item_t *e = cb_cbor_build_uint8(16);
  cbor_item_t *f = cb_cbor_build_uint8(16);
  cb_cbor_mark_negint(f);
  assert(!cb_cbor_int_eq(e,f));
  cb_cbor_delete_int(&e);
  cb_cbor_delete_int(&f);
}

// TODO
void test_cbor_int_ne() {}

// TODO
void test_cbor_int_lt() {}

// TODO
void test_cbor_int_gt() {}

// TODO
void test_cbor_int_le() {}

// TODO
void test_cbor_int_ge() {}

int main() {
  // NEW
  test_cbor_new_int8();
  test_cbor_new_int16();
  test_cbor_new_int32();
  test_cbor_new_int64();

  // DELETE
  test_cbor_delete_int();

  // MARK
  test_cbor_mark_uint();
  test_cbor_mark_negint();

  //BUILD
  test_cbor_build_uint8();
  test_cbor_build_uint16();
  test_cbor_build_uint32();
  test_cbor_build_uint64();

  // SET
  test_cbor_set_uint8();
  test_cbor_set_uint16();
  test_cbor_set_uint32();
  test_cbor_set_uint64();

  // GET
  test_cbor_get_uint8();
  test_cbor_get_uint16();
  test_cbor_get_uint32();
  test_cbor_get_uint64();

  // COMPARATOR
  test_cbor_int_eq();
  test_cbor_int_ne();
  test_cbor_int_lt();
  test_cbor_int_gt();
  test_cbor_int_le();
  test_cbor_int_ge();

  return EXIT_SUCCESS;
}
