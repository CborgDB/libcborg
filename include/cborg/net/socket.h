/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_NET_SOCKET_H
#define _CBORG_NET_SOCKET_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

typedef struct socket_t {
  int fd;
  uint64_t bytes_read;
  uint64_t bytes_written;
} socket_t;

socket_t *cb_net_socket_new();

void cb_net_socket_delete(socket_t *s);

void cb_net_socket_init(socket_t *s);

void cb_net_socket_terminate(socket_t *s);

void cb_net_socket_read(socket_t *s, void *buf, size_t len);

void cb_net_socket_write(socket_t *s, void *buf, size_t length);

void cb_net_socket_connect(socket_t *s, const char *hostname, uint16_t port);

#endif
