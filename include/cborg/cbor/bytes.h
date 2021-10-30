/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_BYTES_H
#define _CBORG_CBOR_BYTES_H

#include <stdbool.h>
#include <stdlib.h>

#include "cborg/cbor/item.h"

cbor_item_t *cb_cbor_bytes_new(uint8_t *bytes, uint64_t length, bool definite);

void cb_cbor_bytes_add_chunk(cbor_item_t *item, uint8_t *bytes,
                             uint64_t length);

// void cb_cbor_remove_chunk(uint8_t *bytes);

uint64_t cb_cbor_bytes_chunk_count(cbor_item_t *item);

uint64_t cb_cbor_bytes_length(cbor_item_t *item);

void cb_cbor_bytes_set_definite(cbor_item_t *item);

void cb_cbor_bytes_set_indefinite(cbor_item_t *item);

bool cb_cbor_bytes_is_definite(cbor_item_t *item);

bool cb_cbor_bytes_is_indefinite(cbor_item_t *item);

#endif
