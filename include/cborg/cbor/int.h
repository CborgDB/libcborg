/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_INT_H
#define _CBORG_CBOR_INT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cborg/cbor/types.h"

// New int
cbor_item_t *cb_cbor_new_int8();

cbor_item_t *cb_cbor_new_int16();

cbor_item_t *cb_cbor_new_int32();

cbor_item_t *cb_cbor_new_int64();

void cb_cbor_delete_int(cbor_item_t **item);

void cb_cbor_mark_uint(cbor_item_t *item);

void cb_cbor_mark_negint(cbor_item_t *item);

cbor_int_width cb_cbor_int_get_width(const cbor_item_t *item);

// Serialize and deserialize
unsigned char *cb_cbor_int_serialize(cbor_item_t *item);

cbor_item_t *cb_cbor_int_unserialize(unsigned char *data);

// Build int
cbor_item_t *cb_cbor_build_uint8(uint8_t value);

cbor_item_t *cb_cbor_build_uint16(uint16_t value);

cbor_item_t *cb_cbor_build_uint32(uint32_t value);

cbor_item_t *cb_cbor_build_uint64(uint64_t value);

// Mutator
void cb_cbor_set_uint8(cbor_item_t *item, uint8_t value);

void cb_cbor_set_uint16(cbor_item_t *item, uint16_t value);

void cb_cbor_set_uint32(cbor_item_t *item, uint32_t value);

void cb_cbor_set_uint64(cbor_item_t *item, uint64_t value);

// Accessor
uint8_t cb_cbor_get_uint8(const cbor_item_t *item);

uint16_t cb_cbor_get_uint16(const cbor_item_t *item);

uint32_t cb_cbor_get_uint32(const cbor_item_t *item);

uint64_t cb_cbor_get_uint64(const cbor_item_t *item);

// Comparator
bool cb_cbor_int_eq(const cbor_item_t *a, const cbor_item_t *b);

bool cb_cbor_int_ne(const cbor_item_t *a, const cbor_item_t *b);

bool cb_cbor_int_lt(const cbor_item_t *a, const cbor_item_t *b);

bool cb_cbor_int_gt(const cbor_item_t *a, const cbor_item_t *b);

bool cb_cbor_int_le(const cbor_item_t *a, const cbor_item_t *b);

bool cb_cbor_int_ge(const cbor_item_t *a, const cbor_item_t *b);

#endif
