/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_CBOR_TYPES_H
#define _CBORG_CBOR_TYPES_H

#include <stdbool.h>

typedef enum cbor_major_type {
  CBOR_MT_UINT = 0,       // unsigned integer
  CBOR_MT_NEGINT = 1,     // negative integer
  CBOR_MT_BYTESTRING = 2, // byte String
  CBOR_MT_STRING = 3,     // utf-8 string
  CBOR_MT_ARRAY = 4,      // array
  CBOR_MT_MAP = 5,        // map
  CBOR_MT_TAG = 6,        // tag
  CBOR_MT_PRIMITIVE = 7   // primitive (simple, float, true, false, ...)
} cbor_major_type;

typedef enum cbor_int_width {
  CBOR_INT_8 = 1,
  CBOR_INT_16 = 2,
  CBOR_INT_32 = 4,
  CBOR_INT_64 = 8
} cbor_int_width;

typedef enum cbor_primitive_type {
  CBOR_PRIM_FALSE,
  CBOR_PRIM_TRUE,
  CBOR_PRIM_NULL,
  CBOR_PRIM_UNDEFINED,
  CBOR_PRIM_FLOAT_16,
  CBOR_PRIM_FLOAT_32,
  CBOR_PRIM_FLOAT_64
} cbor_primitive_type;

/**
 * Structures for each major type
 *
 */
typedef struct cbor_item_t {
  cbor_major_type mt;
  void *data;
} cbor_item_t;

typedef struct cbor_int_t {
  cbor_int_width width;
  void *value;
} cbor_int_t;

typedef struct cbor_dynamic_t {
  size_t size;
  size_t capacity;
  bool indefinite;
  void **chunks;
  size_t (*encode_start)(size_t, unsigned char *, size_t);
  size_t (*encode_indef_start)(unsigned char *, size_t);
} cbor_dynamic_t;

typedef struct cbor_bytestring_t {
  size_t length;
  bool definite;
  cbor_item_t **chunks;
} cbor_bytestring_t;

typedef struct cbor_string_t {
  size_t length;
  bool definite;
  cbor_item_t **chunks;
} cbor_string_t;

typedef struct cbor_array_t {
  size_t length;
  bool definite;
  cbor_item_t **items;
} cbor_array_t;

typedef struct cbor_pair_t {
  cbor_item_t *key;
  cbor_item_t *value;
} cbor_pair_t;

typedef struct cbor_map_t {
  size_t length;
  bool definite;
  cbor_pair_t **pairs;
} cbor_map_t;

typedef struct cbor_tag_t {
  void *data;
} cbor_tag_t;

typedef struct cbor_primitive_t {
  void *data;
} cbor_primitive_t;

#endif
