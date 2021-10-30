/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <string.h>

#include "cborg/cbor/bytes.h"

cbor_item_t *cb_cbor_bytes_new(uint8_t *bytes, uint64_t length, bool definite) {
  return NULL;
}

void cb_cbor_bytes_add_chunk(cbor_item_t *item, uint8_t *bytes,
                             uint64_t length) {}

uint64_t cb_cbor_bytes_chunk_count(cbor_item_t *item) { return 0; }

uint64_t cb_cbor_bytes_length(cbor_item_t *item) { return 1; }

void cb_cbor_bytes_set_definite(cbor_item_t *item) {}

void cb_cbor_bytes_set_indefinite(cbor_item_t *item) {}

bool cb_cbor_bytes_is_indefinite(cbor_item_t *item) { return false; }

bool cb_cbor_bytes_is_definite(cbor_item_t *item) { return false; }
