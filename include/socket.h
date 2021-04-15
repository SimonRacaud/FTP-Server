/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket.h
*/

#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "socket_t.h"
#include "connection_t.h"
#include "server_t.h"

#define TO_PROCESS(connection, fds) FD_ISSET(connection->sock.fd, &fds)

int socket_server_create(socket_t *sock, uint port, uint max_client);

int socket_server_select(
    select_t *data, connection_t **clients, socket_t *server);

int socket_server_connect(socket_t *client, int server_fd);

char *socket_receive(socket_t *sock);
int socket_send(socket_t *sock, const char *msg);

int socket_client_connect(socket_t *sock, uint port, const char *ip);

int socket_close(socket_t *sock);

// DEBUG
void debug_socket(socket_t *sock, const char *msg);

#endif // SOCKET_H
