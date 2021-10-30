/**
 * Copyright (c) 2020-2021 Adil Benhlal <adil.benhlal@outlook.fr>
 * 
 */

#ifndef _CBORG_NET_SERVER_H
#define _CBORG_NET_SERVER_H

#include <netinet/in.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cborg/net/socket.h"

/**
 * CREATE SERVER
 * PROTOCOL: TCP or UDP
 * PORT: DEFAULT 80
 * Le serveur doit etre capable de traiter un grand nombre de requete
 * pour cela nous devons creer un serveur modulaire capable d'utilisé
 * plusieurs algorithmes différent pour récupérer et traiter les clients
 *  example d'algorithme:
 * - Fair queue
 * - ...
 *
 * Les opération du serveur doivent etre asynchrone pour traiter un max
 * de requete et ne pas attendre si la charge de travail est importante
 *
 */

typedef struct server_t {
  socket_t socket;
  struct sockaddr_in address;
} server_t;

server_t *cb_net_server_new();

void cb_net_server_delete(server_t *s);

void cb_net_server_init(server_t *srv);

void cb_net_server_terminate(server_t *srv);

void cb_net_server_bind(server_t *srv, uint16_t port);

void cb_net_server_listen(server_t *srv, uint64_t backlog);

socket_t cb_net_server_accept(server_t *srv);

#endif
