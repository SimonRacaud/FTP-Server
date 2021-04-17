/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 server_create.c
*/

#include "app.h"
#include "socket.h"

int server_create(server_t *server, uint port, uint max_client)
{
    if (socket_server_create(&server->sock, port, max_client))
        return EXIT_FAILURE;
    server->max_client = max_client;
    server->clients = NULL;
    return EXIT_SUCCESS;
}