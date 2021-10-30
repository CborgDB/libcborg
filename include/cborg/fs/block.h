/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_BLOCK_H
#define _CBORG_BLOCK_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct block_t {
  int fd;
  void *addr;
  uint8_t *data;
  uint64_t blksize;
  off_t size;
  blkcnt_t blocks;
} block_t;

block_t *cb_fs_block_new(const char *filename);

void cb_fs_block_delete(block_t *b);

void cb_fs_block_get_optimal_size(block_t *blk);

void cb_fs_block_read(block_t *blk, size_t n);

void cb_fs_block_write(block_t *blk, size_t n);

#endif
