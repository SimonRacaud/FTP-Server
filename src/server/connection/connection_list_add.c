/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_list_add.c
*/

#include "server.h"

int connection_list_add(connection_t *node, server_t *server)
{
    size_t size = 0;

    if (server->clients != NULL) {
        for (; server->clients[size] != NULL; size++);
        server->clients =
            realloc(server->clients, sizeof(connection_t *) * (size + 2));
        if (!server->clients)
            return EXIT_FAILURE;
        server->clients[size] = node;
        server->clients[size + 1] = NULL;
    } else {
        server->clients = calloc(1, sizeof(connection_t *) * 2);
        if (!server->clients)
            return EXIT_FAILURE;
        server->clients[0] = node;
    }
    return EXIT_SUCCESS;
}