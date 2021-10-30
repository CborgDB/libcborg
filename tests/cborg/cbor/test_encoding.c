/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cborg/cbor/encoding.h"

void test_cbor_encode_uint8() {
  unsigned char buffer[2];
  write(1,buffer,cb_cbor_encode_uint8(23,buffer, 2));
}

void test_cbor_encode_uint16() {
  unsigned char buffer[3];
  cb_cbor_encode_uint16(351,buffer, 3);
  write(1,buffer,3);
}

void test_cbor_encode_uint32() {
  unsigned char buffer[5];
  cb_cbor_encode_uint32(0x16657845,buffer, 5);
  write(1,buffer,5);
}

void test_cbor_encode_uint64() {
  unsigned char buffer[9];
  cb_cbor_encode_uint64(0x8798099887,buffer, 9);
  write(1,buffer,9);
  cb_cbor_encode_uint64(0x8638044887,buffer, 9);
  write(1,buffer,9);
}

void test_cbor_encode_uint() {
  unsigned char buffer[9];
  cb_cbor_encode_uint(0x8798099887,buffer, 9);
  write(1,buffer,9);
}

void test_cbor_encode_negint() {
  unsigned char buffer[9];
  cb_cbor_encode_negint(0x8798099887,buffer, 9);
  write(1,buffer,9);
}

int main() {
  test_cbor_encode_uint8();
  test_cbor_encode_uint16();
  test_cbor_encode_uint32();
  test_cbor_encode_uint64();
  test_cbor_encode_uint();
  test_cbor_encode_negint();

  return EXIT_SUCCESS;
}
