/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <errno.h>

#include "cborg/ds/btree.h"

btree_t *cb_ds_btree_new() { return NULL; }

void cb_ds_btree_delete(btree_t *bs) { free(bs); }
/*
#include "btree/btree.h"

btree_t *btree_new(uint8_t l, uint8_t u) { return NULL; }

void btree_delete(btree_t *btree) {}

void btree_insert(void *element) {}

void btree_lookup(void *element) {}

void btree_remove(void *element) {}
*/
