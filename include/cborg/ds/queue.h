/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_QUEUE_H
#define _CBORG_QUEUE_H

#include <stdlib.h>

typedef struct ds_queue_t {
    
} ds_queue_t;

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
ds_queue_t* cb_ds_queue_new(size_t capacity);

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
void cb_ds_queue_delete(ds_queue_t *s);

#endif
