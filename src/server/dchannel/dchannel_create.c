/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 dchannel_create.c
*/

#include "server.h"
#include "socket.h"

static const uint DCHANNEL_MAX_CLIENT = 1;

static int dchannel_init_active(
    data_channel_t *dchannel, uint port, const char *ip)
{
    dchannel->mode = ACTIVE;
    dchannel->args_active.port = port;
    if (strlen(ip) <= INET_ADDRSTRLEN)
        strcpy(dchannel->args_active.ip, ip);
    else
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int dchannel_init_passive(data_channel_t *dchannel)
{
    if (socket_server_create(
            &dchannel->passive_server, RANDOM_PORT, DCHANNEL_MAX_CLIENT)) {
        return EXIT_FAILURE;
    }
    dchannel->mode = PASSIVE;
    dchannel->sock.fd = -1;
    return EXIT_SUCCESS;
}

data_channel_t *dchannel_create(channel_mode_e mode, uint port, const char *ip)
{
    data_channel_t *node = malloc(sizeof(data_channel_t));

    if (!node)
        return NULL;
    node->sock.fd = -1;
    if (mode == ACTIVE) {
        if (dchannel_init_active(node, port, ip)) {
            free(node);
            return NULL;
        }
    } else {
        if (dchannel_init_passive(node)) {
            free(node);
            return NULL;
        }
    }
    node->used = false;
    return node;
}