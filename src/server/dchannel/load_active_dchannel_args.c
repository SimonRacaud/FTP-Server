/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 20/04/2021 load_active_dchannel_args.c
*/

#include "server.h"
#include <arpa/inet.h>

int load_active_dchannel_args(active_args_t *dest, socket_t *client)
{
    socklen_t len = sizeof(struct sockaddr);

    getsockname(client->fd, (struct sockaddr *) &client->conf, &len);
    if (inet_ntop(AF_INET, &(client->conf.sin_addr), dest->ip, INET_ADDRSTRLEN)
        == NULL) {
        return EXIT_FAILURE;
    }
    dest->port = htons(client->conf.sin_port);
    return EXIT_SUCCESS;
}