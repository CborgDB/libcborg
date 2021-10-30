/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "cborg/ds/bloom.h"
#include "cborg/hash.h"

void test_cb_bloom_new() {
  bloom_filter_t *b1 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  assert(b1->len == 1000);
  cb_ds_bloom_delete(&b1);

  bloom_filter_t *b2 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 5);
  assert(b2->len == 5);
  cb_ds_bloom_delete(&b2);
}

void test_cb_bloom_delete() {
  bloom_filter_t *b1 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  assert(b1 != NULL);
  cb_ds_bloom_delete(&b1);
  assert(b1 == NULL);

  bloom_filter_t *b2 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 5);
  assert(b2 != NULL);
  cb_ds_bloom_delete(&b2);
  assert(b2 == NULL);
}

void test_cb_bloom_insert() {
  bloom_filter_t *b1 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  cb_ds_bloom_insert(b1, "hello", 6);
  cb_ds_bloom_insert(b1, "hello world!", 12);
  // TODO: Test hash equal true in b1->array
  cb_ds_bloom_delete(&b1);
}

void test_cb_bloom_get() {
  bloom_filter_t *b1 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  cb_ds_bloom_insert(b1, "hello", 6);
  cb_ds_bloom_insert(b1, "hello world!", 12);
  assert(cb_ds_bloom_get(b1, "hello", 6) == true);
  assert(cb_ds_bloom_get(b1, "hello world!", 12) == true);
  cb_ds_bloom_delete(&b1);
}

int main() {
  test_cb_bloom_new();
  test_cb_bloom_delete();
  test_cb_bloom_insert();
  test_cb_bloom_get();
  return EXIT_SUCCESS;
}
