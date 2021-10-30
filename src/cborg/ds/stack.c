/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include "cborg/ds/stack.h"

// code not tested

ds_stack_t *cb_ds_stack_new(size_t capacity) {
  ds_stack_t *s = (ds_stack_t *)malloc(sizeof(ds_stack_t));
  s->array = malloc(sizeof(void *) * capacity);
  s->top = 0;
  return s;
}

void cb_ds_stack_delete(ds_stack_t *s) {
  free(s->array);
  free(s);
}

void cb_ds_stack_push(ds_stack_t *s, void *e) {
  if (s->top != s->capacity) {
    s->array[s->top] = e;
    s->top++;
  }
}

void *cb_ds_stack_pop(ds_stack_t *s) {
  s->top--;
  return s->array[s->top+1];
}
