/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_list_add.c
*/

#include "server.h"

int connection_list_push(connection_t *node, connection_t ***clients_ptr)
{
    size_t size = 0;
    connection_t **clients = *clients_ptr;

    if (clients != NULL) {
        for (; clients[size] != NULL; size++);
        clients =
            realloc(clients, sizeof(connection_t *) * (size + 2));
        if (!clients)
            return EXIT_FAILURE;
        clients[size] = node;
        clients[size + 1] = NULL;
    } else {
        *clients_ptr = calloc(1, sizeof(connection_t *) * 2);
        (*clients_ptr)[1] = NULL;
        if (!(*clients_ptr))
            return EXIT_FAILURE;
        (*clients_ptr)[0] = node;
    }
    return EXIT_SUCCESS;
}