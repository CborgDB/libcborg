/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_BTREE_H
#define _CBORG_BTREE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct btree_t {
  void *b;
} btree_t;

btree_t *cb_ds_btree_new();

void cb_ds_btree_delete(btree_t *bt);
/*
#ifndef _BTREE_H
#define _BTREE_H

#include <stdlib.h>

typedef struct btree_t
{
  uint8_t l;
  uint8_t u;
  struct btree_t *kind;
} btree_t;

*/
/** Create l-u B-tree
 * l<=u  -> l-u b-tree
 * exemple: l=3 u=5
 *      - the tree is named 3-5 B-tree
 * @param l l-1 min by node
 * @param u u-1 max by node and u max number of child
 */
/*
btree_t* btree_new(uint8_t l, uint8_t u);

void btree_delete(btree_t *btree);

void btree_insert(void *element);

void btree_lookup(void *element);

void btree_remove(void *element);

#endif
*/

#endif
