/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "cborg/net/socket.h"

int main() {
  /*char buf[100];
  socket_t *s = cb_net_socket_new();
  cb_net_socket_connect(s,"www.google.com",80);
  cb_net_socket_write(s,"GET / HTTP/1.1\n\n",16);
  cb_net_socket_read(s, buf, 100);
  printf("%s",buf);
  cb_net_socket_delete(s);*/

  /*socket_t *s = cb_net_socket_new();
  uint64_t msgLen = 55;
  uint32_t opCode = 1;
  char *tableName = "user";
  cb_net_socket_connect(s,"localhost",8080);
  cb_net_socket_write(s, &msgLen, 8);
  cb_net_socket_write(s, &opCode, 4);
  cb_net_socket_write(s, tableName, 5);

  //printf("%s",buf);
  cb_net_socket_delete(s);*/
  return EXIT_SUCCESS;
}
