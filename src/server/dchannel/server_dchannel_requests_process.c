/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 17/04/2021 server_dchannel_requests_process.c
*/

#include "server.h"
#include "socket.h"

static int sub_routine(select_t *select, connection_t *client)
{
    data_channel_t *dchan = NULL;

    for (size_t i = 0; client->channel_list && client->channel_list[i]; i++) {
        dchan = client->channel_list[i];
        if (dchan->mode == PASSIVE
            && FD_ISSET(dchan->passive_server.fd, &select->read_fds)
            && socket_server_connect(&dchan->sock, dchan->passive_server.fd)) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int server_dchannel_requests_process(select_t *select, connection_t **clients)
{
    for (size_t i = 0; clients && clients[i] != NULL; i++) {
        if (sub_routine(select, clients[i]) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}