/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket_server_select.c
*/

#include "socket.h"

static void init_dchannel_fds(fd_set *fds, connection_t *client)
{
    for (size_t j = 0; client->channel_list[j]; j++) {
        if (client->channel_list[j]->mode == PASSIVE) {
            FD_SET(client->channel_list[j]->passive_server.fd, fds);
        }
    }
}

static void init_fds(fd_set *fds, connection_t **clients, socket_t *server)
{
    FD_ZERO(fds);
    FD_SET(server->fd, fds);
    for (size_t i = 0; clients && clients[i] != NULL; i++) {
        FD_SET(clients[i]->sock.fd, fds);
        if (clients[i]->channel_list) {
            init_dchannel_fds(fds, clients[i]);
        }
    }
}

int socket_server_select(
    select_t *data, connection_t **clients, socket_t *server)
{
    init_fds(&data->write_fds, clients, server);
    init_fds(&data->read_fds, clients, server);
    data->status =
        select(FD_SETSIZE, &data->read_fds, &data->write_fds, NULL, NULL);
    if (data->status == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}