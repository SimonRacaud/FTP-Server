/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_list_remove.c
*/

#include "server.h"

static connection_t **realloc_list(
    size_t size, connection_t **list, connection_t *to_remove)
{
    connection_t **res = malloc(sizeof(connection_t *) * size);
    size_t idx = 0;

    if (!res)
        return NULL;
    res[size] = NULL;
    for (size_t i = 0; i < size; i++) {
        if (list[i] != to_remove) {
            res[idx++] = list[i];
        } else if (connection_destroy(list[i])) {
            return NULL;
        }
    }
    free(list);
    return res;
}

int connection_list_remove(server_t *server, connection_t *to_remove)
{
    size_t size = 0;

    if (server->clients == NULL) {
        return EXIT_SUCCESS;
    }
    for (; server->clients[size] != NULL; size++);
    server->clients = realloc_list(size, server->clients, to_remove);
    if (server->clients == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}