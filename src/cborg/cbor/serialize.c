/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <string.h>

#include "cborg/cbor/int.h"
#include "cborg/cbor/item.h"
#include "cborg/cbor/encoding.h"
#include "cborg/cbor/serialize.h"

size_t cb_cbor_serialize(const cbor_item_t *item, unsigned char *buffer,
                         size_t size) {
  switch (cb_cbor_item_get_mt(item)) {
    case CBOR_MT_UINT:
      return cb_cbor_serialize_uint(item, buffer, size);
      break;
    case CBOR_MT_NEGINT:
      return cb_cbor_serialize_negint(item, buffer, size);
      break;
    case CBOR_MT_BYTESTRING:
      return cb_cbor_serialize_bytestring(item, buffer, size);
      break;
    case CBOR_MT_STRING:
      return cb_cbor_serialize_string(item, buffer, size);
      break;
    case CBOR_MT_ARRAY:
      return cb_cbor_serialize_array(item, buffer, size);
      break;
    case CBOR_MT_MAP:
      return cb_cbor_serialize_map(item, buffer, size);
      break;
    case CBOR_MT_TAG:
      return cb_cbor_serialize_tag(item, buffer, size);
      break;
    case CBOR_MT_PRIMITIVE:
      return cb_cbor_serialize_primitive(item, buffer, size);
      break;
    default:
      return 0;
      break;
  }
}

size_t cb_cbor_serialize_uint(const cbor_item_t *item, unsigned char *buffer,
                              size_t size) {
  switch (cb_cbor_int_get_width(item)) {
    case CBOR_INT_8:
      return cb_cbor_encode_uint8(cb_cbor_get_uint8(item), buffer, size);
      break;
    case CBOR_INT_16:
      return cb_cbor_encode_uint16(cb_cbor_get_uint16(item), buffer, size);
      break;
    case CBOR_INT_32:
      return cb_cbor_encode_uint32(cb_cbor_get_uint32(item), buffer, size);
      break;
    case CBOR_INT_64:
      return cb_cbor_encode_uint64(cb_cbor_get_uint64(item), buffer, size);
      break;
    default:
      return 0;
      break;
  }
}

size_t cb_cbor_serialize_negint(const cbor_item_t *item, unsigned char *buffer,
                                size_t size) {
  switch (cb_cbor_int_get_width(item)) {
    case CBOR_INT_8:
      return cb_cbor_encode_negint8(cb_cbor_get_uint8(item), buffer, size);
      break;
    case CBOR_INT_16:
      return cb_cbor_encode_negint16(cb_cbor_get_uint16(item), buffer, size);
      break;
    case CBOR_INT_32:
      return cb_cbor_encode_negint32(cb_cbor_get_uint32(item), buffer, size);
      break;
    case CBOR_INT_64:
      return cb_cbor_encode_negint64(cb_cbor_get_uint64(item), buffer, size);
      break;
    default:
      return 0;
      break;
  }
}

static size_t _cb_cbor_serialize_bytestring_definite(const cbor_item_t *item,
                                                     unsigned char *buffer,
                                                     size_t size) {
  cbor_bytestring_t *bs = ((cbor_bytestring_t *)(item->data));
  size_t len = bs->length;
  size_t written = cb_cbor_encode_bytestring_start(len, buffer, size);
  if (written && written + len <= size) {
    memcpy(buffer + written, bs->chunks, len);
    return written + len;
  } else {
    return 0;
  }
}

static size_t _cb_cbor_serialize_bytestring_indefinite(const cbor_item_t *item,
                                                       unsigned char *buffer,
                                                       size_t size) {
  cbor_bytestring_t *bs = ((cbor_bytestring_t *)(item->data));
  size_t len = bs->length;
  size_t written = cb_cbor_encode_bytestring_indef_start(buffer, size);
  if (written && written + len <= size) {
    for (size_t i = 0; i < len; i++) {
      size_t chunk_written = cb_cbor_serialize_bytestring(
          bs->chunks[i], buffer + written, size - written);
      if (chunk_written == 0) {
        return 0;
      }
      written += chunk_written;
    }
    return written;
  } else {
    return 0;
  }
}

size_t cb_cbor_serialize_bytestring(const cbor_item_t *item,
                                    unsigned char *buffer, size_t size) {
  cbor_bytestring_t *bs = ((cbor_bytestring_t *)(item->data));
  if (bs->definite) {
    return _cb_cbor_serialize_bytestring_definite(item, buffer, size);
  } else {
    return _cb_cbor_serialize_bytestring_indefinite(item, buffer, size);
  }
}

static size_t _cb_cbor_serialize_string_definite(const cbor_item_t *item,
                                                 unsigned char *buffer,
                                                 size_t size) {
  cbor_string_t *bs = ((cbor_string_t *)(item->data));
  size_t len = bs->length;
  size_t written = cb_cbor_encode_string_start(len, buffer, size);
  if (written && written + len <= size) {
    memcpy(buffer + written, bs->chunks, len);
    return written + len;
  } else {
    return 0;
  }
}

static size_t _cb_cbor_serialize_string_indefinite(const cbor_item_t *item,
                                                   unsigned char *buffer,
                                                   size_t size) {
  cbor_string_t *bs = ((cbor_string_t *)(item->data));
  size_t len = bs->length;
  size_t written = cb_cbor_encode_string_indef_start(buffer, size);
  if (written && written + len <= size) {
    for (size_t i = 0; i < len; i++) {
      size_t chunk_written = cb_cbor_serialize_string(
          bs->chunks[i], buffer + written, size - written);
      if (chunk_written == 0) {
        return 0;
      }
      written += chunk_written;
    }
    return written;
  } else {
    return 0;
  }
}

size_t cb_cbor_serialize_string(const cbor_item_t *item, unsigned char *buffer,
                                size_t size) {
  cbor_string_t *s = ((cbor_string_t *)(item->data));
  if (s->definite) {
    return _cb_cbor_serialize_string_definite(item, buffer, size);
  } else {
    return _cb_cbor_serialize_string_indefinite(item, buffer, size);
  }
}

size_t cb_cbor_serialize_array(const cbor_item_t *item, unsigned char *buffer,
                               size_t size) {
  
  return 0;
}

size_t cb_cbor_serialize_map(const cbor_item_t *item, unsigned char *buffer,
                             size_t size) {
  return 0;
}

size_t cb_cbor_serialize_tag(const cbor_item_t *item, unsigned char *buffer,
                             size_t size) {
  return 0;
}

size_t cb_cbor_serialize_primitive(const cbor_item_t *item,
                                   unsigned char *buffer, size_t size) {
  return 0;
}