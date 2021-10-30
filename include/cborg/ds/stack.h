/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_STACK_H
#define _CBORG_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct ds_stack_t {
    void **array;
    size_t top;
    size_t capacity;
} ds_stack_t;

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
ds_stack_t* cb_ds_stack_new(size_t capacity);

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
void cb_ds_stack_delete(ds_stack_t *s);

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
void cb_ds_stack_push(ds_stack_t *s, void *e);

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
void* cb_ds_stack_pop(ds_stack_t *s);

/**
 * @brief Allocate new bloom filter (need bloom_delete after use)
 * @param h1 Hash function 1
 * @param h2 Hash function 2
 * @param len Length of bloom array
 * @return Pointer of bloom filter structure
 * @see cb_ds_bloom_delete
 */
bool cb_ds_stack_empty(ds_stack_t *s);

#endif
