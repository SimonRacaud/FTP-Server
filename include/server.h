/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 server.h
*/

#ifndef SERVER_H
#define SERVER_H

#ifdef EXIT_FAILURE
#undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

#include "server_t.h"
#include "connection_t.h"

int server_create(server_t *server, uint port, uint max_client);
int server_destroy(server_t *server);

//      Connection
connection_t *connection_create(int server_fd);
int connection_destroy(connection_t *conn);
int connection_list_add(connection_t *node, server_t *server);
int connection_list_remove(server_t *server, connection_t *to_remove);
int connection_list_destroy(connection_t **list);

#endif // SERVER_H
