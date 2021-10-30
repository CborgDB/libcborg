/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <string.h>

#include "cborg/cbor/encoding.h"
#include "cborg/os/endianness.h"

// INT
size_t cb_cbor_encode_uint8(uint8_t value, unsigned char *buffer, size_t size) {
  return _cb_cbor_encode_uint8(value, buffer, size, 0);
}

size_t cb_cbor_encode_uint16(uint16_t value, unsigned char *buffer,
                             size_t size) {
  return _cb_cbor_encode_uint16(value, buffer, size, 0);
}

size_t cb_cbor_encode_uint32(uint32_t value, unsigned char *buffer,
                             size_t size) {
  return _cb_cbor_encode_uint32(value, buffer, size, 0);
}

size_t cb_cbor_encode_uint64(uint64_t value, unsigned char *buffer,
                             size_t size) {
  return _cb_cbor_encode_uint64(value, buffer, size, 0);
}

size_t cb_cbor_encode_uint(uint64_t value, unsigned char *buffer, size_t size) {
  return _cb_cbor_encode_uint(value, buffer, size, 0);
}

// NEG INT
size_t cb_cbor_encode_negint8(uint8_t value, unsigned char *buffer,
                              size_t size) {
  return _cb_cbor_encode_uint8(value, buffer, size, 0x20);
}

size_t cb_cbor_encode_negint16(uint16_t value, unsigned char *buffer,
                               size_t size) {
  return _cb_cbor_encode_uint16(value, buffer, size, 0x20);
}

size_t cb_cbor_encode_negint32(uint32_t value, unsigned char *buffer,
                               size_t size) {
  return _cb_cbor_encode_uint32(value, buffer, size, 0x20);
}

size_t cb_cbor_encode_negint64(uint64_t value, unsigned char *buffer,
                               size_t size) {
  return _cb_cbor_encode_uint64(value, buffer, size, 0x20);
}

size_t cb_cbor_encode_negint(uint64_t value, unsigned char *buffer,
                             size_t size) {
  return _cb_cbor_encode_uint(value, buffer, size, 0x20);
}

// BYTESTRING
size_t cb_cbor_encode_bytestring_start(size_t length, unsigned char *buffer,
                                       size_t size) {
  return _cb_cbor_encode_uint(length, buffer, size, 0x40);
}

size_t cb_cbor_encode_bytestring_indef_start(unsigned char *buffer,
                                             size_t size) {
  return cb_cbor_encode_byte(0x5F, buffer, size);
}

// STRING
size_t cb_cbor_encode_string_start(size_t length, unsigned char *buffer,
                                   size_t size) {
  return _cb_cbor_encode_uint(length, buffer, size, 0x60);
}

size_t cb_cbor_encode_string_indef_start(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0x7F, buffer, size);
}

// ARRAY
size_t cb_cbor_encode_array_start(size_t length, unsigned char *buffer,
                                  size_t size) {
  return _cb_cbor_encode_uint(length, buffer, size, 0x80);
}

size_t cb_cbor_encode_array_indef_start(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0x9F, buffer, size);
}

// MAP
size_t cb_cbor_encode_map_start(size_t length, unsigned char *buffer,
                                size_t size) {
  return _cb_cbor_encode_uint(length, buffer, size, 0xA0);
}

size_t cb_cbor_encode_map_indef_start(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xBF, buffer, size);
}

size_t cb_cbor_encode_byte(uint8_t byte, unsigned char *buffer, size_t size) {
  if (size >= 1) {
    buffer[0] = byte;
    return 1;
  }
  return 0;
}

size_t cb_cbor_encode_break(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xFF, buffer, size);
}

size_t cb_cbor_encode_false(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xF4, buffer, size);
}

size_t cb_cbor_encode_true(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xF5, buffer, size);
}

size_t cb_cbor_encode_null(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xF6, buffer, size);
}

size_t cb_cbor_encode_undefined(unsigned char *buffer, size_t size) {
  return cb_cbor_encode_byte(0xF7, buffer, size);
}

// internal

static inline size_t _cb_cbor_encode_uint8(uint8_t value, unsigned char *buffer,
                                           size_t size, uint8_t offset) {
  if (value < 24) {
    if (size >= 1) {
      buffer[0] = value + offset;
      return 1;
    }
  } else {
    if (size >= 2) {
      buffer[0] = 24 + offset;
      buffer[1] = value;
      return 2;
    }
  }
  return 0;
}

static inline size_t _cb_cbor_encode_uint16(uint16_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset) {
  if (size >= 3) {
    buffer[0] = 25 + offset;
    if (cb_is_little_endian())
      *((uint16_t *)(buffer + 1)) = cb_bswap16(value);
    else
      *((uint16_t *)(buffer + 1)) = value;
    return 3;
  }
  return 0;
}

static inline size_t _cb_cbor_encode_uint32(uint32_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset) {
  if (size >= 5) {
    buffer[0] = 26 + offset;
    if (cb_is_little_endian())
      *((uint32_t *)(buffer + 1)) = cb_bswap32(value);
    else
      *((uint32_t *)(buffer + 1)) = value;
    return 5;
  }
  return 0;
}

static inline size_t _cb_cbor_encode_uint64(uint64_t value,
                                            unsigned char *buffer, size_t size,
                                            uint8_t offset) {
  if (size >= 9) {
    buffer[0] = 27 + offset;
    if (cb_is_little_endian())
      *((uint64_t *)(buffer + 1)) = cb_bswap64(value);
    else
      *((uint64_t *)(buffer + 1)) = value;
    return 9;
  }
  return 0;
}

static inline size_t _cb_cbor_encode_uint(uint64_t value, unsigned char *buffer,
                                          size_t size, uint8_t offset) {
  if (value <= UINT16_MAX)
    if (value <= UINT8_MAX)
      return _cb_cbor_encode_uint8(value, buffer, size, offset);
    else
      return _cb_cbor_encode_uint16(value, buffer, size, offset);
  else if (value <= UINT32_MAX)
    return _cb_cbor_encode_uint32(value, buffer, size, offset);
  else
    return _cb_cbor_encode_uint64(value, buffer, size, offset);
}
