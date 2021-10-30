/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include "cborg/ds/bloom.h"

bloom_filter_t *cb_ds_bloom_new(uint64_t (*h1)(const void *, size_t),
                                uint64_t (*h2)(const void *, size_t),
                                size_t len) {
  bloom_filter_t *bloom = (bloom_filter_t *)malloc(sizeof(bloom_filter_t));
  bloom->bs = cb_ds_bitset_new(len);
  bloom->len = len;
  bloom->h1 = h1;
  bloom->h2 = h2;
  return bloom;
}

void cb_ds_bloom_delete(bloom_filter_t **bloom) {
  cb_ds_bitset_delete((*bloom)->bs);
  free(*bloom);
  *bloom = NULL;
}

void cb_ds_bloom_insert(bloom_filter_t *bloom, void *buf, size_t len) {
  cb_ds_bitset_set(bloom->bs, bloom->h1(buf, len) % bloom->len, true);
  cb_ds_bitset_set(bloom->bs, bloom->h2(buf, len) % bloom->len, true);
}

bool cb_ds_bloom_get(bloom_filter_t *bloom, void *buf, size_t len) {
  return cb_ds_bitset_test(bloom->bs, bloom->h1(buf, len) % bloom->len) &&
         cb_ds_bitset_test(bloom->bs, bloom->h2(buf, len) % bloom->len);
}
