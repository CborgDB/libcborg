/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_BITSET_H
#define _CBORG_BITSET_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the number of bytes needed to store a number of bits
#define __bitset_size(nbits) ((nbits + 7) >> 3)

// Returns the index of the bit in bitset->array (=idx/8)
#define __bitset_byte(idx) ((idx) >> 3)

// Returns the bit mask
#define __bitset_bit_mask(idx) (1 << ((idx)&0x7))

// TODO: format bitset using cbor
// TODO: bitset thread-safe

typedef struct bitset_t {
  bool flip;
  size_t size;
  size_t count;
  uint8_t *array;
} bitset_t;

/**
 * @brief Allocate new bitset (need bitset_delete after use)
 * @param len Length of bitset
 * @return Pointer of bitset structure
 * @see cb_ds_bitset_delete
 */
bitset_t *cb_ds_bitset_new(size_t nb_bits);

/**
 * @brief Free bitset
 * @param bs Bitset
 * @see cb_ds_bitset_new
 */
void cb_ds_bitset_delete(bitset_t *bs);

/**
 * @brief Number of bits 1 in bitset
 * @param bs Bitset
 * @return Number of bits in the bitset that have a value of one.
 * @see cb_ds_bitset_size
 * @see cb_ds_bitset_flip
 */
size_t cb_ds_bitset_count(bitset_t *bs);

/**
 * @brief Total size in number of bits
 * @param bs Bitset
 * @return Length of bitset.
 * @see cb_ds_bitset_count
 * @see cb_ds_bitset_flip
 */
size_t cb_ds_bitset_size(bitset_t *bs);

/**
 * @brief Test if idx bit in bitset have value 1
 * @param bs Bitset
 * @param idx Index of bit
 * @return True if the idx bit is 1, false otherwise.
 * @see cb_ds_bitset_set
 */
bool cb_ds_bitset_test(bitset_t *bs, size_t idx);

/**
 * @brief Test if a bit in bitset has the value 1
 * @param bs Bitset
 * @return True if one bit has the value 1, false otherwise.
 * @see cb_ds_bitset_none
 * @see cb_ds_bitset_all
 */
bool cb_ds_bitset_any(bitset_t *bs);

/**
 * @brief Test if all bits has the value 0
 * @param bs Bitset
 * @return True if all bits has the value 0, false otherwise.
 * @see cb_ds_bitset_any
 * @see cb_ds_bitset_all
 */
bool cb_ds_bitset_none(bitset_t *bs);

/**
 * @brief Test if all bits has the value 1
 * @param bs Bitset
 * @return True if all bits has the value 1, false otherwise.
 * @see cb_ds_bitset_any
 * @see cb_ds_bitset_none
 */
bool cb_ds_bitset_all(bitset_t *bs);

/**
 * @brief Set value in bitset at idx.
 * @param bs Bitset
 * @param idx Index of bit
 * @param value For idx bit in the bitset (true = 1; false = 0)
 * @see cb_ds_bitset_test
 */
void cb_ds_bitset_set(bitset_t *bs, size_t idx, bool value);

/**
 * @brief Reset bitset
 * @param bs Bitset
 * @see cb_ds_bitset_new
 * @see cb_ds_bitset_delete
 */
void cb_ds_bitset_reset(bitset_t *bs);

/**
 * @brief Flip all bits in the bitset (all 1 become 0 and all 0 become 1)
 * @param bs Bitset
 */
void cb_ds_bitset_flip(bitset_t *bs);

/**
 * @brief Bitset in string, like "00010001110"
 * @param bs Bitset
 * @return The human readeable bitset
 * @see cb_ds_bitset_write
 * @see cb_ds_bitset_read
 */
char *cb_ds_bitset_to_string(bitset_t *bs);

/**
 * @brief Write the bitset to a file in binary format (/!\ Unstable)
 * @param bs Bitset
 * @param path File path (include file name)
 * @see cb_ds_bitset_read
 */
void cb_ds_bitset_write(bitset_t *bs, const char *path);

/**
 * @brief Read bitset from binary file  (/!\ Unstable)
 * @param  path File that contains the bitset in binary format
 * @return Bitset
 * @see cb_ds_bitset_write
 */
bitset_t *cb_ds_bitset_read(const char *path);

#endif
