/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include "cborg/ds/vector.h"

ds_vector_t *cb_ds_vector_new(size_t capacity) {
  ds_vector_t *v = (ds_vector_t *)malloc(sizeof(ds_vector_t));
  cb_ds_vector_init(v,capacity);
  return v;
}

void cb_ds_vector_init(ds_vector_t *v, size_t capacity){
  v->array = (void **)malloc(sizeof(void *) * capacity);
  v->capacity = capacity;
  v->size = 0;
}

void cb_ds_vector_delete(ds_vector_t *v) {
  cb_ds_vector_terminate(v);
  free(v);
}

void cb_ds_vector_terminate(ds_vector_t *v){
  free(v->array);
  v->array = NULL;
  v->capacity = 0;
  v->size = 0;
}

void cb_ds_vector_push(ds_vector_t *v, void *e) {
  if(v->size == v->capacity){
    v->array = realloc(v->array, v->capacity * 2);
    v->capacity *=2;
  }
  v->array[v->size] = e;
  v->size++;
}

void *cb_ds_vector_pop(ds_vector_t *v) {
  if(v->size > 0){
    void *e = v->array[v->size - 1];
    v->array[v->size - 1] = NULL;
    v->size--;
    return e;
  }
  return NULL;
}

void *cb_ds_vector_at(ds_vector_t *v, size_t pos){
  return pos < v->size ? v->array[pos] : NULL;
}

bool cb_ds_vector_is_empty(ds_vector_t *v){
  return v->size == 0;
}
