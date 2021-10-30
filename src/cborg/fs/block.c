/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "cborg/fs/block.h"

block_t *cb_fs_block_new(const char *filename) {
  block_t *blk = (block_t *)malloc(sizeof(block_t));
  blk->fd = open(filename, O_RDWR | O_CREAT, 0600);
  cb_fs_block_get_optimal_size(blk);
  blk->data = malloc(sizeof(uint8_t) * (blk->blksize));
  return blk;
}

void cb_fs_block_get_optimal_size(block_t *blk) {
  struct stat s;
  fstat(blk->fd, &s);
  blk->blksize = s.st_blksize;
  blk->size = s.st_size;
  blk->blocks = s.st_blocks;
}

void cb_fs_block_read(block_t *blk, size_t n) {
  pread(blk->fd, blk->data, blk->blksize, n * (blk->blksize));
}

void cb_fs_block_write(block_t *blk, size_t n) {
  pwrite(blk->fd, blk->data, blk->blksize, n * (blk->blksize));
}

void cb_fs_block_delete(block_t *b) {
  free(b->data);
  close(b->fd);
  free(b);
}
