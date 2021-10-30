/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_SERIALIZE_H
#define _CBORG_CBOR_SERIALIZE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cborg/cbor/types.h"

size_t cb_cbor_serialize(const cbor_item_t *item, unsigned char *buffer,
                         size_t size);

size_t cb_cbor_serialize_uint(const cbor_item_t *item, unsigned char *buffer,
                              size_t size);

size_t cb_cbor_serialize_negint(const cbor_item_t *item, unsigned char *buffer,
                                size_t size);

size_t cb_cbor_serialize_int(const cbor_item_t *item, unsigned char *buffer,
                             size_t size);

static size_t _cb_cbor_serialize_bytestring_definite(const cbor_item_t *item,
                                                     unsigned char *buffer,
                                                     size_t size);

static size_t _cb_cbor_serialize_bytestring_indefinite(const cbor_item_t *item,
                                                       unsigned char *buffer,
                                                       size_t size);

size_t cb_cbor_serialize_bytestring(const cbor_item_t *item,
                                    unsigned char *buffer, size_t size);

static size_t _cb_cbor_serialize_string_definite(const cbor_item_t *item,
                                                 unsigned char *buffer,
                                                 size_t size);

static size_t _cb_cbor_serialize_string_indefinite(const cbor_item_t *item,
                                                   unsigned char *buffer,
                                                   size_t size);

size_t cb_cbor_serialize_string(const cbor_item_t *item, unsigned char *buffer,
                                size_t size);

size_t cb_cbor_serialize_array(const cbor_item_t *item, unsigned char *buffer,
                               size_t size);

size_t cb_cbor_serialize_map(const cbor_item_t *item, unsigned char *buffer,
                             size_t size);

size_t cb_cbor_serialize_tag(const cbor_item_t *item, unsigned char *buffer,
                             size_t size);

size_t cb_cbor_serialize_primitive(const cbor_item_t *item,
                                   unsigned char *buffer, size_t size);

#endif
