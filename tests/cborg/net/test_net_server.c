/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "cborg/net/server.h"
#include "cborg/net/socket.h"
#include "cborg/internal/alloc.h"
#include "cborg/internal/log.h"

int main() {
  /*char buf[400];
  server_t *srv = cb_net_server_new();
  cb_net_server_listen(srv, 80, 1000);
  int i=0;
  while (1) {
    socket_t s = cb_net_server_accept(srv);
    cb_net_socket_read(&s, buf, 400);
    printf("%s", buf);
    cb_net_socket_write(&s, "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello world!\n", 55);
    printf("Message sent %d\n",++i);
    close(s.fd);
  }
  cb_net_server_delete(srv);*/
  /*void *p;
  int ret;
  ret = cb_malloc(1000000000000000000,&p);
  cb_free(p);
  cb_log_debug();
  cb_log_info();*/
  return EXIT_SUCCESS;
}
