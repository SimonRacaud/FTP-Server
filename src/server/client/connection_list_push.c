/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 connection_list_add.c
*/

#include "server.h"

static connection_t **app_new_client(connection_t **clients, connection_t *node)
{
    size_t size = 0;
    connection_t **new_clients;

    while (clients[size] != NULL)
        size++;
    new_clients = malloc(sizeof(connection_t *) * (size + 2));
    if (!new_clients)
        return NULL;
    for (size_t i = 0; i < size; i++)
        new_clients[i] = clients[i];
    new_clients[size] = node;
    new_clients[size + 1] = NULL;
    free(clients);
    return new_clients;
}

int connection_list_push(connection_t *node, connection_t ***clients_ptr)
{
    connection_t **clients = *clients_ptr;

    if (clients != NULL) {
        *clients_ptr = app_new_client(clients, node);
        if (*clients_ptr == NULL)
            return EXIT_FAILURE;
    } else {
        *clients_ptr = calloc(1, sizeof(connection_t *) * 2);
        (*clients_ptr)[1] = NULL;
        if (!(*clients_ptr))
            return EXIT_FAILURE;
        (*clients_ptr)[0] = node;
    }
    return EXIT_SUCCESS;
}