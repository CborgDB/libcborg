/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_VECTOR_H
#define _CBORG_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct ds_vector_t {
  void **array;
  size_t size;
  size_t capacity;
} ds_vector_t;

/**
 * @brief Allocate new vector (need bloom_delete after use)
 * @param capacity Capacity of vector
 * @return Pointer of new vector
 * @see cb_ds_vector_delete
 */
ds_vector_t* cb_ds_vector_new(size_t capacity);

/**
 * @brief Allocate array in ds_vector_t with capacity
 * @param v Pointer of vector
 * @param capacity Capacity of vector
 * @see cb_ds_vector_terminate
 */
void cb_ds_vector_init(ds_vector_t *v, size_t capacity);

/**
 * @brief Free the vector
 * @param v Pointer of vector
 * @see cb_ds_vector_new
 */
void cb_ds_vector_delete(ds_vector_t *v);

/**
 * @brief Free the array in vector
 * @param v Pointer of vector
 * @see cb_ds_vector_init
 */
void cb_ds_vector_terminate(ds_vector_t *v);

/**
 * @brief Push data in the vector
 * @param v Pointer of vector
 * @param e Pointer of data you want to push in the vector
 * @see cb_ds_vector_pop
 */
void cb_ds_vector_push(ds_vector_t *v, void *e);

/**
 * @brief Pop data in the vector (last data in the array)
 * @param v Pointer of vector
 * @see cb_ds_vector_push
 */
void *cb_ds_vector_pop(ds_vector_t *v);

/**
 * @brief Get the data at pos in the vector
 * @param v Pointer of vector
 * @param pos Position of the data you want to get
 * @return Data in the array
 * @see cb_ds_bloom_delete
 */
void *cb_ds_vector_at(ds_vector_t *v, size_t pos);

/**
 * @brief Test if the vector is empty
 * @param v Pointer of vector
 * @return True if vector is empty, false otherwise.
 */
bool cb_ds_vector_is_empty(ds_vector_t *v);

#endif
