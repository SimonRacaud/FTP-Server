/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket_server_select.c
*/

#include "socket.h"

static void init_fds(fd_set *fds, connection_t **clients, socket_t *server)
{
    FD_ZERO(fds);
    FD_SET(server->fd, fds);
    for (size_t i = 0; clients[i] != NULL; i++) {
        FD_SET(clients[i]->sock.fd, fds);
        for (size_t j = 0; clients[i]->channel_list[j]; j++) {
            FD_SET(clients[i]->channel_list[j]->sock.fd, fds);
        }
    }
}

int socket_server_select(
    select_t *data, connection_t **clients, socket_t *server)
{
    init_fds(&data->write_fds, clients, server);
    data->status =
        select(FD_SETSIZE, &data->read_fds, &data->write_fds, NULL, NULL);
    if (data->status == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}