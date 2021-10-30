/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>

#include "cborg/ds/vector.h"

void test_cb_ds_vector_new_and_delete() {
  ds_vector_t *v1 = NULL;
  v1 = cb_ds_vector_new(10);
  assert(v1 != NULL);
  assert(v1->array != NULL);
  assert(v1->capacity = 10);
  assert(v1->size == 0);

  ds_vector_t *v2 = NULL;
  v2 = cb_ds_vector_new(130);
  assert(v2 != NULL);
  assert(v2->array != NULL);
  assert(v2->capacity = 130);
  assert(v2->size == 0);

  cb_ds_vector_delete(v1);
  cb_ds_vector_delete(v2);
}

void test_cb_ds_vector_init_and_terminate() {
  ds_vector_t v;
  v.array = NULL;
  v.capacity = 0;
  v.size = 10;
  cb_ds_vector_init(&v, 10);
  assert(v.array != NULL);
  assert(v.capacity == 10);
  assert(v.size == 0);
  cb_ds_vector_terminate(&v);
  assert(v.array == NULL);
  assert(v.capacity == 0);
  assert(v.size == 0);
}

void test_cb_ds_vector_push() {
  ds_vector_t *v = NULL;
  v = cb_ds_vector_new(10);
  assert(v->capacity == 10);
  assert(v->size == 0);
  cb_ds_vector_push(v, NULL);
  assert(v->array[0] == NULL);
  assert(v->capacity == 10);
  assert(v->size == 1);

  // Test alloc dynamic
  for (size_t i = 0; i < 9; i++) {
    cb_ds_vector_push(v, NULL);
  }
  assert(v->capacity == 10);
  assert(v->size == 10);
  cb_ds_vector_push(v, NULL);
  assert(v->capacity == 20);
  assert(v->size == 11);

  cb_ds_vector_delete(v);
}

void test_cb_ds_vector_pop() {
  ds_vector_t *v = NULL;
  v = cb_ds_vector_new(10);
  assert(v->capacity == 10);
  assert(v->size == 0);
  int a = 115;
  cb_ds_vector_push(v, &a);
  assert(v->array[0] == &a);
  assert(v->capacity == 10);
  assert(v->size == 1);
  void *e = NULL;
  e = cb_ds_vector_pop(v);
  assert(*(int*)e == 115);
  assert(e == &a);

  cb_ds_vector_delete(v);
}

void test_cb_ds_vector_at() {
  ds_vector_t *v = NULL;
  v = cb_ds_vector_new(10);
  int a = 115;
  cb_ds_vector_push(v, &a);
  void *pa = cb_ds_vector_at(v, 0);
  void *pnull = cb_ds_vector_at(v, 1);
  assert(pa != NULL);
  assert( *(int*)pa == 115);
  assert( *(int*)pa == a);
  assert(pa == &a);
  assert(pnull == NULL);
  cb_ds_vector_delete(v);
}

void test_cb_ds_vector_is_empty() {
  ds_vector_t *v = NULL;
  v = cb_ds_vector_new(10);
  assert(cb_ds_vector_is_empty(v));
  int a = 115;
  cb_ds_vector_push(v, &a);
  assert(!cb_ds_vector_is_empty(v));
  cb_ds_vector_pop(v);
  assert(cb_ds_vector_is_empty(v));
  cb_ds_vector_delete(v);
}

int main() {
  test_cb_ds_vector_new_and_delete();
  test_cb_ds_vector_init_and_terminate();
  test_cb_ds_vector_push();
  test_cb_ds_vector_pop();
  test_cb_ds_vector_at();
  test_cb_ds_vector_is_empty();
  return EXIT_SUCCESS;
}
