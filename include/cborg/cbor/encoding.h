/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_ENCODING_H
#define _CBORG_CBOR_ENCODING_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cborg/cbor/types.h"

// UINT
size_t cb_cbor_encode_uint8(uint8_t value, unsigned char *buffer, size_t size);

size_t cb_cbor_encode_uint16(uint16_t value, unsigned char *buffer,
                             size_t size);

size_t cb_cbor_encode_uint32(uint32_t value, unsigned char *buffer,
                             size_t size);

size_t cb_cbor_encode_uint64(uint64_t value, unsigned char *buffer,
                             size_t size);

size_t cb_cbor_encode_uint(uint64_t value, unsigned char *buffer, size_t size);

// NEGINT
size_t cb_cbor_encode_negint8(uint8_t value, unsigned char *buffer,
                              size_t size);

size_t cb_cbor_encode_negint16(uint16_t value, unsigned char *buffer,
                               size_t size);

size_t cb_cbor_encode_negint32(uint32_t value, unsigned char *buffer,
                               size_t size);

size_t cb_cbor_encode_negint64(uint64_t value, unsigned char *buffer,
                               size_t size);

size_t cb_cbor_encode_negint(uint64_t value, unsigned char *buffer,
                             size_t size);

// BYTESTRING
size_t cb_cbor_encode_bytestring_start(size_t length, unsigned char *buffer,
                                       size_t size);

size_t cb_cbor_encode_bytestring_indef_start(unsigned char *buffer,
                                             size_t size);

// STRING
size_t cb_cbor_encode_string_start(size_t length, unsigned char *buffer,
                                   size_t size);

size_t cb_cbor_encode_string_indef_start(unsigned char *buffer, size_t size);

// ARRAY
size_t cb_cbor_encode_array_start(size_t length, unsigned char *buffer,
                                  size_t size);

size_t cb_cbor_encode_array_indef_start(unsigned char *buffer, size_t size);

// MAP
size_t cb_cbor_encode_map_start(size_t length, unsigned char *buffer,
                                size_t size);

size_t cb_cbor_encode_map_indef_start(unsigned char *buffer, size_t size);

// TAG

// SIMPLE

size_t cb_cbor_encode_byte(uint8_t byte, unsigned char *buffer, size_t size);

size_t cb_cbor_encode_break(unsigned char *buffer, size_t size);

size_t cb_cbor_encode_false(unsigned char *buffer, size_t size);

size_t cb_cbor_encode_true(unsigned char *buffer, size_t size);

size_t cb_cbor_encode_null(unsigned char *buffer, size_t size);

size_t cb_cbor_encode_undefined(unsigned char *buffer, size_t size);

// INTERNAL
static inline size_t _cb_cbor_encode_uint8(uint8_t value, unsigned char *buffer,
                                           size_t size, uint8_t offset);

static inline size_t _cb_cbor_encode_uint16(uint16_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset);

static inline size_t _cb_cbor_encode_uint32(uint32_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset);

static inline size_t _cb_cbor_encode_uint64(uint64_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset);

static inline size_t _cb_cbor_encode_uint(uint64_t value, unsigned char *buffer,
                                          size_t size, uint8_t offset);

#endif
