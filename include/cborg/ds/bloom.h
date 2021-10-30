/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_BLOOM_H
#define _CBORG_BLOOM_H

#include <stdbool.h>
#include <stdlib.h>

#include "cborg/ds/bitset.h"

/**
 *  @file   bloom.h
 *  @brief  Bloom filter
 *  @author Adil Benhlal
 *  @date   2021-06-29
 */

/**
 *  TODO: see the document below to make the bloom filter more efficient with
 * two hash functions
 * - link: https://www.eecs.harvard.edu/~michaelm/postscripts/rsa2008.pdf
 */

typedef struct bloom_filter_t {
  uint64_t (*h1)(const void *, size_t);
  uint64_t (*h2)(const void *, size_t);
  size_t len;
  bitset_t *bs;
} bloom_filter_t;

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
bloom_filter_t *cb_ds_bloom_new(uint64_t (*h1)(const void *, size_t),
                                uint64_t (*h2)(const void *, size_t),
                                size_t len);

/**
 * @brief Free bloom filter
 * @param bloom Hash function 1
 * @see cb_ds_bloom_new
 */
void cb_ds_bloom_delete(bloom_filter_t **bloom);

/**
 * @brief Insert data in bloom filter
 * @param bloom Bloom filter
 * @param buf Data
 * @param len Length of data
 * @see cb_ds_bloom_get
 */
void cb_ds_bloom_insert(bloom_filter_t *bloom, void *buf, size_t len);

/**
 * Intersection of two bloom filter
 */
void cb_ds_bloom_intersection();

/**
 * @brief Checks if the data is in the Bloom filter
 * @param bloom Bloom filter
 * @param buf Data
 * @param len Length of data
 * @return True if the data exists otherwise false
 * @see cb_ds_bloom_insert
 */
bool cb_ds_bloom_get(bloom_filter_t *bloom, void *buf, size_t len);

#endif
