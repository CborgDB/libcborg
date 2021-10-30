/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#include "cborg/net/socket.h"

#define h_addr h_addr_list[0]

void cb_net_socket_init(socket_t *s) {
  if ((s->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
}

void cb_net_socket_terminate(socket_t *s) { close(s->fd); }

socket_t *cb_net_socket_new() {
  socket_t *s = (socket_t *)malloc(sizeof(socket_t));
  cb_net_socket_init(s);
  return s;
}

void cb_net_socket_delete(socket_t *s) {
  cb_net_socket_terminate(s);
  free(s);
}

void cb_net_socket_read(socket_t *s, void *buf, size_t nbyte) {
  //read(s->fd, buf, len);
  size_t bytes_read = 0;
  for (size_t total_read = 0; total_read < nbyte; total_read += bytes_read) {
    if ((bytes_read =
             read(s->fd, (char *)buf + total_read, nbyte - total_read)) < 0) {
      printf("ERROR: cb_os_read = %s\n", strerror(errno));
    }
  }
}

void cb_net_socket_write(socket_t *s, void *buf, size_t nbyte) {
  //write(s->fd, buf, length);
  size_t bytes_written = 0;
  for (size_t total_written = 0; total_written < nbyte;
       total_written += bytes_written) {
    if ((bytes_written = write(s->fd, (char *)buf + total_written,
                               nbyte - total_written)) < 0) {
      printf("ERROR: cb_os_write= %s\n", strerror(errno));
    }
  }
}

void cb_net_socket_connect(socket_t *s, const char *hostname, uint16_t port) {
  struct hostent *hostinfo = NULL;
  struct sockaddr_in sin = {0};

  hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "Unknown host %s.\n", hostname);
    exit(EXIT_FAILURE);
  }
  sin.sin_addr = *(struct in_addr *)hostinfo->h_addr;
  sin.sin_port = htons(port);
  sin.sin_family = AF_INET;

  if (connect(s->fd, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1) {
    perror("connect()");
    exit(errno);
  }
}
