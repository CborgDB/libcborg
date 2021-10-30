/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "cborg/os/endianness.h"

int main() {
  assert(0x2301 == cb_bswap16(0x0123));
  printf("%u\n", cb_bswap16(0x0123));

  assert(0x67452301u == cb_bswap32(0x01234567u));
  printf("%u\n", cb_bswap32(0x01234567u));

  assert(0xEFCDAB8967452301llu == cb_bswap64(0x0123456789ABCDEFllu));
  printf("%"PRIu64"\n", cb_bswap64(0x0123456789ABCDEFllu));
  return EXIT_SUCCESS;
}
